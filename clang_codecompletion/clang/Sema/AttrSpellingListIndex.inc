/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Code to translate different attribute spellings into internal identifiers  *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

  switch (getParsedKind()) {
    case IgnoredAttribute:
    case UnknownAttribute:
    case NoSemaHandlerAttribute:
      llvm_unreachable("Ignored/unknown shouldn't get here");
  case AT_AArch64VectorPcs: {
    if (Name == "aarch64_vector_pcs" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "aarch64_vector_pcs" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "aarch64_vector_pcs" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_AMDGPUFlatWorkGroupSize: {
    if (Name == "amdgpu_flat_work_group_size" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "amdgpu_flat_work_group_size" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    break;
  }
  case AT_AMDGPUNumSGPR: {
    if (Name == "amdgpu_num_sgpr" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "amdgpu_num_sgpr" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    break;
  }
  case AT_AMDGPUNumVGPR: {
    if (Name == "amdgpu_num_vgpr" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "amdgpu_num_vgpr" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    break;
  }
  case AT_AMDGPUWavesPerEU: {
    if (Name == "amdgpu_waves_per_eu" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "amdgpu_waves_per_eu" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    break;
  }
  case AT_Interrupt: {
    if (Name == "interrupt" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "interrupt" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "gnu")
        return 1;
    if (Name == "interrupt" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "gnu")
        return 2;
    break;
  }
  case AT_AVRSignal: {
    if (Name == "signal" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "signal" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "gnu")
        return 1;
    if (Name == "signal" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "gnu")
        return 2;
    break;
  }
  case AT_AbiTag: {
    if (Name == "abi_tag" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "abi_tag" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "gnu")
        return 1;
    break;
  }
  case AT_AcquireCapability: {
    if (Name == "acquire_capability" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "acquire_capability" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "acquire_shared_capability" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 2;
    if (Name == "acquire_shared_capability" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 3;
    if (Name == "exclusive_lock_function" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 4;
    if (Name == "shared_lock_function" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 5;
    break;
  }
  case AT_AcquireHandle: {
    if (Name == "acquire_handle" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "acquire_handle" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "acquire_handle" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_AcquiredAfter: {
    if (Name == "acquired_after" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    break;
  }
  case AT_AcquiredBefore: {
    if (Name == "acquired_before" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    break;
  }
  case AT_AddressSpace: {
    if (Name == "address_space" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "address_space" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "address_space" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_Alias: {
    if (Name == "alias" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "alias" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "gnu")
        return 1;
    if (Name == "alias" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "gnu")
        return 2;
    break;
  }
  case AT_AlignValue: {
    if (Name == "align_value" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    break;
  }
  case AT_Aligned: {
    if (Name == "aligned" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "aligned" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "gnu")
        return 1;
    if (Name == "aligned" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "gnu")
        return 2;
    if (Name == "align" && getSyntax() == AttributeCommonInfo::AS_Declspec && Scope == "")
        return 3;
    if (Name == "alignas" && getSyntax() == AttributeCommonInfo::AS_Keyword && Scope == "")
        return 4;
    if (Name == "_Alignas" && getSyntax() == AttributeCommonInfo::AS_Keyword && Scope == "")
        return 5;
    break;
  }
  case AT_AllocAlign: {
    if (Name == "alloc_align" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "alloc_align" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "gnu")
        return 1;
    if (Name == "alloc_align" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "gnu")
        return 2;
    break;
  }
  case AT_AllocSize: {
    if (Name == "alloc_size" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "alloc_size" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "gnu")
        return 1;
    if (Name == "alloc_size" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "gnu")
        return 2;
    break;
  }
  case AT_AlwaysDestroy: {
    if (Name == "always_destroy" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "always_destroy" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    break;
  }
  case AT_AlwaysInline: {
    if (Name == "always_inline" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "always_inline" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "gnu")
        return 1;
    if (Name == "always_inline" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "gnu")
        return 2;
    if (Name == "__forceinline" && getSyntax() == AttributeCommonInfo::AS_Keyword && Scope == "")
        return 3;
    break;
  }
  case AT_AnalyzerNoReturn: {
    if (Name == "analyzer_noreturn" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    break;
  }
  case AT_Annotate: {
    if (Name == "annotate" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "annotate" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "annotate" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_AnyX86NoCallerSavedRegisters: {
    if (Name == "no_caller_saved_registers" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "no_caller_saved_registers" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "gnu")
        return 1;
    if (Name == "no_caller_saved_registers" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "gnu")
        return 2;
    break;
  }
  case AT_AnyX86NoCfCheck: {
    if (Name == "nocf_check" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "nocf_check" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "gnu")
        return 1;
    if (Name == "nocf_check" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "gnu")
        return 2;
    break;
  }
  case AT_ArcWeakrefUnavailable: {
    if (Name == "objc_arc_weak_reference_unavailable" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "objc_arc_weak_reference_unavailable" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "objc_arc_weak_reference_unavailable" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_ArgumentWithTypeTag: {
    if (Name == "argument_with_type_tag" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "argument_with_type_tag" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "argument_with_type_tag" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    if (Name == "pointer_with_type_tag" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 3;
    if (Name == "pointer_with_type_tag" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 4;
    if (Name == "pointer_with_type_tag" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 5;
    break;
  }
  case AT_ArmBuiltinAlias: {
    if (Name == "__clang_arm_builtin_alias" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "__clang_arm_builtin_alias" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "__clang_arm_builtin_alias" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_ArmMveStrictPolymorphism: {
    if (Name == "__clang_arm_mve_strict_polymorphism" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "__clang_arm_mve_strict_polymorphism" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "__clang_arm_mve_strict_polymorphism" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_ArmSveVectorBits: {
    if (Name == "arm_sve_vector_bits" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    break;
  }
  case AT_Artificial: {
    if (Name == "artificial" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "artificial" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "gnu")
        return 1;
    if (Name == "artificial" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "gnu")
        return 2;
    break;
  }
  case AT_AssertCapability: {
    if (Name == "assert_capability" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "assert_capability" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "assert_shared_capability" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 2;
    if (Name == "assert_shared_capability" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 3;
    break;
  }
  case AT_AssertExclusiveLock: {
    if (Name == "assert_exclusive_lock" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    break;
  }
  case AT_AssertSharedLock: {
    if (Name == "assert_shared_lock" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    break;
  }
  case AT_AssumeAligned: {
    if (Name == "assume_aligned" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "assume_aligned" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "gnu")
        return 1;
    if (Name == "assume_aligned" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "gnu")
        return 2;
    break;
  }
  case AT_Assumption: {
    if (Name == "assume" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "assume" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "assume" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_Availability: {
    if (Name == "availability" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "availability" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "availability" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_BPFPreserveAccessIndex: {
    if (Name == "preserve_access_index" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "preserve_access_index" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "preserve_access_index" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_BTFDeclTag: {
    if (Name == "btf_decl_tag" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "btf_decl_tag" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "btf_decl_tag" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_BTFTypeTag: {
    if (Name == "btf_type_tag" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "btf_type_tag" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "btf_type_tag" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_Blocks: {
    if (Name == "blocks" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "blocks" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "blocks" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_BuiltinAlias: {
    if (Name == "builtin_alias" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 0;
    if (Name == "builtin_alias" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 1;
    if (Name == "clang_builtin_alias" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 2;
    break;
  }
  case AT_CDecl: {
    if (Name == "cdecl" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "cdecl" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "gnu")
        return 1;
    if (Name == "cdecl" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "gnu")
        return 2;
    if (Name == "__cdecl" && getSyntax() == AttributeCommonInfo::AS_Keyword && Scope == "")
        return 3;
    if (Name == "_cdecl" && getSyntax() == AttributeCommonInfo::AS_Keyword && Scope == "")
        return 4;
    break;
  }
  case AT_CFAuditedTransfer: {
    if (Name == "cf_audited_transfer" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "cf_audited_transfer" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "cf_audited_transfer" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_CFConsumed: {
    if (Name == "cf_consumed" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "cf_consumed" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "cf_consumed" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_CFGuard: {
    if (Name == "guard" && getSyntax() == AttributeCommonInfo::AS_Declspec && Scope == "")
        return 0;
    break;
  }
  case AT_CFICanonicalJumpTable: {
    if (Name == "cfi_canonical_jump_table" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "cfi_canonical_jump_table" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "cfi_canonical_jump_table" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_CFReturnsNotRetained: {
    if (Name == "cf_returns_not_retained" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "cf_returns_not_retained" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "cf_returns_not_retained" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_CFReturnsRetained: {
    if (Name == "cf_returns_retained" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "cf_returns_retained" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "cf_returns_retained" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_CFUnknownTransfer: {
    if (Name == "cf_unknown_transfer" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "cf_unknown_transfer" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "cf_unknown_transfer" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_CPUDispatch: {
    if (Name == "cpu_dispatch" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "cpu_dispatch" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "cpu_dispatch" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    if (Name == "cpu_dispatch" && getSyntax() == AttributeCommonInfo::AS_Declspec && Scope == "")
        return 3;
    break;
  }
  case AT_CPUSpecific: {
    if (Name == "cpu_specific" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "cpu_specific" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "cpu_specific" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    if (Name == "cpu_specific" && getSyntax() == AttributeCommonInfo::AS_Declspec && Scope == "")
        return 3;
    break;
  }
  case AT_CUDAConstant: {
    if (Name == "constant" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "__constant__" && getSyntax() == AttributeCommonInfo::AS_Declspec && Scope == "")
        return 1;
    break;
  }
  case AT_CUDADevice: {
    if (Name == "device" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "__device__" && getSyntax() == AttributeCommonInfo::AS_Declspec && Scope == "")
        return 1;
    break;
  }
  case AT_CUDADeviceBuiltinSurfaceType: {
    if (Name == "device_builtin_surface_type" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "__device_builtin_surface_type__" && getSyntax() == AttributeCommonInfo::AS_Declspec && Scope == "")
        return 1;
    break;
  }
  case AT_CUDADeviceBuiltinTextureType: {
    if (Name == "device_builtin_texture_type" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "__device_builtin_texture_type__" && getSyntax() == AttributeCommonInfo::AS_Declspec && Scope == "")
        return 1;
    break;
  }
  case AT_CUDAGlobal: {
    if (Name == "global" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "__global__" && getSyntax() == AttributeCommonInfo::AS_Declspec && Scope == "")
        return 1;
    break;
  }
  case AT_CUDAHost: {
    if (Name == "host" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "__host__" && getSyntax() == AttributeCommonInfo::AS_Declspec && Scope == "")
        return 1;
    break;
  }
  case AT_CUDAInvalidTarget: {
    break;
  }
  case AT_CUDALaunchBounds: {
    if (Name == "launch_bounds" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "__launch_bounds__" && getSyntax() == AttributeCommonInfo::AS_Declspec && Scope == "")
        return 1;
    break;
  }
  case AT_CUDAShared: {
    if (Name == "shared" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "__shared__" && getSyntax() == AttributeCommonInfo::AS_Declspec && Scope == "")
        return 1;
    break;
  }
  case AT_CXX11NoReturn: {
    if (Name == "noreturn" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "")
        return 0;
    break;
  }
  case AT_CallableWhen: {
    if (Name == "callable_when" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "callable_when" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    break;
  }
  case AT_Callback: {
    if (Name == "callback" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "callback" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "callback" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_CalledOnce: {
    if (Name == "called_once" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "called_once" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "called_once" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_Capability: {
    if (Name == "capability" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "capability" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "shared_capability" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 2;
    if (Name == "shared_capability" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 3;
    break;
  }
  case AT_CarriesDependency: {
    if (Name == "carries_dependency" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "carries_dependency" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "")
        return 1;
    break;
  }
  case AT_Cleanup: {
    if (Name == "cleanup" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "cleanup" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "gnu")
        return 1;
    if (Name == "cleanup" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "gnu")
        return 2;
    break;
  }
  case AT_CmseNSCall: {
    if (Name == "cmse_nonsecure_call" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    break;
  }
  case AT_CmseNSEntry: {
    if (Name == "cmse_nonsecure_entry" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    break;
  }
  case AT_CodeSeg: {
    if (Name == "code_seg" && getSyntax() == AttributeCommonInfo::AS_Declspec && Scope == "")
        return 0;
    break;
  }
  case AT_Cold: {
    if (Name == "cold" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "cold" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "gnu")
        return 1;
    if (Name == "cold" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "gnu")
        return 2;
    break;
  }
  case AT_Common: {
    if (Name == "common" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "common" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "gnu")
        return 1;
    if (Name == "common" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "gnu")
        return 2;
    break;
  }
  case AT_Const: {
    if (Name == "const" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "const" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "gnu")
        return 1;
    if (Name == "const" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "gnu")
        return 2;
    if (Name == "__const" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 3;
    if (Name == "__const" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "gnu")
        return 4;
    if (Name == "__const" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "gnu")
        return 5;
    break;
  }
  case AT_ConstInit: {
    if (Name == "constinit" && getSyntax() == AttributeCommonInfo::AS_Keyword && Scope == "")
        return 0;
    if (Name == "require_constant_initialization" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 1;
    if (Name == "require_constant_initialization" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 2;
    break;
  }
  case AT_Constructor: {
    if (Name == "constructor" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "constructor" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "gnu")
        return 1;
    if (Name == "constructor" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "gnu")
        return 2;
    break;
  }
  case AT_Consumable: {
    if (Name == "consumable" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "consumable" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    break;
  }
  case AT_ConsumableAutoCast: {
    if (Name == "consumable_auto_cast_state" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "consumable_auto_cast_state" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    break;
  }
  case AT_ConsumableSetOnRead: {
    if (Name == "consumable_set_state_on_read" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "consumable_set_state_on_read" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    break;
  }
  case AT_Convergent: {
    if (Name == "convergent" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "convergent" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "convergent" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_DLLExport: {
    if (Name == "dllexport" && getSyntax() == AttributeCommonInfo::AS_Declspec && Scope == "")
        return 0;
    if (Name == "dllexport" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 1;
    if (Name == "dllexport" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "gnu")
        return 2;
    if (Name == "dllexport" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "gnu")
        return 3;
    break;
  }
  case AT_DLLExportStaticLocal: {
    break;
  }
  case AT_DLLImport: {
    if (Name == "dllimport" && getSyntax() == AttributeCommonInfo::AS_Declspec && Scope == "")
        return 0;
    if (Name == "dllimport" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 1;
    if (Name == "dllimport" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "gnu")
        return 2;
    if (Name == "dllimport" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "gnu")
        return 3;
    break;
  }
  case AT_DLLImportStaticLocal: {
    break;
  }
  case AT_Deprecated: {
    if (Name == "deprecated" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "deprecated" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "gnu")
        return 1;
    if (Name == "deprecated" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "gnu")
        return 2;
    if (Name == "deprecated" && getSyntax() == AttributeCommonInfo::AS_Declspec && Scope == "")
        return 3;
    if (Name == "deprecated" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "")
        return 4;
    if (Name == "deprecated" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "")
        return 5;
    break;
  }
  case AT_Destructor: {
    if (Name == "destructor" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "destructor" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "gnu")
        return 1;
    if (Name == "destructor" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "gnu")
        return 2;
    break;
  }
  case AT_DiagnoseAsBuiltin: {
    if (Name == "diagnose_as_builtin" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "diagnose_as_builtin" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "diagnose_as_builtin" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_DiagnoseIf: {
    if (Name == "diagnose_if" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    break;
  }
  case AT_DisableSanitizerInstrumentation: {
    if (Name == "disable_sanitizer_instrumentation" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "disable_sanitizer_instrumentation" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "disable_sanitizer_instrumentation" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_DisableTailCalls: {
    if (Name == "disable_tail_calls" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "disable_tail_calls" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "disable_tail_calls" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_EmptyBases: {
    if (Name == "empty_bases" && getSyntax() == AttributeCommonInfo::AS_Declspec && Scope == "")
        return 0;
    break;
  }
  case AT_EnableIf: {
    if (Name == "enable_if" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    break;
  }
  case AT_EnforceTCB: {
    if (Name == "enforce_tcb" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "enforce_tcb" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "enforce_tcb" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_EnforceTCBLeaf: {
    if (Name == "enforce_tcb_leaf" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "enforce_tcb_leaf" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "enforce_tcb_leaf" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_EnumExtensibility: {
    if (Name == "enum_extensibility" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "enum_extensibility" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "enum_extensibility" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_Error: {
    if (Name == "error" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "error" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "gnu")
        return 1;
    if (Name == "error" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "gnu")
        return 2;
    if (Name == "warning" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 3;
    if (Name == "warning" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "gnu")
        return 4;
    if (Name == "warning" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "gnu")
        return 5;
    break;
  }
  case AT_ExcludeFromExplicitInstantiation: {
    if (Name == "exclude_from_explicit_instantiation" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "exclude_from_explicit_instantiation" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "exclude_from_explicit_instantiation" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_ExclusiveTrylockFunction: {
    if (Name == "exclusive_trylock_function" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    break;
  }
  case AT_ExtVectorType: {
    if (Name == "ext_vector_type" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    break;
  }
  case AT_ExternalSourceSymbol: {
    if (Name == "external_source_symbol" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "external_source_symbol" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "external_source_symbol" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_FallThrough: {
    if (Name == "fallthrough" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "")
        return 0;
    if (Name == "fallthrough" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "")
        return 1;
    if (Name == "fallthrough" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 2;
    if (Name == "fallthrough" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 3;
    if (Name == "fallthrough" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "gnu")
        return 4;
    if (Name == "fallthrough" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "gnu")
        return 5;
    break;
  }
  case AT_FastCall: {
    if (Name == "fastcall" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "fastcall" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "gnu")
        return 1;
    if (Name == "fastcall" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "gnu")
        return 2;
    if (Name == "__fastcall" && getSyntax() == AttributeCommonInfo::AS_Keyword && Scope == "")
        return 3;
    if (Name == "_fastcall" && getSyntax() == AttributeCommonInfo::AS_Keyword && Scope == "")
        return 4;
    break;
  }
  case AT_FlagEnum: {
    if (Name == "flag_enum" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "flag_enum" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "flag_enum" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_Flatten: {
    if (Name == "flatten" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "flatten" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "gnu")
        return 1;
    if (Name == "flatten" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "gnu")
        return 2;
    break;
  }
  case AT_Format: {
    if (Name == "format" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "format" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "gnu")
        return 1;
    if (Name == "format" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "gnu")
        return 2;
    break;
  }
  case AT_FormatArg: {
    if (Name == "format_arg" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "format_arg" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "gnu")
        return 1;
    if (Name == "format_arg" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "gnu")
        return 2;
    break;
  }
  case AT_GNUInline: {
    if (Name == "gnu_inline" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "gnu_inline" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "gnu")
        return 1;
    if (Name == "gnu_inline" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "gnu")
        return 2;
    break;
  }
  case AT_GuardedBy: {
    if (Name == "guarded_by" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    break;
  }
  case AT_GuardedVar: {
    if (Name == "guarded_var" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "guarded_var" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    break;
  }
  case AT_HIPManaged: {
    if (Name == "managed" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "__managed__" && getSyntax() == AttributeCommonInfo::AS_Declspec && Scope == "")
        return 1;
    break;
  }
  case AT_Hot: {
    if (Name == "hot" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "hot" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "gnu")
        return 1;
    if (Name == "hot" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "gnu")
        return 2;
    break;
  }
  case AT_IBAction: {
    if (Name == "ibaction" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "ibaction" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "ibaction" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_IBOutlet: {
    if (Name == "iboutlet" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "iboutlet" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "iboutlet" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_IBOutletCollection: {
    if (Name == "iboutletcollection" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "iboutletcollection" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "iboutletcollection" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_IFunc: {
    if (Name == "ifunc" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "ifunc" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "gnu")
        return 1;
    if (Name == "ifunc" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "gnu")
        return 2;
    break;
  }
  case AT_InitPriority: {
    if (Name == "init_priority" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "init_priority" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "gnu")
        return 1;
    break;
  }
  case AT_IntelOclBicc: {
    if (Name == "intel_ocl_bicc" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "intel_ocl_bicc" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    break;
  }
  case AT_InternalLinkage: {
    if (Name == "internal_linkage" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "internal_linkage" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "internal_linkage" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_LTOVisibilityPublic: {
    if (Name == "lto_visibility_public" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "lto_visibility_public" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "lto_visibility_public" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_LayoutVersion: {
    if (Name == "layout_version" && getSyntax() == AttributeCommonInfo::AS_Declspec && Scope == "")
        return 0;
    break;
  }
  case AT_Leaf: {
    if (Name == "leaf" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "leaf" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "gnu")
        return 1;
    if (Name == "leaf" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "gnu")
        return 2;
    break;
  }
  case AT_LifetimeBound: {
    if (Name == "lifetimebound" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "lifetimebound" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    break;
  }
  case AT_Likely: {
    if (Name == "likely" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "")
        return 0;
    if (Name == "likely" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 1;
    break;
  }
  case AT_LoaderUninitialized: {
    if (Name == "loader_uninitialized" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "loader_uninitialized" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "loader_uninitialized" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_LockReturned: {
    if (Name == "lock_returned" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    break;
  }
  case AT_Lockable: {
    if (Name == "lockable" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    break;
  }
  case AT_LocksExcluded: {
    if (Name == "locks_excluded" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    break;
  }
  case AT_LoopHint: {
    if (Name == "loop" && getSyntax() == AttributeCommonInfo::AS_Pragma && Scope == "clang")
        return 0;
    if (Name == "unroll" && getSyntax() == AttributeCommonInfo::AS_Pragma && Scope == "")
        return 1;
    if (Name == "nounroll" && getSyntax() == AttributeCommonInfo::AS_Pragma && Scope == "")
        return 2;
    if (Name == "unroll_and_jam" && getSyntax() == AttributeCommonInfo::AS_Pragma && Scope == "")
        return 3;
    if (Name == "nounroll_and_jam" && getSyntax() == AttributeCommonInfo::AS_Pragma && Scope == "")
        return 4;
    break;
  }
  case AT_MIGServerRoutine: {
    if (Name == "mig_server_routine" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "mig_server_routine" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "mig_server_routine" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_MSABI: {
    if (Name == "ms_abi" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "ms_abi" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "gnu")
        return 1;
    if (Name == "ms_abi" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "gnu")
        return 2;
    break;
  }
  case AT_MSAllocator: {
    if (Name == "allocator" && getSyntax() == AttributeCommonInfo::AS_Declspec && Scope == "")
        return 0;
    break;
  }
  case AT_MSInheritance: {
    if (Name == "__single_inheritance" && getSyntax() == AttributeCommonInfo::AS_Keyword && Scope == "")
        return 0;
    if (Name == "__multiple_inheritance" && getSyntax() == AttributeCommonInfo::AS_Keyword && Scope == "")
        return 1;
    if (Name == "__virtual_inheritance" && getSyntax() == AttributeCommonInfo::AS_Keyword && Scope == "")
        return 2;
    if (Name == "__unspecified_inheritance" && getSyntax() == AttributeCommonInfo::AS_Keyword && Scope == "")
        return 3;
    break;
  }
  case AT_MSNoVTable: {
    if (Name == "novtable" && getSyntax() == AttributeCommonInfo::AS_Declspec && Scope == "")
        return 0;
    break;
  }
  case AT_MSStruct: {
    if (Name == "ms_struct" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "ms_struct" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "gnu")
        return 1;
    if (Name == "ms_struct" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "gnu")
        return 2;
    break;
  }
  case AT_MatrixType: {
    if (Name == "matrix_type" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "matrix_type" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "matrix_type" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_MayAlias: {
    if (Name == "may_alias" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "may_alias" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "gnu")
        return 1;
    if (Name == "may_alias" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "gnu")
        return 2;
    break;
  }
  case AT_MicroMips: {
    if (Name == "micromips" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "micromips" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "gnu")
        return 1;
    if (Name == "micromips" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "gnu")
        return 2;
    break;
  }
  case AT_MinSize: {
    if (Name == "minsize" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "minsize" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "minsize" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_MinVectorWidth: {
    if (Name == "min_vector_width" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "min_vector_width" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "min_vector_width" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_Mips16: {
    if (Name == "mips16" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "mips16" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "gnu")
        return 1;
    if (Name == "mips16" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "gnu")
        return 2;
    break;
  }
  case AT_MipsLongCall: {
    if (Name == "long_call" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "long_call" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "gnu")
        return 1;
    if (Name == "long_call" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "gnu")
        return 2;
    if (Name == "far" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 3;
    if (Name == "far" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "gnu")
        return 4;
    if (Name == "far" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "gnu")
        return 5;
    break;
  }
  case AT_MipsShortCall: {
    if (Name == "short_call" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "short_call" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "gnu")
        return 1;
    if (Name == "short_call" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "gnu")
        return 2;
    if (Name == "near" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 3;
    if (Name == "near" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "gnu")
        return 4;
    if (Name == "near" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "gnu")
        return 5;
    break;
  }
  case AT_Mode: {
    if (Name == "mode" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "mode" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "gnu")
        return 1;
    if (Name == "mode" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "gnu")
        return 2;
    break;
  }
  case AT_MustTail: {
    if (Name == "musttail" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "musttail" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "musttail" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_NSConsumed: {
    if (Name == "ns_consumed" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "ns_consumed" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "ns_consumed" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_NSConsumesSelf: {
    if (Name == "ns_consumes_self" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "ns_consumes_self" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "ns_consumes_self" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_NSErrorDomain: {
    if (Name == "ns_error_domain" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    break;
  }
  case AT_NSReturnsAutoreleased: {
    if (Name == "ns_returns_autoreleased" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "ns_returns_autoreleased" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "ns_returns_autoreleased" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_NSReturnsNotRetained: {
    if (Name == "ns_returns_not_retained" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "ns_returns_not_retained" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "ns_returns_not_retained" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_NSReturnsRetained: {
    if (Name == "ns_returns_retained" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "ns_returns_retained" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "ns_returns_retained" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_Naked: {
    if (Name == "naked" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "naked" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "gnu")
        return 1;
    if (Name == "naked" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "gnu")
        return 2;
    if (Name == "naked" && getSyntax() == AttributeCommonInfo::AS_Declspec && Scope == "")
        return 3;
    break;
  }
  case AT_NeonPolyVectorType: {
    if (Name == "neon_polyvector_type" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "neon_polyvector_type" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "neon_polyvector_type" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_NeonVectorType: {
    if (Name == "neon_vector_type" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "neon_vector_type" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "neon_vector_type" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_NoAlias: {
    if (Name == "noalias" && getSyntax() == AttributeCommonInfo::AS_Declspec && Scope == "")
        return 0;
    break;
  }
  case AT_NoBuiltin: {
    if (Name == "no_builtin" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "no_builtin" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "no_builtin" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_NoCommon: {
    if (Name == "nocommon" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "nocommon" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "gnu")
        return 1;
    if (Name == "nocommon" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "gnu")
        return 2;
    break;
  }
  case AT_NoDebug: {
    if (Name == "nodebug" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "nodebug" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "gnu")
        return 1;
    if (Name == "nodebug" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "gnu")
        return 2;
    break;
  }
  case AT_NoDeref: {
    if (Name == "noderef" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "noderef" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "noderef" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_NoDestroy: {
    if (Name == "no_destroy" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "no_destroy" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    break;
  }
  case AT_NoDuplicate: {
    if (Name == "noduplicate" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "noduplicate" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "noduplicate" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_NoEscape: {
    if (Name == "noescape" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "noescape" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "noescape" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_NoInline: {
    if (Name == "noinline" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "noinline" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "gnu")
        return 1;
    if (Name == "noinline" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "gnu")
        return 2;
    if (Name == "noinline" && getSyntax() == AttributeCommonInfo::AS_Declspec && Scope == "")
        return 3;
    break;
  }
  case AT_NoInstrumentFunction: {
    if (Name == "no_instrument_function" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "no_instrument_function" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "gnu")
        return 1;
    if (Name == "no_instrument_function" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "gnu")
        return 2;
    break;
  }
  case AT_NoMerge: {
    if (Name == "nomerge" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "nomerge" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "nomerge" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_NoMicroMips: {
    if (Name == "nomicromips" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "nomicromips" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "gnu")
        return 1;
    if (Name == "nomicromips" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "gnu")
        return 2;
    break;
  }
  case AT_NoMips16: {
    if (Name == "nomips16" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "nomips16" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "gnu")
        return 1;
    if (Name == "nomips16" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "gnu")
        return 2;
    break;
  }
  case AT_NoProfileFunction: {
    if (Name == "no_profile_instrument_function" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "no_profile_instrument_function" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "gnu")
        return 1;
    if (Name == "no_profile_instrument_function" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "gnu")
        return 2;
    break;
  }
  case AT_NoReturn: {
    if (Name == "noreturn" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "noreturn" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "gnu")
        return 1;
    if (Name == "noreturn" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "gnu")
        return 2;
    if (Name == "noreturn" && getSyntax() == AttributeCommonInfo::AS_Declspec && Scope == "")
        return 3;
    break;
  }
  case AT_NoSanitize: {
    if (Name == "no_sanitize" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "no_sanitize" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "no_sanitize" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_NoSanitizeSpecific: {
    if (Name == "no_address_safety_analysis" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "no_address_safety_analysis" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "gnu")
        return 1;
    if (Name == "no_address_safety_analysis" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "gnu")
        return 2;
    if (Name == "no_sanitize_address" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 3;
    if (Name == "no_sanitize_address" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "gnu")
        return 4;
    if (Name == "no_sanitize_address" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "gnu")
        return 5;
    if (Name == "no_sanitize_thread" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 6;
    if (Name == "no_sanitize_thread" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "gnu")
        return 7;
    if (Name == "no_sanitize_thread" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "gnu")
        return 8;
    if (Name == "no_sanitize_memory" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 9;
    if (Name == "no_sanitize_memory" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 10;
    if (Name == "no_sanitize_memory" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 11;
    break;
  }
  case AT_NoSpeculativeLoadHardening: {
    if (Name == "no_speculative_load_hardening" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "no_speculative_load_hardening" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "no_speculative_load_hardening" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_NoSplitStack: {
    if (Name == "no_split_stack" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "no_split_stack" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "gnu")
        return 1;
    if (Name == "no_split_stack" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "gnu")
        return 2;
    break;
  }
  case AT_NoStackProtector: {
    if (Name == "no_stack_protector" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "no_stack_protector" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "no_stack_protector" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_NoThreadSafetyAnalysis: {
    if (Name == "no_thread_safety_analysis" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "no_thread_safety_analysis" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "no_thread_safety_analysis" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_NoThrow: {
    if (Name == "nothrow" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "nothrow" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "gnu")
        return 1;
    if (Name == "nothrow" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "gnu")
        return 2;
    if (Name == "nothrow" && getSyntax() == AttributeCommonInfo::AS_Declspec && Scope == "")
        return 3;
    break;
  }
  case AT_NoUniqueAddress: {
    if (Name == "no_unique_address" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "")
        return 0;
    break;
  }
  case AT_NonNull: {
    if (Name == "nonnull" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "nonnull" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "gnu")
        return 1;
    if (Name == "nonnull" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "gnu")
        return 2;
    break;
  }
  case AT_NotTailCalled: {
    if (Name == "not_tail_called" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "not_tail_called" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "not_tail_called" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_OSConsumed: {
    if (Name == "os_consumed" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "os_consumed" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "os_consumed" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_OSConsumesThis: {
    if (Name == "os_consumes_this" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "os_consumes_this" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "os_consumes_this" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_OSReturnsNotRetained: {
    if (Name == "os_returns_not_retained" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "os_returns_not_retained" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "os_returns_not_retained" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_OSReturnsRetained: {
    if (Name == "os_returns_retained" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "os_returns_retained" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "os_returns_retained" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_OSReturnsRetainedOnNonZero: {
    if (Name == "os_returns_retained_on_non_zero" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "os_returns_retained_on_non_zero" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "os_returns_retained_on_non_zero" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_OSReturnsRetainedOnZero: {
    if (Name == "os_returns_retained_on_zero" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "os_returns_retained_on_zero" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "os_returns_retained_on_zero" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_ObjCBoxable: {
    if (Name == "objc_boxable" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "objc_boxable" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "objc_boxable" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_ObjCBridge: {
    if (Name == "objc_bridge" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "objc_bridge" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "objc_bridge" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_ObjCBridgeMutable: {
    if (Name == "objc_bridge_mutable" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "objc_bridge_mutable" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "objc_bridge_mutable" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_ObjCBridgeRelated: {
    if (Name == "objc_bridge_related" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "objc_bridge_related" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "objc_bridge_related" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_ObjCClassStub: {
    if (Name == "objc_class_stub" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "objc_class_stub" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "objc_class_stub" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_ObjCDesignatedInitializer: {
    if (Name == "objc_designated_initializer" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "objc_designated_initializer" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "objc_designated_initializer" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_ObjCDirect: {
    if (Name == "objc_direct" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "objc_direct" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "objc_direct" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_ObjCDirectMembers: {
    if (Name == "objc_direct_members" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "objc_direct_members" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "objc_direct_members" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_ObjCException: {
    if (Name == "objc_exception" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "objc_exception" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "objc_exception" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_ObjCExplicitProtocolImpl: {
    if (Name == "objc_protocol_requires_explicit_implementation" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "objc_protocol_requires_explicit_implementation" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "objc_protocol_requires_explicit_implementation" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_ObjCExternallyRetained: {
    if (Name == "objc_externally_retained" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "objc_externally_retained" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "objc_externally_retained" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_ObjCGC: {
    if (Name == "objc_gc" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "objc_gc" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "objc_gc" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_ObjCIndependentClass: {
    if (Name == "objc_independent_class" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "objc_independent_class" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "objc_independent_class" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_ObjCInertUnsafeUnretained: {
    if (Name == "__unsafe_unretained" && getSyntax() == AttributeCommonInfo::AS_Keyword && Scope == "")
        return 0;
    break;
  }
  case AT_ObjCKindOf: {
    if (Name == "__kindof" && getSyntax() == AttributeCommonInfo::AS_Keyword && Scope == "")
        return 0;
    break;
  }
  case AT_ObjCMethodFamily: {
    if (Name == "objc_method_family" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "objc_method_family" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "objc_method_family" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_ObjCNSObject: {
    if (Name == "NSObject" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "NSObject" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "NSObject" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_ObjCNonLazyClass: {
    if (Name == "objc_nonlazy_class" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "objc_nonlazy_class" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "objc_nonlazy_class" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_ObjCNonRuntimeProtocol: {
    if (Name == "objc_non_runtime_protocol" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "objc_non_runtime_protocol" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "objc_non_runtime_protocol" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_ObjCOwnership: {
    if (Name == "objc_ownership" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "objc_ownership" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "objc_ownership" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_ObjCPreciseLifetime: {
    if (Name == "objc_precise_lifetime" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "objc_precise_lifetime" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "objc_precise_lifetime" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_ObjCRequiresPropertyDefs: {
    if (Name == "objc_requires_property_definitions" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "objc_requires_property_definitions" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "objc_requires_property_definitions" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_ObjCRequiresSuper: {
    if (Name == "objc_requires_super" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "objc_requires_super" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "objc_requires_super" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_ObjCReturnsInnerPointer: {
    if (Name == "objc_returns_inner_pointer" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "objc_returns_inner_pointer" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "objc_returns_inner_pointer" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_ObjCRootClass: {
    if (Name == "objc_root_class" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "objc_root_class" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "objc_root_class" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_ObjCRuntimeName: {
    if (Name == "objc_runtime_name" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "objc_runtime_name" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "objc_runtime_name" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_ObjCRuntimeVisible: {
    if (Name == "objc_runtime_visible" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "objc_runtime_visible" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "objc_runtime_visible" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_ObjCSubclassingRestricted: {
    if (Name == "objc_subclassing_restricted" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "objc_subclassing_restricted" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "objc_subclassing_restricted" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_OpenCLAccess: {
    if (Name == "__read_only" && getSyntax() == AttributeCommonInfo::AS_Keyword && Scope == "")
        return 0;
    if (Name == "read_only" && getSyntax() == AttributeCommonInfo::AS_Keyword && Scope == "")
        return 1;
    if (Name == "__write_only" && getSyntax() == AttributeCommonInfo::AS_Keyword && Scope == "")
        return 2;
    if (Name == "write_only" && getSyntax() == AttributeCommonInfo::AS_Keyword && Scope == "")
        return 3;
    if (Name == "__read_write" && getSyntax() == AttributeCommonInfo::AS_Keyword && Scope == "")
        return 4;
    if (Name == "read_write" && getSyntax() == AttributeCommonInfo::AS_Keyword && Scope == "")
        return 5;
    break;
  }
  case AT_OpenCLConstantAddressSpace: {
    if (Name == "__constant" && getSyntax() == AttributeCommonInfo::AS_Keyword && Scope == "")
        return 0;
    if (Name == "constant" && getSyntax() == AttributeCommonInfo::AS_Keyword && Scope == "")
        return 1;
    if (Name == "opencl_constant" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 2;
    if (Name == "opencl_constant" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 3;
    if (Name == "opencl_constant" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 4;
    break;
  }
  case AT_OpenCLGenericAddressSpace: {
    if (Name == "__generic" && getSyntax() == AttributeCommonInfo::AS_Keyword && Scope == "")
        return 0;
    if (Name == "generic" && getSyntax() == AttributeCommonInfo::AS_Keyword && Scope == "")
        return 1;
    if (Name == "opencl_generic" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 2;
    if (Name == "opencl_generic" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 3;
    if (Name == "opencl_generic" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 4;
    break;
  }
  case AT_OpenCLGlobalAddressSpace: {
    if (Name == "__global" && getSyntax() == AttributeCommonInfo::AS_Keyword && Scope == "")
        return 0;
    if (Name == "global" && getSyntax() == AttributeCommonInfo::AS_Keyword && Scope == "")
        return 1;
    if (Name == "opencl_global" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 2;
    if (Name == "opencl_global" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 3;
    if (Name == "opencl_global" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 4;
    break;
  }
  case AT_OpenCLGlobalDeviceAddressSpace: {
    if (Name == "opencl_global_device" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "opencl_global_device" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "opencl_global_device" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_OpenCLGlobalHostAddressSpace: {
    if (Name == "opencl_global_host" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "opencl_global_host" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "opencl_global_host" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_OpenCLIntelReqdSubGroupSize: {
    if (Name == "intel_reqd_sub_group_size" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    break;
  }
  case AT_OpenCLKernel: {
    if (Name == "__kernel" && getSyntax() == AttributeCommonInfo::AS_Keyword && Scope == "")
        return 0;
    if (Name == "kernel" && getSyntax() == AttributeCommonInfo::AS_Keyword && Scope == "")
        return 1;
    break;
  }
  case AT_OpenCLLocalAddressSpace: {
    if (Name == "__local" && getSyntax() == AttributeCommonInfo::AS_Keyword && Scope == "")
        return 0;
    if (Name == "local" && getSyntax() == AttributeCommonInfo::AS_Keyword && Scope == "")
        return 1;
    if (Name == "opencl_local" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 2;
    if (Name == "opencl_local" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 3;
    if (Name == "opencl_local" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 4;
    break;
  }
  case AT_OpenCLNoSVM: {
    if (Name == "nosvm" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    break;
  }
  case AT_OpenCLPrivateAddressSpace: {
    if (Name == "__private" && getSyntax() == AttributeCommonInfo::AS_Keyword && Scope == "")
        return 0;
    if (Name == "private" && getSyntax() == AttributeCommonInfo::AS_Keyword && Scope == "")
        return 1;
    if (Name == "opencl_private" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 2;
    if (Name == "opencl_private" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 3;
    if (Name == "opencl_private" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 4;
    break;
  }
  case AT_OpenCLUnrollHint: {
    if (Name == "opencl_unroll_hint" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    break;
  }
  case AT_OptimizeNone: {
    if (Name == "optnone" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "optnone" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "optnone" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_Overloadable: {
    if (Name == "overloadable" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "overloadable" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "overloadable" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_Owner: {
    if (Name == "Owner" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "gsl")
        return 0;
    break;
  }
  case AT_Ownership: {
    if (Name == "ownership_holds" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "ownership_holds" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "ownership_holds" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    if (Name == "ownership_returns" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 3;
    if (Name == "ownership_returns" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 4;
    if (Name == "ownership_returns" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 5;
    if (Name == "ownership_takes" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 6;
    if (Name == "ownership_takes" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 7;
    if (Name == "ownership_takes" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 8;
    break;
  }
  case AT_Packed: {
    if (Name == "packed" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "packed" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "gnu")
        return 1;
    if (Name == "packed" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "gnu")
        return 2;
    break;
  }
  case AT_ParamTypestate: {
    if (Name == "param_typestate" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "param_typestate" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    break;
  }
  case AT_Pascal: {
    if (Name == "pascal" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "pascal" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "pascal" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    if (Name == "__pascal" && getSyntax() == AttributeCommonInfo::AS_Keyword && Scope == "")
        return 3;
    if (Name == "_pascal" && getSyntax() == AttributeCommonInfo::AS_Keyword && Scope == "")
        return 4;
    break;
  }
  case AT_PassObjectSize: {
    if (Name == "pass_object_size" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "pass_object_size" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "pass_object_size" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    if (Name == "pass_dynamic_object_size" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 3;
    if (Name == "pass_dynamic_object_size" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 4;
    if (Name == "pass_dynamic_object_size" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 5;
    break;
  }
  case AT_PatchableFunctionEntry: {
    if (Name == "patchable_function_entry" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "patchable_function_entry" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "gnu")
        return 1;
    if (Name == "patchable_function_entry" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "gnu")
        return 2;
    break;
  }
  case AT_Pcs: {
    if (Name == "pcs" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "pcs" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "gnu")
        return 1;
    if (Name == "pcs" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "gnu")
        return 2;
    break;
  }
  case AT_Pointer: {
    if (Name == "Pointer" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "gsl")
        return 0;
    break;
  }
  case AT_PragmaClangBSSSection: {
    break;
  }
  case AT_PragmaClangDataSection: {
    break;
  }
  case AT_PragmaClangRelroSection: {
    break;
  }
  case AT_PragmaClangRodataSection: {
    break;
  }
  case AT_PragmaClangTextSection: {
    break;
  }
  case AT_PreferredName: {
    if (Name == "preferred_name" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "preferred_name" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    break;
  }
  case AT_PreserveAll: {
    if (Name == "preserve_all" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "preserve_all" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "preserve_all" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_PreserveMost: {
    if (Name == "preserve_most" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "preserve_most" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "preserve_most" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_PtGuardedBy: {
    if (Name == "pt_guarded_by" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    break;
  }
  case AT_PtGuardedVar: {
    if (Name == "pt_guarded_var" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "pt_guarded_var" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    break;
  }
  case AT_Ptr32: {
    if (Name == "__ptr32" && getSyntax() == AttributeCommonInfo::AS_Keyword && Scope == "")
        return 0;
    break;
  }
  case AT_Ptr64: {
    if (Name == "__ptr64" && getSyntax() == AttributeCommonInfo::AS_Keyword && Scope == "")
        return 0;
    break;
  }
  case AT_Pure: {
    if (Name == "pure" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "pure" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "gnu")
        return 1;
    if (Name == "pure" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "gnu")
        return 2;
    break;
  }
  case AT_RegCall: {
    if (Name == "regcall" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "regcall" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "gnu")
        return 1;
    if (Name == "regcall" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "gnu")
        return 2;
    if (Name == "__regcall" && getSyntax() == AttributeCommonInfo::AS_Keyword && Scope == "")
        return 3;
    break;
  }
  case AT_Regparm: {
    if (Name == "regparm" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "regparm" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "gnu")
        return 1;
    if (Name == "regparm" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "gnu")
        return 2;
    break;
  }
  case AT_Reinitializes: {
    if (Name == "reinitializes" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "reinitializes" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    break;
  }
  case AT_ReleaseCapability: {
    if (Name == "release_capability" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "release_capability" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "release_shared_capability" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 2;
    if (Name == "release_shared_capability" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 3;
    if (Name == "release_generic_capability" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 4;
    if (Name == "release_generic_capability" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 5;
    if (Name == "unlock_function" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 6;
    if (Name == "unlock_function" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 7;
    break;
  }
  case AT_ReleaseHandle: {
    if (Name == "release_handle" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "release_handle" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "release_handle" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_RenderScriptKernel: {
    if (Name == "kernel" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    break;
  }
  case AT_ReqdWorkGroupSize: {
    if (Name == "reqd_work_group_size" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    break;
  }
  case AT_RequiresCapability: {
    if (Name == "requires_capability" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "requires_capability" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "exclusive_locks_required" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 2;
    if (Name == "exclusive_locks_required" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 3;
    if (Name == "requires_shared_capability" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 4;
    if (Name == "requires_shared_capability" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 5;
    if (Name == "shared_locks_required" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 6;
    if (Name == "shared_locks_required" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 7;
    break;
  }
  case AT_Restrict: {
    if (Name == "restrict" && getSyntax() == AttributeCommonInfo::AS_Declspec && Scope == "")
        return 0;
    if (Name == "malloc" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 1;
    if (Name == "malloc" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "gnu")
        return 2;
    if (Name == "malloc" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "gnu")
        return 3;
    break;
  }
  case AT_Retain: {
    if (Name == "retain" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "retain" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "gnu")
        return 1;
    if (Name == "retain" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "gnu")
        return 2;
    break;
  }
  case AT_ReturnTypestate: {
    if (Name == "return_typestate" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "return_typestate" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    break;
  }
  case AT_ReturnsNonNull: {
    if (Name == "returns_nonnull" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "returns_nonnull" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "gnu")
        return 1;
    if (Name == "returns_nonnull" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "gnu")
        return 2;
    break;
  }
  case AT_ReturnsTwice: {
    if (Name == "returns_twice" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "returns_twice" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "gnu")
        return 1;
    if (Name == "returns_twice" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "gnu")
        return 2;
    break;
  }
  case AT_SPtr: {
    if (Name == "__sptr" && getSyntax() == AttributeCommonInfo::AS_Keyword && Scope == "")
        return 0;
    break;
  }
  case AT_SYCLKernel: {
    if (Name == "sycl_kernel" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "sycl_kernel" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "sycl_kernel" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_ScopedLockable: {
    if (Name == "scoped_lockable" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "scoped_lockable" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    break;
  }
  case AT_Section: {
    if (Name == "section" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "section" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "gnu")
        return 1;
    if (Name == "section" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "gnu")
        return 2;
    if (Name == "allocate" && getSyntax() == AttributeCommonInfo::AS_Declspec && Scope == "")
        return 3;
    break;
  }
  case AT_SelectAny: {
    if (Name == "selectany" && getSyntax() == AttributeCommonInfo::AS_Declspec && Scope == "")
        return 0;
    if (Name == "selectany" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 1;
    if (Name == "selectany" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "gnu")
        return 2;
    if (Name == "selectany" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "gnu")
        return 3;
    break;
  }
  case AT_Sentinel: {
    if (Name == "sentinel" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "sentinel" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "gnu")
        return 1;
    if (Name == "sentinel" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "gnu")
        return 2;
    break;
  }
  case AT_SetTypestate: {
    if (Name == "set_typestate" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "set_typestate" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    break;
  }
  case AT_SharedTrylockFunction: {
    if (Name == "shared_trylock_function" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    break;
  }
  case AT_SpeculativeLoadHardening: {
    if (Name == "speculative_load_hardening" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "speculative_load_hardening" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "speculative_load_hardening" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_StandaloneDebug: {
    if (Name == "standalone_debug" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "standalone_debug" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    break;
  }
  case AT_StdCall: {
    if (Name == "stdcall" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "stdcall" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "gnu")
        return 1;
    if (Name == "stdcall" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "gnu")
        return 2;
    if (Name == "__stdcall" && getSyntax() == AttributeCommonInfo::AS_Keyword && Scope == "")
        return 3;
    if (Name == "_stdcall" && getSyntax() == AttributeCommonInfo::AS_Keyword && Scope == "")
        return 4;
    break;
  }
  case AT_StrictFP: {
    break;
  }
  case AT_Suppress: {
    if (Name == "suppress" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "gsl")
        return 0;
    break;
  }
  case AT_SwiftAsync: {
    if (Name == "swift_async" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "swift_async" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "swift_async" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_SwiftAsyncCall: {
    if (Name == "swiftasynccall" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "swiftasynccall" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "swiftasynccall" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_SwiftAsyncContext: {
    if (Name == "swift_async_context" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "swift_async_context" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "swift_async_context" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_SwiftAsyncError: {
    if (Name == "swift_async_error" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "swift_async_error" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "swift_async_error" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_SwiftAsyncName: {
    if (Name == "swift_async_name" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    break;
  }
  case AT_SwiftAttr: {
    if (Name == "swift_attr" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    break;
  }
  case AT_SwiftBridge: {
    if (Name == "swift_bridge" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    break;
  }
  case AT_SwiftBridgedTypedef: {
    if (Name == "swift_bridged_typedef" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    break;
  }
  case AT_SwiftCall: {
    if (Name == "swiftcall" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "swiftcall" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "swiftcall" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_SwiftContext: {
    if (Name == "swift_context" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "swift_context" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "swift_context" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_SwiftError: {
    if (Name == "swift_error" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    break;
  }
  case AT_SwiftErrorResult: {
    if (Name == "swift_error_result" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "swift_error_result" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "swift_error_result" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_SwiftIndirectResult: {
    if (Name == "swift_indirect_result" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "swift_indirect_result" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "swift_indirect_result" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_SwiftName: {
    if (Name == "swift_name" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    break;
  }
  case AT_SwiftNewType: {
    if (Name == "swift_newtype" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "swift_wrapper" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 1;
    break;
  }
  case AT_SwiftObjCMembers: {
    if (Name == "swift_objc_members" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    break;
  }
  case AT_SwiftPrivate: {
    if (Name == "swift_private" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    break;
  }
  case AT_SysVABI: {
    if (Name == "sysv_abi" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "sysv_abi" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "gnu")
        return 1;
    if (Name == "sysv_abi" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "gnu")
        return 2;
    break;
  }
  case AT_TLSModel: {
    if (Name == "tls_model" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "tls_model" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "gnu")
        return 1;
    if (Name == "tls_model" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "gnu")
        return 2;
    break;
  }
  case AT_Target: {
    if (Name == "target" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "target" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "gnu")
        return 1;
    if (Name == "target" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "gnu")
        return 2;
    break;
  }
  case AT_TargetClones: {
    if (Name == "target_clones" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "target_clones" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "gnu")
        return 1;
    if (Name == "target_clones" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "gnu")
        return 2;
    break;
  }
  case AT_TestTypestate: {
    if (Name == "test_typestate" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "test_typestate" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    break;
  }
  case AT_ThisCall: {
    if (Name == "thiscall" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "thiscall" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "gnu")
        return 1;
    if (Name == "thiscall" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "gnu")
        return 2;
    if (Name == "__thiscall" && getSyntax() == AttributeCommonInfo::AS_Keyword && Scope == "")
        return 3;
    if (Name == "_thiscall" && getSyntax() == AttributeCommonInfo::AS_Keyword && Scope == "")
        return 4;
    break;
  }
  case AT_Thread: {
    if (Name == "thread" && getSyntax() == AttributeCommonInfo::AS_Declspec && Scope == "")
        return 0;
    break;
  }
  case AT_TransparentUnion: {
    if (Name == "transparent_union" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "transparent_union" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "gnu")
        return 1;
    if (Name == "transparent_union" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "gnu")
        return 2;
    break;
  }
  case AT_TrivialABI: {
    if (Name == "trivial_abi" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "trivial_abi" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    break;
  }
  case AT_TryAcquireCapability: {
    if (Name == "try_acquire_capability" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "try_acquire_capability" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "try_acquire_shared_capability" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 2;
    if (Name == "try_acquire_shared_capability" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 3;
    break;
  }
  case AT_TypeNonNull: {
    if (Name == "_Nonnull" && getSyntax() == AttributeCommonInfo::AS_Keyword && Scope == "")
        return 0;
    break;
  }
  case AT_TypeNullUnspecified: {
    if (Name == "_Null_unspecified" && getSyntax() == AttributeCommonInfo::AS_Keyword && Scope == "")
        return 0;
    break;
  }
  case AT_TypeNullable: {
    if (Name == "_Nullable" && getSyntax() == AttributeCommonInfo::AS_Keyword && Scope == "")
        return 0;
    break;
  }
  case AT_TypeNullableResult: {
    if (Name == "_Nullable_result" && getSyntax() == AttributeCommonInfo::AS_Keyword && Scope == "")
        return 0;
    break;
  }
  case AT_TypeTagForDatatype: {
    if (Name == "type_tag_for_datatype" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "type_tag_for_datatype" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "type_tag_for_datatype" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_TypeVisibility: {
    if (Name == "type_visibility" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "type_visibility" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "type_visibility" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_UPtr: {
    if (Name == "__uptr" && getSyntax() == AttributeCommonInfo::AS_Keyword && Scope == "")
        return 0;
    break;
  }
  case AT_Unavailable: {
    if (Name == "unavailable" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "unavailable" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "unavailable" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_Uninitialized: {
    if (Name == "uninitialized" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "uninitialized" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    break;
  }
  case AT_Unlikely: {
    if (Name == "unlikely" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "")
        return 0;
    if (Name == "unlikely" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 1;
    break;
  }
  case AT_Unused: {
    if (Name == "maybe_unused" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "")
        return 0;
    if (Name == "unused" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 1;
    if (Name == "unused" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "gnu")
        return 2;
    if (Name == "unused" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "gnu")
        return 3;
    if (Name == "maybe_unused" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "")
        return 4;
    break;
  }
  case AT_UseHandle: {
    if (Name == "use_handle" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "use_handle" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "use_handle" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_Used: {
    if (Name == "used" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "used" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "gnu")
        return 1;
    if (Name == "used" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "gnu")
        return 2;
    break;
  }
  case AT_UsingIfExists: {
    if (Name == "using_if_exists" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "using_if_exists" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    break;
  }
  case AT_Uuid: {
    if (Name == "uuid" && getSyntax() == AttributeCommonInfo::AS_Declspec && Scope == "")
        return 0;
    if (Name == "uuid" && getSyntax() == AttributeCommonInfo::AS_Microsoft && Scope == "")
        return 1;
    break;
  }
  case AT_VecReturn: {
    if (Name == "vecreturn" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "vecreturn" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    break;
  }
  case AT_VecTypeHint: {
    if (Name == "vec_type_hint" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    break;
  }
  case AT_VectorCall: {
    if (Name == "vectorcall" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "vectorcall" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "vectorcall" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    if (Name == "__vectorcall" && getSyntax() == AttributeCommonInfo::AS_Keyword && Scope == "")
        return 3;
    if (Name == "_vectorcall" && getSyntax() == AttributeCommonInfo::AS_Keyword && Scope == "")
        return 4;
    break;
  }
  case AT_VectorSize: {
    if (Name == "vector_size" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "vector_size" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "gnu")
        return 1;
    if (Name == "vector_size" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "gnu")
        return 2;
    break;
  }
  case AT_Visibility: {
    if (Name == "visibility" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "visibility" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "gnu")
        return 1;
    if (Name == "visibility" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "gnu")
        return 2;
    break;
  }
  case AT_WarnUnused: {
    if (Name == "warn_unused" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "warn_unused" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "gnu")
        return 1;
    if (Name == "warn_unused" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "gnu")
        return 2;
    break;
  }
  case AT_WarnUnusedResult: {
    if (Name == "nodiscard" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "")
        return 0;
    if (Name == "nodiscard" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "")
        return 1;
    if (Name == "warn_unused_result" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 2;
    if (Name == "warn_unused_result" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 3;
    if (Name == "warn_unused_result" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "gnu")
        return 4;
    if (Name == "warn_unused_result" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "gnu")
        return 5;
    break;
  }
  case AT_Weak: {
    if (Name == "weak" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "weak" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "gnu")
        return 1;
    if (Name == "weak" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "gnu")
        return 2;
    break;
  }
  case AT_WeakImport: {
    if (Name == "weak_import" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "weak_import" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "weak_import" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_WeakRef: {
    if (Name == "weakref" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "weakref" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "gnu")
        return 1;
    if (Name == "weakref" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "gnu")
        return 2;
    break;
  }
  case AT_WebAssemblyExportName: {
    if (Name == "export_name" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "export_name" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "export_name" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_WebAssemblyImportModule: {
    if (Name == "import_module" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "import_module" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "import_module" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_WebAssemblyImportName: {
    if (Name == "import_name" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "import_name" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "import_name" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  case AT_WorkGroupSizeHint: {
    if (Name == "work_group_size_hint" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    break;
  }
  case AT_X86ForceAlignArgPointer: {
    if (Name == "force_align_arg_pointer" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "force_align_arg_pointer" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "gnu")
        return 1;
    if (Name == "force_align_arg_pointer" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "gnu")
        return 2;
    break;
  }
  case AT_XRayInstrument: {
    if (Name == "xray_always_instrument" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "xray_always_instrument" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "xray_always_instrument" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    if (Name == "xray_never_instrument" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 3;
    if (Name == "xray_never_instrument" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 4;
    if (Name == "xray_never_instrument" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 5;
    break;
  }
  case AT_XRayLogArgs: {
    if (Name == "xray_log_args" && getSyntax() == AttributeCommonInfo::AS_GNU && Scope == "")
        return 0;
    if (Name == "xray_log_args" && getSyntax() == AttributeCommonInfo::AS_CXX11 && Scope == "clang")
        return 1;
    if (Name == "xray_log_args" && getSyntax() == AttributeCommonInfo::AS_C2x && Scope == "clang")
        return 2;
    break;
  }
  }
  return 0;
