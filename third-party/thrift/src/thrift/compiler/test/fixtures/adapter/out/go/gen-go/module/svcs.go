// @generated by Thrift for [[[ program path ]]]
// This file is probably not the place you want to edit!

package module // [[[ program thrift source path ]]]


import (
    "context"
    "fmt"
    "strings"

    thrift "github.com/facebook/fbthrift/thrift/lib/go/thrift"
    metadata "github.com/facebook/fbthrift/thrift/lib/thrift/metadata"
)

// (needed to ensure safety because of naive import list construction)
var _ = context.Background
var _ = fmt.Printf
var _ = strings.Split
var _ = thrift.ZERO
var _ = metadata.GoUnusedProtection__



type Service interface {
    Func(ctx context.Context, arg1 StringWithAdapter_7208, arg2 string, arg3 *Foo) (MyI32_4873, error)
}

type ServiceChannelClientInterface interface {
    thrift.ClientInterface
    Service
}

type ServiceClientInterface interface {
    thrift.ClientInterface
    Func(arg1 StringWithAdapter_7208, arg2 string, arg3 *Foo) (MyI32_4873, error)
}

type ServiceContextClientInterface interface {
    ServiceClientInterface
    FuncContext(ctx context.Context, arg1 StringWithAdapter_7208, arg2 string, arg3 *Foo) (MyI32_4873, error)
}

type ServiceChannelClient struct {
    ch thrift.RequestChannel
}
// Compile time interface enforcer
var _ ServiceChannelClientInterface = (*ServiceChannelClient)(nil)

func NewServiceChannelClient(channel thrift.RequestChannel) *ServiceChannelClient {
    return &ServiceChannelClient{
        ch: channel,
    }
}

func (c *ServiceChannelClient) Close() error {
    return c.ch.Close()
}

type ServiceClient struct {
    chClient *ServiceChannelClient
}
// Compile time interface enforcer
var _ ServiceClientInterface = (*ServiceClient)(nil)
var _ ServiceContextClientInterface = (*ServiceClient)(nil)

func NewServiceClient(prot thrift.Protocol) *ServiceClient {
    return &ServiceClient{
        chClient: NewServiceChannelClient(
            thrift.NewSerialChannel(prot),
        ),
    }
}

func (c *ServiceClient) Close() error {
    return c.chClient.Close()
}

func (c *ServiceChannelClient) Func(ctx context.Context, arg1 StringWithAdapter_7208, arg2 string, arg3 *Foo) (MyI32_4873, error) {
    in := &reqServiceFunc{
        Arg1: arg1,
        Arg2: arg2,
        Arg3: arg3,
    }
    out := newRespServiceFunc()
    err := c.ch.Call(ctx, "func", in, out)
    if err != nil {
        return 0, err
    }
    return out.GetSuccess(), nil
}

func (c *ServiceClient) Func(arg1 StringWithAdapter_7208, arg2 string, arg3 *Foo) (MyI32_4873, error) {
    return c.chClient.Func(context.Background(), arg1, arg2, arg3)
}

func (c *ServiceClient) FuncContext(ctx context.Context, arg1 StringWithAdapter_7208, arg2 string, arg3 *Foo) (MyI32_4873, error) {
    return c.chClient.Func(ctx, arg1, arg2, arg3)
}

type reqServiceFunc struct {
    Arg1 StringWithAdapter_7208 `thrift:"arg1,1" json:"arg1" db:"arg1"`
    Arg2 string `thrift:"arg2,2" json:"arg2" db:"arg2"`
    Arg3 *Foo `thrift:"arg3,3" json:"arg3" db:"arg3"`
}
// Compile time interface enforcer
var _ thrift.Struct = (*reqServiceFunc)(nil)

// Deprecated: ServiceFuncArgsDeprecated is deprecated, since it is supposed to be internal.
type ServiceFuncArgsDeprecated = reqServiceFunc

func newReqServiceFunc() *reqServiceFunc {
    return (&reqServiceFunc{}).
        SetArg1NonCompat(NewStringWithAdapter_7208()).
        SetArg2NonCompat("").
        SetArg3NonCompat(*NewFoo())
}

func (x *reqServiceFunc) GetArg1NonCompat() StringWithAdapter_7208 {
    return x.Arg1
}

func (x *reqServiceFunc) GetArg1() StringWithAdapter_7208 {
    return x.Arg1
}

func (x *reqServiceFunc) GetArg2NonCompat() string {
    return x.Arg2
}

func (x *reqServiceFunc) GetArg2() string {
    return x.Arg2
}

func (x *reqServiceFunc) GetArg3NonCompat() *Foo {
    return x.Arg3
}

func (x *reqServiceFunc) GetArg3() *Foo {
    if !x.IsSetArg3() {
        return nil
    }

    return x.Arg3
}

func (x *reqServiceFunc) SetArg1NonCompat(value StringWithAdapter_7208) *reqServiceFunc {
    x.Arg1 = value
    return x
}

func (x *reqServiceFunc) SetArg1(value StringWithAdapter_7208) *reqServiceFunc {
    x.Arg1 = value
    return x
}

