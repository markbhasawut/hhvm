// Autogenerated by Thrift for thrift/annotation/cpp.thrift
//
// DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
//  @generated

package cpp

import (
    thrift "github.com/facebook/fbthrift/thrift/lib/go/thrift"
    metadata "github.com/facebook/fbthrift/thrift/lib/thrift/metadata"
)

// mapsCopy is a copy of maps.Copy from Go 1.21
// TODO: remove mapsCopy once we can safely upgrade to Go 1.21 without requiring any rollback.
func mapsCopy[M1 ~map[K]V, M2 ~map[K]V, K comparable, V any](dst M1, src M2) {
	for k, v := range src {
		dst[k] = v
	}
}

// (needed to ensure safety because of naive import list construction)
var _ = thrift.ZERO
// TODO: uncomment when can safely upgrade to Go 1.21 without requiring any rollback.
// var _ = maps.Copy[map[int]int, map[int]int]
var _ = metadata.GoUnusedProtection__

// Premade Thrift types
var (
    premadeThriftType_string = metadata.NewThriftType().SetTPrimitive(
        metadata.ThriftPrimitiveType_THRIFT_STRING_TYPE.Ptr(),
            )
    premadeThriftType_cpp_RefType = metadata.NewThriftType().SetTEnum(
        metadata.NewThriftEnumType().
            SetName("cpp.RefType"),
            )
    premadeThriftType_bool = metadata.NewThriftType().SetTPrimitive(
        metadata.ThriftPrimitiveType_THRIFT_BOOL_TYPE.Ptr(),
            )
    premadeThriftType_cpp_EnumUnderlyingType = metadata.NewThriftType().SetTEnum(
        metadata.NewThriftEnumType().
            SetName("cpp.EnumUnderlyingType"),
            )
)

var structMetadatas = []*metadata.ThriftStruct{
    metadata.NewThriftStruct().
    SetName("cpp.Type").
    SetIsUnion(false).
    SetFields(
        []*metadata.ThriftField{
            metadata.NewThriftField().
    SetId(1).
    SetName("name").
    SetIsOptional(false).
    SetType(premadeThriftType_string),
            metadata.NewThriftField().
    SetId(2).
    SetName("template").
    SetIsOptional(false).
    SetType(premadeThriftType_string),
        },
    ),
    metadata.NewThriftStruct().
    SetName("cpp.Ref").
    SetIsUnion(false).
    SetFields(
        []*metadata.ThriftField{
            metadata.NewThriftField().
    SetId(1).
    SetName("type").
    SetIsOptional(false).
    SetType(premadeThriftType_cpp_RefType),
        },
    ),
    metadata.NewThriftStruct().
    SetName("cpp.Name").
    SetIsUnion(false).
    SetFields(
        []*metadata.ThriftField{
            metadata.NewThriftField().
    SetId(1).
    SetName("value").
    SetIsOptional(false).
    SetType(premadeThriftType_string),
        },
    ),
    metadata.NewThriftStruct().
    SetName("cpp.Lazy").
    SetIsUnion(false).
    SetFields(
        []*metadata.ThriftField{
            metadata.NewThriftField().
    SetId(1).
    SetName("ref").
    SetIsOptional(false).
    SetType(premadeThriftType_bool),
        },
    ),
    metadata.NewThriftStruct().
    SetName("cpp.DisableLazyChecksum").
    SetIsUnion(false),
    metadata.NewThriftStruct().
    SetName("cpp.Adapter").
    SetIsUnion(false).
    SetFields(
        []*metadata.ThriftField{
            metadata.NewThriftField().
    SetId(1).
    SetName("name").
    SetIsOptional(false).
    SetType(premadeThriftType_string),
            metadata.NewThriftField().
    SetId(2).
    SetName("adaptedType").
    SetIsOptional(false).
    SetType(premadeThriftType_string),
            metadata.NewThriftField().
    SetId(3).
    SetName("underlyingName").
    SetIsOptional(false).
    SetType(premadeThriftType_string),
            metadata.NewThriftField().
    SetId(4).
    SetName("extraNamespace").
    SetIsOptional(false).
    SetType(premadeThriftType_string),
            metadata.NewThriftField().
    SetId(5).
    SetName("moveOnly").
    SetIsOptional(false).
    SetType(premadeThriftType_bool),
        },
    ),
    metadata.NewThriftStruct().
    SetName("cpp.PackIsset").
    SetIsUnion(false).
    SetFields(
        []*metadata.ThriftField{
            metadata.NewThriftField().
    SetId(1).
    SetName("atomic").
    SetIsOptional(false).
    SetType(premadeThriftType_bool),
        },
    ),
    metadata.NewThriftStruct().
    SetName("cpp.MinimizePadding").
    SetIsUnion(false),
    metadata.NewThriftStruct().
    SetName("cpp.ScopedEnumAsUnionType").
    SetIsUnion(false),
    metadata.NewThriftStruct().
    SetName("cpp.FieldInterceptor").
    SetIsUnion(false).
    SetFields(
        []*metadata.ThriftField{
            metadata.NewThriftField().
    SetId(1).
    SetName("name").
    SetIsOptional(false).
    SetType(premadeThriftType_string),
            metadata.NewThriftField().
    SetId(2).
    SetName("noinline").
    SetIsOptional(false).
    SetType(premadeThriftType_bool),
        },
    ),
    metadata.NewThriftStruct().
    SetName("cpp.UseOpEncode").
    SetIsUnion(false),
    metadata.NewThriftStruct().
    SetName("cpp.EnumType").
    SetIsUnion(false).
    SetFields(
        []*metadata.ThriftField{
            metadata.NewThriftField().
    SetId(1).
    SetName("type").
    SetIsOptional(false).
    SetType(premadeThriftType_cpp_EnumUnderlyingType),
        },
    ),
    metadata.NewThriftStruct().
    SetName("cpp.Frozen2Exclude").
    SetIsUnion(false),
    metadata.NewThriftStruct().
    SetName("cpp.Frozen2RequiresCompleteContainerParams").
    SetIsUnion(false),
    metadata.NewThriftStruct().
    SetName("cpp.ProcessInEbThreadUnsafe").
    SetIsUnion(false),
    metadata.NewThriftStruct().
    SetName("cpp.RuntimeAnnotation").
    SetIsUnion(false),
    metadata.NewThriftStruct().
    SetName("cpp.UseCursorSerialization").
    SetIsUnion(false),
}

