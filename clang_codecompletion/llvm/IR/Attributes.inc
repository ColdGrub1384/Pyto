#ifdef GET_ATTR_NAMES
#undef GET_ATTR_NAMES
#ifndef ATTRIBUTE_ALL
#define ATTRIBUTE_ALL(FIRST, SECOND)
#endif

#ifndef ATTRIBUTE_ENUM
#define ATTRIBUTE_ENUM(FIRST, SECOND) ATTRIBUTE_ALL(FIRST, SECOND)
#endif

ATTRIBUTE_ENUM(AlwaysInline,alwaysinline)
ATTRIBUTE_ENUM(ArgMemOnly,argmemonly)
ATTRIBUTE_ENUM(Builtin,builtin)
ATTRIBUTE_ENUM(Cold,cold)
ATTRIBUTE_ENUM(Convergent,convergent)
ATTRIBUTE_ENUM(DisableSanitizerInstrumentation,disable_sanitizer_instrumentation)
ATTRIBUTE_ENUM(Hot,hot)
ATTRIBUTE_ENUM(ImmArg,immarg)
ATTRIBUTE_ENUM(InReg,inreg)
ATTRIBUTE_ENUM(InaccessibleMemOnly,inaccessiblememonly)
ATTRIBUTE_ENUM(InaccessibleMemOrArgMemOnly,inaccessiblemem_or_argmemonly)
ATTRIBUTE_ENUM(InlineHint,inlinehint)
ATTRIBUTE_ENUM(JumpTable,jumptable)
ATTRIBUTE_ENUM(MinSize,minsize)
ATTRIBUTE_ENUM(MustProgress,mustprogress)
ATTRIBUTE_ENUM(Naked,naked)
ATTRIBUTE_ENUM(Nest,nest)
ATTRIBUTE_ENUM(NoAlias,noalias)
ATTRIBUTE_ENUM(NoBuiltin,nobuiltin)
ATTRIBUTE_ENUM(NoCallback,nocallback)
ATTRIBUTE_ENUM(NoCapture,nocapture)
ATTRIBUTE_ENUM(NoCfCheck,nocf_check)
ATTRIBUTE_ENUM(NoDuplicate,noduplicate)
ATTRIBUTE_ENUM(NoFree,nofree)
ATTRIBUTE_ENUM(NoImplicitFloat,noimplicitfloat)
ATTRIBUTE_ENUM(NoInline,noinline)
ATTRIBUTE_ENUM(NoMerge,nomerge)
ATTRIBUTE_ENUM(NoProfile,noprofile)
ATTRIBUTE_ENUM(NoRecurse,norecurse)
ATTRIBUTE_ENUM(NoRedZone,noredzone)
ATTRIBUTE_ENUM(NoReturn,noreturn)
ATTRIBUTE_ENUM(NoSanitizeCoverage,nosanitize_coverage)
ATTRIBUTE_ENUM(NoSync,nosync)
ATTRIBUTE_ENUM(NoUndef,noundef)
ATTRIBUTE_ENUM(NoUnwind,nounwind)
ATTRIBUTE_ENUM(NonLazyBind,nonlazybind)
ATTRIBUTE_ENUM(NonNull,nonnull)
ATTRIBUTE_ENUM(NullPointerIsValid,null_pointer_is_valid)
ATTRIBUTE_ENUM(OptForFuzzing,optforfuzzing)
ATTRIBUTE_ENUM(OptimizeForSize,optsize)
ATTRIBUTE_ENUM(OptimizeNone,optnone)
ATTRIBUTE_ENUM(ReadNone,readnone)
ATTRIBUTE_ENUM(ReadOnly,readonly)
ATTRIBUTE_ENUM(Returned,returned)
ATTRIBUTE_ENUM(ReturnsTwice,returns_twice)
ATTRIBUTE_ENUM(SExt,signext)
ATTRIBUTE_ENUM(SafeStack,safestack)
ATTRIBUTE_ENUM(SanitizeAddress,sanitize_address)
ATTRIBUTE_ENUM(SanitizeHWAddress,sanitize_hwaddress)
ATTRIBUTE_ENUM(SanitizeMemTag,sanitize_memtag)
ATTRIBUTE_ENUM(SanitizeMemory,sanitize_memory)
ATTRIBUTE_ENUM(SanitizeThread,sanitize_thread)
ATTRIBUTE_ENUM(ShadowCallStack,shadowcallstack)
ATTRIBUTE_ENUM(Speculatable,speculatable)
ATTRIBUTE_ENUM(SpeculativeLoadHardening,speculative_load_hardening)
ATTRIBUTE_ENUM(StackProtect,ssp)
ATTRIBUTE_ENUM(StackProtectReq,sspreq)
ATTRIBUTE_ENUM(StackProtectStrong,sspstrong)
ATTRIBUTE_ENUM(StrictFP,strictfp)
ATTRIBUTE_ENUM(SwiftAsync,swiftasync)
ATTRIBUTE_ENUM(SwiftError,swifterror)
ATTRIBUTE_ENUM(SwiftSelf,swiftself)
ATTRIBUTE_ENUM(UWTable,uwtable)
ATTRIBUTE_ENUM(WillReturn,willreturn)
ATTRIBUTE_ENUM(WriteOnly,writeonly)
ATTRIBUTE_ENUM(ZExt,zeroext)
ATTRIBUTE_ENUM(ByRef,byref)
ATTRIBUTE_ENUM(ByVal,byval)
ATTRIBUTE_ENUM(ElementType,elementtype)
ATTRIBUTE_ENUM(InAlloca,inalloca)
ATTRIBUTE_ENUM(Preallocated,preallocated)
ATTRIBUTE_ENUM(StructRet,sret)
ATTRIBUTE_ENUM(Alignment,align)
ATTRIBUTE_ENUM(AllocSize,allocsize)
ATTRIBUTE_ENUM(Dereferenceable,dereferenceable)
ATTRIBUTE_ENUM(DereferenceableOrNull,dereferenceable_or_null)
ATTRIBUTE_ENUM(StackAlignment,alignstack)
ATTRIBUTE_ENUM(VScaleRange,vscale_range)
#undef ATTRIBUTE_ENUM

