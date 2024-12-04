/**************************************************************************** 
* 
* Copyright (c) 2023  C*Core -   All Rights Reserved  
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* 
* PROJECT     : CCFC2016BC           
* DESCRIPTION : CCFC2016BC flash low level drivers code 
* HISTORY     : Initial version.
* @file     flash_lld.h
* @version  1.4
* @date     2023 - 06 - 12
* @brief    Initial version.
*
*****************************************************************************/
#ifndef FLASH_LLD_H
#define FLASH_LLD_H

#include "CCFC2016BC.h"
#include "e200z7_asm.h"
#include "typedefs.h"

/* Define for: CFlash use block erase */
//#define CFLASH_USE_BLK_ERASE

/* Define discovery option for double bit fault event */
#define EER_MCR                 (0U)
#define IVOR_EXCEPTION          (1U)
#define PAGE_SIZE               (0x00002000U) /* 8KB  */

#define EER_OPTION              (IVOR_EXCEPTION)

/* Read and write macros */
#define WRITE8(address, value)      (*(vuint8_t *)(address) = (value))
#define READ8(address)              ((uint8_t)(*(vuint8_t*)(address)))
#define SET8(address, value)        (*(vuint8_t*)(address) |= (value))
#define CLEAR8(address, value)      (*(vuint8_t*)(address) &= ~(value))

#define WRITE16(address, value)     (*(vuint16_t*)(address) = (value))
#define READ16(address)             ((uint16_t)(*(vuint16_t*)(address)))
#define SET16(address, value)       (*(vuint16_t*)(address) |= (value))
#define CLEAR16(address, value)     (*(vuint16_t*)(address) &= ~(value))

#define WRITE32(address, value)     (*(vuint32_t*)(address) = (value))
#define READ32(address)             ((uint32_t)(*(vuint32_t*)(address)))
#define SET32(address, value)       (*(vuint32_t*)(address) |= (value))
#define CLEAR32(address, value)     (*(vuint32_t*)(address) &= ~(value))

/*
 * **********************************************************************/
/* Define CFlash Sector StartAddress */
#define CFLASH_SECTOR0_START    (0x00000000u)   /* Low0  StartAddress */
#define CFLASH_SECTOR1_START    (0x00008000u)   /* Low1  StartAddress */
#define CFLASH_SECTOR2_START    (0x0000C000u)   /* Low2  StartAddress */
#define CFLASH_SECTOR3_START    (0x00010000u)   /* Low3  StartAddress */
#define CFLASH_SECTOR4_START    (0x00018000u)   /* Low4  StartAddress */
#define CFLASH_SECTOR5_START    (0x00020000u)   /* Low5  StartAddress */
#define CFLASH_SECTOR6_START    (0x00040000u)   /* Mid0  StartAddress */
#define CFLASH_SECTOR7_START    (0x00060000u)   /* Mid1  StartAddress */
#define CFLASH_SECTOR8_START    (0x00080000u)   /* High0 StartAddress */
#define CFLASH_SECTOR9_START    (0x000A0000u)   /* High1 StartAddress */
#define CFLASH_SECTOR10_START   (0x000C0000u)   /* High2 StartAddress */
#define CFLASH_SECTOR11_START   (0x000E0000u)   /* High3 StartAddress */
#define CFLASH_SECTOR12_START   (0x00100000u)   /* High4 StartAddress */
#define CFLASH_SECTOR13_START   (0x00120000u)   /* High5 StartAddress */
#define CFLASH_SECTOR14_START   (0x00140000u)   /* High6 StartAddress */
#define CFLASH_SECTOR15_START   (0x00160000u)   /* High7 StartAddress */
#define CFLASH_SECTOR16_START   (0x00180000u)   /* High8 StartAddress */
#define CFLASH_SECTOR17_START   (0x001A0000u)   /* High9 StartAddress */
#define CFLASH_SECTOR18_START   (0x001C0000u)   /* High10 StartAddress */
#define CFLASH_SECTOR19_START   (0x001E0000u)   /* High11 StartAddress */
#define CFLASH_SECTOR20_START   (0x00200000u)   /* High12 StartAddress */
#define CFLASH_SECTOR21_START   (0x00220000u)   /* High13 StartAddress */
#define CFLASH_SECTOR22_START   (0x00240000u)   /* High14 StartAddress */
#define CFLASH_SECTOR23_START   (0x00260000u)   /* High15 StartAddress */

