/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* A CRTP reader for Clang Type nodes                                         *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

template <class PropertyReader>
class AbstractTypeReader {
public:
  PropertyReader &R;

  AbstractTypeReader(PropertyReader &R) : R(R) {}

  QualType read(Type::TypeClass kind) {
    switch (kind) {
    case Type::Adjusted:
      return readAdjustedType();
    case Type::Decayed:
      return readDecayedType();
    case Type::ConstantArray:
      return readConstantArrayType();
    case Type::DependentSizedArray:
      return readDependentSizedArrayType();
    case Type::IncompleteArray:
      return readIncompleteArrayType();
    case Type::VariableArray:
      return readVariableArrayType();
    case Type::Atomic:
      return readAtomicType();
    case Type::Attributed:
      return readAttributedType();
    case Type::BitInt:
      return readBitIntType();
    case Type::BlockPointer:
      return readBlockPointerType();
    case Type::Builtin:
      return readBuiltinType();
    case Type::Complex:
      return readComplexType();
    case Type::Decltype:
      return readDecltypeType();
    case Type::Auto:
      return readAutoType();
    case Type::DeducedTemplateSpecialization:
      return readDeducedTemplateSpecializationType();
    case Type::DependentAddressSpace:
      return readDependentAddressSpaceType();
    case Type::DependentBitInt:
      return readDependentBitIntType();
    case Type::DependentName:
      return readDependentNameType();
    case Type::DependentSizedExtVector:
      return readDependentSizedExtVectorType();
    case Type::DependentTemplateSpecialization:
      return readDependentTemplateSpecializationType();
    case Type::DependentVector:
      return readDependentVectorType();
    case Type::Elaborated:
      return readElaboratedType();
    case Type::FunctionNoProto:
      return readFunctionNoProtoType();
    case Type::FunctionProto:
      return readFunctionProtoType();
    case Type::InjectedClassName:
      return readInjectedClassNameType();
    case Type::MacroQualified:
      return readMacroQualifiedType();
    case Type::ConstantMatrix:
      return readConstantMatrixType();
    case Type::DependentSizedMatrix:
      return readDependentSizedMatrixType();
    case Type::MemberPointer:
      return readMemberPointerType();
    case Type::ObjCObjectPointer:
      return readObjCObjectPointerType();
    case Type::ObjCObject:
      return readObjCObjectType();
    case Type::ObjCInterface:
      return readObjCInterfaceType();
    case Type::ObjCTypeParam:
      return readObjCTypeParamType();
    case Type::PackExpansion:
      return readPackExpansionType();
    case Type::Paren:
      return readParenType();
    case Type::Pipe:
      return readPipeType();
    case Type::Pointer:
      return readPointerType();
    case Type::LValueReference:
      return readLValueReferenceType();
    case Type::RValueReference:
      return readRValueReferenceType();
    case Type::SubstTemplateTypeParmPack:
      return readSubstTemplateTypeParmPackType();
    case Type::SubstTemplateTypeParm:
      return readSubstTemplateTypeParmType();
    case Type::Enum:
      return readEnumType();
    case Type::Record:
      return readRecordType();
    case Type::TemplateSpecialization:
      return readTemplateSpecializationType();
    case Type::TemplateTypeParm:
      return readTemplateTypeParmType();
    case Type::TypeOfExpr:
      return readTypeOfExprType();
    case Type::TypeOf:
      return readTypeOfType();
    case Type::Typedef:
      return readTypedefType();
    case Type::UnaryTransform:
      return readUnaryTransformType();
    case Type::UnresolvedUsing:
      return readUnresolvedUsingType();
    case Type::Using:
      return readUsingType();
    case Type::Vector:
      return readVectorType();
    case Type::ExtVector:
      return readExtVectorType();
    }
    llvm_unreachable("bad kind");
  }

  QualType readAdjustedType() {
    auto &ctx = R.getASTContext();
    QualType originalType = R.find("originalType").readQualType();
    QualType adjustedType = R.find("adjustedType").readQualType();
     return ctx.getAdjustedType(originalType, adjustedType); 
  }

  QualType readDecayedType() {
    auto &ctx = R.getASTContext();
    QualType originalType = R.find("originalType").readQualType();
     return ctx.getAdjustedParameterType(originalType); 
  }