#ifndef ATTRIBUTE_STRBOOL
#define ATTRIBUTE_STRBOOL(FIRST, SECOND) ATTRIBUTE_ALL(FIRST, SECOND)
#endif

ATTRIBUTE_STRBOOL(AMDGPUUnsafeFPAtomics,amdgpu-unsafe-fp-atomics)
ATTRIBUTE_STRBOOL(LessPreciseFPMAD,less-precise-fpmad)
ATTRIBUTE_STRBOOL(NoInfsFPMath,no-infs-fp-math)
ATTRIBUTE_STRBOOL(NoInlineLineTables,no-inline-line-tables)
ATTRIBUTE_STRBOOL(NoJumpTables,no-jump-tables)
ATTRIBUTE_STRBOOL(NoNansFPMath,no-nans-fp-math)
ATTRIBUTE_STRBOOL(NoSignedZerosFPMath,no-signed-zeros-fp-math)
ATTRIBUTE_STRBOOL(ProfileSampleAccurate,profile-sample-accurate)
ATTRIBUTE_STRBOOL(UnsafeFPMath,unsafe-fp-math)
ATTRIBUTE_STRBOOL(UseSampleProfile,use-sample-profile)
#undef ATTRIBUTE_STRBOOL

#undef ATTRIBUTE_ALL
#endif

