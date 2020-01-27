// Copyright (c) Facebook, Inc. and its affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the "hack" directory of this source tree.
use emit_fatal_rust as emit_fatal;
use hhas_type::{constraint, Info};
use hhbc_id_rust::{class, Id as ClassId};
use hhbc_string_utils_rust as string_utils;
use instruction_sequence_rust::Result;
use naming_special_names_rust::{classes, typehints};
use oxidized::{
    aast_defs::{Hint, Hint_, Hint_::*, NastShapeInfo, ShapeFieldInfo, Tprim},
    ast_defs::{Id, ShapeFieldName},
    pos::Pos,
};

pub enum Kind {
    Property,
    Return,
    Param,
    TypeDef,
    UpperBound,
}

fn fmt_name_or_prim(tparams: &[&str], name: String) -> String {
    if tparams.contains(&name.as_str())
        || string_utils::is_self(&name)
        || string_utils::is_parent(&name)
    {
        name
    } else {
        let id = class::Type::from_ast_name(&name);
        if string_utils::is_xhp(&string_utils::strip_ns(&name)) {
            id.to_unmangled_str()
        } else {
            id.into()
        }
    }
}

pub fn prim_to_string(prim: &Tprim) -> String {
    use Tprim::*;
    let res = match prim {
        Tnull => typehints::NULL,
        Tvoid => typehints::VOID,
        Tint => typehints::INT,
        Tbool => typehints::BOOL,
        Tfloat => typehints::FLOAT,
        Tstring => typehints::STRING,
        Tresource => typehints::RESOURCE,
        Tnum => typehints::NUM,
        Tarraykey => typehints::ARRAYKEY,
        Tnoreturn => typehints::NORETURN,
        Tatom(s) => return format!(":@{}", s),
    };
    String::from(res)
}

pub fn fmt_hint(tparams: &[&str], strip_tparams: bool, hint: Hint) -> String {
    let Hint(_, h) = hint;
    match *h {
        Happly(Id(_, id), args) => {
            let name = fmt_name_or_prim(tparams, id);
            if args.is_empty() || strip_tparams {
                name
            } else {
                format!("{}<{}>", name, fmt_hints(tparams, args))
            }
        }
        Hfun(hf) => {
            // TODO(mqian): Implement for inout parameters
            if hf.is_coroutine {
                panic!("Codegen for coroutine functions is not supported")
            } else {
                format!(
                    "(function ({}): {})",
                    fmt_hints(tparams, hf.param_tys),
                    fmt_hint(tparams, false, hf.return_ty)
                )
            }
        }
        Haccess(Hint(_, hint), accesses) => {
            if let Happly(Id(_, id), _) = *hint {
                format!(
                    "{}::{}",
                    fmt_name_or_prim(tparams, id),
                    accesses
                        .into_iter()
                        .map(|Id(_, s)| s)
                        .collect::<Vec<_>>()
                        .join("::")
                )
            } else {
                panic!("ast_to_nast error. Should be Haccess(Happly())")
            }
        }
        Hoption(hint) => {
            let Hint(p, h) = hint;
            if let Hsoft(t) = *h {
                // Follow HHVM order: soft -> option
                // Can we fix this eventually?
                format!("@?{}", fmt_hint(tparams, false, t))
            } else {
                format!("?{}", fmt_hint(tparams, false, Hint(p, h)))
            }
        }
        // No guarantee that this is in the correct order when using map instead of list
        //  TODO: Check whether shape fields need to retain order *)
        Hshape(NastShapeInfo { field_map, .. }) => {
            let fmt_field_name = |name| match name {
                ShapeFieldName::SFlitInt((_, s)) => s,
                ShapeFieldName::SFlitStr((_, s)) => format!("'{}'", s),
                ShapeFieldName::SFclassConst(Id(_, cid), (_, s)) => {
                    format!("{}::{}", fmt_name_or_prim(tparams, cid), s)
                }
            };
            let fmt_field = |field: ShapeFieldInfo| {
                let prefix = if field.optional { "?" } else { "" };
                format!(
                    "{}{}=>{}",
                    prefix,
                    fmt_field_name(field.name),
                    fmt_hint(tparams, false, field.hint)
                )
            };
            let shape_fields = field_map
                .into_iter()
                .map(fmt_field)
                .collect::<Vec<_>>()
                .join(", ");
            string_utils::prefix_namespace("HH", &format!("shape({})", shape_fields).as_str())
        }
        Htuple(hints) => format!("({})", fmt_hints(tparams, hints.to_owned())),
        Hlike(t) => format!("~{}", fmt_hint(tparams, false, t.to_owned())),
        Hsoft(t) => format!("@{}", fmt_hint(tparams, false, t.to_owned())),
        HpuAccess(h, Id(_, id)) => format!("({}:@{})", fmt_hint(tparams, false, h.to_owned()), id),
        Herr | Hany => panic!("This should be an error caught in naming"),
        h => fmt_name_or_prim(tparams, hint_to_string(&h)),
    }
}

