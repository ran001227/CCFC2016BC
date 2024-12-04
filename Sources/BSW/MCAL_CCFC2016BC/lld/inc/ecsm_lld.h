/**************************************************************************** 
* 
* Copyright (c) 2023  C*Core -   All Rights Reserved  
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* 
* PROJECT     : CCFC2016BC           
* DESCRIPTION : CCFC2016BC ECSM low level drivers code 
* HISTORY     : Initial version.
* @file     ECSM_lld.h
* @version  1.1
* @date     2023 - 02 - 15
* @brief    Initial version.
*
*****************************************************************************/
#ifndef ECSM_LLD_H
#define ECSM_LLD_H
#include "CCFC2016BC.h"
#include "typedefs.h"
#include "console.h"
#include "common.h"
#include "sys.h"

/************************************************************************
 *    Miscellaneous Interrupt Register (MIR)
 *    Configuration parameter(Access: Special)
 *      FB0AI: Flash Bank 0 Abort Interrupt
 *      FB0SI: Flash Bank 0 Stall Interrupt
 *      FB1AI: Flash Bank 1 Abort Interrupt
 *      FB1SI: Flash Bank 1 Stall Interrupt
 ************************************************************************/
#define ECSM_MIR_FB0AI      (0x80U)
#define ECSM_MIR_FB0SI      (0x40U)
#define ECSM_MIR_FB1AI      (0x20U)
#define ECSM_MIR_FB1SI      (0x10U)
#define ECSM_MIR_ALL_INT    (0xFFU)

/************************************************************************
 *    ECC Configuration Register (ECR)
 *    Configuration parameter
 ************************************************************************/
#define ECR_DIS     (0x00U)
#define ECR_EN      (0x01U)
#define ECR_ALL     (0x33U)
#define ECR_ER1BR   (0x20U)    /* Enable SRAM 1-bit Reporting */
#define ECR_EF1BR   (0x10U)    /* Enable Flash 1-bit Reporting */
#define ECR_ERNCR   (0x02U)    /* Enable SRAM Non-Correctable Reporting */
#define ECR_EFNCR   (0x01U)    /* Enable Flash Non-Correctable Reporting */


/************************************************************************
 *    ECC Status Register (ESR)
 *    Configuration parameter, Access: Read/Write(Special)
 ************************************************************************/
#define ESR_ALL     (0x33U)
#define ESR_R1BC    (0x20U)    /* SRAM 1-bit Correction */
#define ESR_F1BC    (0x10U)    /* Flash Memory 1-bit Correction */
#define ESR_RNCE    (0x02U)    /* SRAM Non-Correctable Error */
#define ESR_FNCE    (0x01U)    /* Flash Memory Non-Correctable Error */


/************************************************************************
 *    ECC Error Generation Register (EEGR)
 *    Configuration parameter
 ************************************************************************/
#define EEGR_FRC1BI                 (0x2000U)
#define EEGR_FR11BI                 (0x1000U)
#define EEGR_FRCNCI                 (0x0200U)
#define EEGR_FR1NCI                 (0x0100U)
    /* NO INVERTED:
     * (ECSM.EEGR.R & 0x7F) >= 0x47 */
#define EEGR_ERRBIT_MAX             (0x007FU)
#define EEGR_ERRBIT71_NO_INVERTED   (0x0047U)
    /* if ERRBIT = 70, then ECC Parity[6] of the odd bank is inverted */
#define EEGR_ERRBIT70_PARITY6       (0x0046U)
#define EEGR_ERRBIT69_PARITY5       (0x0045U)
#define EEGR_ERRBIT68_PARITY4       (0x0044U)
#define EEGR_ERRBIT67_PARITY3       (0x0043U)
#define EEGR_ERRBIT66_PARITY2       (0x0042U)
#define EEGR_ERRBIT65_PARITY1       (0x0041U)
#define EEGR_ERRBIT64_PARITY0       (0x0040U)
#define EEGR_ERRBIT63_NO_INVERTED   (0x003FU)
    /* NO INVERTED: 
     * ((ECSM.EEGR.R & 0x7F) <= 0x3F) && ((ECSM.EEGR.R & 0x7F) >= 0x20) */
