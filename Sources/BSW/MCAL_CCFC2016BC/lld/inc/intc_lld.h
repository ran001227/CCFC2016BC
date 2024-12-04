/****************************************************************************
*
* Copyright(c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS, " AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
* PROJECT     : CCFC2016BC
* DESCRIPTION : CCFC2016BC Intc low level drivers Code
* HISTORY     : Initial version.
* @file     intc_lld.c
* @version  1.1
* @date     2023 - 02 - 15
* @brief    Initial version.
*
*****************************************************************************/

#ifndef INTC_LLD_H_
#define INTC_LLD_H_
#include "typedefs.h"
#include "IntcInterrupts.h"

/* ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  == = */
/* Module macros.                                                               */
/* ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  == = */

/**
 * @brief   IRQ prologue code.
 * @details This macro must be inserted at the start of all IRQ handlers.
 */
#define IRQ_PROLOGUE()

/**
 * @brief   IRQ epilogue code.
 * @details This macro must be inserted at the end of all IRQ handlers.
 */
#define IRQ_EPILOGUE()

/**
 * @brief   IRQ handler function declaration.
 * @details This macro hides the details of an ISR function declaration.
 *
 * @param[in] id        a vector name as defined in @p vectors.s
 */
#define IRQ_HANDLER(id)     void id(void)

/**
 * @brief   Globally enables interrupts.
 */
#define irqIsrEnable()      asm volatile("wrteei  1" : : : "memory");

/**
 * @brief   Globally disables interrupts.
 */
#define irqIsrDisable()     asm volatile("wrteei  0" : : : "memory");

/************************************************************************
 *    INTC Module Configuration Register(INTC_MCR)
 *    Configuration parameter
 *    VTES: Vector table entry size.
 *    HVEN: Hardware vector enable.
 ************************************************************************/
typedef enum
{
    MCR_HVEN_SOFTWARE       = ((uint32_t)0x00000000UL), /* Default */
    MCR_HVEN_HARDWARE       = ((uint32_t)0x00000001UL),
    MCR_VTES_4BYTES         = ((uint32_t)0x00000000UL), /* Default */
    MCR_VTES_8BYTES         = ((uint32_t)0x00000020UL)
} INTC_MCR_t;

typedef enum
{
    HVEN_SOFTWARE           = 0U,
    HVEN_HARDWARE           = 1U
} INTC_MCR_HVEN_t;

typedef enum
{
    VTES_4BYTES             = 0U,
    VTES_8BYTES             = 1U
} INTC_MCR_VTES_t;

/************************************************************************
 *    INTC Current Priority Register for Processor(INTC_CPR)
 *    Configuration parameter
 ************************************************************************/
typedef enum
{
    CPR_PRI_0               = 0U,   /* lowest priority */
    CPR_PRI_1               = 1U,
    CPR_PRI_2               = 2U,
    CPR_PRI_3               = 3U,
    CPR_PRI_4               = 4U,
    CPR_PRI_5               = 5U,
    CPR_PRI_6               = 6U,
    CPR_PRI_7               = 7U,
    CPR_PRI_8               = 8U,
    CPR_PRI_9               = 9U,
    CPR_PRI_10              = 10U,
    CPR_PRI_11              = 11U,
    CPR_PRI_12              = 12U,
    CPR_PRI_13              = 13U,
    CPR_PRI_14              = 14U,
    CPR_PRI_15              = 15U   /* highest priority(default) */
} INTC_CPR_t;

/************************************************************************
 *    INTC Interrupt Acknowledge Register(INTC_IACKR)
 ************************************************************************/
#define IACKR_INTVEC_MASK       (0x000007FCUL)
#define IACKR_VTBA_MASK         (0xFFFFF800UL)
#define IACKR_INTVEC_8B_MASK    (0x00000FF8UL)
#define IACKR_VTBA_8B_MASK      (0xFFFFF000UL)

/************************************************************************
 *    INTC End - of - Interrupt Register(INTC_EOIR)
 ************************************************************************/
#define INTC_EOIR_MASK          (0xFFFFFFFFUL)

/************************************************************************
 *    INTC Software Set/Clear Interrupt Registers
 *                     (INTC_SSCIR0_3 - INTC_SSCIR4_7)
 *    Configuration parameter
 ************************************************************************/
typedef enum
{
    /* Clear Flag Bits:
     * Writing a 1 to CLRx clears it provided that a 1 is not written
     * simultaneously to its corresponding SETx bit */
    INTC_SSCIR_CLR          = ((uint8_t)0x01U),

    /* Set Flag Bits:
     * Writing a 1 sets the corresponding CLRx bit. */
    INTC_SSCIR_SET          = ((uint8_t)0x02U)
} INTC_SSCIR_t;

