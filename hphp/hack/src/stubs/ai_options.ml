(*
 * Copyright (c) 2015, Facebook, Inc.
 * All rights reserved.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the "hack" directory of this source tree.
 *
 *)
 
type t = {
  analyses: string list;
  unittest_hack_root: string option;
  run_hh_distc_workers_locally: bool;
  compute_folded_class_decls_with_hh_distc: bool;
  compute_type_infos_with_hh_distc: bool;
}

let prepare ~server:_ _ = {
  analyses = [];
  unittest_hack_root = None;
  run_hh_distc_workers_locally = false;
  compute_folded_class_decls_with_hh_distc = false;
  compute_type_infos_with_hh_distc = false;
}

let modify_shared_mem _options config = config

let merge_for_unit_tests a _b = a