#define EEGR_ERRBIT32_NO_INVERTED   (0x0020U)
    /* if ERRBIT = 31, then SRAM[31] of the odd bank is inverted */
#define EEGR_ERRBIT31_SRAM31        (0x001FU)
#define EEGR_ERRBIT30_SRAM30        (0x001EU)
#define EEGR_ERRBIT29_SRAM29        (0x001DU)
#define EEGR_ERRBIT28_SRAM28        (0x001CU)
#define EEGR_ERRBIT27_SRAM27        (0x001BU)
#define EEGR_ERRBIT26_SRAM26        (0x001AU)
#define EEGR_ERRBIT25_SRAM25        (0x0019U)
#define EEGR_ERRBIT24_SRAM24        (0x0018U)
#define EEGR_ERRBIT23_SRAM23        (0x0017U)
#define EEGR_ERRBIT22_SRAM22        (0x0016U)
#define EEGR_ERRBIT21_SRAM21        (0x0015U)
#define EEGR_ERRBIT20_SRAM20        (0x0014U)
#define EEGR_ERRBIT19_SRAM19        (0x0013U)
#define EEGR_ERRBIT18_SRAM18        (0x0012U)
#define EEGR_ERRBIT17_SRAM17        (0x0011U)
#define EEGR_ERRBIT16_SRAM16        (0x0010U)
#define EEGR_ERRBIT15_SRAM15        (0x000FU)
#define EEGR_ERRBIT14_SRAM14        (0x000EU)
#define EEGR_ERRBIT13_SRAM13        (0x000DU)
#define EEGR_ERRBIT12_SRAM12        (0x000CU)
#define EEGR_ERRBIT11_SRAM11        (0x000BU)
#define EEGR_ERRBIT10_SRAM10        (0x000AU)
#define EEGR_ERRBIT9_SRAM9          (0x0009U)
#define EEGR_ERRBIT8_SRAM8          (0x0008U)
#define EEGR_ERRBIT7_SRAM7          (0x0007U)
#define EEGR_ERRBIT6_SRAM6          (0x0006U)
#define EEGR_ERRBIT5_SRAM5          (0x0005U)
#define EEGR_ERRBIT4_SRAM4          (0x0004U)
#define EEGR_ERRBIT3_SRAM3          (0x0003U)
#define EEGR_ERRBIT2_SRAM2          (0x0002U)
#define EEGR_ERRBIT1_SRAM1          (0x0001U)
#define EEGR_ERRBIT0_SRAM0          (0x0000U)


/************************************************************************
 *    Platform Flash ECC Attributes Register (PFEAT)
 *    Platform RAM ECC Attributes Register (PREAT)
 *    Configuration parameter
 *    bit[0:7] = {WRITE[0], SIZE[1:3], PROTECTION[4:7]}
 ************************************************************************/
typedef enum
{/* bit[0] */
    EAT_READ    = 0U,
    EAT_WRITE   = 1U
} ECSM_EAT_WRITE_t;

typedef enum
{/* bit[1:3] */
    EAT_SIZE_8BIT   = 0U,
    EAT_SIZE_16BIT  = 1U,
    EAT_SIZE_32BIT  = 2U
} ECSM_EAT_SIZE_t;

typedef enum
{/* bit[4] */
    EAT_PROTECTION_NON_CACHEABLE    = 0U,
    EAT_PROTECTION_CACHEABLE        = 1U
} ECSM_EAT_PROTECTION_CACHEABLE_t;

typedef enum
{/* bit[5] */
    EAT_PROTECTION_NON_BUFFERABLE   = 0U,
    EAT_PROTECTION_BUFFERABLE       = 1U
} ECSM_EAT_PROTECTION_BUFFERABLE_t;

typedef enum
{/* bit[6] */
    EAT_PROTECTION_MODE_USER        = 0U,
    EAT_PROTECTION_MODE_SUPERVISOR  = 1U
} ECSM_EAT_PROTECTION_MODE_t;