  QualType readConstantArrayType() {
    auto &ctx = R.getASTContext();
    llvm::APInt sizeValue = R.find("sizeValue").readAPInt();
    Expr* size = R.find("size").readExprRef();
    QualType elementType = R.find("elementType").readQualType();
    ArrayType::ArraySizeModifier sizeModifier = R.find("sizeModifier").readArraySizeModifier();
    Qualifiers indexQualifiers = R.find("indexQualifiers").readQualifiers();
    
    return ctx.getConstantArrayType(elementType, sizeValue, size,
                                    sizeModifier,
                                    indexQualifiers.getCVRQualifiers());
  
  }

  QualType readDependentSizedArrayType() {
    auto &ctx = R.getASTContext();
    Expr* size = R.find("size").readExprRef();
    SourceLocation leftBracketLoc = R.find("leftBracketLoc").readSourceLocation();
    SourceLocation rightBracketLoc = R.find("rightBracketLoc").readSourceLocation();
    QualType elementType = R.find("elementType").readQualType();
    ArrayType::ArraySizeModifier sizeModifier = R.find("sizeModifier").readArraySizeModifier();
    Qualifiers indexQualifiers = R.find("indexQualifiers").readQualifiers();
    
    return ctx.getDependentSizedArrayType(elementType, size, sizeModifier,
                                          indexQualifiers.getCVRQualifiers(),
                                          SourceRange(leftBracketLoc,
                                                      rightBracketLoc));
  
  }

  QualType readIncompleteArrayType() {
    auto &ctx = R.getASTContext();
    QualType elementType = R.find("elementType").readQualType();
    ArrayType::ArraySizeModifier sizeModifier = R.find("sizeModifier").readArraySizeModifier();
    Qualifiers indexQualifiers = R.find("indexQualifiers").readQualifiers();
    
    return ctx.getIncompleteArrayType(elementType, sizeModifier,
                                      indexQualifiers.getCVRQualifiers());
  
  }

  QualType readVariableArrayType() {
    auto &ctx = R.getASTContext();
    SourceLocation leftBracketLoc = R.find("leftBracketLoc").readSourceLocation();
    SourceLocation rightBracketLoc = R.find("rightBracketLoc").readSourceLocation();
    Expr* size = R.find("size").readExprRef();
    QualType elementType = R.find("elementType").readQualType();
    ArrayType::ArraySizeModifier sizeModifier = R.find("sizeModifier").readArraySizeModifier();
    Qualifiers indexQualifiers = R.find("indexQualifiers").readQualifiers();
    
    return ctx.getVariableArrayType(elementType, size, sizeModifier,
                                    indexQualifiers.getCVRQualifiers(),
                                    SourceRange(leftBracketLoc,
                                                rightBracketLoc));
  
  }

  QualType readAtomicType() {
    auto &ctx = R.getASTContext();
    QualType valueType = R.find("valueType").readQualType();
    
    return ctx.getAtomicType(valueType);
  
  }

  QualType readAttributedType() {
    auto &ctx = R.getASTContext();
    QualType modifiedType = R.find("modifiedType").readQualType();
    QualType equivalentType = R.find("equivalentType").readQualType();
    attr::Kind attribute = R.find("attribute").readAttrKind();
    
    return ctx.getAttributedType(attribute, modifiedType, equivalentType);
  
  }

  QualType readBitIntType() {
    auto &ctx = R.getASTContext();
    bool isUnsigned = R.find("isUnsigned").readBool();
    uint32_t numBits = R.find("numBits").readUInt32();
    
    return ctx.getBitIntType(isUnsigned, numBits);
  
  }

  QualType readBlockPointerType() {
    auto &ctx = R.getASTContext();
    QualType pointeeType = R.find("pointeeType").readQualType();
     return ctx.getBlockPointerType(pointeeType); 
  }