/************************************************************************
 *    INTC Priority Select Registers(INTC_PSR0_3 - INTC_PSR360_362)
 *    Configuration parameter
 ************************************************************************/
typedef enum
{
    PSR_PRI_0               = ((uint8_t)0U),
    PSR_PRI_1               = ((uint8_t)1U),
    PSR_PRI_2               = ((uint8_t)2U),
    PSR_PRI_3               = ((uint8_t)3U),
    PSR_PRI_4               = ((uint8_t)4U),
    PSR_PRI_5               = ((uint8_t)5U),
    PSR_PRI_6               = ((uint8_t)6U),
    PSR_PRI_7               = ((uint8_t)7U),
    PSR_PRI_8               = ((uint8_t)8U),
    PSR_PRI_9               = ((uint8_t)9U),
    PSR_PRI_10              = ((uint8_t)10U),
    PSR_PRI_11              = ((uint8_t)11U),
    PSR_PRI_12              = ((uint8_t)12U),
    PSR_PRI_13              = ((uint8_t)13U),
    PSR_PRI_14              = ((uint8_t)14U),
    PSR_PRI_15              = ((uint8_t)15U)
} INTC_PSR_PRI_t;

/************************************************************************
 *    Interrupt vector table number
 *    Configuration parameter
 ************************************************************************/
