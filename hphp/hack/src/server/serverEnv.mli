(*
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the "hack" directory of this source tree.
 *
 *)

open Hh_prelude

type seconds = float

type seconds_since_epoch = float

(** The "static" environment, initialized first and then doesn't change *)
type genv = {
  options: ServerArgs.options;
  config: ServerConfig.t;
  local_config: ServerLocalConfig.t;
  workers: MultiWorker.worker list option;
      (** Early-initialized workers to be used in MultiWorker jobs
          They are initialized early to keep their heaps as empty as possible. *)
  notifier: ServerNotifier.t;  (** Common abstraction for watchman/dfind *)
  indexer: (string -> bool) -> unit -> string list;
      (** Returns the list of files under .hhconfig, subject to a filter.
      TODO: this indexer should be moved to a member of ServerNotifier,
      but can't because zoncolan needs to tweak it. *)
  mutable debug_channels: (Timeout.in_channel * Out_channel.t) option;
}

module Init_telemetry : sig
  (** These names appear in telemetry, where it's nice to see the word "Init" in them. *)
  type reason =
    | Init_lazy_dirty  (** normal saved-state init *)
    | Init_typecheck_disabled_after_init  (** I don't know what this is for *)
    | Init_eager  (** full init *)
    | Init_lazy_full  (** failed a saved-state init, and fell back to full *)
    | Init_prechecked_fanout  (** I don't know what this is for *)

  (** This is telemetry, generated by ServerInit, to explain in subsequent
  events why ServerMain's first full check had to happen. *)
  type t

  val make : reason -> Telemetry.t -> t

  val get : t -> Telemetry.t

  val get_reason : t -> string
end

(** How "old" a given saved state is relative to the working revision.
    That is, a saved state has some corresponding revision X, and `hh` is invoked on a commit
    of mergebase Y.

    Distance tracks the number of revisions between X and Y, using globalrev.
    Age tracks the time elapsed between X and Y in seconds, according to hg log data.
*)
type saved_state_delta = {
  distance: int;
  age: int;
}
[@@deriving show]

type init_env = {
  approach_name: string;
  ci_info: Ci_util.info option Future.t option; [@opaque]
      (** The info describing the CI job the server is a part of, if any *)
  init_error: string option;
  init_id: string;
  init_start_t: float;
  init_type: string;
  mergebase: Hg.Rev.t option;
  why_needed_full_check: Init_telemetry.t option;
      (** This is about the first full check (if any) which was deferred after init.
      It gets reset after that first full check is completed.
      First parameter is a string label used in telemetry. Second is opaque telemetry. *)
  recheck_id: string option;
  (* Additional data associated with init that we want to log when a first full
   * check completes. *)
  saved_state_delta: saved_state_delta option;
  naming_table_manifold_path: string option;
      (** The manifold path for remote typechecker workers to download the naming table
          saved state. This value will be None in the case of full init *)
}

type full_check_status =
  | Full_check_needed
      (** Some updates have not been fully processed. We get into this state every
          time file contents change (on disk, or through IDE notifications).
          Operations that depend on global state (like taking full error list, or
          looking up things in dependency table) will have stale results. *)
  | Full_check_started
      (** Same as above, except server will actively try to process outstanding
          changes (by going into ServerTypeCheck from main loop - this might need to
          be repeated several times before progressing to Full_check_done, due to
          ability to interrupt typecheck jobs).
          Server starts in this state, and we also enter it from Full_check_needed
          whenever there is a command requiring full check pending, or when user
          saves a file. *)
  | Full_check_done  (** All the changes have been fully processed. *)
[@@deriving show]

type dirty_deps = {
  dirty_local_deps: Typing_deps.DepSet.t;
      (** We are rechecking dirty files to bootstrap the dependency graph.
          After this is done we need to also recheck full fan-out (in this updated
          graph) of provided set. *)
  dirty_master_deps: Typing_deps.DepSet.t;
      (** The fan-outs of those nodes were not expanded yet. *)
  rechecked_files: Relative_path.Set.t;
      (** Files that have been rechecked since server startup *)
  clean_local_deps: Typing_deps.DepSet.t;
      (** Those deps have already been checked against their interaction with
          dirty_master_deps. Storing them here to avoid checking it over and over *)
}

(** When using prechecked files we split initial typechecking in two phases
    (dirty files and a subset of their fan-out). Other init types compute the
    full fan-out up-front. *)
type prechecked_files_status =
  | Prechecked_files_disabled
  | Initial_typechecking of dirty_deps
  | Prechecked_files_ready of dirty_deps

module RecheckLoopStats : sig
  type t = {
    updates_stale: bool;
        (** Watchman subscription has gone down, so state of the world after the
            recheck loop may not reflect what is actually on disk. *)
    per_batch_telemetry: Telemetry.t list;
    total_changed_files_count: int;
        (** Count of files changed on disk and potentially also in the IDE. *)
    total_rechecked_count: int;
    last_iteration_start_time: seconds_since_epoch;
        (** Start time of the last loop iteration, after the last user change. *)
    duration: seconds;
    time_first_result: seconds_since_epoch option;
        (** This is either the duration to get the first error if any
            or until we get "typecheck done" status message.
            This is originally None when no result has been sent yet,
            and should be [Some timestamp] at the end of the loop. *)
    recheck_id: string;
    any_full_checks: bool;
  }

  val empty : recheck_id:string -> t

  (** The format of this json is user-facing, returned from 'hh check --json' *)
  val to_user_telemetry : t -> Telemetry.t

  (** Update field [time_first_result] if given timestamp is the
      first sent result. *)
  val record_result_sent_ts : t -> seconds_since_epoch option -> t
end

(** The environment constantly maintained by the server.
    In addition to this environment, many functions are storing and
    updating ASTs, NASTs, and types in a shared space
    (see respectively Parser_heap, Naming_table, Typing_env).
    The Ast.id are keys to index this shared space. *)
type env = {
  naming_table: Naming_table.t;
  deps_mode: Typing_deps_mode.t;
  tcopt: TypecheckerOptions.t;
  popt: ParserOptions.t;
  gleanopt: GleanOptions.t;
  swriteopt: SymbolWriteOptions.t;
  errorl: Errors.t; [@opaque]
      (** Errors are indexed by files that were known to GENERATE errors in
          corresponding phases. Note that this is different from HAVING errors -
          it's possible for checking of A to generate error in B - in this case
          Errors.get_failed_files Typing should contain A, not B.
          Conversly, if declaring A will require declaring B, we should put
          B in failed decl. Same if checking A will cause declaring B (via lazy
          decl).

          During recheck, we add those files to the set of files to reanalyze
          at each stage in order to regenerate their error lists. So those
          failed_ sets are the main piece of mutable state that incremental mode
          needs to maintain - the errors themselves are more of a cache, and should
          always be possible to be regenerated based on those sets. *)
  failed_naming: Relative_path.Set.t;
      (** failed_naming is used as kind of a dependency tracking mechanism:
          if files A.php and B.php both define class C, then those files are
          mutually depending on each other (edit to one might resolve naming
          ambiguity and change the interpretation of the other). Both of those
          files being inside failed_naming is how we track the need to
          check for this condition.

          See test_naming_errors.ml and test_failed_naming.ml *)
  last_command_time: float;
      (** Timestamp of last IDE file synchronization command *)
  last_notifier_check_time: float;
      (** Timestamp of last query for disk changes *)
  last_idle_job_time: float;  (** Timestamp of last ServerIdle.go run *)
  disk_needs_parsing: Relative_path.Set.t;
  clock: Watchman.clock option;
      (** This is the clock as of when disk_needs_parsing was last updated.
      None if not using Watchman. *)
  needs_phase2_redecl: Relative_path.Set.t;
      (** Declarations that became invalidated and moved to "old" part of the heap.
          We keep them there to be used in "determining changes" step of recheck.
          (when they are compared to "new" versions). Depending on lazy decl to
          compute "new" versions in all the other scenarios (like IDE queries) *)
  needs_recheck: Relative_path.Set.t;
      (** Files that need to be typechecked before commands that depend on global
          state (like full list of errors, build, or find all references) can be
          executed . After full check this should be empty, unless that check was
          cancelled mid-flight, in which case full_check_status will be set to
          Full_check_started and entire thing will be retried on next iteration. *)
  why_needs_server_type_check: string * string;
      (** Why is a round of ServerTypeCheck needed? For instance, if a typecheck
      got interrupted+cancelled leaving files still needing to be checked, the
      reason will be stored here. It's written+read by [ServerTypeCheck.type_check].
      The first of the two strings is a user-facing message, and the second is additional
      information for logs. *)
  init_env: init_env;
  full_check_status: full_check_status;
  prechecked_files: prechecked_files_status;
  changed_files: Relative_path.Set.t;
  interrupt_handlers:
    genv ->
    env ->
    (Unix.file_descr * env MultiThreadedCall.interrupt_handler) list;
  nonpersistent_client_pending_command_needs_full_check:
    ((env -> env) * string * ClientProvider.client) option;
      [@opaque]
      (** When a non-persistent client sends a command that cannot be immediately handled
          (due to needing full check) we put the continuation that finishes handling
          it here. The string specifies a reason why this command needs full
          recheck (for logging/debugging purposes) *)
  last_recheck_loop_stats: RecheckLoopStats.t;
  last_recheck_loop_stats_for_actual_work: RecheckLoopStats.t option;
  old_decl_client_opt: Remote_old_decls_ffi.old_decl_client option;
}
[@@deriving show]

val is_full_check_done : full_check_status -> bool

val is_full_check_needed : full_check_status -> bool

val is_full_check_started : full_check_status -> bool

val list_files : env -> string list

val add_changed_files : env -> Relative_path.Set.t -> env

val show_clock : Watchman.clock option -> string