  QualType readBuiltinType() {
    auto &ctx = R.getASTContext();
    BuiltinType::Kind kind = R.find("kind").readBuiltinTypeKind();
    
      switch (kind) {
#define IMAGE_TYPE(IMGTYPE, ID, SINGLETON_ID, ACCESS, SUFFIX) \
      case BuiltinType::ID: return ctx.SINGLETON_ID;
#include "clang/Basic/OpenCLImageTypes.def"

#define EXT_OPAQUE_TYPE(EXTTYPE, ID, EXT) \
      case BuiltinType::ID: return ctx.ID##Ty;
#include "clang/Basic/OpenCLExtensionTypes.def"

#define SVE_TYPE(NAME, ID, SINGLETON_ID) \
      case BuiltinType::ID: return ctx.SINGLETON_ID;
#include "clang/Basic/AArch64SVEACLETypes.def"

#define PPC_VECTOR_TYPE(NAME, ID, SIZE) \
      case BuiltinType::ID: return ctx.ID##Ty;
#include "clang/Basic/PPCTypes.def"

#define RVV_TYPE(NAME, ID, SINGLETON_ID) \
      case BuiltinType::ID: return ctx.SINGLETON_ID;
#include "clang/Basic/RISCVVTypes.def"

#define BUILTIN_TYPE(ID, SINGLETON_ID) \
      case BuiltinType::ID: return ctx.SINGLETON_ID;
#include "clang/AST/BuiltinTypes.def"
      }
      llvm_unreachable("unreachable builtin case");
  
  }

  QualType readComplexType() {
    auto &ctx = R.getASTContext();
    QualType elementType = R.find("elementType").readQualType();
     return ctx.getComplexType(elementType); 
  }

  QualType readDecltypeType() {
    auto &ctx = R.getASTContext();
    QualType underlyingType = R.find("underlyingType").readQualType();
    Expr* expression = R.find("expression").readExprRef();
    
    return ctx.getDecltypeType(expression, underlyingType);
  
  }

  QualType readAutoType() {
    auto &ctx = R.getASTContext();
    llvm::Optional<QualType> deducedType = R.find("deducedType").template readOptional<QualType>();
    AutoTypeKeyword keyword = R.find("keyword").readAutoTypeKeyword();
    llvm::Optional<ConceptDecl*> typeConstraintConcept = R.find("typeConstraintConcept").template readOptional<ConceptDecl*>();
    llvm::SmallVector<TemplateArgument, 8> typeConstraintArguments_buffer_0;
    llvm::ArrayRef<TemplateArgument> typeConstraintArguments = R.find("typeConstraintArguments").template readArray<TemplateArgument>(typeConstraintArguments_buffer_0);
    uint32_t dependence = R.find("dependence").readUInt32();
    
    return ctx.getAutoType(makeNullableFromOptional(deducedType), keyword,
                           /*isDependentWithoutDeducedType*/ dependence > 0,
                           /*isPackWithoutDeducedType*/ dependence > 1,
                           makePointerFromOptional(typeConstraintConcept),
                           typeConstraintArguments);
  
  }

  QualType readDeducedTemplateSpecializationType() {
    auto &ctx = R.getASTContext();
    llvm::Optional<TemplateName> templateName = R.find("templateName").template readOptional<TemplateName>();
    QualType deducedType = R.find("deducedType").readQualType();
    bool dependent = R.find("dependent").readBool();
    
    return ctx.getDeducedTemplateSpecializationType(
                                     makeNullableFromOptional(templateName),
                                     deducedType, dependent);
  
  }

  QualType readDependentAddressSpaceType() {
    auto &ctx = R.getASTContext();
    QualType pointeeType = R.find("pointeeType").readQualType();
    Expr* addressSpace = R.find("addressSpace").readExprRef();
    SourceLocation attributeLoc = R.find("attributeLoc").readSourceLocation();
    
    return ctx.getDependentAddressSpaceType(pointeeType, addressSpace,
                                            attributeLoc);
  
  }

  QualType readDependentBitIntType() {
    auto &ctx = R.getASTContext();
    bool isUnsigned = R.find("isUnsigned").readBool();
    Expr* numBitsExpr = R.find("numBitsExpr").readExprRef();
    
    return ctx.getDependentBitIntType(isUnsigned, numBitsExpr);
  
  }

  QualType readDependentNameType() {
    auto &ctx = R.getASTContext();
    ElaboratedTypeKeyword keyword = R.find("keyword").readElaboratedTypeKeyword();
    NestedNameSpecifier * qualifier = R.find("qualifier").readNestedNameSpecifier();
    IdentifierInfo* name = R.find("name").readIdentifier();
    llvm::Optional<QualType> underlyingType = R.find("underlyingType").template readOptional<QualType>();
    
    QualType canon = (underlyingType
                        ? ctx.getCanonicalType(*underlyingType)
                        : QualType());
    return ctx.getDependentNameType(keyword, qualifier, name, canon);
  
  }