/* Define CFlash Sector Size */
#define CFLASH_SECTOR0_SIZE     (0x8000u)   /*  32KB */
#define CFLASH_SECTOR1_SIZE     (0x4000u)   /*  16KB */
#define CFLASH_SECTOR2_SIZE     (0x4000u)   /*  16KB */
#define CFLASH_SECTOR3_SIZE     (0x8000u)   /*  32KB */
#define CFLASH_SECTOR4_SIZE     (0x8000u)   /*  32KB */
#define CFLASH_SECTOR5_SIZE     (0x20000u)  /* 128KB */
#define CFLASH_SECTOR6_SIZE     (0x20000u)  /* 128KB */
#define CFLASH_SECTOR7_SIZE     (0x20000u)  /* 128KB */
#define CFLASH_SECTOR8_SIZE     (0x20000u)  /* 128KB */
#define CFLASH_SECTOR9_SIZE     (0x20000u)  /* 128KB */
#define CFLASH_SECTOR10_SIZE    (0x20000u)  /* 128KB */
#define CFLASH_SECTOR11_SIZE    (0x20000u)  /* 128KB */
#define CFLASH_SECTOR12_SIZE    (0x20000u)  /* 128KB */
#define CFLASH_SECTOR13_SIZE    (0x20000u)  /* 128KB */
#define CFLASH_SECTOR14_SIZE    (0x20000u)  /* 128KB */
#define CFLASH_SECTOR15_SIZE    (0x20000u)  /* 128KB */
#define CFLASH_SECTOR16_SIZE    (0x20000u)  /* 128KB */
#define CFLASH_SECTOR17_SIZE    (0x20000u)  /* 128KB */
#define CFLASH_SECTOR18_SIZE    (0x20000u)  /* 128KB */
#define CFLASH_SECTOR19_SIZE    (0x20000u)  /* 128KB */
#define CFLASH_SECTOR20_SIZE    (0x20000u)  /* 128KB */
#define CFLASH_SECTOR21_SIZE    (0x20000u)  /* 128KB */
#define CFLASH_SECTOR22_SIZE    (0x20000u)  /* 128KB */
#define CFLASH_SECTOR23_SIZE    (0x20000u)  /* 128KB */

#define CFLASH_LOW0_5_SIZE          (0x40000u)  /* 256KB */
#define CFLASH_MID0_1_SIZE          (0x40000u)  /* 256KB */
#define CFLASH_HIGH0_15_SIZE        (0x200000u)  /* 2MB */

/* Define CFlash Shadow StartAddress/Size */
#define CFLASH_SHADOW_ROW_BASE  (0x00400000u)
#define CFLASH_SHADOW_ROW_SIZE  (0x4000u)   /* 16KB */

/* Define CFlash Test StartAddress/Size */
#define CFLASH_TEST_BASE        (0x00480000u)
#define CFLASH_TEST_SIZE        (0x4000u)   /* 16KB */

/*
 * **********************************************************************/
/* Define DFlash Sector StartAddress */
#define DFLASH_SECTOR0_START    (0x00800000u)
#define DFLASH_SECTOR1_START    (0x00820000u)
#define DFLASH_SECTOR2_START    (0x00840000u)
#define DFLASH_SECTOR3_START    (0x00860000u)

/* Define DFlash Sector Size */
#define DFLASH_SECTOR0_SIZE     (0x20000u)   /* 128KB */
#define DFLASH_SECTOR1_SIZE     (0x20000u)   /* 128KB */
#define DFLASH_SECTOR2_SIZE     (0x20000u)   /* 128KB */
#define DFLASH_SECTOR3_SIZE     (0x20000u)   /* 128KB */

#define DFLASH_LOW0_3_SIZE      (0x80000u)  /* 512KB */

/* Define DFlash Test StartAddress/Size */
#define DFLASH_TEST_BASE        (0x00C00000u)
#define DFLASH_TEST_SIZE        (0x4000u)   /* 16KB */


/*      CFlash TestFlash structure
 * **********************************************************************/
#define CFLASH_USER_OTP_BASE0   (0x480000u)
#define CFLASH_USER_OTP_SIZE0   (0x2000u)   /* 8KB */

#define CFLASH_USER_OTP_BASE1   (0x483D00u)
#define CFLASH_USER_OTP_SIZE1   (0xE8u)     /* 232Bytes*/

#define CFLASH_USER_OTP_BASE2   (0x483E00u)
#define CFLASH_USER_OTP_SIZE2   (0x100u)    /* 256Bytes*/

/* CFlash Non-volatile Low/Mid Address Space Block Locking Register */
#define CFLASH_NVLML_H          (0x483DE8u)
#define CFLASH_NVLML_L          (0x483DECu)

/* CFlash Non-volatile High Address Space Block Locking Register */
#define CFLASH_NVHBL_H          (0x483DF0u)
#define CFLASH_NVHBL_L          (0x483DF4u)

/* CFlash Non-volatile Secondary Low/Mid Address Space Block Locking REG*/
#define CFLASH_NVSLL_H          (0x483DF8u)
#define CFLASH_NVSLL_L          (0x483DFCu)

/*      DFlash TestFlash structure
 * **********************************************************************/
#define DFLASH_USER_OTP_BASE0   (0xC00000u)
#define DFLASH_USER_OTP_SIZE0   (0x2000u)   /* 8KB */

