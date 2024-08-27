(*
 * Copyright (c) 2018, Facebook, Inc.
 * All rights reserved.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the "hack" directory of this source tree.
 *
 *)

val go :
  ServerCommandTypes.file_input list ->
  Provider_context.t ->
  Warnings_saved_state.t option ->
  Errors.t * Tast.program Tast_with_dynamic.t Relative_path.Map.t