typedef enum
{
    /* Software configurable flag Interrupt Numbers */
    SOFT_CFG_FLAG_0_IRQn        = 0U,   /* 0x0804 */
    SOFT_CFG_FLAG_1_IRQn        = 1U,
    SOFT_CFG_FLAG_2_IRQn        = 2U,
    SOFT_CFG_FLAG_3_IRQn        = 3U,
    SOFT_CFG_FLAG_4_IRQn        = 4U,
    SOFT_CFG_FLAG_5_IRQn        = 5U,
    SOFT_CFG_FLAG_6_IRQn        = 6U,
    SOFT_CFG_FLAG_7_IRQn        = 7U,

    /* Reserved */
    RESERVED_IRQ8               = 8U,

    /* ECSM:
     * Platform Flash Bank 0 Abort |
     * Platform Flash Bank 0 Stall |
     * Platform Flash Bank 1 Abort |
     * Platform Flash Bank 1 Stall | */
    PFLASH_ABORT_STALL_IRQn     = 9U,

    /* Reserved */
    RESERVED_IRQ10              = 10U,

    /* eDMA Interrupt Numbers */
    EDMA_CH0_IRQn               = 11U,
    EDMA_CH1_IRQn               = 12U,
    EDMA_CH2_IRQn               = 13U,
    EDMA_CH3_IRQn               = 14U,
    EDMA_CH4_IRQn               = 15U,
    EDMA_CH5_IRQn               = 16U,
    EDMA_CH6_IRQn               = 17U,
    EDMA_CH7_IRQn               = 18U,
    EDMA_CH8_IRQn               = 19U,
    EDMA_CH9_IRQn               = 20U,
    EDMA_CH10_IRQn              = 21U,
    EDMA_CH11_IRQn              = 22U,
    EDMA_CH12_IRQn              = 23U,
    EDMA_CH13_IRQn              = 24U,
    EDMA_CH14_IRQn              = 25U,
    EDMA_CH15_IRQn              = 26U,

    /* Reserved */
    RESERVED_IRQ27              = 27U,

    /* SWT Interrupt Numbers */
    SWT_TIMEOUT_IRQn            = 28U,

    /* Reserved */
    RESERVED_IRQ29              = 29U,

    /* STM Interrupt Numbers */
    STM_MATCH_ON_CH0_IRQn       = 30U,
    STM_MATCH_ON_CH1_IRQn       = 31U,
    STM_MATCH_ON_CH2_IRQn       = 32U,
    STM_MATCH_ON_CH3_IRQn       = 33U,

    /* Reserved */
    RESERVED_IRQ34              = 34U,

    /* Platform ECC Double Bit Detection:
     * ECC_DBD_PlatformFlash |
     * ECC_DBD_PlatformRAM */
    ECC_DBD_PFLASH_PRAM_IRQn    = 35U,

    /* Platform ECC Single Bit Correction:
     * ECC_SBC_PlatformFlash |
     * ECC_SBC_PlatformRAM */
    ECC_SBC_PFLASH_PRAM_IRQn    = 36U,

    /* Reserved */
    RESERVED_IRQ37              = 37U,

    /* RTC/API Interrupt Numbers */
    RTC_IRQn                    = 38U,
    API_IRQn                    = 39U,

    /* Reserved */
    RESERVED_IRQ40              = 40U,

    /* SIU Interrupt Numbers */
    SIU_EXTI0_7_IRQn            = 41U,
    SIU_EXTI8_15_IRQn           = 42U,
    SIU_EXTI16_23_IRQn          = 43U,

    /* Reserved */
    RESERVED_IRQ44              = 44U,
    RESERVED_IRQ45              = 45U,

    /* WKPU Interrupt Numbers */
    WKPU_0_7_IRQn               = 46U,
    WKPU_8_15_IRQn              = 47U,
    WKPU_16_23_IRQn             = 48U,
    WKPU_24_31_IRQn             = 49U,

    /* Reserved */
    RESERVED_IRQ50              = 50U,

    /* MC_ME Interrupt Numbers */
    MC_ME_SAFE_MODE_IRQn        = 51U,
    MC_ME_MODE_TRANS_IRQn       = 52U,
    MC_ME_INVALID_MODE_IRQn     = 53U,
    MC_ME_INVALID_MODE_CFG_IRQn = 54U,

    /* Reserved */
    RESERVED_IRQ55              = 55U,

    /* MC_RGM Interrupt Numbers
     * Functional and destructive reset
     * alternate event interrupt(ipi_int) */
    MC_RGM_IPI_IRQn             = 56U,

    /* FXOSC Interrupt Numbers */
    MC_CGM_FXOSC_IRQn           = 57U,

    /* Reserved */
    RESERVED_IRQ58              = 58U,

    /* PIT Interrupt Numbers */
    PIT_CH0_IRQn                = 59U,
    PIT_CH1_IRQn                = 60U,
    PIT_CH2_IRQn                = 61U,

    /* ADC0 Interrupt Numbers */
    ADC0_EOC_IRQn               = 62U,
    RESERVED_IRQ63              = 63U,
    ADC0_WD_IRQn                = 64U,

    /* FlexCAN_0 Interrupt Numbers */
    FLEXCAN0_ESR_ERR_IRQn       = 65U,
    FLEXCAN0_ESR_TX_RX_IRQn     = 66U,
    RESERVED_IRQ67              = 67U,
    FLEXCAN0_BUF_00_03_IRQn     = 68U,
    FLEXCAN0_BUF_04_07_IRQn     = 69U,
    FLEXCAN0_BUF_08_11_IRQn     = 70U,
    FLEXCAN0_BUF_12_15_IRQn     = 71U,
    FLEXCAN0_BUF_16_31_IRQn     = 72U,
    FLEXCAN0_BUF_32_63_IRQn     = 73U,

    /* DSPI_0 Interrupt Numbers */
    DSPI0_SR_TFUF_RFOF_IRQn     = 74U,
    DSPI0_SR_EOQF_IRQn          = 75U,
    DSPI0_SR_TFFF_IRQn          = 76U,
    DSPI0_SR_TCF_IRQn           = 77U,
    DSPI0_SR_RFDF_IRQn          = 78U,

    /* LINFLEX_0 Interrupt Numbers */
    LINFLEX0_RXI_IRQn           = 79U,
    LINFLEX0_TXI_IRQn           = 80U,
    LINFLEX0_ERR_IRQn           = 81U,

    /* ADC1 Interrupt Numbers */
    ADC1_EOC_IRQn               = 82U,
    RESERVED_IRQ83              = 83U,
    ADC1_WD_IRQn                = 84U,

    /* FlexCAN_1 Interrupt Numbers */
    FLEXCAN1_ESR_ERR_IRQn       = 85U,
    FLEXCAN1_ESR_TX_RX_IRQn     = 86U,
    FLEXCAN1_ESR_WAK_IRQn       = 87U,
    FLEXCAN1_BUF_00_03_IRQn     = 88U,
    FLEXCAN1_BUF_04_07_IRQn     = 89U,
    FLEXCAN1_BUF_08_11_IRQn     = 90U,
    FLEXCAN1_BUF_12_15_IRQn     = 91U,
    FLEXCAN1_BUF_16_31_IRQn     = 92U,
    FLEXCAN1_BUF_32_63_IRQn     = 93U,

    /* DSPI_1 Interrupt Numbers */
    DSPI1_SR_TFUF_RFOF_IRQn     = 94U,
    DSPI1_SR_EOQF_IRQn          = 95U,
    DSPI1_SR_TFFF_IRQn          = 96U,
    DSPI1_SR_TCF_IRQn           = 97U,
    DSPI1_SR_RFDF_IRQn          = 98U,

    /* LINFLEX_1 Interrupt Numbers */
    LINFLEX1_RXI_IRQn           = 99U,
    LINFLEX1_TXI_IRQn           = 100U,
    LINFLEX1_ERR_IRQn           = 101U,

    /* Reserved */
    RESERVED_IRQ102             = 102U,
    RESERVED_IRQ103             = 103U,
    RESERVED_IRQ104             = 104U,

    /* FlexCAN_2 Interrupt Numbers */
    FLEXCAN2_ESR_ERR_IRQn       = 105U,
    FLEXCAN2_ESR_TX_RX_IRQn     = 106U,
    RESERVED_IRQ107             = 107U,
    FLEXCAN2_BUF_00_03_IRQn     = 108U,
    FLEXCAN2_BUF_04_07_IRQn     = 109U,
    FLEXCAN2_BUF_08_11_IRQn     = 110U,
    FLEXCAN2_BUF_12_15_IRQn     = 111U,
    FLEXCAN2_BUF_16_31_IRQn     = 112U,
    FLEXCAN2_BUF_32_63_IRQn     = 113U,

    /* DSPI_2 Interrupt Numbers */
    DSPI2_SR_TFUF_RFOF_IRQn     = 114U,
    DSPI2_SR_EOQF_IRQn          = 115U,
    DSPI2_SR_TFFF_IRQn          = 116U,
    DSPI2_SR_TCF_IRQn           = 117U,
    DSPI2_SR_RFDF_IRQn          = 118U,

    /* LINFLEX_2 Interrupt Numbers */
    LINFLEX2_RXI_IRQn           = 119U,
    LINFLEX2_TXI_IRQn           = 120U,
    LINFLEX2_ERR_IRQn           = 121U,

    /* LINFLEX_3 Interrupt Numbers */
    LINFLEX3_RXI_IRQn           = 122U,
    LINFLEX3_TXI_IRQn           = 123U,
    LINFLEX3_ERR_IRQn           = 124U,

    /* I2C_0 Interrupt Numbers */
    I2C0_SR_IRQn                = 125U,
    /* I2C_1 Interrupt Numbers */
    I2C1_SR_IRQn                = 126U,

    /* PIT Interrupt Numbers */
    PIT_CH3_IRQn                = 127U,
    PIT_CH4_IRQn                = 128U,
    PIT_CH5_IRQn                = 129U,
    PIT_CH6_IRQn                = 130U,
    PIT_CH7_IRQn                = 131U,

    /* LINFLEX_10 Interrupt Numbers */
    LINFLEX10_RXI_IRQn          = 132U,
    LINFLEX10_TXI_IRQn          = 133U,
    LINFLEX10_ERR_IRQn          = 134U,

    /* LINFLEX_11 Interrupt Numbers */
    LINFLEX11_RXI_IRQn          = 135U,
    LINFLEX11_TXI_IRQn          = 136U,
    LINFLEX11_ERR_IRQn          = 137U,

    /* I2C_2 Interrupt Numbers */
    I2C2_SR_IRQn                = 138U,
    /* I2C_3 Interrupt Numbers */
    I2C3_SR_IRQn                = 139U,

    /* Reserved */
    RESERVED_IRQ140             = 140U,

    /* eMIOS_0 Interrupt Numbers */
    EMIOS0_GFR_F0_F1_IRQn       = 141U,
    EMIOS0_GFR_F2_F3_IRQn       = 142U,
    EMIOS0_GFR_F4_F5_IRQn       = 143U,
    EMIOS0_GFR_F6_F7_IRQn       = 144U,
    EMIOS0_GFR_F8_F9_IRQn       = 145U,
    EMIOS0_GFR_F10_F11_IRQn     = 146U,
    EMIOS0_GFR_F12_F13_IRQn     = 147U,
    EMIOS0_GFR_F14_F15_IRQn     = 148U,
    EMIOS0_GFR_F16_F17_IRQn     = 149U,
    EMIOS0_GFR_F18_F19_IRQn     = 150U,
    EMIOS0_GFR_F20_F21_IRQn     = 151U,
    EMIOS0_GFR_F22_F23_IRQn     = 152U,
    EMIOS0_GFR_F24_F25_IRQn     = 153U,
    EMIOS0_GFR_F26_F27_IRQn     = 154U,
    EMIOS0_GFR_F28_F29_IRQn     = 155U,
    EMIOS0_GFR_F30_F31_IRQn     = 156U,

    /* eMIOS_1 Interrupt Numbers */
    EMIOS1_GFR_F0_F1_IRQn       = 157U,
    EMIOS1_GFR_F2_F3_IRQn       = 158U,
    EMIOS1_GFR_F4_F5_IRQn       = 159U,
    EMIOS1_GFR_F6_F7_IRQn       = 160U,
    EMIOS1_GFR_F8_F9_IRQn       = 161U,
    EMIOS1_GFR_F10_F11_IRQn     = 162U,
    EMIOS1_GFR_F12_F13_IRQn     = 163U,
    EMIOS1_GFR_F14_F15_IRQn     = 164U,
    EMIOS1_GFR_F16_F17_IRQn     = 165U,
    EMIOS1_GFR_F18_F19_IRQn     = 166U,
    EMIOS1_GFR_F20_F21_IRQn     = 167U,
    EMIOS1_GFR_F22_F23_IRQn     = 168U,
    EMIOS1_GFR_F24_F25_IRQn     = 169U,
    EMIOS1_GFR_F26_F27_IRQn     = 170U,
    EMIOS1_GFR_F28_F29_IRQn     = 171U,
    EMIOS1_GFR_F30_F31_IRQn     = 172U,

    /* FlexCAN_3 Interrupt Numbers */
    FLEXCAN3_ESR_ERR_IRQn       = 173U,
    FLEXCAN3_ESR_TX_RX_IRQn     = 174U,
    RESERVED_IRQ175             = 175U,
    FLEXCAN3_BUF_00_03_IRQn     = 176U,
    FLEXCAN3_BUF_04_07_IRQn     = 177U,
    FLEXCAN3_BUF_08_11_IRQn     = 178U,
    FLEXCAN3_BUF_12_15_IRQn     = 179U,
    FLEXCAN3_BUF_16_31_IRQn     = 180U,
    FLEXCAN3_BUF_32_63_IRQn     = 181U,

    /* DSPI_3 Interrupt Numbers */
    DSPI3_SR_TFUF_RFOF_IRQn     = 182U,
    DSPI3_SR_EOQF_IRQn          = 183U,
    DSPI3_SR_TFFF_IRQn          = 184U,
    DSPI3_SR_TCF_IRQn           = 185U,
    DSPI3_SR_RFDF_IRQn          = 186U,

    /* LINFLEX_4 Interrupt Numbers */
    LINFLEX4_RXI_IRQn           = 187U,
    LINFLEX4_TXI_IRQn           = 188U,
    LINFLEX4_ERR_IRQn           = 189U,

    /* FlexCAN_4 Interrupt Numbers */
    FLEXCAN4_ESR_ERR_IRQn       = 190U,
    FLEXCAN4_ESR_TX_RX_IRQn     = 191U,
    RESERVED_IRQ192             = 192U,
    FLEXCAN4_BUF_00_03_IRQn     = 193U,
    FLEXCAN4_BUF_04_07_IRQn     = 194U,
    FLEXCAN4_BUF_08_11_IRQn     = 195U,
    FLEXCAN4_BUF_12_15_IRQn     = 196U,
    FLEXCAN4_BUF_16_31_IRQn     = 197U,
    FLEXCAN4_BUF_32_63_IRQn     = 198U,

    /* LINFLEX_5 Interrupt Numbers */
    LINFLEX5_RXI_IRQn           = 199U,
    LINFLEX5_TXI_IRQn           = 200U,
    LINFLEX5_ERR_IRQn           = 201U,

    /* FlexCAN_5 Interrupt Numbers */
    FLEXCAN5_ESR_ERR_IRQn       = 202U,
    FLEXCAN5_ESR_TX_RX_IRQn     = 203U,
    RESERVED_IRQ204             = 204U,
    FLEXCAN5_BUF_00_03_IRQn     = 205U,
    FLEXCAN5_BUF_04_07_IRQn     = 206U,
    FLEXCAN5_BUF_08_11_IRQn     = 207U,
    FLEXCAN5_BUF_12_15_IRQn     = 208U,
    FLEXCAN5_BUF_16_31_IRQn     = 209U,
    FLEXCAN5_BUF_32_63_IRQn     = 210U,

    /* DSPI_4 Interrupt Numbers */
    DSPI4_SR_TFUF_RFOF_IRQn     = 211U,
    DSPI4_SR_EOQF_IRQn          = 212U,
    DSPI4_SR_TFFF_IRQn          = 213U,
    DSPI4_SR_TCF_IRQn           = 214U,
    DSPI4_SR_RFDF_IRQn          = 215U,

    /* LINFLEX_6 Interrupt Numbers */
    LINFLEX6_RXI_IRQn           = 216U,
    LINFLEX6_TXI_IRQn           = 217U,
    LINFLEX6_ERR_IRQn           = 218U,

    /* DSPI_5 Interrupt Numbers */
    DSPI5_SR_TFUF_RFOF_IRQn     = 219U,
    DSPI5_SR_EOQF_IRQn          = 220U,
    DSPI5_SR_TFFF_IRQn          = 221U,
    DSPI5_SR_TCF_IRQn           = 222U,
    DSPI5_SR_RFDF_IRQn          = 223U,

    /* LINFLEX_7 Interrupt Numbers */
    LINFLEX7_RXI_IRQn           = 224U,
    LINFLEX7_TXI_IRQn           = 225U,
    LINFLEX7_ERR_IRQn           = 226U,

    /* LINFLEX_8 Interrupt Numbers */
    LINFLEX8_RXI_IRQn           = 227U,
    LINFLEX8_TXI_IRQn           = 228U,
    LINFLEX8_ERR_IRQn           = 229U,

    /* LINFLEX_9 Interrupt Numbers */
    LINFLEX9_RXI_IRQn           = 230U,
    LINFLEX9_TXI_IRQn           = 231U,
    LINFLEX9_ERR_IRQn           = 232U,

    /* SXOSC Interrupt Numbers */
    MC_CGM_SXOSC_IRQn           = 233U,

    /* CANFD Interrupt Numbers */
    CANFD0_IRQn                 = 234U,
    CANFD1_IRQn                 = 235U,
    CANFD2_IRQn                 = 236U,
    CANFD3_IRQn                 = 237U,
    CANFD4_IRQn                 = 238U,
    CANFD5_IRQn                 = 239U,
    CANFD6_IRQn                 = 240U,
    CANFD7_IRQn                 = 241U,

    /* ADC0 Interrupt Numbers */
    ADC0_RFIFO_DRAIN_IRQn       = 242U,
    ADC0_RFIFO_OV_IRQn          = 243U,

    /* ADC1 Interrupt Numbers */
    ADC1_RFIFO_DRAIN_IRQn       = 244U,
    ADC1_RFIFO_OV_IRQn          = 245U,

    /* FlexCAN_6 Interrupt Numbers */
    FLEXCAN6_ESR_ERR_IRQn       = 246U,
    FLEXCAN6_ESR_TX_RX_IRQn     = 247U,
    RESERVED_IRQ248             = 248U,
    FLEXCAN6_BUF_00_03_IRQn     = 249U,
    FLEXCAN6_BUF_04_07_IRQn     = 250U,
    FLEXCAN6_BUF_08_11_IRQn     = 251U,
    FLEXCAN6_BUF_12_15_IRQn     = 252U,
    FLEXCAN6_BUF_16_31_IRQn     = 253U,
    FLEXCAN6_BUF_32_63_IRQn     = 254U,

    /* FlexCAN_7 Interrupt Numbers */
    FLEXCAN7_ESR_ERR_IRQn       = 255U,
    FLEXCAN7_ESR_TX_RX_IRQn     = 256U,
    RESERVED_IRQ257             = 257U,
    FLEXCAN7_BUF_00_03_IRQn     = 258U,
    FLEXCAN7_BUF_04_07_IRQn     = 259U,
    FLEXCAN7_BUF_08_11_IRQn     = 260U,
    FLEXCAN7_BUF_12_15_IRQn     = 261U,
    FLEXCAN7_BUF_16_31_IRQn     = 262U,
    FLEXCAN7_BUF_32_63_IRQn     = 263U,

    /* ipi_int_channel_etpu_1 Interrupt Numbers */
    ETPU1_CH0_IRQn              = 264U,
    ETPU1_CH1_IRQn              = 265U,
    ETPU1_CH2_IRQn              = 266U,
    ETPU1_CH3_IRQn              = 267U,
    ETPU1_CH4_IRQn              = 268U,
    ETPU1_CH5_IRQn              = 269U,
    ETPU1_CH6_IRQn              = 270U,
    ETPU1_CH7_IRQn              = 271U,
    ETPU1_CH8_IRQn              = 272U,
    ETPU1_CH9_IRQn              = 273U,
    ETPU1_CH10_IRQn             = 274U,
    ETPU1_CH11_IRQn             = 275U,
    ETPU1_CH12_IRQn             = 276U,
    ETPU1_CH13_IRQn             = 277U,
    ETPU1_CH14_IRQn             = 278U,
    ETPU1_CH15_IRQn             = 279U,
    ETPU1_CH16_IRQn             = 280U,
    ETPU1_CH17_IRQn             = 281U,
    ETPU1_CH18_IRQn             = 282U,
    ETPU1_CH19_IRQn             = 283U,
    ETPU1_CH20_IRQn             = 284U,
    ETPU1_CH21_IRQn             = 285U,
    ETPU1_CH22_IRQn             = 286U,
    ETPU1_CH23_IRQn             = 287U,
    ETPU1_CH24_IRQn             = 288U,
    ETPU1_CH25_IRQn             = 289U,
    ETPU1_CH26_IRQn             = 290U,
    ETPU1_CH27_IRQn             = 291U,
    ETPU1_CH28_IRQn             = 292U,
    ETPU1_CH29_IRQn             = 293U,
    ETPU1_CH30_IRQn             = 294U,
    ETPU1_CH31_IRQn             = 295U,

    /* ipi_int_channel_etpu_2 Interrupt Numbers */
    ETPU2_CH0_IRQn              = 296U,
    ETPU2_CH1_IRQn              = 297U,
    ETPU2_CH2_IRQn              = 298U,
    ETPU2_CH3_IRQn              = 299U,
    ETPU2_CH4_IRQn              = 300U,
    ETPU2_CH5_IRQn              = 301U,
    ETPU2_CH6_IRQn              = 302U,
    ETPU2_CH7_IRQn              = 303U,
    ETPU2_CH8_IRQn              = 304U,
    ETPU2_CH9_IRQn              = 305U,
    ETPU2_CH10_IRQn             = 306U,
    ETPU2_CH11_IRQn             = 307U,
    ETPU2_CH12_IRQn             = 308U,
    ETPU2_CH13_IRQn             = 309U,
    ETPU2_CH14_IRQn             = 310U,
    ETPU2_CH15_IRQn             = 311U,
    ETPU2_CH16_IRQn             = 312U,
    ETPU2_CH17_IRQn             = 313U,
    ETPU2_CH18_IRQn             = 314U,
    ETPU2_CH19_IRQn             = 315U,
    ETPU2_CH20_IRQn             = 316U,
    ETPU2_CH21_IRQn             = 317U,
    ETPU2_CH22_IRQn             = 318U,
    ETPU2_CH23_IRQn             = 319U,
    ETPU2_CH24_IRQn             = 320U,
    ETPU2_CH25_IRQn             = 321U,
    ETPU2_CH26_IRQn             = 322U,
    ETPU2_CH27_IRQn             = 323U,
    ETPU2_CH28_IRQn             = 324U,
    ETPU2_CH29_IRQn             = 325U,
    ETPU2_CH30_IRQn             = 326U,
    ETPU2_CH31_IRQn             = 327U,

    /* ipi_int_glex eTPU Interrupt Numbers */
    ETPU_IPI_GLEX_IRQn          = 328U,

    /* DSPI_6 Interrupt Numbers */
    DSPI6_SR_TFUF_RFOF_IRQn     = 329U,
    DSPI6_SR_EOQF_IRQn          = 330U,
    DSPI6_SR_TFFF_IRQn          = 331U,
    DSPI6_SR_TCF_IRQn           = 332U,
    DSPI6_SR_RFDF_IRQn          = 333U,

    /* DSPI_7 Interrupt Numbers */
    DSPI7_SR_TFUF_RFOF_IRQn     = 334U,
    DSPI7_SR_EOQF_IRQn          = 335U,
    DSPI7_SR_TFFF_IRQn          = 336U,
    DSPI7_SR_TCF_IRQn           = 337U,
    DSPI7_SR_RFDF_IRQn          = 338U,

    /* DSPI_8 Interrupt Numbers */
    DSPI8_SR_TFUF_RFOF_IRQn     = 339U,
    DSPI8_SR_EOQF_IRQn          = 340U,
    DSPI8_SR_TFFF_IRQn          = 341U,
    DSPI8_SR_TCF_IRQn           = 342U,
    DSPI8_SR_RFDF_IRQn          = 343U,

    /* Decimation_filter Interrupt Numbers */
    DECFILTER_ERR_IRQn          = 344U,
    DECFILTER_IN_IRQn           = 345U,
    DECFILTER_OUT_IRQn          = 346U,

    /* LINFLEX_12 Interrupt Numbers */
    LINFLEX12_RXI_IRQn          = 347U,
    LINFLEX12_TXI_IRQn          = 348U,
    LINFLEX12_ERR_IRQn          = 349U,

    /* LINFLEX_13 Interrupt Numbers */
    LINFLEX13_RXI_IRQn          = 350U,
    LINFLEX13_TXI_IRQn          = 351U,
    LINFLEX13_ERR_IRQn          = 352U,

    /* eDMA Interrupt Numbers */
    EDMA_IPI_16_IRQn            = 353U,
    EDMA_IPI_17_IRQn            = 354U,
    EDMA_IPI_18_IRQn            = 355U,
    EDMA_IPI_19_IRQn            = 356U,
    EDMA_IPI_20_IRQn            = 357U,
    EDMA_IPI_21_IRQn            = 358U,
    EDMA_IPI_22_IRQn            = 359U,
    EDMA_IPI_23_IRQn            = 360U,
    EDMA_ERR_63_22_IRQn         = 361U,
    EDMA_ERR_31_0_IRQn          = 362U
} IRQn_t;