#define DFLASH_USER_OTP_BASE1   (0xC03D00u)
#define DFLASH_USER_OTP_SIZE1   (0xE8u)     /* 232Bytes*/

#define DFLASH_USER_OTP_BASE2   (0xC03E00u)
#define DFLASH_USER_OTP_SIZE2   (0x100u)    /* 256Bytes*/

/* DFlash Non-volatile Low/Mid Address Space Block Locking Register */
#define DFLASH_NVLML_H          (0xC03DE8u)
#define DFLASH_NVLML_L          (0xC03DECu)

/* DFlash Non-volatile Secondary Low/Mid Address Space Block Locking REG*/
#define DFLASH_NVSLL_H          (0xC03DF8u)
#define DFLASH_NVSLL_L          (0xC03DFCu)

/*      PFlash(CFlash) Shadow sector structure
 * **********************************************************************/
#define CFLASH_SHADOW_USER_BASE CFLASH_SHADOW_ROW_BASE
#define CFLASH_SHADOW_USER_SIZE (0x3DD0u)   /* 15824Bytes*/

/* Non-volatile Platform Flash Memory Access Protection Register */
#define NVPFAPR_H               (0x403E00u)
#define NVPFAPR_L               (0x403E04u)

/* Non-volatile User Options register */
#define NVUSRO_H                (0x403E18u)
#define NVUSRO_L                (0x403E1Cu)

/*
 * **********************************************************************/
/* Define size macros*/
#define WORD_SIZE       (4u)
#define DWORD_SIZE      (8u)
#define PGM_SIZE        (8u)

/* Bank0: CFlash, Bank1: DFlash */
#define CFLASH_BANK0    (0x00000001U)
#define DFLASH_BANK1    (0x00000002U)
#define PSRAM_ADDR      (0x00000003U)
#define ERROR_BANK      (0x00000004U)


/************************************************************************
 *    CFLASH_LML, CFLASH_HBL, CFLASH_SLL
 *    DFLASH_LML, DFLASH_SLL
 *    Unlock Password Configuration
 ************************************************************************/
#define FLASH_LML_KEY   (0xA1A11111u)
#define FLASH_HBL_KEY   (0xB2B22222u)
#define FLASH_SLL_KEY   (0xC3C33333u)


/************************************************************************
 *    CFlash Module Configuration Register (CFLASH_MCR)
 *    Configuration parameter
 ************************************************************************/
#define CFLASH_MCR_NULL (0x00000000u)
#define CFLASH_MCR_EHV  (0x00000001u)  /* Enable High Voltage (RW)         */
#define CFLASH_MCR_ESUS (0x00000002u)  /* Erase SUSpend (RW)               */
#define CFLASH_MCR_ERS  (0x00000004u)  /* ERaSe (RW)                       */
#define CFLASH_MCR_PSUS (0x00000008u)  /* Program SUSpend (RW)             */
#define CFLASH_MCR_PGM  (0x00000010u)  /* ProGraM (RW)                     */
#define CFLASH_MCR_PEG  (0x00000200u)  /* Program/Erase Good (RO)          */
#define CFLASH_MCR_DONE (0x00000400u)  /* modify operation DONE (RO)       */
#define CFLASH_MCR_PEAS (0x00000800u)  /* Program/Erase Access Space (RO)  */
#define CFLASH_MCR_RWE  (0x00004000u)  /* Read-while-Write event Error(RW) */
#define CFLASH_MCR_EER  (0x00008000u)  /* Ecc event ERror (RW)             */
#define CFLASH_MCR_MAS  (0x00010000u)  /* Mid Address Space (RO)           */
#define CFLASH_MCR_EDC  (0x80000000u)  /* Ecc Data Correction (RW)         */

/* Low Address Space (Read Only) */
#define CFLASH_MCR_LAS0 (0x00000000u)  /* Reserved */
#define CFLASH_MCR_LAS1 (0x00100000u)  /* Reserved */
#define CFLASH_MCR_LAS2 (0x00200000u)  /* 32KB + 2x16KB + 2x32KB + 128KB */
#define CFLASH_MCR_LAS3 (0x00300000u)  /* Reserved */
#define CFLASH_MCR_LAS4 (0x00400000u)  /* Reserved */
#define CFLASH_MCR_LAS5 (0x00500000u)  /* Reserved */
#define CFLASH_MCR_LAS6 (0x00600000u)  /* 4 x 16KB */
#define CFLASH_MCR_LAS7 (0x00700000u)  /* Reserved */

/* Array space SIZE (Read Only) */
#define CFLASH_MCR_SIZE0    (0x00000000u)  /* 128KB */
#define CFLASH_MCR_SIZE1    (0x01000000u)  /* 256KB */
#define CFLASH_MCR_SIZE2    (0x02000000u)  /* 512KB */
#define CFLASH_MCR_SIZE3    (0x03000000u)  /* 1024KB */
#define CFLASH_MCR_SIZE4    (0x04000000u)  /* 1536KB */
#define CFLASH_MCR_SIZE5    (0x05000000u)  /* Reserved(2048KB) */
#define CFLASH_MCR_SIZE6    (0x06000000u)  /* 64KB */
#define CFLASH_MCR_SIZE7    (0x07000000u)  /* Reserved */


