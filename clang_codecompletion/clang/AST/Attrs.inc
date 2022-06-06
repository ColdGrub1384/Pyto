/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Attribute classes' definitions                                             *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

#ifndef LLVM_CLANG_ATTR_CLASSES_INC
#define LLVM_CLANG_ATTR_CLASSES_INC

static inline void DelimitAttributeArgument(raw_ostream& OS, bool& IsFirst) {
  if (IsFirst) {
    IsFirst = false;
    OS << "(";
  } else
    OS << ", ";
}
class AArch64VectorPcsAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_aarch64_vector_pcs = 0,
    CXX11_clang_aarch64_vector_pcs = 1,
    C2x_clang_aarch64_vector_pcs = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static AArch64VectorPcsAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static AArch64VectorPcsAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static AArch64VectorPcsAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static AArch64VectorPcsAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  AArch64VectorPcsAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  AArch64VectorPcsAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::AArch64VectorPcs; }
};

class AMDGPUFlatWorkGroupSizeAttr : public InheritableAttr {
Expr * min;

Expr * max;

public:
  enum Spelling {
    GNU_amdgpu_flat_work_group_size = 0,
    CXX11_clang_amdgpu_flat_work_group_size = 1,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static AMDGPUFlatWorkGroupSizeAttr *CreateImplicit(ASTContext &Ctx, Expr * Min, Expr * Max, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static AMDGPUFlatWorkGroupSizeAttr *Create(ASTContext &Ctx, Expr * Min, Expr * Max, const AttributeCommonInfo &CommonInfo);
  static AMDGPUFlatWorkGroupSizeAttr *CreateImplicit(ASTContext &Ctx, Expr * Min, Expr * Max, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static AMDGPUFlatWorkGroupSizeAttr *Create(ASTContext &Ctx, Expr * Min, Expr * Max, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  AMDGPUFlatWorkGroupSizeAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , Expr * Min
              , Expr * Max
             );

  AMDGPUFlatWorkGroupSizeAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  Expr * getMin() const {
    return min;
  }

  Expr * getMax() const {
    return max;
  }



  static bool classof(const Attr *A) { return A->getKind() == attr::AMDGPUFlatWorkGroupSize; }
};

class AMDGPUNumSGPRAttr : public InheritableAttr {
unsigned numSGPR;

public:
  enum Spelling {
    GNU_amdgpu_num_sgpr = 0,
    CXX11_clang_amdgpu_num_sgpr = 1,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static AMDGPUNumSGPRAttr *CreateImplicit(ASTContext &Ctx, unsigned NumSGPR, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static AMDGPUNumSGPRAttr *Create(ASTContext &Ctx, unsigned NumSGPR, const AttributeCommonInfo &CommonInfo);
  static AMDGPUNumSGPRAttr *CreateImplicit(ASTContext &Ctx, unsigned NumSGPR, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static AMDGPUNumSGPRAttr *Create(ASTContext &Ctx, unsigned NumSGPR, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  AMDGPUNumSGPRAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , unsigned NumSGPR
             );

  AMDGPUNumSGPRAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  unsigned getNumSGPR() const {
    return numSGPR;
  }



  static bool classof(const Attr *A) { return A->getKind() == attr::AMDGPUNumSGPR; }
};

class AMDGPUNumVGPRAttr : public InheritableAttr {
unsigned numVGPR;

public:
  enum Spelling {
    GNU_amdgpu_num_vgpr = 0,
    CXX11_clang_amdgpu_num_vgpr = 1,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static AMDGPUNumVGPRAttr *CreateImplicit(ASTContext &Ctx, unsigned NumVGPR, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static AMDGPUNumVGPRAttr *Create(ASTContext &Ctx, unsigned NumVGPR, const AttributeCommonInfo &CommonInfo);
  static AMDGPUNumVGPRAttr *CreateImplicit(ASTContext &Ctx, unsigned NumVGPR, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static AMDGPUNumVGPRAttr *Create(ASTContext &Ctx, unsigned NumVGPR, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  AMDGPUNumVGPRAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , unsigned NumVGPR
             );

  AMDGPUNumVGPRAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  unsigned getNumVGPR() const {
    return numVGPR;
  }



  static bool classof(const Attr *A) { return A->getKind() == attr::AMDGPUNumVGPR; }
};

class AMDGPUWavesPerEUAttr : public InheritableAttr {
Expr * min;

Expr * max;

public:
  enum Spelling {
    GNU_amdgpu_waves_per_eu = 0,
    CXX11_clang_amdgpu_waves_per_eu = 1,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static AMDGPUWavesPerEUAttr *CreateImplicit(ASTContext &Ctx, Expr * Min, Expr * Max, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static AMDGPUWavesPerEUAttr *Create(ASTContext &Ctx, Expr * Min, Expr * Max, const AttributeCommonInfo &CommonInfo);
  static AMDGPUWavesPerEUAttr *CreateImplicit(ASTContext &Ctx, Expr * Min, Expr * Max, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static AMDGPUWavesPerEUAttr *Create(ASTContext &Ctx, Expr * Min, Expr * Max, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  AMDGPUWavesPerEUAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , Expr * Min
              , Expr * Max
             );
  AMDGPUWavesPerEUAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , Expr * Min
             );

  AMDGPUWavesPerEUAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  Expr * getMin() const {
    return min;
  }

  Expr * getMax() const {
    return max;
  }



  static bool classof(const Attr *A) { return A->getKind() == attr::AMDGPUWavesPerEU; }
};

class ARMInterruptAttr : public InheritableAttr {
public:
  enum InterruptType {
    IRQ,
    FIQ,
    SWI,
    ABORT,
    UNDEF,
    Generic
  };
private:
  InterruptType interrupt;

public:
  enum Spelling {
    GNU_interrupt = 0,
    CXX11_gnu_interrupt = 1,
    C2x_gnu_interrupt = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static ARMInterruptAttr *CreateImplicit(ASTContext &Ctx, InterruptType Interrupt, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static ARMInterruptAttr *Create(ASTContext &Ctx, InterruptType Interrupt, const AttributeCommonInfo &CommonInfo);
  static ARMInterruptAttr *CreateImplicit(ASTContext &Ctx, InterruptType Interrupt, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static ARMInterruptAttr *Create(ASTContext &Ctx, InterruptType Interrupt, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  ARMInterruptAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , InterruptType Interrupt
             );
  ARMInterruptAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  ARMInterruptAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  InterruptType getInterrupt() const {
    return interrupt;
  }

  static bool ConvertStrToInterruptType(StringRef Val, InterruptType &Out);
  static const char *ConvertInterruptTypeToStr(InterruptType Val);


  static bool classof(const Attr *A) { return A->getKind() == attr::ARMInterrupt; }
};

class AVRInterruptAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_interrupt = 0,
    CXX11_gnu_interrupt = 1,
    C2x_gnu_interrupt = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static AVRInterruptAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static AVRInterruptAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static AVRInterruptAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static AVRInterruptAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  AVRInterruptAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  AVRInterruptAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::AVRInterrupt; }
};

class AVRSignalAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_signal = 0,
    CXX11_gnu_signal = 1,
    C2x_gnu_signal = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static AVRSignalAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static AVRSignalAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static AVRSignalAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static AVRSignalAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  AVRSignalAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  AVRSignalAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::AVRSignal; }
};

class AbiTagAttr : public Attr {
  unsigned tags_Size;
  StringRef *tags_;

public:
  enum Spelling {
    GNU_abi_tag = 0,
    CXX11_gnu_abi_tag = 1,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static AbiTagAttr *CreateImplicit(ASTContext &Ctx, StringRef *Tags, unsigned TagsSize, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static AbiTagAttr *Create(ASTContext &Ctx, StringRef *Tags, unsigned TagsSize, const AttributeCommonInfo &CommonInfo);
  static AbiTagAttr *CreateImplicit(ASTContext &Ctx, StringRef *Tags, unsigned TagsSize, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static AbiTagAttr *Create(ASTContext &Ctx, StringRef *Tags, unsigned TagsSize, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  AbiTagAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , StringRef *Tags, unsigned TagsSize
             );
  AbiTagAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  AbiTagAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  typedef StringRef* tags_iterator;
  tags_iterator tags_begin() const { return tags_; }
  tags_iterator tags_end() const { return tags_ + tags_Size; }
  unsigned tags_size() const { return tags_Size; }
  llvm::iterator_range<tags_iterator> tags() const { return llvm::make_range(tags_begin(), tags_end()); }




  static bool classof(const Attr *A) { return A->getKind() == attr::AbiTag; }
};

class AcquireCapabilityAttr : public InheritableAttr {
  unsigned args_Size;
  Expr * *args_;

public:
  enum Spelling {
    GNU_acquire_capability = 0,
    CXX11_clang_acquire_capability = 1,
    GNU_acquire_shared_capability = 2,
    CXX11_clang_acquire_shared_capability = 3,
    GNU_exclusive_lock_function = 4,
    GNU_shared_lock_function = 5,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static AcquireCapabilityAttr *CreateImplicit(ASTContext &Ctx, Expr * *Args, unsigned ArgsSize, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static AcquireCapabilityAttr *Create(ASTContext &Ctx, Expr * *Args, unsigned ArgsSize, const AttributeCommonInfo &CommonInfo);
  static AcquireCapabilityAttr *CreateImplicit(ASTContext &Ctx, Expr * *Args, unsigned ArgsSize, SourceRange Range, AttributeCommonInfo::Syntax Syntax, AcquireCapabilityAttr::Spelling S = static_cast<Spelling>(SpellingNotCalculated));
  static AcquireCapabilityAttr *Create(ASTContext &Ctx, Expr * *Args, unsigned ArgsSize, SourceRange Range, AttributeCommonInfo::Syntax Syntax, AcquireCapabilityAttr::Spelling S = static_cast<Spelling>(SpellingNotCalculated));

  // Constructors
  AcquireCapabilityAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , Expr * *Args, unsigned ArgsSize
             );
  AcquireCapabilityAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  AcquireCapabilityAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  Spelling getSemanticSpelling() const;
  bool isShared() const { return getAttributeSpellingListIndex() == 2 ||
    getAttributeSpellingListIndex() == 3 ||
    getAttributeSpellingListIndex() == 5; }
  typedef Expr ** args_iterator;
  args_iterator args_begin() const { return args_; }
  args_iterator args_end() const { return args_ + args_Size; }
  unsigned args_size() const { return args_Size; }
  llvm::iterator_range<args_iterator> args() const { return llvm::make_range(args_begin(), args_end()); }




  static bool classof(const Attr *A) { return A->getKind() == attr::AcquireCapability; }
};

class AcquireHandleAttr : public InheritableAttr {
unsigned handleTypeLength;
char *handleType;

public:
  enum Spelling {
    GNU_acquire_handle = 0,
    CXX11_clang_acquire_handle = 1,
    C2x_clang_acquire_handle = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static AcquireHandleAttr *CreateImplicit(ASTContext &Ctx, llvm::StringRef HandleType, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static AcquireHandleAttr *Create(ASTContext &Ctx, llvm::StringRef HandleType, const AttributeCommonInfo &CommonInfo);
  static AcquireHandleAttr *CreateImplicit(ASTContext &Ctx, llvm::StringRef HandleType, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static AcquireHandleAttr *Create(ASTContext &Ctx, llvm::StringRef HandleType, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  AcquireHandleAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , llvm::StringRef HandleType
             );

  AcquireHandleAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  llvm::StringRef getHandleType() const {
    return llvm::StringRef(handleType, handleTypeLength);
  }
  unsigned getHandleTypeLength() const {
    return handleTypeLength;
  }
  void setHandleType(ASTContext &C, llvm::StringRef S) {
    handleTypeLength = S.size();
    this->handleType = new (C, 1) char [handleTypeLength];
    if (!S.empty())
      std::memcpy(this->handleType, S.data(), handleTypeLength);
  }



  static bool classof(const Attr *A) { return A->getKind() == attr::AcquireHandle; }
};

class AcquiredAfterAttr : public InheritableAttr {
  unsigned args_Size;
  Expr * *args_;

public:
  // Factory methods
  static AcquiredAfterAttr *CreateImplicit(ASTContext &Ctx, Expr * *Args, unsigned ArgsSize, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static AcquiredAfterAttr *Create(ASTContext &Ctx, Expr * *Args, unsigned ArgsSize, const AttributeCommonInfo &CommonInfo);
  static AcquiredAfterAttr *CreateImplicit(ASTContext &Ctx, Expr * *Args, unsigned ArgsSize, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static AcquiredAfterAttr *Create(ASTContext &Ctx, Expr * *Args, unsigned ArgsSize, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  AcquiredAfterAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , Expr * *Args, unsigned ArgsSize
             );
  AcquiredAfterAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  AcquiredAfterAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  typedef Expr ** args_iterator;
  args_iterator args_begin() const { return args_; }
  args_iterator args_end() const { return args_ + args_Size; }
  unsigned args_size() const { return args_Size; }
  llvm::iterator_range<args_iterator> args() const { return llvm::make_range(args_begin(), args_end()); }




  static bool classof(const Attr *A) { return A->getKind() == attr::AcquiredAfter; }
};

class AcquiredBeforeAttr : public InheritableAttr {
  unsigned args_Size;
  Expr * *args_;

public:
  // Factory methods
  static AcquiredBeforeAttr *CreateImplicit(ASTContext &Ctx, Expr * *Args, unsigned ArgsSize, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static AcquiredBeforeAttr *Create(ASTContext &Ctx, Expr * *Args, unsigned ArgsSize, const AttributeCommonInfo &CommonInfo);
  static AcquiredBeforeAttr *CreateImplicit(ASTContext &Ctx, Expr * *Args, unsigned ArgsSize, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static AcquiredBeforeAttr *Create(ASTContext &Ctx, Expr * *Args, unsigned ArgsSize, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  AcquiredBeforeAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , Expr * *Args, unsigned ArgsSize
             );
  AcquiredBeforeAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  AcquiredBeforeAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  typedef Expr ** args_iterator;
  args_iterator args_begin() const { return args_; }
  args_iterator args_end() const { return args_ + args_Size; }
  unsigned args_size() const { return args_Size; }
  llvm::iterator_range<args_iterator> args() const { return llvm::make_range(args_begin(), args_end()); }




  static bool classof(const Attr *A) { return A->getKind() == attr::AcquiredBefore; }
};

class AddressSpaceAttr : public TypeAttr {
int addressSpace;

public:
  enum Spelling {
    GNU_address_space = 0,
    CXX11_clang_address_space = 1,
    C2x_clang_address_space = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static AddressSpaceAttr *CreateImplicit(ASTContext &Ctx, int AddressSpace, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static AddressSpaceAttr *Create(ASTContext &Ctx, int AddressSpace, const AttributeCommonInfo &CommonInfo);
  static AddressSpaceAttr *CreateImplicit(ASTContext &Ctx, int AddressSpace, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static AddressSpaceAttr *Create(ASTContext &Ctx, int AddressSpace, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  AddressSpaceAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , int AddressSpace
             );

  AddressSpaceAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  int getAddressSpace() const {
    return addressSpace;
  }



  static bool classof(const Attr *A) { return A->getKind() == attr::AddressSpace; }
};

class AliasAttr : public Attr {
unsigned aliaseeLength;
char *aliasee;

public:
  enum Spelling {
    GNU_alias = 0,
    CXX11_gnu_alias = 1,
    C2x_gnu_alias = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static AliasAttr *CreateImplicit(ASTContext &Ctx, llvm::StringRef Aliasee, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static AliasAttr *Create(ASTContext &Ctx, llvm::StringRef Aliasee, const AttributeCommonInfo &CommonInfo);
  static AliasAttr *CreateImplicit(ASTContext &Ctx, llvm::StringRef Aliasee, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static AliasAttr *Create(ASTContext &Ctx, llvm::StringRef Aliasee, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  AliasAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , llvm::StringRef Aliasee
             );

  AliasAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  llvm::StringRef getAliasee() const {
    return llvm::StringRef(aliasee, aliaseeLength);
  }
  unsigned getAliaseeLength() const {
    return aliaseeLength;
  }
  void setAliasee(ASTContext &C, llvm::StringRef S) {
    aliaseeLength = S.size();
    this->aliasee = new (C, 1) char [aliaseeLength];
    if (!S.empty())
      std::memcpy(this->aliasee, S.data(), aliaseeLength);
  }



  static bool classof(const Attr *A) { return A->getKind() == attr::Alias; }
};

class AlignMac68kAttr : public InheritableAttr {
public:
  // Factory methods
  static AlignMac68kAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static AlignMac68kAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static AlignMac68kAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static AlignMac68kAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  AlignMac68kAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  AlignMac68kAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::AlignMac68k; }
};

class AlignNaturalAttr : public InheritableAttr {
public:
  // Factory methods
  static AlignNaturalAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static AlignNaturalAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static AlignNaturalAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static AlignNaturalAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  AlignNaturalAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  AlignNaturalAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::AlignNatural; }
};

class AlignValueAttr : public Attr {
Expr * alignment;

public:
  // Factory methods
  static AlignValueAttr *CreateImplicit(ASTContext &Ctx, Expr * Alignment, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static AlignValueAttr *Create(ASTContext &Ctx, Expr * Alignment, const AttributeCommonInfo &CommonInfo);
  static AlignValueAttr *CreateImplicit(ASTContext &Ctx, Expr * Alignment, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static AlignValueAttr *Create(ASTContext &Ctx, Expr * Alignment, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  AlignValueAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , Expr * Alignment
             );

  AlignValueAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  Expr * getAlignment() const {
    return alignment;
  }



  static bool classof(const Attr *A) { return A->getKind() == attr::AlignValue; }
};

class AlignedAttr : public InheritableAttr {
bool isalignmentExpr;
union {
Expr *alignmentExpr;
TypeSourceInfo *alignmentType;
};

public:
  enum Spelling {
    GNU_aligned = 0,
    CXX11_gnu_aligned = 1,
    C2x_gnu_aligned = 2,
    Declspec_align = 3,
    Keyword_alignas = 4,
    Keyword_Alignas = 5,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static AlignedAttr *CreateImplicit(ASTContext &Ctx, bool IsAlignmentExpr, void *Alignment, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static AlignedAttr *Create(ASTContext &Ctx, bool IsAlignmentExpr, void *Alignment, const AttributeCommonInfo &CommonInfo);
  static AlignedAttr *CreateImplicit(ASTContext &Ctx, bool IsAlignmentExpr, void *Alignment, SourceRange Range, AttributeCommonInfo::Syntax Syntax, AlignedAttr::Spelling S = static_cast<Spelling>(SpellingNotCalculated));
  static AlignedAttr *Create(ASTContext &Ctx, bool IsAlignmentExpr, void *Alignment, SourceRange Range, AttributeCommonInfo::Syntax Syntax, AlignedAttr::Spelling S = static_cast<Spelling>(SpellingNotCalculated));

  // Constructors
  AlignedAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , bool IsAlignmentExpr, void *Alignment
             );
  AlignedAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  AlignedAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  Spelling getSemanticSpelling() const;
  bool isGNU() const { return getAttributeSpellingListIndex() == 0 ||
    getAttributeSpellingListIndex() == 1 ||
    getAttributeSpellingListIndex() == 2; }
  bool isC11() const { return getAttributeSpellingListIndex() == 5; }
  bool isAlignas() const { return getAttributeSpellingListIndex() == 4 ||
    getAttributeSpellingListIndex() == 5; }
  bool isDeclspec() const { return getAttributeSpellingListIndex() == 3; }
  bool isAlignmentDependent() const;
  bool isAlignmentErrorDependent() const;
  unsigned getAlignment(ASTContext &Ctx) const;
  bool isAlignmentExpr() const {
    return isalignmentExpr;
  }
  Expr *getAlignmentExpr() const {
    assert(isalignmentExpr);
    return alignmentExpr;
  }
  TypeSourceInfo *getAlignmentType() const {
    assert(!isalignmentExpr);
    return alignmentType;
  }



  static bool classof(const Attr *A) { return A->getKind() == attr::Aligned; }
};

class AllocAlignAttr : public InheritableAttr {
ParamIdx paramIndex;

public:
  enum Spelling {
    GNU_alloc_align = 0,
    CXX11_gnu_alloc_align = 1,
    C2x_gnu_alloc_align = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static AllocAlignAttr *CreateImplicit(ASTContext &Ctx, ParamIdx ParamIndex, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static AllocAlignAttr *Create(ASTContext &Ctx, ParamIdx ParamIndex, const AttributeCommonInfo &CommonInfo);
  static AllocAlignAttr *CreateImplicit(ASTContext &Ctx, ParamIdx ParamIndex, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static AllocAlignAttr *Create(ASTContext &Ctx, ParamIdx ParamIndex, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  AllocAlignAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , ParamIdx ParamIndex
             );

  AllocAlignAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  ParamIdx getParamIndex() const {
    return paramIndex;
  }



  static bool classof(const Attr *A) { return A->getKind() == attr::AllocAlign; }
};

class AllocSizeAttr : public InheritableAttr {
ParamIdx elemSizeParam;

ParamIdx numElemsParam;

public:
  enum Spelling {
    GNU_alloc_size = 0,
    CXX11_gnu_alloc_size = 1,
    C2x_gnu_alloc_size = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static AllocSizeAttr *CreateImplicit(ASTContext &Ctx, ParamIdx ElemSizeParam, ParamIdx NumElemsParam, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static AllocSizeAttr *Create(ASTContext &Ctx, ParamIdx ElemSizeParam, ParamIdx NumElemsParam, const AttributeCommonInfo &CommonInfo);
  static AllocSizeAttr *CreateImplicit(ASTContext &Ctx, ParamIdx ElemSizeParam, ParamIdx NumElemsParam, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static AllocSizeAttr *Create(ASTContext &Ctx, ParamIdx ElemSizeParam, ParamIdx NumElemsParam, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  AllocSizeAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , ParamIdx ElemSizeParam
              , ParamIdx NumElemsParam
             );
  AllocSizeAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , ParamIdx ElemSizeParam
             );

  AllocSizeAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  ParamIdx getElemSizeParam() const {
    return elemSizeParam;
  }

  ParamIdx getNumElemsParam() const {
    return numElemsParam;
  }



  static bool classof(const Attr *A) { return A->getKind() == attr::AllocSize; }
};

class AlwaysDestroyAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_always_destroy = 0,
    CXX11_clang_always_destroy = 1,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static AlwaysDestroyAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static AlwaysDestroyAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static AlwaysDestroyAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static AlwaysDestroyAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  AlwaysDestroyAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  AlwaysDestroyAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::AlwaysDestroy; }
};

class AlwaysInlineAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_always_inline = 0,
    CXX11_gnu_always_inline = 1,
    C2x_gnu_always_inline = 2,
    Keyword_forceinline = 3,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static AlwaysInlineAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static AlwaysInlineAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static AlwaysInlineAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax, AlwaysInlineAttr::Spelling S = static_cast<Spelling>(SpellingNotCalculated));
  static AlwaysInlineAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax, AlwaysInlineAttr::Spelling S = static_cast<Spelling>(SpellingNotCalculated));

  // Constructors
  AlwaysInlineAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  AlwaysInlineAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  Spelling getSemanticSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::AlwaysInline; }
};

class AnalyzerNoReturnAttr : public InheritableAttr {
public:
  // Factory methods
  static AnalyzerNoReturnAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static AnalyzerNoReturnAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static AnalyzerNoReturnAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static AnalyzerNoReturnAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  AnalyzerNoReturnAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  AnalyzerNoReturnAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::AnalyzerNoReturn; }
};

class AnnotateAttr : public InheritableParamAttr {
unsigned annotationLength;
char *annotation;

  unsigned args_Size;
  Expr * *args_;

public:
  enum Spelling {
    GNU_annotate = 0,
    CXX11_clang_annotate = 1,
    C2x_clang_annotate = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static AnnotateAttr *CreateImplicit(ASTContext &Ctx, llvm::StringRef Annotation, Expr * *Args, unsigned ArgsSize, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static AnnotateAttr *Create(ASTContext &Ctx, llvm::StringRef Annotation, Expr * *Args, unsigned ArgsSize, const AttributeCommonInfo &CommonInfo);
  static AnnotateAttr *CreateImplicit(ASTContext &Ctx, llvm::StringRef Annotation, Expr * *Args, unsigned ArgsSize, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static AnnotateAttr *Create(ASTContext &Ctx, llvm::StringRef Annotation, Expr * *Args, unsigned ArgsSize, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  AnnotateAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , llvm::StringRef Annotation
              , Expr * *Args, unsigned ArgsSize
             );
  AnnotateAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , llvm::StringRef Annotation
             );

  AnnotateAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  llvm::StringRef getAnnotation() const {
    return llvm::StringRef(annotation, annotationLength);
  }
  unsigned getAnnotationLength() const {
    return annotationLength;
  }
  void setAnnotation(ASTContext &C, llvm::StringRef S) {
    annotationLength = S.size();
    this->annotation = new (C, 1) char [annotationLength];
    if (!S.empty())
      std::memcpy(this->annotation, S.data(), annotationLength);
  }

  typedef Expr ** args_iterator;
  args_iterator args_begin() const { return args_; }
  args_iterator args_end() const { return args_ + args_Size; }
  unsigned args_size() const { return args_Size; }
  llvm::iterator_range<args_iterator> args() const { return llvm::make_range(args_begin(), args_end()); }



  static AnnotateAttr *Create(ASTContext &Ctx, llvm::StringRef Annotation, \
              const AttributeCommonInfo &CommonInfo) {
    return AnnotateAttr::Create(Ctx, Annotation, nullptr, 0, CommonInfo);
  }
  static AnnotateAttr *CreateImplicit(ASTContext &Ctx, llvm::StringRef Annotation, \
              const AttributeCommonInfo &CommonInfo = {SourceRange{}}) {
    return AnnotateAttr::CreateImplicit(Ctx, Annotation, nullptr, 0, CommonInfo);
  }
  

  static bool classof(const Attr *A) { return A->getKind() == attr::Annotate; }
};

class AnyX86InterruptAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_interrupt = 0,
    CXX11_gnu_interrupt = 1,
    C2x_gnu_interrupt = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static AnyX86InterruptAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static AnyX86InterruptAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static AnyX86InterruptAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static AnyX86InterruptAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  AnyX86InterruptAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  AnyX86InterruptAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::AnyX86Interrupt; }
};

class AnyX86NoCallerSavedRegistersAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_no_caller_saved_registers = 0,
    CXX11_gnu_no_caller_saved_registers = 1,
    C2x_gnu_no_caller_saved_registers = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static AnyX86NoCallerSavedRegistersAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static AnyX86NoCallerSavedRegistersAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static AnyX86NoCallerSavedRegistersAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static AnyX86NoCallerSavedRegistersAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  AnyX86NoCallerSavedRegistersAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  AnyX86NoCallerSavedRegistersAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::AnyX86NoCallerSavedRegisters; }
};

class AnyX86NoCfCheckAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_nocf_check = 0,
    CXX11_gnu_nocf_check = 1,
    C2x_gnu_nocf_check = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static AnyX86NoCfCheckAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static AnyX86NoCfCheckAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static AnyX86NoCfCheckAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static AnyX86NoCfCheckAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  AnyX86NoCfCheckAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  AnyX86NoCfCheckAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::AnyX86NoCfCheck; }
};

class ArcWeakrefUnavailableAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_objc_arc_weak_reference_unavailable = 0,
    CXX11_clang_objc_arc_weak_reference_unavailable = 1,
    C2x_clang_objc_arc_weak_reference_unavailable = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static ArcWeakrefUnavailableAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static ArcWeakrefUnavailableAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static ArcWeakrefUnavailableAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static ArcWeakrefUnavailableAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  ArcWeakrefUnavailableAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  ArcWeakrefUnavailableAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::ArcWeakrefUnavailable; }
};

class ArgumentWithTypeTagAttr : public InheritableAttr {
IdentifierInfo * argumentKind;

ParamIdx argumentIdx;

ParamIdx typeTagIdx;

bool isPointer;

public:
  enum Spelling {
    GNU_argument_with_type_tag = 0,
    CXX11_clang_argument_with_type_tag = 1,
    C2x_clang_argument_with_type_tag = 2,
    GNU_pointer_with_type_tag = 3,
    CXX11_clang_pointer_with_type_tag = 4,
    C2x_clang_pointer_with_type_tag = 5,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static ArgumentWithTypeTagAttr *CreateImplicit(ASTContext &Ctx, IdentifierInfo * ArgumentKind, ParamIdx ArgumentIdx, ParamIdx TypeTagIdx, bool IsPointer, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static ArgumentWithTypeTagAttr *Create(ASTContext &Ctx, IdentifierInfo * ArgumentKind, ParamIdx ArgumentIdx, ParamIdx TypeTagIdx, bool IsPointer, const AttributeCommonInfo &CommonInfo);
  static ArgumentWithTypeTagAttr *CreateImplicit(ASTContext &Ctx, IdentifierInfo * ArgumentKind, ParamIdx ArgumentIdx, ParamIdx TypeTagIdx, bool IsPointer, SourceRange Range, AttributeCommonInfo::Syntax Syntax, ArgumentWithTypeTagAttr::Spelling S = static_cast<Spelling>(SpellingNotCalculated));
  static ArgumentWithTypeTagAttr *Create(ASTContext &Ctx, IdentifierInfo * ArgumentKind, ParamIdx ArgumentIdx, ParamIdx TypeTagIdx, bool IsPointer, SourceRange Range, AttributeCommonInfo::Syntax Syntax, ArgumentWithTypeTagAttr::Spelling S = static_cast<Spelling>(SpellingNotCalculated));
  static ArgumentWithTypeTagAttr *CreateImplicit(ASTContext &Ctx, IdentifierInfo * ArgumentKind, ParamIdx ArgumentIdx, ParamIdx TypeTagIdx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static ArgumentWithTypeTagAttr *Create(ASTContext &Ctx, IdentifierInfo * ArgumentKind, ParamIdx ArgumentIdx, ParamIdx TypeTagIdx, const AttributeCommonInfo &CommonInfo);
  static ArgumentWithTypeTagAttr *CreateImplicit(ASTContext &Ctx, IdentifierInfo * ArgumentKind, ParamIdx ArgumentIdx, ParamIdx TypeTagIdx, SourceRange Range, AttributeCommonInfo::Syntax Syntax, ArgumentWithTypeTagAttr::Spelling S = static_cast<Spelling>(SpellingNotCalculated));
  static ArgumentWithTypeTagAttr *Create(ASTContext &Ctx, IdentifierInfo * ArgumentKind, ParamIdx ArgumentIdx, ParamIdx TypeTagIdx, SourceRange Range, AttributeCommonInfo::Syntax Syntax, ArgumentWithTypeTagAttr::Spelling S = static_cast<Spelling>(SpellingNotCalculated));

  // Constructors
  ArgumentWithTypeTagAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , IdentifierInfo * ArgumentKind
              , ParamIdx ArgumentIdx
              , ParamIdx TypeTagIdx
              , bool IsPointer
             );
  ArgumentWithTypeTagAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , IdentifierInfo * ArgumentKind
              , ParamIdx ArgumentIdx
              , ParamIdx TypeTagIdx
             );

  ArgumentWithTypeTagAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  Spelling getSemanticSpelling() const;
  IdentifierInfo * getArgumentKind() const {
    return argumentKind;
  }

  ParamIdx getArgumentIdx() const {
    return argumentIdx;
  }

  ParamIdx getTypeTagIdx() const {
    return typeTagIdx;
  }

  bool getIsPointer() const {
    return isPointer;
  }



  static bool classof(const Attr *A) { return A->getKind() == attr::ArgumentWithTypeTag; }
};

class ArmBuiltinAliasAttr : public InheritableAttr {
IdentifierInfo * builtinName;

public:
  enum Spelling {
    GNU_clang_arm_builtin_alias = 0,
    CXX11_clang_clang_arm_builtin_alias = 1,
    C2x_clang_clang_arm_builtin_alias = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static ArmBuiltinAliasAttr *CreateImplicit(ASTContext &Ctx, IdentifierInfo * BuiltinName, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static ArmBuiltinAliasAttr *Create(ASTContext &Ctx, IdentifierInfo * BuiltinName, const AttributeCommonInfo &CommonInfo);
  static ArmBuiltinAliasAttr *CreateImplicit(ASTContext &Ctx, IdentifierInfo * BuiltinName, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static ArmBuiltinAliasAttr *Create(ASTContext &Ctx, IdentifierInfo * BuiltinName, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  ArmBuiltinAliasAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , IdentifierInfo * BuiltinName
             );

  ArmBuiltinAliasAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  IdentifierInfo * getBuiltinName() const {
    return builtinName;
  }



  static bool classof(const Attr *A) { return A->getKind() == attr::ArmBuiltinAlias; }
};

class ArmMveStrictPolymorphismAttr : public TypeAttr {
public:
  enum Spelling {
    GNU_clang_arm_mve_strict_polymorphism = 0,
    CXX11_clang_clang_arm_mve_strict_polymorphism = 1,
    C2x_clang_clang_arm_mve_strict_polymorphism = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static ArmMveStrictPolymorphismAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static ArmMveStrictPolymorphismAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static ArmMveStrictPolymorphismAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static ArmMveStrictPolymorphismAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  ArmMveStrictPolymorphismAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  ArmMveStrictPolymorphismAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::ArmMveStrictPolymorphism; }
};

class ArtificialAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_artificial = 0,
    CXX11_gnu_artificial = 1,
    C2x_gnu_artificial = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static ArtificialAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static ArtificialAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static ArtificialAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static ArtificialAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  ArtificialAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  ArtificialAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::Artificial; }
};

class AsmLabelAttr : public InheritableAttr {
unsigned labelLength;
char *label;

bool isLiteralLabel;

public:
  enum Spelling {
    Keyword_asm = 0,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static AsmLabelAttr *CreateImplicit(ASTContext &Ctx, llvm::StringRef Label, bool IsLiteralLabel, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static AsmLabelAttr *Create(ASTContext &Ctx, llvm::StringRef Label, bool IsLiteralLabel, const AttributeCommonInfo &CommonInfo);
  static AsmLabelAttr *CreateImplicit(ASTContext &Ctx, llvm::StringRef Label, bool IsLiteralLabel, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static AsmLabelAttr *Create(ASTContext &Ctx, llvm::StringRef Label, bool IsLiteralLabel, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static AsmLabelAttr *CreateImplicit(ASTContext &Ctx, llvm::StringRef Label, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static AsmLabelAttr *Create(ASTContext &Ctx, llvm::StringRef Label, const AttributeCommonInfo &CommonInfo);
  static AsmLabelAttr *CreateImplicit(ASTContext &Ctx, llvm::StringRef Label, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static AsmLabelAttr *Create(ASTContext &Ctx, llvm::StringRef Label, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  AsmLabelAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , llvm::StringRef Label
              , bool IsLiteralLabel
             );
  AsmLabelAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , llvm::StringRef Label
             );

  AsmLabelAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  llvm::StringRef getLabel() const {
    return llvm::StringRef(label, labelLength);
  }
  unsigned getLabelLength() const {
    return labelLength;
  }
  void setLabel(ASTContext &C, llvm::StringRef S) {
    labelLength = S.size();
    this->label = new (C, 1) char [labelLength];
    if (!S.empty())
      std::memcpy(this->label, S.data(), labelLength);
  }

  bool getIsLiteralLabel() const {
    return isLiteralLabel;
  }


bool isEquivalent(AsmLabelAttr *Other) const {
  return getLabel() == Other->getLabel() && getIsLiteralLabel() == Other->getIsLiteralLabel();
}


  static bool classof(const Attr *A) { return A->getKind() == attr::AsmLabel; }
};

class AssertCapabilityAttr : public InheritableAttr {
  unsigned args_Size;
  Expr * *args_;

public:
  enum Spelling {
    GNU_assert_capability = 0,
    CXX11_clang_assert_capability = 1,
    GNU_assert_shared_capability = 2,
    CXX11_clang_assert_shared_capability = 3,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static AssertCapabilityAttr *CreateImplicit(ASTContext &Ctx, Expr * *Args, unsigned ArgsSize, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static AssertCapabilityAttr *Create(ASTContext &Ctx, Expr * *Args, unsigned ArgsSize, const AttributeCommonInfo &CommonInfo);
  static AssertCapabilityAttr *CreateImplicit(ASTContext &Ctx, Expr * *Args, unsigned ArgsSize, SourceRange Range, AttributeCommonInfo::Syntax Syntax, AssertCapabilityAttr::Spelling S = static_cast<Spelling>(SpellingNotCalculated));
  static AssertCapabilityAttr *Create(ASTContext &Ctx, Expr * *Args, unsigned ArgsSize, SourceRange Range, AttributeCommonInfo::Syntax Syntax, AssertCapabilityAttr::Spelling S = static_cast<Spelling>(SpellingNotCalculated));

  // Constructors
  AssertCapabilityAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , Expr * *Args, unsigned ArgsSize
             );
  AssertCapabilityAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  AssertCapabilityAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  Spelling getSemanticSpelling() const;
  bool isShared() const { return getAttributeSpellingListIndex() == 2 ||
    getAttributeSpellingListIndex() == 3; }
  typedef Expr ** args_iterator;
  args_iterator args_begin() const { return args_; }
  args_iterator args_end() const { return args_ + args_Size; }
  unsigned args_size() const { return args_Size; }
  llvm::iterator_range<args_iterator> args() const { return llvm::make_range(args_begin(), args_end()); }




  static bool classof(const Attr *A) { return A->getKind() == attr::AssertCapability; }
};

class AssertExclusiveLockAttr : public InheritableAttr {
  unsigned args_Size;
  Expr * *args_;

public:
  // Factory methods
  static AssertExclusiveLockAttr *CreateImplicit(ASTContext &Ctx, Expr * *Args, unsigned ArgsSize, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static AssertExclusiveLockAttr *Create(ASTContext &Ctx, Expr * *Args, unsigned ArgsSize, const AttributeCommonInfo &CommonInfo);
  static AssertExclusiveLockAttr *CreateImplicit(ASTContext &Ctx, Expr * *Args, unsigned ArgsSize, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static AssertExclusiveLockAttr *Create(ASTContext &Ctx, Expr * *Args, unsigned ArgsSize, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  AssertExclusiveLockAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , Expr * *Args, unsigned ArgsSize
             );
  AssertExclusiveLockAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  AssertExclusiveLockAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  typedef Expr ** args_iterator;
  args_iterator args_begin() const { return args_; }
  args_iterator args_end() const { return args_ + args_Size; }
  unsigned args_size() const { return args_Size; }
  llvm::iterator_range<args_iterator> args() const { return llvm::make_range(args_begin(), args_end()); }




  static bool classof(const Attr *A) { return A->getKind() == attr::AssertExclusiveLock; }
};

class AssertSharedLockAttr : public InheritableAttr {
  unsigned args_Size;
  Expr * *args_;

public:
  // Factory methods
  static AssertSharedLockAttr *CreateImplicit(ASTContext &Ctx, Expr * *Args, unsigned ArgsSize, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static AssertSharedLockAttr *Create(ASTContext &Ctx, Expr * *Args, unsigned ArgsSize, const AttributeCommonInfo &CommonInfo);
  static AssertSharedLockAttr *CreateImplicit(ASTContext &Ctx, Expr * *Args, unsigned ArgsSize, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static AssertSharedLockAttr *Create(ASTContext &Ctx, Expr * *Args, unsigned ArgsSize, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  AssertSharedLockAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , Expr * *Args, unsigned ArgsSize
             );
  AssertSharedLockAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  AssertSharedLockAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  typedef Expr ** args_iterator;
  args_iterator args_begin() const { return args_; }
  args_iterator args_end() const { return args_ + args_Size; }
  unsigned args_size() const { return args_Size; }
  llvm::iterator_range<args_iterator> args() const { return llvm::make_range(args_begin(), args_end()); }




  static bool classof(const Attr *A) { return A->getKind() == attr::AssertSharedLock; }
};

class AssumeAlignedAttr : public InheritableAttr {
Expr * alignment;

Expr * offset;

public:
  enum Spelling {
    GNU_assume_aligned = 0,
    CXX11_gnu_assume_aligned = 1,
    C2x_gnu_assume_aligned = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static AssumeAlignedAttr *CreateImplicit(ASTContext &Ctx, Expr * Alignment, Expr * Offset, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static AssumeAlignedAttr *Create(ASTContext &Ctx, Expr * Alignment, Expr * Offset, const AttributeCommonInfo &CommonInfo);
  static AssumeAlignedAttr *CreateImplicit(ASTContext &Ctx, Expr * Alignment, Expr * Offset, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static AssumeAlignedAttr *Create(ASTContext &Ctx, Expr * Alignment, Expr * Offset, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  AssumeAlignedAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , Expr * Alignment
              , Expr * Offset
             );
  AssumeAlignedAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , Expr * Alignment
             );

  AssumeAlignedAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  Expr * getAlignment() const {
    return alignment;
  }

  Expr * getOffset() const {
    return offset;
  }



  static bool classof(const Attr *A) { return A->getKind() == attr::AssumeAligned; }
};

class AssumptionAttr : public InheritableAttr {
unsigned assumptionLength;
char *assumption;

public:
  enum Spelling {
    GNU_assume = 0,
    CXX11_clang_assume = 1,
    C2x_clang_assume = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static AssumptionAttr *CreateImplicit(ASTContext &Ctx, llvm::StringRef Assumption, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static AssumptionAttr *Create(ASTContext &Ctx, llvm::StringRef Assumption, const AttributeCommonInfo &CommonInfo);
  static AssumptionAttr *CreateImplicit(ASTContext &Ctx, llvm::StringRef Assumption, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static AssumptionAttr *Create(ASTContext &Ctx, llvm::StringRef Assumption, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  AssumptionAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , llvm::StringRef Assumption
             );

  AssumptionAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  llvm::StringRef getAssumption() const {
    return llvm::StringRef(assumption, assumptionLength);
  }
  unsigned getAssumptionLength() const {
    return assumptionLength;
  }
  void setAssumption(ASTContext &C, llvm::StringRef S) {
    assumptionLength = S.size();
    this->assumption = new (C, 1) char [assumptionLength];
    if (!S.empty())
      std::memcpy(this->assumption, S.data(), assumptionLength);
  }



  static bool classof(const Attr *A) { return A->getKind() == attr::Assumption; }
};

class AvailabilityAttr : public InheritableAttr {
IdentifierInfo * platform;

VersionTuple introduced;


VersionTuple deprecated;


VersionTuple obsoleted;


bool unavailable;

unsigned messageLength;
char *message;

bool strict;

unsigned replacementLength;
char *replacement;

int priority;

public:
  enum Spelling {
    GNU_availability = 0,
    CXX11_clang_availability = 1,
    C2x_clang_availability = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static AvailabilityAttr *CreateImplicit(ASTContext &Ctx, IdentifierInfo * Platform, VersionTuple Introduced, VersionTuple Deprecated, VersionTuple Obsoleted, bool Unavailable, llvm::StringRef Message, bool Strict, llvm::StringRef Replacement, int Priority, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static AvailabilityAttr *Create(ASTContext &Ctx, IdentifierInfo * Platform, VersionTuple Introduced, VersionTuple Deprecated, VersionTuple Obsoleted, bool Unavailable, llvm::StringRef Message, bool Strict, llvm::StringRef Replacement, int Priority, const AttributeCommonInfo &CommonInfo);
  static AvailabilityAttr *CreateImplicit(ASTContext &Ctx, IdentifierInfo * Platform, VersionTuple Introduced, VersionTuple Deprecated, VersionTuple Obsoleted, bool Unavailable, llvm::StringRef Message, bool Strict, llvm::StringRef Replacement, int Priority, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static AvailabilityAttr *Create(ASTContext &Ctx, IdentifierInfo * Platform, VersionTuple Introduced, VersionTuple Deprecated, VersionTuple Obsoleted, bool Unavailable, llvm::StringRef Message, bool Strict, llvm::StringRef Replacement, int Priority, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  AvailabilityAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , IdentifierInfo * Platform
              , VersionTuple Introduced
              , VersionTuple Deprecated
              , VersionTuple Obsoleted
              , bool Unavailable
              , llvm::StringRef Message
              , bool Strict
              , llvm::StringRef Replacement
              , int Priority
             );

  AvailabilityAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  IdentifierInfo * getPlatform() const {
    return platform;
  }

  VersionTuple getIntroduced() const {
    return introduced;
  }
  void setIntroduced(ASTContext &C, VersionTuple V) {
    introduced = V;
  }

  VersionTuple getDeprecated() const {
    return deprecated;
  }
  void setDeprecated(ASTContext &C, VersionTuple V) {
    deprecated = V;
  }

  VersionTuple getObsoleted() const {
    return obsoleted;
  }
  void setObsoleted(ASTContext &C, VersionTuple V) {
    obsoleted = V;
  }

  bool getUnavailable() const {
    return unavailable;
  }

  llvm::StringRef getMessage() const {
    return llvm::StringRef(message, messageLength);
  }
  unsigned getMessageLength() const {
    return messageLength;
  }
  void setMessage(ASTContext &C, llvm::StringRef S) {
    messageLength = S.size();
    this->message = new (C, 1) char [messageLength];
    if (!S.empty())
      std::memcpy(this->message, S.data(), messageLength);
  }

  bool getStrict() const {
    return strict;
  }

  llvm::StringRef getReplacement() const {
    return llvm::StringRef(replacement, replacementLength);
  }
  unsigned getReplacementLength() const {
    return replacementLength;
  }
  void setReplacement(ASTContext &C, llvm::StringRef S) {
    replacementLength = S.size();
    this->replacement = new (C, 1) char [replacementLength];
    if (!S.empty())
      std::memcpy(this->replacement, S.data(), replacementLength);
  }

  int getPriority() const {
    return priority;
  }

static llvm::StringRef getPrettyPlatformName(llvm::StringRef Platform) {
    return llvm::StringSwitch<llvm::StringRef>(Platform)
             .Case("android", "Android")
             .Case("fuchsia", "Fuchsia")
             .Case("ios", "iOS")
             .Case("macos", "macOS")
             .Case("tvos", "tvOS")
             .Case("watchos", "watchOS")
             .Case("ios_app_extension", "iOS (App Extension)")
             .Case("macos_app_extension", "macOS (App Extension)")
             .Case("tvos_app_extension", "tvOS (App Extension)")
             .Case("watchos_app_extension", "watchOS (App Extension)")
             .Case("maccatalyst", "macCatalyst")
             .Case("maccatalyst_app_extension", "macCatalyst (App Extension)")
             .Case("swift", "Swift")
             .Default(llvm::StringRef());
}
static llvm::StringRef getPlatformNameSourceSpelling(llvm::StringRef Platform) {
    return llvm::StringSwitch<llvm::StringRef>(Platform)
             .Case("ios", "iOS")
             .Case("macos", "macOS")
             .Case("tvos", "tvOS")
             .Case("watchos", "watchOS")
             .Case("ios_app_extension", "iOSApplicationExtension")
             .Case("macos_app_extension", "macOSApplicationExtension")
             .Case("tvos_app_extension", "tvOSApplicationExtension")
             .Case("watchos_app_extension", "watchOSApplicationExtension")
             .Case("maccatalyst", "macCatalyst")
             .Case("maccatalyst_app_extension", "macCatalystApplicationExtension")
             .Case("zos", "z/OS")
             .Default(Platform);
}
static llvm::StringRef canonicalizePlatformName(llvm::StringRef Platform) {
    return llvm::StringSwitch<llvm::StringRef>(Platform)
             .Case("iOS", "ios")
             .Case("macOS", "macos")
             .Case("tvOS", "tvos")
             .Case("watchOS", "watchos")
             .Case("iOSApplicationExtension", "ios_app_extension")
             .Case("macOSApplicationExtension", "macos_app_extension")
             .Case("tvOSApplicationExtension", "tvos_app_extension")
             .Case("watchOSApplicationExtension", "watchos_app_extension")
             .Case("macCatalyst", "maccatalyst")
             .Case("macCatalystApplicationExtension", "maccatalyst_app_extension")
             .Default(Platform);
} 

  static bool classof(const Attr *A) { return A->getKind() == attr::Availability; }
};

class BPFPreserveAccessIndexAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_preserve_access_index = 0,
    CXX11_clang_preserve_access_index = 1,
    C2x_clang_preserve_access_index = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static BPFPreserveAccessIndexAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static BPFPreserveAccessIndexAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static BPFPreserveAccessIndexAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static BPFPreserveAccessIndexAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  BPFPreserveAccessIndexAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  BPFPreserveAccessIndexAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::BPFPreserveAccessIndex; }
};

class BTFDeclTagAttr : public InheritableAttr {
unsigned bTFDeclTagLength;
char *bTFDeclTag;

public:
  enum Spelling {
    GNU_btf_decl_tag = 0,
    CXX11_clang_btf_decl_tag = 1,
    C2x_clang_btf_decl_tag = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static BTFDeclTagAttr *CreateImplicit(ASTContext &Ctx, llvm::StringRef BTFDeclTag, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static BTFDeclTagAttr *Create(ASTContext &Ctx, llvm::StringRef BTFDeclTag, const AttributeCommonInfo &CommonInfo);
  static BTFDeclTagAttr *CreateImplicit(ASTContext &Ctx, llvm::StringRef BTFDeclTag, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static BTFDeclTagAttr *Create(ASTContext &Ctx, llvm::StringRef BTFDeclTag, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  BTFDeclTagAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , llvm::StringRef BTFDeclTag
             );

  BTFDeclTagAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  llvm::StringRef getBTFDeclTag() const {
    return llvm::StringRef(bTFDeclTag, bTFDeclTagLength);
  }
  unsigned getBTFDeclTagLength() const {
    return bTFDeclTagLength;
  }
  void setBTFDeclTag(ASTContext &C, llvm::StringRef S) {
    bTFDeclTagLength = S.size();
    this->bTFDeclTag = new (C, 1) char [bTFDeclTagLength];
    if (!S.empty())
      std::memcpy(this->bTFDeclTag, S.data(), bTFDeclTagLength);
  }



  static bool classof(const Attr *A) { return A->getKind() == attr::BTFDeclTag; }
};

class BTFTypeTagAttr : public TypeAttr {
unsigned bTFTypeTagLength;
char *bTFTypeTag;

public:
  enum Spelling {
    GNU_btf_type_tag = 0,
    CXX11_clang_btf_type_tag = 1,
    C2x_clang_btf_type_tag = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static BTFTypeTagAttr *CreateImplicit(ASTContext &Ctx, llvm::StringRef BTFTypeTag, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static BTFTypeTagAttr *Create(ASTContext &Ctx, llvm::StringRef BTFTypeTag, const AttributeCommonInfo &CommonInfo);
  static BTFTypeTagAttr *CreateImplicit(ASTContext &Ctx, llvm::StringRef BTFTypeTag, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static BTFTypeTagAttr *Create(ASTContext &Ctx, llvm::StringRef BTFTypeTag, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  BTFTypeTagAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , llvm::StringRef BTFTypeTag
             );

  BTFTypeTagAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  llvm::StringRef getBTFTypeTag() const {
    return llvm::StringRef(bTFTypeTag, bTFTypeTagLength);
  }
  unsigned getBTFTypeTagLength() const {
    return bTFTypeTagLength;
  }
  void setBTFTypeTag(ASTContext &C, llvm::StringRef S) {
    bTFTypeTagLength = S.size();
    this->bTFTypeTag = new (C, 1) char [bTFTypeTagLength];
    if (!S.empty())
      std::memcpy(this->bTFTypeTag, S.data(), bTFTypeTagLength);
  }



  static bool classof(const Attr *A) { return A->getKind() == attr::BTFTypeTag; }
};

class BlocksAttr : public InheritableAttr {
public:
  enum BlockType {
    ByRef
  };
private:
  BlockType type;

public:
  enum Spelling {
    GNU_blocks = 0,
    CXX11_clang_blocks = 1,
    C2x_clang_blocks = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static BlocksAttr *CreateImplicit(ASTContext &Ctx, BlockType Type, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static BlocksAttr *Create(ASTContext &Ctx, BlockType Type, const AttributeCommonInfo &CommonInfo);
  static BlocksAttr *CreateImplicit(ASTContext &Ctx, BlockType Type, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static BlocksAttr *Create(ASTContext &Ctx, BlockType Type, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  BlocksAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , BlockType Type
             );

  BlocksAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  BlockType getType() const {
    return type;
  }

  static bool ConvertStrToBlockType(StringRef Val, BlockType &Out);
  static const char *ConvertBlockTypeToStr(BlockType Val);


  static bool classof(const Attr *A) { return A->getKind() == attr::Blocks; }
};

class BuiltinAttr : public InheritableAttr {
unsigned iD;

public:
  // Factory methods
  static BuiltinAttr *CreateImplicit(ASTContext &Ctx, unsigned ID, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static BuiltinAttr *Create(ASTContext &Ctx, unsigned ID, const AttributeCommonInfo &CommonInfo);
  static BuiltinAttr *CreateImplicit(ASTContext &Ctx, unsigned ID, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static BuiltinAttr *Create(ASTContext &Ctx, unsigned ID, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  BuiltinAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , unsigned ID
             );

  BuiltinAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  unsigned getID() const {
    return iD;
  }



  static bool classof(const Attr *A) { return A->getKind() == attr::Builtin; }
};

class BuiltinAliasAttr : public Attr {
IdentifierInfo * builtinName;

public:
  enum Spelling {
    CXX11_clang_builtin_alias = 0,
    C2x_clang_builtin_alias = 1,
    GNU_clang_builtin_alias = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static BuiltinAliasAttr *CreateImplicit(ASTContext &Ctx, IdentifierInfo * BuiltinName, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static BuiltinAliasAttr *Create(ASTContext &Ctx, IdentifierInfo * BuiltinName, const AttributeCommonInfo &CommonInfo);
  static BuiltinAliasAttr *CreateImplicit(ASTContext &Ctx, IdentifierInfo * BuiltinName, SourceRange Range, AttributeCommonInfo::Syntax Syntax, BuiltinAliasAttr::Spelling S = static_cast<Spelling>(SpellingNotCalculated));
  static BuiltinAliasAttr *Create(ASTContext &Ctx, IdentifierInfo * BuiltinName, SourceRange Range, AttributeCommonInfo::Syntax Syntax, BuiltinAliasAttr::Spelling S = static_cast<Spelling>(SpellingNotCalculated));

  // Constructors
  BuiltinAliasAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , IdentifierInfo * BuiltinName
             );

  BuiltinAliasAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  Spelling getSemanticSpelling() const;
  IdentifierInfo * getBuiltinName() const {
    return builtinName;
  }



  static bool classof(const Attr *A) { return A->getKind() == attr::BuiltinAlias; }
};

class C11NoReturnAttr : public InheritableAttr {
public:
  // Factory methods
  static C11NoReturnAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static C11NoReturnAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static C11NoReturnAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static C11NoReturnAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  C11NoReturnAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  C11NoReturnAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::C11NoReturn; }
};

class CDeclAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_cdecl = 0,
    CXX11_gnu_cdecl = 1,
    C2x_gnu_cdecl = 2,
    Keyword_cdecl = 3,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static CDeclAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static CDeclAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static CDeclAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static CDeclAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  CDeclAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  CDeclAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::CDecl; }
};

class CFAuditedTransferAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_cf_audited_transfer = 0,
    CXX11_clang_cf_audited_transfer = 1,
    C2x_clang_cf_audited_transfer = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static CFAuditedTransferAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static CFAuditedTransferAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static CFAuditedTransferAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static CFAuditedTransferAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  CFAuditedTransferAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  CFAuditedTransferAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::CFAuditedTransfer; }
};

class CFConsumedAttr : public InheritableParamAttr {
public:
  enum Spelling {
    GNU_cf_consumed = 0,
    CXX11_clang_cf_consumed = 1,
    C2x_clang_cf_consumed = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static CFConsumedAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static CFConsumedAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static CFConsumedAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static CFConsumedAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  CFConsumedAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  CFConsumedAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::CFConsumed; }
};

class CFGuardAttr : public InheritableAttr {
public:
  enum GuardArg {
    nocf
  };
private:
  GuardArg guard;

public:
  // Factory methods
  static CFGuardAttr *CreateImplicit(ASTContext &Ctx, GuardArg Guard, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static CFGuardAttr *Create(ASTContext &Ctx, GuardArg Guard, const AttributeCommonInfo &CommonInfo);
  static CFGuardAttr *CreateImplicit(ASTContext &Ctx, GuardArg Guard, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static CFGuardAttr *Create(ASTContext &Ctx, GuardArg Guard, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  CFGuardAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , GuardArg Guard
             );

  CFGuardAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  GuardArg getGuard() const {
    return guard;
  }

  static bool ConvertStrToGuardArg(StringRef Val, GuardArg &Out);
  static const char *ConvertGuardArgToStr(GuardArg Val);


  static bool classof(const Attr *A) { return A->getKind() == attr::CFGuard; }
};

class CFICanonicalJumpTableAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_cfi_canonical_jump_table = 0,
    CXX11_clang_cfi_canonical_jump_table = 1,
    C2x_clang_cfi_canonical_jump_table = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static CFICanonicalJumpTableAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static CFICanonicalJumpTableAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static CFICanonicalJumpTableAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static CFICanonicalJumpTableAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  CFICanonicalJumpTableAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  CFICanonicalJumpTableAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::CFICanonicalJumpTable; }
};

class CFReturnsNotRetainedAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_cf_returns_not_retained = 0,
    CXX11_clang_cf_returns_not_retained = 1,
    C2x_clang_cf_returns_not_retained = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static CFReturnsNotRetainedAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static CFReturnsNotRetainedAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static CFReturnsNotRetainedAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static CFReturnsNotRetainedAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  CFReturnsNotRetainedAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  CFReturnsNotRetainedAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::CFReturnsNotRetained; }
};

class CFReturnsRetainedAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_cf_returns_retained = 0,
    CXX11_clang_cf_returns_retained = 1,
    C2x_clang_cf_returns_retained = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static CFReturnsRetainedAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static CFReturnsRetainedAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static CFReturnsRetainedAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static CFReturnsRetainedAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  CFReturnsRetainedAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  CFReturnsRetainedAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::CFReturnsRetained; }
};

class CFUnknownTransferAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_cf_unknown_transfer = 0,
    CXX11_clang_cf_unknown_transfer = 1,
    C2x_clang_cf_unknown_transfer = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static CFUnknownTransferAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static CFUnknownTransferAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static CFUnknownTransferAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static CFUnknownTransferAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  CFUnknownTransferAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  CFUnknownTransferAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::CFUnknownTransfer; }
};

class CPUDispatchAttr : public InheritableAttr {
  unsigned cpus_Size;
  IdentifierInfo * *cpus_;

public:
  enum Spelling {
    GNU_cpu_dispatch = 0,
    CXX11_clang_cpu_dispatch = 1,
    C2x_clang_cpu_dispatch = 2,
    Declspec_cpu_dispatch = 3,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static CPUDispatchAttr *CreateImplicit(ASTContext &Ctx, IdentifierInfo * *Cpus, unsigned CpusSize, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static CPUDispatchAttr *Create(ASTContext &Ctx, IdentifierInfo * *Cpus, unsigned CpusSize, const AttributeCommonInfo &CommonInfo);
  static CPUDispatchAttr *CreateImplicit(ASTContext &Ctx, IdentifierInfo * *Cpus, unsigned CpusSize, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static CPUDispatchAttr *Create(ASTContext &Ctx, IdentifierInfo * *Cpus, unsigned CpusSize, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  CPUDispatchAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , IdentifierInfo * *Cpus, unsigned CpusSize
             );
  CPUDispatchAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  CPUDispatchAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  typedef IdentifierInfo ** cpus_iterator;
  cpus_iterator cpus_begin() const { return cpus_; }
  cpus_iterator cpus_end() const { return cpus_ + cpus_Size; }
  unsigned cpus_size() const { return cpus_Size; }
  llvm::iterator_range<cpus_iterator> cpus() const { return llvm::make_range(cpus_begin(), cpus_end()); }




  static bool classof(const Attr *A) { return A->getKind() == attr::CPUDispatch; }
};

class CPUSpecificAttr : public InheritableAttr {
  unsigned cpus_Size;
  IdentifierInfo * *cpus_;

public:
  enum Spelling {
    GNU_cpu_specific = 0,
    CXX11_clang_cpu_specific = 1,
    C2x_clang_cpu_specific = 2,
    Declspec_cpu_specific = 3,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static CPUSpecificAttr *CreateImplicit(ASTContext &Ctx, IdentifierInfo * *Cpus, unsigned CpusSize, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static CPUSpecificAttr *Create(ASTContext &Ctx, IdentifierInfo * *Cpus, unsigned CpusSize, const AttributeCommonInfo &CommonInfo);
  static CPUSpecificAttr *CreateImplicit(ASTContext &Ctx, IdentifierInfo * *Cpus, unsigned CpusSize, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static CPUSpecificAttr *Create(ASTContext &Ctx, IdentifierInfo * *Cpus, unsigned CpusSize, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  CPUSpecificAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , IdentifierInfo * *Cpus, unsigned CpusSize
             );
  CPUSpecificAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  CPUSpecificAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  typedef IdentifierInfo ** cpus_iterator;
  cpus_iterator cpus_begin() const { return cpus_; }
  cpus_iterator cpus_end() const { return cpus_ + cpus_Size; }
  unsigned cpus_size() const { return cpus_Size; }
  llvm::iterator_range<cpus_iterator> cpus() const { return llvm::make_range(cpus_begin(), cpus_end()); }



    IdentifierInfo *getCPUName(unsigned Index) const {
      return *(cpus_begin() + Index);
    }
  

  static bool classof(const Attr *A) { return A->getKind() == attr::CPUSpecific; }
};

class CUDAConstantAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_constant = 0,
    Declspec_constant = 1,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static CUDAConstantAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static CUDAConstantAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static CUDAConstantAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static CUDAConstantAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  CUDAConstantAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  CUDAConstantAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::CUDAConstant; }
};

class CUDADeviceAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_device = 0,
    Declspec_device = 1,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static CUDADeviceAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static CUDADeviceAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static CUDADeviceAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static CUDADeviceAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  CUDADeviceAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  CUDADeviceAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::CUDADevice; }
};

class CUDADeviceBuiltinSurfaceTypeAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_device_builtin_surface_type = 0,
    Declspec_device_builtin_surface_type = 1,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static CUDADeviceBuiltinSurfaceTypeAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static CUDADeviceBuiltinSurfaceTypeAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static CUDADeviceBuiltinSurfaceTypeAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static CUDADeviceBuiltinSurfaceTypeAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  CUDADeviceBuiltinSurfaceTypeAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  CUDADeviceBuiltinSurfaceTypeAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::CUDADeviceBuiltinSurfaceType; }
};

class CUDADeviceBuiltinTextureTypeAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_device_builtin_texture_type = 0,
    Declspec_device_builtin_texture_type = 1,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static CUDADeviceBuiltinTextureTypeAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static CUDADeviceBuiltinTextureTypeAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static CUDADeviceBuiltinTextureTypeAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static CUDADeviceBuiltinTextureTypeAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  CUDADeviceBuiltinTextureTypeAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  CUDADeviceBuiltinTextureTypeAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::CUDADeviceBuiltinTextureType; }
};

class CUDAGlobalAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_global = 0,
    Declspec_global = 1,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static CUDAGlobalAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static CUDAGlobalAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static CUDAGlobalAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static CUDAGlobalAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  CUDAGlobalAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  CUDAGlobalAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::CUDAGlobal; }
};

class CUDAHostAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_host = 0,
    Declspec_host = 1,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static CUDAHostAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static CUDAHostAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static CUDAHostAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static CUDAHostAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  CUDAHostAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  CUDAHostAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::CUDAHost; }
};

class CUDAInvalidTargetAttr : public InheritableAttr {
public:
  // Factory methods
  static CUDAInvalidTargetAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static CUDAInvalidTargetAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static CUDAInvalidTargetAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static CUDAInvalidTargetAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  CUDAInvalidTargetAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  CUDAInvalidTargetAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::CUDAInvalidTarget; }
};

class CUDALaunchBoundsAttr : public InheritableAttr {
Expr * maxThreads;

Expr * minBlocks;

public:
  enum Spelling {
    GNU_launch_bounds = 0,
    Declspec_launch_bounds = 1,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static CUDALaunchBoundsAttr *CreateImplicit(ASTContext &Ctx, Expr * MaxThreads, Expr * MinBlocks, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static CUDALaunchBoundsAttr *Create(ASTContext &Ctx, Expr * MaxThreads, Expr * MinBlocks, const AttributeCommonInfo &CommonInfo);
  static CUDALaunchBoundsAttr *CreateImplicit(ASTContext &Ctx, Expr * MaxThreads, Expr * MinBlocks, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static CUDALaunchBoundsAttr *Create(ASTContext &Ctx, Expr * MaxThreads, Expr * MinBlocks, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  CUDALaunchBoundsAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , Expr * MaxThreads
              , Expr * MinBlocks
             );
  CUDALaunchBoundsAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , Expr * MaxThreads
             );

  CUDALaunchBoundsAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  Expr * getMaxThreads() const {
    return maxThreads;
  }

  Expr * getMinBlocks() const {
    return minBlocks;
  }



  static bool classof(const Attr *A) { return A->getKind() == attr::CUDALaunchBounds; }
};

class CUDASharedAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_shared = 0,
    Declspec_shared = 1,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static CUDASharedAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static CUDASharedAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static CUDASharedAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static CUDASharedAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  CUDASharedAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  CUDASharedAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::CUDAShared; }
};

class CXX11NoReturnAttr : public InheritableAttr {
public:
  // Factory methods
  static CXX11NoReturnAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static CXX11NoReturnAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static CXX11NoReturnAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static CXX11NoReturnAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  CXX11NoReturnAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  CXX11NoReturnAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::CXX11NoReturn; }
};

class CallableWhenAttr : public InheritableAttr {
public:
  enum ConsumedState {
    Unknown,
    Consumed,
    Unconsumed
  };
private:
  unsigned callableStates_Size;
  ConsumedState *callableStates_;

public:
  enum Spelling {
    GNU_callable_when = 0,
    CXX11_clang_callable_when = 1,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static CallableWhenAttr *CreateImplicit(ASTContext &Ctx, ConsumedState *CallableStates, unsigned CallableStatesSize, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static CallableWhenAttr *Create(ASTContext &Ctx, ConsumedState *CallableStates, unsigned CallableStatesSize, const AttributeCommonInfo &CommonInfo);
  static CallableWhenAttr *CreateImplicit(ASTContext &Ctx, ConsumedState *CallableStates, unsigned CallableStatesSize, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static CallableWhenAttr *Create(ASTContext &Ctx, ConsumedState *CallableStates, unsigned CallableStatesSize, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  CallableWhenAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , ConsumedState *CallableStates, unsigned CallableStatesSize
             );
  CallableWhenAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  CallableWhenAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  typedef ConsumedState* callableStates_iterator;
  callableStates_iterator callableStates_begin() const { return callableStates_; }
  callableStates_iterator callableStates_end() const { return callableStates_ + callableStates_Size; }
  unsigned callableStates_size() const { return callableStates_Size; }
  llvm::iterator_range<callableStates_iterator> callableStates() const { return llvm::make_range(callableStates_begin(), callableStates_end()); }


  static bool ConvertStrToConsumedState(StringRef Val, ConsumedState &Out);
  static const char *ConvertConsumedStateToStr(ConsumedState Val);


  static bool classof(const Attr *A) { return A->getKind() == attr::CallableWhen; }
};

class CallbackAttr : public InheritableAttr {
  unsigned encoding_Size;
  int *encoding_;

public:
  enum Spelling {
    GNU_callback = 0,
    CXX11_clang_callback = 1,
    C2x_clang_callback = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static CallbackAttr *CreateImplicit(ASTContext &Ctx, int *Encoding, unsigned EncodingSize, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static CallbackAttr *Create(ASTContext &Ctx, int *Encoding, unsigned EncodingSize, const AttributeCommonInfo &CommonInfo);
  static CallbackAttr *CreateImplicit(ASTContext &Ctx, int *Encoding, unsigned EncodingSize, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static CallbackAttr *Create(ASTContext &Ctx, int *Encoding, unsigned EncodingSize, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  CallbackAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , int *Encoding, unsigned EncodingSize
             );
  CallbackAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  CallbackAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  typedef int* encoding_iterator;
  encoding_iterator encoding_begin() const { return encoding_; }
  encoding_iterator encoding_end() const { return encoding_ + encoding_Size; }
  unsigned encoding_size() const { return encoding_Size; }
  llvm::iterator_range<encoding_iterator> encoding() const { return llvm::make_range(encoding_begin(), encoding_end()); }




  static bool classof(const Attr *A) { return A->getKind() == attr::Callback; }
};

class CalledOnceAttr : public Attr {
public:
  enum Spelling {
    GNU_called_once = 0,
    CXX11_clang_called_once = 1,
    C2x_clang_called_once = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static CalledOnceAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static CalledOnceAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static CalledOnceAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static CalledOnceAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  CalledOnceAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  CalledOnceAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::CalledOnce; }
};

class CapabilityAttr : public InheritableAttr {
unsigned nameLength;
char *name;

public:
  enum Spelling {
    GNU_capability = 0,
    CXX11_clang_capability = 1,
    GNU_shared_capability = 2,
    CXX11_clang_shared_capability = 3,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static CapabilityAttr *CreateImplicit(ASTContext &Ctx, llvm::StringRef Name, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static CapabilityAttr *Create(ASTContext &Ctx, llvm::StringRef Name, const AttributeCommonInfo &CommonInfo);
  static CapabilityAttr *CreateImplicit(ASTContext &Ctx, llvm::StringRef Name, SourceRange Range, AttributeCommonInfo::Syntax Syntax, CapabilityAttr::Spelling S = static_cast<Spelling>(SpellingNotCalculated));
  static CapabilityAttr *Create(ASTContext &Ctx, llvm::StringRef Name, SourceRange Range, AttributeCommonInfo::Syntax Syntax, CapabilityAttr::Spelling S = static_cast<Spelling>(SpellingNotCalculated));

  // Constructors
  CapabilityAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , llvm::StringRef Name
             );

  CapabilityAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  Spelling getSemanticSpelling() const;
  bool isShared() const { return getAttributeSpellingListIndex() == 2 ||
    getAttributeSpellingListIndex() == 3; }
  llvm::StringRef getName() const {
    return llvm::StringRef(name, nameLength);
  }
  unsigned getNameLength() const {
    return nameLength;
  }
  void setName(ASTContext &C, llvm::StringRef S) {
    nameLength = S.size();
    this->name = new (C, 1) char [nameLength];
    if (!S.empty())
      std::memcpy(this->name, S.data(), nameLength);
  }



  static bool classof(const Attr *A) { return A->getKind() == attr::Capability; }
};

class CapturedRecordAttr : public InheritableAttr {
public:
  // Factory methods
  static CapturedRecordAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static CapturedRecordAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static CapturedRecordAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static CapturedRecordAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  CapturedRecordAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  CapturedRecordAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::CapturedRecord; }
};

class CarriesDependencyAttr : public InheritableParamAttr {
public:
  enum Spelling {
    GNU_carries_dependency = 0,
    CXX11_carries_dependency = 1,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static CarriesDependencyAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static CarriesDependencyAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static CarriesDependencyAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static CarriesDependencyAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  CarriesDependencyAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  CarriesDependencyAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::CarriesDependency; }
};

class CleanupAttr : public InheritableAttr {
FunctionDecl * functionDecl;

public:
  enum Spelling {
    GNU_cleanup = 0,
    CXX11_gnu_cleanup = 1,
    C2x_gnu_cleanup = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static CleanupAttr *CreateImplicit(ASTContext &Ctx, FunctionDecl * FunctionDecl, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static CleanupAttr *Create(ASTContext &Ctx, FunctionDecl * FunctionDecl, const AttributeCommonInfo &CommonInfo);
  static CleanupAttr *CreateImplicit(ASTContext &Ctx, FunctionDecl * FunctionDecl, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static CleanupAttr *Create(ASTContext &Ctx, FunctionDecl * FunctionDecl, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  CleanupAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , FunctionDecl * FunctionDecl
             );

  CleanupAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  FunctionDecl * getFunctionDecl() const {
    return functionDecl;
  }



  static bool classof(const Attr *A) { return A->getKind() == attr::Cleanup; }
};

class CmseNSCallAttr : public TypeAttr {
public:
  // Factory methods
  static CmseNSCallAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static CmseNSCallAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static CmseNSCallAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static CmseNSCallAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  CmseNSCallAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  CmseNSCallAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::CmseNSCall; }
};

class CmseNSEntryAttr : public InheritableAttr {
public:
  // Factory methods
  static CmseNSEntryAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static CmseNSEntryAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static CmseNSEntryAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static CmseNSEntryAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  CmseNSEntryAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  CmseNSEntryAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::CmseNSEntry; }
};

class CodeSegAttr : public InheritableAttr {
unsigned nameLength;
char *name;

public:
  // Factory methods
  static CodeSegAttr *CreateImplicit(ASTContext &Ctx, llvm::StringRef Name, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static CodeSegAttr *Create(ASTContext &Ctx, llvm::StringRef Name, const AttributeCommonInfo &CommonInfo);
  static CodeSegAttr *CreateImplicit(ASTContext &Ctx, llvm::StringRef Name, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static CodeSegAttr *Create(ASTContext &Ctx, llvm::StringRef Name, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  CodeSegAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , llvm::StringRef Name
             );

  CodeSegAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  llvm::StringRef getName() const {
    return llvm::StringRef(name, nameLength);
  }
  unsigned getNameLength() const {
    return nameLength;
  }
  void setName(ASTContext &C, llvm::StringRef S) {
    nameLength = S.size();
    this->name = new (C, 1) char [nameLength];
    if (!S.empty())
      std::memcpy(this->name, S.data(), nameLength);
  }



  static bool classof(const Attr *A) { return A->getKind() == attr::CodeSeg; }
};

class ColdAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_cold = 0,
    CXX11_gnu_cold = 1,
    C2x_gnu_cold = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static ColdAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static ColdAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static ColdAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static ColdAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  ColdAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  ColdAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::Cold; }
};

class CommonAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_common = 0,
    CXX11_gnu_common = 1,
    C2x_gnu_common = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static CommonAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static CommonAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static CommonAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static CommonAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  CommonAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  CommonAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::Common; }
};

class ConstAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_const = 0,
    CXX11_gnu_const = 1,
    C2x_gnu_const = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static ConstAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static ConstAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static ConstAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static ConstAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  ConstAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  ConstAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::Const; }
};

class ConstInitAttr : public InheritableAttr {
public:
  enum Spelling {
    Keyword_constinit = 0,
    GNU_require_constant_initialization = 1,
    CXX11_clang_require_constant_initialization = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static ConstInitAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static ConstInitAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static ConstInitAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax, ConstInitAttr::Spelling S = static_cast<Spelling>(SpellingNotCalculated));
  static ConstInitAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax, ConstInitAttr::Spelling S = static_cast<Spelling>(SpellingNotCalculated));

  // Constructors
  ConstInitAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  ConstInitAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  Spelling getSemanticSpelling() const;
  bool isConstinit() const { return getAttributeSpellingListIndex() == 0; }


  static bool classof(const Attr *A) { return A->getKind() == attr::ConstInit; }
};

class ConstructorAttr : public InheritableAttr {
int priority;

public:
  enum Spelling {
    GNU_constructor = 0,
    CXX11_gnu_constructor = 1,
    C2x_gnu_constructor = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static ConstructorAttr *CreateImplicit(ASTContext &Ctx, int Priority, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static ConstructorAttr *Create(ASTContext &Ctx, int Priority, const AttributeCommonInfo &CommonInfo);
  static ConstructorAttr *CreateImplicit(ASTContext &Ctx, int Priority, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static ConstructorAttr *Create(ASTContext &Ctx, int Priority, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  ConstructorAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , int Priority
             );
  ConstructorAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  ConstructorAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  int getPriority() const {
    return priority;
  }

  static const int DefaultPriority = 65535;



  static bool classof(const Attr *A) { return A->getKind() == attr::Constructor; }
};

class ConsumableAttr : public InheritableAttr {
public:
  enum ConsumedState {
    Unknown,
    Consumed,
    Unconsumed
  };
private:
  ConsumedState defaultState;

public:
  enum Spelling {
    GNU_consumable = 0,
    CXX11_clang_consumable = 1,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static ConsumableAttr *CreateImplicit(ASTContext &Ctx, ConsumedState DefaultState, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static ConsumableAttr *Create(ASTContext &Ctx, ConsumedState DefaultState, const AttributeCommonInfo &CommonInfo);
  static ConsumableAttr *CreateImplicit(ASTContext &Ctx, ConsumedState DefaultState, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static ConsumableAttr *Create(ASTContext &Ctx, ConsumedState DefaultState, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  ConsumableAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , ConsumedState DefaultState
             );

  ConsumableAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  ConsumedState getDefaultState() const {
    return defaultState;
  }

  static bool ConvertStrToConsumedState(StringRef Val, ConsumedState &Out);
  static const char *ConvertConsumedStateToStr(ConsumedState Val);


  static bool classof(const Attr *A) { return A->getKind() == attr::Consumable; }
};

class ConsumableAutoCastAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_consumable_auto_cast_state = 0,
    CXX11_clang_consumable_auto_cast_state = 1,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static ConsumableAutoCastAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static ConsumableAutoCastAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static ConsumableAutoCastAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static ConsumableAutoCastAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  ConsumableAutoCastAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  ConsumableAutoCastAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::ConsumableAutoCast; }
};

class ConsumableSetOnReadAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_consumable_set_state_on_read = 0,
    CXX11_clang_consumable_set_state_on_read = 1,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static ConsumableSetOnReadAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static ConsumableSetOnReadAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static ConsumableSetOnReadAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static ConsumableSetOnReadAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  ConsumableSetOnReadAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  ConsumableSetOnReadAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::ConsumableSetOnRead; }
};

class ConvergentAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_convergent = 0,
    CXX11_clang_convergent = 1,
    C2x_clang_convergent = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static ConvergentAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static ConvergentAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static ConvergentAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static ConvergentAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  ConvergentAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  ConvergentAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::Convergent; }
};

class DLLExportAttr : public InheritableAttr {
public:
  enum Spelling {
    Declspec_dllexport = 0,
    GNU_dllexport = 1,
    CXX11_gnu_dllexport = 2,
    C2x_gnu_dllexport = 3,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static DLLExportAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static DLLExportAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static DLLExportAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static DLLExportAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  DLLExportAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  DLLExportAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::DLLExport; }
};

class DLLExportStaticLocalAttr : public InheritableAttr {
public:
  // Factory methods
  static DLLExportStaticLocalAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static DLLExportStaticLocalAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static DLLExportStaticLocalAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static DLLExportStaticLocalAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  DLLExportStaticLocalAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  DLLExportStaticLocalAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::DLLExportStaticLocal; }
};

class DLLImportAttr : public InheritableAttr {
public:
  enum Spelling {
    Declspec_dllimport = 0,
    GNU_dllimport = 1,
    CXX11_gnu_dllimport = 2,
    C2x_gnu_dllimport = 3,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static DLLImportAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static DLLImportAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static DLLImportAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static DLLImportAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  DLLImportAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  DLLImportAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;

private:
  bool PropagatedToBaseTemplate = false;

public:
  void setPropagatedToBaseTemplate() { PropagatedToBaseTemplate = true; }
  bool wasPropagatedToBaseTemplate() { return PropagatedToBaseTemplate; }
  

  static bool classof(const Attr *A) { return A->getKind() == attr::DLLImport; }
};

class DLLImportStaticLocalAttr : public InheritableAttr {
public:
  // Factory methods
  static DLLImportStaticLocalAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static DLLImportStaticLocalAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static DLLImportStaticLocalAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static DLLImportStaticLocalAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  DLLImportStaticLocalAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  DLLImportStaticLocalAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::DLLImportStaticLocal; }
};

class DeprecatedAttr : public InheritableAttr {
unsigned messageLength;
char *message;

unsigned replacementLength;
char *replacement;

public:
  enum Spelling {
    GNU_deprecated = 0,
    CXX11_gnu_deprecated = 1,
    C2x_gnu_deprecated = 2,
    Declspec_deprecated = 3,
    CXX11_deprecated = 4,
    C2x_deprecated = 5,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static DeprecatedAttr *CreateImplicit(ASTContext &Ctx, llvm::StringRef Message, llvm::StringRef Replacement, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static DeprecatedAttr *Create(ASTContext &Ctx, llvm::StringRef Message, llvm::StringRef Replacement, const AttributeCommonInfo &CommonInfo);
  static DeprecatedAttr *CreateImplicit(ASTContext &Ctx, llvm::StringRef Message, llvm::StringRef Replacement, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static DeprecatedAttr *Create(ASTContext &Ctx, llvm::StringRef Message, llvm::StringRef Replacement, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  DeprecatedAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , llvm::StringRef Message
              , llvm::StringRef Replacement
             );
  DeprecatedAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  DeprecatedAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  llvm::StringRef getMessage() const {
    return llvm::StringRef(message, messageLength);
  }
  unsigned getMessageLength() const {
    return messageLength;
  }
  void setMessage(ASTContext &C, llvm::StringRef S) {
    messageLength = S.size();
    this->message = new (C, 1) char [messageLength];
    if (!S.empty())
      std::memcpy(this->message, S.data(), messageLength);
  }

  llvm::StringRef getReplacement() const {
    return llvm::StringRef(replacement, replacementLength);
  }
  unsigned getReplacementLength() const {
    return replacementLength;
  }
  void setReplacement(ASTContext &C, llvm::StringRef S) {
    replacementLength = S.size();
    this->replacement = new (C, 1) char [replacementLength];
    if (!S.empty())
      std::memcpy(this->replacement, S.data(), replacementLength);
  }



  static bool classof(const Attr *A) { return A->getKind() == attr::Deprecated; }
};

class DestructorAttr : public InheritableAttr {
int priority;

public:
  enum Spelling {
    GNU_destructor = 0,
    CXX11_gnu_destructor = 1,
    C2x_gnu_destructor = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static DestructorAttr *CreateImplicit(ASTContext &Ctx, int Priority, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static DestructorAttr *Create(ASTContext &Ctx, int Priority, const AttributeCommonInfo &CommonInfo);
  static DestructorAttr *CreateImplicit(ASTContext &Ctx, int Priority, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static DestructorAttr *Create(ASTContext &Ctx, int Priority, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  DestructorAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , int Priority
             );
  DestructorAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  DestructorAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  int getPriority() const {
    return priority;
  }

  static const int DefaultPriority = 65535;



  static bool classof(const Attr *A) { return A->getKind() == attr::Destructor; }
};

class DiagnoseAsBuiltinAttr : public InheritableAttr {
FunctionDecl * function;

  unsigned argIndices_Size;
  unsigned *argIndices_;

public:
  enum Spelling {
    GNU_diagnose_as_builtin = 0,
    CXX11_clang_diagnose_as_builtin = 1,
    C2x_clang_diagnose_as_builtin = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static DiagnoseAsBuiltinAttr *CreateImplicit(ASTContext &Ctx, FunctionDecl * Function, unsigned *ArgIndices, unsigned ArgIndicesSize, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static DiagnoseAsBuiltinAttr *Create(ASTContext &Ctx, FunctionDecl * Function, unsigned *ArgIndices, unsigned ArgIndicesSize, const AttributeCommonInfo &CommonInfo);
  static DiagnoseAsBuiltinAttr *CreateImplicit(ASTContext &Ctx, FunctionDecl * Function, unsigned *ArgIndices, unsigned ArgIndicesSize, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static DiagnoseAsBuiltinAttr *Create(ASTContext &Ctx, FunctionDecl * Function, unsigned *ArgIndices, unsigned ArgIndicesSize, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  DiagnoseAsBuiltinAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , FunctionDecl * Function
              , unsigned *ArgIndices, unsigned ArgIndicesSize
             );
  DiagnoseAsBuiltinAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , FunctionDecl * Function
             );

  DiagnoseAsBuiltinAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  FunctionDecl * getFunction() const {
    return function;
  }

  typedef unsigned* argIndices_iterator;
  argIndices_iterator argIndices_begin() const { return argIndices_; }
  argIndices_iterator argIndices_end() const { return argIndices_ + argIndices_Size; }
  unsigned argIndices_size() const { return argIndices_Size; }
  llvm::iterator_range<argIndices_iterator> argIndices() const { return llvm::make_range(argIndices_begin(), argIndices_end()); }




  static bool classof(const Attr *A) { return A->getKind() == attr::DiagnoseAsBuiltin; }
};

class DiagnoseIfAttr : public InheritableAttr {
Expr * cond;

unsigned messageLength;
char *message;

public:
  enum DiagnosticType {
    DT_Error,
    DT_Warning
  };
private:
  DiagnosticType diagnosticType;

bool argDependent;

NamedDecl * parent;

public:
  // Factory methods
  static DiagnoseIfAttr *CreateImplicit(ASTContext &Ctx, Expr * Cond, llvm::StringRef Message, DiagnosticType DiagnosticType, bool ArgDependent, NamedDecl * Parent, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static DiagnoseIfAttr *Create(ASTContext &Ctx, Expr * Cond, llvm::StringRef Message, DiagnosticType DiagnosticType, bool ArgDependent, NamedDecl * Parent, const AttributeCommonInfo &CommonInfo);
  static DiagnoseIfAttr *CreateImplicit(ASTContext &Ctx, Expr * Cond, llvm::StringRef Message, DiagnosticType DiagnosticType, bool ArgDependent, NamedDecl * Parent, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static DiagnoseIfAttr *Create(ASTContext &Ctx, Expr * Cond, llvm::StringRef Message, DiagnosticType DiagnosticType, bool ArgDependent, NamedDecl * Parent, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static DiagnoseIfAttr *CreateImplicit(ASTContext &Ctx, Expr * Cond, llvm::StringRef Message, DiagnosticType DiagnosticType, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static DiagnoseIfAttr *Create(ASTContext &Ctx, Expr * Cond, llvm::StringRef Message, DiagnosticType DiagnosticType, const AttributeCommonInfo &CommonInfo);
  static DiagnoseIfAttr *CreateImplicit(ASTContext &Ctx, Expr * Cond, llvm::StringRef Message, DiagnosticType DiagnosticType, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static DiagnoseIfAttr *Create(ASTContext &Ctx, Expr * Cond, llvm::StringRef Message, DiagnosticType DiagnosticType, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  DiagnoseIfAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , Expr * Cond
              , llvm::StringRef Message
              , DiagnosticType DiagnosticType
              , bool ArgDependent
              , NamedDecl * Parent
             );
  DiagnoseIfAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , Expr * Cond
              , llvm::StringRef Message
              , DiagnosticType DiagnosticType
             );

  DiagnoseIfAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  Expr * getCond() const {
    return cond;
  }

  llvm::StringRef getMessage() const {
    return llvm::StringRef(message, messageLength);
  }
  unsigned getMessageLength() const {
    return messageLength;
  }
  void setMessage(ASTContext &C, llvm::StringRef S) {
    messageLength = S.size();
    this->message = new (C, 1) char [messageLength];
    if (!S.empty())
      std::memcpy(this->message, S.data(), messageLength);
  }

  DiagnosticType getDiagnosticType() const {
    return diagnosticType;
  }

  static bool ConvertStrToDiagnosticType(StringRef Val, DiagnosticType &Out);
  static const char *ConvertDiagnosticTypeToStr(DiagnosticType Val);
  bool getArgDependent() const {
    return argDependent;
  }

  NamedDecl * getParent() const {
    return parent;
  }


    bool isError() const { return diagnosticType == DT_Error; }
    bool isWarning() const { return diagnosticType == DT_Warning; }
  

  static bool classof(const Attr *A) { return A->getKind() == attr::DiagnoseIf; }
};

class DisableSanitizerInstrumentationAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_disable_sanitizer_instrumentation = 0,
    CXX11_clang_disable_sanitizer_instrumentation = 1,
    C2x_clang_disable_sanitizer_instrumentation = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static DisableSanitizerInstrumentationAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static DisableSanitizerInstrumentationAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static DisableSanitizerInstrumentationAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static DisableSanitizerInstrumentationAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  DisableSanitizerInstrumentationAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  DisableSanitizerInstrumentationAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::DisableSanitizerInstrumentation; }
};

class DisableTailCallsAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_disable_tail_calls = 0,
    CXX11_clang_disable_tail_calls = 1,
    C2x_clang_disable_tail_calls = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static DisableTailCallsAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static DisableTailCallsAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static DisableTailCallsAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static DisableTailCallsAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  DisableTailCallsAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  DisableTailCallsAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::DisableTailCalls; }
};

class EmptyBasesAttr : public InheritableAttr {
public:
  // Factory methods
  static EmptyBasesAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static EmptyBasesAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static EmptyBasesAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static EmptyBasesAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  EmptyBasesAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  EmptyBasesAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::EmptyBases; }
};

class EnableIfAttr : public InheritableAttr {
Expr * cond;

unsigned messageLength;
char *message;

public:
  // Factory methods
  static EnableIfAttr *CreateImplicit(ASTContext &Ctx, Expr * Cond, llvm::StringRef Message, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static EnableIfAttr *Create(ASTContext &Ctx, Expr * Cond, llvm::StringRef Message, const AttributeCommonInfo &CommonInfo);
  static EnableIfAttr *CreateImplicit(ASTContext &Ctx, Expr * Cond, llvm::StringRef Message, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static EnableIfAttr *Create(ASTContext &Ctx, Expr * Cond, llvm::StringRef Message, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  EnableIfAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , Expr * Cond
              , llvm::StringRef Message
             );

  EnableIfAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  Expr * getCond() const {
    return cond;
  }

  llvm::StringRef getMessage() const {
    return llvm::StringRef(message, messageLength);
  }
  unsigned getMessageLength() const {
    return messageLength;
  }
  void setMessage(ASTContext &C, llvm::StringRef S) {
    messageLength = S.size();
    this->message = new (C, 1) char [messageLength];
    if (!S.empty())
      std::memcpy(this->message, S.data(), messageLength);
  }



  static bool classof(const Attr *A) { return A->getKind() == attr::EnableIf; }
};

class EnforceTCBAttr : public InheritableAttr {
unsigned tCBNameLength;
char *tCBName;

public:
  enum Spelling {
    GNU_enforce_tcb = 0,
    CXX11_clang_enforce_tcb = 1,
    C2x_clang_enforce_tcb = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static EnforceTCBAttr *CreateImplicit(ASTContext &Ctx, llvm::StringRef TCBName, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static EnforceTCBAttr *Create(ASTContext &Ctx, llvm::StringRef TCBName, const AttributeCommonInfo &CommonInfo);
  static EnforceTCBAttr *CreateImplicit(ASTContext &Ctx, llvm::StringRef TCBName, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static EnforceTCBAttr *Create(ASTContext &Ctx, llvm::StringRef TCBName, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  EnforceTCBAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , llvm::StringRef TCBName
             );

  EnforceTCBAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  llvm::StringRef getTCBName() const {
    return llvm::StringRef(tCBName, tCBNameLength);
  }
  unsigned getTCBNameLength() const {
    return tCBNameLength;
  }
  void setTCBName(ASTContext &C, llvm::StringRef S) {
    tCBNameLength = S.size();
    this->tCBName = new (C, 1) char [tCBNameLength];
    if (!S.empty())
      std::memcpy(this->tCBName, S.data(), tCBNameLength);
  }



  static bool classof(const Attr *A) { return A->getKind() == attr::EnforceTCB; }
};

class EnforceTCBLeafAttr : public InheritableAttr {
unsigned tCBNameLength;
char *tCBName;

public:
  enum Spelling {
    GNU_enforce_tcb_leaf = 0,
    CXX11_clang_enforce_tcb_leaf = 1,
    C2x_clang_enforce_tcb_leaf = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static EnforceTCBLeafAttr *CreateImplicit(ASTContext &Ctx, llvm::StringRef TCBName, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static EnforceTCBLeafAttr *Create(ASTContext &Ctx, llvm::StringRef TCBName, const AttributeCommonInfo &CommonInfo);
  static EnforceTCBLeafAttr *CreateImplicit(ASTContext &Ctx, llvm::StringRef TCBName, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static EnforceTCBLeafAttr *Create(ASTContext &Ctx, llvm::StringRef TCBName, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  EnforceTCBLeafAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , llvm::StringRef TCBName
             );

  EnforceTCBLeafAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  llvm::StringRef getTCBName() const {
    return llvm::StringRef(tCBName, tCBNameLength);
  }
  unsigned getTCBNameLength() const {
    return tCBNameLength;
  }
  void setTCBName(ASTContext &C, llvm::StringRef S) {
    tCBNameLength = S.size();
    this->tCBName = new (C, 1) char [tCBNameLength];
    if (!S.empty())
      std::memcpy(this->tCBName, S.data(), tCBNameLength);
  }



  static bool classof(const Attr *A) { return A->getKind() == attr::EnforceTCBLeaf; }
};

class EnumExtensibilityAttr : public InheritableAttr {
public:
  enum Kind {
    Closed,
    Open
  };
private:
  Kind extensibility;

public:
  enum Spelling {
    GNU_enum_extensibility = 0,
    CXX11_clang_enum_extensibility = 1,
    C2x_clang_enum_extensibility = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static EnumExtensibilityAttr *CreateImplicit(ASTContext &Ctx, Kind Extensibility, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static EnumExtensibilityAttr *Create(ASTContext &Ctx, Kind Extensibility, const AttributeCommonInfo &CommonInfo);
  static EnumExtensibilityAttr *CreateImplicit(ASTContext &Ctx, Kind Extensibility, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static EnumExtensibilityAttr *Create(ASTContext &Ctx, Kind Extensibility, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  EnumExtensibilityAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , Kind Extensibility
             );

  EnumExtensibilityAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  Kind getExtensibility() const {
    return extensibility;
  }

  static bool ConvertStrToKind(StringRef Val, Kind &Out);
  static const char *ConvertKindToStr(Kind Val);


  static bool classof(const Attr *A) { return A->getKind() == attr::EnumExtensibility; }
};

class ErrorAttr : public InheritableAttr {
unsigned userDiagnosticLength;
char *userDiagnostic;

public:
  enum Spelling {
    GNU_error = 0,
    CXX11_gnu_error = 1,
    C2x_gnu_error = 2,
    GNU_warning = 3,
    CXX11_gnu_warning = 4,
    C2x_gnu_warning = 5,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static ErrorAttr *CreateImplicit(ASTContext &Ctx, llvm::StringRef UserDiagnostic, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static ErrorAttr *Create(ASTContext &Ctx, llvm::StringRef UserDiagnostic, const AttributeCommonInfo &CommonInfo);
  static ErrorAttr *CreateImplicit(ASTContext &Ctx, llvm::StringRef UserDiagnostic, SourceRange Range, AttributeCommonInfo::Syntax Syntax, ErrorAttr::Spelling S = static_cast<Spelling>(SpellingNotCalculated));
  static ErrorAttr *Create(ASTContext &Ctx, llvm::StringRef UserDiagnostic, SourceRange Range, AttributeCommonInfo::Syntax Syntax, ErrorAttr::Spelling S = static_cast<Spelling>(SpellingNotCalculated));

  // Constructors
  ErrorAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , llvm::StringRef UserDiagnostic
             );

  ErrorAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  Spelling getSemanticSpelling() const;
  bool isError() const { return getAttributeSpellingListIndex() == 0 ||
    getAttributeSpellingListIndex() == 1 ||
    getAttributeSpellingListIndex() == 2; }
  bool isWarning() const { return getAttributeSpellingListIndex() == 3 ||
    getAttributeSpellingListIndex() == 4 ||
    getAttributeSpellingListIndex() == 5; }
  llvm::StringRef getUserDiagnostic() const {
    return llvm::StringRef(userDiagnostic, userDiagnosticLength);
  }
  unsigned getUserDiagnosticLength() const {
    return userDiagnosticLength;
  }
  void setUserDiagnostic(ASTContext &C, llvm::StringRef S) {
    userDiagnosticLength = S.size();
    this->userDiagnostic = new (C, 1) char [userDiagnosticLength];
    if (!S.empty())
      std::memcpy(this->userDiagnostic, S.data(), userDiagnosticLength);
  }



  static bool classof(const Attr *A) { return A->getKind() == attr::Error; }
};

class ExcludeFromExplicitInstantiationAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_exclude_from_explicit_instantiation = 0,
    CXX11_clang_exclude_from_explicit_instantiation = 1,
    C2x_clang_exclude_from_explicit_instantiation = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static ExcludeFromExplicitInstantiationAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static ExcludeFromExplicitInstantiationAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static ExcludeFromExplicitInstantiationAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static ExcludeFromExplicitInstantiationAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  ExcludeFromExplicitInstantiationAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  ExcludeFromExplicitInstantiationAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::ExcludeFromExplicitInstantiation; }
};

class ExclusiveTrylockFunctionAttr : public InheritableAttr {
Expr * successValue;

  unsigned args_Size;
  Expr * *args_;

public:
  // Factory methods
  static ExclusiveTrylockFunctionAttr *CreateImplicit(ASTContext &Ctx, Expr * SuccessValue, Expr * *Args, unsigned ArgsSize, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static ExclusiveTrylockFunctionAttr *Create(ASTContext &Ctx, Expr * SuccessValue, Expr * *Args, unsigned ArgsSize, const AttributeCommonInfo &CommonInfo);
  static ExclusiveTrylockFunctionAttr *CreateImplicit(ASTContext &Ctx, Expr * SuccessValue, Expr * *Args, unsigned ArgsSize, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static ExclusiveTrylockFunctionAttr *Create(ASTContext &Ctx, Expr * SuccessValue, Expr * *Args, unsigned ArgsSize, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  ExclusiveTrylockFunctionAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , Expr * SuccessValue
              , Expr * *Args, unsigned ArgsSize
             );
  ExclusiveTrylockFunctionAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , Expr * SuccessValue
             );

  ExclusiveTrylockFunctionAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  Expr * getSuccessValue() const {
    return successValue;
  }

  typedef Expr ** args_iterator;
  args_iterator args_begin() const { return args_; }
  args_iterator args_end() const { return args_ + args_Size; }
  unsigned args_size() const { return args_Size; }
  llvm::iterator_range<args_iterator> args() const { return llvm::make_range(args_begin(), args_end()); }




  static bool classof(const Attr *A) { return A->getKind() == attr::ExclusiveTrylockFunction; }
};

class ExternalSourceSymbolAttr : public InheritableAttr {
unsigned languageLength;
char *language;

unsigned definedInLength;
char *definedIn;

bool generatedDeclaration;

public:
  enum Spelling {
    GNU_external_source_symbol = 0,
    CXX11_clang_external_source_symbol = 1,
    C2x_clang_external_source_symbol = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static ExternalSourceSymbolAttr *CreateImplicit(ASTContext &Ctx, llvm::StringRef Language, llvm::StringRef DefinedIn, bool GeneratedDeclaration, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static ExternalSourceSymbolAttr *Create(ASTContext &Ctx, llvm::StringRef Language, llvm::StringRef DefinedIn, bool GeneratedDeclaration, const AttributeCommonInfo &CommonInfo);
  static ExternalSourceSymbolAttr *CreateImplicit(ASTContext &Ctx, llvm::StringRef Language, llvm::StringRef DefinedIn, bool GeneratedDeclaration, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static ExternalSourceSymbolAttr *Create(ASTContext &Ctx, llvm::StringRef Language, llvm::StringRef DefinedIn, bool GeneratedDeclaration, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  ExternalSourceSymbolAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , llvm::StringRef Language
              , llvm::StringRef DefinedIn
              , bool GeneratedDeclaration
             );
  ExternalSourceSymbolAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  ExternalSourceSymbolAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  llvm::StringRef getLanguage() const {
    return llvm::StringRef(language, languageLength);
  }
  unsigned getLanguageLength() const {
    return languageLength;
  }
  void setLanguage(ASTContext &C, llvm::StringRef S) {
    languageLength = S.size();
    this->language = new (C, 1) char [languageLength];
    if (!S.empty())
      std::memcpy(this->language, S.data(), languageLength);
  }

  llvm::StringRef getDefinedIn() const {
    return llvm::StringRef(definedIn, definedInLength);
  }
  unsigned getDefinedInLength() const {
    return definedInLength;
  }
  void setDefinedIn(ASTContext &C, llvm::StringRef S) {
    definedInLength = S.size();
    this->definedIn = new (C, 1) char [definedInLength];
    if (!S.empty())
      std::memcpy(this->definedIn, S.data(), definedInLength);
  }

  bool getGeneratedDeclaration() const {
    return generatedDeclaration;
  }



  static bool classof(const Attr *A) { return A->getKind() == attr::ExternalSourceSymbol; }
};

class FallThroughAttr : public StmtAttr {
public:
  enum Spelling {
    CXX11_fallthrough = 0,
    C2x_fallthrough = 1,
    CXX11_clang_fallthrough = 2,
    GNU_fallthrough = 3,
    CXX11_gnu_fallthrough = 4,
    C2x_gnu_fallthrough = 5,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static FallThroughAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static FallThroughAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static FallThroughAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static FallThroughAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  FallThroughAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  FallThroughAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::FallThrough; }
};

class FastCallAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_fastcall = 0,
    CXX11_gnu_fastcall = 1,
    C2x_gnu_fastcall = 2,
    Keyword_fastcall = 3,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static FastCallAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static FastCallAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static FastCallAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static FastCallAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  FastCallAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  FastCallAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::FastCall; }
};

class FinalAttr : public InheritableAttr {
public:
  enum Spelling {
    Keyword_final = 0,
    Keyword_sealed = 1,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static FinalAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static FinalAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static FinalAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax, FinalAttr::Spelling S = static_cast<Spelling>(SpellingNotCalculated));
  static FinalAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax, FinalAttr::Spelling S = static_cast<Spelling>(SpellingNotCalculated));

  // Constructors
  FinalAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  FinalAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  Spelling getSemanticSpelling() const;
  bool isSpelledAsSealed() const { return getAttributeSpellingListIndex() == 1; }


  static bool classof(const Attr *A) { return A->getKind() == attr::Final; }
};

class FlagEnumAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_flag_enum = 0,
    CXX11_clang_flag_enum = 1,
    C2x_clang_flag_enum = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static FlagEnumAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static FlagEnumAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static FlagEnumAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static FlagEnumAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  FlagEnumAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  FlagEnumAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::FlagEnum; }
};

class FlattenAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_flatten = 0,
    CXX11_gnu_flatten = 1,
    C2x_gnu_flatten = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static FlattenAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static FlattenAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static FlattenAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static FlattenAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  FlattenAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  FlattenAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::Flatten; }
};

class FormatAttr : public InheritableAttr {
IdentifierInfo * type;

int formatIdx;

int firstArg;

public:
  enum Spelling {
    GNU_format = 0,
    CXX11_gnu_format = 1,
    C2x_gnu_format = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static FormatAttr *CreateImplicit(ASTContext &Ctx, IdentifierInfo * Type, int FormatIdx, int FirstArg, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static FormatAttr *Create(ASTContext &Ctx, IdentifierInfo * Type, int FormatIdx, int FirstArg, const AttributeCommonInfo &CommonInfo);
  static FormatAttr *CreateImplicit(ASTContext &Ctx, IdentifierInfo * Type, int FormatIdx, int FirstArg, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static FormatAttr *Create(ASTContext &Ctx, IdentifierInfo * Type, int FormatIdx, int FirstArg, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  FormatAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , IdentifierInfo * Type
              , int FormatIdx
              , int FirstArg
             );

  FormatAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  IdentifierInfo * getType() const {
    return type;
  }

  int getFormatIdx() const {
    return formatIdx;
  }

  int getFirstArg() const {
    return firstArg;
  }



  static bool classof(const Attr *A) { return A->getKind() == attr::Format; }
};

class FormatArgAttr : public InheritableAttr {
ParamIdx formatIdx;

public:
  enum Spelling {
    GNU_format_arg = 0,
    CXX11_gnu_format_arg = 1,
    C2x_gnu_format_arg = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static FormatArgAttr *CreateImplicit(ASTContext &Ctx, ParamIdx FormatIdx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static FormatArgAttr *Create(ASTContext &Ctx, ParamIdx FormatIdx, const AttributeCommonInfo &CommonInfo);
  static FormatArgAttr *CreateImplicit(ASTContext &Ctx, ParamIdx FormatIdx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static FormatArgAttr *Create(ASTContext &Ctx, ParamIdx FormatIdx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  FormatArgAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , ParamIdx FormatIdx
             );

  FormatArgAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  ParamIdx getFormatIdx() const {
    return formatIdx;
  }



  static bool classof(const Attr *A) { return A->getKind() == attr::FormatArg; }
};

class GNUInlineAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_gnu_inline = 0,
    CXX11_gnu_gnu_inline = 1,
    C2x_gnu_gnu_inline = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static GNUInlineAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static GNUInlineAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static GNUInlineAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static GNUInlineAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  GNUInlineAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  GNUInlineAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::GNUInline; }
};

class GuardedByAttr : public InheritableAttr {
Expr * arg;

public:
  // Factory methods
  static GuardedByAttr *CreateImplicit(ASTContext &Ctx, Expr * Arg, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static GuardedByAttr *Create(ASTContext &Ctx, Expr * Arg, const AttributeCommonInfo &CommonInfo);
  static GuardedByAttr *CreateImplicit(ASTContext &Ctx, Expr * Arg, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static GuardedByAttr *Create(ASTContext &Ctx, Expr * Arg, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  GuardedByAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , Expr * Arg
             );

  GuardedByAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  Expr * getArg() const {
    return arg;
  }



  static bool classof(const Attr *A) { return A->getKind() == attr::GuardedBy; }
};

class GuardedVarAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_guarded_var = 0,
    CXX11_clang_guarded_var = 1,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static GuardedVarAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static GuardedVarAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static GuardedVarAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static GuardedVarAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  GuardedVarAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  GuardedVarAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::GuardedVar; }
};

class HIPManagedAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_managed = 0,
    Declspec_managed = 1,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static HIPManagedAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static HIPManagedAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static HIPManagedAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static HIPManagedAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  HIPManagedAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  HIPManagedAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::HIPManaged; }
};

class HotAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_hot = 0,
    CXX11_gnu_hot = 1,
    C2x_gnu_hot = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static HotAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static HotAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static HotAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static HotAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  HotAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  HotAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::Hot; }
};

class IBActionAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_ibaction = 0,
    CXX11_clang_ibaction = 1,
    C2x_clang_ibaction = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static IBActionAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static IBActionAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static IBActionAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static IBActionAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  IBActionAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  IBActionAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::IBAction; }
};

class IBOutletAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_iboutlet = 0,
    CXX11_clang_iboutlet = 1,
    C2x_clang_iboutlet = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static IBOutletAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static IBOutletAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static IBOutletAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static IBOutletAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  IBOutletAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  IBOutletAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::IBOutlet; }
};

class IBOutletCollectionAttr : public InheritableAttr {
TypeSourceInfo * interface_;

public:
  enum Spelling {
    GNU_iboutletcollection = 0,
    CXX11_clang_iboutletcollection = 1,
    C2x_clang_iboutletcollection = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static IBOutletCollectionAttr *CreateImplicit(ASTContext &Ctx, TypeSourceInfo * Interface, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static IBOutletCollectionAttr *Create(ASTContext &Ctx, TypeSourceInfo * Interface, const AttributeCommonInfo &CommonInfo);
  static IBOutletCollectionAttr *CreateImplicit(ASTContext &Ctx, TypeSourceInfo * Interface, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static IBOutletCollectionAttr *Create(ASTContext &Ctx, TypeSourceInfo * Interface, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  IBOutletCollectionAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , TypeSourceInfo * Interface
             );
  IBOutletCollectionAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  IBOutletCollectionAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  QualType getInterface() const {
    return interface_->getType();
  }  TypeSourceInfo * getInterfaceLoc() const {
    return interface_;
  }



  static bool classof(const Attr *A) { return A->getKind() == attr::IBOutletCollection; }
};

class IFuncAttr : public Attr {
unsigned resolverLength;
char *resolver;

public:
  enum Spelling {
    GNU_ifunc = 0,
    CXX11_gnu_ifunc = 1,
    C2x_gnu_ifunc = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static IFuncAttr *CreateImplicit(ASTContext &Ctx, llvm::StringRef Resolver, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static IFuncAttr *Create(ASTContext &Ctx, llvm::StringRef Resolver, const AttributeCommonInfo &CommonInfo);
  static IFuncAttr *CreateImplicit(ASTContext &Ctx, llvm::StringRef Resolver, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static IFuncAttr *Create(ASTContext &Ctx, llvm::StringRef Resolver, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  IFuncAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , llvm::StringRef Resolver
             );

  IFuncAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  llvm::StringRef getResolver() const {
    return llvm::StringRef(resolver, resolverLength);
  }
  unsigned getResolverLength() const {
    return resolverLength;
  }
  void setResolver(ASTContext &C, llvm::StringRef S) {
    resolverLength = S.size();
    this->resolver = new (C, 1) char [resolverLength];
    if (!S.empty())
      std::memcpy(this->resolver, S.data(), resolverLength);
  }



  static bool classof(const Attr *A) { return A->getKind() == attr::IFunc; }
};

class InitPriorityAttr : public InheritableAttr {
unsigned priority;

public:
  enum Spelling {
    GNU_init_priority = 0,
    CXX11_gnu_init_priority = 1,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static InitPriorityAttr *CreateImplicit(ASTContext &Ctx, unsigned Priority, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static InitPriorityAttr *Create(ASTContext &Ctx, unsigned Priority, const AttributeCommonInfo &CommonInfo);
  static InitPriorityAttr *CreateImplicit(ASTContext &Ctx, unsigned Priority, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static InitPriorityAttr *Create(ASTContext &Ctx, unsigned Priority, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  InitPriorityAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , unsigned Priority
             );

  InitPriorityAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  unsigned getPriority() const {
    return priority;
  }



  static bool classof(const Attr *A) { return A->getKind() == attr::InitPriority; }
};

class InitSegAttr : public Attr {
unsigned sectionLength;
char *section;

public:
  // Factory methods
  static InitSegAttr *CreateImplicit(ASTContext &Ctx, llvm::StringRef Section, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static InitSegAttr *Create(ASTContext &Ctx, llvm::StringRef Section, const AttributeCommonInfo &CommonInfo);
  static InitSegAttr *CreateImplicit(ASTContext &Ctx, llvm::StringRef Section, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static InitSegAttr *Create(ASTContext &Ctx, llvm::StringRef Section, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  InitSegAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , llvm::StringRef Section
             );

  InitSegAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  llvm::StringRef getSection() const {
    return llvm::StringRef(section, sectionLength);
  }
  unsigned getSectionLength() const {
    return sectionLength;
  }
  void setSection(ASTContext &C, llvm::StringRef S) {
    sectionLength = S.size();
    this->section = new (C, 1) char [sectionLength];
    if (!S.empty())
      std::memcpy(this->section, S.data(), sectionLength);
  }


  void printPrettyPragma(raw_ostream &OS, const PrintingPolicy &Policy) const {
    OS << " (" << getSection() << ')';
  }
  

  static bool classof(const Attr *A) { return A->getKind() == attr::InitSeg; }
};

class IntelOclBiccAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_intel_ocl_bicc = 0,
    CXX11_clang_intel_ocl_bicc = 1,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static IntelOclBiccAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static IntelOclBiccAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static IntelOclBiccAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static IntelOclBiccAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  IntelOclBiccAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  IntelOclBiccAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::IntelOclBicc; }
};

class InternalLinkageAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_internal_linkage = 0,
    CXX11_clang_internal_linkage = 1,
    C2x_clang_internal_linkage = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static InternalLinkageAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static InternalLinkageAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static InternalLinkageAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static InternalLinkageAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  InternalLinkageAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  InternalLinkageAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::InternalLinkage; }
};

class LTOVisibilityPublicAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_lto_visibility_public = 0,
    CXX11_clang_lto_visibility_public = 1,
    C2x_clang_lto_visibility_public = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static LTOVisibilityPublicAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static LTOVisibilityPublicAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static LTOVisibilityPublicAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static LTOVisibilityPublicAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  LTOVisibilityPublicAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  LTOVisibilityPublicAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::LTOVisibilityPublic; }
};

class LayoutVersionAttr : public InheritableAttr {
unsigned version;

public:
  // Factory methods
  static LayoutVersionAttr *CreateImplicit(ASTContext &Ctx, unsigned Version, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static LayoutVersionAttr *Create(ASTContext &Ctx, unsigned Version, const AttributeCommonInfo &CommonInfo);
  static LayoutVersionAttr *CreateImplicit(ASTContext &Ctx, unsigned Version, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static LayoutVersionAttr *Create(ASTContext &Ctx, unsigned Version, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  LayoutVersionAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , unsigned Version
             );

  LayoutVersionAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  unsigned getVersion() const {
    return version;
  }



  static bool classof(const Attr *A) { return A->getKind() == attr::LayoutVersion; }
};

class LeafAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_leaf = 0,
    CXX11_gnu_leaf = 1,
    C2x_gnu_leaf = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static LeafAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static LeafAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static LeafAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static LeafAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  LeafAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  LeafAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::Leaf; }
};

class LifetimeBoundAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_lifetimebound = 0,
    CXX11_clang_lifetimebound = 1,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static LifetimeBoundAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static LifetimeBoundAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static LifetimeBoundAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static LifetimeBoundAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  LifetimeBoundAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  LifetimeBoundAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::LifetimeBound; }
};

class LikelyAttr : public StmtAttr {
public:
  enum Spelling {
    CXX11_likely = 0,
    C2x_clang_likely = 1,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static LikelyAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static LikelyAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static LikelyAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static LikelyAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  LikelyAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  LikelyAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::Likely; }
};

class LoaderUninitializedAttr : public Attr {
public:
  enum Spelling {
    GNU_loader_uninitialized = 0,
    CXX11_clang_loader_uninitialized = 1,
    C2x_clang_loader_uninitialized = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static LoaderUninitializedAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static LoaderUninitializedAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static LoaderUninitializedAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static LoaderUninitializedAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  LoaderUninitializedAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  LoaderUninitializedAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::LoaderUninitialized; }
};

class LockReturnedAttr : public InheritableAttr {
Expr * arg;

public:
  // Factory methods
  static LockReturnedAttr *CreateImplicit(ASTContext &Ctx, Expr * Arg, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static LockReturnedAttr *Create(ASTContext &Ctx, Expr * Arg, const AttributeCommonInfo &CommonInfo);
  static LockReturnedAttr *CreateImplicit(ASTContext &Ctx, Expr * Arg, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static LockReturnedAttr *Create(ASTContext &Ctx, Expr * Arg, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  LockReturnedAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , Expr * Arg
             );

  LockReturnedAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  Expr * getArg() const {
    return arg;
  }



  static bool classof(const Attr *A) { return A->getKind() == attr::LockReturned; }
};

class LocksExcludedAttr : public InheritableAttr {
  unsigned args_Size;
  Expr * *args_;

public:
  // Factory methods
  static LocksExcludedAttr *CreateImplicit(ASTContext &Ctx, Expr * *Args, unsigned ArgsSize, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static LocksExcludedAttr *Create(ASTContext &Ctx, Expr * *Args, unsigned ArgsSize, const AttributeCommonInfo &CommonInfo);
  static LocksExcludedAttr *CreateImplicit(ASTContext &Ctx, Expr * *Args, unsigned ArgsSize, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static LocksExcludedAttr *Create(ASTContext &Ctx, Expr * *Args, unsigned ArgsSize, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  LocksExcludedAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , Expr * *Args, unsigned ArgsSize
             );
  LocksExcludedAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  LocksExcludedAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  typedef Expr ** args_iterator;
  args_iterator args_begin() const { return args_; }
  args_iterator args_end() const { return args_ + args_Size; }
  unsigned args_size() const { return args_Size; }
  llvm::iterator_range<args_iterator> args() const { return llvm::make_range(args_begin(), args_end()); }




  static bool classof(const Attr *A) { return A->getKind() == attr::LocksExcluded; }
};

class LoopHintAttr : public Attr {
public:
  enum OptionType {
    Vectorize,
    VectorizeWidth,
    Interleave,
    InterleaveCount,
    Unroll,
    UnrollCount,
    UnrollAndJam,
    UnrollAndJamCount,
    PipelineDisabled,
    PipelineInitiationInterval,
    Distribute,
    VectorizePredicate
  };
private:
  OptionType option;

public:
  enum LoopHintState {
    Enable,
    Disable,
    Numeric,
    FixedWidth,
    ScalableWidth,
    AssumeSafety,
    Full
  };
private:
  LoopHintState state;

Expr * value;

public:
  enum Spelling {
    Pragma_clang_loop = 0,
    Pragma_unroll = 1,
    Pragma_nounroll = 2,
    Pragma_unroll_and_jam = 3,
    Pragma_nounroll_and_jam = 4,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static LoopHintAttr *CreateImplicit(ASTContext &Ctx, OptionType Option, LoopHintState State, Expr * Value, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static LoopHintAttr *Create(ASTContext &Ctx, OptionType Option, LoopHintState State, Expr * Value, const AttributeCommonInfo &CommonInfo);
  static LoopHintAttr *CreateImplicit(ASTContext &Ctx, OptionType Option, LoopHintState State, Expr * Value, SourceRange Range, AttributeCommonInfo::Syntax Syntax, LoopHintAttr::Spelling S = static_cast<Spelling>(SpellingNotCalculated));
  static LoopHintAttr *Create(ASTContext &Ctx, OptionType Option, LoopHintState State, Expr * Value, SourceRange Range, AttributeCommonInfo::Syntax Syntax, LoopHintAttr::Spelling S = static_cast<Spelling>(SpellingNotCalculated));

  // Constructors
  LoopHintAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , OptionType Option
              , LoopHintState State
              , Expr * Value
             );

  LoopHintAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  Spelling getSemanticSpelling() const;
  OptionType getOption() const {
    return option;
  }

  static bool ConvertStrToOptionType(StringRef Val, OptionType &Out);
  static const char *ConvertOptionTypeToStr(OptionType Val);
  LoopHintState getState() const {
    return state;
  }

  static bool ConvertStrToLoopHintState(StringRef Val, LoopHintState &Out);
  static const char *ConvertLoopHintStateToStr(LoopHintState Val);
  Expr * getValue() const {
    return value;
  }


  static const char *getOptionName(int Option) {
    switch(Option) {
    case Vectorize: return "vectorize";
    case VectorizeWidth: return "vectorize_width";
    case Interleave: return "interleave";
    case InterleaveCount: return "interleave_count";
    case Unroll: return "unroll";
    case UnrollCount: return "unroll_count";
    case UnrollAndJam: return "unroll_and_jam";
    case UnrollAndJamCount: return "unroll_and_jam_count";
    case PipelineDisabled: return "pipeline";
    case PipelineInitiationInterval: return "pipeline_initiation_interval";
    case Distribute: return "distribute";
    case VectorizePredicate: return "vectorize_predicate";
    }
    llvm_unreachable("Unhandled LoopHint option.");
  }

  void printPrettyPragma(raw_ostream &OS, const PrintingPolicy &Policy) const;

  // Return a string containing the loop hint argument including the
  // enclosing parentheses.
  std::string getValueString(const PrintingPolicy &Policy) const;

  // Return a string suitable for identifying this attribute in diagnostics.
  std::string getDiagnosticName(const PrintingPolicy &Policy) const;
  

  static bool classof(const Attr *A) { return A->getKind() == attr::LoopHint; }
};

class M68kInterruptAttr : public InheritableAttr {
unsigned number;

public:
  // Factory methods
  static M68kInterruptAttr *CreateImplicit(ASTContext &Ctx, unsigned Number, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static M68kInterruptAttr *Create(ASTContext &Ctx, unsigned Number, const AttributeCommonInfo &CommonInfo);
  static M68kInterruptAttr *CreateImplicit(ASTContext &Ctx, unsigned Number, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static M68kInterruptAttr *Create(ASTContext &Ctx, unsigned Number, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  M68kInterruptAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , unsigned Number
             );

  M68kInterruptAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  unsigned getNumber() const {
    return number;
  }



  static bool classof(const Attr *A) { return A->getKind() == attr::M68kInterrupt; }
};

class MIGServerRoutineAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_mig_server_routine = 0,
    CXX11_clang_mig_server_routine = 1,
    C2x_clang_mig_server_routine = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static MIGServerRoutineAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static MIGServerRoutineAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static MIGServerRoutineAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static MIGServerRoutineAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  MIGServerRoutineAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  MIGServerRoutineAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::MIGServerRoutine; }
};

class MSABIAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_ms_abi = 0,
    CXX11_gnu_ms_abi = 1,
    C2x_gnu_ms_abi = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static MSABIAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static MSABIAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static MSABIAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static MSABIAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  MSABIAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  MSABIAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::MSABI; }
};

class MSAllocatorAttr : public InheritableAttr {
public:
  // Factory methods
  static MSAllocatorAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static MSAllocatorAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static MSAllocatorAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static MSAllocatorAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  MSAllocatorAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  MSAllocatorAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::MSAllocator; }
};

class MSInheritanceAttr : public InheritableAttr {
bool bestCase;

public:
  enum Spelling {
    Keyword_single_inheritance = 0,
    Keyword_multiple_inheritance = 1,
    Keyword_virtual_inheritance = 2,
    Keyword_unspecified_inheritance = 3,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static MSInheritanceAttr *CreateImplicit(ASTContext &Ctx, bool BestCase, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static MSInheritanceAttr *Create(ASTContext &Ctx, bool BestCase, const AttributeCommonInfo &CommonInfo);
  static MSInheritanceAttr *CreateImplicit(ASTContext &Ctx, bool BestCase, SourceRange Range, AttributeCommonInfo::Syntax Syntax, MSInheritanceAttr::Spelling S = static_cast<Spelling>(SpellingNotCalculated));
  static MSInheritanceAttr *Create(ASTContext &Ctx, bool BestCase, SourceRange Range, AttributeCommonInfo::Syntax Syntax, MSInheritanceAttr::Spelling S = static_cast<Spelling>(SpellingNotCalculated));
  static MSInheritanceAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static MSInheritanceAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static MSInheritanceAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax, MSInheritanceAttr::Spelling S = static_cast<Spelling>(SpellingNotCalculated));
  static MSInheritanceAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax, MSInheritanceAttr::Spelling S = static_cast<Spelling>(SpellingNotCalculated));

  // Constructors
  MSInheritanceAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , bool BestCase
             );
  MSInheritanceAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  MSInheritanceAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  Spelling getSemanticSpelling() const;
  bool getBestCase() const {
    return bestCase;
  }

  static const bool DefaultBestCase = true;


  MSInheritanceModel getInheritanceModel() const {
    // The spelling enum should agree with MSInheritanceModel.
    return MSInheritanceModel(getSemanticSpelling());
  }
  

  static bool classof(const Attr *A) { return A->getKind() == attr::MSInheritance; }
};

class MSNoVTableAttr : public InheritableAttr {
public:
  // Factory methods
  static MSNoVTableAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static MSNoVTableAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static MSNoVTableAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static MSNoVTableAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  MSNoVTableAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  MSNoVTableAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::MSNoVTable; }
};

class MSP430InterruptAttr : public InheritableAttr {
unsigned number;

public:
  enum Spelling {
    GNU_interrupt = 0,
    CXX11_gnu_interrupt = 1,
    C2x_gnu_interrupt = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static MSP430InterruptAttr *CreateImplicit(ASTContext &Ctx, unsigned Number, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static MSP430InterruptAttr *Create(ASTContext &Ctx, unsigned Number, const AttributeCommonInfo &CommonInfo);
  static MSP430InterruptAttr *CreateImplicit(ASTContext &Ctx, unsigned Number, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static MSP430InterruptAttr *Create(ASTContext &Ctx, unsigned Number, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  MSP430InterruptAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , unsigned Number
             );

  MSP430InterruptAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  unsigned getNumber() const {
    return number;
  }



  static bool classof(const Attr *A) { return A->getKind() == attr::MSP430Interrupt; }
};

class MSStructAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_ms_struct = 0,
    CXX11_gnu_ms_struct = 1,
    C2x_gnu_ms_struct = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static MSStructAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static MSStructAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static MSStructAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static MSStructAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  MSStructAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  MSStructAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::MSStruct; }
};

class MSVtorDispAttr : public InheritableAttr {
unsigned vdm;

public:
  // Factory methods
  static MSVtorDispAttr *CreateImplicit(ASTContext &Ctx, unsigned Vdm, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static MSVtorDispAttr *Create(ASTContext &Ctx, unsigned Vdm, const AttributeCommonInfo &CommonInfo);
  static MSVtorDispAttr *CreateImplicit(ASTContext &Ctx, unsigned Vdm, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static MSVtorDispAttr *Create(ASTContext &Ctx, unsigned Vdm, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  MSVtorDispAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , unsigned Vdm
             );

  MSVtorDispAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  unsigned getVdm() const {
    return vdm;
  }


  MSVtorDispMode getVtorDispMode() const { return MSVtorDispMode(vdm); }
  

  static bool classof(const Attr *A) { return A->getKind() == attr::MSVtorDisp; }
};

class MaxFieldAlignmentAttr : public InheritableAttr {
unsigned alignment;

public:
  // Factory methods
  static MaxFieldAlignmentAttr *CreateImplicit(ASTContext &Ctx, unsigned Alignment, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static MaxFieldAlignmentAttr *Create(ASTContext &Ctx, unsigned Alignment, const AttributeCommonInfo &CommonInfo);
  static MaxFieldAlignmentAttr *CreateImplicit(ASTContext &Ctx, unsigned Alignment, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static MaxFieldAlignmentAttr *Create(ASTContext &Ctx, unsigned Alignment, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  MaxFieldAlignmentAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , unsigned Alignment
             );

  MaxFieldAlignmentAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  unsigned getAlignment() const {
    return alignment;
  }



  static bool classof(const Attr *A) { return A->getKind() == attr::MaxFieldAlignment; }
};

class MayAliasAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_may_alias = 0,
    CXX11_gnu_may_alias = 1,
    C2x_gnu_may_alias = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static MayAliasAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static MayAliasAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static MayAliasAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static MayAliasAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  MayAliasAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  MayAliasAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::MayAlias; }
};

class MicroMipsAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_micromips = 0,
    CXX11_gnu_micromips = 1,
    C2x_gnu_micromips = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static MicroMipsAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static MicroMipsAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static MicroMipsAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static MicroMipsAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  MicroMipsAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  MicroMipsAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::MicroMips; }
};

class MinSizeAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_minsize = 0,
    CXX11_clang_minsize = 1,
    C2x_clang_minsize = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static MinSizeAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static MinSizeAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static MinSizeAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static MinSizeAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  MinSizeAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  MinSizeAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::MinSize; }
};

class MinVectorWidthAttr : public InheritableAttr {
unsigned vectorWidth;

public:
  enum Spelling {
    GNU_min_vector_width = 0,
    CXX11_clang_min_vector_width = 1,
    C2x_clang_min_vector_width = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static MinVectorWidthAttr *CreateImplicit(ASTContext &Ctx, unsigned VectorWidth, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static MinVectorWidthAttr *Create(ASTContext &Ctx, unsigned VectorWidth, const AttributeCommonInfo &CommonInfo);
  static MinVectorWidthAttr *CreateImplicit(ASTContext &Ctx, unsigned VectorWidth, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static MinVectorWidthAttr *Create(ASTContext &Ctx, unsigned VectorWidth, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  MinVectorWidthAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , unsigned VectorWidth
             );

  MinVectorWidthAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  unsigned getVectorWidth() const {
    return vectorWidth;
  }



  static bool classof(const Attr *A) { return A->getKind() == attr::MinVectorWidth; }
};

class Mips16Attr : public InheritableAttr {
public:
  enum Spelling {
    GNU_mips16 = 0,
    CXX11_gnu_mips16 = 1,
    C2x_gnu_mips16 = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static Mips16Attr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static Mips16Attr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static Mips16Attr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static Mips16Attr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  Mips16Attr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  Mips16Attr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::Mips16; }
};

class MipsInterruptAttr : public InheritableAttr {
public:
  enum InterruptType {
    sw0,
    sw1,
    hw0,
    hw1,
    hw2,
    hw3,
    hw4,
    hw5,
    eic
  };
private:
  InterruptType interrupt;

public:
  enum Spelling {
    GNU_interrupt = 0,
    CXX11_gnu_interrupt = 1,
    C2x_gnu_interrupt = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static MipsInterruptAttr *CreateImplicit(ASTContext &Ctx, InterruptType Interrupt, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static MipsInterruptAttr *Create(ASTContext &Ctx, InterruptType Interrupt, const AttributeCommonInfo &CommonInfo);
  static MipsInterruptAttr *CreateImplicit(ASTContext &Ctx, InterruptType Interrupt, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static MipsInterruptAttr *Create(ASTContext &Ctx, InterruptType Interrupt, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  MipsInterruptAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , InterruptType Interrupt
             );

  MipsInterruptAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  InterruptType getInterrupt() const {
    return interrupt;
  }

  static bool ConvertStrToInterruptType(StringRef Val, InterruptType &Out);
  static const char *ConvertInterruptTypeToStr(InterruptType Val);


  static bool classof(const Attr *A) { return A->getKind() == attr::MipsInterrupt; }
};

class MipsLongCallAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_long_call = 0,
    CXX11_gnu_long_call = 1,
    C2x_gnu_long_call = 2,
    GNU_far = 3,
    CXX11_gnu_far = 4,
    C2x_gnu_far = 5,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static MipsLongCallAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static MipsLongCallAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static MipsLongCallAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax, MipsLongCallAttr::Spelling S = static_cast<Spelling>(SpellingNotCalculated));
  static MipsLongCallAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax, MipsLongCallAttr::Spelling S = static_cast<Spelling>(SpellingNotCalculated));

  // Constructors
  MipsLongCallAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  MipsLongCallAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  Spelling getSemanticSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::MipsLongCall; }
};

class MipsShortCallAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_short_call = 0,
    CXX11_gnu_short_call = 1,
    C2x_gnu_short_call = 2,
    GNU_near = 3,
    CXX11_gnu_near = 4,
    C2x_gnu_near = 5,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static MipsShortCallAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static MipsShortCallAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static MipsShortCallAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax, MipsShortCallAttr::Spelling S = static_cast<Spelling>(SpellingNotCalculated));
  static MipsShortCallAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax, MipsShortCallAttr::Spelling S = static_cast<Spelling>(SpellingNotCalculated));

  // Constructors
  MipsShortCallAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  MipsShortCallAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  Spelling getSemanticSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::MipsShortCall; }
};

class ModeAttr : public Attr {
IdentifierInfo * mode;

public:
  enum Spelling {
    GNU_mode = 0,
    CXX11_gnu_mode = 1,
    C2x_gnu_mode = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static ModeAttr *CreateImplicit(ASTContext &Ctx, IdentifierInfo * Mode, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static ModeAttr *Create(ASTContext &Ctx, IdentifierInfo * Mode, const AttributeCommonInfo &CommonInfo);
  static ModeAttr *CreateImplicit(ASTContext &Ctx, IdentifierInfo * Mode, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static ModeAttr *Create(ASTContext &Ctx, IdentifierInfo * Mode, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  ModeAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , IdentifierInfo * Mode
             );

  ModeAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  IdentifierInfo * getMode() const {
    return mode;
  }



  static bool classof(const Attr *A) { return A->getKind() == attr::Mode; }
};

class MustTailAttr : public StmtAttr {
public:
  enum Spelling {
    GNU_musttail = 0,
    CXX11_clang_musttail = 1,
    C2x_clang_musttail = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static MustTailAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static MustTailAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static MustTailAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static MustTailAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  MustTailAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  MustTailAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::MustTail; }
};

class NSConsumedAttr : public InheritableParamAttr {
public:
  enum Spelling {
    GNU_ns_consumed = 0,
    CXX11_clang_ns_consumed = 1,
    C2x_clang_ns_consumed = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static NSConsumedAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static NSConsumedAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static NSConsumedAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static NSConsumedAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  NSConsumedAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  NSConsumedAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::NSConsumed; }
};

class NSConsumesSelfAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_ns_consumes_self = 0,
    CXX11_clang_ns_consumes_self = 1,
    C2x_clang_ns_consumes_self = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static NSConsumesSelfAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static NSConsumesSelfAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static NSConsumesSelfAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static NSConsumesSelfAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  NSConsumesSelfAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  NSConsumesSelfAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::NSConsumesSelf; }
};

class NSErrorDomainAttr : public InheritableAttr {
VarDecl * errorDomain;

public:
  // Factory methods
  static NSErrorDomainAttr *CreateImplicit(ASTContext &Ctx, VarDecl * ErrorDomain, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static NSErrorDomainAttr *Create(ASTContext &Ctx, VarDecl * ErrorDomain, const AttributeCommonInfo &CommonInfo);
  static NSErrorDomainAttr *CreateImplicit(ASTContext &Ctx, VarDecl * ErrorDomain, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static NSErrorDomainAttr *Create(ASTContext &Ctx, VarDecl * ErrorDomain, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  NSErrorDomainAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , VarDecl * ErrorDomain
             );

  NSErrorDomainAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  VarDecl * getErrorDomain() const {
    return errorDomain;
  }



  static bool classof(const Attr *A) { return A->getKind() == attr::NSErrorDomain; }
};

class NSReturnsAutoreleasedAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_ns_returns_autoreleased = 0,
    CXX11_clang_ns_returns_autoreleased = 1,
    C2x_clang_ns_returns_autoreleased = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static NSReturnsAutoreleasedAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static NSReturnsAutoreleasedAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static NSReturnsAutoreleasedAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static NSReturnsAutoreleasedAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  NSReturnsAutoreleasedAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  NSReturnsAutoreleasedAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::NSReturnsAutoreleased; }
};

class NSReturnsNotRetainedAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_ns_returns_not_retained = 0,
    CXX11_clang_ns_returns_not_retained = 1,
    C2x_clang_ns_returns_not_retained = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static NSReturnsNotRetainedAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static NSReturnsNotRetainedAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static NSReturnsNotRetainedAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static NSReturnsNotRetainedAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  NSReturnsNotRetainedAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  NSReturnsNotRetainedAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::NSReturnsNotRetained; }
};

class NSReturnsRetainedAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_ns_returns_retained = 0,
    CXX11_clang_ns_returns_retained = 1,
    C2x_clang_ns_returns_retained = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static NSReturnsRetainedAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static NSReturnsRetainedAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static NSReturnsRetainedAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static NSReturnsRetainedAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  NSReturnsRetainedAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  NSReturnsRetainedAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::NSReturnsRetained; }
};

class NakedAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_naked = 0,
    CXX11_gnu_naked = 1,
    C2x_gnu_naked = 2,
    Declspec_naked = 3,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static NakedAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static NakedAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static NakedAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static NakedAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  NakedAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  NakedAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::Naked; }
};

class NoAliasAttr : public InheritableAttr {
public:
  // Factory methods
  static NoAliasAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static NoAliasAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static NoAliasAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static NoAliasAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  NoAliasAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  NoAliasAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::NoAlias; }
};

class NoBuiltinAttr : public Attr {
  unsigned builtinNames_Size;
  StringRef *builtinNames_;

public:
  enum Spelling {
    GNU_no_builtin = 0,
    CXX11_clang_no_builtin = 1,
    C2x_clang_no_builtin = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static NoBuiltinAttr *CreateImplicit(ASTContext &Ctx, StringRef *BuiltinNames, unsigned BuiltinNamesSize, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static NoBuiltinAttr *Create(ASTContext &Ctx, StringRef *BuiltinNames, unsigned BuiltinNamesSize, const AttributeCommonInfo &CommonInfo);
  static NoBuiltinAttr *CreateImplicit(ASTContext &Ctx, StringRef *BuiltinNames, unsigned BuiltinNamesSize, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static NoBuiltinAttr *Create(ASTContext &Ctx, StringRef *BuiltinNames, unsigned BuiltinNamesSize, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  NoBuiltinAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , StringRef *BuiltinNames, unsigned BuiltinNamesSize
             );
  NoBuiltinAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  NoBuiltinAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  typedef StringRef* builtinNames_iterator;
  builtinNames_iterator builtinNames_begin() const { return builtinNames_; }
  builtinNames_iterator builtinNames_end() const { return builtinNames_ + builtinNames_Size; }
  unsigned builtinNames_size() const { return builtinNames_Size; }
  llvm::iterator_range<builtinNames_iterator> builtinNames() const { return llvm::make_range(builtinNames_begin(), builtinNames_end()); }




  static bool classof(const Attr *A) { return A->getKind() == attr::NoBuiltin; }
};

class NoCommonAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_nocommon = 0,
    CXX11_gnu_nocommon = 1,
    C2x_gnu_nocommon = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static NoCommonAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static NoCommonAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static NoCommonAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static NoCommonAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  NoCommonAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  NoCommonAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::NoCommon; }
};

class NoDebugAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_nodebug = 0,
    CXX11_gnu_nodebug = 1,
    C2x_gnu_nodebug = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static NoDebugAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static NoDebugAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static NoDebugAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static NoDebugAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  NoDebugAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  NoDebugAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::NoDebug; }
};

class NoDerefAttr : public TypeAttr {
public:
  enum Spelling {
    GNU_noderef = 0,
    CXX11_clang_noderef = 1,
    C2x_clang_noderef = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static NoDerefAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static NoDerefAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static NoDerefAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static NoDerefAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  NoDerefAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  NoDerefAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::NoDeref; }
};

class NoDestroyAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_no_destroy = 0,
    CXX11_clang_no_destroy = 1,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static NoDestroyAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static NoDestroyAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static NoDestroyAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static NoDestroyAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  NoDestroyAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  NoDestroyAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::NoDestroy; }
};

class NoDuplicateAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_noduplicate = 0,
    CXX11_clang_noduplicate = 1,
    C2x_clang_noduplicate = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static NoDuplicateAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static NoDuplicateAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static NoDuplicateAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static NoDuplicateAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  NoDuplicateAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  NoDuplicateAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::NoDuplicate; }
};

class NoEscapeAttr : public Attr {
public:
  enum Spelling {
    GNU_noescape = 0,
    CXX11_clang_noescape = 1,
    C2x_clang_noescape = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static NoEscapeAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static NoEscapeAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static NoEscapeAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static NoEscapeAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  NoEscapeAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  NoEscapeAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::NoEscape; }
};

class NoInlineAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_noinline = 0,
    CXX11_gnu_noinline = 1,
    C2x_gnu_noinline = 2,
    Declspec_noinline = 3,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static NoInlineAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static NoInlineAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static NoInlineAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static NoInlineAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  NoInlineAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  NoInlineAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::NoInline; }
};

class NoInstrumentFunctionAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_no_instrument_function = 0,
    CXX11_gnu_no_instrument_function = 1,
    C2x_gnu_no_instrument_function = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static NoInstrumentFunctionAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static NoInstrumentFunctionAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static NoInstrumentFunctionAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static NoInstrumentFunctionAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  NoInstrumentFunctionAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  NoInstrumentFunctionAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::NoInstrumentFunction; }
};

class NoMergeAttr : public DeclOrStmtAttr {
public:
  enum Spelling {
    GNU_nomerge = 0,
    CXX11_clang_nomerge = 1,
    C2x_clang_nomerge = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static NoMergeAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static NoMergeAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static NoMergeAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static NoMergeAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  NoMergeAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  NoMergeAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::NoMerge; }
};

class NoMicroMipsAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_nomicromips = 0,
    CXX11_gnu_nomicromips = 1,
    C2x_gnu_nomicromips = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static NoMicroMipsAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static NoMicroMipsAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static NoMicroMipsAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static NoMicroMipsAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  NoMicroMipsAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  NoMicroMipsAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::NoMicroMips; }
};

class NoMips16Attr : public InheritableAttr {
public:
  enum Spelling {
    GNU_nomips16 = 0,
    CXX11_gnu_nomips16 = 1,
    C2x_gnu_nomips16 = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static NoMips16Attr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static NoMips16Attr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static NoMips16Attr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static NoMips16Attr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  NoMips16Attr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  NoMips16Attr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::NoMips16; }
};

class NoProfileFunctionAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_no_profile_instrument_function = 0,
    CXX11_gnu_no_profile_instrument_function = 1,
    C2x_gnu_no_profile_instrument_function = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static NoProfileFunctionAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static NoProfileFunctionAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static NoProfileFunctionAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static NoProfileFunctionAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  NoProfileFunctionAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  NoProfileFunctionAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::NoProfileFunction; }
};

class NoReturnAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_noreturn = 0,
    CXX11_gnu_noreturn = 1,
    C2x_gnu_noreturn = 2,
    Declspec_noreturn = 3,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static NoReturnAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static NoReturnAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static NoReturnAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static NoReturnAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  NoReturnAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  NoReturnAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::NoReturn; }
};

class NoSanitizeAttr : public InheritableAttr {
  unsigned sanitizers_Size;
  StringRef *sanitizers_;

public:
  enum Spelling {
    GNU_no_sanitize = 0,
    CXX11_clang_no_sanitize = 1,
    C2x_clang_no_sanitize = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static NoSanitizeAttr *CreateImplicit(ASTContext &Ctx, StringRef *Sanitizers, unsigned SanitizersSize, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static NoSanitizeAttr *Create(ASTContext &Ctx, StringRef *Sanitizers, unsigned SanitizersSize, const AttributeCommonInfo &CommonInfo);
  static NoSanitizeAttr *CreateImplicit(ASTContext &Ctx, StringRef *Sanitizers, unsigned SanitizersSize, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static NoSanitizeAttr *Create(ASTContext &Ctx, StringRef *Sanitizers, unsigned SanitizersSize, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  NoSanitizeAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , StringRef *Sanitizers, unsigned SanitizersSize
             );
  NoSanitizeAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  NoSanitizeAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  typedef StringRef* sanitizers_iterator;
  sanitizers_iterator sanitizers_begin() const { return sanitizers_; }
  sanitizers_iterator sanitizers_end() const { return sanitizers_ + sanitizers_Size; }
  unsigned sanitizers_size() const { return sanitizers_Size; }
  llvm::iterator_range<sanitizers_iterator> sanitizers() const { return llvm::make_range(sanitizers_begin(), sanitizers_end()); }



    SanitizerMask getMask() const {
      SanitizerMask Mask;
      for (auto SanitizerName : sanitizers()) {
        SanitizerMask ParsedMask =
            parseSanitizerValue(SanitizerName, /*AllowGroups=*/true);
        Mask |= expandSanitizerGroups(ParsedMask);
      }
      return Mask;
    }

    bool hasCoverage() const {
      return llvm::is_contained(sanitizers(), "coverage");
    }
  

  static bool classof(const Attr *A) { return A->getKind() == attr::NoSanitize; }
};

class NoSpeculativeLoadHardeningAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_no_speculative_load_hardening = 0,
    CXX11_clang_no_speculative_load_hardening = 1,
    C2x_clang_no_speculative_load_hardening = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static NoSpeculativeLoadHardeningAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static NoSpeculativeLoadHardeningAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static NoSpeculativeLoadHardeningAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static NoSpeculativeLoadHardeningAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  NoSpeculativeLoadHardeningAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  NoSpeculativeLoadHardeningAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::NoSpeculativeLoadHardening; }
};

class NoSplitStackAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_no_split_stack = 0,
    CXX11_gnu_no_split_stack = 1,
    C2x_gnu_no_split_stack = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static NoSplitStackAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static NoSplitStackAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static NoSplitStackAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static NoSplitStackAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  NoSplitStackAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  NoSplitStackAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::NoSplitStack; }
};

class NoStackProtectorAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_no_stack_protector = 0,
    CXX11_clang_no_stack_protector = 1,
    C2x_clang_no_stack_protector = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static NoStackProtectorAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static NoStackProtectorAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static NoStackProtectorAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static NoStackProtectorAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  NoStackProtectorAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  NoStackProtectorAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::NoStackProtector; }
};

class NoThreadSafetyAnalysisAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_no_thread_safety_analysis = 0,
    CXX11_clang_no_thread_safety_analysis = 1,
    C2x_clang_no_thread_safety_analysis = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static NoThreadSafetyAnalysisAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static NoThreadSafetyAnalysisAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static NoThreadSafetyAnalysisAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static NoThreadSafetyAnalysisAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  NoThreadSafetyAnalysisAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  NoThreadSafetyAnalysisAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::NoThreadSafetyAnalysis; }
};

class NoThrowAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_nothrow = 0,
    CXX11_gnu_nothrow = 1,
    C2x_gnu_nothrow = 2,
    Declspec_nothrow = 3,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static NoThrowAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static NoThrowAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static NoThrowAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static NoThrowAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  NoThrowAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  NoThrowAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::NoThrow; }
};

class NoUniqueAddressAttr : public InheritableAttr {
public:
  // Factory methods
  static NoUniqueAddressAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static NoUniqueAddressAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static NoUniqueAddressAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static NoUniqueAddressAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  NoUniqueAddressAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  NoUniqueAddressAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::NoUniqueAddress; }
};

class NonNullAttr : public InheritableParamAttr {
  unsigned args_Size;
  ParamIdx *args_;

public:
  enum Spelling {
    GNU_nonnull = 0,
    CXX11_gnu_nonnull = 1,
    C2x_gnu_nonnull = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static NonNullAttr *CreateImplicit(ASTContext &Ctx, ParamIdx *Args, unsigned ArgsSize, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static NonNullAttr *Create(ASTContext &Ctx, ParamIdx *Args, unsigned ArgsSize, const AttributeCommonInfo &CommonInfo);
  static NonNullAttr *CreateImplicit(ASTContext &Ctx, ParamIdx *Args, unsigned ArgsSize, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static NonNullAttr *Create(ASTContext &Ctx, ParamIdx *Args, unsigned ArgsSize, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  NonNullAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , ParamIdx *Args, unsigned ArgsSize
             );
  NonNullAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  NonNullAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  typedef ParamIdx* args_iterator;
  args_iterator args_begin() const { return args_; }
  args_iterator args_end() const { return args_ + args_Size; }
  unsigned args_size() const { return args_Size; }
  llvm::iterator_range<args_iterator> args() const { return llvm::make_range(args_begin(), args_end()); }



    bool isNonNull(unsigned IdxAST) const {
      if (!args_size())
        return true;
      return args_end() != std::find_if(
          args_begin(), args_end(),
          [=](const ParamIdx &Idx) { return Idx.getASTIndex() == IdxAST; });
    }
  

  static bool classof(const Attr *A) { return A->getKind() == attr::NonNull; }
};

class NotTailCalledAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_not_tail_called = 0,
    CXX11_clang_not_tail_called = 1,
    C2x_clang_not_tail_called = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static NotTailCalledAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static NotTailCalledAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static NotTailCalledAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static NotTailCalledAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  NotTailCalledAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  NotTailCalledAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::NotTailCalled; }
};

class OMPAllocateDeclAttr : public InheritableAttr {
public:
  enum AllocatorTypeTy {
    OMPNullMemAlloc,
    OMPDefaultMemAlloc,
    OMPLargeCapMemAlloc,
    OMPConstMemAlloc,
    OMPHighBWMemAlloc,
    OMPLowLatMemAlloc,
    OMPCGroupMemAlloc,
    OMPPTeamMemAlloc,
    OMPThreadMemAlloc,
    OMPUserDefinedMemAlloc
  };
private:
  AllocatorTypeTy allocatorType;

Expr * allocator;

Expr * alignment;

public:
  // Factory methods
  static OMPAllocateDeclAttr *CreateImplicit(ASTContext &Ctx, AllocatorTypeTy AllocatorType, Expr * Allocator, Expr * Alignment, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static OMPAllocateDeclAttr *Create(ASTContext &Ctx, AllocatorTypeTy AllocatorType, Expr * Allocator, Expr * Alignment, const AttributeCommonInfo &CommonInfo);
  static OMPAllocateDeclAttr *CreateImplicit(ASTContext &Ctx, AllocatorTypeTy AllocatorType, Expr * Allocator, Expr * Alignment, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static OMPAllocateDeclAttr *Create(ASTContext &Ctx, AllocatorTypeTy AllocatorType, Expr * Allocator, Expr * Alignment, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  OMPAllocateDeclAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , AllocatorTypeTy AllocatorType
              , Expr * Allocator
              , Expr * Alignment
             );

  OMPAllocateDeclAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  AllocatorTypeTy getAllocatorType() const {
    return allocatorType;
  }

  static bool ConvertStrToAllocatorTypeTy(StringRef Val, AllocatorTypeTy &Out);
  static const char *ConvertAllocatorTypeTyToStr(AllocatorTypeTy Val);
  Expr * getAllocator() const {
    return allocator;
  }

  Expr * getAlignment() const {
    return alignment;
  }



  static bool classof(const Attr *A) { return A->getKind() == attr::OMPAllocateDecl; }
};

class OMPCaptureKindAttr : public Attr {
unsigned captureKindVal;

public:
  // Factory methods
  static OMPCaptureKindAttr *CreateImplicit(ASTContext &Ctx, unsigned CaptureKindVal, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static OMPCaptureKindAttr *Create(ASTContext &Ctx, unsigned CaptureKindVal, const AttributeCommonInfo &CommonInfo);
  static OMPCaptureKindAttr *CreateImplicit(ASTContext &Ctx, unsigned CaptureKindVal, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static OMPCaptureKindAttr *Create(ASTContext &Ctx, unsigned CaptureKindVal, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  OMPCaptureKindAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , unsigned CaptureKindVal
             );

  OMPCaptureKindAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  unsigned getCaptureKindVal() const {
    return captureKindVal;
  }


    llvm::omp::Clause getCaptureKind() const {
      return static_cast<llvm::omp::Clause>(getCaptureKindVal());
    }
  

  static bool classof(const Attr *A) { return A->getKind() == attr::OMPCaptureKind; }
};

class OMPCaptureNoInitAttr : public InheritableAttr {
public:
  // Factory methods
  static OMPCaptureNoInitAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static OMPCaptureNoInitAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static OMPCaptureNoInitAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static OMPCaptureNoInitAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  OMPCaptureNoInitAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  OMPCaptureNoInitAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::OMPCaptureNoInit; }
};

class OMPDeclareSimdDeclAttr : public Attr {
public:
  enum BranchStateTy {
    BS_Undefined,
    BS_Inbranch,
    BS_Notinbranch
  };
private:
  BranchStateTy branchState;

Expr * simdlen;

  unsigned uniforms_Size;
  Expr * *uniforms_;

  unsigned aligneds_Size;
  Expr * *aligneds_;

  unsigned alignments_Size;
  Expr * *alignments_;

  unsigned linears_Size;
  Expr * *linears_;

  unsigned modifiers_Size;
  unsigned *modifiers_;

  unsigned steps_Size;
  Expr * *steps_;

public:
  // Factory methods
  static OMPDeclareSimdDeclAttr *CreateImplicit(ASTContext &Ctx, BranchStateTy BranchState, Expr * Simdlen, Expr * *Uniforms, unsigned UniformsSize, Expr * *Aligneds, unsigned AlignedsSize, Expr * *Alignments, unsigned AlignmentsSize, Expr * *Linears, unsigned LinearsSize, unsigned *Modifiers, unsigned ModifiersSize, Expr * *Steps, unsigned StepsSize, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static OMPDeclareSimdDeclAttr *Create(ASTContext &Ctx, BranchStateTy BranchState, Expr * Simdlen, Expr * *Uniforms, unsigned UniformsSize, Expr * *Aligneds, unsigned AlignedsSize, Expr * *Alignments, unsigned AlignmentsSize, Expr * *Linears, unsigned LinearsSize, unsigned *Modifiers, unsigned ModifiersSize, Expr * *Steps, unsigned StepsSize, const AttributeCommonInfo &CommonInfo);
  static OMPDeclareSimdDeclAttr *CreateImplicit(ASTContext &Ctx, BranchStateTy BranchState, Expr * Simdlen, Expr * *Uniforms, unsigned UniformsSize, Expr * *Aligneds, unsigned AlignedsSize, Expr * *Alignments, unsigned AlignmentsSize, Expr * *Linears, unsigned LinearsSize, unsigned *Modifiers, unsigned ModifiersSize, Expr * *Steps, unsigned StepsSize, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static OMPDeclareSimdDeclAttr *Create(ASTContext &Ctx, BranchStateTy BranchState, Expr * Simdlen, Expr * *Uniforms, unsigned UniformsSize, Expr * *Aligneds, unsigned AlignedsSize, Expr * *Alignments, unsigned AlignmentsSize, Expr * *Linears, unsigned LinearsSize, unsigned *Modifiers, unsigned ModifiersSize, Expr * *Steps, unsigned StepsSize, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  OMPDeclareSimdDeclAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , BranchStateTy BranchState
              , Expr * Simdlen
              , Expr * *Uniforms, unsigned UniformsSize
              , Expr * *Aligneds, unsigned AlignedsSize
              , Expr * *Alignments, unsigned AlignmentsSize
              , Expr * *Linears, unsigned LinearsSize
              , unsigned *Modifiers, unsigned ModifiersSize
              , Expr * *Steps, unsigned StepsSize
             );
  OMPDeclareSimdDeclAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , BranchStateTy BranchState
              , Expr * Simdlen
             );

  OMPDeclareSimdDeclAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  BranchStateTy getBranchState() const {
    return branchState;
  }

  static bool ConvertStrToBranchStateTy(StringRef Val, BranchStateTy &Out);
  static const char *ConvertBranchStateTyToStr(BranchStateTy Val);
  Expr * getSimdlen() const {
    return simdlen;
  }

  typedef Expr ** uniforms_iterator;
  uniforms_iterator uniforms_begin() const { return uniforms_; }
  uniforms_iterator uniforms_end() const { return uniforms_ + uniforms_Size; }
  unsigned uniforms_size() const { return uniforms_Size; }
  llvm::iterator_range<uniforms_iterator> uniforms() const { return llvm::make_range(uniforms_begin(), uniforms_end()); }


  typedef Expr ** aligneds_iterator;
  aligneds_iterator aligneds_begin() const { return aligneds_; }
  aligneds_iterator aligneds_end() const { return aligneds_ + aligneds_Size; }
  unsigned aligneds_size() const { return aligneds_Size; }
  llvm::iterator_range<aligneds_iterator> aligneds() const { return llvm::make_range(aligneds_begin(), aligneds_end()); }


  typedef Expr ** alignments_iterator;
  alignments_iterator alignments_begin() const { return alignments_; }
  alignments_iterator alignments_end() const { return alignments_ + alignments_Size; }
  unsigned alignments_size() const { return alignments_Size; }
  llvm::iterator_range<alignments_iterator> alignments() const { return llvm::make_range(alignments_begin(), alignments_end()); }


  typedef Expr ** linears_iterator;
  linears_iterator linears_begin() const { return linears_; }
  linears_iterator linears_end() const { return linears_ + linears_Size; }
  unsigned linears_size() const { return linears_Size; }
  llvm::iterator_range<linears_iterator> linears() const { return llvm::make_range(linears_begin(), linears_end()); }


  typedef unsigned* modifiers_iterator;
  modifiers_iterator modifiers_begin() const { return modifiers_; }
  modifiers_iterator modifiers_end() const { return modifiers_ + modifiers_Size; }
  unsigned modifiers_size() const { return modifiers_Size; }
  llvm::iterator_range<modifiers_iterator> modifiers() const { return llvm::make_range(modifiers_begin(), modifiers_end()); }


  typedef Expr ** steps_iterator;
  steps_iterator steps_begin() const { return steps_; }
  steps_iterator steps_end() const { return steps_ + steps_Size; }
  unsigned steps_size() const { return steps_Size; }
  llvm::iterator_range<steps_iterator> steps() const { return llvm::make_range(steps_begin(), steps_end()); }



    void printPrettyPragma(raw_ostream & OS, const PrintingPolicy &Policy)
        const;
  

  static bool classof(const Attr *A) { return A->getKind() == attr::OMPDeclareSimdDecl; }
};

class OMPDeclareTargetDeclAttr : public InheritableAttr {
public:
  enum MapTypeTy {
    MT_To,
    MT_Link
  };
private:
  MapTypeTy mapType;

public:
  enum DevTypeTy {
    DT_Host,
    DT_NoHost,
    DT_Any
  };
private:
  DevTypeTy devType;

unsigned level;

public:
  // Factory methods
  static OMPDeclareTargetDeclAttr *CreateImplicit(ASTContext &Ctx, MapTypeTy MapType, DevTypeTy DevType, unsigned Level, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static OMPDeclareTargetDeclAttr *Create(ASTContext &Ctx, MapTypeTy MapType, DevTypeTy DevType, unsigned Level, const AttributeCommonInfo &CommonInfo);
  static OMPDeclareTargetDeclAttr *CreateImplicit(ASTContext &Ctx, MapTypeTy MapType, DevTypeTy DevType, unsigned Level, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static OMPDeclareTargetDeclAttr *Create(ASTContext &Ctx, MapTypeTy MapType, DevTypeTy DevType, unsigned Level, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  OMPDeclareTargetDeclAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , MapTypeTy MapType
              , DevTypeTy DevType
              , unsigned Level
             );

  OMPDeclareTargetDeclAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  MapTypeTy getMapType() const {
    return mapType;
  }

  static bool ConvertStrToMapTypeTy(StringRef Val, MapTypeTy &Out);
  static const char *ConvertMapTypeTyToStr(MapTypeTy Val);
  DevTypeTy getDevType() const {
    return devType;
  }

  static bool ConvertStrToDevTypeTy(StringRef Val, DevTypeTy &Out);
  static const char *ConvertDevTypeTyToStr(DevTypeTy Val);
  unsigned getLevel() const {
    return level;
  }


    void printPrettyPragma(raw_ostream &OS, const PrintingPolicy &Policy) const;
    static llvm::Optional<MapTypeTy>
    isDeclareTargetDeclaration(const ValueDecl *VD);
    static llvm::Optional<OMPDeclareTargetDeclAttr*> getActiveAttr(const ValueDecl *VD);
    static llvm::Optional<DevTypeTy> getDeviceType(const ValueDecl *VD);
    static llvm::Optional<SourceLocation> getLocation(const ValueDecl *VD);
  

  static bool classof(const Attr *A) { return A->getKind() == attr::OMPDeclareTargetDecl; }
};

class OMPDeclareVariantAttr : public InheritableAttr {
Expr * variantFuncRef;

OMPTraitInfo * traitInfos;

  unsigned adjustArgsNothing_Size;
  Expr * *adjustArgsNothing_;

  unsigned adjustArgsNeedDevicePtr_Size;
  Expr * *adjustArgsNeedDevicePtr_;

public:
  enum InteropType {
    Target,
    TargetSync,
    Target_TargetSync
  };
private:
  unsigned appendArgs_Size;
  InteropType *appendArgs_;

public:
  // Factory methods
  static OMPDeclareVariantAttr *CreateImplicit(ASTContext &Ctx, Expr * VariantFuncRef, OMPTraitInfo * TraitInfos, Expr * *AdjustArgsNothing, unsigned AdjustArgsNothingSize, Expr * *AdjustArgsNeedDevicePtr, unsigned AdjustArgsNeedDevicePtrSize, InteropType *AppendArgs, unsigned AppendArgsSize, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static OMPDeclareVariantAttr *Create(ASTContext &Ctx, Expr * VariantFuncRef, OMPTraitInfo * TraitInfos, Expr * *AdjustArgsNothing, unsigned AdjustArgsNothingSize, Expr * *AdjustArgsNeedDevicePtr, unsigned AdjustArgsNeedDevicePtrSize, InteropType *AppendArgs, unsigned AppendArgsSize, const AttributeCommonInfo &CommonInfo);
  static OMPDeclareVariantAttr *CreateImplicit(ASTContext &Ctx, Expr * VariantFuncRef, OMPTraitInfo * TraitInfos, Expr * *AdjustArgsNothing, unsigned AdjustArgsNothingSize, Expr * *AdjustArgsNeedDevicePtr, unsigned AdjustArgsNeedDevicePtrSize, InteropType *AppendArgs, unsigned AppendArgsSize, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static OMPDeclareVariantAttr *Create(ASTContext &Ctx, Expr * VariantFuncRef, OMPTraitInfo * TraitInfos, Expr * *AdjustArgsNothing, unsigned AdjustArgsNothingSize, Expr * *AdjustArgsNeedDevicePtr, unsigned AdjustArgsNeedDevicePtrSize, InteropType *AppendArgs, unsigned AppendArgsSize, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  OMPDeclareVariantAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , Expr * VariantFuncRef
              , OMPTraitInfo * TraitInfos
              , Expr * *AdjustArgsNothing, unsigned AdjustArgsNothingSize
              , Expr * *AdjustArgsNeedDevicePtr, unsigned AdjustArgsNeedDevicePtrSize
              , InteropType *AppendArgs, unsigned AppendArgsSize
             );
  OMPDeclareVariantAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , Expr * VariantFuncRef
              , OMPTraitInfo * TraitInfos
             );

  OMPDeclareVariantAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  Expr * getVariantFuncRef() const {
    return variantFuncRef;
  }

  OMPTraitInfo * getTraitInfos() const {
    return traitInfos;
  }

  typedef Expr ** adjustArgsNothing_iterator;
  adjustArgsNothing_iterator adjustArgsNothing_begin() const { return adjustArgsNothing_; }
  adjustArgsNothing_iterator adjustArgsNothing_end() const { return adjustArgsNothing_ + adjustArgsNothing_Size; }
  unsigned adjustArgsNothing_size() const { return adjustArgsNothing_Size; }
  llvm::iterator_range<adjustArgsNothing_iterator> adjustArgsNothing() const { return llvm::make_range(adjustArgsNothing_begin(), adjustArgsNothing_end()); }


  typedef Expr ** adjustArgsNeedDevicePtr_iterator;
  adjustArgsNeedDevicePtr_iterator adjustArgsNeedDevicePtr_begin() const { return adjustArgsNeedDevicePtr_; }
  adjustArgsNeedDevicePtr_iterator adjustArgsNeedDevicePtr_end() const { return adjustArgsNeedDevicePtr_ + adjustArgsNeedDevicePtr_Size; }
  unsigned adjustArgsNeedDevicePtr_size() const { return adjustArgsNeedDevicePtr_Size; }
  llvm::iterator_range<adjustArgsNeedDevicePtr_iterator> adjustArgsNeedDevicePtr() const { return llvm::make_range(adjustArgsNeedDevicePtr_begin(), adjustArgsNeedDevicePtr_end()); }


  typedef InteropType* appendArgs_iterator;
  appendArgs_iterator appendArgs_begin() const { return appendArgs_; }
  appendArgs_iterator appendArgs_end() const { return appendArgs_ + appendArgs_Size; }
  unsigned appendArgs_size() const { return appendArgs_Size; }
  llvm::iterator_range<appendArgs_iterator> appendArgs() const { return llvm::make_range(appendArgs_begin(), appendArgs_end()); }


  static bool ConvertStrToInteropType(StringRef Val, InteropType &Out);
  static const char *ConvertInteropTypeToStr(InteropType Val);

    OMPTraitInfo &getTraitInfo() { return *traitInfos; }
    void printPrettyPragma(raw_ostream & OS, const PrintingPolicy &Policy)
        const;
  

  static bool classof(const Attr *A) { return A->getKind() == attr::OMPDeclareVariant; }
};

class OMPReferencedVarAttr : public Attr {
Expr * ref;

public:
  // Factory methods
  static OMPReferencedVarAttr *CreateImplicit(ASTContext &Ctx, Expr * Ref, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static OMPReferencedVarAttr *Create(ASTContext &Ctx, Expr * Ref, const AttributeCommonInfo &CommonInfo);
  static OMPReferencedVarAttr *CreateImplicit(ASTContext &Ctx, Expr * Ref, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static OMPReferencedVarAttr *Create(ASTContext &Ctx, Expr * Ref, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  OMPReferencedVarAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , Expr * Ref
             );

  OMPReferencedVarAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  Expr * getRef() const {
    return ref;
  }



  static bool classof(const Attr *A) { return A->getKind() == attr::OMPReferencedVar; }
};

class OMPThreadPrivateDeclAttr : public InheritableAttr {
public:
  // Factory methods
  static OMPThreadPrivateDeclAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static OMPThreadPrivateDeclAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static OMPThreadPrivateDeclAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static OMPThreadPrivateDeclAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  OMPThreadPrivateDeclAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  OMPThreadPrivateDeclAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::OMPThreadPrivateDecl; }
};

class OSConsumedAttr : public InheritableParamAttr {
public:
  enum Spelling {
    GNU_os_consumed = 0,
    CXX11_clang_os_consumed = 1,
    C2x_clang_os_consumed = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static OSConsumedAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static OSConsumedAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static OSConsumedAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static OSConsumedAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  OSConsumedAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  OSConsumedAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::OSConsumed; }
};

class OSConsumesThisAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_os_consumes_this = 0,
    CXX11_clang_os_consumes_this = 1,
    C2x_clang_os_consumes_this = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static OSConsumesThisAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static OSConsumesThisAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static OSConsumesThisAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static OSConsumesThisAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  OSConsumesThisAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  OSConsumesThisAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::OSConsumesThis; }
};

class OSReturnsNotRetainedAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_os_returns_not_retained = 0,
    CXX11_clang_os_returns_not_retained = 1,
    C2x_clang_os_returns_not_retained = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static OSReturnsNotRetainedAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static OSReturnsNotRetainedAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static OSReturnsNotRetainedAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static OSReturnsNotRetainedAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  OSReturnsNotRetainedAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  OSReturnsNotRetainedAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::OSReturnsNotRetained; }
};

class OSReturnsRetainedAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_os_returns_retained = 0,
    CXX11_clang_os_returns_retained = 1,
    C2x_clang_os_returns_retained = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static OSReturnsRetainedAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static OSReturnsRetainedAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static OSReturnsRetainedAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static OSReturnsRetainedAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  OSReturnsRetainedAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  OSReturnsRetainedAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::OSReturnsRetained; }
};

class OSReturnsRetainedOnNonZeroAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_os_returns_retained_on_non_zero = 0,
    CXX11_clang_os_returns_retained_on_non_zero = 1,
    C2x_clang_os_returns_retained_on_non_zero = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static OSReturnsRetainedOnNonZeroAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static OSReturnsRetainedOnNonZeroAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static OSReturnsRetainedOnNonZeroAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static OSReturnsRetainedOnNonZeroAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  OSReturnsRetainedOnNonZeroAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  OSReturnsRetainedOnNonZeroAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::OSReturnsRetainedOnNonZero; }
};

class OSReturnsRetainedOnZeroAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_os_returns_retained_on_zero = 0,
    CXX11_clang_os_returns_retained_on_zero = 1,
    C2x_clang_os_returns_retained_on_zero = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static OSReturnsRetainedOnZeroAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static OSReturnsRetainedOnZeroAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static OSReturnsRetainedOnZeroAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static OSReturnsRetainedOnZeroAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  OSReturnsRetainedOnZeroAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  OSReturnsRetainedOnZeroAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::OSReturnsRetainedOnZero; }
};

class ObjCBoxableAttr : public Attr {
public:
  enum Spelling {
    GNU_objc_boxable = 0,
    CXX11_clang_objc_boxable = 1,
    C2x_clang_objc_boxable = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static ObjCBoxableAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static ObjCBoxableAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static ObjCBoxableAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static ObjCBoxableAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  ObjCBoxableAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  ObjCBoxableAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::ObjCBoxable; }
};

class ObjCBridgeAttr : public InheritableAttr {
IdentifierInfo * bridgedType;

public:
  enum Spelling {
    GNU_objc_bridge = 0,
    CXX11_clang_objc_bridge = 1,
    C2x_clang_objc_bridge = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static ObjCBridgeAttr *CreateImplicit(ASTContext &Ctx, IdentifierInfo * BridgedType, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static ObjCBridgeAttr *Create(ASTContext &Ctx, IdentifierInfo * BridgedType, const AttributeCommonInfo &CommonInfo);
  static ObjCBridgeAttr *CreateImplicit(ASTContext &Ctx, IdentifierInfo * BridgedType, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static ObjCBridgeAttr *Create(ASTContext &Ctx, IdentifierInfo * BridgedType, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  ObjCBridgeAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , IdentifierInfo * BridgedType
             );

  ObjCBridgeAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  IdentifierInfo * getBridgedType() const {
    return bridgedType;
  }



  static bool classof(const Attr *A) { return A->getKind() == attr::ObjCBridge; }
};

class ObjCBridgeMutableAttr : public InheritableAttr {
IdentifierInfo * bridgedType;

public:
  enum Spelling {
    GNU_objc_bridge_mutable = 0,
    CXX11_clang_objc_bridge_mutable = 1,
    C2x_clang_objc_bridge_mutable = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static ObjCBridgeMutableAttr *CreateImplicit(ASTContext &Ctx, IdentifierInfo * BridgedType, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static ObjCBridgeMutableAttr *Create(ASTContext &Ctx, IdentifierInfo * BridgedType, const AttributeCommonInfo &CommonInfo);
  static ObjCBridgeMutableAttr *CreateImplicit(ASTContext &Ctx, IdentifierInfo * BridgedType, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static ObjCBridgeMutableAttr *Create(ASTContext &Ctx, IdentifierInfo * BridgedType, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  ObjCBridgeMutableAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , IdentifierInfo * BridgedType
             );

  ObjCBridgeMutableAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  IdentifierInfo * getBridgedType() const {
    return bridgedType;
  }



  static bool classof(const Attr *A) { return A->getKind() == attr::ObjCBridgeMutable; }
};

class ObjCBridgeRelatedAttr : public InheritableAttr {
IdentifierInfo * relatedClass;

IdentifierInfo * classMethod;

IdentifierInfo * instanceMethod;

public:
  enum Spelling {
    GNU_objc_bridge_related = 0,
    CXX11_clang_objc_bridge_related = 1,
    C2x_clang_objc_bridge_related = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static ObjCBridgeRelatedAttr *CreateImplicit(ASTContext &Ctx, IdentifierInfo * RelatedClass, IdentifierInfo * ClassMethod, IdentifierInfo * InstanceMethod, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static ObjCBridgeRelatedAttr *Create(ASTContext &Ctx, IdentifierInfo * RelatedClass, IdentifierInfo * ClassMethod, IdentifierInfo * InstanceMethod, const AttributeCommonInfo &CommonInfo);
  static ObjCBridgeRelatedAttr *CreateImplicit(ASTContext &Ctx, IdentifierInfo * RelatedClass, IdentifierInfo * ClassMethod, IdentifierInfo * InstanceMethod, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static ObjCBridgeRelatedAttr *Create(ASTContext &Ctx, IdentifierInfo * RelatedClass, IdentifierInfo * ClassMethod, IdentifierInfo * InstanceMethod, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  ObjCBridgeRelatedAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , IdentifierInfo * RelatedClass
              , IdentifierInfo * ClassMethod
              , IdentifierInfo * InstanceMethod
             );

  ObjCBridgeRelatedAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  IdentifierInfo * getRelatedClass() const {
    return relatedClass;
  }

  IdentifierInfo * getClassMethod() const {
    return classMethod;
  }

  IdentifierInfo * getInstanceMethod() const {
    return instanceMethod;
  }



  static bool classof(const Attr *A) { return A->getKind() == attr::ObjCBridgeRelated; }
};

class ObjCClassStubAttr : public Attr {
public:
  enum Spelling {
    GNU_objc_class_stub = 0,
    CXX11_clang_objc_class_stub = 1,
    C2x_clang_objc_class_stub = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static ObjCClassStubAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static ObjCClassStubAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static ObjCClassStubAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static ObjCClassStubAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  ObjCClassStubAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  ObjCClassStubAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::ObjCClassStub; }
};

class ObjCDesignatedInitializerAttr : public Attr {
public:
  enum Spelling {
    GNU_objc_designated_initializer = 0,
    CXX11_clang_objc_designated_initializer = 1,
    C2x_clang_objc_designated_initializer = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static ObjCDesignatedInitializerAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static ObjCDesignatedInitializerAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static ObjCDesignatedInitializerAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static ObjCDesignatedInitializerAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  ObjCDesignatedInitializerAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  ObjCDesignatedInitializerAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::ObjCDesignatedInitializer; }
};

class ObjCDirectAttr : public Attr {
public:
  enum Spelling {
    GNU_objc_direct = 0,
    CXX11_clang_objc_direct = 1,
    C2x_clang_objc_direct = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static ObjCDirectAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static ObjCDirectAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static ObjCDirectAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static ObjCDirectAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  ObjCDirectAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  ObjCDirectAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::ObjCDirect; }
};

class ObjCDirectMembersAttr : public Attr {
public:
  enum Spelling {
    GNU_objc_direct_members = 0,
    CXX11_clang_objc_direct_members = 1,
    C2x_clang_objc_direct_members = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static ObjCDirectMembersAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static ObjCDirectMembersAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static ObjCDirectMembersAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static ObjCDirectMembersAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  ObjCDirectMembersAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  ObjCDirectMembersAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::ObjCDirectMembers; }
};

class ObjCExceptionAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_objc_exception = 0,
    CXX11_clang_objc_exception = 1,
    C2x_clang_objc_exception = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static ObjCExceptionAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static ObjCExceptionAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static ObjCExceptionAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static ObjCExceptionAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  ObjCExceptionAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  ObjCExceptionAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::ObjCException; }
};

class ObjCExplicitProtocolImplAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_objc_protocol_requires_explicit_implementation = 0,
    CXX11_clang_objc_protocol_requires_explicit_implementation = 1,
    C2x_clang_objc_protocol_requires_explicit_implementation = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static ObjCExplicitProtocolImplAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static ObjCExplicitProtocolImplAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static ObjCExplicitProtocolImplAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static ObjCExplicitProtocolImplAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  ObjCExplicitProtocolImplAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  ObjCExplicitProtocolImplAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::ObjCExplicitProtocolImpl; }
};

class ObjCExternallyRetainedAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_objc_externally_retained = 0,
    CXX11_clang_objc_externally_retained = 1,
    C2x_clang_objc_externally_retained = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static ObjCExternallyRetainedAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static ObjCExternallyRetainedAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static ObjCExternallyRetainedAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static ObjCExternallyRetainedAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  ObjCExternallyRetainedAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  ObjCExternallyRetainedAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::ObjCExternallyRetained; }
};

class ObjCGCAttr : public TypeAttr {
IdentifierInfo * kind;

public:
  enum Spelling {
    GNU_objc_gc = 0,
    CXX11_clang_objc_gc = 1,
    C2x_clang_objc_gc = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static ObjCGCAttr *CreateImplicit(ASTContext &Ctx, IdentifierInfo * Kind, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static ObjCGCAttr *Create(ASTContext &Ctx, IdentifierInfo * Kind, const AttributeCommonInfo &CommonInfo);
  static ObjCGCAttr *CreateImplicit(ASTContext &Ctx, IdentifierInfo * Kind, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static ObjCGCAttr *Create(ASTContext &Ctx, IdentifierInfo * Kind, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  ObjCGCAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , IdentifierInfo * Kind
             );

  ObjCGCAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  IdentifierInfo * getKind() const {
    return kind;
  }



  static bool classof(const Attr *A) { return A->getKind() == attr::ObjCGC; }
};

class ObjCIndependentClassAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_objc_independent_class = 0,
    CXX11_clang_objc_independent_class = 1,
    C2x_clang_objc_independent_class = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static ObjCIndependentClassAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static ObjCIndependentClassAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static ObjCIndependentClassAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static ObjCIndependentClassAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  ObjCIndependentClassAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  ObjCIndependentClassAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::ObjCIndependentClass; }
};

class ObjCInertUnsafeUnretainedAttr : public TypeAttr {
public:
  // Factory methods
  static ObjCInertUnsafeUnretainedAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static ObjCInertUnsafeUnretainedAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static ObjCInertUnsafeUnretainedAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static ObjCInertUnsafeUnretainedAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  ObjCInertUnsafeUnretainedAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  ObjCInertUnsafeUnretainedAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::ObjCInertUnsafeUnretained; }
};

class ObjCKindOfAttr : public TypeAttr {
public:
  // Factory methods
  static ObjCKindOfAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static ObjCKindOfAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static ObjCKindOfAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static ObjCKindOfAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  ObjCKindOfAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  ObjCKindOfAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::ObjCKindOf; }
};

class ObjCMethodFamilyAttr : public InheritableAttr {
public:
  enum FamilyKind {
    OMF_None,
    OMF_alloc,
    OMF_copy,
    OMF_init,
    OMF_mutableCopy,
    OMF_new
  };
private:
  FamilyKind family;

public:
  enum Spelling {
    GNU_objc_method_family = 0,
    CXX11_clang_objc_method_family = 1,
    C2x_clang_objc_method_family = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static ObjCMethodFamilyAttr *CreateImplicit(ASTContext &Ctx, FamilyKind Family, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static ObjCMethodFamilyAttr *Create(ASTContext &Ctx, FamilyKind Family, const AttributeCommonInfo &CommonInfo);
  static ObjCMethodFamilyAttr *CreateImplicit(ASTContext &Ctx, FamilyKind Family, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static ObjCMethodFamilyAttr *Create(ASTContext &Ctx, FamilyKind Family, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  ObjCMethodFamilyAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , FamilyKind Family
             );

  ObjCMethodFamilyAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  FamilyKind getFamily() const {
    return family;
  }

  static bool ConvertStrToFamilyKind(StringRef Val, FamilyKind &Out);
  static const char *ConvertFamilyKindToStr(FamilyKind Val);


  static bool classof(const Attr *A) { return A->getKind() == attr::ObjCMethodFamily; }
};

class ObjCNSObjectAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_NSObject = 0,
    CXX11_clang_NSObject = 1,
    C2x_clang_NSObject = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static ObjCNSObjectAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static ObjCNSObjectAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static ObjCNSObjectAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static ObjCNSObjectAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  ObjCNSObjectAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  ObjCNSObjectAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::ObjCNSObject; }
};

class ObjCNonLazyClassAttr : public Attr {
public:
  enum Spelling {
    GNU_objc_nonlazy_class = 0,
    CXX11_clang_objc_nonlazy_class = 1,
    C2x_clang_objc_nonlazy_class = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static ObjCNonLazyClassAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static ObjCNonLazyClassAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static ObjCNonLazyClassAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static ObjCNonLazyClassAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  ObjCNonLazyClassAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  ObjCNonLazyClassAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::ObjCNonLazyClass; }
};

class ObjCNonRuntimeProtocolAttr : public Attr {
public:
  enum Spelling {
    GNU_objc_non_runtime_protocol = 0,
    CXX11_clang_objc_non_runtime_protocol = 1,
    C2x_clang_objc_non_runtime_protocol = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static ObjCNonRuntimeProtocolAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static ObjCNonRuntimeProtocolAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static ObjCNonRuntimeProtocolAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static ObjCNonRuntimeProtocolAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  ObjCNonRuntimeProtocolAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  ObjCNonRuntimeProtocolAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::ObjCNonRuntimeProtocol; }
};

class ObjCOwnershipAttr : public InheritableAttr {
IdentifierInfo * kind;

public:
  enum Spelling {
    GNU_objc_ownership = 0,
    CXX11_clang_objc_ownership = 1,
    C2x_clang_objc_ownership = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static ObjCOwnershipAttr *CreateImplicit(ASTContext &Ctx, IdentifierInfo * Kind, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static ObjCOwnershipAttr *Create(ASTContext &Ctx, IdentifierInfo * Kind, const AttributeCommonInfo &CommonInfo);
  static ObjCOwnershipAttr *CreateImplicit(ASTContext &Ctx, IdentifierInfo * Kind, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static ObjCOwnershipAttr *Create(ASTContext &Ctx, IdentifierInfo * Kind, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  ObjCOwnershipAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , IdentifierInfo * Kind
             );

  ObjCOwnershipAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  IdentifierInfo * getKind() const {
    return kind;
  }



  static bool classof(const Attr *A) { return A->getKind() == attr::ObjCOwnership; }
};

class ObjCPreciseLifetimeAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_objc_precise_lifetime = 0,
    CXX11_clang_objc_precise_lifetime = 1,
    C2x_clang_objc_precise_lifetime = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static ObjCPreciseLifetimeAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static ObjCPreciseLifetimeAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static ObjCPreciseLifetimeAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static ObjCPreciseLifetimeAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  ObjCPreciseLifetimeAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  ObjCPreciseLifetimeAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::ObjCPreciseLifetime; }
};

class ObjCRequiresPropertyDefsAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_objc_requires_property_definitions = 0,
    CXX11_clang_objc_requires_property_definitions = 1,
    C2x_clang_objc_requires_property_definitions = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static ObjCRequiresPropertyDefsAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static ObjCRequiresPropertyDefsAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static ObjCRequiresPropertyDefsAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static ObjCRequiresPropertyDefsAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  ObjCRequiresPropertyDefsAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  ObjCRequiresPropertyDefsAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::ObjCRequiresPropertyDefs; }
};

class ObjCRequiresSuperAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_objc_requires_super = 0,
    CXX11_clang_objc_requires_super = 1,
    C2x_clang_objc_requires_super = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static ObjCRequiresSuperAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static ObjCRequiresSuperAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static ObjCRequiresSuperAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static ObjCRequiresSuperAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  ObjCRequiresSuperAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  ObjCRequiresSuperAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::ObjCRequiresSuper; }
};

class ObjCReturnsInnerPointerAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_objc_returns_inner_pointer = 0,
    CXX11_clang_objc_returns_inner_pointer = 1,
    C2x_clang_objc_returns_inner_pointer = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static ObjCReturnsInnerPointerAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static ObjCReturnsInnerPointerAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static ObjCReturnsInnerPointerAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static ObjCReturnsInnerPointerAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  ObjCReturnsInnerPointerAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  ObjCReturnsInnerPointerAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::ObjCReturnsInnerPointer; }
};

class ObjCRootClassAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_objc_root_class = 0,
    CXX11_clang_objc_root_class = 1,
    C2x_clang_objc_root_class = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static ObjCRootClassAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static ObjCRootClassAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static ObjCRootClassAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static ObjCRootClassAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  ObjCRootClassAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  ObjCRootClassAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::ObjCRootClass; }
};

class ObjCRuntimeNameAttr : public Attr {
unsigned metadataNameLength;
char *metadataName;

public:
  enum Spelling {
    GNU_objc_runtime_name = 0,
    CXX11_clang_objc_runtime_name = 1,
    C2x_clang_objc_runtime_name = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static ObjCRuntimeNameAttr *CreateImplicit(ASTContext &Ctx, llvm::StringRef MetadataName, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static ObjCRuntimeNameAttr *Create(ASTContext &Ctx, llvm::StringRef MetadataName, const AttributeCommonInfo &CommonInfo);
  static ObjCRuntimeNameAttr *CreateImplicit(ASTContext &Ctx, llvm::StringRef MetadataName, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static ObjCRuntimeNameAttr *Create(ASTContext &Ctx, llvm::StringRef MetadataName, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  ObjCRuntimeNameAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , llvm::StringRef MetadataName
             );

  ObjCRuntimeNameAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  llvm::StringRef getMetadataName() const {
    return llvm::StringRef(metadataName, metadataNameLength);
  }
  unsigned getMetadataNameLength() const {
    return metadataNameLength;
  }
  void setMetadataName(ASTContext &C, llvm::StringRef S) {
    metadataNameLength = S.size();
    this->metadataName = new (C, 1) char [metadataNameLength];
    if (!S.empty())
      std::memcpy(this->metadataName, S.data(), metadataNameLength);
  }



  static bool classof(const Attr *A) { return A->getKind() == attr::ObjCRuntimeName; }
};

class ObjCRuntimeVisibleAttr : public Attr {
public:
  enum Spelling {
    GNU_objc_runtime_visible = 0,
    CXX11_clang_objc_runtime_visible = 1,
    C2x_clang_objc_runtime_visible = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static ObjCRuntimeVisibleAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static ObjCRuntimeVisibleAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static ObjCRuntimeVisibleAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static ObjCRuntimeVisibleAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  ObjCRuntimeVisibleAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  ObjCRuntimeVisibleAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::ObjCRuntimeVisible; }
};

class ObjCSubclassingRestrictedAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_objc_subclassing_restricted = 0,
    CXX11_clang_objc_subclassing_restricted = 1,
    C2x_clang_objc_subclassing_restricted = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static ObjCSubclassingRestrictedAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static ObjCSubclassingRestrictedAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static ObjCSubclassingRestrictedAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static ObjCSubclassingRestrictedAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  ObjCSubclassingRestrictedAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  ObjCSubclassingRestrictedAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::ObjCSubclassingRestricted; }
};

class OpenCLAccessAttr : public Attr {
public:
  enum Spelling {
    Keyword_read_only = 0,
    Keyword_write_only = 2,
    Keyword_read_write = 4,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static OpenCLAccessAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static OpenCLAccessAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static OpenCLAccessAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax, OpenCLAccessAttr::Spelling S = static_cast<Spelling>(SpellingNotCalculated));
  static OpenCLAccessAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax, OpenCLAccessAttr::Spelling S = static_cast<Spelling>(SpellingNotCalculated));

  // Constructors
  OpenCLAccessAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  OpenCLAccessAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  Spelling getSemanticSpelling() const;
  bool isReadOnly() const { return getAttributeSpellingListIndex() == 0 ||
    getAttributeSpellingListIndex() == 1; }
  bool isReadWrite() const { return getAttributeSpellingListIndex() == 4 ||
    getAttributeSpellingListIndex() == 5; }
  bool isWriteOnly() const { return getAttributeSpellingListIndex() == 2 ||
    getAttributeSpellingListIndex() == 3; }


  static bool classof(const Attr *A) { return A->getKind() == attr::OpenCLAccess; }
};

class OpenCLConstantAddressSpaceAttr : public TypeAttr {
public:
  enum Spelling {
    Keyword_constant = 0,
    GNU_opencl_constant = 2,
    CXX11_clang_opencl_constant = 3,
    C2x_clang_opencl_constant = 4,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static OpenCLConstantAddressSpaceAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static OpenCLConstantAddressSpaceAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static OpenCLConstantAddressSpaceAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax, OpenCLConstantAddressSpaceAttr::Spelling S = static_cast<Spelling>(SpellingNotCalculated));
  static OpenCLConstantAddressSpaceAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax, OpenCLConstantAddressSpaceAttr::Spelling S = static_cast<Spelling>(SpellingNotCalculated));

  // Constructors
  OpenCLConstantAddressSpaceAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  OpenCLConstantAddressSpaceAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  Spelling getSemanticSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::OpenCLConstantAddressSpace; }
};

class OpenCLGenericAddressSpaceAttr : public TypeAttr {
public:
  enum Spelling {
    Keyword_generic = 0,
    GNU_opencl_generic = 2,
    CXX11_clang_opencl_generic = 3,
    C2x_clang_opencl_generic = 4,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static OpenCLGenericAddressSpaceAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static OpenCLGenericAddressSpaceAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static OpenCLGenericAddressSpaceAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax, OpenCLGenericAddressSpaceAttr::Spelling S = static_cast<Spelling>(SpellingNotCalculated));
  static OpenCLGenericAddressSpaceAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax, OpenCLGenericAddressSpaceAttr::Spelling S = static_cast<Spelling>(SpellingNotCalculated));

  // Constructors
  OpenCLGenericAddressSpaceAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  OpenCLGenericAddressSpaceAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  Spelling getSemanticSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::OpenCLGenericAddressSpace; }
};

class OpenCLGlobalAddressSpaceAttr : public TypeAttr {
public:
  enum Spelling {
    Keyword_global = 0,
    GNU_opencl_global = 2,
    CXX11_clang_opencl_global = 3,
    C2x_clang_opencl_global = 4,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static OpenCLGlobalAddressSpaceAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static OpenCLGlobalAddressSpaceAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static OpenCLGlobalAddressSpaceAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax, OpenCLGlobalAddressSpaceAttr::Spelling S = static_cast<Spelling>(SpellingNotCalculated));
  static OpenCLGlobalAddressSpaceAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax, OpenCLGlobalAddressSpaceAttr::Spelling S = static_cast<Spelling>(SpellingNotCalculated));

  // Constructors
  OpenCLGlobalAddressSpaceAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  OpenCLGlobalAddressSpaceAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  Spelling getSemanticSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::OpenCLGlobalAddressSpace; }
};

class OpenCLGlobalDeviceAddressSpaceAttr : public TypeAttr {
public:
  enum Spelling {
    GNU_opencl_global_device = 0,
    CXX11_clang_opencl_global_device = 1,
    C2x_clang_opencl_global_device = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static OpenCLGlobalDeviceAddressSpaceAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static OpenCLGlobalDeviceAddressSpaceAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static OpenCLGlobalDeviceAddressSpaceAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static OpenCLGlobalDeviceAddressSpaceAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  OpenCLGlobalDeviceAddressSpaceAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  OpenCLGlobalDeviceAddressSpaceAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::OpenCLGlobalDeviceAddressSpace; }
};

class OpenCLGlobalHostAddressSpaceAttr : public TypeAttr {
public:
  enum Spelling {
    GNU_opencl_global_host = 0,
    CXX11_clang_opencl_global_host = 1,
    C2x_clang_opencl_global_host = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static OpenCLGlobalHostAddressSpaceAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static OpenCLGlobalHostAddressSpaceAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static OpenCLGlobalHostAddressSpaceAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static OpenCLGlobalHostAddressSpaceAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  OpenCLGlobalHostAddressSpaceAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  OpenCLGlobalHostAddressSpaceAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::OpenCLGlobalHostAddressSpace; }
};

class OpenCLIntelReqdSubGroupSizeAttr : public InheritableAttr {
unsigned subGroupSize;

public:
  // Factory methods
  static OpenCLIntelReqdSubGroupSizeAttr *CreateImplicit(ASTContext &Ctx, unsigned SubGroupSize, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static OpenCLIntelReqdSubGroupSizeAttr *Create(ASTContext &Ctx, unsigned SubGroupSize, const AttributeCommonInfo &CommonInfo);
  static OpenCLIntelReqdSubGroupSizeAttr *CreateImplicit(ASTContext &Ctx, unsigned SubGroupSize, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static OpenCLIntelReqdSubGroupSizeAttr *Create(ASTContext &Ctx, unsigned SubGroupSize, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  OpenCLIntelReqdSubGroupSizeAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , unsigned SubGroupSize
             );

  OpenCLIntelReqdSubGroupSizeAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  unsigned getSubGroupSize() const {
    return subGroupSize;
  }



  static bool classof(const Attr *A) { return A->getKind() == attr::OpenCLIntelReqdSubGroupSize; }
};

class OpenCLKernelAttr : public InheritableAttr {
public:
  enum Spelling {
    Keyword_kernel = 0,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static OpenCLKernelAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static OpenCLKernelAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static OpenCLKernelAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static OpenCLKernelAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  OpenCLKernelAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  OpenCLKernelAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::OpenCLKernel; }
};

class OpenCLLocalAddressSpaceAttr : public TypeAttr {
public:
  enum Spelling {
    Keyword_local = 0,
    GNU_opencl_local = 2,
    CXX11_clang_opencl_local = 3,
    C2x_clang_opencl_local = 4,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static OpenCLLocalAddressSpaceAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static OpenCLLocalAddressSpaceAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static OpenCLLocalAddressSpaceAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax, OpenCLLocalAddressSpaceAttr::Spelling S = static_cast<Spelling>(SpellingNotCalculated));
  static OpenCLLocalAddressSpaceAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax, OpenCLLocalAddressSpaceAttr::Spelling S = static_cast<Spelling>(SpellingNotCalculated));

  // Constructors
  OpenCLLocalAddressSpaceAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  OpenCLLocalAddressSpaceAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  Spelling getSemanticSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::OpenCLLocalAddressSpace; }
};

class OpenCLPrivateAddressSpaceAttr : public TypeAttr {
public:
  enum Spelling {
    Keyword_private = 0,
    GNU_opencl_private = 2,
    CXX11_clang_opencl_private = 3,
    C2x_clang_opencl_private = 4,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static OpenCLPrivateAddressSpaceAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static OpenCLPrivateAddressSpaceAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static OpenCLPrivateAddressSpaceAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax, OpenCLPrivateAddressSpaceAttr::Spelling S = static_cast<Spelling>(SpellingNotCalculated));
  static OpenCLPrivateAddressSpaceAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax, OpenCLPrivateAddressSpaceAttr::Spelling S = static_cast<Spelling>(SpellingNotCalculated));