/************************************************************************/
/************************************************************************/
/************************************************************************/

/************************************************************************
 *    INTC Module Configuration Register(INTC_MCR)
 *    Access: User read/write
 ************************************************************************/
/*
 * @brief      Read INTC Module Configuration.
 * @retval     INTC_MCR_t(HVEN | VTES)
 *             INTC_MCR_VTES_t
 *             INTC_MCR_HVEN_t
 * */
#define INTC_GET_MCR()                   (INTC.MCR.R)
#define INTC_GET_MCR_VTES()              (INTC.MCR.B.VTES)
#define INTC_GET_MCR_HVEN()              (INTC.MCR.B.HVEN)

/*
 * @brief      INTC Module Configuration init.
 * @param[in]  HVEN - Hardware vector enable.
 *             VTES - Vector table entry size.
 *             val: INTC_MCR_t(HVEN | VTES)
 * @param[out] None
 * @retval     None
 * @notapi
 * */
#define INTC_MCR_SET(val) (INTC.MCR.R = (val)) /* PRQA S 3472 */

/* @param[in]  val: INTC_MCR_VTES_t
 * */
#define INTC_MCR_VTES_SET(val) (INTC.MCR.B.VTES = (val)) /* PRQA S 3472 */

/* @param[in]  val: INTC_MCR_HVEN_t
 * */