/************************************************************************
 *    CFlash Low/Mid Address Space Block Locking Register (CFLASH_LML)
 *    Configuration parameter
 ************************************************************************/
#define CFLASH_LML_NULL (0x00000000u) /*  No need to unlock */
#define CFLASH_LML_LLK0 (0x00000001u) /*  32KB: 0x00000000u - 0x00007FFFu */
#define CFLASH_LML_LLK1 (0x00000002u) /*  16KB: 0x00008000u - 0x0000BFFFu */
#define CFLASH_LML_LLK2 (0x00000004u) /*  16KB: 0x0000C000u - 0x0000FFFFu */
#define CFLASH_LML_LLK3 (0x00000008u) /*  32KB: 0x00010000u - 0x00017FFFu */
#define CFLASH_LML_LLK4 (0x00000010u) /*  32KB: 0x00018000u - 0x0001FFFFu */
#define CFLASH_LML_LLK5 (0x00000020u) /* 128KB: 0x00020000u - 0x0003FFFFu */
#define CFLASH_LML_MLK0 (0x00010000u) /* 128KB: 0x00040000u - 0x0005FFFFu */
#define CFLASH_LML_MLK1 (0x00020000u) /* 128KB: 0x00060000u - 0x0007FFFFu */
#define CFLASH_LML_LOCK (0x0003003Fu) /* LLK0~LLK5 + MLK0~MLK1 */
#define CFLASH_LML_TSLK (0x00100000u) /*Shadow(16KB):0x00400000u-0x00403FFFu
                                        *Test(16KB):  0x00480000u-0x00483FFFu*/
#define CFLASH_LML_LME  (0x80000000u) /* Write to the password to enable  */


/************************************************************************
 *    CFlash High Address Space Block Locking Register (CFLASH_HBL)
 *    Configuration parameter
 ************************************************************************/
#define CFLASH_HBL_NULL     (0x00000000u) /* No need to unlock */
#define CFLASH_HBL_HLK0     (0x00000001u) /* 128KB: 0x00080000u - 0x0009FFFFu */
#define CFLASH_HBL_HLK1     (0x00000002u) /* 128KB: 0x000A0000u - 0x000BFFFFu */
#define CFLASH_HBL_HLK2     (0x00000004u) /* 128KB: 0x000C0000u - 0x000DFFFFu */
#define CFLASH_HBL_HLK3     (0x00000008u) /* 128KB: 0x000E0000u - 0x000FFFFFu */
#define CFLASH_HBL_HLK4     (0x00000010u) /* 128KB: 0x00100000u - 0x0011FFFFu */
#define CFLASH_HBL_HLK5     (0x00000020u) /* 128KB: 0x00120000u - 0x0013FFFFu */
#define CFLASH_HBL_HLK6     (0x00000040u) /* 128KB: 0x00140000u - 0x0015FFFFu */
#define CFLASH_HBL_HLK7     (0x00000080u) /* 128KB: 0x00160000u - 0x0017FFFFu */
#define CFLASH_HBL_HLK8     (0x00000100u) /* 128KB: 0x00180000u - 0x0019FFFFu */
#define CFLASH_HBL_HLK9     (0x00000200u) /* 128KB: 0x001A0000u - 0x001BFFFFu */
#define CFLASH_HBL_HLK10    (0x00000400u) /* 128KB: 0x001C0000u - 0x001DFFFFu */
#define CFLASH_HBL_HLK11    (0x00000800u) /* 128KB: 0x001E0000u - 0x001FFFFFu */
#define CFLASH_HBL_HLK12    (0x00001000u) /* 128KB: 0x00200000u - 0x0021FFFFu */
#define CFLASH_HBL_HLK13    (0x00002000u) /* 128KB: 0x00220000u - 0x0023FFFFu */
#define CFLASH_HBL_HLK14    (0x00004000u) /* 128KB: 0x00240000u - 0x0025FFFFu */
#define CFLASH_HBL_HLK15    (0x00008000u) /* 128KB: 0x00260000u - 0x0027FFFFu */
#define CFLASH_HBL_LOCK     (0x0000FFFFu) /* HLK0~15 */
#define CFLASH_HBL_LME      (0x80000000u) /* Write to the password to enable  */


/************************************************************************
 *    CFlash Secondary Low/Mid Address 
 *                          Space Block Locking Register(CFLASH_SLL)
 *    Configuration parameter
 ************************************************************************/
