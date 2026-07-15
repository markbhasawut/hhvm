let () =
  let argv = Sys.argv in
  let argc = Array.length argv in
  let current_exe = Sys.executable_name in
  let current_dir = Filename.dirname current_exe in

  let client_commands = [
    "check"; "status"; "start"; "stop"; "restart"; "lint"; "ide"; "lsp";
  ] in

  let client_options = [
    "--from"; "--timeout"; "--autostart";
    "--deps-out-at-pos-batch"; "--deps-in-at-pos-batch"; "--error-format";
    "--enforcement-at-pos-batch"; "--file-dependents"; "--find-class-refs";
    "--find-refs"; "--identify-function"; "--identify";
    "--inheritance-ancestor-classes-batch"; "--inheritance-ancestor-interfaces-batch";
    "--inheritance-ancestor-traits-batch"; "--inheritance-ancestors";
    "--inheritance-children"; "--lint-all"; "--lint-stdin"; "--list-files";
    "--max-errors"; "--logname"; "--outline";
    "--outline-for-agents"; "--refactor"; "--single"; "--multi"; "--stats";
    "--infer-dynamic"; "--infer-dynamic-as-data"; "--type-at-pos-batch";
    "--type-error-at-pos"; "--is-subtype"; "-Wall"; "-Wnone";
    "-W"; "-Wno"; "-Wignore-files"; "-Wgenerated"; "--ultrahelp"
  ] in

  let server_options = [
    "--daemon"; "-d"; "--check"; "--save-naming"; "--write-symbol-info";
    "--max-procs"; "--profile-log"; "--no-load"; "--enable-global-access-check";
    "--save-64bit"; "--dump-fanout"; "--waiting-client"; "--custom-hhi-path";
    "--with-mini-state"; "--saved-state-ignore-hhconfig"
  ] in

  let has_arg options =
    let rec check i =
      if i >= argc then false
      else if List.mem argv.(i) options then true
      else check (i + 1)
    in
    check 1
  in

  if argc = 1 then begin
    Printf.eprintf "[hh] hh is a wrapper driver that calls hh_client or hh_server underneath.\n%!";
    Printf.eprintf "[hh] Defaulting to hh_client.exe\n%!"
  end;

  let is_server =
    if has_arg server_options then
      true
    else if has_arg client_commands || has_arg client_options then
      false
    else
      false
  in

  let target_bin =
    if is_server then
      Filename.concat current_dir "hh_server.exe"
    else
      Filename.concat current_dir "hh_client.exe"
  in

  let target_args = Array.copy argv in
  target_args.(0) <- target_bin;

  let args_str = String.concat " " (List.tl (Array.to_list argv)) in
  if argc > 1 then
    Printf.eprintf "[hh] Wrapper driver: executing %s %s\n%!" target_bin args_str
  else
    Printf.eprintf "[hh] Wrapper driver: executing %s\n%!" target_bin;

  try
    Unix.execv target_bin target_args
  with
  | Unix.Unix_error (err, _, _) ->
    Printf.eprintf "Failed to execute %s: %s\n%!" target_bin (Unix.error_message err);
    exit 127
