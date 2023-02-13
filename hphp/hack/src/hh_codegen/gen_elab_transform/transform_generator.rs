// Copyright (c) Facebook, Inc. and its affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the "hack" directory of this source tree.

#![allow(unused)]

use proc_macro2::TokenStream;
use quote::quote;

use super::contains_ocaml_attr;
use super::Context;
use super::Direction;
use crate::common::to_snake;

pub fn gen(ctx: &Context) -> TokenStream {
    let manual_impls = gen_manual_impls();
    let impls: Vec<_> = ctx
        .type_structures()
        .map(|s| gen_transform_and_traverse(ctx, s))
        .collect();

    quote! {
        #![allow(unused_variables)]

        use std::ops::ControlFlow::Break;

        use oxidized::ast_defs::*;
        use oxidized::aast_defs::*;

        mod pass;
        pub use pass::Pass;
        pub use pass::Passes;

        pub trait Transform<Cfg, Err> {
            #[inline(always)]
            fn transform(
                &mut self,
                cfg: &Cfg,
                errs: &mut Vec<Err>,
                pass: &mut (impl Pass<Cfg = Cfg, Err = Err> + Clone),
            ) {
                self.traverse(cfg, errs, pass);
            }
            #[inline(always)]
            fn traverse(
                &mut self,
                cfg: &Cfg,
                errs: &mut Vec<Err>,
                pass: &mut (impl Pass<Cfg = Cfg, Err = Err> + Clone),
            ) {}
        }

        impl<Cfg, Err> Transform<Cfg, Err> for () {}
        impl<Cfg, Err> Transform<Cfg, Err> for bool {}
        impl<Cfg, Err> Transform<Cfg, Err> for isize {}
        impl<Cfg, Err> Transform<Cfg, Err> for String {}
        impl<Cfg, Err> Transform<Cfg, Err> for bstr::BString {}
        impl<Cfg, Err> Transform<Cfg, Err> for oxidized::pos::Pos {}
        impl<Cfg, Err> Transform<Cfg, Err> for oxidized::file_info::Mode {}
        impl<Cfg, Err> Transform<Cfg, Err> for oxidized::namespace_env::Env {}
        impl<Cfg, Err, Ex> Transform<Cfg, Err> for oxidized::LocalIdMap<(Pos, Ex)> {}

        #(#manual_impls)*

        #(#impls)*
    }
}