#define CFLASH_SLL_NULL     (0x00000000u) /*  No need to unlock */
#define CFLASH_SLL_SLK0     (0x00000001u) /*  32KB: 0x00000000u - 0x00007FFFu */
#define CFLASH_SLL_SLK1     (0x00000002u) /*  16KB: 0x00008000u - 0x0000BFFFu */
#define CFLASH_SLL_SLK2     (0x00000004u) /*  16KB: 0x0000C000u - 0x0000FFFFu */
#define CFLASH_SLL_SLK3     (0x00000008u) /*  32KB: 0x00010000u - 0x00017FFFu */
#define CFLASH_SLL_SLK4     (0x00000010u) /*  32KB: 0x00018000u - 0x0001FFFFu */
#define CFLASH_SLL_SLK5     (0x00000020u) /* 128KB: 0x00020000u - 0x0003FFFFu */
#define CFLASH_SLL_SMK0     (0x00010000u) /* 128KB: 0x00040000u - 0x0005FFFFu */
#define CFLASH_SLL_SMK1     (0x00020000u) /* 128KB: 0x00060000u - 0x0007FFFFu */
#define CFLASH_SLL_LOCK     (0x0003003Fu) /* SLK0~5 + SMK0~1 */
#define CFLASH_SLL_STSLK    (0x00100000u) /*Shadow(16KB):0x00400000u-0x00403FFFu
                                            *Test(16KB):  0x00480000u-0x00483FFFu*/
#define CFLASH_SLL_SLE      (0x80000000u) /* Write to the password to enable  */


/************************************************************************
 *    CFlash Low/Mid Address Space Block Select Register (CFLASH_LMS)
 *    Configuration parameter
 *    (Shadow/Test does not have the selection function)
 ************************************************************************/
#define CFLASH_LMS_NULL     (0x00000000u) /* UnSelect: LSL0~5 + MSL0~1 */
#define CFLASH_LMS_LSL0     (0x00000001u) /*  32KB: 0x00000000u - 0x00007FFFu */
#define CFLASH_LMS_LSL1     (0x00000002u) /*  16KB: 0x00008000u - 0x0000BFFFu */
#define CFLASH_LMS_LSL2     (0x00000004u) /*  16KB: 0x0000C000u - 0x0000FFFFu */
#define CFLASH_LMS_LSL3     (0x00000008u) /*  32KB: 0x00010000u - 0x00017FFFu */
#define CFLASH_LMS_LSL4     (0x00000010u) /*  32KB: 0x00018000u - 0x0001FFFFu */
#define CFLASH_LMS_LSL5     (0x00000020u) /* 128KB: 0x00020000u - 0x0003FFFFu */
#define CFLASH_LMS_L0_5     (0x0000003Fu) /* Select: LSL0~5 */
#define CFLASH_LMS_MSL0     (0x00010000u) /* 128KB: 0x00040000u - 0x0005FFFFu */
#define CFLASH_LMS_MSL1     (0x00020000u) /* 128KB: 0x00060000u - 0x0007FFFFu */
#define CFLASH_LMS_M0_1     (0x00030000u) /* Select: MSL0~1 */
#define CFLASH_L0_5_M0_1    (0x0003003Fu) /* Select: LSL0~5 + MSL0~1 */


/************************************************************************
 *    CFlash High Address Space Block Select Register (CFLASH_HBS)
 *    Configuration parameter
 ************************************************************************/
#define CFLASH_HBS_NULL     (0x00000000u) /* UnSelect: HSL0~7 */
#define CFLASH_HBS_HSL0     (0x00000001u) /* 128KB: 0x00080000u - 0x0009FFFFu */
#define CFLASH_HBS_HSL1     (0x00000002u) /* 128KB: 0x000A0000u - 0x000BFFFFu */
#define CFLASH_HBS_HSL2     (0x00000004u) /* 128KB: 0x000C0000u - 0x000DFFFFu */
#define CFLASH_HBS_HSL3     (0x00000008u) /* 128KB: 0x000E0000u - 0x000FFFFFu */
#define CFLASH_HBS_HSL4     (0x00000010u) /* 128KB: 0x00100000u - 0x0011FFFFu */
#define CFLASH_HBS_HSL5     (0x00000020u) /* 128KB: 0x00120000u - 0x0013FFFFu */
#define CFLASH_HBS_HSL6     (0x00000040u) /* 128KB: 0x00140000u - 0x0015FFFFu */
#define CFLASH_HBS_HSL7     (0x00000080u) /* 128KB: 0x00160000u - 0x0017FFFFu */
#define CFLASH_HBS_HSL8     (0x00000100u) /* 128KB: 0x00180000u - 0x0019FFFFu */
#define CFLASH_HBS_HSL9     (0x00000200u) /* 128KB: 0x001A0000u - 0x001BFFFFu */
#define CFLASH_HBS_HSL10    (0x00000400u) /* 128KB: 0x001C0000u - 0x001DFFFFu */
#define CFLASH_HBS_HSL11    (0x00000800u) /* 128KB: 0x001E0000u - 0x001FFFFFu */
#define CFLASH_HBS_HSL12    (0x00001000u) /* 128KB: 0x00200000u - 0x0021FFFFu */
#define CFLASH_HBS_HSL13    (0x00002000u) /* 128KB: 0x00220000u - 0x0023FFFFu */
#define CFLASH_HBS_HSL14    (0x00004000u) /* 128KB: 0x00240000u - 0x0025FFFFu */
#define CFLASH_HBS_HSL15    (0x00008000u) /* 128KB: 0x00260000u - 0x0027FFFFu */
#define CFLASH_HBS_H0_15    (0x0000FFFFu) /* Select: HSL0~15 */



