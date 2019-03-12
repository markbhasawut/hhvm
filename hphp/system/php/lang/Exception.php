<?hh // partial

namespace {

class Exception implements Throwable {
  use \__SystemLib\BaseException;

  private static $traceOpts = 0;

  final public static function getTraceOptions() {
    return self::$traceOpts;
  }

  final public static function setTraceOptions($opts) {
    self::$traceOpts = (int)$opts;
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/exception.construct.php )
   *
   * Constructs the Exception.
   *
   * @message    mixed   The Exception message to throw.
   * @code       mixed   The Exception code.
   * @previous   mixed   The previous exception used for the exception
   *                     chaining.
   */
  <<__Rx>>
  public function __construct($message = '', $code = 0,
                              <<__MaybeMutable>> ?Throwable $previous = null) {

    // Child classes may just override the protected property
    // without implementing a constructor or calling parent one.
    // In this case we should not override it from the param.

    if ($message !== '' || $this->message === '') {
      $this->message = $message;
    }

    if ($code !== 0 || $this->code === 0) {
      $this->code = $code;
    }

    $this->previous = $previous;
  }
}

}
