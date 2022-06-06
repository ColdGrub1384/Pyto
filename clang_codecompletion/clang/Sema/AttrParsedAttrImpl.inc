/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Parsed attribute helpers                                                   *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

#if !defined(WANT_DECL_MERGE_LOGIC) && !defined(WANT_STMT_MERGE_LOGIC)
static bool isStruct(const Decl *D) {
  if (const auto *S = dyn_cast<RecordDecl>(D))
    return !S->isUnion();
  return false;
}

static bool isSharedVar(const Decl *D) {
  if (const auto *S = dyn_cast<VarDecl>(D))
    return S->hasGlobalStorage() && !S->getTLSKind();
  return false;
}

static bool isGlobalVar(const Decl *D) {
  if (const auto *S = dyn_cast<VarDecl>(D))
    return S->hasGlobalStorage();
  return false;
}

static bool isHasFunctionProto(const Decl *D) {
  if (const auto *S = dyn_cast<Decl>(D))
    return (S->getFunctionType(true) != nullptr &&
                              isa<FunctionProtoType>(S->getFunctionType())) ||
                                       isa<ObjCMethodDecl>(S) ||
                                       isa<BlockDecl>(S);
  return false;
}

static bool isFunctionLike(const Decl *D) {
  if (const auto *S = dyn_cast<Decl>(D))
    return S->getFunctionType(false) != nullptr;
  return false;
}

static bool isInlineFunction(const Decl *D) {
  if (const auto *S = dyn_cast<FunctionDecl>(D))
    return S->isInlineSpecified();
  return false;
}

static bool isLocalVar(const Decl *D) {
  if (const auto *S = dyn_cast<VarDecl>(D))
    return S->hasLocalStorage() && !isa<ParmVarDecl>(S);
  return false;
}

static bool isObjCInstanceMethod(const Decl *D) {
  if (const auto *S = dyn_cast<ObjCMethodDecl>(D))
    return S->isInstanceMethod();
  return false;
}

static bool isImplicitObjectParameter(const Decl *D) {
  if (const auto *S = dyn_cast<FunctionDecl>(D))
    return static_cast<void>(S), false;
  return false;
}

static bool isNonParmVar(const Decl *D) {
  if (const auto *S = dyn_cast<VarDecl>(D))
    return S->getKind() != Decl::ParmVar;
  return false;
}

static bool isNonBitField(const Decl *D) {
  if (const auto *S = dyn_cast<FieldDecl>(D))
    return !S->isBitField();
  return false;
}

static bool isNonStaticCXXMethod(const Decl *D) {
  if (const auto *S = dyn_cast<CXXMethodDecl>(D))
    return !S->isStatic();
  return false;
}

static bool isClassTmpl(const Decl *D) {
  if (const auto *S = dyn_cast<CXXRecordDecl>(D))
    return S->getDescribedClassTemplate();
  return false;
}

static bool isNonStaticNonConstCXXMethod(const Decl *D) {
  if (const auto *S = dyn_cast<CXXMethodDecl>(D))
    return !S->isStatic() && !S->isConst();
  return false;
}

static bool isNonLocalVar(const Decl *D) {
  if (const auto *S = dyn_cast<VarDecl>(D))
    return !S->hasLocalStorage();
  return false;
}

static bool isFunctionTmpl(const Decl *D) {
  if (const auto *S = dyn_cast<FunctionDecl>(D))
    return S->getTemplatedKind() ==
                                 FunctionDecl::TK_FunctionTemplate;
  return false;
}

static bool isTLSVar(const Decl *D) {
  if (const auto *S = dyn_cast<VarDecl>(D))
    return S->getTLSKind() != 0;
  return false;
}

static constexpr ParsedAttrInfo::Spelling AArch64VectorPcsSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "aarch64_vector_pcs"},
  {AttributeCommonInfo::AS_CXX11, "clang::aarch64_vector_pcs"},
  {AttributeCommonInfo::AS_C2x, "clang::aarch64_vector_pcs"},
};
struct ParsedAttrInfoAArch64VectorPcs final : public ParsedAttrInfo {
  ParsedAttrInfoAArch64VectorPcs() {
    AttrKind = ParsedAttr::AT_AArch64VectorPcs;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 1;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 0;
    Spellings = AArch64VectorPcsSpellings;
  }
static const ParsedAttrInfoAArch64VectorPcs Instance;
};
const ParsedAttrInfoAArch64VectorPcs ParsedAttrInfoAArch64VectorPcs::Instance;
static constexpr ParsedAttrInfo::Spelling AMDGPUFlatWorkGroupSizeSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "amdgpu_flat_work_group_size"},
  {AttributeCommonInfo::AS_CXX11, "clang::amdgpu_flat_work_group_size"},
};
static constexpr const char *AMDGPUFlatWorkGroupSizeArgNames[] = {
"Min","Max",};
struct ParsedAttrInfoAMDGPUFlatWorkGroupSize final : public ParsedAttrInfo {
  ParsedAttrInfoAMDGPUFlatWorkGroupSize() {
    AttrKind = ParsedAttr::AT_AMDGPUFlatWorkGroupSize;
    NumArgs = 2;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = AMDGPUFlatWorkGroupSizeSpellings;
    ArgNames = AMDGPUFlatWorkGroupSizeArgNames;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FunctionDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::err_attribute_wrong_decl_type_str)
      << Attr << "kernel functions";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_function, /*IsSupported=*/true));
}

static const ParsedAttrInfoAMDGPUFlatWorkGroupSize Instance;
};
const ParsedAttrInfoAMDGPUFlatWorkGroupSize ParsedAttrInfoAMDGPUFlatWorkGroupSize::Instance;
static constexpr ParsedAttrInfo::Spelling AMDGPUNumSGPRSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "amdgpu_num_sgpr"},
  {AttributeCommonInfo::AS_CXX11, "clang::amdgpu_num_sgpr"},
};
static constexpr const char *AMDGPUNumSGPRArgNames[] = {
"NumSGPR",};
struct ParsedAttrInfoAMDGPUNumSGPR final : public ParsedAttrInfo {
  ParsedAttrInfoAMDGPUNumSGPR() {
    AttrKind = ParsedAttr::AT_AMDGPUNumSGPR;
    NumArgs = 1;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = AMDGPUNumSGPRSpellings;
    ArgNames = AMDGPUNumSGPRArgNames;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FunctionDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::err_attribute_wrong_decl_type_str)
      << Attr << "kernel functions";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_function, /*IsSupported=*/true));
}

static const ParsedAttrInfoAMDGPUNumSGPR Instance;
};
const ParsedAttrInfoAMDGPUNumSGPR ParsedAttrInfoAMDGPUNumSGPR::Instance;
static constexpr ParsedAttrInfo::Spelling AMDGPUNumVGPRSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "amdgpu_num_vgpr"},
  {AttributeCommonInfo::AS_CXX11, "clang::amdgpu_num_vgpr"},
};
static constexpr const char *AMDGPUNumVGPRArgNames[] = {
"NumVGPR",};
struct ParsedAttrInfoAMDGPUNumVGPR final : public ParsedAttrInfo {
  ParsedAttrInfoAMDGPUNumVGPR() {
    AttrKind = ParsedAttr::AT_AMDGPUNumVGPR;
    NumArgs = 1;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = AMDGPUNumVGPRSpellings;
    ArgNames = AMDGPUNumVGPRArgNames;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FunctionDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::err_attribute_wrong_decl_type_str)
      << Attr << "kernel functions";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_function, /*IsSupported=*/true));
}

static const ParsedAttrInfoAMDGPUNumVGPR Instance;
};
const ParsedAttrInfoAMDGPUNumVGPR ParsedAttrInfoAMDGPUNumVGPR::Instance;
static constexpr ParsedAttrInfo::Spelling AMDGPUWavesPerEUSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "amdgpu_waves_per_eu"},
  {AttributeCommonInfo::AS_CXX11, "clang::amdgpu_waves_per_eu"},
};
static constexpr const char *AMDGPUWavesPerEUArgNames[] = {
"Min","Max",};
struct ParsedAttrInfoAMDGPUWavesPerEU final : public ParsedAttrInfo {
  ParsedAttrInfoAMDGPUWavesPerEU() {
    AttrKind = ParsedAttr::AT_AMDGPUWavesPerEU;
    NumArgs = 1;
    OptArgs = 1;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = AMDGPUWavesPerEUSpellings;
    ArgNames = AMDGPUWavesPerEUArgNames;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FunctionDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::err_attribute_wrong_decl_type_str)
      << Attr << "kernel functions";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_function, /*IsSupported=*/true));
}

static const ParsedAttrInfoAMDGPUWavesPerEU Instance;
};
const ParsedAttrInfoAMDGPUWavesPerEU ParsedAttrInfoAMDGPUWavesPerEU::Instance;
static constexpr ParsedAttrInfo::Spelling InterruptSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "interrupt"},
  {AttributeCommonInfo::AS_CXX11, "gnu::interrupt"},
  {AttributeCommonInfo::AS_C2x, "gnu::interrupt"},
};
static constexpr const char *InterruptArgNames[] = {
"Interrupt",};
struct ParsedAttrInfoInterrupt final : public ParsedAttrInfo {
  ParsedAttrInfoInterrupt() {
    AttrKind = ParsedAttr::AT_Interrupt;
    NumArgs = 0;
    OptArgs = 1;
    HasCustomParsing = 1;
    IsTargetSpecific = 1;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 1;
    IsSupportedByPragmaAttribute = 0;
    Spellings = InterruptSpellings;
    ArgNames = InterruptArgNames;
  }
bool existsInTarget(const TargetInfo &Target) const override {
  const llvm::Triple &T = Target.getTriple(); (void)T;
  return true && (T.getArch() == llvm::Triple::arm || T.getArch() == llvm::Triple::thumb || T.getArch() == llvm::Triple::armeb || T.getArch() == llvm::Triple::thumbeb || T.getArch() == llvm::Triple::avr || T.getArch() == llvm::Triple::x86 || T.getArch() == llvm::Triple::x86_64 || T.getArch() == llvm::Triple::m68k || T.getArch() == llvm::Triple::msp430 || T.getArch() == llvm::Triple::mips || T.getArch() == llvm::Triple::mipsel || T.getArch() == llvm::Triple::riscv32 || T.getArch() == llvm::Triple::riscv64);
}

static const ParsedAttrInfoInterrupt Instance;
};
const ParsedAttrInfoInterrupt ParsedAttrInfoInterrupt::Instance;
static constexpr ParsedAttrInfo::Spelling AVRSignalSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "signal"},
  {AttributeCommonInfo::AS_CXX11, "gnu::signal"},
  {AttributeCommonInfo::AS_C2x, "gnu::signal"},
};
struct ParsedAttrInfoAVRSignal final : public ParsedAttrInfo {
  ParsedAttrInfoAVRSignal() {
    AttrKind = ParsedAttr::AT_AVRSignal;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 1;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 1;
    IsSupportedByPragmaAttribute = 1;
    Spellings = AVRSignalSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FunctionDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "functions";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

bool existsInTarget(const TargetInfo &Target) const override {
  const llvm::Triple &T = Target.getTriple(); (void)T;
  return true && (T.getArch() == llvm::Triple::avr);
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_function, /*IsSupported=*/true));
}

static const ParsedAttrInfoAVRSignal Instance;
};
const ParsedAttrInfoAVRSignal ParsedAttrInfoAVRSignal::Instance;
static constexpr ParsedAttrInfo::Spelling AbiTagSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "abi_tag"},
  {AttributeCommonInfo::AS_CXX11, "gnu::abi_tag"},
};
static constexpr const char *AbiTagArgNames[] = {
"Tags...",};
struct ParsedAttrInfoAbiTag final : public ParsedAttrInfo {
  ParsedAttrInfoAbiTag() {
    AttrKind = ParsedAttr::AT_AbiTag;
    NumArgs = 0;
    OptArgs = 15;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 1;
    IsSupportedByPragmaAttribute = 1;
    Spellings = AbiTagSpellings;
    ArgNames = AbiTagArgNames;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isStruct(D) && !isa<VarDecl>(D) && !isa<FunctionDecl>(D) && !isa<NamespaceDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::err_attribute_wrong_decl_type_str)
      << Attr << "structs, variables, functions, and namespaces";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_record_not_is_union, /*IsSupported=*/true));
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_variable, /*IsSupported=*/true));
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_function, /*IsSupported=*/true));
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_namespace, /*IsSupported=*/LangOpts.CPlusPlus));
}

static const ParsedAttrInfoAbiTag Instance;
};
const ParsedAttrInfoAbiTag ParsedAttrInfoAbiTag::Instance;
static constexpr ParsedAttrInfo::Spelling AcquireCapabilitySpellings[] = {
  {AttributeCommonInfo::AS_GNU, "acquire_capability"},
  {AttributeCommonInfo::AS_CXX11, "clang::acquire_capability"},
  {AttributeCommonInfo::AS_GNU, "acquire_shared_capability"},
  {AttributeCommonInfo::AS_CXX11, "clang::acquire_shared_capability"},
  {AttributeCommonInfo::AS_GNU, "exclusive_lock_function"},
  {AttributeCommonInfo::AS_GNU, "shared_lock_function"},
};
static constexpr const char *AcquireCapabilityArgNames[] = {
"Args...",};
struct ParsedAttrInfoAcquireCapability final : public ParsedAttrInfo {
  ParsedAttrInfoAcquireCapability() {
    AttrKind = ParsedAttr::AT_AcquireCapability;
    NumArgs = 0;
    OptArgs = 15;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 0;
    Spellings = AcquireCapabilitySpellings;
    ArgNames = AcquireCapabilityArgNames;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FunctionDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "functions";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

unsigned spellingIndexToSemanticSpelling(const ParsedAttr &Attr) const override {
  enum Spelling {
    GNU_acquire_capability = 0,
    CXX11_clang_acquire_capability = 1,
    GNU_acquire_shared_capability = 2,
    CXX11_clang_acquire_shared_capability = 3,
    GNU_exclusive_lock_function = 4,
    GNU_shared_lock_function = 5,
  SpellingNotCalculated = 15

  };

  unsigned Idx = Attr.getAttributeSpellingListIndex();
  switch (Idx) {
    default: llvm_unreachable("Unknown spelling list index");
    case 0: return GNU_acquire_capability;
    case 1: return CXX11_clang_acquire_capability;
    case 2: return GNU_acquire_shared_capability;
    case 3: return CXX11_clang_acquire_shared_capability;
    case 4: return GNU_exclusive_lock_function;
    case 5: return GNU_shared_lock_function;
  }
}

static const ParsedAttrInfoAcquireCapability Instance;
};
const ParsedAttrInfoAcquireCapability ParsedAttrInfoAcquireCapability::Instance;
static constexpr ParsedAttrInfo::Spelling AcquireHandleSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "acquire_handle"},
  {AttributeCommonInfo::AS_CXX11, "clang::acquire_handle"},
  {AttributeCommonInfo::AS_C2x, "clang::acquire_handle"},
};
static constexpr const char *AcquireHandleArgNames[] = {
"HandleType",};
struct ParsedAttrInfoAcquireHandle final : public ParsedAttrInfo {
  ParsedAttrInfoAcquireHandle() {
    AttrKind = ParsedAttr::AT_AcquireHandle;
    NumArgs = 1;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 1;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = AcquireHandleSpellings;
    ArgNames = AcquireHandleArgNames;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FunctionDecl>(D) && !isa<TypedefNameDecl>(D) && !isa<ParmVarDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "functions, typedefs, and parameters";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_function, /*IsSupported=*/true));
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_type_alias, /*IsSupported=*/true));
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_variable_is_parameter, /*IsSupported=*/true));
}

static const ParsedAttrInfoAcquireHandle Instance;
};
const ParsedAttrInfoAcquireHandle ParsedAttrInfoAcquireHandle::Instance;
static constexpr ParsedAttrInfo::Spelling AcquiredAfterSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "acquired_after"},
};
static constexpr const char *AcquiredAfterArgNames[] = {
"Args...",};
struct ParsedAttrInfoAcquiredAfter final : public ParsedAttrInfo {
  ParsedAttrInfoAcquiredAfter() {
    AttrKind = ParsedAttr::AT_AcquiredAfter;
    NumArgs = 0;
    OptArgs = 15;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 0;
    Spellings = AcquiredAfterSpellings;
    ArgNames = AcquiredAfterArgNames;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FieldDecl>(D) && !isSharedVar(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "non-static data members and global variables";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

static const ParsedAttrInfoAcquiredAfter Instance;
};
const ParsedAttrInfoAcquiredAfter ParsedAttrInfoAcquiredAfter::Instance;
static constexpr ParsedAttrInfo::Spelling AcquiredBeforeSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "acquired_before"},
};
static constexpr const char *AcquiredBeforeArgNames[] = {
"Args...",};
struct ParsedAttrInfoAcquiredBefore final : public ParsedAttrInfo {
  ParsedAttrInfoAcquiredBefore() {
    AttrKind = ParsedAttr::AT_AcquiredBefore;
    NumArgs = 0;
    OptArgs = 15;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 0;
    Spellings = AcquiredBeforeSpellings;
    ArgNames = AcquiredBeforeArgNames;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FieldDecl>(D) && !isSharedVar(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "non-static data members and global variables";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

static const ParsedAttrInfoAcquiredBefore Instance;
};
const ParsedAttrInfoAcquiredBefore ParsedAttrInfoAcquiredBefore::Instance;
static constexpr ParsedAttrInfo::Spelling AddressSpaceSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "address_space"},
  {AttributeCommonInfo::AS_CXX11, "clang::address_space"},
  {AttributeCommonInfo::AS_C2x, "clang::address_space"},
};
static constexpr const char *AddressSpaceArgNames[] = {
"AddressSpace",};
struct ParsedAttrInfoAddressSpace final : public ParsedAttrInfo {
  ParsedAttrInfoAddressSpace() {
    AttrKind = ParsedAttr::AT_AddressSpace;
    NumArgs = 1;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 1;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 0;
    Spellings = AddressSpaceSpellings;
    ArgNames = AddressSpaceArgNames;
  }
static const ParsedAttrInfoAddressSpace Instance;
};
const ParsedAttrInfoAddressSpace ParsedAttrInfoAddressSpace::Instance;
static constexpr ParsedAttrInfo::Spelling AliasSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "alias"},
  {AttributeCommonInfo::AS_CXX11, "gnu::alias"},
  {AttributeCommonInfo::AS_C2x, "gnu::alias"},
};
static constexpr const char *AliasArgNames[] = {
"Aliasee",};
struct ParsedAttrInfoAlias final : public ParsedAttrInfo {
  ParsedAttrInfoAlias() {
    AttrKind = ParsedAttr::AT_Alias;
    NumArgs = 1;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 1;
    IsSupportedByPragmaAttribute = 1;
    Spellings = AliasSpellings;
    ArgNames = AliasArgNames;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FunctionDecl>(D) && !isGlobalVar(D)) {
    S.Diag(Attr.getLoc(), diag::err_attribute_wrong_decl_type_str)
      << Attr << "functions and global variables";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_function, /*IsSupported=*/true));
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_variable_is_global, /*IsSupported=*/true));
}

static const ParsedAttrInfoAlias Instance;
};
const ParsedAttrInfoAlias ParsedAttrInfoAlias::Instance;
static constexpr ParsedAttrInfo::Spelling AlignValueSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "align_value"},
};
static constexpr const char *AlignValueArgNames[] = {
"Alignment",};
struct ParsedAttrInfoAlignValue final : public ParsedAttrInfo {
  ParsedAttrInfoAlignValue() {
    AttrKind = ParsedAttr::AT_AlignValue;
    NumArgs = 1;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = AlignValueSpellings;
    ArgNames = AlignValueArgNames;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<VarDecl>(D) && !isa<TypedefNameDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "variables and typedefs";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_variable, /*IsSupported=*/true));
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_type_alias, /*IsSupported=*/true));
}

static const ParsedAttrInfoAlignValue Instance;
};
const ParsedAttrInfoAlignValue ParsedAttrInfoAlignValue::Instance;
static constexpr ParsedAttrInfo::Spelling AlignedSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "aligned"},
  {AttributeCommonInfo::AS_CXX11, "gnu::aligned"},
  {AttributeCommonInfo::AS_C2x, "gnu::aligned"},
  {AttributeCommonInfo::AS_Declspec, "align"},
  {AttributeCommonInfo::AS_Keyword, "alignas"},
  {AttributeCommonInfo::AS_Keyword, "_Alignas"},
};
static constexpr const char *AlignedArgNames[] = {
"Alignment",};
struct ParsedAttrInfoAligned final : public ParsedAttrInfo {
  ParsedAttrInfoAligned() {
    AttrKind = ParsedAttr::AT_Aligned;
    NumArgs = 0;
    OptArgs = 1;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 1;
    IsSupportedByPragmaAttribute = 0;
    Spellings = AlignedSpellings;
    ArgNames = AlignedArgNames;
  }
unsigned spellingIndexToSemanticSpelling(const ParsedAttr &Attr) const override {
  enum Spelling {
    GNU_aligned = 0,
    CXX11_gnu_aligned = 1,
    C2x_gnu_aligned = 2,
    Declspec_align = 3,
    Keyword_alignas = 4,
    Keyword_Alignas = 5,
  SpellingNotCalculated = 15

  };

  unsigned Idx = Attr.getAttributeSpellingListIndex();
  switch (Idx) {
    default: llvm_unreachable("Unknown spelling list index");
    case 0: return GNU_aligned;
    case 1: return CXX11_gnu_aligned;
    case 2: return C2x_gnu_aligned;
    case 3: return Declspec_align;
    case 4: return Keyword_alignas;
    case 5: return Keyword_Alignas;
  }
}

static const ParsedAttrInfoAligned Instance;
};
const ParsedAttrInfoAligned ParsedAttrInfoAligned::Instance;
static constexpr ParsedAttrInfo::Spelling AllocAlignSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "alloc_align"},
  {AttributeCommonInfo::AS_CXX11, "gnu::alloc_align"},
  {AttributeCommonInfo::AS_C2x, "gnu::alloc_align"},
};
static constexpr const char *AllocAlignArgNames[] = {
"ParamIndex",};
struct ParsedAttrInfoAllocAlign final : public ParsedAttrInfo {
  ParsedAttrInfoAllocAlign() {
    AttrKind = ParsedAttr::AT_AllocAlign;
    NumArgs = 1;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 1;
    IsSupportedByPragmaAttribute = 0;
    Spellings = AllocAlignSpellings;
    ArgNames = AllocAlignArgNames;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isHasFunctionProto(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "non-K&R-style functions";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

static const ParsedAttrInfoAllocAlign Instance;
};
const ParsedAttrInfoAllocAlign ParsedAttrInfoAllocAlign::Instance;
static constexpr ParsedAttrInfo::Spelling AllocSizeSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "alloc_size"},
  {AttributeCommonInfo::AS_CXX11, "gnu::alloc_size"},
  {AttributeCommonInfo::AS_C2x, "gnu::alloc_size"},
};
static constexpr const char *AllocSizeArgNames[] = {
"ElemSizeParam","NumElemsParam",};
struct ParsedAttrInfoAllocSize final : public ParsedAttrInfo {
  ParsedAttrInfoAllocSize() {
    AttrKind = ParsedAttr::AT_AllocSize;
    NumArgs = 1;
    OptArgs = 1;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 1;
    IsSupportedByPragmaAttribute = 0;
    Spellings = AllocSizeSpellings;
    ArgNames = AllocSizeArgNames;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isHasFunctionProto(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "non-K&R-style functions";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

static const ParsedAttrInfoAllocSize Instance;
};
const ParsedAttrInfoAllocSize ParsedAttrInfoAllocSize::Instance;
static constexpr ParsedAttrInfo::Spelling AlwaysDestroySpellings[] = {
  {AttributeCommonInfo::AS_GNU, "always_destroy"},
  {AttributeCommonInfo::AS_CXX11, "clang::always_destroy"},
};
struct ParsedAttrInfoAlwaysDestroy final : public ParsedAttrInfo {
  ParsedAttrInfoAlwaysDestroy() {
    AttrKind = ParsedAttr::AT_AlwaysDestroy;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = AlwaysDestroySpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<VarDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "variables";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

  using ParsedAttrInfo::diagMutualExclusion;

  bool diagMutualExclusion(Sema &S, const ParsedAttr &AL, const Decl *D) const override {
    if (const auto *A = D->getAttr<NoDestroyAttr>()) {
      S.Diag(AL.getLoc(), diag::err_attributes_are_not_compatible) << AL << A;
      S.Diag(A->getLocation(), diag::note_conflicting_attribute);      
return false;
    }
    return true;
  }

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_variable, /*IsSupported=*/true));
}

static const ParsedAttrInfoAlwaysDestroy Instance;
};
const ParsedAttrInfoAlwaysDestroy ParsedAttrInfoAlwaysDestroy::Instance;
static constexpr ParsedAttrInfo::Spelling AlwaysInlineSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "always_inline"},
  {AttributeCommonInfo::AS_CXX11, "gnu::always_inline"},
  {AttributeCommonInfo::AS_C2x, "gnu::always_inline"},
  {AttributeCommonInfo::AS_Keyword, "__forceinline"},
};
struct ParsedAttrInfoAlwaysInline final : public ParsedAttrInfo {
  ParsedAttrInfoAlwaysInline() {
    AttrKind = ParsedAttr::AT_AlwaysInline;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 1;
    IsSupportedByPragmaAttribute = 1;
    Spellings = AlwaysInlineSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FunctionDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "functions";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

  using ParsedAttrInfo::diagMutualExclusion;

  bool diagMutualExclusion(Sema &S, const ParsedAttr &AL, const Decl *D) const override {
    if (const auto *A = D->getAttr<NotTailCalledAttr>()) {
      S.Diag(AL.getLoc(), diag::err_attributes_are_not_compatible) << AL << A;
      S.Diag(A->getLocation(), diag::note_conflicting_attribute);      
return false;
    }
    return true;
  }

unsigned spellingIndexToSemanticSpelling(const ParsedAttr &Attr) const override {
  enum Spelling {
    GNU_always_inline = 0,
    CXX11_gnu_always_inline = 1,
    C2x_gnu_always_inline = 2,
    Keyword_forceinline = 3,
  SpellingNotCalculated = 15

  };

  unsigned Idx = Attr.getAttributeSpellingListIndex();
  switch (Idx) {
    default: llvm_unreachable("Unknown spelling list index");
    case 0: return GNU_always_inline;
    case 1: return CXX11_gnu_always_inline;
    case 2: return C2x_gnu_always_inline;
    case 3: return Keyword_forceinline;
  }
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_function, /*IsSupported=*/true));
}

static const ParsedAttrInfoAlwaysInline Instance;
};
const ParsedAttrInfoAlwaysInline ParsedAttrInfoAlwaysInline::Instance;
static constexpr ParsedAttrInfo::Spelling AnalyzerNoReturnSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "analyzer_noreturn"},
};
struct ParsedAttrInfoAnalyzerNoReturn final : public ParsedAttrInfo {
  ParsedAttrInfoAnalyzerNoReturn() {
    AttrKind = ParsedAttr::AT_AnalyzerNoReturn;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 0;
    Spellings = AnalyzerNoReturnSpellings;
  }
static const ParsedAttrInfoAnalyzerNoReturn Instance;
};
const ParsedAttrInfoAnalyzerNoReturn ParsedAttrInfoAnalyzerNoReturn::Instance;
static constexpr ParsedAttrInfo::Spelling AnnotateSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "annotate"},
  {AttributeCommonInfo::AS_CXX11, "clang::annotate"},
  {AttributeCommonInfo::AS_C2x, "clang::annotate"},
};
static constexpr const char *AnnotateArgNames[] = {
"Annotation","Args...",};
struct ParsedAttrInfoAnnotate final : public ParsedAttrInfo {
  ParsedAttrInfoAnnotate() {
    AttrKind = ParsedAttr::AT_Annotate;
    NumArgs = 1;
    OptArgs = 15;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = AnnotateSpellings;
    ArgNames = AnnotateArgNames;
  }
static const ParsedAttrInfoAnnotate Instance;
};
const ParsedAttrInfoAnnotate ParsedAttrInfoAnnotate::Instance;
static constexpr ParsedAttrInfo::Spelling AnyX86NoCallerSavedRegistersSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "no_caller_saved_registers"},
  {AttributeCommonInfo::AS_CXX11, "gnu::no_caller_saved_registers"},
  {AttributeCommonInfo::AS_C2x, "gnu::no_caller_saved_registers"},
};
struct ParsedAttrInfoAnyX86NoCallerSavedRegisters final : public ParsedAttrInfo {
  ParsedAttrInfoAnyX86NoCallerSavedRegisters() {
    AttrKind = ParsedAttr::AT_AnyX86NoCallerSavedRegisters;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 1;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 1;
    IsSupportedByPragmaAttribute = 0;
    Spellings = AnyX86NoCallerSavedRegistersSpellings;
  }
bool existsInTarget(const TargetInfo &Target) const override {
  const llvm::Triple &T = Target.getTriple(); (void)T;
  return true && (T.getArch() == llvm::Triple::x86 || T.getArch() == llvm::Triple::x86_64);
}

AttrHandling handleDeclAttribute(Sema &S, Decl *D,const ParsedAttr &Attr) const override {
  D->addAttr(::new (S.Context) AnyX86NoCallerSavedRegistersAttr(S.Context, Attr));
  return AttributeApplied;
}

static const ParsedAttrInfoAnyX86NoCallerSavedRegisters Instance;
};
const ParsedAttrInfoAnyX86NoCallerSavedRegisters ParsedAttrInfoAnyX86NoCallerSavedRegisters::Instance;
static constexpr ParsedAttrInfo::Spelling AnyX86NoCfCheckSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "nocf_check"},
  {AttributeCommonInfo::AS_CXX11, "gnu::nocf_check"},
  {AttributeCommonInfo::AS_C2x, "gnu::nocf_check"},
};
struct ParsedAttrInfoAnyX86NoCfCheck final : public ParsedAttrInfo {
  ParsedAttrInfoAnyX86NoCfCheck() {
    AttrKind = ParsedAttr::AT_AnyX86NoCfCheck;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 1;
    IsType = 1;
    IsStmt = 0;
    IsKnownToGCC = 1;
    IsSupportedByPragmaAttribute = 1;
    Spellings = AnyX86NoCfCheckSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isFunctionLike(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "functions and function pointers";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

bool existsInTarget(const TargetInfo &Target) const override {
  const llvm::Triple &T = Target.getTriple(); (void)T;
  return true && (T.getArch() == llvm::Triple::x86 || T.getArch() == llvm::Triple::x86_64);
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_hasType_functionType, /*IsSupported=*/true));
}

static const ParsedAttrInfoAnyX86NoCfCheck Instance;
};
const ParsedAttrInfoAnyX86NoCfCheck ParsedAttrInfoAnyX86NoCfCheck::Instance;
static constexpr ParsedAttrInfo::Spelling ArcWeakrefUnavailableSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "objc_arc_weak_reference_unavailable"},
  {AttributeCommonInfo::AS_CXX11, "clang::objc_arc_weak_reference_unavailable"},
  {AttributeCommonInfo::AS_C2x, "clang::objc_arc_weak_reference_unavailable"},
};
struct ParsedAttrInfoArcWeakrefUnavailable final : public ParsedAttrInfo {
  ParsedAttrInfoArcWeakrefUnavailable() {
    AttrKind = ParsedAttr::AT_ArcWeakrefUnavailable;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = ArcWeakrefUnavailableSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<ObjCInterfaceDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::err_attribute_wrong_decl_type_str)
      << Attr << "Objective-C interfaces";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_objc_interface, /*IsSupported=*/LangOpts.ObjC));
}

AttrHandling handleDeclAttribute(Sema &S, Decl *D,const ParsedAttr &Attr) const override {
  D->addAttr(::new (S.Context) ArcWeakrefUnavailableAttr(S.Context, Attr));
  return AttributeApplied;
}

static const ParsedAttrInfoArcWeakrefUnavailable Instance;
};
const ParsedAttrInfoArcWeakrefUnavailable ParsedAttrInfoArcWeakrefUnavailable::Instance;
static constexpr ParsedAttrInfo::Spelling ArgumentWithTypeTagSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "argument_with_type_tag"},
  {AttributeCommonInfo::AS_CXX11, "clang::argument_with_type_tag"},
  {AttributeCommonInfo::AS_C2x, "clang::argument_with_type_tag"},
  {AttributeCommonInfo::AS_GNU, "pointer_with_type_tag"},
  {AttributeCommonInfo::AS_CXX11, "clang::pointer_with_type_tag"},
  {AttributeCommonInfo::AS_C2x, "clang::pointer_with_type_tag"},
};
static constexpr const char *ArgumentWithTypeTagArgNames[] = {
"ArgumentKind","ArgumentIdx","TypeTagIdx",};
struct ParsedAttrInfoArgumentWithTypeTag final : public ParsedAttrInfo {
  ParsedAttrInfoArgumentWithTypeTag() {
    AttrKind = ParsedAttr::AT_ArgumentWithTypeTag;
    NumArgs = 3;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 0;
    Spellings = ArgumentWithTypeTagSpellings;
    ArgNames = ArgumentWithTypeTagArgNames;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isHasFunctionProto(D)) {
    S.Diag(Attr.getLoc(), diag::err_attribute_wrong_decl_type_str)
      << Attr << "non-K&R-style functions";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

unsigned spellingIndexToSemanticSpelling(const ParsedAttr &Attr) const override {
  enum Spelling {
    GNU_argument_with_type_tag = 0,
    CXX11_clang_argument_with_type_tag = 1,
    C2x_clang_argument_with_type_tag = 2,
    GNU_pointer_with_type_tag = 3,
    CXX11_clang_pointer_with_type_tag = 4,
    C2x_clang_pointer_with_type_tag = 5,
  SpellingNotCalculated = 15

  };

  unsigned Idx = Attr.getAttributeSpellingListIndex();
  switch (Idx) {
    default: llvm_unreachable("Unknown spelling list index");
    case 0: return GNU_argument_with_type_tag;
    case 1: return CXX11_clang_argument_with_type_tag;
    case 2: return C2x_clang_argument_with_type_tag;
    case 3: return GNU_pointer_with_type_tag;
    case 4: return CXX11_clang_pointer_with_type_tag;
    case 5: return C2x_clang_pointer_with_type_tag;
  }
}

static const ParsedAttrInfoArgumentWithTypeTag Instance;
};
const ParsedAttrInfoArgumentWithTypeTag ParsedAttrInfoArgumentWithTypeTag::Instance;
static constexpr ParsedAttrInfo::Spelling ArmBuiltinAliasSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "__clang_arm_builtin_alias"},
  {AttributeCommonInfo::AS_CXX11, "clang::__clang_arm_builtin_alias"},
  {AttributeCommonInfo::AS_C2x, "clang::__clang_arm_builtin_alias"},
};
static constexpr const char *ArmBuiltinAliasArgNames[] = {
"BuiltinName",};
struct ParsedAttrInfoArmBuiltinAlias final : public ParsedAttrInfo {
  ParsedAttrInfoArmBuiltinAlias() {
    AttrKind = ParsedAttr::AT_ArmBuiltinAlias;
    NumArgs = 1;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 1;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = ArmBuiltinAliasSpellings;
    ArgNames = ArmBuiltinAliasArgNames;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FunctionDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::err_attribute_wrong_decl_type_str)
      << Attr << "functions";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

bool existsInTarget(const TargetInfo &Target) const override {
  const llvm::Triple &T = Target.getTriple(); (void)T;
  return true && (T.getArch() == llvm::Triple::arm || T.getArch() == llvm::Triple::thumb || T.getArch() == llvm::Triple::armeb || T.getArch() == llvm::Triple::thumbeb || T.getArch() == llvm::Triple::aarch64);
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_function, /*IsSupported=*/true));
}

static const ParsedAttrInfoArmBuiltinAlias Instance;
};
const ParsedAttrInfoArmBuiltinAlias ParsedAttrInfoArmBuiltinAlias::Instance;
static constexpr ParsedAttrInfo::Spelling ArmMveStrictPolymorphismSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "__clang_arm_mve_strict_polymorphism"},
  {AttributeCommonInfo::AS_CXX11, "clang::__clang_arm_mve_strict_polymorphism"},
  {AttributeCommonInfo::AS_C2x, "clang::__clang_arm_mve_strict_polymorphism"},
};
struct ParsedAttrInfoArmMveStrictPolymorphism final : public ParsedAttrInfo {
  ParsedAttrInfoArmMveStrictPolymorphism() {
    AttrKind = ParsedAttr::AT_ArmMveStrictPolymorphism;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 1;
    IsType = 1;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 0;
    Spellings = ArmMveStrictPolymorphismSpellings;
  }
bool existsInTarget(const TargetInfo &Target) const override {
  const llvm::Triple &T = Target.getTriple(); (void)T;
  return true && (T.getArch() == llvm::Triple::arm || T.getArch() == llvm::Triple::thumb || T.getArch() == llvm::Triple::armeb || T.getArch() == llvm::Triple::thumbeb);
}

static const ParsedAttrInfoArmMveStrictPolymorphism Instance;
};
const ParsedAttrInfoArmMveStrictPolymorphism ParsedAttrInfoArmMveStrictPolymorphism::Instance;
static constexpr ParsedAttrInfo::Spelling ArmSveVectorBitsSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "arm_sve_vector_bits"},
};
static constexpr const char *ArmSveVectorBitsArgNames[] = {
"NumBits",};
struct ParsedAttrInfoArmSveVectorBits final : public ParsedAttrInfo {
  ParsedAttrInfoArmSveVectorBits() {
    AttrKind = ParsedAttr::AT_ArmSveVectorBits;
    NumArgs = 1;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 1;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 0;
    Spellings = ArmSveVectorBitsSpellings;
    ArgNames = ArmSveVectorBitsArgNames;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<TypedefNameDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::err_attribute_wrong_decl_type_str)
      << Attr << "typedefs";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

static const ParsedAttrInfoArmSveVectorBits Instance;
};
const ParsedAttrInfoArmSveVectorBits ParsedAttrInfoArmSveVectorBits::Instance;
static constexpr ParsedAttrInfo::Spelling ArtificialSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "artificial"},
  {AttributeCommonInfo::AS_CXX11, "gnu::artificial"},
  {AttributeCommonInfo::AS_C2x, "gnu::artificial"},
};
struct ParsedAttrInfoArtificial final : public ParsedAttrInfo {
  ParsedAttrInfoArtificial() {
    AttrKind = ParsedAttr::AT_Artificial;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 1;
    IsSupportedByPragmaAttribute = 0;
    Spellings = ArtificialSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isInlineFunction(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "inline functions";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

AttrHandling handleDeclAttribute(Sema &S, Decl *D,const ParsedAttr &Attr) const override {
  D->addAttr(::new (S.Context) ArtificialAttr(S.Context, Attr));
  return AttributeApplied;
}

static const ParsedAttrInfoArtificial Instance;
};
const ParsedAttrInfoArtificial ParsedAttrInfoArtificial::Instance;
static constexpr ParsedAttrInfo::Spelling AssertCapabilitySpellings[] = {
  {AttributeCommonInfo::AS_GNU, "assert_capability"},
  {AttributeCommonInfo::AS_CXX11, "clang::assert_capability"},
  {AttributeCommonInfo::AS_GNU, "assert_shared_capability"},
  {AttributeCommonInfo::AS_CXX11, "clang::assert_shared_capability"},
};
static constexpr const char *AssertCapabilityArgNames[] = {
"Args...",};
struct ParsedAttrInfoAssertCapability final : public ParsedAttrInfo {
  ParsedAttrInfoAssertCapability() {
    AttrKind = ParsedAttr::AT_AssertCapability;
    NumArgs = 0;
    OptArgs = 15;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 0;
    Spellings = AssertCapabilitySpellings;
    ArgNames = AssertCapabilityArgNames;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FunctionDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "functions";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

unsigned spellingIndexToSemanticSpelling(const ParsedAttr &Attr) const override {
  enum Spelling {
    GNU_assert_capability = 0,
    CXX11_clang_assert_capability = 1,
    GNU_assert_shared_capability = 2,
    CXX11_clang_assert_shared_capability = 3,
  SpellingNotCalculated = 15

  };

  unsigned Idx = Attr.getAttributeSpellingListIndex();
  switch (Idx) {
    default: llvm_unreachable("Unknown spelling list index");
    case 0: return GNU_assert_capability;
    case 1: return CXX11_clang_assert_capability;
    case 2: return GNU_assert_shared_capability;
    case 3: return CXX11_clang_assert_shared_capability;
  }
}

static const ParsedAttrInfoAssertCapability Instance;
};
const ParsedAttrInfoAssertCapability ParsedAttrInfoAssertCapability::Instance;
static constexpr ParsedAttrInfo::Spelling AssertExclusiveLockSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "assert_exclusive_lock"},
};
static constexpr const char *AssertExclusiveLockArgNames[] = {
"Args...",};
struct ParsedAttrInfoAssertExclusiveLock final : public ParsedAttrInfo {
  ParsedAttrInfoAssertExclusiveLock() {
    AttrKind = ParsedAttr::AT_AssertExclusiveLock;
    NumArgs = 0;
    OptArgs = 15;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 0;
    Spellings = AssertExclusiveLockSpellings;
    ArgNames = AssertExclusiveLockArgNames;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FunctionDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "functions";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

static const ParsedAttrInfoAssertExclusiveLock Instance;
};
const ParsedAttrInfoAssertExclusiveLock ParsedAttrInfoAssertExclusiveLock::Instance;
static constexpr ParsedAttrInfo::Spelling AssertSharedLockSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "assert_shared_lock"},
};
static constexpr const char *AssertSharedLockArgNames[] = {
"Args...",};
struct ParsedAttrInfoAssertSharedLock final : public ParsedAttrInfo {
  ParsedAttrInfoAssertSharedLock() {
    AttrKind = ParsedAttr::AT_AssertSharedLock;
    NumArgs = 0;
    OptArgs = 15;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 0;
    Spellings = AssertSharedLockSpellings;
    ArgNames = AssertSharedLockArgNames;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FunctionDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "functions";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

static const ParsedAttrInfoAssertSharedLock Instance;
};
const ParsedAttrInfoAssertSharedLock ParsedAttrInfoAssertSharedLock::Instance;
static constexpr ParsedAttrInfo::Spelling AssumeAlignedSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "assume_aligned"},
  {AttributeCommonInfo::AS_CXX11, "gnu::assume_aligned"},
  {AttributeCommonInfo::AS_C2x, "gnu::assume_aligned"},
};
static constexpr const char *AssumeAlignedArgNames[] = {
"Alignment","Offset",};
struct ParsedAttrInfoAssumeAligned final : public ParsedAttrInfo {
  ParsedAttrInfoAssumeAligned() {
    AttrKind = ParsedAttr::AT_AssumeAligned;
    NumArgs = 1;
    OptArgs = 1;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 1;
    IsSupportedByPragmaAttribute = 1;
    Spellings = AssumeAlignedSpellings;
    ArgNames = AssumeAlignedArgNames;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<ObjCMethodDecl>(D) && !isa<FunctionDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "Objective-C methods and functions";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_objc_method, /*IsSupported=*/LangOpts.ObjC));
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_function, /*IsSupported=*/true));
}

static const ParsedAttrInfoAssumeAligned Instance;
};
const ParsedAttrInfoAssumeAligned ParsedAttrInfoAssumeAligned::Instance;
static constexpr ParsedAttrInfo::Spelling AssumptionSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "assume"},
  {AttributeCommonInfo::AS_CXX11, "clang::assume"},
  {AttributeCommonInfo::AS_C2x, "clang::assume"},
};
static constexpr const char *AssumptionArgNames[] = {
"Assumption",};
struct ParsedAttrInfoAssumption final : public ParsedAttrInfo {
  ParsedAttrInfoAssumption() {
    AttrKind = ParsedAttr::AT_Assumption;
    NumArgs = 1;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = AssumptionSpellings;
    ArgNames = AssumptionArgNames;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FunctionDecl>(D) && !isa<ObjCMethodDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "functions and Objective-C methods";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_function, /*IsSupported=*/true));
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_objc_method, /*IsSupported=*/LangOpts.ObjC));
}

static const ParsedAttrInfoAssumption Instance;
};
const ParsedAttrInfoAssumption ParsedAttrInfoAssumption::Instance;
static constexpr ParsedAttrInfo::Spelling AvailabilitySpellings[] = {
  {AttributeCommonInfo::AS_GNU, "availability"},
  {AttributeCommonInfo::AS_CXX11, "clang::availability"},
  {AttributeCommonInfo::AS_C2x, "clang::availability"},
};
static constexpr const char *AvailabilityArgNames[] = {
"platform","introduced","deprecated","obsoleted","unavailable","message","strict","replacement","priority",};
struct ParsedAttrInfoAvailability final : public ParsedAttrInfo {
  ParsedAttrInfoAvailability() {
    AttrKind = ParsedAttr::AT_Availability;
    NumArgs = 9;
    OptArgs = 0;
    HasCustomParsing = 1;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = AvailabilitySpellings;
    ArgNames = AvailabilityArgNames;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<NamedDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "named declarations";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_record, /*IsSupported=*/true));
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_enum, /*IsSupported=*/true));
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_enum_constant, /*IsSupported=*/true));
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_field, /*IsSupported=*/true));
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_function, /*IsSupported=*/true));
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_namespace, /*IsSupported=*/LangOpts.CPlusPlus));
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_objc_category, /*IsSupported=*/LangOpts.ObjC));
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_objc_implementation, /*IsSupported=*/LangOpts.ObjC));
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_objc_interface, /*IsSupported=*/LangOpts.ObjC));
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_objc_method, /*IsSupported=*/LangOpts.ObjC));
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_objc_property, /*IsSupported=*/LangOpts.ObjC));
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_objc_protocol, /*IsSupported=*/LangOpts.ObjC));
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_record, /*IsSupported=*/true));
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_type_alias, /*IsSupported=*/true));
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_variable, /*IsSupported=*/true));
}

static const ParsedAttrInfoAvailability Instance;
};
const ParsedAttrInfoAvailability ParsedAttrInfoAvailability::Instance;
static constexpr ParsedAttrInfo::Spelling BPFPreserveAccessIndexSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "preserve_access_index"},
  {AttributeCommonInfo::AS_CXX11, "clang::preserve_access_index"},
  {AttributeCommonInfo::AS_C2x, "clang::preserve_access_index"},
};
struct ParsedAttrInfoBPFPreserveAccessIndex final : public ParsedAttrInfo {
  ParsedAttrInfoBPFPreserveAccessIndex() {
    AttrKind = ParsedAttr::AT_BPFPreserveAccessIndex;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 1;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = BPFPreserveAccessIndexSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<RecordDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::err_attribute_wrong_decl_type_str)
      << Attr << "structs, unions, and classes";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

bool acceptsLangOpts(const LangOptions &LangOpts) const override {
  return (!LangOpts.CPlusPlus);
}

bool existsInTarget(const TargetInfo &Target) const override {
  const llvm::Triple &T = Target.getTriple(); (void)T;
  return true && (T.getArch() == llvm::Triple::bpfel || T.getArch() == llvm::Triple::bpfeb);
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_record, /*IsSupported=*/true));
}

static const ParsedAttrInfoBPFPreserveAccessIndex Instance;
};
const ParsedAttrInfoBPFPreserveAccessIndex ParsedAttrInfoBPFPreserveAccessIndex::Instance;
static constexpr ParsedAttrInfo::Spelling BTFDeclTagSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "btf_decl_tag"},
  {AttributeCommonInfo::AS_CXX11, "clang::btf_decl_tag"},
  {AttributeCommonInfo::AS_C2x, "clang::btf_decl_tag"},
};
static constexpr const char *BTFDeclTagArgNames[] = {
"BTFDeclTag",};
struct ParsedAttrInfoBTFDeclTag final : public ParsedAttrInfo {
  ParsedAttrInfoBTFDeclTag() {
    AttrKind = ParsedAttr::AT_BTFDeclTag;
    NumArgs = 1;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = BTFDeclTagSpellings;
    ArgNames = BTFDeclTagArgNames;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<VarDecl>(D) && !isa<FunctionDecl>(D) && !isa<RecordDecl>(D) && !isa<FieldDecl>(D) && !isa<TypedefNameDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::err_attribute_wrong_decl_type_str)
      << Attr << "variables, functions, structs, unions, classes, non-static data members, and typedefs";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

bool acceptsLangOpts(const LangOptions &LangOpts) const override {
  return (!LangOpts.CPlusPlus);
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_variable, /*IsSupported=*/true));
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_function, /*IsSupported=*/true));
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_record, /*IsSupported=*/true));
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_field, /*IsSupported=*/true));
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_type_alias, /*IsSupported=*/true));
}

static const ParsedAttrInfoBTFDeclTag Instance;
};
const ParsedAttrInfoBTFDeclTag ParsedAttrInfoBTFDeclTag::Instance;
static constexpr ParsedAttrInfo::Spelling BTFTypeTagSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "btf_type_tag"},
  {AttributeCommonInfo::AS_CXX11, "clang::btf_type_tag"},
  {AttributeCommonInfo::AS_C2x, "clang::btf_type_tag"},
};
static constexpr const char *BTFTypeTagArgNames[] = {
"BTFTypeTag",};
struct ParsedAttrInfoBTFTypeTag final : public ParsedAttrInfo {
  ParsedAttrInfoBTFTypeTag() {
    AttrKind = ParsedAttr::AT_BTFTypeTag;
    NumArgs = 1;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 1;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 0;
    Spellings = BTFTypeTagSpellings;
    ArgNames = BTFTypeTagArgNames;
  }
bool acceptsLangOpts(const LangOptions &LangOpts) const override {
  return (!LangOpts.CPlusPlus);
}

static const ParsedAttrInfoBTFTypeTag Instance;
};
const ParsedAttrInfoBTFTypeTag ParsedAttrInfoBTFTypeTag::Instance;
static constexpr ParsedAttrInfo::Spelling BlocksSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "blocks"},
  {AttributeCommonInfo::AS_CXX11, "clang::blocks"},
  {AttributeCommonInfo::AS_C2x, "clang::blocks"},
};
static constexpr const char *BlocksArgNames[] = {
"Type",};
struct ParsedAttrInfoBlocks final : public ParsedAttrInfo {
  ParsedAttrInfoBlocks() {
    AttrKind = ParsedAttr::AT_Blocks;
    NumArgs = 1;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 0;
    Spellings = BlocksSpellings;
    ArgNames = BlocksArgNames;
  }
static const ParsedAttrInfoBlocks Instance;
};
const ParsedAttrInfoBlocks ParsedAttrInfoBlocks::Instance;
static constexpr ParsedAttrInfo::Spelling BuiltinAliasSpellings[] = {
  {AttributeCommonInfo::AS_CXX11, "clang::builtin_alias"},
  {AttributeCommonInfo::AS_C2x, "clang::builtin_alias"},
  {AttributeCommonInfo::AS_GNU, "clang_builtin_alias"},
};
static constexpr const char *BuiltinAliasArgNames[] = {
"BuiltinName",};
struct ParsedAttrInfoBuiltinAlias final : public ParsedAttrInfo {
  ParsedAttrInfoBuiltinAlias() {
    AttrKind = ParsedAttr::AT_BuiltinAlias;
    NumArgs = 1;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = BuiltinAliasSpellings;
    ArgNames = BuiltinAliasArgNames;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FunctionDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::err_attribute_wrong_decl_type_str)
      << Attr << "functions";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

unsigned spellingIndexToSemanticSpelling(const ParsedAttr &Attr) const override {
  enum Spelling {
    CXX11_clang_builtin_alias = 0,
    C2x_clang_builtin_alias = 1,
    GNU_clang_builtin_alias = 2,
  SpellingNotCalculated = 15

  };

  unsigned Idx = Attr.getAttributeSpellingListIndex();
  switch (Idx) {
    default: llvm_unreachable("Unknown spelling list index");
    case 0: return CXX11_clang_builtin_alias;
    case 1: return C2x_clang_builtin_alias;
    case 2: return GNU_clang_builtin_alias;
  }
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_function, /*IsSupported=*/true));
}

static const ParsedAttrInfoBuiltinAlias Instance;
};
const ParsedAttrInfoBuiltinAlias ParsedAttrInfoBuiltinAlias::Instance;
static constexpr ParsedAttrInfo::Spelling CDeclSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "cdecl"},
  {AttributeCommonInfo::AS_CXX11, "gnu::cdecl"},
  {AttributeCommonInfo::AS_C2x, "gnu::cdecl"},
  {AttributeCommonInfo::AS_Keyword, "__cdecl"},
  {AttributeCommonInfo::AS_Keyword, "_cdecl"},
};
struct ParsedAttrInfoCDecl final : public ParsedAttrInfo {
  ParsedAttrInfoCDecl() {
    AttrKind = ParsedAttr::AT_CDecl;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 1;
    IsStmt = 0;
    IsKnownToGCC = 1;
    IsSupportedByPragmaAttribute = 0;
    Spellings = CDeclSpellings;
  }
static const ParsedAttrInfoCDecl Instance;
};
const ParsedAttrInfoCDecl ParsedAttrInfoCDecl::Instance;
static constexpr ParsedAttrInfo::Spelling CFAuditedTransferSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "cf_audited_transfer"},
  {AttributeCommonInfo::AS_CXX11, "clang::cf_audited_transfer"},
  {AttributeCommonInfo::AS_C2x, "clang::cf_audited_transfer"},
};
struct ParsedAttrInfoCFAuditedTransfer final : public ParsedAttrInfo {
  ParsedAttrInfoCFAuditedTransfer() {
    AttrKind = ParsedAttr::AT_CFAuditedTransfer;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = CFAuditedTransferSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FunctionDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::err_attribute_wrong_decl_type_str)
      << Attr << "functions";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

  using ParsedAttrInfo::diagMutualExclusion;

  bool diagMutualExclusion(Sema &S, const ParsedAttr &AL, const Decl *D) const override {
    if (const auto *A = D->getAttr<CFUnknownTransferAttr>()) {
      S.Diag(AL.getLoc(), diag::err_attributes_are_not_compatible) << AL << A;
      S.Diag(A->getLocation(), diag::note_conflicting_attribute);      
return false;
    }
    return true;
  }

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_function, /*IsSupported=*/true));
}

AttrHandling handleDeclAttribute(Sema &S, Decl *D,const ParsedAttr &Attr) const override {
  D->addAttr(::new (S.Context) CFAuditedTransferAttr(S.Context, Attr));
  return AttributeApplied;
}

static const ParsedAttrInfoCFAuditedTransfer Instance;
};
const ParsedAttrInfoCFAuditedTransfer ParsedAttrInfoCFAuditedTransfer::Instance;
static constexpr ParsedAttrInfo::Spelling CFConsumedSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "cf_consumed"},
  {AttributeCommonInfo::AS_CXX11, "clang::cf_consumed"},
  {AttributeCommonInfo::AS_C2x, "clang::cf_consumed"},
};
struct ParsedAttrInfoCFConsumed final : public ParsedAttrInfo {
  ParsedAttrInfoCFConsumed() {
    AttrKind = ParsedAttr::AT_CFConsumed;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = CFConsumedSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<ParmVarDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "parameters";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_variable_is_parameter, /*IsSupported=*/true));
}

static const ParsedAttrInfoCFConsumed Instance;
};
const ParsedAttrInfoCFConsumed ParsedAttrInfoCFConsumed::Instance;
static constexpr ParsedAttrInfo::Spelling CFGuardSpellings[] = {
  {AttributeCommonInfo::AS_Declspec, "guard"},
};
static constexpr const char *CFGuardArgNames[] = {
"Guard",};
struct ParsedAttrInfoCFGuard final : public ParsedAttrInfo {
  ParsedAttrInfoCFGuard() {
    AttrKind = ParsedAttr::AT_CFGuard;
    NumArgs = 1;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 0;
    Spellings = CFGuardSpellings;
    ArgNames = CFGuardArgNames;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FunctionDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "functions";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

static const ParsedAttrInfoCFGuard Instance;
};
const ParsedAttrInfoCFGuard ParsedAttrInfoCFGuard::Instance;
static constexpr ParsedAttrInfo::Spelling CFICanonicalJumpTableSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "cfi_canonical_jump_table"},
  {AttributeCommonInfo::AS_CXX11, "clang::cfi_canonical_jump_table"},
  {AttributeCommonInfo::AS_C2x, "clang::cfi_canonical_jump_table"},
};
struct ParsedAttrInfoCFICanonicalJumpTable final : public ParsedAttrInfo {
  ParsedAttrInfoCFICanonicalJumpTable() {
    AttrKind = ParsedAttr::AT_CFICanonicalJumpTable;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = CFICanonicalJumpTableSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FunctionDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::err_attribute_wrong_decl_type_str)
      << Attr << "functions";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_function, /*IsSupported=*/true));
}

AttrHandling handleDeclAttribute(Sema &S, Decl *D,const ParsedAttr &Attr) const override {
  D->addAttr(::new (S.Context) CFICanonicalJumpTableAttr(S.Context, Attr));
  return AttributeApplied;
}

static const ParsedAttrInfoCFICanonicalJumpTable Instance;
};
const ParsedAttrInfoCFICanonicalJumpTable ParsedAttrInfoCFICanonicalJumpTable::Instance;
static constexpr ParsedAttrInfo::Spelling CFReturnsNotRetainedSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "cf_returns_not_retained"},
  {AttributeCommonInfo::AS_CXX11, "clang::cf_returns_not_retained"},
  {AttributeCommonInfo::AS_C2x, "clang::cf_returns_not_retained"},
};
struct ParsedAttrInfoCFReturnsNotRetained final : public ParsedAttrInfo {
  ParsedAttrInfoCFReturnsNotRetained() {
    AttrKind = ParsedAttr::AT_CFReturnsNotRetained;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 0;
    Spellings = CFReturnsNotRetainedSpellings;
  }
static const ParsedAttrInfoCFReturnsNotRetained Instance;
};
const ParsedAttrInfoCFReturnsNotRetained ParsedAttrInfoCFReturnsNotRetained::Instance;
static constexpr ParsedAttrInfo::Spelling CFReturnsRetainedSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "cf_returns_retained"},
  {AttributeCommonInfo::AS_CXX11, "clang::cf_returns_retained"},
  {AttributeCommonInfo::AS_C2x, "clang::cf_returns_retained"},
};
struct ParsedAttrInfoCFReturnsRetained final : public ParsedAttrInfo {
  ParsedAttrInfoCFReturnsRetained() {
    AttrKind = ParsedAttr::AT_CFReturnsRetained;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 0;
    Spellings = CFReturnsRetainedSpellings;
  }
static const ParsedAttrInfoCFReturnsRetained Instance;
};
const ParsedAttrInfoCFReturnsRetained ParsedAttrInfoCFReturnsRetained::Instance;
static constexpr ParsedAttrInfo::Spelling CFUnknownTransferSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "cf_unknown_transfer"},
  {AttributeCommonInfo::AS_CXX11, "clang::cf_unknown_transfer"},
  {AttributeCommonInfo::AS_C2x, "clang::cf_unknown_transfer"},
};
struct ParsedAttrInfoCFUnknownTransfer final : public ParsedAttrInfo {
  ParsedAttrInfoCFUnknownTransfer() {
    AttrKind = ParsedAttr::AT_CFUnknownTransfer;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = CFUnknownTransferSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FunctionDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::err_attribute_wrong_decl_type_str)
      << Attr << "functions";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

  using ParsedAttrInfo::diagMutualExclusion;

  bool diagMutualExclusion(Sema &S, const ParsedAttr &AL, const Decl *D) const override {
    if (const auto *A = D->getAttr<CFAuditedTransferAttr>()) {
      S.Diag(AL.getLoc(), diag::err_attributes_are_not_compatible) << AL << A;
      S.Diag(A->getLocation(), diag::note_conflicting_attribute);      
return false;
    }
    return true;
  }

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_function, /*IsSupported=*/true));
}

AttrHandling handleDeclAttribute(Sema &S, Decl *D,const ParsedAttr &Attr) const override {
  D->addAttr(::new (S.Context) CFUnknownTransferAttr(S.Context, Attr));
  return AttributeApplied;
}

static const ParsedAttrInfoCFUnknownTransfer Instance;
};
const ParsedAttrInfoCFUnknownTransfer ParsedAttrInfoCFUnknownTransfer::Instance;
static constexpr ParsedAttrInfo::Spelling CPUDispatchSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "cpu_dispatch"},
  {AttributeCommonInfo::AS_CXX11, "clang::cpu_dispatch"},
  {AttributeCommonInfo::AS_C2x, "clang::cpu_dispatch"},
  {AttributeCommonInfo::AS_Declspec, "cpu_dispatch"},
};
static constexpr const char *CPUDispatchArgNames[] = {
"Cpus...",};
struct ParsedAttrInfoCPUDispatch final : public ParsedAttrInfo {
  ParsedAttrInfoCPUDispatch() {
    AttrKind = ParsedAttr::AT_CPUDispatch;
    NumArgs = 0;
    OptArgs = 15;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = CPUDispatchSpellings;
    ArgNames = CPUDispatchArgNames;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FunctionDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "functions";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

  using ParsedAttrInfo::diagMutualExclusion;

  bool diagMutualExclusion(Sema &S, const ParsedAttr &AL, const Decl *D) const override {
    if (const auto *A = D->getAttr<TargetClonesAttr>()) {
      S.Diag(AL.getLoc(), diag::err_attributes_are_not_compatible) << AL << A;
      S.Diag(A->getLocation(), diag::note_conflicting_attribute);      
return false;
    }
    if (const auto *A = D->getAttr<TargetAttr>()) {
      S.Diag(AL.getLoc(), diag::err_attributes_are_not_compatible) << AL << A;
      S.Diag(A->getLocation(), diag::note_conflicting_attribute);      
return false;
    }
    if (const auto *A = D->getAttr<CPUSpecificAttr>()) {
      S.Diag(AL.getLoc(), diag::err_attributes_are_not_compatible) << AL << A;
      S.Diag(A->getLocation(), diag::note_conflicting_attribute);      
return false;
    }
    return true;
  }

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_function, /*IsSupported=*/true));
}

static const ParsedAttrInfoCPUDispatch Instance;
};
const ParsedAttrInfoCPUDispatch ParsedAttrInfoCPUDispatch::Instance;
static constexpr ParsedAttrInfo::Spelling CPUSpecificSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "cpu_specific"},
  {AttributeCommonInfo::AS_CXX11, "clang::cpu_specific"},
  {AttributeCommonInfo::AS_C2x, "clang::cpu_specific"},
  {AttributeCommonInfo::AS_Declspec, "cpu_specific"},
};
static constexpr const char *CPUSpecificArgNames[] = {
"Cpus...",};
struct ParsedAttrInfoCPUSpecific final : public ParsedAttrInfo {
  ParsedAttrInfoCPUSpecific() {
    AttrKind = ParsedAttr::AT_CPUSpecific;
    NumArgs = 0;
    OptArgs = 15;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = CPUSpecificSpellings;
    ArgNames = CPUSpecificArgNames;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FunctionDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "functions";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

  using ParsedAttrInfo::diagMutualExclusion;

  bool diagMutualExclusion(Sema &S, const ParsedAttr &AL, const Decl *D) const override {
    if (const auto *A = D->getAttr<TargetClonesAttr>()) {
      S.Diag(AL.getLoc(), diag::err_attributes_are_not_compatible) << AL << A;
      S.Diag(A->getLocation(), diag::note_conflicting_attribute);      
return false;
    }
    if (const auto *A = D->getAttr<TargetAttr>()) {
      S.Diag(AL.getLoc(), diag::err_attributes_are_not_compatible) << AL << A;
      S.Diag(A->getLocation(), diag::note_conflicting_attribute);      
return false;
    }
    if (const auto *A = D->getAttr<CPUDispatchAttr>()) {
      S.Diag(AL.getLoc(), diag::err_attributes_are_not_compatible) << AL << A;
      S.Diag(A->getLocation(), diag::note_conflicting_attribute);      
return false;
    }
    return true;
  }

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_function, /*IsSupported=*/true));
}

static const ParsedAttrInfoCPUSpecific Instance;
};
const ParsedAttrInfoCPUSpecific ParsedAttrInfoCPUSpecific::Instance;
static constexpr ParsedAttrInfo::Spelling CUDAConstantSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "constant"},
  {AttributeCommonInfo::AS_Declspec, "__constant__"},
};
struct ParsedAttrInfoCUDAConstant final : public ParsedAttrInfo {
  ParsedAttrInfoCUDAConstant() {
    AttrKind = ParsedAttr::AT_CUDAConstant;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = CUDAConstantSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<VarDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "variables";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

  using ParsedAttrInfo::diagMutualExclusion;

  bool diagMutualExclusion(Sema &S, const ParsedAttr &AL, const Decl *D) const override {
    if (const auto *A = D->getAttr<CUDASharedAttr>()) {
      S.Diag(AL.getLoc(), diag::err_attributes_are_not_compatible) << AL << A;
      S.Diag(A->getLocation(), diag::note_conflicting_attribute);      
return false;
    }
    if (const auto *A = D->getAttr<HIPManagedAttr>()) {
      S.Diag(AL.getLoc(), diag::err_attributes_are_not_compatible) << AL << A;
      S.Diag(A->getLocation(), diag::note_conflicting_attribute);      
return false;
    }
    return true;
  }

bool acceptsLangOpts(const LangOptions &LangOpts) const override {
  return LangOpts.CUDA;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_variable, /*IsSupported=*/true));
}

static const ParsedAttrInfoCUDAConstant Instance;
};
const ParsedAttrInfoCUDAConstant ParsedAttrInfoCUDAConstant::Instance;
static constexpr ParsedAttrInfo::Spelling CUDADeviceSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "device"},
  {AttributeCommonInfo::AS_Declspec, "__device__"},
};
struct ParsedAttrInfoCUDADevice final : public ParsedAttrInfo {
  ParsedAttrInfoCUDADevice() {
    AttrKind = ParsedAttr::AT_CUDADevice;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = CUDADeviceSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FunctionDecl>(D) && !isa<VarDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "functions and variables";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

  using ParsedAttrInfo::diagMutualExclusion;

  bool diagMutualExclusion(Sema &S, const ParsedAttr &AL, const Decl *D) const override {
    if (const auto *A = D->getAttr<CUDAGlobalAttr>()) {
      S.Diag(AL.getLoc(), diag::err_attributes_are_not_compatible) << AL << A;
      S.Diag(A->getLocation(), diag::note_conflicting_attribute);      
return false;
    }
    return true;
  }

bool acceptsLangOpts(const LangOptions &LangOpts) const override {
  return LangOpts.CUDA;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_function, /*IsSupported=*/true));
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_variable, /*IsSupported=*/true));
}

static const ParsedAttrInfoCUDADevice Instance;
};
const ParsedAttrInfoCUDADevice ParsedAttrInfoCUDADevice::Instance;
static constexpr ParsedAttrInfo::Spelling CUDADeviceBuiltinSurfaceTypeSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "device_builtin_surface_type"},
  {AttributeCommonInfo::AS_Declspec, "__device_builtin_surface_type__"},
};
struct ParsedAttrInfoCUDADeviceBuiltinSurfaceType final : public ParsedAttrInfo {
  ParsedAttrInfoCUDADeviceBuiltinSurfaceType() {
    AttrKind = ParsedAttr::AT_CUDADeviceBuiltinSurfaceType;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = CUDADeviceBuiltinSurfaceTypeSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<CXXRecordDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "classes";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

  using ParsedAttrInfo::diagMutualExclusion;

  bool diagMutualExclusion(Sema &S, const ParsedAttr &AL, const Decl *D) const override {
    if (const auto *A = D->getAttr<CUDADeviceBuiltinTextureTypeAttr>()) {
      S.Diag(AL.getLoc(), diag::err_attributes_are_not_compatible) << AL << A;
      S.Diag(A->getLocation(), diag::note_conflicting_attribute);      
return false;
    }
    return true;
  }

bool acceptsLangOpts(const LangOptions &LangOpts) const override {
  return LangOpts.CUDA;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_record, /*IsSupported=*/true));
}

AttrHandling handleDeclAttribute(Sema &S, Decl *D,const ParsedAttr &Attr) const override {
  D->addAttr(::new (S.Context) CUDADeviceBuiltinSurfaceTypeAttr(S.Context, Attr));
  return AttributeApplied;
}

static const ParsedAttrInfoCUDADeviceBuiltinSurfaceType Instance;
};
const ParsedAttrInfoCUDADeviceBuiltinSurfaceType ParsedAttrInfoCUDADeviceBuiltinSurfaceType::Instance;
static constexpr ParsedAttrInfo::Spelling CUDADeviceBuiltinTextureTypeSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "device_builtin_texture_type"},
  {AttributeCommonInfo::AS_Declspec, "__device_builtin_texture_type__"},
};
struct ParsedAttrInfoCUDADeviceBuiltinTextureType final : public ParsedAttrInfo {
  ParsedAttrInfoCUDADeviceBuiltinTextureType() {
    AttrKind = ParsedAttr::AT_CUDADeviceBuiltinTextureType;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = CUDADeviceBuiltinTextureTypeSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<CXXRecordDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "classes";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

  using ParsedAttrInfo::diagMutualExclusion;

  bool diagMutualExclusion(Sema &S, const ParsedAttr &AL, const Decl *D) const override {
    if (const auto *A = D->getAttr<CUDADeviceBuiltinSurfaceTypeAttr>()) {
      S.Diag(AL.getLoc(), diag::err_attributes_are_not_compatible) << AL << A;
      S.Diag(A->getLocation(), diag::note_conflicting_attribute);      
return false;
    }
    return true;
  }

bool acceptsLangOpts(const LangOptions &LangOpts) const override {
  return LangOpts.CUDA;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_record, /*IsSupported=*/true));
}

AttrHandling handleDeclAttribute(Sema &S, Decl *D,const ParsedAttr &Attr) const override {
  D->addAttr(::new (S.Context) CUDADeviceBuiltinTextureTypeAttr(S.Context, Attr));
  return AttributeApplied;
}

static const ParsedAttrInfoCUDADeviceBuiltinTextureType Instance;
};
const ParsedAttrInfoCUDADeviceBuiltinTextureType ParsedAttrInfoCUDADeviceBuiltinTextureType::Instance;
static constexpr ParsedAttrInfo::Spelling CUDAGlobalSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "global"},
  {AttributeCommonInfo::AS_Declspec, "__global__"},
};
struct ParsedAttrInfoCUDAGlobal final : public ParsedAttrInfo {
  ParsedAttrInfoCUDAGlobal() {
    AttrKind = ParsedAttr::AT_CUDAGlobal;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = CUDAGlobalSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FunctionDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "functions";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

  using ParsedAttrInfo::diagMutualExclusion;

  bool diagMutualExclusion(Sema &S, const ParsedAttr &AL, const Decl *D) const override {
    if (const auto *A = D->getAttr<CUDADeviceAttr>()) {
      S.Diag(AL.getLoc(), diag::err_attributes_are_not_compatible) << AL << A;
      S.Diag(A->getLocation(), diag::note_conflicting_attribute);      
return false;
    }
    if (const auto *A = D->getAttr<CUDAHostAttr>()) {
      S.Diag(AL.getLoc(), diag::err_attributes_are_not_compatible) << AL << A;
      S.Diag(A->getLocation(), diag::note_conflicting_attribute);      
return false;
    }
    return true;
  }

bool acceptsLangOpts(const LangOptions &LangOpts) const override {
  return LangOpts.CUDA;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_function, /*IsSupported=*/true));
}

static const ParsedAttrInfoCUDAGlobal Instance;
};
const ParsedAttrInfoCUDAGlobal ParsedAttrInfoCUDAGlobal::Instance;
static constexpr ParsedAttrInfo::Spelling CUDAHostSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "host"},
  {AttributeCommonInfo::AS_Declspec, "__host__"},
};
struct ParsedAttrInfoCUDAHost final : public ParsedAttrInfo {
  ParsedAttrInfoCUDAHost() {
    AttrKind = ParsedAttr::AT_CUDAHost;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = CUDAHostSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FunctionDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "functions";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

  using ParsedAttrInfo::diagMutualExclusion;

  bool diagMutualExclusion(Sema &S, const ParsedAttr &AL, const Decl *D) const override {
    if (const auto *A = D->getAttr<CUDAGlobalAttr>()) {
      S.Diag(AL.getLoc(), diag::err_attributes_are_not_compatible) << AL << A;
      S.Diag(A->getLocation(), diag::note_conflicting_attribute);      
return false;
    }
    return true;
  }

bool acceptsLangOpts(const LangOptions &LangOpts) const override {
  return LangOpts.CUDA;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_function, /*IsSupported=*/true));
}

AttrHandling handleDeclAttribute(Sema &S, Decl *D,const ParsedAttr &Attr) const override {
  D->addAttr(::new (S.Context) CUDAHostAttr(S.Context, Attr));
  return AttributeApplied;
}

static const ParsedAttrInfoCUDAHost Instance;
};
const ParsedAttrInfoCUDAHost ParsedAttrInfoCUDAHost::Instance;
struct ParsedAttrInfoCUDAInvalidTarget final : public ParsedAttrInfo {
  ParsedAttrInfoCUDAInvalidTarget() {
    AttrKind = ParsedAttr::AT_CUDAInvalidTarget;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 0;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FunctionDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "functions";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

bool acceptsLangOpts(const LangOptions &LangOpts) const override {
  return LangOpts.CUDA;
}

static const ParsedAttrInfoCUDAInvalidTarget Instance;
};
const ParsedAttrInfoCUDAInvalidTarget ParsedAttrInfoCUDAInvalidTarget::Instance;
static constexpr ParsedAttrInfo::Spelling CUDALaunchBoundsSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "launch_bounds"},
  {AttributeCommonInfo::AS_Declspec, "__launch_bounds__"},
};
static constexpr const char *CUDALaunchBoundsArgNames[] = {
"MaxThreads","MinBlocks",};
struct ParsedAttrInfoCUDALaunchBounds final : public ParsedAttrInfo {
  ParsedAttrInfoCUDALaunchBounds() {
    AttrKind = ParsedAttr::AT_CUDALaunchBounds;
    NumArgs = 1;
    OptArgs = 1;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = CUDALaunchBoundsSpellings;
    ArgNames = CUDALaunchBoundsArgNames;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<ObjCMethodDecl>(D) && !isFunctionLike(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "Objective-C methods, functions, and function pointers";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

bool acceptsLangOpts(const LangOptions &LangOpts) const override {
  return LangOpts.CUDA;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_objc_method, /*IsSupported=*/LangOpts.ObjC));
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_hasType_functionType, /*IsSupported=*/true));
}

static const ParsedAttrInfoCUDALaunchBounds Instance;
};
const ParsedAttrInfoCUDALaunchBounds ParsedAttrInfoCUDALaunchBounds::Instance;
static constexpr ParsedAttrInfo::Spelling CUDASharedSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "shared"},
  {AttributeCommonInfo::AS_Declspec, "__shared__"},
};
struct ParsedAttrInfoCUDAShared final : public ParsedAttrInfo {
  ParsedAttrInfoCUDAShared() {
    AttrKind = ParsedAttr::AT_CUDAShared;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = CUDASharedSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<VarDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "variables";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

  using ParsedAttrInfo::diagMutualExclusion;

  bool diagMutualExclusion(Sema &S, const ParsedAttr &AL, const Decl *D) const override {
    if (const auto *A = D->getAttr<CUDAConstantAttr>()) {
      S.Diag(AL.getLoc(), diag::err_attributes_are_not_compatible) << AL << A;
      S.Diag(A->getLocation(), diag::note_conflicting_attribute);      
return false;
    }
    if (const auto *A = D->getAttr<HIPManagedAttr>()) {
      S.Diag(AL.getLoc(), diag::err_attributes_are_not_compatible) << AL << A;
      S.Diag(A->getLocation(), diag::note_conflicting_attribute);      
return false;
    }
    return true;
  }

bool acceptsLangOpts(const LangOptions &LangOpts) const override {
  return LangOpts.CUDA;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_variable, /*IsSupported=*/true));
}

static const ParsedAttrInfoCUDAShared Instance;
};
const ParsedAttrInfoCUDAShared ParsedAttrInfoCUDAShared::Instance;
static constexpr ParsedAttrInfo::Spelling CXX11NoReturnSpellings[] = {
  {AttributeCommonInfo::AS_CXX11, "noreturn"},
};
struct ParsedAttrInfoCXX11NoReturn final : public ParsedAttrInfo {
  ParsedAttrInfoCXX11NoReturn() {
    AttrKind = ParsedAttr::AT_CXX11NoReturn;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = CXX11NoReturnSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FunctionDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::err_attribute_wrong_decl_type_str)
      << Attr << "functions";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_function, /*IsSupported=*/true));
}

AttrHandling handleDeclAttribute(Sema &S, Decl *D,const ParsedAttr &Attr) const override {
  D->addAttr(::new (S.Context) CXX11NoReturnAttr(S.Context, Attr));
  return AttributeApplied;
}

static const ParsedAttrInfoCXX11NoReturn Instance;
};
const ParsedAttrInfoCXX11NoReturn ParsedAttrInfoCXX11NoReturn::Instance;
static constexpr ParsedAttrInfo::Spelling CallableWhenSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "callable_when"},
  {AttributeCommonInfo::AS_CXX11, "clang::callable_when"},
};
static constexpr const char *CallableWhenArgNames[] = {
"CallableStates...",};
struct ParsedAttrInfoCallableWhen final : public ParsedAttrInfo {
  ParsedAttrInfoCallableWhen() {
    AttrKind = ParsedAttr::AT_CallableWhen;
    NumArgs = 0;
    OptArgs = 15;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = CallableWhenSpellings;
    ArgNames = CallableWhenArgNames;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<CXXMethodDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "functions";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_function_is_member, /*IsSupported=*/LangOpts.CPlusPlus));
}

static const ParsedAttrInfoCallableWhen Instance;
};
const ParsedAttrInfoCallableWhen ParsedAttrInfoCallableWhen::Instance;
static constexpr ParsedAttrInfo::Spelling CallbackSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "callback"},
  {AttributeCommonInfo::AS_CXX11, "clang::callback"},
  {AttributeCommonInfo::AS_C2x, "clang::callback"},
};
static constexpr const char *CallbackArgNames[] = {
"Encoding...",};
struct ParsedAttrInfoCallback final : public ParsedAttrInfo {
  ParsedAttrInfoCallback() {
    AttrKind = ParsedAttr::AT_Callback;
    NumArgs = 0;
    OptArgs = 15;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = CallbackSpellings;
    ArgNames = CallbackArgNames;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FunctionDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "functions";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_function, /*IsSupported=*/true));
}

static const ParsedAttrInfoCallback Instance;
};
const ParsedAttrInfoCallback ParsedAttrInfoCallback::Instance;
static constexpr ParsedAttrInfo::Spelling CalledOnceSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "called_once"},
  {AttributeCommonInfo::AS_CXX11, "clang::called_once"},
  {AttributeCommonInfo::AS_C2x, "clang::called_once"},
};
struct ParsedAttrInfoCalledOnce final : public ParsedAttrInfo {
  ParsedAttrInfoCalledOnce() {
    AttrKind = ParsedAttr::AT_CalledOnce;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = CalledOnceSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<ParmVarDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "parameters";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

bool acceptsLangOpts(const LangOptions &LangOpts) const override {
  return LangOpts.ObjC;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_variable_is_parameter, /*IsSupported=*/true));
}

static const ParsedAttrInfoCalledOnce Instance;
};
const ParsedAttrInfoCalledOnce ParsedAttrInfoCalledOnce::Instance;
static constexpr ParsedAttrInfo::Spelling CapabilitySpellings[] = {
  {AttributeCommonInfo::AS_GNU, "capability"},
  {AttributeCommonInfo::AS_CXX11, "clang::capability"},
  {AttributeCommonInfo::AS_GNU, "shared_capability"},
  {AttributeCommonInfo::AS_CXX11, "clang::shared_capability"},
};
static constexpr const char *CapabilityArgNames[] = {
"Name",};
struct ParsedAttrInfoCapability final : public ParsedAttrInfo {
  ParsedAttrInfoCapability() {
    AttrKind = ParsedAttr::AT_Capability;
    NumArgs = 1;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = CapabilitySpellings;
    ArgNames = CapabilityArgNames;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<RecordDecl>(D) && !isa<TypedefNameDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::err_attribute_wrong_decl_type_str)
      << Attr << "structs, unions, classes, and typedefs";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

unsigned spellingIndexToSemanticSpelling(const ParsedAttr &Attr) const override {
  enum Spelling {
    GNU_capability = 0,
    CXX11_clang_capability = 1,
    GNU_shared_capability = 2,
    CXX11_clang_shared_capability = 3,
  SpellingNotCalculated = 15

  };

  unsigned Idx = Attr.getAttributeSpellingListIndex();
  switch (Idx) {
    default: llvm_unreachable("Unknown spelling list index");
    case 0: return GNU_capability;
    case 1: return CXX11_clang_capability;
    case 2: return GNU_shared_capability;
    case 3: return CXX11_clang_shared_capability;
  }
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_record, /*IsSupported=*/true));
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_type_alias, /*IsSupported=*/true));
}

static const ParsedAttrInfoCapability Instance;
};
const ParsedAttrInfoCapability ParsedAttrInfoCapability::Instance;
static constexpr ParsedAttrInfo::Spelling CarriesDependencySpellings[] = {
  {AttributeCommonInfo::AS_GNU, "carries_dependency"},
  {AttributeCommonInfo::AS_CXX11, "carries_dependency"},
};
struct ParsedAttrInfoCarriesDependency final : public ParsedAttrInfo {
  ParsedAttrInfoCarriesDependency() {
    AttrKind = ParsedAttr::AT_CarriesDependency;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = CarriesDependencySpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<ParmVarDecl>(D) && !isa<ObjCMethodDecl>(D) && !isa<FunctionDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::err_attribute_wrong_decl_type_str)
      << Attr << "parameters, Objective-C methods, and functions";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_variable_is_parameter, /*IsSupported=*/true));
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_objc_method, /*IsSupported=*/LangOpts.ObjC));
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_function, /*IsSupported=*/true));
}

static const ParsedAttrInfoCarriesDependency Instance;
};
const ParsedAttrInfoCarriesDependency ParsedAttrInfoCarriesDependency::Instance;
static constexpr ParsedAttrInfo::Spelling CleanupSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "cleanup"},
  {AttributeCommonInfo::AS_CXX11, "gnu::cleanup"},
  {AttributeCommonInfo::AS_C2x, "gnu::cleanup"},
};
static constexpr const char *CleanupArgNames[] = {
"FunctionDecl",};
struct ParsedAttrInfoCleanup final : public ParsedAttrInfo {
  ParsedAttrInfoCleanup() {
    AttrKind = ParsedAttr::AT_Cleanup;
    NumArgs = 1;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 1;
    IsSupportedByPragmaAttribute = 1;
    Spellings = CleanupSpellings;
    ArgNames = CleanupArgNames;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isLocalVar(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "local variables";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_variable_is_local, /*IsSupported=*/true));
}

static const ParsedAttrInfoCleanup Instance;
};
const ParsedAttrInfoCleanup ParsedAttrInfoCleanup::Instance;
static constexpr ParsedAttrInfo::Spelling CmseNSCallSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "cmse_nonsecure_call"},
};
struct ParsedAttrInfoCmseNSCall final : public ParsedAttrInfo {
  ParsedAttrInfoCmseNSCall() {
    AttrKind = ParsedAttr::AT_CmseNSCall;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 1;
    IsType = 1;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 0;
    Spellings = CmseNSCallSpellings;
  }
bool acceptsLangOpts(const LangOptions &LangOpts) const override {
  return LangOpts.Cmse;
}

bool existsInTarget(const TargetInfo &Target) const override {
  const llvm::Triple &T = Target.getTriple(); (void)T;
  return true && (T.getArch() == llvm::Triple::arm || T.getArch() == llvm::Triple::thumb || T.getArch() == llvm::Triple::armeb || T.getArch() == llvm::Triple::thumbeb);
}

static const ParsedAttrInfoCmseNSCall Instance;
};
const ParsedAttrInfoCmseNSCall ParsedAttrInfoCmseNSCall::Instance;
static constexpr ParsedAttrInfo::Spelling CmseNSEntrySpellings[] = {
  {AttributeCommonInfo::AS_GNU, "cmse_nonsecure_entry"},
};
struct ParsedAttrInfoCmseNSEntry final : public ParsedAttrInfo {
  ParsedAttrInfoCmseNSEntry() {
    AttrKind = ParsedAttr::AT_CmseNSEntry;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 1;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = CmseNSEntrySpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FunctionDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "functions";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

bool acceptsLangOpts(const LangOptions &LangOpts) const override {
  return LangOpts.Cmse;
}

bool existsInTarget(const TargetInfo &Target) const override {
  const llvm::Triple &T = Target.getTriple(); (void)T;
  return true && (T.getArch() == llvm::Triple::arm || T.getArch() == llvm::Triple::thumb || T.getArch() == llvm::Triple::armeb || T.getArch() == llvm::Triple::thumbeb);
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_function, /*IsSupported=*/true));
}

static const ParsedAttrInfoCmseNSEntry Instance;
};
const ParsedAttrInfoCmseNSEntry ParsedAttrInfoCmseNSEntry::Instance;
static constexpr ParsedAttrInfo::Spelling CodeSegSpellings[] = {
  {AttributeCommonInfo::AS_Declspec, "code_seg"},
};
static constexpr const char *CodeSegArgNames[] = {
"Name",};
struct ParsedAttrInfoCodeSeg final : public ParsedAttrInfo {
  ParsedAttrInfoCodeSeg() {
    AttrKind = ParsedAttr::AT_CodeSeg;
    NumArgs = 1;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 0;
    Spellings = CodeSegSpellings;
    ArgNames = CodeSegArgNames;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FunctionDecl>(D) && !isa<CXXRecordDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::err_attribute_wrong_decl_type_str)
      << Attr << "functions and classes";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

static const ParsedAttrInfoCodeSeg Instance;
};
const ParsedAttrInfoCodeSeg ParsedAttrInfoCodeSeg::Instance;
static constexpr ParsedAttrInfo::Spelling ColdSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "cold"},
  {AttributeCommonInfo::AS_CXX11, "gnu::cold"},
  {AttributeCommonInfo::AS_C2x, "gnu::cold"},
};
struct ParsedAttrInfoCold final : public ParsedAttrInfo {
  ParsedAttrInfoCold() {
    AttrKind = ParsedAttr::AT_Cold;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 1;
    IsSupportedByPragmaAttribute = 1;
    Spellings = ColdSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FunctionDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "functions";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

  using ParsedAttrInfo::diagMutualExclusion;

  bool diagMutualExclusion(Sema &S, const ParsedAttr &AL, const Decl *D) const override {
    if (const auto *A = D->getAttr<HotAttr>()) {
      S.Diag(AL.getLoc(), diag::err_attributes_are_not_compatible) << AL << A;
      S.Diag(A->getLocation(), diag::note_conflicting_attribute);      
return false;
    }
    return true;
  }

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_function, /*IsSupported=*/true));
}

AttrHandling handleDeclAttribute(Sema &S, Decl *D,const ParsedAttr &Attr) const override {
  D->addAttr(::new (S.Context) ColdAttr(S.Context, Attr));
  return AttributeApplied;
}

static const ParsedAttrInfoCold Instance;
};
const ParsedAttrInfoCold ParsedAttrInfoCold::Instance;
static constexpr ParsedAttrInfo::Spelling CommonSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "common"},
  {AttributeCommonInfo::AS_CXX11, "gnu::common"},
  {AttributeCommonInfo::AS_C2x, "gnu::common"},
};
struct ParsedAttrInfoCommon final : public ParsedAttrInfo {
  ParsedAttrInfoCommon() {
    AttrKind = ParsedAttr::AT_Common;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 1;
    IsSupportedByPragmaAttribute = 1;
    Spellings = CommonSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<VarDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "variables";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

  using ParsedAttrInfo::diagMutualExclusion;

  bool diagMutualExclusion(Sema &S, const ParsedAttr &AL, const Decl *D) const override {
    if (const auto *A = D->getAttr<InternalLinkageAttr>()) {
      S.Diag(AL.getLoc(), diag::err_attributes_are_not_compatible) << AL << A;
      S.Diag(A->getLocation(), diag::note_conflicting_attribute);      
return false;
    }
    return true;
  }

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_variable, /*IsSupported=*/true));
}

static const ParsedAttrInfoCommon Instance;
};
const ParsedAttrInfoCommon ParsedAttrInfoCommon::Instance;
static constexpr ParsedAttrInfo::Spelling ConstSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "const"},
  {AttributeCommonInfo::AS_CXX11, "gnu::const"},
  {AttributeCommonInfo::AS_C2x, "gnu::const"},
  {AttributeCommonInfo::AS_GNU, "__const"},
  {AttributeCommonInfo::AS_CXX11, "gnu::__const"},
  {AttributeCommonInfo::AS_C2x, "gnu::__const"},
};
struct ParsedAttrInfoConst final : public ParsedAttrInfo {
  ParsedAttrInfoConst() {
    AttrKind = ParsedAttr::AT_Const;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 1;
    IsSupportedByPragmaAttribute = 0;
    Spellings = ConstSpellings;
  }
AttrHandling handleDeclAttribute(Sema &S, Decl *D,const ParsedAttr &Attr) const override {
  D->addAttr(::new (S.Context) ConstAttr(S.Context, Attr));
  return AttributeApplied;
}

static const ParsedAttrInfoConst Instance;
};
const ParsedAttrInfoConst ParsedAttrInfoConst::Instance;
static constexpr ParsedAttrInfo::Spelling ConstInitSpellings[] = {
  {AttributeCommonInfo::AS_Keyword, "constinit"},
  {AttributeCommonInfo::AS_GNU, "require_constant_initialization"},
  {AttributeCommonInfo::AS_CXX11, "clang::require_constant_initialization"},
};
struct ParsedAttrInfoConstInit final : public ParsedAttrInfo {
  ParsedAttrInfoConstInit() {
    AttrKind = ParsedAttr::AT_ConstInit;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = ConstInitSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isGlobalVar(D)) {
    S.Diag(Attr.getLoc(), diag::err_attribute_wrong_decl_type_str)
      << Attr << "global variables";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

bool acceptsLangOpts(const LangOptions &LangOpts) const override {
  return LangOpts.CPlusPlus;
}

unsigned spellingIndexToSemanticSpelling(const ParsedAttr &Attr) const override {
  enum Spelling {
    Keyword_constinit = 0,
    GNU_require_constant_initialization = 1,
    CXX11_clang_require_constant_initialization = 2,
  SpellingNotCalculated = 15

  };

  unsigned Idx = Attr.getAttributeSpellingListIndex();
  switch (Idx) {
    default: llvm_unreachable("Unknown spelling list index");
    case 0: return Keyword_constinit;
    case 1: return GNU_require_constant_initialization;
    case 2: return CXX11_clang_require_constant_initialization;
  }
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_variable_is_global, /*IsSupported=*/true));
}

AttrHandling handleDeclAttribute(Sema &S, Decl *D,const ParsedAttr &Attr) const override {
  D->addAttr(::new (S.Context) ConstInitAttr(S.Context, Attr));
  return AttributeApplied;
}

static const ParsedAttrInfoConstInit Instance;
};
const ParsedAttrInfoConstInit ParsedAttrInfoConstInit::Instance;
static constexpr ParsedAttrInfo::Spelling ConstructorSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "constructor"},
  {AttributeCommonInfo::AS_CXX11, "gnu::constructor"},
  {AttributeCommonInfo::AS_C2x, "gnu::constructor"},
};
static constexpr const char *ConstructorArgNames[] = {
"Priority",};
struct ParsedAttrInfoConstructor final : public ParsedAttrInfo {
  ParsedAttrInfoConstructor() {
    AttrKind = ParsedAttr::AT_Constructor;
    NumArgs = 0;
    OptArgs = 1;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 1;
    IsSupportedByPragmaAttribute = 1;
    Spellings = ConstructorSpellings;
    ArgNames = ConstructorArgNames;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FunctionDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "functions";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_function, /*IsSupported=*/true));
}

static const ParsedAttrInfoConstructor Instance;
};
const ParsedAttrInfoConstructor ParsedAttrInfoConstructor::Instance;
static constexpr ParsedAttrInfo::Spelling ConsumableSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "consumable"},
  {AttributeCommonInfo::AS_CXX11, "clang::consumable"},
};
static constexpr const char *ConsumableArgNames[] = {
"DefaultState",};
struct ParsedAttrInfoConsumable final : public ParsedAttrInfo {
  ParsedAttrInfoConsumable() {
    AttrKind = ParsedAttr::AT_Consumable;
    NumArgs = 1;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = ConsumableSpellings;
    ArgNames = ConsumableArgNames;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<CXXRecordDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "classes";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_record, /*IsSupported=*/true));
}

static const ParsedAttrInfoConsumable Instance;
};
const ParsedAttrInfoConsumable ParsedAttrInfoConsumable::Instance;
static constexpr ParsedAttrInfo::Spelling ConsumableAutoCastSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "consumable_auto_cast_state"},
  {AttributeCommonInfo::AS_CXX11, "clang::consumable_auto_cast_state"},
};
struct ParsedAttrInfoConsumableAutoCast final : public ParsedAttrInfo {
  ParsedAttrInfoConsumableAutoCast() {
    AttrKind = ParsedAttr::AT_ConsumableAutoCast;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = ConsumableAutoCastSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<CXXRecordDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "classes";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_record, /*IsSupported=*/true));
}

AttrHandling handleDeclAttribute(Sema &S, Decl *D,const ParsedAttr &Attr) const override {
  D->addAttr(::new (S.Context) ConsumableAutoCastAttr(S.Context, Attr));
  return AttributeApplied;
}

static const ParsedAttrInfoConsumableAutoCast Instance;
};
const ParsedAttrInfoConsumableAutoCast ParsedAttrInfoConsumableAutoCast::Instance;
static constexpr ParsedAttrInfo::Spelling ConsumableSetOnReadSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "consumable_set_state_on_read"},
  {AttributeCommonInfo::AS_CXX11, "clang::consumable_set_state_on_read"},
};
struct ParsedAttrInfoConsumableSetOnRead final : public ParsedAttrInfo {
  ParsedAttrInfoConsumableSetOnRead() {
    AttrKind = ParsedAttr::AT_ConsumableSetOnRead;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = ConsumableSetOnReadSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<CXXRecordDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "classes";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_record, /*IsSupported=*/true));
}

AttrHandling handleDeclAttribute(Sema &S, Decl *D,const ParsedAttr &Attr) const override {
  D->addAttr(::new (S.Context) ConsumableSetOnReadAttr(S.Context, Attr));
  return AttributeApplied;
}

static const ParsedAttrInfoConsumableSetOnRead Instance;
};
const ParsedAttrInfoConsumableSetOnRead ParsedAttrInfoConsumableSetOnRead::Instance;
static constexpr ParsedAttrInfo::Spelling ConvergentSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "convergent"},
  {AttributeCommonInfo::AS_CXX11, "clang::convergent"},
  {AttributeCommonInfo::AS_C2x, "clang::convergent"},
};
struct ParsedAttrInfoConvergent final : public ParsedAttrInfo {
  ParsedAttrInfoConvergent() {
    AttrKind = ParsedAttr::AT_Convergent;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = ConvergentSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FunctionDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "functions";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_function, /*IsSupported=*/true));
}

AttrHandling handleDeclAttribute(Sema &S, Decl *D,const ParsedAttr &Attr) const override {
  D->addAttr(::new (S.Context) ConvergentAttr(S.Context, Attr));
  return AttributeApplied;
}

static const ParsedAttrInfoConvergent Instance;
};
const ParsedAttrInfoConvergent ParsedAttrInfoConvergent::Instance;
static constexpr ParsedAttrInfo::Spelling DLLExportSpellings[] = {
  {AttributeCommonInfo::AS_Declspec, "dllexport"},
  {AttributeCommonInfo::AS_GNU, "dllexport"},
  {AttributeCommonInfo::AS_CXX11, "gnu::dllexport"},
  {AttributeCommonInfo::AS_C2x, "gnu::dllexport"},
};
struct ParsedAttrInfoDLLExport final : public ParsedAttrInfo {
  ParsedAttrInfoDLLExport() {
    AttrKind = ParsedAttr::AT_DLLExport;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 1;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 1;
    IsSupportedByPragmaAttribute = 1;
    Spellings = DLLExportSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FunctionDecl>(D) && !isa<VarDecl>(D) && !isa<CXXRecordDecl>(D) && !isa<ObjCInterfaceDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "functions, variables, classes, and Objective-C interfaces";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

bool existsInTarget(const TargetInfo &Target) const override {
  const llvm::Triple &T = Target.getTriple(); (void)T;
  return true && ( Target.getTriple().hasDLLImportExport() );
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_function, /*IsSupported=*/true));
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_variable, /*IsSupported=*/true));
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_record, /*IsSupported=*/true));
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_objc_interface, /*IsSupported=*/LangOpts.ObjC));
}

static const ParsedAttrInfoDLLExport Instance;
};
const ParsedAttrInfoDLLExport ParsedAttrInfoDLLExport::Instance;
struct ParsedAttrInfoDLLExportStaticLocal final : public ParsedAttrInfo {
  ParsedAttrInfoDLLExportStaticLocal() {
    AttrKind = ParsedAttr::AT_DLLExportStaticLocal;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 1;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 0;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FunctionDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "functions";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

bool existsInTarget(const TargetInfo &Target) const override {
  const llvm::Triple &T = Target.getTriple(); (void)T;
  return true && ( Target.getTriple().hasDLLImportExport() );
}

static const ParsedAttrInfoDLLExportStaticLocal Instance;
};
const ParsedAttrInfoDLLExportStaticLocal ParsedAttrInfoDLLExportStaticLocal::Instance;
static constexpr ParsedAttrInfo::Spelling DLLImportSpellings[] = {
  {AttributeCommonInfo::AS_Declspec, "dllimport"},
  {AttributeCommonInfo::AS_GNU, "dllimport"},
  {AttributeCommonInfo::AS_CXX11, "gnu::dllimport"},
  {AttributeCommonInfo::AS_C2x, "gnu::dllimport"},
};
struct ParsedAttrInfoDLLImport final : public ParsedAttrInfo {
  ParsedAttrInfoDLLImport() {
    AttrKind = ParsedAttr::AT_DLLImport;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 1;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 1;
    IsSupportedByPragmaAttribute = 1;
    Spellings = DLLImportSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FunctionDecl>(D) && !isa<VarDecl>(D) && !isa<CXXRecordDecl>(D) && !isa<ObjCInterfaceDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "functions, variables, classes, and Objective-C interfaces";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

bool existsInTarget(const TargetInfo &Target) const override {
  const llvm::Triple &T = Target.getTriple(); (void)T;
  return true && ( Target.getTriple().hasDLLImportExport() );
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_function, /*IsSupported=*/true));
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_variable, /*IsSupported=*/true));
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_record, /*IsSupported=*/true));
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_objc_interface, /*IsSupported=*/LangOpts.ObjC));
}

static const ParsedAttrInfoDLLImport Instance;
};
const ParsedAttrInfoDLLImport ParsedAttrInfoDLLImport::Instance;
struct ParsedAttrInfoDLLImportStaticLocal final : public ParsedAttrInfo {
  ParsedAttrInfoDLLImportStaticLocal() {
    AttrKind = ParsedAttr::AT_DLLImportStaticLocal;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 1;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 0;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FunctionDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "functions";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

bool existsInTarget(const TargetInfo &Target) const override {
  const llvm::Triple &T = Target.getTriple(); (void)T;
  return true && ( Target.getTriple().hasDLLImportExport() );
}

static const ParsedAttrInfoDLLImportStaticLocal Instance;
};
const ParsedAttrInfoDLLImportStaticLocal ParsedAttrInfoDLLImportStaticLocal::Instance;
static constexpr ParsedAttrInfo::Spelling DeprecatedSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "deprecated"},
  {AttributeCommonInfo::AS_CXX11, "gnu::deprecated"},
  {AttributeCommonInfo::AS_C2x, "gnu::deprecated"},
  {AttributeCommonInfo::AS_Declspec, "deprecated"},
  {AttributeCommonInfo::AS_CXX11, "deprecated"},
  {AttributeCommonInfo::AS_C2x, "deprecated"},
};
static constexpr const char *DeprecatedArgNames[] = {
"Message","Replacement",};
struct ParsedAttrInfoDeprecated final : public ParsedAttrInfo {
  ParsedAttrInfoDeprecated() {
    AttrKind = ParsedAttr::AT_Deprecated;
    NumArgs = 0;
    OptArgs = 2;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 1;
    IsSupportedByPragmaAttribute = 0;
    Spellings = DeprecatedSpellings;
    ArgNames = DeprecatedArgNames;
  }
static const ParsedAttrInfoDeprecated Instance;
};
const ParsedAttrInfoDeprecated ParsedAttrInfoDeprecated::Instance;
static constexpr ParsedAttrInfo::Spelling DestructorSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "destructor"},
  {AttributeCommonInfo::AS_CXX11, "gnu::destructor"},
  {AttributeCommonInfo::AS_C2x, "gnu::destructor"},
};
static constexpr const char *DestructorArgNames[] = {
"Priority",};
struct ParsedAttrInfoDestructor final : public ParsedAttrInfo {
  ParsedAttrInfoDestructor() {
    AttrKind = ParsedAttr::AT_Destructor;
    NumArgs = 0;
    OptArgs = 1;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 1;
    IsSupportedByPragmaAttribute = 1;
    Spellings = DestructorSpellings;
    ArgNames = DestructorArgNames;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FunctionDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "functions";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_function, /*IsSupported=*/true));
}

static const ParsedAttrInfoDestructor Instance;
};
const ParsedAttrInfoDestructor ParsedAttrInfoDestructor::Instance;
static constexpr ParsedAttrInfo::Spelling DiagnoseAsBuiltinSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "diagnose_as_builtin"},
  {AttributeCommonInfo::AS_CXX11, "clang::diagnose_as_builtin"},
  {AttributeCommonInfo::AS_C2x, "clang::diagnose_as_builtin"},
};
static constexpr const char *DiagnoseAsBuiltinArgNames[] = {
"Function","ArgIndices...",};
struct ParsedAttrInfoDiagnoseAsBuiltin final : public ParsedAttrInfo {
  ParsedAttrInfoDiagnoseAsBuiltin() {
    AttrKind = ParsedAttr::AT_DiagnoseAsBuiltin;
    NumArgs = 1;
    OptArgs = 15;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = DiagnoseAsBuiltinSpellings;
    ArgNames = DiagnoseAsBuiltinArgNames;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FunctionDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "functions";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_function, /*IsSupported=*/true));
}

static const ParsedAttrInfoDiagnoseAsBuiltin Instance;
};
const ParsedAttrInfoDiagnoseAsBuiltin ParsedAttrInfoDiagnoseAsBuiltin::Instance;
static constexpr ParsedAttrInfo::Spelling DiagnoseIfSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "diagnose_if"},
};
static constexpr const char *DiagnoseIfArgNames[] = {
"Cond","Message","DiagnosticType",};
struct ParsedAttrInfoDiagnoseIf final : public ParsedAttrInfo {
  ParsedAttrInfoDiagnoseIf() {
    AttrKind = ParsedAttr::AT_DiagnoseIf;
    NumArgs = 3;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 0;
    Spellings = DiagnoseIfSpellings;
    ArgNames = DiagnoseIfArgNames;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FunctionDecl>(D) && !isa<ObjCMethodDecl>(D) && !isa<ObjCPropertyDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "functions, Objective-C methods, and Objective-C properties";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

static const ParsedAttrInfoDiagnoseIf Instance;
};
const ParsedAttrInfoDiagnoseIf ParsedAttrInfoDiagnoseIf::Instance;
static constexpr ParsedAttrInfo::Spelling DisableSanitizerInstrumentationSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "disable_sanitizer_instrumentation"},
  {AttributeCommonInfo::AS_CXX11, "clang::disable_sanitizer_instrumentation"},
  {AttributeCommonInfo::AS_C2x, "clang::disable_sanitizer_instrumentation"},
};
struct ParsedAttrInfoDisableSanitizerInstrumentation final : public ParsedAttrInfo {
  ParsedAttrInfoDisableSanitizerInstrumentation() {
    AttrKind = ParsedAttr::AT_DisableSanitizerInstrumentation;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = DisableSanitizerInstrumentationSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FunctionDecl>(D) && !isa<ObjCMethodDecl>(D) && !isGlobalVar(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "functions, Objective-C methods, and global variables";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_function, /*IsSupported=*/true));
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_objc_method, /*IsSupported=*/LangOpts.ObjC));
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_variable_is_global, /*IsSupported=*/true));
}

AttrHandling handleDeclAttribute(Sema &S, Decl *D,const ParsedAttr &Attr) const override {
  D->addAttr(::new (S.Context) DisableSanitizerInstrumentationAttr(S.Context, Attr));
  return AttributeApplied;
}

static const ParsedAttrInfoDisableSanitizerInstrumentation Instance;
};
const ParsedAttrInfoDisableSanitizerInstrumentation ParsedAttrInfoDisableSanitizerInstrumentation::Instance;
static constexpr ParsedAttrInfo::Spelling DisableTailCallsSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "disable_tail_calls"},
  {AttributeCommonInfo::AS_CXX11, "clang::disable_tail_calls"},
  {AttributeCommonInfo::AS_C2x, "clang::disable_tail_calls"},
};
struct ParsedAttrInfoDisableTailCalls final : public ParsedAttrInfo {
  ParsedAttrInfoDisableTailCalls() {
    AttrKind = ParsedAttr::AT_DisableTailCalls;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = DisableTailCallsSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FunctionDecl>(D) && !isa<ObjCMethodDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "functions and Objective-C methods";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

  using ParsedAttrInfo::diagMutualExclusion;

  bool diagMutualExclusion(Sema &S, const ParsedAttr &AL, const Decl *D) const override {
    if (const auto *A = D->getAttr<NakedAttr>()) {
      S.Diag(AL.getLoc(), diag::err_attributes_are_not_compatible) << AL << A;
      S.Diag(A->getLocation(), diag::note_conflicting_attribute);      
return false;
    }
    return true;
  }

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_function, /*IsSupported=*/true));
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_objc_method, /*IsSupported=*/LangOpts.ObjC));
}

AttrHandling handleDeclAttribute(Sema &S, Decl *D,const ParsedAttr &Attr) const override {
  D->addAttr(::new (S.Context) DisableTailCallsAttr(S.Context, Attr));
  return AttributeApplied;
}

static const ParsedAttrInfoDisableTailCalls Instance;
};
const ParsedAttrInfoDisableTailCalls ParsedAttrInfoDisableTailCalls::Instance;
static constexpr ParsedAttrInfo::Spelling EmptyBasesSpellings[] = {
  {AttributeCommonInfo::AS_Declspec, "empty_bases"},
};
struct ParsedAttrInfoEmptyBases final : public ParsedAttrInfo {
  ParsedAttrInfoEmptyBases() {
    AttrKind = ParsedAttr::AT_EmptyBases;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 1;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 0;
    Spellings = EmptyBasesSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<CXXRecordDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "classes";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

bool existsInTarget(const TargetInfo &Target) const override {
  const llvm::Triple &T = Target.getTriple(); (void)T;
  return true && (T.getArch() == llvm::Triple::x86 || T.getArch() == llvm::Triple::x86_64 || T.getArch() == llvm::Triple::arm || T.getArch() == llvm::Triple::thumb || T.getArch() == llvm::Triple::aarch64) && ( Target.getCXXABI().isMicrosoft() );
}

AttrHandling handleDeclAttribute(Sema &S, Decl *D,const ParsedAttr &Attr) const override {
  D->addAttr(::new (S.Context) EmptyBasesAttr(S.Context, Attr));
  return AttributeApplied;
}

static const ParsedAttrInfoEmptyBases Instance;
};
const ParsedAttrInfoEmptyBases ParsedAttrInfoEmptyBases::Instance;
static constexpr ParsedAttrInfo::Spelling EnableIfSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "enable_if"},
};
static constexpr const char *EnableIfArgNames[] = {
"Cond","Message",};
struct ParsedAttrInfoEnableIf final : public ParsedAttrInfo {
  ParsedAttrInfoEnableIf() {
    AttrKind = ParsedAttr::AT_EnableIf;
    NumArgs = 2;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = EnableIfSpellings;
    ArgNames = EnableIfArgNames;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FunctionDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "functions";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_function, /*IsSupported=*/true));
}

static const ParsedAttrInfoEnableIf Instance;
};
const ParsedAttrInfoEnableIf ParsedAttrInfoEnableIf::Instance;
static constexpr ParsedAttrInfo::Spelling EnforceTCBSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "enforce_tcb"},
  {AttributeCommonInfo::AS_CXX11, "clang::enforce_tcb"},
  {AttributeCommonInfo::AS_C2x, "clang::enforce_tcb"},
};
static constexpr const char *EnforceTCBArgNames[] = {
"TCBName",};
struct ParsedAttrInfoEnforceTCB final : public ParsedAttrInfo {
  ParsedAttrInfoEnforceTCB() {
    AttrKind = ParsedAttr::AT_EnforceTCB;
    NumArgs = 1;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = EnforceTCBSpellings;
    ArgNames = EnforceTCBArgNames;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FunctionDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "functions";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_function, /*IsSupported=*/true));
}

static const ParsedAttrInfoEnforceTCB Instance;
};
const ParsedAttrInfoEnforceTCB ParsedAttrInfoEnforceTCB::Instance;
static constexpr ParsedAttrInfo::Spelling EnforceTCBLeafSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "enforce_tcb_leaf"},
  {AttributeCommonInfo::AS_CXX11, "clang::enforce_tcb_leaf"},
  {AttributeCommonInfo::AS_C2x, "clang::enforce_tcb_leaf"},
};
static constexpr const char *EnforceTCBLeafArgNames[] = {
"TCBName",};
struct ParsedAttrInfoEnforceTCBLeaf final : public ParsedAttrInfo {
  ParsedAttrInfoEnforceTCBLeaf() {
    AttrKind = ParsedAttr::AT_EnforceTCBLeaf;
    NumArgs = 1;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = EnforceTCBLeafSpellings;
    ArgNames = EnforceTCBLeafArgNames;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FunctionDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "functions";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_function, /*IsSupported=*/true));
}

static const ParsedAttrInfoEnforceTCBLeaf Instance;
};
const ParsedAttrInfoEnforceTCBLeaf ParsedAttrInfoEnforceTCBLeaf::Instance;
static constexpr ParsedAttrInfo::Spelling EnumExtensibilitySpellings[] = {
  {AttributeCommonInfo::AS_GNU, "enum_extensibility"},
  {AttributeCommonInfo::AS_CXX11, "clang::enum_extensibility"},
  {AttributeCommonInfo::AS_C2x, "clang::enum_extensibility"},
};
static constexpr const char *EnumExtensibilityArgNames[] = {
"Extensibility",};
struct ParsedAttrInfoEnumExtensibility final : public ParsedAttrInfo {
  ParsedAttrInfoEnumExtensibility() {
    AttrKind = ParsedAttr::AT_EnumExtensibility;
    NumArgs = 1;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = EnumExtensibilitySpellings;
    ArgNames = EnumExtensibilityArgNames;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<EnumDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "enums";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_enum, /*IsSupported=*/true));
}

static const ParsedAttrInfoEnumExtensibility Instance;
};
const ParsedAttrInfoEnumExtensibility ParsedAttrInfoEnumExtensibility::Instance;
static constexpr ParsedAttrInfo::Spelling ErrorSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "error"},
  {AttributeCommonInfo::AS_CXX11, "gnu::error"},
  {AttributeCommonInfo::AS_C2x, "gnu::error"},
  {AttributeCommonInfo::AS_GNU, "warning"},
  {AttributeCommonInfo::AS_CXX11, "gnu::warning"},
  {AttributeCommonInfo::AS_C2x, "gnu::warning"},
};
static constexpr const char *ErrorArgNames[] = {
"UserDiagnostic",};
struct ParsedAttrInfoError final : public ParsedAttrInfo {
  ParsedAttrInfoError() {
    AttrKind = ParsedAttr::AT_Error;
    NumArgs = 1;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 1;
    IsSupportedByPragmaAttribute = 1;
    Spellings = ErrorSpellings;
    ArgNames = ErrorArgNames;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FunctionDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::err_attribute_wrong_decl_type_str)
      << Attr << "functions";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

unsigned spellingIndexToSemanticSpelling(const ParsedAttr &Attr) const override {
  enum Spelling {
    GNU_error = 0,
    CXX11_gnu_error = 1,
    C2x_gnu_error = 2,
    GNU_warning = 3,
    CXX11_gnu_warning = 4,
    C2x_gnu_warning = 5,
  SpellingNotCalculated = 15

  };

  unsigned Idx = Attr.getAttributeSpellingListIndex();
  switch (Idx) {
    default: llvm_unreachable("Unknown spelling list index");
    case 0: return GNU_error;
    case 1: return CXX11_gnu_error;
    case 2: return C2x_gnu_error;
    case 3: return GNU_warning;
    case 4: return CXX11_gnu_warning;
    case 5: return C2x_gnu_warning;
  }
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_function, /*IsSupported=*/true));
}

static const ParsedAttrInfoError Instance;
};
const ParsedAttrInfoError ParsedAttrInfoError::Instance;
static constexpr ParsedAttrInfo::Spelling ExcludeFromExplicitInstantiationSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "exclude_from_explicit_instantiation"},
  {AttributeCommonInfo::AS_CXX11, "clang::exclude_from_explicit_instantiation"},
  {AttributeCommonInfo::AS_C2x, "clang::exclude_from_explicit_instantiation"},
};
struct ParsedAttrInfoExcludeFromExplicitInstantiation final : public ParsedAttrInfo {
  ParsedAttrInfoExcludeFromExplicitInstantiation() {
    AttrKind = ParsedAttr::AT_ExcludeFromExplicitInstantiation;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = ExcludeFromExplicitInstantiationSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<VarDecl>(D) && !isa<FunctionDecl>(D) && !isa<CXXRecordDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "variables, functions, and classes";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_variable, /*IsSupported=*/true));
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_function, /*IsSupported=*/true));
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_record, /*IsSupported=*/true));
}

AttrHandling handleDeclAttribute(Sema &S, Decl *D,const ParsedAttr &Attr) const override {
  D->addAttr(::new (S.Context) ExcludeFromExplicitInstantiationAttr(S.Context, Attr));
  return AttributeApplied;
}

static const ParsedAttrInfoExcludeFromExplicitInstantiation Instance;
};
const ParsedAttrInfoExcludeFromExplicitInstantiation ParsedAttrInfoExcludeFromExplicitInstantiation::Instance;
static constexpr ParsedAttrInfo::Spelling ExclusiveTrylockFunctionSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "exclusive_trylock_function"},
};
static constexpr const char *ExclusiveTrylockFunctionArgNames[] = {
"SuccessValue","Args...",};
struct ParsedAttrInfoExclusiveTrylockFunction final : public ParsedAttrInfo {
  ParsedAttrInfoExclusiveTrylockFunction() {
    AttrKind = ParsedAttr::AT_ExclusiveTrylockFunction;
    NumArgs = 1;
    OptArgs = 15;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 0;
    Spellings = ExclusiveTrylockFunctionSpellings;
    ArgNames = ExclusiveTrylockFunctionArgNames;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FunctionDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "functions";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

static const ParsedAttrInfoExclusiveTrylockFunction Instance;
};
const ParsedAttrInfoExclusiveTrylockFunction ParsedAttrInfoExclusiveTrylockFunction::Instance;
static constexpr ParsedAttrInfo::Spelling ExtVectorTypeSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "ext_vector_type"},
};
static constexpr const char *ExtVectorTypeArgNames[] = {
"NumElements",};
struct ParsedAttrInfoExtVectorType final : public ParsedAttrInfo {
  ParsedAttrInfoExtVectorType() {
    AttrKind = ParsedAttr::AT_ExtVectorType;
    NumArgs = 1;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 0;
    Spellings = ExtVectorTypeSpellings;
    ArgNames = ExtVectorTypeArgNames;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<TypedefNameDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::err_attribute_wrong_decl_type_str)
      << Attr << "typedefs";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

static const ParsedAttrInfoExtVectorType Instance;
};
const ParsedAttrInfoExtVectorType ParsedAttrInfoExtVectorType::Instance;
static constexpr ParsedAttrInfo::Spelling ExternalSourceSymbolSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "external_source_symbol"},
  {AttributeCommonInfo::AS_CXX11, "clang::external_source_symbol"},
  {AttributeCommonInfo::AS_C2x, "clang::external_source_symbol"},
};
static constexpr const char *ExternalSourceSymbolArgNames[] = {
"language","definedIn","generatedDeclaration",};
struct ParsedAttrInfoExternalSourceSymbol final : public ParsedAttrInfo {
  ParsedAttrInfoExternalSourceSymbol() {
    AttrKind = ParsedAttr::AT_ExternalSourceSymbol;
    NumArgs = 0;
    OptArgs = 3;
    HasCustomParsing = 1;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = ExternalSourceSymbolSpellings;
    ArgNames = ExternalSourceSymbolArgNames;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<NamedDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "named declarations";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_record, /*IsSupported=*/true));
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_enum, /*IsSupported=*/true));
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_enum_constant, /*IsSupported=*/true));
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_field, /*IsSupported=*/true));
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_function, /*IsSupported=*/true));
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_namespace, /*IsSupported=*/LangOpts.CPlusPlus));
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_objc_category, /*IsSupported=*/LangOpts.ObjC));
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_objc_implementation, /*IsSupported=*/LangOpts.ObjC));
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_objc_interface, /*IsSupported=*/LangOpts.ObjC));
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_objc_method, /*IsSupported=*/LangOpts.ObjC));
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_objc_property, /*IsSupported=*/LangOpts.ObjC));
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_objc_protocol, /*IsSupported=*/LangOpts.ObjC));
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_record, /*IsSupported=*/true));
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_type_alias, /*IsSupported=*/true));
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_variable, /*IsSupported=*/true));
}

static const ParsedAttrInfoExternalSourceSymbol Instance;
};
const ParsedAttrInfoExternalSourceSymbol ParsedAttrInfoExternalSourceSymbol::Instance;
static constexpr ParsedAttrInfo::Spelling FallThroughSpellings[] = {
  {AttributeCommonInfo::AS_CXX11, "fallthrough"},
  {AttributeCommonInfo::AS_C2x, "fallthrough"},
  {AttributeCommonInfo::AS_CXX11, "clang::fallthrough"},
  {AttributeCommonInfo::AS_GNU, "fallthrough"},
  {AttributeCommonInfo::AS_CXX11, "gnu::fallthrough"},
  {AttributeCommonInfo::AS_C2x, "gnu::fallthrough"},
};
struct ParsedAttrInfoFallThrough final : public ParsedAttrInfo {
  ParsedAttrInfoFallThrough() {
    AttrKind = ParsedAttr::AT_FallThrough;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 1;
    IsKnownToGCC = 1;
    IsSupportedByPragmaAttribute = 0;
    Spellings = FallThroughSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &AL, const Decl *D) const override {
  S.Diag(AL.getLoc(), diag::err_stmt_attribute_invalid_on_decl)
    << AL << D->getLocation();
  return false;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &Attr, const Stmt *St) const override {
  if (!isa<NullStmt>(St) && !isa<SwitchCase>(St)) {
    S.Diag(Attr.getLoc(), diag::err_attribute_wrong_decl_type_str)
      << Attr << "empty statements";
    return false;
  }
  return true;
}

static const ParsedAttrInfoFallThrough Instance;
};
const ParsedAttrInfoFallThrough ParsedAttrInfoFallThrough::Instance;
static constexpr ParsedAttrInfo::Spelling FastCallSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "fastcall"},
  {AttributeCommonInfo::AS_CXX11, "gnu::fastcall"},
  {AttributeCommonInfo::AS_C2x, "gnu::fastcall"},
  {AttributeCommonInfo::AS_Keyword, "__fastcall"},
  {AttributeCommonInfo::AS_Keyword, "_fastcall"},
};
struct ParsedAttrInfoFastCall final : public ParsedAttrInfo {
  ParsedAttrInfoFastCall() {
    AttrKind = ParsedAttr::AT_FastCall;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 1;
    IsStmt = 0;
    IsKnownToGCC = 1;
    IsSupportedByPragmaAttribute = 0;
    Spellings = FastCallSpellings;
  }
static const ParsedAttrInfoFastCall Instance;
};
const ParsedAttrInfoFastCall ParsedAttrInfoFastCall::Instance;
static constexpr ParsedAttrInfo::Spelling FlagEnumSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "flag_enum"},
  {AttributeCommonInfo::AS_CXX11, "clang::flag_enum"},
  {AttributeCommonInfo::AS_C2x, "clang::flag_enum"},
};
struct ParsedAttrInfoFlagEnum final : public ParsedAttrInfo {
  ParsedAttrInfoFlagEnum() {
    AttrKind = ParsedAttr::AT_FlagEnum;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = FlagEnumSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<EnumDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "enums";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_enum, /*IsSupported=*/true));
}

AttrHandling handleDeclAttribute(Sema &S, Decl *D,const ParsedAttr &Attr) const override {
  D->addAttr(::new (S.Context) FlagEnumAttr(S.Context, Attr));
  return AttributeApplied;
}

static const ParsedAttrInfoFlagEnum Instance;
};
const ParsedAttrInfoFlagEnum ParsedAttrInfoFlagEnum::Instance;
static constexpr ParsedAttrInfo::Spelling FlattenSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "flatten"},
  {AttributeCommonInfo::AS_CXX11, "gnu::flatten"},
  {AttributeCommonInfo::AS_C2x, "gnu::flatten"},
};
struct ParsedAttrInfoFlatten final : public ParsedAttrInfo {
  ParsedAttrInfoFlatten() {
    AttrKind = ParsedAttr::AT_Flatten;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 1;
    IsSupportedByPragmaAttribute = 1;
    Spellings = FlattenSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FunctionDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::err_attribute_wrong_decl_type_str)
      << Attr << "functions";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_function, /*IsSupported=*/true));
}

AttrHandling handleDeclAttribute(Sema &S, Decl *D,const ParsedAttr &Attr) const override {
  D->addAttr(::new (S.Context) FlattenAttr(S.Context, Attr));
  return AttributeApplied;
}

static const ParsedAttrInfoFlatten Instance;
};
const ParsedAttrInfoFlatten ParsedAttrInfoFlatten::Instance;
static constexpr ParsedAttrInfo::Spelling FormatSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "format"},
  {AttributeCommonInfo::AS_CXX11, "gnu::format"},
  {AttributeCommonInfo::AS_C2x, "gnu::format"},
};
static constexpr const char *FormatArgNames[] = {
"Type","FormatIdx","FirstArg",};
struct ParsedAttrInfoFormat final : public ParsedAttrInfo {
  ParsedAttrInfoFormat() {
    AttrKind = ParsedAttr::AT_Format;
    NumArgs = 3;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 1;
    IsSupportedByPragmaAttribute = 0;
    Spellings = FormatSpellings;
    ArgNames = FormatArgNames;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<ObjCMethodDecl>(D) && !isa<BlockDecl>(D) && !isHasFunctionProto(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "Objective-C methods, blocks, and non-K&R-style functions";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

static const ParsedAttrInfoFormat Instance;
};
const ParsedAttrInfoFormat ParsedAttrInfoFormat::Instance;
static constexpr ParsedAttrInfo::Spelling FormatArgSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "format_arg"},
  {AttributeCommonInfo::AS_CXX11, "gnu::format_arg"},
  {AttributeCommonInfo::AS_C2x, "gnu::format_arg"},
};
static constexpr const char *FormatArgArgNames[] = {
"FormatIdx",};
struct ParsedAttrInfoFormatArg final : public ParsedAttrInfo {
  ParsedAttrInfoFormatArg() {
    AttrKind = ParsedAttr::AT_FormatArg;
    NumArgs = 1;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 1;
    IsSupportedByPragmaAttribute = 0;
    Spellings = FormatArgSpellings;
    ArgNames = FormatArgArgNames;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<ObjCMethodDecl>(D) && !isHasFunctionProto(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "Objective-C methods and non-K&R-style functions";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

static const ParsedAttrInfoFormatArg Instance;
};
const ParsedAttrInfoFormatArg ParsedAttrInfoFormatArg::Instance;
static constexpr ParsedAttrInfo::Spelling GNUInlineSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "gnu_inline"},
  {AttributeCommonInfo::AS_CXX11, "gnu::gnu_inline"},
  {AttributeCommonInfo::AS_C2x, "gnu::gnu_inline"},
};
struct ParsedAttrInfoGNUInline final : public ParsedAttrInfo {
  ParsedAttrInfoGNUInline() {
    AttrKind = ParsedAttr::AT_GNUInline;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 1;
    IsSupportedByPragmaAttribute = 1;
    Spellings = GNUInlineSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FunctionDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "functions";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_function, /*IsSupported=*/true));
}

static const ParsedAttrInfoGNUInline Instance;
};
const ParsedAttrInfoGNUInline ParsedAttrInfoGNUInline::Instance;
static constexpr ParsedAttrInfo::Spelling GuardedBySpellings[] = {
  {AttributeCommonInfo::AS_GNU, "guarded_by"},
};
static constexpr const char *GuardedByArgNames[] = {
"Arg",};
struct ParsedAttrInfoGuardedBy final : public ParsedAttrInfo {
  ParsedAttrInfoGuardedBy() {
    AttrKind = ParsedAttr::AT_GuardedBy;
    NumArgs = 1;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 0;
    Spellings = GuardedBySpellings;
    ArgNames = GuardedByArgNames;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FieldDecl>(D) && !isSharedVar(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "non-static data members and global variables";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

static const ParsedAttrInfoGuardedBy Instance;
};
const ParsedAttrInfoGuardedBy ParsedAttrInfoGuardedBy::Instance;
static constexpr ParsedAttrInfo::Spelling GuardedVarSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "guarded_var"},
  {AttributeCommonInfo::AS_CXX11, "clang::guarded_var"},
};
struct ParsedAttrInfoGuardedVar final : public ParsedAttrInfo {
  ParsedAttrInfoGuardedVar() {
    AttrKind = ParsedAttr::AT_GuardedVar;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 0;
    Spellings = GuardedVarSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FieldDecl>(D) && !isSharedVar(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "non-static data members and global variables";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

AttrHandling handleDeclAttribute(Sema &S, Decl *D,const ParsedAttr &Attr) const override {
  D->addAttr(::new (S.Context) GuardedVarAttr(S.Context, Attr));
  return AttributeApplied;
}

static const ParsedAttrInfoGuardedVar Instance;
};
const ParsedAttrInfoGuardedVar ParsedAttrInfoGuardedVar::Instance;
static constexpr ParsedAttrInfo::Spelling HIPManagedSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "managed"},
  {AttributeCommonInfo::AS_Declspec, "__managed__"},
};
struct ParsedAttrInfoHIPManaged final : public ParsedAttrInfo {
  ParsedAttrInfoHIPManaged() {
    AttrKind = ParsedAttr::AT_HIPManaged;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = HIPManagedSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<VarDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "variables";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

  using ParsedAttrInfo::diagMutualExclusion;

  bool diagMutualExclusion(Sema &S, const ParsedAttr &AL, const Decl *D) const override {
    if (const auto *A = D->getAttr<CUDAConstantAttr>()) {
      S.Diag(AL.getLoc(), diag::err_attributes_are_not_compatible) << AL << A;
      S.Diag(A->getLocation(), diag::note_conflicting_attribute);      
return false;
    }
    if (const auto *A = D->getAttr<CUDASharedAttr>()) {
      S.Diag(AL.getLoc(), diag::err_attributes_are_not_compatible) << AL << A;
      S.Diag(A->getLocation(), diag::note_conflicting_attribute);      
return false;
    }
    return true;
  }

bool acceptsLangOpts(const LangOptions &LangOpts) const override {
  return LangOpts.HIP;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_variable, /*IsSupported=*/true));
}

static const ParsedAttrInfoHIPManaged Instance;
};
const ParsedAttrInfoHIPManaged ParsedAttrInfoHIPManaged::Instance;
static constexpr ParsedAttrInfo::Spelling HotSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "hot"},
  {AttributeCommonInfo::AS_CXX11, "gnu::hot"},
  {AttributeCommonInfo::AS_C2x, "gnu::hot"},
};
struct ParsedAttrInfoHot final : public ParsedAttrInfo {
  ParsedAttrInfoHot() {
    AttrKind = ParsedAttr::AT_Hot;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 1;
    IsSupportedByPragmaAttribute = 1;
    Spellings = HotSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FunctionDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "functions";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

  using ParsedAttrInfo::diagMutualExclusion;

  bool diagMutualExclusion(Sema &S, const ParsedAttr &AL, const Decl *D) const override {
    if (const auto *A = D->getAttr<ColdAttr>()) {
      S.Diag(AL.getLoc(), diag::err_attributes_are_not_compatible) << AL << A;
      S.Diag(A->getLocation(), diag::note_conflicting_attribute);      
return false;
    }
    return true;
  }

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_function, /*IsSupported=*/true));
}

AttrHandling handleDeclAttribute(Sema &S, Decl *D,const ParsedAttr &Attr) const override {
  D->addAttr(::new (S.Context) HotAttr(S.Context, Attr));
  return AttributeApplied;
}

static const ParsedAttrInfoHot Instance;
};
const ParsedAttrInfoHot ParsedAttrInfoHot::Instance;
static constexpr ParsedAttrInfo::Spelling IBActionSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "ibaction"},
  {AttributeCommonInfo::AS_CXX11, "clang::ibaction"},
  {AttributeCommonInfo::AS_C2x, "clang::ibaction"},
};
struct ParsedAttrInfoIBAction final : public ParsedAttrInfo {
  ParsedAttrInfoIBAction() {
    AttrKind = ParsedAttr::AT_IBAction;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = IBActionSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isObjCInstanceMethod(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "Objective-C instance methods";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_objc_method_is_instance, /*IsSupported=*/LangOpts.ObjC));
}

AttrHandling handleDeclAttribute(Sema &S, Decl *D,const ParsedAttr &Attr) const override {
  D->addAttr(::new (S.Context) IBActionAttr(S.Context, Attr));
  return AttributeApplied;
}

static const ParsedAttrInfoIBAction Instance;
};
const ParsedAttrInfoIBAction ParsedAttrInfoIBAction::Instance;
static constexpr ParsedAttrInfo::Spelling IBOutletSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "iboutlet"},
  {AttributeCommonInfo::AS_CXX11, "clang::iboutlet"},
  {AttributeCommonInfo::AS_C2x, "clang::iboutlet"},
};
struct ParsedAttrInfoIBOutlet final : public ParsedAttrInfo {
  ParsedAttrInfoIBOutlet() {
    AttrKind = ParsedAttr::AT_IBOutlet;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 0;
    Spellings = IBOutletSpellings;
  }
static const ParsedAttrInfoIBOutlet Instance;
};
const ParsedAttrInfoIBOutlet ParsedAttrInfoIBOutlet::Instance;
static constexpr ParsedAttrInfo::Spelling IBOutletCollectionSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "iboutletcollection"},
  {AttributeCommonInfo::AS_CXX11, "clang::iboutletcollection"},
  {AttributeCommonInfo::AS_C2x, "clang::iboutletcollection"},
};
static constexpr const char *IBOutletCollectionArgNames[] = {
"Interface",};
struct ParsedAttrInfoIBOutletCollection final : public ParsedAttrInfo {
  ParsedAttrInfoIBOutletCollection() {
    AttrKind = ParsedAttr::AT_IBOutletCollection;
    NumArgs = 0;
    OptArgs = 1;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 0;
    Spellings = IBOutletCollectionSpellings;
    ArgNames = IBOutletCollectionArgNames;
  }
static const ParsedAttrInfoIBOutletCollection Instance;
};
const ParsedAttrInfoIBOutletCollection ParsedAttrInfoIBOutletCollection::Instance;
static constexpr ParsedAttrInfo::Spelling IFuncSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "ifunc"},
  {AttributeCommonInfo::AS_CXX11, "gnu::ifunc"},
  {AttributeCommonInfo::AS_C2x, "gnu::ifunc"},
};
static constexpr const char *IFuncArgNames[] = {
"Resolver",};
struct ParsedAttrInfoIFunc final : public ParsedAttrInfo {
  ParsedAttrInfoIFunc() {
    AttrKind = ParsedAttr::AT_IFunc;
    NumArgs = 1;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 1;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 1;
    IsSupportedByPragmaAttribute = 1;
    Spellings = IFuncSpellings;
    ArgNames = IFuncArgNames;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FunctionDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "functions";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

bool existsInTarget(const TargetInfo &Target) const override {
  const llvm::Triple &T = Target.getTriple(); (void)T;
  return true && (T.getObjectFormat() == llvm::Triple::ELF);
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_function, /*IsSupported=*/true));
}

static const ParsedAttrInfoIFunc Instance;
};
const ParsedAttrInfoIFunc ParsedAttrInfoIFunc::Instance;
static constexpr ParsedAttrInfo::Spelling InitPrioritySpellings[] = {
  {AttributeCommonInfo::AS_GNU, "init_priority"},
  {AttributeCommonInfo::AS_CXX11, "gnu::init_priority"},
};
static constexpr const char *InitPriorityArgNames[] = {
"Priority",};
struct ParsedAttrInfoInitPriority final : public ParsedAttrInfo {
  ParsedAttrInfoInitPriority() {
    AttrKind = ParsedAttr::AT_InitPriority;
    NumArgs = 1;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 1;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 1;
    IsSupportedByPragmaAttribute = 1;
    Spellings = InitPrioritySpellings;
    ArgNames = InitPriorityArgNames;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<VarDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::err_attribute_wrong_decl_type_str)
      << Attr << "variables";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

bool existsInTarget(const TargetInfo &Target) const override {
  const llvm::Triple &T = Target.getTriple(); (void)T;
  return true && ( !Target.getTriple().isOSzOS() );
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_variable, /*IsSupported=*/true));
}

static const ParsedAttrInfoInitPriority Instance;
};
const ParsedAttrInfoInitPriority ParsedAttrInfoInitPriority::Instance;
static constexpr ParsedAttrInfo::Spelling IntelOclBiccSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "intel_ocl_bicc"},
  {AttributeCommonInfo::AS_CXX11, "clang::intel_ocl_bicc"},
};
struct ParsedAttrInfoIntelOclBicc final : public ParsedAttrInfo {
  ParsedAttrInfoIntelOclBicc() {
    AttrKind = ParsedAttr::AT_IntelOclBicc;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 1;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 0;
    Spellings = IntelOclBiccSpellings;
  }
static const ParsedAttrInfoIntelOclBicc Instance;
};
const ParsedAttrInfoIntelOclBicc ParsedAttrInfoIntelOclBicc::Instance;
static constexpr ParsedAttrInfo::Spelling InternalLinkageSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "internal_linkage"},
  {AttributeCommonInfo::AS_CXX11, "clang::internal_linkage"},
  {AttributeCommonInfo::AS_C2x, "clang::internal_linkage"},
};
struct ParsedAttrInfoInternalLinkage final : public ParsedAttrInfo {
  ParsedAttrInfoInternalLinkage() {
    AttrKind = ParsedAttr::AT_InternalLinkage;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = InternalLinkageSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<VarDecl>(D) && !isa<FunctionDecl>(D) && !isa<CXXRecordDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "variables, functions, and classes";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

  using ParsedAttrInfo::diagMutualExclusion;

  bool diagMutualExclusion(Sema &S, const ParsedAttr &AL, const Decl *D) const override {
    if (const auto *A = D->getAttr<CommonAttr>()) {
      S.Diag(AL.getLoc(), diag::err_attributes_are_not_compatible) << AL << A;
      S.Diag(A->getLocation(), diag::note_conflicting_attribute);      
return false;
    }
    return true;
  }

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_variable, /*IsSupported=*/true));
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_function, /*IsSupported=*/true));
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_record, /*IsSupported=*/true));
}

static const ParsedAttrInfoInternalLinkage Instance;
};
const ParsedAttrInfoInternalLinkage ParsedAttrInfoInternalLinkage::Instance;
static constexpr ParsedAttrInfo::Spelling LTOVisibilityPublicSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "lto_visibility_public"},
  {AttributeCommonInfo::AS_CXX11, "clang::lto_visibility_public"},
  {AttributeCommonInfo::AS_C2x, "clang::lto_visibility_public"},
};
struct ParsedAttrInfoLTOVisibilityPublic final : public ParsedAttrInfo {
  ParsedAttrInfoLTOVisibilityPublic() {
    AttrKind = ParsedAttr::AT_LTOVisibilityPublic;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = LTOVisibilityPublicSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<RecordDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "structs, unions, and classes";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_record, /*IsSupported=*/true));
}

AttrHandling handleDeclAttribute(Sema &S, Decl *D,const ParsedAttr &Attr) const override {
  D->addAttr(::new (S.Context) LTOVisibilityPublicAttr(S.Context, Attr));
  return AttributeApplied;
}

static const ParsedAttrInfoLTOVisibilityPublic Instance;
};
const ParsedAttrInfoLTOVisibilityPublic ParsedAttrInfoLTOVisibilityPublic::Instance;
static constexpr ParsedAttrInfo::Spelling LayoutVersionSpellings[] = {
  {AttributeCommonInfo::AS_Declspec, "layout_version"},
};
static constexpr const char *LayoutVersionArgNames[] = {
"Version",};
struct ParsedAttrInfoLayoutVersion final : public ParsedAttrInfo {
  ParsedAttrInfoLayoutVersion() {
    AttrKind = ParsedAttr::AT_LayoutVersion;
    NumArgs = 1;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 1;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 0;
    Spellings = LayoutVersionSpellings;
    ArgNames = LayoutVersionArgNames;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<CXXRecordDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "classes";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

bool existsInTarget(const TargetInfo &Target) const override {
  const llvm::Triple &T = Target.getTriple(); (void)T;
  return true && (T.getArch() == llvm::Triple::x86 || T.getArch() == llvm::Triple::x86_64 || T.getArch() == llvm::Triple::arm || T.getArch() == llvm::Triple::thumb || T.getArch() == llvm::Triple::aarch64) && ( Target.getCXXABI().isMicrosoft() );
}

static const ParsedAttrInfoLayoutVersion Instance;
};
const ParsedAttrInfoLayoutVersion ParsedAttrInfoLayoutVersion::Instance;
static constexpr ParsedAttrInfo::Spelling LeafSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "leaf"},
  {AttributeCommonInfo::AS_CXX11, "gnu::leaf"},
  {AttributeCommonInfo::AS_C2x, "gnu::leaf"},
};
struct ParsedAttrInfoLeaf final : public ParsedAttrInfo {
  ParsedAttrInfoLeaf() {
    AttrKind = ParsedAttr::AT_Leaf;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 1;
    IsSupportedByPragmaAttribute = 1;
    Spellings = LeafSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FunctionDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "functions";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_function, /*IsSupported=*/true));
}

AttrHandling handleDeclAttribute(Sema &S, Decl *D,const ParsedAttr &Attr) const override {
  D->addAttr(::new (S.Context) LeafAttr(S.Context, Attr));
  return AttributeApplied;
}

static const ParsedAttrInfoLeaf Instance;
};
const ParsedAttrInfoLeaf ParsedAttrInfoLeaf::Instance;
static constexpr ParsedAttrInfo::Spelling LifetimeBoundSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "lifetimebound"},
  {AttributeCommonInfo::AS_CXX11, "clang::lifetimebound"},
};
struct ParsedAttrInfoLifetimeBound final : public ParsedAttrInfo {
  ParsedAttrInfoLifetimeBound() {
    AttrKind = ParsedAttr::AT_LifetimeBound;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 1;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 0;
    Spellings = LifetimeBoundSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<ParmVarDecl>(D) && !isImplicitObjectParameter(D)) {
    S.Diag(Attr.getLoc(), diag::err_attribute_wrong_decl_type_str)
      << Attr << "parameters and implicit object parameters";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

bool acceptsLangOpts(const LangOptions &LangOpts) const override {
  return LangOpts.CPlusPlus;
}

AttrHandling handleDeclAttribute(Sema &S, Decl *D,const ParsedAttr &Attr) const override {
  D->addAttr(::new (S.Context) LifetimeBoundAttr(S.Context, Attr));
  return AttributeApplied;
}

static const ParsedAttrInfoLifetimeBound Instance;
};
const ParsedAttrInfoLifetimeBound ParsedAttrInfoLifetimeBound::Instance;
static constexpr ParsedAttrInfo::Spelling LikelySpellings[] = {
  {AttributeCommonInfo::AS_CXX11, "likely"},
  {AttributeCommonInfo::AS_C2x, "clang::likely"},
};
struct ParsedAttrInfoLikely final : public ParsedAttrInfo {
  ParsedAttrInfoLikely() {
    AttrKind = ParsedAttr::AT_Likely;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 1;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 0;
    Spellings = LikelySpellings;
  }
  using ParsedAttrInfo::diagMutualExclusion;

static const ParsedAttrInfoLikely Instance;
};
const ParsedAttrInfoLikely ParsedAttrInfoLikely::Instance;
static constexpr ParsedAttrInfo::Spelling LoaderUninitializedSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "loader_uninitialized"},
  {AttributeCommonInfo::AS_CXX11, "clang::loader_uninitialized"},
  {AttributeCommonInfo::AS_C2x, "clang::loader_uninitialized"},
};
struct ParsedAttrInfoLoaderUninitialized final : public ParsedAttrInfo {
  ParsedAttrInfoLoaderUninitialized() {
    AttrKind = ParsedAttr::AT_LoaderUninitialized;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = LoaderUninitializedSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isGlobalVar(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "global variables";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_variable_is_global, /*IsSupported=*/true));
}

AttrHandling handleDeclAttribute(Sema &S, Decl *D,const ParsedAttr &Attr) const override {
  D->addAttr(::new (S.Context) LoaderUninitializedAttr(S.Context, Attr));
  return AttributeApplied;
}

static const ParsedAttrInfoLoaderUninitialized Instance;
};
const ParsedAttrInfoLoaderUninitialized ParsedAttrInfoLoaderUninitialized::Instance;
static constexpr ParsedAttrInfo::Spelling LockReturnedSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "lock_returned"},
};
static constexpr const char *LockReturnedArgNames[] = {
"Arg",};
struct ParsedAttrInfoLockReturned final : public ParsedAttrInfo {
  ParsedAttrInfoLockReturned() {
    AttrKind = ParsedAttr::AT_LockReturned;
    NumArgs = 1;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 0;
    Spellings = LockReturnedSpellings;
    ArgNames = LockReturnedArgNames;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FunctionDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "functions";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

static const ParsedAttrInfoLockReturned Instance;
};
const ParsedAttrInfoLockReturned ParsedAttrInfoLockReturned::Instance;
static constexpr ParsedAttrInfo::Spelling LockableSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "lockable"},
};
struct ParsedAttrInfoLockable final : public ParsedAttrInfo {
  ParsedAttrInfoLockable() {
    AttrKind = ParsedAttr::AT_Lockable;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = LockableSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<RecordDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "structs, unions, and classes";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_record, /*IsSupported=*/true));
}

static const ParsedAttrInfoLockable Instance;
};
const ParsedAttrInfoLockable ParsedAttrInfoLockable::Instance;
static constexpr ParsedAttrInfo::Spelling LocksExcludedSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "locks_excluded"},
};
static constexpr const char *LocksExcludedArgNames[] = {
"Args...",};
struct ParsedAttrInfoLocksExcluded final : public ParsedAttrInfo {
  ParsedAttrInfoLocksExcluded() {
    AttrKind = ParsedAttr::AT_LocksExcluded;
    NumArgs = 0;
    OptArgs = 15;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 0;
    Spellings = LocksExcludedSpellings;
    ArgNames = LocksExcludedArgNames;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FunctionDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "functions";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

static const ParsedAttrInfoLocksExcluded Instance;
};
const ParsedAttrInfoLocksExcluded ParsedAttrInfoLocksExcluded::Instance;
static constexpr ParsedAttrInfo::Spelling LoopHintSpellings[] = {
  {AttributeCommonInfo::AS_Pragma, "clang::loop"},
  {AttributeCommonInfo::AS_Pragma, "unroll"},
  {AttributeCommonInfo::AS_Pragma, "nounroll"},
  {AttributeCommonInfo::AS_Pragma, "unroll_and_jam"},
  {AttributeCommonInfo::AS_Pragma, "nounroll_and_jam"},
};
static constexpr const char *LoopHintArgNames[] = {
"Option","State","Value",};
struct ParsedAttrInfoLoopHint final : public ParsedAttrInfo {
  ParsedAttrInfoLoopHint() {
    AttrKind = ParsedAttr::AT_LoopHint;
    NumArgs = 3;
    OptArgs = 0;
    HasCustomParsing = 1;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 0;
    Spellings = LoopHintSpellings;
    ArgNames = LoopHintArgNames;
  }
unsigned spellingIndexToSemanticSpelling(const ParsedAttr &Attr) const override {
  enum Spelling {
    Pragma_clang_loop = 0,
    Pragma_unroll = 1,
    Pragma_nounroll = 2,
    Pragma_unroll_and_jam = 3,
    Pragma_nounroll_and_jam = 4,
  SpellingNotCalculated = 15

  };

  unsigned Idx = Attr.getAttributeSpellingListIndex();
  switch (Idx) {
    default: llvm_unreachable("Unknown spelling list index");
    case 0: return Pragma_clang_loop;
    case 1: return Pragma_unroll;
    case 2: return Pragma_nounroll;
    case 3: return Pragma_unroll_and_jam;
    case 4: return Pragma_nounroll_and_jam;
  }
}

static const ParsedAttrInfoLoopHint Instance;
};
const ParsedAttrInfoLoopHint ParsedAttrInfoLoopHint::Instance;
static constexpr ParsedAttrInfo::Spelling MIGServerRoutineSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "mig_server_routine"},
  {AttributeCommonInfo::AS_CXX11, "clang::mig_server_routine"},
  {AttributeCommonInfo::AS_C2x, "clang::mig_server_routine"},
};
struct ParsedAttrInfoMIGServerRoutine final : public ParsedAttrInfo {
  ParsedAttrInfoMIGServerRoutine() {
    AttrKind = ParsedAttr::AT_MIGServerRoutine;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = MIGServerRoutineSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FunctionDecl>(D) && !isa<ObjCMethodDecl>(D) && !isa<BlockDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "functions, Objective-C methods, and blocks";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_function, /*IsSupported=*/true));
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_objc_method, /*IsSupported=*/LangOpts.ObjC));
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_block, /*IsSupported=*/LangOpts.Blocks));
}

static const ParsedAttrInfoMIGServerRoutine Instance;
};
const ParsedAttrInfoMIGServerRoutine ParsedAttrInfoMIGServerRoutine::Instance;
static constexpr ParsedAttrInfo::Spelling MSABISpellings[] = {
  {AttributeCommonInfo::AS_GNU, "ms_abi"},
  {AttributeCommonInfo::AS_CXX11, "gnu::ms_abi"},
  {AttributeCommonInfo::AS_C2x, "gnu::ms_abi"},
};
struct ParsedAttrInfoMSABI final : public ParsedAttrInfo {
  ParsedAttrInfoMSABI() {
    AttrKind = ParsedAttr::AT_MSABI;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 1;
    IsStmt = 0;
    IsKnownToGCC = 1;
    IsSupportedByPragmaAttribute = 0;
    Spellings = MSABISpellings;
  }
static const ParsedAttrInfoMSABI Instance;
};
const ParsedAttrInfoMSABI ParsedAttrInfoMSABI::Instance;
static constexpr ParsedAttrInfo::Spelling MSAllocatorSpellings[] = {
  {AttributeCommonInfo::AS_Declspec, "allocator"},
};
struct ParsedAttrInfoMSAllocator final : public ParsedAttrInfo {
  ParsedAttrInfoMSAllocator() {
    AttrKind = ParsedAttr::AT_MSAllocator;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 0;
    Spellings = MSAllocatorSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FunctionDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "functions";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

static const ParsedAttrInfoMSAllocator Instance;
};
const ParsedAttrInfoMSAllocator ParsedAttrInfoMSAllocator::Instance;
static constexpr ParsedAttrInfo::Spelling MSInheritanceSpellings[] = {
  {AttributeCommonInfo::AS_Keyword, "__single_inheritance"},
  {AttributeCommonInfo::AS_Keyword, "__multiple_inheritance"},
  {AttributeCommonInfo::AS_Keyword, "__virtual_inheritance"},
  {AttributeCommonInfo::AS_Keyword, "__unspecified_inheritance"},
};
struct ParsedAttrInfoMSInheritance final : public ParsedAttrInfo {
  ParsedAttrInfoMSInheritance() {
    AttrKind = ParsedAttr::AT_MSInheritance;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 0;
    Spellings = MSInheritanceSpellings;
  }
bool acceptsLangOpts(const LangOptions &LangOpts) const override {
  return LangOpts.MicrosoftExt;
}

unsigned spellingIndexToSemanticSpelling(const ParsedAttr &Attr) const override {
  enum Spelling {
    Keyword_single_inheritance = 0,
    Keyword_multiple_inheritance = 1,
    Keyword_virtual_inheritance = 2,
    Keyword_unspecified_inheritance = 3,
  SpellingNotCalculated = 15

  };

  unsigned Idx = Attr.getAttributeSpellingListIndex();
  switch (Idx) {
    default: llvm_unreachable("Unknown spelling list index");
    case 0: return Keyword_single_inheritance;
    case 1: return Keyword_multiple_inheritance;
    case 2: return Keyword_virtual_inheritance;
    case 3: return Keyword_unspecified_inheritance;
  }
}

static const ParsedAttrInfoMSInheritance Instance;
};
const ParsedAttrInfoMSInheritance ParsedAttrInfoMSInheritance::Instance;
static constexpr ParsedAttrInfo::Spelling MSNoVTableSpellings[] = {
  {AttributeCommonInfo::AS_Declspec, "novtable"},
};
struct ParsedAttrInfoMSNoVTable final : public ParsedAttrInfo {
  ParsedAttrInfoMSNoVTable() {
    AttrKind = ParsedAttr::AT_MSNoVTable;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 1;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 0;
    Spellings = MSNoVTableSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<CXXRecordDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "classes";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

bool existsInTarget(const TargetInfo &Target) const override {
  const llvm::Triple &T = Target.getTriple(); (void)T;
  return true && (T.getArch() == llvm::Triple::x86 || T.getArch() == llvm::Triple::x86_64 || T.getArch() == llvm::Triple::arm || T.getArch() == llvm::Triple::thumb || T.getArch() == llvm::Triple::aarch64) && ( Target.getCXXABI().isMicrosoft() );
}

AttrHandling handleDeclAttribute(Sema &S, Decl *D,const ParsedAttr &Attr) const override {
  D->addAttr(::new (S.Context) MSNoVTableAttr(S.Context, Attr));
  return AttributeApplied;
}

static const ParsedAttrInfoMSNoVTable Instance;
};
const ParsedAttrInfoMSNoVTable ParsedAttrInfoMSNoVTable::Instance;
static constexpr ParsedAttrInfo::Spelling MSStructSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "ms_struct"},
  {AttributeCommonInfo::AS_CXX11, "gnu::ms_struct"},
  {AttributeCommonInfo::AS_C2x, "gnu::ms_struct"},
};
struct ParsedAttrInfoMSStruct final : public ParsedAttrInfo {
  ParsedAttrInfoMSStruct() {
    AttrKind = ParsedAttr::AT_MSStruct;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 1;
    IsSupportedByPragmaAttribute = 1;
    Spellings = MSStructSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<RecordDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "structs, unions, and classes";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_record, /*IsSupported=*/true));
}

AttrHandling handleDeclAttribute(Sema &S, Decl *D,const ParsedAttr &Attr) const override {
  D->addAttr(::new (S.Context) MSStructAttr(S.Context, Attr));
  return AttributeApplied;
}

static const ParsedAttrInfoMSStruct Instance;
};
const ParsedAttrInfoMSStruct ParsedAttrInfoMSStruct::Instance;
static constexpr ParsedAttrInfo::Spelling MatrixTypeSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "matrix_type"},
  {AttributeCommonInfo::AS_CXX11, "clang::matrix_type"},
  {AttributeCommonInfo::AS_C2x, "clang::matrix_type"},
};
static constexpr const char *MatrixTypeArgNames[] = {
"NumRows","NumColumns",};
struct ParsedAttrInfoMatrixType final : public ParsedAttrInfo {
  ParsedAttrInfoMatrixType() {
    AttrKind = ParsedAttr::AT_MatrixType;
    NumArgs = 2;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 1;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 0;
    Spellings = MatrixTypeSpellings;
    ArgNames = MatrixTypeArgNames;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<TypedefNameDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::err_attribute_wrong_decl_type_str)
      << Attr << "typedefs";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

static const ParsedAttrInfoMatrixType Instance;
};
const ParsedAttrInfoMatrixType ParsedAttrInfoMatrixType::Instance;
static constexpr ParsedAttrInfo::Spelling MayAliasSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "may_alias"},
  {AttributeCommonInfo::AS_CXX11, "gnu::may_alias"},
  {AttributeCommonInfo::AS_C2x, "gnu::may_alias"},
};
struct ParsedAttrInfoMayAlias final : public ParsedAttrInfo {
  ParsedAttrInfoMayAlias() {
    AttrKind = ParsedAttr::AT_MayAlias;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 1;
    IsSupportedByPragmaAttribute = 0;
    Spellings = MayAliasSpellings;
  }
AttrHandling handleDeclAttribute(Sema &S, Decl *D,const ParsedAttr &Attr) const override {
  D->addAttr(::new (S.Context) MayAliasAttr(S.Context, Attr));
  return AttributeApplied;
}

static const ParsedAttrInfoMayAlias Instance;
};
const ParsedAttrInfoMayAlias ParsedAttrInfoMayAlias::Instance;
static constexpr ParsedAttrInfo::Spelling MicroMipsSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "micromips"},
  {AttributeCommonInfo::AS_CXX11, "gnu::micromips"},
  {AttributeCommonInfo::AS_C2x, "gnu::micromips"},
};
struct ParsedAttrInfoMicroMips final : public ParsedAttrInfo {
  ParsedAttrInfoMicroMips() {
    AttrKind = ParsedAttr::AT_MicroMips;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 1;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 1;
    IsSupportedByPragmaAttribute = 1;
    Spellings = MicroMipsSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FunctionDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::err_attribute_wrong_decl_type_str)
      << Attr << "functions";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

  using ParsedAttrInfo::diagMutualExclusion;

  bool diagMutualExclusion(Sema &S, const ParsedAttr &AL, const Decl *D) const override {
    if (const auto *A = D->getAttr<Mips16Attr>()) {
      S.Diag(AL.getLoc(), diag::err_attributes_are_not_compatible) << AL << A;
      S.Diag(A->getLocation(), diag::note_conflicting_attribute);      
return false;
    }
    return true;
  }

bool existsInTarget(const TargetInfo &Target) const override {
  const llvm::Triple &T = Target.getTriple(); (void)T;
  return true && (T.getArch() == llvm::Triple::mips || T.getArch() == llvm::Triple::mipsel);
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_function, /*IsSupported=*/true));
}

AttrHandling handleDeclAttribute(Sema &S, Decl *D,const ParsedAttr &Attr) const override {
  D->addAttr(::new (S.Context) MicroMipsAttr(S.Context, Attr));
  return AttributeApplied;
}

static const ParsedAttrInfoMicroMips Instance;
};
const ParsedAttrInfoMicroMips ParsedAttrInfoMicroMips::Instance;
static constexpr ParsedAttrInfo::Spelling MinSizeSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "minsize"},
  {AttributeCommonInfo::AS_CXX11, "clang::minsize"},
  {AttributeCommonInfo::AS_C2x, "clang::minsize"},
};
struct ParsedAttrInfoMinSize final : public ParsedAttrInfo {
  ParsedAttrInfoMinSize() {
    AttrKind = ParsedAttr::AT_MinSize;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = MinSizeSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FunctionDecl>(D) && !isa<ObjCMethodDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::err_attribute_wrong_decl_type_str)
      << Attr << "functions and Objective-C methods";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_function, /*IsSupported=*/true));
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_objc_method, /*IsSupported=*/LangOpts.ObjC));
}

static const ParsedAttrInfoMinSize Instance;
};
const ParsedAttrInfoMinSize ParsedAttrInfoMinSize::Instance;
static constexpr ParsedAttrInfo::Spelling MinVectorWidthSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "min_vector_width"},
  {AttributeCommonInfo::AS_CXX11, "clang::min_vector_width"},
  {AttributeCommonInfo::AS_C2x, "clang::min_vector_width"},
};
static constexpr const char *MinVectorWidthArgNames[] = {
"VectorWidth",};
struct ParsedAttrInfoMinVectorWidth final : public ParsedAttrInfo {
  ParsedAttrInfoMinVectorWidth() {
    AttrKind = ParsedAttr::AT_MinVectorWidth;
    NumArgs = 1;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = MinVectorWidthSpellings;
    ArgNames = MinVectorWidthArgNames;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FunctionDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::err_attribute_wrong_decl_type_str)
      << Attr << "functions";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_function, /*IsSupported=*/true));
}

static const ParsedAttrInfoMinVectorWidth Instance;
};
const ParsedAttrInfoMinVectorWidth ParsedAttrInfoMinVectorWidth::Instance;
static constexpr ParsedAttrInfo::Spelling Mips16Spellings[] = {
  {AttributeCommonInfo::AS_GNU, "mips16"},
  {AttributeCommonInfo::AS_CXX11, "gnu::mips16"},
  {AttributeCommonInfo::AS_C2x, "gnu::mips16"},
};
struct ParsedAttrInfoMips16 final : public ParsedAttrInfo {
  ParsedAttrInfoMips16() {
    AttrKind = ParsedAttr::AT_Mips16;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 1;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 1;
    IsSupportedByPragmaAttribute = 1;
    Spellings = Mips16Spellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FunctionDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::err_attribute_wrong_decl_type_str)
      << Attr << "functions";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

  using ParsedAttrInfo::diagMutualExclusion;

  bool diagMutualExclusion(Sema &S, const ParsedAttr &AL, const Decl *D) const override {
    if (const auto *A = D->getAttr<MipsInterruptAttr>()) {
      S.Diag(AL.getLoc(), diag::err_attributes_are_not_compatible) << AL << A;
      S.Diag(A->getLocation(), diag::note_conflicting_attribute);      
return false;
    }
    if (const auto *A = D->getAttr<MicroMipsAttr>()) {
      S.Diag(AL.getLoc(), diag::err_attributes_are_not_compatible) << AL << A;
      S.Diag(A->getLocation(), diag::note_conflicting_attribute);      
return false;
    }
    return true;
  }

bool existsInTarget(const TargetInfo &Target) const override {
  const llvm::Triple &T = Target.getTriple(); (void)T;
  return true && (T.getArch() == llvm::Triple::mips || T.getArch() == llvm::Triple::mipsel);
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_function, /*IsSupported=*/true));
}

AttrHandling handleDeclAttribute(Sema &S, Decl *D,const ParsedAttr &Attr) const override {
  D->addAttr(::new (S.Context) Mips16Attr(S.Context, Attr));
  return AttributeApplied;
}

static const ParsedAttrInfoMips16 Instance;
};
const ParsedAttrInfoMips16 ParsedAttrInfoMips16::Instance;
static constexpr ParsedAttrInfo::Spelling MipsLongCallSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "long_call"},
  {AttributeCommonInfo::AS_CXX11, "gnu::long_call"},
  {AttributeCommonInfo::AS_C2x, "gnu::long_call"},
  {AttributeCommonInfo::AS_GNU, "far"},
  {AttributeCommonInfo::AS_CXX11, "gnu::far"},
  {AttributeCommonInfo::AS_C2x, "gnu::far"},
};
struct ParsedAttrInfoMipsLongCall final : public ParsedAttrInfo {
  ParsedAttrInfoMipsLongCall() {
    AttrKind = ParsedAttr::AT_MipsLongCall;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 1;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 1;
    IsSupportedByPragmaAttribute = 1;
    Spellings = MipsLongCallSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FunctionDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "functions";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

  using ParsedAttrInfo::diagMutualExclusion;

  bool diagMutualExclusion(Sema &S, const ParsedAttr &AL, const Decl *D) const override {
    if (const auto *A = D->getAttr<MipsShortCallAttr>()) {
      S.Diag(AL.getLoc(), diag::err_attributes_are_not_compatible) << AL << A;
      S.Diag(A->getLocation(), diag::note_conflicting_attribute);      
return false;
    }
    return true;
  }

bool existsInTarget(const TargetInfo &Target) const override {
  const llvm::Triple &T = Target.getTriple(); (void)T;
  return true && (T.getArch() == llvm::Triple::mips || T.getArch() == llvm::Triple::mipsel || T.getArch() == llvm::Triple::mips64 || T.getArch() == llvm::Triple::mips64el);
}

unsigned spellingIndexToSemanticSpelling(const ParsedAttr &Attr) const override {
  enum Spelling {
    GNU_long_call = 0,
    CXX11_gnu_long_call = 1,
    C2x_gnu_long_call = 2,
    GNU_far = 3,
    CXX11_gnu_far = 4,
    C2x_gnu_far = 5,
  SpellingNotCalculated = 15

  };

  unsigned Idx = Attr.getAttributeSpellingListIndex();
  switch (Idx) {
    default: llvm_unreachable("Unknown spelling list index");
    case 0: return GNU_long_call;
    case 1: return CXX11_gnu_long_call;
    case 2: return C2x_gnu_long_call;
    case 3: return GNU_far;
    case 4: return CXX11_gnu_far;
    case 5: return C2x_gnu_far;
  }
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_function, /*IsSupported=*/true));
}

AttrHandling handleDeclAttribute(Sema &S, Decl *D,const ParsedAttr &Attr) const override {
  D->addAttr(::new (S.Context) MipsLongCallAttr(S.Context, Attr));
  return AttributeApplied;
}

static const ParsedAttrInfoMipsLongCall Instance;
};
const ParsedAttrInfoMipsLongCall ParsedAttrInfoMipsLongCall::Instance;
static constexpr ParsedAttrInfo::Spelling MipsShortCallSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "short_call"},
  {AttributeCommonInfo::AS_CXX11, "gnu::short_call"},
  {AttributeCommonInfo::AS_C2x, "gnu::short_call"},
  {AttributeCommonInfo::AS_GNU, "near"},
  {AttributeCommonInfo::AS_CXX11, "gnu::near"},
  {AttributeCommonInfo::AS_C2x, "gnu::near"},
};
struct ParsedAttrInfoMipsShortCall final : public ParsedAttrInfo {
  ParsedAttrInfoMipsShortCall() {
    AttrKind = ParsedAttr::AT_MipsShortCall;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 1;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 1;
    IsSupportedByPragmaAttribute = 1;
    Spellings = MipsShortCallSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FunctionDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "functions";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

  using ParsedAttrInfo::diagMutualExclusion;

  bool diagMutualExclusion(Sema &S, const ParsedAttr &AL, const Decl *D) const override {
    if (const auto *A = D->getAttr<MipsLongCallAttr>()) {
      S.Diag(AL.getLoc(), diag::err_attributes_are_not_compatible) << AL << A;
      S.Diag(A->getLocation(), diag::note_conflicting_attribute);      
return false;
    }
    return true;
  }

bool existsInTarget(const TargetInfo &Target) const override {
  const llvm::Triple &T = Target.getTriple(); (void)T;
  return true && (T.getArch() == llvm::Triple::mips || T.getArch() == llvm::Triple::mipsel || T.getArch() == llvm::Triple::mips64 || T.getArch() == llvm::Triple::mips64el);
}

unsigned spellingIndexToSemanticSpelling(const ParsedAttr &Attr) const override {
  enum Spelling {
    GNU_short_call = 0,
    CXX11_gnu_short_call = 1,
    C2x_gnu_short_call = 2,
    GNU_near = 3,
    CXX11_gnu_near = 4,
    C2x_gnu_near = 5,
  SpellingNotCalculated = 15

  };

  unsigned Idx = Attr.getAttributeSpellingListIndex();
  switch (Idx) {
    default: llvm_unreachable("Unknown spelling list index");
    case 0: return GNU_short_call;
    case 1: return CXX11_gnu_short_call;
    case 2: return C2x_gnu_short_call;
    case 3: return GNU_near;
    case 4: return CXX11_gnu_near;
    case 5: return C2x_gnu_near;
  }
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_function, /*IsSupported=*/true));
}

AttrHandling handleDeclAttribute(Sema &S, Decl *D,const ParsedAttr &Attr) const override {
  D->addAttr(::new (S.Context) MipsShortCallAttr(S.Context, Attr));
  return AttributeApplied;
}

static const ParsedAttrInfoMipsShortCall Instance;
};
const ParsedAttrInfoMipsShortCall ParsedAttrInfoMipsShortCall::Instance;
static constexpr ParsedAttrInfo::Spelling ModeSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "mode"},
  {AttributeCommonInfo::AS_CXX11, "gnu::mode"},
  {AttributeCommonInfo::AS_C2x, "gnu::mode"},
};
static constexpr const char *ModeArgNames[] = {
"Mode",};
struct ParsedAttrInfoMode final : public ParsedAttrInfo {
  ParsedAttrInfoMode() {
    AttrKind = ParsedAttr::AT_Mode;
    NumArgs = 1;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 1;
    IsSupportedByPragmaAttribute = 0;
    Spellings = ModeSpellings;
    ArgNames = ModeArgNames;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<VarDecl>(D) && !isa<EnumDecl>(D) && !isa<TypedefNameDecl>(D) && !isa<FieldDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::err_attribute_wrong_decl_type_str)
      << Attr << "variables, enums, typedefs, and non-static data members";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

static const ParsedAttrInfoMode Instance;
};
const ParsedAttrInfoMode ParsedAttrInfoMode::Instance;
static constexpr ParsedAttrInfo::Spelling MustTailSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "musttail"},
  {AttributeCommonInfo::AS_CXX11, "clang::musttail"},
  {AttributeCommonInfo::AS_C2x, "clang::musttail"},
};
struct ParsedAttrInfoMustTail final : public ParsedAttrInfo {
  ParsedAttrInfoMustTail() {
    AttrKind = ParsedAttr::AT_MustTail;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 1;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 0;
    Spellings = MustTailSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &AL, const Decl *D) const override {
  S.Diag(AL.getLoc(), diag::err_stmt_attribute_invalid_on_decl)
    << AL << D->getLocation();
  return false;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &Attr, const Stmt *St) const override {
  if (!isa<ReturnStmt>(St)) {
    S.Diag(Attr.getLoc(), diag::err_attribute_wrong_decl_type_str)
      << Attr << "return statements";
    return false;
  }
  return true;
}

static const ParsedAttrInfoMustTail Instance;
};
const ParsedAttrInfoMustTail ParsedAttrInfoMustTail::Instance;
static constexpr ParsedAttrInfo::Spelling NSConsumedSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "ns_consumed"},
  {AttributeCommonInfo::AS_CXX11, "clang::ns_consumed"},
  {AttributeCommonInfo::AS_C2x, "clang::ns_consumed"},
};
struct ParsedAttrInfoNSConsumed final : public ParsedAttrInfo {
  ParsedAttrInfoNSConsumed() {
    AttrKind = ParsedAttr::AT_NSConsumed;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = NSConsumedSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<ParmVarDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "parameters";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_variable_is_parameter, /*IsSupported=*/true));
}

static const ParsedAttrInfoNSConsumed Instance;
};
const ParsedAttrInfoNSConsumed ParsedAttrInfoNSConsumed::Instance;
static constexpr ParsedAttrInfo::Spelling NSConsumesSelfSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "ns_consumes_self"},
  {AttributeCommonInfo::AS_CXX11, "clang::ns_consumes_self"},
  {AttributeCommonInfo::AS_C2x, "clang::ns_consumes_self"},
};
struct ParsedAttrInfoNSConsumesSelf final : public ParsedAttrInfo {
  ParsedAttrInfoNSConsumesSelf() {
    AttrKind = ParsedAttr::AT_NSConsumesSelf;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = NSConsumesSelfSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<ObjCMethodDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "Objective-C methods";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_objc_method, /*IsSupported=*/LangOpts.ObjC));
}

AttrHandling handleDeclAttribute(Sema &S, Decl *D,const ParsedAttr &Attr) const override {
  D->addAttr(::new (S.Context) NSConsumesSelfAttr(S.Context, Attr));
  return AttributeApplied;
}

static const ParsedAttrInfoNSConsumesSelf Instance;
};
const ParsedAttrInfoNSConsumesSelf ParsedAttrInfoNSConsumesSelf::Instance;
static constexpr ParsedAttrInfo::Spelling NSErrorDomainSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "ns_error_domain"},
};
static constexpr const char *NSErrorDomainArgNames[] = {
"ErrorDomain",};
struct ParsedAttrInfoNSErrorDomain final : public ParsedAttrInfo {
  ParsedAttrInfoNSErrorDomain() {
    AttrKind = ParsedAttr::AT_NSErrorDomain;
    NumArgs = 1;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = NSErrorDomainSpellings;
    ArgNames = NSErrorDomainArgNames;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<EnumDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::err_attribute_wrong_decl_type_str)
      << Attr << "enums";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_enum, /*IsSupported=*/true));
}

static const ParsedAttrInfoNSErrorDomain Instance;
};
const ParsedAttrInfoNSErrorDomain ParsedAttrInfoNSErrorDomain::Instance;
static constexpr ParsedAttrInfo::Spelling NSReturnsAutoreleasedSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "ns_returns_autoreleased"},
  {AttributeCommonInfo::AS_CXX11, "clang::ns_returns_autoreleased"},
  {AttributeCommonInfo::AS_C2x, "clang::ns_returns_autoreleased"},
};
struct ParsedAttrInfoNSReturnsAutoreleased final : public ParsedAttrInfo {
  ParsedAttrInfoNSReturnsAutoreleased() {
    AttrKind = ParsedAttr::AT_NSReturnsAutoreleased;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 0;
    Spellings = NSReturnsAutoreleasedSpellings;
  }
static const ParsedAttrInfoNSReturnsAutoreleased Instance;
};
const ParsedAttrInfoNSReturnsAutoreleased ParsedAttrInfoNSReturnsAutoreleased::Instance;
static constexpr ParsedAttrInfo::Spelling NSReturnsNotRetainedSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "ns_returns_not_retained"},
  {AttributeCommonInfo::AS_CXX11, "clang::ns_returns_not_retained"},
  {AttributeCommonInfo::AS_C2x, "clang::ns_returns_not_retained"},
};
struct ParsedAttrInfoNSReturnsNotRetained final : public ParsedAttrInfo {
  ParsedAttrInfoNSReturnsNotRetained() {
    AttrKind = ParsedAttr::AT_NSReturnsNotRetained;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 0;
    Spellings = NSReturnsNotRetainedSpellings;
  }
static const ParsedAttrInfoNSReturnsNotRetained Instance;
};
const ParsedAttrInfoNSReturnsNotRetained ParsedAttrInfoNSReturnsNotRetained::Instance;
static constexpr ParsedAttrInfo::Spelling NSReturnsRetainedSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "ns_returns_retained"},
  {AttributeCommonInfo::AS_CXX11, "clang::ns_returns_retained"},
  {AttributeCommonInfo::AS_C2x, "clang::ns_returns_retained"},
};
struct ParsedAttrInfoNSReturnsRetained final : public ParsedAttrInfo {
  ParsedAttrInfoNSReturnsRetained() {
    AttrKind = ParsedAttr::AT_NSReturnsRetained;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 1;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 0;
    Spellings = NSReturnsRetainedSpellings;
  }
static const ParsedAttrInfoNSReturnsRetained Instance;
};
const ParsedAttrInfoNSReturnsRetained ParsedAttrInfoNSReturnsRetained::Instance;
static constexpr ParsedAttrInfo::Spelling NakedSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "naked"},
  {AttributeCommonInfo::AS_CXX11, "gnu::naked"},
  {AttributeCommonInfo::AS_C2x, "gnu::naked"},
  {AttributeCommonInfo::AS_Declspec, "naked"},
};
struct ParsedAttrInfoNaked final : public ParsedAttrInfo {
  ParsedAttrInfoNaked() {
    AttrKind = ParsedAttr::AT_Naked;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 1;
    IsSupportedByPragmaAttribute = 1;
    Spellings = NakedSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FunctionDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "functions";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

  using ParsedAttrInfo::diagMutualExclusion;

  bool diagMutualExclusion(Sema &S, const ParsedAttr &AL, const Decl *D) const override {
    if (const auto *A = D->getAttr<DisableTailCallsAttr>()) {
      S.Diag(AL.getLoc(), diag::err_attributes_are_not_compatible) << AL << A;
      S.Diag(A->getLocation(), diag::note_conflicting_attribute);      
return false;
    }
    return true;
  }

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_function, /*IsSupported=*/true));
}

static const ParsedAttrInfoNaked Instance;
};
const ParsedAttrInfoNaked ParsedAttrInfoNaked::Instance;
static constexpr ParsedAttrInfo::Spelling NeonPolyVectorTypeSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "neon_polyvector_type"},
  {AttributeCommonInfo::AS_CXX11, "clang::neon_polyvector_type"},
  {AttributeCommonInfo::AS_C2x, "clang::neon_polyvector_type"},
};
static constexpr const char *NeonPolyVectorTypeArgNames[] = {
"NumElements",};
struct ParsedAttrInfoNeonPolyVectorType final : public ParsedAttrInfo {
  ParsedAttrInfoNeonPolyVectorType() {
    AttrKind = ParsedAttr::AT_NeonPolyVectorType;
    NumArgs = 1;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 1;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 0;
    Spellings = NeonPolyVectorTypeSpellings;
    ArgNames = NeonPolyVectorTypeArgNames;
  }
static const ParsedAttrInfoNeonPolyVectorType Instance;
};
const ParsedAttrInfoNeonPolyVectorType ParsedAttrInfoNeonPolyVectorType::Instance;
static constexpr ParsedAttrInfo::Spelling NeonVectorTypeSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "neon_vector_type"},
  {AttributeCommonInfo::AS_CXX11, "clang::neon_vector_type"},
  {AttributeCommonInfo::AS_C2x, "clang::neon_vector_type"},
};
static constexpr const char *NeonVectorTypeArgNames[] = {
"NumElements",};
struct ParsedAttrInfoNeonVectorType final : public ParsedAttrInfo {
  ParsedAttrInfoNeonVectorType() {
    AttrKind = ParsedAttr::AT_NeonVectorType;
    NumArgs = 1;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 1;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 0;
    Spellings = NeonVectorTypeSpellings;
    ArgNames = NeonVectorTypeArgNames;
  }
static const ParsedAttrInfoNeonVectorType Instance;
};
const ParsedAttrInfoNeonVectorType ParsedAttrInfoNeonVectorType::Instance;
static constexpr ParsedAttrInfo::Spelling NoAliasSpellings[] = {
  {AttributeCommonInfo::AS_Declspec, "noalias"},
};
struct ParsedAttrInfoNoAlias final : public ParsedAttrInfo {
  ParsedAttrInfoNoAlias() {
    AttrKind = ParsedAttr::AT_NoAlias;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 0;
    Spellings = NoAliasSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FunctionDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "functions";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

AttrHandling handleDeclAttribute(Sema &S, Decl *D,const ParsedAttr &Attr) const override {
  D->addAttr(::new (S.Context) NoAliasAttr(S.Context, Attr));
  return AttributeApplied;
}

static const ParsedAttrInfoNoAlias Instance;
};
const ParsedAttrInfoNoAlias ParsedAttrInfoNoAlias::Instance;
static constexpr ParsedAttrInfo::Spelling NoBuiltinSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "no_builtin"},
  {AttributeCommonInfo::AS_CXX11, "clang::no_builtin"},
  {AttributeCommonInfo::AS_C2x, "clang::no_builtin"},
};
static constexpr const char *NoBuiltinArgNames[] = {
"BuiltinNames...",};
struct ParsedAttrInfoNoBuiltin final : public ParsedAttrInfo {
  ParsedAttrInfoNoBuiltin() {
    AttrKind = ParsedAttr::AT_NoBuiltin;
    NumArgs = 0;
    OptArgs = 15;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = NoBuiltinSpellings;
    ArgNames = NoBuiltinArgNames;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FunctionDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "functions";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_function, /*IsSupported=*/true));
}

static const ParsedAttrInfoNoBuiltin Instance;
};
const ParsedAttrInfoNoBuiltin ParsedAttrInfoNoBuiltin::Instance;
static constexpr ParsedAttrInfo::Spelling NoCommonSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "nocommon"},
  {AttributeCommonInfo::AS_CXX11, "gnu::nocommon"},
  {AttributeCommonInfo::AS_C2x, "gnu::nocommon"},
};
struct ParsedAttrInfoNoCommon final : public ParsedAttrInfo {
  ParsedAttrInfoNoCommon() {
    AttrKind = ParsedAttr::AT_NoCommon;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 1;
    IsSupportedByPragmaAttribute = 1;
    Spellings = NoCommonSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<VarDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "variables";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_variable, /*IsSupported=*/true));
}

AttrHandling handleDeclAttribute(Sema &S, Decl *D,const ParsedAttr &Attr) const override {
  D->addAttr(::new (S.Context) NoCommonAttr(S.Context, Attr));
  return AttributeApplied;
}

static const ParsedAttrInfoNoCommon Instance;
};
const ParsedAttrInfoNoCommon ParsedAttrInfoNoCommon::Instance;
static constexpr ParsedAttrInfo::Spelling NoDebugSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "nodebug"},
  {AttributeCommonInfo::AS_CXX11, "gnu::nodebug"},
  {AttributeCommonInfo::AS_C2x, "gnu::nodebug"},
};
struct ParsedAttrInfoNoDebug final : public ParsedAttrInfo {
  ParsedAttrInfoNoDebug() {
    AttrKind = ParsedAttr::AT_NoDebug;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 1;
    IsSupportedByPragmaAttribute = 1;
    Spellings = NoDebugSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<TypedefNameDecl>(D) && !isFunctionLike(D) && !isa<ObjCMethodDecl>(D) && !isNonParmVar(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "typedefs, functions, function pointers, Objective-C methods, and variables";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_type_alias, /*IsSupported=*/true));
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_hasType_functionType, /*IsSupported=*/true));
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_objc_method, /*IsSupported=*/LangOpts.ObjC));
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_variable_not_is_parameter, /*IsSupported=*/true));
}

static const ParsedAttrInfoNoDebug Instance;
};
const ParsedAttrInfoNoDebug ParsedAttrInfoNoDebug::Instance;
static constexpr ParsedAttrInfo::Spelling NoDerefSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "noderef"},
  {AttributeCommonInfo::AS_CXX11, "clang::noderef"},
  {AttributeCommonInfo::AS_C2x, "clang::noderef"},
};
struct ParsedAttrInfoNoDeref final : public ParsedAttrInfo {
  ParsedAttrInfoNoDeref() {
    AttrKind = ParsedAttr::AT_NoDeref;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 1;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 0;
    Spellings = NoDerefSpellings;
  }
static const ParsedAttrInfoNoDeref Instance;
};
const ParsedAttrInfoNoDeref ParsedAttrInfoNoDeref::Instance;
static constexpr ParsedAttrInfo::Spelling NoDestroySpellings[] = {
  {AttributeCommonInfo::AS_GNU, "no_destroy"},
  {AttributeCommonInfo::AS_CXX11, "clang::no_destroy"},
};
struct ParsedAttrInfoNoDestroy final : public ParsedAttrInfo {
  ParsedAttrInfoNoDestroy() {
    AttrKind = ParsedAttr::AT_NoDestroy;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = NoDestroySpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<VarDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "variables";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

  using ParsedAttrInfo::diagMutualExclusion;

  bool diagMutualExclusion(Sema &S, const ParsedAttr &AL, const Decl *D) const override {
    if (const auto *A = D->getAttr<AlwaysDestroyAttr>()) {
      S.Diag(AL.getLoc(), diag::err_attributes_are_not_compatible) << AL << A;
      S.Diag(A->getLocation(), diag::note_conflicting_attribute);      
return false;
    }
    return true;
  }

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_variable, /*IsSupported=*/true));
}

static const ParsedAttrInfoNoDestroy Instance;
};
const ParsedAttrInfoNoDestroy ParsedAttrInfoNoDestroy::Instance;
static constexpr ParsedAttrInfo::Spelling NoDuplicateSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "noduplicate"},
  {AttributeCommonInfo::AS_CXX11, "clang::noduplicate"},
  {AttributeCommonInfo::AS_C2x, "clang::noduplicate"},
};
struct ParsedAttrInfoNoDuplicate final : public ParsedAttrInfo {
  ParsedAttrInfoNoDuplicate() {
    AttrKind = ParsedAttr::AT_NoDuplicate;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = NoDuplicateSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FunctionDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "functions";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_function, /*IsSupported=*/true));
}

AttrHandling handleDeclAttribute(Sema &S, Decl *D,const ParsedAttr &Attr) const override {
  D->addAttr(::new (S.Context) NoDuplicateAttr(S.Context, Attr));
  return AttributeApplied;
}

static const ParsedAttrInfoNoDuplicate Instance;
};
const ParsedAttrInfoNoDuplicate ParsedAttrInfoNoDuplicate::Instance;
static constexpr ParsedAttrInfo::Spelling NoEscapeSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "noescape"},
  {AttributeCommonInfo::AS_CXX11, "clang::noescape"},
  {AttributeCommonInfo::AS_C2x, "clang::noescape"},
};
struct ParsedAttrInfoNoEscape final : public ParsedAttrInfo {
  ParsedAttrInfoNoEscape() {
    AttrKind = ParsedAttr::AT_NoEscape;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = NoEscapeSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<ParmVarDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "parameters";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_variable_is_parameter, /*IsSupported=*/true));
}

static const ParsedAttrInfoNoEscape Instance;
};
const ParsedAttrInfoNoEscape ParsedAttrInfoNoEscape::Instance;
static constexpr ParsedAttrInfo::Spelling NoInlineSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "noinline"},
  {AttributeCommonInfo::AS_CXX11, "gnu::noinline"},
  {AttributeCommonInfo::AS_C2x, "gnu::noinline"},
  {AttributeCommonInfo::AS_Declspec, "noinline"},
};
struct ParsedAttrInfoNoInline final : public ParsedAttrInfo {
  ParsedAttrInfoNoInline() {
    AttrKind = ParsedAttr::AT_NoInline;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 1;
    IsSupportedByPragmaAttribute = 1;
    Spellings = NoInlineSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FunctionDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "functions";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_function, /*IsSupported=*/true));
}

AttrHandling handleDeclAttribute(Sema &S, Decl *D,const ParsedAttr &Attr) const override {
  D->addAttr(::new (S.Context) NoInlineAttr(S.Context, Attr));
  return AttributeApplied;
}

static const ParsedAttrInfoNoInline Instance;
};
const ParsedAttrInfoNoInline ParsedAttrInfoNoInline::Instance;
static constexpr ParsedAttrInfo::Spelling NoInstrumentFunctionSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "no_instrument_function"},
  {AttributeCommonInfo::AS_CXX11, "gnu::no_instrument_function"},
  {AttributeCommonInfo::AS_C2x, "gnu::no_instrument_function"},
};
struct ParsedAttrInfoNoInstrumentFunction final : public ParsedAttrInfo {
  ParsedAttrInfoNoInstrumentFunction() {
    AttrKind = ParsedAttr::AT_NoInstrumentFunction;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 1;
    IsSupportedByPragmaAttribute = 1;
    Spellings = NoInstrumentFunctionSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FunctionDecl>(D) && !isa<ObjCMethodDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "functions and Objective-C methods";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_function, /*IsSupported=*/true));
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_objc_method, /*IsSupported=*/LangOpts.ObjC));
}

AttrHandling handleDeclAttribute(Sema &S, Decl *D,const ParsedAttr &Attr) const override {
  D->addAttr(::new (S.Context) NoInstrumentFunctionAttr(S.Context, Attr));
  return AttributeApplied;
}

static const ParsedAttrInfoNoInstrumentFunction Instance;
};
const ParsedAttrInfoNoInstrumentFunction ParsedAttrInfoNoInstrumentFunction::Instance;
static constexpr ParsedAttrInfo::Spelling NoMergeSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "nomerge"},
  {AttributeCommonInfo::AS_CXX11, "clang::nomerge"},
  {AttributeCommonInfo::AS_C2x, "clang::nomerge"},
};
struct ParsedAttrInfoNoMerge final : public ParsedAttrInfo {
  ParsedAttrInfoNoMerge() {
    AttrKind = ParsedAttr::AT_NoMerge;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 1;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = NoMergeSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FunctionDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::err_attribute_wrong_decl_type_str)
      << Attr << "functions and statements";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &Attr, const Stmt *St) const override {
  if (!isa<Stmt>(St)) {
    S.Diag(Attr.getLoc(), diag::err_attribute_wrong_decl_type_str)
      << Attr << "functions and statements";
    return false;
  }
  return true;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_function, /*IsSupported=*/true));
}

AttrHandling handleDeclAttribute(Sema &S, Decl *D,const ParsedAttr &Attr) const override {
  D->addAttr(::new (S.Context) NoMergeAttr(S.Context, Attr));
  return AttributeApplied;
}

static const ParsedAttrInfoNoMerge Instance;
};
const ParsedAttrInfoNoMerge ParsedAttrInfoNoMerge::Instance;
static constexpr ParsedAttrInfo::Spelling NoMicroMipsSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "nomicromips"},
  {AttributeCommonInfo::AS_CXX11, "gnu::nomicromips"},
  {AttributeCommonInfo::AS_C2x, "gnu::nomicromips"},
};
struct ParsedAttrInfoNoMicroMips final : public ParsedAttrInfo {
  ParsedAttrInfoNoMicroMips() {
    AttrKind = ParsedAttr::AT_NoMicroMips;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 1;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 1;
    IsSupportedByPragmaAttribute = 1;
    Spellings = NoMicroMipsSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FunctionDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::err_attribute_wrong_decl_type_str)
      << Attr << "functions";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

bool existsInTarget(const TargetInfo &Target) const override {
  const llvm::Triple &T = Target.getTriple(); (void)T;
  return true && (T.getArch() == llvm::Triple::mips || T.getArch() == llvm::Triple::mipsel);
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_function, /*IsSupported=*/true));
}

AttrHandling handleDeclAttribute(Sema &S, Decl *D,const ParsedAttr &Attr) const override {
  D->addAttr(::new (S.Context) NoMicroMipsAttr(S.Context, Attr));
  return AttributeApplied;
}

static const ParsedAttrInfoNoMicroMips Instance;
};
const ParsedAttrInfoNoMicroMips ParsedAttrInfoNoMicroMips::Instance;
static constexpr ParsedAttrInfo::Spelling NoMips16Spellings[] = {
  {AttributeCommonInfo::AS_GNU, "nomips16"},
  {AttributeCommonInfo::AS_CXX11, "gnu::nomips16"},
  {AttributeCommonInfo::AS_C2x, "gnu::nomips16"},
};
struct ParsedAttrInfoNoMips16 final : public ParsedAttrInfo {
  ParsedAttrInfoNoMips16() {
    AttrKind = ParsedAttr::AT_NoMips16;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 1;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 1;
    IsSupportedByPragmaAttribute = 1;
    Spellings = NoMips16Spellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FunctionDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::err_attribute_wrong_decl_type_str)
      << Attr << "functions";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

bool existsInTarget(const TargetInfo &Target) const override {
  const llvm::Triple &T = Target.getTriple(); (void)T;
  return true && (T.getArch() == llvm::Triple::mips || T.getArch() == llvm::Triple::mipsel);
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_function, /*IsSupported=*/true));
}

AttrHandling handleDeclAttribute(Sema &S, Decl *D,const ParsedAttr &Attr) const override {
  D->addAttr(::new (S.Context) NoMips16Attr(S.Context, Attr));
  return AttributeApplied;
}

static const ParsedAttrInfoNoMips16 Instance;
};
const ParsedAttrInfoNoMips16 ParsedAttrInfoNoMips16::Instance;
static constexpr ParsedAttrInfo::Spelling NoProfileFunctionSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "no_profile_instrument_function"},
  {AttributeCommonInfo::AS_CXX11, "gnu::no_profile_instrument_function"},
  {AttributeCommonInfo::AS_C2x, "gnu::no_profile_instrument_function"},
};
struct ParsedAttrInfoNoProfileFunction final : public ParsedAttrInfo {
  ParsedAttrInfoNoProfileFunction() {
    AttrKind = ParsedAttr::AT_NoProfileFunction;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 1;
    IsSupportedByPragmaAttribute = 1;
    Spellings = NoProfileFunctionSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FunctionDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "functions";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_function, /*IsSupported=*/true));
}

AttrHandling handleDeclAttribute(Sema &S, Decl *D,const ParsedAttr &Attr) const override {
  D->addAttr(::new (S.Context) NoProfileFunctionAttr(S.Context, Attr));
  return AttributeApplied;
}

static const ParsedAttrInfoNoProfileFunction Instance;
};
const ParsedAttrInfoNoProfileFunction ParsedAttrInfoNoProfileFunction::Instance;
static constexpr ParsedAttrInfo::Spelling NoReturnSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "noreturn"},
  {AttributeCommonInfo::AS_CXX11, "gnu::noreturn"},
  {AttributeCommonInfo::AS_C2x, "gnu::noreturn"},
  {AttributeCommonInfo::AS_Declspec, "noreturn"},
};
struct ParsedAttrInfoNoReturn final : public ParsedAttrInfo {
  ParsedAttrInfoNoReturn() {
    AttrKind = ParsedAttr::AT_NoReturn;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 1;
    IsSupportedByPragmaAttribute = 0;
    Spellings = NoReturnSpellings;
  }
static const ParsedAttrInfoNoReturn Instance;
};
const ParsedAttrInfoNoReturn ParsedAttrInfoNoReturn::Instance;
static constexpr ParsedAttrInfo::Spelling NoSanitizeSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "no_sanitize"},
  {AttributeCommonInfo::AS_CXX11, "clang::no_sanitize"},
  {AttributeCommonInfo::AS_C2x, "clang::no_sanitize"},
};
static constexpr const char *NoSanitizeArgNames[] = {
"Sanitizers...",};
struct ParsedAttrInfoNoSanitize final : public ParsedAttrInfo {
  ParsedAttrInfoNoSanitize() {
    AttrKind = ParsedAttr::AT_NoSanitize;
    NumArgs = 0;
    OptArgs = 15;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = NoSanitizeSpellings;
    ArgNames = NoSanitizeArgNames;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FunctionDecl>(D) && !isa<ObjCMethodDecl>(D) && !isGlobalVar(D)) {
    S.Diag(Attr.getLoc(), diag::err_attribute_wrong_decl_type_str)
      << Attr << "functions, Objective-C methods, and global variables";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_function, /*IsSupported=*/true));
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_objc_method, /*IsSupported=*/LangOpts.ObjC));
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_variable_is_global, /*IsSupported=*/true));
}

static const ParsedAttrInfoNoSanitize Instance;
};
const ParsedAttrInfoNoSanitize ParsedAttrInfoNoSanitize::Instance;
static constexpr ParsedAttrInfo::Spelling NoSanitizeSpecificSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "no_address_safety_analysis"},
  {AttributeCommonInfo::AS_CXX11, "gnu::no_address_safety_analysis"},
  {AttributeCommonInfo::AS_C2x, "gnu::no_address_safety_analysis"},
  {AttributeCommonInfo::AS_GNU, "no_sanitize_address"},
  {AttributeCommonInfo::AS_CXX11, "gnu::no_sanitize_address"},
  {AttributeCommonInfo::AS_C2x, "gnu::no_sanitize_address"},
  {AttributeCommonInfo::AS_GNU, "no_sanitize_thread"},
  {AttributeCommonInfo::AS_CXX11, "gnu::no_sanitize_thread"},
  {AttributeCommonInfo::AS_C2x, "gnu::no_sanitize_thread"},
  {AttributeCommonInfo::AS_GNU, "no_sanitize_memory"},
  {AttributeCommonInfo::AS_CXX11, "clang::no_sanitize_memory"},
  {AttributeCommonInfo::AS_C2x, "clang::no_sanitize_memory"},
};
struct ParsedAttrInfoNoSanitizeSpecific final : public ParsedAttrInfo {
  ParsedAttrInfoNoSanitizeSpecific() {
    AttrKind = ParsedAttr::AT_NoSanitizeSpecific;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 1;
    IsSupportedByPragmaAttribute = 1;
    Spellings = NoSanitizeSpecificSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FunctionDecl>(D) && !isGlobalVar(D)) {
    S.Diag(Attr.getLoc(), diag::err_attribute_wrong_decl_type_str)
      << Attr << "functions and global variables";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_function, /*IsSupported=*/true));
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_variable_is_global, /*IsSupported=*/true));
}

static const ParsedAttrInfoNoSanitizeSpecific Instance;
};
const ParsedAttrInfoNoSanitizeSpecific ParsedAttrInfoNoSanitizeSpecific::Instance;
static constexpr ParsedAttrInfo::Spelling NoSpeculativeLoadHardeningSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "no_speculative_load_hardening"},
  {AttributeCommonInfo::AS_CXX11, "clang::no_speculative_load_hardening"},
  {AttributeCommonInfo::AS_C2x, "clang::no_speculative_load_hardening"},
};
struct ParsedAttrInfoNoSpeculativeLoadHardening final : public ParsedAttrInfo {
  ParsedAttrInfoNoSpeculativeLoadHardening() {
    AttrKind = ParsedAttr::AT_NoSpeculativeLoadHardening;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = NoSpeculativeLoadHardeningSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FunctionDecl>(D) && !isa<ObjCMethodDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::err_attribute_wrong_decl_type_str)
      << Attr << "functions and Objective-C methods";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

  using ParsedAttrInfo::diagMutualExclusion;

  bool diagMutualExclusion(Sema &S, const ParsedAttr &AL, const Decl *D) const override {
    if (const auto *A = D->getAttr<SpeculativeLoadHardeningAttr>()) {
      S.Diag(AL.getLoc(), diag::err_attributes_are_not_compatible) << AL << A;
      S.Diag(A->getLocation(), diag::note_conflicting_attribute);      
return false;
    }
    return true;
  }

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_function, /*IsSupported=*/true));
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_objc_method, /*IsSupported=*/LangOpts.ObjC));
}

AttrHandling handleDeclAttribute(Sema &S, Decl *D,const ParsedAttr &Attr) const override {
  D->addAttr(::new (S.Context) NoSpeculativeLoadHardeningAttr(S.Context, Attr));
  return AttributeApplied;
}

static const ParsedAttrInfoNoSpeculativeLoadHardening Instance;
};
const ParsedAttrInfoNoSpeculativeLoadHardening ParsedAttrInfoNoSpeculativeLoadHardening::Instance;
static constexpr ParsedAttrInfo::Spelling NoSplitStackSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "no_split_stack"},
  {AttributeCommonInfo::AS_CXX11, "gnu::no_split_stack"},
  {AttributeCommonInfo::AS_C2x, "gnu::no_split_stack"},
};
struct ParsedAttrInfoNoSplitStack final : public ParsedAttrInfo {
  ParsedAttrInfoNoSplitStack() {
    AttrKind = ParsedAttr::AT_NoSplitStack;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 1;
    IsSupportedByPragmaAttribute = 1;
    Spellings = NoSplitStackSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FunctionDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::err_attribute_wrong_decl_type_str)
      << Attr << "functions";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_function, /*IsSupported=*/true));
}

AttrHandling handleDeclAttribute(Sema &S, Decl *D,const ParsedAttr &Attr) const override {
  D->addAttr(::new (S.Context) NoSplitStackAttr(S.Context, Attr));
  return AttributeApplied;
}

static const ParsedAttrInfoNoSplitStack Instance;
};
const ParsedAttrInfoNoSplitStack ParsedAttrInfoNoSplitStack::Instance;
static constexpr ParsedAttrInfo::Spelling NoStackProtectorSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "no_stack_protector"},
  {AttributeCommonInfo::AS_CXX11, "clang::no_stack_protector"},
  {AttributeCommonInfo::AS_C2x, "clang::no_stack_protector"},
};
struct ParsedAttrInfoNoStackProtector final : public ParsedAttrInfo {
  ParsedAttrInfoNoStackProtector() {
    AttrKind = ParsedAttr::AT_NoStackProtector;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = NoStackProtectorSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FunctionDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "functions";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_function, /*IsSupported=*/true));
}

AttrHandling handleDeclAttribute(Sema &S, Decl *D,const ParsedAttr &Attr) const override {
  D->addAttr(::new (S.Context) NoStackProtectorAttr(S.Context, Attr));
  return AttributeApplied;
}

static const ParsedAttrInfoNoStackProtector Instance;
};
const ParsedAttrInfoNoStackProtector ParsedAttrInfoNoStackProtector::Instance;
static constexpr ParsedAttrInfo::Spelling NoThreadSafetyAnalysisSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "no_thread_safety_analysis"},
  {AttributeCommonInfo::AS_CXX11, "clang::no_thread_safety_analysis"},
  {AttributeCommonInfo::AS_C2x, "clang::no_thread_safety_analysis"},
};
struct ParsedAttrInfoNoThreadSafetyAnalysis final : public ParsedAttrInfo {
  ParsedAttrInfoNoThreadSafetyAnalysis() {
    AttrKind = ParsedAttr::AT_NoThreadSafetyAnalysis;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = NoThreadSafetyAnalysisSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FunctionDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "functions";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_function, /*IsSupported=*/true));
}

AttrHandling handleDeclAttribute(Sema &S, Decl *D,const ParsedAttr &Attr) const override {
  D->addAttr(::new (S.Context) NoThreadSafetyAnalysisAttr(S.Context, Attr));
  return AttributeApplied;
}

static const ParsedAttrInfoNoThreadSafetyAnalysis Instance;
};
const ParsedAttrInfoNoThreadSafetyAnalysis ParsedAttrInfoNoThreadSafetyAnalysis::Instance;
static constexpr ParsedAttrInfo::Spelling NoThrowSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "nothrow"},
  {AttributeCommonInfo::AS_CXX11, "gnu::nothrow"},
  {AttributeCommonInfo::AS_C2x, "gnu::nothrow"},
  {AttributeCommonInfo::AS_Declspec, "nothrow"},
};
struct ParsedAttrInfoNoThrow final : public ParsedAttrInfo {
  ParsedAttrInfoNoThrow() {
    AttrKind = ParsedAttr::AT_NoThrow;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 1;
    IsSupportedByPragmaAttribute = 1;
    Spellings = NoThrowSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isFunctionLike(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "functions and function pointers";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_hasType_functionType, /*IsSupported=*/true));
}

static const ParsedAttrInfoNoThrow Instance;
};
const ParsedAttrInfoNoThrow ParsedAttrInfoNoThrow::Instance;
static constexpr ParsedAttrInfo::Spelling NoUniqueAddressSpellings[] = {
  {AttributeCommonInfo::AS_CXX11, "no_unique_address"},
};
struct ParsedAttrInfoNoUniqueAddress final : public ParsedAttrInfo {
  ParsedAttrInfoNoUniqueAddress() {
    AttrKind = ParsedAttr::AT_NoUniqueAddress;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 1;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 0;
    Spellings = NoUniqueAddressSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isNonBitField(D)) {
    S.Diag(Attr.getLoc(), diag::err_attribute_wrong_decl_type_str)
      << Attr << "non-bit-field non-static data members";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

bool existsInTarget(const TargetInfo &Target) const override {
  const llvm::Triple &T = Target.getTriple(); (void)T;
  return true && ( Target.getCXXABI().isItaniumFamily() );
}

AttrHandling handleDeclAttribute(Sema &S, Decl *D,const ParsedAttr &Attr) const override {
  D->addAttr(::new (S.Context) NoUniqueAddressAttr(S.Context, Attr));
  return AttributeApplied;
}

static const ParsedAttrInfoNoUniqueAddress Instance;
};
const ParsedAttrInfoNoUniqueAddress ParsedAttrInfoNoUniqueAddress::Instance;
static constexpr ParsedAttrInfo::Spelling NonNullSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "nonnull"},
  {AttributeCommonInfo::AS_CXX11, "gnu::nonnull"},
  {AttributeCommonInfo::AS_C2x, "gnu::nonnull"},
};
static constexpr const char *NonNullArgNames[] = {
"Args...",};
struct ParsedAttrInfoNonNull final : public ParsedAttrInfo {
  ParsedAttrInfoNonNull() {
    AttrKind = ParsedAttr::AT_NonNull;
    NumArgs = 0;
    OptArgs = 15;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 1;
    IsSupportedByPragmaAttribute = 0;
    Spellings = NonNullSpellings;
    ArgNames = NonNullArgNames;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<ObjCMethodDecl>(D) && !isHasFunctionProto(D) && !isa<ParmVarDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "functions, methods, and parameters";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

static const ParsedAttrInfoNonNull Instance;
};
const ParsedAttrInfoNonNull ParsedAttrInfoNonNull::Instance;
static constexpr ParsedAttrInfo::Spelling NotTailCalledSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "not_tail_called"},
  {AttributeCommonInfo::AS_CXX11, "clang::not_tail_called"},
  {AttributeCommonInfo::AS_C2x, "clang::not_tail_called"},
};
struct ParsedAttrInfoNotTailCalled final : public ParsedAttrInfo {
  ParsedAttrInfoNotTailCalled() {
    AttrKind = ParsedAttr::AT_NotTailCalled;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = NotTailCalledSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FunctionDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "functions";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

  using ParsedAttrInfo::diagMutualExclusion;

  bool diagMutualExclusion(Sema &S, const ParsedAttr &AL, const Decl *D) const override {
    if (const auto *A = D->getAttr<AlwaysInlineAttr>()) {
      S.Diag(AL.getLoc(), diag::err_attributes_are_not_compatible) << AL << A;
      S.Diag(A->getLocation(), diag::note_conflicting_attribute);      
return false;
    }
    return true;
  }

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_function, /*IsSupported=*/true));
}

AttrHandling handleDeclAttribute(Sema &S, Decl *D,const ParsedAttr &Attr) const override {
  D->addAttr(::new (S.Context) NotTailCalledAttr(S.Context, Attr));
  return AttributeApplied;
}

static const ParsedAttrInfoNotTailCalled Instance;
};
const ParsedAttrInfoNotTailCalled ParsedAttrInfoNotTailCalled::Instance;
static constexpr ParsedAttrInfo::Spelling OSConsumedSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "os_consumed"},
  {AttributeCommonInfo::AS_CXX11, "clang::os_consumed"},
  {AttributeCommonInfo::AS_C2x, "clang::os_consumed"},
};
struct ParsedAttrInfoOSConsumed final : public ParsedAttrInfo {
  ParsedAttrInfoOSConsumed() {
    AttrKind = ParsedAttr::AT_OSConsumed;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = OSConsumedSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<ParmVarDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "parameters";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_variable_is_parameter, /*IsSupported=*/true));
}

static const ParsedAttrInfoOSConsumed Instance;
};
const ParsedAttrInfoOSConsumed ParsedAttrInfoOSConsumed::Instance;
static constexpr ParsedAttrInfo::Spelling OSConsumesThisSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "os_consumes_this"},
  {AttributeCommonInfo::AS_CXX11, "clang::os_consumes_this"},
  {AttributeCommonInfo::AS_C2x, "clang::os_consumes_this"},
};
struct ParsedAttrInfoOSConsumesThis final : public ParsedAttrInfo {
  ParsedAttrInfoOSConsumesThis() {
    AttrKind = ParsedAttr::AT_OSConsumesThis;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 0;
    Spellings = OSConsumesThisSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isNonStaticCXXMethod(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "non-static member functions";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

AttrHandling handleDeclAttribute(Sema &S, Decl *D,const ParsedAttr &Attr) const override {
  D->addAttr(::new (S.Context) OSConsumesThisAttr(S.Context, Attr));
  return AttributeApplied;
}

static const ParsedAttrInfoOSConsumesThis Instance;
};
const ParsedAttrInfoOSConsumesThis ParsedAttrInfoOSConsumesThis::Instance;
static constexpr ParsedAttrInfo::Spelling OSReturnsNotRetainedSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "os_returns_not_retained"},
  {AttributeCommonInfo::AS_CXX11, "clang::os_returns_not_retained"},
  {AttributeCommonInfo::AS_C2x, "clang::os_returns_not_retained"},
};
struct ParsedAttrInfoOSReturnsNotRetained final : public ParsedAttrInfo {
  ParsedAttrInfoOSReturnsNotRetained() {
    AttrKind = ParsedAttr::AT_OSReturnsNotRetained;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = OSReturnsNotRetainedSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FunctionDecl>(D) && !isa<ObjCMethodDecl>(D) && !isa<ObjCPropertyDecl>(D) && !isa<ParmVarDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "functions, Objective-C methods, Objective-C properties, and parameters";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_function, /*IsSupported=*/true));
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_objc_method, /*IsSupported=*/LangOpts.ObjC));
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_objc_property, /*IsSupported=*/LangOpts.ObjC));
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_variable_is_parameter, /*IsSupported=*/true));
}

static const ParsedAttrInfoOSReturnsNotRetained Instance;
};
const ParsedAttrInfoOSReturnsNotRetained ParsedAttrInfoOSReturnsNotRetained::Instance;
static constexpr ParsedAttrInfo::Spelling OSReturnsRetainedSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "os_returns_retained"},
  {AttributeCommonInfo::AS_CXX11, "clang::os_returns_retained"},
  {AttributeCommonInfo::AS_C2x, "clang::os_returns_retained"},
};
struct ParsedAttrInfoOSReturnsRetained final : public ParsedAttrInfo {
  ParsedAttrInfoOSReturnsRetained() {
    AttrKind = ParsedAttr::AT_OSReturnsRetained;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = OSReturnsRetainedSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FunctionDecl>(D) && !isa<ObjCMethodDecl>(D) && !isa<ObjCPropertyDecl>(D) && !isa<ParmVarDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "functions, Objective-C methods, Objective-C properties, and parameters";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_function, /*IsSupported=*/true));
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_objc_method, /*IsSupported=*/LangOpts.ObjC));
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_objc_property, /*IsSupported=*/LangOpts.ObjC));
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_variable_is_parameter, /*IsSupported=*/true));
}

static const ParsedAttrInfoOSReturnsRetained Instance;
};
const ParsedAttrInfoOSReturnsRetained ParsedAttrInfoOSReturnsRetained::Instance;
static constexpr ParsedAttrInfo::Spelling OSReturnsRetainedOnNonZeroSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "os_returns_retained_on_non_zero"},
  {AttributeCommonInfo::AS_CXX11, "clang::os_returns_retained_on_non_zero"},
  {AttributeCommonInfo::AS_C2x, "clang::os_returns_retained_on_non_zero"},
};
struct ParsedAttrInfoOSReturnsRetainedOnNonZero final : public ParsedAttrInfo {
  ParsedAttrInfoOSReturnsRetainedOnNonZero() {
    AttrKind = ParsedAttr::AT_OSReturnsRetainedOnNonZero;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = OSReturnsRetainedOnNonZeroSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<ParmVarDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "parameters";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_variable_is_parameter, /*IsSupported=*/true));
}

static const ParsedAttrInfoOSReturnsRetainedOnNonZero Instance;
};
const ParsedAttrInfoOSReturnsRetainedOnNonZero ParsedAttrInfoOSReturnsRetainedOnNonZero::Instance;
static constexpr ParsedAttrInfo::Spelling OSReturnsRetainedOnZeroSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "os_returns_retained_on_zero"},
  {AttributeCommonInfo::AS_CXX11, "clang::os_returns_retained_on_zero"},
  {AttributeCommonInfo::AS_C2x, "clang::os_returns_retained_on_zero"},
};
struct ParsedAttrInfoOSReturnsRetainedOnZero final : public ParsedAttrInfo {
  ParsedAttrInfoOSReturnsRetainedOnZero() {
    AttrKind = ParsedAttr::AT_OSReturnsRetainedOnZero;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = OSReturnsRetainedOnZeroSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<ParmVarDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "parameters";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_variable_is_parameter, /*IsSupported=*/true));
}

static const ParsedAttrInfoOSReturnsRetainedOnZero Instance;
};
const ParsedAttrInfoOSReturnsRetainedOnZero ParsedAttrInfoOSReturnsRetainedOnZero::Instance;
static constexpr ParsedAttrInfo::Spelling ObjCBoxableSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "objc_boxable"},
  {AttributeCommonInfo::AS_CXX11, "clang::objc_boxable"},
  {AttributeCommonInfo::AS_C2x, "clang::objc_boxable"},
};
struct ParsedAttrInfoObjCBoxable final : public ParsedAttrInfo {
  ParsedAttrInfoObjCBoxable() {
    AttrKind = ParsedAttr::AT_ObjCBoxable;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = ObjCBoxableSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<RecordDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::err_attribute_wrong_decl_type_str)
      << Attr << "structs, unions, and classes";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_record, /*IsSupported=*/true));
}

static const ParsedAttrInfoObjCBoxable Instance;
};
const ParsedAttrInfoObjCBoxable ParsedAttrInfoObjCBoxable::Instance;
static constexpr ParsedAttrInfo::Spelling ObjCBridgeSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "objc_bridge"},
  {AttributeCommonInfo::AS_CXX11, "clang::objc_bridge"},
  {AttributeCommonInfo::AS_C2x, "clang::objc_bridge"},
};
static constexpr const char *ObjCBridgeArgNames[] = {
"BridgedType",};
struct ParsedAttrInfoObjCBridge final : public ParsedAttrInfo {
  ParsedAttrInfoObjCBridge() {
    AttrKind = ParsedAttr::AT_ObjCBridge;
    NumArgs = 1;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = ObjCBridgeSpellings;
    ArgNames = ObjCBridgeArgNames;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<RecordDecl>(D) && !isa<TypedefNameDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::err_attribute_wrong_decl_type_str)
      << Attr << "structs, unions, classes, and typedefs";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_record, /*IsSupported=*/true));
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_type_alias, /*IsSupported=*/true));
}

static const ParsedAttrInfoObjCBridge Instance;
};
const ParsedAttrInfoObjCBridge ParsedAttrInfoObjCBridge::Instance;
static constexpr ParsedAttrInfo::Spelling ObjCBridgeMutableSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "objc_bridge_mutable"},
  {AttributeCommonInfo::AS_CXX11, "clang::objc_bridge_mutable"},
  {AttributeCommonInfo::AS_C2x, "clang::objc_bridge_mutable"},
};
static constexpr const char *ObjCBridgeMutableArgNames[] = {
"BridgedType",};
struct ParsedAttrInfoObjCBridgeMutable final : public ParsedAttrInfo {
  ParsedAttrInfoObjCBridgeMutable() {
    AttrKind = ParsedAttr::AT_ObjCBridgeMutable;
    NumArgs = 1;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = ObjCBridgeMutableSpellings;
    ArgNames = ObjCBridgeMutableArgNames;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<RecordDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::err_attribute_wrong_decl_type_str)
      << Attr << "structs, unions, and classes";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_record, /*IsSupported=*/true));
}

static const ParsedAttrInfoObjCBridgeMutable Instance;
};
const ParsedAttrInfoObjCBridgeMutable ParsedAttrInfoObjCBridgeMutable::Instance;
static constexpr ParsedAttrInfo::Spelling ObjCBridgeRelatedSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "objc_bridge_related"},
  {AttributeCommonInfo::AS_CXX11, "clang::objc_bridge_related"},
  {AttributeCommonInfo::AS_C2x, "clang::objc_bridge_related"},
};
static constexpr const char *ObjCBridgeRelatedArgNames[] = {
"RelatedClass","ClassMethod","InstanceMethod",};
struct ParsedAttrInfoObjCBridgeRelated final : public ParsedAttrInfo {
  ParsedAttrInfoObjCBridgeRelated() {
    AttrKind = ParsedAttr::AT_ObjCBridgeRelated;
    NumArgs = 3;
    OptArgs = 0;
    HasCustomParsing = 1;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = ObjCBridgeRelatedSpellings;
    ArgNames = ObjCBridgeRelatedArgNames;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<RecordDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::err_attribute_wrong_decl_type_str)
      << Attr << "structs, unions, and classes";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_record, /*IsSupported=*/true));
}

static const ParsedAttrInfoObjCBridgeRelated Instance;
};
const ParsedAttrInfoObjCBridgeRelated ParsedAttrInfoObjCBridgeRelated::Instance;
static constexpr ParsedAttrInfo::Spelling ObjCClassStubSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "objc_class_stub"},
  {AttributeCommonInfo::AS_CXX11, "clang::objc_class_stub"},
  {AttributeCommonInfo::AS_C2x, "clang::objc_class_stub"},
};
struct ParsedAttrInfoObjCClassStub final : public ParsedAttrInfo {
  ParsedAttrInfoObjCClassStub() {
    AttrKind = ParsedAttr::AT_ObjCClassStub;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = ObjCClassStubSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<ObjCInterfaceDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::err_attribute_wrong_decl_type_str)
      << Attr << "Objective-C interfaces";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

bool acceptsLangOpts(const LangOptions &LangOpts) const override {
  return (LangOpts.ObjCRuntime.allowsClassStubs());
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_objc_interface, /*IsSupported=*/LangOpts.ObjC));
}

AttrHandling handleDeclAttribute(Sema &S, Decl *D,const ParsedAttr &Attr) const override {
  D->addAttr(::new (S.Context) ObjCClassStubAttr(S.Context, Attr));
  return AttributeApplied;
}

static const ParsedAttrInfoObjCClassStub Instance;
};
const ParsedAttrInfoObjCClassStub ParsedAttrInfoObjCClassStub::Instance;
static constexpr ParsedAttrInfo::Spelling ObjCDesignatedInitializerSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "objc_designated_initializer"},
  {AttributeCommonInfo::AS_CXX11, "clang::objc_designated_initializer"},
  {AttributeCommonInfo::AS_C2x, "clang::objc_designated_initializer"},
};
struct ParsedAttrInfoObjCDesignatedInitializer final : public ParsedAttrInfo {
  ParsedAttrInfoObjCDesignatedInitializer() {
    AttrKind = ParsedAttr::AT_ObjCDesignatedInitializer;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = ObjCDesignatedInitializerSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<ObjCMethodDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::err_attribute_wrong_decl_type_str)
      << Attr << "Objective-C methods";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_objc_method, /*IsSupported=*/LangOpts.ObjC));
}

static const ParsedAttrInfoObjCDesignatedInitializer Instance;
};
const ParsedAttrInfoObjCDesignatedInitializer ParsedAttrInfoObjCDesignatedInitializer::Instance;
static constexpr ParsedAttrInfo::Spelling ObjCDirectSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "objc_direct"},
  {AttributeCommonInfo::AS_CXX11, "clang::objc_direct"},
  {AttributeCommonInfo::AS_C2x, "clang::objc_direct"},
};
struct ParsedAttrInfoObjCDirect final : public ParsedAttrInfo {
  ParsedAttrInfoObjCDirect() {
    AttrKind = ParsedAttr::AT_ObjCDirect;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = ObjCDirectSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<ObjCMethodDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::err_attribute_wrong_decl_type_str)
      << Attr << "Objective-C methods";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

bool acceptsLangOpts(const LangOptions &LangOpts) const override {
  return LangOpts.ObjC;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_objc_method, /*IsSupported=*/LangOpts.ObjC));
}

static const ParsedAttrInfoObjCDirect Instance;
};
const ParsedAttrInfoObjCDirect ParsedAttrInfoObjCDirect::Instance;
static constexpr ParsedAttrInfo::Spelling ObjCDirectMembersSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "objc_direct_members"},
  {AttributeCommonInfo::AS_CXX11, "clang::objc_direct_members"},
  {AttributeCommonInfo::AS_C2x, "clang::objc_direct_members"},
};
struct ParsedAttrInfoObjCDirectMembers final : public ParsedAttrInfo {
  ParsedAttrInfoObjCDirectMembers() {
    AttrKind = ParsedAttr::AT_ObjCDirectMembers;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = ObjCDirectMembersSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<ObjCImplDecl>(D) && !isa<ObjCInterfaceDecl>(D) && !isa<ObjCCategoryDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::err_attribute_wrong_decl_type_str)
      << Attr << "Objective-C implementation declarations, Objective-C interfaces, and Objective-C containers";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

bool acceptsLangOpts(const LangOptions &LangOpts) const override {
  return LangOpts.ObjC;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_objc_implementation, /*IsSupported=*/LangOpts.ObjC));
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_objc_interface, /*IsSupported=*/LangOpts.ObjC));
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_objc_category, /*IsSupported=*/LangOpts.ObjC));
}

static const ParsedAttrInfoObjCDirectMembers Instance;
};
const ParsedAttrInfoObjCDirectMembers ParsedAttrInfoObjCDirectMembers::Instance;
static constexpr ParsedAttrInfo::Spelling ObjCExceptionSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "objc_exception"},
  {AttributeCommonInfo::AS_CXX11, "clang::objc_exception"},
  {AttributeCommonInfo::AS_C2x, "clang::objc_exception"},
};
struct ParsedAttrInfoObjCException final : public ParsedAttrInfo {
  ParsedAttrInfoObjCException() {
    AttrKind = ParsedAttr::AT_ObjCException;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = ObjCExceptionSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<ObjCInterfaceDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::err_attribute_wrong_decl_type_str)
      << Attr << "Objective-C interfaces";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_objc_interface, /*IsSupported=*/LangOpts.ObjC));
}

AttrHandling handleDeclAttribute(Sema &S, Decl *D,const ParsedAttr &Attr) const override {
  D->addAttr(::new (S.Context) ObjCExceptionAttr(S.Context, Attr));
  return AttributeApplied;
}

static const ParsedAttrInfoObjCException Instance;
};
const ParsedAttrInfoObjCException ParsedAttrInfoObjCException::Instance;
static constexpr ParsedAttrInfo::Spelling ObjCExplicitProtocolImplSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "objc_protocol_requires_explicit_implementation"},
  {AttributeCommonInfo::AS_CXX11, "clang::objc_protocol_requires_explicit_implementation"},
  {AttributeCommonInfo::AS_C2x, "clang::objc_protocol_requires_explicit_implementation"},
};
struct ParsedAttrInfoObjCExplicitProtocolImpl final : public ParsedAttrInfo {
  ParsedAttrInfoObjCExplicitProtocolImpl() {
    AttrKind = ParsedAttr::AT_ObjCExplicitProtocolImpl;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = ObjCExplicitProtocolImplSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<ObjCProtocolDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::err_attribute_wrong_decl_type_str)
      << Attr << "Objective-C protocols";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_objc_protocol, /*IsSupported=*/LangOpts.ObjC));
}

static const ParsedAttrInfoObjCExplicitProtocolImpl Instance;
};
const ParsedAttrInfoObjCExplicitProtocolImpl ParsedAttrInfoObjCExplicitProtocolImpl::Instance;
static constexpr ParsedAttrInfo::Spelling ObjCExternallyRetainedSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "objc_externally_retained"},
  {AttributeCommonInfo::AS_CXX11, "clang::objc_externally_retained"},
  {AttributeCommonInfo::AS_C2x, "clang::objc_externally_retained"},
};
struct ParsedAttrInfoObjCExternallyRetained final : public ParsedAttrInfo {
  ParsedAttrInfoObjCExternallyRetained() {
    AttrKind = ParsedAttr::AT_ObjCExternallyRetained;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = ObjCExternallyRetainedSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isNonParmVar(D) && !isa<FunctionDecl>(D) && !isa<BlockDecl>(D) && !isa<ObjCMethodDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "variables, functions, blocks, and Objective-C methods";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

bool acceptsLangOpts(const LangOptions &LangOpts) const override {
  return LangOpts.ObjCAutoRefCount;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_variable_not_is_parameter, /*IsSupported=*/true));
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_function, /*IsSupported=*/true));
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_block, /*IsSupported=*/LangOpts.Blocks));
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_objc_method, /*IsSupported=*/LangOpts.ObjC));
}

static const ParsedAttrInfoObjCExternallyRetained Instance;
};
const ParsedAttrInfoObjCExternallyRetained ParsedAttrInfoObjCExternallyRetained::Instance;
static constexpr ParsedAttrInfo::Spelling ObjCGCSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "objc_gc"},
  {AttributeCommonInfo::AS_CXX11, "clang::objc_gc"},
  {AttributeCommonInfo::AS_C2x, "clang::objc_gc"},
};
static constexpr const char *ObjCGCArgNames[] = {
"Kind",};
struct ParsedAttrInfoObjCGC final : public ParsedAttrInfo {
  ParsedAttrInfoObjCGC() {
    AttrKind = ParsedAttr::AT_ObjCGC;
    NumArgs = 1;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 1;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 0;
    Spellings = ObjCGCSpellings;
    ArgNames = ObjCGCArgNames;
  }
static const ParsedAttrInfoObjCGC Instance;
};
const ParsedAttrInfoObjCGC ParsedAttrInfoObjCGC::Instance;
static constexpr ParsedAttrInfo::Spelling ObjCIndependentClassSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "objc_independent_class"},
  {AttributeCommonInfo::AS_CXX11, "clang::objc_independent_class"},
  {AttributeCommonInfo::AS_C2x, "clang::objc_independent_class"},
};
struct ParsedAttrInfoObjCIndependentClass final : public ParsedAttrInfo {
  ParsedAttrInfoObjCIndependentClass() {
    AttrKind = ParsedAttr::AT_ObjCIndependentClass;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 0;
    Spellings = ObjCIndependentClassSpellings;
  }
static const ParsedAttrInfoObjCIndependentClass Instance;
};
const ParsedAttrInfoObjCIndependentClass ParsedAttrInfoObjCIndependentClass::Instance;
static constexpr ParsedAttrInfo::Spelling ObjCInertUnsafeUnretainedSpellings[] = {
  {AttributeCommonInfo::AS_Keyword, "__unsafe_unretained"},
};
struct ParsedAttrInfoObjCInertUnsafeUnretained final : public ParsedAttrInfo {
  ParsedAttrInfoObjCInertUnsafeUnretained() {
    AttrKind = ParsedAttr::AT_ObjCInertUnsafeUnretained;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 1;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 0;
    Spellings = ObjCInertUnsafeUnretainedSpellings;
  }
static const ParsedAttrInfoObjCInertUnsafeUnretained Instance;
};
const ParsedAttrInfoObjCInertUnsafeUnretained ParsedAttrInfoObjCInertUnsafeUnretained::Instance;
static constexpr ParsedAttrInfo::Spelling ObjCKindOfSpellings[] = {
  {AttributeCommonInfo::AS_Keyword, "__kindof"},
};
struct ParsedAttrInfoObjCKindOf final : public ParsedAttrInfo {
  ParsedAttrInfoObjCKindOf() {
    AttrKind = ParsedAttr::AT_ObjCKindOf;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 1;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 0;
    Spellings = ObjCKindOfSpellings;
  }
static const ParsedAttrInfoObjCKindOf Instance;
};
const ParsedAttrInfoObjCKindOf ParsedAttrInfoObjCKindOf::Instance;
static constexpr ParsedAttrInfo::Spelling ObjCMethodFamilySpellings[] = {
  {AttributeCommonInfo::AS_GNU, "objc_method_family"},
  {AttributeCommonInfo::AS_CXX11, "clang::objc_method_family"},
  {AttributeCommonInfo::AS_C2x, "clang::objc_method_family"},
};
static constexpr const char *ObjCMethodFamilyArgNames[] = {
"Family",};
struct ParsedAttrInfoObjCMethodFamily final : public ParsedAttrInfo {
  ParsedAttrInfoObjCMethodFamily() {
    AttrKind = ParsedAttr::AT_ObjCMethodFamily;
    NumArgs = 1;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = ObjCMethodFamilySpellings;
    ArgNames = ObjCMethodFamilyArgNames;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<ObjCMethodDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::err_attribute_wrong_decl_type_str)
      << Attr << "Objective-C methods";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_objc_method, /*IsSupported=*/LangOpts.ObjC));
}

static const ParsedAttrInfoObjCMethodFamily Instance;
};
const ParsedAttrInfoObjCMethodFamily ParsedAttrInfoObjCMethodFamily::Instance;
static constexpr ParsedAttrInfo::Spelling ObjCNSObjectSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "NSObject"},
  {AttributeCommonInfo::AS_CXX11, "clang::NSObject"},
  {AttributeCommonInfo::AS_C2x, "clang::NSObject"},
};
struct ParsedAttrInfoObjCNSObject final : public ParsedAttrInfo {
  ParsedAttrInfoObjCNSObject() {
    AttrKind = ParsedAttr::AT_ObjCNSObject;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 0;
    Spellings = ObjCNSObjectSpellings;
  }
static const ParsedAttrInfoObjCNSObject Instance;
};
const ParsedAttrInfoObjCNSObject ParsedAttrInfoObjCNSObject::Instance;
static constexpr ParsedAttrInfo::Spelling ObjCNonLazyClassSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "objc_nonlazy_class"},
  {AttributeCommonInfo::AS_CXX11, "clang::objc_nonlazy_class"},
  {AttributeCommonInfo::AS_C2x, "clang::objc_nonlazy_class"},
};
struct ParsedAttrInfoObjCNonLazyClass final : public ParsedAttrInfo {
  ParsedAttrInfoObjCNonLazyClass() {
    AttrKind = ParsedAttr::AT_ObjCNonLazyClass;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = ObjCNonLazyClassSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<ObjCInterfaceDecl>(D) && !isa<ObjCImplDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::err_attribute_wrong_decl_type_str)
      << Attr << "Objective-C interfaces and Objective-C implementation declarations";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

bool acceptsLangOpts(const LangOptions &LangOpts) const override {
  return LangOpts.ObjC;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_objc_interface, /*IsSupported=*/LangOpts.ObjC));
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_objc_implementation, /*IsSupported=*/LangOpts.ObjC));
}

AttrHandling handleDeclAttribute(Sema &S, Decl *D,const ParsedAttr &Attr) const override {
  D->addAttr(::new (S.Context) ObjCNonLazyClassAttr(S.Context, Attr));
  return AttributeApplied;
}

static const ParsedAttrInfoObjCNonLazyClass Instance;
};
const ParsedAttrInfoObjCNonLazyClass ParsedAttrInfoObjCNonLazyClass::Instance;
static constexpr ParsedAttrInfo::Spelling ObjCNonRuntimeProtocolSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "objc_non_runtime_protocol"},
  {AttributeCommonInfo::AS_CXX11, "clang::objc_non_runtime_protocol"},
  {AttributeCommonInfo::AS_C2x, "clang::objc_non_runtime_protocol"},
};
struct ParsedAttrInfoObjCNonRuntimeProtocol final : public ParsedAttrInfo {
  ParsedAttrInfoObjCNonRuntimeProtocol() {
    AttrKind = ParsedAttr::AT_ObjCNonRuntimeProtocol;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = ObjCNonRuntimeProtocolSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<ObjCProtocolDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::err_attribute_wrong_decl_type_str)
      << Attr << "Objective-C protocols";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

bool acceptsLangOpts(const LangOptions &LangOpts) const override {
  return LangOpts.ObjC;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_objc_protocol, /*IsSupported=*/LangOpts.ObjC));
}

AttrHandling handleDeclAttribute(Sema &S, Decl *D,const ParsedAttr &Attr) const override {
  D->addAttr(::new (S.Context) ObjCNonRuntimeProtocolAttr(S.Context, Attr));
  return AttributeApplied;
}

static const ParsedAttrInfoObjCNonRuntimeProtocol Instance;
};
const ParsedAttrInfoObjCNonRuntimeProtocol ParsedAttrInfoObjCNonRuntimeProtocol::Instance;
static constexpr ParsedAttrInfo::Spelling ObjCOwnershipSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "objc_ownership"},
  {AttributeCommonInfo::AS_CXX11, "clang::objc_ownership"},
  {AttributeCommonInfo::AS_C2x, "clang::objc_ownership"},
};
static constexpr const char *ObjCOwnershipArgNames[] = {
"Kind",};
struct ParsedAttrInfoObjCOwnership final : public ParsedAttrInfo {
  ParsedAttrInfoObjCOwnership() {
    AttrKind = ParsedAttr::AT_ObjCOwnership;
    NumArgs = 1;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 1;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 0;
    Spellings = ObjCOwnershipSpellings;
    ArgNames = ObjCOwnershipArgNames;
  }
static const ParsedAttrInfoObjCOwnership Instance;
};
const ParsedAttrInfoObjCOwnership ParsedAttrInfoObjCOwnership::Instance;
static constexpr ParsedAttrInfo::Spelling ObjCPreciseLifetimeSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "objc_precise_lifetime"},
  {AttributeCommonInfo::AS_CXX11, "clang::objc_precise_lifetime"},
  {AttributeCommonInfo::AS_C2x, "clang::objc_precise_lifetime"},
};
struct ParsedAttrInfoObjCPreciseLifetime final : public ParsedAttrInfo {
  ParsedAttrInfoObjCPreciseLifetime() {
    AttrKind = ParsedAttr::AT_ObjCPreciseLifetime;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = ObjCPreciseLifetimeSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<VarDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::err_attribute_wrong_decl_type_str)
      << Attr << "variables";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_variable, /*IsSupported=*/true));
}

static const ParsedAttrInfoObjCPreciseLifetime Instance;
};
const ParsedAttrInfoObjCPreciseLifetime ParsedAttrInfoObjCPreciseLifetime::Instance;
static constexpr ParsedAttrInfo::Spelling ObjCRequiresPropertyDefsSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "objc_requires_property_definitions"},
  {AttributeCommonInfo::AS_CXX11, "clang::objc_requires_property_definitions"},
  {AttributeCommonInfo::AS_C2x, "clang::objc_requires_property_definitions"},
};
struct ParsedAttrInfoObjCRequiresPropertyDefs final : public ParsedAttrInfo {
  ParsedAttrInfoObjCRequiresPropertyDefs() {
    AttrKind = ParsedAttr::AT_ObjCRequiresPropertyDefs;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = ObjCRequiresPropertyDefsSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<ObjCInterfaceDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::err_attribute_wrong_decl_type_str)
      << Attr << "Objective-C interfaces";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_objc_interface, /*IsSupported=*/LangOpts.ObjC));
}

AttrHandling handleDeclAttribute(Sema &S, Decl *D,const ParsedAttr &Attr) const override {
  D->addAttr(::new (S.Context) ObjCRequiresPropertyDefsAttr(S.Context, Attr));
  return AttributeApplied;
}

static const ParsedAttrInfoObjCRequiresPropertyDefs Instance;
};
const ParsedAttrInfoObjCRequiresPropertyDefs ParsedAttrInfoObjCRequiresPropertyDefs::Instance;
static constexpr ParsedAttrInfo::Spelling ObjCRequiresSuperSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "objc_requires_super"},
  {AttributeCommonInfo::AS_CXX11, "clang::objc_requires_super"},
  {AttributeCommonInfo::AS_C2x, "clang::objc_requires_super"},
};
struct ParsedAttrInfoObjCRequiresSuper final : public ParsedAttrInfo {
  ParsedAttrInfoObjCRequiresSuper() {
    AttrKind = ParsedAttr::AT_ObjCRequiresSuper;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = ObjCRequiresSuperSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<ObjCMethodDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::err_attribute_wrong_decl_type_str)
      << Attr << "Objective-C methods";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_objc_method, /*IsSupported=*/LangOpts.ObjC));
}

static const ParsedAttrInfoObjCRequiresSuper Instance;
};
const ParsedAttrInfoObjCRequiresSuper ParsedAttrInfoObjCRequiresSuper::Instance;
static constexpr ParsedAttrInfo::Spelling ObjCReturnsInnerPointerSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "objc_returns_inner_pointer"},
  {AttributeCommonInfo::AS_CXX11, "clang::objc_returns_inner_pointer"},
  {AttributeCommonInfo::AS_C2x, "clang::objc_returns_inner_pointer"},
};
struct ParsedAttrInfoObjCReturnsInnerPointer final : public ParsedAttrInfo {
  ParsedAttrInfoObjCReturnsInnerPointer() {
    AttrKind = ParsedAttr::AT_ObjCReturnsInnerPointer;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = ObjCReturnsInnerPointerSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<ObjCMethodDecl>(D) && !isa<ObjCPropertyDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::err_attribute_wrong_decl_type_str)
      << Attr << "Objective-C methods and Objective-C properties";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_objc_method, /*IsSupported=*/LangOpts.ObjC));
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_objc_property, /*IsSupported=*/LangOpts.ObjC));
}

static const ParsedAttrInfoObjCReturnsInnerPointer Instance;
};
const ParsedAttrInfoObjCReturnsInnerPointer ParsedAttrInfoObjCReturnsInnerPointer::Instance;
static constexpr ParsedAttrInfo::Spelling ObjCRootClassSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "objc_root_class"},
  {AttributeCommonInfo::AS_CXX11, "clang::objc_root_class"},
  {AttributeCommonInfo::AS_C2x, "clang::objc_root_class"},
};
struct ParsedAttrInfoObjCRootClass final : public ParsedAttrInfo {
  ParsedAttrInfoObjCRootClass() {
    AttrKind = ParsedAttr::AT_ObjCRootClass;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = ObjCRootClassSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<ObjCInterfaceDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::err_attribute_wrong_decl_type_str)
      << Attr << "Objective-C interfaces";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_objc_interface, /*IsSupported=*/LangOpts.ObjC));
}

AttrHandling handleDeclAttribute(Sema &S, Decl *D,const ParsedAttr &Attr) const override {
  D->addAttr(::new (S.Context) ObjCRootClassAttr(S.Context, Attr));
  return AttributeApplied;
}

static const ParsedAttrInfoObjCRootClass Instance;
};
const ParsedAttrInfoObjCRootClass ParsedAttrInfoObjCRootClass::Instance;
static constexpr ParsedAttrInfo::Spelling ObjCRuntimeNameSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "objc_runtime_name"},
  {AttributeCommonInfo::AS_CXX11, "clang::objc_runtime_name"},
  {AttributeCommonInfo::AS_C2x, "clang::objc_runtime_name"},
};
static constexpr const char *ObjCRuntimeNameArgNames[] = {
"MetadataName",};
struct ParsedAttrInfoObjCRuntimeName final : public ParsedAttrInfo {
  ParsedAttrInfoObjCRuntimeName() {
    AttrKind = ParsedAttr::AT_ObjCRuntimeName;
    NumArgs = 1;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = ObjCRuntimeNameSpellings;
    ArgNames = ObjCRuntimeNameArgNames;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<ObjCInterfaceDecl>(D) && !isa<ObjCProtocolDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::err_attribute_wrong_decl_type_str)
      << Attr << "Objective-C interfaces and Objective-C protocols";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_objc_interface, /*IsSupported=*/LangOpts.ObjC));
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_objc_protocol, /*IsSupported=*/LangOpts.ObjC));
}

static const ParsedAttrInfoObjCRuntimeName Instance;
};
const ParsedAttrInfoObjCRuntimeName ParsedAttrInfoObjCRuntimeName::Instance;
static constexpr ParsedAttrInfo::Spelling ObjCRuntimeVisibleSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "objc_runtime_visible"},
  {AttributeCommonInfo::AS_CXX11, "clang::objc_runtime_visible"},
  {AttributeCommonInfo::AS_C2x, "clang::objc_runtime_visible"},
};
struct ParsedAttrInfoObjCRuntimeVisible final : public ParsedAttrInfo {
  ParsedAttrInfoObjCRuntimeVisible() {
    AttrKind = ParsedAttr::AT_ObjCRuntimeVisible;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = ObjCRuntimeVisibleSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<ObjCInterfaceDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::err_attribute_wrong_decl_type_str)
      << Attr << "Objective-C interfaces";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_objc_interface, /*IsSupported=*/LangOpts.ObjC));
}

AttrHandling handleDeclAttribute(Sema &S, Decl *D,const ParsedAttr &Attr) const override {
  D->addAttr(::new (S.Context) ObjCRuntimeVisibleAttr(S.Context, Attr));
  return AttributeApplied;
}

static const ParsedAttrInfoObjCRuntimeVisible Instance;
};
const ParsedAttrInfoObjCRuntimeVisible ParsedAttrInfoObjCRuntimeVisible::Instance;
static constexpr ParsedAttrInfo::Spelling ObjCSubclassingRestrictedSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "objc_subclassing_restricted"},
  {AttributeCommonInfo::AS_CXX11, "clang::objc_subclassing_restricted"},
  {AttributeCommonInfo::AS_C2x, "clang::objc_subclassing_restricted"},
};
struct ParsedAttrInfoObjCSubclassingRestricted final : public ParsedAttrInfo {
  ParsedAttrInfoObjCSubclassingRestricted() {
    AttrKind = ParsedAttr::AT_ObjCSubclassingRestricted;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = ObjCSubclassingRestrictedSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<ObjCInterfaceDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::err_attribute_wrong_decl_type_str)
      << Attr << "Objective-C interfaces";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_objc_interface, /*IsSupported=*/LangOpts.ObjC));
}

AttrHandling handleDeclAttribute(Sema &S, Decl *D,const ParsedAttr &Attr) const override {
  D->addAttr(::new (S.Context) ObjCSubclassingRestrictedAttr(S.Context, Attr));
  return AttributeApplied;
}

static const ParsedAttrInfoObjCSubclassingRestricted Instance;
};
const ParsedAttrInfoObjCSubclassingRestricted ParsedAttrInfoObjCSubclassingRestricted::Instance;
static constexpr ParsedAttrInfo::Spelling OpenCLAccessSpellings[] = {
  {AttributeCommonInfo::AS_Keyword, "__read_only"},
  {AttributeCommonInfo::AS_Keyword, "read_only"},
  {AttributeCommonInfo::AS_Keyword, "__write_only"},
  {AttributeCommonInfo::AS_Keyword, "write_only"},
  {AttributeCommonInfo::AS_Keyword, "__read_write"},
  {AttributeCommonInfo::AS_Keyword, "read_write"},
};
struct ParsedAttrInfoOpenCLAccess final : public ParsedAttrInfo {
  ParsedAttrInfoOpenCLAccess() {
    AttrKind = ParsedAttr::AT_OpenCLAccess;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 0;
    Spellings = OpenCLAccessSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<ParmVarDecl>(D) && !isa<TypedefNameDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::err_attribute_wrong_decl_type_str)
      << Attr << "parameters and typedefs";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

unsigned spellingIndexToSemanticSpelling(const ParsedAttr &Attr) const override {
  enum Spelling {
    Keyword_read_only = 0,
    Keyword_write_only = 2,
    Keyword_read_write = 4,
  SpellingNotCalculated = 15

  };

  unsigned Idx = Attr.getAttributeSpellingListIndex();
  switch (Idx) {
    default: llvm_unreachable("Unknown spelling list index");
    case 0: return Keyword_read_only;
    case 1: return Keyword_read_only;
    case 2: return Keyword_write_only;
    case 3: return Keyword_write_only;
    case 4: return Keyword_read_write;
    case 5: return Keyword_read_write;
  }
}

static const ParsedAttrInfoOpenCLAccess Instance;
};
const ParsedAttrInfoOpenCLAccess ParsedAttrInfoOpenCLAccess::Instance;
static constexpr ParsedAttrInfo::Spelling OpenCLConstantAddressSpaceSpellings[] = {
  {AttributeCommonInfo::AS_Keyword, "__constant"},
  {AttributeCommonInfo::AS_Keyword, "constant"},
  {AttributeCommonInfo::AS_GNU, "opencl_constant"},
  {AttributeCommonInfo::AS_CXX11, "clang::opencl_constant"},
  {AttributeCommonInfo::AS_C2x, "clang::opencl_constant"},
};
struct ParsedAttrInfoOpenCLConstantAddressSpace final : public ParsedAttrInfo {
  ParsedAttrInfoOpenCLConstantAddressSpace() {
    AttrKind = ParsedAttr::AT_OpenCLConstantAddressSpace;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 1;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 0;
    Spellings = OpenCLConstantAddressSpaceSpellings;
  }
unsigned spellingIndexToSemanticSpelling(const ParsedAttr &Attr) const override {
  enum Spelling {
    Keyword_constant = 0,
    GNU_opencl_constant = 2,
    CXX11_clang_opencl_constant = 3,
    C2x_clang_opencl_constant = 4,
  SpellingNotCalculated = 15

  };

  unsigned Idx = Attr.getAttributeSpellingListIndex();
  switch (Idx) {
    default: llvm_unreachable("Unknown spelling list index");
    case 0: return Keyword_constant;
    case 1: return Keyword_constant;
    case 2: return GNU_opencl_constant;
    case 3: return CXX11_clang_opencl_constant;
    case 4: return C2x_clang_opencl_constant;
  }
}

static const ParsedAttrInfoOpenCLConstantAddressSpace Instance;
};
const ParsedAttrInfoOpenCLConstantAddressSpace ParsedAttrInfoOpenCLConstantAddressSpace::Instance;
static constexpr ParsedAttrInfo::Spelling OpenCLGenericAddressSpaceSpellings[] = {
  {AttributeCommonInfo::AS_Keyword, "__generic"},
  {AttributeCommonInfo::AS_Keyword, "generic"},
  {AttributeCommonInfo::AS_GNU, "opencl_generic"},
  {AttributeCommonInfo::AS_CXX11, "clang::opencl_generic"},
  {AttributeCommonInfo::AS_C2x, "clang::opencl_generic"},
};
struct ParsedAttrInfoOpenCLGenericAddressSpace final : public ParsedAttrInfo {
  ParsedAttrInfoOpenCLGenericAddressSpace() {
    AttrKind = ParsedAttr::AT_OpenCLGenericAddressSpace;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 1;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 0;
    Spellings = OpenCLGenericAddressSpaceSpellings;
  }
unsigned spellingIndexToSemanticSpelling(const ParsedAttr &Attr) const override {
  enum Spelling {
    Keyword_generic = 0,
    GNU_opencl_generic = 2,
    CXX11_clang_opencl_generic = 3,
    C2x_clang_opencl_generic = 4,
  SpellingNotCalculated = 15

  };

  unsigned Idx = Attr.getAttributeSpellingListIndex();
  switch (Idx) {
    default: llvm_unreachable("Unknown spelling list index");
    case 0: return Keyword_generic;
    case 1: return Keyword_generic;
    case 2: return GNU_opencl_generic;
    case 3: return CXX11_clang_opencl_generic;
    case 4: return C2x_clang_opencl_generic;
  }
}

static const ParsedAttrInfoOpenCLGenericAddressSpace Instance;
};
const ParsedAttrInfoOpenCLGenericAddressSpace ParsedAttrInfoOpenCLGenericAddressSpace::Instance;
static constexpr ParsedAttrInfo::Spelling OpenCLGlobalAddressSpaceSpellings[] = {
  {AttributeCommonInfo::AS_Keyword, "__global"},
  {AttributeCommonInfo::AS_Keyword, "global"},
  {AttributeCommonInfo::AS_GNU, "opencl_global"},
  {AttributeCommonInfo::AS_CXX11, "clang::opencl_global"},
  {AttributeCommonInfo::AS_C2x, "clang::opencl_global"},
};
struct ParsedAttrInfoOpenCLGlobalAddressSpace final : public ParsedAttrInfo {
  ParsedAttrInfoOpenCLGlobalAddressSpace() {
    AttrKind = ParsedAttr::AT_OpenCLGlobalAddressSpace;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 1;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 0;
    Spellings = OpenCLGlobalAddressSpaceSpellings;
  }
unsigned spellingIndexToSemanticSpelling(const ParsedAttr &Attr) const override {
  enum Spelling {
    Keyword_global = 0,
    GNU_opencl_global = 2,
    CXX11_clang_opencl_global = 3,
    C2x_clang_opencl_global = 4,
  SpellingNotCalculated = 15

  };

  unsigned Idx = Attr.getAttributeSpellingListIndex();
  switch (Idx) {
    default: llvm_unreachable("Unknown spelling list index");
    case 0: return Keyword_global;
    case 1: return Keyword_global;
    case 2: return GNU_opencl_global;
    case 3: return CXX11_clang_opencl_global;
    case 4: return C2x_clang_opencl_global;
  }
}

static const ParsedAttrInfoOpenCLGlobalAddressSpace Instance;
};
const ParsedAttrInfoOpenCLGlobalAddressSpace ParsedAttrInfoOpenCLGlobalAddressSpace::Instance;
static constexpr ParsedAttrInfo::Spelling OpenCLGlobalDeviceAddressSpaceSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "opencl_global_device"},
  {AttributeCommonInfo::AS_CXX11, "clang::opencl_global_device"},
  {AttributeCommonInfo::AS_C2x, "clang::opencl_global_device"},
};
struct ParsedAttrInfoOpenCLGlobalDeviceAddressSpace final : public ParsedAttrInfo {
  ParsedAttrInfoOpenCLGlobalDeviceAddressSpace() {
    AttrKind = ParsedAttr::AT_OpenCLGlobalDeviceAddressSpace;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 1;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 0;
    Spellings = OpenCLGlobalDeviceAddressSpaceSpellings;
  }
static const ParsedAttrInfoOpenCLGlobalDeviceAddressSpace Instance;
};
const ParsedAttrInfoOpenCLGlobalDeviceAddressSpace ParsedAttrInfoOpenCLGlobalDeviceAddressSpace::Instance;
static constexpr ParsedAttrInfo::Spelling OpenCLGlobalHostAddressSpaceSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "opencl_global_host"},
  {AttributeCommonInfo::AS_CXX11, "clang::opencl_global_host"},
  {AttributeCommonInfo::AS_C2x, "clang::opencl_global_host"},
};
struct ParsedAttrInfoOpenCLGlobalHostAddressSpace final : public ParsedAttrInfo {
  ParsedAttrInfoOpenCLGlobalHostAddressSpace() {
    AttrKind = ParsedAttr::AT_OpenCLGlobalHostAddressSpace;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 1;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 0;
    Spellings = OpenCLGlobalHostAddressSpaceSpellings;
  }
static const ParsedAttrInfoOpenCLGlobalHostAddressSpace Instance;
};
const ParsedAttrInfoOpenCLGlobalHostAddressSpace ParsedAttrInfoOpenCLGlobalHostAddressSpace::Instance;
static constexpr ParsedAttrInfo::Spelling OpenCLIntelReqdSubGroupSizeSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "intel_reqd_sub_group_size"},
};
static constexpr const char *OpenCLIntelReqdSubGroupSizeArgNames[] = {
"SubGroupSize",};
struct ParsedAttrInfoOpenCLIntelReqdSubGroupSize final : public ParsedAttrInfo {
  ParsedAttrInfoOpenCLIntelReqdSubGroupSize() {
    AttrKind = ParsedAttr::AT_OpenCLIntelReqdSubGroupSize;
    NumArgs = 1;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = OpenCLIntelReqdSubGroupSizeSpellings;
    ArgNames = OpenCLIntelReqdSubGroupSizeArgNames;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FunctionDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::err_attribute_wrong_decl_type_str)
      << Attr << "functions";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_function, /*IsSupported=*/true));
}

static const ParsedAttrInfoOpenCLIntelReqdSubGroupSize Instance;
};
const ParsedAttrInfoOpenCLIntelReqdSubGroupSize ParsedAttrInfoOpenCLIntelReqdSubGroupSize::Instance;
static constexpr ParsedAttrInfo::Spelling OpenCLKernelSpellings[] = {
  {AttributeCommonInfo::AS_Keyword, "__kernel"},
  {AttributeCommonInfo::AS_Keyword, "kernel"},
};
struct ParsedAttrInfoOpenCLKernel final : public ParsedAttrInfo {
  ParsedAttrInfoOpenCLKernel() {
    AttrKind = ParsedAttr::AT_OpenCLKernel;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 0;
    Spellings = OpenCLKernelSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FunctionDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::err_attribute_wrong_decl_type_str)
      << Attr << "functions";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

AttrHandling handleDeclAttribute(Sema &S, Decl *D,const ParsedAttr &Attr) const override {
  D->addAttr(::new (S.Context) OpenCLKernelAttr(S.Context, Attr));
  return AttributeApplied;
}

static const ParsedAttrInfoOpenCLKernel Instance;
};
const ParsedAttrInfoOpenCLKernel ParsedAttrInfoOpenCLKernel::Instance;
static constexpr ParsedAttrInfo::Spelling OpenCLLocalAddressSpaceSpellings[] = {
  {AttributeCommonInfo::AS_Keyword, "__local"},
  {AttributeCommonInfo::AS_Keyword, "local"},
  {AttributeCommonInfo::AS_GNU, "opencl_local"},
  {AttributeCommonInfo::AS_CXX11, "clang::opencl_local"},
  {AttributeCommonInfo::AS_C2x, "clang::opencl_local"},
};
struct ParsedAttrInfoOpenCLLocalAddressSpace final : public ParsedAttrInfo {
  ParsedAttrInfoOpenCLLocalAddressSpace() {
    AttrKind = ParsedAttr::AT_OpenCLLocalAddressSpace;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 1;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 0;
    Spellings = OpenCLLocalAddressSpaceSpellings;
  }
unsigned spellingIndexToSemanticSpelling(const ParsedAttr &Attr) const override {
  enum Spelling {
    Keyword_local = 0,
    GNU_opencl_local = 2,
    CXX11_clang_opencl_local = 3,
    C2x_clang_opencl_local = 4,
  SpellingNotCalculated = 15

  };

  unsigned Idx = Attr.getAttributeSpellingListIndex();
  switch (Idx) {
    default: llvm_unreachable("Unknown spelling list index");
    case 0: return Keyword_local;
    case 1: return Keyword_local;
    case 2: return GNU_opencl_local;
    case 3: return CXX11_clang_opencl_local;
    case 4: return C2x_clang_opencl_local;
  }
}

static const ParsedAttrInfoOpenCLLocalAddressSpace Instance;
};
const ParsedAttrInfoOpenCLLocalAddressSpace ParsedAttrInfoOpenCLLocalAddressSpace::Instance;
static constexpr ParsedAttrInfo::Spelling OpenCLNoSVMSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "nosvm"},
};
struct ParsedAttrInfoOpenCLNoSVM final : public ParsedAttrInfo {
  ParsedAttrInfoOpenCLNoSVM() {
    AttrKind = ParsedAttr::AT_OpenCLNoSVM;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = OpenCLNoSVMSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<VarDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "variables";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

bool acceptsLangOpts(const LangOptions &LangOpts) const override {
  return LangOpts.OpenCL;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_variable, /*IsSupported=*/true));
}

static const ParsedAttrInfoOpenCLNoSVM Instance;
};
const ParsedAttrInfoOpenCLNoSVM ParsedAttrInfoOpenCLNoSVM::Instance;
static constexpr ParsedAttrInfo::Spelling OpenCLPrivateAddressSpaceSpellings[] = {
  {AttributeCommonInfo::AS_Keyword, "__private"},
  {AttributeCommonInfo::AS_Keyword, "private"},
  {AttributeCommonInfo::AS_GNU, "opencl_private"},
  {AttributeCommonInfo::AS_CXX11, "clang::opencl_private"},
  {AttributeCommonInfo::AS_C2x, "clang::opencl_private"},
};
struct ParsedAttrInfoOpenCLPrivateAddressSpace final : public ParsedAttrInfo {
  ParsedAttrInfoOpenCLPrivateAddressSpace() {
    AttrKind = ParsedAttr::AT_OpenCLPrivateAddressSpace;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 1;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 0;
    Spellings = OpenCLPrivateAddressSpaceSpellings;
  }
unsigned spellingIndexToSemanticSpelling(const ParsedAttr &Attr) const override {
  enum Spelling {
    Keyword_private = 0,
    GNU_opencl_private = 2,
    CXX11_clang_opencl_private = 3,
    C2x_clang_opencl_private = 4,
  SpellingNotCalculated = 15

  };

  unsigned Idx = Attr.getAttributeSpellingListIndex();
  switch (Idx) {
    default: llvm_unreachable("Unknown spelling list index");
    case 0: return Keyword_private;
    case 1: return Keyword_private;
    case 2: return GNU_opencl_private;
    case 3: return CXX11_clang_opencl_private;
    case 4: return C2x_clang_opencl_private;
  }
}

static const ParsedAttrInfoOpenCLPrivateAddressSpace Instance;
};
const ParsedAttrInfoOpenCLPrivateAddressSpace ParsedAttrInfoOpenCLPrivateAddressSpace::Instance;
static constexpr ParsedAttrInfo::Spelling OpenCLUnrollHintSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "opencl_unroll_hint"},
};
static constexpr const char *OpenCLUnrollHintArgNames[] = {
"UnrollHint",};
struct ParsedAttrInfoOpenCLUnrollHint final : public ParsedAttrInfo {
  ParsedAttrInfoOpenCLUnrollHint() {
    AttrKind = ParsedAttr::AT_OpenCLUnrollHint;
    NumArgs = 0;
    OptArgs = 1;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 1;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 0;
    Spellings = OpenCLUnrollHintSpellings;
    ArgNames = OpenCLUnrollHintArgNames;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &AL, const Decl *D) const override {
  S.Diag(AL.getLoc(), diag::err_stmt_attribute_invalid_on_decl)
    << AL << D->getLocation();
  return false;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &Attr, const Stmt *St) const override {
  if (!isa<ForStmt>(St) && !isa<CXXForRangeStmt>(St) && !isa<WhileStmt>(St) && !isa<DoStmt>(St)) {
    S.Diag(Attr.getLoc(), diag::err_attribute_wrong_decl_type_str)
      << Attr << "'for', 'while', and 'do' statements";
    return false;
  }
  return true;
}

static const ParsedAttrInfoOpenCLUnrollHint Instance;
};
const ParsedAttrInfoOpenCLUnrollHint ParsedAttrInfoOpenCLUnrollHint::Instance;
static constexpr ParsedAttrInfo::Spelling OptimizeNoneSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "optnone"},
  {AttributeCommonInfo::AS_CXX11, "clang::optnone"},
  {AttributeCommonInfo::AS_C2x, "clang::optnone"},
};
struct ParsedAttrInfoOptimizeNone final : public ParsedAttrInfo {
  ParsedAttrInfoOptimizeNone() {
    AttrKind = ParsedAttr::AT_OptimizeNone;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = OptimizeNoneSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FunctionDecl>(D) && !isa<ObjCMethodDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "functions and Objective-C methods";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_function, /*IsSupported=*/true));
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_objc_method, /*IsSupported=*/LangOpts.ObjC));
}

static const ParsedAttrInfoOptimizeNone Instance;
};
const ParsedAttrInfoOptimizeNone ParsedAttrInfoOptimizeNone::Instance;
static constexpr ParsedAttrInfo::Spelling OverloadableSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "overloadable"},
  {AttributeCommonInfo::AS_CXX11, "clang::overloadable"},
  {AttributeCommonInfo::AS_C2x, "clang::overloadable"},
};
struct ParsedAttrInfoOverloadable final : public ParsedAttrInfo {
  ParsedAttrInfoOverloadable() {
    AttrKind = ParsedAttr::AT_Overloadable;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = OverloadableSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FunctionDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::err_attribute_wrong_decl_type_str)
      << Attr << "functions";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_function, /*IsSupported=*/true));
}

AttrHandling handleDeclAttribute(Sema &S, Decl *D,const ParsedAttr &Attr) const override {
  D->addAttr(::new (S.Context) OverloadableAttr(S.Context, Attr));
  return AttributeApplied;
}

static const ParsedAttrInfoOverloadable Instance;
};
const ParsedAttrInfoOverloadable ParsedAttrInfoOverloadable::Instance;
static constexpr ParsedAttrInfo::Spelling OwnerSpellings[] = {
  {AttributeCommonInfo::AS_CXX11, "gsl::Owner"},
};
static constexpr const char *OwnerArgNames[] = {
"DerefType",};
struct ParsedAttrInfoOwner final : public ParsedAttrInfo {
  ParsedAttrInfoOwner() {
    AttrKind = ParsedAttr::AT_Owner;
    NumArgs = 0;
    OptArgs = 1;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = OwnerSpellings;
    ArgNames = OwnerArgNames;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isStruct(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "structs";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

  using ParsedAttrInfo::diagMutualExclusion;

  bool diagMutualExclusion(Sema &S, const ParsedAttr &AL, const Decl *D) const override {
    if (const auto *A = D->getAttr<PointerAttr>()) {
      S.Diag(AL.getLoc(), diag::err_attributes_are_not_compatible) << AL << A;
      S.Diag(A->getLocation(), diag::note_conflicting_attribute);      
return false;
    }
    return true;
  }

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_record_not_is_union, /*IsSupported=*/true));
}

static const ParsedAttrInfoOwner Instance;
};
const ParsedAttrInfoOwner ParsedAttrInfoOwner::Instance;
static constexpr ParsedAttrInfo::Spelling OwnershipSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "ownership_holds"},
  {AttributeCommonInfo::AS_CXX11, "clang::ownership_holds"},
  {AttributeCommonInfo::AS_C2x, "clang::ownership_holds"},
  {AttributeCommonInfo::AS_GNU, "ownership_returns"},
  {AttributeCommonInfo::AS_CXX11, "clang::ownership_returns"},
  {AttributeCommonInfo::AS_C2x, "clang::ownership_returns"},
  {AttributeCommonInfo::AS_GNU, "ownership_takes"},
  {AttributeCommonInfo::AS_CXX11, "clang::ownership_takes"},
  {AttributeCommonInfo::AS_C2x, "clang::ownership_takes"},
};
static constexpr const char *OwnershipArgNames[] = {
"Module","Args...",};
struct ParsedAttrInfoOwnership final : public ParsedAttrInfo {
  ParsedAttrInfoOwnership() {
    AttrKind = ParsedAttr::AT_Ownership;
    NumArgs = 1;
    OptArgs = 15;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 0;
    Spellings = OwnershipSpellings;
    ArgNames = OwnershipArgNames;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isHasFunctionProto(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "non-K&R-style functions";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

unsigned spellingIndexToSemanticSpelling(const ParsedAttr &Attr) const override {
  enum Spelling {
    GNU_ownership_holds = 0,
    CXX11_clang_ownership_holds = 1,
    C2x_clang_ownership_holds = 2,
    GNU_ownership_returns = 3,
    CXX11_clang_ownership_returns = 4,
    C2x_clang_ownership_returns = 5,
    GNU_ownership_takes = 6,
    CXX11_clang_ownership_takes = 7,
    C2x_clang_ownership_takes = 8,
  SpellingNotCalculated = 15

  };

  unsigned Idx = Attr.getAttributeSpellingListIndex();
  switch (Idx) {
    default: llvm_unreachable("Unknown spelling list index");
    case 0: return GNU_ownership_holds;
    case 1: return CXX11_clang_ownership_holds;
    case 2: return C2x_clang_ownership_holds;
    case 3: return GNU_ownership_returns;
    case 4: return CXX11_clang_ownership_returns;
    case 5: return C2x_clang_ownership_returns;
    case 6: return GNU_ownership_takes;
    case 7: return CXX11_clang_ownership_takes;
    case 8: return C2x_clang_ownership_takes;
  }
}

static const ParsedAttrInfoOwnership Instance;
};
const ParsedAttrInfoOwnership ParsedAttrInfoOwnership::Instance;
static constexpr ParsedAttrInfo::Spelling PackedSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "packed"},
  {AttributeCommonInfo::AS_CXX11, "gnu::packed"},
  {AttributeCommonInfo::AS_C2x, "gnu::packed"},
};
struct ParsedAttrInfoPacked final : public ParsedAttrInfo {
  ParsedAttrInfoPacked() {
    AttrKind = ParsedAttr::AT_Packed;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 1;
    IsSupportedByPragmaAttribute = 0;
    Spellings = PackedSpellings;
  }
static const ParsedAttrInfoPacked Instance;
};
const ParsedAttrInfoPacked ParsedAttrInfoPacked::Instance;
static constexpr ParsedAttrInfo::Spelling ParamTypestateSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "param_typestate"},
  {AttributeCommonInfo::AS_CXX11, "clang::param_typestate"},
};
static constexpr const char *ParamTypestateArgNames[] = {
"ParamState",};
struct ParsedAttrInfoParamTypestate final : public ParsedAttrInfo {
  ParsedAttrInfoParamTypestate() {
    AttrKind = ParsedAttr::AT_ParamTypestate;
    NumArgs = 1;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = ParamTypestateSpellings;
    ArgNames = ParamTypestateArgNames;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<ParmVarDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "parameters";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_variable_is_parameter, /*IsSupported=*/true));
}

static const ParsedAttrInfoParamTypestate Instance;
};
const ParsedAttrInfoParamTypestate ParsedAttrInfoParamTypestate::Instance;
static constexpr ParsedAttrInfo::Spelling PascalSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "pascal"},
  {AttributeCommonInfo::AS_CXX11, "clang::pascal"},
  {AttributeCommonInfo::AS_C2x, "clang::pascal"},
  {AttributeCommonInfo::AS_Keyword, "__pascal"},
  {AttributeCommonInfo::AS_Keyword, "_pascal"},
};
struct ParsedAttrInfoPascal final : public ParsedAttrInfo {
  ParsedAttrInfoPascal() {
    AttrKind = ParsedAttr::AT_Pascal;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 1;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 0;
    Spellings = PascalSpellings;
  }
static const ParsedAttrInfoPascal Instance;
};
const ParsedAttrInfoPascal ParsedAttrInfoPascal::Instance;
static constexpr ParsedAttrInfo::Spelling PassObjectSizeSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "pass_object_size"},
  {AttributeCommonInfo::AS_CXX11, "clang::pass_object_size"},
  {AttributeCommonInfo::AS_C2x, "clang::pass_object_size"},
  {AttributeCommonInfo::AS_GNU, "pass_dynamic_object_size"},
  {AttributeCommonInfo::AS_CXX11, "clang::pass_dynamic_object_size"},
  {AttributeCommonInfo::AS_C2x, "clang::pass_dynamic_object_size"},
};
static constexpr const char *PassObjectSizeArgNames[] = {
"Type",};
struct ParsedAttrInfoPassObjectSize final : public ParsedAttrInfo {
  ParsedAttrInfoPassObjectSize() {
    AttrKind = ParsedAttr::AT_PassObjectSize;
    NumArgs = 1;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = PassObjectSizeSpellings;
    ArgNames = PassObjectSizeArgNames;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<ParmVarDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "parameters";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

unsigned spellingIndexToSemanticSpelling(const ParsedAttr &Attr) const override {
  enum Spelling {
    GNU_pass_object_size = 0,
    CXX11_clang_pass_object_size = 1,
    C2x_clang_pass_object_size = 2,
    GNU_pass_dynamic_object_size = 3,
    CXX11_clang_pass_dynamic_object_size = 4,
    C2x_clang_pass_dynamic_object_size = 5,
  SpellingNotCalculated = 15

  };

  unsigned Idx = Attr.getAttributeSpellingListIndex();
  switch (Idx) {
    default: llvm_unreachable("Unknown spelling list index");
    case 0: return GNU_pass_object_size;
    case 1: return CXX11_clang_pass_object_size;
    case 2: return C2x_clang_pass_object_size;
    case 3: return GNU_pass_dynamic_object_size;
    case 4: return CXX11_clang_pass_dynamic_object_size;
    case 5: return C2x_clang_pass_dynamic_object_size;
  }
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_variable_is_parameter, /*IsSupported=*/true));
}

static const ParsedAttrInfoPassObjectSize Instance;
};
const ParsedAttrInfoPassObjectSize ParsedAttrInfoPassObjectSize::Instance;
static constexpr ParsedAttrInfo::Spelling PatchableFunctionEntrySpellings[] = {
  {AttributeCommonInfo::AS_GNU, "patchable_function_entry"},
  {AttributeCommonInfo::AS_CXX11, "gnu::patchable_function_entry"},
  {AttributeCommonInfo::AS_C2x, "gnu::patchable_function_entry"},
};
static constexpr const char *PatchableFunctionEntryArgNames[] = {
"Count","Offset",};
struct ParsedAttrInfoPatchableFunctionEntry final : public ParsedAttrInfo {
  ParsedAttrInfoPatchableFunctionEntry() {
    AttrKind = ParsedAttr::AT_PatchableFunctionEntry;
    NumArgs = 1;
    OptArgs = 1;
    HasCustomParsing = 0;
    IsTargetSpecific = 1;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 1;
    IsSupportedByPragmaAttribute = 1;
    Spellings = PatchableFunctionEntrySpellings;
    ArgNames = PatchableFunctionEntryArgNames;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FunctionDecl>(D) && !isa<ObjCMethodDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "functions and Objective-C methods";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

bool existsInTarget(const TargetInfo &Target) const override {
  const llvm::Triple &T = Target.getTriple(); (void)T;
  return true && (T.getArch() == llvm::Triple::aarch64 || T.getArch() == llvm::Triple::aarch64_be || T.getArch() == llvm::Triple::riscv32 || T.getArch() == llvm::Triple::riscv64 || T.getArch() == llvm::Triple::x86 || T.getArch() == llvm::Triple::x86_64);
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_function, /*IsSupported=*/true));
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_objc_method, /*IsSupported=*/LangOpts.ObjC));
}

static const ParsedAttrInfoPatchableFunctionEntry Instance;
};
const ParsedAttrInfoPatchableFunctionEntry ParsedAttrInfoPatchableFunctionEntry::Instance;
static constexpr ParsedAttrInfo::Spelling PcsSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "pcs"},
  {AttributeCommonInfo::AS_CXX11, "gnu::pcs"},
  {AttributeCommonInfo::AS_C2x, "gnu::pcs"},
};
static constexpr const char *PcsArgNames[] = {
"PCS",};
struct ParsedAttrInfoPcs final : public ParsedAttrInfo {
  ParsedAttrInfoPcs() {
    AttrKind = ParsedAttr::AT_Pcs;
    NumArgs = 1;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 1;
    IsStmt = 0;
    IsKnownToGCC = 1;
    IsSupportedByPragmaAttribute = 0;
    Spellings = PcsSpellings;
    ArgNames = PcsArgNames;
  }
static const ParsedAttrInfoPcs Instance;
};
const ParsedAttrInfoPcs ParsedAttrInfoPcs::Instance;
static constexpr ParsedAttrInfo::Spelling PointerSpellings[] = {
  {AttributeCommonInfo::AS_CXX11, "gsl::Pointer"},
};
static constexpr const char *PointerArgNames[] = {
"DerefType",};
struct ParsedAttrInfoPointer final : public ParsedAttrInfo {
  ParsedAttrInfoPointer() {
    AttrKind = ParsedAttr::AT_Pointer;
    NumArgs = 0;
    OptArgs = 1;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = PointerSpellings;
    ArgNames = PointerArgNames;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isStruct(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "structs";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

  using ParsedAttrInfo::diagMutualExclusion;

  bool diagMutualExclusion(Sema &S, const ParsedAttr &AL, const Decl *D) const override {
    if (const auto *A = D->getAttr<OwnerAttr>()) {
      S.Diag(AL.getLoc(), diag::err_attributes_are_not_compatible) << AL << A;
      S.Diag(A->getLocation(), diag::note_conflicting_attribute);      
return false;
    }
    return true;
  }

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_record_not_is_union, /*IsSupported=*/true));
}

static const ParsedAttrInfoPointer Instance;
};
const ParsedAttrInfoPointer ParsedAttrInfoPointer::Instance;
static constexpr const char *PragmaClangBSSSectionArgNames[] = {
"Name",};
struct ParsedAttrInfoPragmaClangBSSSection final : public ParsedAttrInfo {
  ParsedAttrInfoPragmaClangBSSSection() {
    AttrKind = ParsedAttr::AT_PragmaClangBSSSection;
    NumArgs = 1;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 0;
    ArgNames = PragmaClangBSSSectionArgNames;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isGlobalVar(D)) {
    S.Diag(Attr.getLoc(), diag::err_attribute_wrong_decl_type_str)
      << Attr << "global variables";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

static const ParsedAttrInfoPragmaClangBSSSection Instance;
};
const ParsedAttrInfoPragmaClangBSSSection ParsedAttrInfoPragmaClangBSSSection::Instance;
static constexpr const char *PragmaClangDataSectionArgNames[] = {
"Name",};
struct ParsedAttrInfoPragmaClangDataSection final : public ParsedAttrInfo {
  ParsedAttrInfoPragmaClangDataSection() {
    AttrKind = ParsedAttr::AT_PragmaClangDataSection;
    NumArgs = 1;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 0;
    ArgNames = PragmaClangDataSectionArgNames;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isGlobalVar(D)) {
    S.Diag(Attr.getLoc(), diag::err_attribute_wrong_decl_type_str)
      << Attr << "global variables";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

static const ParsedAttrInfoPragmaClangDataSection Instance;
};
const ParsedAttrInfoPragmaClangDataSection ParsedAttrInfoPragmaClangDataSection::Instance;
static constexpr const char *PragmaClangRelroSectionArgNames[] = {
"Name",};
struct ParsedAttrInfoPragmaClangRelroSection final : public ParsedAttrInfo {
  ParsedAttrInfoPragmaClangRelroSection() {
    AttrKind = ParsedAttr::AT_PragmaClangRelroSection;
    NumArgs = 1;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 0;
    ArgNames = PragmaClangRelroSectionArgNames;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isGlobalVar(D)) {
    S.Diag(Attr.getLoc(), diag::err_attribute_wrong_decl_type_str)
      << Attr << "global variables";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

static const ParsedAttrInfoPragmaClangRelroSection Instance;
};
const ParsedAttrInfoPragmaClangRelroSection ParsedAttrInfoPragmaClangRelroSection::Instance;
static constexpr const char *PragmaClangRodataSectionArgNames[] = {
"Name",};
struct ParsedAttrInfoPragmaClangRodataSection final : public ParsedAttrInfo {
  ParsedAttrInfoPragmaClangRodataSection() {
    AttrKind = ParsedAttr::AT_PragmaClangRodataSection;
    NumArgs = 1;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 0;
    ArgNames = PragmaClangRodataSectionArgNames;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isGlobalVar(D)) {
    S.Diag(Attr.getLoc(), diag::err_attribute_wrong_decl_type_str)
      << Attr << "global variables";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

static const ParsedAttrInfoPragmaClangRodataSection Instance;
};
const ParsedAttrInfoPragmaClangRodataSection ParsedAttrInfoPragmaClangRodataSection::Instance;
static constexpr const char *PragmaClangTextSectionArgNames[] = {
"Name",};
struct ParsedAttrInfoPragmaClangTextSection final : public ParsedAttrInfo {
  ParsedAttrInfoPragmaClangTextSection() {
    AttrKind = ParsedAttr::AT_PragmaClangTextSection;
    NumArgs = 1;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 0;
    ArgNames = PragmaClangTextSectionArgNames;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FunctionDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::err_attribute_wrong_decl_type_str)
      << Attr << "functions";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

static const ParsedAttrInfoPragmaClangTextSection Instance;
};
const ParsedAttrInfoPragmaClangTextSection ParsedAttrInfoPragmaClangTextSection::Instance;
static constexpr ParsedAttrInfo::Spelling PreferredNameSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "preferred_name"},
  {AttributeCommonInfo::AS_CXX11, "clang::preferred_name"},
};
static constexpr const char *PreferredNameArgNames[] = {
"TypedefType",};
struct ParsedAttrInfoPreferredName final : public ParsedAttrInfo {
  ParsedAttrInfoPreferredName() {
    AttrKind = ParsedAttr::AT_PreferredName;
    NumArgs = 1;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 0;
    Spellings = PreferredNameSpellings;
    ArgNames = PreferredNameArgNames;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isClassTmpl(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "class templates";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

static const ParsedAttrInfoPreferredName Instance;
};
const ParsedAttrInfoPreferredName ParsedAttrInfoPreferredName::Instance;
static constexpr ParsedAttrInfo::Spelling PreserveAllSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "preserve_all"},
  {AttributeCommonInfo::AS_CXX11, "clang::preserve_all"},
  {AttributeCommonInfo::AS_C2x, "clang::preserve_all"},
};
struct ParsedAttrInfoPreserveAll final : public ParsedAttrInfo {
  ParsedAttrInfoPreserveAll() {
    AttrKind = ParsedAttr::AT_PreserveAll;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 1;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 0;
    Spellings = PreserveAllSpellings;
  }
static const ParsedAttrInfoPreserveAll Instance;
};
const ParsedAttrInfoPreserveAll ParsedAttrInfoPreserveAll::Instance;
static constexpr ParsedAttrInfo::Spelling PreserveMostSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "preserve_most"},
  {AttributeCommonInfo::AS_CXX11, "clang::preserve_most"},
  {AttributeCommonInfo::AS_C2x, "clang::preserve_most"},
};
struct ParsedAttrInfoPreserveMost final : public ParsedAttrInfo {
  ParsedAttrInfoPreserveMost() {
    AttrKind = ParsedAttr::AT_PreserveMost;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 1;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 0;
    Spellings = PreserveMostSpellings;
  }
static const ParsedAttrInfoPreserveMost Instance;
};
const ParsedAttrInfoPreserveMost ParsedAttrInfoPreserveMost::Instance;
static constexpr ParsedAttrInfo::Spelling PtGuardedBySpellings[] = {
  {AttributeCommonInfo::AS_GNU, "pt_guarded_by"},
};
static constexpr const char *PtGuardedByArgNames[] = {
"Arg",};
struct ParsedAttrInfoPtGuardedBy final : public ParsedAttrInfo {
  ParsedAttrInfoPtGuardedBy() {
    AttrKind = ParsedAttr::AT_PtGuardedBy;
    NumArgs = 1;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 0;
    Spellings = PtGuardedBySpellings;
    ArgNames = PtGuardedByArgNames;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FieldDecl>(D) && !isSharedVar(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "non-static data members and global variables";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

static const ParsedAttrInfoPtGuardedBy Instance;
};
const ParsedAttrInfoPtGuardedBy ParsedAttrInfoPtGuardedBy::Instance;
static constexpr ParsedAttrInfo::Spelling PtGuardedVarSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "pt_guarded_var"},
  {AttributeCommonInfo::AS_CXX11, "clang::pt_guarded_var"},
};
struct ParsedAttrInfoPtGuardedVar final : public ParsedAttrInfo {
  ParsedAttrInfoPtGuardedVar() {
    AttrKind = ParsedAttr::AT_PtGuardedVar;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 0;
    Spellings = PtGuardedVarSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FieldDecl>(D) && !isSharedVar(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "non-static data members and global variables";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

static const ParsedAttrInfoPtGuardedVar Instance;
};
const ParsedAttrInfoPtGuardedVar ParsedAttrInfoPtGuardedVar::Instance;
static constexpr ParsedAttrInfo::Spelling Ptr32Spellings[] = {
  {AttributeCommonInfo::AS_Keyword, "__ptr32"},
};
struct ParsedAttrInfoPtr32 final : public ParsedAttrInfo {
  ParsedAttrInfoPtr32() {
    AttrKind = ParsedAttr::AT_Ptr32;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 1;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 0;
    Spellings = Ptr32Spellings;
  }
static const ParsedAttrInfoPtr32 Instance;
};
const ParsedAttrInfoPtr32 ParsedAttrInfoPtr32::Instance;
static constexpr ParsedAttrInfo::Spelling Ptr64Spellings[] = {
  {AttributeCommonInfo::AS_Keyword, "__ptr64"},
};
struct ParsedAttrInfoPtr64 final : public ParsedAttrInfo {
  ParsedAttrInfoPtr64() {
    AttrKind = ParsedAttr::AT_Ptr64;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 1;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 0;
    Spellings = Ptr64Spellings;
  }
static const ParsedAttrInfoPtr64 Instance;
};
const ParsedAttrInfoPtr64 ParsedAttrInfoPtr64::Instance;
static constexpr ParsedAttrInfo::Spelling PureSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "pure"},
  {AttributeCommonInfo::AS_CXX11, "gnu::pure"},
  {AttributeCommonInfo::AS_C2x, "gnu::pure"},
};
struct ParsedAttrInfoPure final : public ParsedAttrInfo {
  ParsedAttrInfoPure() {
    AttrKind = ParsedAttr::AT_Pure;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 1;
    IsSupportedByPragmaAttribute = 0;
    Spellings = PureSpellings;
  }
AttrHandling handleDeclAttribute(Sema &S, Decl *D,const ParsedAttr &Attr) const override {
  D->addAttr(::new (S.Context) PureAttr(S.Context, Attr));
  return AttributeApplied;
}

static const ParsedAttrInfoPure Instance;
};
const ParsedAttrInfoPure ParsedAttrInfoPure::Instance;
static constexpr ParsedAttrInfo::Spelling RegCallSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "regcall"},
  {AttributeCommonInfo::AS_CXX11, "gnu::regcall"},
  {AttributeCommonInfo::AS_C2x, "gnu::regcall"},
  {AttributeCommonInfo::AS_Keyword, "__regcall"},
};
struct ParsedAttrInfoRegCall final : public ParsedAttrInfo {
  ParsedAttrInfoRegCall() {
    AttrKind = ParsedAttr::AT_RegCall;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 1;
    IsStmt = 0;
    IsKnownToGCC = 1;
    IsSupportedByPragmaAttribute = 0;
    Spellings = RegCallSpellings;
  }
static const ParsedAttrInfoRegCall Instance;
};
const ParsedAttrInfoRegCall ParsedAttrInfoRegCall::Instance;
static constexpr ParsedAttrInfo::Spelling RegparmSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "regparm"},
  {AttributeCommonInfo::AS_CXX11, "gnu::regparm"},
  {AttributeCommonInfo::AS_C2x, "gnu::regparm"},
};
static constexpr const char *RegparmArgNames[] = {
"NumParams",};
struct ParsedAttrInfoRegparm final : public ParsedAttrInfo {
  ParsedAttrInfoRegparm() {
    AttrKind = ParsedAttr::AT_Regparm;
    NumArgs = 1;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 1;
    IsStmt = 0;
    IsKnownToGCC = 1;
    IsSupportedByPragmaAttribute = 0;
    Spellings = RegparmSpellings;
    ArgNames = RegparmArgNames;
  }
static const ParsedAttrInfoRegparm Instance;
};
const ParsedAttrInfoRegparm ParsedAttrInfoRegparm::Instance;
static constexpr ParsedAttrInfo::Spelling ReinitializesSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "reinitializes"},
  {AttributeCommonInfo::AS_CXX11, "clang::reinitializes"},
};
struct ParsedAttrInfoReinitializes final : public ParsedAttrInfo {
  ParsedAttrInfoReinitializes() {
    AttrKind = ParsedAttr::AT_Reinitializes;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 0;
    Spellings = ReinitializesSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isNonStaticNonConstCXXMethod(D)) {
    S.Diag(Attr.getLoc(), diag::err_attribute_wrong_decl_type_str)
      << Attr << "non-static non-const member functions";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

AttrHandling handleDeclAttribute(Sema &S, Decl *D,const ParsedAttr &Attr) const override {
  D->addAttr(::new (S.Context) ReinitializesAttr(S.Context, Attr));
  return AttributeApplied;
}

static const ParsedAttrInfoReinitializes Instance;
};
const ParsedAttrInfoReinitializes ParsedAttrInfoReinitializes::Instance;
static constexpr ParsedAttrInfo::Spelling ReleaseCapabilitySpellings[] = {
  {AttributeCommonInfo::AS_GNU, "release_capability"},
  {AttributeCommonInfo::AS_CXX11, "clang::release_capability"},
  {AttributeCommonInfo::AS_GNU, "release_shared_capability"},
  {AttributeCommonInfo::AS_CXX11, "clang::release_shared_capability"},
  {AttributeCommonInfo::AS_GNU, "release_generic_capability"},
  {AttributeCommonInfo::AS_CXX11, "clang::release_generic_capability"},
  {AttributeCommonInfo::AS_GNU, "unlock_function"},
  {AttributeCommonInfo::AS_CXX11, "clang::unlock_function"},
};
static constexpr const char *ReleaseCapabilityArgNames[] = {
"Args...",};
struct ParsedAttrInfoReleaseCapability final : public ParsedAttrInfo {
  ParsedAttrInfoReleaseCapability() {
    AttrKind = ParsedAttr::AT_ReleaseCapability;
    NumArgs = 0;
    OptArgs = 15;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 0;
    Spellings = ReleaseCapabilitySpellings;
    ArgNames = ReleaseCapabilityArgNames;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FunctionDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "functions";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

unsigned spellingIndexToSemanticSpelling(const ParsedAttr &Attr) const override {
  enum Spelling {
    GNU_release_capability = 0,
    CXX11_clang_release_capability = 1,
    GNU_release_shared_capability = 2,
    CXX11_clang_release_shared_capability = 3,
    GNU_release_generic_capability = 4,
    CXX11_clang_release_generic_capability = 5,
    GNU_unlock_function = 6,
    CXX11_clang_unlock_function = 7,
  SpellingNotCalculated = 15

  };

  unsigned Idx = Attr.getAttributeSpellingListIndex();
  switch (Idx) {
    default: llvm_unreachable("Unknown spelling list index");
    case 0: return GNU_release_capability;
    case 1: return CXX11_clang_release_capability;
    case 2: return GNU_release_shared_capability;
    case 3: return CXX11_clang_release_shared_capability;
    case 4: return GNU_release_generic_capability;
    case 5: return CXX11_clang_release_generic_capability;
    case 6: return GNU_unlock_function;
    case 7: return CXX11_clang_unlock_function;
  }
}

static const ParsedAttrInfoReleaseCapability Instance;
};
const ParsedAttrInfoReleaseCapability ParsedAttrInfoReleaseCapability::Instance;
static constexpr ParsedAttrInfo::Spelling ReleaseHandleSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "release_handle"},
  {AttributeCommonInfo::AS_CXX11, "clang::release_handle"},
  {AttributeCommonInfo::AS_C2x, "clang::release_handle"},
};
static constexpr const char *ReleaseHandleArgNames[] = {
"HandleType",};
struct ParsedAttrInfoReleaseHandle final : public ParsedAttrInfo {
  ParsedAttrInfoReleaseHandle() {
    AttrKind = ParsedAttr::AT_ReleaseHandle;
    NumArgs = 1;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = ReleaseHandleSpellings;
    ArgNames = ReleaseHandleArgNames;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<ParmVarDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "parameters";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_variable_is_parameter, /*IsSupported=*/true));
}

static const ParsedAttrInfoReleaseHandle Instance;
};
const ParsedAttrInfoReleaseHandle ParsedAttrInfoReleaseHandle::Instance;
static constexpr ParsedAttrInfo::Spelling RenderScriptKernelSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "kernel"},
};
struct ParsedAttrInfoRenderScriptKernel final : public ParsedAttrInfo {
  ParsedAttrInfoRenderScriptKernel() {
    AttrKind = ParsedAttr::AT_RenderScriptKernel;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = RenderScriptKernelSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FunctionDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "functions";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

bool acceptsLangOpts(const LangOptions &LangOpts) const override {
  return LangOpts.RenderScript;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_function, /*IsSupported=*/true));
}

AttrHandling handleDeclAttribute(Sema &S, Decl *D,const ParsedAttr &Attr) const override {
  D->addAttr(::new (S.Context) RenderScriptKernelAttr(S.Context, Attr));
  return AttributeApplied;
}

static const ParsedAttrInfoRenderScriptKernel Instance;
};
const ParsedAttrInfoRenderScriptKernel ParsedAttrInfoRenderScriptKernel::Instance;
static constexpr ParsedAttrInfo::Spelling ReqdWorkGroupSizeSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "reqd_work_group_size"},
};
static constexpr const char *ReqdWorkGroupSizeArgNames[] = {
"XDim","YDim","ZDim",};
struct ParsedAttrInfoReqdWorkGroupSize final : public ParsedAttrInfo {
  ParsedAttrInfoReqdWorkGroupSize() {
    AttrKind = ParsedAttr::AT_ReqdWorkGroupSize;
    NumArgs = 3;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = ReqdWorkGroupSizeSpellings;
    ArgNames = ReqdWorkGroupSizeArgNames;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FunctionDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::err_attribute_wrong_decl_type_str)
      << Attr << "functions";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_function, /*IsSupported=*/true));
}

static const ParsedAttrInfoReqdWorkGroupSize Instance;
};
const ParsedAttrInfoReqdWorkGroupSize ParsedAttrInfoReqdWorkGroupSize::Instance;
static constexpr ParsedAttrInfo::Spelling RequiresCapabilitySpellings[] = {
  {AttributeCommonInfo::AS_GNU, "requires_capability"},
  {AttributeCommonInfo::AS_CXX11, "clang::requires_capability"},
  {AttributeCommonInfo::AS_GNU, "exclusive_locks_required"},
  {AttributeCommonInfo::AS_CXX11, "clang::exclusive_locks_required"},
  {AttributeCommonInfo::AS_GNU, "requires_shared_capability"},
  {AttributeCommonInfo::AS_CXX11, "clang::requires_shared_capability"},
  {AttributeCommonInfo::AS_GNU, "shared_locks_required"},
  {AttributeCommonInfo::AS_CXX11, "clang::shared_locks_required"},
};
static constexpr const char *RequiresCapabilityArgNames[] = {
"Args...",};
struct ParsedAttrInfoRequiresCapability final : public ParsedAttrInfo {
  ParsedAttrInfoRequiresCapability() {
    AttrKind = ParsedAttr::AT_RequiresCapability;
    NumArgs = 0;
    OptArgs = 15;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 0;
    Spellings = RequiresCapabilitySpellings;
    ArgNames = RequiresCapabilityArgNames;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FunctionDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "functions";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

unsigned spellingIndexToSemanticSpelling(const ParsedAttr &Attr) const override {
  enum Spelling {
    GNU_requires_capability = 0,
    CXX11_clang_requires_capability = 1,
    GNU_exclusive_locks_required = 2,
    CXX11_clang_exclusive_locks_required = 3,
    GNU_requires_shared_capability = 4,
    CXX11_clang_requires_shared_capability = 5,
    GNU_shared_locks_required = 6,
    CXX11_clang_shared_locks_required = 7,
  SpellingNotCalculated = 15

  };

  unsigned Idx = Attr.getAttributeSpellingListIndex();
  switch (Idx) {
    default: llvm_unreachable("Unknown spelling list index");
    case 0: return GNU_requires_capability;
    case 1: return CXX11_clang_requires_capability;
    case 2: return GNU_exclusive_locks_required;
    case 3: return CXX11_clang_exclusive_locks_required;
    case 4: return GNU_requires_shared_capability;
    case 5: return CXX11_clang_requires_shared_capability;
    case 6: return GNU_shared_locks_required;
    case 7: return CXX11_clang_shared_locks_required;
  }
}

static const ParsedAttrInfoRequiresCapability Instance;
};
const ParsedAttrInfoRequiresCapability ParsedAttrInfoRequiresCapability::Instance;
static constexpr ParsedAttrInfo::Spelling RestrictSpellings[] = {
  {AttributeCommonInfo::AS_Declspec, "restrict"},
  {AttributeCommonInfo::AS_GNU, "malloc"},
  {AttributeCommonInfo::AS_CXX11, "gnu::malloc"},
  {AttributeCommonInfo::AS_C2x, "gnu::malloc"},
};
struct ParsedAttrInfoRestrict final : public ParsedAttrInfo {
  ParsedAttrInfoRestrict() {
    AttrKind = ParsedAttr::AT_Restrict;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 1;
    IsSupportedByPragmaAttribute = 1;
    Spellings = RestrictSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FunctionDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "functions";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

unsigned spellingIndexToSemanticSpelling(const ParsedAttr &Attr) const override {
  enum Spelling {
    Declspec_restrict = 0,
    GNU_malloc = 1,
    CXX11_gnu_malloc = 2,
    C2x_gnu_malloc = 3,
  SpellingNotCalculated = 15

  };

  unsigned Idx = Attr.getAttributeSpellingListIndex();
  switch (Idx) {
    default: llvm_unreachable("Unknown spelling list index");
    case 0: return Declspec_restrict;
    case 1: return GNU_malloc;
    case 2: return CXX11_gnu_malloc;
    case 3: return C2x_gnu_malloc;
  }
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_function, /*IsSupported=*/true));
}

static const ParsedAttrInfoRestrict Instance;
};
const ParsedAttrInfoRestrict ParsedAttrInfoRestrict::Instance;
static constexpr ParsedAttrInfo::Spelling RetainSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "retain"},
  {AttributeCommonInfo::AS_CXX11, "gnu::retain"},
  {AttributeCommonInfo::AS_C2x, "gnu::retain"},
};
struct ParsedAttrInfoRetain final : public ParsedAttrInfo {
  ParsedAttrInfoRetain() {
    AttrKind = ParsedAttr::AT_Retain;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 1;
    IsSupportedByPragmaAttribute = 0;
    Spellings = RetainSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isNonLocalVar(D) && !isa<FunctionDecl>(D) && !isa<ObjCMethodDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "variables with non-local storage, functions, and Objective-C methods";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

AttrHandling handleDeclAttribute(Sema &S, Decl *D,const ParsedAttr &Attr) const override {
  D->addAttr(::new (S.Context) RetainAttr(S.Context, Attr));
  return AttributeApplied;
}

static const ParsedAttrInfoRetain Instance;
};
const ParsedAttrInfoRetain ParsedAttrInfoRetain::Instance;
static constexpr ParsedAttrInfo::Spelling ReturnTypestateSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "return_typestate"},
  {AttributeCommonInfo::AS_CXX11, "clang::return_typestate"},
};
static constexpr const char *ReturnTypestateArgNames[] = {
"State",};
struct ParsedAttrInfoReturnTypestate final : public ParsedAttrInfo {
  ParsedAttrInfoReturnTypestate() {
    AttrKind = ParsedAttr::AT_ReturnTypestate;
    NumArgs = 1;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = ReturnTypestateSpellings;
    ArgNames = ReturnTypestateArgNames;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FunctionDecl>(D) && !isa<ParmVarDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "functions and parameters";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_function, /*IsSupported=*/true));
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_variable_is_parameter, /*IsSupported=*/true));
}

static const ParsedAttrInfoReturnTypestate Instance;
};
const ParsedAttrInfoReturnTypestate ParsedAttrInfoReturnTypestate::Instance;
static constexpr ParsedAttrInfo::Spelling ReturnsNonNullSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "returns_nonnull"},
  {AttributeCommonInfo::AS_CXX11, "gnu::returns_nonnull"},
  {AttributeCommonInfo::AS_C2x, "gnu::returns_nonnull"},
};
struct ParsedAttrInfoReturnsNonNull final : public ParsedAttrInfo {
  ParsedAttrInfoReturnsNonNull() {
    AttrKind = ParsedAttr::AT_ReturnsNonNull;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 1;
    IsSupportedByPragmaAttribute = 1;
    Spellings = ReturnsNonNullSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<ObjCMethodDecl>(D) && !isa<FunctionDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "Objective-C methods and functions";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_objc_method, /*IsSupported=*/LangOpts.ObjC));
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_function, /*IsSupported=*/true));
}

static const ParsedAttrInfoReturnsNonNull Instance;
};
const ParsedAttrInfoReturnsNonNull ParsedAttrInfoReturnsNonNull::Instance;
static constexpr ParsedAttrInfo::Spelling ReturnsTwiceSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "returns_twice"},
  {AttributeCommonInfo::AS_CXX11, "gnu::returns_twice"},
  {AttributeCommonInfo::AS_C2x, "gnu::returns_twice"},
};
struct ParsedAttrInfoReturnsTwice final : public ParsedAttrInfo {
  ParsedAttrInfoReturnsTwice() {
    AttrKind = ParsedAttr::AT_ReturnsTwice;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 1;
    IsSupportedByPragmaAttribute = 1;
    Spellings = ReturnsTwiceSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FunctionDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "functions";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_function, /*IsSupported=*/true));
}

AttrHandling handleDeclAttribute(Sema &S, Decl *D,const ParsedAttr &Attr) const override {
  D->addAttr(::new (S.Context) ReturnsTwiceAttr(S.Context, Attr));
  return AttributeApplied;
}

static const ParsedAttrInfoReturnsTwice Instance;
};
const ParsedAttrInfoReturnsTwice ParsedAttrInfoReturnsTwice::Instance;
static constexpr ParsedAttrInfo::Spelling SPtrSpellings[] = {
  {AttributeCommonInfo::AS_Keyword, "__sptr"},
};
struct ParsedAttrInfoSPtr final : public ParsedAttrInfo {
  ParsedAttrInfoSPtr() {
    AttrKind = ParsedAttr::AT_SPtr;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 1;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 0;
    Spellings = SPtrSpellings;
  }
static const ParsedAttrInfoSPtr Instance;
};
const ParsedAttrInfoSPtr ParsedAttrInfoSPtr::Instance;
static constexpr ParsedAttrInfo::Spelling SYCLKernelSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "sycl_kernel"},
  {AttributeCommonInfo::AS_CXX11, "clang::sycl_kernel"},
  {AttributeCommonInfo::AS_C2x, "clang::sycl_kernel"},
};
struct ParsedAttrInfoSYCLKernel final : public ParsedAttrInfo {
  ParsedAttrInfoSYCLKernel() {
    AttrKind = ParsedAttr::AT_SYCLKernel;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 0;
    Spellings = SYCLKernelSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isFunctionTmpl(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "function templates";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

bool acceptsLangOpts(const LangOptions &LangOpts) const override {
  return LangOpts.SYCLIsDevice;
}

static const ParsedAttrInfoSYCLKernel Instance;
};
const ParsedAttrInfoSYCLKernel ParsedAttrInfoSYCLKernel::Instance;
static constexpr ParsedAttrInfo::Spelling ScopedLockableSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "scoped_lockable"},
  {AttributeCommonInfo::AS_CXX11, "clang::scoped_lockable"},
};
struct ParsedAttrInfoScopedLockable final : public ParsedAttrInfo {
  ParsedAttrInfoScopedLockable() {
    AttrKind = ParsedAttr::AT_ScopedLockable;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = ScopedLockableSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<RecordDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "structs, unions, and classes";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_record, /*IsSupported=*/true));
}

AttrHandling handleDeclAttribute(Sema &S, Decl *D,const ParsedAttr &Attr) const override {
  D->addAttr(::new (S.Context) ScopedLockableAttr(S.Context, Attr));
  return AttributeApplied;
}

static const ParsedAttrInfoScopedLockable Instance;
};
const ParsedAttrInfoScopedLockable ParsedAttrInfoScopedLockable::Instance;
static constexpr ParsedAttrInfo::Spelling SectionSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "section"},
  {AttributeCommonInfo::AS_CXX11, "gnu::section"},
  {AttributeCommonInfo::AS_C2x, "gnu::section"},
  {AttributeCommonInfo::AS_Declspec, "allocate"},
};
static constexpr const char *SectionArgNames[] = {
"Name",};
struct ParsedAttrInfoSection final : public ParsedAttrInfo {
  ParsedAttrInfoSection() {
    AttrKind = ParsedAttr::AT_Section;
    NumArgs = 1;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 1;
    IsSupportedByPragmaAttribute = 1;
    Spellings = SectionSpellings;
    ArgNames = SectionArgNames;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FunctionDecl>(D) && !isGlobalVar(D) && !isa<ObjCMethodDecl>(D) && !isa<ObjCPropertyDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::err_attribute_wrong_decl_type_str)
      << Attr << "functions, global variables, Objective-C methods, and Objective-C properties";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

unsigned spellingIndexToSemanticSpelling(const ParsedAttr &Attr) const override {
  enum Spelling {
    GNU_section = 0,
    CXX11_gnu_section = 1,
    C2x_gnu_section = 2,
    Declspec_allocate = 3,
  SpellingNotCalculated = 15

  };

  unsigned Idx = Attr.getAttributeSpellingListIndex();
  switch (Idx) {
    default: llvm_unreachable("Unknown spelling list index");
    case 0: return GNU_section;
    case 1: return CXX11_gnu_section;
    case 2: return C2x_gnu_section;
    case 3: return Declspec_allocate;
  }
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_function, /*IsSupported=*/true));
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_variable_is_global, /*IsSupported=*/true));
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_objc_method, /*IsSupported=*/LangOpts.ObjC));
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_objc_property, /*IsSupported=*/LangOpts.ObjC));
}

static const ParsedAttrInfoSection Instance;
};
const ParsedAttrInfoSection ParsedAttrInfoSection::Instance;
static constexpr ParsedAttrInfo::Spelling SelectAnySpellings[] = {
  {AttributeCommonInfo::AS_Declspec, "selectany"},
  {AttributeCommonInfo::AS_GNU, "selectany"},
  {AttributeCommonInfo::AS_CXX11, "gnu::selectany"},
  {AttributeCommonInfo::AS_C2x, "gnu::selectany"},
};
struct ParsedAttrInfoSelectAny final : public ParsedAttrInfo {
  ParsedAttrInfoSelectAny() {
    AttrKind = ParsedAttr::AT_SelectAny;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 1;
    IsSupportedByPragmaAttribute = 0;
    Spellings = SelectAnySpellings;
  }
AttrHandling handleDeclAttribute(Sema &S, Decl *D,const ParsedAttr &Attr) const override {
  D->addAttr(::new (S.Context) SelectAnyAttr(S.Context, Attr));
  return AttributeApplied;
}

static const ParsedAttrInfoSelectAny Instance;
};
const ParsedAttrInfoSelectAny ParsedAttrInfoSelectAny::Instance;
static constexpr ParsedAttrInfo::Spelling SentinelSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "sentinel"},
  {AttributeCommonInfo::AS_CXX11, "gnu::sentinel"},
  {AttributeCommonInfo::AS_C2x, "gnu::sentinel"},
};
static constexpr const char *SentinelArgNames[] = {
"Sentinel","NullPos",};
struct ParsedAttrInfoSentinel final : public ParsedAttrInfo {
  ParsedAttrInfoSentinel() {
    AttrKind = ParsedAttr::AT_Sentinel;
    NumArgs = 0;
    OptArgs = 2;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 1;
    IsSupportedByPragmaAttribute = 0;
    Spellings = SentinelSpellings;
    ArgNames = SentinelArgNames;
  }
static const ParsedAttrInfoSentinel Instance;
};
const ParsedAttrInfoSentinel ParsedAttrInfoSentinel::Instance;
static constexpr ParsedAttrInfo::Spelling SetTypestateSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "set_typestate"},
  {AttributeCommonInfo::AS_CXX11, "clang::set_typestate"},
};
static constexpr const char *SetTypestateArgNames[] = {
"NewState",};
struct ParsedAttrInfoSetTypestate final : public ParsedAttrInfo {
  ParsedAttrInfoSetTypestate() {
    AttrKind = ParsedAttr::AT_SetTypestate;
    NumArgs = 1;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = SetTypestateSpellings;
    ArgNames = SetTypestateArgNames;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<CXXMethodDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "functions";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_function_is_member, /*IsSupported=*/LangOpts.CPlusPlus));
}

static const ParsedAttrInfoSetTypestate Instance;
};
const ParsedAttrInfoSetTypestate ParsedAttrInfoSetTypestate::Instance;
static constexpr ParsedAttrInfo::Spelling SharedTrylockFunctionSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "shared_trylock_function"},
};
static constexpr const char *SharedTrylockFunctionArgNames[] = {
"SuccessValue","Args...",};
struct ParsedAttrInfoSharedTrylockFunction final : public ParsedAttrInfo {
  ParsedAttrInfoSharedTrylockFunction() {
    AttrKind = ParsedAttr::AT_SharedTrylockFunction;
    NumArgs = 1;
    OptArgs = 15;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 0;
    Spellings = SharedTrylockFunctionSpellings;
    ArgNames = SharedTrylockFunctionArgNames;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FunctionDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "functions";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

static const ParsedAttrInfoSharedTrylockFunction Instance;
};
const ParsedAttrInfoSharedTrylockFunction ParsedAttrInfoSharedTrylockFunction::Instance;
static constexpr ParsedAttrInfo::Spelling SpeculativeLoadHardeningSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "speculative_load_hardening"},
  {AttributeCommonInfo::AS_CXX11, "clang::speculative_load_hardening"},
  {AttributeCommonInfo::AS_C2x, "clang::speculative_load_hardening"},
};
struct ParsedAttrInfoSpeculativeLoadHardening final : public ParsedAttrInfo {
  ParsedAttrInfoSpeculativeLoadHardening() {
    AttrKind = ParsedAttr::AT_SpeculativeLoadHardening;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = SpeculativeLoadHardeningSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FunctionDecl>(D) && !isa<ObjCMethodDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::err_attribute_wrong_decl_type_str)
      << Attr << "functions and Objective-C methods";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

  using ParsedAttrInfo::diagMutualExclusion;

  bool diagMutualExclusion(Sema &S, const ParsedAttr &AL, const Decl *D) const override {
    if (const auto *A = D->getAttr<NoSpeculativeLoadHardeningAttr>()) {
      S.Diag(AL.getLoc(), diag::err_attributes_are_not_compatible) << AL << A;
      S.Diag(A->getLocation(), diag::note_conflicting_attribute);      
return false;
    }
    return true;
  }

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_function, /*IsSupported=*/true));
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_objc_method, /*IsSupported=*/LangOpts.ObjC));
}

AttrHandling handleDeclAttribute(Sema &S, Decl *D,const ParsedAttr &Attr) const override {
  D->addAttr(::new (S.Context) SpeculativeLoadHardeningAttr(S.Context, Attr));
  return AttributeApplied;
}

static const ParsedAttrInfoSpeculativeLoadHardening Instance;
};
const ParsedAttrInfoSpeculativeLoadHardening ParsedAttrInfoSpeculativeLoadHardening::Instance;
static constexpr ParsedAttrInfo::Spelling StandaloneDebugSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "standalone_debug"},
  {AttributeCommonInfo::AS_CXX11, "clang::standalone_debug"},
};
struct ParsedAttrInfoStandaloneDebug final : public ParsedAttrInfo {
  ParsedAttrInfoStandaloneDebug() {
    AttrKind = ParsedAttr::AT_StandaloneDebug;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = StandaloneDebugSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<CXXRecordDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "classes";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

bool acceptsLangOpts(const LangOptions &LangOpts) const override {
  return LangOpts.CPlusPlus;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_record, /*IsSupported=*/true));
}

AttrHandling handleDeclAttribute(Sema &S, Decl *D,const ParsedAttr &Attr) const override {
  D->addAttr(::new (S.Context) StandaloneDebugAttr(S.Context, Attr));
  return AttributeApplied;
}

static const ParsedAttrInfoStandaloneDebug Instance;
};
const ParsedAttrInfoStandaloneDebug ParsedAttrInfoStandaloneDebug::Instance;
static constexpr ParsedAttrInfo::Spelling StdCallSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "stdcall"},
  {AttributeCommonInfo::AS_CXX11, "gnu::stdcall"},
  {AttributeCommonInfo::AS_C2x, "gnu::stdcall"},
  {AttributeCommonInfo::AS_Keyword, "__stdcall"},
  {AttributeCommonInfo::AS_Keyword, "_stdcall"},
};
struct ParsedAttrInfoStdCall final : public ParsedAttrInfo {
  ParsedAttrInfoStdCall() {
    AttrKind = ParsedAttr::AT_StdCall;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 1;
    IsStmt = 0;
    IsKnownToGCC = 1;
    IsSupportedByPragmaAttribute = 0;
    Spellings = StdCallSpellings;
  }
static const ParsedAttrInfoStdCall Instance;
};
const ParsedAttrInfoStdCall ParsedAttrInfoStdCall::Instance;
struct ParsedAttrInfoStrictFP final : public ParsedAttrInfo {
  ParsedAttrInfoStrictFP() {
    AttrKind = ParsedAttr::AT_StrictFP;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 0;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FunctionDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "functions";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

static const ParsedAttrInfoStrictFP Instance;
};
const ParsedAttrInfoStrictFP ParsedAttrInfoStrictFP::Instance;
static constexpr ParsedAttrInfo::Spelling SuppressSpellings[] = {
  {AttributeCommonInfo::AS_CXX11, "gsl::suppress"},
};
static constexpr const char *SuppressArgNames[] = {
"DiagnosticIdentifiers...",};
struct ParsedAttrInfoSuppress final : public ParsedAttrInfo {
  ParsedAttrInfoSuppress() {
    AttrKind = ParsedAttr::AT_Suppress;
    NumArgs = 0;
    OptArgs = 15;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 1;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 0;
    Spellings = SuppressSpellings;
    ArgNames = SuppressArgNames;
  }
static const ParsedAttrInfoSuppress Instance;
};
const ParsedAttrInfoSuppress ParsedAttrInfoSuppress::Instance;
static constexpr ParsedAttrInfo::Spelling SwiftAsyncSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "swift_async"},
  {AttributeCommonInfo::AS_CXX11, "clang::swift_async"},
  {AttributeCommonInfo::AS_C2x, "clang::swift_async"},
};
static constexpr const char *SwiftAsyncArgNames[] = {
"Kind","CompletionHandlerIndex",};
struct ParsedAttrInfoSwiftAsync final : public ParsedAttrInfo {
  ParsedAttrInfoSwiftAsync() {
    AttrKind = ParsedAttr::AT_SwiftAsync;
    NumArgs = 1;
    OptArgs = 1;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = SwiftAsyncSpellings;
    ArgNames = SwiftAsyncArgNames;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FunctionDecl>(D) && !isa<ObjCMethodDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "functions and Objective-C methods";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_function, /*IsSupported=*/true));
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_objc_method, /*IsSupported=*/LangOpts.ObjC));
}

static const ParsedAttrInfoSwiftAsync Instance;
};
const ParsedAttrInfoSwiftAsync ParsedAttrInfoSwiftAsync::Instance;
static constexpr ParsedAttrInfo::Spelling SwiftAsyncCallSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "swiftasynccall"},
  {AttributeCommonInfo::AS_CXX11, "clang::swiftasynccall"},
  {AttributeCommonInfo::AS_C2x, "clang::swiftasynccall"},
};
struct ParsedAttrInfoSwiftAsyncCall final : public ParsedAttrInfo {
  ParsedAttrInfoSwiftAsyncCall() {
    AttrKind = ParsedAttr::AT_SwiftAsyncCall;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 1;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 0;
    Spellings = SwiftAsyncCallSpellings;
  }
static const ParsedAttrInfoSwiftAsyncCall Instance;
};
const ParsedAttrInfoSwiftAsyncCall ParsedAttrInfoSwiftAsyncCall::Instance;
static constexpr ParsedAttrInfo::Spelling SwiftAsyncContextSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "swift_async_context"},
  {AttributeCommonInfo::AS_CXX11, "clang::swift_async_context"},
  {AttributeCommonInfo::AS_C2x, "clang::swift_async_context"},
};
struct ParsedAttrInfoSwiftAsyncContext final : public ParsedAttrInfo {
  ParsedAttrInfoSwiftAsyncContext() {
    AttrKind = ParsedAttr::AT_SwiftAsyncContext;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = SwiftAsyncContextSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<ParmVarDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "parameters";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_variable_is_parameter, /*IsSupported=*/true));
}

static const ParsedAttrInfoSwiftAsyncContext Instance;
};
const ParsedAttrInfoSwiftAsyncContext ParsedAttrInfoSwiftAsyncContext::Instance;
static constexpr ParsedAttrInfo::Spelling SwiftAsyncErrorSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "swift_async_error"},
  {AttributeCommonInfo::AS_CXX11, "clang::swift_async_error"},
  {AttributeCommonInfo::AS_C2x, "clang::swift_async_error"},
};
static constexpr const char *SwiftAsyncErrorArgNames[] = {
"Convention","HandlerParamIdx",};
struct ParsedAttrInfoSwiftAsyncError final : public ParsedAttrInfo {
  ParsedAttrInfoSwiftAsyncError() {
    AttrKind = ParsedAttr::AT_SwiftAsyncError;
    NumArgs = 1;
    OptArgs = 1;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = SwiftAsyncErrorSpellings;
    ArgNames = SwiftAsyncErrorArgNames;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FunctionDecl>(D) && !isa<ObjCMethodDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "functions and Objective-C methods";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_function, /*IsSupported=*/true));
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_objc_method, /*IsSupported=*/LangOpts.ObjC));
}

static const ParsedAttrInfoSwiftAsyncError Instance;
};
const ParsedAttrInfoSwiftAsyncError ParsedAttrInfoSwiftAsyncError::Instance;
static constexpr ParsedAttrInfo::Spelling SwiftAsyncNameSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "swift_async_name"},
};
static constexpr const char *SwiftAsyncNameArgNames[] = {
"Name",};
struct ParsedAttrInfoSwiftAsyncName final : public ParsedAttrInfo {
  ParsedAttrInfoSwiftAsyncName() {
    AttrKind = ParsedAttr::AT_SwiftAsyncName;
    NumArgs = 1;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = SwiftAsyncNameSpellings;
    ArgNames = SwiftAsyncNameArgNames;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<ObjCMethodDecl>(D) && !isa<FunctionDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::err_attribute_wrong_decl_type_str)
      << Attr << "Objective-C methods and functions";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_objc_method, /*IsSupported=*/LangOpts.ObjC));
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_function, /*IsSupported=*/true));
}

static const ParsedAttrInfoSwiftAsyncName Instance;
};
const ParsedAttrInfoSwiftAsyncName ParsedAttrInfoSwiftAsyncName::Instance;
static constexpr ParsedAttrInfo::Spelling SwiftAttrSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "swift_attr"},
};
static constexpr const char *SwiftAttrArgNames[] = {
"Attribute",};
struct ParsedAttrInfoSwiftAttr final : public ParsedAttrInfo {
  ParsedAttrInfoSwiftAttr() {
    AttrKind = ParsedAttr::AT_SwiftAttr;
    NumArgs = 1;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = SwiftAttrSpellings;
    ArgNames = SwiftAttrArgNames;
  }
static const ParsedAttrInfoSwiftAttr Instance;
};
const ParsedAttrInfoSwiftAttr ParsedAttrInfoSwiftAttr::Instance;
static constexpr ParsedAttrInfo::Spelling SwiftBridgeSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "swift_bridge"},
};
static constexpr const char *SwiftBridgeArgNames[] = {
"SwiftType",};
struct ParsedAttrInfoSwiftBridge final : public ParsedAttrInfo {
  ParsedAttrInfoSwiftBridge() {
    AttrKind = ParsedAttr::AT_SwiftBridge;
    NumArgs = 1;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 0;
    Spellings = SwiftBridgeSpellings;
    ArgNames = SwiftBridgeArgNames;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<TagDecl>(D) && !isa<TypedefNameDecl>(D) && !isa<ObjCInterfaceDecl>(D) && !isa<ObjCProtocolDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::err_attribute_wrong_decl_type_str)
      << Attr << "tag types, typedefs, Objective-C interfaces, and Objective-C protocols";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

static const ParsedAttrInfoSwiftBridge Instance;
};
const ParsedAttrInfoSwiftBridge ParsedAttrInfoSwiftBridge::Instance;
static constexpr ParsedAttrInfo::Spelling SwiftBridgedTypedefSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "swift_bridged_typedef"},
};
struct ParsedAttrInfoSwiftBridgedTypedef final : public ParsedAttrInfo {
  ParsedAttrInfoSwiftBridgedTypedef() {
    AttrKind = ParsedAttr::AT_SwiftBridgedTypedef;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = SwiftBridgedTypedefSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<TypedefNameDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::err_attribute_wrong_decl_type_str)
      << Attr << "typedefs";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_type_alias, /*IsSupported=*/true));
}

AttrHandling handleDeclAttribute(Sema &S, Decl *D,const ParsedAttr &Attr) const override {
  D->addAttr(::new (S.Context) SwiftBridgedTypedefAttr(S.Context, Attr));
  return AttributeApplied;
}

static const ParsedAttrInfoSwiftBridgedTypedef Instance;
};
const ParsedAttrInfoSwiftBridgedTypedef ParsedAttrInfoSwiftBridgedTypedef::Instance;
static constexpr ParsedAttrInfo::Spelling SwiftCallSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "swiftcall"},
  {AttributeCommonInfo::AS_CXX11, "clang::swiftcall"},
  {AttributeCommonInfo::AS_C2x, "clang::swiftcall"},
};
struct ParsedAttrInfoSwiftCall final : public ParsedAttrInfo {
  ParsedAttrInfoSwiftCall() {
    AttrKind = ParsedAttr::AT_SwiftCall;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 1;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 0;
    Spellings = SwiftCallSpellings;
  }
static const ParsedAttrInfoSwiftCall Instance;
};
const ParsedAttrInfoSwiftCall ParsedAttrInfoSwiftCall::Instance;
static constexpr ParsedAttrInfo::Spelling SwiftContextSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "swift_context"},
  {AttributeCommonInfo::AS_CXX11, "clang::swift_context"},
  {AttributeCommonInfo::AS_C2x, "clang::swift_context"},
};
struct ParsedAttrInfoSwiftContext final : public ParsedAttrInfo {
  ParsedAttrInfoSwiftContext() {
    AttrKind = ParsedAttr::AT_SwiftContext;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = SwiftContextSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<ParmVarDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "parameters";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_variable_is_parameter, /*IsSupported=*/true));
}

static const ParsedAttrInfoSwiftContext Instance;
};
const ParsedAttrInfoSwiftContext ParsedAttrInfoSwiftContext::Instance;
static constexpr ParsedAttrInfo::Spelling SwiftErrorSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "swift_error"},
};
static constexpr const char *SwiftErrorArgNames[] = {
"Convention",};
struct ParsedAttrInfoSwiftError final : public ParsedAttrInfo {
  ParsedAttrInfoSwiftError() {
    AttrKind = ParsedAttr::AT_SwiftError;
    NumArgs = 1;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = SwiftErrorSpellings;
    ArgNames = SwiftErrorArgNames;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FunctionDecl>(D) && !isa<ObjCMethodDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::err_attribute_wrong_decl_type_str)
      << Attr << "functions and Objective-C methods";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_function, /*IsSupported=*/true));
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_objc_method, /*IsSupported=*/LangOpts.ObjC));
}

static const ParsedAttrInfoSwiftError Instance;
};
const ParsedAttrInfoSwiftError ParsedAttrInfoSwiftError::Instance;
static constexpr ParsedAttrInfo::Spelling SwiftErrorResultSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "swift_error_result"},
  {AttributeCommonInfo::AS_CXX11, "clang::swift_error_result"},
  {AttributeCommonInfo::AS_C2x, "clang::swift_error_result"},
};
struct ParsedAttrInfoSwiftErrorResult final : public ParsedAttrInfo {
  ParsedAttrInfoSwiftErrorResult() {
    AttrKind = ParsedAttr::AT_SwiftErrorResult;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = SwiftErrorResultSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<ParmVarDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "parameters";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_variable_is_parameter, /*IsSupported=*/true));
}

static const ParsedAttrInfoSwiftErrorResult Instance;
};
const ParsedAttrInfoSwiftErrorResult ParsedAttrInfoSwiftErrorResult::Instance;
static constexpr ParsedAttrInfo::Spelling SwiftIndirectResultSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "swift_indirect_result"},
  {AttributeCommonInfo::AS_CXX11, "clang::swift_indirect_result"},
  {AttributeCommonInfo::AS_C2x, "clang::swift_indirect_result"},
};
struct ParsedAttrInfoSwiftIndirectResult final : public ParsedAttrInfo {
  ParsedAttrInfoSwiftIndirectResult() {
    AttrKind = ParsedAttr::AT_SwiftIndirectResult;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = SwiftIndirectResultSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<ParmVarDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "parameters";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_variable_is_parameter, /*IsSupported=*/true));
}

static const ParsedAttrInfoSwiftIndirectResult Instance;
};
const ParsedAttrInfoSwiftIndirectResult ParsedAttrInfoSwiftIndirectResult::Instance;
static constexpr ParsedAttrInfo::Spelling SwiftNameSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "swift_name"},
};
static constexpr const char *SwiftNameArgNames[] = {
"Name",};
struct ParsedAttrInfoSwiftName final : public ParsedAttrInfo {
  ParsedAttrInfoSwiftName() {
    AttrKind = ParsedAttr::AT_SwiftName;
    NumArgs = 1;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 0;
    Spellings = SwiftNameSpellings;
    ArgNames = SwiftNameArgNames;
  }
static const ParsedAttrInfoSwiftName Instance;
};
const ParsedAttrInfoSwiftName ParsedAttrInfoSwiftName::Instance;
static constexpr ParsedAttrInfo::Spelling SwiftNewTypeSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "swift_newtype"},
  {AttributeCommonInfo::AS_GNU, "swift_wrapper"},
};
static constexpr const char *SwiftNewTypeArgNames[] = {
"NewtypeKind",};
struct ParsedAttrInfoSwiftNewType final : public ParsedAttrInfo {
  ParsedAttrInfoSwiftNewType() {
    AttrKind = ParsedAttr::AT_SwiftNewType;
    NumArgs = 1;
    OptArgs = 0;
    HasCustomParsing = 1;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = SwiftNewTypeSpellings;
    ArgNames = SwiftNewTypeArgNames;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<TypedefNameDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::err_attribute_wrong_decl_type_str)
      << Attr << "typedefs";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

unsigned spellingIndexToSemanticSpelling(const ParsedAttr &Attr) const override {
  enum Spelling {
    GNU_swift_newtype = 0,
    GNU_swift_wrapper = 1,
  SpellingNotCalculated = 15

  };

  unsigned Idx = Attr.getAttributeSpellingListIndex();
  switch (Idx) {
    default: llvm_unreachable("Unknown spelling list index");
    case 0: return GNU_swift_newtype;
    case 1: return GNU_swift_wrapper;
  }
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_type_alias, /*IsSupported=*/true));
}

static const ParsedAttrInfoSwiftNewType Instance;
};
const ParsedAttrInfoSwiftNewType ParsedAttrInfoSwiftNewType::Instance;
static constexpr ParsedAttrInfo::Spelling SwiftObjCMembersSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "swift_objc_members"},
};
struct ParsedAttrInfoSwiftObjCMembers final : public ParsedAttrInfo {
  ParsedAttrInfoSwiftObjCMembers() {
    AttrKind = ParsedAttr::AT_SwiftObjCMembers;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = SwiftObjCMembersSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<ObjCInterfaceDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::err_attribute_wrong_decl_type_str)
      << Attr << "Objective-C interfaces";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_objc_interface, /*IsSupported=*/LangOpts.ObjC));
}

AttrHandling handleDeclAttribute(Sema &S, Decl *D,const ParsedAttr &Attr) const override {
  D->addAttr(::new (S.Context) SwiftObjCMembersAttr(S.Context, Attr));
  return AttributeApplied;
}

static const ParsedAttrInfoSwiftObjCMembers Instance;
};
const ParsedAttrInfoSwiftObjCMembers ParsedAttrInfoSwiftObjCMembers::Instance;
static constexpr ParsedAttrInfo::Spelling SwiftPrivateSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "swift_private"},
};
struct ParsedAttrInfoSwiftPrivate final : public ParsedAttrInfo {
  ParsedAttrInfoSwiftPrivate() {
    AttrKind = ParsedAttr::AT_SwiftPrivate;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 0;
    Spellings = SwiftPrivateSpellings;
  }
AttrHandling handleDeclAttribute(Sema &S, Decl *D,const ParsedAttr &Attr) const override {
  D->addAttr(::new (S.Context) SwiftPrivateAttr(S.Context, Attr));
  return AttributeApplied;
}

static const ParsedAttrInfoSwiftPrivate Instance;
};
const ParsedAttrInfoSwiftPrivate ParsedAttrInfoSwiftPrivate::Instance;
static constexpr ParsedAttrInfo::Spelling SysVABISpellings[] = {
  {AttributeCommonInfo::AS_GNU, "sysv_abi"},
  {AttributeCommonInfo::AS_CXX11, "gnu::sysv_abi"},
  {AttributeCommonInfo::AS_C2x, "gnu::sysv_abi"},
};
struct ParsedAttrInfoSysVABI final : public ParsedAttrInfo {
  ParsedAttrInfoSysVABI() {
    AttrKind = ParsedAttr::AT_SysVABI;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 1;
    IsStmt = 0;
    IsKnownToGCC = 1;
    IsSupportedByPragmaAttribute = 0;
    Spellings = SysVABISpellings;
  }
static const ParsedAttrInfoSysVABI Instance;
};
const ParsedAttrInfoSysVABI ParsedAttrInfoSysVABI::Instance;
static constexpr ParsedAttrInfo::Spelling TLSModelSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "tls_model"},
  {AttributeCommonInfo::AS_CXX11, "gnu::tls_model"},
  {AttributeCommonInfo::AS_C2x, "gnu::tls_model"},
};
static constexpr const char *TLSModelArgNames[] = {
"Model",};
struct ParsedAttrInfoTLSModel final : public ParsedAttrInfo {
  ParsedAttrInfoTLSModel() {
    AttrKind = ParsedAttr::AT_TLSModel;
    NumArgs = 1;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 1;
    IsSupportedByPragmaAttribute = 1;
    Spellings = TLSModelSpellings;
    ArgNames = TLSModelArgNames;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isTLSVar(D)) {
    S.Diag(Attr.getLoc(), diag::err_attribute_wrong_decl_type_str)
      << Attr << "thread-local variables";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_variable_is_thread_local, /*IsSupported=*/true));
}

static const ParsedAttrInfoTLSModel Instance;
};
const ParsedAttrInfoTLSModel ParsedAttrInfoTLSModel::Instance;
static constexpr ParsedAttrInfo::Spelling TargetSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "target"},
  {AttributeCommonInfo::AS_CXX11, "gnu::target"},
  {AttributeCommonInfo::AS_C2x, "gnu::target"},
};
static constexpr const char *TargetArgNames[] = {
"featuresStr",};
struct ParsedAttrInfoTarget final : public ParsedAttrInfo {
  ParsedAttrInfoTarget() {
    AttrKind = ParsedAttr::AT_Target;
    NumArgs = 1;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 1;
    IsSupportedByPragmaAttribute = 1;
    Spellings = TargetSpellings;
    ArgNames = TargetArgNames;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FunctionDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::err_attribute_wrong_decl_type_str)
      << Attr << "functions";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

  using ParsedAttrInfo::diagMutualExclusion;

  bool diagMutualExclusion(Sema &S, const ParsedAttr &AL, const Decl *D) const override {
    if (const auto *A = D->getAttr<TargetClonesAttr>()) {
      S.Diag(AL.getLoc(), diag::err_attributes_are_not_compatible) << AL << A;
      S.Diag(A->getLocation(), diag::note_conflicting_attribute);      
return false;
    }
    if (const auto *A = D->getAttr<CPUDispatchAttr>()) {
      S.Diag(AL.getLoc(), diag::err_attributes_are_not_compatible) << AL << A;
      S.Diag(A->getLocation(), diag::note_conflicting_attribute);      
return false;
    }
    if (const auto *A = D->getAttr<CPUSpecificAttr>()) {
      S.Diag(AL.getLoc(), diag::err_attributes_are_not_compatible) << AL << A;
      S.Diag(A->getLocation(), diag::note_conflicting_attribute);      
return false;
    }
    return true;
  }

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_function, /*IsSupported=*/true));
}

static const ParsedAttrInfoTarget Instance;
};
const ParsedAttrInfoTarget ParsedAttrInfoTarget::Instance;
static constexpr ParsedAttrInfo::Spelling TargetClonesSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "target_clones"},
  {AttributeCommonInfo::AS_CXX11, "gnu::target_clones"},
  {AttributeCommonInfo::AS_C2x, "gnu::target_clones"},
};
static constexpr const char *TargetClonesArgNames[] = {
"featuresStrs...",};
struct ParsedAttrInfoTargetClones final : public ParsedAttrInfo {
  ParsedAttrInfoTargetClones() {
    AttrKind = ParsedAttr::AT_TargetClones;
    NumArgs = 0;
    OptArgs = 15;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 1;
    IsSupportedByPragmaAttribute = 1;
    Spellings = TargetClonesSpellings;
    ArgNames = TargetClonesArgNames;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FunctionDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::err_attribute_wrong_decl_type_str)
      << Attr << "functions";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

  using ParsedAttrInfo::diagMutualExclusion;

  bool diagMutualExclusion(Sema &S, const ParsedAttr &AL, const Decl *D) const override {
    if (const auto *A = D->getAttr<TargetAttr>()) {
      S.Diag(AL.getLoc(), diag::err_attributes_are_not_compatible) << AL << A;
      S.Diag(A->getLocation(), diag::note_conflicting_attribute);      
return false;
    }
    if (const auto *A = D->getAttr<CPUDispatchAttr>()) {
      S.Diag(AL.getLoc(), diag::err_attributes_are_not_compatible) << AL << A;
      S.Diag(A->getLocation(), diag::note_conflicting_attribute);      
return false;
    }
    if (const auto *A = D->getAttr<CPUSpecificAttr>()) {
      S.Diag(AL.getLoc(), diag::err_attributes_are_not_compatible) << AL << A;
      S.Diag(A->getLocation(), diag::note_conflicting_attribute);      
return false;
    }
    return true;
  }

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_function, /*IsSupported=*/true));
}

static const ParsedAttrInfoTargetClones Instance;
};
const ParsedAttrInfoTargetClones ParsedAttrInfoTargetClones::Instance;
static constexpr ParsedAttrInfo::Spelling TestTypestateSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "test_typestate"},
  {AttributeCommonInfo::AS_CXX11, "clang::test_typestate"},
};
static constexpr const char *TestTypestateArgNames[] = {
"TestState",};
struct ParsedAttrInfoTestTypestate final : public ParsedAttrInfo {
  ParsedAttrInfoTestTypestate() {
    AttrKind = ParsedAttr::AT_TestTypestate;
    NumArgs = 1;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = TestTypestateSpellings;
    ArgNames = TestTypestateArgNames;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<CXXMethodDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "functions";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_function_is_member, /*IsSupported=*/LangOpts.CPlusPlus));
}

static const ParsedAttrInfoTestTypestate Instance;
};
const ParsedAttrInfoTestTypestate ParsedAttrInfoTestTypestate::Instance;
static constexpr ParsedAttrInfo::Spelling ThisCallSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "thiscall"},
  {AttributeCommonInfo::AS_CXX11, "gnu::thiscall"},
  {AttributeCommonInfo::AS_C2x, "gnu::thiscall"},
  {AttributeCommonInfo::AS_Keyword, "__thiscall"},
  {AttributeCommonInfo::AS_Keyword, "_thiscall"},
};
struct ParsedAttrInfoThisCall final : public ParsedAttrInfo {
  ParsedAttrInfoThisCall() {
    AttrKind = ParsedAttr::AT_ThisCall;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 1;
    IsStmt = 0;
    IsKnownToGCC = 1;
    IsSupportedByPragmaAttribute = 0;
    Spellings = ThisCallSpellings;
  }
static const ParsedAttrInfoThisCall Instance;
};
const ParsedAttrInfoThisCall ParsedAttrInfoThisCall::Instance;
static constexpr ParsedAttrInfo::Spelling ThreadSpellings[] = {
  {AttributeCommonInfo::AS_Declspec, "thread"},
};
struct ParsedAttrInfoThread final : public ParsedAttrInfo {
  ParsedAttrInfoThread() {
    AttrKind = ParsedAttr::AT_Thread;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 0;
    Spellings = ThreadSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<VarDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "variables";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

bool acceptsLangOpts(const LangOptions &LangOpts) const override {
  return LangOpts.MicrosoftExt;
}

static const ParsedAttrInfoThread Instance;
};
const ParsedAttrInfoThread ParsedAttrInfoThread::Instance;
static constexpr ParsedAttrInfo::Spelling TransparentUnionSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "transparent_union"},
  {AttributeCommonInfo::AS_CXX11, "gnu::transparent_union"},
  {AttributeCommonInfo::AS_C2x, "gnu::transparent_union"},
};
struct ParsedAttrInfoTransparentUnion final : public ParsedAttrInfo {
  ParsedAttrInfoTransparentUnion() {
    AttrKind = ParsedAttr::AT_TransparentUnion;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 1;
    IsSupportedByPragmaAttribute = 0;
    Spellings = TransparentUnionSpellings;
  }
bool acceptsLangOpts(const LangOptions &LangOpts) const override {
  return (!LangOpts.CPlusPlus);
}

static const ParsedAttrInfoTransparentUnion Instance;
};
const ParsedAttrInfoTransparentUnion ParsedAttrInfoTransparentUnion::Instance;
static constexpr ParsedAttrInfo::Spelling TrivialABISpellings[] = {
  {AttributeCommonInfo::AS_GNU, "trivial_abi"},
  {AttributeCommonInfo::AS_CXX11, "clang::trivial_abi"},
};
struct ParsedAttrInfoTrivialABI final : public ParsedAttrInfo {
  ParsedAttrInfoTrivialABI() {
    AttrKind = ParsedAttr::AT_TrivialABI;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = TrivialABISpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<CXXRecordDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "classes";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

bool acceptsLangOpts(const LangOptions &LangOpts) const override {
  return LangOpts.CPlusPlus;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_record, /*IsSupported=*/true));
}

AttrHandling handleDeclAttribute(Sema &S, Decl *D,const ParsedAttr &Attr) const override {
  D->addAttr(::new (S.Context) TrivialABIAttr(S.Context, Attr));
  return AttributeApplied;
}

static const ParsedAttrInfoTrivialABI Instance;
};
const ParsedAttrInfoTrivialABI ParsedAttrInfoTrivialABI::Instance;
static constexpr ParsedAttrInfo::Spelling TryAcquireCapabilitySpellings[] = {
  {AttributeCommonInfo::AS_GNU, "try_acquire_capability"},
  {AttributeCommonInfo::AS_CXX11, "clang::try_acquire_capability"},
  {AttributeCommonInfo::AS_GNU, "try_acquire_shared_capability"},
  {AttributeCommonInfo::AS_CXX11, "clang::try_acquire_shared_capability"},
};
static constexpr const char *TryAcquireCapabilityArgNames[] = {
"SuccessValue","Args...",};
struct ParsedAttrInfoTryAcquireCapability final : public ParsedAttrInfo {
  ParsedAttrInfoTryAcquireCapability() {
    AttrKind = ParsedAttr::AT_TryAcquireCapability;
    NumArgs = 1;
    OptArgs = 15;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 0;
    Spellings = TryAcquireCapabilitySpellings;
    ArgNames = TryAcquireCapabilityArgNames;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FunctionDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::err_attribute_wrong_decl_type_str)
      << Attr << "functions";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

unsigned spellingIndexToSemanticSpelling(const ParsedAttr &Attr) const override {
  enum Spelling {
    GNU_try_acquire_capability = 0,
    CXX11_clang_try_acquire_capability = 1,
    GNU_try_acquire_shared_capability = 2,
    CXX11_clang_try_acquire_shared_capability = 3,
  SpellingNotCalculated = 15

  };

  unsigned Idx = Attr.getAttributeSpellingListIndex();
  switch (Idx) {
    default: llvm_unreachable("Unknown spelling list index");
    case 0: return GNU_try_acquire_capability;
    case 1: return CXX11_clang_try_acquire_capability;
    case 2: return GNU_try_acquire_shared_capability;
    case 3: return CXX11_clang_try_acquire_shared_capability;
  }
}

static const ParsedAttrInfoTryAcquireCapability Instance;
};
const ParsedAttrInfoTryAcquireCapability ParsedAttrInfoTryAcquireCapability::Instance;
static constexpr ParsedAttrInfo::Spelling TypeNonNullSpellings[] = {
  {AttributeCommonInfo::AS_Keyword, "_Nonnull"},
};
struct ParsedAttrInfoTypeNonNull final : public ParsedAttrInfo {
  ParsedAttrInfoTypeNonNull() {
    AttrKind = ParsedAttr::AT_TypeNonNull;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 1;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 0;
    Spellings = TypeNonNullSpellings;
  }
static const ParsedAttrInfoTypeNonNull Instance;
};
const ParsedAttrInfoTypeNonNull ParsedAttrInfoTypeNonNull::Instance;
static constexpr ParsedAttrInfo::Spelling TypeNullUnspecifiedSpellings[] = {
  {AttributeCommonInfo::AS_Keyword, "_Null_unspecified"},
};
struct ParsedAttrInfoTypeNullUnspecified final : public ParsedAttrInfo {
  ParsedAttrInfoTypeNullUnspecified() {
    AttrKind = ParsedAttr::AT_TypeNullUnspecified;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 1;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 0;
    Spellings = TypeNullUnspecifiedSpellings;
  }
static const ParsedAttrInfoTypeNullUnspecified Instance;
};
const ParsedAttrInfoTypeNullUnspecified ParsedAttrInfoTypeNullUnspecified::Instance;
static constexpr ParsedAttrInfo::Spelling TypeNullableSpellings[] = {
  {AttributeCommonInfo::AS_Keyword, "_Nullable"},
};
struct ParsedAttrInfoTypeNullable final : public ParsedAttrInfo {
  ParsedAttrInfoTypeNullable() {
    AttrKind = ParsedAttr::AT_TypeNullable;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 1;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 0;
    Spellings = TypeNullableSpellings;
  }
static const ParsedAttrInfoTypeNullable Instance;
};
const ParsedAttrInfoTypeNullable ParsedAttrInfoTypeNullable::Instance;
static constexpr ParsedAttrInfo::Spelling TypeNullableResultSpellings[] = {
  {AttributeCommonInfo::AS_Keyword, "_Nullable_result"},
};
struct ParsedAttrInfoTypeNullableResult final : public ParsedAttrInfo {
  ParsedAttrInfoTypeNullableResult() {
    AttrKind = ParsedAttr::AT_TypeNullableResult;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 1;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 0;
    Spellings = TypeNullableResultSpellings;
  }
static const ParsedAttrInfoTypeNullableResult Instance;
};
const ParsedAttrInfoTypeNullableResult ParsedAttrInfoTypeNullableResult::Instance;
static constexpr ParsedAttrInfo::Spelling TypeTagForDatatypeSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "type_tag_for_datatype"},
  {AttributeCommonInfo::AS_CXX11, "clang::type_tag_for_datatype"},
  {AttributeCommonInfo::AS_C2x, "clang::type_tag_for_datatype"},
};
static constexpr const char *TypeTagForDatatypeArgNames[] = {
"ArgumentKind","MatchingCType","LayoutCompatible","MustBeNull",};
struct ParsedAttrInfoTypeTagForDatatype final : public ParsedAttrInfo {
  ParsedAttrInfoTypeTagForDatatype() {
    AttrKind = ParsedAttr::AT_TypeTagForDatatype;
    NumArgs = 4;
    OptArgs = 0;
    HasCustomParsing = 1;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 0;
    Spellings = TypeTagForDatatypeSpellings;
    ArgNames = TypeTagForDatatypeArgNames;
  }
static const ParsedAttrInfoTypeTagForDatatype Instance;
};
const ParsedAttrInfoTypeTagForDatatype ParsedAttrInfoTypeTagForDatatype::Instance;
static constexpr ParsedAttrInfo::Spelling TypeVisibilitySpellings[] = {
  {AttributeCommonInfo::AS_GNU, "type_visibility"},
  {AttributeCommonInfo::AS_CXX11, "clang::type_visibility"},
  {AttributeCommonInfo::AS_C2x, "clang::type_visibility"},
};
static constexpr const char *TypeVisibilityArgNames[] = {
"Visibility",};
struct ParsedAttrInfoTypeVisibility final : public ParsedAttrInfo {
  ParsedAttrInfoTypeVisibility() {
    AttrKind = ParsedAttr::AT_TypeVisibility;
    NumArgs = 1;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 0;
    Spellings = TypeVisibilitySpellings;
    ArgNames = TypeVisibilityArgNames;
  }
static const ParsedAttrInfoTypeVisibility Instance;
};
const ParsedAttrInfoTypeVisibility ParsedAttrInfoTypeVisibility::Instance;
static constexpr ParsedAttrInfo::Spelling UPtrSpellings[] = {
  {AttributeCommonInfo::AS_Keyword, "__uptr"},
};
struct ParsedAttrInfoUPtr final : public ParsedAttrInfo {
  ParsedAttrInfoUPtr() {
    AttrKind = ParsedAttr::AT_UPtr;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 1;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 0;
    Spellings = UPtrSpellings;
  }
static const ParsedAttrInfoUPtr Instance;
};
const ParsedAttrInfoUPtr ParsedAttrInfoUPtr::Instance;
static constexpr ParsedAttrInfo::Spelling UnavailableSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "unavailable"},
  {AttributeCommonInfo::AS_CXX11, "clang::unavailable"},
  {AttributeCommonInfo::AS_C2x, "clang::unavailable"},
};
static constexpr const char *UnavailableArgNames[] = {
"Message",};
struct ParsedAttrInfoUnavailable final : public ParsedAttrInfo {
  ParsedAttrInfoUnavailable() {
    AttrKind = ParsedAttr::AT_Unavailable;
    NumArgs = 0;
    OptArgs = 1;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 0;
    Spellings = UnavailableSpellings;
    ArgNames = UnavailableArgNames;
  }
static const ParsedAttrInfoUnavailable Instance;
};
const ParsedAttrInfoUnavailable ParsedAttrInfoUnavailable::Instance;
static constexpr ParsedAttrInfo::Spelling UninitializedSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "uninitialized"},
  {AttributeCommonInfo::AS_CXX11, "clang::uninitialized"},
};
struct ParsedAttrInfoUninitialized final : public ParsedAttrInfo {
  ParsedAttrInfoUninitialized() {
    AttrKind = ParsedAttr::AT_Uninitialized;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = UninitializedSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isLocalVar(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "local variables";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_variable_is_local, /*IsSupported=*/true));
}

static const ParsedAttrInfoUninitialized Instance;
};
const ParsedAttrInfoUninitialized ParsedAttrInfoUninitialized::Instance;
static constexpr ParsedAttrInfo::Spelling UnlikelySpellings[] = {
  {AttributeCommonInfo::AS_CXX11, "unlikely"},
  {AttributeCommonInfo::AS_C2x, "clang::unlikely"},
};
struct ParsedAttrInfoUnlikely final : public ParsedAttrInfo {
  ParsedAttrInfoUnlikely() {
    AttrKind = ParsedAttr::AT_Unlikely;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 1;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 0;
    Spellings = UnlikelySpellings;
  }
  using ParsedAttrInfo::diagMutualExclusion;

static const ParsedAttrInfoUnlikely Instance;
};
const ParsedAttrInfoUnlikely ParsedAttrInfoUnlikely::Instance;
static constexpr ParsedAttrInfo::Spelling UnusedSpellings[] = {
  {AttributeCommonInfo::AS_CXX11, "maybe_unused"},
  {AttributeCommonInfo::AS_GNU, "unused"},
  {AttributeCommonInfo::AS_CXX11, "gnu::unused"},
  {AttributeCommonInfo::AS_C2x, "gnu::unused"},
  {AttributeCommonInfo::AS_C2x, "maybe_unused"},
};
struct ParsedAttrInfoUnused final : public ParsedAttrInfo {
  ParsedAttrInfoUnused() {
    AttrKind = ParsedAttr::AT_Unused;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 1;
    IsSupportedByPragmaAttribute = 0;
    Spellings = UnusedSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<VarDecl>(D) && !isa<ObjCIvarDecl>(D) && !isa<TypeDecl>(D) && !isa<EnumDecl>(D) && !isa<EnumConstantDecl>(D) && !isa<LabelDecl>(D) && !isa<FieldDecl>(D) && !isa<ObjCMethodDecl>(D) && !isFunctionLike(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "variables, non-static data members, types, enums, enumerators, labels, non-static data members, Objective-C methods, functions, and function pointers";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

unsigned spellingIndexToSemanticSpelling(const ParsedAttr &Attr) const override {
  enum Spelling {
    CXX11_maybe_unused = 0,
    GNU_unused = 1,
    CXX11_gnu_unused = 2,
    C2x_gnu_unused = 3,
    C2x_maybe_unused = 4,
  SpellingNotCalculated = 15

  };

  unsigned Idx = Attr.getAttributeSpellingListIndex();
  switch (Idx) {
    default: llvm_unreachable("Unknown spelling list index");
    case 0: return CXX11_maybe_unused;
    case 1: return GNU_unused;
    case 2: return CXX11_gnu_unused;
    case 3: return C2x_gnu_unused;
    case 4: return C2x_maybe_unused;
  }
}

static const ParsedAttrInfoUnused Instance;
};
const ParsedAttrInfoUnused ParsedAttrInfoUnused::Instance;
static constexpr ParsedAttrInfo::Spelling UseHandleSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "use_handle"},
  {AttributeCommonInfo::AS_CXX11, "clang::use_handle"},
  {AttributeCommonInfo::AS_C2x, "clang::use_handle"},
};
static constexpr const char *UseHandleArgNames[] = {
"HandleType",};
struct ParsedAttrInfoUseHandle final : public ParsedAttrInfo {
  ParsedAttrInfoUseHandle() {
    AttrKind = ParsedAttr::AT_UseHandle;
    NumArgs = 1;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = UseHandleSpellings;
    ArgNames = UseHandleArgNames;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<ParmVarDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "parameters";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_variable_is_parameter, /*IsSupported=*/true));
}

static const ParsedAttrInfoUseHandle Instance;
};
const ParsedAttrInfoUseHandle ParsedAttrInfoUseHandle::Instance;
static constexpr ParsedAttrInfo::Spelling UsedSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "used"},
  {AttributeCommonInfo::AS_CXX11, "gnu::used"},
  {AttributeCommonInfo::AS_C2x, "gnu::used"},
};
struct ParsedAttrInfoUsed final : public ParsedAttrInfo {
  ParsedAttrInfoUsed() {
    AttrKind = ParsedAttr::AT_Used;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 1;
    IsSupportedByPragmaAttribute = 0;
    Spellings = UsedSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isNonLocalVar(D) && !isa<FunctionDecl>(D) && !isa<ObjCMethodDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "variables with non-local storage, functions, and Objective-C methods";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

AttrHandling handleDeclAttribute(Sema &S, Decl *D,const ParsedAttr &Attr) const override {
  D->addAttr(::new (S.Context) UsedAttr(S.Context, Attr));
  return AttributeApplied;
}

static const ParsedAttrInfoUsed Instance;
};
const ParsedAttrInfoUsed ParsedAttrInfoUsed::Instance;
static constexpr ParsedAttrInfo::Spelling UsingIfExistsSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "using_if_exists"},
  {AttributeCommonInfo::AS_CXX11, "clang::using_if_exists"},
};
struct ParsedAttrInfoUsingIfExists final : public ParsedAttrInfo {
  ParsedAttrInfoUsingIfExists() {
    AttrKind = ParsedAttr::AT_UsingIfExists;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 0;
    Spellings = UsingIfExistsSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<UsingDecl>(D) && !isa<UnresolvedUsingTypenameDecl>(D) && !isa<UnresolvedUsingValueDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::err_attribute_wrong_decl_type_str)
      << Attr << "named declarations, types, and value declarations";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

static const ParsedAttrInfoUsingIfExists Instance;
};
const ParsedAttrInfoUsingIfExists ParsedAttrInfoUsingIfExists::Instance;
static constexpr ParsedAttrInfo::Spelling UuidSpellings[] = {
  {AttributeCommonInfo::AS_Declspec, "uuid"},
  {AttributeCommonInfo::AS_Microsoft, "uuid"},
};
static constexpr const char *UuidArgNames[] = {
"Guid",};
struct ParsedAttrInfoUuid final : public ParsedAttrInfo {
  ParsedAttrInfoUuid() {
    AttrKind = ParsedAttr::AT_Uuid;
    NumArgs = 1;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 0;
    Spellings = UuidSpellings;
    ArgNames = UuidArgNames;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<RecordDecl>(D) && !isa<EnumDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "structs, unions, classes, and enums";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

bool acceptsLangOpts(const LangOptions &LangOpts) const override {
  return LangOpts.MicrosoftExt || LangOpts.Borland;
}

static const ParsedAttrInfoUuid Instance;
};
const ParsedAttrInfoUuid ParsedAttrInfoUuid::Instance;
static constexpr ParsedAttrInfo::Spelling VecReturnSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "vecreturn"},
  {AttributeCommonInfo::AS_CXX11, "clang::vecreturn"},
};
struct ParsedAttrInfoVecReturn final : public ParsedAttrInfo {
  ParsedAttrInfoVecReturn() {
    AttrKind = ParsedAttr::AT_VecReturn;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = VecReturnSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<CXXRecordDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::err_attribute_wrong_decl_type_str)
      << Attr << "classes";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_record, /*IsSupported=*/true));
}

static const ParsedAttrInfoVecReturn Instance;
};
const ParsedAttrInfoVecReturn ParsedAttrInfoVecReturn::Instance;
static constexpr ParsedAttrInfo::Spelling VecTypeHintSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "vec_type_hint"},
};
static constexpr const char *VecTypeHintArgNames[] = {
"TypeHint",};
struct ParsedAttrInfoVecTypeHint final : public ParsedAttrInfo {
  ParsedAttrInfoVecTypeHint() {
    AttrKind = ParsedAttr::AT_VecTypeHint;
    NumArgs = 1;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = VecTypeHintSpellings;
    ArgNames = VecTypeHintArgNames;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FunctionDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::err_attribute_wrong_decl_type_str)
      << Attr << "functions";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_function, /*IsSupported=*/true));
}

static const ParsedAttrInfoVecTypeHint Instance;
};
const ParsedAttrInfoVecTypeHint ParsedAttrInfoVecTypeHint::Instance;
static constexpr ParsedAttrInfo::Spelling VectorCallSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "vectorcall"},
  {AttributeCommonInfo::AS_CXX11, "clang::vectorcall"},
  {AttributeCommonInfo::AS_C2x, "clang::vectorcall"},
  {AttributeCommonInfo::AS_Keyword, "__vectorcall"},
  {AttributeCommonInfo::AS_Keyword, "_vectorcall"},
};
struct ParsedAttrInfoVectorCall final : public ParsedAttrInfo {
  ParsedAttrInfoVectorCall() {
    AttrKind = ParsedAttr::AT_VectorCall;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 1;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 0;
    Spellings = VectorCallSpellings;
  }
static const ParsedAttrInfoVectorCall Instance;
};
const ParsedAttrInfoVectorCall ParsedAttrInfoVectorCall::Instance;
static constexpr ParsedAttrInfo::Spelling VectorSizeSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "vector_size"},
  {AttributeCommonInfo::AS_CXX11, "gnu::vector_size"},
  {AttributeCommonInfo::AS_C2x, "gnu::vector_size"},
};
static constexpr const char *VectorSizeArgNames[] = {
"NumBytes",};
struct ParsedAttrInfoVectorSize final : public ParsedAttrInfo {
  ParsedAttrInfoVectorSize() {
    AttrKind = ParsedAttr::AT_VectorSize;
    NumArgs = 1;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 1;
    IsStmt = 0;
    IsKnownToGCC = 1;
    IsSupportedByPragmaAttribute = 0;
    Spellings = VectorSizeSpellings;
    ArgNames = VectorSizeArgNames;
  }
static const ParsedAttrInfoVectorSize Instance;
};
const ParsedAttrInfoVectorSize ParsedAttrInfoVectorSize::Instance;
static constexpr ParsedAttrInfo::Spelling VisibilitySpellings[] = {
  {AttributeCommonInfo::AS_GNU, "visibility"},
  {AttributeCommonInfo::AS_CXX11, "gnu::visibility"},
  {AttributeCommonInfo::AS_C2x, "gnu::visibility"},
};
static constexpr const char *VisibilityArgNames[] = {
"Visibility",};
struct ParsedAttrInfoVisibility final : public ParsedAttrInfo {
  ParsedAttrInfoVisibility() {
    AttrKind = ParsedAttr::AT_Visibility;
    NumArgs = 1;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 1;
    IsSupportedByPragmaAttribute = 0;
    Spellings = VisibilitySpellings;
    ArgNames = VisibilityArgNames;
  }
static const ParsedAttrInfoVisibility Instance;
};
const ParsedAttrInfoVisibility ParsedAttrInfoVisibility::Instance;
static constexpr ParsedAttrInfo::Spelling WarnUnusedSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "warn_unused"},
  {AttributeCommonInfo::AS_CXX11, "gnu::warn_unused"},
  {AttributeCommonInfo::AS_C2x, "gnu::warn_unused"},
};
struct ParsedAttrInfoWarnUnused final : public ParsedAttrInfo {
  ParsedAttrInfoWarnUnused() {
    AttrKind = ParsedAttr::AT_WarnUnused;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 1;
    IsSupportedByPragmaAttribute = 1;
    Spellings = WarnUnusedSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<RecordDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "structs, unions, and classes";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_record, /*IsSupported=*/true));
}

AttrHandling handleDeclAttribute(Sema &S, Decl *D,const ParsedAttr &Attr) const override {
  D->addAttr(::new (S.Context) WarnUnusedAttr(S.Context, Attr));
  return AttributeApplied;
}

static const ParsedAttrInfoWarnUnused Instance;
};
const ParsedAttrInfoWarnUnused ParsedAttrInfoWarnUnused::Instance;
static constexpr ParsedAttrInfo::Spelling WarnUnusedResultSpellings[] = {
  {AttributeCommonInfo::AS_CXX11, "nodiscard"},
  {AttributeCommonInfo::AS_C2x, "nodiscard"},
  {AttributeCommonInfo::AS_CXX11, "clang::warn_unused_result"},
  {AttributeCommonInfo::AS_GNU, "warn_unused_result"},
  {AttributeCommonInfo::AS_CXX11, "gnu::warn_unused_result"},
  {AttributeCommonInfo::AS_C2x, "gnu::warn_unused_result"},
};
static constexpr const char *WarnUnusedResultArgNames[] = {
"Message",};
struct ParsedAttrInfoWarnUnusedResult final : public ParsedAttrInfo {
  ParsedAttrInfoWarnUnusedResult() {
    AttrKind = ParsedAttr::AT_WarnUnusedResult;
    NumArgs = 0;
    OptArgs = 1;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 1;
    IsSupportedByPragmaAttribute = 1;
    Spellings = WarnUnusedResultSpellings;
    ArgNames = WarnUnusedResultArgNames;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<ObjCMethodDecl>(D) && !isa<EnumDecl>(D) && !isa<RecordDecl>(D) && !isFunctionLike(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "Objective-C methods, enums, structs, unions, classes, functions, and function pointers";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

unsigned spellingIndexToSemanticSpelling(const ParsedAttr &Attr) const override {
  enum Spelling {
    CXX11_nodiscard = 0,
    C2x_nodiscard = 1,
    CXX11_clang_warn_unused_result = 2,
    GNU_warn_unused_result = 3,
    CXX11_gnu_warn_unused_result = 4,
    C2x_gnu_warn_unused_result = 5,
  SpellingNotCalculated = 15

  };

  unsigned Idx = Attr.getAttributeSpellingListIndex();
  switch (Idx) {
    default: llvm_unreachable("Unknown spelling list index");
    case 0: return CXX11_nodiscard;
    case 1: return C2x_nodiscard;
    case 2: return CXX11_clang_warn_unused_result;
    case 3: return GNU_warn_unused_result;
    case 4: return CXX11_gnu_warn_unused_result;
    case 5: return C2x_gnu_warn_unused_result;
  }
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_objc_method, /*IsSupported=*/LangOpts.ObjC));
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_enum, /*IsSupported=*/true));
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_record, /*IsSupported=*/true));
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_hasType_functionType, /*IsSupported=*/true));
}

static const ParsedAttrInfoWarnUnusedResult Instance;
};
const ParsedAttrInfoWarnUnusedResult ParsedAttrInfoWarnUnusedResult::Instance;
static constexpr ParsedAttrInfo::Spelling WeakSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "weak"},
  {AttributeCommonInfo::AS_CXX11, "gnu::weak"},
  {AttributeCommonInfo::AS_C2x, "gnu::weak"},
};
struct ParsedAttrInfoWeak final : public ParsedAttrInfo {
  ParsedAttrInfoWeak() {
    AttrKind = ParsedAttr::AT_Weak;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 1;
    IsSupportedByPragmaAttribute = 1;
    Spellings = WeakSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<VarDecl>(D) && !isa<FunctionDecl>(D) && !isa<CXXRecordDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "variables, functions, and classes";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_variable, /*IsSupported=*/true));
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_function, /*IsSupported=*/true));
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_record, /*IsSupported=*/true));
}

AttrHandling handleDeclAttribute(Sema &S, Decl *D,const ParsedAttr &Attr) const override {
  D->addAttr(::new (S.Context) WeakAttr(S.Context, Attr));
  return AttributeApplied;
}

static const ParsedAttrInfoWeak Instance;
};
const ParsedAttrInfoWeak ParsedAttrInfoWeak::Instance;
static constexpr ParsedAttrInfo::Spelling WeakImportSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "weak_import"},
  {AttributeCommonInfo::AS_CXX11, "clang::weak_import"},
  {AttributeCommonInfo::AS_C2x, "clang::weak_import"},
};
struct ParsedAttrInfoWeakImport final : public ParsedAttrInfo {
  ParsedAttrInfoWeakImport() {
    AttrKind = ParsedAttr::AT_WeakImport;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 0;
    Spellings = WeakImportSpellings;
  }
static const ParsedAttrInfoWeakImport Instance;
};
const ParsedAttrInfoWeakImport ParsedAttrInfoWeakImport::Instance;
static constexpr ParsedAttrInfo::Spelling WeakRefSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "weakref"},
  {AttributeCommonInfo::AS_CXX11, "gnu::weakref"},
  {AttributeCommonInfo::AS_C2x, "gnu::weakref"},
};
static constexpr const char *WeakRefArgNames[] = {
"Aliasee",};
struct ParsedAttrInfoWeakRef final : public ParsedAttrInfo {
  ParsedAttrInfoWeakRef() {
    AttrKind = ParsedAttr::AT_WeakRef;
    NumArgs = 0;
    OptArgs = 1;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 1;
    IsSupportedByPragmaAttribute = 1;
    Spellings = WeakRefSpellings;
    ArgNames = WeakRefArgNames;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<VarDecl>(D) && !isa<FunctionDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::err_attribute_wrong_decl_type_str)
      << Attr << "variables and functions";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_variable, /*IsSupported=*/true));
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_function, /*IsSupported=*/true));
}

static const ParsedAttrInfoWeakRef Instance;
};
const ParsedAttrInfoWeakRef ParsedAttrInfoWeakRef::Instance;
static constexpr ParsedAttrInfo::Spelling WebAssemblyExportNameSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "export_name"},
  {AttributeCommonInfo::AS_CXX11, "clang::export_name"},
  {AttributeCommonInfo::AS_C2x, "clang::export_name"},
};
static constexpr const char *WebAssemblyExportNameArgNames[] = {
"ExportName",};
struct ParsedAttrInfoWebAssemblyExportName final : public ParsedAttrInfo {
  ParsedAttrInfoWebAssemblyExportName() {
    AttrKind = ParsedAttr::AT_WebAssemblyExportName;
    NumArgs = 1;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 1;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = WebAssemblyExportNameSpellings;
    ArgNames = WebAssemblyExportNameArgNames;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FunctionDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::err_attribute_wrong_decl_type_str)
      << Attr << "functions";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

bool existsInTarget(const TargetInfo &Target) const override {
  const llvm::Triple &T = Target.getTriple(); (void)T;
  return true && (T.getArch() == llvm::Triple::wasm32 || T.getArch() == llvm::Triple::wasm64);
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_function, /*IsSupported=*/true));
}

static const ParsedAttrInfoWebAssemblyExportName Instance;
};
const ParsedAttrInfoWebAssemblyExportName ParsedAttrInfoWebAssemblyExportName::Instance;
static constexpr ParsedAttrInfo::Spelling WebAssemblyImportModuleSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "import_module"},
  {AttributeCommonInfo::AS_CXX11, "clang::import_module"},
  {AttributeCommonInfo::AS_C2x, "clang::import_module"},
};
static constexpr const char *WebAssemblyImportModuleArgNames[] = {
"ImportModule",};
struct ParsedAttrInfoWebAssemblyImportModule final : public ParsedAttrInfo {
  ParsedAttrInfoWebAssemblyImportModule() {
    AttrKind = ParsedAttr::AT_WebAssemblyImportModule;
    NumArgs = 1;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 1;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = WebAssemblyImportModuleSpellings;
    ArgNames = WebAssemblyImportModuleArgNames;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FunctionDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::err_attribute_wrong_decl_type_str)
      << Attr << "functions";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

bool existsInTarget(const TargetInfo &Target) const override {
  const llvm::Triple &T = Target.getTriple(); (void)T;
  return true && (T.getArch() == llvm::Triple::wasm32 || T.getArch() == llvm::Triple::wasm64);
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_function, /*IsSupported=*/true));
}

static const ParsedAttrInfoWebAssemblyImportModule Instance;
};
const ParsedAttrInfoWebAssemblyImportModule ParsedAttrInfoWebAssemblyImportModule::Instance;
static constexpr ParsedAttrInfo::Spelling WebAssemblyImportNameSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "import_name"},
  {AttributeCommonInfo::AS_CXX11, "clang::import_name"},
  {AttributeCommonInfo::AS_C2x, "clang::import_name"},
};
static constexpr const char *WebAssemblyImportNameArgNames[] = {
"ImportName",};
struct ParsedAttrInfoWebAssemblyImportName final : public ParsedAttrInfo {
  ParsedAttrInfoWebAssemblyImportName() {
    AttrKind = ParsedAttr::AT_WebAssemblyImportName;
    NumArgs = 1;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 1;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = WebAssemblyImportNameSpellings;
    ArgNames = WebAssemblyImportNameArgNames;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FunctionDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::err_attribute_wrong_decl_type_str)
      << Attr << "functions";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

bool existsInTarget(const TargetInfo &Target) const override {
  const llvm::Triple &T = Target.getTriple(); (void)T;
  return true && (T.getArch() == llvm::Triple::wasm32 || T.getArch() == llvm::Triple::wasm64);
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_function, /*IsSupported=*/true));
}

static const ParsedAttrInfoWebAssemblyImportName Instance;
};
const ParsedAttrInfoWebAssemblyImportName ParsedAttrInfoWebAssemblyImportName::Instance;
static constexpr ParsedAttrInfo::Spelling WorkGroupSizeHintSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "work_group_size_hint"},
};
static constexpr const char *WorkGroupSizeHintArgNames[] = {
"XDim","YDim","ZDim",};
struct ParsedAttrInfoWorkGroupSizeHint final : public ParsedAttrInfo {
  ParsedAttrInfoWorkGroupSizeHint() {
    AttrKind = ParsedAttr::AT_WorkGroupSizeHint;
    NumArgs = 3;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = WorkGroupSizeHintSpellings;
    ArgNames = WorkGroupSizeHintArgNames;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FunctionDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::err_attribute_wrong_decl_type_str)
      << Attr << "functions";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_function, /*IsSupported=*/true));
}

static const ParsedAttrInfoWorkGroupSizeHint Instance;
};
const ParsedAttrInfoWorkGroupSizeHint ParsedAttrInfoWorkGroupSizeHint::Instance;
static constexpr ParsedAttrInfo::Spelling X86ForceAlignArgPointerSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "force_align_arg_pointer"},
  {AttributeCommonInfo::AS_CXX11, "gnu::force_align_arg_pointer"},
  {AttributeCommonInfo::AS_C2x, "gnu::force_align_arg_pointer"},
};
struct ParsedAttrInfoX86ForceAlignArgPointer final : public ParsedAttrInfo {
  ParsedAttrInfoX86ForceAlignArgPointer() {
    AttrKind = ParsedAttr::AT_X86ForceAlignArgPointer;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 1;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 1;
    IsSupportedByPragmaAttribute = 0;
    Spellings = X86ForceAlignArgPointerSpellings;
  }
bool existsInTarget(const TargetInfo &Target) const override {
  const llvm::Triple &T = Target.getTriple(); (void)T;
  return true && (T.getArch() == llvm::Triple::x86 || T.getArch() == llvm::Triple::x86_64);
}

static const ParsedAttrInfoX86ForceAlignArgPointer Instance;
};
const ParsedAttrInfoX86ForceAlignArgPointer ParsedAttrInfoX86ForceAlignArgPointer::Instance;
static constexpr ParsedAttrInfo::Spelling XRayInstrumentSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "xray_always_instrument"},
  {AttributeCommonInfo::AS_CXX11, "clang::xray_always_instrument"},
  {AttributeCommonInfo::AS_C2x, "clang::xray_always_instrument"},
  {AttributeCommonInfo::AS_GNU, "xray_never_instrument"},
  {AttributeCommonInfo::AS_CXX11, "clang::xray_never_instrument"},
  {AttributeCommonInfo::AS_C2x, "clang::xray_never_instrument"},
};
struct ParsedAttrInfoXRayInstrument final : public ParsedAttrInfo {
  ParsedAttrInfoXRayInstrument() {
    AttrKind = ParsedAttr::AT_XRayInstrument;
    NumArgs = 0;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = XRayInstrumentSpellings;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FunctionDecl>(D) && !isa<ObjCMethodDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "functions and Objective-C methods";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

unsigned spellingIndexToSemanticSpelling(const ParsedAttr &Attr) const override {
  enum Spelling {
    GNU_xray_always_instrument = 0,
    CXX11_clang_xray_always_instrument = 1,
    C2x_clang_xray_always_instrument = 2,
    GNU_xray_never_instrument = 3,
    CXX11_clang_xray_never_instrument = 4,
    C2x_clang_xray_never_instrument = 5,
  SpellingNotCalculated = 15

  };

  unsigned Idx = Attr.getAttributeSpellingListIndex();
  switch (Idx) {
    default: llvm_unreachable("Unknown spelling list index");
    case 0: return GNU_xray_always_instrument;
    case 1: return CXX11_clang_xray_always_instrument;
    case 2: return C2x_clang_xray_always_instrument;
    case 3: return GNU_xray_never_instrument;
    case 4: return CXX11_clang_xray_never_instrument;
    case 5: return C2x_clang_xray_never_instrument;
  }
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_function, /*IsSupported=*/true));
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_objc_method, /*IsSupported=*/LangOpts.ObjC));
}

AttrHandling handleDeclAttribute(Sema &S, Decl *D,const ParsedAttr &Attr) const override {
  D->addAttr(::new (S.Context) XRayInstrumentAttr(S.Context, Attr));
  return AttributeApplied;
}

static const ParsedAttrInfoXRayInstrument Instance;
};
const ParsedAttrInfoXRayInstrument ParsedAttrInfoXRayInstrument::Instance;
static constexpr ParsedAttrInfo::Spelling XRayLogArgsSpellings[] = {
  {AttributeCommonInfo::AS_GNU, "xray_log_args"},
  {AttributeCommonInfo::AS_CXX11, "clang::xray_log_args"},
  {AttributeCommonInfo::AS_C2x, "clang::xray_log_args"},
};
static constexpr const char *XRayLogArgsArgNames[] = {
"ArgumentCount",};
struct ParsedAttrInfoXRayLogArgs final : public ParsedAttrInfo {
  ParsedAttrInfoXRayLogArgs() {
    AttrKind = ParsedAttr::AT_XRayLogArgs;
    NumArgs = 1;
    OptArgs = 0;
    HasCustomParsing = 0;
    IsTargetSpecific = 0;
    IsType = 0;
    IsStmt = 0;
    IsKnownToGCC = 0;
    IsSupportedByPragmaAttribute = 1;
    Spellings = XRayLogArgsSpellings;
    ArgNames = XRayLogArgsArgNames;
  }
bool diagAppertainsToDecl(Sema &S, const ParsedAttr &Attr, const Decl *D) const override {
  if (!isa<FunctionDecl>(D) && !isa<ObjCMethodDecl>(D)) {
    S.Diag(Attr.getLoc(), diag::warn_attribute_wrong_decl_type_str)
      << Attr << "functions and Objective-C methods";
    return false;
  }
  return true;
}

bool diagAppertainsToStmt(Sema &S, const ParsedAttr &AL, const Stmt *St) const override {
  S.Diag(AL.getLoc(), diag::err_decl_attribute_invalid_on_stmt)
    << AL << St->getBeginLoc();
  return false;
}

void getPragmaAttributeMatchRules(llvm::SmallVectorImpl<std::pair<attr::SubjectMatchRule, bool>> &MatchRules, const LangOptions &LangOpts) const override {
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_function, /*IsSupported=*/true));
  MatchRules.push_back(std::make_pair(attr::SubjectMatchRule_objc_method, /*IsSupported=*/LangOpts.ObjC));
}

static const ParsedAttrInfoXRayLogArgs Instance;
};
const ParsedAttrInfoXRayLogArgs ParsedAttrInfoXRayLogArgs::Instance;
static const ParsedAttrInfo *AttrInfoMap[] = {
&ParsedAttrInfoAArch64VectorPcs::Instance,
&ParsedAttrInfoAMDGPUFlatWorkGroupSize::Instance,
&ParsedAttrInfoAMDGPUNumSGPR::Instance,
&ParsedAttrInfoAMDGPUNumVGPR::Instance,
&ParsedAttrInfoAMDGPUWavesPerEU::Instance,
&ParsedAttrInfoInterrupt::Instance,
&ParsedAttrInfoAVRSignal::Instance,
&ParsedAttrInfoAbiTag::Instance,
&ParsedAttrInfoAcquireCapability::Instance,
&ParsedAttrInfoAcquireHandle::Instance,
&ParsedAttrInfoAcquiredAfter::Instance,
&ParsedAttrInfoAcquiredBefore::Instance,
&ParsedAttrInfoAddressSpace::Instance,
&ParsedAttrInfoAlias::Instance,
&ParsedAttrInfoAlignValue::Instance,
&ParsedAttrInfoAligned::Instance,
&ParsedAttrInfoAllocAlign::Instance,
&ParsedAttrInfoAllocSize::Instance,
&ParsedAttrInfoAlwaysDestroy::Instance,
&ParsedAttrInfoAlwaysInline::Instance,
&ParsedAttrInfoAnalyzerNoReturn::Instance,
&ParsedAttrInfoAnnotate::Instance,
&ParsedAttrInfoAnyX86NoCallerSavedRegisters::Instance,
&ParsedAttrInfoAnyX86NoCfCheck::Instance,
&ParsedAttrInfoArcWeakrefUnavailable::Instance,
&ParsedAttrInfoArgumentWithTypeTag::Instance,
&ParsedAttrInfoArmBuiltinAlias::Instance,
&ParsedAttrInfoArmMveStrictPolymorphism::Instance,
&ParsedAttrInfoArmSveVectorBits::Instance,
&ParsedAttrInfoArtificial::Instance,
&ParsedAttrInfoAssertCapability::Instance,
&ParsedAttrInfoAssertExclusiveLock::Instance,
&ParsedAttrInfoAssertSharedLock::Instance,
&ParsedAttrInfoAssumeAligned::Instance,
&ParsedAttrInfoAssumption::Instance,
&ParsedAttrInfoAvailability::Instance,
&ParsedAttrInfoBPFPreserveAccessIndex::Instance,
&ParsedAttrInfoBTFDeclTag::Instance,
&ParsedAttrInfoBTFTypeTag::Instance,
&ParsedAttrInfoBlocks::Instance,
&ParsedAttrInfoBuiltinAlias::Instance,
&ParsedAttrInfoCDecl::Instance,
&ParsedAttrInfoCFAuditedTransfer::Instance,
&ParsedAttrInfoCFConsumed::Instance,
&ParsedAttrInfoCFGuard::Instance,
&ParsedAttrInfoCFICanonicalJumpTable::Instance,
&ParsedAttrInfoCFReturnsNotRetained::Instance,
&ParsedAttrInfoCFReturnsRetained::Instance,
&ParsedAttrInfoCFUnknownTransfer::Instance,
&ParsedAttrInfoCPUDispatch::Instance,
&ParsedAttrInfoCPUSpecific::Instance,
&ParsedAttrInfoCUDAConstant::Instance,
&ParsedAttrInfoCUDADevice::Instance,
&ParsedAttrInfoCUDADeviceBuiltinSurfaceType::Instance,
&ParsedAttrInfoCUDADeviceBuiltinTextureType::Instance,
&ParsedAttrInfoCUDAGlobal::Instance,
&ParsedAttrInfoCUDAHost::Instance,
&ParsedAttrInfoCUDAInvalidTarget::Instance,
&ParsedAttrInfoCUDALaunchBounds::Instance,
&ParsedAttrInfoCUDAShared::Instance,
&ParsedAttrInfoCXX11NoReturn::Instance,
&ParsedAttrInfoCallableWhen::Instance,
&ParsedAttrInfoCallback::Instance,
&ParsedAttrInfoCalledOnce::Instance,
&ParsedAttrInfoCapability::Instance,
&ParsedAttrInfoCarriesDependency::Instance,
&ParsedAttrInfoCleanup::Instance,
&ParsedAttrInfoCmseNSCall::Instance,
&ParsedAttrInfoCmseNSEntry::Instance,
&ParsedAttrInfoCodeSeg::Instance,
&ParsedAttrInfoCold::Instance,
&ParsedAttrInfoCommon::Instance,
&ParsedAttrInfoConst::Instance,
&ParsedAttrInfoConstInit::Instance,
&ParsedAttrInfoConstructor::Instance,
&ParsedAttrInfoConsumable::Instance,
&ParsedAttrInfoConsumableAutoCast::Instance,
&ParsedAttrInfoConsumableSetOnRead::Instance,
&ParsedAttrInfoConvergent::Instance,
&ParsedAttrInfoDLLExport::Instance,
&ParsedAttrInfoDLLExportStaticLocal::Instance,
&ParsedAttrInfoDLLImport::Instance,
&ParsedAttrInfoDLLImportStaticLocal::Instance,
&ParsedAttrInfoDeprecated::Instance,
&ParsedAttrInfoDestructor::Instance,
&ParsedAttrInfoDiagnoseAsBuiltin::Instance,
&ParsedAttrInfoDiagnoseIf::Instance,
&ParsedAttrInfoDisableSanitizerInstrumentation::Instance,
&ParsedAttrInfoDisableTailCalls::Instance,
&ParsedAttrInfoEmptyBases::Instance,
&ParsedAttrInfoEnableIf::Instance,
&ParsedAttrInfoEnforceTCB::Instance,
&ParsedAttrInfoEnforceTCBLeaf::Instance,
&ParsedAttrInfoEnumExtensibility::Instance,
&ParsedAttrInfoError::Instance,
&ParsedAttrInfoExcludeFromExplicitInstantiation::Instance,
&ParsedAttrInfoExclusiveTrylockFunction::Instance,
&ParsedAttrInfoExtVectorType::Instance,
&ParsedAttrInfoExternalSourceSymbol::Instance,
&ParsedAttrInfoFallThrough::Instance,
&ParsedAttrInfoFastCall::Instance,
&ParsedAttrInfoFlagEnum::Instance,
&ParsedAttrInfoFlatten::Instance,
&ParsedAttrInfoFormat::Instance,
&ParsedAttrInfoFormatArg::Instance,
&ParsedAttrInfoGNUInline::Instance,
&ParsedAttrInfoGuardedBy::Instance,
&ParsedAttrInfoGuardedVar::Instance,
&ParsedAttrInfoHIPManaged::Instance,
&ParsedAttrInfoHot::Instance,
&ParsedAttrInfoIBAction::Instance,
&ParsedAttrInfoIBOutlet::Instance,
&ParsedAttrInfoIBOutletCollection::Instance,
&ParsedAttrInfoIFunc::Instance,
&ParsedAttrInfoInitPriority::Instance,
&ParsedAttrInfoIntelOclBicc::Instance,
&ParsedAttrInfoInternalLinkage::Instance,
&ParsedAttrInfoLTOVisibilityPublic::Instance,
&ParsedAttrInfoLayoutVersion::Instance,
&ParsedAttrInfoLeaf::Instance,
&ParsedAttrInfoLifetimeBound::Instance,
&ParsedAttrInfoLikely::Instance,
&ParsedAttrInfoLoaderUninitialized::Instance,
&ParsedAttrInfoLockReturned::Instance,
&ParsedAttrInfoLockable::Instance,
&ParsedAttrInfoLocksExcluded::Instance,
&ParsedAttrInfoLoopHint::Instance,
&ParsedAttrInfoMIGServerRoutine::Instance,
&ParsedAttrInfoMSABI::Instance,
&ParsedAttrInfoMSAllocator::Instance,
&ParsedAttrInfoMSInheritance::Instance,
&ParsedAttrInfoMSNoVTable::Instance,
&ParsedAttrInfoMSStruct::Instance,
&ParsedAttrInfoMatrixType::Instance,
&ParsedAttrInfoMayAlias::Instance,
&ParsedAttrInfoMicroMips::Instance,
&ParsedAttrInfoMinSize::Instance,
&ParsedAttrInfoMinVectorWidth::Instance,
&ParsedAttrInfoMips16::Instance,
&ParsedAttrInfoMipsLongCall::Instance,
&ParsedAttrInfoMipsShortCall::Instance,
&ParsedAttrInfoMode::Instance,
&ParsedAttrInfoMustTail::Instance,
&ParsedAttrInfoNSConsumed::Instance,
&ParsedAttrInfoNSConsumesSelf::Instance,
&ParsedAttrInfoNSErrorDomain::Instance,
&ParsedAttrInfoNSReturnsAutoreleased::Instance,
&ParsedAttrInfoNSReturnsNotRetained::Instance,
&ParsedAttrInfoNSReturnsRetained::Instance,
&ParsedAttrInfoNaked::Instance,
&ParsedAttrInfoNeonPolyVectorType::Instance,
&ParsedAttrInfoNeonVectorType::Instance,
&ParsedAttrInfoNoAlias::Instance,
&ParsedAttrInfoNoBuiltin::Instance,
&ParsedAttrInfoNoCommon::Instance,
&ParsedAttrInfoNoDebug::Instance,
&ParsedAttrInfoNoDeref::Instance,
&ParsedAttrInfoNoDestroy::Instance,
&ParsedAttrInfoNoDuplicate::Instance,
&ParsedAttrInfoNoEscape::Instance,
&ParsedAttrInfoNoInline::Instance,
&ParsedAttrInfoNoInstrumentFunction::Instance,
&ParsedAttrInfoNoMerge::Instance,
&ParsedAttrInfoNoMicroMips::Instance,
&ParsedAttrInfoNoMips16::Instance,
&ParsedAttrInfoNoProfileFunction::Instance,
&ParsedAttrInfoNoReturn::Instance,
&ParsedAttrInfoNoSanitize::Instance,
&ParsedAttrInfoNoSanitizeSpecific::Instance,
&ParsedAttrInfoNoSpeculativeLoadHardening::Instance,
&ParsedAttrInfoNoSplitStack::Instance,
&ParsedAttrInfoNoStackProtector::Instance,
&ParsedAttrInfoNoThreadSafetyAnalysis::Instance,
&ParsedAttrInfoNoThrow::Instance,
&ParsedAttrInfoNoUniqueAddress::Instance,
&ParsedAttrInfoNonNull::Instance,
&ParsedAttrInfoNotTailCalled::Instance,
&ParsedAttrInfoOSConsumed::Instance,
&ParsedAttrInfoOSConsumesThis::Instance,
&ParsedAttrInfoOSReturnsNotRetained::Instance,
&ParsedAttrInfoOSReturnsRetained::Instance,
&ParsedAttrInfoOSReturnsRetainedOnNonZero::Instance,
&ParsedAttrInfoOSReturnsRetainedOnZero::Instance,
&ParsedAttrInfoObjCBoxable::Instance,
&ParsedAttrInfoObjCBridge::Instance,
&ParsedAttrInfoObjCBridgeMutable::Instance,
&ParsedAttrInfoObjCBridgeRelated::Instance,
&ParsedAttrInfoObjCClassStub::Instance,
&ParsedAttrInfoObjCDesignatedInitializer::Instance,
&ParsedAttrInfoObjCDirect::Instance,
&ParsedAttrInfoObjCDirectMembers::Instance,
&ParsedAttrInfoObjCException::Instance,
&ParsedAttrInfoObjCExplicitProtocolImpl::Instance,
&ParsedAttrInfoObjCExternallyRetained::Instance,
&ParsedAttrInfoObjCGC::Instance,
&ParsedAttrInfoObjCIndependentClass::Instance,
&ParsedAttrInfoObjCInertUnsafeUnretained::Instance,
&ParsedAttrInfoObjCKindOf::Instance,
&ParsedAttrInfoObjCMethodFamily::Instance,
&ParsedAttrInfoObjCNSObject::Instance,
&ParsedAttrInfoObjCNonLazyClass::Instance,
&ParsedAttrInfoObjCNonRuntimeProtocol::Instance,
&ParsedAttrInfoObjCOwnership::Instance,
&ParsedAttrInfoObjCPreciseLifetime::Instance,
&ParsedAttrInfoObjCRequiresPropertyDefs::Instance,
&ParsedAttrInfoObjCRequiresSuper::Instance,
&ParsedAttrInfoObjCReturnsInnerPointer::Instance,
&ParsedAttrInfoObjCRootClass::Instance,
&ParsedAttrInfoObjCRuntimeName::Instance,
&ParsedAttrInfoObjCRuntimeVisible::Instance,
&ParsedAttrInfoObjCSubclassingRestricted::Instance,
&ParsedAttrInfoOpenCLAccess::Instance,
&ParsedAttrInfoOpenCLConstantAddressSpace::Instance,
&ParsedAttrInfoOpenCLGenericAddressSpace::Instance,
&ParsedAttrInfoOpenCLGlobalAddressSpace::Instance,
&ParsedAttrInfoOpenCLGlobalDeviceAddressSpace::Instance,
&ParsedAttrInfoOpenCLGlobalHostAddressSpace::Instance,
&ParsedAttrInfoOpenCLIntelReqdSubGroupSize::Instance,
&ParsedAttrInfoOpenCLKernel::Instance,
&ParsedAttrInfoOpenCLLocalAddressSpace::Instance,
&ParsedAttrInfoOpenCLNoSVM::Instance,
&ParsedAttrInfoOpenCLPrivateAddressSpace::Instance,
&ParsedAttrInfoOpenCLUnrollHint::Instance,
&ParsedAttrInfoOptimizeNone::Instance,
&ParsedAttrInfoOverloadable::Instance,
&ParsedAttrInfoOwner::Instance,
&ParsedAttrInfoOwnership::Instance,
&ParsedAttrInfoPacked::Instance,
&ParsedAttrInfoParamTypestate::Instance,
&ParsedAttrInfoPascal::Instance,
&ParsedAttrInfoPassObjectSize::Instance,
&ParsedAttrInfoPatchableFunctionEntry::Instance,
&ParsedAttrInfoPcs::Instance,
&ParsedAttrInfoPointer::Instance,
&ParsedAttrInfoPragmaClangBSSSection::Instance,
&ParsedAttrInfoPragmaClangDataSection::Instance,
&ParsedAttrInfoPragmaClangRelroSection::Instance,
&ParsedAttrInfoPragmaClangRodataSection::Instance,
&ParsedAttrInfoPragmaClangTextSection::Instance,
&ParsedAttrInfoPreferredName::Instance,
&ParsedAttrInfoPreserveAll::Instance,
&ParsedAttrInfoPreserveMost::Instance,
&ParsedAttrInfoPtGuardedBy::Instance,
&ParsedAttrInfoPtGuardedVar::Instance,
&ParsedAttrInfoPtr32::Instance,
&ParsedAttrInfoPtr64::Instance,
&ParsedAttrInfoPure::Instance,
&ParsedAttrInfoRegCall::Instance,
&ParsedAttrInfoRegparm::Instance,
&ParsedAttrInfoReinitializes::Instance,
&ParsedAttrInfoReleaseCapability::Instance,
&ParsedAttrInfoReleaseHandle::Instance,
&ParsedAttrInfoRenderScriptKernel::Instance,
&ParsedAttrInfoReqdWorkGroupSize::Instance,
&ParsedAttrInfoRequiresCapability::Instance,
&ParsedAttrInfoRestrict::Instance,
&ParsedAttrInfoRetain::Instance,
&ParsedAttrInfoReturnTypestate::Instance,
&ParsedAttrInfoReturnsNonNull::Instance,
&ParsedAttrInfoReturnsTwice::Instance,
&ParsedAttrInfoSPtr::Instance,
&ParsedAttrInfoSYCLKernel::Instance,
&ParsedAttrInfoScopedLockable::Instance,
&ParsedAttrInfoSection::Instance,
&ParsedAttrInfoSelectAny::Instance,
&ParsedAttrInfoSentinel::Instance,
&ParsedAttrInfoSetTypestate::Instance,
&ParsedAttrInfoSharedTrylockFunction::Instance,
&ParsedAttrInfoSpeculativeLoadHardening::Instance,
&ParsedAttrInfoStandaloneDebug::Instance,
&ParsedAttrInfoStdCall::Instance,
&ParsedAttrInfoStrictFP::Instance,
&ParsedAttrInfoSuppress::Instance,
&ParsedAttrInfoSwiftAsync::Instance,
&ParsedAttrInfoSwiftAsyncCall::Instance,
&ParsedAttrInfoSwiftAsyncContext::Instance,
&ParsedAttrInfoSwiftAsyncError::Instance,
&ParsedAttrInfoSwiftAsyncName::Instance,
&ParsedAttrInfoSwiftAttr::Instance,
&ParsedAttrInfoSwiftBridge::Instance,
&ParsedAttrInfoSwiftBridgedTypedef::Instance,
&ParsedAttrInfoSwiftCall::Instance,
&ParsedAttrInfoSwiftContext::Instance,
&ParsedAttrInfoSwiftError::Instance,
&ParsedAttrInfoSwiftErrorResult::Instance,
&ParsedAttrInfoSwiftIndirectResult::Instance,
&ParsedAttrInfoSwiftName::Instance,
&ParsedAttrInfoSwiftNewType::Instance,
&ParsedAttrInfoSwiftObjCMembers::Instance,
&ParsedAttrInfoSwiftPrivate::Instance,
&ParsedAttrInfoSysVABI::Instance,
&ParsedAttrInfoTLSModel::Instance,
&ParsedAttrInfoTarget::Instance,
&ParsedAttrInfoTargetClones::Instance,
&ParsedAttrInfoTestTypestate::Instance,
&ParsedAttrInfoThisCall::Instance,
&ParsedAttrInfoThread::Instance,
&ParsedAttrInfoTransparentUnion::Instance,
&ParsedAttrInfoTrivialABI::Instance,
&ParsedAttrInfoTryAcquireCapability::Instance,
&ParsedAttrInfoTypeNonNull::Instance,
&ParsedAttrInfoTypeNullUnspecified::Instance,
&ParsedAttrInfoTypeNullable::Instance,
&ParsedAttrInfoTypeNullableResult::Instance,
&ParsedAttrInfoTypeTagForDatatype::Instance,
&ParsedAttrInfoTypeVisibility::Instance,
&ParsedAttrInfoUPtr::Instance,
&ParsedAttrInfoUnavailable::Instance,
&ParsedAttrInfoUninitialized::Instance,
&ParsedAttrInfoUnlikely::Instance,
&ParsedAttrInfoUnused::Instance,
&ParsedAttrInfoUseHandle::Instance,
&ParsedAttrInfoUsed::Instance,
&ParsedAttrInfoUsingIfExists::Instance,
&ParsedAttrInfoUuid::Instance,
&ParsedAttrInfoVecReturn::Instance,
&ParsedAttrInfoVecTypeHint::Instance,
&ParsedAttrInfoVectorCall::Instance,
&ParsedAttrInfoVectorSize::Instance,
&ParsedAttrInfoVisibility::Instance,
&ParsedAttrInfoWarnUnused::Instance,
&ParsedAttrInfoWarnUnusedResult::Instance,
&ParsedAttrInfoWeak::Instance,
&ParsedAttrInfoWeakImport::Instance,
&ParsedAttrInfoWeakRef::Instance,
&ParsedAttrInfoWebAssemblyExportName::Instance,
&ParsedAttrInfoWebAssemblyImportModule::Instance,
&ParsedAttrInfoWebAssemblyImportName::Instance,
&ParsedAttrInfoWorkGroupSizeHint::Instance,
&ParsedAttrInfoX86ForceAlignArgPointer::Instance,
&ParsedAttrInfoXRayInstrument::Instance,
&ParsedAttrInfoXRayLogArgs::Instance,
};

static bool checkAttributeMatchRuleAppliesTo(const Decl *D, attr::SubjectMatchRule rule) {
  switch (rule) {
  case attr::SubjectMatchRule_block:
    return isa<BlockDecl>(D);
  case attr::SubjectMatchRule_enum:
    return isa<EnumDecl>(D);
  case attr::SubjectMatchRule_enum_constant:
    return isa<EnumConstantDecl>(D);
  case attr::SubjectMatchRule_field:
    return isa<FieldDecl>(D);
  case attr::SubjectMatchRule_function:
    return isa<FunctionDecl>(D);
  case attr::SubjectMatchRule_function_is_member:
    return isa<CXXMethodDecl>(D);
  case attr::SubjectMatchRule_namespace:
    return isa<NamespaceDecl>(D);
  case attr::SubjectMatchRule_objc_category:
    return isa<ObjCCategoryDecl>(D);
  case attr::SubjectMatchRule_objc_implementation:
    return isa<ObjCImplDecl>(D);
  case attr::SubjectMatchRule_objc_interface:
    return isa<ObjCInterfaceDecl>(D);
  case attr::SubjectMatchRule_objc_method:
    return isa<ObjCMethodDecl>(D);
  case attr::SubjectMatchRule_objc_method_is_instance:
    return isObjCInstanceMethod(D);
  case attr::SubjectMatchRule_objc_property:
    return isa<ObjCPropertyDecl>(D);
  case attr::SubjectMatchRule_objc_protocol:
    return isa<ObjCProtocolDecl>(D);
  case attr::SubjectMatchRule_record:
    return isa<RecordDecl>(D) || isa<CXXRecordDecl>(D);
  case attr::SubjectMatchRule_record_not_is_union:
    return isStruct(D);
  case attr::SubjectMatchRule_hasType_abstract:
    assert(false && "Abstract matcher rule isn't allowed");
    return false;
  case attr::SubjectMatchRule_hasType_functionType:
    return isFunctionLike(D);
  case attr::SubjectMatchRule_type_alias:
    return isa<TypedefNameDecl>(D);
  case attr::SubjectMatchRule_variable:
    return isa<VarDecl>(D);
  case attr::SubjectMatchRule_variable_is_thread_local:
    return isTLSVar(D);
  case attr::SubjectMatchRule_variable_is_global:
    return isGlobalVar(D);
  case attr::SubjectMatchRule_variable_is_local:
    return isLocalVar(D);
  case attr::SubjectMatchRule_variable_is_parameter:
    return isa<ParmVarDecl>(D);
  case attr::SubjectMatchRule_variable_not_is_parameter:
    return isNonParmVar(D);
  }
  llvm_unreachable("Invalid match rule");
return false;
}

#elif defined(WANT_DECL_MERGE_LOGIC)

static bool DiagnoseMutualExclusions(Sema &S, const NamedDecl *D, const Attr *A) {
  if (const auto *Second = dyn_cast<AlwaysDestroyAttr>(A)) {
    if (const auto *First = D->getAttr<NoDestroyAttr>()) {
      S.Diag(First->getLocation(), diag::err_attributes_are_not_compatible) << First << Second;
      S.Diag(Second->getLocation(), diag::note_conflicting_attribute);
      return false;
    }
    return true;
  }
  if (const auto *Second = dyn_cast<AlwaysInlineAttr>(A)) {
    if (const auto *First = D->getAttr<NotTailCalledAttr>()) {
      S.Diag(First->getLocation(), diag::err_attributes_are_not_compatible) << First << Second;
      S.Diag(Second->getLocation(), diag::note_conflicting_attribute);
      return false;
    }
    return true;
  }
  if (const auto *Second = dyn_cast<CFAuditedTransferAttr>(A)) {
    if (const auto *First = D->getAttr<CFUnknownTransferAttr>()) {
      S.Diag(First->getLocation(), diag::err_attributes_are_not_compatible) << First << Second;
      S.Diag(Second->getLocation(), diag::note_conflicting_attribute);
      return false;
    }
    return true;
  }
  if (const auto *Second = dyn_cast<CFUnknownTransferAttr>(A)) {
    if (const auto *First = D->getAttr<CFAuditedTransferAttr>()) {
      S.Diag(First->getLocation(), diag::err_attributes_are_not_compatible) << First << Second;
      S.Diag(Second->getLocation(), diag::note_conflicting_attribute);
      return false;
    }
    return true;
  }
  if (const auto *Second = dyn_cast<CPUDispatchAttr>(A)) {
    if (const auto *First = D->getAttr<TargetClonesAttr>()) {
      S.Diag(First->getLocation(), diag::err_attributes_are_not_compatible) << First << Second;
      S.Diag(Second->getLocation(), diag::note_conflicting_attribute);
      return false;
    }
    if (const auto *First = D->getAttr<TargetAttr>()) {
      S.Diag(First->getLocation(), diag::err_attributes_are_not_compatible) << First << Second;
      S.Diag(Second->getLocation(), diag::note_conflicting_attribute);
      return false;
    }
    if (const auto *First = D->getAttr<CPUSpecificAttr>()) {
      S.Diag(First->getLocation(), diag::err_attributes_are_not_compatible) << First << Second;
      S.Diag(Second->getLocation(), diag::note_conflicting_attribute);
      return false;
    }
    return true;
  }
  if (const auto *Second = dyn_cast<CPUSpecificAttr>(A)) {
    if (const auto *First = D->getAttr<TargetClonesAttr>()) {
      S.Diag(First->getLocation(), diag::err_attributes_are_not_compatible) << First << Second;
      S.Diag(Second->getLocation(), diag::note_conflicting_attribute);
      return false;
    }
    if (const auto *First = D->getAttr<TargetAttr>()) {
      S.Diag(First->getLocation(), diag::err_attributes_are_not_compatible) << First << Second;
      S.Diag(Second->getLocation(), diag::note_conflicting_attribute);
      return false;
    }
    if (const auto *First = D->getAttr<CPUDispatchAttr>()) {
      S.Diag(First->getLocation(), diag::err_attributes_are_not_compatible) << First << Second;
      S.Diag(Second->getLocation(), diag::note_conflicting_attribute);
      return false;
    }
    return true;
  }
  if (const auto *Second = dyn_cast<CUDAConstantAttr>(A)) {
    if (const auto *First = D->getAttr<CUDASharedAttr>()) {
      S.Diag(First->getLocation(), diag::err_attributes_are_not_compatible) << First << Second;
      S.Diag(Second->getLocation(), diag::note_conflicting_attribute);
      return false;
    }
    if (const auto *First = D->getAttr<HIPManagedAttr>()) {
      S.Diag(First->getLocation(), diag::err_attributes_are_not_compatible) << First << Second;
      S.Diag(Second->getLocation(), diag::note_conflicting_attribute);
      return false;
    }
    return true;
  }
  if (const auto *Second = dyn_cast<CUDADeviceAttr>(A)) {
    if (const auto *First = D->getAttr<CUDAGlobalAttr>()) {
      S.Diag(First->getLocation(), diag::err_attributes_are_not_compatible) << First << Second;
      S.Diag(Second->getLocation(), diag::note_conflicting_attribute);
      return false;
    }
    return true;
  }
  if (const auto *Second = dyn_cast<CUDADeviceBuiltinSurfaceTypeAttr>(A)) {
    if (const auto *First = D->getAttr<CUDADeviceBuiltinTextureTypeAttr>()) {
      S.Diag(First->getLocation(), diag::err_attributes_are_not_compatible) << First << Second;
      S.Diag(Second->getLocation(), diag::note_conflicting_attribute);
      return false;
    }
    return true;
  }
  if (const auto *Second = dyn_cast<CUDADeviceBuiltinTextureTypeAttr>(A)) {
    if (const auto *First = D->getAttr<CUDADeviceBuiltinSurfaceTypeAttr>()) {
      S.Diag(First->getLocation(), diag::err_attributes_are_not_compatible) << First << Second;
      S.Diag(Second->getLocation(), diag::note_conflicting_attribute);
      return false;
    }
    return true;
  }
  if (const auto *Second = dyn_cast<CUDAGlobalAttr>(A)) {
    if (const auto *First = D->getAttr<CUDADeviceAttr>()) {
      S.Diag(First->getLocation(), diag::err_attributes_are_not_compatible) << First << Second;
      S.Diag(Second->getLocation(), diag::note_conflicting_attribute);
      return false;
    }
    if (const auto *First = D->getAttr<CUDAHostAttr>()) {
      S.Diag(First->getLocation(), diag::err_attributes_are_not_compatible) << First << Second;
      S.Diag(Second->getLocation(), diag::note_conflicting_attribute);
      return false;
    }
    return true;
  }
  if (const auto *Second = dyn_cast<CUDAHostAttr>(A)) {
    if (const auto *First = D->getAttr<CUDAGlobalAttr>()) {
      S.Diag(First->getLocation(), diag::err_attributes_are_not_compatible) << First << Second;
      S.Diag(Second->getLocation(), diag::note_conflicting_attribute);
      return false;
    }
    return true;
  }
  if (const auto *Second = dyn_cast<CUDASharedAttr>(A)) {
    if (const auto *First = D->getAttr<CUDAConstantAttr>()) {
      S.Diag(First->getLocation(), diag::err_attributes_are_not_compatible) << First << Second;
      S.Diag(Second->getLocation(), diag::note_conflicting_attribute);
      return false;
    }
    if (const auto *First = D->getAttr<HIPManagedAttr>()) {
      S.Diag(First->getLocation(), diag::err_attributes_are_not_compatible) << First << Second;
      S.Diag(Second->getLocation(), diag::note_conflicting_attribute);
      return false;
    }
    return true;
  }
  if (const auto *Second = dyn_cast<ColdAttr>(A)) {
    if (const auto *First = D->getAttr<HotAttr>()) {
      S.Diag(First->getLocation(), diag::err_attributes_are_not_compatible) << First << Second;
      S.Diag(Second->getLocation(), diag::note_conflicting_attribute);
      return false;
    }
    return true;
  }
  if (const auto *Second = dyn_cast<CommonAttr>(A)) {
    if (const auto *First = D->getAttr<InternalLinkageAttr>()) {
      S.Diag(First->getLocation(), diag::err_attributes_are_not_compatible) << First << Second;
      S.Diag(Second->getLocation(), diag::note_conflicting_attribute);
      return false;
    }
    return true;
  }
  if (const auto *Second = dyn_cast<DisableTailCallsAttr>(A)) {
    if (const auto *First = D->getAttr<NakedAttr>()) {
      S.Diag(First->getLocation(), diag::err_attributes_are_not_compatible) << First << Second;
      S.Diag(Second->getLocation(), diag::note_conflicting_attribute);
      return false;
    }
    return true;
  }
  if (const auto *Second = dyn_cast<HIPManagedAttr>(A)) {
    if (const auto *First = D->getAttr<CUDAConstantAttr>()) {
      S.Diag(First->getLocation(), diag::err_attributes_are_not_compatible) << First << Second;
      S.Diag(Second->getLocation(), diag::note_conflicting_attribute);
      return false;
    }
    if (const auto *First = D->getAttr<CUDASharedAttr>()) {
      S.Diag(First->getLocation(), diag::err_attributes_are_not_compatible) << First << Second;
      S.Diag(Second->getLocation(), diag::note_conflicting_attribute);
      return false;
    }
    return true;
  }
  if (const auto *Second = dyn_cast<HotAttr>(A)) {
    if (const auto *First = D->getAttr<ColdAttr>()) {
      S.Diag(First->getLocation(), diag::err_attributes_are_not_compatible) << First << Second;
      S.Diag(Second->getLocation(), diag::note_conflicting_attribute);
      return false;
    }
    return true;
  }
  if (const auto *Second = dyn_cast<InternalLinkageAttr>(A)) {
    if (const auto *First = D->getAttr<CommonAttr>()) {
      S.Diag(First->getLocation(), diag::err_attributes_are_not_compatible) << First << Second;
      S.Diag(Second->getLocation(), diag::note_conflicting_attribute);
      return false;
    }
    return true;
  }
  if (const auto *Second = dyn_cast<MicroMipsAttr>(A)) {
    if (const auto *First = D->getAttr<Mips16Attr>()) {
      S.Diag(First->getLocation(), diag::err_attributes_are_not_compatible) << First << Second;
      S.Diag(Second->getLocation(), diag::note_conflicting_attribute);
      return false;
    }
    return true;
  }
  if (const auto *Second = dyn_cast<Mips16Attr>(A)) {
    if (const auto *First = D->getAttr<MipsInterruptAttr>()) {
      S.Diag(First->getLocation(), diag::err_attributes_are_not_compatible) << First << Second;
      S.Diag(Second->getLocation(), diag::note_conflicting_attribute);
      return false;
    }
    if (const auto *First = D->getAttr<MicroMipsAttr>()) {
      S.Diag(First->getLocation(), diag::err_attributes_are_not_compatible) << First << Second;
      S.Diag(Second->getLocation(), diag::note_conflicting_attribute);
      return false;
    }
    return true;
  }
  if (const auto *Second = dyn_cast<MipsLongCallAttr>(A)) {
    if (const auto *First = D->getAttr<MipsShortCallAttr>()) {
      S.Diag(First->getLocation(), diag::err_attributes_are_not_compatible) << First << Second;
      S.Diag(Second->getLocation(), diag::note_conflicting_attribute);
      return false;
    }
    return true;
  }
  if (const auto *Second = dyn_cast<MipsShortCallAttr>(A)) {
    if (const auto *First = D->getAttr<MipsLongCallAttr>()) {
      S.Diag(First->getLocation(), diag::err_attributes_are_not_compatible) << First << Second;
      S.Diag(Second->getLocation(), diag::note_conflicting_attribute);
      return false;
    }
    return true;
  }
  if (const auto *Second = dyn_cast<NakedAttr>(A)) {
    if (const auto *First = D->getAttr<DisableTailCallsAttr>()) {
      S.Diag(First->getLocation(), diag::err_attributes_are_not_compatible) << First << Second;
      S.Diag(Second->getLocation(), diag::note_conflicting_attribute);
      return false;
    }
    return true;
  }
  if (const auto *Second = dyn_cast<NoDestroyAttr>(A)) {
    if (const auto *First = D->getAttr<AlwaysDestroyAttr>()) {
      S.Diag(First->getLocation(), diag::err_attributes_are_not_compatible) << First << Second;
      S.Diag(Second->getLocation(), diag::note_conflicting_attribute);
      return false;
    }
    return true;
  }
  if (const auto *Second = dyn_cast<NoSpeculativeLoadHardeningAttr>(A)) {
    if (const auto *First = D->getAttr<SpeculativeLoadHardeningAttr>()) {
      S.Diag(First->getLocation(), diag::err_attributes_are_not_compatible) << First << Second;
      S.Diag(Second->getLocation(), diag::note_conflicting_attribute);
      return false;
    }
    return true;
  }
  if (const auto *Second = dyn_cast<NotTailCalledAttr>(A)) {
    if (const auto *First = D->getAttr<AlwaysInlineAttr>()) {
      S.Diag(First->getLocation(), diag::err_attributes_are_not_compatible) << First << Second;
      S.Diag(Second->getLocation(), diag::note_conflicting_attribute);
      return false;
    }
    return true;
  }
  if (const auto *Second = dyn_cast<OwnerAttr>(A)) {
    if (const auto *First = D->getAttr<PointerAttr>()) {
      S.Diag(First->getLocation(), diag::err_attributes_are_not_compatible) << First << Second;
      S.Diag(Second->getLocation(), diag::note_conflicting_attribute);
      return false;
    }
    return true;
  }
  if (const auto *Second = dyn_cast<PointerAttr>(A)) {
    if (const auto *First = D->getAttr<OwnerAttr>()) {
      S.Diag(First->getLocation(), diag::err_attributes_are_not_compatible) << First << Second;
      S.Diag(Second->getLocation(), diag::note_conflicting_attribute);
      return false;
    }
    return true;
  }
  if (const auto *Second = dyn_cast<SpeculativeLoadHardeningAttr>(A)) {
    if (const auto *First = D->getAttr<NoSpeculativeLoadHardeningAttr>()) {
      S.Diag(First->getLocation(), diag::err_attributes_are_not_compatible) << First << Second;
      S.Diag(Second->getLocation(), diag::note_conflicting_attribute);
      return false;
    }
    return true;
  }
  if (const auto *Second = dyn_cast<TargetAttr>(A)) {
    if (const auto *First = D->getAttr<TargetClonesAttr>()) {
      S.Diag(First->getLocation(), diag::err_attributes_are_not_compatible) << First << Second;
      S.Diag(Second->getLocation(), diag::note_conflicting_attribute);
      return false;
    }
    if (const auto *First = D->getAttr<CPUDispatchAttr>()) {
      S.Diag(First->getLocation(), diag::err_attributes_are_not_compatible) << First << Second;
      S.Diag(Second->getLocation(), diag::note_conflicting_attribute);
      return false;
    }
    if (const auto *First = D->getAttr<CPUSpecificAttr>()) {
      S.Diag(First->getLocation(), diag::err_attributes_are_not_compatible) << First << Second;
      S.Diag(Second->getLocation(), diag::note_conflicting_attribute);
      return false;
    }
    return true;
  }
  if (const auto *Second = dyn_cast<TargetClonesAttr>(A)) {
    if (const auto *First = D->getAttr<TargetAttr>()) {
      S.Diag(First->getLocation(), diag::err_attributes_are_not_compatible) << First << Second;
      S.Diag(Second->getLocation(), diag::note_conflicting_attribute);
      return false;
    }
    if (const auto *First = D->getAttr<CPUDispatchAttr>()) {
      S.Diag(First->getLocation(), diag::err_attributes_are_not_compatible) << First << Second;
      S.Diag(Second->getLocation(), diag::note_conflicting_attribute);
      return false;
    }
    if (const auto *First = D->getAttr<CPUSpecificAttr>()) {
      S.Diag(First->getLocation(), diag::err_attributes_are_not_compatible) << First << Second;
      S.Diag(Second->getLocation(), diag::note_conflicting_attribute);
      return false;
    }
    return true;
  }
  return true;
}

#elif defined(WANT_STMT_MERGE_LOGIC)

static bool DiagnoseMutualExclusions(Sema &S, const SmallVectorImpl<const Attr *> &C) {
  for (const Attr *A : C) {
    if (const auto *Second = dyn_cast<LikelyAttr>(A)) {
      auto Iter = llvm::find_if(C, [](const Attr *Check) { return isa<UnlikelyAttr>(Check); });
      if (Iter != C.end()) {
        S.Diag((*Iter)->getLocation(), diag::err_attributes_are_not_compatible) << *Iter << Second;
        S.Diag(Second->getLocation(), diag::note_conflicting_attribute);
        return false;
      }
    }
    if (const auto *Second = dyn_cast<UnlikelyAttr>(A)) {
      auto Iter = llvm::find_if(C, [](const Attr *Check) { return isa<LikelyAttr>(Check); });
      if (Iter != C.end()) {
        S.Diag((*Iter)->getLocation(), diag::err_attributes_are_not_compatible) << *Iter << Second;
        S.Diag(Second->getLocation(), diag::note_conflicting_attribute);
        return false;
      }
    }
  }
  return true;
}

#endif