  // Constructors
  OpenCLPrivateAddressSpaceAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  OpenCLPrivateAddressSpaceAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  Spelling getSemanticSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::OpenCLPrivateAddressSpace; }
};

class OpenCLUnrollHintAttr : public StmtAttr {
unsigned unrollHint;

public:
  // Factory methods
  static OpenCLUnrollHintAttr *CreateImplicit(ASTContext &Ctx, unsigned UnrollHint, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static OpenCLUnrollHintAttr *Create(ASTContext &Ctx, unsigned UnrollHint, const AttributeCommonInfo &CommonInfo);
  static OpenCLUnrollHintAttr *CreateImplicit(ASTContext &Ctx, unsigned UnrollHint, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static OpenCLUnrollHintAttr *Create(ASTContext &Ctx, unsigned UnrollHint, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  OpenCLUnrollHintAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , unsigned UnrollHint
             );
  OpenCLUnrollHintAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  OpenCLUnrollHintAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  unsigned getUnrollHint() const {
    return unrollHint;
  }



  static bool classof(const Attr *A) { return A->getKind() == attr::OpenCLUnrollHint; }
};

class OptimizeNoneAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_optnone = 0,
    CXX11_clang_optnone = 1,
    C2x_clang_optnone = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static OptimizeNoneAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static OptimizeNoneAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static OptimizeNoneAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static OptimizeNoneAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  OptimizeNoneAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  OptimizeNoneAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::OptimizeNone; }
};