typedef enum
{/* bit[7] */
    EAT_PROTECTION_TYPE_L_FETCH = 0U,
    EAT_PROTECTION_TYPE_DATA    = 1U
} ECSM_EAT_PROTECTION_TYPE_t;


/************************************************************************
 *    Platform RAM ECC Syndrome Register (PRESR)
 *    Configuration parameter
 ************************************************************************/
typedef enum
{/* 0 ~ 0x7F */
    PRESR_ECC_ODD_0         = 0x00U,
    PRESR_NO_ERROR          = 0x01U,
    PRESR_ECC_ODD_1         = 0x02U,
    PRESR_ECC_ODD_2         = 0x04U,
    PRESR_DATA_ODD_BANK_31  = 0x06U,
    PRESR_ECC_ODD_3         = 0x08U,
    PRESR_DATA_ODD_BANK_30  = 0x0AU,
    PRESR_DATA_ODD_BANK_29  = 0x0CU,
    PRESR_DATA_ODD_BANK_28  = 0x0EU,
    PRESR_ECC_ODD_4         = 0x10U,
    PRESR_DATA_ODD_BANK_27  = 0x12U,
    PRESR_DATA_ODD_BANK_26  = 0x14U,
    PRESR_DATA_ODD_BANK_25  = 0x16U,
    PRESR_DATA_ODD_BANK_24  = 0x18U,
    PRESR_DATA_ODD_BANK_23  = 0x1AU,
    PRESR_DATA_ODD_BANK_22  = 0x1CU,
    PRESR_DATA_ODD_BANK_21  = 0x50U,
    PRESR_ECC_ODD_5         = 0x20U,
    PRESR_DATA_ODD_BANK_20  = 0x22U,
    PRESR_DATA_ODD_BANK_19  = 0x24U,
    PRESR_DATA_ODD_BANK_18  = 0x26U,
    PRESR_DATA_ODD_BANK_17  = 0x28U,
    PRESR_DATA_ODD_BANK_16  = 0x2AU,
    PRESR_DATA_ODD_BANK_15  = 0x2CU,
    PRESR_DATA_ODD_BANK_14  = 0x58U,
    PRESR_DATA_ODD_BANK_13  = 0x30U,
    PRESR_DATA_ODD_BANK_12  = 0x32U,
    PRESR_DATA_ODD_BANK_11  = 0x34U,
    PRESR_DATA_ODD_BANK_10  = 0x64U,
    PRESR_DATA_ODD_BANK_9   = 0x38U,
    PRESR_DATA_ODD_BANK_8   = 0x62U,
    PRESR_DATA_ODD_BANK_7   = 0x70U,
    PRESR_DATA_ODD_BANK_6   = 0x60U,
    PRESR_ECC_ODD_6         = 0x40U,
    PRESR_DATA_ODD_BANK_5   = 0x42U,
    PRESR_DATA_ODD_BANK_4   = 0x44U,
    PRESR_DATA_ODD_BANK_3   = 0x46U,
    PRESR_DATA_ODD_BANK_2   = 0x48U,
    PRESR_DATA_ODD_BANK_1   = 0x4AU,
    PRESR_DATA_ODD_BANK_0   = 0x4CU,
    PRESR_MUL_BIT_ERR0      = 0x03U, /* Multiple bit error */
    PRESR_MUL_BIT_ERR1      = 0x05U, /* Multiple bit error */
    PRESR_MUL_BIT_ERR2      = 0x4DU  /* Multiple bit error:  >= 0x4D */
} ECSM_PRESR_t;

/************************************************************************
 *    Functional declarations
 ************************************************************************/

void ECSM_SRAM_Force1BitOne(uint16_t errBit);
uint32_t ECSM_ECC_ECR_Config(uint8_t ecrSel, uint8_t ecrSW);
void ECSM_SRAM_ForceStop(void);
void ECSM_SRAM_Force1BitCont(uint16_t errBit);
void ECSM_SRAM_Force2BitOne(uint16_t errBit);
void ECSM_SRAM_Force2BitCont(uint16_t errBit);

#endif  /* ECSM_LLD_H */
