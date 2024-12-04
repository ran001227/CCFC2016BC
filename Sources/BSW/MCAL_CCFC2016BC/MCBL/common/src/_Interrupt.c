/******************************************************************************
*	Copyright (c) ECO-EV Technologies Co., Ltd. 2018-2019.
*	All rights reserved.

*	File name:		_Interrupt.c
*	Author:			ECO-EV
*	Version:		V1.0.1
*	Date:			2018-4-28
*	Description:
*	Others:
*	History:
*
*	1. Date:
*	   Author:
*	   Modification:
*	2. ...
******************************************************************************/

/******************************************************************************
include
******************************************************************************/
#include "CCFC2016BC.h"//#include "MPC5744P.h"
#include "typedefs.h"
#include "_Interrupt.h"
//#include "compiler_api.h"

/******************************************************************************
Private constant Definitions
******************************************************************************/

#define ISR_COUNTMAX             (362U)

#define PRIORITY_0   (0U)   /* lowest priority */
#define PRIORITY_1   (1U)
#define PRIORITY_2   (2U)
#define PRIORITY_3   (3U)
#define PRIORITY_4   (4U)
#define PRIORITY_5   (5U)
#define PRIORITY_6   (6U)
#define PRIORITY_7   (7U)
#define PRIORITY_8   (8U)
#define PRIORITY_9   (9U)
#define PRIORITY_10  (10U)
#define PRIORITY_11  (11U)
#define PRIORITY_12  (12U)
#define PRIORITY_13  (13U)
#define PRIORITY_14  (14U)
#define PRIORITY_15  (15U)
#define PRIORITY_NULL   (16U)