#ifdef GET_ATTR_ENUM
#undef GET_ATTR_ENUM
FirstEnumAttr = 1,
AlwaysInline = 1,
ArgMemOnly = 2,
Builtin = 3,
Cold = 4,
Convergent = 5,
DisableSanitizerInstrumentation = 6,
Hot = 7,
ImmArg = 8,
InReg = 9,
InaccessibleMemOnly = 10,
InaccessibleMemOrArgMemOnly = 11,
InlineHint = 12,
JumpTable = 13,
MinSize = 14,
MustProgress = 15,
Naked = 16,
Nest = 17,
NoAlias = 18,
NoBuiltin = 19,
NoCallback = 20,
NoCapture = 21,
NoCfCheck = 22,
NoDuplicate = 23,
NoFree = 24,
NoImplicitFloat = 25,
NoInline = 26,
NoMerge = 27,
NoProfile = 28,
NoRecurse = 29,
NoRedZone = 30,
NoReturn = 31,
NoSanitizeCoverage = 32,
NoSync = 33,
NoUndef = 34,
NoUnwind = 35,
NonLazyBind = 36,
NonNull = 37,
NullPointerIsValid = 38,
OptForFuzzing = 39,
OptimizeForSize = 40,
OptimizeNone = 41,
ReadNone = 42,
ReadOnly = 43,
Returned = 44,
ReturnsTwice = 45,
SExt = 46,
SafeStack = 47,
SanitizeAddress = 48,
SanitizeHWAddress = 49,
SanitizeMemTag = 50,
SanitizeMemory = 51,
SanitizeThread = 52,
ShadowCallStack = 53,
Speculatable = 54,
SpeculativeLoadHardening = 55,
StackProtect = 56,
StackProtectReq = 57,
StackProtectStrong = 58,
StrictFP = 59,
SwiftAsync = 60,
SwiftError = 61,
SwiftSelf = 62,
UWTable = 63,
WillReturn = 64,
WriteOnly = 65,
ZExt = 66,
LastEnumAttr = 66,
FirstTypeAttr = 67,
ByRef = 67,
ByVal = 68,
ElementType = 69,
InAlloca = 70,
Preallocated = 71,
StructRet = 72,
LastTypeAttr = 72,
FirstIntAttr = 73,
Alignment = 73,
AllocSize = 74,
Dereferenceable = 75,
DereferenceableOrNull = 76,
StackAlignment = 77,
VScaleRange = 78,
LastIntAttr = 78,
#endif

#ifdef GET_ATTR_COMPAT_FUNC
#undef GET_ATTR_COMPAT_FUNC
static inline bool hasCompatibleFnAttrs(const Function &Caller,
                                        const Function &Callee) {
  bool Ret = true;

  Ret &= isEqual<SanitizeAddressAttr>(Caller, Callee);
  Ret &= isEqual<SanitizeThreadAttr>(Caller, Callee);
  Ret &= isEqual<SanitizeMemoryAttr>(Caller, Callee);
  Ret &= isEqual<SanitizeHWAddressAttr>(Caller, Callee);
  Ret &= isEqual<SanitizeMemTagAttr>(Caller, Callee);
  Ret &= isEqual<SafeStackAttr>(Caller, Callee);
  Ret &= isEqual<ShadowCallStackAttr>(Caller, Callee);
  Ret &= isEqual<UseSampleProfileAttr>(Caller, Callee);
  Ret &= isEqual<NoProfileAttr>(Caller, Callee);

  return Ret;
}

static inline void mergeFnAttrs(Function &Caller,
                                const Function &Callee) {
  setAND<NoInfsFPMathAttr>(Caller, Callee);
  setAND<NoNansFPMathAttr>(Caller, Callee);
  setAND<NoSignedZerosFPMathAttr>(Caller, Callee);
  setAND<UnsafeFPMathAttr>(Caller, Callee);
  setOR<NoImplicitFloatAttr>(Caller, Callee);
  setOR<NoJumpTablesAttr>(Caller, Callee);
  setOR<ProfileSampleAccurateAttr>(Caller, Callee);
  setOR<SpeculativeLoadHardeningAttr>(Caller, Callee);
  adjustCallerSSPLevel(Caller, Callee);
  adjustCallerStackProbes(Caller, Callee);
  adjustCallerStackProbeSize(Caller, Callee);
  adjustMinLegalVectorWidth(Caller, Callee);
  adjustNullPointerValidAttr(Caller, Callee);
  setAND<MustProgressAttr>(Caller, Callee);
  setAND<AMDGPUUnsafeFPAtomicsAttr>(Caller, Callee);
  setAND<LessPreciseFPMADAttr>(Caller, Callee);
}

