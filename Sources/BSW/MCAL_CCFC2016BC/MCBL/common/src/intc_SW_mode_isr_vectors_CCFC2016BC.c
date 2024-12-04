/*****************************************************************************/
/* FILE NAME: intc_SW_mode_isr_vectors_MPC5744P.c COPYRIGHT(c) Freescale 2015*/
/*                                                      All Rights Reserved  */
/* DESCRIPTION: MPC5744P ISR vectors for INTC in software vector mode        */
/*              Based on MPC5744P ref manual rev 5.1 Table 7-20.             */
/* USAGE:  For desired vector #, replace "dummy" with ISR name and declare   */
/*         your isr name extern like the example below:                      */
/*                       extern void MyPeripheralISR(void);                  */
/*                                                                           */
/*****************************************************************************/
/* REV      AUTHOR        DATE        DESCRIPTION OF CHANGE                  */
/* ---   -----------    ----------    ---------------------                  */
/* 1.0     S Mihalik     03 Aug 2015   Initial version                        */
/*****************************************************************************/
#include "typedefs.h"

/*========================================================================*/
/*    PROTOTYPES                                                    */
/*========================================================================*/
void dummy                   (void);
extern void Mcal_GPT_PIT0_Isr(void);
extern void Mcal_GPT_PIT1_Isr(void);
extern void Mcal_GPT_PIT2_Isr(void);
extern void Mcal_GPT_PIT3_Isr(void);
//extern void Mcal_GPT_STM_Isr(void);
//extern void ISR_ETimer0(void);
//extern void ISR_ETimer1(void);
//extern void ISR_ETimer2(void);
extern void Mcal_CAN_Error_Isr(void);
extern void Mcal_CAN_BusOffWARN_Isr(void);
extern void Mcal_CAN0_BUF00_31_Isr(void);
extern void Mcal_CAN1_BUF00_31_Isr(void);
extern void Mcal_CAN2_BUF00_31_Isr(void);
extern void Mcal_CAN3_BUF00_31_Isr(void);
extern void Mcal_CAN0_BUF32_63_Isr(void);
extern void Mcal_CAN1_BUF32_63_Isr(void);
extern void Mcal_CAN2_BUF32_63_Isr(void);
extern void Mcal_CAN3_BUF32_63_Isr(void);
extern void Mcal_CANFD0_Isr(void);
extern void Mcal_CANFD1_Isr(void);
extern void Mcal_CANFD2_Isr(void);
extern void Mcal_CANFD3_Isr(void);
//extern void Mcal_EXINT_CAN3_RX_Isr(void);
//extern void Mcal_LIN_RX_Isr(void);
//extern void Mcal_LIN_TX_Isr(void);
extern void Mcal_INTC_SS0_ISR(void);
extern void Mcal_INTC_SS1_ISR(void);
extern void Mcal_INTC_SS2_ISR(void);
extern void Mcal_INTC_SS3_ISR(void);
//extern void Mcal_INTC_SS4_ISR(void);
//extern void Mcal_INTC_SS5_ISR(void);
//extern void Mcal_INTC_SS6_ISR(void);
//extern void Mcal_INTC_SS7_ISR(void);
//extern void I2C_LLD_IRQHandler0(void);
//extern void I2C_LLD_IRQHandler1(void);
//extern void I2C_LLD_IRQHandler2(void);
//extern void I2C_LLD_IRQHandler3(void);
/*========================================================================*/
/* GLOBAL VARIABLES                                               */
/*========================================================================*/

