/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS, " AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
* PROJECT     : CCFC2016BC
* DESCRIPTION : CCFC2016BC e200z7 ASM handler code
* HISTORY     : Initial version.
* @file     e200z7_asm.h
* @version  1.1
* @date     2023 - 02 - 15
* @brief    Initial version.
*
*****************************************************************************/

#ifndef E200Z7_ASM_H
#define E200Z7_ASM_H

#ifdef __cplusplus
extern "C" {
#endif

/************************************************************************
 *    Machine State Register (MSR)
 *    Configuration parameter
 ************************************************************************/
/* User cache lock enable. (Implemented, but ignored by e200z7) */
#define MSR_UCLE    0x04000000U
/* SPE available */
#define MSR_SPE     0x02000000U
/* Wait state (power management) enable.
 * Defined as optional by Book E and implemented in the e200z7. */
#define MSR_WE      0x00040000U
/* Critical interrupt enable */
#define MSR_CE      0x00020000U
/* External interrupt enable */
#define MSR_EE      0x00008000U
/* Problem state */
#define MSR_PR      0x00004000U
/* Floating - point available */
#define MSR_FP      0x00002000U
/* Machine check enable */
#define MSR_ME      0x00001000U
/* Floating - point exception mode 0 (not used by the e200z7) */
#define MSR_FE0     0x00000800U
/* Debug interrupt enable */
#define MSR_DE      0x00000400U
/* Floating - point exception mode 1 (not used by the e200z7) */
#define MSR_FE1     0x00000200U
/* Instruction address space */
#define MSR_IS      0x00000040U
/* Data address space */
#define MSR_DS      0x00000020U
/* Recoverable Interrupt (e200z335 only) */
#define MSR_RI      0x00000002U

/* Disable EE (only set MSR EE bit) */
#define DIS_MSR_EE()    asm volatile("wrteei  0")
/* Enable EE (only set MSR EE bit) */
#define EN_MSR_EE()     asm volatile("wrteei  1")

/************************************************************************
 *    This function is used as default ASM handler
 *    From ppclib.h
 ************************************************************************/

/* insert a no - operation instruction */
#define NOP asm volatile("nop" : :)

/* insert 10 no - operation instructions */
#define NOP10 NOP; NOP; NOP; NOP; NOP; \
              NOP; NOP; NOP; NOP; NOP

/* store a word $data to $addr */
#define STW(data,addr) asm volatile("stwx %0,0,%1"::"r"(data),"r"(addr))

/* load a word $data from $addr */
#define LDW(data,addr) asm volatile("lwzx %0,0,%1":"=r"(data):"r"(addr))

/* store a byte $data to $addr */
#define STB(data,addr) asm volatile("stbx %0,0,%1"::"r"(data),"r"(addr))

/* load a byte $data from $addr */
#define LDB(data,addr) asm volatile("lbzx %0,0,%1":"=r"(data):"r"(addr))

/* store a halfword $data to $addr */
#define STH(data,addr) asm volatile("sthx %0,0,%1"::"r"(data),"r"(addr))

/* load a halfword $data from $addr */
#define LDH(data,addr) asm volatile("lhzx %0,0,%1":"=r"(data):"r"(addr))

/* store a word $data to $addr+bias */
#define STWZ(data,addr,bias) asm volatile("stw %0,%1(%2)"::"r"(data),"n"(bias),"b"(addr))

/* load a word $data from $addr+bias */
#define LWZ(data,addr,bias) asm volatile("lwz %0,%1(%2)":"=r"(data):"n"(bias),"b"(addr))

/* atom store (store word conditional indexed) */
#define STWCX(data,addr) asm volatile("stwcx. %0,0,%1"::"r"(data),"r"(addr))

/* atom load (load word and reserve indexed) */
#define LWARX(data,addr) asm volatile("lwarx %0,0,%1":"=r"(data):"r"(addr))

/* read $data from $spr index */
#define MFSPR(data,spr) asm volatile("mfspr %0,%1" : "=r" (data) : "n" (spr))

/* write $data to $spr index */
#define MTSPR(spr,data) asm volatile("mtspr %0,%1" : : "n" (spr), "r" (data))

/* read $data from MSR */
#define MFMSR(data)      asm volatile("mfmsr %0" : "=r" (data) : )

/* write $data to MSR */
#define MTMSR(data)      asm volatile("mtmsr %0" : : "r" (data))

/* read $data from $dcr address */
#define MFDCR(data,dcr)  asm volatile("mfdcrx %0,%1" : "=r" (data) : "r" (dcr))

/* wirte $data to $dcr address */
#define MTDCR(dcr,data)  asm volatile("mtdcrx %0,%1" : : "r" (dcr), "r" (data))

/* insert a conditional soft-breakpoint */
#define COND_TRAP(cond,ra,rb) asm volatile("tw %0,%1,%2"::"n"(cond),"r"(ra),"r"(rb))

/* unconditional jump to address, which is saved in CTR */
#define BCTR           asm volatile("bctr")

/* unconditional jump to addr, which is saved in CTR and save return addr into LR */
#define BCTRL          asm volatile("bctrl")

/* ensure load and store order */
#define MSYNC          asm volatile("msync")

/* insert a smal gap between this ld/st and next ld/st, like a small msync */
#define MBAR           asm volatile("mbar")

/* ensure instruction excution order */
#define ISYNC          asm volatile("isync")

/* start a system call exception */
#define SYSTEM_CALL    asm volatile("sc")

#ifdef __cplusplus
}
#endif

#endif  /* E200Z7_ASM_H */