func (x *reqServiceFunc) SetArg2NonCompat(value string) *reqServiceFunc {
    x.Arg2 = value
    return x
}

func (x *reqServiceFunc) SetArg2(value string) *reqServiceFunc {
    x.Arg2 = value
    return x
}

func (x *reqServiceFunc) SetArg3NonCompat(value Foo) *reqServiceFunc {
    x.Arg3 = &value
    return x
}

func (x *reqServiceFunc) SetArg3(value *Foo) *reqServiceFunc {
    x.Arg3 = value
    return x
}

func (x *reqServiceFunc) IsSetArg3() bool {
    return x != nil && x.Arg3 != nil
}

func (x *reqServiceFunc) writeField1(p thrift.Format) error {  // Arg1
    if err := p.WriteFieldBegin("arg1", thrift.STRING, 1); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write field begin error: ", x), err)
    }

    item := x.Arg1
    err := WriteStringWithAdapter_7208(item, p)
if err != nil {
    return err
}

    if err := p.WriteFieldEnd(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write field end error: ", x), err)
    }
    return nil
}

func (x *reqServiceFunc) writeField2(p thrift.Format) error {  // Arg2
    if err := p.WriteFieldBegin("arg2", thrift.STRING, 2); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write field begin error: ", x), err)
    }

    item := x.Arg2
    if err := p.WriteString(item); err != nil {
    return err
}

    if err := p.WriteFieldEnd(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write field end error: ", x), err)
    }
    return nil
}

func (x *reqServiceFunc) writeField3(p thrift.Format) error {  // Arg3
    if !x.IsSetArg3() {
        return nil
    }

    if err := p.WriteFieldBegin("arg3", thrift.STRUCT, 3); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write field begin error: ", x), err)
    }

    item := x.Arg3
    if err := item.Write(p); err != nil {
    return err
}

    if err := p.WriteFieldEnd(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write field end error: ", x), err)
    }
    return nil
}

func (x *reqServiceFunc) readField1(p thrift.Format) error {  // Arg1
    result, err := ReadStringWithAdapter_7208(p)
if err != nil {
    return err
}

    x.Arg1 = result
    return nil
}

func (x *reqServiceFunc) readField2(p thrift.Format) error {  // Arg2
    result, err := p.ReadString()
if err != nil {
    return err
}

    x.Arg2 = result
    return nil
}

func (x *reqServiceFunc) readField3(p thrift.Format) error {  // Arg3
    result := *NewFoo()
err := result.Read(p)
if err != nil {
    return err
}

    x.Arg3 = &result
    return nil
}

func (x *reqServiceFunc) toString1() string {  // Arg1
    return fmt.Sprintf("%v", x.Arg1)
}

func (x *reqServiceFunc) toString2() string {  // Arg2
    return fmt.Sprintf("%v", x.Arg2)
}

func (x *reqServiceFunc) toString3() string {  // Arg3
    return fmt.Sprintf("%v", x.Arg3)
}

// Deprecated: Use newReqServiceFunc().GetArg3() instead.
func (x *reqServiceFunc) DefaultGetArg3() *Foo {
    if !x.IsSetArg3() {
        return NewFoo()
    }
    return x.Arg3
}



func (x *reqServiceFunc) Write(p thrift.Format) error {
    if err := p.WriteStructBegin("reqServiceFunc"); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write struct begin error: ", x), err)
    }

    if err := x.writeField1(p); err != nil {
        return err
    }

    if err := x.writeField2(p); err != nil {
        return err
    }

    if err := x.writeField3(p); err != nil {
        return err
    }

    if err := p.WriteFieldStop(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write field stop error: ", x), err)
    }

    if err := p.WriteStructEnd(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write struct end error: ", x), err)
    }
    return nil
}

func (x *reqServiceFunc) Read(p thrift.Format) error {
    if _, err := p.ReadStructBegin(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T read error: ", x), err)
    }

    for {
        _, wireType, id, err := p.ReadFieldBegin()
        if err != nil {
            return thrift.PrependError(fmt.Sprintf("%T field %d read error: ", x, id), err)
        }

        if wireType == thrift.STOP {
            break;
        }

        switch {
        case (id == 1 && wireType == thrift.Type(thrift.STRING)):  // arg1
            if err := x.readField1(p); err != nil {
                return err
            }
        case (id == 2 && wireType == thrift.Type(thrift.STRING)):  // arg2
            if err := x.readField2(p); err != nil {
                return err
            }
        case (id == 3 && wireType == thrift.Type(thrift.STRUCT)):  // arg3
            if err := x.readField3(p); err != nil {
                return err
            }
        default:
            if err := p.Skip(wireType); err != nil {
                return err
            }
        }

        if err := p.ReadFieldEnd(); err != nil {
            return err
        }
    }

    if err := p.ReadStructEnd(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T read struct end error: ", x), err)
    }

    return nil
}

