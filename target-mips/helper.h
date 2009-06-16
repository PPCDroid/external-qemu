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
#define DEF_HELPER_1_0 DEF_HELPER
#define DEF_HELPER_1_1 DEF_HELPER
#define DEF_HELPER_1_2 DEF_HELPER
#define DEF_HELPER_1_3 DEF_HELPER
#define DEF_HELPER_1_4 DEF_HELPER
#define HELPER(x) glue(helper_,x)
#endif


DEF_HELPER_0_2(raise_exception_err, void, (uint32_t, int))
DEF_HELPER_0_1(raise_exception, void, (uint32_t))
DEF_HELPER_0_0(interrupt_restart, void, (void))

DEF_HELPER_1_3(lwl, uint32_t, (uint32_t, uint32_t, int))
DEF_HELPER_1_3(lwr, uint32_t, (uint32_t, uint32_t, int))
DEF_HELPER_0_3(swl, void, (uint32_t, uint32_t, int))
DEF_HELPER_0_3(swr, void, (uint32_t, uint32_t, int))

DEF_HELPER_1_1(clo, uint32_t, (uint32_t))
DEF_HELPER_1_1(clz, uint32_t, (uint32_t))

DEF_HELPER_1_2(muls, uint32_t, (uint32_t, uint32_t))
DEF_HELPER_1_2(mulsu, uint32_t, (uint32_t, uint32_t))
DEF_HELPER_1_2(macc, uint32_t, (uint32_t, uint32_t))
DEF_HELPER_1_2(maccu, uint32_t, (uint32_t, uint32_t))
DEF_HELPER_1_2(msac, uint32_t, (uint32_t, uint32_t))
DEF_HELPER_1_2(msacu, uint32_t, (uint32_t, uint32_t))
DEF_HELPER_1_2(mulhi, uint32_t, (uint32_t, uint32_t))
DEF_HELPER_1_2(mulhiu, uint32_t, (uint32_t, uint32_t))
DEF_HELPER_1_2(mulshi, uint32_t, (uint32_t, uint32_t))
DEF_HELPER_1_2(mulshiu, uint32_t, (uint32_t, uint32_t))
DEF_HELPER_1_2(macchi, uint32_t, (uint32_t, uint32_t))
DEF_HELPER_1_2(macchiu, uint32_t, (uint32_t, uint32_t))
DEF_HELPER_1_2(msachi, uint32_t, (uint32_t, uint32_t))
DEF_HELPER_1_2(msachiu, uint32_t, (uint32_t, uint32_t))

#ifndef CONFIG_USER_ONLY
/* CP0 helpers */
DEF_HELPER_1_0(mfc0_mvpcontrol, uint32_t, (void))
DEF_HELPER_1_0(mfc0_mvpconf0, uint32_t, (void))
DEF_HELPER_1_0(mfc0_mvpconf1, uint32_t, (void))
DEF_HELPER_1_0(mfc0_random, uint32_t, (void))
DEF_HELPER_1_0(mfc0_tcstatus, uint32_t, (void))
DEF_HELPER_1_0(mftc0_tcstatus, uint32_t, (void))
DEF_HELPER_1_0(mfc0_tcbind, uint32_t, (void))
DEF_HELPER_1_0(mftc0_tcbind, uint32_t, (void))
DEF_HELPER_1_0(mfc0_tcrestart, uint32_t, (void))
DEF_HELPER_1_0(mftc0_tcrestart, uint32_t, (void))
DEF_HELPER_1_0(mfc0_tchalt, uint32_t, (void))
DEF_HELPER_1_0(mftc0_tchalt, uint32_t, (void))
DEF_HELPER_1_0(mfc0_tccontext, uint32_t, (void))
DEF_HELPER_1_0(mftc0_tccontext, uint32_t, (void))
DEF_HELPER_1_0(mfc0_tcschedule, uint32_t, (void))
DEF_HELPER_1_0(mftc0_tcschedule, uint32_t, (void))
DEF_HELPER_1_0(mfc0_tcschefback, uint32_t, (void))
DEF_HELPER_1_0(mftc0_tcschefback, uint32_t, (void))
DEF_HELPER_1_0(mfc0_count, uint32_t, (void))
DEF_HELPER_1_0(mftc0_entryhi, uint32_t, (void))
DEF_HELPER_1_0(mftc0_status, uint32_t, (void))
DEF_HELPER_1_0(mfc0_lladdr, uint32_t, (void))
DEF_HELPER_1_1(mfc0_watchlo, target_ulong, (uint32_t))
DEF_HELPER_1_1(mfc0_watchhi, uint32_t, (uint32_t))
DEF_HELPER_1_0(mfc0_debug, uint32_t, (void))
DEF_HELPER_1_0(mftc0_debug, uint32_t, (void))

