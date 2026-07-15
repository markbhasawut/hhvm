; GENERATED RULES

(rule
 (targets test_constant_ctor_embed_error.actual.ml)
 (deps
  (:pp pp.exe)
  (:input test_constant_ctor_embed_error.ml)
  %{project_root}/hack/.ocamlformat)
 (action
   (progn
     (with-stdout-to %{targets} (run ./%{pp} --impl %{input} -o %{targets}))
      (bash "if command -v arc >/dev/null 2>&1; then arc f %{targets} >/dev/null 2>&1; else ocamlformat --inplace --enable-outside-detected-project %{targets}; fi")
   )
 )
)
(rule
 (alias runtest)
 (action
  (diff test_constant_ctor_embed_error.expected.ml test_constant_ctor_embed_error.actual.ml)))

(rule
 (targets test_inline_record_embed_error.actual.ml)
 (deps
  (:pp pp.exe)
  (:input test_inline_record_embed_error.ml)
  %{project_root}/hack/.ocamlformat)
 (action
   (progn
     (with-stdout-to %{targets} (run ./%{pp} --impl %{input} -o %{targets}))
      (bash "if command -v arc >/dev/null 2>&1; then arc f %{targets} >/dev/null 2>&1; else ocamlformat --inplace --enable-outside-detected-project %{targets}; fi")
   )
 )
)
(rule
 (alias runtest)
 (action
  (diff test_inline_record_embed_error.expected.ml test_inline_record_embed_error.actual.ml)))