func (x *reqServiceFunc) String() string {
    if x == nil {
        return "<nil>"
    }

    var sb strings.Builder

    sb.WriteString("reqServiceFunc({")
    sb.WriteString(fmt.Sprintf("Arg1:%s ", x.toString1()))
    sb.WriteString(fmt.Sprintf("Arg2:%s ", x.toString2()))
    sb.WriteString(fmt.Sprintf("Arg3:%s", x.toString3()))
    sb.WriteString("})")

    return sb.String()
}
type respServiceFunc struct {
    Success *MyI32_4873 `thrift:"success,0,optional" json:"success,omitempty" db:"success"`
}
// Compile time interface enforcer
var _ thrift.Struct = (*respServiceFunc)(nil)
var _ thrift.WritableResult = (*respServiceFunc)(nil)

// Deprecated: ServiceFuncResultDeprecated is deprecated, since it is supposed to be internal.
type ServiceFuncResultDeprecated = respServiceFunc

func newRespServiceFunc() *respServiceFunc {
    return (&respServiceFunc{})
}

func (x *respServiceFunc) GetSuccessNonCompat() *MyI32_4873 {
    return x.Success
}

func (x *respServiceFunc) GetSuccess() MyI32_4873 {
    if !x.IsSetSuccess() {
        return NewMyI32_4873()
    }

    return *x.Success
}

func (x *respServiceFunc) SetSuccessNonCompat(value MyI32_4873) *respServiceFunc {
    x.Success = &value
    return x
}

func (x *respServiceFunc) SetSuccess(value *MyI32_4873) *respServiceFunc {
    x.Success = value
    return x
}

func (x *respServiceFunc) IsSetSuccess() bool {
    return x != nil && x.Success != nil
}

func (x *respServiceFunc) writeField0(p thrift.Format) error {  // Success
    if !x.IsSetSuccess() {
        return nil
    }

    if err := p.WriteFieldBegin("success", thrift.I32, 0); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write field begin error: ", x), err)
    }

    item := *x.Success
    err := WriteMyI32_4873(item, p)
if err != nil {
    return err
}

    if err := p.WriteFieldEnd(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write field end error: ", x), err)
    }
    return nil
}

func (x *respServiceFunc) readField0(p thrift.Format) error {  // Success
    result, err := ReadMyI32_4873(p)
if err != nil {
    return err
}

    x.Success = &result
    return nil
}

func (x *respServiceFunc) toString0() string {  // Success
    if x.IsSetSuccess() {
        return fmt.Sprintf("%v", *x.Success)
    }
    return fmt.Sprintf("%v", x.Success)
}




func (x *respServiceFunc) Exception() thrift.WritableException {
    return nil
}

func (x *respServiceFunc) Write(p thrift.Format) error {
    if err := p.WriteStructBegin("respServiceFunc"); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write struct begin error: ", x), err)
    }

    if err := x.writeField0(p); err != nil {
        return err
    }

    if err := p.WriteFieldStop(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write field stop error: ", x), err)
    }

    if err := p.WriteStructEnd(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write struct end error: ", x), err)
    }
    return nil
}

func (x *respServiceFunc) Read(p thrift.Format) error {
    if _, err := p.ReadStructBegin(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T read error: ", x), err)
    }

    for {
        _, wireType, id, err := p.ReadFieldBegin()
        if err != nil {
            return thrift.PrependError(fmt.Sprintf("%T field %d read error: ", x, id), err)
        }

        if wireType == thrift.STOP {
            break;
        }

        switch {
        case (id == 0 && wireType == thrift.Type(thrift.I32)):  // success
            if err := x.readField0(p); err != nil {
                return err
            }
        default:
            if err := p.Skip(wireType); err != nil {
                return err
            }
        }

        if err := p.ReadFieldEnd(); err != nil {
            return err
        }
    }

    if err := p.ReadStructEnd(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T read struct end error: ", x), err)
    }

    return nil
}

func (x *respServiceFunc) String() string {
    if x == nil {
        return "<nil>"
    }

    var sb strings.Builder

    sb.WriteString("respServiceFunc({")
    sb.WriteString(fmt.Sprintf("Success:%s", x.toString0()))
    sb.WriteString("})")

    return sb.String()
}


type ServiceProcessor struct {
    processorMap       map[string]thrift.ProcessorFunctionContext
    functionServiceMap map[string]string
    handler            Service
}
// Compile time interface enforcer
var _ thrift.ProcessorContext = (*ServiceProcessor)(nil)

func NewServiceProcessor(handler Service) *ServiceProcessor {
    p := &ServiceProcessor{
        handler:            handler,
        processorMap:       make(map[string]thrift.ProcessorFunctionContext),
        functionServiceMap: make(map[string]string),
    }
    p.AddToProcessorMap("func", &procFuncServiceFunc{handler: handler})
    p.AddToFunctionServiceMap("func", "Service")

    return p
}

func (p *ServiceProcessor) AddToProcessorMap(key string, processor thrift.ProcessorFunctionContext) {
    p.processorMap[key] = processor
}

func (p *ServiceProcessor) AddToFunctionServiceMap(key, service string) {
    p.functionServiceMap[key] = service
}

func (p *ServiceProcessor) GetProcessorFunctionContext(key string) (processor thrift.ProcessorFunctionContext, err error) {
    if processor, ok := p.processorMap[key]; ok {
        return processor, nil
    }
    return nil, nil
}