#define INTC_MCR_HVEN_SET(val) (INTC.MCR.B.HVEN = (val)) /* PRQA S 3472 */

/************************************************************************
 *    INTC Current Priority Register for Processor(INTC_CPR)
 *    Access: User read/write
 ************************************************************************/
/*
 * @brief      Read INTC Current Priority.
 * @retval     INTC_CPR_t
 * */
#define INTC_GET_CPR()                   (INTC.CPR.R)    /* 32 bits */ /* PRQA S 3472 */
#define INTC_GET_CPR_PRI()               (INTC.CPR.B.PRI)/* 4 bits */ /* PRQA S 3472 */

/*
 * @brief      INTC Current Priority set.
 * @param[in]  val: INTC_CPR_t
 * */
#define INTC_CPR_SET(val) (INTC.CPR.R = (val)) /* PRQA S 3472 */

/************************************************************************
 *    INTC Software Set/Clear Interrupt Registers
 *                     (INTC_SSCIR0_3 - INTC_SSCIR4_7)
 *    Access: User read/write
 ************************************************************************/
/* @param[in]   n: 0U~7U
 * @retval      INTC_SSCIR_t(8 bits)
 * */
#define INTC_GET_SSCIR(n)             (INTC.SSCIR[n].R)

/************************************************************************
 *    INTC Priority Select Registers(INTC_PSR0_3 - INTC_PSR232_233)
 *    Access: User read/write
 ************************************************************************/
