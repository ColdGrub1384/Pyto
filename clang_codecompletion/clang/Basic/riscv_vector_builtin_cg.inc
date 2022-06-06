case RISCVVector::BI__builtin_rvv_vget_v:

      {
        ID = Intrinsic::experimental_vector_extract;
        auto *VecTy = cast<ScalableVectorType>(ResultType);
        auto *OpVecTy = cast<ScalableVectorType>(Ops[0]->getType());
        // Mask to only valid indices.
        unsigned MaxIndex = OpVecTy->getMinNumElements() / VecTy->getMinNumElements();
        assert(isPowerOf2_32(MaxIndex));
        Ops[1] = Builder.CreateAnd(Ops[1], MaxIndex - 1);
        Ops[1] = Builder.CreateMul(Ops[1],
                                   ConstantInt::get(Ops[1]->getType(),
                                                    VecTy->getMinNumElements()));
        IntrinsicTypes = {ResultType, Ops[0]->getType()};
        return Builder.CreateCall(CGM.getIntrinsic(ID, IntrinsicTypes), Ops, "");
      }
      break;
case RISCVVector::BI__builtin_rvv_vset_v:

      {
        ID = Intrinsic::experimental_vector_insert;
        IntrinsicTypes = {ResultType, Ops[2]->getType()};
        auto *ResVecTy = cast<ScalableVectorType>(ResultType);
        auto *VecTy = cast<ScalableVectorType>(Ops[2]->getType());
        // Mask to only valid indices.
        unsigned MaxIndex = ResVecTy->getMinNumElements() / VecTy->getMinNumElements();
        assert(isPowerOf2_32(MaxIndex));
        Ops[1] = Builder.CreateAnd(Ops[1], MaxIndex - 1);
        Ops[1] = Builder.CreateMul(Ops[1],
                                   ConstantInt::get(Ops[1]->getType(),
                                                    VecTy->getMinNumElements()));
        std::swap(Ops[1], Ops[2]);
        return Builder.CreateCall(CGM.getIntrinsic(ID, IntrinsicTypes), Ops, "");
      }
      break;
case RISCVVector::BI__builtin_rvv_vlmul_ext_v:

        ID = Intrinsic::experimental_vector_insert;
        IntrinsicTypes = {ResultType, Ops[0]->getType()};
        Ops.push_back(llvm::UndefValue::get(ResultType));
        std::swap(Ops[0], Ops[1]);
        Ops.push_back(ConstantInt::get(Int64Ty, 0));
        return Builder.CreateCall(CGM.getIntrinsic(ID, IntrinsicTypes), Ops, "");
      break;
case RISCVVector::BI__builtin_rvv_vlmul_trunc_v:
 {
        ID = Intrinsic::experimental_vector_extract;
        IntrinsicTypes = {ResultType, Ops[0]->getType()};
        Ops.push_back(ConstantInt::get(Int64Ty, 0));
        return Builder.CreateCall(CGM.getIntrinsic(ID, IntrinsicTypes), Ops, "");
      } break;
case RISCVVector::BI__builtin_rvv_vreinterpret_v:

        return Builder.CreateBitCast(Ops[0], ResultType);
      break;
case RISCVVector::BI__builtin_rvv_vundefined:

        return llvm::UndefValue::get(ResultType);
      break;