func (p *ServiceProcessor) ProcessorMap() map[string]thrift.ProcessorFunctionContext {
    return p.processorMap
}

func (p *ServiceProcessor) FunctionServiceMap() map[string]string {
    return p.functionServiceMap
}

func (p *ServiceProcessor) GetThriftMetadata() *metadata.ThriftMetadata {
    return GetThriftMetadataForService("module.Service")
}


type procFuncServiceFunc struct {
    handler Service
}
// Compile time interface enforcer
var _ thrift.ProcessorFunctionContext = (*procFuncServiceFunc)(nil)

func (p *procFuncServiceFunc) Read(iprot thrift.Format) (thrift.Struct, thrift.Exception) {
    args := newReqServiceFunc()
    if err := args.Read(iprot); err != nil {
        return nil, err
    }
    iprot.ReadMessageEnd()
    return args, nil
}

func (p *procFuncServiceFunc) Write(seqId int32, result thrift.WritableStruct, oprot thrift.Format) (err thrift.Exception) {
    var err2 error
    messageType := thrift.REPLY
    switch result.(type) {
    case thrift.ApplicationException:
        messageType = thrift.EXCEPTION
    }

    if err2 = oprot.WriteMessageBegin("func", messageType, seqId); err2 != nil {
        err = err2
    }
    if err2 = result.Write(oprot); err == nil && err2 != nil {
        err = err2
    }
    if err2 = oprot.WriteMessageEnd(); err == nil && err2 != nil {
        err = err2
    }
    if err2 = oprot.Flush(); err == nil && err2 != nil {
        err = err2
    }
    return err
}

func (p *procFuncServiceFunc) RunContext(ctx context.Context, reqStruct thrift.Struct) (thrift.WritableStruct, thrift.ApplicationException) {
    args := reqStruct.(*reqServiceFunc)
    result := newRespServiceFunc()
    retval, err := p.handler.Func(ctx, args.Arg1, args.Arg2, args.Arg3)
    if err != nil {
        x := thrift.NewApplicationExceptionCause(thrift.INTERNAL_ERROR, "Internal error processing Func: " + err.Error(), err)
        return x, x
    }

    result.Success = &retval
    return result, nil
}




type AdapterService interface {
    Count(ctx context.Context) (*CountingStruct, error)
    AdaptedTypes(ctx context.Context, arg *HeapAllocated) (*HeapAllocated, error)
}

type AdapterServiceChannelClientInterface interface {
    thrift.ClientInterface
    AdapterService
}

type AdapterServiceClientInterface interface {
    thrift.ClientInterface
    Count() (*CountingStruct, error)
    AdaptedTypes(arg *HeapAllocated) (*HeapAllocated, error)
}

type AdapterServiceContextClientInterface interface {
    AdapterServiceClientInterface
    CountContext(ctx context.Context) (*CountingStruct, error)
    AdaptedTypesContext(ctx context.Context, arg *HeapAllocated) (*HeapAllocated, error)
}

type AdapterServiceChannelClient struct {
    ch thrift.RequestChannel
}
// Compile time interface enforcer
var _ AdapterServiceChannelClientInterface = (*AdapterServiceChannelClient)(nil)

func NewAdapterServiceChannelClient(channel thrift.RequestChannel) *AdapterServiceChannelClient {
    return &AdapterServiceChannelClient{
        ch: channel,
    }
}

func (c *AdapterServiceChannelClient) Close() error {
    return c.ch.Close()
}

type AdapterServiceClient struct {
    chClient *AdapterServiceChannelClient
}
// Compile time interface enforcer
var _ AdapterServiceClientInterface = (*AdapterServiceClient)(nil)
var _ AdapterServiceContextClientInterface = (*AdapterServiceClient)(nil)

func NewAdapterServiceClient(prot thrift.Protocol) *AdapterServiceClient {
    return &AdapterServiceClient{
        chClient: NewAdapterServiceChannelClient(
            thrift.NewSerialChannel(prot),
        ),
    }
}

func (c *AdapterServiceClient) Close() error {
    return c.chClient.Close()
}

func (c *AdapterServiceChannelClient) Count(ctx context.Context) (*CountingStruct, error) {
    in := &reqAdapterServiceCount{
    }
    out := newRespAdapterServiceCount()
    err := c.ch.Call(ctx, "count", in, out)
    if err != nil {
        return nil, err
    }
    return out.GetSuccess(), nil
}

func (c *AdapterServiceClient) Count() (*CountingStruct, error) {
    return c.chClient.Count(context.Background())
}

func (c *AdapterServiceClient) CountContext(ctx context.Context) (*CountingStruct, error) {
    return c.chClient.Count(ctx)
}

func (c *AdapterServiceChannelClient) AdaptedTypes(ctx context.Context, arg *HeapAllocated) (*HeapAllocated, error) {
    in := &reqAdapterServiceAdaptedTypes{
        Arg: arg,
    }
    out := newRespAdapterServiceAdaptedTypes()
    err := c.ch.Call(ctx, "adaptedTypes", in, out)
    if err != nil {
        return nil, err
    }
    return out.GetSuccess(), nil
}