fn hint_to_string(h: &Hint_) -> String {
    let res = match h {
        Hprim(p) => return prim_to_string(p),
        Hmixed | Hunion(_) | Hintersection(_) => typehints::MIXED,
        Hnonnull => typehints::NONNULL,
        Habstr(s) => s,
        Harray(_, _) => typehints::ARRAY,
        Hdarray(_, _) => typehints::DARRAY,
        Hvarray(_) => typehints::VARRAY,
        HvarrayOrDarray(_, _) => typehints::VARRAY_OR_DARRAY,
        Hthis => typehints::THIS,
        Hdynamic => typehints::DYNAMIC,
        Hnothing => typehints::NOTHING,
        _ => panic!("shouldn't invoke this function"),
    };
    String::from(res)
}

fn fmt_hints(tparams: &[&str], hints: Vec<Hint>) -> String {
    hints
        .into_iter()
        .map(|h| fmt_hint(tparams, false, h))
        .collect::<Vec<_>>()
        .join(", ")
}

fn can_be_nullable(hint: &Hint_) -> bool {
    match hint {
        Haccess(_, _) | Hfun(_) | Hdynamic | Hnonnull | Hmixed => false,
        Hoption(Hint(_, h)) => {
            if let Haccess(_, _) = **h {
                true
            } else {
                can_be_nullable(&**h)
            }
        }
        Happly(Id(_, id), _) => {
            id != "\\HH\\dynamic" && id != "\\HH\\nonnull" && id != "\\HH\\mixed"
        }
        Herr | Hany => panic!("This should be an error caught in naming"),
        _ => true,
    }
}

fn hint_to_type_constraint(
    kind: &Kind,
    tparams: &[&str],
    skipawaitable: bool,
    h: &Hint,
) -> constraint::Type {
    use constraint::{Flags, Type};
    let Hint(pos, hint) = h;
    match &**hint {
        Hdynamic | Hlike(_) | Hfun(_) | Hunion(_) | Hintersection(_) | Hmixed | HpuAccess(_, _) => {
            Type::default()
        }
        Haccess(_, _) => Type::make_with_raw_str("", Flags::EXTENDED_HINT | Flags::TYPE_CONSTANT),
        Hshape(_) => Type::make_with_raw_str("HH\\darray", Flags::EXTENDED_HINT),
        Htuple(_) => Type::make_with_raw_str("HH\\varray", Flags::EXTENDED_HINT),
        Hsoft(t) => make_tc_with_flags_if_non_empty_flags(
            kind,
            tparams,
            skipawaitable,
            t,
            Flags::SOFT | Flags::EXTENDED_HINT,
        ),
        Herr | Hany => panic!("This should be an error caught in naming"),
        Hoption(t) => {
            if let Happly(Id(_, s), hs) = &**hint {
                if skipawaitable && is_awaitable(&s) {
                    match &hs[..] {
                        [] => return Type::default(),
                        [h] => return hint_to_type_constraint(kind, tparams, false, h),
                        _ => (),
                    }
                }
            } else if let Hsoft(Hint(_, h)) = &**hint {
                if let Happly(Id(_, s), hs) = &**h {
                    if skipawaitable && is_awaitable(&s) {
                        if let [h] = &hs[..] {
                            return make_tc_with_flags_if_non_empty_flags(
                                kind,
                                tparams,
                                skipawaitable,
                                h,
                                Flags::SOFT | Flags::EXTENDED_HINT,
                            );
                        }
                    }
                }
            }
            make_tc_with_flags_if_non_empty_flags(
                kind,
                tparams,
                skipawaitable,
                t,
                Flags::NULLABLE | Flags::DISPLAY_NULLABLE | Flags::EXTENDED_HINT,
            )
        }
        Happly(Id(_, s), hs) => {
            match &hs[..] {
                [] => {
                    if s == "\\HH\\dynamic"
                        || s == "\\HH\\mixed"
                        || (skipawaitable && is_awaitable(s))
                        || (s.eq_ignore_ascii_case("\\hh\\void") && !is_typedef(&kind))
                    {
                        return Type::default();
                    }
                }
                [Hint(_, h)] => {
                    if skipawaitable && is_awaitable(s) {
                        match &**h {
                            Hprim(Tprim::Tvoid) => return Type::default(),
                            Happly(Id(_, s), hs) => {
                                if s == "\\HH\\void" && hs.is_empty() {
                                    return Type::default();
                                }
                            }
                            _ => (),
                        }
                    }
                }
                _ => (),
            };
            happly_helper(tparams, kind, pos, s.to_string()).unwrap()
        }
        h => happly_helper(tparams, kind, pos, hint_to_string(h)).unwrap(),
    }
}

fn is_awaitable(s: &str) -> bool {
    s == classes::AWAITABLE
}

fn is_typedef(kind: &Kind) -> bool {
    if let Kind::TypeDef = kind {
        true
    } else {
        false
    }
}

