(*
 * Copyright (c) 2015, Facebook, Inc.
 * All rights reserved.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the "hack" directory of this source tree.
 *
 *)

open Hh_prelude

type flags = int

type bit_mask = int

(* Is this bit set in the flags? *)
let is_set (bit : bit_mask) (flags : flags) : bool =
  not (Int.equal 0 (Int.bit_and bit flags))

(* Set a single bit to a boolean value *)
let set_bit bit value flags =
  if value then
    Int.bit_or bit flags
  else
    Int.bit_and (Int.bit_not bit) flags

type fun_type_flags = int

type fun_param_flags = int

module ClassElt : sig
  type t [@@deriving show]

  val make :
    xhp_attr:Xhp_attribute.t option ->
    abstract:bool ->
    final:bool ->
    superfluous_override:bool ->
    lsb:bool ->
    synthesized:bool ->
    const:bool ->
    lateinit:bool ->
    dynamicallycallable:bool ->
    readonly_prop:bool ->
    support_dynamic_type:bool ->
    needs_init:bool ->
    safe_global_variable:bool ->
    t

  val is_abstract : t -> bool

  val is_final : t -> bool

  val has_superfluous_override : t -> bool

  val has_lsb : t -> bool

  (** Whether a class element comes from a `require extends`. *)
  val is_synthesized : t -> bool

  val is_const : t -> bool

  val has_lateinit : t -> bool

  val is_dynamicallycallable : t -> bool

  val supports_dynamic_type : t -> bool

  val is_readonly_prop : t -> bool

  val needs_init : t -> bool

  val is_safe_global_variable : t -> bool

  val get_xhp_attr : t -> Xhp_attribute.t option

  val set_synthesized : t -> t

  val reset_superfluous_override : t -> t
