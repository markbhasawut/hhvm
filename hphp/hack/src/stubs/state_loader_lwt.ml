module FromDisk = struct
  type load_result = {
    naming_table_path: Path.t;
    warning_saved_state_path: Path.t;
    files_changed: Saved_state_loader.changed_files;
  }

  let load ~project_metadata:_ ~threshold:_ ~root:_ =
    Error "State_loader_lwt not supported in public build"
end

let load ~ssopt:_ ~progress_callback:_ ~watchman_opts:_ ~ignore_hh_version:_ =
  Lwt.fail_with "State_loader_lwt not supported in public build"

let prepare_download_dir ~saved_state_cache_limit:_ ~download_dir:_ =
  Lwt.fail_with "State_loader_lwt not supported in public build"

let get_saved_state_target_path ~download_dir:_ ~manifold_path:_ =
  Lwt.fail_with "State_loader_lwt not supported in public build"

let download_and_unpack_saved_state_from_manifold ~ssopt:_ ~manifold_path:_ ~target_path:_ ~progress_callback:_ =
  Lwt.fail_with "State_loader_lwt not supported in public build"

let get_project_metadata ~repo:_ ~opts:_ ~ignore_hh_version:_ =
  Lwt.fail_with "State_loader_lwt not supported in public build"