var exceptionMetadatas = []*metadata.ThriftException{
}

var enumMetadatas = []*metadata.ThriftEnum{
    metadata.NewThriftEnum().
    SetName("cpp.RefType").
    SetElements(
        map[int32]string{
            0: "Unique",
            1: "Shared",
            2: "SharedMutable",
        },
    ),
    metadata.NewThriftEnum().
    SetName("cpp.EnumUnderlyingType").
    SetElements(
        map[int32]string{
            0: "I8",
            1: "U8",
            2: "I16",
            3: "U16",
            4: "U32",
        },
    ),
}

var serviceMetadatas = []*metadata.ThriftService{
}

// GetThriftMetadata returns complete Thrift metadata for current and imported packages.
func GetThriftMetadata() *metadata.ThriftMetadata {
    allEnums := GetEnumsMetadata()
    allStructs := GetStructsMetadata()
    allExceptions := GetExceptionsMetadata()
    allServices := GetServicesMetadata()

    return metadata.NewThriftMetadata().
        SetEnums(allEnums).
        SetStructs(allStructs).
        SetExceptions(allExceptions).
        SetServices(allServices)
}

// GetEnumsMetadata returns Thrift metadata for enums in the current and recursively included packages.
func GetEnumsMetadata() map[string]*metadata.ThriftEnum {
    allEnumsMap := make(map[string]*metadata.ThriftEnum)

    // Add enum metadatas from the current program...
    for _, enumMetadata := range enumMetadatas {
        allEnumsMap[enumMetadata.GetName()] = enumMetadata
    }

    // ...now add enum metadatas from recursively included programs.

    return allEnumsMap
}

// GetStructsMetadata returns Thrift metadata for structs in the current and recursively included packages.
func GetStructsMetadata() map[string]*metadata.ThriftStruct {
    allStructsMap := make(map[string]*metadata.ThriftStruct)

    // Add struct metadatas from the current program...
    for _, structMetadata := range structMetadatas {
        allStructsMap[structMetadata.GetName()] = structMetadata
    }

    // ...now add struct metadatas from recursively included programs.

    return allStructsMap
}

// GetExceptionsMetadata returns Thrift metadata for exceptions in the current and recursively included packages.
func GetExceptionsMetadata() map[string]*metadata.ThriftException {
    allExceptionsMap := make(map[string]*metadata.ThriftException)

    // Add exception metadatas from the current program...
    for _, exceptionMetadata := range exceptionMetadatas {
        allExceptionsMap[exceptionMetadata.GetName()] = exceptionMetadata
    }

    // ...now add exception metadatas from recursively included programs.

    return allExceptionsMap
}

// GetServicesMetadata returns Thrift metadata for services in the current and recursively included packages.
func GetServicesMetadata() map[string]*metadata.ThriftService {
    allServicesMap := make(map[string]*metadata.ThriftService)

    // Add service metadatas from the current program...
    for _, serviceMetadata := range serviceMetadatas {
        allServicesMap[serviceMetadata.GetName()] = serviceMetadata
    }

    // ...now add service metadatas from recursively included programs.

    return allServicesMap
}

// GetThriftMetadataForService returns Thrift metadata for the given service.
func GetThriftMetadataForService(scopedServiceName string) *metadata.ThriftMetadata {
    thriftMetadata := GetThriftMetadata()

    allServicesMap := thriftMetadata.GetServices()
    relevantServicesMap := make(map[string]*metadata.ThriftService)

    serviceMetadata := allServicesMap[scopedServiceName]
    // Visit and record all recursive parents of the target service.
    for serviceMetadata != nil {
        relevantServicesMap[serviceMetadata.GetName()] = serviceMetadata
        if serviceMetadata.IsSetParent() {
            serviceMetadata = allServicesMap[serviceMetadata.GetParent()]
        } else {
            serviceMetadata = nil
        }
    }

    thriftMetadata.SetServices(relevantServicesMap)

    return thriftMetadata
}