func (c *AdapterServiceClient) AdaptedTypes(arg *HeapAllocated) (*HeapAllocated, error) {
    return c.chClient.AdaptedTypes(context.Background(), arg)
}

func (c *AdapterServiceClient) AdaptedTypesContext(ctx context.Context, arg *HeapAllocated) (*HeapAllocated, error) {
    return c.chClient.AdaptedTypes(ctx, arg)
}

type reqAdapterServiceCount struct {
}
// Compile time interface enforcer
var _ thrift.Struct = (*reqAdapterServiceCount)(nil)

// Deprecated: AdapterServiceCountArgsDeprecated is deprecated, since it is supposed to be internal.
type AdapterServiceCountArgsDeprecated = reqAdapterServiceCount

func newReqAdapterServiceCount() *reqAdapterServiceCount {
    return (&reqAdapterServiceCount{})
}



func (x *reqAdapterServiceCount) Write(p thrift.Format) error {
    if err := p.WriteStructBegin("reqAdapterServiceCount"); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write struct begin error: ", x), err)
    }

    if err := p.WriteFieldStop(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write field stop error: ", x), err)
    }

    if err := p.WriteStructEnd(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write struct end error: ", x), err)
    }
    return nil
}

func (x *reqAdapterServiceCount) Read(p thrift.Format) error {
    if _, err := p.ReadStructBegin(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T read error: ", x), err)
    }

    for {
        _, wireType, id, err := p.ReadFieldBegin()
        if err != nil {
            return thrift.PrependError(fmt.Sprintf("%T field %d read error: ", x, id), err)
        }

        if wireType == thrift.STOP {
            break;
        }

        switch {
        default:
            if err := p.Skip(wireType); err != nil {
                return err
            }
        }

        if err := p.ReadFieldEnd(); err != nil {
            return err
        }
    }

    if err := p.ReadStructEnd(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T read struct end error: ", x), err)
    }

    return nil
}

func (x *reqAdapterServiceCount) String() string {
    if x == nil {
        return "<nil>"
    }

    var sb strings.Builder

    sb.WriteString("reqAdapterServiceCount({")
    sb.WriteString("})")

    return sb.String()
}
type respAdapterServiceCount struct {
    Success *CountingStruct `thrift:"success,0,optional" json:"success,omitempty" db:"success"`
}
// Compile time interface enforcer
var _ thrift.Struct = (*respAdapterServiceCount)(nil)
var _ thrift.WritableResult = (*respAdapterServiceCount)(nil)

// Deprecated: AdapterServiceCountResultDeprecated is deprecated, since it is supposed to be internal.
type AdapterServiceCountResultDeprecated = respAdapterServiceCount

func newRespAdapterServiceCount() *respAdapterServiceCount {
    return (&respAdapterServiceCount{})
}

func (x *respAdapterServiceCount) GetSuccessNonCompat() *CountingStruct {
    return x.Success
}

func (x *respAdapterServiceCount) GetSuccess() *CountingStruct {
    if !x.IsSetSuccess() {
        return nil
    }

    return x.Success
}

func (x *respAdapterServiceCount) SetSuccessNonCompat(value CountingStruct) *respAdapterServiceCount {
    x.Success = &value
    return x
}

func (x *respAdapterServiceCount) SetSuccess(value *CountingStruct) *respAdapterServiceCount {
    x.Success = value
    return x
}

func (x *respAdapterServiceCount) IsSetSuccess() bool {
    return x != nil && x.Success != nil
}

func (x *respAdapterServiceCount) writeField0(p thrift.Format) error {  // Success
    if !x.IsSetSuccess() {
        return nil
    }

    if err := p.WriteFieldBegin("success", thrift.STRUCT, 0); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write field begin error: ", x), err)
    }

    item := x.Success
    if err := item.Write(p); err != nil {
    return err
}

    if err := p.WriteFieldEnd(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write field end error: ", x), err)
    }
    return nil
}

func (x *respAdapterServiceCount) readField0(p thrift.Format) error {  // Success
    result := *NewCountingStruct()
err := result.Read(p)
if err != nil {
    return err
}

    x.Success = &result
    return nil
}

func (x *respAdapterServiceCount) toString0() string {  // Success
    return fmt.Sprintf("%v", x.Success)
}

// Deprecated: Use newRespAdapterServiceCount().GetSuccess() instead.
func (x *respAdapterServiceCount) DefaultGetSuccess() *CountingStruct {
    if !x.IsSetSuccess() {
        return NewCountingStruct()
    }
    return x.Success
}



func (x *respAdapterServiceCount) Exception() thrift.WritableException {
    return nil
}

func (x *respAdapterServiceCount) Write(p thrift.Format) error {
    if err := p.WriteStructBegin("respAdapterServiceCount"); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write struct begin error: ", x), err)
    }

    if err := x.writeField0(p); err != nil {
        return err
    }

    if err := p.WriteFieldStop(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write field stop error: ", x), err)
    }

    if err := p.WriteStructEnd(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write struct end error: ", x), err)
    }
    return nil
}

