#define DEF_HELPER(name, ret, args) ret glue(helper_,name) args;

#ifdef GEN_HELPER
#define DEF_HELPER_0_0(name, ret, args) \
DEF_HELPER(name, ret, args) \
static inline void gen_helper_##name(void) \
{ \
    tcg_gen_helper_0_0(helper_##name); \
}
#define DEF_HELPER_0_1(name, ret, args) \
DEF_HELPER(name, ret, args) \
static inline void gen_helper_##name(TCGv arg1) \
{ \
    tcg_gen_helper_0_1(helper_##name, arg1); \
}
#define DEF_HELPER_0_2(name, ret, args) \
DEF_HELPER(name, ret, args) \
static inline void gen_helper_##name(TCGv arg1, TCGv arg2) \
{ \
    tcg_gen_helper_0_2(helper_##name, arg1, arg2); \
}
#define DEF_HELPER_0_3(name, ret, args) \
DEF_HELPER(name, ret, args) \
static inline void gen_helper_##name( \
    TCGv arg1, TCGv arg2, TCGv arg3) \
{ \
    tcg_gen_helper_0_3(helper_##name, arg1, arg2, arg3); \
}
#define DEF_HELPER_0_4(name, ret, args) \
DEF_HELPER(name, ret, args) \
static inline void gen_helper_##name( \
    TCGv arg1, TCGv arg2, TCGv arg3, TCGv arg4) \
{ \
    tcg_gen_helper_0_4(helper_##name, arg1, arg2, arg3, arg4); \
}
#define DEF_HELPER_1_0(name, ret, args) \
DEF_HELPER(name, ret, args) \
static inline void gen_helper_##name(TCGv ret) \
{ \
    tcg_gen_helper_1_0(helper_##name, ret); \
}
#define DEF_HELPER_1_1(name, ret, args) \
DEF_HELPER(name, ret, args) \
static inline void gen_helper_##name(TCGv ret, TCGv arg1) \
{ \
    tcg_gen_helper_1_1(helper_##name, ret, arg1); \
}
#define DEF_HELPER_1_2(name, ret, args) \
DEF_HELPER(name, ret, args) \
static inline void gen_helper_##name(TCGv ret, TCGv arg1, TCGv arg2) \
{ \
    tcg_gen_helper_1_2(helper_##name, ret, arg1, arg2); \
}
#define DEF_HELPER_1_3(name, ret, args) \
DEF_HELPER(name, ret, args) \
static inline void gen_helper_##name(TCGv ret, \
    TCGv arg1, TCGv arg2, TCGv arg3) \
{ \
    tcg_gen_helper_1_3(helper_##name, ret, arg1, arg2, arg3); \
}
#define DEF_HELPER_1_4(name, ret, args) \
DEF_HELPER(name, ret, args) \
static inline void gen_helper_##name(TCGv ret, \
    TCGv arg1, TCGv arg2, TCGv arg3, TCGv arg4) \
{ \
    tcg_gen_helper_1_4(helper_##name, ret, arg1, arg2, arg3, arg4); \
}
#else /* !GEN_HELPER */
#define DEF_HELPER_0_0 DEF_HELPER
#define DEF_HELPER_0_1 DEF_HELPER
#define DEF_HELPER_0_2 DEF_HELPER
#define DEF_HELPER_0_3 DEF_HELPER
#define DEF_HELPER_0_4 DEF_HELPER
#define DEF_HELPER_1_0 DEF_HELPER
#define DEF_HELPER_1_1 DEF_HELPER
#define DEF_HELPER_1_2 DEF_HELPER
#define DEF_HELPER_1_3 DEF_HELPER
#define DEF_HELPER_1_4 DEF_HELPER
#define HELPER(x) glue(helper_,x)
#endif


DEF_HELPER_0_2(raise_exception_err, void, (uint32_t, uint32_t))
DEF_HELPER_0_1(raise_exception, void, (uint32_t))
DEF_HELPER_0_3(tw, void, (target_ulong, target_ulong, uint32_t))
#if defined(TARGET_PPC64)
DEF_HELPER_0_3(td, void, (target_ulong, target_ulong, uint32_t))
#endif
#if !defined(CONFIG_USER_ONLY)
DEF_HELPER_0_1(store_msr, void, (target_ulong))
DEF_HELPER_0_0(rfi, void, (void))
DEF_HELPER_0_0(rfsvc, void, (void))
DEF_HELPER_0_0(40x_rfci, void, (void))
DEF_HELPER_0_0(rfci, void, (void))
DEF_HELPER_0_0(rfdi, void, (void))
DEF_HELPER_0_0(rfmci, void, (void))
#if defined(TARGET_PPC64)
DEF_HELPER_0_0(rfid, void, (void))
DEF_HELPER_0_0(hrfid, void, (void))
#endif
#endif

DEF_HELPER_0_2(lmw, void, (target_ulong, uint32_t))
DEF_HELPER_0_2(stmw, void, (target_ulong, uint32_t))
DEF_HELPER_0_3(lsw, void, (target_ulong, uint32_t, uint32_t))
DEF_HELPER_0_4(lswx, void, (target_ulong, uint32_t, uint32_t, uint32_t))
DEF_HELPER_0_3(stsw, void, (target_ulong, uint32_t, uint32_t))
DEF_HELPER_0_1(dcbz, void, (target_ulong))
DEF_HELPER_0_1(dcbz_970, void, (target_ulong))
DEF_HELPER_0_1(icbi, void, (target_ulong))
DEF_HELPER_1_4(lscbx, target_ulong, (target_ulong, uint32_t, uint32_t, uint32_t))

DEF_HELPER_1_0(load_cr, target_ulong, (void))
DEF_HELPER_0_2(store_cr, void, (target_ulong, uint32_t))

#if defined(TARGET_PPC64)
DEF_HELPER_1_2(mulhd, uint64_t, (uint64_t, uint64_t))
DEF_HELPER_1_2(mulhdu, uint64_t, (uint64_t, uint64_t))
DEF_HELPER_1_2(mulldo, uint64_t, (uint64_t, uint64_t))
#endif

DEF_HELPER_1_1(cntlzw, target_ulong, (target_ulong))
DEF_HELPER_1_1(popcntb, target_ulong, (target_ulong))
DEF_HELPER_1_2(sraw, target_ulong, (target_ulong, target_ulong))
#if defined(TARGET_PPC64)
DEF_HELPER_1_1(cntlzd, target_ulong, (target_ulong))
DEF_HELPER_1_1(popcntb_64, target_ulong, (target_ulong))
DEF_HELPER_1_2(srad, target_ulong, (target_ulong, target_ulong))
#endif

DEF_HELPER_1_1(cntlsw32, uint32_t, (uint32_t))
DEF_HELPER_1_1(cntlzw32, uint32_t, (uint32_t))
DEF_HELPER_1_2(brinc, target_ulong, (target_ulong, target_ulong))

DEF_HELPER_0_0(float_check_status, void, (void))
#ifdef CONFIG_SOFTFLOAT
DEF_HELPER_0_0(reset_fpstatus, void, (void))
#endif
DEF_HELPER_1_2(compute_fprf, uint32_t, (uint64_t, uint32_t))
DEF_HELPER_0_2(store_fpscr, void, (uint64_t, uint32_t))
DEF_HELPER_0_1(fpscr_clrbit, void, (uint32_t))
DEF_HELPER_0_1(fpscr_setbit, void, (uint32_t))
DEF_HELPER_1_1(float64_to_float32, uint32_t, (uint64_t))
DEF_HELPER_1_1(float32_to_float64, uint64_t, (uint32_t))

DEF_HELPER_0_3(fcmpo, void, (uint64_t, uint64_t, uint32_t))
DEF_HELPER_0_3(fcmpu, void, (uint64_t, uint64_t, uint32_t))

DEF_HELPER_1_1(fctiw, uint64_t, (uint64_t))
DEF_HELPER_1_1(fctiwz, uint64_t, (uint64_t))
#if defined(TARGET_PPC64)
DEF_HELPER_1_1(fcfid, uint64_t, (uint64_t))
DEF_HELPER_1_1(fctid, uint64_t, (uint64_t))
DEF_HELPER_1_1(fctidz, uint64_t, (uint64_t))
#endif
DEF_HELPER_1_1(frsp, uint64_t, (uint64_t))
DEF_HELPER_1_1(frin, uint64_t, (uint64_t))
DEF_HELPER_1_1(friz, uint64_t, (uint64_t))
DEF_HELPER_1_1(frip, uint64_t, (uint64_t))
DEF_HELPER_1_1(frim, uint64_t, (uint64_t))

DEF_HELPER_1_2(fadd, uint64_t, (uint64_t, uint64_t))
DEF_HELPER_1_2(fsub, uint64_t, (uint64_t, uint64_t))
DEF_HELPER_1_2(fmul, uint64_t, (uint64_t, uint64_t))
DEF_HELPER_1_2(fdiv, uint64_t, (uint64_t, uint64_t))
DEF_HELPER_1_3(fmadd, uint64_t, (uint64_t, uint64_t, uint64_t))
DEF_HELPER_1_3(fmsub, uint64_t, (uint64_t, uint64_t, uint64_t))
DEF_HELPER_1_3(fnmadd, uint64_t, (uint64_t, uint64_t, uint64_t))
DEF_HELPER_1_3(fnmsub, uint64_t, (uint64_t, uint64_t, uint64_t))
DEF_HELPER_1_1(fabs, uint64_t, (uint64_t))
DEF_HELPER_1_1(fnabs, uint64_t, (uint64_t))
DEF_HELPER_1_1(fneg, uint64_t, (uint64_t))
DEF_HELPER_1_1(fsqrt, uint64_t, (uint64_t))
DEF_HELPER_1_1(fre, uint64_t, (uint64_t))
DEF_HELPER_1_1(fres, uint64_t, (uint64_t))
DEF_HELPER_1_1(frsqrte, uint64_t, (uint64_t))
DEF_HELPER_1_3(fsel, uint64_t, (uint64_t, uint64_t, uint64_t))

#define dh_alias_avr ptr
#define dh_ctype_avr ppc_avr_t *

DEF_HELPER_0_3(vaddubm, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_3(vadduhm, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_3(vadduwm, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_3(vsububm, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_3(vsubuhm, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_3(vsubuwm, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_3(vavgub, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_3(vavguh, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_3(vavguw, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_3(vavgsb, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_3(vavgsh, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_3(vavgsw, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_3(vminsb, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_3(vminsh, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_3(vminsw, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_3(vmaxsb, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_3(vmaxsh, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_3(vmaxsw, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_3(vminub, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_3(vminuh, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_3(vminuw, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_3(vmaxub, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_3(vmaxuh, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_3(vmaxuw, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_3(vcmpequb, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_3(vcmpequh, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_3(vcmpequw, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_3(vcmpgtub, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_3(vcmpgtuh, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_3(vcmpgtuw, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_3(vcmpgtsb, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_3(vcmpgtsh, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_3(vcmpgtsw, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_3(vcmpeqfp, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_3(vcmpgefp, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_3(vcmpgtfp, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_3(vcmpbfp, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_3(vcmpequb_dot, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_3(vcmpequh_dot, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_3(vcmpequw_dot, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_3(vcmpgtub_dot, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_3(vcmpgtuh_dot, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_3(vcmpgtuw_dot, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_3(vcmpgtsb_dot, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_3(vcmpgtsh_dot, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_3(vcmpgtsw_dot, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_3(vcmpeqfp_dot, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_3(vcmpgefp_dot, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_3(vcmpgtfp_dot, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_3(vcmpbfp_dot, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_3(vmrglb, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_3(vmrglh, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_3(vmrglw, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_3(vmrghb, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_3(vmrghh, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_3(vmrghw, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_3(vmulesb, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_3(vmulesh, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_3(vmuleub, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_3(vmuleuh, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_3(vmulosb, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_3(vmulosh, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_3(vmuloub, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_3(vmulouh, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_3(vsrab, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_3(vsrah, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_3(vsraw, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_3(vsrb, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_3(vsrh, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_3(vsrw, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_3(vslb, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_3(vslh, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_3(vslw, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_3(vslo, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_3(vsro, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_3(vaddcuw, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_3(vsubcuw, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_2(lvsl, void, (ppc_avr_t *, target_ulong));
DEF_HELPER_0_2(lvsr, void, (ppc_avr_t *, target_ulong));
DEF_HELPER_0_3(vaddsbs, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_3(vaddshs, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_3(vaddsws, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_3(vsubsbs, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_3(vsubshs, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_3(vsubsws, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_3(vaddubs, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_3(vadduhs, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_3(vadduws, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_3(vsububs, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_3(vsubuhs, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_3(vsubuws, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_3(vrlb, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_3(vrlh, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_3(vrlw, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_3(vsl, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_3(vsr, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_4(vsldoi, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *, uint32_t))
DEF_HELPER_0_2(vspltisb, void, (ppc_avr_t *, uint32_t))
DEF_HELPER_0_2(vspltish, void, (ppc_avr_t *, uint32_t))
DEF_HELPER_0_2(vspltisw, void, (ppc_avr_t *, uint32_t))
DEF_HELPER_0_3(vspltb, void, (ppc_avr_t *, ppc_avr_t *, uint32_t))
DEF_HELPER_0_3(vsplth, void, (ppc_avr_t *, ppc_avr_t *, uint32_t))
DEF_HELPER_0_3(vspltw, void, (ppc_avr_t *, ppc_avr_t *, uint32_t))
DEF_HELPER_0_2(vupkhpx, void, (ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_2(vupklpx, void, (ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_2(vupkhsb, void, (ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_2(vupkhsh, void, (ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_2(vupklsb, void, (ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_2(vupklsh, void, (ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_4(vmsumubm, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_4(vmsummbm, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_4(vsel, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_4(vperm, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_3(vpkshss, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_3(vpkshus, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_3(vpkswss, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_3(vpkswus, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_3(vpkuhus, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_3(vpkuwus, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_3(vpkuhum, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_3(vpkuwum, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_3(vpkpx, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_4(vmhaddshs, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_4(vmhraddshs, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_4(vmsumuhm, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_4(vmsumuhs, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_4(vmsumshm, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_4(vmsumshs, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_4(vmladduhm, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_1(mtvscr, void, (ppc_avr_t *))
DEF_HELPER_0_2(lvebx, void, (ppc_avr_t *, target_ulong))
DEF_HELPER_0_2(lvehx, void, (ppc_avr_t *, target_ulong))
DEF_HELPER_0_2(lvewx, void, (ppc_avr_t *, target_ulong))
DEF_HELPER_0_2(stvebx, void, (ppc_avr_t *, target_ulong))
DEF_HELPER_0_2(stvehx, void, (ppc_avr_t *, target_ulong))
DEF_HELPER_0_2(stvewx, void, (ppc_avr_t *, target_ulong))
DEF_HELPER_0_3(vsumsws, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_3(vsum2sws, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_3(vsum4sbs, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_3(vsum4shs, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_3(vsum4ubs, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_3(vaddfp, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_3(vsubfp, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_3(vmaxfp, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_3(vminfp, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_2(vrefp, void, (ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_2(vrsqrtefp, void, (ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_4(vmaddfp, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_4(vnmsubfp, void, (ppc_avr_t *, ppc_avr_t *, ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_2(vlogefp, void, (ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_2(vrfim, void, (ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_2(vrfin, void, (ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_2(vrfip, void, (ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_2(vrfiz, void, (ppc_avr_t *, ppc_avr_t *))
DEF_HELPER_0_3(vcfux, void, (ppc_avr_t *, ppc_avr_t *, uint32_t))
DEF_HELPER_0_3(vcfsx, void, (ppc_avr_t *, ppc_avr_t *, uint32_t))
DEF_HELPER_0_3(vctuxs, void, (ppc_avr_t *, ppc_avr_t *, uint32_t))
DEF_HELPER_0_3(vctsxs, void, (ppc_avr_t *, ppc_avr_t *, uint32_t))

DEF_HELPER_1_1(efscfsi, uint32_t, (uint32_t))
DEF_HELPER_1_1(efscfui, uint32_t, (uint32_t))
DEF_HELPER_1_1(efscfuf, uint32_t, (uint32_t))
DEF_HELPER_1_1(efscfsf, uint32_t, (uint32_t))
DEF_HELPER_1_1(efsctsi, uint32_t, (uint32_t))
DEF_HELPER_1_1(efsctui, uint32_t, (uint32_t))
DEF_HELPER_1_1(efsctsiz, uint32_t, (uint32_t))
DEF_HELPER_1_1(efsctuiz, uint32_t, (uint32_t))
DEF_HELPER_1_1(efsctsf, uint32_t, (uint32_t))
DEF_HELPER_1_1(efsctuf, uint32_t, (uint32_t))
DEF_HELPER_1_1(evfscfsi, uint64_t, (uint64_t))
DEF_HELPER_1_1(evfscfui, uint64_t, (uint64_t))
DEF_HELPER_1_1(evfscfuf, uint64_t, (uint64_t))
DEF_HELPER_1_1(evfscfsf, uint64_t, (uint64_t))
DEF_HELPER_1_1(evfsctsi, uint64_t, (uint64_t))
DEF_HELPER_1_1(evfsctui, uint64_t, (uint64_t))
DEF_HELPER_1_1(evfsctsiz, uint64_t, (uint64_t))
DEF_HELPER_1_1(evfsctuiz, uint64_t, (uint64_t))
DEF_HELPER_1_1(evfsctsf, uint64_t, (uint64_t))
DEF_HELPER_1_1(evfsctuf, uint64_t, (uint64_t))
DEF_HELPER_1_2(efsadd, uint32_t, (uint32_t, uint32_t))
DEF_HELPER_1_2(efssub, uint32_t, (uint32_t, uint32_t))
DEF_HELPER_1_2(efsmul, uint32_t, (uint32_t, uint32_t))
DEF_HELPER_1_2(efsdiv, uint32_t, (uint32_t, uint32_t))
DEF_HELPER_1_2(evfsadd, uint64_t, (uint64_t, uint64_t))
DEF_HELPER_1_2(evfssub, uint64_t, (uint64_t, uint64_t))
DEF_HELPER_1_2(evfsmul, uint64_t, (uint64_t, uint64_t))
DEF_HELPER_1_2(evfsdiv, uint64_t, (uint64_t, uint64_t))
DEF_HELPER_1_2(efststlt, uint32_t, (uint32_t, uint32_t))
DEF_HELPER_1_2(efststgt, uint32_t, (uint32_t, uint32_t))
DEF_HELPER_1_2(efststeq, uint32_t, (uint32_t, uint32_t))
DEF_HELPER_1_2(efscmplt, uint32_t, (uint32_t, uint32_t))
DEF_HELPER_1_2(efscmpgt, uint32_t, (uint32_t, uint32_t))
DEF_HELPER_1_2(efscmpeq, uint32_t, (uint32_t, uint32_t))
DEF_HELPER_1_2(evfststlt, uint32_t, (uint64_t, uint64_t))
DEF_HELPER_1_2(evfststgt, uint32_t, (uint64_t, uint64_t))
DEF_HELPER_1_2(evfststeq, uint32_t, (uint64_t, uint64_t))
DEF_HELPER_1_2(evfscmplt, uint32_t, (uint64_t, uint64_t))
DEF_HELPER_1_2(evfscmpgt, uint32_t, (uint64_t, uint64_t))
DEF_HELPER_1_2(evfscmpeq, uint32_t, (uint64_t, uint64_t))
DEF_HELPER_1_1(efdcfsi, uint64_t, (uint32_t))
DEF_HELPER_1_1(efdcfsid, uint64_t, (uint64_t))
DEF_HELPER_1_1(efdcfui, uint64_t, (uint32_t))
DEF_HELPER_1_1(efdcfuid, uint64_t, (uint64_t))
DEF_HELPER_1_1(efdctsi, uint32_t, (uint64_t))
DEF_HELPER_1_1(efdctui, uint32_t, (uint64_t))
DEF_HELPER_1_1(efdctsiz, uint32_t, (uint64_t))
DEF_HELPER_1_1(efdctsidz, uint64_t, (uint64_t))
DEF_HELPER_1_1(efdctuiz, uint32_t, (uint64_t))
DEF_HELPER_1_1(efdctuidz, uint64_t, (uint64_t))
DEF_HELPER_1_1(efdcfsf, uint64_t, (uint32_t))
DEF_HELPER_1_1(efdcfuf, uint64_t, (uint32_t))
DEF_HELPER_1_1(efdctsf, uint32_t, (uint64_t))
DEF_HELPER_1_1(efdctuf, uint32_t, (uint64_t))
DEF_HELPER_1_1(efscfd, uint32_t, (uint64_t))
DEF_HELPER_1_1(efdcfs, uint64_t, (uint32_t))
DEF_HELPER_1_2(efdadd, uint64_t, (uint64_t, uint64_t))
DEF_HELPER_1_2(efdsub, uint64_t, (uint64_t, uint64_t))
DEF_HELPER_1_2(efdmul, uint64_t, (uint64_t, uint64_t))
DEF_HELPER_1_2(efddiv, uint64_t, (uint64_t, uint64_t))
DEF_HELPER_1_2(efdtstlt, uint32_t, (uint64_t, uint64_t))
DEF_HELPER_1_2(efdtstgt, uint32_t, (uint64_t, uint64_t))
DEF_HELPER_1_2(efdtsteq, uint32_t, (uint64_t, uint64_t))
DEF_HELPER_1_2(efdcmplt, uint32_t, (uint64_t, uint64_t))
DEF_HELPER_1_2(efdcmpgt, uint32_t, (uint64_t, uint64_t))
DEF_HELPER_1_2(efdcmpeq, uint32_t, (uint64_t, uint64_t))

#if !defined(CONFIG_USER_ONLY)
DEF_HELPER_1_1(4xx_tlbre_hi, target_ulong, (target_ulong))
DEF_HELPER_1_1(4xx_tlbre_lo, target_ulong, (target_ulong))
DEF_HELPER_0_2(4xx_tlbwe_hi, void, (target_ulong, target_ulong))
DEF_HELPER_0_2(4xx_tlbwe_lo, void, (target_ulong, target_ulong))
DEF_HELPER_1_1(4xx_tlbsx, target_ulong, (target_ulong))
DEF_HELPER_1_2(440_tlbre, target_ulong, (uint32_t, target_ulong))
DEF_HELPER_0_3(440_tlbwe, void, (uint32_t, target_ulong, target_ulong))
DEF_HELPER_1_1(440_tlbsx, target_ulong, (target_ulong))
DEF_HELPER_0_1(6xx_tlbd, void, (target_ulong))
DEF_HELPER_0_1(6xx_tlbi, void, (target_ulong))
DEF_HELPER_0_1(74xx_tlbd, void, (target_ulong))
DEF_HELPER_0_1(74xx_tlbi, void, (target_ulong))
DEF_HELPER_0_0(tlbia, void, (void))
DEF_HELPER_0_1(tlbie, void, (target_ulong))
#if defined(TARGET_PPC64)
DEF_HELPER_1_1(load_slb, target_ulong, (target_ulong))
DEF_HELPER_0_2(store_slb, void, (target_ulong, target_ulong))
DEF_HELPER_0_0(slbia, void, (void))
DEF_HELPER_0_1(slbie, void, (target_ulong))
#endif
DEF_HELPER_1_1(load_sr, target_ulong, (target_ulong))
DEF_HELPER_0_2(store_sr, void, (target_ulong, target_ulong))

DEF_HELPER_1_1(602_mfrom, target_ulong, (target_ulong))
#endif

DEF_HELPER_1_3(dlmzb, target_ulong, (target_ulong, target_ulong, uint32_t))
DEF_HELPER_1_1(clcs, target_ulong, (uint32_t))
#if !defined(CONFIG_USER_ONLY)
DEF_HELPER_1_1(rac, target_ulong, (target_ulong))
#endif
DEF_HELPER_1_2(div, target_ulong, (target_ulong, target_ulong))
DEF_HELPER_1_2(divo, target_ulong, (target_ulong, target_ulong))
DEF_HELPER_1_2(divs, target_ulong, (target_ulong, target_ulong))
DEF_HELPER_1_2(divso, target_ulong, (target_ulong, target_ulong))

DEF_HELPER_1_1(load_dcr, target_ulong, (target_ulong))
DEF_HELPER_0_2(store_dcr, void, (target_ulong, target_ulong))

DEF_HELPER_0_1(load_dump_spr, void, (uint32_t))
DEF_HELPER_0_1(store_dump_spr, void, (uint32_t))
DEF_HELPER_1_0(load_tbl, target_ulong, (void))
DEF_HELPER_1_0(load_tbu, target_ulong, (void))
DEF_HELPER_1_0(load_atbl, target_ulong, (void))
DEF_HELPER_1_0(load_atbu, target_ulong, (void))
DEF_HELPER_1_0(load_601_rtcl, target_ulong, (void))
DEF_HELPER_1_0(load_601_rtcu, target_ulong, (void))
#if !defined(CONFIG_USER_ONLY)
#if defined(TARGET_PPC64)
DEF_HELPER_0_1(store_asr, void, (target_ulong))
#endif
DEF_HELPER_0_1(store_sdr1, void, (target_ulong))
DEF_HELPER_0_1(store_tbl, void, (target_ulong))
DEF_HELPER_0_1(store_tbu, void, (target_ulong))
DEF_HELPER_0_1(store_atbl, void, (target_ulong))
DEF_HELPER_0_1(store_atbu, void, (target_ulong))
DEF_HELPER_0_1(store_601_rtcl, void, (target_ulong))
DEF_HELPER_0_1(store_601_rtcu, void, (target_ulong))
DEF_HELPER_1_0(load_decr, target_ulong, (void))
DEF_HELPER_0_1(store_decr, void, (target_ulong))
DEF_HELPER_0_1(store_hid0_601, void, (target_ulong))
DEF_HELPER_0_2(store_403_pbr, void, (uint32_t, target_ulong))
DEF_HELPER_1_0(load_40x_pit, target_ulong, (void))
DEF_HELPER_0_1(store_40x_pit, void, (target_ulong))
DEF_HELPER_0_1(store_40x_dbcr0, void, (target_ulong))
DEF_HELPER_0_1(store_40x_sler, void, (target_ulong))
DEF_HELPER_0_1(store_booke_tcr, void, (target_ulong))
DEF_HELPER_0_1(store_booke_tsr, void, (target_ulong))
DEF_HELPER_0_2(store_ibatl, void, (uint32_t, target_ulong))
DEF_HELPER_0_2(store_ibatu, void, (uint32_t, target_ulong))
DEF_HELPER_0_2(store_dbatl, void, (uint32_t, target_ulong))
DEF_HELPER_0_2(store_dbatu, void, (uint32_t, target_ulong))
DEF_HELPER_0_2(store_601_batl, void, (uint32_t, target_ulong))
DEF_HELPER_0_2(store_601_batu, void, (uint32_t, target_ulong))
#endif

#undef DEF_HELPER
#undef DEF_HELPER_0_0
#undef DEF_HELPER_0_1
#undef DEF_HELPER_0_2
#undef DEF_HELPER_0_3
#undef DEF_HELPER_0_4
#undef DEF_HELPER_1_0
#undef DEF_HELPER_1_1
#undef DEF_HELPER_1_2
#undef DEF_HELPER_1_3
#undef DEF_HELPER_1_4
#undef GEN_HELPER