  QualType readDependentSizedExtVectorType() {
    auto &ctx = R.getASTContext();
    QualType elementType = R.find("elementType").readQualType();
    Expr* size = R.find("size").readExprRef();
    SourceLocation attributeLoc = R.find("attributeLoc").readSourceLocation();
    
    return ctx.getDependentSizedExtVectorType(elementType, size, attributeLoc);
  
  }

  QualType readDependentTemplateSpecializationType() {
    auto &ctx = R.getASTContext();
    ElaboratedTypeKeyword keyword = R.find("keyword").readElaboratedTypeKeyword();
    NestedNameSpecifier * qualifier = R.find("qualifier").readNestedNameSpecifier();
    IdentifierInfo* name = R.find("name").readIdentifier();
    llvm::SmallVector<TemplateArgument, 8> templateArguments_buffer_0;
    llvm::ArrayRef<TemplateArgument> templateArguments = R.find("templateArguments").template readArray<TemplateArgument>(templateArguments_buffer_0);
    
    return ctx.getDependentTemplateSpecializationType(keyword, qualifier,
                                                      name, templateArguments);
  
  }

  QualType readDependentVectorType() {
    auto &ctx = R.getASTContext();
    QualType elementType = R.find("elementType").readQualType();
    Expr* size = R.find("size").readExprRef();
    SourceLocation attributeLoc = R.find("attributeLoc").readSourceLocation();
    VectorType::VectorKind vectorKind = R.find("vectorKind").readVectorKind();
    
    return ctx.getDependentVectorType(elementType, size, attributeLoc,
                                      vectorKind);
  
  }

  QualType readElaboratedType() {
    auto &ctx = R.getASTContext();
    ElaboratedTypeKeyword keyword = R.find("keyword").readElaboratedTypeKeyword();
    NestedNameSpecifier * qualifier = R.find("qualifier").readNestedNameSpecifier();
    QualType namedType = R.find("namedType").readQualType();
    llvm::Optional<TagDecl*> ownedTag = R.find("ownedTag").template readOptional<TagDecl*>();
    
    return ctx.getElaboratedType(keyword, qualifier, namedType,
                                 makePointerFromOptional(ownedTag));
  
  }

  QualType readFunctionNoProtoType() {
    auto &ctx = R.getASTContext();
    QualType returnType = R.find("returnType").readQualType();
    bool noReturn = R.find("noReturn").readBool();
    bool hasRegParm = R.find("hasRegParm").readBool();
    uint32_t regParm = R.find("regParm").readUInt32();
    CallingConv callingConvention = R.find("callingConvention").readCallingConv();
    bool producesResult = R.find("producesResult").readBool();
    bool noCallerSavedRegs = R.find("noCallerSavedRegs").readBool();
    bool noCfCheck = R.find("noCfCheck").readBool();
    bool cmseNSCall = R.find("cmseNSCall").readBool();
    
    auto extInfo = FunctionType::ExtInfo(noReturn, hasRegParm, regParm,
                                         callingConvention, producesResult,
                                         noCallerSavedRegs, noCfCheck,
                                         cmseNSCall);
    return ctx.getFunctionNoProtoType(returnType, extInfo);
  
  }

  QualType readFunctionProtoType() {
    auto &ctx = R.getASTContext();
    bool variadic = R.find("variadic").readBool();
    bool trailingReturn = R.find("trailingReturn").readBool();
    Qualifiers methodQualifiers = R.find("methodQualifiers").readQualifiers();
    RefQualifierKind refQualifier = R.find("refQualifier").readRefQualifierKind();
    llvm::SmallVector<QualType, 8> exceptionSpecifier_buffer_0;
    FunctionProtoType::ExceptionSpecInfo exceptionSpecifier = R.find("exceptionSpecifier").readExceptionSpecInfo(exceptionSpecifier_buffer_0);
    llvm::SmallVector<QualType, 8> parameters_buffer_0;
    llvm::ArrayRef<QualType> parameters = R.find("parameters").template readArray<QualType>(parameters_buffer_0);
    llvm::SmallVector<FunctionProtoType::ExtParameterInfo, 8> extParameterInfo_buffer_0;
    llvm::ArrayRef<FunctionProtoType::ExtParameterInfo> extParameterInfo = R.find("extParameterInfo").template readArray<FunctionProtoType::ExtParameterInfo>(extParameterInfo_buffer_0);
    QualType returnType = R.find("returnType").readQualType();
    bool noReturn = R.find("noReturn").readBool();
    bool hasRegParm = R.find("hasRegParm").readBool();
    uint32_t regParm = R.find("regParm").readUInt32();
    CallingConv callingConvention = R.find("callingConvention").readCallingConv();
    bool producesResult = R.find("producesResult").readBool();
    bool noCallerSavedRegs = R.find("noCallerSavedRegs").readBool();
    bool noCfCheck = R.find("noCfCheck").readBool();
    bool cmseNSCall = R.find("cmseNSCall").readBool();
    
    auto extInfo = FunctionType::ExtInfo(noReturn, hasRegParm, regParm,
                                         callingConvention, producesResult,
                                         noCallerSavedRegs, noCfCheck,
                                         cmseNSCall);
    FunctionProtoType::ExtProtoInfo epi;
    epi.ExtInfo = extInfo;
    epi.Variadic = variadic;
    epi.HasTrailingReturn = trailingReturn;
    epi.TypeQuals = methodQualifiers;
    epi.RefQualifier = refQualifier;
    epi.ExceptionSpec = exceptionSpecifier;
    epi.ExtParameterInfos =
      extParameterInfo.empty() ? nullptr : extParameterInfo.data();
    return ctx.getFunctionType(returnType, parameters, epi);
  
  }

