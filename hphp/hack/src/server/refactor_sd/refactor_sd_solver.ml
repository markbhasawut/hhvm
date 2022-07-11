(*
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the "hack" directory of this source tree.
 *
 *)

open Hh_prelude
open Refactor_sd_types

type constraints = {
  introductions: Pos.t list;
  subsets: (entity_ * entity_) list;
  upcasts: (entity_ * Pos.t) list;
}

let constraints_init = { introductions = []; subsets = []; upcasts = [] }

let rec transitive_closure (set : PointsToSet.t) : PointsToSet.t =
  let immediate_consequence (x, y) set =
    let add (y', z) set =
      if equal_entity_ y y' then
        PointsToSet.add (x, z) set
      else
        set
    in
    PointsToSet.fold add set set
  in
  let new_set = PointsToSet.fold immediate_consequence set set in
  if PointsToSet.cardinal new_set = PointsToSet.cardinal set then
    set
  else
    transitive_closure new_set

let find_pointers (introductions : Pos.t list) (set : PointsToSet.t) :
    PointsToSet.t =
  let check_if_pointer (has_pointer_set : PointsToSet.t) (pointer_pos : Pos.t) =
    let contains_pos ((sub, _) : entity_ * entity_) =
      match sub with
      | Literal pos -> Pos.compare pointer_pos pos = 0
      | _ -> false
    in
    let new_set = PointsToSet.filter contains_pos set in
    PointsToSet.union new_set has_pointer_set
  in
  List.fold introductions ~init:PointsToSet.empty ~f:check_if_pointer

let partition_constraint constraints = function
  | Introduction pos ->
    { constraints with introductions = pos :: constraints.introductions }
  | Subset (sub, sup) ->
    { constraints with subsets = (sub, sup) :: constraints.subsets }
  | Upcast (entity, pos) ->
    { constraints with upcasts = (entity, pos) :: constraints.upcasts }

let subset_lookups subsets =
  let update entity entity' =
    EntityMap.update entity (function
        | None -> Some (EntitySet.singleton entity')
        | Some set -> Some (EntitySet.add entity' set))
  in
  let (subset_map, superset_map) =
    let update_maps (e, e') (subset_map, superset_map) =
      let subset_map = update e' e subset_map in
      let superset_map = update e e' superset_map in
      (subset_map, superset_map)
    in
    PointsToSet.fold update_maps subsets (EntityMap.empty, EntityMap.empty)
  in

  (* Generate lookup functions. This code is different from shape_analysis. *)
  let collect map (entity, pos) =
    match EntityMap.find_opt entity map with
    | Some entities ->
      List.map ~f:(fun ent -> (ent, pos)) (EntitySet.elements entities)
    | None -> []
  in
  (collect subset_map, collect superset_map)

let simplify (_env : Typing_env_types.env) (constraints : constraint_ list) :
    refactor_sd_result list =
  let { introductions; upcasts; subsets } =
    List.fold ~init:constraints_init ~f:partition_constraint constraints
  in

  let subsets_reflexive =
    List.map ~f:(fun pos -> Literal pos) introductions
    @ List.map ~f:(fun (e, _pos) -> e) upcasts
    @ List.concat_map subsets ~f:(fun (e, e') -> [e; e'])
    |> List.map ~f:(fun e -> (e, e))
  in
  let subsets = subsets_reflexive @ subsets in
  let subsets = PointsToSet.of_list subsets |> transitive_closure in
  let subsets = subsets |> find_pointers introductions in
  let (collect_subsets, _collect_supersets) = subset_lookups subsets in
  let upcasts = upcasts |> List.concat_map ~f:collect_subsets in
  (* Convert to individual upcast results *)
  let exists_upcast_results : refactor_sd_result list =
    upcasts |> List.map ~f:(fun (_entity, pos) -> Exists_Upcast pos)
  in
  if List.is_empty exists_upcast_results then
    [No_Upcast]
  else
    exists_upcast_results