DEF_HELPER_0_1(mtc0_index, void, (uint32_t))
DEF_HELPER_0_1(mtc0_mvpcontrol, void, (uint32_t))
DEF_HELPER_0_1(mtc0_vpecontrol, void, (uint32_t))
DEF_HELPER_0_1(mtc0_vpeconf0, void, (uint32_t))
DEF_HELPER_0_1(mtc0_vpeconf1, void, (uint32_t))
DEF_HELPER_0_1(mtc0_yqmask, void, (uint32_t))
DEF_HELPER_0_1(mtc0_vpeopt, void, (uint32_t))
DEF_HELPER_0_1(mtc0_entrylo0, void, (uint32_t))
DEF_HELPER_0_1(mtc0_tcstatus, void, (uint32_t))
DEF_HELPER_0_1(mttc0_tcstatus, void, (uint32_t))
DEF_HELPER_0_1(mtc0_tcbind, void, (uint32_t))
DEF_HELPER_0_1(mttc0_tcbind, void, (uint32_t))
DEF_HELPER_0_1(mtc0_tcrestart, void, (uint32_t))
DEF_HELPER_0_1(mttc0_tcrestart, void, (uint32_t))
DEF_HELPER_0_1(mtc0_tchalt, void, (uint32_t))
DEF_HELPER_0_1(mttc0_tchalt, void, (uint32_t))
DEF_HELPER_0_1(mtc0_tccontext, void, (uint32_t))
DEF_HELPER_0_1(mttc0_tccontext, void, (uint32_t))
DEF_HELPER_0_1(mtc0_tcschedule, void, (uint32_t))
DEF_HELPER_0_1(mttc0_tcschedule, void, (uint32_t))
DEF_HELPER_0_1(mtc0_tcschefback, void, (uint32_t))
DEF_HELPER_0_1(mttc0_tcschefback, void, (uint32_t))
DEF_HELPER_0_1(mtc0_entrylo1, void, (uint32_t))
DEF_HELPER_0_1(mtc0_context, void, (uint32_t))
DEF_HELPER_0_1(mtc0_pagemask, void, (uint32_t))
DEF_HELPER_0_1(mtc0_pagegrain, void, (uint32_t))
DEF_HELPER_0_1(mtc0_wired, void, (uint32_t))
DEF_HELPER_0_1(mtc0_srsconf0, void, (uint32_t))
DEF_HELPER_0_1(mtc0_srsconf1, void, (uint32_t))
DEF_HELPER_0_1(mtc0_srsconf2, void, (uint32_t))
DEF_HELPER_0_1(mtc0_srsconf3, void, (uint32_t))
DEF_HELPER_0_1(mtc0_srsconf4, void, (uint32_t))
DEF_HELPER_0_1(mtc0_hwrena, void, (uint32_t))
DEF_HELPER_0_1(mtc0_count, void, (uint32_t))
DEF_HELPER_0_1(mtc0_entryhi, void, (uint32_t))
DEF_HELPER_0_1(mttc0_entryhi, void, (uint32_t))
DEF_HELPER_0_1(mtc0_compare, void, (target_ulong))
DEF_HELPER_0_1(mtc0_status, void, (target_ulong))
DEF_HELPER_0_1(mttc0_status, void, (uint32_t))
DEF_HELPER_0_1(mtc0_intctl, void, (target_ulong))
DEF_HELPER_0_1(mtc0_srsctl, void, (target_ulong))
DEF_HELPER_0_1(mtc0_cause, void, (uint32_t))
DEF_HELPER_0_1(mtc0_ebase, void, (uint32_t))
DEF_HELPER_0_1(mtc0_config0, void, (uint32_t))
DEF_HELPER_0_1(mtc0_config2, void, (uint32_t))
DEF_HELPER_0_2(mtc0_watchlo, void, (target_ulong, uint32_t))
DEF_HELPER_0_2(mtc0_watchhi, void, (target_ulong, uint32_t))
DEF_HELPER_0_1(mtc0_xcontext, void, (uint32_t))
DEF_HELPER_0_1(mtc0_framemask, void, (uint32_t))
DEF_HELPER_0_1(mtc0_debug, void, (uint32_t))
DEF_HELPER_0_1(mttc0_debug, void, (uint32_t))
DEF_HELPER_0_1(mtc0_performance0, void, (uint32_t))
DEF_HELPER_0_1(mtc0_taglo, void, (uint32_t))
DEF_HELPER_0_1(mtc0_datalo, void, (uint32_t))
DEF_HELPER_0_1(mtc0_taghi, void, (uint32_t))
DEF_HELPER_0_1(mtc0_datahi, void, (uint32_t))