/*========================================================================*/
/* GLOBAL VARIABLES   Priority                                         */
/*========================================================================*/
const uint8_t IntcIsrPriorityTable[] = {

(uint8_t) PRIORITY_13, /* Priority #   0 SOFT_CFG_FLAG_0_IRQn */
(uint8_t) PRIORITY_13, /* Priority #   1 SOFT_CFG_FLAG_1_IRQn */
(uint8_t) PRIORITY_13, /* Priority #   2 SOFT_CFG_FLAG_2_IRQn */
(uint8_t) PRIORITY_13, /* Priority #   3 SOFT_CFG_FLAG_3_IRQn */
(uint8_t) PRIORITY_13, /* Priority #   4 SOFT_CFG_FLAG_4_IRQn */
(uint8_t) PRIORITY_13, /* Priority #   5 SOFT_CFG_FLAG_5_IRQn */
(uint8_t) PRIORITY_13, /* Priority #   6 SOFT_CFG_FLAG_6_IRQn */
(uint8_t) PRIORITY_13, /* Priority #   7 SOFT_CFG_FLAG_7_IRQn */
(uint8_t) PRIORITY_0, /* Priority #   8 RESERVED_IRQ8 */
(uint8_t) PRIORITY_0, /* Priority #   9 PFLASH_ABORT_STALL_IRQn */
(uint8_t) PRIORITY_0, /* Priority #  10 RESERVED_IRQ10 */
(uint8_t) PRIORITY_0, /* Priority #  11 EDMA_CH0_IRQn */
(uint8_t) PRIORITY_0, /* Priority #  12 EDMA_CH1_IRQn */
(uint8_t) PRIORITY_0, /* Priority #  13 EDMA_CH2_IRQn */
(uint8_t) PRIORITY_0, /* Priority #  14 EDMA_CH3_IRQn */
(uint8_t) PRIORITY_0, /* Priority #  15 EDMA_CH4_IRQn */
(uint8_t) PRIORITY_0, /* Priority #  16 EDMA_CH5_IRQn */
(uint8_t) PRIORITY_0, /* Priority #  17 EDMA_CH6_IRQn */
(uint8_t) PRIORITY_0, /* Priority #  18 EDMA_CH7_IRQn */
(uint8_t) PRIORITY_0, /* Priority #  19 EDMA_CH8_IRQn */
(uint8_t) PRIORITY_0, /* Priority #  20 EDMA_CH9_IRQn */
(uint8_t) PRIORITY_0, /* Priority #  21 EDMA_CH10_IRQn */
(uint8_t) PRIORITY_0, /* Priority #  22 EDMA_CH11_IRQn */
(uint8_t) PRIORITY_0, /* Priority #  23 EDMA_CH12_IRQn */
(uint8_t) PRIORITY_0, /* Priority #  24 EDMA_CH13_IRQn */
(uint8_t) PRIORITY_0, /* Priority #  25 EDMA_CH14_IRQn */
(uint8_t) PRIORITY_0, /* Priority #  26 EDMA_CH15_IRQn */
(uint8_t) PRIORITY_0, /* Priority #  27 RESERVED_IRQ27 */
(uint8_t) PRIORITY_0, /* Priority #  28 SWT_TIMEOUT_IRQn */
(uint8_t) PRIORITY_0, /* Priority #  29 RESERVED_IRQ29 */
(uint8_t) PRIORITY_0, /* Priority #  30 STM_MATCH_ON_CH0_IRQn */
(uint8_t) PRIORITY_0, /* Priority #  31 STM_MATCH_ON_CH1_IRQn */
(uint8_t) PRIORITY_0, /* Priority #  32 STM_MATCH_ON_CH2_IRQn */
(uint8_t) PRIORITY_0, /* Priority #  33 STM_MATCH_ON_CH3_IRQn */
(uint8_t) PRIORITY_0, /* Priority #  34 RESERVED_IRQ34 */
(uint8_t) PRIORITY_0, /* Priority #  35 ECC_DBD_PFLASH_PRAM_IRQn */
(uint8_t) PRIORITY_0, /* Priority #  36 ECC_SBC_PFLASH_PRAM_IRQn */
(uint8_t) PRIORITY_0, /* Priority #  37 RESERVED_IRQ37 */
(uint8_t) PRIORITY_0, /* Priority #  38 RTC_IRQn */
(uint8_t) PRIORITY_0, /* Priority #  39 API_IRQn */
(uint8_t) PRIORITY_0, /* Priority #  40 RESERVED_IRQ40 */
(uint8_t) PRIORITY_0, /* Priority #  41 SIU_EXTI0_7_IRQn */
(uint8_t) PRIORITY_0, /* Priority #  42 SIU_EXTI8_15_IRQn */
(uint8_t) PRIORITY_0, /* Priority #  43 SIU_EXTI16_23_IRQn */
(uint8_t) PRIORITY_0, /* Priority #  44 RESERVED_IRQ44 */
(uint8_t) PRIORITY_0, /* Priority #  45 RESERVED_IRQ45 */
(uint8_t) PRIORITY_0, /* Priority #  46 WKPU_0_7_IRQn */
(uint8_t) PRIORITY_0, /* Priority #  47 WKPU_8_15_IRQn */
(uint8_t) PRIORITY_0, /* Priority #  48 WKPU_16_23_IRQn */
(uint8_t) PRIORITY_0, /* Priority #  49 WKPU_24_31_IRQn */
(uint8_t) PRIORITY_0, /* Priority #  50 RESERVED_IRQ50 */
(uint8_t) PRIORITY_0, /* Priority #  51 MC_ME_SAFE_MODE_IRQn */
(uint8_t) PRIORITY_0, /* Priority #  52 MC_ME_MODE_TRANS_IRQn */
(uint8_t) PRIORITY_0, /* Priority #  53 MC_ME_INVALID_MODE_IRQn */
(uint8_t) PRIORITY_0, /* Priority #  54 MC_ME_INVALID_MODE_CFG_IRQn */
(uint8_t) PRIORITY_0, /* Priority #  55 RESERVED_IRQ55 */
(uint8_t) PRIORITY_0, /* Priority #  56 MC_RGM_IPI_IRQn */
(uint8_t) PRIORITY_0, /* Priority #  57 MC_CGM_FXOSC_IRQn */
(uint8_t) PRIORITY_0, /* Priority #  58 RESERVED_IRQ58 */
(uint8_t) PRIORITY_14, /* Priority #  59 PIT_CH0_IRQn */
(uint8_t) PRIORITY_14, /* Priority #  60 PIT_CH1_IRQn */
(uint8_t) PRIORITY_14, /* Priority #  61 PIT_CH2_IRQn */
(uint8_t) PRIORITY_0, /* Priority #  62 ADC0_EOC_IRQn */
(uint8_t) PRIORITY_0, /* Priority #  63 RESERVED_IRQ63 */
(uint8_t) PRIORITY_0, /* Priority #  64 ADC0_WD_IRQn */
(uint8_t) PRIORITY_14, /* Priority #  65 FLEXCAN0_ESR_ERR_IRQn */
(uint8_t) PRIORITY_14, /* Priority #  66 FLEXCAN0_ESR_TX_RX_IRQn */
(uint8_t) PRIORITY_0, /* Priority #  67 RESERVED_IRQ67 */
(uint8_t) PRIORITY_14, /* Priority #  68 FLEXCAN0_BUF_00_03_IRQn */
(uint8_t) PRIORITY_14, /* Priority #  69 FLEXCAN0_BUF_04_07_IRQn */
(uint8_t) PRIORITY_14, /* Priority #  70 FLEXCAN0_BUF_08_11_IRQn */
(uint8_t) PRIORITY_14, /* Priority #  71 FLEXCAN0_BUF_12_15_IRQn */
(uint8_t) PRIORITY_14, /* Priority #  72 FLEXCAN0_BUF_16_31_IRQn */
(uint8_t) PRIORITY_14, /* Priority #  73 FLEXCAN0_BUF_32_63_IRQn */
(uint8_t) PRIORITY_0, /* Priority #  74 DSPI0_SR_TFUF_RFOF_IRQn */
(uint8_t) PRIORITY_0, /* Priority #  75 DSPI0_SR_EOQF_IRQn */
(uint8_t) PRIORITY_0, /* Priority #  76 DSPI0_SR_TFFF_IRQn */
(uint8_t) PRIORITY_0, /* Priority #  77 DSPI0_SR_TCF_IRQn */
(uint8_t) PRIORITY_0, /* Priority #  78 DSPI0_SR_RFDF_IRQn */
(uint8_t) PRIORITY_0, /* Priority #  79 LINFLEX0_RXI_IRQn */
(uint8_t) PRIORITY_0, /* Priority #  80 LINFLEX0_TXI_IRQn */
(uint8_t) PRIORITY_0, /* Priority #  81 LINFLEX0_ERR_IRQn */
(uint8_t) PRIORITY_0, /* Priority #  82 ADC1_EOC_IRQn */
(uint8_t) PRIORITY_0, /* Priority #  83 RESERVED_IRQ83 */
(uint8_t) PRIORITY_0, /* Priority #  84 ADC1_WD_IRQn */
(uint8_t) PRIORITY_14, /* Priority #  85 FLEXCAN1_ESR_ERR_IRQn */
(uint8_t) PRIORITY_14, /* Priority #  86 FLEXCAN1_ESR_TX_RX_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority #  87 FLEXCAN1_ESR_WAK_IRQn */
(uint8_t) PRIORITY_14, /* Priority #  88 FLEXCAN1_BUF_00_03_IRQn */
(uint8_t) PRIORITY_14, /* Priority #  89 FLEXCAN1_BUF_04_07_IRQn */
(uint8_t) PRIORITY_14, /* Priority #  90 FLEXCAN1_BUF_08_11_IRQn */
(uint8_t) PRIORITY_14, /* Priority #  91 FLEXCAN1_BUF_12_15_IRQn */
(uint8_t) PRIORITY_14, /* Priority #  92 FLEXCAN1_BUF_16_31_IRQn */
(uint8_t) PRIORITY_14, /* Priority #  93 FLEXCAN1_BUF_32_63_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority #  94 DSPI1_SR_TFUF_RFOF_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority #  95 DSPI1_SR_EOQF_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority #  96 DSPI1_SR_TFFF_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority #  97 DSPI1_SR_TCF_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority #  98 DSPI1_SR_RFDF_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority #  99 LINFLEX1_RXI_IRQn */

(uint8_t) PRIORITY_NULL, /* Priority # 100 LINFLEX1_TXI_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 101 LINFLEX1_ERR_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 102 RESERVED_IRQ102 */
(uint8_t) PRIORITY_NULL, /* Priority # 103 RESERVED_IRQ103 */
(uint8_t) PRIORITY_NULL, /* Priority # 104 RESERVED_IRQ104 */
(uint8_t) PRIORITY_14, /* Priority # 105 FLEXCAN2_ESR_ERR_IRQn */
(uint8_t) PRIORITY_14, /* Priority # 106 FLEXCAN2_ESR_TX_RX_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 107 RESERVED_IRQ107 */
(uint8_t) PRIORITY_14, /* Priority # 108 FLEXCAN2_BUF_00_03_IRQn */
(uint8_t) PRIORITY_14, /* Priority # 109 FLEXCAN2_BUF_04_07_IRQn */
(uint8_t) PRIORITY_14, /* Priority # 110 FLEXCAN2_BUF_08_11_IRQn */
(uint8_t) PRIORITY_14, /* Priority # 111 FLEXCAN2_BUF_12_15_IRQn */
(uint8_t) PRIORITY_14, /* Priority # 112 FLEXCAN2_BUF_16_31_IRQn */
(uint8_t) PRIORITY_14, /* Priority # 113 FLEXCAN2_BUF_32_63_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 114 DSPI2_SR_TFUF_RFOF_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 115 DSPI2_SR_EOQF_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 116 DSPI2_SR_TFFF_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 117 DSPI2_SR_TCF_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 118 DSPI2_SR_RFDF_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 119 LINFLEX2_RXI_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 120 LINFLEX2_TXI_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 121 LINFLEX2_ERR_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 122 LINFLEX3_RXI_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 123 LINFLEX3_TXI_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 124 LINFLEX3_ERR_IRQn */
(uint8_t) PRIORITY_8, /* Priority # 125 I2C0_SR_IRQn */
(uint8_t) PRIORITY_8, /* Priority # 126 I2C1_SR_IRQn */
(uint8_t) PRIORITY_12, /* Priority # 127 PIT_CH3_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 128 PIT_CH4_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 129 PIT_CH5_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 130 PIT_CH6_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 131 PIT_CH7_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 132 LINFLEX10_RXI_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 133 LINFLEX10_TXI_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 134 LINFLEX10_ERR_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 135 LINFLEX11_RXI_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 136 LINFLEX11_TXI_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 137 LINFLEX11_ERR_IRQn */
(uint8_t) PRIORITY_8, /* Priority # 138 I2C2_SR_IRQn */
(uint8_t) PRIORITY_8, /* Priority # 139 I2C3_SR_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 140 RESERVED_IRQ140 */
(uint8_t) PRIORITY_NULL, /* Priority # 141 EMIOS0_GFR_F0_F1_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 142 EMIOS0_GFR_F2_F3_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 143 EMIOS0_GFR_F4_F5_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 144 EMIOS0_GFR_F6_F7_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 145 EMIOS0_GFR_F8_F9_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 146 EMIOS0_GFR_F10_F11_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 147 EMIOS0_GFR_F12_F13_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 148 EMIOS0_GFR_F14_F15_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 149 EMIOS0_GFR_F16_F17_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 150 EMIOS0_GFR_F18_F19_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 151 EMIOS0_GFR_F20_F21_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 152 EMIOS0_GFR_F22_F23_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 153 EMIOS0_GFR_F24_F25_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 154 EMIOS0_GFR_F26_F27_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 155 EMIOS0_GFR_F28_F29_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 156 EMIOS0_GFR_F30_F31_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 157 EMIOS1_GFR_F0_F1_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 158 EMIOS1_GFR_F2_F3_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 159 EMIOS1_GFR_F4_F5_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 160 EMIOS1_GFR_F6_F7_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 161 EMIOS1_GFR_F8_F9_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 162 EMIOS1_GFR_F10_F11_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 163 EMIOS1_GFR_F12_F13_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 164 EMIOS1_GFR_F14_F15_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 165 EMIOS1_GFR_F16_F17_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 166 EMIOS1_GFR_F18_F19_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 167 EMIOS1_GFR_F20_F21_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 168 EMIOS1_GFR_F22_F23_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 169 EMIOS1_GFR_F24_F25_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 170 EMIOS1_GFR_F26_F27_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 171 EMIOS1_GFR_F28_F29_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 172 EMIOS1_GFR_F30_F31_IRQn */
(uint8_t) PRIORITY_14, /* Priority # 173 FLEXCAN3_ESR_ERR_IRQn */
(uint8_t) PRIORITY_14, /* Priority # 174 FLEXCAN3_ESR_TX_RX_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 175 RESERVED_IRQ175 */
(uint8_t) PRIORITY_14, /* Priority # 176 FLEXCAN3_BUF_00_03_IRQn */
(uint8_t) PRIORITY_14, /* Priority # 177 FLEXCAN3_BUF_04_07_IRQn */
(uint8_t) PRIORITY_14, /* Priority # 178 FLEXCAN3_BUF_08_11_IRQn */
(uint8_t) PRIORITY_14, /* Priority # 179 FLEXCAN3_BUF_12_15_IRQn */
(uint8_t) PRIORITY_14, /* Priority # 180 FLEXCAN3_BUF_16_31_IRQn */
(uint8_t) PRIORITY_14, /* Priority # 181 FLEXCAN3_BUF_32_63_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 182 DSPI3_SR_TFUF_RFOF_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 183 DSPI3_SR_EOQF_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 184 DSPI3_SR_TFFF_IRQn */
(uint8_t) PRIORITY_0, /* Priority # 185 DSPI3_SR_TCF_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 186 DSPI3_SR_RFDF_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 187 LINFLEX4_RXI_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 188 LINFLEX4_TXI_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 189 LINFLEX4_ERR_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 190 FLEXCAN4_ESR_ERR_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 191 FLEXCAN4_ESR_TX_RX_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 192 RESERVED_IRQ192 */
(uint8_t) PRIORITY_NULL, /* Priority # 193 FLEXCAN4_BUF_00_03_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 194 FLEXCAN4_BUF_04_07_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 195 FLEXCAN4_BUF_08_11_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 196 FLEXCAN4_BUF_12_15_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 197 FLEXCAN4_BUF_16_31_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 198 FLEXCAN4_BUF_32_63_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 199 LINFLEX5_RXI_IRQn */

(uint8_t) PRIORITY_NULL, /* Priority # 200 LINFLEX5_TXI_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 201 LINFLEX5_ERR_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 202 FLEXCAN5_ESR_ERR_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 203 FLEXCAN5_ESR_TX_RX_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 204 RESERVED_IRQ204 */
(uint8_t) PRIORITY_NULL, /* Priority # 205 FLEXCAN5_BUF_00_03_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 206 FLEXCAN5_BUF_04_07_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 207 FLEXCAN5_BUF_08_11_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 208 FLEXCAN5_BUF_12_15_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 209 FLEXCAN5_BUF_16_31_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 210 FLEXCAN5_BUF_32_63_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 211 DSPI4_SR_TFUF_RFOF_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 212 DSPI4_SR_EOQF_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 213 DSPI4_SR_TFFF_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 214 DSPI4_SR_TCF_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 215 DSPI4_SR_RFDF_IRQn */
(uint8_t) PRIORITY_0, /* Priority # 216 LINFLEX6_RXI_IRQn */
(uint8_t) PRIORITY_0, /* Priority # 217 LINFLEX6_TXI_IRQn */
(uint8_t) PRIORITY_0, /* Priority # 218 LINFLEX6_ERR_IRQn */
(uint8_t) PRIORITY_0, /* Priority # 219 DSPI5_SR_TFUF_RFOF_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 220 DSPI5_SR_EOQF_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 221 DSPI5_SR_TFFF_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 222 DSPI5_SR_TCF_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 223 DSPI5_SR_RFDF_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 224 LINFLEX7_RXI_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 225 LINFLEX7_TXI_IRQn */
(uint8_t) PRIORITY_0, /* Priority # 226 LINFLEX7_ERR_IRQn */
(uint8_t) PRIORITY_0, /* Priority # 227 LINFLEX8_RXI_IRQn */
(uint8_t) PRIORITY_0, /* Priority # 228 LINFLEX8_TXI_IRQn */
(uint8_t) PRIORITY_0, /* Priority # 229 LINFLEX8_ERR_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 230 LINFLEX9_RXI_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 231 LINFLEX9_TXI_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 232 LINFLEX9_ERR_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 233 MC_CGM_SXOSC_IRQn */
(uint8_t) PRIORITY_11, /* Priority # 234 CANFD0_IRQn */
(uint8_t) PRIORITY_11, /* Priority # 235 CANFD1_IRQn */
(uint8_t) PRIORITY_11, /* Priority # 236 CANFD2_IRQn */
(uint8_t) PRIORITY_11, /* Priority # 237 CANFD3_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 238 CANFD4_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 239 CANFD5_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 240 CANFD6_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 241 CANFD7_IRQn */
(uint8_t) PRIORITY_0, /* Priority # 242 ADC0_RFIFO_DRAIN_IRQn */
(uint8_t) PRIORITY_0, /* Priority # 243 ADC0_RFIFO_OV_IRQn */
(uint8_t) PRIORITY_0, /* Priority # 244 ADC1_RFIFO_DRAIN_IRQn */
(uint8_t) PRIORITY_0, /* Priority # 245 ADC1_RFIFO_OV_IRQn */
(uint8_t) PRIORITY_0, /* Priority # 246 FLEXCAN6_ESR_ERR_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 247 FLEXCAN6_ESR_TX_RX_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 248 RESERVED_IRQ248 */
(uint8_t) PRIORITY_NULL, /* Priority # 249 FLEXCAN6_BUF_00_03_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 250 FLEXCAN6_BUF_04_07_IRQn */
(uint8_t) PRIORITY_0, /* Priority # 251 FLEXCAN6_BUF_08_11_IRQn */
(uint8_t) PRIORITY_0, /* Priority # 252 FLEXCAN6_BUF_12_15_IRQn */
(uint8_t) PRIORITY_0, /* Priority # 253 FLEXCAN6_BUF_16_31_IRQn */
(uint8_t) PRIORITY_0, /* Priority # 254 FLEXCAN6_BUF_32_63_IRQn */
(uint8_t) PRIORITY_0, /* Priority # 255 FLEXCAN7_ESR_ERR_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 256 FLEXCAN7_ESR_TX_RX_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 257 RESERVED_IRQ257 */
(uint8_t) PRIORITY_NULL, /* Priority # 258 FLEXCAN7_BUF_00_03_IRQn */
(uint8_t) PRIORITY_0, /* Priority # 259 FLEXCAN7_BUF_04_07_IRQn */
(uint8_t) PRIORITY_0, /* Priority # 260 FLEXCAN7_BUF_08_11_IRQn */
(uint8_t) PRIORITY_0, /* Priority # 261 FLEXCAN7_BUF_12_15_IRQn */
(uint8_t) PRIORITY_0, /* Priority # 262 FLEXCAN7_BUF_16_31_IRQn */
(uint8_t) PRIORITY_0, /* Priority # 263 FLEXCAN7_BUF_32_63_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 264 ETPU1_CH0_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 265 ETPU1_CH1_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 266 ETPU1_CH2_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 267 ETPU1_CH3_IRQn */
(uint8_t) PRIORITY_0, /* Priority # 268 ETPU1_CH4_IRQn */
(uint8_t) PRIORITY_0, /* Priority # 269 ETPU1_CH5_IRQn */
(uint8_t) PRIORITY_0, /* Priority # 270 ETPU1_CH6_IRQn */
(uint8_t) PRIORITY_0, /* Priority # 271 ETPU1_CH7_IRQn */
(uint8_t) PRIORITY_0, /* Priority # 272 ETPU1_CH8_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 273 ETPU1_CH9_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 274 ETPU1_CH10_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 275 ETPU1_CH11_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 276 ETPU1_CH12_IRQn */
(uint8_t) PRIORITY_0, /* Priority # 277 ETPU1_CH13_IRQn */
(uint8_t) PRIORITY_0, /* Priority # 278 ETPU1_CH14_IRQn */
(uint8_t) PRIORITY_0, /* Priority # 279 ETPU1_CH15_IRQn */
(uint8_t) PRIORITY_0, /* Priority # 280 ETPU1_CH16_IRQn */
(uint8_t) PRIORITY_0, /* Priority # 281 ETPU1_CH17_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 282 ETPU1_CH18_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 283 ETPU1_CH19_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 284 ETPU1_CH20_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 285 ETPU1_CH21_IRQn */
(uint8_t) PRIORITY_0, /* Priority # 286 ETPU1_CH22_IRQn */
(uint8_t) PRIORITY_0, /* Priority # 287 ETPU1_CH23_IRQn */
(uint8_t) PRIORITY_0, /* Priority # 288 ETPU1_CH24_IRQn */
(uint8_t) PRIORITY_0, /* Priority # 289 ETPU1_CH25_IRQn */
(uint8_t) PRIORITY_0, /* Priority # 290 ETPU1_CH26_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 291 ETPU1_CH27_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 292 ETPU1_CH28_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 293 ETPU1_CH29_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 294 ETPU1_CH30_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 295 ETPU1_CH31_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 296 ETPU2_CH0_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 297 ETPU2_CH1_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 298 ETPU2_CH2_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 299 ETPU2_CH3_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 300 ETPU2_CH4_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 301 ETPU2_CH5_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 302 ETPU2_CH6_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 303 ETPU2_CH7_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 304 ETPU2_CH8_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 305 ETPU2_CH9_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 306 ETPU2_CH10_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 307 ETPU2_CH11_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 308 ETPU2_CH12_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 309 ETPU2_CH13_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 310 ETPU2_CH14_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 311 ETPU2_CH15_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 312 ETPU2_CH16_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 313 ETPU2_CH17_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 314 ETPU2_CH18_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 315 ETPU2_CH19_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 316 ETPU2_CH20_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 317 ETPU2_CH21_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 318 ETPU2_CH22_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 319 ETPU2_CH23_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 320 ETPU2_CH24_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 321 ETPU2_CH25_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 322 ETPU2_CH26_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 323 ETPU2_CH27_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 324 ETPU2_CH28_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 325 ETPU2_CH29_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 326 ETPU2_CH30_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 327 ETPU2_CH31_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 328 ETPU_IPI_GLEX_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 329 DSPI6_SR_TFUF_RFOF_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 330 DSPI6_SR_EOQF_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 331 DSPI6_SR_TFFF_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 332 DSPI6_SR_TCF_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 333 DSPI6_SR_RFDF_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 334 DSPI7_SR_TFUF_RFOF_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 335 DSPI7_SR_EOQF_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 336 DSPI7_SR_TFFF_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 337 DSPI7_SR_TCF_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 338 DSPI7_SR_RFDF_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 339 DSPI8_SR_TFUF_RFOF_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 340 DSPI8_SR_EOQF_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 341 DSPI8_SR_TFFF_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 342 DSPI8_SR_TCF_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 343 DSPI8_SR_RFDF_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 344 DECFILTER_ERR_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 345 DECFILTER_IN_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 346 DECFILTER_OUT_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 347 LINFLEX12_RXI_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 348 LINFLEX12_TXI_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 349 LINFLEX12_ERR_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 350 LINFLEX13_RXI_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 351 LINFLEX13_TXI_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 352 LINFLEX13_ERR_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 353 EDMA_IPI_16_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 354 EDMA_IPI_17_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 355 EDMA_IPI_18_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 356 EDMA_IPI_19_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 357 EDMA_IPI_20_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 358 EDMA_IPI_21_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 359 EDMA_IPI_22_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 360 EDMA_IPI_23_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 361 EDMA_ERR_63_22_IRQn */
(uint8_t) PRIORITY_NULL, /* Priority # 362 EDMA_ERR_31_0_IRQn */

};


