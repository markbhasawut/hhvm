let load ~ssopt:_ ~progress_callback:_ ~watchman_opts:_ ~ignore_hh_version:_ =
  Future.of_value (Error "State_loader_futures not supported in public build")