fn gen_transform_and_traverse(ctx: &Context, mut s: synstructure::Structure<'_>) -> TokenStream {
    // By default, if you are deriving an impl of trait Foo for generic type
    // X<T>, synstructure will add Foo as a bound not only for the type
    // parameter T, but also for every type which appears as a field in X. This
    // is not necessary for our use case--we can just require that the type
    // parameters implement our trait.
    s.add_bounds(synstructure::AddBounds::Generics);

    // We are mutating the AST and need &mut references to fields.
    s.bind_with(|_bi| synstructure::BindStyle::RefMut);

    // Cleaner generated syntax for `gen impl` hygiene. Not supported by Rust
    // versions before 1.37. We don't really need the hygiene at all (the quote
    // we pass to `gen_impl` doesn't define any items other than the trait
    // impl), but I don't think there's a way to turn it off.
    s.underscore_const(true);

    // If the type is marked opaque, generate a no-op Transform impl.
    if contains_ocaml_attr(&s.ast().attrs, "transform.opaque") {
        return s.gen_impl(quote! {
            gen impl<Cfg, Err> Transform<Cfg, Err> for @Self {}
        });
    }

    // Don't visit fields or variants marked opaque.
    s.filter(|bi| !contains_ocaml_attr(&bi.ast().attrs, "transform.opaque"));
    s.filter_variants(|v| !contains_ocaml_attr(v.ast().attrs, "transform.opaque"));

    let ty_name = s.ast().ident.to_string();
    let transform_body = gen_transform_body(
        &super::gen_pass_method_name(&ty_name, Direction::TopDown),
        &super::gen_pass_method_name(&ty_name, Direction::BottomUp),
        quote!(self),
        quote!(self.traverse(cfg, errs, pass)),
    );
    let traverse_body = gen_traverse_body(&ty_name, &s);
    let ex_bound = if s.referenced_ty_params().iter().any(|tp| *tp == "Ex") {
        quote!(where Ex: Default)
    } else {
        quote!()
    };

    s.gen_impl(quote! {
        gen impl<Cfg, Err> Transform<Cfg, Err> for @Self
            #ex_bound
        {
            fn transform(
                &mut self,
                cfg: &Cfg,
                errs: &mut Vec<Err>,
                pass: &mut (impl Pass<Cfg = Cfg, Err = Err> + Clone),
            ) {
                #transform_body
            }

            fn traverse(
                &mut self,
                cfg: &Cfg,
                errs: &mut Vec<Err>,
                pass: &mut (impl Pass<Cfg = Cfg, Err = Err> + Clone),
            ) {
                match self { #traverse_body }
            }
        }
    })
}

fn gen_traverse_body(ty_name: &str, s: &synstructure::Structure<'_>) -> TokenStream {
    s.variants()
        .iter()
        .map(|v| gen_variant_traverse(ty_name, v))
        .chain(std::iter::once(if s.omitted_variants() {
            quote!(_ => {})
        } else {
            quote!()
        }))
        .collect()
}

fn gen_variant_traverse(ty_name: &str, v: &synstructure::VariantInfo<'_>) -> TokenStream {
    if !contains_ocaml_attr(v.ast().attrs, "transform.explicit") {
        return v.each(|bi| gen_fld_traverse(ty_name, bi));
    }
    let pass_method_td =
        super::gen_pass_ctor_method_name(ty_name, v.ast().ident.to_string(), Direction::TopDown);
    let pass_method_bu =
        super::gen_pass_ctor_method_name(ty_name, v.ast().ident.to_string(), Direction::BottomUp);
    if v.ast().fields.len() != 1 {
        panic!("transform.explicit only supports variants with 1 field")
    }
    v.each(|bi| {
        gen_transform_body(
            &pass_method_td,
            &pass_method_bu,
            quote!(#bi),
            quote! { #bi.transform(cfg, errs, pass) },
        )
    })
}

fn gen_fld_traverse(ty_name: &str, bi: &synstructure::BindingInfo<'_>) -> TokenStream {
    let transform_bi = quote! { #bi.transform(cfg, errs, pass) };
    if !contains_ocaml_attr(&bi.ast().attrs, "transform.explicit") {
        return transform_bi;
    }
    // Since Transform is a trait, we can't have special implementations
    // of Transform::transform for fields. Instead, we inline the
    // transform_fld function here (in the Transform::traverse body).
    let pass_method_td = super::gen_pass_fld_method_name(
        ty_name,
        (bi.ast().ident.as_ref())
            .map(|i| i.to_string())
            .unwrap_or_default(),
        Direction::TopDown,
    );
    let pass_method_bu = super::gen_pass_fld_method_name(
        ty_name,
        (bi.ast().ident.as_ref())
            .map(|i| i.to_string())
            .unwrap_or_default(),
        Direction::BottomUp,
    );
    gen_transform_body(&pass_method_td, &pass_method_bu, quote!(#bi), transform_bi)
}

fn gen_transform_body(
    pass_method_td: &syn::Ident,
    pass_method_bu: &syn::Ident,
    elem: TokenStream,
    recurse: TokenStream,
) -> TokenStream {
    quote! {
        let mut in_pass = pass.clone();
        if let Break(..) = pass.#pass_method_td(#elem, cfg, errs) {
            return;
        }
        #recurse;
        in_pass.#pass_method_bu(#elem, cfg, errs);
    }
}

fn gen_manual_impls() -> Vec<TokenStream> {
    let transform = quote!(transform(cfg, errs, &mut pass.clone()));

    #[rustfmt::skip]
    let manual_impls = vec![
        (vec!["T"], quote!(&mut T), quote!((**self).#transform)),
        (vec!["T"], quote!(Box<T>), quote!((**self).#transform)),
        (vec!["L", "R"], quote!(itertools::Either<L, R>), quote! {
            match self {
                Self::Left(x) => x.#transform,
                Self::Right(x) => x.#transform,
            }
        }),
        (vec!["T"], quote!(Vec<T>), quote! {
            for x in self.iter_mut() {
                x.#transform;
            }
        }),
        (vec!["T"], quote!(Option<T>), quote! {
            match self {
                Some(x) => x.#transform,
                None => {}
            }
        }),
        (vec!["T"], quote!(oxidized::lazy::Lazy<T>), quote!(self.0.#transform)),
        (vec!["K", "V"], quote!(std::collections::BTreeMap<K, V>), quote! {
            for x in self.values_mut() {
                x.#transform;
            }
        }),
        (vec!["T"], quote!(ocamlrep::rc::RcOc<T>), quote! {
            if let Some(x) = ocamlrep::rc::RcOc::get_mut(self) {
                x.#transform;
            }
        }),
        (vec!["T"], quote!(std::rc::Rc<T>), quote! {
            if let Some(x) = std::rc::Rc::get_mut(self) {
                x.#transform;
            }
        }),
        (vec!["T1", "T2"], quote!((T1, T2)), quote! {
            self.0.#transform;
            self.1.#transform;
        }),
        (vec!["T1", "T2", "T3"], quote!((T1, T2, T3)), quote! {
            self.0.#transform;
            self.1.#transform;
            self.2.#transform;
        }),
        (vec!["T1", "T2", "T3", "T4"], quote!((T1, T2, T3, T4)), quote! {
            self.0.#transform;
            self.1.#transform;
            self.2.#transform;
            self.3.#transform;
        }),
        (vec!["T1", "T2", "T3", "T4", "T5"], quote!((T1, T2, T3, T4, T5)), quote! {
            self.0.#transform;
            self.1.#transform;
            self.2.#transform;
            self.3.#transform;
            self.4.#transform;
        }),
    ];

    manual_impls
        .into_iter()
        .map(|(tp, ty, body)| gen_manual_impl(tp, ty, body))
        .collect()
}

fn gen_manual_impl(
    typarams: Vec<&'static str>,
    ty: TokenStream,
    traverse_body: TokenStream,
) -> TokenStream {
    let typarams: Vec<_> = typarams
        .into_iter()
        .map(|tp| quote::format_ident!("{}", tp))
        .collect();
    quote! {
        impl<Cfg, Err, #(#typarams,)*> Transform<Cfg, Err> for #ty
        where
            #(#typarams: Transform<Cfg, Err>,)*
        {
            fn traverse(
                &mut self,
                cfg: &Cfg,
                errs: &mut Vec<Err>,
                pass: &mut (impl Pass<Cfg = Cfg, Err = Err> + Clone),
            ) {
                #traverse_body
            }
        }
    }
}
