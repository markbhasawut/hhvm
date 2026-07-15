type handle = unit

let spawn ~root:_ ~ss_dir:_ ~hhdg_path:_ ~fanout:_ _tcopt =
  Error "Hh_distc FFI not supported in public build"

let get_re_session_id _handle = ""

let get_fd _handle = Unix.stdin

let recv _handle = Ok None

let join _handle = Ok (Diagnostics.empty, Map_reduce_ffi.empty)

let cancel _handle = ()