/* MIPS MT functions */
DEF_HELPER_1_1(mftgpr, target_ulong, (uint32_t))
DEF_HELPER_1_1(mftlo, target_ulong, (uint32_t))
DEF_HELPER_1_1(mfthi, target_ulong, (uint32_t))
DEF_HELPER_1_1(mftacx, target_ulong, (uint32_t))
DEF_HELPER_1_0(mftdsp, uint32_t, (void))
DEF_HELPER_0_2(mttgpr, void, (target_ulong, uint32_t))
DEF_HELPER_0_2(mttlo, void, (target_ulong, uint32_t))
DEF_HELPER_0_2(mtthi, void, (target_ulong, uint32_t))
DEF_HELPER_0_2(mttacx, void, (target_ulong, uint32_t))
DEF_HELPER_0_1(mttdsp, void, (uint32_t))
DEF_HELPER_1_1(dmt, uint32_t, (uint32_t))
DEF_HELPER_1_1(emt, uint32_t, (uint32_t))
DEF_HELPER_1_1(dvpe, uint32_t, (uint32_t))
DEF_HELPER_1_1(evpe, uint32_t, (uint32_t))
#endif /* !CONFIG_USER_ONLY */
DEF_HELPER_0_2(fork, void, (uint32_t, uint32_t))
DEF_HELPER_1_1(yield, uint32_t, (uint32_t))

/* CP1 functions */
DEF_HELPER_1_1(cfc1, uint32_t, (uint32_t))
DEF_HELPER_0_2(ctc1, void, (target_ulong, uint32_t))

DEF_HELPER_1_1(float_cvtd_s, uint64_t, (uint32_t))
DEF_HELPER_1_1(float_cvtd_w, uint64_t, (uint32_t))
DEF_HELPER_1_1(float_cvtd_l, uint64_t, (uint64_t))
DEF_HELPER_1_1(float_cvtl_d, uint64_t, (uint64_t))
DEF_HELPER_1_1(float_cvtl_s, uint64_t, (uint32_t))
DEF_HELPER_1_1(float_cvtps_pw, uint64_t, (uint64_t))
DEF_HELPER_1_1(float_cvtpw_ps, uint64_t, (uint64_t))
DEF_HELPER_1_1(float_cvts_d, uint32_t, (uint64_t))
DEF_HELPER_1_1(float_cvts_w, uint32_t, (uint32_t))
DEF_HELPER_1_1(float_cvts_l, uint32_t, (uint64_t))
DEF_HELPER_1_1(float_cvts_pl, uint32_t, (uint32_t))
DEF_HELPER_1_1(float_cvts_pu, uint32_t, (uint32_t))
DEF_HELPER_1_1(float_cvtw_s, uint32_t, (uint32_t))
DEF_HELPER_1_1(float_cvtw_d, uint32_t, (uint64_t))

DEF_HELPER_1_2(float_addr_ps, uint64_t, (uint64_t, uint64_t))
DEF_HELPER_1_2(float_mulr_ps, uint64_t, (uint64_t, uint64_t))