#endif
#ifdef GET_ATTR_PROP_TABLE
#undef GET_ATTR_PROP_TABLE
static const uint8_t AttrPropTable[] = {
0 | AttributeProperty::FnAttr,
0 | AttributeProperty::FnAttr,
0 | AttributeProperty::FnAttr,
0 | AttributeProperty::FnAttr,
0 | AttributeProperty::FnAttr,
0 | AttributeProperty::FnAttr,
0 | AttributeProperty::FnAttr,
0 | AttributeProperty::ParamAttr,
0 | AttributeProperty::ParamAttr | AttributeProperty::RetAttr,
0 | AttributeProperty::FnAttr,
0 | AttributeProperty::FnAttr,
0 | AttributeProperty::FnAttr,
0 | AttributeProperty::FnAttr,
0 | AttributeProperty::FnAttr,
0 | AttributeProperty::FnAttr,
0 | AttributeProperty::FnAttr,
0 | AttributeProperty::ParamAttr,
0 | AttributeProperty::ParamAttr | AttributeProperty::RetAttr,
0 | AttributeProperty::FnAttr,
0 | AttributeProperty::FnAttr,
0 | AttributeProperty::ParamAttr,
0 | AttributeProperty::FnAttr,
0 | AttributeProperty::FnAttr,
0 | AttributeProperty::FnAttr | AttributeProperty::ParamAttr,
0 | AttributeProperty::FnAttr,
0 | AttributeProperty::FnAttr,
0 | AttributeProperty::FnAttr,
0 | AttributeProperty::FnAttr,
0 | AttributeProperty::FnAttr,
0 | AttributeProperty::FnAttr,
0 | AttributeProperty::FnAttr,
0 | AttributeProperty::FnAttr,
0 | AttributeProperty::FnAttr,
0 | AttributeProperty::ParamAttr | AttributeProperty::RetAttr,
0 | AttributeProperty::FnAttr,
0 | AttributeProperty::FnAttr,
0 | AttributeProperty::ParamAttr | AttributeProperty::RetAttr,
0 | AttributeProperty::FnAttr,
0 | AttributeProperty::FnAttr,
0 | AttributeProperty::FnAttr,
0 | AttributeProperty::FnAttr,
0 | AttributeProperty::FnAttr | AttributeProperty::ParamAttr,
0 | AttributeProperty::FnAttr | AttributeProperty::ParamAttr,
0 | AttributeProperty::ParamAttr,
0 | AttributeProperty::FnAttr,
0 | AttributeProperty::ParamAttr | AttributeProperty::RetAttr,
0 | AttributeProperty::FnAttr,
0 | AttributeProperty::FnAttr,
0 | AttributeProperty::FnAttr,
0 | AttributeProperty::FnAttr,
0 | AttributeProperty::FnAttr,
0 | AttributeProperty::FnAttr,
0 | AttributeProperty::FnAttr,
0 | AttributeProperty::FnAttr,
0 | AttributeProperty::FnAttr,
0 | AttributeProperty::FnAttr,
0 | AttributeProperty::FnAttr,
0 | AttributeProperty::FnAttr,
0 | AttributeProperty::FnAttr,
0 | AttributeProperty::ParamAttr,
0 | AttributeProperty::ParamAttr,
0 | AttributeProperty::ParamAttr,
0 | AttributeProperty::FnAttr,
0 | AttributeProperty::FnAttr,
0 | AttributeProperty::FnAttr | AttributeProperty::ParamAttr,
0 | AttributeProperty::ParamAttr | AttributeProperty::RetAttr,
0 | AttributeProperty::ParamAttr,
0 | AttributeProperty::ParamAttr,
0 | AttributeProperty::ParamAttr,
0 | AttributeProperty::ParamAttr,
0 | AttributeProperty::FnAttr | AttributeProperty::ParamAttr,
0 | AttributeProperty::ParamAttr,
0 | AttributeProperty::ParamAttr | AttributeProperty::RetAttr,
0 | AttributeProperty::FnAttr,
0 | AttributeProperty::ParamAttr | AttributeProperty::RetAttr,
0 | AttributeProperty::ParamAttr | AttributeProperty::RetAttr,
0 | AttributeProperty::FnAttr | AttributeProperty::ParamAttr,
0 | AttributeProperty::FnAttr,
};
#endif
