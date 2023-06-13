// Copyright (c) Facebook, Inc. and its affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the "hack" directory of this source tree.
//
// @generated SignedSource<<fb5ff079a89c68380480970d4f614b8b>>
//
// To regenerate this file, run:
//   hphp/hack/src/oxidized_regen.sh

use arena_trait::TrivialDrop;
use eq_modulo_pos::EqModuloPos;
use no_pos_hash::NoPosHash;
use ocamlrep::FromOcamlRepIn;
use ocamlrep::ToOcamlRep;
use ocamlrep_caml_builtins::Int64;
pub use oxidized::file_info::Mode;
pub use oxidized::file_info::NameType;
pub use prim_defs::*;
use serde::Deserialize;
use serde::Serialize;

#[allow(unused_imports)]
use crate::*;

/// We define two types of positions establishing the location of a given name:
/// a Full position contains the exact position of a name in a file, and a
/// File position contains just the file and the type of toplevel entity,
/// allowing us to lazily retrieve the name's exact location if necessary.
#[derive(
    Clone,
    Copy,
    Debug,
    Deserialize,
    Eq,
    FromOcamlRepIn,
    Hash,
    NoPosHash,
    Ord,
    PartialEq,
    PartialOrd,
    Serialize,
    ToOcamlRep
)]
#[rust_to_ocaml(attr = "deriving (eq, show)")]
#[repr(C, u8)]
pub enum Pos<'a> {
    #[serde(deserialize_with = "arena_deserializer::arena", borrow)]
    Full(&'a pos::Pos<'a>),
    #[serde(deserialize_with = "arena_deserializer::arena", borrow)]
    #[rust_to_ocaml(inline_tuple)]
    File(
        &'a (
            oxidized::file_info::NameType,
            &'a relative_path::RelativePath<'a>,
        ),
    ),
}
impl<'a> TrivialDrop for Pos<'a> {}
arena_deserializer::impl_deserialize_in_arena!(Pos<'arena>);

/// An id contains a pos, name and a optional decl hash. The decl hash is None
/// only in the case when we didn't compute it for performance reasons
#[derive(
    Clone,
    Debug,
    Deserialize,
    Eq,
    FromOcamlRepIn,
    Hash,
    NoPosHash,
    Ord,
    PartialEq,
    PartialOrd,
    Serialize,
    ToOcamlRep
)]
#[rust_to_ocaml(attr = "deriving (eq, show)")]
#[repr(C)]
pub struct Id<'a>(
    #[serde(deserialize_with = "arena_deserializer::arena", borrow)] pub Pos<'a>,
    #[serde(deserialize_with = "arena_deserializer::arena", borrow)] pub &'a str,
    #[serde(deserialize_with = "arena_deserializer::arena", borrow)] pub Option<&'a Int64>,
);
impl<'a> TrivialDrop for Id<'a> {}
arena_deserializer::impl_deserialize_in_arena!(Id<'arena>);

#[derive(
    Clone,
    Debug,
    Deserialize,
    Eq,
    EqModuloPos,
    FromOcamlRepIn,
    Hash,
    NoPosHash,
    Ord,
    PartialEq,
    PartialOrd,
    Serialize,
    ToOcamlRep
)]
#[rust_to_ocaml(attr = "deriving eq")]
#[repr(C)]
pub struct HashType<'a>(
    #[serde(deserialize_with = "arena_deserializer::arena", borrow)] pub Option<&'a Int64>,
);
impl<'a> TrivialDrop for HashType<'a> {}
arena_deserializer::impl_deserialize_in_arena!(HashType<'arena>);

/// The record produced by the parsing phase.
#[derive(
    Clone,
    Debug,
    Deserialize,
    Eq,
    FromOcamlRepIn,
    Hash,
    NoPosHash,
    Ord,
    PartialEq,
    PartialOrd,
    Serialize,
    ToOcamlRep
)]
#[rust_to_ocaml(attr = "deriving show")]
#[repr(C)]
pub struct FileInfo<'a> {
    #[serde(deserialize_with = "arena_deserializer::arena", borrow)]
    pub hash: &'a HashType<'a>,
    pub file_mode: Option<oxidized::file_info::Mode>,
    #[serde(deserialize_with = "arena_deserializer::arena", borrow)]
    pub funs: &'a [&'a Id<'a>],
    #[serde(deserialize_with = "arena_deserializer::arena", borrow)]
    pub classes: &'a [&'a Id<'a>],
    #[serde(deserialize_with = "arena_deserializer::arena", borrow)]
    pub typedefs: &'a [&'a Id<'a>],
    #[serde(deserialize_with = "arena_deserializer::arena", borrow)]
    pub consts: &'a [&'a Id<'a>],
    #[serde(deserialize_with = "arena_deserializer::arena", borrow)]
    pub modules: &'a [&'a Id<'a>],
    /// None if loaded from saved state
    #[serde(deserialize_with = "arena_deserializer::arena", borrow)]
    pub comments: Option<&'a [(&'a pos::Pos<'a>, Comment<'a>)]>,
}
impl<'a> TrivialDrop for FileInfo<'a> {}
arena_deserializer::impl_deserialize_in_arena!(FileInfo<'arena>);

pub use oxidized::file_info::Names;

/// The simplified record stored in saved-state.
#[derive(
    Clone,
    Debug,
    Deserialize,
    Eq,
    FromOcamlRepIn,
    Hash,
    NoPosHash,
    Ord,
    PartialEq,
    PartialOrd,
    Serialize,
    ToOcamlRep
)]
#[rust_to_ocaml(prefix = "sn_")]
#[repr(C)]
pub struct SavedNames<'a> {
    #[serde(deserialize_with = "arena_deserializer::arena", borrow)]
    pub funs: s_set::SSet<'a>,
    #[serde(deserialize_with = "arena_deserializer::arena", borrow)]
    pub classes: s_set::SSet<'a>,
    #[serde(deserialize_with = "arena_deserializer::arena", borrow)]
    pub types: s_set::SSet<'a>,
    #[serde(deserialize_with = "arena_deserializer::arena", borrow)]
    pub consts: s_set::SSet<'a>,
    #[serde(deserialize_with = "arena_deserializer::arena", borrow)]
    pub modules: s_set::SSet<'a>,
}
impl<'a> TrivialDrop for SavedNames<'a> {}
arena_deserializer::impl_deserialize_in_arena!(SavedNames<'arena>);

#[derive(
    Clone,
    Debug,
    Deserialize,
    Eq,
    FromOcamlRepIn,
    Hash,
    NoPosHash,
    Ord,
    PartialEq,
    PartialOrd,
    Serialize,
    ToOcamlRep
)]
#[repr(C)]
pub struct Diff<'a> {
    #[serde(deserialize_with = "arena_deserializer::arena", borrow)]
    pub removed_funs: s_set::SSet<'a>,
    #[serde(deserialize_with = "arena_deserializer::arena", borrow)]
    pub added_funs: s_set::SSet<'a>,
    #[serde(deserialize_with = "arena_deserializer::arena", borrow)]
    pub removed_classes: s_set::SSet<'a>,
    #[serde(deserialize_with = "arena_deserializer::arena", borrow)]
    pub added_classes: s_set::SSet<'a>,
    #[serde(deserialize_with = "arena_deserializer::arena", borrow)]
    pub removed_types: s_set::SSet<'a>,
    #[serde(deserialize_with = "arena_deserializer::arena", borrow)]
    pub added_types: s_set::SSet<'a>,
    #[serde(deserialize_with = "arena_deserializer::arena", borrow)]
    pub removed_consts: s_set::SSet<'a>,
    #[serde(deserialize_with = "arena_deserializer::arena", borrow)]
    pub added_consts: s_set::SSet<'a>,
    #[serde(deserialize_with = "arena_deserializer::arena", borrow)]
    pub removed_modules: s_set::SSet<'a>,
    #[serde(deserialize_with = "arena_deserializer::arena", borrow)]
    pub added_modules: s_set::SSet<'a>,
}
impl<'a> TrivialDrop for Diff<'a> {}
arena_deserializer::impl_deserialize_in_arena!(Diff<'arena>);