#define FOP_PROTO(op)                       \
DEF_HELPER_1_1(float_ ## op ## l_s, uint64_t, (uint32_t)) \
DEF_HELPER_1_1(float_ ## op ## l_d, uint64_t, (uint64_t)) \
DEF_HELPER_1_1(float_ ## op ## w_s, uint32_t, (uint32_t)) \
DEF_HELPER_1_1(float_ ## op ## w_d, uint32_t, (uint64_t))
FOP_PROTO(round)
FOP_PROTO(trunc)
FOP_PROTO(ceil)
FOP_PROTO(floor)
#undef FOP_PROTO

#define FOP_PROTO(op)                       \
DEF_HELPER_1_1(float_ ## op ## _s, uint32_t, (uint32_t))  \
DEF_HELPER_1_1(float_ ## op ## _d, uint64_t, (uint64_t))
FOP_PROTO(sqrt)
FOP_PROTO(rsqrt)
FOP_PROTO(recip)
#undef FOP_PROTO

#define FOP_PROTO(op)                       \
DEF_HELPER_1_1(float_ ## op ## _s, uint32_t, (uint32_t))  \
DEF_HELPER_1_1(float_ ## op ## _d, uint64_t, (uint64_t))  \
DEF_HELPER_1_1(float_ ## op ## _ps, uint64_t, (uint64_t))
FOP_PROTO(abs)
FOP_PROTO(chs)
FOP_PROTO(recip1)
FOP_PROTO(rsqrt1)
#undef FOP_PROTO

#define FOP_PROTO(op)                             \
DEF_HELPER_1_2(float_ ## op ## _s, uint32_t, (uint32_t, uint32_t))   \
DEF_HELPER_1_2(float_ ## op ## _d, uint64_t, (uint64_t, uint64_t))   \
DEF_HELPER_1_2(float_ ## op ## _ps, uint64_t, (uint64_t, uint64_t))
FOP_PROTO(add)
FOP_PROTO(sub)
FOP_PROTO(mul)
FOP_PROTO(div)
FOP_PROTO(recip2)
FOP_PROTO(rsqrt2)
#undef FOP_PROTO

#define FOP_PROTO(op)                                 \
DEF_HELPER_1_3(float_ ## op ## _s, uint32_t, (uint32_t, uint32_t, uint32_t))  \
DEF_HELPER_1_3(float_ ## op ## _d, uint64_t, (uint64_t, uint64_t, uint64_t))  \
DEF_HELPER_1_3(float_ ## op ## _ps, uint64_t, (uint64_t, uint64_t, uint64_t))
FOP_PROTO(muladd)
FOP_PROTO(mulsub)
FOP_PROTO(nmuladd)
FOP_PROTO(nmulsub)
#undef FOP_PROTO

#define FOP_PROTO(op)                               \
DEF_HELPER_0_3(cmp_d_ ## op, void, (uint64_t, uint64_t, int))     \
DEF_HELPER_0_3(cmpabs_d_ ## op, void, (uint64_t, uint64_t, int))  \
DEF_HELPER_0_3(cmp_s_ ## op, void, (uint32_t, uint32_t, int))     \
DEF_HELPER_0_3(cmpabs_s_ ## op, void, (uint32_t, uint32_t, int))  \
DEF_HELPER_0_3(cmp_ps_ ## op, void, (uint64_t, uint64_t, int))    \
DEF_HELPER_0_3(cmpabs_ps_ ## op, void, (uint64_t, uint64_t, int))
FOP_PROTO(f)
FOP_PROTO(un)
FOP_PROTO(eq)
FOP_PROTO(ueq)
FOP_PROTO(olt)
FOP_PROTO(ult)
FOP_PROTO(ole)
FOP_PROTO(ule)
FOP_PROTO(sf)
FOP_PROTO(ngle)
FOP_PROTO(seq)
FOP_PROTO(ngl)
FOP_PROTO(lt)
FOP_PROTO(nge)
FOP_PROTO(le)
FOP_PROTO(ngt)
#undef FOP_PROTO

/* Special functions */
#ifndef CONFIG_USER_ONLY
DEF_HELPER_0_0(tlbwi, void, (void))
DEF_HELPER_0_0(tlbwr, void, (void))
DEF_HELPER_0_0(tlbp, void, (void))
DEF_HELPER_0_0(tlbr, void, (void))
DEF_HELPER_1_0(di, uint32_t, (void))
DEF_HELPER_1_0(ei, uint32_t, (void))
DEF_HELPER_0_0(eret, void, (void))
DEF_HELPER_0_0(deret, void, (void))
#endif /* !CONFIG_USER_ONLY */
DEF_HELPER_1_0(rdhwr_cpunum, uint32_t, (void))
DEF_HELPER_1_0(rdhwr_synci_step, uint32_t, (void))
DEF_HELPER_1_0(rdhwr_cc, uint32_t, (void))
DEF_HELPER_1_0(rdhwr_ccres, uint32_t, (void))
DEF_HELPER_0_1(pmon, void, (int))
DEF_HELPER_0_0(wait, void, (void))