func (x *respAdapterServiceCount) Read(p thrift.Format) error {
    if _, err := p.ReadStructBegin(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T read error: ", x), err)
    }

    for {
        _, wireType, id, err := p.ReadFieldBegin()
        if err != nil {
            return thrift.PrependError(fmt.Sprintf("%T field %d read error: ", x, id), err)
        }

        if wireType == thrift.STOP {
            break;
        }

        switch {
        case (id == 0 && wireType == thrift.Type(thrift.STRUCT)):  // success
            if err := x.readField0(p); err != nil {
                return err
            }
        default:
            if err := p.Skip(wireType); err != nil {
                return err
            }
        }

        if err := p.ReadFieldEnd(); err != nil {
            return err
        }
    }

    if err := p.ReadStructEnd(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T read struct end error: ", x), err)
    }

    return nil
}

func (x *respAdapterServiceCount) String() string {
    if x == nil {
        return "<nil>"
    }

    var sb strings.Builder

    sb.WriteString("respAdapterServiceCount({")
    sb.WriteString(fmt.Sprintf("Success:%s", x.toString0()))
    sb.WriteString("})")

    return sb.String()
}
type reqAdapterServiceAdaptedTypes struct {
    Arg *HeapAllocated `thrift:"arg,1" json:"arg" db:"arg"`
}
// Compile time interface enforcer
var _ thrift.Struct = (*reqAdapterServiceAdaptedTypes)(nil)

// Deprecated: AdapterServiceAdaptedTypesArgsDeprecated is deprecated, since it is supposed to be internal.
type AdapterServiceAdaptedTypesArgsDeprecated = reqAdapterServiceAdaptedTypes

func newReqAdapterServiceAdaptedTypes() *reqAdapterServiceAdaptedTypes {
    return (&reqAdapterServiceAdaptedTypes{}).
        SetArgNonCompat(*NewHeapAllocated())
}

func (x *reqAdapterServiceAdaptedTypes) GetArgNonCompat() *HeapAllocated {
    return x.Arg
}

func (x *reqAdapterServiceAdaptedTypes) GetArg() *HeapAllocated {
    if !x.IsSetArg() {
        return nil
    }

    return x.Arg
}

func (x *reqAdapterServiceAdaptedTypes) SetArgNonCompat(value HeapAllocated) *reqAdapterServiceAdaptedTypes {
    x.Arg = &value
    return x
}

func (x *reqAdapterServiceAdaptedTypes) SetArg(value *HeapAllocated) *reqAdapterServiceAdaptedTypes {
    x.Arg = value
    return x
}

func (x *reqAdapterServiceAdaptedTypes) IsSetArg() bool {
    return x != nil && x.Arg != nil
}

func (x *reqAdapterServiceAdaptedTypes) writeField1(p thrift.Format) error {  // Arg
    if !x.IsSetArg() {
        return nil
    }

    if err := p.WriteFieldBegin("arg", thrift.STRUCT, 1); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write field begin error: ", x), err)
    }

    item := x.Arg
    if err := item.Write(p); err != nil {
    return err
}

    if err := p.WriteFieldEnd(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write field end error: ", x), err)
    }
    return nil
}

func (x *reqAdapterServiceAdaptedTypes) readField1(p thrift.Format) error {  // Arg
    result := *NewHeapAllocated()
err := result.Read(p)
if err != nil {
    return err
}

    x.Arg = &result
    return nil
}

func (x *reqAdapterServiceAdaptedTypes) toString1() string {  // Arg
    return fmt.Sprintf("%v", x.Arg)
}

// Deprecated: Use newReqAdapterServiceAdaptedTypes().GetArg() instead.
func (x *reqAdapterServiceAdaptedTypes) DefaultGetArg() *HeapAllocated {
    if !x.IsSetArg() {
        return NewHeapAllocated()
    }
    return x.Arg
}



func (x *reqAdapterServiceAdaptedTypes) Write(p thrift.Format) error {
    if err := p.WriteStructBegin("reqAdapterServiceAdaptedTypes"); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write struct begin error: ", x), err)
    }

    if err := x.writeField1(p); err != nil {
        return err
    }

    if err := p.WriteFieldStop(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write field stop error: ", x), err)
    }

    if err := p.WriteStructEnd(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write struct end error: ", x), err)
    }
    return nil
}

func (x *reqAdapterServiceAdaptedTypes) Read(p thrift.Format) error {
    if _, err := p.ReadStructBegin(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T read error: ", x), err)
    }

    for {
        _, wireType, id, err := p.ReadFieldBegin()
        if err != nil {
            return thrift.PrependError(fmt.Sprintf("%T field %d read error: ", x, id), err)
        }

        if wireType == thrift.STOP {
            break;
        }

        switch {
        case (id == 1 && wireType == thrift.Type(thrift.STRUCT)):  // arg
            if err := x.readField1(p); err != nil {
                return err
            }
        default:
            if err := p.Skip(wireType); err != nil {
                return err
            }
        }

        if err := p.ReadFieldEnd(); err != nil {
            return err
        }
    }

    if err := p.ReadStructEnd(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T read struct end error: ", x), err)
    }

    return nil
}