/************************************************************************/
/************************************************************************/
/************************************************************************/


/************************************************************************
 *    DFlash Module Configuration Register (DFLASH_MCR)
 *    Configuration parameter
 ************************************************************************/
#define DFLASH_MCR_NULL     (0x00000000u)
#define DFLASH_MCR_EHV      (0x00000001u)  /* Enable High Voltage (RW)         */
#define DFLASH_MCR_ESUS     (0x00000002u)  /* Erase SUSpend (RW)               */
#define DFLASH_MCR_ERS      (0x00000004u)  /* ERaSe (RW)                       */
#define DFLASH_MCR_PSUS     (0x00000008u)  /* Program SUSpend (RW)             */
#define DFLASH_MCR_PGM      (0x00000010u)  /* ProGraM (RW)                     */
#define DFLASH_MCR_PEG      (0x00000200u)  /* Program/Erase Good (RO)          */
#define DFLASH_MCR_DONE     (0x00000400u)  /* modify operation DONE (RO)       */
#define DFLASH_MCR_PEAS     (0x00000800u)  /* Program/Erase Access Space (RO)  */
#define DFLASH_MCR_RWE      (0x00004000u)  /* Read-while-Write event Error(RW) */
#define DFLASH_MCR_EER      (0x00008000u)  /* Ecc event ERror (RW)             */
#define DFLASH_MCR_MAS      (0x00010000u)  /* Mid Address Space (RO)           */
#define DFLASH_MCR_EDC      (0x80000000u)  /* Ecc Data Correction (RW)         */

/* Low Address Space (Read Only) */
#define DFLASH_MCR_LAS0     (0x00000000u)  /* Reserved */
#define DFLASH_MCR_LAS1     (0x00100000u)  /* Reserved */
#define DFLASH_MCR_LAS2     (0x00200000u)  /* 32KB + 2x16KB + 2x32KB + 128KB */
#define DFLASH_MCR_LAS3     (0x00300000u)  /* Reserved */
#define DFLASH_MCR_LAS4     (0x00400000u)  /* Reserved */
#define DFLASH_MCR_LAS5     (0x00500000u)  /* Reserved */
#define DFLASH_MCR_LAS6     (0x00600000u)  /* 4 x 16KB */
#define DFLASH_MCR_LAS7     (0x00700000u)  /* Reserved */

/* Array space SIZE (Read Only) */
#define DFLASH_MCR_SIZE0    (0x00000000u)  /* 128KB */
#define DFLASH_MCR_SIZE1    (0x01000000u)  /* 256KB */
#define DFLASH_MCR_SIZE2    (0x02000000u)  /* 512KB */
#define DFLASH_MCR_SIZE3    (0x03000000u)  /* Reserved(1024KB) */
#define DFLASH_MCR_SIZE4    (0x04000000u)  /* Reserved(1536KB) */
#define DFLASH_MCR_SIZE5    (0x05000000u)  /* Reserved(2048KB) */
#define DFLASH_MCR_SIZE6    (0x06000000u)  /* 64KB */
#define DFLASH_MCR_SIZE7    (0x07000000u)  /* Reserved */


/************************************************************************
 *    DFlash Low/Mid Address Space Block Locking Register (DFLASH_LML)
 *    Configuration parameter
 ************************************************************************/
#define DFLASH_LML_NULL     (0x00000000u) /* No need to unlock */
#define DFLASH_LML_LLK0     (0x00000001u) /* 128KB: 0x00800000u - 0x0081FFFFu */
#define DFLASH_LML_LLK1     (0x00000002u) /* 128KB: 0x00820000u - 0x0083FFFFu */
#define DFLASH_LML_LLK2     (0x00000004u) /* 128KB: 0x00840000u - 0x0085FFFFu */
#define DFLASH_LML_LLK3     (0x00000008u) /* 128KB: 0x00860000u - 0x0087FFFFu */
#define DFLASH_LML_LOCK     (0x0000000Fu) /* LLK0 ~ LLK3 */
#define DFLASH_LML_TSLK     (0x00100000u) /*Test(16KB):0x00C00000u-0x00C03FFFu*/
#define DFLASH_LML_LME      (0x80000000u) /* Write to the password to enable  */


