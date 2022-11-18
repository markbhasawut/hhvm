<?hh

class MyClass {
  public function __construct(public int $x) {}

  public function getX(): int {
    // Ensure $x exists, so we only get an error about dynamic method
    // access.
    $x = 'whatever';

    return $this->$x;
  }
}