case RISCVVector::BI__builtin_rvv_vaadd_vv:
case RISCVVector::BI__builtin_rvv_vaadd_vx:
  ID = Intrinsic::riscv_vaadd;
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vaadd_vv_m:
case RISCVVector::BI__builtin_rvv_vaadd_vx_m:
  ID = Intrinsic::riscv_vaadd_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  Ops.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
  IntrinsicTypes = {ResultType, Ops[2]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vaaddu_vv:
case RISCVVector::BI__builtin_rvv_vaaddu_vx:
  ID = Intrinsic::riscv_vaaddu;
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vaaddu_vv_m:
case RISCVVector::BI__builtin_rvv_vaaddu_vx_m:
  ID = Intrinsic::riscv_vaaddu_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  Ops.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
  IntrinsicTypes = {ResultType, Ops[2]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vadc_vvm:
case RISCVVector::BI__builtin_rvv_vadc_vxm:
  ID = Intrinsic::riscv_vadc;
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vadd_vv:
case RISCVVector::BI__builtin_rvv_vadd_vx:
  ID = Intrinsic::riscv_vadd;
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vadd_vv_m:
case RISCVVector::BI__builtin_rvv_vadd_vx_m:
  ID = Intrinsic::riscv_vadd_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  Ops.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
  IntrinsicTypes = {ResultType, Ops[2]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vand_vv:
case RISCVVector::BI__builtin_rvv_vand_vx:
  ID = Intrinsic::riscv_vand;
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vand_vv_m:
case RISCVVector::BI__builtin_rvv_vand_vx_m:
  ID = Intrinsic::riscv_vand_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  Ops.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
  IntrinsicTypes = {ResultType, Ops[2]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vasub_vv:
case RISCVVector::BI__builtin_rvv_vasub_vx:
  ID = Intrinsic::riscv_vasub;
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vasub_vv_m:
case RISCVVector::BI__builtin_rvv_vasub_vx_m:
  ID = Intrinsic::riscv_vasub_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  Ops.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
  IntrinsicTypes = {ResultType, Ops[2]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vasubu_vv:
case RISCVVector::BI__builtin_rvv_vasubu_vx:
  ID = Intrinsic::riscv_vasubu;
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vasubu_vv_m:
case RISCVVector::BI__builtin_rvv_vasubu_vx_m:
  ID = Intrinsic::riscv_vasubu_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  Ops.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
  IntrinsicTypes = {ResultType, Ops[2]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vcompress_vm:
  ID = Intrinsic::riscv_vcompress;

      std::rotate(Ops.begin(), Ops.begin() + 1, Ops.begin() + 3);
      IntrinsicTypes = {ResultType, Ops[3]->getType()};
    break;
case RISCVVector::BI__builtin_rvv_vcpop_m:
  ID = Intrinsic::riscv_vcpop;
  IntrinsicTypes = {Ops[0]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vcpop_m_m:
  ID = Intrinsic::riscv_vcpop_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  IntrinsicTypes = {Ops[0]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vdiv_vv:
case RISCVVector::BI__builtin_rvv_vdiv_vx:
  ID = Intrinsic::riscv_vdiv;
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vdiv_vv_m:
case RISCVVector::BI__builtin_rvv_vdiv_vx_m:
  ID = Intrinsic::riscv_vdiv_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  Ops.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
  IntrinsicTypes = {ResultType, Ops[2]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vdivu_vv:
case RISCVVector::BI__builtin_rvv_vdivu_vx:
  ID = Intrinsic::riscv_vdivu;
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vdivu_vv_m:
case RISCVVector::BI__builtin_rvv_vdivu_vx_m:
  ID = Intrinsic::riscv_vdivu_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  Ops.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
  IntrinsicTypes = {ResultType, Ops[2]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfadd_vv:
case RISCVVector::BI__builtin_rvv_vfadd_vf:
  ID = Intrinsic::riscv_vfadd;
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfadd_vv_m:
case RISCVVector::BI__builtin_rvv_vfadd_vf_m:
  ID = Intrinsic::riscv_vfadd_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  Ops.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
  IntrinsicTypes = {ResultType, Ops[2]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfclass_v:
  ID = Intrinsic::riscv_vfclass;
  IntrinsicTypes = {Ops[0]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfclass_v_m:
  ID = Intrinsic::riscv_vfclass_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  IntrinsicTypes = {Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfcvt_f_x_v:
  ID = Intrinsic::riscv_vfcvt_f_x_v;
  IntrinsicTypes = {ResultType, Ops[0]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfcvt_f_x_v_m:
  ID = Intrinsic::riscv_vfcvt_f_x_v_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  Ops.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfcvt_f_xu_v:
  ID = Intrinsic::riscv_vfcvt_f_xu_v;
  IntrinsicTypes = {ResultType, Ops[0]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfcvt_f_xu_v_m:
  ID = Intrinsic::riscv_vfcvt_f_xu_v_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  Ops.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfcvt_rtz_x_f_v:
  ID = Intrinsic::riscv_vfcvt_rtz_x_f_v;
  IntrinsicTypes = {ResultType, Ops[0]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfcvt_rtz_x_f_v_m:
  ID = Intrinsic::riscv_vfcvt_rtz_x_f_v_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  Ops.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfcvt_rtz_xu_f_v:
  ID = Intrinsic::riscv_vfcvt_rtz_xu_f_v;
  IntrinsicTypes = {ResultType, Ops[0]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfcvt_rtz_xu_f_v_m:
  ID = Intrinsic::riscv_vfcvt_rtz_xu_f_v_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  Ops.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfcvt_x_f_v:
  ID = Intrinsic::riscv_vfcvt_x_f_v;
  IntrinsicTypes = {ResultType, Ops[0]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfcvt_x_f_v_m:
  ID = Intrinsic::riscv_vfcvt_x_f_v_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  Ops.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfcvt_xu_f_v:
  ID = Intrinsic::riscv_vfcvt_xu_f_v;
  IntrinsicTypes = {ResultType, Ops[0]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfcvt_xu_f_v_m:
  ID = Intrinsic::riscv_vfcvt_xu_f_v_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  Ops.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfdiv_vv:
case RISCVVector::BI__builtin_rvv_vfdiv_vf:
  ID = Intrinsic::riscv_vfdiv;
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfdiv_vv_m:
case RISCVVector::BI__builtin_rvv_vfdiv_vf_m:
  ID = Intrinsic::riscv_vfdiv_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  Ops.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
  IntrinsicTypes = {ResultType, Ops[2]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfirst_m:
  ID = Intrinsic::riscv_vfirst;
  IntrinsicTypes = {Ops[0]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfirst_m_m:
  ID = Intrinsic::riscv_vfirst_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  IntrinsicTypes = {Ops[0]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfmacc_vv:
case RISCVVector::BI__builtin_rvv_vfmacc_vf:
  ID = Intrinsic::riscv_vfmacc;
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfmacc_vv_m:
case RISCVVector::BI__builtin_rvv_vfmacc_vf_m:
  ID = Intrinsic::riscv_vfmacc_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfmadd_vv:
case RISCVVector::BI__builtin_rvv_vfmadd_vf:
  ID = Intrinsic::riscv_vfmadd;
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfmadd_vv_m:
case RISCVVector::BI__builtin_rvv_vfmadd_vf_m:
  ID = Intrinsic::riscv_vfmadd_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfmax_vv:
case RISCVVector::BI__builtin_rvv_vfmax_vf:
  ID = Intrinsic::riscv_vfmax;
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfmax_vv_m:
case RISCVVector::BI__builtin_rvv_vfmax_vf_m:
  ID = Intrinsic::riscv_vfmax_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  Ops.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
  IntrinsicTypes = {ResultType, Ops[2]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfmerge_vfm:
  ID = Intrinsic::riscv_vfmerge;

      std::rotate(Ops.begin(), Ops.begin() + 1, Ops.begin() + 3);
      IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops[3]->getType()};
    break;
case RISCVVector::BI__builtin_rvv_vfmin_vv:
case RISCVVector::BI__builtin_rvv_vfmin_vf:
  ID = Intrinsic::riscv_vfmin;
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfmin_vv_m:
case RISCVVector::BI__builtin_rvv_vfmin_vf_m:
  ID = Intrinsic::riscv_vfmin_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  Ops.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
  IntrinsicTypes = {ResultType, Ops[2]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfmsac_vv:
case RISCVVector::BI__builtin_rvv_vfmsac_vf:
  ID = Intrinsic::riscv_vfmsac;
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfmsac_vv_m:
case RISCVVector::BI__builtin_rvv_vfmsac_vf_m:
  ID = Intrinsic::riscv_vfmsac_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfmsub_vv:
case RISCVVector::BI__builtin_rvv_vfmsub_vf:
  ID = Intrinsic::riscv_vfmsub;
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfmsub_vv_m:
case RISCVVector::BI__builtin_rvv_vfmsub_vf_m:
  ID = Intrinsic::riscv_vfmsub_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfmul_vv:
case RISCVVector::BI__builtin_rvv_vfmul_vf:
  ID = Intrinsic::riscv_vfmul;
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfmul_vv_m:
case RISCVVector::BI__builtin_rvv_vfmul_vf_m:
  ID = Intrinsic::riscv_vfmul_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  Ops.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
  IntrinsicTypes = {ResultType, Ops[2]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfmv_f_s:
  ID = Intrinsic::riscv_vfmv_f_s;
  IntrinsicTypes = {Ops[0]->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfmv_s_f:
case RISCVVector::BI__builtin_rvv_vfmv_s_x:
  ID = Intrinsic::riscv_vfmv_s_f;
  IntrinsicTypes = {ResultType, Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfmv_v_f:
  ID = Intrinsic::riscv_vfmv_v_f;
  IntrinsicTypes = {ResultType, Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfncvt_f_f_w:
  ID = Intrinsic::riscv_vfncvt_f_f_w;
  IntrinsicTypes = {ResultType, Ops[0]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfncvt_f_f_w_m:
  ID = Intrinsic::riscv_vfncvt_f_f_w_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  Ops.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfncvt_f_x_w:
  ID = Intrinsic::riscv_vfncvt_f_x_w;
  IntrinsicTypes = {ResultType, Ops[0]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfncvt_f_x_w_m:
  ID = Intrinsic::riscv_vfncvt_f_x_w_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  Ops.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfncvt_f_xu_w:
  ID = Intrinsic::riscv_vfncvt_f_xu_w;
  IntrinsicTypes = {ResultType, Ops[0]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfncvt_f_xu_w_m:
  ID = Intrinsic::riscv_vfncvt_f_xu_w_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  Ops.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfncvt_rod_f_f_w:
  ID = Intrinsic::riscv_vfncvt_rod_f_f_w;
  IntrinsicTypes = {ResultType, Ops[0]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfncvt_rod_f_f_w_m:
  ID = Intrinsic::riscv_vfncvt_rod_f_f_w_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  Ops.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfncvt_rtz_x_f_w:
  ID = Intrinsic::riscv_vfncvt_rtz_x_f_w;
  IntrinsicTypes = {ResultType, Ops[0]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfncvt_rtz_x_f_w_m:
  ID = Intrinsic::riscv_vfncvt_rtz_x_f_w_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  Ops.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfncvt_rtz_xu_f_w:
  ID = Intrinsic::riscv_vfncvt_rtz_xu_f_w;
  IntrinsicTypes = {ResultType, Ops[0]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfncvt_rtz_xu_f_w_m:
  ID = Intrinsic::riscv_vfncvt_rtz_xu_f_w_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  Ops.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfncvt_x_f_w:
  ID = Intrinsic::riscv_vfncvt_x_f_w;
  IntrinsicTypes = {ResultType, Ops[0]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfncvt_x_f_w_m:
  ID = Intrinsic::riscv_vfncvt_x_f_w_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  Ops.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfncvt_xu_f_w:
  ID = Intrinsic::riscv_vfncvt_xu_f_w;
  IntrinsicTypes = {ResultType, Ops[0]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfncvt_xu_f_w_m:
  ID = Intrinsic::riscv_vfncvt_xu_f_w_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  Ops.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfnmacc_vv:
case RISCVVector::BI__builtin_rvv_vfnmacc_vf:
  ID = Intrinsic::riscv_vfnmacc;
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfnmacc_vv_m:
case RISCVVector::BI__builtin_rvv_vfnmacc_vf_m:
  ID = Intrinsic::riscv_vfnmacc_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfnmadd_vv:
case RISCVVector::BI__builtin_rvv_vfnmadd_vf:
  ID = Intrinsic::riscv_vfnmadd;
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfnmadd_vv_m:
case RISCVVector::BI__builtin_rvv_vfnmadd_vf_m:
  ID = Intrinsic::riscv_vfnmadd_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfnmsac_vv:
case RISCVVector::BI__builtin_rvv_vfnmsac_vf:
  ID = Intrinsic::riscv_vfnmsac;
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfnmsac_vv_m:
case RISCVVector::BI__builtin_rvv_vfnmsac_vf_m:
  ID = Intrinsic::riscv_vfnmsac_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfnmsub_vv:
case RISCVVector::BI__builtin_rvv_vfnmsub_vf:
  ID = Intrinsic::riscv_vfnmsub;
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfnmsub_vv_m:
case RISCVVector::BI__builtin_rvv_vfnmsub_vf_m:
  ID = Intrinsic::riscv_vfnmsub_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfrdiv_vf:
  ID = Intrinsic::riscv_vfrdiv;
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfrdiv_vf_m:
  ID = Intrinsic::riscv_vfrdiv_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  Ops.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
  IntrinsicTypes = {ResultType, Ops[2]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfrec7_v:
  ID = Intrinsic::riscv_vfrec7;
  IntrinsicTypes = {ResultType, Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfrec7_v_m:
  ID = Intrinsic::riscv_vfrec7_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  Ops.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
  IntrinsicTypes = {ResultType, Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfredmax_vs:
  ID = Intrinsic::riscv_vfredmax;
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfredmax_vs_m:
  ID = Intrinsic::riscv_vfredmax_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfredmin_vs:
  ID = Intrinsic::riscv_vfredmin;
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfredmin_vs_m:
  ID = Intrinsic::riscv_vfredmin_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfredosum_vs:
  ID = Intrinsic::riscv_vfredosum;
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfredosum_vs_m:
  ID = Intrinsic::riscv_vfredosum_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfredusum_vs:
  ID = Intrinsic::riscv_vfredusum;
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfredusum_vs_m:
  ID = Intrinsic::riscv_vfredusum_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfrsqrt7_v:
  ID = Intrinsic::riscv_vfrsqrt7;
  IntrinsicTypes = {ResultType, Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfrsqrt7_v_m:
  ID = Intrinsic::riscv_vfrsqrt7_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  Ops.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
  IntrinsicTypes = {ResultType, Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfrsub_vf:
  ID = Intrinsic::riscv_vfrsub;
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfrsub_vf_m:
  ID = Intrinsic::riscv_vfrsub_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  Ops.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
  IntrinsicTypes = {ResultType, Ops[2]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfsgnj_vv:
case RISCVVector::BI__builtin_rvv_vfsgnj_vf:
  ID = Intrinsic::riscv_vfsgnj;
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfsgnj_vv_m:
case RISCVVector::BI__builtin_rvv_vfsgnj_vf_m:
  ID = Intrinsic::riscv_vfsgnj_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  Ops.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
  IntrinsicTypes = {ResultType, Ops[2]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfsgnjn_vv:
case RISCVVector::BI__builtin_rvv_vfsgnjn_vf:
  ID = Intrinsic::riscv_vfsgnjn;
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfneg_v:
  ID = Intrinsic::riscv_vfsgnjn;

      {
        // op1, vl
        IntrinsicTypes = {ResultType,
                          Ops[0]->getType(), Ops[1]->getType()};
        Ops.insert(Ops.begin() + 1, Ops[0]);
        break;
      }
      break;
case RISCVVector::BI__builtin_rvv_vfsgnjn_vv_m:
case RISCVVector::BI__builtin_rvv_vfsgnjn_vf_m:
  ID = Intrinsic::riscv_vfsgnjn_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  Ops.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
  IntrinsicTypes = {ResultType, Ops[2]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfneg_v_m:
  ID = Intrinsic::riscv_vfsgnjn_mask;

      {
        std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
        Ops.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
        // maskedoff, op1, mask, vl
        IntrinsicTypes = {ResultType,
                          Ops[1]->getType(),
                          Ops[3]->getType()};
        Ops.insert(Ops.begin() + 2, Ops[1]);
        break;
      }
      break;
case RISCVVector::BI__builtin_rvv_vfsgnjx_vv:
case RISCVVector::BI__builtin_rvv_vfsgnjx_vf:
  ID = Intrinsic::riscv_vfsgnjx;
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfabs_v:
  ID = Intrinsic::riscv_vfsgnjx;

      {
        // op1, vl
        IntrinsicTypes = {ResultType,
                          Ops[0]->getType(), Ops[1]->getType()};
        Ops.insert(Ops.begin() + 1, Ops[0]);
        break;
      }
      break;
case RISCVVector::BI__builtin_rvv_vfsgnjx_vv_m:
case RISCVVector::BI__builtin_rvv_vfsgnjx_vf_m:
  ID = Intrinsic::riscv_vfsgnjx_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  Ops.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
  IntrinsicTypes = {ResultType, Ops[2]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfabs_v_m:
  ID = Intrinsic::riscv_vfsgnjx_mask;

      {
        std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
        Ops.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
        // maskedoff, op1, mask, vl
        IntrinsicTypes = {ResultType,
                          Ops[1]->getType(),
                          Ops[3]->getType()};
        Ops.insert(Ops.begin() + 2, Ops[1]);
        break;
      }
      break;
case RISCVVector::BI__builtin_rvv_vfslide1down_vf:
  ID = Intrinsic::riscv_vfslide1down;
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfslide1down_vf_m:
  ID = Intrinsic::riscv_vfslide1down_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  Ops.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
  IntrinsicTypes = {ResultType, Ops[2]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfslide1up_vf:
  ID = Intrinsic::riscv_vfslide1up;
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfslide1up_vf_m:
  ID = Intrinsic::riscv_vfslide1up_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  Ops.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
  IntrinsicTypes = {ResultType, Ops[2]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfsqrt_v:
  ID = Intrinsic::riscv_vfsqrt;
  IntrinsicTypes = {ResultType, Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfsqrt_v_m:
  ID = Intrinsic::riscv_vfsqrt_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  Ops.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
  IntrinsicTypes = {ResultType, Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfsub_vv:
case RISCVVector::BI__builtin_rvv_vfsub_vf:
  ID = Intrinsic::riscv_vfsub;
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfsub_vv_m:
case RISCVVector::BI__builtin_rvv_vfsub_vf_m:
  ID = Intrinsic::riscv_vfsub_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  Ops.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
  IntrinsicTypes = {ResultType, Ops[2]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfwadd_vv:
case RISCVVector::BI__builtin_rvv_vfwadd_vf:
  ID = Intrinsic::riscv_vfwadd;
  IntrinsicTypes = {ResultType, Ops[0]->getType(), Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfwadd_vv_m:
case RISCVVector::BI__builtin_rvv_vfwadd_vf_m:
  ID = Intrinsic::riscv_vfwadd_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  Ops.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops[2]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfwadd_wv:
case RISCVVector::BI__builtin_rvv_vfwadd_wf:
  ID = Intrinsic::riscv_vfwadd_w;
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfwadd_wv_m:
case RISCVVector::BI__builtin_rvv_vfwadd_wf_m:
  ID = Intrinsic::riscv_vfwadd_w_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  Ops.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
  IntrinsicTypes = {ResultType, Ops[2]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfwcvt_f_f_v:
  ID = Intrinsic::riscv_vfwcvt_f_f_v;
  IntrinsicTypes = {ResultType, Ops[0]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfwcvt_f_f_v_m:
  ID = Intrinsic::riscv_vfwcvt_f_f_v_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  Ops.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfwcvt_f_x_v:
  ID = Intrinsic::riscv_vfwcvt_f_x_v;
  IntrinsicTypes = {ResultType, Ops[0]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfwcvt_f_x_v_m:
  ID = Intrinsic::riscv_vfwcvt_f_x_v_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  Ops.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfwcvt_f_xu_v:
  ID = Intrinsic::riscv_vfwcvt_f_xu_v;
  IntrinsicTypes = {ResultType, Ops[0]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfwcvt_f_xu_v_m:
  ID = Intrinsic::riscv_vfwcvt_f_xu_v_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  Ops.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfwcvt_rtz_x_f_v:
  ID = Intrinsic::riscv_vfwcvt_rtz_x_f_v;
  IntrinsicTypes = {ResultType, Ops[0]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfwcvt_rtz_x_f_v_m:
  ID = Intrinsic::riscv_vfwcvt_rtz_x_f_v_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  Ops.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfwcvt_rtz_xu_f_v:
  ID = Intrinsic::riscv_vfwcvt_rtz_xu_f_v;
  IntrinsicTypes = {ResultType, Ops[0]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfwcvt_rtz_xu_f_v_m:
  ID = Intrinsic::riscv_vfwcvt_rtz_xu_f_v_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  Ops.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfwcvt_x_f_v:
  ID = Intrinsic::riscv_vfwcvt_x_f_v;
  IntrinsicTypes = {ResultType, Ops[0]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfwcvt_x_f_v_m:
  ID = Intrinsic::riscv_vfwcvt_x_f_v_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  Ops.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfwcvt_xu_f_v:
  ID = Intrinsic::riscv_vfwcvt_xu_f_v;
  IntrinsicTypes = {ResultType, Ops[0]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfwcvt_xu_f_v_m:
  ID = Intrinsic::riscv_vfwcvt_xu_f_v_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  Ops.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfwmacc_vv:
case RISCVVector::BI__builtin_rvv_vfwmacc_vf:
  ID = Intrinsic::riscv_vfwmacc;
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops[2]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfwmacc_vv_m:
case RISCVVector::BI__builtin_rvv_vfwmacc_vf_m:
  ID = Intrinsic::riscv_vfwmacc_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops[2]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfwmsac_vv:
case RISCVVector::BI__builtin_rvv_vfwmsac_vf:
  ID = Intrinsic::riscv_vfwmsac;
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops[2]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfwmsac_vv_m:
case RISCVVector::BI__builtin_rvv_vfwmsac_vf_m:
  ID = Intrinsic::riscv_vfwmsac_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops[2]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfwmul_vv:
case RISCVVector::BI__builtin_rvv_vfwmul_vf:
  ID = Intrinsic::riscv_vfwmul;
  IntrinsicTypes = {ResultType, Ops[0]->getType(), Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfwmul_vv_m:
case RISCVVector::BI__builtin_rvv_vfwmul_vf_m:
  ID = Intrinsic::riscv_vfwmul_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  Ops.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops[2]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfwnmacc_vv:
case RISCVVector::BI__builtin_rvv_vfwnmacc_vf:
  ID = Intrinsic::riscv_vfwnmacc;
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops[2]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfwnmacc_vv_m:
case RISCVVector::BI__builtin_rvv_vfwnmacc_vf_m:
  ID = Intrinsic::riscv_vfwnmacc_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops[2]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfwnmsac_vv:
case RISCVVector::BI__builtin_rvv_vfwnmsac_vf:
  ID = Intrinsic::riscv_vfwnmsac;
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops[2]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfwnmsac_vv_m:
case RISCVVector::BI__builtin_rvv_vfwnmsac_vf_m:
  ID = Intrinsic::riscv_vfwnmsac_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops[2]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfwredosum_vs:
  ID = Intrinsic::riscv_vfwredosum;
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfwredosum_vs_m:
  ID = Intrinsic::riscv_vfwredosum_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfwredusum_vs:
  ID = Intrinsic::riscv_vfwredusum;
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfwredusum_vs_m:
  ID = Intrinsic::riscv_vfwredusum_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfwsub_vv:
case RISCVVector::BI__builtin_rvv_vfwsub_vf:
  ID = Intrinsic::riscv_vfwsub;
  IntrinsicTypes = {ResultType, Ops[0]->getType(), Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfwsub_vv_m:
case RISCVVector::BI__builtin_rvv_vfwsub_vf_m:
  ID = Intrinsic::riscv_vfwsub_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  Ops.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops[2]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfwsub_wv:
case RISCVVector::BI__builtin_rvv_vfwsub_wf:
  ID = Intrinsic::riscv_vfwsub_w;
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vfwsub_wv_m:
case RISCVVector::BI__builtin_rvv_vfwsub_wf_m:
  ID = Intrinsic::riscv_vfwsub_w_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  Ops.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
  IntrinsicTypes = {ResultType, Ops[2]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vid_v:
  ID = Intrinsic::riscv_vid;
  IntrinsicTypes = {ResultType, Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vid_v_m:
  ID = Intrinsic::riscv_vid_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  IntrinsicTypes = {ResultType, Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_viota_m:
  ID = Intrinsic::riscv_viota;
  IntrinsicTypes = {ResultType, Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_viota_m_m:
  ID = Intrinsic::riscv_viota_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  IntrinsicTypes = {ResultType, Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vle8_v:
case RISCVVector::BI__builtin_rvv_vle16_v:
case RISCVVector::BI__builtin_rvv_vle32_v:
case RISCVVector::BI__builtin_rvv_vle64_v:
  ID = Intrinsic::riscv_vle;

      IntrinsicTypes = {ResultType, Ops[1]->getType()};
      Ops[0] = Builder.CreateBitCast(Ops[0], ResultType->getPointerTo());
    break;
case RISCVVector::BI__builtin_rvv_vle8_v_m:
case RISCVVector::BI__builtin_rvv_vle16_v_m:
case RISCVVector::BI__builtin_rvv_vle32_v_m:
case RISCVVector::BI__builtin_rvv_vle64_v_m:
  ID = Intrinsic::riscv_vle_mask;

      // Move mask to right before vl.
      std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
      Ops.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
      IntrinsicTypes = {ResultType, Ops[3]->getType()};
      Ops[1] = Builder.CreateBitCast(Ops[1], ResultType->getPointerTo());
    break;
case RISCVVector::BI__builtin_rvv_vle16ff_v:
case RISCVVector::BI__builtin_rvv_vle32ff_v:
case RISCVVector::BI__builtin_rvv_vle64ff_v:
case RISCVVector::BI__builtin_rvv_vle8ff_v:
  ID = Intrinsic::riscv_vleff;

      {
        IntrinsicTypes = {ResultType, Ops[2]->getType()};
        Ops[0] = Builder.CreateBitCast(Ops[0], ResultType->getPointerTo());
        Value *NewVL = Ops[1];
        Ops.erase(Ops.begin() + 1);
        llvm::Function *F = CGM.getIntrinsic(ID, IntrinsicTypes);
        llvm::Value *LoadValue = Builder.CreateCall(F, Ops, "");
        llvm::Value *V = Builder.CreateExtractValue(LoadValue, {0});
        // Store new_vl.
        clang::CharUnits Align =
            CGM.getNaturalPointeeTypeAlignment(E->getArg(1)->getType());
        Builder.CreateStore(Builder.CreateExtractValue(LoadValue, {1}),
                            Address(NewVL, Align));
        return V;
      }
      break;
case RISCVVector::BI__builtin_rvv_vle16ff_v_m:
case RISCVVector::BI__builtin_rvv_vle32ff_v_m:
case RISCVVector::BI__builtin_rvv_vle64ff_v_m:
case RISCVVector::BI__builtin_rvv_vle8ff_v_m:
  ID = Intrinsic::riscv_vleff_mask;

      {
        // Move mask to right before vl.
        std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
        Ops.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
        IntrinsicTypes = {ResultType, Ops[4]->getType()};
        Ops[1] = Builder.CreateBitCast(Ops[1], ResultType->getPointerTo());
        Value *NewVL = Ops[2];
        Ops.erase(Ops.begin() + 2);
        llvm::Function *F = CGM.getIntrinsic(ID, IntrinsicTypes);
        llvm::Value *LoadValue = Builder.CreateCall(F, Ops, "");
        llvm::Value *V = Builder.CreateExtractValue(LoadValue, {0});
        // Store new_vl.
        clang::CharUnits Align =
            CGM.getNaturalPointeeTypeAlignment(E->getArg(3)->getType());
        Builder.CreateStore(Builder.CreateExtractValue(LoadValue, {1}),
                            Address(NewVL, Align));
        return V;
      }
      break;
case RISCVVector::BI__builtin_rvv_vlm_v:
  ID = Intrinsic::riscv_vlm;

      IntrinsicTypes = {ResultType, Ops[1]->getType()};
      Ops[0] = Builder.CreateBitCast(Ops[0], ResultType->getPointerTo());
    break;
case RISCVVector::BI__builtin_rvv_vloxei8_v:
case RISCVVector::BI__builtin_rvv_vloxei16_v:
case RISCVVector::BI__builtin_rvv_vloxei32_v:
case RISCVVector::BI__builtin_rvv_vloxei64_v:
  ID = Intrinsic::riscv_vloxei;

        IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops[2]->getType()};
        Ops[0] = Builder.CreateBitCast(Ops[0], ResultType->getPointerTo());
      break;
case RISCVVector::BI__builtin_rvv_vloxei8_v_m:
case RISCVVector::BI__builtin_rvv_vloxei16_v_m:
case RISCVVector::BI__builtin_rvv_vloxei32_v_m:
case RISCVVector::BI__builtin_rvv_vloxei64_v_m:
  ID = Intrinsic::riscv_vloxei_mask;

        // Move mask to right before vl.
        std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
        Ops.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
        IntrinsicTypes = {ResultType, Ops[2]->getType(), Ops[4]->getType()};
        Ops[1] = Builder.CreateBitCast(Ops[1], ResultType->getPointerTo());
      break;
case RISCVVector::BI__builtin_rvv_vloxseg2ei16_v:
case RISCVVector::BI__builtin_rvv_vloxseg2ei32_v:
case RISCVVector::BI__builtin_rvv_vloxseg2ei64_v:
case RISCVVector::BI__builtin_rvv_vloxseg2ei8_v:
  ID = Intrinsic::riscv_vloxseg2;
  NF = 2;

    {
      // builtin: (val0 address, val1 address, ..., ptr, index, vl)
      IntrinsicTypes = {ConvertType(E->getArg(0)->getType()->getPointeeType()),
                        Ops[NF + 1]->getType(), Ops[NF + 2]->getType()};
      // intrinsic: (ptr, index, vl)
      llvm::Value *Operands[] = {Ops[NF], Ops[NF + 1], Ops[NF + 2]};
      llvm::Function *F = CGM.getIntrinsic(ID, IntrinsicTypes);
      llvm::Value *LoadValue = Builder.CreateCall(F, Operands, "");
      clang::CharUnits Align =
          CGM.getNaturalPointeeTypeAlignment(E->getArg(0)->getType());
      llvm::Value *V;
      for (unsigned I = 0; I < NF; ++I) {
        V = Builder.CreateStore(Builder.CreateExtractValue(LoadValue, {I}),
                                Address(Ops[I], Align));
      }
      return V;
    }
            break;
case RISCVVector::BI__builtin_rvv_vloxseg2ei16_v_m:
case RISCVVector::BI__builtin_rvv_vloxseg2ei32_v_m:
case RISCVVector::BI__builtin_rvv_vloxseg2ei64_v_m:
case RISCVVector::BI__builtin_rvv_vloxseg2ei8_v_m:
  ID = Intrinsic::riscv_vloxseg2_mask;
  NF = 2;

    {
      // builtin: (val0 address, ..., mask, maskedoff0, ..., ptr, index, vl)
      IntrinsicTypes = {ConvertType(E->getArg(0)->getType()->getPointeeType()),
                        Ops[2 * NF + 2]->getType(), Ops[2 * NF + 3]->getType()};
      // intrinsic: (maskedoff0, ..., ptr, index, mask, vl)
      SmallVector<llvm::Value*, 12> Operands;
      for (unsigned I = 0; I < NF; ++I)
        Operands.push_back(Ops[NF + I + 1]);
      Operands.push_back(Ops[2 * NF + 1]);
      Operands.push_back(Ops[2 * NF + 2]);
      Operands.push_back(Ops[NF]);
      Operands.push_back(Ops[2 * NF + 3]);
      Operands.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
      assert(Operands.size() == NF + 5);
      llvm::Function *F = CGM.getIntrinsic(ID, IntrinsicTypes);
      llvm::Value *LoadValue = Builder.CreateCall(F, Operands, "");
      clang::CharUnits Align =
          CGM.getNaturalPointeeTypeAlignment(E->getArg(0)->getType());
      llvm::Value *V;
      for (unsigned I = 0; I < NF; ++I) {
        V = Builder.CreateStore(Builder.CreateExtractValue(LoadValue, {I}),
                                Address(Ops[I], Align));
      }
      return V;
    }
            break;
case RISCVVector::BI__builtin_rvv_vloxseg3ei8_v:
case RISCVVector::BI__builtin_rvv_vloxseg3ei16_v:
case RISCVVector::BI__builtin_rvv_vloxseg3ei32_v:
case RISCVVector::BI__builtin_rvv_vloxseg3ei64_v:
  ID = Intrinsic::riscv_vloxseg3;
  NF = 3;

    {
      // builtin: (val0 address, val1 address, ..., ptr, index, vl)
      IntrinsicTypes = {ConvertType(E->getArg(0)->getType()->getPointeeType()),
                        Ops[NF + 1]->getType(), Ops[NF + 2]->getType()};
      // intrinsic: (ptr, index, vl)
      llvm::Value *Operands[] = {Ops[NF], Ops[NF + 1], Ops[NF + 2]};
      llvm::Function *F = CGM.getIntrinsic(ID, IntrinsicTypes);
      llvm::Value *LoadValue = Builder.CreateCall(F, Operands, "");
      clang::CharUnits Align =
          CGM.getNaturalPointeeTypeAlignment(E->getArg(0)->getType());
      llvm::Value *V;
      for (unsigned I = 0; I < NF; ++I) {
        V = Builder.CreateStore(Builder.CreateExtractValue(LoadValue, {I}),
                                Address(Ops[I], Align));
      }
      return V;
    }
            break;
case RISCVVector::BI__builtin_rvv_vloxseg3ei8_v_m:
case RISCVVector::BI__builtin_rvv_vloxseg3ei16_v_m:
case RISCVVector::BI__builtin_rvv_vloxseg3ei32_v_m:
case RISCVVector::BI__builtin_rvv_vloxseg3ei64_v_m:
  ID = Intrinsic::riscv_vloxseg3_mask;
  NF = 3;

    {
      // builtin: (val0 address, ..., mask, maskedoff0, ..., ptr, index, vl)
      IntrinsicTypes = {ConvertType(E->getArg(0)->getType()->getPointeeType()),
                        Ops[2 * NF + 2]->getType(), Ops[2 * NF + 3]->getType()};
      // intrinsic: (maskedoff0, ..., ptr, index, mask, vl)
      SmallVector<llvm::Value*, 12> Operands;
      for (unsigned I = 0; I < NF; ++I)
        Operands.push_back(Ops[NF + I + 1]);
      Operands.push_back(Ops[2 * NF + 1]);
      Operands.push_back(Ops[2 * NF + 2]);
      Operands.push_back(Ops[NF]);
      Operands.push_back(Ops[2 * NF + 3]);
      Operands.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
      assert(Operands.size() == NF + 5);
      llvm::Function *F = CGM.getIntrinsic(ID, IntrinsicTypes);
      llvm::Value *LoadValue = Builder.CreateCall(F, Operands, "");
      clang::CharUnits Align =
          CGM.getNaturalPointeeTypeAlignment(E->getArg(0)->getType());
      llvm::Value *V;
      for (unsigned I = 0; I < NF; ++I) {
        V = Builder.CreateStore(Builder.CreateExtractValue(LoadValue, {I}),
                                Address(Ops[I], Align));
      }
      return V;
    }
            break;
case RISCVVector::BI__builtin_rvv_vloxseg4ei8_v:
case RISCVVector::BI__builtin_rvv_vloxseg4ei16_v:
case RISCVVector::BI__builtin_rvv_vloxseg4ei32_v:
case RISCVVector::BI__builtin_rvv_vloxseg4ei64_v:
  ID = Intrinsic::riscv_vloxseg4;
  NF = 4;

    {
      // builtin: (val0 address, val1 address, ..., ptr, index, vl)
      IntrinsicTypes = {ConvertType(E->getArg(0)->getType()->getPointeeType()),
                        Ops[NF + 1]->getType(), Ops[NF + 2]->getType()};
      // intrinsic: (ptr, index, vl)
      llvm::Value *Operands[] = {Ops[NF], Ops[NF + 1], Ops[NF + 2]};
      llvm::Function *F = CGM.getIntrinsic(ID, IntrinsicTypes);
      llvm::Value *LoadValue = Builder.CreateCall(F, Operands, "");
      clang::CharUnits Align =
          CGM.getNaturalPointeeTypeAlignment(E->getArg(0)->getType());
      llvm::Value *V;
      for (unsigned I = 0; I < NF; ++I) {
        V = Builder.CreateStore(Builder.CreateExtractValue(LoadValue, {I}),
                                Address(Ops[I], Align));
      }
      return V;
    }
            break;
case RISCVVector::BI__builtin_rvv_vloxseg4ei8_v_m:
case RISCVVector::BI__builtin_rvv_vloxseg4ei16_v_m:
case RISCVVector::BI__builtin_rvv_vloxseg4ei32_v_m:
case RISCVVector::BI__builtin_rvv_vloxseg4ei64_v_m:
  ID = Intrinsic::riscv_vloxseg4_mask;
  NF = 4;

    {
      // builtin: (val0 address, ..., mask, maskedoff0, ..., ptr, index, vl)
      IntrinsicTypes = {ConvertType(E->getArg(0)->getType()->getPointeeType()),
                        Ops[2 * NF + 2]->getType(), Ops[2 * NF + 3]->getType()};
      // intrinsic: (maskedoff0, ..., ptr, index, mask, vl)
      SmallVector<llvm::Value*, 12> Operands;
      for (unsigned I = 0; I < NF; ++I)
        Operands.push_back(Ops[NF + I + 1]);
      Operands.push_back(Ops[2 * NF + 1]);
      Operands.push_back(Ops[2 * NF + 2]);
      Operands.push_back(Ops[NF]);
      Operands.push_back(Ops[2 * NF + 3]);
      Operands.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
      assert(Operands.size() == NF + 5);
      llvm::Function *F = CGM.getIntrinsic(ID, IntrinsicTypes);
      llvm::Value *LoadValue = Builder.CreateCall(F, Operands, "");
      clang::CharUnits Align =
          CGM.getNaturalPointeeTypeAlignment(E->getArg(0)->getType());
      llvm::Value *V;
      for (unsigned I = 0; I < NF; ++I) {
        V = Builder.CreateStore(Builder.CreateExtractValue(LoadValue, {I}),
                                Address(Ops[I], Align));
      }
      return V;
    }
            break;
case RISCVVector::BI__builtin_rvv_vloxseg5ei8_v:
case RISCVVector::BI__builtin_rvv_vloxseg5ei16_v:
case RISCVVector::BI__builtin_rvv_vloxseg5ei32_v:
case RISCVVector::BI__builtin_rvv_vloxseg5ei64_v:
  ID = Intrinsic::riscv_vloxseg5;
  NF = 5;

    {
      // builtin: (val0 address, val1 address, ..., ptr, index, vl)
      IntrinsicTypes = {ConvertType(E->getArg(0)->getType()->getPointeeType()),
                        Ops[NF + 1]->getType(), Ops[NF + 2]->getType()};
      // intrinsic: (ptr, index, vl)
      llvm::Value *Operands[] = {Ops[NF], Ops[NF + 1], Ops[NF + 2]};
      llvm::Function *F = CGM.getIntrinsic(ID, IntrinsicTypes);
      llvm::Value *LoadValue = Builder.CreateCall(F, Operands, "");
      clang::CharUnits Align =
          CGM.getNaturalPointeeTypeAlignment(E->getArg(0)->getType());
      llvm::Value *V;
      for (unsigned I = 0; I < NF; ++I) {
        V = Builder.CreateStore(Builder.CreateExtractValue(LoadValue, {I}),
                                Address(Ops[I], Align));
      }
      return V;
    }
            break;
case RISCVVector::BI__builtin_rvv_vloxseg5ei8_v_m:
case RISCVVector::BI__builtin_rvv_vloxseg5ei16_v_m:
case RISCVVector::BI__builtin_rvv_vloxseg5ei32_v_m:
case RISCVVector::BI__builtin_rvv_vloxseg5ei64_v_m:
  ID = Intrinsic::riscv_vloxseg5_mask;
  NF = 5;

    {
      // builtin: (val0 address, ..., mask, maskedoff0, ..., ptr, index, vl)
      IntrinsicTypes = {ConvertType(E->getArg(0)->getType()->getPointeeType()),
                        Ops[2 * NF + 2]->getType(), Ops[2 * NF + 3]->getType()};
      // intrinsic: (maskedoff0, ..., ptr, index, mask, vl)
      SmallVector<llvm::Value*, 12> Operands;
      for (unsigned I = 0; I < NF; ++I)
        Operands.push_back(Ops[NF + I + 1]);
      Operands.push_back(Ops[2 * NF + 1]);
      Operands.push_back(Ops[2 * NF + 2]);
      Operands.push_back(Ops[NF]);
      Operands.push_back(Ops[2 * NF + 3]);
      Operands.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
      assert(Operands.size() == NF + 5);
      llvm::Function *F = CGM.getIntrinsic(ID, IntrinsicTypes);
      llvm::Value *LoadValue = Builder.CreateCall(F, Operands, "");
      clang::CharUnits Align =
          CGM.getNaturalPointeeTypeAlignment(E->getArg(0)->getType());
      llvm::Value *V;
      for (unsigned I = 0; I < NF; ++I) {
        V = Builder.CreateStore(Builder.CreateExtractValue(LoadValue, {I}),
                                Address(Ops[I], Align));
      }
      return V;
    }
            break;
case RISCVVector::BI__builtin_rvv_vloxseg6ei8_v:
case RISCVVector::BI__builtin_rvv_vloxseg6ei16_v:
case RISCVVector::BI__builtin_rvv_vloxseg6ei32_v:
case RISCVVector::BI__builtin_rvv_vloxseg6ei64_v:
  ID = Intrinsic::riscv_vloxseg6;
  NF = 6;

    {
      // builtin: (val0 address, val1 address, ..., ptr, index, vl)
      IntrinsicTypes = {ConvertType(E->getArg(0)->getType()->getPointeeType()),
                        Ops[NF + 1]->getType(), Ops[NF + 2]->getType()};
      // intrinsic: (ptr, index, vl)
      llvm::Value *Operands[] = {Ops[NF], Ops[NF + 1], Ops[NF + 2]};
      llvm::Function *F = CGM.getIntrinsic(ID, IntrinsicTypes);
      llvm::Value *LoadValue = Builder.CreateCall(F, Operands, "");
      clang::CharUnits Align =
          CGM.getNaturalPointeeTypeAlignment(E->getArg(0)->getType());
      llvm::Value *V;
      for (unsigned I = 0; I < NF; ++I) {
        V = Builder.CreateStore(Builder.CreateExtractValue(LoadValue, {I}),
                                Address(Ops[I], Align));
      }
      return V;
    }
            break;
case RISCVVector::BI__builtin_rvv_vloxseg6ei8_v_m:
case RISCVVector::BI__builtin_rvv_vloxseg6ei16_v_m:
case RISCVVector::BI__builtin_rvv_vloxseg6ei32_v_m:
case RISCVVector::BI__builtin_rvv_vloxseg6ei64_v_m:
  ID = Intrinsic::riscv_vloxseg6_mask;
  NF = 6;

    {
      // builtin: (val0 address, ..., mask, maskedoff0, ..., ptr, index, vl)
      IntrinsicTypes = {ConvertType(E->getArg(0)->getType()->getPointeeType()),
                        Ops[2 * NF + 2]->getType(), Ops[2 * NF + 3]->getType()};
      // intrinsic: (maskedoff0, ..., ptr, index, mask, vl)
      SmallVector<llvm::Value*, 12> Operands;
      for (unsigned I = 0; I < NF; ++I)
        Operands.push_back(Ops[NF + I + 1]);
      Operands.push_back(Ops[2 * NF + 1]);
      Operands.push_back(Ops[2 * NF + 2]);
      Operands.push_back(Ops[NF]);
      Operands.push_back(Ops[2 * NF + 3]);
      Operands.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
      assert(Operands.size() == NF + 5);
      llvm::Function *F = CGM.getIntrinsic(ID, IntrinsicTypes);
      llvm::Value *LoadValue = Builder.CreateCall(F, Operands, "");
      clang::CharUnits Align =
          CGM.getNaturalPointeeTypeAlignment(E->getArg(0)->getType());
      llvm::Value *V;
      for (unsigned I = 0; I < NF; ++I) {
        V = Builder.CreateStore(Builder.CreateExtractValue(LoadValue, {I}),
                                Address(Ops[I], Align));
      }
      return V;
    }
            break;
case RISCVVector::BI__builtin_rvv_vloxseg7ei8_v:
case RISCVVector::BI__builtin_rvv_vloxseg7ei16_v:
case RISCVVector::BI__builtin_rvv_vloxseg7ei32_v:
case RISCVVector::BI__builtin_rvv_vloxseg7ei64_v:
  ID = Intrinsic::riscv_vloxseg7;
  NF = 7;

    {
      // builtin: (val0 address, val1 address, ..., ptr, index, vl)
      IntrinsicTypes = {ConvertType(E->getArg(0)->getType()->getPointeeType()),
                        Ops[NF + 1]->getType(), Ops[NF + 2]->getType()};
      // intrinsic: (ptr, index, vl)
      llvm::Value *Operands[] = {Ops[NF], Ops[NF + 1], Ops[NF + 2]};
      llvm::Function *F = CGM.getIntrinsic(ID, IntrinsicTypes);
      llvm::Value *LoadValue = Builder.CreateCall(F, Operands, "");
      clang::CharUnits Align =
          CGM.getNaturalPointeeTypeAlignment(E->getArg(0)->getType());
      llvm::Value *V;
      for (unsigned I = 0; I < NF; ++I) {
        V = Builder.CreateStore(Builder.CreateExtractValue(LoadValue, {I}),
                                Address(Ops[I], Align));
      }
      return V;
    }
            break;
case RISCVVector::BI__builtin_rvv_vloxseg7ei8_v_m:
case RISCVVector::BI__builtin_rvv_vloxseg7ei16_v_m:
case RISCVVector::BI__builtin_rvv_vloxseg7ei32_v_m:
case RISCVVector::BI__builtin_rvv_vloxseg7ei64_v_m:
  ID = Intrinsic::riscv_vloxseg7_mask;
  NF = 7;

    {
      // builtin: (val0 address, ..., mask, maskedoff0, ..., ptr, index, vl)
      IntrinsicTypes = {ConvertType(E->getArg(0)->getType()->getPointeeType()),
                        Ops[2 * NF + 2]->getType(), Ops[2 * NF + 3]->getType()};
      // intrinsic: (maskedoff0, ..., ptr, index, mask, vl)
      SmallVector<llvm::Value*, 12> Operands;
      for (unsigned I = 0; I < NF; ++I)
        Operands.push_back(Ops[NF + I + 1]);
      Operands.push_back(Ops[2 * NF + 1]);
      Operands.push_back(Ops[2 * NF + 2]);
      Operands.push_back(Ops[NF]);
      Operands.push_back(Ops[2 * NF + 3]);
      Operands.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
      assert(Operands.size() == NF + 5);
      llvm::Function *F = CGM.getIntrinsic(ID, IntrinsicTypes);
      llvm::Value *LoadValue = Builder.CreateCall(F, Operands, "");
      clang::CharUnits Align =
          CGM.getNaturalPointeeTypeAlignment(E->getArg(0)->getType());
      llvm::Value *V;
      for (unsigned I = 0; I < NF; ++I) {
        V = Builder.CreateStore(Builder.CreateExtractValue(LoadValue, {I}),
                                Address(Ops[I], Align));
      }
      return V;
    }
            break;
case RISCVVector::BI__builtin_rvv_vloxseg8ei8_v:
case RISCVVector::BI__builtin_rvv_vloxseg8ei16_v:
case RISCVVector::BI__builtin_rvv_vloxseg8ei32_v:
case RISCVVector::BI__builtin_rvv_vloxseg8ei64_v:
  ID = Intrinsic::riscv_vloxseg8;
  NF = 8;

    {
      // builtin: (val0 address, val1 address, ..., ptr, index, vl)
      IntrinsicTypes = {ConvertType(E->getArg(0)->getType()->getPointeeType()),
                        Ops[NF + 1]->getType(), Ops[NF + 2]->getType()};
      // intrinsic: (ptr, index, vl)
      llvm::Value *Operands[] = {Ops[NF], Ops[NF + 1], Ops[NF + 2]};
      llvm::Function *F = CGM.getIntrinsic(ID, IntrinsicTypes);
      llvm::Value *LoadValue = Builder.CreateCall(F, Operands, "");
      clang::CharUnits Align =
          CGM.getNaturalPointeeTypeAlignment(E->getArg(0)->getType());
      llvm::Value *V;
      for (unsigned I = 0; I < NF; ++I) {
        V = Builder.CreateStore(Builder.CreateExtractValue(LoadValue, {I}),
                                Address(Ops[I], Align));
      }
      return V;
    }
            break;
case RISCVVector::BI__builtin_rvv_vloxseg8ei8_v_m:
case RISCVVector::BI__builtin_rvv_vloxseg8ei16_v_m:
case RISCVVector::BI__builtin_rvv_vloxseg8ei32_v_m:
case RISCVVector::BI__builtin_rvv_vloxseg8ei64_v_m:
  ID = Intrinsic::riscv_vloxseg8_mask;
  NF = 8;

    {
      // builtin: (val0 address, ..., mask, maskedoff0, ..., ptr, index, vl)
      IntrinsicTypes = {ConvertType(E->getArg(0)->getType()->getPointeeType()),
                        Ops[2 * NF + 2]->getType(), Ops[2 * NF + 3]->getType()};
      // intrinsic: (maskedoff0, ..., ptr, index, mask, vl)
      SmallVector<llvm::Value*, 12> Operands;
      for (unsigned I = 0; I < NF; ++I)
        Operands.push_back(Ops[NF + I + 1]);
      Operands.push_back(Ops[2 * NF + 1]);
      Operands.push_back(Ops[2 * NF + 2]);
      Operands.push_back(Ops[NF]);
      Operands.push_back(Ops[2 * NF + 3]);
      Operands.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
      assert(Operands.size() == NF + 5);
      llvm::Function *F = CGM.getIntrinsic(ID, IntrinsicTypes);
      llvm::Value *LoadValue = Builder.CreateCall(F, Operands, "");
      clang::CharUnits Align =
          CGM.getNaturalPointeeTypeAlignment(E->getArg(0)->getType());
      llvm::Value *V;
      for (unsigned I = 0; I < NF; ++I) {
        V = Builder.CreateStore(Builder.CreateExtractValue(LoadValue, {I}),
                                Address(Ops[I], Align));
      }
      return V;
    }
            break;
case RISCVVector::BI__builtin_rvv_vlse8_v:
case RISCVVector::BI__builtin_rvv_vlse16_v:
case RISCVVector::BI__builtin_rvv_vlse32_v:
case RISCVVector::BI__builtin_rvv_vlse64_v:
  ID = Intrinsic::riscv_vlse;

        IntrinsicTypes = {ResultType, Ops[2]->getType()};
        Ops[0] = Builder.CreateBitCast(Ops[0], ResultType->getPointerTo());
      break;
case RISCVVector::BI__builtin_rvv_vlse8_v_m:
case RISCVVector::BI__builtin_rvv_vlse16_v_m:
case RISCVVector::BI__builtin_rvv_vlse32_v_m:
case RISCVVector::BI__builtin_rvv_vlse64_v_m:
  ID = Intrinsic::riscv_vlse_mask;

        // Move mask to right before vl.
        std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
        Ops.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
        IntrinsicTypes = {ResultType, Ops[4]->getType()};
        Ops[1] = Builder.CreateBitCast(Ops[1], ResultType->getPointerTo());
      break;
case RISCVVector::BI__builtin_rvv_vlseg2e8_v:
case RISCVVector::BI__builtin_rvv_vlseg2e16_v:
case RISCVVector::BI__builtin_rvv_vlseg2e32_v:
case RISCVVector::BI__builtin_rvv_vlseg2e64_v:
  ID = Intrinsic::riscv_vlseg2;
  NF = 2;

    {
      // builtin: (val0 address, val1 address, ..., ptr, vl)
      IntrinsicTypes = {ConvertType(E->getArg(0)->getType()->getPointeeType()),
                        Ops[NF + 1]->getType()};
      // intrinsic: (ptr, vl)
      llvm::Value *Operands[] = {Ops[NF], Ops[NF + 1]};
      llvm::Function *F = CGM.getIntrinsic(ID, IntrinsicTypes);
      llvm::Value *LoadValue = Builder.CreateCall(F, Operands, "");
      clang::CharUnits Align =
          CGM.getNaturalPointeeTypeAlignment(E->getArg(0)->getType());
      llvm::Value *V;
      for (unsigned I = 0; I < NF; ++I) {
        V = Builder.CreateStore(Builder.CreateExtractValue(LoadValue, {I}),
                                Address(Ops[I], Align));
      }
      return V;
    }
            break;
case RISCVVector::BI__builtin_rvv_vlseg2e8_v_m:
case RISCVVector::BI__builtin_rvv_vlseg2e16_v_m:
case RISCVVector::BI__builtin_rvv_vlseg2e32_v_m:
case RISCVVector::BI__builtin_rvv_vlseg2e64_v_m:
  ID = Intrinsic::riscv_vlseg2_mask;
  NF = 2;

    {
      // builtin: (val0 address, ..., mask, maskedoff0, ..., ptr, vl)
      // intrinsic: (maskedoff0, ..., ptr, mask, vl)
      IntrinsicTypes = {ConvertType(E->getArg(0)->getType()->getPointeeType()),
                        Ops[2 * NF + 2]->getType()};
      SmallVector<llvm::Value*, 12> Operands;
      for (unsigned I = 0; I < NF; ++I)
        Operands.push_back(Ops[NF + I + 1]);
      Operands.push_back(Ops[2 * NF + 1]);
      Operands.push_back(Ops[NF]);
      Operands.push_back(Ops[2 * NF + 2]);
      Operands.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
      assert(Operands.size() == NF + 4);
      llvm::Function *F = CGM.getIntrinsic(ID, IntrinsicTypes);
      llvm::Value *LoadValue = Builder.CreateCall(F, Operands, "");
      clang::CharUnits Align =
          CGM.getNaturalPointeeTypeAlignment(E->getArg(0)->getType());
      llvm::Value *V;
      for (unsigned I = 0; I < NF; ++I) {
        V = Builder.CreateStore(Builder.CreateExtractValue(LoadValue, {I}),
                                Address(Ops[I], Align));
      }
      return V;
    }
            break;
case RISCVVector::BI__builtin_rvv_vlseg2e16ff_v:
case RISCVVector::BI__builtin_rvv_vlseg2e32ff_v:
case RISCVVector::BI__builtin_rvv_vlseg2e8ff_v:
case RISCVVector::BI__builtin_rvv_vlseg2e64ff_v:
  ID = Intrinsic::riscv_vlseg2ff;
  NF = 2;

    {
      // builtin: (val0 address, val1 address, ..., ptr, new_vl, vl)
      IntrinsicTypes = {ConvertType(E->getArg(0)->getType()->getPointeeType()),
                        Ops[NF + 2]->getType()};
      // intrinsic: (ptr, vl)
      llvm::Value *Operands[] = {Ops[NF], Ops[NF + 2]};
      Value *NewVL = Ops[NF + 1];
      llvm::Function *F = CGM.getIntrinsic(ID, IntrinsicTypes);
      llvm::Value *LoadValue = Builder.CreateCall(F, Operands, "");
      clang::CharUnits Align =
          CGM.getNaturalPointeeTypeAlignment(E->getArg(0)->getType());
      for (unsigned I = 0; I < NF; ++I) {
        Builder.CreateStore(Builder.CreateExtractValue(LoadValue, {I}),
                            Address(Ops[I], Align));
      }
      // Store new_vl.
      return Builder.CreateStore(Builder.CreateExtractValue(LoadValue, {NF}),
                                 Address(NewVL, Align));
    }
            break;
case RISCVVector::BI__builtin_rvv_vlseg2e16ff_v_m:
case RISCVVector::BI__builtin_rvv_vlseg2e32ff_v_m:
case RISCVVector::BI__builtin_rvv_vlseg2e8ff_v_m:
case RISCVVector::BI__builtin_rvv_vlseg2e64ff_v_m:
  ID = Intrinsic::riscv_vlseg2ff_mask;
  NF = 2;

    {
      // builtin: (val0 address, ..., mask, maskedoff0, ..., ptr, new_vl, vl)
      // intrinsic: (maskedoff0, ..., ptr, mask, vl)
      IntrinsicTypes = {ConvertType(E->getArg(0)->getType()->getPointeeType()),
                        Ops[2 * NF + 3]->getType()};
      SmallVector<llvm::Value*, 12> Operands;
      for (unsigned I = 0; I < NF; ++I)
        Operands.push_back(Ops[NF + I + 1]);
      Operands.push_back(Ops[2 * NF + 1]);
      Operands.push_back(Ops[NF]);
      Operands.push_back(Ops[2 * NF + 3]);
      Operands.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
      Value *NewVL = Ops[2 * NF + 2];
      assert(Operands.size() == NF + 4);
      llvm::Function *F = CGM.getIntrinsic(ID, IntrinsicTypes);
      llvm::Value *LoadValue = Builder.CreateCall(F, Operands, "");
      clang::CharUnits Align =
          CGM.getNaturalPointeeTypeAlignment(E->getArg(0)->getType());
      for (unsigned I = 0; I < NF; ++I) {
        Builder.CreateStore(Builder.CreateExtractValue(LoadValue, {I}),
                            Address(Ops[I], Align));
      }
      // Store new_vl.
      return Builder.CreateStore(Builder.CreateExtractValue(LoadValue, {NF}),
                                 Address(NewVL, Align));
    }
            break;
case RISCVVector::BI__builtin_rvv_vlseg3e8_v:
case RISCVVector::BI__builtin_rvv_vlseg3e16_v:
case RISCVVector::BI__builtin_rvv_vlseg3e32_v:
case RISCVVector::BI__builtin_rvv_vlseg3e64_v:
  ID = Intrinsic::riscv_vlseg3;
  NF = 3;

    {
      // builtin: (val0 address, val1 address, ..., ptr, vl)
      IntrinsicTypes = {ConvertType(E->getArg(0)->getType()->getPointeeType()),
                        Ops[NF + 1]->getType()};
      // intrinsic: (ptr, vl)
      llvm::Value *Operands[] = {Ops[NF], Ops[NF + 1]};
      llvm::Function *F = CGM.getIntrinsic(ID, IntrinsicTypes);
      llvm::Value *LoadValue = Builder.CreateCall(F, Operands, "");
      clang::CharUnits Align =
          CGM.getNaturalPointeeTypeAlignment(E->getArg(0)->getType());
      llvm::Value *V;
      for (unsigned I = 0; I < NF; ++I) {
        V = Builder.CreateStore(Builder.CreateExtractValue(LoadValue, {I}),
                                Address(Ops[I], Align));
      }
      return V;
    }
            break;
case RISCVVector::BI__builtin_rvv_vlseg3e8_v_m:
case RISCVVector::BI__builtin_rvv_vlseg3e16_v_m:
case RISCVVector::BI__builtin_rvv_vlseg3e32_v_m:
case RISCVVector::BI__builtin_rvv_vlseg3e64_v_m:
  ID = Intrinsic::riscv_vlseg3_mask;
  NF = 3;

    {
      // builtin: (val0 address, ..., mask, maskedoff0, ..., ptr, vl)
      // intrinsic: (maskedoff0, ..., ptr, mask, vl)
      IntrinsicTypes = {ConvertType(E->getArg(0)->getType()->getPointeeType()),
                        Ops[2 * NF + 2]->getType()};
      SmallVector<llvm::Value*, 12> Operands;
      for (unsigned I = 0; I < NF; ++I)
        Operands.push_back(Ops[NF + I + 1]);
      Operands.push_back(Ops[2 * NF + 1]);
      Operands.push_back(Ops[NF]);
      Operands.push_back(Ops[2 * NF + 2]);
      Operands.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
      assert(Operands.size() == NF + 4);
      llvm::Function *F = CGM.getIntrinsic(ID, IntrinsicTypes);
      llvm::Value *LoadValue = Builder.CreateCall(F, Operands, "");
      clang::CharUnits Align =
          CGM.getNaturalPointeeTypeAlignment(E->getArg(0)->getType());
      llvm::Value *V;
      for (unsigned I = 0; I < NF; ++I) {
        V = Builder.CreateStore(Builder.CreateExtractValue(LoadValue, {I}),
                                Address(Ops[I], Align));
      }
      return V;
    }
            break;
case RISCVVector::BI__builtin_rvv_vlseg3e8ff_v:
case RISCVVector::BI__builtin_rvv_vlseg3e16ff_v:
case RISCVVector::BI__builtin_rvv_vlseg3e32ff_v:
case RISCVVector::BI__builtin_rvv_vlseg3e64ff_v:
  ID = Intrinsic::riscv_vlseg3ff;
  NF = 3;

    {
      // builtin: (val0 address, val1 address, ..., ptr, new_vl, vl)
      IntrinsicTypes = {ConvertType(E->getArg(0)->getType()->getPointeeType()),
                        Ops[NF + 2]->getType()};
      // intrinsic: (ptr, vl)
      llvm::Value *Operands[] = {Ops[NF], Ops[NF + 2]};
      Value *NewVL = Ops[NF + 1];
      llvm::Function *F = CGM.getIntrinsic(ID, IntrinsicTypes);
      llvm::Value *LoadValue = Builder.CreateCall(F, Operands, "");
      clang::CharUnits Align =
          CGM.getNaturalPointeeTypeAlignment(E->getArg(0)->getType());
      for (unsigned I = 0; I < NF; ++I) {
        Builder.CreateStore(Builder.CreateExtractValue(LoadValue, {I}),
                            Address(Ops[I], Align));
      }
      // Store new_vl.
      return Builder.CreateStore(Builder.CreateExtractValue(LoadValue, {NF}),
                                 Address(NewVL, Align));
    }
            break;
case RISCVVector::BI__builtin_rvv_vlseg3e8ff_v_m:
case RISCVVector::BI__builtin_rvv_vlseg3e16ff_v_m:
case RISCVVector::BI__builtin_rvv_vlseg3e32ff_v_m:
case RISCVVector::BI__builtin_rvv_vlseg3e64ff_v_m:
  ID = Intrinsic::riscv_vlseg3ff_mask;
  NF = 3;

    {
      // builtin: (val0 address, ..., mask, maskedoff0, ..., ptr, new_vl, vl)
      // intrinsic: (maskedoff0, ..., ptr, mask, vl)
      IntrinsicTypes = {ConvertType(E->getArg(0)->getType()->getPointeeType()),
                        Ops[2 * NF + 3]->getType()};
      SmallVector<llvm::Value*, 12> Operands;
      for (unsigned I = 0; I < NF; ++I)
        Operands.push_back(Ops[NF + I + 1]);
      Operands.push_back(Ops[2 * NF + 1]);
      Operands.push_back(Ops[NF]);
      Operands.push_back(Ops[2 * NF + 3]);
      Operands.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
      Value *NewVL = Ops[2 * NF + 2];
      assert(Operands.size() == NF + 4);
      llvm::Function *F = CGM.getIntrinsic(ID, IntrinsicTypes);
      llvm::Value *LoadValue = Builder.CreateCall(F, Operands, "");
      clang::CharUnits Align =
          CGM.getNaturalPointeeTypeAlignment(E->getArg(0)->getType());
      for (unsigned I = 0; I < NF; ++I) {
        Builder.CreateStore(Builder.CreateExtractValue(LoadValue, {I}),
                            Address(Ops[I], Align));
      }
      // Store new_vl.
      return Builder.CreateStore(Builder.CreateExtractValue(LoadValue, {NF}),
                                 Address(NewVL, Align));
    }
            break;
case RISCVVector::BI__builtin_rvv_vlseg4e8_v:
case RISCVVector::BI__builtin_rvv_vlseg4e16_v:
case RISCVVector::BI__builtin_rvv_vlseg4e32_v:
case RISCVVector::BI__builtin_rvv_vlseg4e64_v:
  ID = Intrinsic::riscv_vlseg4;
  NF = 4;

    {
      // builtin: (val0 address, val1 address, ..., ptr, vl)
      IntrinsicTypes = {ConvertType(E->getArg(0)->getType()->getPointeeType()),
                        Ops[NF + 1]->getType()};
      // intrinsic: (ptr, vl)
      llvm::Value *Operands[] = {Ops[NF], Ops[NF + 1]};
      llvm::Function *F = CGM.getIntrinsic(ID, IntrinsicTypes);
      llvm::Value *LoadValue = Builder.CreateCall(F, Operands, "");
      clang::CharUnits Align =
          CGM.getNaturalPointeeTypeAlignment(E->getArg(0)->getType());
      llvm::Value *V;
      for (unsigned I = 0; I < NF; ++I) {
        V = Builder.CreateStore(Builder.CreateExtractValue(LoadValue, {I}),
                                Address(Ops[I], Align));
      }
      return V;
    }
            break;
case RISCVVector::BI__builtin_rvv_vlseg4e8_v_m:
case RISCVVector::BI__builtin_rvv_vlseg4e16_v_m:
case RISCVVector::BI__builtin_rvv_vlseg4e32_v_m:
case RISCVVector::BI__builtin_rvv_vlseg4e64_v_m:
  ID = Intrinsic::riscv_vlseg4_mask;
  NF = 4;

    {
      // builtin: (val0 address, ..., mask, maskedoff0, ..., ptr, vl)
      // intrinsic: (maskedoff0, ..., ptr, mask, vl)
      IntrinsicTypes = {ConvertType(E->getArg(0)->getType()->getPointeeType()),
                        Ops[2 * NF + 2]->getType()};
      SmallVector<llvm::Value*, 12> Operands;
      for (unsigned I = 0; I < NF; ++I)
        Operands.push_back(Ops[NF + I + 1]);
      Operands.push_back(Ops[2 * NF + 1]);
      Operands.push_back(Ops[NF]);
      Operands.push_back(Ops[2 * NF + 2]);
      Operands.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
      assert(Operands.size() == NF + 4);
      llvm::Function *F = CGM.getIntrinsic(ID, IntrinsicTypes);
      llvm::Value *LoadValue = Builder.CreateCall(F, Operands, "");
      clang::CharUnits Align =
          CGM.getNaturalPointeeTypeAlignment(E->getArg(0)->getType());
      llvm::Value *V;
      for (unsigned I = 0; I < NF; ++I) {
        V = Builder.CreateStore(Builder.CreateExtractValue(LoadValue, {I}),
                                Address(Ops[I], Align));
      }
      return V;
    }
            break;
case RISCVVector::BI__builtin_rvv_vlseg4e8ff_v:
case RISCVVector::BI__builtin_rvv_vlseg4e16ff_v:
case RISCVVector::BI__builtin_rvv_vlseg4e32ff_v:
case RISCVVector::BI__builtin_rvv_vlseg4e64ff_v:
  ID = Intrinsic::riscv_vlseg4ff;
  NF = 4;

    {
      // builtin: (val0 address, val1 address, ..., ptr, new_vl, vl)
      IntrinsicTypes = {ConvertType(E->getArg(0)->getType()->getPointeeType()),
                        Ops[NF + 2]->getType()};
      // intrinsic: (ptr, vl)
      llvm::Value *Operands[] = {Ops[NF], Ops[NF + 2]};
      Value *NewVL = Ops[NF + 1];
      llvm::Function *F = CGM.getIntrinsic(ID, IntrinsicTypes);
      llvm::Value *LoadValue = Builder.CreateCall(F, Operands, "");
      clang::CharUnits Align =
          CGM.getNaturalPointeeTypeAlignment(E->getArg(0)->getType());
      for (unsigned I = 0; I < NF; ++I) {
        Builder.CreateStore(Builder.CreateExtractValue(LoadValue, {I}),
                            Address(Ops[I], Align));
      }
      // Store new_vl.
      return Builder.CreateStore(Builder.CreateExtractValue(LoadValue, {NF}),
                                 Address(NewVL, Align));
    }
            break;
case RISCVVector::BI__builtin_rvv_vlseg4e8ff_v_m:
case RISCVVector::BI__builtin_rvv_vlseg4e16ff_v_m:
case RISCVVector::BI__builtin_rvv_vlseg4e32ff_v_m:
case RISCVVector::BI__builtin_rvv_vlseg4e64ff_v_m:
  ID = Intrinsic::riscv_vlseg4ff_mask;
  NF = 4;

    {
      // builtin: (val0 address, ..., mask, maskedoff0, ..., ptr, new_vl, vl)
      // intrinsic: (maskedoff0, ..., ptr, mask, vl)
      IntrinsicTypes = {ConvertType(E->getArg(0)->getType()->getPointeeType()),
                        Ops[2 * NF + 3]->getType()};
      SmallVector<llvm::Value*, 12> Operands;
      for (unsigned I = 0; I < NF; ++I)
        Operands.push_back(Ops[NF + I + 1]);
      Operands.push_back(Ops[2 * NF + 1]);
      Operands.push_back(Ops[NF]);
      Operands.push_back(Ops[2 * NF + 3]);
      Operands.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
      Value *NewVL = Ops[2 * NF + 2];
      assert(Operands.size() == NF + 4);
      llvm::Function *F = CGM.getIntrinsic(ID, IntrinsicTypes);
      llvm::Value *LoadValue = Builder.CreateCall(F, Operands, "");
      clang::CharUnits Align =
          CGM.getNaturalPointeeTypeAlignment(E->getArg(0)->getType());
      for (unsigned I = 0; I < NF; ++I) {
        Builder.CreateStore(Builder.CreateExtractValue(LoadValue, {I}),
                            Address(Ops[I], Align));
      }
      // Store new_vl.
      return Builder.CreateStore(Builder.CreateExtractValue(LoadValue, {NF}),
                                 Address(NewVL, Align));
    }
            break;
case RISCVVector::BI__builtin_rvv_vlseg5e8_v:
case RISCVVector::BI__builtin_rvv_vlseg5e16_v:
case RISCVVector::BI__builtin_rvv_vlseg5e32_v:
case RISCVVector::BI__builtin_rvv_vlseg5e64_v:
  ID = Intrinsic::riscv_vlseg5;
  NF = 5;

    {
      // builtin: (val0 address, val1 address, ..., ptr, vl)
      IntrinsicTypes = {ConvertType(E->getArg(0)->getType()->getPointeeType()),
                        Ops[NF + 1]->getType()};
      // intrinsic: (ptr, vl)
      llvm::Value *Operands[] = {Ops[NF], Ops[NF + 1]};
      llvm::Function *F = CGM.getIntrinsic(ID, IntrinsicTypes);
      llvm::Value *LoadValue = Builder.CreateCall(F, Operands, "");
      clang::CharUnits Align =
          CGM.getNaturalPointeeTypeAlignment(E->getArg(0)->getType());
      llvm::Value *V;
      for (unsigned I = 0; I < NF; ++I) {
        V = Builder.CreateStore(Builder.CreateExtractValue(LoadValue, {I}),
                                Address(Ops[I], Align));
      }
      return V;
    }
            break;
case RISCVVector::BI__builtin_rvv_vlseg5e8_v_m:
case RISCVVector::BI__builtin_rvv_vlseg5e16_v_m:
case RISCVVector::BI__builtin_rvv_vlseg5e32_v_m:
case RISCVVector::BI__builtin_rvv_vlseg5e64_v_m:
  ID = Intrinsic::riscv_vlseg5_mask;
  NF = 5;

    {
      // builtin: (val0 address, ..., mask, maskedoff0, ..., ptr, vl)
      // intrinsic: (maskedoff0, ..., ptr, mask, vl)
      IntrinsicTypes = {ConvertType(E->getArg(0)->getType()->getPointeeType()),
                        Ops[2 * NF + 2]->getType()};
      SmallVector<llvm::Value*, 12> Operands;
      for (unsigned I = 0; I < NF; ++I)
        Operands.push_back(Ops[NF + I + 1]);
      Operands.push_back(Ops[2 * NF + 1]);
      Operands.push_back(Ops[NF]);
      Operands.push_back(Ops[2 * NF + 2]);
      Operands.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
      assert(Operands.size() == NF + 4);
      llvm::Function *F = CGM.getIntrinsic(ID, IntrinsicTypes);
      llvm::Value *LoadValue = Builder.CreateCall(F, Operands, "");
      clang::CharUnits Align =
          CGM.getNaturalPointeeTypeAlignment(E->getArg(0)->getType());
      llvm::Value *V;
      for (unsigned I = 0; I < NF; ++I) {
        V = Builder.CreateStore(Builder.CreateExtractValue(LoadValue, {I}),
                                Address(Ops[I], Align));
      }
      return V;
    }
            break;
case RISCVVector::BI__builtin_rvv_vlseg5e8ff_v:
case RISCVVector::BI__builtin_rvv_vlseg5e16ff_v:
case RISCVVector::BI__builtin_rvv_vlseg5e32ff_v:
case RISCVVector::BI__builtin_rvv_vlseg5e64ff_v:
  ID = Intrinsic::riscv_vlseg5ff;
  NF = 5;

    {
      // builtin: (val0 address, val1 address, ..., ptr, new_vl, vl)
      IntrinsicTypes = {ConvertType(E->getArg(0)->getType()->getPointeeType()),
                        Ops[NF + 2]->getType()};
      // intrinsic: (ptr, vl)
      llvm::Value *Operands[] = {Ops[NF], Ops[NF + 2]};
      Value *NewVL = Ops[NF + 1];
      llvm::Function *F = CGM.getIntrinsic(ID, IntrinsicTypes);
      llvm::Value *LoadValue = Builder.CreateCall(F, Operands, "");
      clang::CharUnits Align =
          CGM.getNaturalPointeeTypeAlignment(E->getArg(0)->getType());
      for (unsigned I = 0; I < NF; ++I) {
        Builder.CreateStore(Builder.CreateExtractValue(LoadValue, {I}),
                            Address(Ops[I], Align));
      }
      // Store new_vl.
      return Builder.CreateStore(Builder.CreateExtractValue(LoadValue, {NF}),
                                 Address(NewVL, Align));
    }
            break;
case RISCVVector::BI__builtin_rvv_vlseg5e8ff_v_m:
case RISCVVector::BI__builtin_rvv_vlseg5e16ff_v_m:
case RISCVVector::BI__builtin_rvv_vlseg5e32ff_v_m:
case RISCVVector::BI__builtin_rvv_vlseg5e64ff_v_m:
  ID = Intrinsic::riscv_vlseg5ff_mask;
  NF = 5;

    {
      // builtin: (val0 address, ..., mask, maskedoff0, ..., ptr, new_vl, vl)
      // intrinsic: (maskedoff0, ..., ptr, mask, vl)
      IntrinsicTypes = {ConvertType(E->getArg(0)->getType()->getPointeeType()),
                        Ops[2 * NF + 3]->getType()};
      SmallVector<llvm::Value*, 12> Operands;
      for (unsigned I = 0; I < NF; ++I)
        Operands.push_back(Ops[NF + I + 1]);
      Operands.push_back(Ops[2 * NF + 1]);
      Operands.push_back(Ops[NF]);
      Operands.push_back(Ops[2 * NF + 3]);
      Operands.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
      Value *NewVL = Ops[2 * NF + 2];
      assert(Operands.size() == NF + 4);
      llvm::Function *F = CGM.getIntrinsic(ID, IntrinsicTypes);
      llvm::Value *LoadValue = Builder.CreateCall(F, Operands, "");
      clang::CharUnits Align =
          CGM.getNaturalPointeeTypeAlignment(E->getArg(0)->getType());
      for (unsigned I = 0; I < NF; ++I) {
        Builder.CreateStore(Builder.CreateExtractValue(LoadValue, {I}),
                            Address(Ops[I], Align));
      }
      // Store new_vl.
      return Builder.CreateStore(Builder.CreateExtractValue(LoadValue, {NF}),
                                 Address(NewVL, Align));
    }
            break;
case RISCVVector::BI__builtin_rvv_vlseg6e8_v:
case RISCVVector::BI__builtin_rvv_vlseg6e16_v:
case RISCVVector::BI__builtin_rvv_vlseg6e32_v:
case RISCVVector::BI__builtin_rvv_vlseg6e64_v:
  ID = Intrinsic::riscv_vlseg6;
  NF = 6;

    {
      // builtin: (val0 address, val1 address, ..., ptr, vl)
      IntrinsicTypes = {ConvertType(E->getArg(0)->getType()->getPointeeType()),
                        Ops[NF + 1]->getType()};
      // intrinsic: (ptr, vl)
      llvm::Value *Operands[] = {Ops[NF], Ops[NF + 1]};
      llvm::Function *F = CGM.getIntrinsic(ID, IntrinsicTypes);
      llvm::Value *LoadValue = Builder.CreateCall(F, Operands, "");
      clang::CharUnits Align =
          CGM.getNaturalPointeeTypeAlignment(E->getArg(0)->getType());
      llvm::Value *V;
      for (unsigned I = 0; I < NF; ++I) {
        V = Builder.CreateStore(Builder.CreateExtractValue(LoadValue, {I}),
                                Address(Ops[I], Align));
      }
      return V;
    }
            break;
case RISCVVector::BI__builtin_rvv_vlseg6e8_v_m:
case RISCVVector::BI__builtin_rvv_vlseg6e16_v_m:
case RISCVVector::BI__builtin_rvv_vlseg6e32_v_m:
case RISCVVector::BI__builtin_rvv_vlseg6e64_v_m:
  ID = Intrinsic::riscv_vlseg6_mask;
  NF = 6;

    {
      // builtin: (val0 address, ..., mask, maskedoff0, ..., ptr, vl)
      // intrinsic: (maskedoff0, ..., ptr, mask, vl)
      IntrinsicTypes = {ConvertType(E->getArg(0)->getType()->getPointeeType()),
                        Ops[2 * NF + 2]->getType()};
      SmallVector<llvm::Value*, 12> Operands;
      for (unsigned I = 0; I < NF; ++I)
        Operands.push_back(Ops[NF + I + 1]);
      Operands.push_back(Ops[2 * NF + 1]);
      Operands.push_back(Ops[NF]);
      Operands.push_back(Ops[2 * NF + 2]);
      Operands.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
      assert(Operands.size() == NF + 4);
      llvm::Function *F = CGM.getIntrinsic(ID, IntrinsicTypes);
      llvm::Value *LoadValue = Builder.CreateCall(F, Operands, "");
      clang::CharUnits Align =
          CGM.getNaturalPointeeTypeAlignment(E->getArg(0)->getType());
      llvm::Value *V;
      for (unsigned I = 0; I < NF; ++I) {
        V = Builder.CreateStore(Builder.CreateExtractValue(LoadValue, {I}),
                                Address(Ops[I], Align));
      }
      return V;
    }
            break;
case RISCVVector::BI__builtin_rvv_vlseg6e8ff_v:
case RISCVVector::BI__builtin_rvv_vlseg6e16ff_v:
case RISCVVector::BI__builtin_rvv_vlseg6e32ff_v:
case RISCVVector::BI__builtin_rvv_vlseg6e64ff_v:
  ID = Intrinsic::riscv_vlseg6ff;
  NF = 6;

    {
      // builtin: (val0 address, val1 address, ..., ptr, new_vl, vl)
      IntrinsicTypes = {ConvertType(E->getArg(0)->getType()->getPointeeType()),
                        Ops[NF + 2]->getType()};
      // intrinsic: (ptr, vl)
      llvm::Value *Operands[] = {Ops[NF], Ops[NF + 2]};
      Value *NewVL = Ops[NF + 1];
      llvm::Function *F = CGM.getIntrinsic(ID, IntrinsicTypes);
      llvm::Value *LoadValue = Builder.CreateCall(F, Operands, "");
      clang::CharUnits Align =
          CGM.getNaturalPointeeTypeAlignment(E->getArg(0)->getType());
      for (unsigned I = 0; I < NF; ++I) {
        Builder.CreateStore(Builder.CreateExtractValue(LoadValue, {I}),
                            Address(Ops[I], Align));
      }
      // Store new_vl.
      return Builder.CreateStore(Builder.CreateExtractValue(LoadValue, {NF}),
                                 Address(NewVL, Align));
    }
            break;
case RISCVVector::BI__builtin_rvv_vlseg6e8ff_v_m:
case RISCVVector::BI__builtin_rvv_vlseg6e16ff_v_m:
case RISCVVector::BI__builtin_rvv_vlseg6e32ff_v_m:
case RISCVVector::BI__builtin_rvv_vlseg6e64ff_v_m:
  ID = Intrinsic::riscv_vlseg6ff_mask;
  NF = 6;

    {
      // builtin: (val0 address, ..., mask, maskedoff0, ..., ptr, new_vl, vl)
      // intrinsic: (maskedoff0, ..., ptr, mask, vl)
      IntrinsicTypes = {ConvertType(E->getArg(0)->getType()->getPointeeType()),
                        Ops[2 * NF + 3]->getType()};
      SmallVector<llvm::Value*, 12> Operands;
      for (unsigned I = 0; I < NF; ++I)
        Operands.push_back(Ops[NF + I + 1]);
      Operands.push_back(Ops[2 * NF + 1]);
      Operands.push_back(Ops[NF]);
      Operands.push_back(Ops[2 * NF + 3]);
      Operands.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
      Value *NewVL = Ops[2 * NF + 2];
      assert(Operands.size() == NF + 4);
      llvm::Function *F = CGM.getIntrinsic(ID, IntrinsicTypes);
      llvm::Value *LoadValue = Builder.CreateCall(F, Operands, "");
      clang::CharUnits Align =
          CGM.getNaturalPointeeTypeAlignment(E->getArg(0)->getType());
      for (unsigned I = 0; I < NF; ++I) {
        Builder.CreateStore(Builder.CreateExtractValue(LoadValue, {I}),
                            Address(Ops[I], Align));
      }
      // Store new_vl.
      return Builder.CreateStore(Builder.CreateExtractValue(LoadValue, {NF}),
                                 Address(NewVL, Align));
    }
            break;
case RISCVVector::BI__builtin_rvv_vlseg7e8_v:
case RISCVVector::BI__builtin_rvv_vlseg7e16_v:
case RISCVVector::BI__builtin_rvv_vlseg7e32_v:
case RISCVVector::BI__builtin_rvv_vlseg7e64_v:
  ID = Intrinsic::riscv_vlseg7;
  NF = 7;

    {
      // builtin: (val0 address, val1 address, ..., ptr, vl)
      IntrinsicTypes = {ConvertType(E->getArg(0)->getType()->getPointeeType()),
                        Ops[NF + 1]->getType()};
      // intrinsic: (ptr, vl)
      llvm::Value *Operands[] = {Ops[NF], Ops[NF + 1]};
      llvm::Function *F = CGM.getIntrinsic(ID, IntrinsicTypes);
      llvm::Value *LoadValue = Builder.CreateCall(F, Operands, "");
      clang::CharUnits Align =
          CGM.getNaturalPointeeTypeAlignment(E->getArg(0)->getType());
      llvm::Value *V;
      for (unsigned I = 0; I < NF; ++I) {
        V = Builder.CreateStore(Builder.CreateExtractValue(LoadValue, {I}),
                                Address(Ops[I], Align));
      }
      return V;
    }
            break;
case RISCVVector::BI__builtin_rvv_vlseg7e8_v_m:
case RISCVVector::BI__builtin_rvv_vlseg7e16_v_m:
case RISCVVector::BI__builtin_rvv_vlseg7e32_v_m:
case RISCVVector::BI__builtin_rvv_vlseg7e64_v_m:
  ID = Intrinsic::riscv_vlseg7_mask;
  NF = 7;

    {
      // builtin: (val0 address, ..., mask, maskedoff0, ..., ptr, vl)
      // intrinsic: (maskedoff0, ..., ptr, mask, vl)
      IntrinsicTypes = {ConvertType(E->getArg(0)->getType()->getPointeeType()),
                        Ops[2 * NF + 2]->getType()};
      SmallVector<llvm::Value*, 12> Operands;
      for (unsigned I = 0; I < NF; ++I)
        Operands.push_back(Ops[NF + I + 1]);
      Operands.push_back(Ops[2 * NF + 1]);
      Operands.push_back(Ops[NF]);
      Operands.push_back(Ops[2 * NF + 2]);
      Operands.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
      assert(Operands.size() == NF + 4);
      llvm::Function *F = CGM.getIntrinsic(ID, IntrinsicTypes);
      llvm::Value *LoadValue = Builder.CreateCall(F, Operands, "");
      clang::CharUnits Align =
          CGM.getNaturalPointeeTypeAlignment(E->getArg(0)->getType());
      llvm::Value *V;
      for (unsigned I = 0; I < NF; ++I) {
        V = Builder.CreateStore(Builder.CreateExtractValue(LoadValue, {I}),
                                Address(Ops[I], Align));
      }
      return V;
    }
            break;
case RISCVVector::BI__builtin_rvv_vlseg7e8ff_v:
case RISCVVector::BI__builtin_rvv_vlseg7e16ff_v:
case RISCVVector::BI__builtin_rvv_vlseg7e32ff_v:
case RISCVVector::BI__builtin_rvv_vlseg7e64ff_v:
  ID = Intrinsic::riscv_vlseg7ff;
  NF = 7;

    {
      // builtin: (val0 address, val1 address, ..., ptr, new_vl, vl)
      IntrinsicTypes = {ConvertType(E->getArg(0)->getType()->getPointeeType()),
                        Ops[NF + 2]->getType()};
      // intrinsic: (ptr, vl)
      llvm::Value *Operands[] = {Ops[NF], Ops[NF + 2]};
      Value *NewVL = Ops[NF + 1];
      llvm::Function *F = CGM.getIntrinsic(ID, IntrinsicTypes);
      llvm::Value *LoadValue = Builder.CreateCall(F, Operands, "");
      clang::CharUnits Align =
          CGM.getNaturalPointeeTypeAlignment(E->getArg(0)->getType());
      for (unsigned I = 0; I < NF; ++I) {
        Builder.CreateStore(Builder.CreateExtractValue(LoadValue, {I}),
                            Address(Ops[I], Align));
      }
      // Store new_vl.
      return Builder.CreateStore(Builder.CreateExtractValue(LoadValue, {NF}),
                                 Address(NewVL, Align));
    }
            break;
case RISCVVector::BI__builtin_rvv_vlseg7e8ff_v_m:
case RISCVVector::BI__builtin_rvv_vlseg7e16ff_v_m:
case RISCVVector::BI__builtin_rvv_vlseg7e32ff_v_m:
case RISCVVector::BI__builtin_rvv_vlseg7e64ff_v_m:
  ID = Intrinsic::riscv_vlseg7ff_mask;
  NF = 7;

    {
      // builtin: (val0 address, ..., mask, maskedoff0, ..., ptr, new_vl, vl)
      // intrinsic: (maskedoff0, ..., ptr, mask, vl)
      IntrinsicTypes = {ConvertType(E->getArg(0)->getType()->getPointeeType()),
                        Ops[2 * NF + 3]->getType()};
      SmallVector<llvm::Value*, 12> Operands;
      for (unsigned I = 0; I < NF; ++I)
        Operands.push_back(Ops[NF + I + 1]);
      Operands.push_back(Ops[2 * NF + 1]);
      Operands.push_back(Ops[NF]);
      Operands.push_back(Ops[2 * NF + 3]);
      Operands.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
      Value *NewVL = Ops[2 * NF + 2];
      assert(Operands.size() == NF + 4);
      llvm::Function *F = CGM.getIntrinsic(ID, IntrinsicTypes);
      llvm::Value *LoadValue = Builder.CreateCall(F, Operands, "");
      clang::CharUnits Align =
          CGM.getNaturalPointeeTypeAlignment(E->getArg(0)->getType());
      for (unsigned I = 0; I < NF; ++I) {
        Builder.CreateStore(Builder.CreateExtractValue(LoadValue, {I}),
                            Address(Ops[I], Align));
      }
      // Store new_vl.
      return Builder.CreateStore(Builder.CreateExtractValue(LoadValue, {NF}),
                                 Address(NewVL, Align));
    }
            break;
case RISCVVector::BI__builtin_rvv_vlseg8e8_v:
case RISCVVector::BI__builtin_rvv_vlseg8e16_v:
case RISCVVector::BI__builtin_rvv_vlseg8e32_v:
case RISCVVector::BI__builtin_rvv_vlseg8e64_v:
  ID = Intrinsic::riscv_vlseg8;
  NF = 8;

    {
      // builtin: (val0 address, val1 address, ..., ptr, vl)
      IntrinsicTypes = {ConvertType(E->getArg(0)->getType()->getPointeeType()),
                        Ops[NF + 1]->getType()};
      // intrinsic: (ptr, vl)
      llvm::Value *Operands[] = {Ops[NF], Ops[NF + 1]};
      llvm::Function *F = CGM.getIntrinsic(ID, IntrinsicTypes);
      llvm::Value *LoadValue = Builder.CreateCall(F, Operands, "");
      clang::CharUnits Align =
          CGM.getNaturalPointeeTypeAlignment(E->getArg(0)->getType());
      llvm::Value *V;
      for (unsigned I = 0; I < NF; ++I) {
        V = Builder.CreateStore(Builder.CreateExtractValue(LoadValue, {I}),
                                Address(Ops[I], Align));
      }
      return V;
    }
            break;
case RISCVVector::BI__builtin_rvv_vlseg8e8_v_m:
case RISCVVector::BI__builtin_rvv_vlseg8e16_v_m:
case RISCVVector::BI__builtin_rvv_vlseg8e32_v_m:
case RISCVVector::BI__builtin_rvv_vlseg8e64_v_m:
  ID = Intrinsic::riscv_vlseg8_mask;
  NF = 8;

    {
      // builtin: (val0 address, ..., mask, maskedoff0, ..., ptr, vl)
      // intrinsic: (maskedoff0, ..., ptr, mask, vl)
      IntrinsicTypes = {ConvertType(E->getArg(0)->getType()->getPointeeType()),
                        Ops[2 * NF + 2]->getType()};
      SmallVector<llvm::Value*, 12> Operands;
      for (unsigned I = 0; I < NF; ++I)
        Operands.push_back(Ops[NF + I + 1]);
      Operands.push_back(Ops[2 * NF + 1]);
      Operands.push_back(Ops[NF]);
      Operands.push_back(Ops[2 * NF + 2]);
      Operands.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
      assert(Operands.size() == NF + 4);
      llvm::Function *F = CGM.getIntrinsic(ID, IntrinsicTypes);
      llvm::Value *LoadValue = Builder.CreateCall(F, Operands, "");
      clang::CharUnits Align =
          CGM.getNaturalPointeeTypeAlignment(E->getArg(0)->getType());
      llvm::Value *V;
      for (unsigned I = 0; I < NF; ++I) {
        V = Builder.CreateStore(Builder.CreateExtractValue(LoadValue, {I}),
                                Address(Ops[I], Align));
      }
      return V;
    }
            break;
case RISCVVector::BI__builtin_rvv_vlseg8e8ff_v:
case RISCVVector::BI__builtin_rvv_vlseg8e16ff_v:
case RISCVVector::BI__builtin_rvv_vlseg8e32ff_v:
case RISCVVector::BI__builtin_rvv_vlseg8e64ff_v:
  ID = Intrinsic::riscv_vlseg8ff;
  NF = 8;

    {
      // builtin: (val0 address, val1 address, ..., ptr, new_vl, vl)
      IntrinsicTypes = {ConvertType(E->getArg(0)->getType()->getPointeeType()),
                        Ops[NF + 2]->getType()};
      // intrinsic: (ptr, vl)
      llvm::Value *Operands[] = {Ops[NF], Ops[NF + 2]};
      Value *NewVL = Ops[NF + 1];
      llvm::Function *F = CGM.getIntrinsic(ID, IntrinsicTypes);
      llvm::Value *LoadValue = Builder.CreateCall(F, Operands, "");
      clang::CharUnits Align =
          CGM.getNaturalPointeeTypeAlignment(E->getArg(0)->getType());
      for (unsigned I = 0; I < NF; ++I) {
        Builder.CreateStore(Builder.CreateExtractValue(LoadValue, {I}),
                            Address(Ops[I], Align));
      }
      // Store new_vl.
      return Builder.CreateStore(Builder.CreateExtractValue(LoadValue, {NF}),
                                 Address(NewVL, Align));
    }
            break;
case RISCVVector::BI__builtin_rvv_vlseg8e8ff_v_m:
case RISCVVector::BI__builtin_rvv_vlseg8e16ff_v_m:
case RISCVVector::BI__builtin_rvv_vlseg8e32ff_v_m:
case RISCVVector::BI__builtin_rvv_vlseg8e64ff_v_m:
  ID = Intrinsic::riscv_vlseg8ff_mask;
  NF = 8;

    {
      // builtin: (val0 address, ..., mask, maskedoff0, ..., ptr, new_vl, vl)
      // intrinsic: (maskedoff0, ..., ptr, mask, vl)
      IntrinsicTypes = {ConvertType(E->getArg(0)->getType()->getPointeeType()),
                        Ops[2 * NF + 3]->getType()};
      SmallVector<llvm::Value*, 12> Operands;
      for (unsigned I = 0; I < NF; ++I)
        Operands.push_back(Ops[NF + I + 1]);
      Operands.push_back(Ops[2 * NF + 1]);
      Operands.push_back(Ops[NF]);
      Operands.push_back(Ops[2 * NF + 3]);
      Operands.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
      Value *NewVL = Ops[2 * NF + 2];
      assert(Operands.size() == NF + 4);
      llvm::Function *F = CGM.getIntrinsic(ID, IntrinsicTypes);
      llvm::Value *LoadValue = Builder.CreateCall(F, Operands, "");
      clang::CharUnits Align =
          CGM.getNaturalPointeeTypeAlignment(E->getArg(0)->getType());
      for (unsigned I = 0; I < NF; ++I) {
        Builder.CreateStore(Builder.CreateExtractValue(LoadValue, {I}),
                            Address(Ops[I], Align));
      }
      // Store new_vl.
      return Builder.CreateStore(Builder.CreateExtractValue(LoadValue, {NF}),
                                 Address(NewVL, Align));
    }
            break;
case RISCVVector::BI__builtin_rvv_vlsseg2e8_v:
case RISCVVector::BI__builtin_rvv_vlsseg2e16_v:
case RISCVVector::BI__builtin_rvv_vlsseg2e32_v:
case RISCVVector::BI__builtin_rvv_vlsseg2e64_v:
  ID = Intrinsic::riscv_vlsseg2;
  NF = 2;

    {
      // builtin: (val0 address, val1 address, ..., ptr, stride, vl)
      IntrinsicTypes = {ConvertType(E->getArg(0)->getType()->getPointeeType()),
                        Ops[NF + 2]->getType()};
      // intrinsic: (ptr, stride, vl)
      llvm::Value *Operands[] = {Ops[NF], Ops[NF + 1], Ops[NF + 2]};
      llvm::Function *F = CGM.getIntrinsic(ID, IntrinsicTypes);
      llvm::Value *LoadValue = Builder.CreateCall(F, Operands, "");
      clang::CharUnits Align =
          CGM.getNaturalPointeeTypeAlignment(E->getArg(0)->getType());
      llvm::Value *V;
      for (unsigned I = 0; I < NF; ++I) {
        V = Builder.CreateStore(Builder.CreateExtractValue(LoadValue, {I}),
                                Address(Ops[I], Align));
      }
      return V;
    }
            break;
case RISCVVector::BI__builtin_rvv_vlsseg2e8_v_m:
case RISCVVector::BI__builtin_rvv_vlsseg2e16_v_m:
case RISCVVector::BI__builtin_rvv_vlsseg2e32_v_m:
case RISCVVector::BI__builtin_rvv_vlsseg2e64_v_m:
  ID = Intrinsic::riscv_vlsseg2_mask;
  NF = 2;

    {
      // builtin: (val0 address, ..., mask, maskedoff0, ..., ptr, stride, vl)
      // intrinsic: (maskedoff0, ..., ptr, stride, mask, vl)
      IntrinsicTypes = {ConvertType(E->getArg(0)->getType()->getPointeeType()),
                        Ops[2 * NF + 3]->getType()};
      SmallVector<llvm::Value*, 12> Operands;
      for (unsigned I = 0; I < NF; ++I)
        Operands.push_back(Ops[NF + I + 1]);
      Operands.push_back(Ops[2 * NF + 1]);
      Operands.push_back(Ops[2 * NF + 2]);
      Operands.push_back(Ops[NF]);
      Operands.push_back(Ops[2 * NF + 3]);
      Operands.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
      assert(Operands.size() == NF + 5);
      llvm::Function *F = CGM.getIntrinsic(ID, IntrinsicTypes);
      llvm::Value *LoadValue = Builder.CreateCall(F, Operands, "");
      clang::CharUnits Align =
          CGM.getNaturalPointeeTypeAlignment(E->getArg(0)->getType());
      llvm::Value *V;
      for (unsigned I = 0; I < NF; ++I) {
        V = Builder.CreateStore(Builder.CreateExtractValue(LoadValue, {I}),
                                Address(Ops[I], Align));
      }
      return V;
    }
            break;
case RISCVVector::BI__builtin_rvv_vlsseg3e8_v:
case RISCVVector::BI__builtin_rvv_vlsseg3e16_v:
case RISCVVector::BI__builtin_rvv_vlsseg3e32_v:
case RISCVVector::BI__builtin_rvv_vlsseg3e64_v:
  ID = Intrinsic::riscv_vlsseg3;
  NF = 3;

    {
      // builtin: (val0 address, val1 address, ..., ptr, stride, vl)
      IntrinsicTypes = {ConvertType(E->getArg(0)->getType()->getPointeeType()),
                        Ops[NF + 2]->getType()};
      // intrinsic: (ptr, stride, vl)
      llvm::Value *Operands[] = {Ops[NF], Ops[NF + 1], Ops[NF + 2]};
      llvm::Function *F = CGM.getIntrinsic(ID, IntrinsicTypes);
      llvm::Value *LoadValue = Builder.CreateCall(F, Operands, "");
      clang::CharUnits Align =
          CGM.getNaturalPointeeTypeAlignment(E->getArg(0)->getType());
      llvm::Value *V;
      for (unsigned I = 0; I < NF; ++I) {
        V = Builder.CreateStore(Builder.CreateExtractValue(LoadValue, {I}),
                                Address(Ops[I], Align));
      }
      return V;
    }
            break;
case RISCVVector::BI__builtin_rvv_vlsseg3e8_v_m:
case RISCVVector::BI__builtin_rvv_vlsseg3e16_v_m:
case RISCVVector::BI__builtin_rvv_vlsseg3e32_v_m:
case RISCVVector::BI__builtin_rvv_vlsseg3e64_v_m:
  ID = Intrinsic::riscv_vlsseg3_mask;
  NF = 3;

    {
      // builtin: (val0 address, ..., mask, maskedoff0, ..., ptr, stride, vl)
      // intrinsic: (maskedoff0, ..., ptr, stride, mask, vl)
      IntrinsicTypes = {ConvertType(E->getArg(0)->getType()->getPointeeType()),
                        Ops[2 * NF + 3]->getType()};
      SmallVector<llvm::Value*, 12> Operands;
      for (unsigned I = 0; I < NF; ++I)
        Operands.push_back(Ops[NF + I + 1]);
      Operands.push_back(Ops[2 * NF + 1]);
      Operands.push_back(Ops[2 * NF + 2]);
      Operands.push_back(Ops[NF]);
      Operands.push_back(Ops[2 * NF + 3]);
      Operands.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
      assert(Operands.size() == NF + 5);
      llvm::Function *F = CGM.getIntrinsic(ID, IntrinsicTypes);
      llvm::Value *LoadValue = Builder.CreateCall(F, Operands, "");
      clang::CharUnits Align =
          CGM.getNaturalPointeeTypeAlignment(E->getArg(0)->getType());
      llvm::Value *V;
      for (unsigned I = 0; I < NF; ++I) {
        V = Builder.CreateStore(Builder.CreateExtractValue(LoadValue, {I}),
                                Address(Ops[I], Align));
      }
      return V;
    }
            break;
case RISCVVector::BI__builtin_rvv_vlsseg4e8_v:
case RISCVVector::BI__builtin_rvv_vlsseg4e16_v:
case RISCVVector::BI__builtin_rvv_vlsseg4e32_v:
case RISCVVector::BI__builtin_rvv_vlsseg4e64_v:
  ID = Intrinsic::riscv_vlsseg4;
  NF = 4;

    {
      // builtin: (val0 address, val1 address, ..., ptr, stride, vl)
      IntrinsicTypes = {ConvertType(E->getArg(0)->getType()->getPointeeType()),
                        Ops[NF + 2]->getType()};
      // intrinsic: (ptr, stride, vl)
      llvm::Value *Operands[] = {Ops[NF], Ops[NF + 1], Ops[NF + 2]};
      llvm::Function *F = CGM.getIntrinsic(ID, IntrinsicTypes);
      llvm::Value *LoadValue = Builder.CreateCall(F, Operands, "");
      clang::CharUnits Align =
          CGM.getNaturalPointeeTypeAlignment(E->getArg(0)->getType());
      llvm::Value *V;
      for (unsigned I = 0; I < NF; ++I) {
        V = Builder.CreateStore(Builder.CreateExtractValue(LoadValue, {I}),
                                Address(Ops[I], Align));
      }
      return V;
    }
            break;
case RISCVVector::BI__builtin_rvv_vlsseg4e8_v_m:
case RISCVVector::BI__builtin_rvv_vlsseg4e16_v_m:
case RISCVVector::BI__builtin_rvv_vlsseg4e32_v_m:
case RISCVVector::BI__builtin_rvv_vlsseg4e64_v_m:
  ID = Intrinsic::riscv_vlsseg4_mask;
  NF = 4;

    {
      // builtin: (val0 address, ..., mask, maskedoff0, ..., ptr, stride, vl)
      // intrinsic: (maskedoff0, ..., ptr, stride, mask, vl)
      IntrinsicTypes = {ConvertType(E->getArg(0)->getType()->getPointeeType()),
                        Ops[2 * NF + 3]->getType()};
      SmallVector<llvm::Value*, 12> Operands;
      for (unsigned I = 0; I < NF; ++I)
        Operands.push_back(Ops[NF + I + 1]);
      Operands.push_back(Ops[2 * NF + 1]);
      Operands.push_back(Ops[2 * NF + 2]);
      Operands.push_back(Ops[NF]);
      Operands.push_back(Ops[2 * NF + 3]);
      Operands.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
      assert(Operands.size() == NF + 5);
      llvm::Function *F = CGM.getIntrinsic(ID, IntrinsicTypes);
      llvm::Value *LoadValue = Builder.CreateCall(F, Operands, "");
      clang::CharUnits Align =
          CGM.getNaturalPointeeTypeAlignment(E->getArg(0)->getType());
      llvm::Value *V;
      for (unsigned I = 0; I < NF; ++I) {
        V = Builder.CreateStore(Builder.CreateExtractValue(LoadValue, {I}),
                                Address(Ops[I], Align));
      }
      return V;
    }
            break;
case RISCVVector::BI__builtin_rvv_vlsseg5e8_v:
case RISCVVector::BI__builtin_rvv_vlsseg5e16_v:
case RISCVVector::BI__builtin_rvv_vlsseg5e32_v:
case RISCVVector::BI__builtin_rvv_vlsseg5e64_v:
  ID = Intrinsic::riscv_vlsseg5;
  NF = 5;

    {
      // builtin: (val0 address, val1 address, ..., ptr, stride, vl)
      IntrinsicTypes = {ConvertType(E->getArg(0)->getType()->getPointeeType()),
                        Ops[NF + 2]->getType()};
      // intrinsic: (ptr, stride, vl)
      llvm::Value *Operands[] = {Ops[NF], Ops[NF + 1], Ops[NF + 2]};
      llvm::Function *F = CGM.getIntrinsic(ID, IntrinsicTypes);
      llvm::Value *LoadValue = Builder.CreateCall(F, Operands, "");
      clang::CharUnits Align =
          CGM.getNaturalPointeeTypeAlignment(E->getArg(0)->getType());
      llvm::Value *V;
      for (unsigned I = 0; I < NF; ++I) {
        V = Builder.CreateStore(Builder.CreateExtractValue(LoadValue, {I}),
                                Address(Ops[I], Align));
      }
      return V;
    }
            break;
case RISCVVector::BI__builtin_rvv_vlsseg5e8_v_m:
case RISCVVector::BI__builtin_rvv_vlsseg5e16_v_m:
case RISCVVector::BI__builtin_rvv_vlsseg5e32_v_m:
case RISCVVector::BI__builtin_rvv_vlsseg5e64_v_m:
  ID = Intrinsic::riscv_vlsseg5_mask;
  NF = 5;

    {
      // builtin: (val0 address, ..., mask, maskedoff0, ..., ptr, stride, vl)
      // intrinsic: (maskedoff0, ..., ptr, stride, mask, vl)
      IntrinsicTypes = {ConvertType(E->getArg(0)->getType()->getPointeeType()),
                        Ops[2 * NF + 3]->getType()};
      SmallVector<llvm::Value*, 12> Operands;
      for (unsigned I = 0; I < NF; ++I)
        Operands.push_back(Ops[NF + I + 1]);
      Operands.push_back(Ops[2 * NF + 1]);
      Operands.push_back(Ops[2 * NF + 2]);
      Operands.push_back(Ops[NF]);
      Operands.push_back(Ops[2 * NF + 3]);
      Operands.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
      assert(Operands.size() == NF + 5);
      llvm::Function *F = CGM.getIntrinsic(ID, IntrinsicTypes);
      llvm::Value *LoadValue = Builder.CreateCall(F, Operands, "");
      clang::CharUnits Align =
          CGM.getNaturalPointeeTypeAlignment(E->getArg(0)->getType());
      llvm::Value *V;
      for (unsigned I = 0; I < NF; ++I) {
        V = Builder.CreateStore(Builder.CreateExtractValue(LoadValue, {I}),
                                Address(Ops[I], Align));
      }
      return V;
    }
            break;
case RISCVVector::BI__builtin_rvv_vlsseg6e8_v:
case RISCVVector::BI__builtin_rvv_vlsseg6e16_v:
case RISCVVector::BI__builtin_rvv_vlsseg6e32_v:
case RISCVVector::BI__builtin_rvv_vlsseg6e64_v:
  ID = Intrinsic::riscv_vlsseg6;
  NF = 6;

    {
      // builtin: (val0 address, val1 address, ..., ptr, stride, vl)
      IntrinsicTypes = {ConvertType(E->getArg(0)->getType()->getPointeeType()),
                        Ops[NF + 2]->getType()};
      // intrinsic: (ptr, stride, vl)
      llvm::Value *Operands[] = {Ops[NF], Ops[NF + 1], Ops[NF + 2]};
      llvm::Function *F = CGM.getIntrinsic(ID, IntrinsicTypes);
      llvm::Value *LoadValue = Builder.CreateCall(F, Operands, "");
      clang::CharUnits Align =
          CGM.getNaturalPointeeTypeAlignment(E->getArg(0)->getType());
      llvm::Value *V;
      for (unsigned I = 0; I < NF; ++I) {
        V = Builder.CreateStore(Builder.CreateExtractValue(LoadValue, {I}),
                                Address(Ops[I], Align));
      }
      return V;
    }
            break;
case RISCVVector::BI__builtin_rvv_vlsseg6e8_v_m:
case RISCVVector::BI__builtin_rvv_vlsseg6e16_v_m:
case RISCVVector::BI__builtin_rvv_vlsseg6e32_v_m:
case RISCVVector::BI__builtin_rvv_vlsseg6e64_v_m:
  ID = Intrinsic::riscv_vlsseg6_mask;
  NF = 6;

    {
      // builtin: (val0 address, ..., mask, maskedoff0, ..., ptr, stride, vl)
      // intrinsic: (maskedoff0, ..., ptr, stride, mask, vl)
      IntrinsicTypes = {ConvertType(E->getArg(0)->getType()->getPointeeType()),
                        Ops[2 * NF + 3]->getType()};
      SmallVector<llvm::Value*, 12> Operands;
      for (unsigned I = 0; I < NF; ++I)
        Operands.push_back(Ops[NF + I + 1]);
      Operands.push_back(Ops[2 * NF + 1]);
      Operands.push_back(Ops[2 * NF + 2]);
      Operands.push_back(Ops[NF]);
      Operands.push_back(Ops[2 * NF + 3]);
      Operands.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
      assert(Operands.size() == NF + 5);
      llvm::Function *F = CGM.getIntrinsic(ID, IntrinsicTypes);
      llvm::Value *LoadValue = Builder.CreateCall(F, Operands, "");
      clang::CharUnits Align =
          CGM.getNaturalPointeeTypeAlignment(E->getArg(0)->getType());
      llvm::Value *V;
      for (unsigned I = 0; I < NF; ++I) {
        V = Builder.CreateStore(Builder.CreateExtractValue(LoadValue, {I}),
                                Address(Ops[I], Align));
      }
      return V;
    }
            break;
case RISCVVector::BI__builtin_rvv_vlsseg7e8_v:
case RISCVVector::BI__builtin_rvv_vlsseg7e16_v:
case RISCVVector::BI__builtin_rvv_vlsseg7e32_v:
case RISCVVector::BI__builtin_rvv_vlsseg7e64_v:
  ID = Intrinsic::riscv_vlsseg7;
  NF = 7;

    {
      // builtin: (val0 address, val1 address, ..., ptr, stride, vl)
      IntrinsicTypes = {ConvertType(E->getArg(0)->getType()->getPointeeType()),
                        Ops[NF + 2]->getType()};
      // intrinsic: (ptr, stride, vl)
      llvm::Value *Operands[] = {Ops[NF], Ops[NF + 1], Ops[NF + 2]};
      llvm::Function *F = CGM.getIntrinsic(ID, IntrinsicTypes);
      llvm::Value *LoadValue = Builder.CreateCall(F, Operands, "");
      clang::CharUnits Align =
          CGM.getNaturalPointeeTypeAlignment(E->getArg(0)->getType());
      llvm::Value *V;
      for (unsigned I = 0; I < NF; ++I) {
        V = Builder.CreateStore(Builder.CreateExtractValue(LoadValue, {I}),
                                Address(Ops[I], Align));
      }
      return V;
    }
            break;
case RISCVVector::BI__builtin_rvv_vlsseg7e8_v_m:
case RISCVVector::BI__builtin_rvv_vlsseg7e16_v_m:
case RISCVVector::BI__builtin_rvv_vlsseg7e32_v_m:
case RISCVVector::BI__builtin_rvv_vlsseg7e64_v_m:
  ID = Intrinsic::riscv_vlsseg7_mask;
  NF = 7;

    {
      // builtin: (val0 address, ..., mask, maskedoff0, ..., ptr, stride, vl)
      // intrinsic: (maskedoff0, ..., ptr, stride, mask, vl)
      IntrinsicTypes = {ConvertType(E->getArg(0)->getType()->getPointeeType()),
                        Ops[2 * NF + 3]->getType()};
      SmallVector<llvm::Value*, 12> Operands;
      for (unsigned I = 0; I < NF; ++I)
        Operands.push_back(Ops[NF + I + 1]);
      Operands.push_back(Ops[2 * NF + 1]);
      Operands.push_back(Ops[2 * NF + 2]);
      Operands.push_back(Ops[NF]);
      Operands.push_back(Ops[2 * NF + 3]);
      Operands.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
      assert(Operands.size() == NF + 5);
      llvm::Function *F = CGM.getIntrinsic(ID, IntrinsicTypes);
      llvm::Value *LoadValue = Builder.CreateCall(F, Operands, "");
      clang::CharUnits Align =
          CGM.getNaturalPointeeTypeAlignment(E->getArg(0)->getType());
      llvm::Value *V;
      for (unsigned I = 0; I < NF; ++I) {
        V = Builder.CreateStore(Builder.CreateExtractValue(LoadValue, {I}),
                                Address(Ops[I], Align));
      }
      return V;
    }
            break;
case RISCVVector::BI__builtin_rvv_vlsseg8e8_v:
case RISCVVector::BI__builtin_rvv_vlsseg8e16_v:
case RISCVVector::BI__builtin_rvv_vlsseg8e32_v:
case RISCVVector::BI__builtin_rvv_vlsseg8e64_v:
  ID = Intrinsic::riscv_vlsseg8;
  NF = 8;

    {
      // builtin: (val0 address, val1 address, ..., ptr, stride, vl)
      IntrinsicTypes = {ConvertType(E->getArg(0)->getType()->getPointeeType()),
                        Ops[NF + 2]->getType()};
      // intrinsic: (ptr, stride, vl)
      llvm::Value *Operands[] = {Ops[NF], Ops[NF + 1], Ops[NF + 2]};
      llvm::Function *F = CGM.getIntrinsic(ID, IntrinsicTypes);
      llvm::Value *LoadValue = Builder.CreateCall(F, Operands, "");
      clang::CharUnits Align =
          CGM.getNaturalPointeeTypeAlignment(E->getArg(0)->getType());
      llvm::Value *V;
      for (unsigned I = 0; I < NF; ++I) {
        V = Builder.CreateStore(Builder.CreateExtractValue(LoadValue, {I}),
                                Address(Ops[I], Align));
      }
      return V;
    }
            break;
case RISCVVector::BI__builtin_rvv_vlsseg8e8_v_m:
case RISCVVector::BI__builtin_rvv_vlsseg8e16_v_m:
case RISCVVector::BI__builtin_rvv_vlsseg8e32_v_m:
case RISCVVector::BI__builtin_rvv_vlsseg8e64_v_m:
  ID = Intrinsic::riscv_vlsseg8_mask;
  NF = 8;

    {
      // builtin: (val0 address, ..., mask, maskedoff0, ..., ptr, stride, vl)
      // intrinsic: (maskedoff0, ..., ptr, stride, mask, vl)
      IntrinsicTypes = {ConvertType(E->getArg(0)->getType()->getPointeeType()),
                        Ops[2 * NF + 3]->getType()};
      SmallVector<llvm::Value*, 12> Operands;
      for (unsigned I = 0; I < NF; ++I)
        Operands.push_back(Ops[NF + I + 1]);
      Operands.push_back(Ops[2 * NF + 1]);
      Operands.push_back(Ops[2 * NF + 2]);
      Operands.push_back(Ops[NF]);
      Operands.push_back(Ops[2 * NF + 3]);
      Operands.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
      assert(Operands.size() == NF + 5);
      llvm::Function *F = CGM.getIntrinsic(ID, IntrinsicTypes);
      llvm::Value *LoadValue = Builder.CreateCall(F, Operands, "");
      clang::CharUnits Align =
          CGM.getNaturalPointeeTypeAlignment(E->getArg(0)->getType());
      llvm::Value *V;
      for (unsigned I = 0; I < NF; ++I) {
        V = Builder.CreateStore(Builder.CreateExtractValue(LoadValue, {I}),
                                Address(Ops[I], Align));
      }
      return V;
    }
            break;
case RISCVVector::BI__builtin_rvv_vluxei8_v:
case RISCVVector::BI__builtin_rvv_vluxei16_v:
case RISCVVector::BI__builtin_rvv_vluxei32_v:
case RISCVVector::BI__builtin_rvv_vluxei64_v:
  ID = Intrinsic::riscv_vluxei;

        IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops[2]->getType()};
        Ops[0] = Builder.CreateBitCast(Ops[0], ResultType->getPointerTo());
      break;
case RISCVVector::BI__builtin_rvv_vluxei8_v_m:
case RISCVVector::BI__builtin_rvv_vluxei16_v_m:
case RISCVVector::BI__builtin_rvv_vluxei32_v_m:
case RISCVVector::BI__builtin_rvv_vluxei64_v_m:
  ID = Intrinsic::riscv_vluxei_mask;

        // Move mask to right before vl.
        std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
        Ops.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
        IntrinsicTypes = {ResultType, Ops[2]->getType(), Ops[4]->getType()};
        Ops[1] = Builder.CreateBitCast(Ops[1], ResultType->getPointerTo());
      break;
case RISCVVector::BI__builtin_rvv_vluxseg2ei8_v:
case RISCVVector::BI__builtin_rvv_vluxseg2ei16_v:
case RISCVVector::BI__builtin_rvv_vluxseg2ei32_v:
case RISCVVector::BI__builtin_rvv_vluxseg2ei64_v:
  ID = Intrinsic::riscv_vluxseg2;
  NF = 2;

    {
      // builtin: (val0 address, val1 address, ..., ptr, index, vl)
      IntrinsicTypes = {ConvertType(E->getArg(0)->getType()->getPointeeType()),
                        Ops[NF + 1]->getType(), Ops[NF + 2]->getType()};
      // intrinsic: (ptr, index, vl)
      llvm::Value *Operands[] = {Ops[NF], Ops[NF + 1], Ops[NF + 2]};
      llvm::Function *F = CGM.getIntrinsic(ID, IntrinsicTypes);
      llvm::Value *LoadValue = Builder.CreateCall(F, Operands, "");
      clang::CharUnits Align =
          CGM.getNaturalPointeeTypeAlignment(E->getArg(0)->getType());
      llvm::Value *V;
      for (unsigned I = 0; I < NF; ++I) {
        V = Builder.CreateStore(Builder.CreateExtractValue(LoadValue, {I}),
                                Address(Ops[I], Align));
      }
      return V;
    }
            break;
case RISCVVector::BI__builtin_rvv_vluxseg2ei8_v_m:
case RISCVVector::BI__builtin_rvv_vluxseg2ei16_v_m:
case RISCVVector::BI__builtin_rvv_vluxseg2ei32_v_m:
case RISCVVector::BI__builtin_rvv_vluxseg2ei64_v_m:
  ID = Intrinsic::riscv_vluxseg2_mask;
  NF = 2;

    {
      // builtin: (val0 address, ..., mask, maskedoff0, ..., ptr, index, vl)
      IntrinsicTypes = {ConvertType(E->getArg(0)->getType()->getPointeeType()),
                        Ops[2 * NF + 2]->getType(), Ops[2 * NF + 3]->getType()};
      // intrinsic: (maskedoff0, ..., ptr, index, mask, vl)
      SmallVector<llvm::Value*, 12> Operands;
      for (unsigned I = 0; I < NF; ++I)
        Operands.push_back(Ops[NF + I + 1]);
      Operands.push_back(Ops[2 * NF + 1]);
      Operands.push_back(Ops[2 * NF + 2]);
      Operands.push_back(Ops[NF]);
      Operands.push_back(Ops[2 * NF + 3]);
      Operands.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
      assert(Operands.size() == NF + 5);
      llvm::Function *F = CGM.getIntrinsic(ID, IntrinsicTypes);
      llvm::Value *LoadValue = Builder.CreateCall(F, Operands, "");
      clang::CharUnits Align =
          CGM.getNaturalPointeeTypeAlignment(E->getArg(0)->getType());
      llvm::Value *V;
      for (unsigned I = 0; I < NF; ++I) {
        V = Builder.CreateStore(Builder.CreateExtractValue(LoadValue, {I}),
                                Address(Ops[I], Align));
      }
      return V;
    }
            break;
case RISCVVector::BI__builtin_rvv_vluxseg3ei8_v:
case RISCVVector::BI__builtin_rvv_vluxseg3ei16_v:
case RISCVVector::BI__builtin_rvv_vluxseg3ei32_v:
case RISCVVector::BI__builtin_rvv_vluxseg3ei64_v:
  ID = Intrinsic::riscv_vluxseg3;
  NF = 3;

    {
      // builtin: (val0 address, val1 address, ..., ptr, index, vl)
      IntrinsicTypes = {ConvertType(E->getArg(0)->getType()->getPointeeType()),
                        Ops[NF + 1]->getType(), Ops[NF + 2]->getType()};
      // intrinsic: (ptr, index, vl)
      llvm::Value *Operands[] = {Ops[NF], Ops[NF + 1], Ops[NF + 2]};
      llvm::Function *F = CGM.getIntrinsic(ID, IntrinsicTypes);
      llvm::Value *LoadValue = Builder.CreateCall(F, Operands, "");
      clang::CharUnits Align =
          CGM.getNaturalPointeeTypeAlignment(E->getArg(0)->getType());
      llvm::Value *V;
      for (unsigned I = 0; I < NF; ++I) {
        V = Builder.CreateStore(Builder.CreateExtractValue(LoadValue, {I}),
                                Address(Ops[I], Align));
      }
      return V;
    }
            break;
case RISCVVector::BI__builtin_rvv_vluxseg3ei8_v_m:
case RISCVVector::BI__builtin_rvv_vluxseg3ei16_v_m:
case RISCVVector::BI__builtin_rvv_vluxseg3ei32_v_m:
case RISCVVector::BI__builtin_rvv_vluxseg3ei64_v_m:
  ID = Intrinsic::riscv_vluxseg3_mask;
  NF = 3;

    {
      // builtin: (val0 address, ..., mask, maskedoff0, ..., ptr, index, vl)
      IntrinsicTypes = {ConvertType(E->getArg(0)->getType()->getPointeeType()),
                        Ops[2 * NF + 2]->getType(), Ops[2 * NF + 3]->getType()};
      // intrinsic: (maskedoff0, ..., ptr, index, mask, vl)
      SmallVector<llvm::Value*, 12> Operands;
      for (unsigned I = 0; I < NF; ++I)
        Operands.push_back(Ops[NF + I + 1]);
      Operands.push_back(Ops[2 * NF + 1]);
      Operands.push_back(Ops[2 * NF + 2]);
      Operands.push_back(Ops[NF]);
      Operands.push_back(Ops[2 * NF + 3]);
      Operands.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
      assert(Operands.size() == NF + 5);
      llvm::Function *F = CGM.getIntrinsic(ID, IntrinsicTypes);
      llvm::Value *LoadValue = Builder.CreateCall(F, Operands, "");
      clang::CharUnits Align =
          CGM.getNaturalPointeeTypeAlignment(E->getArg(0)->getType());
      llvm::Value *V;
      for (unsigned I = 0; I < NF; ++I) {
        V = Builder.CreateStore(Builder.CreateExtractValue(LoadValue, {I}),
                                Address(Ops[I], Align));
      }
      return V;
    }
            break;
case RISCVVector::BI__builtin_rvv_vluxseg4ei8_v:
case RISCVVector::BI__builtin_rvv_vluxseg4ei16_v:
case RISCVVector::BI__builtin_rvv_vluxseg4ei32_v:
case RISCVVector::BI__builtin_rvv_vluxseg4ei64_v:
  ID = Intrinsic::riscv_vluxseg4;
  NF = 4;

    {
      // builtin: (val0 address, val1 address, ..., ptr, index, vl)
      IntrinsicTypes = {ConvertType(E->getArg(0)->getType()->getPointeeType()),
                        Ops[NF + 1]->getType(), Ops[NF + 2]->getType()};
      // intrinsic: (ptr, index, vl)
      llvm::Value *Operands[] = {Ops[NF], Ops[NF + 1], Ops[NF + 2]};
      llvm::Function *F = CGM.getIntrinsic(ID, IntrinsicTypes);
      llvm::Value *LoadValue = Builder.CreateCall(F, Operands, "");
      clang::CharUnits Align =
          CGM.getNaturalPointeeTypeAlignment(E->getArg(0)->getType());
      llvm::Value *V;
      for (unsigned I = 0; I < NF; ++I) {
        V = Builder.CreateStore(Builder.CreateExtractValue(LoadValue, {I}),
                                Address(Ops[I], Align));
      }
      return V;
    }
            break;
case RISCVVector::BI__builtin_rvv_vluxseg4ei8_v_m:
case RISCVVector::BI__builtin_rvv_vluxseg4ei16_v_m:
case RISCVVector::BI__builtin_rvv_vluxseg4ei32_v_m:
case RISCVVector::BI__builtin_rvv_vluxseg4ei64_v_m:
  ID = Intrinsic::riscv_vluxseg4_mask;
  NF = 4;

    {
      // builtin: (val0 address, ..., mask, maskedoff0, ..., ptr, index, vl)
      IntrinsicTypes = {ConvertType(E->getArg(0)->getType()->getPointeeType()),
                        Ops[2 * NF + 2]->getType(), Ops[2 * NF + 3]->getType()};
      // intrinsic: (maskedoff0, ..., ptr, index, mask, vl)
      SmallVector<llvm::Value*, 12> Operands;
      for (unsigned I = 0; I < NF; ++I)
        Operands.push_back(Ops[NF + I + 1]);
      Operands.push_back(Ops[2 * NF + 1]);
      Operands.push_back(Ops[2 * NF + 2]);
      Operands.push_back(Ops[NF]);
      Operands.push_back(Ops[2 * NF + 3]);
      Operands.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
      assert(Operands.size() == NF + 5);
      llvm::Function *F = CGM.getIntrinsic(ID, IntrinsicTypes);
      llvm::Value *LoadValue = Builder.CreateCall(F, Operands, "");
      clang::CharUnits Align =
          CGM.getNaturalPointeeTypeAlignment(E->getArg(0)->getType());
      llvm::Value *V;
      for (unsigned I = 0; I < NF; ++I) {
        V = Builder.CreateStore(Builder.CreateExtractValue(LoadValue, {I}),
                                Address(Ops[I], Align));
      }
      return V;
    }
            break;
case RISCVVector::BI__builtin_rvv_vluxseg5ei8_v:
case RISCVVector::BI__builtin_rvv_vluxseg5ei16_v:
case RISCVVector::BI__builtin_rvv_vluxseg5ei32_v:
case RISCVVector::BI__builtin_rvv_vluxseg5ei64_v:
  ID = Intrinsic::riscv_vluxseg5;
  NF = 5;

    {
      // builtin: (val0 address, val1 address, ..., ptr, index, vl)
      IntrinsicTypes = {ConvertType(E->getArg(0)->getType()->getPointeeType()),
                        Ops[NF + 1]->getType(), Ops[NF + 2]->getType()};
      // intrinsic: (ptr, index, vl)
      llvm::Value *Operands[] = {Ops[NF], Ops[NF + 1], Ops[NF + 2]};
      llvm::Function *F = CGM.getIntrinsic(ID, IntrinsicTypes);
      llvm::Value *LoadValue = Builder.CreateCall(F, Operands, "");
      clang::CharUnits Align =
          CGM.getNaturalPointeeTypeAlignment(E->getArg(0)->getType());
      llvm::Value *V;
      for (unsigned I = 0; I < NF; ++I) {
        V = Builder.CreateStore(Builder.CreateExtractValue(LoadValue, {I}),
                                Address(Ops[I], Align));
      }
      return V;
    }
            break;
case RISCVVector::BI__builtin_rvv_vluxseg5ei8_v_m:
case RISCVVector::BI__builtin_rvv_vluxseg5ei16_v_m:
case RISCVVector::BI__builtin_rvv_vluxseg5ei32_v_m:
case RISCVVector::BI__builtin_rvv_vluxseg5ei64_v_m:
  ID = Intrinsic::riscv_vluxseg5_mask;
  NF = 5;

    {
      // builtin: (val0 address, ..., mask, maskedoff0, ..., ptr, index, vl)
      IntrinsicTypes = {ConvertType(E->getArg(0)->getType()->getPointeeType()),
                        Ops[2 * NF + 2]->getType(), Ops[2 * NF + 3]->getType()};
      // intrinsic: (maskedoff0, ..., ptr, index, mask, vl)
      SmallVector<llvm::Value*, 12> Operands;
      for (unsigned I = 0; I < NF; ++I)
        Operands.push_back(Ops[NF + I + 1]);
      Operands.push_back(Ops[2 * NF + 1]);
      Operands.push_back(Ops[2 * NF + 2]);
      Operands.push_back(Ops[NF]);
      Operands.push_back(Ops[2 * NF + 3]);
      Operands.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
      assert(Operands.size() == NF + 5);
      llvm::Function *F = CGM.getIntrinsic(ID, IntrinsicTypes);
      llvm::Value *LoadValue = Builder.CreateCall(F, Operands, "");
      clang::CharUnits Align =
          CGM.getNaturalPointeeTypeAlignment(E->getArg(0)->getType());
      llvm::Value *V;
      for (unsigned I = 0; I < NF; ++I) {
        V = Builder.CreateStore(Builder.CreateExtractValue(LoadValue, {I}),
                                Address(Ops[I], Align));
      }
      return V;
    }
            break;
case RISCVVector::BI__builtin_rvv_vluxseg6ei8_v:
case RISCVVector::BI__builtin_rvv_vluxseg6ei16_v:
case RISCVVector::BI__builtin_rvv_vluxseg6ei32_v:
case RISCVVector::BI__builtin_rvv_vluxseg6ei64_v:
  ID = Intrinsic::riscv_vluxseg6;
  NF = 6;

    {
      // builtin: (val0 address, val1 address, ..., ptr, index, vl)
      IntrinsicTypes = {ConvertType(E->getArg(0)->getType()->getPointeeType()),
                        Ops[NF + 1]->getType(), Ops[NF + 2]->getType()};
      // intrinsic: (ptr, index, vl)
      llvm::Value *Operands[] = {Ops[NF], Ops[NF + 1], Ops[NF + 2]};
      llvm::Function *F = CGM.getIntrinsic(ID, IntrinsicTypes);
      llvm::Value *LoadValue = Builder.CreateCall(F, Operands, "");
      clang::CharUnits Align =
          CGM.getNaturalPointeeTypeAlignment(E->getArg(0)->getType());
      llvm::Value *V;
      for (unsigned I = 0; I < NF; ++I) {
        V = Builder.CreateStore(Builder.CreateExtractValue(LoadValue, {I}),
                                Address(Ops[I], Align));
      }
      return V;
    }
            break;
case RISCVVector::BI__builtin_rvv_vluxseg6ei8_v_m:
case RISCVVector::BI__builtin_rvv_vluxseg6ei16_v_m:
case RISCVVector::BI__builtin_rvv_vluxseg6ei32_v_m:
case RISCVVector::BI__builtin_rvv_vluxseg6ei64_v_m:
  ID = Intrinsic::riscv_vluxseg6_mask;
  NF = 6;

    {
      // builtin: (val0 address, ..., mask, maskedoff0, ..., ptr, index, vl)
      IntrinsicTypes = {ConvertType(E->getArg(0)->getType()->getPointeeType()),
                        Ops[2 * NF + 2]->getType(), Ops[2 * NF + 3]->getType()};
      // intrinsic: (maskedoff0, ..., ptr, index, mask, vl)
      SmallVector<llvm::Value*, 12> Operands;
      for (unsigned I = 0; I < NF; ++I)
        Operands.push_back(Ops[NF + I + 1]);
      Operands.push_back(Ops[2 * NF + 1]);
      Operands.push_back(Ops[2 * NF + 2]);
      Operands.push_back(Ops[NF]);
      Operands.push_back(Ops[2 * NF + 3]);
      Operands.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
      assert(Operands.size() == NF + 5);
      llvm::Function *F = CGM.getIntrinsic(ID, IntrinsicTypes);
      llvm::Value *LoadValue = Builder.CreateCall(F, Operands, "");
      clang::CharUnits Align =
          CGM.getNaturalPointeeTypeAlignment(E->getArg(0)->getType());
      llvm::Value *V;
      for (unsigned I = 0; I < NF; ++I) {
        V = Builder.CreateStore(Builder.CreateExtractValue(LoadValue, {I}),
                                Address(Ops[I], Align));
      }
      return V;
    }
            break;
case RISCVVector::BI__builtin_rvv_vluxseg7ei8_v:
case RISCVVector::BI__builtin_rvv_vluxseg7ei16_v:
case RISCVVector::BI__builtin_rvv_vluxseg7ei32_v:
case RISCVVector::BI__builtin_rvv_vluxseg7ei64_v:
  ID = Intrinsic::riscv_vluxseg7;
  NF = 7;

    {
      // builtin: (val0 address, val1 address, ..., ptr, index, vl)
      IntrinsicTypes = {ConvertType(E->getArg(0)->getType()->getPointeeType()),
                        Ops[NF + 1]->getType(), Ops[NF + 2]->getType()};
      // intrinsic: (ptr, index, vl)
      llvm::Value *Operands[] = {Ops[NF], Ops[NF + 1], Ops[NF + 2]};
      llvm::Function *F = CGM.getIntrinsic(ID, IntrinsicTypes);
      llvm::Value *LoadValue = Builder.CreateCall(F, Operands, "");
      clang::CharUnits Align =
          CGM.getNaturalPointeeTypeAlignment(E->getArg(0)->getType());
      llvm::Value *V;
      for (unsigned I = 0; I < NF; ++I) {
        V = Builder.CreateStore(Builder.CreateExtractValue(LoadValue, {I}),
                                Address(Ops[I], Align));
      }
      return V;
    }
            break;
case RISCVVector::BI__builtin_rvv_vluxseg7ei8_v_m:
case RISCVVector::BI__builtin_rvv_vluxseg7ei16_v_m:
case RISCVVector::BI__builtin_rvv_vluxseg7ei32_v_m:
case RISCVVector::BI__builtin_rvv_vluxseg7ei64_v_m:
  ID = Intrinsic::riscv_vluxseg7_mask;
  NF = 7;

    {
      // builtin: (val0 address, ..., mask, maskedoff0, ..., ptr, index, vl)
      IntrinsicTypes = {ConvertType(E->getArg(0)->getType()->getPointeeType()),
                        Ops[2 * NF + 2]->getType(), Ops[2 * NF + 3]->getType()};
      // intrinsic: (maskedoff0, ..., ptr, index, mask, vl)
      SmallVector<llvm::Value*, 12> Operands;
      for (unsigned I = 0; I < NF; ++I)
        Operands.push_back(Ops[NF + I + 1]);
      Operands.push_back(Ops[2 * NF + 1]);
      Operands.push_back(Ops[2 * NF + 2]);
      Operands.push_back(Ops[NF]);
      Operands.push_back(Ops[2 * NF + 3]);
      Operands.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
      assert(Operands.size() == NF + 5);
      llvm::Function *F = CGM.getIntrinsic(ID, IntrinsicTypes);
      llvm::Value *LoadValue = Builder.CreateCall(F, Operands, "");
      clang::CharUnits Align =
          CGM.getNaturalPointeeTypeAlignment(E->getArg(0)->getType());
      llvm::Value *V;
      for (unsigned I = 0; I < NF; ++I) {
        V = Builder.CreateStore(Builder.CreateExtractValue(LoadValue, {I}),
                                Address(Ops[I], Align));
      }
      return V;
    }
            break;
case RISCVVector::BI__builtin_rvv_vluxseg8ei8_v:
case RISCVVector::BI__builtin_rvv_vluxseg8ei16_v:
case RISCVVector::BI__builtin_rvv_vluxseg8ei32_v:
case RISCVVector::BI__builtin_rvv_vluxseg8ei64_v:
  ID = Intrinsic::riscv_vluxseg8;
  NF = 8;

    {
      // builtin: (val0 address, val1 address, ..., ptr, index, vl)
      IntrinsicTypes = {ConvertType(E->getArg(0)->getType()->getPointeeType()),
                        Ops[NF + 1]->getType(), Ops[NF + 2]->getType()};
      // intrinsic: (ptr, index, vl)
      llvm::Value *Operands[] = {Ops[NF], Ops[NF + 1], Ops[NF + 2]};
      llvm::Function *F = CGM.getIntrinsic(ID, IntrinsicTypes);
      llvm::Value *LoadValue = Builder.CreateCall(F, Operands, "");
      clang::CharUnits Align =
          CGM.getNaturalPointeeTypeAlignment(E->getArg(0)->getType());
      llvm::Value *V;
      for (unsigned I = 0; I < NF; ++I) {
        V = Builder.CreateStore(Builder.CreateExtractValue(LoadValue, {I}),
                                Address(Ops[I], Align));
      }
      return V;
    }
            break;
case RISCVVector::BI__builtin_rvv_vluxseg8ei8_v_m:
case RISCVVector::BI__builtin_rvv_vluxseg8ei16_v_m:
case RISCVVector::BI__builtin_rvv_vluxseg8ei32_v_m:
case RISCVVector::BI__builtin_rvv_vluxseg8ei64_v_m:
  ID = Intrinsic::riscv_vluxseg8_mask;
  NF = 8;

    {
      // builtin: (val0 address, ..., mask, maskedoff0, ..., ptr, index, vl)
      IntrinsicTypes = {ConvertType(E->getArg(0)->getType()->getPointeeType()),
                        Ops[2 * NF + 2]->getType(), Ops[2 * NF + 3]->getType()};
      // intrinsic: (maskedoff0, ..., ptr, index, mask, vl)
      SmallVector<llvm::Value*, 12> Operands;
      for (unsigned I = 0; I < NF; ++I)
        Operands.push_back(Ops[NF + I + 1]);
      Operands.push_back(Ops[2 * NF + 1]);
      Operands.push_back(Ops[2 * NF + 2]);
      Operands.push_back(Ops[NF]);
      Operands.push_back(Ops[2 * NF + 3]);
      Operands.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
      assert(Operands.size() == NF + 5);
      llvm::Function *F = CGM.getIntrinsic(ID, IntrinsicTypes);
      llvm::Value *LoadValue = Builder.CreateCall(F, Operands, "");
      clang::CharUnits Align =
          CGM.getNaturalPointeeTypeAlignment(E->getArg(0)->getType());
      llvm::Value *V;
      for (unsigned I = 0; I < NF; ++I) {
        V = Builder.CreateStore(Builder.CreateExtractValue(LoadValue, {I}),
                                Address(Ops[I], Align));
      }
      return V;
    }
            break;
case RISCVVector::BI__builtin_rvv_vmacc_vv:
case RISCVVector::BI__builtin_rvv_vmacc_vx:
  ID = Intrinsic::riscv_vmacc;
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vmacc_vv_m:
case RISCVVector::BI__builtin_rvv_vmacc_vx_m:
  ID = Intrinsic::riscv_vmacc_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vmadc_vv:
case RISCVVector::BI__builtin_rvv_vmadc_vx:
  ID = Intrinsic::riscv_vmadc;
  IntrinsicTypes = {Ops[0]->getType(), Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vmadc_vvm:
case RISCVVector::BI__builtin_rvv_vmadc_vxm:
  ID = Intrinsic::riscv_vmadc_carry_in;
  IntrinsicTypes = {Ops[0]->getType(), Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vmadd_vv:
case RISCVVector::BI__builtin_rvv_vmadd_vx:
  ID = Intrinsic::riscv_vmadd;
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vmadd_vv_m:
case RISCVVector::BI__builtin_rvv_vmadd_vx_m:
  ID = Intrinsic::riscv_vmadd_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vmmv_m:
  ID = Intrinsic::riscv_vmand;

      {
        // op1, vl
        IntrinsicTypes = {ResultType,
                          Ops[1]->getType()};
        Ops.insert(Ops.begin() + 1, Ops[0]);
        break;
      }
      break;
case RISCVVector::BI__builtin_rvv_vmand_mm:
  ID = Intrinsic::riscv_vmand;
  IntrinsicTypes = {ResultType, Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vmandn_mm:
  ID = Intrinsic::riscv_vmandn;
  IntrinsicTypes = {ResultType, Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vmax_vv:
case RISCVVector::BI__builtin_rvv_vmax_vx:
  ID = Intrinsic::riscv_vmax;
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vmax_vv_m:
case RISCVVector::BI__builtin_rvv_vmax_vx_m:
  ID = Intrinsic::riscv_vmax_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  Ops.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
  IntrinsicTypes = {ResultType, Ops[2]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vmaxu_vv:
case RISCVVector::BI__builtin_rvv_vmaxu_vx:
  ID = Intrinsic::riscv_vmaxu;
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vmaxu_vv_m:
case RISCVVector::BI__builtin_rvv_vmaxu_vx_m:
  ID = Intrinsic::riscv_vmaxu_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  Ops.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
  IntrinsicTypes = {ResultType, Ops[2]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vmclr_m:
  ID = Intrinsic::riscv_vmclr;
  IntrinsicTypes = {ResultType, Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vmerge_vvm:
case RISCVVector::BI__builtin_rvv_vmerge_vxm:
  ID = Intrinsic::riscv_vmerge;

      std::rotate(Ops.begin(), Ops.begin() + 1, Ops.begin() + 3);
      IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops[3]->getType()};
    break;
case RISCVVector::BI__builtin_rvv_vmfeq_vv:
case RISCVVector::BI__builtin_rvv_vmfeq_vf:
  ID = Intrinsic::riscv_vmfeq;
  IntrinsicTypes = {Ops[0]->getType(), Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vmfeq_vv_m:
case RISCVVector::BI__builtin_rvv_vmfeq_vf_m:
  ID = Intrinsic::riscv_vmfeq_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  IntrinsicTypes = {Ops[1]->getType(), Ops[2]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vmfge_vv:
case RISCVVector::BI__builtin_rvv_vmfge_vf:
  ID = Intrinsic::riscv_vmfge;
  IntrinsicTypes = {Ops[0]->getType(), Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vmfge_vv_m:
case RISCVVector::BI__builtin_rvv_vmfge_vf_m:
  ID = Intrinsic::riscv_vmfge_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  IntrinsicTypes = {Ops[1]->getType(), Ops[2]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vmfgt_vv:
case RISCVVector::BI__builtin_rvv_vmfgt_vf:
  ID = Intrinsic::riscv_vmfgt;
  IntrinsicTypes = {Ops[0]->getType(), Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vmfgt_vv_m:
case RISCVVector::BI__builtin_rvv_vmfgt_vf_m:
  ID = Intrinsic::riscv_vmfgt_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  IntrinsicTypes = {Ops[1]->getType(), Ops[2]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vmfle_vv:
case RISCVVector::BI__builtin_rvv_vmfle_vf:
  ID = Intrinsic::riscv_vmfle;
  IntrinsicTypes = {Ops[0]->getType(), Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vmfle_vv_m:
case RISCVVector::BI__builtin_rvv_vmfle_vf_m:
  ID = Intrinsic::riscv_vmfle_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  IntrinsicTypes = {Ops[1]->getType(), Ops[2]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vmflt_vv:
case RISCVVector::BI__builtin_rvv_vmflt_vf:
  ID = Intrinsic::riscv_vmflt;
  IntrinsicTypes = {Ops[0]->getType(), Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vmflt_vv_m:
case RISCVVector::BI__builtin_rvv_vmflt_vf_m:
  ID = Intrinsic::riscv_vmflt_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  IntrinsicTypes = {Ops[1]->getType(), Ops[2]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vmfne_vv:
case RISCVVector::BI__builtin_rvv_vmfne_vf:
  ID = Intrinsic::riscv_vmfne;
  IntrinsicTypes = {Ops[0]->getType(), Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vmfne_vv_m:
case RISCVVector::BI__builtin_rvv_vmfne_vf_m:
  ID = Intrinsic::riscv_vmfne_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  IntrinsicTypes = {Ops[1]->getType(), Ops[2]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vmin_vv:
case RISCVVector::BI__builtin_rvv_vmin_vx:
  ID = Intrinsic::riscv_vmin;
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vmin_vv_m:
case RISCVVector::BI__builtin_rvv_vmin_vx_m:
  ID = Intrinsic::riscv_vmin_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  Ops.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
  IntrinsicTypes = {ResultType, Ops[2]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vminu_vv:
case RISCVVector::BI__builtin_rvv_vminu_vx:
  ID = Intrinsic::riscv_vminu;
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vminu_vv_m:
case RISCVVector::BI__builtin_rvv_vminu_vx_m:
  ID = Intrinsic::riscv_vminu_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  Ops.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
  IntrinsicTypes = {ResultType, Ops[2]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vmnot_m:
  ID = Intrinsic::riscv_vmnand;

      {
        // op1, vl
        IntrinsicTypes = {ResultType,
                          Ops[1]->getType()};
        Ops.insert(Ops.begin() + 1, Ops[0]);
        break;
      }
      break;
case RISCVVector::BI__builtin_rvv_vmnand_mm:
  ID = Intrinsic::riscv_vmnand;
  IntrinsicTypes = {ResultType, Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vmnor_mm:
  ID = Intrinsic::riscv_vmnor;
  IntrinsicTypes = {ResultType, Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vmor_mm:
  ID = Intrinsic::riscv_vmor;
  IntrinsicTypes = {ResultType, Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vmorn_mm:
  ID = Intrinsic::riscv_vmorn;
  IntrinsicTypes = {ResultType, Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vmsbc_vv:
case RISCVVector::BI__builtin_rvv_vmsbc_vx:
  ID = Intrinsic::riscv_vmsbc;
  IntrinsicTypes = {Ops[0]->getType(), Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vmsbc_vvm:
case RISCVVector::BI__builtin_rvv_vmsbc_vxm:
  ID = Intrinsic::riscv_vmsbc_borrow_in;
  IntrinsicTypes = {Ops[0]->getType(), Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vmsbf_m:
  ID = Intrinsic::riscv_vmsbf;
  IntrinsicTypes = {ResultType, Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vmsbf_m_m:
  ID = Intrinsic::riscv_vmsbf_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  IntrinsicTypes = {ResultType, Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vmseq_vv:
case RISCVVector::BI__builtin_rvv_vmseq_vx:
  ID = Intrinsic::riscv_vmseq;
  IntrinsicTypes = {Ops[0]->getType(), Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vmseq_vv_m:
case RISCVVector::BI__builtin_rvv_vmseq_vx_m:
  ID = Intrinsic::riscv_vmseq_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  IntrinsicTypes = {Ops[1]->getType(), Ops[2]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vmset_m:
  ID = Intrinsic::riscv_vmset;
  IntrinsicTypes = {ResultType, Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vmsge_vv:
case RISCVVector::BI__builtin_rvv_vmsge_vx:
  ID = Intrinsic::riscv_vmsge;
  IntrinsicTypes = {Ops[0]->getType(), Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vmsge_vv_m:
case RISCVVector::BI__builtin_rvv_vmsge_vx_m:
  ID = Intrinsic::riscv_vmsge_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  IntrinsicTypes = {Ops[1]->getType(), Ops[2]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vmsgeu_vv:
case RISCVVector::BI__builtin_rvv_vmsgeu_vx:
  ID = Intrinsic::riscv_vmsgeu;
  IntrinsicTypes = {Ops[0]->getType(), Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vmsgeu_vv_m:
case RISCVVector::BI__builtin_rvv_vmsgeu_vx_m:
  ID = Intrinsic::riscv_vmsgeu_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  IntrinsicTypes = {Ops[1]->getType(), Ops[2]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vmsgt_vv:
case RISCVVector::BI__builtin_rvv_vmsgt_vx:
  ID = Intrinsic::riscv_vmsgt;
  IntrinsicTypes = {Ops[0]->getType(), Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vmsgt_vv_m:
case RISCVVector::BI__builtin_rvv_vmsgt_vx_m:
  ID = Intrinsic::riscv_vmsgt_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  IntrinsicTypes = {Ops[1]->getType(), Ops[2]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vmsgtu_vv:
case RISCVVector::BI__builtin_rvv_vmsgtu_vx:
  ID = Intrinsic::riscv_vmsgtu;
  IntrinsicTypes = {Ops[0]->getType(), Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vmsgtu_vv_m:
case RISCVVector::BI__builtin_rvv_vmsgtu_vx_m:
  ID = Intrinsic::riscv_vmsgtu_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  IntrinsicTypes = {Ops[1]->getType(), Ops[2]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vmsif_m:
  ID = Intrinsic::riscv_vmsif;
  IntrinsicTypes = {ResultType, Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vmsif_m_m:
  ID = Intrinsic::riscv_vmsif_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  IntrinsicTypes = {ResultType, Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vmsle_vv:
case RISCVVector::BI__builtin_rvv_vmsle_vx:
  ID = Intrinsic::riscv_vmsle;
  IntrinsicTypes = {Ops[0]->getType(), Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vmsle_vv_m:
case RISCVVector::BI__builtin_rvv_vmsle_vx_m:
  ID = Intrinsic::riscv_vmsle_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  IntrinsicTypes = {Ops[1]->getType(), Ops[2]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vmsleu_vv:
case RISCVVector::BI__builtin_rvv_vmsleu_vx:
  ID = Intrinsic::riscv_vmsleu;
  IntrinsicTypes = {Ops[0]->getType(), Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vmsleu_vv_m:
case RISCVVector::BI__builtin_rvv_vmsleu_vx_m:
  ID = Intrinsic::riscv_vmsleu_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  IntrinsicTypes = {Ops[1]->getType(), Ops[2]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vmslt_vv:
case RISCVVector::BI__builtin_rvv_vmslt_vx:
  ID = Intrinsic::riscv_vmslt;
  IntrinsicTypes = {Ops[0]->getType(), Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vmslt_vv_m:
case RISCVVector::BI__builtin_rvv_vmslt_vx_m:
  ID = Intrinsic::riscv_vmslt_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  IntrinsicTypes = {Ops[1]->getType(), Ops[2]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vmsltu_vv:
case RISCVVector::BI__builtin_rvv_vmsltu_vx:
  ID = Intrinsic::riscv_vmsltu;
  IntrinsicTypes = {Ops[0]->getType(), Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vmsltu_vv_m:
case RISCVVector::BI__builtin_rvv_vmsltu_vx_m:
  ID = Intrinsic::riscv_vmsltu_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  IntrinsicTypes = {Ops[1]->getType(), Ops[2]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vmsne_vv:
case RISCVVector::BI__builtin_rvv_vmsne_vx:
  ID = Intrinsic::riscv_vmsne;
  IntrinsicTypes = {Ops[0]->getType(), Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vmsne_vv_m:
case RISCVVector::BI__builtin_rvv_vmsne_vx_m:
  ID = Intrinsic::riscv_vmsne_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  IntrinsicTypes = {Ops[1]->getType(), Ops[2]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vmsof_m:
  ID = Intrinsic::riscv_vmsof;
  IntrinsicTypes = {ResultType, Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vmsof_m_m:
  ID = Intrinsic::riscv_vmsof_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  IntrinsicTypes = {ResultType, Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vmul_vv:
case RISCVVector::BI__builtin_rvv_vmul_vx:
  ID = Intrinsic::riscv_vmul;
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vmul_vv_m:
case RISCVVector::BI__builtin_rvv_vmul_vx_m:
  ID = Intrinsic::riscv_vmul_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  Ops.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
  IntrinsicTypes = {ResultType, Ops[2]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vmulh_vv:
case RISCVVector::BI__builtin_rvv_vmulh_vx:
  ID = Intrinsic::riscv_vmulh;
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vmulh_vv_m:
case RISCVVector::BI__builtin_rvv_vmulh_vx_m:
  ID = Intrinsic::riscv_vmulh_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  Ops.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
  IntrinsicTypes = {ResultType, Ops[2]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vmulhsu_vv:
case RISCVVector::BI__builtin_rvv_vmulhsu_vx:
  ID = Intrinsic::riscv_vmulhsu;
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vmulhsu_vv_m:
case RISCVVector::BI__builtin_rvv_vmulhsu_vx_m:
  ID = Intrinsic::riscv_vmulhsu_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  Ops.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
  IntrinsicTypes = {ResultType, Ops[2]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vmulhu_vv:
case RISCVVector::BI__builtin_rvv_vmulhu_vx:
  ID = Intrinsic::riscv_vmulhu;
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vmulhu_vv_m:
case RISCVVector::BI__builtin_rvv_vmulhu_vx_m:
  ID = Intrinsic::riscv_vmulhu_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  Ops.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
  IntrinsicTypes = {ResultType, Ops[2]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vmv_s_x:
  ID = Intrinsic::riscv_vmv_s_x;
  IntrinsicTypes = {ResultType, Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vmv_v_v:
  ID = Intrinsic::riscv_vmv_v_v;
  IntrinsicTypes = {ResultType, Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vmv_v_x:
  ID = Intrinsic::riscv_vmv_v_x;
  IntrinsicTypes = {ResultType, Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vmv_x_s:
  ID = Intrinsic::riscv_vmv_x_s;
  IntrinsicTypes = {Ops[0]->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vmxnor_mm:
  ID = Intrinsic::riscv_vmxnor;
  IntrinsicTypes = {ResultType, Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vmxor_mm:
  ID = Intrinsic::riscv_vmxor;
  IntrinsicTypes = {ResultType, Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vnclip_wv:
case RISCVVector::BI__builtin_rvv_vnclip_wx:
  ID = Intrinsic::riscv_vnclip;
  IntrinsicTypes = {ResultType, Ops[0]->getType(), Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vnclip_wv_m:
case RISCVVector::BI__builtin_rvv_vnclip_wx_m:
  ID = Intrinsic::riscv_vnclip_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  Ops.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops[2]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vnclipu_wv:
case RISCVVector::BI__builtin_rvv_vnclipu_wx:
  ID = Intrinsic::riscv_vnclipu;
  IntrinsicTypes = {ResultType, Ops[0]->getType(), Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vnclipu_wv_m:
case RISCVVector::BI__builtin_rvv_vnclipu_wx_m:
  ID = Intrinsic::riscv_vnclipu_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  Ops.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops[2]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vnmsac_vv:
case RISCVVector::BI__builtin_rvv_vnmsac_vx:
  ID = Intrinsic::riscv_vnmsac;
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vnmsac_vv_m:
case RISCVVector::BI__builtin_rvv_vnmsac_vx_m:
  ID = Intrinsic::riscv_vnmsac_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vnmsub_vv:
case RISCVVector::BI__builtin_rvv_vnmsub_vx:
  ID = Intrinsic::riscv_vnmsub;
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vnmsub_vv_m:
case RISCVVector::BI__builtin_rvv_vnmsub_vx_m:
  ID = Intrinsic::riscv_vnmsub_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vnsra_wv:
case RISCVVector::BI__builtin_rvv_vnsra_wx:
  ID = Intrinsic::riscv_vnsra;
  IntrinsicTypes = {ResultType, Ops[0]->getType(), Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vnsra_wv_m:
case RISCVVector::BI__builtin_rvv_vnsra_wx_m:
  ID = Intrinsic::riscv_vnsra_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  Ops.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops[2]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vnsrl_wv:
case RISCVVector::BI__builtin_rvv_vnsrl_wx:
  ID = Intrinsic::riscv_vnsrl;
  IntrinsicTypes = {ResultType, Ops[0]->getType(), Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vncvt_x_x_w:
  ID = Intrinsic::riscv_vnsrl;

      {
        // op1, vl
        IntrinsicTypes = {ResultType,
                          Ops[0]->getType(),
                          Ops[1]->getType(),
                          Ops[1]->getType()};
        Ops.insert(Ops.begin() + 1, llvm::Constant::getNullValue(IntrinsicTypes[2]));
        break;
      }
      break;
case RISCVVector::BI__builtin_rvv_vnsrl_wv_m:
case RISCVVector::BI__builtin_rvv_vnsrl_wx_m:
  ID = Intrinsic::riscv_vnsrl_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  Ops.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops[2]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vncvt_x_x_w_m:
  ID = Intrinsic::riscv_vnsrl_mask;

      {
        std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
        Ops.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
        // maskedoff, op1, mask, vl
        IntrinsicTypes = {ResultType,
                          Ops[1]->getType(),
                          Ops[3]->getType(),
                          Ops[3]->getType()};
        Ops.insert(Ops.begin() + 2, llvm::Constant::getNullValue(IntrinsicTypes[2]));
        break;
      }
      break;
case RISCVVector::BI__builtin_rvv_vor_vv:
case RISCVVector::BI__builtin_rvv_vor_vx:
  ID = Intrinsic::riscv_vor;
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vor_vv_m:
case RISCVVector::BI__builtin_rvv_vor_vx_m:
  ID = Intrinsic::riscv_vor_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  Ops.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
  IntrinsicTypes = {ResultType, Ops[2]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vredand_vs:
  ID = Intrinsic::riscv_vredand;
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vredand_vs_m:
  ID = Intrinsic::riscv_vredand_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vredmax_vs:
  ID = Intrinsic::riscv_vredmax;
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vredmax_vs_m:
  ID = Intrinsic::riscv_vredmax_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vredmaxu_vs:
  ID = Intrinsic::riscv_vredmaxu;
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vredmaxu_vs_m:
  ID = Intrinsic::riscv_vredmaxu_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vredmin_vs:
  ID = Intrinsic::riscv_vredmin;
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vredmin_vs_m:
  ID = Intrinsic::riscv_vredmin_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vredminu_vs:
  ID = Intrinsic::riscv_vredminu;
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vredminu_vs_m:
  ID = Intrinsic::riscv_vredminu_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vredor_vs:
  ID = Intrinsic::riscv_vredor;
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vredor_vs_m:
  ID = Intrinsic::riscv_vredor_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vredsum_vs:
  ID = Intrinsic::riscv_vredsum;
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vredsum_vs_m:
  ID = Intrinsic::riscv_vredsum_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vredxor_vs:
  ID = Intrinsic::riscv_vredxor;
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vredxor_vs_m:
  ID = Intrinsic::riscv_vredxor_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vrem_vv:
case RISCVVector::BI__builtin_rvv_vrem_vx:
  ID = Intrinsic::riscv_vrem;
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vrem_vv_m:
case RISCVVector::BI__builtin_rvv_vrem_vx_m:
  ID = Intrinsic::riscv_vrem_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  Ops.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
  IntrinsicTypes = {ResultType, Ops[2]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vremu_vv:
case RISCVVector::BI__builtin_rvv_vremu_vx:
  ID = Intrinsic::riscv_vremu;
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vremu_vv_m:
case RISCVVector::BI__builtin_rvv_vremu_vx_m:
  ID = Intrinsic::riscv_vremu_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  Ops.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
  IntrinsicTypes = {ResultType, Ops[2]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vrgather_vv:
  ID = Intrinsic::riscv_vrgather_vv;
  IntrinsicTypes = {ResultType, Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vrgather_vv_m:
  ID = Intrinsic::riscv_vrgather_vv_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  Ops.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
  IntrinsicTypes = {ResultType, Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vrgather_vx:
  ID = Intrinsic::riscv_vrgather_vx;
  IntrinsicTypes = {ResultType, Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vrgather_vx_m:
  ID = Intrinsic::riscv_vrgather_vx_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  Ops.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
  IntrinsicTypes = {ResultType, Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vrgatherei16_vv:
  ID = Intrinsic::riscv_vrgatherei16_vv;
  IntrinsicTypes = {ResultType, Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vrgatherei16_vv_m:
  ID = Intrinsic::riscv_vrgatherei16_vv_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  Ops.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
  IntrinsicTypes = {ResultType, Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vrsub_vx:
  ID = Intrinsic::riscv_vrsub;
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vneg_v:
  ID = Intrinsic::riscv_vrsub;

      {
        // op1, vl
        IntrinsicTypes = {ResultType,
                          cast<llvm::VectorType>(ResultType)->getElementType(),
                          Ops[1]->getType()};
        Ops.insert(Ops.begin() + 1, llvm::Constant::getNullValue(IntrinsicTypes[1]));
        break;
      }
      break;
case RISCVVector::BI__builtin_rvv_vrsub_vx_m:
  ID = Intrinsic::riscv_vrsub_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  Ops.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
  IntrinsicTypes = {ResultType, Ops[2]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vneg_v_m:
  ID = Intrinsic::riscv_vrsub_mask;

      {
        std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
        Ops.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
        // maskedoff, op1, mask, vl
        IntrinsicTypes = {ResultType,
                          cast<llvm::VectorType>(ResultType)->getElementType(),
                          Ops[3]->getType()};
        Ops.insert(Ops.begin() + 2, llvm::Constant::getNullValue(IntrinsicTypes[1]));
        break;
      }
      break;
case RISCVVector::BI__builtin_rvv_vsadd_vv:
case RISCVVector::BI__builtin_rvv_vsadd_vx:
  ID = Intrinsic::riscv_vsadd;
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vsadd_vv_m:
case RISCVVector::BI__builtin_rvv_vsadd_vx_m:
  ID = Intrinsic::riscv_vsadd_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  Ops.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
  IntrinsicTypes = {ResultType, Ops[2]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vsaddu_vv:
case RISCVVector::BI__builtin_rvv_vsaddu_vx:
  ID = Intrinsic::riscv_vsaddu;
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vsaddu_vv_m:
case RISCVVector::BI__builtin_rvv_vsaddu_vx_m:
  ID = Intrinsic::riscv_vsaddu_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  Ops.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
  IntrinsicTypes = {ResultType, Ops[2]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vsbc_vvm:
case RISCVVector::BI__builtin_rvv_vsbc_vxm:
  ID = Intrinsic::riscv_vsbc;
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vse8_v:
case RISCVVector::BI__builtin_rvv_vse16_v:
case RISCVVector::BI__builtin_rvv_vse32_v:
case RISCVVector::BI__builtin_rvv_vse64_v:
  ID = Intrinsic::riscv_vse;

      // Builtin: (ptr, value, vl). Intrinsic: (value, ptr, vl)
      std::swap(Ops[0], Ops[1]);
      Ops[1] = Builder.CreateBitCast(Ops[1], Ops[0]->getType()->getPointerTo());
      IntrinsicTypes = {Ops[0]->getType(), Ops[2]->getType()};
    break;
case RISCVVector::BI__builtin_rvv_vse8_v_m:
case RISCVVector::BI__builtin_rvv_vse16_v_m:
case RISCVVector::BI__builtin_rvv_vse32_v_m:
case RISCVVector::BI__builtin_rvv_vse64_v_m:
  ID = Intrinsic::riscv_vse_mask;

      // Builtin: (mask, ptr, value, vl). Intrinsic: (value, ptr, mask, vl)
      std::swap(Ops[0], Ops[2]);
      Ops[1] = Builder.CreateBitCast(Ops[1], Ops[0]->getType()->getPointerTo());
      IntrinsicTypes = {Ops[0]->getType(), Ops[3]->getType()};
    break;
case RISCVVector::BI__builtin_rvv_vsetvli:
  ID = Intrinsic::riscv_vsetvli;
IntrinsicTypes = {ResultType};break;
case RISCVVector::BI__builtin_rvv_vsetvlimax:
  ID = Intrinsic::riscv_vsetvlimax;
IntrinsicTypes = {ResultType};break;
case RISCVVector::BI__builtin_rvv_vsext_vf2:
case RISCVVector::BI__builtin_rvv_vsext_vf4:
case RISCVVector::BI__builtin_rvv_vsext_vf8:
  ID = Intrinsic::riscv_vsext;
  IntrinsicTypes = {ResultType, Ops[0]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vsext_vf2_m:
case RISCVVector::BI__builtin_rvv_vsext_vf4_m:
case RISCVVector::BI__builtin_rvv_vsext_vf8_m:
  ID = Intrinsic::riscv_vsext_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  Ops.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vslide1down_vx:
  ID = Intrinsic::riscv_vslide1down;
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vslide1down_vx_m:
  ID = Intrinsic::riscv_vslide1down_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  Ops.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
  IntrinsicTypes = {ResultType, Ops[2]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vslide1up_vx:
  ID = Intrinsic::riscv_vslide1up;
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vslide1up_vx_m:
  ID = Intrinsic::riscv_vslide1up_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  Ops.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
  IntrinsicTypes = {ResultType, Ops[2]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vslidedown_vx:
  ID = Intrinsic::riscv_vslidedown;
  IntrinsicTypes = {ResultType, Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vslidedown_vx_m:
  ID = Intrinsic::riscv_vslidedown_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  IntrinsicTypes = {ResultType, Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vslideup_vx:
  ID = Intrinsic::riscv_vslideup;
  IntrinsicTypes = {ResultType, Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vslideup_vx_m:
  ID = Intrinsic::riscv_vslideup_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  IntrinsicTypes = {ResultType, Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vsll_vv:
case RISCVVector::BI__builtin_rvv_vsll_vx:
  ID = Intrinsic::riscv_vsll;
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vsll_vv_m:
case RISCVVector::BI__builtin_rvv_vsll_vx_m:
  ID = Intrinsic::riscv_vsll_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  Ops.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
  IntrinsicTypes = {ResultType, Ops[2]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vsm_v:
  ID = Intrinsic::riscv_vsm;

      // Builtin: (ptr, value, vl). Intrinsic: (value, ptr, vl)
      std::swap(Ops[0], Ops[1]);
      Ops[1] = Builder.CreateBitCast(Ops[1], Ops[0]->getType()->getPointerTo());
      IntrinsicTypes = {Ops[0]->getType(), Ops[2]->getType()};
    break;
case RISCVVector::BI__builtin_rvv_vsmul_vv:
case RISCVVector::BI__builtin_rvv_vsmul_vx:
  ID = Intrinsic::riscv_vsmul;
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vsmul_vv_m:
case RISCVVector::BI__builtin_rvv_vsmul_vx_m:
  ID = Intrinsic::riscv_vsmul_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  Ops.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
  IntrinsicTypes = {ResultType, Ops[2]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vsoxei8_v:
case RISCVVector::BI__builtin_rvv_vsoxei16_v:
case RISCVVector::BI__builtin_rvv_vsoxei32_v:
case RISCVVector::BI__builtin_rvv_vsoxei64_v:
  ID = Intrinsic::riscv_vsoxei;

        // Builtin: (ptr, index, value, vl). Intrinsic: (value, ptr, index, vl)
        std::rotate(Ops.begin(), Ops.begin() + 2, Ops.begin() + 3);
        Ops[1] = Builder.CreateBitCast(Ops[1],Ops[0]->getType()->getPointerTo());
        IntrinsicTypes = {Ops[0]->getType(), Ops[2]->getType(), Ops[3]->getType()};
      break;
case RISCVVector::BI__builtin_rvv_vsoxei8_v_m:
case RISCVVector::BI__builtin_rvv_vsoxei16_v_m:
case RISCVVector::BI__builtin_rvv_vsoxei32_v_m:
case RISCVVector::BI__builtin_rvv_vsoxei64_v_m:
  ID = Intrinsic::riscv_vsoxei_mask;

        // Builtin: (mask, ptr, index, value, vl). Intrinsic: (value, ptr, index, mask, vl)
        std::swap(Ops[0], Ops[3]);
        Ops[1] = Builder.CreateBitCast(Ops[1], Ops[0]->getType()->getPointerTo());
        IntrinsicTypes = {Ops[0]->getType(), Ops[2]->getType(), Ops[4]->getType()};
      break;
case RISCVVector::BI__builtin_rvv_vsoxseg2ei8_v:
case RISCVVector::BI__builtin_rvv_vsoxseg2ei16_v:
case RISCVVector::BI__builtin_rvv_vsoxseg2ei32_v:
case RISCVVector::BI__builtin_rvv_vsoxseg2ei64_v:
  ID = Intrinsic::riscv_vsoxseg2;
  NF = 2;

    {
      // Builtin: (ptr, index, val0, val1, ..., vl)
      // Intrinsic: (val0, val1, ..., ptr, index, vl)
      std::rotate(Ops.begin(), Ops.begin() + 2, Ops.end() - 1);
      IntrinsicTypes = {Ops[0]->getType(),
                        Ops[NF + 1]->getType(), Ops[NF + 2]->getType()};
      assert(Ops.size() == NF + 3);
    }
            break;
case RISCVVector::BI__builtin_rvv_vsoxseg2ei8_v_m:
case RISCVVector::BI__builtin_rvv_vsoxseg2ei16_v_m:
case RISCVVector::BI__builtin_rvv_vsoxseg2ei32_v_m:
case RISCVVector::BI__builtin_rvv_vsoxseg2ei64_v_m:
  ID = Intrinsic::riscv_vsoxseg2_mask;
  NF = 2;

    {
      // Builtin: (mask, ptr, index, val0, val1, ..., vl)
      // Intrinsic: (val0, val1, ..., ptr, index, mask, vl)
      std::rotate(Ops.begin(), Ops.begin() + 3, Ops.end() - 1);
      std::rotate(Ops.begin() + NF, Ops.begin() + NF + 1, Ops.begin() + NF + 3);
      IntrinsicTypes = {Ops[0]->getType(),
                        Ops[NF + 1]->getType(), Ops[NF + 3]->getType()};
      assert(Ops.size() == NF + 4);
    }
            break;
case RISCVVector::BI__builtin_rvv_vsoxseg3ei8_v:
case RISCVVector::BI__builtin_rvv_vsoxseg3ei16_v:
case RISCVVector::BI__builtin_rvv_vsoxseg3ei32_v:
case RISCVVector::BI__builtin_rvv_vsoxseg3ei64_v:
  ID = Intrinsic::riscv_vsoxseg3;
  NF = 3;

    {
      // Builtin: (ptr, index, val0, val1, ..., vl)
      // Intrinsic: (val0, val1, ..., ptr, index, vl)
      std::rotate(Ops.begin(), Ops.begin() + 2, Ops.end() - 1);
      IntrinsicTypes = {Ops[0]->getType(),
                        Ops[NF + 1]->getType(), Ops[NF + 2]->getType()};
      assert(Ops.size() == NF + 3);
    }
            break;
case RISCVVector::BI__builtin_rvv_vsoxseg3ei8_v_m:
case RISCVVector::BI__builtin_rvv_vsoxseg3ei16_v_m:
case RISCVVector::BI__builtin_rvv_vsoxseg3ei32_v_m:
case RISCVVector::BI__builtin_rvv_vsoxseg3ei64_v_m:
  ID = Intrinsic::riscv_vsoxseg3_mask;
  NF = 3;

    {
      // Builtin: (mask, ptr, index, val0, val1, ..., vl)
      // Intrinsic: (val0, val1, ..., ptr, index, mask, vl)
      std::rotate(Ops.begin(), Ops.begin() + 3, Ops.end() - 1);
      std::rotate(Ops.begin() + NF, Ops.begin() + NF + 1, Ops.begin() + NF + 3);
      IntrinsicTypes = {Ops[0]->getType(),
                        Ops[NF + 1]->getType(), Ops[NF + 3]->getType()};
      assert(Ops.size() == NF + 4);
    }
            break;
case RISCVVector::BI__builtin_rvv_vsoxseg4ei8_v:
case RISCVVector::BI__builtin_rvv_vsoxseg4ei16_v:
case RISCVVector::BI__builtin_rvv_vsoxseg4ei32_v:
case RISCVVector::BI__builtin_rvv_vsoxseg4ei64_v:
  ID = Intrinsic::riscv_vsoxseg4;
  NF = 4;

    {
      // Builtin: (ptr, index, val0, val1, ..., vl)
      // Intrinsic: (val0, val1, ..., ptr, index, vl)
      std::rotate(Ops.begin(), Ops.begin() + 2, Ops.end() - 1);
      IntrinsicTypes = {Ops[0]->getType(),
                        Ops[NF + 1]->getType(), Ops[NF + 2]->getType()};
      assert(Ops.size() == NF + 3);
    }
            break;
case RISCVVector::BI__builtin_rvv_vsoxseg4ei8_v_m:
case RISCVVector::BI__builtin_rvv_vsoxseg4ei16_v_m:
case RISCVVector::BI__builtin_rvv_vsoxseg4ei32_v_m:
case RISCVVector::BI__builtin_rvv_vsoxseg4ei64_v_m:
  ID = Intrinsic::riscv_vsoxseg4_mask;
  NF = 4;

    {
      // Builtin: (mask, ptr, index, val0, val1, ..., vl)
      // Intrinsic: (val0, val1, ..., ptr, index, mask, vl)
      std::rotate(Ops.begin(), Ops.begin() + 3, Ops.end() - 1);
      std::rotate(Ops.begin() + NF, Ops.begin() + NF + 1, Ops.begin() + NF + 3);
      IntrinsicTypes = {Ops[0]->getType(),
                        Ops[NF + 1]->getType(), Ops[NF + 3]->getType()};
      assert(Ops.size() == NF + 4);
    }
            break;
case RISCVVector::BI__builtin_rvv_vsoxseg5ei8_v:
case RISCVVector::BI__builtin_rvv_vsoxseg5ei16_v:
case RISCVVector::BI__builtin_rvv_vsoxseg5ei32_v:
case RISCVVector::BI__builtin_rvv_vsoxseg5ei64_v:
  ID = Intrinsic::riscv_vsoxseg5;
  NF = 5;

    {
      // Builtin: (ptr, index, val0, val1, ..., vl)
      // Intrinsic: (val0, val1, ..., ptr, index, vl)
      std::rotate(Ops.begin(), Ops.begin() + 2, Ops.end() - 1);
      IntrinsicTypes = {Ops[0]->getType(),
                        Ops[NF + 1]->getType(), Ops[NF + 2]->getType()};
      assert(Ops.size() == NF + 3);
    }
            break;
case RISCVVector::BI__builtin_rvv_vsoxseg5ei8_v_m:
case RISCVVector::BI__builtin_rvv_vsoxseg5ei16_v_m:
case RISCVVector::BI__builtin_rvv_vsoxseg5ei32_v_m:
case RISCVVector::BI__builtin_rvv_vsoxseg5ei64_v_m:
  ID = Intrinsic::riscv_vsoxseg5_mask;
  NF = 5;

    {
      // Builtin: (mask, ptr, index, val0, val1, ..., vl)
      // Intrinsic: (val0, val1, ..., ptr, index, mask, vl)
      std::rotate(Ops.begin(), Ops.begin() + 3, Ops.end() - 1);
      std::rotate(Ops.begin() + NF, Ops.begin() + NF + 1, Ops.begin() + NF + 3);
      IntrinsicTypes = {Ops[0]->getType(),
                        Ops[NF + 1]->getType(), Ops[NF + 3]->getType()};
      assert(Ops.size() == NF + 4);
    }
            break;
case RISCVVector::BI__builtin_rvv_vsoxseg6ei8_v:
case RISCVVector::BI__builtin_rvv_vsoxseg6ei16_v:
case RISCVVector::BI__builtin_rvv_vsoxseg6ei32_v:
case RISCVVector::BI__builtin_rvv_vsoxseg6ei64_v:
  ID = Intrinsic::riscv_vsoxseg6;
  NF = 6;

    {
      // Builtin: (ptr, index, val0, val1, ..., vl)
      // Intrinsic: (val0, val1, ..., ptr, index, vl)
      std::rotate(Ops.begin(), Ops.begin() + 2, Ops.end() - 1);
      IntrinsicTypes = {Ops[0]->getType(),
                        Ops[NF + 1]->getType(), Ops[NF + 2]->getType()};
      assert(Ops.size() == NF + 3);
    }
            break;
case RISCVVector::BI__builtin_rvv_vsoxseg6ei8_v_m:
case RISCVVector::BI__builtin_rvv_vsoxseg6ei16_v_m:
case RISCVVector::BI__builtin_rvv_vsoxseg6ei32_v_m:
case RISCVVector::BI__builtin_rvv_vsoxseg6ei64_v_m:
  ID = Intrinsic::riscv_vsoxseg6_mask;
  NF = 6;

    {
      // Builtin: (mask, ptr, index, val0, val1, ..., vl)
      // Intrinsic: (val0, val1, ..., ptr, index, mask, vl)
      std::rotate(Ops.begin(), Ops.begin() + 3, Ops.end() - 1);
      std::rotate(Ops.begin() + NF, Ops.begin() + NF + 1, Ops.begin() + NF + 3);
      IntrinsicTypes = {Ops[0]->getType(),
                        Ops[NF + 1]->getType(), Ops[NF + 3]->getType()};
      assert(Ops.size() == NF + 4);
    }
            break;
case RISCVVector::BI__builtin_rvv_vsoxseg7ei8_v:
case RISCVVector::BI__builtin_rvv_vsoxseg7ei16_v:
case RISCVVector::BI__builtin_rvv_vsoxseg7ei32_v:
case RISCVVector::BI__builtin_rvv_vsoxseg7ei64_v:
  ID = Intrinsic::riscv_vsoxseg7;
  NF = 7;

    {
      // Builtin: (ptr, index, val0, val1, ..., vl)
      // Intrinsic: (val0, val1, ..., ptr, index, vl)
      std::rotate(Ops.begin(), Ops.begin() + 2, Ops.end() - 1);
      IntrinsicTypes = {Ops[0]->getType(),
                        Ops[NF + 1]->getType(), Ops[NF + 2]->getType()};
      assert(Ops.size() == NF + 3);
    }
            break;
case RISCVVector::BI__builtin_rvv_vsoxseg7ei8_v_m:
case RISCVVector::BI__builtin_rvv_vsoxseg7ei16_v_m:
case RISCVVector::BI__builtin_rvv_vsoxseg7ei32_v_m:
case RISCVVector::BI__builtin_rvv_vsoxseg7ei64_v_m:
  ID = Intrinsic::riscv_vsoxseg7_mask;
  NF = 7;

    {
      // Builtin: (mask, ptr, index, val0, val1, ..., vl)
      // Intrinsic: (val0, val1, ..., ptr, index, mask, vl)
      std::rotate(Ops.begin(), Ops.begin() + 3, Ops.end() - 1);
      std::rotate(Ops.begin() + NF, Ops.begin() + NF + 1, Ops.begin() + NF + 3);
      IntrinsicTypes = {Ops[0]->getType(),
                        Ops[NF + 1]->getType(), Ops[NF + 3]->getType()};
      assert(Ops.size() == NF + 4);
    }
            break;
case RISCVVector::BI__builtin_rvv_vsoxseg8ei8_v:
case RISCVVector::BI__builtin_rvv_vsoxseg8ei16_v:
case RISCVVector::BI__builtin_rvv_vsoxseg8ei32_v:
case RISCVVector::BI__builtin_rvv_vsoxseg8ei64_v:
  ID = Intrinsic::riscv_vsoxseg8;
  NF = 8;

    {
      // Builtin: (ptr, index, val0, val1, ..., vl)
      // Intrinsic: (val0, val1, ..., ptr, index, vl)
      std::rotate(Ops.begin(), Ops.begin() + 2, Ops.end() - 1);
      IntrinsicTypes = {Ops[0]->getType(),
                        Ops[NF + 1]->getType(), Ops[NF + 2]->getType()};
      assert(Ops.size() == NF + 3);
    }
            break;
case RISCVVector::BI__builtin_rvv_vsoxseg8ei8_v_m:
case RISCVVector::BI__builtin_rvv_vsoxseg8ei16_v_m:
case RISCVVector::BI__builtin_rvv_vsoxseg8ei32_v_m:
case RISCVVector::BI__builtin_rvv_vsoxseg8ei64_v_m:
  ID = Intrinsic::riscv_vsoxseg8_mask;
  NF = 8;

    {
      // Builtin: (mask, ptr, index, val0, val1, ..., vl)
      // Intrinsic: (val0, val1, ..., ptr, index, mask, vl)
      std::rotate(Ops.begin(), Ops.begin() + 3, Ops.end() - 1);
      std::rotate(Ops.begin() + NF, Ops.begin() + NF + 1, Ops.begin() + NF + 3);
      IntrinsicTypes = {Ops[0]->getType(),
                        Ops[NF + 1]->getType(), Ops[NF + 3]->getType()};
      assert(Ops.size() == NF + 4);
    }
            break;
case RISCVVector::BI__builtin_rvv_vsra_vv:
case RISCVVector::BI__builtin_rvv_vsra_vx:
  ID = Intrinsic::riscv_vsra;
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vsra_vv_m:
case RISCVVector::BI__builtin_rvv_vsra_vx_m:
  ID = Intrinsic::riscv_vsra_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  Ops.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
  IntrinsicTypes = {ResultType, Ops[2]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vsrl_vv:
case RISCVVector::BI__builtin_rvv_vsrl_vx:
  ID = Intrinsic::riscv_vsrl;
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vsrl_vv_m:
case RISCVVector::BI__builtin_rvv_vsrl_vx_m:
  ID = Intrinsic::riscv_vsrl_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  Ops.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
  IntrinsicTypes = {ResultType, Ops[2]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vsse16_v:
case RISCVVector::BI__builtin_rvv_vsse32_v:
case RISCVVector::BI__builtin_rvv_vsse64_v:
case RISCVVector::BI__builtin_rvv_vsse8_v:
  ID = Intrinsic::riscv_vsse;

        // Builtin: (ptr, stride, value, vl). Intrinsic: (value, ptr, stride, vl)
        std::rotate(Ops.begin(), Ops.begin() + 2, Ops.begin() + 3);
        Ops[1] = Builder.CreateBitCast(Ops[1], Ops[0]->getType()->getPointerTo());
        IntrinsicTypes = {Ops[0]->getType(), Ops[3]->getType()};
      break;
case RISCVVector::BI__builtin_rvv_vsse16_v_m:
case RISCVVector::BI__builtin_rvv_vsse32_v_m:
case RISCVVector::BI__builtin_rvv_vsse64_v_m:
case RISCVVector::BI__builtin_rvv_vsse8_v_m:
  ID = Intrinsic::riscv_vsse_mask;

        // Builtin: (mask, ptr, stride, value, vl). Intrinsic: (value, ptr, stride, mask, vl)
        std::swap(Ops[0], Ops[3]);
        Ops[1] = Builder.CreateBitCast(Ops[1], Ops[0]->getType()->getPointerTo());
        IntrinsicTypes = {Ops[0]->getType(), Ops[4]->getType()};
      break;
case RISCVVector::BI__builtin_rvv_vsseg2e16_v:
case RISCVVector::BI__builtin_rvv_vsseg2e32_v:
case RISCVVector::BI__builtin_rvv_vsseg2e64_v:
case RISCVVector::BI__builtin_rvv_vsseg2e8_v:
  ID = Intrinsic::riscv_vsseg2;
  NF = 2;

    {
      // Builtin: (ptr, val0, val1, ..., vl)
      // Intrinsic: (val0, val1, ..., ptr, vl)
      std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
      IntrinsicTypes = {Ops[0]->getType(), Ops[NF + 1]->getType()};
      assert(Ops.size() == NF + 2);
    }
            break;
case RISCVVector::BI__builtin_rvv_vsseg2e16_v_m:
case RISCVVector::BI__builtin_rvv_vsseg2e32_v_m:
case RISCVVector::BI__builtin_rvv_vsseg2e64_v_m:
case RISCVVector::BI__builtin_rvv_vsseg2e8_v_m:
  ID = Intrinsic::riscv_vsseg2_mask;
  NF = 2;

    {
      // Builtin: (mask, ptr, val0, val1, ..., vl)
      // Intrinsic: (val0, val1, ..., ptr, mask, vl)
      std::rotate(Ops.begin(), Ops.begin() + 2, Ops.end() - 1);
      std::swap(Ops[NF], Ops[NF + 1]);
      IntrinsicTypes = {Ops[0]->getType(), Ops[NF + 2]->getType()};
      assert(Ops.size() == NF + 3);
    }
            break;
case RISCVVector::BI__builtin_rvv_vsseg3e8_v:
case RISCVVector::BI__builtin_rvv_vsseg3e16_v:
case RISCVVector::BI__builtin_rvv_vsseg3e32_v:
case RISCVVector::BI__builtin_rvv_vsseg3e64_v:
  ID = Intrinsic::riscv_vsseg3;
  NF = 3;

    {
      // Builtin: (ptr, val0, val1, ..., vl)
      // Intrinsic: (val0, val1, ..., ptr, vl)
      std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
      IntrinsicTypes = {Ops[0]->getType(), Ops[NF + 1]->getType()};
      assert(Ops.size() == NF + 2);
    }
            break;
case RISCVVector::BI__builtin_rvv_vsseg3e8_v_m:
case RISCVVector::BI__builtin_rvv_vsseg3e16_v_m:
case RISCVVector::BI__builtin_rvv_vsseg3e32_v_m:
case RISCVVector::BI__builtin_rvv_vsseg3e64_v_m:
  ID = Intrinsic::riscv_vsseg3_mask;
  NF = 3;

    {
      // Builtin: (mask, ptr, val0, val1, ..., vl)
      // Intrinsic: (val0, val1, ..., ptr, mask, vl)
      std::rotate(Ops.begin(), Ops.begin() + 2, Ops.end() - 1);
      std::swap(Ops[NF], Ops[NF + 1]);
      IntrinsicTypes = {Ops[0]->getType(), Ops[NF + 2]->getType()};
      assert(Ops.size() == NF + 3);
    }
            break;
case RISCVVector::BI__builtin_rvv_vsseg4e8_v:
case RISCVVector::BI__builtin_rvv_vsseg4e16_v:
case RISCVVector::BI__builtin_rvv_vsseg4e32_v:
case RISCVVector::BI__builtin_rvv_vsseg4e64_v:
  ID = Intrinsic::riscv_vsseg4;
  NF = 4;

    {
      // Builtin: (ptr, val0, val1, ..., vl)
      // Intrinsic: (val0, val1, ..., ptr, vl)
      std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
      IntrinsicTypes = {Ops[0]->getType(), Ops[NF + 1]->getType()};
      assert(Ops.size() == NF + 2);
    }
            break;
case RISCVVector::BI__builtin_rvv_vsseg4e8_v_m:
case RISCVVector::BI__builtin_rvv_vsseg4e16_v_m:
case RISCVVector::BI__builtin_rvv_vsseg4e32_v_m:
case RISCVVector::BI__builtin_rvv_vsseg4e64_v_m:
  ID = Intrinsic::riscv_vsseg4_mask;
  NF = 4;

    {
      // Builtin: (mask, ptr, val0, val1, ..., vl)
      // Intrinsic: (val0, val1, ..., ptr, mask, vl)
      std::rotate(Ops.begin(), Ops.begin() + 2, Ops.end() - 1);
      std::swap(Ops[NF], Ops[NF + 1]);
      IntrinsicTypes = {Ops[0]->getType(), Ops[NF + 2]->getType()};
      assert(Ops.size() == NF + 3);
    }
            break;
case RISCVVector::BI__builtin_rvv_vsseg5e8_v:
case RISCVVector::BI__builtin_rvv_vsseg5e16_v:
case RISCVVector::BI__builtin_rvv_vsseg5e32_v:
case RISCVVector::BI__builtin_rvv_vsseg5e64_v:
  ID = Intrinsic::riscv_vsseg5;
  NF = 5;

    {
      // Builtin: (ptr, val0, val1, ..., vl)
      // Intrinsic: (val0, val1, ..., ptr, vl)
      std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
      IntrinsicTypes = {Ops[0]->getType(), Ops[NF + 1]->getType()};
      assert(Ops.size() == NF + 2);
    }
            break;
case RISCVVector::BI__builtin_rvv_vsseg5e8_v_m:
case RISCVVector::BI__builtin_rvv_vsseg5e16_v_m:
case RISCVVector::BI__builtin_rvv_vsseg5e32_v_m:
case RISCVVector::BI__builtin_rvv_vsseg5e64_v_m:
  ID = Intrinsic::riscv_vsseg5_mask;
  NF = 5;

    {
      // Builtin: (mask, ptr, val0, val1, ..., vl)
      // Intrinsic: (val0, val1, ..., ptr, mask, vl)
      std::rotate(Ops.begin(), Ops.begin() + 2, Ops.end() - 1);
      std::swap(Ops[NF], Ops[NF + 1]);
      IntrinsicTypes = {Ops[0]->getType(), Ops[NF + 2]->getType()};
      assert(Ops.size() == NF + 3);
    }
            break;
case RISCVVector::BI__builtin_rvv_vsseg6e8_v:
case RISCVVector::BI__builtin_rvv_vsseg6e16_v:
case RISCVVector::BI__builtin_rvv_vsseg6e32_v:
case RISCVVector::BI__builtin_rvv_vsseg6e64_v:
  ID = Intrinsic::riscv_vsseg6;
  NF = 6;

    {
      // Builtin: (ptr, val0, val1, ..., vl)
      // Intrinsic: (val0, val1, ..., ptr, vl)
      std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
      IntrinsicTypes = {Ops[0]->getType(), Ops[NF + 1]->getType()};
      assert(Ops.size() == NF + 2);
    }
            break;
case RISCVVector::BI__builtin_rvv_vsseg6e8_v_m:
case RISCVVector::BI__builtin_rvv_vsseg6e16_v_m:
case RISCVVector::BI__builtin_rvv_vsseg6e32_v_m:
case RISCVVector::BI__builtin_rvv_vsseg6e64_v_m:
  ID = Intrinsic::riscv_vsseg6_mask;
  NF = 6;

    {
      // Builtin: (mask, ptr, val0, val1, ..., vl)
      // Intrinsic: (val0, val1, ..., ptr, mask, vl)
      std::rotate(Ops.begin(), Ops.begin() + 2, Ops.end() - 1);
      std::swap(Ops[NF], Ops[NF + 1]);
      IntrinsicTypes = {Ops[0]->getType(), Ops[NF + 2]->getType()};
      assert(Ops.size() == NF + 3);
    }
            break;
case RISCVVector::BI__builtin_rvv_vsseg7e8_v:
case RISCVVector::BI__builtin_rvv_vsseg7e16_v:
case RISCVVector::BI__builtin_rvv_vsseg7e32_v:
case RISCVVector::BI__builtin_rvv_vsseg7e64_v:
  ID = Intrinsic::riscv_vsseg7;
  NF = 7;

    {
      // Builtin: (ptr, val0, val1, ..., vl)
      // Intrinsic: (val0, val1, ..., ptr, vl)
      std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
      IntrinsicTypes = {Ops[0]->getType(), Ops[NF + 1]->getType()};
      assert(Ops.size() == NF + 2);
    }
            break;
case RISCVVector::BI__builtin_rvv_vsseg7e8_v_m:
case RISCVVector::BI__builtin_rvv_vsseg7e16_v_m:
case RISCVVector::BI__builtin_rvv_vsseg7e32_v_m:
case RISCVVector::BI__builtin_rvv_vsseg7e64_v_m:
  ID = Intrinsic::riscv_vsseg7_mask;
  NF = 7;

    {
      // Builtin: (mask, ptr, val0, val1, ..., vl)
      // Intrinsic: (val0, val1, ..., ptr, mask, vl)
      std::rotate(Ops.begin(), Ops.begin() + 2, Ops.end() - 1);
      std::swap(Ops[NF], Ops[NF + 1]);
      IntrinsicTypes = {Ops[0]->getType(), Ops[NF + 2]->getType()};
      assert(Ops.size() == NF + 3);
    }
            break;
case RISCVVector::BI__builtin_rvv_vsseg8e8_v:
case RISCVVector::BI__builtin_rvv_vsseg8e16_v:
case RISCVVector::BI__builtin_rvv_vsseg8e32_v:
case RISCVVector::BI__builtin_rvv_vsseg8e64_v:
  ID = Intrinsic::riscv_vsseg8;
  NF = 8;

    {
      // Builtin: (ptr, val0, val1, ..., vl)
      // Intrinsic: (val0, val1, ..., ptr, vl)
      std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
      IntrinsicTypes = {Ops[0]->getType(), Ops[NF + 1]->getType()};
      assert(Ops.size() == NF + 2);
    }
            break;
case RISCVVector::BI__builtin_rvv_vsseg8e8_v_m:
case RISCVVector::BI__builtin_rvv_vsseg8e16_v_m:
case RISCVVector::BI__builtin_rvv_vsseg8e32_v_m:
case RISCVVector::BI__builtin_rvv_vsseg8e64_v_m:
  ID = Intrinsic::riscv_vsseg8_mask;
  NF = 8;

    {
      // Builtin: (mask, ptr, val0, val1, ..., vl)
      // Intrinsic: (val0, val1, ..., ptr, mask, vl)
      std::rotate(Ops.begin(), Ops.begin() + 2, Ops.end() - 1);
      std::swap(Ops[NF], Ops[NF + 1]);
      IntrinsicTypes = {Ops[0]->getType(), Ops[NF + 2]->getType()};
      assert(Ops.size() == NF + 3);
    }
            break;
case RISCVVector::BI__builtin_rvv_vssra_vv:
case RISCVVector::BI__builtin_rvv_vssra_vx:
  ID = Intrinsic::riscv_vssra;
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vssra_vv_m:
case RISCVVector::BI__builtin_rvv_vssra_vx_m:
  ID = Intrinsic::riscv_vssra_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  Ops.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
  IntrinsicTypes = {ResultType, Ops[2]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vssrl_vv:
case RISCVVector::BI__builtin_rvv_vssrl_vx:
  ID = Intrinsic::riscv_vssrl;
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vssrl_vv_m:
case RISCVVector::BI__builtin_rvv_vssrl_vx_m:
  ID = Intrinsic::riscv_vssrl_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  Ops.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
  IntrinsicTypes = {ResultType, Ops[2]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vssseg2e16_v:
case RISCVVector::BI__builtin_rvv_vssseg2e32_v:
case RISCVVector::BI__builtin_rvv_vssseg2e64_v:
case RISCVVector::BI__builtin_rvv_vssseg2e8_v:
  ID = Intrinsic::riscv_vssseg2;
  NF = 2;

    {
      // Builtin: (ptr, stride, val0, val1, ..., vl).
      // Intrinsic: (val0, val1, ..., ptr, stride, vl)
      std::rotate(Ops.begin(), Ops.begin() + 2, Ops.end() - 1);
      IntrinsicTypes = {Ops[0]->getType(), Ops[NF + 1]->getType()};
      assert(Ops.size() == NF + 3);
    }
            break;
case RISCVVector::BI__builtin_rvv_vssseg2e16_v_m:
case RISCVVector::BI__builtin_rvv_vssseg2e32_v_m:
case RISCVVector::BI__builtin_rvv_vssseg2e64_v_m:
case RISCVVector::BI__builtin_rvv_vssseg2e8_v_m:
  ID = Intrinsic::riscv_vssseg2_mask;
  NF = 2;

    {
      // Builtin: (mask, ptr, stride, val0, val1, ..., vl).
      // Intrinsic: (val0, val1, ..., ptr, stride, mask, vl)
      std::rotate(Ops.begin(), Ops.begin() + 3, Ops.end() - 1);
      std::rotate(Ops.begin() + NF, Ops.begin() + NF + 1, Ops.begin() + NF + 3);
      IntrinsicTypes = {Ops[0]->getType(), Ops[NF + 1]->getType()};
      assert(Ops.size() == NF + 4);
    }
            break;
case RISCVVector::BI__builtin_rvv_vssseg3e8_v:
case RISCVVector::BI__builtin_rvv_vssseg3e16_v:
case RISCVVector::BI__builtin_rvv_vssseg3e32_v:
case RISCVVector::BI__builtin_rvv_vssseg3e64_v:
  ID = Intrinsic::riscv_vssseg3;
  NF = 3;

    {
      // Builtin: (ptr, stride, val0, val1, ..., vl).
      // Intrinsic: (val0, val1, ..., ptr, stride, vl)
      std::rotate(Ops.begin(), Ops.begin() + 2, Ops.end() - 1);
      IntrinsicTypes = {Ops[0]->getType(), Ops[NF + 1]->getType()};
      assert(Ops.size() == NF + 3);
    }
            break;
case RISCVVector::BI__builtin_rvv_vssseg3e8_v_m:
case RISCVVector::BI__builtin_rvv_vssseg3e16_v_m:
case RISCVVector::BI__builtin_rvv_vssseg3e32_v_m:
case RISCVVector::BI__builtin_rvv_vssseg3e64_v_m:
  ID = Intrinsic::riscv_vssseg3_mask;
  NF = 3;

    {
      // Builtin: (mask, ptr, stride, val0, val1, ..., vl).
      // Intrinsic: (val0, val1, ..., ptr, stride, mask, vl)
      std::rotate(Ops.begin(), Ops.begin() + 3, Ops.end() - 1);
      std::rotate(Ops.begin() + NF, Ops.begin() + NF + 1, Ops.begin() + NF + 3);
      IntrinsicTypes = {Ops[0]->getType(), Ops[NF + 1]->getType()};
      assert(Ops.size() == NF + 4);
    }
            break;
case RISCVVector::BI__builtin_rvv_vssseg4e8_v:
case RISCVVector::BI__builtin_rvv_vssseg4e16_v:
case RISCVVector::BI__builtin_rvv_vssseg4e32_v:
case RISCVVector::BI__builtin_rvv_vssseg4e64_v:
  ID = Intrinsic::riscv_vssseg4;
  NF = 4;

    {
      // Builtin: (ptr, stride, val0, val1, ..., vl).
      // Intrinsic: (val0, val1, ..., ptr, stride, vl)
      std::rotate(Ops.begin(), Ops.begin() + 2, Ops.end() - 1);
      IntrinsicTypes = {Ops[0]->getType(), Ops[NF + 1]->getType()};
      assert(Ops.size() == NF + 3);
    }
            break;
case RISCVVector::BI__builtin_rvv_vssseg4e8_v_m:
case RISCVVector::BI__builtin_rvv_vssseg4e16_v_m:
case RISCVVector::BI__builtin_rvv_vssseg4e32_v_m:
case RISCVVector::BI__builtin_rvv_vssseg4e64_v_m:
  ID = Intrinsic::riscv_vssseg4_mask;
  NF = 4;

    {
      // Builtin: (mask, ptr, stride, val0, val1, ..., vl).
      // Intrinsic: (val0, val1, ..., ptr, stride, mask, vl)
      std::rotate(Ops.begin(), Ops.begin() + 3, Ops.end() - 1);
      std::rotate(Ops.begin() + NF, Ops.begin() + NF + 1, Ops.begin() + NF + 3);
      IntrinsicTypes = {Ops[0]->getType(), Ops[NF + 1]->getType()};
      assert(Ops.size() == NF + 4);
    }
            break;
case RISCVVector::BI__builtin_rvv_vssseg5e8_v:
case RISCVVector::BI__builtin_rvv_vssseg5e16_v:
case RISCVVector::BI__builtin_rvv_vssseg5e32_v:
case RISCVVector::BI__builtin_rvv_vssseg5e64_v:
  ID = Intrinsic::riscv_vssseg5;
  NF = 5;

    {
      // Builtin: (ptr, stride, val0, val1, ..., vl).
      // Intrinsic: (val0, val1, ..., ptr, stride, vl)
      std::rotate(Ops.begin(), Ops.begin() + 2, Ops.end() - 1);
      IntrinsicTypes = {Ops[0]->getType(), Ops[NF + 1]->getType()};
      assert(Ops.size() == NF + 3);
    }
            break;
case RISCVVector::BI__builtin_rvv_vssseg5e8_v_m:
case RISCVVector::BI__builtin_rvv_vssseg5e16_v_m:
case RISCVVector::BI__builtin_rvv_vssseg5e32_v_m:
case RISCVVector::BI__builtin_rvv_vssseg5e64_v_m:
  ID = Intrinsic::riscv_vssseg5_mask;
  NF = 5;

    {
      // Builtin: (mask, ptr, stride, val0, val1, ..., vl).
      // Intrinsic: (val0, val1, ..., ptr, stride, mask, vl)
      std::rotate(Ops.begin(), Ops.begin() + 3, Ops.end() - 1);
      std::rotate(Ops.begin() + NF, Ops.begin() + NF + 1, Ops.begin() + NF + 3);
      IntrinsicTypes = {Ops[0]->getType(), Ops[NF + 1]->getType()};
      assert(Ops.size() == NF + 4);
    }
            break;
case RISCVVector::BI__builtin_rvv_vssseg6e8_v:
case RISCVVector::BI__builtin_rvv_vssseg6e16_v:
case RISCVVector::BI__builtin_rvv_vssseg6e32_v:
case RISCVVector::BI__builtin_rvv_vssseg6e64_v:
  ID = Intrinsic::riscv_vssseg6;
  NF = 6;

    {
      // Builtin: (ptr, stride, val0, val1, ..., vl).
      // Intrinsic: (val0, val1, ..., ptr, stride, vl)
      std::rotate(Ops.begin(), Ops.begin() + 2, Ops.end() - 1);
      IntrinsicTypes = {Ops[0]->getType(), Ops[NF + 1]->getType()};
      assert(Ops.size() == NF + 3);
    }
            break;
case RISCVVector::BI__builtin_rvv_vssseg6e8_v_m:
case RISCVVector::BI__builtin_rvv_vssseg6e16_v_m:
case RISCVVector::BI__builtin_rvv_vssseg6e32_v_m:
case RISCVVector::BI__builtin_rvv_vssseg6e64_v_m:
  ID = Intrinsic::riscv_vssseg6_mask;
  NF = 6;

    {
      // Builtin: (mask, ptr, stride, val0, val1, ..., vl).
      // Intrinsic: (val0, val1, ..., ptr, stride, mask, vl)
      std::rotate(Ops.begin(), Ops.begin() + 3, Ops.end() - 1);
      std::rotate(Ops.begin() + NF, Ops.begin() + NF + 1, Ops.begin() + NF + 3);
      IntrinsicTypes = {Ops[0]->getType(), Ops[NF + 1]->getType()};
      assert(Ops.size() == NF + 4);
    }
            break;
case RISCVVector::BI__builtin_rvv_vssseg7e8_v:
case RISCVVector::BI__builtin_rvv_vssseg7e16_v:
case RISCVVector::BI__builtin_rvv_vssseg7e32_v:
case RISCVVector::BI__builtin_rvv_vssseg7e64_v:
  ID = Intrinsic::riscv_vssseg7;
  NF = 7;

    {
      // Builtin: (ptr, stride, val0, val1, ..., vl).
      // Intrinsic: (val0, val1, ..., ptr, stride, vl)
      std::rotate(Ops.begin(), Ops.begin() + 2, Ops.end() - 1);
      IntrinsicTypes = {Ops[0]->getType(), Ops[NF + 1]->getType()};
      assert(Ops.size() == NF + 3);
    }
            break;
case RISCVVector::BI__builtin_rvv_vssseg7e8_v_m:
case RISCVVector::BI__builtin_rvv_vssseg7e16_v_m:
case RISCVVector::BI__builtin_rvv_vssseg7e32_v_m:
case RISCVVector::BI__builtin_rvv_vssseg7e64_v_m:
  ID = Intrinsic::riscv_vssseg7_mask;
  NF = 7;

    {
      // Builtin: (mask, ptr, stride, val0, val1, ..., vl).
      // Intrinsic: (val0, val1, ..., ptr, stride, mask, vl)
      std::rotate(Ops.begin(), Ops.begin() + 3, Ops.end() - 1);
      std::rotate(Ops.begin() + NF, Ops.begin() + NF + 1, Ops.begin() + NF + 3);
      IntrinsicTypes = {Ops[0]->getType(), Ops[NF + 1]->getType()};
      assert(Ops.size() == NF + 4);
    }
            break;
case RISCVVector::BI__builtin_rvv_vssseg8e8_v:
case RISCVVector::BI__builtin_rvv_vssseg8e16_v:
case RISCVVector::BI__builtin_rvv_vssseg8e32_v:
case RISCVVector::BI__builtin_rvv_vssseg8e64_v:
  ID = Intrinsic::riscv_vssseg8;
  NF = 8;

    {
      // Builtin: (ptr, stride, val0, val1, ..., vl).
      // Intrinsic: (val0, val1, ..., ptr, stride, vl)
      std::rotate(Ops.begin(), Ops.begin() + 2, Ops.end() - 1);
      IntrinsicTypes = {Ops[0]->getType(), Ops[NF + 1]->getType()};
      assert(Ops.size() == NF + 3);
    }
            break;
case RISCVVector::BI__builtin_rvv_vssseg8e8_v_m:
case RISCVVector::BI__builtin_rvv_vssseg8e16_v_m:
case RISCVVector::BI__builtin_rvv_vssseg8e32_v_m:
case RISCVVector::BI__builtin_rvv_vssseg8e64_v_m:
  ID = Intrinsic::riscv_vssseg8_mask;
  NF = 8;

    {
      // Builtin: (mask, ptr, stride, val0, val1, ..., vl).
      // Intrinsic: (val0, val1, ..., ptr, stride, mask, vl)
      std::rotate(Ops.begin(), Ops.begin() + 3, Ops.end() - 1);
      std::rotate(Ops.begin() + NF, Ops.begin() + NF + 1, Ops.begin() + NF + 3);
      IntrinsicTypes = {Ops[0]->getType(), Ops[NF + 1]->getType()};
      assert(Ops.size() == NF + 4);
    }
            break;
case RISCVVector::BI__builtin_rvv_vssub_vv:
case RISCVVector::BI__builtin_rvv_vssub_vx:
  ID = Intrinsic::riscv_vssub;
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vssub_vv_m:
case RISCVVector::BI__builtin_rvv_vssub_vx_m:
  ID = Intrinsic::riscv_vssub_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  Ops.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
  IntrinsicTypes = {ResultType, Ops[2]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vssubu_vv:
case RISCVVector::BI__builtin_rvv_vssubu_vx:
  ID = Intrinsic::riscv_vssubu;
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vssubu_vv_m:
case RISCVVector::BI__builtin_rvv_vssubu_vx_m:
  ID = Intrinsic::riscv_vssubu_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  Ops.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
  IntrinsicTypes = {ResultType, Ops[2]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vsub_vv:
case RISCVVector::BI__builtin_rvv_vsub_vx:
  ID = Intrinsic::riscv_vsub;
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vsub_vv_m:
case RISCVVector::BI__builtin_rvv_vsub_vx_m:
  ID = Intrinsic::riscv_vsub_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  Ops.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
  IntrinsicTypes = {ResultType, Ops[2]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vsuxei16_v:
case RISCVVector::BI__builtin_rvv_vsuxei32_v:
case RISCVVector::BI__builtin_rvv_vsuxei64_v:
case RISCVVector::BI__builtin_rvv_vsuxei8_v:
  ID = Intrinsic::riscv_vsuxei;

        // Builtin: (ptr, index, value, vl). Intrinsic: (value, ptr, index, vl)
        std::rotate(Ops.begin(), Ops.begin() + 2, Ops.begin() + 3);
        Ops[1] = Builder.CreateBitCast(Ops[1],Ops[0]->getType()->getPointerTo());
        IntrinsicTypes = {Ops[0]->getType(), Ops[2]->getType(), Ops[3]->getType()};
      break;
case RISCVVector::BI__builtin_rvv_vsuxei16_v_m:
case RISCVVector::BI__builtin_rvv_vsuxei32_v_m:
case RISCVVector::BI__builtin_rvv_vsuxei64_v_m:
case RISCVVector::BI__builtin_rvv_vsuxei8_v_m:
  ID = Intrinsic::riscv_vsuxei_mask;

        // Builtin: (mask, ptr, index, value, vl). Intrinsic: (value, ptr, index, mask, vl)
        std::swap(Ops[0], Ops[3]);
        Ops[1] = Builder.CreateBitCast(Ops[1], Ops[0]->getType()->getPointerTo());
        IntrinsicTypes = {Ops[0]->getType(), Ops[2]->getType(), Ops[4]->getType()};
      break;
case RISCVVector::BI__builtin_rvv_vsuxseg2ei16_v:
case RISCVVector::BI__builtin_rvv_vsuxseg2ei32_v:
case RISCVVector::BI__builtin_rvv_vsuxseg2ei64_v:
case RISCVVector::BI__builtin_rvv_vsuxseg2ei8_v:
  ID = Intrinsic::riscv_vsuxseg2;
  NF = 2;

    {
      // Builtin: (ptr, index, val0, val1, ..., vl)
      // Intrinsic: (val0, val1, ..., ptr, index, vl)
      std::rotate(Ops.begin(), Ops.begin() + 2, Ops.end() - 1);
      IntrinsicTypes = {Ops[0]->getType(),
                        Ops[NF + 1]->getType(), Ops[NF + 2]->getType()};
      assert(Ops.size() == NF + 3);
    }
            break;
case RISCVVector::BI__builtin_rvv_vsuxseg2ei16_v_m:
case RISCVVector::BI__builtin_rvv_vsuxseg2ei32_v_m:
case RISCVVector::BI__builtin_rvv_vsuxseg2ei64_v_m:
case RISCVVector::BI__builtin_rvv_vsuxseg2ei8_v_m:
  ID = Intrinsic::riscv_vsuxseg2_mask;
  NF = 2;

    {
      // Builtin: (mask, ptr, index, val0, val1, ..., vl)
      // Intrinsic: (val0, val1, ..., ptr, index, mask, vl)
      std::rotate(Ops.begin(), Ops.begin() + 3, Ops.end() - 1);
      std::rotate(Ops.begin() + NF, Ops.begin() + NF + 1, Ops.begin() + NF + 3);
      IntrinsicTypes = {Ops[0]->getType(),
                        Ops[NF + 1]->getType(), Ops[NF + 3]->getType()};
      assert(Ops.size() == NF + 4);
    }
            break;
case RISCVVector::BI__builtin_rvv_vsuxseg3ei8_v:
case RISCVVector::BI__builtin_rvv_vsuxseg3ei16_v:
case RISCVVector::BI__builtin_rvv_vsuxseg3ei32_v:
case RISCVVector::BI__builtin_rvv_vsuxseg3ei64_v:
  ID = Intrinsic::riscv_vsuxseg3;
  NF = 3;

    {
      // Builtin: (ptr, index, val0, val1, ..., vl)
      // Intrinsic: (val0, val1, ..., ptr, index, vl)
      std::rotate(Ops.begin(), Ops.begin() + 2, Ops.end() - 1);
      IntrinsicTypes = {Ops[0]->getType(),
                        Ops[NF + 1]->getType(), Ops[NF + 2]->getType()};
      assert(Ops.size() == NF + 3);
    }
            break;
case RISCVVector::BI__builtin_rvv_vsuxseg3ei8_v_m:
case RISCVVector::BI__builtin_rvv_vsuxseg3ei16_v_m:
case RISCVVector::BI__builtin_rvv_vsuxseg3ei32_v_m:
case RISCVVector::BI__builtin_rvv_vsuxseg3ei64_v_m:
  ID = Intrinsic::riscv_vsuxseg3_mask;
  NF = 3;

    {
      // Builtin: (mask, ptr, index, val0, val1, ..., vl)
      // Intrinsic: (val0, val1, ..., ptr, index, mask, vl)
      std::rotate(Ops.begin(), Ops.begin() + 3, Ops.end() - 1);
      std::rotate(Ops.begin() + NF, Ops.begin() + NF + 1, Ops.begin() + NF + 3);
      IntrinsicTypes = {Ops[0]->getType(),
                        Ops[NF + 1]->getType(), Ops[NF + 3]->getType()};
      assert(Ops.size() == NF + 4);
    }
            break;
case RISCVVector::BI__builtin_rvv_vsuxseg4ei8_v:
case RISCVVector::BI__builtin_rvv_vsuxseg4ei16_v:
case RISCVVector::BI__builtin_rvv_vsuxseg4ei32_v:
case RISCVVector::BI__builtin_rvv_vsuxseg4ei64_v:
  ID = Intrinsic::riscv_vsuxseg4;
  NF = 4;

    {
      // Builtin: (ptr, index, val0, val1, ..., vl)
      // Intrinsic: (val0, val1, ..., ptr, index, vl)
      std::rotate(Ops.begin(), Ops.begin() + 2, Ops.end() - 1);
      IntrinsicTypes = {Ops[0]->getType(),
                        Ops[NF + 1]->getType(), Ops[NF + 2]->getType()};
      assert(Ops.size() == NF + 3);
    }
            break;
case RISCVVector::BI__builtin_rvv_vsuxseg4ei8_v_m:
case RISCVVector::BI__builtin_rvv_vsuxseg4ei16_v_m:
case RISCVVector::BI__builtin_rvv_vsuxseg4ei32_v_m:
case RISCVVector::BI__builtin_rvv_vsuxseg4ei64_v_m:
  ID = Intrinsic::riscv_vsuxseg4_mask;
  NF = 4;

    {
      // Builtin: (mask, ptr, index, val0, val1, ..., vl)
      // Intrinsic: (val0, val1, ..., ptr, index, mask, vl)
      std::rotate(Ops.begin(), Ops.begin() + 3, Ops.end() - 1);
      std::rotate(Ops.begin() + NF, Ops.begin() + NF + 1, Ops.begin() + NF + 3);
      IntrinsicTypes = {Ops[0]->getType(),
                        Ops[NF + 1]->getType(), Ops[NF + 3]->getType()};
      assert(Ops.size() == NF + 4);
    }
            break;
case RISCVVector::BI__builtin_rvv_vsuxseg5ei8_v:
case RISCVVector::BI__builtin_rvv_vsuxseg5ei16_v:
case RISCVVector::BI__builtin_rvv_vsuxseg5ei32_v:
case RISCVVector::BI__builtin_rvv_vsuxseg5ei64_v:
  ID = Intrinsic::riscv_vsuxseg5;
  NF = 5;

    {
      // Builtin: (ptr, index, val0, val1, ..., vl)
      // Intrinsic: (val0, val1, ..., ptr, index, vl)
      std::rotate(Ops.begin(), Ops.begin() + 2, Ops.end() - 1);
      IntrinsicTypes = {Ops[0]->getType(),
                        Ops[NF + 1]->getType(), Ops[NF + 2]->getType()};
      assert(Ops.size() == NF + 3);
    }
            break;
case RISCVVector::BI__builtin_rvv_vsuxseg5ei8_v_m:
case RISCVVector::BI__builtin_rvv_vsuxseg5ei16_v_m:
case RISCVVector::BI__builtin_rvv_vsuxseg5ei32_v_m:
case RISCVVector::BI__builtin_rvv_vsuxseg5ei64_v_m:
  ID = Intrinsic::riscv_vsuxseg5_mask;
  NF = 5;

    {
      // Builtin: (mask, ptr, index, val0, val1, ..., vl)
      // Intrinsic: (val0, val1, ..., ptr, index, mask, vl)
      std::rotate(Ops.begin(), Ops.begin() + 3, Ops.end() - 1);
      std::rotate(Ops.begin() + NF, Ops.begin() + NF + 1, Ops.begin() + NF + 3);
      IntrinsicTypes = {Ops[0]->getType(),
                        Ops[NF + 1]->getType(), Ops[NF + 3]->getType()};
      assert(Ops.size() == NF + 4);
    }
            break;
case RISCVVector::BI__builtin_rvv_vsuxseg6ei8_v:
case RISCVVector::BI__builtin_rvv_vsuxseg6ei16_v:
case RISCVVector::BI__builtin_rvv_vsuxseg6ei32_v:
case RISCVVector::BI__builtin_rvv_vsuxseg6ei64_v:
  ID = Intrinsic::riscv_vsuxseg6;
  NF = 6;

    {
      // Builtin: (ptr, index, val0, val1, ..., vl)
      // Intrinsic: (val0, val1, ..., ptr, index, vl)
      std::rotate(Ops.begin(), Ops.begin() + 2, Ops.end() - 1);
      IntrinsicTypes = {Ops[0]->getType(),
                        Ops[NF + 1]->getType(), Ops[NF + 2]->getType()};
      assert(Ops.size() == NF + 3);
    }
            break;
case RISCVVector::BI__builtin_rvv_vsuxseg6ei8_v_m:
case RISCVVector::BI__builtin_rvv_vsuxseg6ei16_v_m:
case RISCVVector::BI__builtin_rvv_vsuxseg6ei32_v_m:
case RISCVVector::BI__builtin_rvv_vsuxseg6ei64_v_m:
  ID = Intrinsic::riscv_vsuxseg6_mask;
  NF = 6;

    {
      // Builtin: (mask, ptr, index, val0, val1, ..., vl)
      // Intrinsic: (val0, val1, ..., ptr, index, mask, vl)
      std::rotate(Ops.begin(), Ops.begin() + 3, Ops.end() - 1);
      std::rotate(Ops.begin() + NF, Ops.begin() + NF + 1, Ops.begin() + NF + 3);
      IntrinsicTypes = {Ops[0]->getType(),
                        Ops[NF + 1]->getType(), Ops[NF + 3]->getType()};
      assert(Ops.size() == NF + 4);
    }
            break;
case RISCVVector::BI__builtin_rvv_vsuxseg7ei8_v:
case RISCVVector::BI__builtin_rvv_vsuxseg7ei16_v:
case RISCVVector::BI__builtin_rvv_vsuxseg7ei32_v:
case RISCVVector::BI__builtin_rvv_vsuxseg7ei64_v:
  ID = Intrinsic::riscv_vsuxseg7;
  NF = 7;

    {
      // Builtin: (ptr, index, val0, val1, ..., vl)
      // Intrinsic: (val0, val1, ..., ptr, index, vl)
      std::rotate(Ops.begin(), Ops.begin() + 2, Ops.end() - 1);
      IntrinsicTypes = {Ops[0]->getType(),
                        Ops[NF + 1]->getType(), Ops[NF + 2]->getType()};
      assert(Ops.size() == NF + 3);
    }
            break;
case RISCVVector::BI__builtin_rvv_vsuxseg7ei8_v_m:
case RISCVVector::BI__builtin_rvv_vsuxseg7ei16_v_m:
case RISCVVector::BI__builtin_rvv_vsuxseg7ei32_v_m:
case RISCVVector::BI__builtin_rvv_vsuxseg7ei64_v_m:
  ID = Intrinsic::riscv_vsuxseg7_mask;
  NF = 7;

    {
      // Builtin: (mask, ptr, index, val0, val1, ..., vl)
      // Intrinsic: (val0, val1, ..., ptr, index, mask, vl)
      std::rotate(Ops.begin(), Ops.begin() + 3, Ops.end() - 1);
      std::rotate(Ops.begin() + NF, Ops.begin() + NF + 1, Ops.begin() + NF + 3);
      IntrinsicTypes = {Ops[0]->getType(),
                        Ops[NF + 1]->getType(), Ops[NF + 3]->getType()};
      assert(Ops.size() == NF + 4);
    }
            break;
case RISCVVector::BI__builtin_rvv_vsuxseg8ei8_v:
case RISCVVector::BI__builtin_rvv_vsuxseg8ei16_v:
case RISCVVector::BI__builtin_rvv_vsuxseg8ei32_v:
case RISCVVector::BI__builtin_rvv_vsuxseg8ei64_v:
  ID = Intrinsic::riscv_vsuxseg8;
  NF = 8;

    {
      // Builtin: (ptr, index, val0, val1, ..., vl)
      // Intrinsic: (val0, val1, ..., ptr, index, vl)
      std::rotate(Ops.begin(), Ops.begin() + 2, Ops.end() - 1);
      IntrinsicTypes = {Ops[0]->getType(),
                        Ops[NF + 1]->getType(), Ops[NF + 2]->getType()};
      assert(Ops.size() == NF + 3);
    }
            break;
case RISCVVector::BI__builtin_rvv_vsuxseg8ei8_v_m:
case RISCVVector::BI__builtin_rvv_vsuxseg8ei16_v_m:
case RISCVVector::BI__builtin_rvv_vsuxseg8ei32_v_m:
case RISCVVector::BI__builtin_rvv_vsuxseg8ei64_v_m:
  ID = Intrinsic::riscv_vsuxseg8_mask;
  NF = 8;

    {
      // Builtin: (mask, ptr, index, val0, val1, ..., vl)
      // Intrinsic: (val0, val1, ..., ptr, index, mask, vl)
      std::rotate(Ops.begin(), Ops.begin() + 3, Ops.end() - 1);
      std::rotate(Ops.begin() + NF, Ops.begin() + NF + 1, Ops.begin() + NF + 3);
      IntrinsicTypes = {Ops[0]->getType(),
                        Ops[NF + 1]->getType(), Ops[NF + 3]->getType()};
      assert(Ops.size() == NF + 4);
    }
            break;
case RISCVVector::BI__builtin_rvv_vwadd_vv:
case RISCVVector::BI__builtin_rvv_vwadd_vx:
  ID = Intrinsic::riscv_vwadd;
  IntrinsicTypes = {ResultType, Ops[0]->getType(), Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vwcvt_x_x_v:
  ID = Intrinsic::riscv_vwadd;

      {
        // op1, vl
        IntrinsicTypes = {ResultType,
                          Ops[0]->getType(),
                          cast<llvm::VectorType>(Ops[0]->getType())->getElementType(),
                          Ops[1]->getType()};
        Ops.insert(Ops.begin() + 1, llvm::Constant::getNullValue(IntrinsicTypes[2]));
        break;
      }
      break;
case RISCVVector::BI__builtin_rvv_vwadd_vv_m:
case RISCVVector::BI__builtin_rvv_vwadd_vx_m:
  ID = Intrinsic::riscv_vwadd_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  Ops.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops[2]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vwcvt_x_x_v_m:
  ID = Intrinsic::riscv_vwadd_mask;

      {
        std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
        Ops.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
        // maskedoff, op1, mask, vl
        IntrinsicTypes = {ResultType,
                          Ops[1]->getType(),
                          cast<llvm::VectorType>(Ops[1]->getType())->getElementType(),
                          Ops[3]->getType()};
        Ops.insert(Ops.begin() + 2, llvm::Constant::getNullValue(IntrinsicTypes[2]));
        break;
      }
      break;
case RISCVVector::BI__builtin_rvv_vwadd_wv:
case RISCVVector::BI__builtin_rvv_vwadd_wx:
  ID = Intrinsic::riscv_vwadd_w;
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vwadd_wv_m:
case RISCVVector::BI__builtin_rvv_vwadd_wx_m:
  ID = Intrinsic::riscv_vwadd_w_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  Ops.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
  IntrinsicTypes = {ResultType, Ops[2]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vwaddu_vv:
case RISCVVector::BI__builtin_rvv_vwaddu_vx:
  ID = Intrinsic::riscv_vwaddu;
  IntrinsicTypes = {ResultType, Ops[0]->getType(), Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vwcvtu_x_x_v:
  ID = Intrinsic::riscv_vwaddu;

      {
        // op1, vl
        IntrinsicTypes = {ResultType,
                          Ops[0]->getType(),
                          cast<llvm::VectorType>(Ops[0]->getType())->getElementType(),
                          Ops[1]->getType()};
        Ops.insert(Ops.begin() + 1, llvm::Constant::getNullValue(IntrinsicTypes[2]));
        break;
      }
      break;
case RISCVVector::BI__builtin_rvv_vwaddu_vv_m:
case RISCVVector::BI__builtin_rvv_vwaddu_vx_m:
  ID = Intrinsic::riscv_vwaddu_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  Ops.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops[2]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vwcvtu_x_x_v_m:
  ID = Intrinsic::riscv_vwaddu_mask;

      {
        std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
        Ops.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
        // maskedoff, op1, mask, vl
        IntrinsicTypes = {ResultType,
                          Ops[1]->getType(),
                          cast<llvm::VectorType>(Ops[1]->getType())->getElementType(),
                          Ops[3]->getType()};
        Ops.insert(Ops.begin() + 2, llvm::Constant::getNullValue(IntrinsicTypes[2]));
        break;
      }
      break;
case RISCVVector::BI__builtin_rvv_vwaddu_wx:
case RISCVVector::BI__builtin_rvv_vwaddu_wv:
  ID = Intrinsic::riscv_vwaddu_w;
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vwaddu_wx_m:
case RISCVVector::BI__builtin_rvv_vwaddu_wv_m:
  ID = Intrinsic::riscv_vwaddu_w_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  Ops.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
  IntrinsicTypes = {ResultType, Ops[2]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vwmacc_vv:
case RISCVVector::BI__builtin_rvv_vwmacc_vx:
  ID = Intrinsic::riscv_vwmacc;
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops[2]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vwmacc_vv_m:
case RISCVVector::BI__builtin_rvv_vwmacc_vx_m:
  ID = Intrinsic::riscv_vwmacc_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops[2]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vwmaccsu_vv:
case RISCVVector::BI__builtin_rvv_vwmaccsu_vx:
  ID = Intrinsic::riscv_vwmaccsu;
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops[2]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vwmaccsu_vv_m:
case RISCVVector::BI__builtin_rvv_vwmaccsu_vx_m:
  ID = Intrinsic::riscv_vwmaccsu_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops[2]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vwmaccu_vv:
case RISCVVector::BI__builtin_rvv_vwmaccu_vx:
  ID = Intrinsic::riscv_vwmaccu;
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops[2]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vwmaccu_vv_m:
case RISCVVector::BI__builtin_rvv_vwmaccu_vx_m:
  ID = Intrinsic::riscv_vwmaccu_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops[2]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vwmaccus_vx:
  ID = Intrinsic::riscv_vwmaccus;
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops[2]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vwmaccus_vx_m:
  ID = Intrinsic::riscv_vwmaccus_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops[2]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vwmul_vv:
case RISCVVector::BI__builtin_rvv_vwmul_vx:
  ID = Intrinsic::riscv_vwmul;
  IntrinsicTypes = {ResultType, Ops[0]->getType(), Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vwmul_vv_m:
case RISCVVector::BI__builtin_rvv_vwmul_vx_m:
  ID = Intrinsic::riscv_vwmul_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  Ops.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops[2]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vwmulsu_vv:
case RISCVVector::BI__builtin_rvv_vwmulsu_vx:
  ID = Intrinsic::riscv_vwmulsu;
  IntrinsicTypes = {ResultType, Ops[0]->getType(), Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vwmulsu_vv_m:
case RISCVVector::BI__builtin_rvv_vwmulsu_vx_m:
  ID = Intrinsic::riscv_vwmulsu_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  Ops.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops[2]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vwmulu_vv:
case RISCVVector::BI__builtin_rvv_vwmulu_vx:
  ID = Intrinsic::riscv_vwmulu;
  IntrinsicTypes = {ResultType, Ops[0]->getType(), Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vwmulu_vv_m:
case RISCVVector::BI__builtin_rvv_vwmulu_vx_m:
  ID = Intrinsic::riscv_vwmulu_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  Ops.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops[2]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vwredsum_vs:
  ID = Intrinsic::riscv_vwredsum;
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vwredsum_vs_m:
  ID = Intrinsic::riscv_vwredsum_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vwredsumu_vs:
  ID = Intrinsic::riscv_vwredsumu;
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vwredsumu_vs_m:
  ID = Intrinsic::riscv_vwredsumu_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vwsub_vv:
case RISCVVector::BI__builtin_rvv_vwsub_vx:
  ID = Intrinsic::riscv_vwsub;
  IntrinsicTypes = {ResultType, Ops[0]->getType(), Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vwsub_vv_m:
case RISCVVector::BI__builtin_rvv_vwsub_vx_m:
  ID = Intrinsic::riscv_vwsub_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  Ops.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops[2]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vwsub_wv:
case RISCVVector::BI__builtin_rvv_vwsub_wx:
  ID = Intrinsic::riscv_vwsub_w;
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vwsub_wv_m:
case RISCVVector::BI__builtin_rvv_vwsub_wx_m:
  ID = Intrinsic::riscv_vwsub_w_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  Ops.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
  IntrinsicTypes = {ResultType, Ops[2]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vwsubu_vv:
case RISCVVector::BI__builtin_rvv_vwsubu_vx:
  ID = Intrinsic::riscv_vwsubu;
  IntrinsicTypes = {ResultType, Ops[0]->getType(), Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vwsubu_vv_m:
case RISCVVector::BI__builtin_rvv_vwsubu_vx_m:
  ID = Intrinsic::riscv_vwsubu_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  Ops.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops[2]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vwsubu_wv:
case RISCVVector::BI__builtin_rvv_vwsubu_wx:
  ID = Intrinsic::riscv_vwsubu_w;
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vwsubu_wv_m:
case RISCVVector::BI__builtin_rvv_vwsubu_wx_m:
  ID = Intrinsic::riscv_vwsubu_w_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  Ops.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
  IntrinsicTypes = {ResultType, Ops[2]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vxor_vv:
case RISCVVector::BI__builtin_rvv_vxor_vx:
  ID = Intrinsic::riscv_vxor;
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vnot_v:
  ID = Intrinsic::riscv_vxor;

      {
        // op1, vl
        IntrinsicTypes = {ResultType,
                          cast<llvm::VectorType>(ResultType)->getElementType(),
                          Ops[1]->getType()};
        Ops.insert(Ops.begin() + 1,
                   llvm::Constant::getAllOnesValue(IntrinsicTypes[1]));
        break;
      }
      break;
case RISCVVector::BI__builtin_rvv_vxor_vv_m:
case RISCVVector::BI__builtin_rvv_vxor_vx_m:
  ID = Intrinsic::riscv_vxor_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  Ops.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
  IntrinsicTypes = {ResultType, Ops[2]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vnot_v_m:
  ID = Intrinsic::riscv_vxor_mask;

      {
        std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
        Ops.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
        // maskedoff, op1, mask, vl
        IntrinsicTypes = {ResultType,
                          cast<llvm::VectorType>(ResultType)->getElementType(),
                          Ops[3]->getType()};
        Ops.insert(Ops.begin() + 2,
                   llvm::Constant::getAllOnesValue(IntrinsicTypes[1]));
        break;
      }
      break;
case RISCVVector::BI__builtin_rvv_vzext_vf2:
case RISCVVector::BI__builtin_rvv_vzext_vf4:
case RISCVVector::BI__builtin_rvv_vzext_vf8:
  ID = Intrinsic::riscv_vzext;
  IntrinsicTypes = {ResultType, Ops[0]->getType(), Ops.back()->getType()};
  break;
case RISCVVector::BI__builtin_rvv_vzext_vf2_m:
case RISCVVector::BI__builtin_rvv_vzext_vf4_m:
case RISCVVector::BI__builtin_rvv_vzext_vf8_m:
  ID = Intrinsic::riscv_vzext_mask;
  std::rotate(Ops.begin(), Ops.begin() + 1, Ops.end() - 1);
  Ops.push_back(ConstantInt::get(Ops.back()->getType(), TAIL_UNDISTURBED));
  IntrinsicTypes = {ResultType, Ops[1]->getType(), Ops.back()->getType()};
  break;