  QualType readInjectedClassNameType() {
    auto &ctx = R.getASTContext();
    Decl* declaration = R.find("declaration").readDeclRef();
    QualType injectedSpecializationType = R.find("injectedSpecializationType").readQualType();
    
    // FIXME: ASTContext::getInjectedClassNameType is not currently suitable
    // for AST reading, too much interdependencies.
    const Type *T = nullptr;
    auto typeDecl = cast<CXXRecordDecl>(declaration);
    for (auto *DI = typeDecl; DI; DI = DI->getPreviousDecl()) {
      if (const Type *existing = DI->getTypeForDecl()) {
        T = existing;
        break;
      }
    }
    if (!T) {
      T = new (ctx, TypeAlignment)
            InjectedClassNameType(typeDecl, injectedSpecializationType);
      for (auto *DI = typeDecl; DI; DI = DI->getPreviousDecl())
        DI->setTypeForDecl(T);
    }
    return QualType(T, 0);
  
  }

  QualType readMacroQualifiedType() {
    auto &ctx = R.getASTContext();
    QualType underlyingType = R.find("underlyingType").readQualType();
    IdentifierInfo* macroIdentifier = R.find("macroIdentifier").readIdentifier();
    
    return ctx.getMacroQualifiedType(underlyingType, macroIdentifier);
  
  }

  QualType readConstantMatrixType() {
    auto &ctx = R.getASTContext();
    uint32_t numRows = R.find("numRows").readUInt32();
    uint32_t numColumns = R.find("numColumns").readUInt32();
    QualType elementType = R.find("elementType").readQualType();
    
    return ctx.getConstantMatrixType(elementType, numRows, numColumns);
  
  }

  QualType readDependentSizedMatrixType() {
    auto &ctx = R.getASTContext();
    Expr* rows = R.find("rows").readExprRef();
    Expr* columns = R.find("columns").readExprRef();
    SourceLocation attributeLoc = R.find("attributeLoc").readSourceLocation();
    QualType elementType = R.find("elementType").readQualType();
    
    return ctx.getDependentSizedMatrixType(elementType, rows, columns, attributeLoc);
  
  }

  QualType readMemberPointerType() {
    auto &ctx = R.getASTContext();
    QualType pointeeType = R.find("pointeeType").readQualType();
    QualType baseType = R.find("baseType").readQualType();
    
    return ctx.getMemberPointerType(pointeeType, baseType.getTypePtr());
  
  }

  QualType readObjCObjectPointerType() {
    auto &ctx = R.getASTContext();
    QualType pointeeType = R.find("pointeeType").readQualType();
    
    return ctx.getObjCObjectPointerType(pointeeType);
  
  }

  QualType readObjCObjectType() {
    auto &ctx = R.getASTContext();
    QualType baseType = R.find("baseType").readQualType();
    llvm::SmallVector<QualType, 8> typeArgsAsWritten_buffer_0;
    llvm::ArrayRef<QualType> typeArgsAsWritten = R.find("typeArgsAsWritten").template readArray<QualType>(typeArgsAsWritten_buffer_0);
    llvm::SmallVector<ObjCProtocolDecl*, 8> qualifiers_buffer_0;
    llvm::ArrayRef<ObjCProtocolDecl*> qualifiers = R.find("qualifiers").template readArray<ObjCProtocolDecl*>(qualifiers_buffer_0);
    bool isKindOfTypeAsWritten = R.find("isKindOfTypeAsWritten").readBool();
    
    return ctx.getObjCObjectType(baseType, typeArgsAsWritten, qualifiers,
                                 isKindOfTypeAsWritten);
  
  }