class OverloadableAttr : public Attr {
public:
  enum Spelling {
    GNU_overloadable = 0,
    CXX11_clang_overloadable = 1,
    C2x_clang_overloadable = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static OverloadableAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static OverloadableAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static OverloadableAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static OverloadableAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  OverloadableAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  OverloadableAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::Overloadable; }
};

class OverrideAttr : public InheritableAttr {
public:
  // Factory methods
  static OverrideAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static OverrideAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static OverrideAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static OverrideAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  OverrideAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  OverrideAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::Override; }
};

class OwnerAttr : public InheritableAttr {
TypeSourceInfo * derefType;

public:
  // Factory methods
  static OwnerAttr *CreateImplicit(ASTContext &Ctx, TypeSourceInfo * DerefType, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static OwnerAttr *Create(ASTContext &Ctx, TypeSourceInfo * DerefType, const AttributeCommonInfo &CommonInfo);
  static OwnerAttr *CreateImplicit(ASTContext &Ctx, TypeSourceInfo * DerefType, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static OwnerAttr *Create(ASTContext &Ctx, TypeSourceInfo * DerefType, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  OwnerAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , TypeSourceInfo * DerefType
             );
  OwnerAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  OwnerAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  QualType getDerefType() const {
    return derefType->getType();
  }  TypeSourceInfo * getDerefTypeLoc() const {
    return derefType;
  }



  static bool classof(const Attr *A) { return A->getKind() == attr::Owner; }
};

class OwnershipAttr : public InheritableAttr {
IdentifierInfo * module;

  unsigned args_Size;
  ParamIdx *args_;

public:
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

  // Factory methods
  static OwnershipAttr *CreateImplicit(ASTContext &Ctx, IdentifierInfo * Module, ParamIdx *Args, unsigned ArgsSize, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static OwnershipAttr *Create(ASTContext &Ctx, IdentifierInfo * Module, ParamIdx *Args, unsigned ArgsSize, const AttributeCommonInfo &CommonInfo);
  static OwnershipAttr *CreateImplicit(ASTContext &Ctx, IdentifierInfo * Module, ParamIdx *Args, unsigned ArgsSize, SourceRange Range, AttributeCommonInfo::Syntax Syntax, OwnershipAttr::Spelling S = static_cast<Spelling>(SpellingNotCalculated));
  static OwnershipAttr *Create(ASTContext &Ctx, IdentifierInfo * Module, ParamIdx *Args, unsigned ArgsSize, SourceRange Range, AttributeCommonInfo::Syntax Syntax, OwnershipAttr::Spelling S = static_cast<Spelling>(SpellingNotCalculated));

  // Constructors
  OwnershipAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , IdentifierInfo * Module
              , ParamIdx *Args, unsigned ArgsSize
             );
  OwnershipAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , IdentifierInfo * Module
             );

  OwnershipAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  Spelling getSemanticSpelling() const;
  bool isHolds() const { return getAttributeSpellingListIndex() == 0 ||
    getAttributeSpellingListIndex() == 1 ||
    getAttributeSpellingListIndex() == 2; }
  bool isReturns() const { return getAttributeSpellingListIndex() == 3 ||
    getAttributeSpellingListIndex() == 4 ||
    getAttributeSpellingListIndex() == 5; }
  bool isTakes() const { return getAttributeSpellingListIndex() == 6 ||
    getAttributeSpellingListIndex() == 7 ||
    getAttributeSpellingListIndex() == 8; }
  IdentifierInfo * getModule() const {
    return module;
  }

  typedef ParamIdx* args_iterator;
  args_iterator args_begin() const { return args_; }
  args_iterator args_end() const { return args_ + args_Size; }
  unsigned args_size() const { return args_Size; }
  llvm::iterator_range<args_iterator> args() const { return llvm::make_range(args_begin(), args_end()); }



    enum OwnershipKind { Holds, Returns, Takes };
    OwnershipKind getOwnKind() const {
      return isHolds() ? Holds :
             isTakes() ? Takes :
             Returns;
    }
  

  static bool classof(const Attr *A) { return A->getKind() == attr::Ownership; }
};

class PackedAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_packed = 0,
    CXX11_gnu_packed = 1,
    C2x_gnu_packed = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static PackedAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static PackedAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static PackedAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static PackedAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  PackedAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  PackedAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::Packed; }
};