/************************************************************************
 *    DFlash Secondary Low/Mid Address 
 *                          Space Block Locking Register(DFLASH_SLL)
 *    Configuration parameter
 ************************************************************************/
#define DFLASH_SLL_NULL     (0x00000000u) /* No need to unlock */
#define DFLASH_SLL_SLK0     (0x00000001u) /* 128KB: 0x00800000u - 0x0081FFFFu */
#define DFLASH_SLL_SLK1     (0x00000002u) /* 128KB: 0x00820000u - 0x0083FFFFu */
#define DFLASH_SLL_SLK2     (0x00000004u) /* 128KB: 0x00840000u - 0x0085FFFFu */
#define DFLASH_SLL_SLK3     (0x00000008u) /* 128KB: 0x00860000u - 0x0087FFFFu */
#define DFLASH_SLL_LOCK     (0x0000000Fu) /* SLK0 ~ SLK3 */
#define DFLASH_SLL_STSLK    (0x00100000u) /*Test(16KB):0x00C00000u-0x00C03FFFu*/
#define DFLASH_SLL_SLE      (0x80000000u) /* Write to the password to enable  */



/************************************************************************
 *    DFlash Low/Mid Address Space Block Select Register (DFLASH_LMS)
 *    Configuration parameter
 *    (Test does not have the selection function)
 ************************************************************************/
#define DFLASH_LMS_NULL     (0x00000000u) /* UnSelect: LSL0~3 */
#define DFLASH_LMS_LSL0     (0x00000001u) /* 128KB: 0x00800000u - 0x0081FFFFu */
#define DFLASH_LMS_LSL1     (0x00000002u) /* 128KB: 0x00820000u - 0x0083FFFFu */
#define DFLASH_LMS_LSL2     (0x00000004u) /* 128KB: 0x00840000u - 0x0085FFFFu */
#define DFLASH_LMS_LSL3     (0x00000008u) /* 128KB: 0x00860000u - 0x0087FFFFu */
#define DFLASH_LMS_L0_3     (0x0000000Fu) /* Select: LSL0~3 */


/************************************************************************/
/************************************************************************/
/************************************************************************/


/************************************************************************
 *    Platform Flash Configuration Register 0 (PFCR0)
 *    Platform Flash Configuration Register 1 (PFCR1)
 *    Configuration parameter
 ************************************************************************/
/* CCFC2016BC Flash Unnecessary functions are deleted, 
 * but the fixed values remain */
#define PFCR0_FIXED_VALUE   (0x18C0006Cu)
#define PFCR1_FIXED_VALUE   (0x18C00000u)


/* PFCR0 Bank0/PFCR1 Bank1, Read Wait-State Control (R/W) */
#define PFCR_BK_RWSC_0      (0x00000000u)  /* No additional wait-states are added */
#define PFCR_BK_RWSC_1      (0x00020000u)  /* One additional wait-state is added */
#define PFCR_BK_RWSC_2      (0x00040000u)
#define PFCR_BK_RWSC_3      (0x00060000u)   /* Default */
#define PFCR_BK_RWSC_4      (0x00080000u)
#define PFCR_BK_RWSC_5      (0x000A0000u)
#define PFCR_BK_RWSC_6      (0x000C0000u)
#define PFCR_BK_RWSC_7      (0x000E0000u)
#define PFCR_BK_RWSC_8      (0x00100000u)
#define PFCR_BK_RWSC_9      (0x00120000u)
#define PFCR_BK_RWSC_10     (0x00140000u)
#define PFCR_BK_RWSC_11     (0x00160000u)
#define PFCR_BK_RWSC_12     (0x00180000u)
#define PFCR_BK_RWSC_13     (0x001A0000u)
#define PFCR_BK_RWSC_14     (0x001C0000u)
#define PFCR_BK_RWSC_15     (0x001E0000u)
#define PFCR_BK_RWSC_16     (0x00200000u)
#define PFCR_BK_RWSC_17     (0x00220000u)
#define PFCR_BK_RWSC_18     (0x00240000u)
#define PFCR_BK_RWSC_19     (0x00260000u)
#define PFCR_BK_RWSC_20     (0x00280000u)
#define PFCR_BK_RWSC_21     (0x002A0000u)
#define PFCR_BK_RWSC_22     (0x002C0000u)
#define PFCR_BK_RWSC_23     (0x002E0000u)
#define PFCR_BK_RWSC_24     (0x00300000u)
#define PFCR_BK_RWSC_25     (0x00320000u)
#define PFCR_BK_RWSC_26     (0x00340000u)
#define PFCR_BK_RWSC_27     (0x00360000u)
#define PFCR_BK_RWSC_28     (0x00380000u)
#define PFCR_BK_RWSC_29     (0x003A0000u)
#define PFCR_BK_RWSC_30     (0x003C0000u)  /* 30 additional wait-states are added */
#define PFCR_BK_RWSC_31     (0x003E0000u)  /* 31 additional wait-states are added */