func (x *reqAdapterServiceAdaptedTypes) String() string {
    if x == nil {
        return "<nil>"
    }

    var sb strings.Builder

    sb.WriteString("reqAdapterServiceAdaptedTypes({")
    sb.WriteString(fmt.Sprintf("Arg:%s", x.toString1()))
    sb.WriteString("})")

    return sb.String()
}
type respAdapterServiceAdaptedTypes struct {
    Success *HeapAllocated `thrift:"success,0,optional" json:"success,omitempty" db:"success"`
}
// Compile time interface enforcer
var _ thrift.Struct = (*respAdapterServiceAdaptedTypes)(nil)
var _ thrift.WritableResult = (*respAdapterServiceAdaptedTypes)(nil)

// Deprecated: AdapterServiceAdaptedTypesResultDeprecated is deprecated, since it is supposed to be internal.
type AdapterServiceAdaptedTypesResultDeprecated = respAdapterServiceAdaptedTypes

func newRespAdapterServiceAdaptedTypes() *respAdapterServiceAdaptedTypes {
    return (&respAdapterServiceAdaptedTypes{})
}

func (x *respAdapterServiceAdaptedTypes) GetSuccessNonCompat() *HeapAllocated {
    return x.Success
}

func (x *respAdapterServiceAdaptedTypes) GetSuccess() *HeapAllocated {
    if !x.IsSetSuccess() {
        return nil
    }

    return x.Success
}

func (x *respAdapterServiceAdaptedTypes) SetSuccessNonCompat(value HeapAllocated) *respAdapterServiceAdaptedTypes {
    x.Success = &value
    return x
}

func (x *respAdapterServiceAdaptedTypes) SetSuccess(value *HeapAllocated) *respAdapterServiceAdaptedTypes {
    x.Success = value
    return x
}

func (x *respAdapterServiceAdaptedTypes) IsSetSuccess() bool {
    return x != nil && x.Success != nil
}

func (x *respAdapterServiceAdaptedTypes) writeField0(p thrift.Format) error {  // Success
    if !x.IsSetSuccess() {
        return nil
    }

    if err := p.WriteFieldBegin("success", thrift.STRUCT, 0); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write field begin error: ", x), err)
    }

    item := x.Success
    if err := item.Write(p); err != nil {
    return err
}

    if err := p.WriteFieldEnd(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write field end error: ", x), err)
    }
    return nil
}

func (x *respAdapterServiceAdaptedTypes) readField0(p thrift.Format) error {  // Success
    result := *NewHeapAllocated()
err := result.Read(p)
if err != nil {
    return err
}

    x.Success = &result
    return nil
}

func (x *respAdapterServiceAdaptedTypes) toString0() string {  // Success
    return fmt.Sprintf("%v", x.Success)
}

// Deprecated: Use newRespAdapterServiceAdaptedTypes().GetSuccess() instead.
func (x *respAdapterServiceAdaptedTypes) DefaultGetSuccess() *HeapAllocated {
    if !x.IsSetSuccess() {
        return NewHeapAllocated()
    }
    return x.Success
}



func (x *respAdapterServiceAdaptedTypes) Exception() thrift.WritableException {
    return nil
}

func (x *respAdapterServiceAdaptedTypes) Write(p thrift.Format) error {
    if err := p.WriteStructBegin("respAdapterServiceAdaptedTypes"); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write struct begin error: ", x), err)
    }

    if err := x.writeField0(p); err != nil {
        return err
    }

    if err := p.WriteFieldStop(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write field stop error: ", x), err)
    }

    if err := p.WriteStructEnd(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write struct end error: ", x), err)
    }
    return nil
}

func (x *respAdapterServiceAdaptedTypes) Read(p thrift.Format) error {
    if _, err := p.ReadStructBegin(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T read error: ", x), err)
    }

    for {
        _, wireType, id, err := p.ReadFieldBegin()
        if err != nil {
            return thrift.PrependError(fmt.Sprintf("%T field %d read error: ", x, id), err)
        }

        if wireType == thrift.STOP {
            break;
        }

        switch {
        case (id == 0 && wireType == thrift.Type(thrift.STRUCT)):  // success
            if err := x.readField0(p); err != nil {
                return err
            }
        default:
            if err := p.Skip(wireType); err != nil {
                return err
            }
        }

        if err := p.ReadFieldEnd(); err != nil {
            return err
        }
    }

    if err := p.ReadStructEnd(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T read struct end error: ", x), err)
    }

    return nil
}

func (x *respAdapterServiceAdaptedTypes) String() string {
    if x == nil {
        return "<nil>"
    }

    var sb strings.Builder

    sb.WriteString("respAdapterServiceAdaptedTypes({")
    sb.WriteString(fmt.Sprintf("Success:%s", x.toString0()))
    sb.WriteString("})")

    return sb.String()
}


type AdapterServiceProcessor struct {
    processorMap       map[string]thrift.ProcessorFunctionContext
    functionServiceMap map[string]string
    handler            AdapterService
}
// Compile time interface enforcer
var _ thrift.ProcessorContext = (*AdapterServiceProcessor)(nil)