class ParamTypestateAttr : public InheritableAttr {
public:
  enum ConsumedState {
    Unknown,
    Consumed,
    Unconsumed
  };
private:
  ConsumedState paramState;

public:
  enum Spelling {
    GNU_param_typestate = 0,
    CXX11_clang_param_typestate = 1,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static ParamTypestateAttr *CreateImplicit(ASTContext &Ctx, ConsumedState ParamState, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static ParamTypestateAttr *Create(ASTContext &Ctx, ConsumedState ParamState, const AttributeCommonInfo &CommonInfo);
  static ParamTypestateAttr *CreateImplicit(ASTContext &Ctx, ConsumedState ParamState, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static ParamTypestateAttr *Create(ASTContext &Ctx, ConsumedState ParamState, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  ParamTypestateAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , ConsumedState ParamState
             );

  ParamTypestateAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  ConsumedState getParamState() const {
    return paramState;
  }

  static bool ConvertStrToConsumedState(StringRef Val, ConsumedState &Out);
  static const char *ConvertConsumedStateToStr(ConsumedState Val);


  static bool classof(const Attr *A) { return A->getKind() == attr::ParamTypestate; }
};

class PascalAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_pascal = 0,
    CXX11_clang_pascal = 1,
    C2x_clang_pascal = 2,
    Keyword_pascal = 3,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static PascalAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static PascalAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static PascalAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static PascalAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  PascalAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  PascalAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::Pascal; }
};

class PassObjectSizeAttr : public InheritableParamAttr {
int type;

public:
  enum Spelling {
    GNU_pass_object_size = 0,
    CXX11_clang_pass_object_size = 1,
    C2x_clang_pass_object_size = 2,
    GNU_pass_dynamic_object_size = 3,
    CXX11_clang_pass_dynamic_object_size = 4,
    C2x_clang_pass_dynamic_object_size = 5,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static PassObjectSizeAttr *CreateImplicit(ASTContext &Ctx, int Type, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static PassObjectSizeAttr *Create(ASTContext &Ctx, int Type, const AttributeCommonInfo &CommonInfo);
  static PassObjectSizeAttr *CreateImplicit(ASTContext &Ctx, int Type, SourceRange Range, AttributeCommonInfo::Syntax Syntax, PassObjectSizeAttr::Spelling S = static_cast<Spelling>(SpellingNotCalculated));
  static PassObjectSizeAttr *Create(ASTContext &Ctx, int Type, SourceRange Range, AttributeCommonInfo::Syntax Syntax, PassObjectSizeAttr::Spelling S = static_cast<Spelling>(SpellingNotCalculated));

  // Constructors
  PassObjectSizeAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , int Type
             );

  PassObjectSizeAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  Spelling getSemanticSpelling() const;
  bool isDynamic() const { return getAttributeSpellingListIndex() == 3 ||
    getAttributeSpellingListIndex() == 4 ||
    getAttributeSpellingListIndex() == 5; }
  int getType() const {
    return type;
  }



  static bool classof(const Attr *A) { return A->getKind() == attr::PassObjectSize; }
};

class PatchableFunctionEntryAttr : public InheritableAttr {
unsigned count;

int offset;

public:
  enum Spelling {
    GNU_patchable_function_entry = 0,
    CXX11_gnu_patchable_function_entry = 1,
    C2x_gnu_patchable_function_entry = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static PatchableFunctionEntryAttr *CreateImplicit(ASTContext &Ctx, unsigned Count, int Offset, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static PatchableFunctionEntryAttr *Create(ASTContext &Ctx, unsigned Count, int Offset, const AttributeCommonInfo &CommonInfo);
  static PatchableFunctionEntryAttr *CreateImplicit(ASTContext &Ctx, unsigned Count, int Offset, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static PatchableFunctionEntryAttr *Create(ASTContext &Ctx, unsigned Count, int Offset, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  PatchableFunctionEntryAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , unsigned Count
              , int Offset
             );
  PatchableFunctionEntryAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , unsigned Count
             );

  PatchableFunctionEntryAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  unsigned getCount() const {
    return count;
  }

  int getOffset() const {
    return offset;
  }

  static const int DefaultOffset = 0;



  static bool classof(const Attr *A) { return A->getKind() == attr::PatchableFunctionEntry; }
};

class PcsAttr : public InheritableAttr {
public:
  enum PCSType {
    AAPCS,
    AAPCS_VFP
  };
private:
  PCSType pCS;

public:
  enum Spelling {
    GNU_pcs = 0,
    CXX11_gnu_pcs = 1,
    C2x_gnu_pcs = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static PcsAttr *CreateImplicit(ASTContext &Ctx, PCSType PCS, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static PcsAttr *Create(ASTContext &Ctx, PCSType PCS, const AttributeCommonInfo &CommonInfo);
  static PcsAttr *CreateImplicit(ASTContext &Ctx, PCSType PCS, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static PcsAttr *Create(ASTContext &Ctx, PCSType PCS, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  PcsAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , PCSType PCS
             );

  PcsAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  PCSType getPCS() const {
    return pCS;
  }

  static bool ConvertStrToPCSType(StringRef Val, PCSType &Out);
  static const char *ConvertPCSTypeToStr(PCSType Val);


  static bool classof(const Attr *A) { return A->getKind() == attr::Pcs; }
};

class PointerAttr : public InheritableAttr {
TypeSourceInfo * derefType;

public:
  // Factory methods
  static PointerAttr *CreateImplicit(ASTContext &Ctx, TypeSourceInfo * DerefType, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static PointerAttr *Create(ASTContext &Ctx, TypeSourceInfo * DerefType, const AttributeCommonInfo &CommonInfo);
  static PointerAttr *CreateImplicit(ASTContext &Ctx, TypeSourceInfo * DerefType, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static PointerAttr *Create(ASTContext &Ctx, TypeSourceInfo * DerefType, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  PointerAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , TypeSourceInfo * DerefType
             );
  PointerAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  PointerAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  QualType getDerefType() const {
    return derefType->getType();
  }  TypeSourceInfo * getDerefTypeLoc() const {
    return derefType;
  }



  static bool classof(const Attr *A) { return A->getKind() == attr::Pointer; }
};

class PragmaClangBSSSectionAttr : public InheritableAttr {
unsigned nameLength;
char *name;

public:
  // Factory methods
  static PragmaClangBSSSectionAttr *CreateImplicit(ASTContext &Ctx, llvm::StringRef Name, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static PragmaClangBSSSectionAttr *Create(ASTContext &Ctx, llvm::StringRef Name, const AttributeCommonInfo &CommonInfo);
  static PragmaClangBSSSectionAttr *CreateImplicit(ASTContext &Ctx, llvm::StringRef Name, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static PragmaClangBSSSectionAttr *Create(ASTContext &Ctx, llvm::StringRef Name, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  PragmaClangBSSSectionAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , llvm::StringRef Name
             );

  PragmaClangBSSSectionAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  llvm::StringRef getName() const {
    return llvm::StringRef(name, nameLength);
  }
  unsigned getNameLength() const {
    return nameLength;
  }
  void setName(ASTContext &C, llvm::StringRef S) {
    nameLength = S.size();
    this->name = new (C, 1) char [nameLength];
    if (!S.empty())
      std::memcpy(this->name, S.data(), nameLength);
  }



  static bool classof(const Attr *A) { return A->getKind() == attr::PragmaClangBSSSection; }
};

class PragmaClangDataSectionAttr : public InheritableAttr {
unsigned nameLength;
char *name;

public:
  // Factory methods
  static PragmaClangDataSectionAttr *CreateImplicit(ASTContext &Ctx, llvm::StringRef Name, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static PragmaClangDataSectionAttr *Create(ASTContext &Ctx, llvm::StringRef Name, const AttributeCommonInfo &CommonInfo);
  static PragmaClangDataSectionAttr *CreateImplicit(ASTContext &Ctx, llvm::StringRef Name, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static PragmaClangDataSectionAttr *Create(ASTContext &Ctx, llvm::StringRef Name, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  PragmaClangDataSectionAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , llvm::StringRef Name
             );

  PragmaClangDataSectionAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  llvm::StringRef getName() const {
    return llvm::StringRef(name, nameLength);
  }
  unsigned getNameLength() const {
    return nameLength;
  }
  void setName(ASTContext &C, llvm::StringRef S) {
    nameLength = S.size();
    this->name = new (C, 1) char [nameLength];
    if (!S.empty())
      std::memcpy(this->name, S.data(), nameLength);
  }



  static bool classof(const Attr *A) { return A->getKind() == attr::PragmaClangDataSection; }
};

class PragmaClangRelroSectionAttr : public InheritableAttr {
unsigned nameLength;
char *name;

public:
  // Factory methods
  static PragmaClangRelroSectionAttr *CreateImplicit(ASTContext &Ctx, llvm::StringRef Name, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static PragmaClangRelroSectionAttr *Create(ASTContext &Ctx, llvm::StringRef Name, const AttributeCommonInfo &CommonInfo);
  static PragmaClangRelroSectionAttr *CreateImplicit(ASTContext &Ctx, llvm::StringRef Name, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static PragmaClangRelroSectionAttr *Create(ASTContext &Ctx, llvm::StringRef Name, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  PragmaClangRelroSectionAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , llvm::StringRef Name
             );

  PragmaClangRelroSectionAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  llvm::StringRef getName() const {
    return llvm::StringRef(name, nameLength);
  }
  unsigned getNameLength() const {
    return nameLength;
  }
  void setName(ASTContext &C, llvm::StringRef S) {
    nameLength = S.size();
    this->name = new (C, 1) char [nameLength];
    if (!S.empty())
      std::memcpy(this->name, S.data(), nameLength);
  }



  static bool classof(const Attr *A) { return A->getKind() == attr::PragmaClangRelroSection; }
};

class PragmaClangRodataSectionAttr : public InheritableAttr {
unsigned nameLength;
char *name;

public:
  // Factory methods
  static PragmaClangRodataSectionAttr *CreateImplicit(ASTContext &Ctx, llvm::StringRef Name, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static PragmaClangRodataSectionAttr *Create(ASTContext &Ctx, llvm::StringRef Name, const AttributeCommonInfo &CommonInfo);
  static PragmaClangRodataSectionAttr *CreateImplicit(ASTContext &Ctx, llvm::StringRef Name, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static PragmaClangRodataSectionAttr *Create(ASTContext &Ctx, llvm::StringRef Name, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  PragmaClangRodataSectionAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , llvm::StringRef Name
             );

  PragmaClangRodataSectionAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  llvm::StringRef getName() const {
    return llvm::StringRef(name, nameLength);
  }
  unsigned getNameLength() const {
    return nameLength;
  }
  void setName(ASTContext &C, llvm::StringRef S) {
    nameLength = S.size();
    this->name = new (C, 1) char [nameLength];
    if (!S.empty())
      std::memcpy(this->name, S.data(), nameLength);
  }



  static bool classof(const Attr *A) { return A->getKind() == attr::PragmaClangRodataSection; }
};

class PragmaClangTextSectionAttr : public InheritableAttr {
unsigned nameLength;
char *name;

public:
  // Factory methods
  static PragmaClangTextSectionAttr *CreateImplicit(ASTContext &Ctx, llvm::StringRef Name, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static PragmaClangTextSectionAttr *Create(ASTContext &Ctx, llvm::StringRef Name, const AttributeCommonInfo &CommonInfo);
  static PragmaClangTextSectionAttr *CreateImplicit(ASTContext &Ctx, llvm::StringRef Name, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static PragmaClangTextSectionAttr *Create(ASTContext &Ctx, llvm::StringRef Name, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  PragmaClangTextSectionAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , llvm::StringRef Name
             );

  PragmaClangTextSectionAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  llvm::StringRef getName() const {
    return llvm::StringRef(name, nameLength);
  }
  unsigned getNameLength() const {
    return nameLength;
  }
  void setName(ASTContext &C, llvm::StringRef S) {
    nameLength = S.size();
    this->name = new (C, 1) char [nameLength];
    if (!S.empty())
      std::memcpy(this->name, S.data(), nameLength);
  }



  static bool classof(const Attr *A) { return A->getKind() == attr::PragmaClangTextSection; }
};

class PreferredNameAttr : public InheritableAttr {
TypeSourceInfo * typedefType;

public:
  enum Spelling {
    GNU_preferred_name = 0,
    CXX11_clang_preferred_name = 1,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static PreferredNameAttr *CreateImplicit(ASTContext &Ctx, TypeSourceInfo * TypedefType, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static PreferredNameAttr *Create(ASTContext &Ctx, TypeSourceInfo * TypedefType, const AttributeCommonInfo &CommonInfo);
  static PreferredNameAttr *CreateImplicit(ASTContext &Ctx, TypeSourceInfo * TypedefType, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static PreferredNameAttr *Create(ASTContext &Ctx, TypeSourceInfo * TypedefType, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  PreferredNameAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , TypeSourceInfo * TypedefType
             );

  PreferredNameAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  QualType getTypedefType() const {
    return typedefType->getType();
  }  TypeSourceInfo * getTypedefTypeLoc() const {
    return typedefType;
  }



  static bool classof(const Attr *A) { return A->getKind() == attr::PreferredName; }
};

class PreserveAllAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_preserve_all = 0,
    CXX11_clang_preserve_all = 1,
    C2x_clang_preserve_all = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static PreserveAllAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static PreserveAllAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static PreserveAllAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static PreserveAllAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  PreserveAllAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  PreserveAllAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::PreserveAll; }
};

class PreserveMostAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_preserve_most = 0,
    CXX11_clang_preserve_most = 1,
    C2x_clang_preserve_most = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static PreserveMostAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static PreserveMostAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static PreserveMostAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static PreserveMostAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  PreserveMostAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  PreserveMostAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::PreserveMost; }
};

class PtGuardedByAttr : public InheritableAttr {
Expr * arg;

public:
  // Factory methods
  static PtGuardedByAttr *CreateImplicit(ASTContext &Ctx, Expr * Arg, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static PtGuardedByAttr *Create(ASTContext &Ctx, Expr * Arg, const AttributeCommonInfo &CommonInfo);
  static PtGuardedByAttr *CreateImplicit(ASTContext &Ctx, Expr * Arg, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static PtGuardedByAttr *Create(ASTContext &Ctx, Expr * Arg, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  PtGuardedByAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , Expr * Arg
             );

  PtGuardedByAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  Expr * getArg() const {
    return arg;
  }



  static bool classof(const Attr *A) { return A->getKind() == attr::PtGuardedBy; }
};

class PtGuardedVarAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_pt_guarded_var = 0,
    CXX11_clang_pt_guarded_var = 1,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static PtGuardedVarAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static PtGuardedVarAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static PtGuardedVarAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static PtGuardedVarAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  PtGuardedVarAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  PtGuardedVarAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::PtGuardedVar; }
};

class Ptr32Attr : public TypeAttr {
public:
  // Factory methods
  static Ptr32Attr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static Ptr32Attr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static Ptr32Attr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static Ptr32Attr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  Ptr32Attr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  Ptr32Attr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::Ptr32; }
};

class Ptr64Attr : public TypeAttr {
public:
  // Factory methods
  static Ptr64Attr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static Ptr64Attr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static Ptr64Attr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static Ptr64Attr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  Ptr64Attr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  Ptr64Attr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::Ptr64; }
};

class PureAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_pure = 0,
    CXX11_gnu_pure = 1,
    C2x_gnu_pure = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static PureAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static PureAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static PureAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static PureAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  PureAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  PureAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::Pure; }
};

class RISCVInterruptAttr : public InheritableAttr {
public:
  enum InterruptType {
    user,
    supervisor,
    machine
  };
private:
  InterruptType interrupt;

public:
  enum Spelling {
    GNU_interrupt = 0,
    CXX11_gnu_interrupt = 1,
    C2x_gnu_interrupt = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static RISCVInterruptAttr *CreateImplicit(ASTContext &Ctx, InterruptType Interrupt, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static RISCVInterruptAttr *Create(ASTContext &Ctx, InterruptType Interrupt, const AttributeCommonInfo &CommonInfo);
  static RISCVInterruptAttr *CreateImplicit(ASTContext &Ctx, InterruptType Interrupt, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static RISCVInterruptAttr *Create(ASTContext &Ctx, InterruptType Interrupt, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  RISCVInterruptAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , InterruptType Interrupt
             );
  RISCVInterruptAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  RISCVInterruptAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  InterruptType getInterrupt() const {
    return interrupt;
  }

  static bool ConvertStrToInterruptType(StringRef Val, InterruptType &Out);
  static const char *ConvertInterruptTypeToStr(InterruptType Val);


  static bool classof(const Attr *A) { return A->getKind() == attr::RISCVInterrupt; }
};

class RegCallAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_regcall = 0,
    CXX11_gnu_regcall = 1,
    C2x_gnu_regcall = 2,
    Keyword_regcall = 3,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static RegCallAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static RegCallAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static RegCallAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static RegCallAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  RegCallAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  RegCallAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::RegCall; }
};

class ReinitializesAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_reinitializes = 0,
    CXX11_clang_reinitializes = 1,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static ReinitializesAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static ReinitializesAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static ReinitializesAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static ReinitializesAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  ReinitializesAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  ReinitializesAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::Reinitializes; }
};

class ReleaseCapabilityAttr : public InheritableAttr {
  unsigned args_Size;
  Expr * *args_;

public:
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

  // Factory methods
  static ReleaseCapabilityAttr *CreateImplicit(ASTContext &Ctx, Expr * *Args, unsigned ArgsSize, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static ReleaseCapabilityAttr *Create(ASTContext &Ctx, Expr * *Args, unsigned ArgsSize, const AttributeCommonInfo &CommonInfo);
  static ReleaseCapabilityAttr *CreateImplicit(ASTContext &Ctx, Expr * *Args, unsigned ArgsSize, SourceRange Range, AttributeCommonInfo::Syntax Syntax, ReleaseCapabilityAttr::Spelling S = static_cast<Spelling>(SpellingNotCalculated));
  static ReleaseCapabilityAttr *Create(ASTContext &Ctx, Expr * *Args, unsigned ArgsSize, SourceRange Range, AttributeCommonInfo::Syntax Syntax, ReleaseCapabilityAttr::Spelling S = static_cast<Spelling>(SpellingNotCalculated));

  // Constructors
  ReleaseCapabilityAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , Expr * *Args, unsigned ArgsSize
             );
  ReleaseCapabilityAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  ReleaseCapabilityAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  Spelling getSemanticSpelling() const;
  bool isShared() const { return getAttributeSpellingListIndex() == 2 ||
    getAttributeSpellingListIndex() == 3; }
  bool isGeneric() const { return getAttributeSpellingListIndex() == 4 ||
    getAttributeSpellingListIndex() == 5 ||
    getAttributeSpellingListIndex() == 6 ||
    getAttributeSpellingListIndex() == 7; }
  typedef Expr ** args_iterator;
  args_iterator args_begin() const { return args_; }
  args_iterator args_end() const { return args_ + args_Size; }
  unsigned args_size() const { return args_Size; }
  llvm::iterator_range<args_iterator> args() const { return llvm::make_range(args_begin(), args_end()); }




  static bool classof(const Attr *A) { return A->getKind() == attr::ReleaseCapability; }
};

class ReleaseHandleAttr : public InheritableParamAttr {
unsigned handleTypeLength;
char *handleType;

public:
  enum Spelling {
    GNU_release_handle = 0,
    CXX11_clang_release_handle = 1,
    C2x_clang_release_handle = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static ReleaseHandleAttr *CreateImplicit(ASTContext &Ctx, llvm::StringRef HandleType, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static ReleaseHandleAttr *Create(ASTContext &Ctx, llvm::StringRef HandleType, const AttributeCommonInfo &CommonInfo);
  static ReleaseHandleAttr *CreateImplicit(ASTContext &Ctx, llvm::StringRef HandleType, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static ReleaseHandleAttr *Create(ASTContext &Ctx, llvm::StringRef HandleType, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  ReleaseHandleAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , llvm::StringRef HandleType
             );

  ReleaseHandleAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  llvm::StringRef getHandleType() const {
    return llvm::StringRef(handleType, handleTypeLength);
  }
  unsigned getHandleTypeLength() const {
    return handleTypeLength;
  }
  void setHandleType(ASTContext &C, llvm::StringRef S) {
    handleTypeLength = S.size();
    this->handleType = new (C, 1) char [handleTypeLength];
    if (!S.empty())
      std::memcpy(this->handleType, S.data(), handleTypeLength);
  }



  static bool classof(const Attr *A) { return A->getKind() == attr::ReleaseHandle; }
};

class RenderScriptKernelAttr : public Attr {
public:
  // Factory methods
  static RenderScriptKernelAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static RenderScriptKernelAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static RenderScriptKernelAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static RenderScriptKernelAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  RenderScriptKernelAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  RenderScriptKernelAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::RenderScriptKernel; }
};

class ReqdWorkGroupSizeAttr : public InheritableAttr {
unsigned xDim;

unsigned yDim;

unsigned zDim;

public:
  // Factory methods
  static ReqdWorkGroupSizeAttr *CreateImplicit(ASTContext &Ctx, unsigned XDim, unsigned YDim, unsigned ZDim, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static ReqdWorkGroupSizeAttr *Create(ASTContext &Ctx, unsigned XDim, unsigned YDim, unsigned ZDim, const AttributeCommonInfo &CommonInfo);
  static ReqdWorkGroupSizeAttr *CreateImplicit(ASTContext &Ctx, unsigned XDim, unsigned YDim, unsigned ZDim, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static ReqdWorkGroupSizeAttr *Create(ASTContext &Ctx, unsigned XDim, unsigned YDim, unsigned ZDim, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  ReqdWorkGroupSizeAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , unsigned XDim
              , unsigned YDim
              , unsigned ZDim
             );

  ReqdWorkGroupSizeAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  unsigned getXDim() const {
    return xDim;
  }

  unsigned getYDim() const {
    return yDim;
  }

  unsigned getZDim() const {
    return zDim;
  }



  static bool classof(const Attr *A) { return A->getKind() == attr::ReqdWorkGroupSize; }
};

class RequiresCapabilityAttr : public InheritableAttr {
  unsigned args_Size;
  Expr * *args_;

public:
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

  // Factory methods
  static RequiresCapabilityAttr *CreateImplicit(ASTContext &Ctx, Expr * *Args, unsigned ArgsSize, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static RequiresCapabilityAttr *Create(ASTContext &Ctx, Expr * *Args, unsigned ArgsSize, const AttributeCommonInfo &CommonInfo);
  static RequiresCapabilityAttr *CreateImplicit(ASTContext &Ctx, Expr * *Args, unsigned ArgsSize, SourceRange Range, AttributeCommonInfo::Syntax Syntax, RequiresCapabilityAttr::Spelling S = static_cast<Spelling>(SpellingNotCalculated));
  static RequiresCapabilityAttr *Create(ASTContext &Ctx, Expr * *Args, unsigned ArgsSize, SourceRange Range, AttributeCommonInfo::Syntax Syntax, RequiresCapabilityAttr::Spelling S = static_cast<Spelling>(SpellingNotCalculated));

  // Constructors
  RequiresCapabilityAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , Expr * *Args, unsigned ArgsSize
             );
  RequiresCapabilityAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  RequiresCapabilityAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  Spelling getSemanticSpelling() const;
  bool isShared() const { return getAttributeSpellingListIndex() == 4 ||
    getAttributeSpellingListIndex() == 5 ||
    getAttributeSpellingListIndex() == 6 ||
    getAttributeSpellingListIndex() == 7; }
  typedef Expr ** args_iterator;
  args_iterator args_begin() const { return args_; }
  args_iterator args_end() const { return args_ + args_Size; }
  unsigned args_size() const { return args_Size; }
  llvm::iterator_range<args_iterator> args() const { return llvm::make_range(args_begin(), args_end()); }




  static bool classof(const Attr *A) { return A->getKind() == attr::RequiresCapability; }
};

class RestrictAttr : public InheritableAttr {
public:
  enum Spelling {
    Declspec_restrict = 0,
    GNU_malloc = 1,
    CXX11_gnu_malloc = 2,
    C2x_gnu_malloc = 3,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static RestrictAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static RestrictAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static RestrictAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax, RestrictAttr::Spelling S = static_cast<Spelling>(SpellingNotCalculated));
  static RestrictAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax, RestrictAttr::Spelling S = static_cast<Spelling>(SpellingNotCalculated));

  // Constructors
  RestrictAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  RestrictAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  Spelling getSemanticSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::Restrict; }
};

class RetainAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_retain = 0,
    CXX11_gnu_retain = 1,
    C2x_gnu_retain = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static RetainAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static RetainAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static RetainAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static RetainAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  RetainAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  RetainAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::Retain; }
};

class ReturnTypestateAttr : public InheritableAttr {
public:
  enum ConsumedState {
    Unknown,
    Consumed,
    Unconsumed
  };
private:
  ConsumedState state;

public:
  enum Spelling {
    GNU_return_typestate = 0,
    CXX11_clang_return_typestate = 1,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static ReturnTypestateAttr *CreateImplicit(ASTContext &Ctx, ConsumedState State, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static ReturnTypestateAttr *Create(ASTContext &Ctx, ConsumedState State, const AttributeCommonInfo &CommonInfo);
  static ReturnTypestateAttr *CreateImplicit(ASTContext &Ctx, ConsumedState State, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static ReturnTypestateAttr *Create(ASTContext &Ctx, ConsumedState State, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  ReturnTypestateAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , ConsumedState State
             );

  ReturnTypestateAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  ConsumedState getState() const {
    return state;
  }

  static bool ConvertStrToConsumedState(StringRef Val, ConsumedState &Out);
  static const char *ConvertConsumedStateToStr(ConsumedState Val);


  static bool classof(const Attr *A) { return A->getKind() == attr::ReturnTypestate; }
};

class ReturnsNonNullAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_returns_nonnull = 0,
    CXX11_gnu_returns_nonnull = 1,
    C2x_gnu_returns_nonnull = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static ReturnsNonNullAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static ReturnsNonNullAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static ReturnsNonNullAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static ReturnsNonNullAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  ReturnsNonNullAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  ReturnsNonNullAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::ReturnsNonNull; }
};

class ReturnsTwiceAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_returns_twice = 0,
    CXX11_gnu_returns_twice = 1,
    C2x_gnu_returns_twice = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static ReturnsTwiceAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static ReturnsTwiceAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static ReturnsTwiceAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static ReturnsTwiceAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  ReturnsTwiceAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  ReturnsTwiceAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::ReturnsTwice; }
};

class SPtrAttr : public TypeAttr {
public:
  // Factory methods
  static SPtrAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static SPtrAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static SPtrAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static SPtrAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  SPtrAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  SPtrAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::SPtr; }
};

class SYCLKernelAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_sycl_kernel = 0,
    CXX11_clang_sycl_kernel = 1,
    C2x_clang_sycl_kernel = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static SYCLKernelAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static SYCLKernelAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static SYCLKernelAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static SYCLKernelAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  SYCLKernelAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  SYCLKernelAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::SYCLKernel; }
};

class ScopedLockableAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_scoped_lockable = 0,
    CXX11_clang_scoped_lockable = 1,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static ScopedLockableAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static ScopedLockableAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static ScopedLockableAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static ScopedLockableAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  ScopedLockableAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  ScopedLockableAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::ScopedLockable; }
};

class SectionAttr : public InheritableAttr {
unsigned nameLength;
char *name;

public:
  enum Spelling {
    GNU_section = 0,
    CXX11_gnu_section = 1,
    C2x_gnu_section = 2,
    Declspec_allocate = 3,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static SectionAttr *CreateImplicit(ASTContext &Ctx, llvm::StringRef Name, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static SectionAttr *Create(ASTContext &Ctx, llvm::StringRef Name, const AttributeCommonInfo &CommonInfo);
  static SectionAttr *CreateImplicit(ASTContext &Ctx, llvm::StringRef Name, SourceRange Range, AttributeCommonInfo::Syntax Syntax, SectionAttr::Spelling S = static_cast<Spelling>(SpellingNotCalculated));
  static SectionAttr *Create(ASTContext &Ctx, llvm::StringRef Name, SourceRange Range, AttributeCommonInfo::Syntax Syntax, SectionAttr::Spelling S = static_cast<Spelling>(SpellingNotCalculated));

  // Constructors
  SectionAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , llvm::StringRef Name
             );

  SectionAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  Spelling getSemanticSpelling() const;
  llvm::StringRef getName() const {
    return llvm::StringRef(name, nameLength);
  }
  unsigned getNameLength() const {
    return nameLength;
  }
  void setName(ASTContext &C, llvm::StringRef S) {
    nameLength = S.size();
    this->name = new (C, 1) char [nameLength];
    if (!S.empty())
      std::memcpy(this->name, S.data(), nameLength);
  }



  static bool classof(const Attr *A) { return A->getKind() == attr::Section; }
};

class SelectAnyAttr : public InheritableAttr {
public:
  enum Spelling {
    Declspec_selectany = 0,
    GNU_selectany = 1,
    CXX11_gnu_selectany = 2,
    C2x_gnu_selectany = 3,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static SelectAnyAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static SelectAnyAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static SelectAnyAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static SelectAnyAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  SelectAnyAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  SelectAnyAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::SelectAny; }
};

class SentinelAttr : public InheritableAttr {
int sentinel;

int nullPos;

public:
  enum Spelling {
    GNU_sentinel = 0,
    CXX11_gnu_sentinel = 1,
    C2x_gnu_sentinel = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static SentinelAttr *CreateImplicit(ASTContext &Ctx, int Sentinel, int NullPos, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static SentinelAttr *Create(ASTContext &Ctx, int Sentinel, int NullPos, const AttributeCommonInfo &CommonInfo);
  static SentinelAttr *CreateImplicit(ASTContext &Ctx, int Sentinel, int NullPos, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static SentinelAttr *Create(ASTContext &Ctx, int Sentinel, int NullPos, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  SentinelAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , int Sentinel
              , int NullPos
             );
  SentinelAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  SentinelAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  int getSentinel() const {
    return sentinel;
  }

  static const int DefaultSentinel = 0;

  int getNullPos() const {
    return nullPos;
  }

  static const int DefaultNullPos = 0;



  static bool classof(const Attr *A) { return A->getKind() == attr::Sentinel; }
};

class SetTypestateAttr : public InheritableAttr {
public:
  enum ConsumedState {
    Unknown,
    Consumed,
    Unconsumed
  };
private:
  ConsumedState newState;

public:
  enum Spelling {
    GNU_set_typestate = 0,
    CXX11_clang_set_typestate = 1,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static SetTypestateAttr *CreateImplicit(ASTContext &Ctx, ConsumedState NewState, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static SetTypestateAttr *Create(ASTContext &Ctx, ConsumedState NewState, const AttributeCommonInfo &CommonInfo);
  static SetTypestateAttr *CreateImplicit(ASTContext &Ctx, ConsumedState NewState, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static SetTypestateAttr *Create(ASTContext &Ctx, ConsumedState NewState, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  SetTypestateAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , ConsumedState NewState
             );

  SetTypestateAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  ConsumedState getNewState() const {
    return newState;
  }

  static bool ConvertStrToConsumedState(StringRef Val, ConsumedState &Out);
  static const char *ConvertConsumedStateToStr(ConsumedState Val);


  static bool classof(const Attr *A) { return A->getKind() == attr::SetTypestate; }
};

class SharedTrylockFunctionAttr : public InheritableAttr {
Expr * successValue;

  unsigned args_Size;
  Expr * *args_;

public:
  // Factory methods
  static SharedTrylockFunctionAttr *CreateImplicit(ASTContext &Ctx, Expr * SuccessValue, Expr * *Args, unsigned ArgsSize, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static SharedTrylockFunctionAttr *Create(ASTContext &Ctx, Expr * SuccessValue, Expr * *Args, unsigned ArgsSize, const AttributeCommonInfo &CommonInfo);
  static SharedTrylockFunctionAttr *CreateImplicit(ASTContext &Ctx, Expr * SuccessValue, Expr * *Args, unsigned ArgsSize, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static SharedTrylockFunctionAttr *Create(ASTContext &Ctx, Expr * SuccessValue, Expr * *Args, unsigned ArgsSize, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  SharedTrylockFunctionAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , Expr * SuccessValue
              , Expr * *Args, unsigned ArgsSize
             );
  SharedTrylockFunctionAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , Expr * SuccessValue
             );

  SharedTrylockFunctionAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  Expr * getSuccessValue() const {
    return successValue;
  }

  typedef Expr ** args_iterator;
  args_iterator args_begin() const { return args_; }
  args_iterator args_end() const { return args_ + args_Size; }
  unsigned args_size() const { return args_Size; }
  llvm::iterator_range<args_iterator> args() const { return llvm::make_range(args_begin(), args_end()); }




  static bool classof(const Attr *A) { return A->getKind() == attr::SharedTrylockFunction; }
};

class SpeculativeLoadHardeningAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_speculative_load_hardening = 0,
    CXX11_clang_speculative_load_hardening = 1,
    C2x_clang_speculative_load_hardening = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static SpeculativeLoadHardeningAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static SpeculativeLoadHardeningAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static SpeculativeLoadHardeningAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static SpeculativeLoadHardeningAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  SpeculativeLoadHardeningAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  SpeculativeLoadHardeningAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::SpeculativeLoadHardening; }
};

class StandaloneDebugAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_standalone_debug = 0,
    CXX11_clang_standalone_debug = 1,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static StandaloneDebugAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static StandaloneDebugAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static StandaloneDebugAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static StandaloneDebugAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  StandaloneDebugAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  StandaloneDebugAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::StandaloneDebug; }
};

class StdCallAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_stdcall = 0,
    CXX11_gnu_stdcall = 1,
    C2x_gnu_stdcall = 2,
    Keyword_stdcall = 3,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static StdCallAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static StdCallAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static StdCallAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static StdCallAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  StdCallAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  StdCallAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::StdCall; }
};

class StrictFPAttr : public InheritableAttr {
public:
  // Factory methods
  static StrictFPAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static StrictFPAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static StrictFPAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static StrictFPAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  StrictFPAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  StrictFPAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::StrictFP; }
};

class SuppressAttr : public StmtAttr {
  unsigned diagnosticIdentifiers_Size;
  StringRef *diagnosticIdentifiers_;

public:
  // Factory methods
  static SuppressAttr *CreateImplicit(ASTContext &Ctx, StringRef *DiagnosticIdentifiers, unsigned DiagnosticIdentifiersSize, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static SuppressAttr *Create(ASTContext &Ctx, StringRef *DiagnosticIdentifiers, unsigned DiagnosticIdentifiersSize, const AttributeCommonInfo &CommonInfo);
  static SuppressAttr *CreateImplicit(ASTContext &Ctx, StringRef *DiagnosticIdentifiers, unsigned DiagnosticIdentifiersSize, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static SuppressAttr *Create(ASTContext &Ctx, StringRef *DiagnosticIdentifiers, unsigned DiagnosticIdentifiersSize, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  SuppressAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , StringRef *DiagnosticIdentifiers, unsigned DiagnosticIdentifiersSize
             );
  SuppressAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  SuppressAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  typedef StringRef* diagnosticIdentifiers_iterator;
  diagnosticIdentifiers_iterator diagnosticIdentifiers_begin() const { return diagnosticIdentifiers_; }
  diagnosticIdentifiers_iterator diagnosticIdentifiers_end() const { return diagnosticIdentifiers_ + diagnosticIdentifiers_Size; }
  unsigned diagnosticIdentifiers_size() const { return diagnosticIdentifiers_Size; }
  llvm::iterator_range<diagnosticIdentifiers_iterator> diagnosticIdentifiers() const { return llvm::make_range(diagnosticIdentifiers_begin(), diagnosticIdentifiers_end()); }




  static bool classof(const Attr *A) { return A->getKind() == attr::Suppress; }
};

class SwiftAsyncAttr : public InheritableAttr {
public:
  enum Kind {
    None,
    SwiftPrivate,
    NotSwiftPrivate
  };
private:
  Kind kind;

ParamIdx completionHandlerIndex;

public:
  enum Spelling {
    GNU_swift_async = 0,
    CXX11_clang_swift_async = 1,
    C2x_clang_swift_async = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static SwiftAsyncAttr *CreateImplicit(ASTContext &Ctx, Kind Kind, ParamIdx CompletionHandlerIndex, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static SwiftAsyncAttr *Create(ASTContext &Ctx, Kind Kind, ParamIdx CompletionHandlerIndex, const AttributeCommonInfo &CommonInfo);
  static SwiftAsyncAttr *CreateImplicit(ASTContext &Ctx, Kind Kind, ParamIdx CompletionHandlerIndex, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static SwiftAsyncAttr *Create(ASTContext &Ctx, Kind Kind, ParamIdx CompletionHandlerIndex, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  SwiftAsyncAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , Kind Kind
              , ParamIdx CompletionHandlerIndex
             );
  SwiftAsyncAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , Kind Kind
             );

  SwiftAsyncAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  Kind getKind() const {
    return kind;
  }

  static bool ConvertStrToKind(StringRef Val, Kind &Out);
  static const char *ConvertKindToStr(Kind Val);
  ParamIdx getCompletionHandlerIndex() const {
    return completionHandlerIndex;
  }



  static bool classof(const Attr *A) { return A->getKind() == attr::SwiftAsync; }
};

class SwiftAsyncCallAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_swiftasynccall = 0,
    CXX11_clang_swiftasynccall = 1,
    C2x_clang_swiftasynccall = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static SwiftAsyncCallAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static SwiftAsyncCallAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static SwiftAsyncCallAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static SwiftAsyncCallAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  SwiftAsyncCallAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  SwiftAsyncCallAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::SwiftAsyncCall; }
};

class SwiftAsyncContextAttr : public ParameterABIAttr {
public:
  enum Spelling {
    GNU_swift_async_context = 0,
    CXX11_clang_swift_async_context = 1,
    C2x_clang_swift_async_context = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static SwiftAsyncContextAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static SwiftAsyncContextAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static SwiftAsyncContextAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static SwiftAsyncContextAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  SwiftAsyncContextAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  SwiftAsyncContextAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::SwiftAsyncContext; }
};

class SwiftAsyncErrorAttr : public InheritableAttr {
public:
  enum ConventionKind {
    None,
    NonNullError,
    ZeroArgument,
    NonZeroArgument
  };
private:
  ConventionKind convention;

unsigned handlerParamIdx;

public:
  enum Spelling {
    GNU_swift_async_error = 0,
    CXX11_clang_swift_async_error = 1,
    C2x_clang_swift_async_error = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static SwiftAsyncErrorAttr *CreateImplicit(ASTContext &Ctx, ConventionKind Convention, unsigned HandlerParamIdx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static SwiftAsyncErrorAttr *Create(ASTContext &Ctx, ConventionKind Convention, unsigned HandlerParamIdx, const AttributeCommonInfo &CommonInfo);
  static SwiftAsyncErrorAttr *CreateImplicit(ASTContext &Ctx, ConventionKind Convention, unsigned HandlerParamIdx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static SwiftAsyncErrorAttr *Create(ASTContext &Ctx, ConventionKind Convention, unsigned HandlerParamIdx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  SwiftAsyncErrorAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , ConventionKind Convention
              , unsigned HandlerParamIdx
             );
  SwiftAsyncErrorAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , ConventionKind Convention
             );

  SwiftAsyncErrorAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  ConventionKind getConvention() const {
    return convention;
  }

  static bool ConvertStrToConventionKind(StringRef Val, ConventionKind &Out);
  static const char *ConvertConventionKindToStr(ConventionKind Val);
  unsigned getHandlerParamIdx() const {
    return handlerParamIdx;
  }



  static bool classof(const Attr *A) { return A->getKind() == attr::SwiftAsyncError; }
};

class SwiftAsyncNameAttr : public InheritableAttr {
unsigned nameLength;
char *name;

public:
  // Factory methods
  static SwiftAsyncNameAttr *CreateImplicit(ASTContext &Ctx, llvm::StringRef Name, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static SwiftAsyncNameAttr *Create(ASTContext &Ctx, llvm::StringRef Name, const AttributeCommonInfo &CommonInfo);
  static SwiftAsyncNameAttr *CreateImplicit(ASTContext &Ctx, llvm::StringRef Name, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static SwiftAsyncNameAttr *Create(ASTContext &Ctx, llvm::StringRef Name, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  SwiftAsyncNameAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , llvm::StringRef Name
             );

  SwiftAsyncNameAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  llvm::StringRef getName() const {
    return llvm::StringRef(name, nameLength);
  }
  unsigned getNameLength() const {
    return nameLength;
  }
  void setName(ASTContext &C, llvm::StringRef S) {
    nameLength = S.size();
    this->name = new (C, 1) char [nameLength];
    if (!S.empty())
      std::memcpy(this->name, S.data(), nameLength);
  }



  static bool classof(const Attr *A) { return A->getKind() == attr::SwiftAsyncName; }
};

class SwiftAttrAttr : public InheritableAttr {
unsigned attributeLength;
char *attribute;

public:
  // Factory methods
  static SwiftAttrAttr *CreateImplicit(ASTContext &Ctx, llvm::StringRef Attribute, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static SwiftAttrAttr *Create(ASTContext &Ctx, llvm::StringRef Attribute, const AttributeCommonInfo &CommonInfo);
  static SwiftAttrAttr *CreateImplicit(ASTContext &Ctx, llvm::StringRef Attribute, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static SwiftAttrAttr *Create(ASTContext &Ctx, llvm::StringRef Attribute, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  SwiftAttrAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , llvm::StringRef Attribute
             );

  SwiftAttrAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  llvm::StringRef getAttribute() const {
    return llvm::StringRef(attribute, attributeLength);
  }
  unsigned getAttributeLength() const {
    return attributeLength;
  }
  void setAttribute(ASTContext &C, llvm::StringRef S) {
    attributeLength = S.size();
    this->attribute = new (C, 1) char [attributeLength];
    if (!S.empty())
      std::memcpy(this->attribute, S.data(), attributeLength);
  }



  static bool classof(const Attr *A) { return A->getKind() == attr::SwiftAttr; }
};

class SwiftBridgeAttr : public InheritableAttr {
unsigned swiftTypeLength;
char *swiftType;

public:
  // Factory methods
  static SwiftBridgeAttr *CreateImplicit(ASTContext &Ctx, llvm::StringRef SwiftType, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static SwiftBridgeAttr *Create(ASTContext &Ctx, llvm::StringRef SwiftType, const AttributeCommonInfo &CommonInfo);
  static SwiftBridgeAttr *CreateImplicit(ASTContext &Ctx, llvm::StringRef SwiftType, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static SwiftBridgeAttr *Create(ASTContext &Ctx, llvm::StringRef SwiftType, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  SwiftBridgeAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , llvm::StringRef SwiftType
             );

  SwiftBridgeAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  llvm::StringRef getSwiftType() const {
    return llvm::StringRef(swiftType, swiftTypeLength);
  }
  unsigned getSwiftTypeLength() const {
    return swiftTypeLength;
  }
  void setSwiftType(ASTContext &C, llvm::StringRef S) {
    swiftTypeLength = S.size();
    this->swiftType = new (C, 1) char [swiftTypeLength];
    if (!S.empty())
      std::memcpy(this->swiftType, S.data(), swiftTypeLength);
  }



  static bool classof(const Attr *A) { return A->getKind() == attr::SwiftBridge; }
};

class SwiftBridgedTypedefAttr : public InheritableAttr {
public:
  // Factory methods
  static SwiftBridgedTypedefAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static SwiftBridgedTypedefAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static SwiftBridgedTypedefAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static SwiftBridgedTypedefAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  SwiftBridgedTypedefAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  SwiftBridgedTypedefAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::SwiftBridgedTypedef; }
};

class SwiftCallAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_swiftcall = 0,
    CXX11_clang_swiftcall = 1,
    C2x_clang_swiftcall = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static SwiftCallAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static SwiftCallAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static SwiftCallAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static SwiftCallAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  SwiftCallAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  SwiftCallAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::SwiftCall; }
};

class SwiftContextAttr : public ParameterABIAttr {
public:
  enum Spelling {
    GNU_swift_context = 0,
    CXX11_clang_swift_context = 1,
    C2x_clang_swift_context = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static SwiftContextAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static SwiftContextAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static SwiftContextAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static SwiftContextAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  SwiftContextAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  SwiftContextAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::SwiftContext; }
};

class SwiftErrorAttr : public InheritableAttr {
public:
  enum ConventionKind {
    None,
    NonNullError,
    NullResult,
    ZeroResult,
    NonZeroResult
  };
private:
  ConventionKind convention;

public:
  // Factory methods
  static SwiftErrorAttr *CreateImplicit(ASTContext &Ctx, ConventionKind Convention, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static SwiftErrorAttr *Create(ASTContext &Ctx, ConventionKind Convention, const AttributeCommonInfo &CommonInfo);
  static SwiftErrorAttr *CreateImplicit(ASTContext &Ctx, ConventionKind Convention, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static SwiftErrorAttr *Create(ASTContext &Ctx, ConventionKind Convention, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  SwiftErrorAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , ConventionKind Convention
             );

  SwiftErrorAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  ConventionKind getConvention() const {
    return convention;
  }

  static bool ConvertStrToConventionKind(StringRef Val, ConventionKind &Out);
  static const char *ConvertConventionKindToStr(ConventionKind Val);


  static bool classof(const Attr *A) { return A->getKind() == attr::SwiftError; }
};

class SwiftErrorResultAttr : public ParameterABIAttr {
public:
  enum Spelling {
    GNU_swift_error_result = 0,
    CXX11_clang_swift_error_result = 1,
    C2x_clang_swift_error_result = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static SwiftErrorResultAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static SwiftErrorResultAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static SwiftErrorResultAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static SwiftErrorResultAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  SwiftErrorResultAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  SwiftErrorResultAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::SwiftErrorResult; }
};

class SwiftIndirectResultAttr : public ParameterABIAttr {
public:
  enum Spelling {
    GNU_swift_indirect_result = 0,
    CXX11_clang_swift_indirect_result = 1,
    C2x_clang_swift_indirect_result = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static SwiftIndirectResultAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static SwiftIndirectResultAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static SwiftIndirectResultAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static SwiftIndirectResultAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  SwiftIndirectResultAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  SwiftIndirectResultAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::SwiftIndirectResult; }
};

class SwiftNameAttr : public InheritableAttr {
unsigned nameLength;
char *name;

public:
  // Factory methods
  static SwiftNameAttr *CreateImplicit(ASTContext &Ctx, llvm::StringRef Name, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static SwiftNameAttr *Create(ASTContext &Ctx, llvm::StringRef Name, const AttributeCommonInfo &CommonInfo);
  static SwiftNameAttr *CreateImplicit(ASTContext &Ctx, llvm::StringRef Name, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static SwiftNameAttr *Create(ASTContext &Ctx, llvm::StringRef Name, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  SwiftNameAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , llvm::StringRef Name
             );

  SwiftNameAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  llvm::StringRef getName() const {
    return llvm::StringRef(name, nameLength);
  }
  unsigned getNameLength() const {
    return nameLength;
  }
  void setName(ASTContext &C, llvm::StringRef S) {
    nameLength = S.size();
    this->name = new (C, 1) char [nameLength];
    if (!S.empty())
      std::memcpy(this->name, S.data(), nameLength);
  }



  static bool classof(const Attr *A) { return A->getKind() == attr::SwiftName; }
};

class SwiftNewTypeAttr : public InheritableAttr {
public:
  enum NewtypeKind {
    NK_Struct,
    NK_Enum
  };
private:
  NewtypeKind newtypeKind;

public:
  enum Spelling {
    GNU_swift_newtype = 0,
    GNU_swift_wrapper = 1,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static SwiftNewTypeAttr *CreateImplicit(ASTContext &Ctx, NewtypeKind NewtypeKind, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static SwiftNewTypeAttr *Create(ASTContext &Ctx, NewtypeKind NewtypeKind, const AttributeCommonInfo &CommonInfo);
  static SwiftNewTypeAttr *CreateImplicit(ASTContext &Ctx, NewtypeKind NewtypeKind, SourceRange Range, AttributeCommonInfo::Syntax Syntax, SwiftNewTypeAttr::Spelling S = static_cast<Spelling>(SpellingNotCalculated));
  static SwiftNewTypeAttr *Create(ASTContext &Ctx, NewtypeKind NewtypeKind, SourceRange Range, AttributeCommonInfo::Syntax Syntax, SwiftNewTypeAttr::Spelling S = static_cast<Spelling>(SpellingNotCalculated));

  // Constructors
  SwiftNewTypeAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , NewtypeKind NewtypeKind
             );

  SwiftNewTypeAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  Spelling getSemanticSpelling() const;
  NewtypeKind getNewtypeKind() const {
    return newtypeKind;
  }

  static bool ConvertStrToNewtypeKind(StringRef Val, NewtypeKind &Out);
  static const char *ConvertNewtypeKindToStr(NewtypeKind Val);


  static bool classof(const Attr *A) { return A->getKind() == attr::SwiftNewType; }
};

class SwiftObjCMembersAttr : public Attr {
public:
  // Factory methods
  static SwiftObjCMembersAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static SwiftObjCMembersAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static SwiftObjCMembersAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static SwiftObjCMembersAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  SwiftObjCMembersAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  SwiftObjCMembersAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::SwiftObjCMembers; }
};

class SwiftPrivateAttr : public InheritableAttr {
public:
  // Factory methods
  static SwiftPrivateAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static SwiftPrivateAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static SwiftPrivateAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static SwiftPrivateAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  SwiftPrivateAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  SwiftPrivateAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::SwiftPrivate; }
};

class SysVABIAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_sysv_abi = 0,
    CXX11_gnu_sysv_abi = 1,
    C2x_gnu_sysv_abi = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static SysVABIAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static SysVABIAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static SysVABIAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static SysVABIAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  SysVABIAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  SysVABIAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::SysVABI; }
};

class TLSModelAttr : public InheritableAttr {
unsigned modelLength;
char *model;

public:
  enum Spelling {
    GNU_tls_model = 0,
    CXX11_gnu_tls_model = 1,
    C2x_gnu_tls_model = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static TLSModelAttr *CreateImplicit(ASTContext &Ctx, llvm::StringRef Model, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static TLSModelAttr *Create(ASTContext &Ctx, llvm::StringRef Model, const AttributeCommonInfo &CommonInfo);
  static TLSModelAttr *CreateImplicit(ASTContext &Ctx, llvm::StringRef Model, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static TLSModelAttr *Create(ASTContext &Ctx, llvm::StringRef Model, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  TLSModelAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , llvm::StringRef Model
             );

  TLSModelAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  llvm::StringRef getModel() const {
    return llvm::StringRef(model, modelLength);
  }
  unsigned getModelLength() const {
    return modelLength;
  }
  void setModel(ASTContext &C, llvm::StringRef S) {
    modelLength = S.size();
    this->model = new (C, 1) char [modelLength];
    if (!S.empty())
      std::memcpy(this->model, S.data(), modelLength);
  }



  static bool classof(const Attr *A) { return A->getKind() == attr::TLSModel; }
};

class TargetAttr : public InheritableAttr {
unsigned featuresStrLength;
char *featuresStr;

public:
  enum Spelling {
    GNU_target = 0,
    CXX11_gnu_target = 1,
    C2x_gnu_target = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static TargetAttr *CreateImplicit(ASTContext &Ctx, llvm::StringRef FeaturesStr, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static TargetAttr *Create(ASTContext &Ctx, llvm::StringRef FeaturesStr, const AttributeCommonInfo &CommonInfo);
  static TargetAttr *CreateImplicit(ASTContext &Ctx, llvm::StringRef FeaturesStr, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static TargetAttr *Create(ASTContext &Ctx, llvm::StringRef FeaturesStr, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  TargetAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , llvm::StringRef FeaturesStr
             );

  TargetAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  llvm::StringRef getFeaturesStr() const {
    return llvm::StringRef(featuresStr, featuresStrLength);
  }
  unsigned getFeaturesStrLength() const {
    return featuresStrLength;
  }
  void setFeaturesStr(ASTContext &C, llvm::StringRef S) {
    featuresStrLength = S.size();
    this->featuresStr = new (C, 1) char [featuresStrLength];
    if (!S.empty())
      std::memcpy(this->featuresStr, S.data(), featuresStrLength);
  }


    ParsedTargetAttr parse() const {
      return parse(getFeaturesStr());
    }

    StringRef getArchitecture() const {
      StringRef Features = getFeaturesStr();
      if (Features == "default") return {};

      SmallVector<StringRef, 1> AttrFeatures;
      Features.split(AttrFeatures, ",");

      for (auto &Feature : AttrFeatures) {
        Feature = Feature.trim();
        if (Feature.startswith("arch="))
          return Feature.drop_front(sizeof("arch=") - 1);
      }
      return "";
    }

    // Gets the list of features as simple string-refs with no +/- or 'no-'.
    // Only adds the items to 'Out' that are additions.
    void getAddedFeatures(llvm::SmallVectorImpl<StringRef> &Out) const {
      StringRef Features = getFeaturesStr();
      if (Features == "default") return;

      SmallVector<StringRef, 1> AttrFeatures;
      Features.split(AttrFeatures, ",");

      for (auto &Feature : AttrFeatures) {
        Feature = Feature.trim();

        if (!Feature.startswith("no-") && !Feature.startswith("arch=") &&
            !Feature.startswith("fpmath=") && !Feature.startswith("tune="))
          Out.push_back(Feature);
      }
    }

    template<class Compare>
    ParsedTargetAttr parse(Compare cmp) const {
      ParsedTargetAttr Attrs = parse();
      llvm::sort(std::begin(Attrs.Features), std::end(Attrs.Features), cmp);
      return Attrs;
    }

    bool isDefaultVersion() const { return getFeaturesStr() == "default"; }

    static ParsedTargetAttr parse(StringRef Features) {
      ParsedTargetAttr Ret;
      if (Features == "default") return Ret;
      SmallVector<StringRef, 1> AttrFeatures;
      Features.split(AttrFeatures, ",");

      // Grab the various features and prepend a "+" to turn on the feature to
      // the backend and add them to our existing set of features.
      for (auto &Feature : AttrFeatures) {
        // Go ahead and trim whitespace rather than either erroring or
        // accepting it weirdly.
        Feature = Feature.trim();

        // TODO: Support the fpmath option. It will require checking
        // overall feature validity for the function with the rest of the
        // attributes on the function.
        if (Feature.startswith("fpmath="))
          continue;

        if (Feature.startswith("branch-protection=")) {
          Ret.BranchProtection = Feature.split('=').second.trim();
          continue;
        }

        // While we're here iterating check for a different target cpu.
        if (Feature.startswith("arch=")) {
          if (!Ret.Architecture.empty())
            Ret.DuplicateArchitecture = true;
          else
            Ret.Architecture = Feature.split("=").second.trim();
        } else if (Feature.startswith("tune=")) {
          if (!Ret.Tune.empty())
            Ret.DuplicateTune = true;
          else
            Ret.Tune = Feature.split("=").second.trim();
        } else if (Feature.startswith("no-"))
          Ret.Features.push_back("-" + Feature.split("-").second.str());
        else
          Ret.Features.push_back("+" + Feature.str());
      }
      return Ret;
    }
  

  static bool classof(const Attr *A) { return A->getKind() == attr::Target; }
};

class TargetClonesAttr : public InheritableAttr {
  unsigned featuresStrs_Size;
  StringRef *featuresStrs_;

public:
  enum Spelling {
    GNU_target_clones = 0,
    CXX11_gnu_target_clones = 1,
    C2x_gnu_target_clones = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static TargetClonesAttr *CreateImplicit(ASTContext &Ctx, StringRef *FeaturesStrs, unsigned FeaturesStrsSize, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static TargetClonesAttr *Create(ASTContext &Ctx, StringRef *FeaturesStrs, unsigned FeaturesStrsSize, const AttributeCommonInfo &CommonInfo);
  static TargetClonesAttr *CreateImplicit(ASTContext &Ctx, StringRef *FeaturesStrs, unsigned FeaturesStrsSize, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static TargetClonesAttr *Create(ASTContext &Ctx, StringRef *FeaturesStrs, unsigned FeaturesStrsSize, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  TargetClonesAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , StringRef *FeaturesStrs, unsigned FeaturesStrsSize
             );
  TargetClonesAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  TargetClonesAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  typedef StringRef* featuresStrs_iterator;
  featuresStrs_iterator featuresStrs_begin() const { return featuresStrs_; }
  featuresStrs_iterator featuresStrs_end() const { return featuresStrs_ + featuresStrs_Size; }
  unsigned featuresStrs_size() const { return featuresStrs_Size; }
  llvm::iterator_range<featuresStrs_iterator> featuresStrs() const { return llvm::make_range(featuresStrs_begin(), featuresStrs_end()); }



    StringRef getFeatureStr(unsigned Index) const {
      return *(featuresStrs_begin() + Index);
    }
    // 'default' is always moved to the end, so it isn't considered
    // when mangling the index.
    unsigned getMangledIndex(unsigned Index) const {
      if (getFeatureStr(Index) == "default")
        return std::count_if(featuresStrs_begin(), featuresStrs_end(),
                              [](StringRef S) { return S != "default"; });

      return std::count_if(featuresStrs_begin(), featuresStrs_begin() + Index,
                           [](StringRef S) { return S != "default"; });
    }

    // True if this is the first of this version to appear in the config string.
    // This is used to make sure we don't try to emit this function multiple
    // times.
    bool isFirstOfVersion(unsigned Index) const {
      StringRef FeatureStr(getFeatureStr(Index));
      return 0 == std::count_if(
                      featuresStrs_begin(), featuresStrs_begin() + Index,
                      [FeatureStr](StringRef S) { return S == FeatureStr; });
    }
  

  static bool classof(const Attr *A) { return A->getKind() == attr::TargetClones; }
};

class TestTypestateAttr : public InheritableAttr {
public:
  enum ConsumedState {
    Consumed,
    Unconsumed
  };
private:
  ConsumedState testState;

public:
  enum Spelling {
    GNU_test_typestate = 0,
    CXX11_clang_test_typestate = 1,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static TestTypestateAttr *CreateImplicit(ASTContext &Ctx, ConsumedState TestState, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static TestTypestateAttr *Create(ASTContext &Ctx, ConsumedState TestState, const AttributeCommonInfo &CommonInfo);
  static TestTypestateAttr *CreateImplicit(ASTContext &Ctx, ConsumedState TestState, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static TestTypestateAttr *Create(ASTContext &Ctx, ConsumedState TestState, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  TestTypestateAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , ConsumedState TestState
             );

  TestTypestateAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  ConsumedState getTestState() const {
    return testState;
  }

  static bool ConvertStrToConsumedState(StringRef Val, ConsumedState &Out);
  static const char *ConvertConsumedStateToStr(ConsumedState Val);


  static bool classof(const Attr *A) { return A->getKind() == attr::TestTypestate; }
};

class ThisCallAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_thiscall = 0,
    CXX11_gnu_thiscall = 1,
    C2x_gnu_thiscall = 2,
    Keyword_thiscall = 3,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static ThisCallAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static ThisCallAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static ThisCallAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static ThisCallAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  ThisCallAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  ThisCallAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::ThisCall; }
};

class ThreadAttr : public Attr {
public:
  // Factory methods
  static ThreadAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static ThreadAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static ThreadAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static ThreadAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  ThreadAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  ThreadAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::Thread; }
};

class TransparentUnionAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_transparent_union = 0,
    CXX11_gnu_transparent_union = 1,
    C2x_gnu_transparent_union = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static TransparentUnionAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static TransparentUnionAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static TransparentUnionAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static TransparentUnionAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  TransparentUnionAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  TransparentUnionAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::TransparentUnion; }
};

class TrivialABIAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_trivial_abi = 0,
    CXX11_clang_trivial_abi = 1,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static TrivialABIAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static TrivialABIAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static TrivialABIAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static TrivialABIAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  TrivialABIAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  TrivialABIAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::TrivialABI; }
};

class TryAcquireCapabilityAttr : public InheritableAttr {
Expr * successValue;

  unsigned args_Size;
  Expr * *args_;

public:
  enum Spelling {
    GNU_try_acquire_capability = 0,
    CXX11_clang_try_acquire_capability = 1,
    GNU_try_acquire_shared_capability = 2,
    CXX11_clang_try_acquire_shared_capability = 3,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static TryAcquireCapabilityAttr *CreateImplicit(ASTContext &Ctx, Expr * SuccessValue, Expr * *Args, unsigned ArgsSize, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static TryAcquireCapabilityAttr *Create(ASTContext &Ctx, Expr * SuccessValue, Expr * *Args, unsigned ArgsSize, const AttributeCommonInfo &CommonInfo);
  static TryAcquireCapabilityAttr *CreateImplicit(ASTContext &Ctx, Expr * SuccessValue, Expr * *Args, unsigned ArgsSize, SourceRange Range, AttributeCommonInfo::Syntax Syntax, TryAcquireCapabilityAttr::Spelling S = static_cast<Spelling>(SpellingNotCalculated));
  static TryAcquireCapabilityAttr *Create(ASTContext &Ctx, Expr * SuccessValue, Expr * *Args, unsigned ArgsSize, SourceRange Range, AttributeCommonInfo::Syntax Syntax, TryAcquireCapabilityAttr::Spelling S = static_cast<Spelling>(SpellingNotCalculated));

  // Constructors
  TryAcquireCapabilityAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , Expr * SuccessValue
              , Expr * *Args, unsigned ArgsSize
             );
  TryAcquireCapabilityAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , Expr * SuccessValue
             );

  TryAcquireCapabilityAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  Spelling getSemanticSpelling() const;
  bool isShared() const { return getAttributeSpellingListIndex() == 2 ||
    getAttributeSpellingListIndex() == 3; }
  Expr * getSuccessValue() const {
    return successValue;
  }

  typedef Expr ** args_iterator;
  args_iterator args_begin() const { return args_; }
  args_iterator args_end() const { return args_ + args_Size; }
  unsigned args_size() const { return args_Size; }
  llvm::iterator_range<args_iterator> args() const { return llvm::make_range(args_begin(), args_end()); }




  static bool classof(const Attr *A) { return A->getKind() == attr::TryAcquireCapability; }
};

class TypeNonNullAttr : public TypeAttr {
public:
  // Factory methods
  static TypeNonNullAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static TypeNonNullAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static TypeNonNullAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static TypeNonNullAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  TypeNonNullAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  TypeNonNullAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::TypeNonNull; }
};

class TypeNullUnspecifiedAttr : public TypeAttr {
public:
  // Factory methods
  static TypeNullUnspecifiedAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static TypeNullUnspecifiedAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static TypeNullUnspecifiedAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static TypeNullUnspecifiedAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  TypeNullUnspecifiedAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  TypeNullUnspecifiedAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::TypeNullUnspecified; }
};

class TypeNullableAttr : public TypeAttr {
public:
  // Factory methods
  static TypeNullableAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static TypeNullableAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static TypeNullableAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static TypeNullableAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  TypeNullableAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  TypeNullableAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::TypeNullable; }
};

class TypeNullableResultAttr : public TypeAttr {
public:
  // Factory methods
  static TypeNullableResultAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static TypeNullableResultAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static TypeNullableResultAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static TypeNullableResultAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  TypeNullableResultAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  TypeNullableResultAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::TypeNullableResult; }
};

class TypeTagForDatatypeAttr : public InheritableAttr {
IdentifierInfo * argumentKind;

TypeSourceInfo * matchingCType;

bool layoutCompatible;

bool mustBeNull;

public:
  enum Spelling {
    GNU_type_tag_for_datatype = 0,
    CXX11_clang_type_tag_for_datatype = 1,
    C2x_clang_type_tag_for_datatype = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static TypeTagForDatatypeAttr *CreateImplicit(ASTContext &Ctx, IdentifierInfo * ArgumentKind, TypeSourceInfo * MatchingCType, bool LayoutCompatible, bool MustBeNull, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static TypeTagForDatatypeAttr *Create(ASTContext &Ctx, IdentifierInfo * ArgumentKind, TypeSourceInfo * MatchingCType, bool LayoutCompatible, bool MustBeNull, const AttributeCommonInfo &CommonInfo);
  static TypeTagForDatatypeAttr *CreateImplicit(ASTContext &Ctx, IdentifierInfo * ArgumentKind, TypeSourceInfo * MatchingCType, bool LayoutCompatible, bool MustBeNull, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static TypeTagForDatatypeAttr *Create(ASTContext &Ctx, IdentifierInfo * ArgumentKind, TypeSourceInfo * MatchingCType, bool LayoutCompatible, bool MustBeNull, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  TypeTagForDatatypeAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , IdentifierInfo * ArgumentKind
              , TypeSourceInfo * MatchingCType
              , bool LayoutCompatible
              , bool MustBeNull
             );

  TypeTagForDatatypeAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  IdentifierInfo * getArgumentKind() const {
    return argumentKind;
  }

  QualType getMatchingCType() const {
    return matchingCType->getType();
  }  TypeSourceInfo * getMatchingCTypeLoc() const {
    return matchingCType;
  }

  bool getLayoutCompatible() const {
    return layoutCompatible;
  }

  bool getMustBeNull() const {
    return mustBeNull;
  }



  static bool classof(const Attr *A) { return A->getKind() == attr::TypeTagForDatatype; }
};

class TypeVisibilityAttr : public InheritableAttr {
public:
  enum VisibilityType {
    Default,
    Hidden,
    Protected
  };
private:
  VisibilityType visibility;

public:
  enum Spelling {
    GNU_type_visibility = 0,
    CXX11_clang_type_visibility = 1,
    C2x_clang_type_visibility = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static TypeVisibilityAttr *CreateImplicit(ASTContext &Ctx, VisibilityType Visibility, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static TypeVisibilityAttr *Create(ASTContext &Ctx, VisibilityType Visibility, const AttributeCommonInfo &CommonInfo);
  static TypeVisibilityAttr *CreateImplicit(ASTContext &Ctx, VisibilityType Visibility, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static TypeVisibilityAttr *Create(ASTContext &Ctx, VisibilityType Visibility, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  TypeVisibilityAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , VisibilityType Visibility
             );

  TypeVisibilityAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  VisibilityType getVisibility() const {
    return visibility;
  }

  static bool ConvertStrToVisibilityType(StringRef Val, VisibilityType &Out);
  static const char *ConvertVisibilityTypeToStr(VisibilityType Val);


  static bool classof(const Attr *A) { return A->getKind() == attr::TypeVisibility; }
};

class UPtrAttr : public TypeAttr {
public:
  // Factory methods
  static UPtrAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static UPtrAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static UPtrAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static UPtrAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  UPtrAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  UPtrAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::UPtr; }
};

class UnavailableAttr : public InheritableAttr {
unsigned messageLength;
char *message;

public:
  enum ImplicitReason {
    IR_None,
    IR_ARCForbiddenType,
    IR_ForbiddenWeak,
    IR_ARCForbiddenConversion,
    IR_ARCInitReturnsUnrelated,
    IR_ARCFieldWithOwnership
  };
private:
  ImplicitReason implicitReason;

public:
  enum Spelling {
    GNU_unavailable = 0,
    CXX11_clang_unavailable = 1,
    C2x_clang_unavailable = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static UnavailableAttr *CreateImplicit(ASTContext &Ctx, llvm::StringRef Message, ImplicitReason ImplicitReason, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static UnavailableAttr *Create(ASTContext &Ctx, llvm::StringRef Message, ImplicitReason ImplicitReason, const AttributeCommonInfo &CommonInfo);
  static UnavailableAttr *CreateImplicit(ASTContext &Ctx, llvm::StringRef Message, ImplicitReason ImplicitReason, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static UnavailableAttr *Create(ASTContext &Ctx, llvm::StringRef Message, ImplicitReason ImplicitReason, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static UnavailableAttr *CreateImplicit(ASTContext &Ctx, llvm::StringRef Message, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static UnavailableAttr *Create(ASTContext &Ctx, llvm::StringRef Message, const AttributeCommonInfo &CommonInfo);
  static UnavailableAttr *CreateImplicit(ASTContext &Ctx, llvm::StringRef Message, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static UnavailableAttr *Create(ASTContext &Ctx, llvm::StringRef Message, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  UnavailableAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , llvm::StringRef Message
              , ImplicitReason ImplicitReason
             );
  UnavailableAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , llvm::StringRef Message
             );
  UnavailableAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  UnavailableAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  llvm::StringRef getMessage() const {
    return llvm::StringRef(message, messageLength);
  }
  unsigned getMessageLength() const {
    return messageLength;
  }
  void setMessage(ASTContext &C, llvm::StringRef S) {
    messageLength = S.size();
    this->message = new (C, 1) char [messageLength];
    if (!S.empty())
      std::memcpy(this->message, S.data(), messageLength);
  }

  ImplicitReason getImplicitReason() const {
    return implicitReason;
  }



  static bool classof(const Attr *A) { return A->getKind() == attr::Unavailable; }
};

class UninitializedAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_uninitialized = 0,
    CXX11_clang_uninitialized = 1,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static UninitializedAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static UninitializedAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static UninitializedAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static UninitializedAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  UninitializedAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  UninitializedAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::Uninitialized; }
};

class UnlikelyAttr : public StmtAttr {
public:
  enum Spelling {
    CXX11_unlikely = 0,
    C2x_clang_unlikely = 1,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static UnlikelyAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static UnlikelyAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static UnlikelyAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static UnlikelyAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  UnlikelyAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  UnlikelyAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::Unlikely; }
};

class UnusedAttr : public InheritableAttr {
public:
  enum Spelling {
    CXX11_maybe_unused = 0,
    GNU_unused = 1,
    CXX11_gnu_unused = 2,
    C2x_gnu_unused = 3,
    C2x_maybe_unused = 4,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static UnusedAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static UnusedAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static UnusedAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax, UnusedAttr::Spelling S = static_cast<Spelling>(SpellingNotCalculated));
  static UnusedAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax, UnusedAttr::Spelling S = static_cast<Spelling>(SpellingNotCalculated));

  // Constructors
  UnusedAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  UnusedAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  Spelling getSemanticSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::Unused; }
};

class UseHandleAttr : public InheritableParamAttr {
unsigned handleTypeLength;
char *handleType;

public:
  enum Spelling {
    GNU_use_handle = 0,
    CXX11_clang_use_handle = 1,
    C2x_clang_use_handle = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static UseHandleAttr *CreateImplicit(ASTContext &Ctx, llvm::StringRef HandleType, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static UseHandleAttr *Create(ASTContext &Ctx, llvm::StringRef HandleType, const AttributeCommonInfo &CommonInfo);
  static UseHandleAttr *CreateImplicit(ASTContext &Ctx, llvm::StringRef HandleType, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static UseHandleAttr *Create(ASTContext &Ctx, llvm::StringRef HandleType, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  UseHandleAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , llvm::StringRef HandleType
             );

  UseHandleAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  llvm::StringRef getHandleType() const {
    return llvm::StringRef(handleType, handleTypeLength);
  }
  unsigned getHandleTypeLength() const {
    return handleTypeLength;
  }
  void setHandleType(ASTContext &C, llvm::StringRef S) {
    handleTypeLength = S.size();
    this->handleType = new (C, 1) char [handleTypeLength];
    if (!S.empty())
      std::memcpy(this->handleType, S.data(), handleTypeLength);
  }



  static bool classof(const Attr *A) { return A->getKind() == attr::UseHandle; }
};

class UsedAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_used = 0,
    CXX11_gnu_used = 1,
    C2x_gnu_used = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static UsedAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static UsedAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static UsedAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static UsedAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  UsedAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  UsedAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::Used; }
};

class UsingIfExistsAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_using_if_exists = 0,
    CXX11_clang_using_if_exists = 1,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static UsingIfExistsAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static UsingIfExistsAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static UsingIfExistsAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static UsingIfExistsAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  UsingIfExistsAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  UsingIfExistsAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::UsingIfExists; }
};

class UuidAttr : public InheritableAttr {
unsigned guidLength;
char *guid;

MSGuidDecl * guidDecl;

public:
  enum Spelling {
    Declspec_uuid = 0,
    Microsoft_uuid = 1,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static UuidAttr *CreateImplicit(ASTContext &Ctx, llvm::StringRef Guid, MSGuidDecl * GuidDecl, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static UuidAttr *Create(ASTContext &Ctx, llvm::StringRef Guid, MSGuidDecl * GuidDecl, const AttributeCommonInfo &CommonInfo);
  static UuidAttr *CreateImplicit(ASTContext &Ctx, llvm::StringRef Guid, MSGuidDecl * GuidDecl, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static UuidAttr *Create(ASTContext &Ctx, llvm::StringRef Guid, MSGuidDecl * GuidDecl, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static UuidAttr *CreateImplicit(ASTContext &Ctx, llvm::StringRef Guid, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static UuidAttr *Create(ASTContext &Ctx, llvm::StringRef Guid, const AttributeCommonInfo &CommonInfo);
  static UuidAttr *CreateImplicit(ASTContext &Ctx, llvm::StringRef Guid, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static UuidAttr *Create(ASTContext &Ctx, llvm::StringRef Guid, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  UuidAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , llvm::StringRef Guid
              , MSGuidDecl * GuidDecl
             );
  UuidAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , llvm::StringRef Guid
             );

  UuidAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  llvm::StringRef getGuid() const {
    return llvm::StringRef(guid, guidLength);
  }
  unsigned getGuidLength() const {
    return guidLength;
  }
  void setGuid(ASTContext &C, llvm::StringRef S) {
    guidLength = S.size();
    this->guid = new (C, 1) char [guidLength];
    if (!S.empty())
      std::memcpy(this->guid, S.data(), guidLength);
  }

  MSGuidDecl * getGuidDecl() const {
    return guidDecl;
  }



  static bool classof(const Attr *A) { return A->getKind() == attr::Uuid; }
};

class VecReturnAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_vecreturn = 0,
    CXX11_clang_vecreturn = 1,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static VecReturnAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static VecReturnAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static VecReturnAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static VecReturnAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  VecReturnAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  VecReturnAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::VecReturn; }
};

class VecTypeHintAttr : public InheritableAttr {
TypeSourceInfo * typeHint;

public:
  // Factory methods
  static VecTypeHintAttr *CreateImplicit(ASTContext &Ctx, TypeSourceInfo * TypeHint, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static VecTypeHintAttr *Create(ASTContext &Ctx, TypeSourceInfo * TypeHint, const AttributeCommonInfo &CommonInfo);
  static VecTypeHintAttr *CreateImplicit(ASTContext &Ctx, TypeSourceInfo * TypeHint, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static VecTypeHintAttr *Create(ASTContext &Ctx, TypeSourceInfo * TypeHint, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  VecTypeHintAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , TypeSourceInfo * TypeHint
             );

  VecTypeHintAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  QualType getTypeHint() const {
    return typeHint->getType();
  }  TypeSourceInfo * getTypeHintLoc() const {
    return typeHint;
  }



  static bool classof(const Attr *A) { return A->getKind() == attr::VecTypeHint; }
};

class VectorCallAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_vectorcall = 0,
    CXX11_clang_vectorcall = 1,
    C2x_clang_vectorcall = 2,
    Keyword_vectorcall = 3,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static VectorCallAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static VectorCallAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static VectorCallAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static VectorCallAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  VectorCallAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  VectorCallAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::VectorCall; }
};

class VisibilityAttr : public InheritableAttr {
public:
  enum VisibilityType {
    Default,
    Hidden,
    Protected
  };
private:
  VisibilityType visibility;

public:
  enum Spelling {
    GNU_visibility = 0,
    CXX11_gnu_visibility = 1,
    C2x_gnu_visibility = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static VisibilityAttr *CreateImplicit(ASTContext &Ctx, VisibilityType Visibility, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static VisibilityAttr *Create(ASTContext &Ctx, VisibilityType Visibility, const AttributeCommonInfo &CommonInfo);
  static VisibilityAttr *CreateImplicit(ASTContext &Ctx, VisibilityType Visibility, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static VisibilityAttr *Create(ASTContext &Ctx, VisibilityType Visibility, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  VisibilityAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , VisibilityType Visibility
             );

  VisibilityAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  VisibilityType getVisibility() const {
    return visibility;
  }

  static bool ConvertStrToVisibilityType(StringRef Val, VisibilityType &Out);
  static const char *ConvertVisibilityTypeToStr(VisibilityType Val);


  static bool classof(const Attr *A) { return A->getKind() == attr::Visibility; }
};

class WarnUnusedAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_warn_unused = 0,
    CXX11_gnu_warn_unused = 1,
    C2x_gnu_warn_unused = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static WarnUnusedAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static WarnUnusedAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static WarnUnusedAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static WarnUnusedAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  WarnUnusedAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  WarnUnusedAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::WarnUnused; }
};

class WarnUnusedResultAttr : public InheritableAttr {
unsigned messageLength;
char *message;

public:
  enum Spelling {
    CXX11_nodiscard = 0,
    C2x_nodiscard = 1,
    CXX11_clang_warn_unused_result = 2,
    GNU_warn_unused_result = 3,
    CXX11_gnu_warn_unused_result = 4,
    C2x_gnu_warn_unused_result = 5,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static WarnUnusedResultAttr *CreateImplicit(ASTContext &Ctx, llvm::StringRef Message, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static WarnUnusedResultAttr *Create(ASTContext &Ctx, llvm::StringRef Message, const AttributeCommonInfo &CommonInfo);
  static WarnUnusedResultAttr *CreateImplicit(ASTContext &Ctx, llvm::StringRef Message, SourceRange Range, AttributeCommonInfo::Syntax Syntax, WarnUnusedResultAttr::Spelling S = static_cast<Spelling>(SpellingNotCalculated));
  static WarnUnusedResultAttr *Create(ASTContext &Ctx, llvm::StringRef Message, SourceRange Range, AttributeCommonInfo::Syntax Syntax, WarnUnusedResultAttr::Spelling S = static_cast<Spelling>(SpellingNotCalculated));

  // Constructors
  WarnUnusedResultAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , llvm::StringRef Message
             );
  WarnUnusedResultAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  WarnUnusedResultAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  Spelling getSemanticSpelling() const;
  llvm::StringRef getMessage() const {
    return llvm::StringRef(message, messageLength);
  }
  unsigned getMessageLength() const {
    return messageLength;
  }
  void setMessage(ASTContext &C, llvm::StringRef S) {
    messageLength = S.size();
    this->message = new (C, 1) char [messageLength];
    if (!S.empty())
      std::memcpy(this->message, S.data(), messageLength);
  }


    // Check whether this the C++11 nodiscard version, even in non C++11
    // spellings.
    bool IsCXX11NoDiscard() const {
      return this->getSemanticSpelling() == CXX11_nodiscard;
    }
  

  static bool classof(const Attr *A) { return A->getKind() == attr::WarnUnusedResult; }
};

class WeakAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_weak = 0,
    CXX11_gnu_weak = 1,
    C2x_gnu_weak = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static WeakAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static WeakAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static WeakAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static WeakAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  WeakAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  WeakAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::Weak; }
};

class WeakImportAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_weak_import = 0,
    CXX11_clang_weak_import = 1,
    C2x_clang_weak_import = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static WeakImportAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static WeakImportAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static WeakImportAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static WeakImportAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  WeakImportAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  WeakImportAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::WeakImport; }
};

class WeakRefAttr : public InheritableAttr {
unsigned aliaseeLength;
char *aliasee;

public:
  enum Spelling {
    GNU_weakref = 0,
    CXX11_gnu_weakref = 1,
    C2x_gnu_weakref = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static WeakRefAttr *CreateImplicit(ASTContext &Ctx, llvm::StringRef Aliasee, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static WeakRefAttr *Create(ASTContext &Ctx, llvm::StringRef Aliasee, const AttributeCommonInfo &CommonInfo);
  static WeakRefAttr *CreateImplicit(ASTContext &Ctx, llvm::StringRef Aliasee, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static WeakRefAttr *Create(ASTContext &Ctx, llvm::StringRef Aliasee, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  WeakRefAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , llvm::StringRef Aliasee
             );
  WeakRefAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  WeakRefAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  llvm::StringRef getAliasee() const {
    return llvm::StringRef(aliasee, aliaseeLength);
  }
  unsigned getAliaseeLength() const {
    return aliaseeLength;
  }
  void setAliasee(ASTContext &C, llvm::StringRef S) {
    aliaseeLength = S.size();
    this->aliasee = new (C, 1) char [aliaseeLength];
    if (!S.empty())
      std::memcpy(this->aliasee, S.data(), aliaseeLength);
  }



  static bool classof(const Attr *A) { return A->getKind() == attr::WeakRef; }
};

class WebAssemblyExportNameAttr : public InheritableAttr {
unsigned exportNameLength;
char *exportName;

public:
  enum Spelling {
    GNU_export_name = 0,
    CXX11_clang_export_name = 1,
    C2x_clang_export_name = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static WebAssemblyExportNameAttr *CreateImplicit(ASTContext &Ctx, llvm::StringRef ExportName, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static WebAssemblyExportNameAttr *Create(ASTContext &Ctx, llvm::StringRef ExportName, const AttributeCommonInfo &CommonInfo);
  static WebAssemblyExportNameAttr *CreateImplicit(ASTContext &Ctx, llvm::StringRef ExportName, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static WebAssemblyExportNameAttr *Create(ASTContext &Ctx, llvm::StringRef ExportName, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  WebAssemblyExportNameAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , llvm::StringRef ExportName
             );

  WebAssemblyExportNameAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  llvm::StringRef getExportName() const {
    return llvm::StringRef(exportName, exportNameLength);
  }
  unsigned getExportNameLength() const {
    return exportNameLength;
  }
  void setExportName(ASTContext &C, llvm::StringRef S) {
    exportNameLength = S.size();
    this->exportName = new (C, 1) char [exportNameLength];
    if (!S.empty())
      std::memcpy(this->exportName, S.data(), exportNameLength);
  }



  static bool classof(const Attr *A) { return A->getKind() == attr::WebAssemblyExportName; }
};

class WebAssemblyImportModuleAttr : public InheritableAttr {
unsigned importModuleLength;
char *importModule;

public:
  enum Spelling {
    GNU_import_module = 0,
    CXX11_clang_import_module = 1,
    C2x_clang_import_module = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static WebAssemblyImportModuleAttr *CreateImplicit(ASTContext &Ctx, llvm::StringRef ImportModule, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static WebAssemblyImportModuleAttr *Create(ASTContext &Ctx, llvm::StringRef ImportModule, const AttributeCommonInfo &CommonInfo);
  static WebAssemblyImportModuleAttr *CreateImplicit(ASTContext &Ctx, llvm::StringRef ImportModule, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static WebAssemblyImportModuleAttr *Create(ASTContext &Ctx, llvm::StringRef ImportModule, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  WebAssemblyImportModuleAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , llvm::StringRef ImportModule
             );

  WebAssemblyImportModuleAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  llvm::StringRef getImportModule() const {
    return llvm::StringRef(importModule, importModuleLength);
  }
  unsigned getImportModuleLength() const {
    return importModuleLength;
  }
  void setImportModule(ASTContext &C, llvm::StringRef S) {
    importModuleLength = S.size();
    this->importModule = new (C, 1) char [importModuleLength];
    if (!S.empty())
      std::memcpy(this->importModule, S.data(), importModuleLength);
  }



  static bool classof(const Attr *A) { return A->getKind() == attr::WebAssemblyImportModule; }
};

class WebAssemblyImportNameAttr : public InheritableAttr {
unsigned importNameLength;
char *importName;

public:
  enum Spelling {
    GNU_import_name = 0,
    CXX11_clang_import_name = 1,
    C2x_clang_import_name = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static WebAssemblyImportNameAttr *CreateImplicit(ASTContext &Ctx, llvm::StringRef ImportName, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static WebAssemblyImportNameAttr *Create(ASTContext &Ctx, llvm::StringRef ImportName, const AttributeCommonInfo &CommonInfo);
  static WebAssemblyImportNameAttr *CreateImplicit(ASTContext &Ctx, llvm::StringRef ImportName, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static WebAssemblyImportNameAttr *Create(ASTContext &Ctx, llvm::StringRef ImportName, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  WebAssemblyImportNameAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , llvm::StringRef ImportName
             );

  WebAssemblyImportNameAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  llvm::StringRef getImportName() const {
    return llvm::StringRef(importName, importNameLength);
  }
  unsigned getImportNameLength() const {
    return importNameLength;
  }
  void setImportName(ASTContext &C, llvm::StringRef S) {
    importNameLength = S.size();
    this->importName = new (C, 1) char [importNameLength];
    if (!S.empty())
      std::memcpy(this->importName, S.data(), importNameLength);
  }



  static bool classof(const Attr *A) { return A->getKind() == attr::WebAssemblyImportName; }
};

class WorkGroupSizeHintAttr : public InheritableAttr {
unsigned xDim;

unsigned yDim;

unsigned zDim;

public:
  // Factory methods
  static WorkGroupSizeHintAttr *CreateImplicit(ASTContext &Ctx, unsigned XDim, unsigned YDim, unsigned ZDim, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static WorkGroupSizeHintAttr *Create(ASTContext &Ctx, unsigned XDim, unsigned YDim, unsigned ZDim, const AttributeCommonInfo &CommonInfo);
  static WorkGroupSizeHintAttr *CreateImplicit(ASTContext &Ctx, unsigned XDim, unsigned YDim, unsigned ZDim, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static WorkGroupSizeHintAttr *Create(ASTContext &Ctx, unsigned XDim, unsigned YDim, unsigned ZDim, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  WorkGroupSizeHintAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , unsigned XDim
              , unsigned YDim
              , unsigned ZDim
             );

  WorkGroupSizeHintAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  unsigned getXDim() const {
    return xDim;
  }

  unsigned getYDim() const {
    return yDim;
  }

  unsigned getZDim() const {
    return zDim;
  }



  static bool classof(const Attr *A) { return A->getKind() == attr::WorkGroupSizeHint; }
};

class X86ForceAlignArgPointerAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_force_align_arg_pointer = 0,
    CXX11_gnu_force_align_arg_pointer = 1,
    C2x_gnu_force_align_arg_pointer = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static X86ForceAlignArgPointerAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static X86ForceAlignArgPointerAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static X86ForceAlignArgPointerAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static X86ForceAlignArgPointerAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  X86ForceAlignArgPointerAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  X86ForceAlignArgPointerAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;


  static bool classof(const Attr *A) { return A->getKind() == attr::X86ForceAlignArgPointer; }
};

class XRayInstrumentAttr : public InheritableAttr {
public:
  enum Spelling {
    GNU_xray_always_instrument = 0,
    CXX11_clang_xray_always_instrument = 1,
    C2x_clang_xray_always_instrument = 2,
    GNU_xray_never_instrument = 3,
    CXX11_clang_xray_never_instrument = 4,
    C2x_clang_xray_never_instrument = 5,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static XRayInstrumentAttr *CreateImplicit(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static XRayInstrumentAttr *Create(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo);
  static XRayInstrumentAttr *CreateImplicit(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax, XRayInstrumentAttr::Spelling S = static_cast<Spelling>(SpellingNotCalculated));
  static XRayInstrumentAttr *Create(ASTContext &Ctx, SourceRange Range, AttributeCommonInfo::Syntax Syntax, XRayInstrumentAttr::Spelling S = static_cast<Spelling>(SpellingNotCalculated));

  // Constructors
  XRayInstrumentAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
             );

  XRayInstrumentAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  Spelling getSemanticSpelling() const;
  bool alwaysXRayInstrument() const { return getAttributeSpellingListIndex() == 0 ||
    getAttributeSpellingListIndex() == 1 ||
    getAttributeSpellingListIndex() == 2; }
  bool neverXRayInstrument() const { return getAttributeSpellingListIndex() == 3 ||
    getAttributeSpellingListIndex() == 4 ||
    getAttributeSpellingListIndex() == 5; }


  static bool classof(const Attr *A) { return A->getKind() == attr::XRayInstrument; }
};

class XRayLogArgsAttr : public InheritableAttr {
unsigned argumentCount;

public:
  enum Spelling {
    GNU_xray_log_args = 0,
    CXX11_clang_xray_log_args = 1,
    C2x_clang_xray_log_args = 2,
  SpellingNotCalculated = 15

  };

  // Factory methods
  static XRayLogArgsAttr *CreateImplicit(ASTContext &Ctx, unsigned ArgumentCount, const AttributeCommonInfo &CommonInfo = {SourceRange{}});
  static XRayLogArgsAttr *Create(ASTContext &Ctx, unsigned ArgumentCount, const AttributeCommonInfo &CommonInfo);
  static XRayLogArgsAttr *CreateImplicit(ASTContext &Ctx, unsigned ArgumentCount, SourceRange Range, AttributeCommonInfo::Syntax Syntax);
  static XRayLogArgsAttr *Create(ASTContext &Ctx, unsigned ArgumentCount, SourceRange Range, AttributeCommonInfo::Syntax Syntax);

  // Constructors
  XRayLogArgsAttr(ASTContext &Ctx, const AttributeCommonInfo &CommonInfo
              , unsigned ArgumentCount
             );

  XRayLogArgsAttr *clone(ASTContext &C) const;
  void printPretty(raw_ostream &OS,
                   const PrintingPolicy &Policy) const;
  const char *getSpelling() const;
  unsigned getArgumentCount() const {
    return argumentCount;
  }



  static bool classof(const Attr *A) { return A->getKind() == attr::XRayLogArgs; }
};

#endif // LLVM_CLANG_ATTR_CLASSES_INC