end = struct
  type t = flags

  module Field = struct
    type t =
      | Abstract
      | Final
      | SuperfluousOverride
          (** Whether the __Override attribute is erroneous, i.e. there is nothing in parents to override.
              This is set during decling (because that's the easiest place to spot this error)
              so that an error can be emitted later during typing. *)
      | Lsb
      | Synthesized
      | Const
      | Lateinit
      | Dynamicallycallable
      | SupportDynamicType
      | XaHasDefault
      | XaTagRequired
      | XaTagLateinit
      | ReadonlyProp
      | NeedsInit
      | SafeGlobalVariable
    [@@deriving enum, show { with_path = false }]

    (* [min] is generated by the enum ppx and is unused. This suppresses the warning. *)
    let _ = min

    let all : t list =
      let rec f i acc =
        if i < 0 then
          acc
        else
          f (i - 1) (Option.value_exn (of_enum i) :: acc)
      in
      f max []

    let to_bit_mask (field : t) : bit_mask = 1 lsl to_enum field

    let list_to_bit_mask (fields : t list) : bit_mask =
      List.map fields ~f:to_bit_mask |> List.fold ~init:0 ~f:Int.bit_or

    (* The three XA bits are used to encode optional XHP attr.
     * Set 1<<10 (0x400) if xa_has_default=true
     * Then encode xa_tag as follows:
     *   Some Required: 1<<11 (0x0800)
     *   Some lateinit: 1<<12 (0x1000)
     *   None:          1<<11 | 1<<12 (0x1800)
     * If attr is not present at all, then masking with 0x1800 will produce zero.
     *)

    let xhp_attr_fields : t list = [XaHasDefault; XaTagLateinit; XaTagRequired]

    let of_xhp_tag : Xhp_attribute.tag -> t = function
      | Xhp_attribute.Required -> XaTagRequired
      | Xhp_attribute.LateInit -> XaTagLateinit

    let to_xhp_tag : t -> Xhp_attribute.tag = function
      | XaTagRequired -> Xhp_attribute.Required
      | XaTagLateinit -> Xhp_attribute.LateInit
      | _ -> failwith "cannot convert field to xhp attribute tag"

    let equal_xhp_tag (field : t) (tag : Xhp_attribute.tag) =
      match (field, tag) with
      | (XaTagRequired, Xhp_attribute.Required)
      | (XaTagLateinit, Xhp_attribute.LateInit) ->
        true
      | _ -> false

    let of_xhp_attr (xa : Xhp_attribute.t option) : t list =
      match xa with
      | None -> []
      | Some { Xhp_attribute.xa_has_default; xa_tag } ->
        let tag_fields =
          match xa_tag with
          | None -> [XaTagRequired; XaTagLateinit]
          | Some tag -> [of_xhp_tag tag]
        in
        if xa_has_default then
          XaHasDefault :: tag_fields
        else
          tag_fields

    let to_xhp_attr (fields : t list) : Xhp_attribute.t option =
      match fields with
      | [] -> None
      | _ :: _ ->
        let rec to_xhp_attr fields xa =
          match fields with
          | [] -> xa
          | field :: fields ->
            let xa =
              let update_tag field tag =
                match tag with
                | None -> Some (to_xhp_tag field)
                | Some tag ->
                  if equal_xhp_tag field tag then
                    Some tag
                  else
                    (* If both XaTagRequired and XaTagLateinit bits are set, then that's
                       code for xa_tag = None. *)
                    None
              in
              match field with
              | XaHasDefault -> { xa with Xhp_attribute.xa_has_default = true }
              | XaTagRequired
              | XaTagLateinit ->
                Xhp_attribute.map_tag xa ~f:(update_tag field)
              | _ -> xa
            in
            to_xhp_attr fields xa
        in
        Some (to_xhp_attr fields Xhp_attribute.init)
  end

  let is_set (field : Field.t) (flags : t) : bool =
    is_set (Field.to_bit_mask field) flags

  let set (field : Field.t) (value : bool) (flags : t) : t =
    set_bit (Field.to_bit_mask field) value flags

  let is_abstract = is_set Field.Abstract

  let is_final = is_set Field.Final

  let has_superfluous_override = is_set Field.SuperfluousOverride

  let has_lsb = is_set Field.Lsb

  let is_synthesized = is_set Field.Synthesized

  let is_const = is_set Field.Const

  let has_lateinit = is_set Field.Lateinit

  let is_dynamicallycallable = is_set Field.Dynamicallycallable

  let supports_dynamic_type = is_set Field.SupportDynamicType

  let is_readonly_prop = is_set Field.ReadonlyProp

  let needs_init = is_set Field.NeedsInit

  let is_safe_global_variable = is_set Field.SafeGlobalVariable

  let get_xhp_attr (flags : t) : Xhp_attribute.t option =
    Field.xhp_attr_fields
    |> List.filter ~f:(fun field -> is_set field flags)
    |> Field.to_xhp_attr

  let set_xhp_attr (xa : Xhp_attribute.t option) (flags : t) : t =
    let xhp_attr_as_flags = xa |> Field.of_xhp_attr |> Field.list_to_bit_mask in
    let reset_xhp_attr =
      let xhp_attr_mask = Field.xhp_attr_fields |> Field.list_to_bit_mask in
      Int.bit_and (Int.bit_not xhp_attr_mask)
    in
    flags |> reset_xhp_attr |> Int.bit_or xhp_attr_as_flags

  let to_string_map (flags : t) : bool SMap.t =
    Field.all
    |> List.map ~f:(fun field -> (Field.show field, is_set field flags))
    |> SMap.of_list

  let show (flags : t) : string = flags |> to_string_map |> SMap.show Bool.pp

  let pp (fmt : Format.formatter) (flags : t) : unit =
    flags |> to_string_map |> SMap.pp Bool.pp fmt

  let make
      ~xhp_attr
      ~abstract
      ~final
      ~superfluous_override
      ~lsb
      ~synthesized
      ~const
      ~lateinit
      ~dynamicallycallable
      ~readonly_prop
      ~support_dynamic_type
      ~needs_init
      ~safe_global_variable =
    let flags = 0 in
    let flags = set Field.Abstract abstract flags in
    let flags = set Field.Final final flags in
    let flags = set Field.SuperfluousOverride superfluous_override flags in
    let flags = set Field.Lsb lsb flags in
    let flags = set Field.Synthesized synthesized flags in
    let flags = set Field.Const const flags in
    let flags = set Field.Lateinit lateinit flags in
    let flags = set Field.Dynamicallycallable dynamicallycallable flags in
    let flags = set_xhp_attr xhp_attr flags in
    let flags = set Field.ReadonlyProp readonly_prop flags in
    let flags = set Field.SupportDynamicType support_dynamic_type flags in
    let flags = set Field.NeedsInit needs_init flags in
    let flags = set Field.SafeGlobalVariable safe_global_variable flags in
    flags

  let set_synthesized = set Field.Synthesized true

  let reset_superfluous_override = set Field.SuperfluousOverride false
end

[@@@ocamlformat "disable"]

(* NB: Keep the values of these flags in sync with typing_defs_flags.rs. *)

(* Function type flags *)
let ft_flags_return_disposable  = 1 lsl 0

let ft_flags_returns_mutable    = 1 lsl 1

let ft_flags_returns_void_to_rx = 1 lsl 2

let ft_flags_async              = 1 lsl 4

let ft_flags_generator          = 1 lsl 5

(* These flags are used for the self type on FunType and the parameter type on FunParam *)
let mutable_flags_owned         = 1 lsl 6

let mutable_flags_borrowed      = 1 lsl 7

let mutable_flags_maybe         = Int.bit_or mutable_flags_owned mutable_flags_borrowed

let mutable_flags_mask          = Int.bit_or mutable_flags_owned mutable_flags_borrowed

let ft_flags_instantiated_targs = 1 lsl 8

let ft_flags_is_function_pointer = 1 lsl 9

let ft_flags_returns_readonly = 1 lsl 10

let ft_flags_readonly_this = 1 lsl 11

let ft_flags_support_dynamic_type = 1 lsl 12

let ft_flags_is_memoized = 1 lsl 13

let ft_flags_variadic          = 1 lsl 14

(* fun_param flags *)
let fp_flags_accept_disposable = 1 lsl 0

let fp_flags_inout             = 1 lsl 1

let fp_flags_has_default       = 1 lsl 2

let fp_flags_ifc_external      = 1 lsl 3

let fp_flags_ifc_can_call      = 1 lsl 4

(* let fp_flags_via_label_DEPRECATED         = 1 lsl 5 *)

(* 6 and 7 are taken by mutability parameters above *)
let fp_flags_readonly          = 1 lsl 8