/*
 * @brief       Read INTC Priority Select.
 * @param[in]   n: 0U~233U
 * @retval      INTC_PSR_PRI_t
 * */
#define INTC_GET_PSR(n)              (INTC.PSR[n].R)     /* 8 bits */
#define INTC_GET_PSR_PRI(n)          (INTC.PSR[n].B.PRI) /* 4 bits */

/* @brief       INTC Priority Select set.
 * @param[in]   n: 0U~233U
 *              val: INTC_PSR_PRI_t
 * */
#define INTC_PSR_SET(n, val) (INTC.PSR[n].R = (val))

#define INTC_PSR_PRI_SET(n, val) (INTC.PSR[n].B.PRI = (val))

/************************************************************************/
/************************************************************************/
/************************************************************************/

/************************************************************************
 *    Functional declarations
 ************************************************************************/
extern void INTC_SoftInit(INTCInterruptFn IRQHandler, uint16_t IRQn, uint8_t psrPri);
extern void INTC_IRQ_Enable(void);
extern void INTC_IRQ_Disable(void);
extern void INTC_SSCIR_ClearFlagBits(uint8_t sscirNum);
extern void INTC_CPR_Init(uint8_t cprPriority);
void irqSysHalt(void);

#endif  /* __INTC_LLD_H_ */
