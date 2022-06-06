/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Attribute text node dumper                                                 *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

  void VisitAMDGPUNumSGPRAttr(const AMDGPUNumSGPRAttr *A) {
    const auto *SA = cast<AMDGPUNumSGPRAttr>(A); (void)SA;
    OS << " " << SA->getNumSGPR();
  }
  void VisitAMDGPUNumVGPRAttr(const AMDGPUNumVGPRAttr *A) {
    const auto *SA = cast<AMDGPUNumVGPRAttr>(A); (void)SA;
    OS << " " << SA->getNumVGPR();
  }
  void VisitARMInterruptAttr(const ARMInterruptAttr *A) {
    const auto *SA = cast<ARMInterruptAttr>(A); (void)SA;
    switch(SA->getInterrupt()) {
    case ARMInterruptAttr::IRQ:
      OS << " IRQ";
      break;
    case ARMInterruptAttr::FIQ:
      OS << " FIQ";
      break;
    case ARMInterruptAttr::SWI:
      OS << " SWI";
      break;
    case ARMInterruptAttr::ABORT:
      OS << " ABORT";
      break;
    case ARMInterruptAttr::UNDEF:
      OS << " UNDEF";
      break;
    case ARMInterruptAttr::Generic:
      OS << " Generic";
      break;
    }
  }
  void VisitAbiTagAttr(const AbiTagAttr *A) {
    const auto *SA = cast<AbiTagAttr>(A); (void)SA;
    for (const auto &Val : SA->tags())
      OS << " " << Val;
  }
  void VisitAcquireCapabilityAttr(const AcquireCapabilityAttr *A) {
    const auto *SA = cast<AcquireCapabilityAttr>(A); (void)SA;
    OS << " " << A->getSpelling();
  }
  void VisitAcquireHandleAttr(const AcquireHandleAttr *A) {
    const auto *SA = cast<AcquireHandleAttr>(A); (void)SA;
    OS << " \"" << SA->getHandleType() << "\"";
  }
  void VisitAddressSpaceAttr(const AddressSpaceAttr *A) {
    const auto *SA = cast<AddressSpaceAttr>(A); (void)SA;
    OS << " " << SA->getAddressSpace();
  }
  void VisitAliasAttr(const AliasAttr *A) {
    const auto *SA = cast<AliasAttr>(A); (void)SA;
    OS << " \"" << SA->getAliasee() << "\"";
  }
  void VisitAlignedAttr(const AlignedAttr *A) {
    const auto *SA = cast<AlignedAttr>(A); (void)SA;
    OS << " " << A->getSpelling();
    if (!SA->isAlignmentExpr())
      dumpType(SA->getAlignmentType()->getType());
  }
  void VisitAllocAlignAttr(const AllocAlignAttr *A) {
    const auto *SA = cast<AllocAlignAttr>(A); (void)SA;
    OS << " " << SA->getParamIndex().getSourceIndex();
  }
  void VisitAllocSizeAttr(const AllocSizeAttr *A) {
    const auto *SA = cast<AllocSizeAttr>(A); (void)SA;
    OS << " " << SA->getElemSizeParam().getSourceIndex();
    if (SA->getNumElemsParam().isValid())
      OS << " " << SA->getNumElemsParam().getSourceIndex();
  }
  void VisitAlwaysInlineAttr(const AlwaysInlineAttr *A) {
    OS << " " << A->getSpelling();
  }
  void VisitAnnotateAttr(const AnnotateAttr *A) {
    const auto *SA = cast<AnnotateAttr>(A); (void)SA;
    OS << " \"" << SA->getAnnotation() << "\"";
  }
  void VisitArgumentWithTypeTagAttr(const ArgumentWithTypeTagAttr *A) {
    const auto *SA = cast<ArgumentWithTypeTagAttr>(A); (void)SA;
    OS << " " << A->getSpelling();
    if (SA->getArgumentKind())
      OS << " " << SA->getArgumentKind()->getName();
    OS << " " << SA->getArgumentIdx().getSourceIndex();
    OS << " " << SA->getTypeTagIdx().getSourceIndex();
    if (SA->getIsPointer()) OS << " IsPointer";
  }
  void VisitArmBuiltinAliasAttr(const ArmBuiltinAliasAttr *A) {
    const auto *SA = cast<ArmBuiltinAliasAttr>(A); (void)SA;
    if (SA->getBuiltinName())
      OS << " " << SA->getBuiltinName()->getName();
  }
  void VisitAsmLabelAttr(const AsmLabelAttr *A) {
    const auto *SA = cast<AsmLabelAttr>(A); (void)SA;
    OS << " \"" << SA->getLabel() << "\"";
    if (SA->getIsLiteralLabel()) OS << " IsLiteralLabel";
  }
  void VisitAssertCapabilityAttr(const AssertCapabilityAttr *A) {
    const auto *SA = cast<AssertCapabilityAttr>(A); (void)SA;
    OS << " " << A->getSpelling();
  }
  void VisitAssumptionAttr(const AssumptionAttr *A) {
    const auto *SA = cast<AssumptionAttr>(A); (void)SA;
    OS << " \"" << SA->getAssumption() << "\"";
  }
  void VisitAvailabilityAttr(const AvailabilityAttr *A) {
    const auto *SA = cast<AvailabilityAttr>(A); (void)SA;
    if (SA->getPlatform())
      OS << " " << SA->getPlatform()->getName();
    OS << " " << SA->getIntroduced();
    OS << " " << SA->getDeprecated();
    OS << " " << SA->getObsoleted();
    if (SA->getUnavailable()) OS << " Unavailable";
    OS << " \"" << SA->getMessage() << "\"";
    if (SA->getStrict()) OS << " Strict";
    OS << " \"" << SA->getReplacement() << "\"";
    OS << " " << SA->getPriority();
  }
  void VisitBTFDeclTagAttr(const BTFDeclTagAttr *A) {
    const auto *SA = cast<BTFDeclTagAttr>(A); (void)SA;
    OS << " \"" << SA->getBTFDeclTag() << "\"";
  }
  void VisitBTFTypeTagAttr(const BTFTypeTagAttr *A) {
    const auto *SA = cast<BTFTypeTagAttr>(A); (void)SA;
    OS << " \"" << SA->getBTFTypeTag() << "\"";
  }
  void VisitBlocksAttr(const BlocksAttr *A) {
    const auto *SA = cast<BlocksAttr>(A); (void)SA;
    switch(SA->getType()) {
    case BlocksAttr::ByRef:
      OS << " ByRef";
      break;
    }
  }
  void VisitBuiltinAttr(const BuiltinAttr *A) {
    const auto *SA = cast<BuiltinAttr>(A); (void)SA;
    OS << " " << SA->getID();
  }
  void VisitBuiltinAliasAttr(const BuiltinAliasAttr *A) {
    const auto *SA = cast<BuiltinAliasAttr>(A); (void)SA;
    OS << " " << A->getSpelling();
    if (SA->getBuiltinName())
      OS << " " << SA->getBuiltinName()->getName();
  }
  void VisitCFGuardAttr(const CFGuardAttr *A) {
    const auto *SA = cast<CFGuardAttr>(A); (void)SA;
    switch(SA->getGuard()) {
    case CFGuardAttr::nocf:
      OS << " nocf";
      break;
    }
  }
  void VisitCPUDispatchAttr(const CPUDispatchAttr *A) {
    const auto *SA = cast<CPUDispatchAttr>(A); (void)SA;
    for (const auto &Val : SA->cpus())
      OS << " " << Val;
  }
  void VisitCPUSpecificAttr(const CPUSpecificAttr *A) {
    const auto *SA = cast<CPUSpecificAttr>(A); (void)SA;
    for (const auto &Val : SA->cpus())
      OS << " " << Val;
  }
  void VisitCallableWhenAttr(const CallableWhenAttr *A) {
    const auto *SA = cast<CallableWhenAttr>(A); (void)SA;
    for (CallableWhenAttr::callableStates_iterator I = SA->callableStates_begin(), E = SA->callableStates_end(); I != E; ++I) {
      switch(*I) {
    case CallableWhenAttr::Unknown:
      OS << " Unknown";
      break;
    case CallableWhenAttr::Consumed:
      OS << " Consumed";
      break;
    case CallableWhenAttr::Unconsumed:
      OS << " Unconsumed";
      break;
      }
    }
  }
  void VisitCallbackAttr(const CallbackAttr *A) {
    const auto *SA = cast<CallbackAttr>(A); (void)SA;
    for (const auto &Val : SA->encoding())
      OS << " " << Val;
  }
  void VisitCapabilityAttr(const CapabilityAttr *A) {
    const auto *SA = cast<CapabilityAttr>(A); (void)SA;
    OS << " " << A->getSpelling();
    OS << " \"" << SA->getName() << "\"";
  }
  void VisitCleanupAttr(const CleanupAttr *A) {
    const auto *SA = cast<CleanupAttr>(A); (void)SA;
    OS << " ";
    dumpBareDeclRef(SA->getFunctionDecl());
  }
  void VisitCodeSegAttr(const CodeSegAttr *A) {
    const auto *SA = cast<CodeSegAttr>(A); (void)SA;
    OS << " \"" << SA->getName() << "\"";
  }
  void VisitConstInitAttr(const ConstInitAttr *A) {
    OS << " " << A->getSpelling();
  }
  void VisitConstructorAttr(const ConstructorAttr *A) {
    const auto *SA = cast<ConstructorAttr>(A); (void)SA;
    OS << " " << SA->getPriority();
  }
  void VisitConsumableAttr(const ConsumableAttr *A) {
    const auto *SA = cast<ConsumableAttr>(A); (void)SA;
    switch(SA->getDefaultState()) {
    case ConsumableAttr::Unknown:
      OS << " Unknown";
      break;
    case ConsumableAttr::Consumed:
      OS << " Consumed";
      break;
    case ConsumableAttr::Unconsumed:
      OS << " Unconsumed";
      break;
    }
  }
  void VisitDeprecatedAttr(const DeprecatedAttr *A) {
    const auto *SA = cast<DeprecatedAttr>(A); (void)SA;
    OS << " \"" << SA->getMessage() << "\"";
    OS << " \"" << SA->getReplacement() << "\"";
  }
  void VisitDestructorAttr(const DestructorAttr *A) {
    const auto *SA = cast<DestructorAttr>(A); (void)SA;
    OS << " " << SA->getPriority();
  }
  void VisitDiagnoseAsBuiltinAttr(const DiagnoseAsBuiltinAttr *A) {
    const auto *SA = cast<DiagnoseAsBuiltinAttr>(A); (void)SA;
    OS << " ";
    dumpBareDeclRef(SA->getFunction());
    for (const auto &Val : SA->argIndices())
      OS << " " << Val;
  }
  void VisitDiagnoseIfAttr(const DiagnoseIfAttr *A) {
    const auto *SA = cast<DiagnoseIfAttr>(A); (void)SA;
    OS << " \"" << SA->getMessage() << "\"";
    switch(SA->getDiagnosticType()) {
    case DiagnoseIfAttr::DT_Error:
      OS << " DT_Error";
      break;
    case DiagnoseIfAttr::DT_Warning:
      OS << " DT_Warning";
      break;
    }
    if (SA->getArgDependent()) OS << " ArgDependent";
    OS << " ";
    dumpBareDeclRef(SA->getParent());
  }
  void VisitEnableIfAttr(const EnableIfAttr *A) {
    const auto *SA = cast<EnableIfAttr>(A); (void)SA;
    OS << " \"" << SA->getMessage() << "\"";
  }
  void VisitEnforceTCBAttr(const EnforceTCBAttr *A) {
    const auto *SA = cast<EnforceTCBAttr>(A); (void)SA;
    OS << " \"" << SA->getTCBName() << "\"";
  }
  void VisitEnforceTCBLeafAttr(const EnforceTCBLeafAttr *A) {
    const auto *SA = cast<EnforceTCBLeafAttr>(A); (void)SA;
    OS << " \"" << SA->getTCBName() << "\"";
  }
  void VisitEnumExtensibilityAttr(const EnumExtensibilityAttr *A) {
    const auto *SA = cast<EnumExtensibilityAttr>(A); (void)SA;
    switch(SA->getExtensibility()) {
    case EnumExtensibilityAttr::Closed:
      OS << " Closed";
      break;
    case EnumExtensibilityAttr::Open:
      OS << " Open";
      break;
    }
  }
  void VisitErrorAttr(const ErrorAttr *A) {
    const auto *SA = cast<ErrorAttr>(A); (void)SA;
    OS << " " << A->getSpelling();
    OS << " \"" << SA->getUserDiagnostic() << "\"";
  }
  void VisitExternalSourceSymbolAttr(const ExternalSourceSymbolAttr *A) {
    const auto *SA = cast<ExternalSourceSymbolAttr>(A); (void)SA;
    OS << " \"" << SA->getLanguage() << "\"";
    OS << " \"" << SA->getDefinedIn() << "\"";
    if (SA->getGeneratedDeclaration()) OS << " GeneratedDeclaration";
  }
  void VisitFinalAttr(const FinalAttr *A) {
    OS << " " << A->getSpelling();
  }
  void VisitFormatAttr(const FormatAttr *A) {
    const auto *SA = cast<FormatAttr>(A); (void)SA;
    if (SA->getType())
      OS << " " << SA->getType()->getName();
    OS << " " << SA->getFormatIdx();
    OS << " " << SA->getFirstArg();
  }
  void VisitFormatArgAttr(const FormatArgAttr *A) {
    const auto *SA = cast<FormatArgAttr>(A); (void)SA;
    OS << " " << SA->getFormatIdx().getSourceIndex();
  }
  void VisitIBOutletCollectionAttr(const IBOutletCollectionAttr *A) {
    const auto *SA = cast<IBOutletCollectionAttr>(A); (void)SA;
    if (SA->getInterfaceLoc())    OS << " " << SA->getInterface().getAsString();
  }
  void VisitIFuncAttr(const IFuncAttr *A) {
    const auto *SA = cast<IFuncAttr>(A); (void)SA;
    OS << " \"" << SA->getResolver() << "\"";
  }
  void VisitInitPriorityAttr(const InitPriorityAttr *A) {
    const auto *SA = cast<InitPriorityAttr>(A); (void)SA;
    OS << " " << SA->getPriority();
  }
  void VisitInitSegAttr(const InitSegAttr *A) {
    const auto *SA = cast<InitSegAttr>(A); (void)SA;
    OS << " \"" << SA->getSection() << "\"";
  }
  void VisitLayoutVersionAttr(const LayoutVersionAttr *A) {
    const auto *SA = cast<LayoutVersionAttr>(A); (void)SA;
    OS << " " << SA->getVersion();
  }
  void VisitLoopHintAttr(const LoopHintAttr *A) {
    const auto *SA = cast<LoopHintAttr>(A); (void)SA;
    OS << " " << A->getSpelling();
    switch(SA->getOption()) {
    case LoopHintAttr::Vectorize:
      OS << " Vectorize";
      break;
    case LoopHintAttr::VectorizeWidth:
      OS << " VectorizeWidth";
      break;
    case LoopHintAttr::Interleave:
      OS << " Interleave";
      break;
    case LoopHintAttr::InterleaveCount:
      OS << " InterleaveCount";
      break;
    case LoopHintAttr::Unroll:
      OS << " Unroll";
      break;
    case LoopHintAttr::UnrollCount:
      OS << " UnrollCount";
      break;
    case LoopHintAttr::UnrollAndJam:
      OS << " UnrollAndJam";
      break;
    case LoopHintAttr::UnrollAndJamCount:
      OS << " UnrollAndJamCount";
      break;
    case LoopHintAttr::PipelineDisabled:
      OS << " PipelineDisabled";
      break;
    case LoopHintAttr::PipelineInitiationInterval:
      OS << " PipelineInitiationInterval";
      break;
    case LoopHintAttr::Distribute:
      OS << " Distribute";
      break;
    case LoopHintAttr::VectorizePredicate:
      OS << " VectorizePredicate";
      break;
    }
    switch(SA->getState()) {
    case LoopHintAttr::Enable:
      OS << " Enable";
      break;
    case LoopHintAttr::Disable:
      OS << " Disable";
      break;
    case LoopHintAttr::Numeric:
      OS << " Numeric";
      break;
    case LoopHintAttr::FixedWidth:
      OS << " FixedWidth";
      break;
    case LoopHintAttr::ScalableWidth:
      OS << " ScalableWidth";
      break;
    case LoopHintAttr::AssumeSafety:
      OS << " AssumeSafety";
      break;
    case LoopHintAttr::Full:
      OS << " Full";
      break;
    }
  }
  void VisitM68kInterruptAttr(const M68kInterruptAttr *A) {
    const auto *SA = cast<M68kInterruptAttr>(A); (void)SA;
    OS << " " << SA->getNumber();
  }
  void VisitMSInheritanceAttr(const MSInheritanceAttr *A) {
    const auto *SA = cast<MSInheritanceAttr>(A); (void)SA;
    OS << " " << A->getSpelling();
    if (SA->getBestCase()) OS << " BestCase";
  }
  void VisitMSP430InterruptAttr(const MSP430InterruptAttr *A) {
    const auto *SA = cast<MSP430InterruptAttr>(A); (void)SA;
    OS << " " << SA->getNumber();
  }
  void VisitMSVtorDispAttr(const MSVtorDispAttr *A) {
    const auto *SA = cast<MSVtorDispAttr>(A); (void)SA;
    OS << " " << SA->getVdm();
  }
  void VisitMaxFieldAlignmentAttr(const MaxFieldAlignmentAttr *A) {
    const auto *SA = cast<MaxFieldAlignmentAttr>(A); (void)SA;
    OS << " " << SA->getAlignment();
  }
  void VisitMinVectorWidthAttr(const MinVectorWidthAttr *A) {
    const auto *SA = cast<MinVectorWidthAttr>(A); (void)SA;
    OS << " " << SA->getVectorWidth();
  }
  void VisitMipsInterruptAttr(const MipsInterruptAttr *A) {
    const auto *SA = cast<MipsInterruptAttr>(A); (void)SA;
    switch(SA->getInterrupt()) {
    case MipsInterruptAttr::sw0:
      OS << " sw0";
      break;
    case MipsInterruptAttr::sw1:
      OS << " sw1";
      break;
    case MipsInterruptAttr::hw0:
      OS << " hw0";
      break;
    case MipsInterruptAttr::hw1:
      OS << " hw1";
      break;
    case MipsInterruptAttr::hw2:
      OS << " hw2";
      break;
    case MipsInterruptAttr::hw3:
      OS << " hw3";
      break;
    case MipsInterruptAttr::hw4:
      OS << " hw4";
      break;
    case MipsInterruptAttr::hw5:
      OS << " hw5";
      break;
    case MipsInterruptAttr::eic:
      OS << " eic";
      break;
    }
  }
  void VisitMipsLongCallAttr(const MipsLongCallAttr *A) {
    OS << " " << A->getSpelling();
  }
  void VisitMipsShortCallAttr(const MipsShortCallAttr *A) {
    OS << " " << A->getSpelling();
  }
  void VisitModeAttr(const ModeAttr *A) {
    const auto *SA = cast<ModeAttr>(A); (void)SA;
    if (SA->getMode())
      OS << " " << SA->getMode()->getName();
  }
  void VisitNSErrorDomainAttr(const NSErrorDomainAttr *A) {
    const auto *SA = cast<NSErrorDomainAttr>(A); (void)SA;
    OS << " ";
    dumpBareDeclRef(SA->getErrorDomain());
  }
  void VisitNoBuiltinAttr(const NoBuiltinAttr *A) {
    const auto *SA = cast<NoBuiltinAttr>(A); (void)SA;
    for (const auto &Val : SA->builtinNames())
      OS << " " << Val;
  }
  void VisitNoSanitizeAttr(const NoSanitizeAttr *A) {
    const auto *SA = cast<NoSanitizeAttr>(A); (void)SA;
    for (const auto &Val : SA->sanitizers())
      OS << " " << Val;
  }
  void VisitNonNullAttr(const NonNullAttr *A) {
    const auto *SA = cast<NonNullAttr>(A); (void)SA;
    for (const auto &Val : SA->args())
      OS << " " << Val.getSourceIndex();
  }
  void VisitOMPAllocateDeclAttr(const OMPAllocateDeclAttr *A) {
    const auto *SA = cast<OMPAllocateDeclAttr>(A); (void)SA;
    switch(SA->getAllocatorType()) {
    case OMPAllocateDeclAttr::OMPNullMemAlloc:
      OS << " OMPNullMemAlloc";
      break;
    case OMPAllocateDeclAttr::OMPDefaultMemAlloc:
      OS << " OMPDefaultMemAlloc";
      break;
    case OMPAllocateDeclAttr::OMPLargeCapMemAlloc:
      OS << " OMPLargeCapMemAlloc";
      break;
    case OMPAllocateDeclAttr::OMPConstMemAlloc:
      OS << " OMPConstMemAlloc";
      break;
    case OMPAllocateDeclAttr::OMPHighBWMemAlloc:
      OS << " OMPHighBWMemAlloc";
      break;
    case OMPAllocateDeclAttr::OMPLowLatMemAlloc:
      OS << " OMPLowLatMemAlloc";
      break;
    case OMPAllocateDeclAttr::OMPCGroupMemAlloc:
      OS << " OMPCGroupMemAlloc";
      break;
    case OMPAllocateDeclAttr::OMPPTeamMemAlloc:
      OS << " OMPPTeamMemAlloc";
      break;
    case OMPAllocateDeclAttr::OMPThreadMemAlloc:
      OS << " OMPThreadMemAlloc";
      break;
    case OMPAllocateDeclAttr::OMPUserDefinedMemAlloc:
      OS << " OMPUserDefinedMemAlloc";
      break;
    }
  }
  void VisitOMPCaptureKindAttr(const OMPCaptureKindAttr *A) {
    const auto *SA = cast<OMPCaptureKindAttr>(A); (void)SA;
    OS << " " << SA->getCaptureKindVal();
  }
  void VisitOMPDeclareSimdDeclAttr(const OMPDeclareSimdDeclAttr *A) {
    const auto *SA = cast<OMPDeclareSimdDeclAttr>(A); (void)SA;
    switch(SA->getBranchState()) {
    case OMPDeclareSimdDeclAttr::BS_Undefined:
      OS << " BS_Undefined";
      break;
    case OMPDeclareSimdDeclAttr::BS_Inbranch:
      OS << " BS_Inbranch";
      break;
    case OMPDeclareSimdDeclAttr::BS_Notinbranch:
      OS << " BS_Notinbranch";
      break;
    }
    for (const auto &Val : SA->modifiers())
      OS << " " << Val;
  }
  void VisitOMPDeclareTargetDeclAttr(const OMPDeclareTargetDeclAttr *A) {
    const auto *SA = cast<OMPDeclareTargetDeclAttr>(A); (void)SA;
    switch(SA->getMapType()) {
    case OMPDeclareTargetDeclAttr::MT_To:
      OS << " MT_To";
      break;
    case OMPDeclareTargetDeclAttr::MT_Link:
      OS << " MT_Link";
      break;
    }
    switch(SA->getDevType()) {
    case OMPDeclareTargetDeclAttr::DT_Host:
      OS << " DT_Host";
      break;
    case OMPDeclareTargetDeclAttr::DT_NoHost:
      OS << " DT_NoHost";
      break;
    case OMPDeclareTargetDeclAttr::DT_Any:
      OS << " DT_Any";
      break;
    }
    OS << " " << SA->getLevel();
  }
  void VisitOMPDeclareVariantAttr(const OMPDeclareVariantAttr *A) {
    const auto *SA = cast<OMPDeclareVariantAttr>(A); (void)SA;
    OS << " " << SA->getTraitInfos();
    for (OMPDeclareVariantAttr::appendArgs_iterator I = SA->appendArgs_begin(), E = SA->appendArgs_end(); I != E; ++I) {
      switch(*I) {
    case OMPDeclareVariantAttr::Target:
      OS << " Target";
      break;
    case OMPDeclareVariantAttr::TargetSync:
      OS << " TargetSync";
      break;
    case OMPDeclareVariantAttr::Target_TargetSync:
      OS << " Target_TargetSync";
      break;
      }
    }
  }
  void VisitObjCBridgeAttr(const ObjCBridgeAttr *A) {
    const auto *SA = cast<ObjCBridgeAttr>(A); (void)SA;
    if (SA->getBridgedType())
      OS << " " << SA->getBridgedType()->getName();
  }
  void VisitObjCBridgeMutableAttr(const ObjCBridgeMutableAttr *A) {
    const auto *SA = cast<ObjCBridgeMutableAttr>(A); (void)SA;
    if (SA->getBridgedType())
      OS << " " << SA->getBridgedType()->getName();
  }
  void VisitObjCBridgeRelatedAttr(const ObjCBridgeRelatedAttr *A) {
    const auto *SA = cast<ObjCBridgeRelatedAttr>(A); (void)SA;
    if (SA->getRelatedClass())
      OS << " " << SA->getRelatedClass()->getName();
    if (SA->getClassMethod())
      OS << " " << SA->getClassMethod()->getName();
    if (SA->getInstanceMethod())
      OS << " " << SA->getInstanceMethod()->getName();
  }
  void VisitObjCGCAttr(const ObjCGCAttr *A) {
    const auto *SA = cast<ObjCGCAttr>(A); (void)SA;
    if (SA->getKind())
      OS << " " << SA->getKind()->getName();
  }
  void VisitObjCMethodFamilyAttr(const ObjCMethodFamilyAttr *A) {
    const auto *SA = cast<ObjCMethodFamilyAttr>(A); (void)SA;
    switch(SA->getFamily()) {
    case ObjCMethodFamilyAttr::OMF_None:
      OS << " OMF_None";
      break;
    case ObjCMethodFamilyAttr::OMF_alloc:
      OS << " OMF_alloc";
      break;
    case ObjCMethodFamilyAttr::OMF_copy:
      OS << " OMF_copy";
      break;
    case ObjCMethodFamilyAttr::OMF_init:
      OS << " OMF_init";
      break;
    case ObjCMethodFamilyAttr::OMF_mutableCopy:
      OS << " OMF_mutableCopy";
      break;
    case ObjCMethodFamilyAttr::OMF_new:
      OS << " OMF_new";
      break;
    }
  }
  void VisitObjCOwnershipAttr(const ObjCOwnershipAttr *A) {
    const auto *SA = cast<ObjCOwnershipAttr>(A); (void)SA;
    if (SA->getKind())
      OS << " " << SA->getKind()->getName();
  }
  void VisitObjCRuntimeNameAttr(const ObjCRuntimeNameAttr *A) {
    const auto *SA = cast<ObjCRuntimeNameAttr>(A); (void)SA;
    OS << " \"" << SA->getMetadataName() << "\"";
  }
  void VisitOpenCLAccessAttr(const OpenCLAccessAttr *A) {
    OS << " " << A->getSpelling();
  }
  void VisitOpenCLConstantAddressSpaceAttr(const OpenCLConstantAddressSpaceAttr *A) {
    OS << " " << A->getSpelling();
  }
  void VisitOpenCLGenericAddressSpaceAttr(const OpenCLGenericAddressSpaceAttr *A) {
    OS << " " << A->getSpelling();
  }
  void VisitOpenCLGlobalAddressSpaceAttr(const OpenCLGlobalAddressSpaceAttr *A) {
    OS << " " << A->getSpelling();
  }
  void VisitOpenCLIntelReqdSubGroupSizeAttr(const OpenCLIntelReqdSubGroupSizeAttr *A) {
    const auto *SA = cast<OpenCLIntelReqdSubGroupSizeAttr>(A); (void)SA;
    OS << " " << SA->getSubGroupSize();
  }
  void VisitOpenCLLocalAddressSpaceAttr(const OpenCLLocalAddressSpaceAttr *A) {
    OS << " " << A->getSpelling();
  }
  void VisitOpenCLPrivateAddressSpaceAttr(const OpenCLPrivateAddressSpaceAttr *A) {
    OS << " " << A->getSpelling();
  }
  void VisitOpenCLUnrollHintAttr(const OpenCLUnrollHintAttr *A) {
    const auto *SA = cast<OpenCLUnrollHintAttr>(A); (void)SA;
    OS << " " << SA->getUnrollHint();
  }
  void VisitOwnerAttr(const OwnerAttr *A) {
    const auto *SA = cast<OwnerAttr>(A); (void)SA;
    if (SA->getDerefTypeLoc())    OS << " " << SA->getDerefType().getAsString();
  }
  void VisitOwnershipAttr(const OwnershipAttr *A) {
    const auto *SA = cast<OwnershipAttr>(A); (void)SA;
    OS << " " << A->getSpelling();
    if (SA->getModule())
      OS << " " << SA->getModule()->getName();
    for (const auto &Val : SA->args())
      OS << " " << Val.getSourceIndex();
  }
  void VisitParamTypestateAttr(const ParamTypestateAttr *A) {
    const auto *SA = cast<ParamTypestateAttr>(A); (void)SA;
    switch(SA->getParamState()) {
    case ParamTypestateAttr::Unknown:
      OS << " Unknown";
      break;
    case ParamTypestateAttr::Consumed:
      OS << " Consumed";
      break;
    case ParamTypestateAttr::Unconsumed:
      OS << " Unconsumed";
      break;
    }
  }
  void VisitPassObjectSizeAttr(const PassObjectSizeAttr *A) {
    const auto *SA = cast<PassObjectSizeAttr>(A); (void)SA;
    OS << " " << A->getSpelling();
    OS << " " << SA->getType();
  }
  void VisitPatchableFunctionEntryAttr(const PatchableFunctionEntryAttr *A) {
    const auto *SA = cast<PatchableFunctionEntryAttr>(A); (void)SA;
    OS << " " << SA->getCount();
    OS << " " << SA->getOffset();
  }
  void VisitPcsAttr(const PcsAttr *A) {
    const auto *SA = cast<PcsAttr>(A); (void)SA;
    switch(SA->getPCS()) {
    case PcsAttr::AAPCS:
      OS << " AAPCS";
      break;
    case PcsAttr::AAPCS_VFP:
      OS << " AAPCS_VFP";
      break;
    }
  }
  void VisitPointerAttr(const PointerAttr *A) {
    const auto *SA = cast<PointerAttr>(A); (void)SA;
    if (SA->getDerefTypeLoc())    OS << " " << SA->getDerefType().getAsString();
  }
  void VisitPragmaClangBSSSectionAttr(const PragmaClangBSSSectionAttr *A) {
    const auto *SA = cast<PragmaClangBSSSectionAttr>(A); (void)SA;
    OS << " \"" << SA->getName() << "\"";
  }
  void VisitPragmaClangDataSectionAttr(const PragmaClangDataSectionAttr *A) {
    const auto *SA = cast<PragmaClangDataSectionAttr>(A); (void)SA;
    OS << " \"" << SA->getName() << "\"";
  }
  void VisitPragmaClangRelroSectionAttr(const PragmaClangRelroSectionAttr *A) {
    const auto *SA = cast<PragmaClangRelroSectionAttr>(A); (void)SA;
    OS << " \"" << SA->getName() << "\"";
  }
  void VisitPragmaClangRodataSectionAttr(const PragmaClangRodataSectionAttr *A) {
    const auto *SA = cast<PragmaClangRodataSectionAttr>(A); (void)SA;
    OS << " \"" << SA->getName() << "\"";
  }
  void VisitPragmaClangTextSectionAttr(const PragmaClangTextSectionAttr *A) {
    const auto *SA = cast<PragmaClangTextSectionAttr>(A); (void)SA;
    OS << " \"" << SA->getName() << "\"";
  }
  void VisitPreferredNameAttr(const PreferredNameAttr *A) {
    const auto *SA = cast<PreferredNameAttr>(A); (void)SA;
    OS << " " << SA->getTypedefType().getAsString();
  }
  void VisitRISCVInterruptAttr(const RISCVInterruptAttr *A) {
    const auto *SA = cast<RISCVInterruptAttr>(A); (void)SA;
    switch(SA->getInterrupt()) {
    case RISCVInterruptAttr::user:
      OS << " user";
      break;
    case RISCVInterruptAttr::supervisor:
      OS << " supervisor";
      break;
    case RISCVInterruptAttr::machine:
      OS << " machine";
      break;
    }
  }
  void VisitReleaseCapabilityAttr(const ReleaseCapabilityAttr *A) {
    const auto *SA = cast<ReleaseCapabilityAttr>(A); (void)SA;
    OS << " " << A->getSpelling();
  }
  void VisitReleaseHandleAttr(const ReleaseHandleAttr *A) {
    const auto *SA = cast<ReleaseHandleAttr>(A); (void)SA;
    OS << " \"" << SA->getHandleType() << "\"";
  }
  void VisitReqdWorkGroupSizeAttr(const ReqdWorkGroupSizeAttr *A) {
    const auto *SA = cast<ReqdWorkGroupSizeAttr>(A); (void)SA;
    OS << " " << SA->getXDim();
    OS << " " << SA->getYDim();
    OS << " " << SA->getZDim();
  }
  void VisitRequiresCapabilityAttr(const RequiresCapabilityAttr *A) {
    const auto *SA = cast<RequiresCapabilityAttr>(A); (void)SA;
    OS << " " << A->getSpelling();
  }
  void VisitRestrictAttr(const RestrictAttr *A) {
    OS << " " << A->getSpelling();
  }
  void VisitReturnTypestateAttr(const ReturnTypestateAttr *A) {
    const auto *SA = cast<ReturnTypestateAttr>(A); (void)SA;
    switch(SA->getState()) {
    case ReturnTypestateAttr::Unknown:
      OS << " Unknown";
      break;
    case ReturnTypestateAttr::Consumed:
      OS << " Consumed";
      break;
    case ReturnTypestateAttr::Unconsumed:
      OS << " Unconsumed";
      break;
    }
  }
  void VisitSectionAttr(const SectionAttr *A) {
    const auto *SA = cast<SectionAttr>(A); (void)SA;
    OS << " " << A->getSpelling();
    OS << " \"" << SA->getName() << "\"";
  }
  void VisitSentinelAttr(const SentinelAttr *A) {
    const auto *SA = cast<SentinelAttr>(A); (void)SA;
    OS << " " << SA->getSentinel();
    OS << " " << SA->getNullPos();
  }
  void VisitSetTypestateAttr(const SetTypestateAttr *A) {
    const auto *SA = cast<SetTypestateAttr>(A); (void)SA;
    switch(SA->getNewState()) {
    case SetTypestateAttr::Unknown:
      OS << " Unknown";
      break;
    case SetTypestateAttr::Consumed:
      OS << " Consumed";
      break;
    case SetTypestateAttr::Unconsumed:
      OS << " Unconsumed";
      break;
    }
  }
  void VisitSuppressAttr(const SuppressAttr *A) {
    const auto *SA = cast<SuppressAttr>(A); (void)SA;
    for (const auto &Val : SA->diagnosticIdentifiers())
      OS << " " << Val;
  }
  void VisitSwiftAsyncAttr(const SwiftAsyncAttr *A) {
    const auto *SA = cast<SwiftAsyncAttr>(A); (void)SA;
    switch(SA->getKind()) {
    case SwiftAsyncAttr::None:
      OS << " None";
      break;
    case SwiftAsyncAttr::SwiftPrivate:
      OS << " SwiftPrivate";
      break;
    case SwiftAsyncAttr::NotSwiftPrivate:
      OS << " NotSwiftPrivate";
      break;
    }
    if (SA->getCompletionHandlerIndex().isValid())
      OS << " " << SA->getCompletionHandlerIndex().getSourceIndex();
  }
  void VisitSwiftAsyncErrorAttr(const SwiftAsyncErrorAttr *A) {
    const auto *SA = cast<SwiftAsyncErrorAttr>(A); (void)SA;
    switch(SA->getConvention()) {
    case SwiftAsyncErrorAttr::None:
      OS << " None";
      break;
    case SwiftAsyncErrorAttr::NonNullError:
      OS << " NonNullError";
      break;
    case SwiftAsyncErrorAttr::ZeroArgument:
      OS << " ZeroArgument";
      break;
    case SwiftAsyncErrorAttr::NonZeroArgument:
      OS << " NonZeroArgument";
      break;
    }
    OS << " " << SA->getHandlerParamIdx();
  }
  void VisitSwiftAsyncNameAttr(const SwiftAsyncNameAttr *A) {
    const auto *SA = cast<SwiftAsyncNameAttr>(A); (void)SA;
    OS << " \"" << SA->getName() << "\"";
  }
  void VisitSwiftAttrAttr(const SwiftAttrAttr *A) {
    const auto *SA = cast<SwiftAttrAttr>(A); (void)SA;
    OS << " \"" << SA->getAttribute() << "\"";
  }
  void VisitSwiftBridgeAttr(const SwiftBridgeAttr *A) {
    const auto *SA = cast<SwiftBridgeAttr>(A); (void)SA;
    OS << " \"" << SA->getSwiftType() << "\"";
  }
  void VisitSwiftErrorAttr(const SwiftErrorAttr *A) {
    const auto *SA = cast<SwiftErrorAttr>(A); (void)SA;
    switch(SA->getConvention()) {
    case SwiftErrorAttr::None:
      OS << " None";
      break;
    case SwiftErrorAttr::NonNullError:
      OS << " NonNullError";
      break;
    case SwiftErrorAttr::NullResult:
      OS << " NullResult";
      break;
    case SwiftErrorAttr::ZeroResult:
      OS << " ZeroResult";
      break;
    case SwiftErrorAttr::NonZeroResult:
      OS << " NonZeroResult";
      break;
    }
  }
  void VisitSwiftNameAttr(const SwiftNameAttr *A) {
    const auto *SA = cast<SwiftNameAttr>(A); (void)SA;
    OS << " \"" << SA->getName() << "\"";
  }
  void VisitSwiftNewTypeAttr(const SwiftNewTypeAttr *A) {
    const auto *SA = cast<SwiftNewTypeAttr>(A); (void)SA;
    OS << " " << A->getSpelling();
    switch(SA->getNewtypeKind()) {
    case SwiftNewTypeAttr::NK_Struct:
      OS << " NK_Struct";
      break;
    case SwiftNewTypeAttr::NK_Enum:
      OS << " NK_Enum";
      break;
    }
  }
  void VisitTLSModelAttr(const TLSModelAttr *A) {
    const auto *SA = cast<TLSModelAttr>(A); (void)SA;
    OS << " \"" << SA->getModel() << "\"";
  }
  void VisitTargetAttr(const TargetAttr *A) {
    const auto *SA = cast<TargetAttr>(A); (void)SA;
    OS << " \"" << SA->getFeaturesStr() << "\"";
  }
  void VisitTargetClonesAttr(const TargetClonesAttr *A) {
    const auto *SA = cast<TargetClonesAttr>(A); (void)SA;
    for (const auto &Val : SA->featuresStrs())
      OS << " " << Val;
  }
  void VisitTestTypestateAttr(const TestTypestateAttr *A) {
    const auto *SA = cast<TestTypestateAttr>(A); (void)SA;
    switch(SA->getTestState()) {
    case TestTypestateAttr::Consumed:
      OS << " Consumed";
      break;
    case TestTypestateAttr::Unconsumed:
      OS << " Unconsumed";
      break;
    }
  }
  void VisitTryAcquireCapabilityAttr(const TryAcquireCapabilityAttr *A) {
    const auto *SA = cast<TryAcquireCapabilityAttr>(A); (void)SA;
    OS << " " << A->getSpelling();
  }
  void VisitTypeTagForDatatypeAttr(const TypeTagForDatatypeAttr *A) {
    const auto *SA = cast<TypeTagForDatatypeAttr>(A); (void)SA;
    if (SA->getArgumentKind())
      OS << " " << SA->getArgumentKind()->getName();
    OS << " " << SA->getMatchingCType().getAsString();
    if (SA->getLayoutCompatible()) OS << " LayoutCompatible";
    if (SA->getMustBeNull()) OS << " MustBeNull";
  }
  void VisitTypeVisibilityAttr(const TypeVisibilityAttr *A) {
    const auto *SA = cast<TypeVisibilityAttr>(A); (void)SA;
    switch(SA->getVisibility()) {
    case TypeVisibilityAttr::Default:
      OS << " Default";
      break;
    case TypeVisibilityAttr::Hidden:
      OS << " Hidden";
      break;
    case TypeVisibilityAttr::Protected:
      OS << " Protected";
      break;
    }
  }
  void VisitUnavailableAttr(const UnavailableAttr *A) {
    const auto *SA = cast<UnavailableAttr>(A); (void)SA;
    OS << " \"" << SA->getMessage() << "\"";
    switch(SA->getImplicitReason()) {
    case UnavailableAttr::IR_None:
      OS << " IR_None";
      break;
    case UnavailableAttr::IR_ARCForbiddenType:
      OS << " IR_ARCForbiddenType";
      break;
    case UnavailableAttr::IR_ForbiddenWeak:
      OS << " IR_ForbiddenWeak";
      break;
    case UnavailableAttr::IR_ARCForbiddenConversion:
      OS << " IR_ARCForbiddenConversion";
      break;
    case UnavailableAttr::IR_ARCInitReturnsUnrelated:
      OS << " IR_ARCInitReturnsUnrelated";
      break;
    case UnavailableAttr::IR_ARCFieldWithOwnership:
      OS << " IR_ARCFieldWithOwnership";
      break;
    }
  }
  void VisitUnusedAttr(const UnusedAttr *A) {
    OS << " " << A->getSpelling();
  }
  void VisitUseHandleAttr(const UseHandleAttr *A) {
    const auto *SA = cast<UseHandleAttr>(A); (void)SA;
    OS << " \"" << SA->getHandleType() << "\"";
  }
  void VisitUuidAttr(const UuidAttr *A) {
    const auto *SA = cast<UuidAttr>(A); (void)SA;
    OS << " \"" << SA->getGuid() << "\"";
    OS << " ";
    dumpBareDeclRef(SA->getGuidDecl());
  }
  void VisitVecTypeHintAttr(const VecTypeHintAttr *A) {
    const auto *SA = cast<VecTypeHintAttr>(A); (void)SA;
    OS << " " << SA->getTypeHint().getAsString();
  }
  void VisitVisibilityAttr(const VisibilityAttr *A) {
    const auto *SA = cast<VisibilityAttr>(A); (void)SA;
    switch(SA->getVisibility()) {
    case VisibilityAttr::Default:
      OS << " Default";
      break;
    case VisibilityAttr::Hidden:
      OS << " Hidden";
      break;
    case VisibilityAttr::Protected:
      OS << " Protected";
      break;
    }
  }
  void VisitWarnUnusedResultAttr(const WarnUnusedResultAttr *A) {
    const auto *SA = cast<WarnUnusedResultAttr>(A); (void)SA;
    OS << " " << A->getSpelling();
    OS << " \"" << SA->getMessage() << "\"";
  }
  void VisitWeakRefAttr(const WeakRefAttr *A) {
    const auto *SA = cast<WeakRefAttr>(A); (void)SA;
    OS << " \"" << SA->getAliasee() << "\"";
  }
  void VisitWebAssemblyExportNameAttr(const WebAssemblyExportNameAttr *A) {
    const auto *SA = cast<WebAssemblyExportNameAttr>(A); (void)SA;
    OS << " \"" << SA->getExportName() << "\"";
  }
  void VisitWebAssemblyImportModuleAttr(const WebAssemblyImportModuleAttr *A) {
    const auto *SA = cast<WebAssemblyImportModuleAttr>(A); (void)SA;
    OS << " \"" << SA->getImportModule() << "\"";
  }
  void VisitWebAssemblyImportNameAttr(const WebAssemblyImportNameAttr *A) {
    const auto *SA = cast<WebAssemblyImportNameAttr>(A); (void)SA;
    OS << " \"" << SA->getImportName() << "\"";
  }
  void VisitWorkGroupSizeHintAttr(const WorkGroupSizeHintAttr *A) {
    const auto *SA = cast<WorkGroupSizeHintAttr>(A); (void)SA;
    OS << " " << SA->getXDim();
    OS << " " << SA->getYDim();
    OS << " " << SA->getZDim();
  }
  void VisitXRayInstrumentAttr(const XRayInstrumentAttr *A) {
    OS << " " << A->getSpelling();
  }
  void VisitXRayLogArgsAttr(const XRayLogArgsAttr *A) {
    const auto *SA = cast<XRayLogArgsAttr>(A); (void)SA;
    OS << " " << SA->getArgumentCount();
  }