  QualType readObjCInterfaceType() {
    auto &ctx = R.getASTContext();
    Decl* declaration = R.find("declaration").readDeclRef();
    
    return ctx.getObjCInterfaceType(
             cast<ObjCInterfaceDecl>(declaration->getCanonicalDecl()));
  
  }

  QualType readObjCTypeParamType() {
    auto &ctx = R.getASTContext();
    ObjCTypeParamDecl* declaration = R.find("declaration").readObjCTypeParamDeclRef();
    llvm::SmallVector<ObjCProtocolDecl*, 8> qualifiers_buffer_0;
    llvm::ArrayRef<ObjCProtocolDecl*> qualifiers = R.find("qualifiers").template readArray<ObjCProtocolDecl*>(qualifiers_buffer_0);
    
    return ctx.getObjCTypeParamType(declaration, qualifiers);
  
  }

  QualType readPackExpansionType() {
    auto &ctx = R.getASTContext();
    QualType pattern = R.find("pattern").readQualType();
    llvm::Optional<uint32_t> numExpansions = R.find("numExpansions").template readOptional<uint32_t>();
    
    return ctx.getPackExpansionType(pattern, numExpansions,
                                    /*ExpectPackInType*/false);
  
  }

  QualType readParenType() {
    auto &ctx = R.getASTContext();
    QualType innerType = R.find("innerType").readQualType();
    
    return ctx.getParenType(innerType);
  
  }

  QualType readPipeType() {
    auto &ctx = R.getASTContext();
    QualType elementType = R.find("elementType").readQualType();
    bool isReadOnly = R.find("isReadOnly").readBool();
    
    return ctx.getPipeType(elementType, isReadOnly);
  
  }

  QualType readPointerType() {
    auto &ctx = R.getASTContext();
    QualType pointeeType = R.find("pointeeType").readQualType();
     return ctx.getPointerType(pointeeType); 
  }

  QualType readLValueReferenceType() {
    auto &ctx = R.getASTContext();
    bool isSpelledAsLValue = R.find("isSpelledAsLValue").readBool();
    QualType pointeeTypeAsWritten = R.find("pointeeTypeAsWritten").readQualType();
    
    return ctx.getLValueReferenceType(pointeeTypeAsWritten,
                                      isSpelledAsLValue);
  
  }

  QualType readRValueReferenceType() {
    auto &ctx = R.getASTContext();
    QualType pointeeTypeAsWritten = R.find("pointeeTypeAsWritten").readQualType();
    
    return ctx.getRValueReferenceType(pointeeTypeAsWritten);
  
  }

  QualType readSubstTemplateTypeParmPackType() {
    auto &ctx = R.getASTContext();
    QualType replacedParameter = R.find("replacedParameter").readQualType();
    TemplateArgument replacementPack = R.find("replacementPack").readTemplateArgument();
    
    return ctx.getSubstTemplateTypeParmPackType(
                         cast<TemplateTypeParmType>(replacedParameter),
                        replacementPack);
  
  }

  QualType readSubstTemplateTypeParmType() {
    auto &ctx = R.getASTContext();
    QualType replacedParameter = R.find("replacedParameter").readQualType();
    QualType replacementType = R.find("replacementType").readQualType();
    
    // The call to getCanonicalType here existed in ASTReader.cpp, too.
    return ctx.getSubstTemplateTypeParmType(
        cast<TemplateTypeParmType>(replacedParameter),
        ctx.getCanonicalType(replacementType));
  
  }

  QualType readEnumType() {
    auto &ctx = R.getASTContext();
    bool dependent = R.find("dependent").readBool();
    Decl* declaration = R.find("declaration").readDeclRef();
    
    QualType result = ctx.getEnumType(cast<EnumDecl>(declaration));
    if (dependent)
      const_cast<Type *>(result.getTypePtr())
          ->addDependence(TypeDependence::DependentInstantiation);
    return result;
  
  }