/******************************************************************************
Public Functions Definitions
******************************************************************************/
void Cpu_InterruptNop(void);
void Cpu_EnableInterrupts(void);
void Cpu_DisableInterrupts(void);
void Cpu_SetInterruptPriority(void);

/******************************************************************************
*   Function:    Cpu_EnableInterrupts
*   Description:
*   Input: None
*   Output: None
*   Return:  None
*   Others:
******************************************************************************/
void Cpu_InterruptNop(void)
{

}

void Cpu_EnableInterruptsISR(void)
{
   /* Enable external interrupts */
	asm ("wrteei  1");
}

void Cpu_DisableInterruptsISR(void)
{
   /* Disable external interrupts */
	asm ("wrteei  0");
	/* Interruption is enabled only when INTC.PSR > INTC.CPR.
	 * Therefore, to disable interruption,
	 * you need to set the current priority to the[maximum]. */
	INTC.CPR.B.PRI = (uint32_t)15U; /* Set the current priority */
}

/******************************************************************************
*   Function:    Cpu_EnableInterrupts
*   Description:
*   Input: None
*   Output: None
*   Return:  None
*   Others:
******************************************************************************/
void Cpu_EnableInterrupts(void)
{
   /* Enable external interrupts */
	asm ("wrteei  1");
	/* Interruption is enabled only when INTC.PSR > INTC.CPR.
	 * Therefore, to enable interruption,
	 * the current priority must be set to the[minimum]. */
	INTC.CPR.B.PRI = (uint32_t)0U;  /* Set the current priority */
}

/******************************************************************************
*   Function:    Cpu_EnableInterrupts
*   Description:
*   Input: None
*   Output: None
*   Return:  None
*   Others:
******************************************************************************/
void Cpu_DisableInterrupts(void)
{
	/* Disable external interrupts */
	asm ("wrteei  0");
	/* Interruption is enabled only when INTC.PSR > INTC.CPR.
	 * Therefore, to disable interruption,
	 * you need to set the current priority to the[maximum]. */
	INTC.CPR.B.PRI = (uint32_t)15U; /* Set the current priority */
}

/******************************************************************************
*   Function:    Cpu_SetInterruptPriorty
*   Description:
*   Input: None
*   Output: None
*   Return:  None
*   Others:
******************************************************************************/
void Cpu_SetInterruptPriority(void)
{
   uint16_t i;

   for(i=0; i<ISR_COUNTMAX; i++)
   {
      if(IntcIsrPriorityTable[i] != PRIORITY_NULL)
      {
         INTC.PSR[i].B.PRI = IntcIsrPriorityTable[i];
      }
   }
}

