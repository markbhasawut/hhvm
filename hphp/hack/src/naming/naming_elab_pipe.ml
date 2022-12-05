(*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the "hack" directory of this source tree.
 *
 *)
module SN = Naming_special_names

module Env = struct
  type t = unit

  let empty = ()
end

let visitor =
  object (_self)
    inherit [_] Aast_defs.endo as super

    method on_'ex _ ex = ex

    method on_'en _ en = en

    method! on_expr_ env expr_ =
      let expr_ =
        match expr_ with
        | Aast.Pipe ((pos, _), e1, e2) ->
          let lid =
            (pos, Local_id.make_unscoped SN.SpecialIdents.dollardollar)
          in
          Aast.Pipe (lid, e1, e2)
        | _ -> expr_
      in
      super#on_expr_ env expr_
  end

let elab f ?(env = Env.empty) elem = f env elem

let elab_fun_def ?env elem = elab visitor#on_fun_def ?env elem

let elab_typedef ?env elem = elab visitor#on_typedef ?env elem

let elab_module_def ?env elem = elab visitor#on_module_def ?env elem

let elab_gconst ?env elem = elab visitor#on_gconst ?env elem

let elab_class ?env elem = elab visitor#on_class_ ?env elem

let elab_program ?env elem = elab visitor#on_program ?env elem
