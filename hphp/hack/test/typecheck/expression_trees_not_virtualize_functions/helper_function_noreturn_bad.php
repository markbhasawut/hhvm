<?hh

<<file:__EnableUnstableFeatures('expression_trees')>>

class Foo {
  public static async function bar(ExampleContext $_):
    Awaitable<ExprTree<ExampleDsl, ExampleDsl::TAst, (function(): noreturn)>>
  {
    throw new Exception();
  }
}

function baz(ExampleContext $_):
  Awaitable<ExprTree<ExampleDsl, ExampleDsl::TAst, (function(): noreturn)>>
{
  throw new Exception();
}

function test<T>(Spliceable<ExampleDsl, ExampleDsl::TAst, (function(T): T)> $x): void {
  ExampleDsl`${ $x }(Foo::bar())`;
  ExampleDsl`${ $x }(baz())`;
}