/* PFCR0_Bank0/PFCR1_Bank1, Read-While-Write Control (R/W) */
    /* This state should be avoided(PFCR_BK_RWWC_0 ~ 3).
     * Setting to this state can cause unpredictable operation. */
#define PFCR_BK_RWWC_0      (0x00000000u)  /* Don't use */
#define PFCR_BK_RWWC_1      (0x00000080u)  /* Don't use */
#define PFCR_BK_RWWC_2      (0x00008000u)  /* Don't use */
#define PFCR_BK_RWWC_3      (0x00008080u)  /* Don't use */
    /* En:operation abort + abort notification interrupt */
#define PFCR_BK_RWWC_4      (0x00010000u)
    /* En:operation abort, Dis:abort notification interrupt */
#define PFCR_BK_RWWC_5      (0x00010080u)
    /* En:stall notification interrupt,
     * Dis:abort + abort notification interrupt */
#define PFCR_BK_RWWC_6      (0x00018000u)
    /* Dis:stall notification interrupt,
     * Dis:abort + abort notification interrupt */
#define PFCR_BK_RWWC_7      (0x00018080u)  /* Default */
#define PFCR_BK_RWWC_M      (0x00018080u)  /* Max */


/* PFCR0 Bank0/PFCR1 Bank1, Port 0 Buffer Enable (R/W) */
#define PFCR_B_P0_BFE_DIS   (0x00000000u)
#define PFCR_B_P0_BFE       (0x00000001u)  /* Default */


/************************************************************************
 *    Platform Flash Access Protection Register (PFAPR)
 *    Configuration parameter
 ************************************************************************/
/* e200z7 core Master 0 Access Protection */
#define PFAPR_M0AP_NO_ACCESS    (0x00000000u)
#define PFAPR_M0AP_RO           (0x00000001u)
#define PFAPR_M0AP_WO           (0x00000002u)
#define PFAPR_M0AP_RW           (0x00000003u)


/************************************************************************
 *    Functional declarations
 ************************************************************************/

/* Define Flash Common Function */
extern uint32_t PFlash_BankType(uint32_t addr);

extern void CFlash_AC_Init(void);
extern void CFlash_UnlockBlocksInit(void);
extern void CFlash_LockBlocksInit(void);
extern void CFlash_UnSelectBlocks(void);
extern uint32_t CFlash_GetBlockSelect(uint32_t addr, uint32_t *lsl, uint32_t *msl, uint32_t *hsl);
extern uint32_t CFlash_GetLowSectorAddrSize(uint32_t lsl, uint32_t *addr, uint32_t *size);
extern uint32_t CFlash_GetMidSectorAddrSize(uint32_t msl, uint32_t *addr, uint32_t *size);
extern uint32_t CFlash_GetHighSectorAddrSize(uint32_t hsl, uint32_t *addr, uint32_t *size);


extern void DFlash_UnlockBlocksInit(void);
extern void DFlash_LockBlocksInit(void);
extern void DFlash_UnSelectBlocks(void);
extern uint32_t DFlash_GetBlockSelect(uint32_t addr, uint32_t *lsl);
extern uint32_t DFlash_GetLowSectorAddrSize(uint32_t lsl, uint32_t *addr, uint32_t *size);

/* Define CFlash Function API For User */
extern void CFlash_SelectBlocks(uint32_t lsl, uint32_t msl, uint32_t hsl);
extern void CFlash_BlockSelect_Cancel(void);
extern void CFlash_UnlockSelectBlock(uint32_t lsl, uint32_t msl, uint32_t hsl);
extern uint32_t CFlash_PageErase(uint32_t addr);
extern uint32_t CFlash_BlockErase(uint32_t lsl, uint32_t msl, uint32_t hsl);
extern uint32_t CFlash_ChipErase(void);
extern uint32_t CFlash_WordRead(uint32_t addr);
extern uint8_t CFlash_ByteRead(uint32_t addr);
extern uint32_t CFlash_DwProgram(uint32_t word1, uint32_t word2, uint32_t addr) ;
extern uint32_t CFlash_Program(uint32_t addr, uint32_t size, const uint32_t *data);

/* Define DFlash Function API For User */
extern void DFlash_SelectBlocks(uint32_t lsl);
extern void DFlash_BlockSelect_Cancel(void);
extern void DFlash_UnlockSelectBlock(uint32_t lsl);
extern uint32_t DFlash_PageErase(uint32_t addr);
extern uint32_t DFlash_BlockErase(uint32_t lsl);
extern uint32_t DFlash_ChipErase(void);
extern uint32_t DFlash_WordRead(uint32_t addr);
extern uint8_t DFlash_ByteRead(uint32_t addr);
extern uint32_t DFlash_DwProgram(uint32_t word1, uint32_t word2, uint32_t addr);
extern uint32_t DFlash_Program(uint32_t addr, uint32_t size, const uint32_t *data);

#endif  /* FLASH_LLD_H */