  QualType readRecordType() {
    auto &ctx = R.getASTContext();
    bool dependent = R.find("dependent").readBool();
    Decl* declaration = R.find("declaration").readDeclRef();
    
    auto record = cast<RecordDecl>(declaration);
    QualType result = ctx.getRecordType(record);
    if (dependent)
      const_cast<Type *>(result.getTypePtr())
          ->addDependence(TypeDependence::DependentInstantiation);
    return result;
  
  }

  QualType readTemplateSpecializationType() {
    auto &ctx = R.getASTContext();
    bool dependent = R.find("dependent").readBool();
    TemplateName templateName = R.find("templateName").readTemplateName();
    llvm::SmallVector<TemplateArgument, 8> templateArguments_buffer_0;
    llvm::ArrayRef<TemplateArgument> templateArguments = R.find("templateArguments").template readArray<TemplateArgument>(templateArguments_buffer_0);
    llvm::Optional<QualType> underlyingType = R.find("underlyingType").template readOptional<QualType>();
    
    QualType result;
    if (!underlyingType.hasValue()) {
      result = ctx.getCanonicalTemplateSpecializationType(templateName,
                                                          templateArguments);
    } else {
      result = ctx.getTemplateSpecializationType(templateName,
                                                 templateArguments,
                                                 *underlyingType);
    }
    if (dependent)
      const_cast<Type *>(result.getTypePtr())
          ->addDependence(TypeDependence::DependentInstantiation);
    return result;
  
  }

  QualType readTemplateTypeParmType() {
    auto &ctx = R.getASTContext();
    uint32_t depth = R.find("depth").readUInt32();
    uint32_t index = R.find("index").readUInt32();
    bool isParameterPack = R.find("isParameterPack").readBool();
    llvm::Optional<TemplateTypeParmDecl*> declaration = R.find("declaration").template readOptional<TemplateTypeParmDecl*>();
    
    return ctx.getTemplateTypeParmType(depth, index, isParameterPack,
                                       makePointerFromOptional(declaration));
  
  }

  QualType readTypeOfExprType() {
    auto &ctx = R.getASTContext();
    Expr* expression = R.find("expression").readExprRef();
    
    return ctx.getTypeOfExprType(expression);
  
  }

  QualType readTypeOfType() {
    auto &ctx = R.getASTContext();
    QualType underlyingType = R.find("underlyingType").readQualType();
    
    return ctx.getTypeOfType(underlyingType);
  
  }

  QualType readTypedefType() {
    auto &ctx = R.getASTContext();
    Decl* declaration = R.find("declaration").readDeclRef();
    llvm::Optional<QualType> canonicalType = R.find("canonicalType").template readOptional<QualType>();
    
    QualType finalCanonicalType =
      canonicalType ? ctx.getCanonicalType(*canonicalType)
                    : QualType();
    return ctx.getTypedefType(cast<TypedefNameDecl>(declaration),
                              finalCanonicalType);
  
  }

  QualType readUnaryTransformType() {
    auto &ctx = R.getASTContext();
    QualType baseType = R.find("baseType").readQualType();
    QualType underlyingType = R.find("underlyingType").readQualType();
    UnaryTransformType::UTTKind transform = R.find("transform").readUnaryTypeTransformKind();
    
    return ctx.getUnaryTransformType(baseType, underlyingType, transform);
  
  }

  QualType readUnresolvedUsingType() {
    auto &ctx = R.getASTContext();
    Decl* declaration = R.find("declaration").readDeclRef();
    
    return ctx.getUnresolvedUsingType(cast<UnresolvedUsingTypenameDecl>(declaration));
  
  }

  QualType readUsingType() {
    auto &ctx = R.getASTContext();
    UsingShadowDecl* foundDeclaration = R.find("foundDeclaration").readUsingShadowDeclRef();
    QualType underlyingType = R.find("underlyingType").readQualType();
    
    return ctx.getUsingType(foundDeclaration, underlyingType);
  
  }

  QualType readVectorType() {
    auto &ctx = R.getASTContext();
    QualType elementType = R.find("elementType").readQualType();
    uint32_t numElements = R.find("numElements").readUInt32();
    VectorType::VectorKind vectorKind = R.find("vectorKind").readVectorKind();
    
    return ctx.getVectorType(elementType, numElements, vectorKind);
  
  }

  QualType readExtVectorType() {
    auto &ctx = R.getASTContext();
    QualType elementType = R.find("elementType").readQualType();
    uint32_t numElements = R.find("numElements").readUInt32();
    
    return ctx.getExtVectorType(elementType, numElements);
  
  }

};