#pragma push /* Save the current state */
#pragma section data_type ".__uninitialized_intc_handlertable" ".__uninitialized_intc_handlertable"
volatile uint32_t IntcIsrVectorTable[] = {
    
(uint32_t) &Mcal_INTC_SS0_ISR, /* Vector #   0 SOFT_CFG_FLAG_0_IRQn */
(uint32_t) &Mcal_INTC_SS1_ISR, /* Vector #   1 SOFT_CFG_FLAG_1_IRQn */
(uint32_t) &Mcal_INTC_SS2_ISR, /* Vector #   2 SOFT_CFG_FLAG_2_IRQn */
(uint32_t) &Mcal_INTC_SS3_ISR, /* Vector #   3 SOFT_CFG_FLAG_3_IRQn */
(uint32_t) &dummy, /* Vector #   4 SOFT_CFG_FLAG_4_IRQn */
(uint32_t) &dummy, /* Vector #   5 SOFT_CFG_FLAG_5_IRQn */
(uint32_t) &dummy, /* Vector #   6 SOFT_CFG_FLAG_6_IRQn */
(uint32_t) &dummy, /* Vector #   7 SOFT_CFG_FLAG_7_IRQn */
(uint32_t) &dummy, /* Vector #   8 RESERVED_IRQ8 */
(uint32_t) &dummy, /* Vector #   9 PFLASH_ABORT_STALL_IRQn */
(uint32_t) &dummy, /* Vector #  10 RESERVED_IRQ10 */
(uint32_t) &dummy, /* Vector #  11 EDMA_CH0_IRQn */
(uint32_t) &dummy, /* Vector #  12 EDMA_CH1_IRQn */
(uint32_t) &dummy, /* Vector #  13 EDMA_CH2_IRQn */
(uint32_t) &dummy, /* Vector #  14 EDMA_CH3_IRQn */
(uint32_t) &dummy, /* Vector #  15 EDMA_CH4_IRQn */
(uint32_t) &dummy, /* Vector #  16 EDMA_CH5_IRQn */
(uint32_t) &dummy, /* Vector #  17 EDMA_CH6_IRQn */
(uint32_t) &dummy, /* Vector #  18 EDMA_CH7_IRQn */
(uint32_t) &dummy, /* Vector #  19 EDMA_CH8_IRQn */
(uint32_t) &dummy, /* Vector #  20 EDMA_CH9_IRQn */
(uint32_t) &dummy, /* Vector #  21 EDMA_CH10_IRQn */
(uint32_t) &dummy, /* Vector #  22 EDMA_CH11_IRQn */
(uint32_t) &dummy, /* Vector #  23 EDMA_CH12_IRQn */
(uint32_t) &dummy, /* Vector #  24 EDMA_CH13_IRQn */
(uint32_t) &dummy, /* Vector #  25 EDMA_CH14_IRQn */
(uint32_t) &dummy, /* Vector #  26 EDMA_CH15_IRQn */
(uint32_t) &dummy, /* Vector #  27 RESERVED_IRQ27 */
(uint32_t) &dummy, /* Vector #  28 SWT_TIMEOUT_IRQn */
(uint32_t) &dummy, /* Vector #  29 RESERVED_IRQ29 */
(uint32_t) &dummy, /* Vector #  30 STM_MATCH_ON_CH0_IRQn */
(uint32_t) &dummy, /* Vector #  31 STM_MATCH_ON_CH1_IRQn */
(uint32_t) &dummy, /* Vector #  32 STM_MATCH_ON_CH2_IRQn */
(uint32_t) &dummy, /* Vector #  33 STM_MATCH_ON_CH3_IRQn */
(uint32_t) &dummy, /* Vector #  34 RESERVED_IRQ34 */
(uint32_t) &dummy, /* Vector #  35 ECC_DBD_PFLASH_PRAM_IRQn */
(uint32_t) &dummy, /* Vector #  36 ECC_SBC_PFLASH_PRAM_IRQn */
(uint32_t) &dummy, /* Vector #  37 RESERVED_IRQ37 */
(uint32_t) &dummy, /* Vector #  38 RTC_IRQn */
(uint32_t) &dummy, /* Vector #  39 API_IRQn */
(uint32_t) &dummy, /* Vector #  40 RESERVED_IRQ40 */
(uint32_t) &dummy, /* Vector #  41 SIU_EXTI0_7_IRQn */
(uint32_t) &dummy, /* Vector #  42 SIU_EXTI8_15_IRQn */
(uint32_t) &dummy, /* Vector #  43 SIU_EXTI16_23_IRQn */
(uint32_t) &dummy, /* Vector #  44 RESERVED_IRQ44 */
(uint32_t) &dummy, /* Vector #  45 RESERVED_IRQ45 */
(uint32_t) &dummy, /* Vector #  46 WKPU_0_7_IRQn */
(uint32_t) &dummy, /* Vector #  47 WKPU_8_15_IRQn */
(uint32_t) &dummy, /* Vector #  48 WKPU_16_23_IRQn */
(uint32_t) &dummy, /* Vector #  49 WKPU_24_31_IRQn */
(uint32_t) &dummy, /* Vector #  50 RESERVED_IRQ50 */
(uint32_t) &dummy, /* Vector #  51 MC_ME_SAFE_MODE_IRQn */
(uint32_t) &dummy, /* Vector #  52 MC_ME_MODE_TRANS_IRQn */
(uint32_t) &dummy, /* Vector #  53 MC_ME_INVALID_MODE_IRQn */
(uint32_t) &dummy, /* Vector #  54 MC_ME_INVALID_MODE_CFG_IRQn */
(uint32_t) &dummy, /* Vector #  55 RESERVED_IRQ55 */
(uint32_t) &dummy, /* Vector #  56 MC_RGM_IPI_IRQn */
(uint32_t) &dummy, /* Vector #  57 MC_CGM_FXOSC_IRQn */
(uint32_t) &dummy, /* Vector #  58 RESERVED_IRQ58 */
(uint32_t) &Mcal_GPT_PIT0_Isr, /* Vector #  59 PIT_CH0_IRQn */
(uint32_t) &Mcal_GPT_PIT1_Isr, /* Vector #  60 PIT_CH1_IRQn */
(uint32_t) &Mcal_GPT_PIT2_Isr, /* Vector #  61 PIT_CH2_IRQn */
(uint32_t) &dummy, /* Vector #  62 ADC0_EOC_IRQn */
(uint32_t) &dummy, /* Vector #  63 RESERVED_IRQ63 */
(uint32_t) &dummy, /* Vector #  64 ADC0_WD_IRQn */
(uint32_t) &Mcal_CAN_Error_Isr, /* Vector #  65 FLEXCAN0_ESR_ERR_IRQn */
(uint32_t) &Mcal_CAN_BusOffWARN_Isr, /* Vector #  66 FLEXCAN0_ESR_TX_RX_IRQn */
(uint32_t) &dummy, /* Vector #  67 RESERVED_IRQ67 */
(uint32_t) &Mcal_CAN0_BUF00_31_Isr, /* Vector #  68 FLEXCAN0_BUF_00_03_IRQn */
(uint32_t) &Mcal_CAN0_BUF00_31_Isr, /* Vector #  69 FLEXCAN0_BUF_04_07_IRQn */
(uint32_t) &Mcal_CAN0_BUF00_31_Isr, /* Vector #  70 FLEXCAN0_BUF_08_11_IRQn */
(uint32_t) &Mcal_CAN0_BUF00_31_Isr, /* Vector #  71 FLEXCAN0_BUF_12_15_IRQn */
(uint32_t) &Mcal_CAN0_BUF00_31_Isr, /* Vector #  72 FLEXCAN0_BUF_16_31_IRQn */
(uint32_t) &Mcal_CAN0_BUF32_63_Isr, /* Vector #  73 FLEXCAN0_BUF_32_63_IRQn */
(uint32_t) &dummy, /* Vector #  74 DSPI0_SR_TFUF_RFOF_IRQn */
(uint32_t) &dummy, /* Vector #  75 DSPI0_SR_EOQF_IRQn */
(uint32_t) &dummy, /* Vector #  76 DSPI0_SR_TFFF_IRQn */
(uint32_t) &dummy, /* Vector #  77 DSPI0_SR_TCF_IRQn */
(uint32_t) &dummy, /* Vector #  78 DSPI0_SR_RFDF_IRQn */
(uint32_t) &dummy, /* Vector #  79 LINFLEX0_RXI_IRQn */
(uint32_t) &dummy, /* Vector #  80 LINFLEX0_TXI_IRQn */
(uint32_t) &dummy, /* Vector #  81 LINFLEX0_ERR_IRQn */
(uint32_t) &dummy, /* Vector #  82 ADC1_EOC_IRQn */
(uint32_t) &dummy, /* Vector #  83 RESERVED_IRQ83 */
(uint32_t) &dummy, /* Vector #  84 ADC1_WD_IRQn */
(uint32_t) &Mcal_CAN_Error_Isr, /* Vector #  85 FLEXCAN1_ESR_ERR_IRQn */
(uint32_t) &Mcal_CAN_BusOffWARN_Isr, /* Vector #  86 FLEXCAN1_ESR_TX_RX_IRQn */
(uint32_t) &dummy, /* Vector #  87 FLEXCAN1_ESR_WAK_IRQn */
(uint32_t) &Mcal_CAN1_BUF00_31_Isr, /* Vector #  88 FLEXCAN1_BUF_00_03_IRQn */
(uint32_t) &Mcal_CAN1_BUF00_31_Isr, /* Vector #  89 FLEXCAN1_BUF_04_07_IRQn */
(uint32_t) &Mcal_CAN1_BUF00_31_Isr, /* Vector #  90 FLEXCAN1_BUF_08_11_IRQn */
(uint32_t) &Mcal_CAN1_BUF00_31_Isr, /* Vector #  91 FLEXCAN1_BUF_12_15_IRQn */
(uint32_t) &Mcal_CAN1_BUF00_31_Isr, /* Vector #  92 FLEXCAN1_BUF_16_31_IRQn */
(uint32_t) &Mcal_CAN1_BUF32_63_Isr, /* Vector #  93 FLEXCAN1_BUF_32_63_IRQn */
(uint32_t) &dummy, /* Vector #  94 DSPI1_SR_TFUF_RFOF_IRQn */
(uint32_t) &dummy, /* Vector #  95 DSPI1_SR_EOQF_IRQn */
(uint32_t) &dummy, /* Vector #  96 DSPI1_SR_TFFF_IRQn */
(uint32_t) &dummy, /* Vector #  97 DSPI1_SR_TCF_IRQn */
(uint32_t) &dummy, /* Vector #  98 DSPI1_SR_RFDF_IRQn */
(uint32_t) &dummy, /* Vector #  99 LINFLEX1_RXI_IRQn */

(uint32_t) &dummy, /* Vector # 100 LINFLEX1_TXI_IRQn */
(uint32_t) &dummy, /* Vector # 101 LINFLEX1_ERR_IRQn */
(uint32_t) &dummy, /* Vector # 102 RESERVED_IRQ102 */
(uint32_t) &dummy, /* Vector # 103 RESERVED_IRQ103 */
(uint32_t) &dummy, /* Vector # 104 RESERVED_IRQ104 */
(uint32_t) &Mcal_CAN_Error_Isr, /* Vector # 105 FLEXCAN2_ESR_ERR_IRQn */
(uint32_t) &Mcal_CAN_BusOffWARN_Isr, /* Vector # 106 FLEXCAN2_ESR_TX_RX_IRQn */
(uint32_t) &dummy, /* Vector # 107 RESERVED_IRQ107 */
(uint32_t) &Mcal_CAN2_BUF00_31_Isr, /* Vector # 108 FLEXCAN2_BUF_00_03_IRQn */
(uint32_t) &Mcal_CAN2_BUF00_31_Isr, /* Vector # 109 FLEXCAN2_BUF_04_07_IRQn */
(uint32_t) &Mcal_CAN2_BUF00_31_Isr, /* Vector # 110 FLEXCAN2_BUF_08_11_IRQn */
(uint32_t) &Mcal_CAN2_BUF00_31_Isr, /* Vector # 111 FLEXCAN2_BUF_12_15_IRQn */
(uint32_t) &Mcal_CAN2_BUF00_31_Isr, /* Vector # 112 FLEXCAN2_BUF_16_31_IRQn */
(uint32_t) &Mcal_CAN2_BUF32_63_Isr, /* Vector # 113 FLEXCAN2_BUF_32_63_IRQn */
(uint32_t) &dummy, /* Vector # 114 DSPI2_SR_TFUF_RFOF_IRQn */
(uint32_t) &dummy, /* Vector # 115 DSPI2_SR_EOQF_IRQn */
(uint32_t) &dummy, /* Vector # 116 DSPI2_SR_TFFF_IRQn */
(uint32_t) &dummy, /* Vector # 117 DSPI2_SR_TCF_IRQn */
(uint32_t) &dummy, /* Vector # 118 DSPI2_SR_RFDF_IRQn */
(uint32_t) &dummy, /* Vector # 119 LINFLEX2_RXI_IRQn */
(uint32_t) &dummy, /* Vector # 120 LINFLEX2_TXI_IRQn */
(uint32_t) &dummy, /* Vector # 121 LINFLEX2_ERR_IRQn */
(uint32_t) &dummy, /* Vector # 122 LINFLEX3_RXI_IRQn */
(uint32_t) &dummy, /* Vector # 123 LINFLEX3_TXI_IRQn */
(uint32_t) &dummy, /* Vector # 124 LINFLEX3_ERR_IRQn */
(uint32_t) &dummy, /* Vector # 125 I2C0_SR_IRQn */
(uint32_t) &dummy, /* Vector # 126 I2C1_SR_IRQn */
(uint32_t) &Mcal_GPT_PIT3_Isr, /* Vector # 127 PIT_CH3_IRQn */
(uint32_t) &dummy, /* Vector # 128 PIT_CH4_IRQn */
(uint32_t) &dummy, /* Vector # 129 PIT_CH5_IRQn */
(uint32_t) &dummy, /* Vector # 130 PIT_CH6_IRQn */
(uint32_t) &dummy, /* Vector # 131 PIT_CH7_IRQn */
(uint32_t) &dummy, /* Vector # 132 LINFLEX10_RXI_IRQn */
(uint32_t) &dummy, /* Vector # 133 LINFLEX10_TXI_IRQn */
(uint32_t) &dummy, /* Vector # 134 LINFLEX10_ERR_IRQn */
(uint32_t) &dummy, /* Vector # 135 LINFLEX11_RXI_IRQn */
(uint32_t) &dummy, /* Vector # 136 LINFLEX11_TXI_IRQn */
(uint32_t) &dummy, /* Vector # 137 LINFLEX11_ERR_IRQn */
(uint32_t) &dummy, /* Vector # 138 I2C2_SR_IRQn */
(uint32_t) &dummy, /* Vector # 139 I2C3_SR_IRQn */
(uint32_t) &dummy, /* Vector # 140 RESERVED_IRQ140 */
(uint32_t) &dummy, /* Vector # 141 EMIOS0_GFR_F0_F1_IRQn */
(uint32_t) &dummy, /* Vector # 142 EMIOS0_GFR_F2_F3_IRQn */
(uint32_t) &dummy, /* Vector # 143 EMIOS0_GFR_F4_F5_IRQn */
(uint32_t) &dummy, /* Vector # 144 EMIOS0_GFR_F6_F7_IRQn */
(uint32_t) &dummy, /* Vector # 145 EMIOS0_GFR_F8_F9_IRQn */
(uint32_t) &dummy, /* Vector # 146 EMIOS0_GFR_F10_F11_IRQn */
(uint32_t) &dummy, /* Vector # 147 EMIOS0_GFR_F12_F13_IRQn */
(uint32_t) &dummy, /* Vector # 148 EMIOS0_GFR_F14_F15_IRQn */
(uint32_t) &dummy, /* Vector # 149 EMIOS0_GFR_F16_F17_IRQn */
(uint32_t) &dummy, /* Vector # 150 EMIOS0_GFR_F18_F19_IRQn */
(uint32_t) &dummy, /* Vector # 151 EMIOS0_GFR_F20_F21_IRQn */
(uint32_t) &dummy, /* Vector # 152 EMIOS0_GFR_F22_F23_IRQn */
(uint32_t) &dummy, /* Vector # 153 EMIOS0_GFR_F24_F25_IRQn */
(uint32_t) &dummy, /* Vector # 154 EMIOS0_GFR_F26_F27_IRQn */
(uint32_t) &dummy, /* Vector # 155 EMIOS0_GFR_F28_F29_IRQn */
(uint32_t) &dummy, /* Vector # 156 EMIOS0_GFR_F30_F31_IRQn */
(uint32_t) &dummy, /* Vector # 157 EMIOS1_GFR_F0_F1_IRQn */
(uint32_t) &dummy, /* Vector # 158 EMIOS1_GFR_F2_F3_IRQn */
(uint32_t) &dummy, /* Vector # 159 EMIOS1_GFR_F4_F5_IRQn */
(uint32_t) &dummy, /* Vector # 160 EMIOS1_GFR_F6_F7_IRQn */
(uint32_t) &dummy, /* Vector # 161 EMIOS1_GFR_F8_F9_IRQn */
(uint32_t) &dummy, /* Vector # 162 EMIOS1_GFR_F10_F11_IRQn */
(uint32_t) &dummy, /* Vector # 163 EMIOS1_GFR_F12_F13_IRQn */
(uint32_t) &dummy, /* Vector # 164 EMIOS1_GFR_F14_F15_IRQn */
(uint32_t) &dummy, /* Vector # 165 EMIOS1_GFR_F16_F17_IRQn */
(uint32_t) &dummy, /* Vector # 166 EMIOS1_GFR_F18_F19_IRQn */
(uint32_t) &dummy, /* Vector # 167 EMIOS1_GFR_F20_F21_IRQn */
(uint32_t) &dummy, /* Vector # 168 EMIOS1_GFR_F22_F23_IRQn */
(uint32_t) &dummy, /* Vector # 169 EMIOS1_GFR_F24_F25_IRQn */
(uint32_t) &dummy, /* Vector # 170 EMIOS1_GFR_F26_F27_IRQn */
(uint32_t) &dummy, /* Vector # 171 EMIOS1_GFR_F28_F29_IRQn */
(uint32_t) &dummy, /* Vector # 172 EMIOS1_GFR_F30_F31_IRQn */
(uint32_t) &Mcal_CAN_Error_Isr, /* Vector # 173 FLEXCAN3_ESR_ERR_IRQn */
(uint32_t) &Mcal_CAN_BusOffWARN_Isr, /* Vector # 174 FLEXCAN3_ESR_TX_RX_IRQn */
(uint32_t) &dummy, /* Vector # 175 RESERVED_IRQ175 */
(uint32_t) &Mcal_CAN3_BUF00_31_Isr, /* Vector # 176 FLEXCAN3_BUF_00_03_IRQn */
(uint32_t) &Mcal_CAN3_BUF00_31_Isr, /* Vector # 177 FLEXCAN3_BUF_04_07_IRQn */
(uint32_t) &Mcal_CAN3_BUF00_31_Isr, /* Vector # 178 FLEXCAN3_BUF_08_11_IRQn */
(uint32_t) &Mcal_CAN3_BUF00_31_Isr, /* Vector # 179 FLEXCAN3_BUF_12_15_IRQn */
(uint32_t) &Mcal_CAN3_BUF00_31_Isr, /* Vector # 180 FLEXCAN3_BUF_16_31_IRQn */
(uint32_t) &Mcal_CAN3_BUF32_63_Isr, /* Vector # 181 FLEXCAN3_BUF_32_63_IRQn */
(uint32_t) &dummy, /* Vector # 182 DSPI3_SR_TFUF_RFOF_IRQn */
(uint32_t) &dummy, /* Vector # 183 DSPI3_SR_EOQF_IRQn */
(uint32_t) &dummy, /* Vector # 184 DSPI3_SR_TFFF_IRQn */
(uint32_t) &dummy, /* Vector # 185 DSPI3_SR_TCF_IRQn */
(uint32_t) &dummy, /* Vector # 186 DSPI3_SR_RFDF_IRQn */
(uint32_t) &dummy, /* Vector # 187 LINFLEX4_RXI_IRQn */
(uint32_t) &dummy, /* Vector # 188 LINFLEX4_TXI_IRQn */
(uint32_t) &dummy, /* Vector # 189 LINFLEX4_ERR_IRQn */
(uint32_t) &dummy, /* Vector # 190 FLEXCAN4_ESR_ERR_IRQn */
(uint32_t) &dummy, /* Vector # 191 FLEXCAN4_ESR_TX_RX_IRQn */
(uint32_t) &dummy, /* Vector # 192 RESERVED_IRQ192 */
(uint32_t) &dummy, /* Vector # 193 FLEXCAN4_BUF_00_03_IRQn */
(uint32_t) &dummy, /* Vector # 194 FLEXCAN4_BUF_04_07_IRQn */
(uint32_t) &dummy, /* Vector # 195 FLEXCAN4_BUF_08_11_IRQn */
(uint32_t) &dummy, /* Vector # 196 FLEXCAN4_BUF_12_15_IRQn */
(uint32_t) &dummy, /* Vector # 197 FLEXCAN4_BUF_16_31_IRQn */
(uint32_t) &dummy, /* Vector # 198 FLEXCAN4_BUF_32_63_IRQn */
(uint32_t) &dummy, /* Vector # 199 LINFLEX5_RXI_IRQn */

(uint32_t) &dummy, /* Vector # 200 LINFLEX5_TXI_IRQn */
(uint32_t) &dummy, /* Vector # 201 LINFLEX5_ERR_IRQn */
(uint32_t) &dummy, /* Vector # 202 FLEXCAN5_ESR_ERR_IRQn */
(uint32_t) &dummy, /* Vector # 203 FLEXCAN5_ESR_TX_RX_IRQn */
(uint32_t) &dummy, /* Vector # 204 RESERVED_IRQ204 */
(uint32_t) &dummy, /* Vector # 205 FLEXCAN5_BUF_00_03_IRQn */
(uint32_t) &dummy, /* Vector # 206 FLEXCAN5_BUF_04_07_IRQn */
(uint32_t) &dummy, /* Vector # 207 FLEXCAN5_BUF_08_11_IRQn */
(uint32_t) &dummy, /* Vector # 208 FLEXCAN5_BUF_12_15_IRQn */
(uint32_t) &dummy, /* Vector # 209 FLEXCAN5_BUF_16_31_IRQn */
(uint32_t) &dummy, /* Vector # 210 FLEXCAN5_BUF_32_63_IRQn */
(uint32_t) &dummy, /* Vector # 211 DSPI4_SR_TFUF_RFOF_IRQn */
(uint32_t) &dummy, /* Vector # 212 DSPI4_SR_EOQF_IRQn */
(uint32_t) &dummy, /* Vector # 213 DSPI4_SR_TFFF_IRQn */
(uint32_t) &dummy, /* Vector # 214 DSPI4_SR_TCF_IRQn */
(uint32_t) &dummy, /* Vector # 215 DSPI4_SR_RFDF_IRQn */
(uint32_t) &dummy, /* Vector # 216 LINFLEX6_RXI_IRQn */
(uint32_t) &dummy, /* Vector # 217 LINFLEX6_TXI_IRQn */
(uint32_t) &dummy, /* Vector # 218 LINFLEX6_ERR_IRQn */
(uint32_t) &dummy, /* Vector # 219 DSPI5_SR_TFUF_RFOF_IRQn */
(uint32_t) &dummy, /* Vector # 220 DSPI5_SR_EOQF_IRQn */
(uint32_t) &dummy, /* Vector # 221 DSPI5_SR_TFFF_IRQn */
(uint32_t) &dummy, /* Vector # 222 DSPI5_SR_TCF_IRQn */
(uint32_t) &dummy, /* Vector # 223 DSPI5_SR_RFDF_IRQn */
(uint32_t) &dummy, /* Vector # 224 LINFLEX7_RXI_IRQn */
(uint32_t) &dummy, /* Vector # 225 LINFLEX7_TXI_IRQn */
(uint32_t) &dummy, /* Vector # 226 LINFLEX7_ERR_IRQn */
(uint32_t) &dummy, /* Vector # 227 LINFLEX8_RXI_IRQn */
(uint32_t) &dummy, /* Vector # 228 LINFLEX8_TXI_IRQn */
(uint32_t) &dummy, /* Vector # 229 LINFLEX8_ERR_IRQn */
(uint32_t) &dummy, /* Vector # 230 LINFLEX9_RXI_IRQn */
(uint32_t) &dummy, /* Vector # 231 LINFLEX9_TXI_IRQn */
(uint32_t) &dummy, /* Vector # 232 LINFLEX9_ERR_IRQn */
(uint32_t) &dummy, /* Vector # 233 MC_CGM_SXOSC_IRQn */
(uint32_t) &Mcal_CANFD0_Isr, /* Vector # 234 CANFD0_IRQn */
(uint32_t) &Mcal_CANFD1_Isr, /* Vector # 235 CANFD1_IRQn */
(uint32_t) &Mcal_CANFD2_Isr, /* Vector # 236 CANFD2_IRQn */
(uint32_t) &Mcal_CANFD3_Isr, /* Vector # 237 CANFD3_IRQn */
(uint32_t) &dummy, /* Vector # 238 CANFD4_IRQn */
(uint32_t) &dummy, /* Vector # 239 CANFD5_IRQn */
(uint32_t) &dummy, /* Vector # 240 CANFD6_IRQn */
(uint32_t) &dummy, /* Vector # 241 CANFD7_IRQn */
(uint32_t) &dummy, /* Vector # 242 ADC0_RFIFO_DRAIN_IRQn */
(uint32_t) &dummy, /* Vector # 243 ADC0_RFIFO_OV_IRQn */
(uint32_t) &dummy, /* Vector # 244 ADC1_RFIFO_DRAIN_IRQn */
(uint32_t) &dummy, /* Vector # 245 ADC1_RFIFO_OV_IRQn */
(uint32_t) &dummy, /* Vector # 246 FLEXCAN6_ESR_ERR_IRQn */
(uint32_t) &dummy, /* Vector # 247 FLEXCAN6_ESR_TX_RX_IRQn */
(uint32_t) &dummy, /* Vector # 248 RESERVED_IRQ248 */
(uint32_t) &dummy, /* Vector # 249 FLEXCAN6_BUF_00_03_IRQn */
(uint32_t) &dummy, /* Vector # 250 FLEXCAN6_BUF_04_07_IRQn */
(uint32_t) &dummy, /* Vector # 251 FLEXCAN6_BUF_08_11_IRQn */
(uint32_t) &dummy, /* Vector # 252 FLEXCAN6_BUF_12_15_IRQn */
(uint32_t) &dummy, /* Vector # 253 FLEXCAN6_BUF_16_31_IRQn */
(uint32_t) &dummy, /* Vector # 254 FLEXCAN6_BUF_32_63_IRQn */
(uint32_t) &dummy, /* Vector # 255 FLEXCAN7_ESR_ERR_IRQn */
(uint32_t) &dummy, /* Vector # 256 FLEXCAN7_ESR_TX_RX_IRQn */
(uint32_t) &dummy, /* Vector # 257 RESERVED_IRQ257 */
(uint32_t) &dummy, /* Vector # 258 FLEXCAN7_BUF_00_03_IRQn */
(uint32_t) &dummy, /* Vector # 259 FLEXCAN7_BUF_04_07_IRQn */
(uint32_t) &dummy, /* Vector # 260 FLEXCAN7_BUF_08_11_IRQn */
(uint32_t) &dummy, /* Vector # 261 FLEXCAN7_BUF_12_15_IRQn */
(uint32_t) &dummy, /* Vector # 262 FLEXCAN7_BUF_16_31_IRQn */
(uint32_t) &dummy, /* Vector # 263 FLEXCAN7_BUF_32_63_IRQn */
(uint32_t) &dummy, /* Vector # 264 ETPU1_CH0_IRQn */
(uint32_t) &dummy, /* Vector # 265 ETPU1_CH1_IRQn */
(uint32_t) &dummy, /* Vector # 266 ETPU1_CH2_IRQn */
(uint32_t) &dummy, /* Vector # 267 ETPU1_CH3_IRQn */
(uint32_t) &dummy, /* Vector # 268 ETPU1_CH4_IRQn */
(uint32_t) &dummy, /* Vector # 269 ETPU1_CH5_IRQn */
(uint32_t) &dummy, /* Vector # 270 ETPU1_CH6_IRQn */
(uint32_t) &dummy, /* Vector # 271 ETPU1_CH7_IRQn */
(uint32_t) &dummy, /* Vector # 272 ETPU1_CH8_IRQn */
(uint32_t) &dummy, /* Vector # 273 ETPU1_CH9_IRQn */
(uint32_t) &dummy, /* Vector # 274 ETPU1_CH10_IRQn */
(uint32_t) &dummy, /* Vector # 275 ETPU1_CH11_IRQn */
(uint32_t) &dummy, /* Vector # 276 ETPU1_CH12_IRQn */
(uint32_t) &dummy, /* Vector # 277 ETPU1_CH13_IRQn */
(uint32_t) &dummy, /* Vector # 278 ETPU1_CH14_IRQn */
(uint32_t) &dummy, /* Vector # 279 ETPU1_CH15_IRQn */
(uint32_t) &dummy, /* Vector # 280 ETPU1_CH16_IRQn */
(uint32_t) &dummy, /* Vector # 281 ETPU1_CH17_IRQn */
(uint32_t) &dummy, /* Vector # 282 ETPU1_CH18_IRQn */
(uint32_t) &dummy, /* Vector # 283 ETPU1_CH19_IRQn */
(uint32_t) &dummy, /* Vector # 284 ETPU1_CH20_IRQn */
(uint32_t) &dummy, /* Vector # 285 ETPU1_CH21_IRQn */
(uint32_t) &dummy, /* Vector # 286 ETPU1_CH22_IRQn */
(uint32_t) &dummy, /* Vector # 287 ETPU1_CH23_IRQn */
(uint32_t) &dummy, /* Vector # 288 ETPU1_CH24_IRQn */
(uint32_t) &dummy, /* Vector # 289 ETPU1_CH25_IRQn */
(uint32_t) &dummy, /* Vector # 290 ETPU1_CH26_IRQn */
(uint32_t) &dummy, /* Vector # 291 ETPU1_CH27_IRQn */
(uint32_t) &dummy, /* Vector # 292 ETPU1_CH28_IRQn */
(uint32_t) &dummy, /* Vector # 293 ETPU1_CH29_IRQn */
(uint32_t) &dummy, /* Vector # 294 ETPU1_CH30_IRQn */
(uint32_t) &dummy, /* Vector # 295 ETPU1_CH31_IRQn */
(uint32_t) &dummy, /* Vector # 296 ETPU2_CH0_IRQn */
(uint32_t) &dummy, /* Vector # 297 ETPU2_CH1_IRQn */
(uint32_t) &dummy, /* Vector # 298 ETPU2_CH2_IRQn */
(uint32_t) &dummy, /* Vector # 299 ETPU2_CH3_IRQn */
(uint32_t) &dummy, /* Vector # 300 ETPU2_CH4_IRQn */
(uint32_t) &dummy, /* Vector # 301 ETPU2_CH5_IRQn */
(uint32_t) &dummy, /* Vector # 302 ETPU2_CH6_IRQn */
(uint32_t) &dummy, /* Vector # 303 ETPU2_CH7_IRQn */
(uint32_t) &dummy, /* Vector # 304 ETPU2_CH8_IRQn */
(uint32_t) &dummy, /* Vector # 305 ETPU2_CH9_IRQn */
(uint32_t) &dummy, /* Vector # 306 ETPU2_CH10_IRQn */
(uint32_t) &dummy, /* Vector # 307 ETPU2_CH11_IRQn */
(uint32_t) &dummy, /* Vector # 308 ETPU2_CH12_IRQn */
(uint32_t) &dummy, /* Vector # 309 ETPU2_CH13_IRQn */
(uint32_t) &dummy, /* Vector # 310 ETPU2_CH14_IRQn */
(uint32_t) &dummy, /* Vector # 311 ETPU2_CH15_IRQn */
(uint32_t) &dummy, /* Vector # 312 ETPU2_CH16_IRQn */
(uint32_t) &dummy, /* Vector # 313 ETPU2_CH17_IRQn */
(uint32_t) &dummy, /* Vector # 314 ETPU2_CH18_IRQn */
(uint32_t) &dummy, /* Vector # 315 ETPU2_CH19_IRQn */
(uint32_t) &dummy, /* Vector # 316 ETPU2_CH20_IRQn */
(uint32_t) &dummy, /* Vector # 317 ETPU2_CH21_IRQn */
(uint32_t) &dummy, /* Vector # 318 ETPU2_CH22_IRQn */
(uint32_t) &dummy, /* Vector # 319 ETPU2_CH23_IRQn */
(uint32_t) &dummy, /* Vector # 320 ETPU2_CH24_IRQn */
(uint32_t) &dummy, /* Vector # 321 ETPU2_CH25_IRQn */
(uint32_t) &dummy, /* Vector # 322 ETPU2_CH26_IRQn */
(uint32_t) &dummy, /* Vector # 323 ETPU2_CH27_IRQn */
(uint32_t) &dummy, /* Vector # 324 ETPU2_CH28_IRQn */
(uint32_t) &dummy, /* Vector # 325 ETPU2_CH29_IRQn */
(uint32_t) &dummy, /* Vector # 326 ETPU2_CH30_IRQn */
(uint32_t) &dummy, /* Vector # 327 ETPU2_CH31_IRQn */
(uint32_t) &dummy, /* Vector # 328 ETPU_IPI_GLEX_IRQn */
(uint32_t) &dummy, /* Vector # 329 DSPI6_SR_TFUF_RFOF_IRQn */
(uint32_t) &dummy, /* Vector # 330 DSPI6_SR_EOQF_IRQn */
(uint32_t) &dummy, /* Vector # 331 DSPI6_SR_TFFF_IRQn */
(uint32_t) &dummy, /* Vector # 332 DSPI6_SR_TCF_IRQn */
(uint32_t) &dummy, /* Vector # 333 DSPI6_SR_RFDF_IRQn */
(uint32_t) &dummy, /* Vector # 334 DSPI7_SR_TFUF_RFOF_IRQn */
(uint32_t) &dummy, /* Vector # 335 DSPI7_SR_EOQF_IRQn */
(uint32_t) &dummy, /* Vector # 336 DSPI7_SR_TFFF_IRQn */
(uint32_t) &dummy, /* Vector # 337 DSPI7_SR_TCF_IRQn */
(uint32_t) &dummy, /* Vector # 338 DSPI7_SR_RFDF_IRQn */
(uint32_t) &dummy, /* Vector # 339 DSPI8_SR_TFUF_RFOF_IRQn */
(uint32_t) &dummy, /* Vector # 340 DSPI8_SR_EOQF_IRQn */
(uint32_t) &dummy, /* Vector # 341 DSPI8_SR_TFFF_IRQn */
(uint32_t) &dummy, /* Vector # 342 DSPI8_SR_TCF_IRQn */
(uint32_t) &dummy, /* Vector # 343 DSPI8_SR_RFDF_IRQn */
(uint32_t) &dummy, /* Vector # 344 DECFILTER_ERR_IRQn */
(uint32_t) &dummy, /* Vector # 345 DECFILTER_IN_IRQn */
(uint32_t) &dummy, /* Vector # 346 DECFILTER_OUT_IRQn */
(uint32_t) &dummy, /* Vector # 347 LINFLEX12_RXI_IRQn */
(uint32_t) &dummy, /* Vector # 348 LINFLEX12_TXI_IRQn */
(uint32_t) &dummy, /* Vector # 349 LINFLEX12_ERR_IRQn */
(uint32_t) &dummy, /* Vector # 350 LINFLEX13_RXI_IRQn */
(uint32_t) &dummy, /* Vector # 351 LINFLEX13_TXI_IRQn */
(uint32_t) &dummy, /* Vector # 352 LINFLEX13_ERR_IRQn */
(uint32_t) &dummy, /* Vector # 353 EDMA_IPI_16_IRQn */
(uint32_t) &dummy, /* Vector # 354 EDMA_IPI_17_IRQn */
(uint32_t) &dummy, /* Vector # 355 EDMA_IPI_18_IRQn */
(uint32_t) &dummy, /* Vector # 356 EDMA_IPI_19_IRQn */
(uint32_t) &dummy, /* Vector # 357 EDMA_IPI_20_IRQn */
(uint32_t) &dummy, /* Vector # 358 EDMA_IPI_21_IRQn */
(uint32_t) &dummy, /* Vector # 359 EDMA_IPI_22_IRQn */
(uint32_t) &dummy, /* Vector # 360 EDMA_IPI_23_IRQn */
(uint32_t) &dummy, /* Vector # 361 EDMA_ERR_63_22_IRQn */
(uint32_t) &dummy, /* Vector # 362 EDMA_ERR_31_0_IRQn */

};
#pragma pop

void dummy (void) {   /* Dummy ISR vector to trap undefined ISRs */
    while (1) {};  /* Wait forever or for watchdog timeout */
}
