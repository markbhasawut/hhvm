<?hh

class TestSoapClient extends SoapClient {

  function __construct($wsdl, $options) {
    parent::__construct($wsdl, $options);
  }

  function __dorequest($request, $location, $action, $version, $one_way = 0) :mixed{
    return <<<EOF
<SOAP-ENV:Envelope SOAP-ENV:encodingStyle="http://schemas.xmlsoap.org/soap/encoding/" xmlns:SOAP-ENV="http://schemas.xmlsoap.org/soap/envelope/" xmlns:ns1="http://test.com/soap/v3/" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:xsd="http://www.w3.org/2001/XMLSchema" xmlns:SOAP-ENC="http://schemas.xmlsoap.org/soap/encoding/">
   <SOAP-ENV:Body>
      <ns1:getObjectResponse>
         <getObjectReturn xsi:type="ns1:Customer" id="ref1">
            <accountId xsi:type="xsd:int">1234</accountId>
            <parent href="#ref1"/>
         </getObjectReturn>
      </ns1:getObjectResponse>
   </SOAP-ENV:Body>
</SOAP-ENV:Envelope>
EOF;
  }

}
<<__EntryPoint>>
function main_entry(): void {
  ini_set("soap.wsdl_cache_enabled",0);
  $timestamp = "2011-07-30T03:25:00-05:00";
  $wsdl = dirname(__FILE__)."/bug55323.wsdl";

  $soapClient = new TestSoapClient($wsdl,
          dict['trace' => 1, 'exceptions' => 0]);
  $result = $soapClient->__soapcall('getObject', vec[]);
  var_dump($result);
}