fn make_tc_with_flags_if_non_empty_flags(
    kind: &Kind,
    tparams: &[&str],
    skipawaitable: bool,
    hint: &Hint,
    flags: constraint::Flags,
) -> constraint::Type {
    let tc = hint_to_type_constraint(kind, tparams, skipawaitable, hint);
    match (&tc.name, &tc.flags.bits()) {
        (None, 0) => tc,
        _ => constraint::Type::make(tc.name, flags | tc.flags),
    }
}

fn happly_helper(
    tparams: &[&str],
    kind: &Kind,
    pos: &Pos,
    name: String,
) -> Result<constraint::Type> {
    use constraint::{Flags, Type};
    if tparams.contains(&name.as_str()) {
        Ok(Type::make_with_raw_str(
            "",
            Flags::EXTENDED_HINT | Flags::TYPE_VAR,
        ))
    } else if string_utils::is_self(&name) || string_utils::is_parent(&name) {
        if is_typedef(&kind) {
            Err(emit_fatal::raise_fatal_runtime(
                pos,
                format!("Cannot access {} when no class scope is active", name),
            ))
        } else {
            Ok(Type::make(Some(name), Flags::empty()))
        }
    } else {
        let name: String = class::Type::from_ast_name(&name).into();
        Ok(Type::make(Some(name), Flags::empty()))
    }
}

fn add_nullable(nullable: bool, flags: constraint::Flags) -> constraint::Flags {
    if nullable {
        constraint::Flags::NULLABLE | constraint::Flags::DISPLAY_NULLABLE | flags
    } else {
        flags
    }
}

fn try_add_nullable(nullable: bool, hint: &Hint, flags: constraint::Flags) -> constraint::Flags {
    let Hint(_, h) = hint;
    add_nullable(nullable && can_be_nullable(&**h), flags)
}

fn make_type_info(
    tparams: &[&str],
    h: &Hint,
    tc_name: Option<String>,
    tc_flags: constraint::Flags,
) -> Info {
    let type_info_user_type = Some(fmt_hint(tparams, false, h.to_owned()));
    let type_info_type_constraint = constraint::Type::make(tc_name, tc_flags);
    Info::make(type_info_user_type, type_info_type_constraint)
}

pub fn hint_to_type_info(
    kind: &Kind,
    skipawaitable: bool,
    nullable: bool,
    tparams: &[&str],
    hint: &Hint,
) -> Info {
    let tc = hint_to_type_constraint(kind, tparams, skipawaitable, hint);
    if let Kind::Param = kind {
        return make_type_info(
            tparams,
            hint,
            tc.name,
            try_add_nullable(nullable, hint, tc.flags),
        );
    };
    let flags = match kind {
        Kind::Return | Kind::Property if tc.name.is_some() => {
            constraint::Flags::EXTENDED_HINT | tc.flags
        }
        Kind::UpperBound => constraint::Flags::UPPERBOUND | tc.flags,
        _ => tc.flags,
    };
    make_type_info(
        tparams,
        hint,
        tc.name,
        if is_typedef(kind) {
            add_nullable(nullable, flags)
        } else {
            try_add_nullable(nullable, hint, flags)
        },
    )
}

pub fn hint_to_class<'a>(hint: &'a Hint) -> class::Type<'a> {
    let Hint(_, h) = hint;
    if let Happly(Id(_, name), _) = &**h {
        class::Type::from_ast_name(&name)
    } else {
        class::from_raw_string("__type_is_not_class__")
    }
}

pub fn emit_type_constraint_for_native_function(
    tparams: &[&str],
    ret_opt: &Option<(Pos, Hint_)>,
    ti: Info,
) -> Info {
    use constraint::Flags;
    let (name, flags) = match (&ti.user_type, ret_opt) {
        (_, None) | (None, _) => (Some(String::from("HH\\void")), Flags::EXTENDED_HINT),
        (Some(t), _) => {
            if t == "HH\\mixed" || t == "callable" {
                (None, Flags::default())
            } else {
                let (_, h) = ret_opt.as_ref().unwrap();
                let name = Some(
                    string_utils::strip_type_list(
                        t.trim_start_matches("?")
                            .trim_start_matches("@")
                            .trim_start_matches("?"),
                    )
                    .to_string(),
                );
                (name, get_flags(tparams, Flags::EXTENDED_HINT, &h))
            }
        }
    };
    let tc = constraint::Type::make(name, flags);
    Info::make(ti.user_type, tc)
}

fn get_flags(tparams: &[&str], flags: constraint::Flags, hint: &Hint_) -> constraint::Flags {
    use constraint::Flags;
    match hint {
        Hoption(x) => {
            let Hint(_, h) = x;
            Flags::NULLABLE | Flags::DISPLAY_NULLABLE | get_flags(tparams, flags, &**h)
        }
        Hsoft(x) => {
            let Hint(_, h) = x;
            Flags::SOFT | get_flags(tparams, flags, &**h)
        }
        Haccess(_, _) => Flags::TYPE_CONSTANT | flags,
        Happly(Id(_, s), _) if tparams.contains(&s.as_str()) => Flags::TYPE_VAR | flags,
        _ => flags,
    }
}