func NewAdapterServiceProcessor(handler AdapterService) *AdapterServiceProcessor {
    p := &AdapterServiceProcessor{
        handler:            handler,
        processorMap:       make(map[string]thrift.ProcessorFunctionContext),
        functionServiceMap: make(map[string]string),
    }
    p.AddToProcessorMap("count", &procFuncAdapterServiceCount{handler: handler})
    p.AddToProcessorMap("adaptedTypes", &procFuncAdapterServiceAdaptedTypes{handler: handler})
    p.AddToFunctionServiceMap("count", "AdapterService")
    p.AddToFunctionServiceMap("adaptedTypes", "AdapterService")

    return p
}

func (p *AdapterServiceProcessor) AddToProcessorMap(key string, processor thrift.ProcessorFunctionContext) {
    p.processorMap[key] = processor
}

func (p *AdapterServiceProcessor) AddToFunctionServiceMap(key, service string) {
    p.functionServiceMap[key] = service
}

func (p *AdapterServiceProcessor) GetProcessorFunctionContext(key string) (processor thrift.ProcessorFunctionContext, err error) {
    if processor, ok := p.processorMap[key]; ok {
        return processor, nil
    }
    return nil, nil
}

func (p *AdapterServiceProcessor) ProcessorMap() map[string]thrift.ProcessorFunctionContext {
    return p.processorMap
}

func (p *AdapterServiceProcessor) FunctionServiceMap() map[string]string {
    return p.functionServiceMap
}

func (p *AdapterServiceProcessor) GetThriftMetadata() *metadata.ThriftMetadata {
    return GetThriftMetadataForService("module.AdapterService")
}


type procFuncAdapterServiceCount struct {
    handler AdapterService
}
// Compile time interface enforcer
var _ thrift.ProcessorFunctionContext = (*procFuncAdapterServiceCount)(nil)

func (p *procFuncAdapterServiceCount) Read(iprot thrift.Format) (thrift.Struct, thrift.Exception) {
    args := newReqAdapterServiceCount()
    if err := args.Read(iprot); err != nil {
        return nil, err
    }
    iprot.ReadMessageEnd()
    return args, nil
}

func (p *procFuncAdapterServiceCount) Write(seqId int32, result thrift.WritableStruct, oprot thrift.Format) (err thrift.Exception) {
    var err2 error
    messageType := thrift.REPLY
    switch result.(type) {
    case thrift.ApplicationException:
        messageType = thrift.EXCEPTION
    }

    if err2 = oprot.WriteMessageBegin("count", messageType, seqId); err2 != nil {
        err = err2
    }
    if err2 = result.Write(oprot); err == nil && err2 != nil {
        err = err2
    }
    if err2 = oprot.WriteMessageEnd(); err == nil && err2 != nil {
        err = err2
    }
    if err2 = oprot.Flush(); err == nil && err2 != nil {
        err = err2
    }
    return err
}

func (p *procFuncAdapterServiceCount) RunContext(ctx context.Context, reqStruct thrift.Struct) (thrift.WritableStruct, thrift.ApplicationException) {
    result := newRespAdapterServiceCount()
    retval, err := p.handler.Count(ctx)
    if err != nil {
        x := thrift.NewApplicationExceptionCause(thrift.INTERNAL_ERROR, "Internal error processing Count: " + err.Error(), err)
        return x, x
    }

    result.Success = retval
    return result, nil
}


type procFuncAdapterServiceAdaptedTypes struct {
    handler AdapterService
}
// Compile time interface enforcer
var _ thrift.ProcessorFunctionContext = (*procFuncAdapterServiceAdaptedTypes)(nil)

func (p *procFuncAdapterServiceAdaptedTypes) Read(iprot thrift.Format) (thrift.Struct, thrift.Exception) {
    args := newReqAdapterServiceAdaptedTypes()
    if err := args.Read(iprot); err != nil {
        return nil, err
    }
    iprot.ReadMessageEnd()
    return args, nil
}

func (p *procFuncAdapterServiceAdaptedTypes) Write(seqId int32, result thrift.WritableStruct, oprot thrift.Format) (err thrift.Exception) {
    var err2 error
    messageType := thrift.REPLY
    switch result.(type) {
    case thrift.ApplicationException:
        messageType = thrift.EXCEPTION
    }

    if err2 = oprot.WriteMessageBegin("adaptedTypes", messageType, seqId); err2 != nil {
        err = err2
    }
    if err2 = result.Write(oprot); err == nil && err2 != nil {
        err = err2
    }
    if err2 = oprot.WriteMessageEnd(); err == nil && err2 != nil {
        err = err2
    }
    if err2 = oprot.Flush(); err == nil && err2 != nil {
        err = err2
    }
    return err
}

func (p *procFuncAdapterServiceAdaptedTypes) RunContext(ctx context.Context, reqStruct thrift.Struct) (thrift.WritableStruct, thrift.ApplicationException) {
    args := reqStruct.(*reqAdapterServiceAdaptedTypes)
    result := newRespAdapterServiceAdaptedTypes()
    retval, err := p.handler.AdaptedTypes(ctx, args.Arg)
    if err != nil {
        x := thrift.NewApplicationExceptionCause(thrift.INTERNAL_ERROR, "Internal error processing AdaptedTypes: " + err.Error(), err)
        return x, x
    }

    result.Success = retval
    return result, nil
}


