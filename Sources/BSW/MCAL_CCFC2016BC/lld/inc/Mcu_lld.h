/****************************************************************************
* 
* Copyright (c) 2023  C*Core -   All Rights Reserved  
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* 
* PROJECT     : CCFC2016BC           
* DESCRIPTION : CCFC2016BC MCU low level drivers code 
* HISTORY     : Initial version.
* @file     Mcu_lld.h
* @version  1.1
* @date     2023 - 02 - 15
* @brief    Initial version.
*
*****************************************************************************/
#ifndef MCU_LLD_H_
#define MCU_LLD_H_
#include "CCFC2016BC.h"
#include "Mcu_Config.h"

/*********************************************************
* @brief    OSC_CTL_t
*           1.FXOSC Control Register.
*           2.SXOSC Control Register.
**********************************************************/
/* Crystal oscillator enable(SXOSC_CTL only). */
#define SXOSC_ON_MASK       ((uint32_t)0x00000001UL)
/* Crystal oscillator status(SXOSC_CTL only). */
#define SXOSC_STATUS_MASK   ((uint32_t)0x00000002UL)
/* Crystal oscillator clock interrupt. */
#define OSC_I_OSC_MASK      ((uint32_t)0x00000080UL)
/* Crystal oscillator clock division factor. */
#define OSC_DIV_MASK        ((uint32_t)0x00001F00UL)
/* Crystal oscillator clock interrupt mask. */
#define OSC_M_OSC_MASK      ((uint32_t)0x00008000UL)
/* FXOSC/SXOSC Control Register default value. */
#define OSC_CTL_DEFAULT     ((uint32_t)0x00800000UL)
/* End of Count Value. */
#define OSC_EOCV_MASK       ((uint32_t)0x00FF0000UL)
/* Crystal Oscillator bypass. */
#define OSC_BYPASS_MASK     ((uint32_t)0x80000000UL)

/**
* @brief    Crystal oscillator enable/disable(SXOSC_ON_MASK).
**/
#define SXOSC_SWITCH_OFF    ((uint32_t)0x00000000UL)
#define SXOSC_SWITCH_ON     ((uint32_t)0x00000001UL)

/**
* @brief    Crystal oscillator status(SXOSC_STATUS_MASK).
**/
#define SXOSC_S_NOT_STABLE  ((uint32_t)0x00000000UL)
#define SXOSC_S_STABLE_CLK  ((uint32_t)0x00000002UL)

/**
* @brief    Crystal oscillator clock interrupt(OSC_I_OSC_MASK).
* @details  This bit is set by hardware when OSCCNT counter
*               reaches the count value EOCV * 512.
*           For example, if the FXOSCON value of the ME_DRUN_MC
*               register is 1, this field will be written to 1 by the
*           hardware after entering the DRUN mode.
* @details  Read:
*               0: No oscillator clock interrupt occurred.
*               1: Oscillator clock interrupt pending.
* @details  Write:
*               0: No effect.
*               1: Clear this field.
**/
#define OSC_I_INT_NO        ((uint32_t)0x00000000UL)
#define OSC_I_INT_PEND      ((uint32_t)0x00000080UL)

/**
 * @brief   Crystal oscillator clock interrupt mask(OSC_M_OSC_MASK).
 * @details Read/Write:
 *              0: Crystal oscillator clock interrupt is masked.
 *              1: Crystal oscillator clock interrupt is enabled.
 * */
#define OSC_M_INT_MASK      ((uint32_t)0x00000000UL)
#define OSC_M_INT_EN        ((uint32_t)0x00008000UL)

/**
 * @brief   Crystal Oscillator bypass(OSC_BYPASS_MASK).
 * @details This bit specifies whether the oscillator should be bypassed or not.
 *          Read:
 *              0: Oscillator output is used as root clock.
 *              1: EXTAL is used as root clock.
 *          Write:
 *              0: No effect.
 *              1: Clear this field.
 **/
#define OSC_BYP_OSC_CLK     ((uint32_t)0x00000000UL)
#define OSC_BYP_EXTAL_CLK   ((uint32_t)0x80000000UL)

/*********************************************************************
* @brief    Slow internal RC oscillator Control Register (SIRC_CTL).
**********************************************************************/
#define SIRC_ON_STDBY_MASK  ((uint32_t)0x00000001UL)
#define SIRC_CLKSTATUS_MASK ((uint32_t)0x00000010UL)
#define SIRC_CTL_DEFAULT    ((uint32_t)0x00000300UL)
#define SIRC_DIV_MASK       ((uint32_t)0x00001F00UL)
#define SIRC_TRIM_MASK      ((uint32_t)0x001F0000UL)

/**
 * @brief   SIRC_ON_STDBY_MASK.
 * @details SIRC_OFF_STDBY: SIRC is switched off in STANDBY mode.
 *          SIRC_ON_STDBY: SIRC is switched on in STANDBY mode.
 **/
#define SIRC_OFF_STDBY      ((uint32_t)0x00000000UL)
#define SIRC_ON_STDBY       ((uint32_t)0x00000001UL)

/**
 * @brief   SIRC_CLKSTATUS_MASK.
 * @details SIRC_CLK_NOT_PROVIDING: SIRC is not providing a stable clock.
 *          SIRC_CLK_PROVIDING: SIRC is providing a stable clock.
 **/
#define SIRC_CLK_NOT_PROVIDING ((uint32_t)0x00000000UL)
#define SIRC_CLK_PROVIDING  ((uint32_t)0x00000010UL)

/*********************************************************************
* @brief    Fast internal RC oscillator Control Register (FIRC_CTL).
**********************************************************************/
#define FIRC_CTL_DEFAULT    ((uint32_t)0x00000000UL)
#define FIRC_ON_STDBY_MASK  ((uint32_t)0x00000020UL)
#define FIRC_DIV_MASK       ((uint32_t)0x00001F00UL)
#define FIRC_TRIM_MASK      ((uint32_t)0x003F0000UL)

/**
 * @brief   FIRC_ON_STDBY_MASK.
 * @details FIRC_OFF_STDBY: FIRC is switched off in STANDBY mode.
 *          FIRC_ON_STDBY: FIRC is switched on in STANDBY mode.
 **/
#define FIRC_OFF_STDBY      ((uint32_t)0x00000000UL)
#define FIRC_ON_STDBY       ((uint32_t)0x00000020UL)

/********************************************************
* @brief    PLL Control Register (CR).
*********************************************************/
#define PLL_PLL_FAIL_FLAG   ((uint32_t)0x00000002UL)
#define PLL_PLL_FAIL_MASK   ((uint32_t)0x00000004UL)
#define PLL_S_LOCK          ((uint32_t)0x00000008UL)
#define PLL_I_LOCK          ((uint32_t)0x00000010UL)
#define PLL_UNLOCK_ONCE     ((uint32_t)0x00000040UL)
#define PLL_EN_PLL_SW       ((uint32_t)0x00000100UL)
#define PLL_NDIV_MASK       ((uint32_t)0x007F0000UL)
#define PLL_ODF_MASK        ((uint32_t)0x03000000UL)
#define PLL_IDF_MASK        ((uint32_t)0x3C000000UL)

/**
 * @brief   PLL_NDIV_MASK.
 **/
#define NDIV_OFFSET         (16U)
#define NDIV_32             (32U)
#define NDIV_33             (33U)
#define NDIV_34             (34U)
#define NDIV_35             (35U)
#define NDIV_36             (36U)
#define NDIV_37             (37U)
#define NDIV_38             (38U)
#define NDIV_39             (39U)
#define NDIV_40             (40U)
#define NDIV_41             (41U)
#define NDIV_42             (42U)
#define NDIV_43             (43U)
#define NDIV_44             (44U)
#define NDIV_45             (45U)
#define NDIV_46             (46U)
#define NDIV_47             (47U)
#define NDIV_48             (48U)
#define NDIV_49             (49U)
#define NDIV_50             (50U)
#define NDIV_51             (51U)
#define NDIV_52             (52U)
#define NDIV_53             (53U)
#define NDIV_54             (54U)
#define NDIV_55             (55U)
#define NDIV_56             (56U)
#define NDIV_57             (57U)
#define NDIV_58             (58U)
#define NDIV_59             (59U)
#define NDIV_60             (60U)   /* Default */
#define NDIV_61             (61U)
#define NDIV_62             (62U)
#define NDIV_63             (63U)
#define NDIV_64             (64U)
#define NDIV_65             (65U)
#define NDIV_66             (66U)
#define NDIV_67             (67U)
#define NDIV_68             (68U)
#define NDIV_69             (69U)
#define NDIV_70             (70U)
#define NDIV_71             (71U)
#define NDIV_72             (72U)
#define NDIV_73             (73U)
#define NDIV_74             (74U)
#define NDIV_75             (75U)
#define NDIV_76             (76U)
#define NDIV_77             (77U)
#define NDIV_78             (78U)
#define NDIV_79             (79U)
#define NDIV_80             (80U)
#define NDIV_81             (81U)
#define NDIV_82             (82U)
#define NDIV_83             (83U)
#define NDIV_84             (84U)
#define NDIV_85             (85U)
#define NDIV_86             (86U)
#define NDIV_87             (87U)
#define NDIV_88             (88U)
#define NDIV_89             (89U)
#define NDIV_90             (90U)
#define NDIV_91             (91U)
#define NDIV_92             (92U)
#define NDIV_93             (93U)
#define NDIV_94             (94U)
#define NDIV_95             (95U)
#define NDIV_96             (96U)

/**
 * @brief   PLL_ODF_MASK.
 **/
#define ODF_DIV_OFFSET      (24U)
#define ODF_DIV_2           (0U)
#define ODF_DIV_4           (1U)
#define ODF_DIV_8_DEFAULT   (2U)   /* Default */
#define ODF_DIV_16          (3U)

/**
 * @brief   PLL_IDF_MASK.
 **/
#define IDF_DIV_OFFSET      (26U)
#define IDF_DIV_1           (0U)    /* Default */
#define IDF_DIV_2           (1U)
#define IDF_DIV_3           (2U)
#define IDF_DIV_4           (3U)
#define IDF_DIV_5           (4U)
#define IDF_DIV_6           (5U)
#define IDF_DIV_7           (6U)
#define IDF_DIV_8           (7U)
#define IDF_DIV_9           (8U)
#define IDF_DIV_10          (9U)
#define IDF_DIV_11          (10U)
#define IDF_DIV_12          (11U)
#define IDF_DIV_13          (12U)
#define IDF_DIV_14          (13U)
#define IDF_DIV_15          (14U)
#define IDF_CLK_OFF         (15U)

/********************************************************
* @brief    PLL Modulation Register (MR).
*           Mode with frequency modulation(FM).
*********************************************************/
#define FMPLL_INC_STEP_MASK     ((uint32_t)0x00007FFFUL)
#define FMPLL_FM_EN_MASK        ((uint32_t)0x00008000UL)
#define FMPLL_MOD_PERIOD_MASK   ((uint32_t)0x1FFF0000UL)
#define FMPLL_SPRD_SEL_MASK     ((uint32_t)0x20000000UL)
#define FMPLL_STRB_BYPASS_MASK  ((uint32_t)0x80000000UL)

/**
 * @brief   FMPLL_FM_EN_MASK.
 **/
#define FM_DIS              ((uint32_t)0x00000000UL)
#define FM_EN               ((uint32_t)0x00008000UL)

/**
 * @brief   FMPLL_SPRD_SEL_MASK.
 **/
#define FM_CENTER_SPRD      ((uint32_t)0x00000000UL)
#define FM_DOWN_SPRD        ((uint32_t)0x20000000UL)

/**
 * @brief   FMPLL_STRB_BYPASS_MASK.
 **/
#define FM_STROBE_USE       ((uint32_t)0x00000000UL)
#define FM_STROBE_BYPASS    ((uint32_t)0x80000000UL)

/*******************************************************************
* @brief    Clock monitor unit: Control Status Register (CMU_CSR).
********************************************************************/
/* FMPLL_0 clock monitor enable. */
#define CMU_CME_A_MASK      ((uint32_t)0x00000001UL)
/* RC clock division factor. */
#define CMU_RCDIV_MASK      ((uint32_t)0x00000006UL)
/* Clock oscillator selection bit. */
#define CMU_CKSEL1_MASK     ((uint32_t)0x00000300UL)
/* Start frequency measure(SFM).
 * The software can only set this bit to start a clock 
 *  frequency measure.
 * It is reset by hardware when the measure is ready in 
 *  the CMU_FDR register.
 * Read:
 *      0: Frequency measurement completed or not yet started.
 *      1: Frequency measurement not completed.
 * Write:
 *      0: No effect.
 *      1: Start frequency measure.
 * */
#define CMU_SFM_MASK        ((uint32_t)0x00800000UL)

/**
 * @brief   CMU_CME_A_MASK.
 **/
#define CMU_CLK_MONITOR_DIS ((uint32_t)0x00000000UL)
#define CMU_CLK_MONITOR_EN  ((uint32_t)0x00000001UL)

/**
 * @brief   CMU_RCDIV_MASK.
 **/
#define CMU_RCDIV_1         ((uint32_t)0x00000000UL)
#define CMU_RCDIV_2         ((uint32_t)0x00000002UL)
#define CMU_RCDIV_4         ((uint32_t)0x00000004UL)
#define CMU_RCDIV_8         ((uint32_t)0x00000006UL)

/**
 * @brief   CMU_CKSEL1_MASK.
 * @details CKSEL1 selects the clock to be measured
 *              by the frequency meter.
 **/
#define CMU_CKSEL1_FIRC     ((uint32_t)0x00000000UL)
#define CMU_CKSEL1_SIRC     ((uint32_t)0x00000100UL)
#define CMU_CKSEL1_SXOSC    ((uint32_t)0x00000200UL)
#define CMU_CKSEL1_FIRC_2   ((uint32_t)0x00000300UL)

/*******************************************************************
* @brief    1.Frequency Display Register (CMU_FDR)
*           2.High Frequency Reference Register FMPLL (CMU_HFREFR)
*           3.Low Frequency Reference Register FMPLL (CMU_LFREFR)
********************************************************************/
#define CMU_FDR_MASK        ((uint32_t)0x000FFFFFUL)
#define CMU_HFREFR_MASK     ((uint32_t)0x00000FFFUL)
#define CMU_LFREFR_MASK     ((uint32_t)0x00000FFFUL)

/*******************************************************************
* @brief    Output Clock Enable Register (CGM_OC_EN).
********************************************************************/
#define CLKOUT_DIS          ((uint32_t)0x00000000UL)
#define CLKOUT_EN           ((uint32_t)0x00000001UL)

/*******************************************************************
* @brief    Output Clock Division Select Register (CGM_OCDS_SC).
********************************************************************/
/**
* @brief    Output Clock Source Selection Control (SC).
**/
#define CLKOUT_SC_FXOSC     ((uint32_t)0x00000000UL)
#define CLKOUT_SC_FISC      ((uint32_t)0x01000000UL)
#define CLKOUT_SC_FMPLL     ((uint32_t)0x02000000UL)
#define CLKOUT_SC_RTCCLK    ((uint32_t)0x03000000UL)    /* CCFC2016BC != MPC5607B */
#define CLKOUT_SC_SIRC      ((uint32_t)0x04000000UL)
#define CLKOUT_SC_SYSCLK    ((uint32_t)0x05000000UL)    /* CCFC2016BC != MPC5607B */
#define CLKOUT_SC_MASK      ((uint32_t)0x0F000000UL)

/**
* @brief    Output Clock Division Select (DS).
**/
#define CLKOUT_DIV_0        ((uint32_t)0x00000000UL)
#define CLKOUT_DIV_2        ((uint32_t)0x10000000UL)
#define CLKOUT_DIV_4        ((uint32_t)0x20000000UL)
#define CLKOUT_DIV_8        ((uint32_t)0x30000000UL)
#define CLKOUT_DIV_MASK     ((uint32_t)0x30000000UL)

/************************************************************************
* @brief    System Clock Divider Configuration Registers (CGM_SC_DC0-3).
*************************************************************************/
#define SYSCLK_DIV_1        ((uint8_t)0x00U)
#define SYSCLK_DIV_2        ((uint8_t)0x01U)
#define SYSCLK_DIV_3        ((uint8_t)0x02U)
#define SYSCLK_DIV_4        ((uint8_t)0x03U)
#define SYSCLK_DIV_5        ((uint8_t)0x04U)
#define SYSCLK_DIV_6        ((uint8_t)0x05U)
#define SYSCLK_DIV_7        ((uint8_t)0x06U)
#define SYSCLK_DIV_8        ((uint8_t)0x07U)
#define SYSCLK_DIV_9        ((uint8_t)0x08U)
#define SYSCLK_DIV_10       ((uint8_t)0x09U)
#define SYSCLK_DIV_11       ((uint8_t)0x0AU)
#define SYSCLK_DIV_12       ((uint8_t)0x0BU)
#define SYSCLK_DIV_13       ((uint8_t)0x0CU)
#define SYSCLK_DIV_14       ((uint8_t)0x0DU)
#define SYSCLK_DIV_15       ((uint8_t)0x0EU)
#define SYSCLK_DIV_16       ((uint8_t)0x0FU)
#define SYSCLK_DIV_MASK     ((uint8_t)0x0FU)
#define SYSCLK_DIV_EN       ((uint8_t)0x80U)

/****************************************************************************
* @brief    1.System Clock Select Status Register (CGM_SC_SS): SELSTAT;
*           2.Global Status Register (ME_GS): SYSCLK;
*           3.RESET Mode Configuration Register (ME_RESET_MC): SYSCLK;
*           4.TEST Mode Configuration Register (ME_TEST_MC): SYSCLK;
*           5.SAFE Mode Configuration Register (ME_SAFE_MC): SYSCLK;
*           6.DRUN Mode Configuration Register (ME_DRUN_MC): SYSCLK;
*           7.RUN0-3 Mode Configuration Registers (ME_RUN0-3_MC): SYSCLK;
*           8.HALT Mode Configuration Register (ME_HALT_MC): SYSCLK;
*           9.STOP Mode Configuration Register (ME_STOP_MC): SYSCLK;
*           10.STANDBY Mode Configuration Register (ME_STANDBY_MC): SYSCLK.
*****************************************************************************/
#define MCU_SYSCLK_FIRC         ((uint32_t)0x00000000UL)    /* 16 MHz int. RC osc.      */
#define MCU_SYSCLK_DIV_FIRC     ((uint32_t)0x00000001UL)    /* div. 16 MHz int. RC osc. */
#define MCU_SYSCLK_FXOSC        ((uint32_t)0x00000002UL)    /* 4-20 MHz ext. xtal osc.  */
#define MCU_SYSCLK_DIV_FXOSC    ((uint32_t)0x00000003UL)    /* div. ext. xtal osc.      */
#define MCU_SYSCLK_PLL          ((uint32_t)0x00000004UL)    /* freq. mod. PLL           */
#define MCU_SYSCLK_DISABLED     ((uint32_t)0x0000000FUL)    /* system clock is disabled */
#define MCU_SYSCLK_MASK         ((uint32_t)0x0000000FUL)

/************************************************************************
* @brief    1.Global Status Register (ME_GS):Current device mode status;
*           2.Mode Control Register (ME_MCTL):Target device mode.
*************************************************************************/
#define ME_MODE_RESET       ((uint32_t)0x00000000UL)
#define ME_MODE_TEST        ((uint32_t)0x10000000UL)
#define ME_MODE_SAFE        ((uint32_t)0x20000000UL)
#define ME_MODE_DRUN        ((uint32_t)0x30000000UL)
#define ME_MODE_RUN0        ((uint32_t)0x40000000UL)
#define ME_MODE_RUN1        ((uint32_t)0x50000000UL)
#define ME_MODE_RUN2        ((uint32_t)0x60000000UL)
#define ME_MODE_RUN3        ((uint32_t)0x70000000UL)
#define ME_MODE_HALT        ((uint32_t)0x80000000UL)
#define ME_MODE_STOP        ((uint32_t)0xA0000000UL)
#define ME_MODE_STANDBY     ((uint32_t)0xD0000000UL)
#define ME_MODE_MASK        ((uint32_t)0xF0000000UL)

/********************************************************
* @brief    Global Status Register (ME_GS).
*********************************************************/
#define ME_GS_MTRANS        ((uint32_t)0x08000000UL)
#define ME_GS_DC            ((uint32_t)0x04000000UL)
#define ME_GS_PDO           ((uint32_t)0x00800000UL)
#define ME_GS_MVR           ((uint32_t)0x00100000UL)
#define ME_GS_DFLA          ((uint32_t)0x000C0000UL)
#define ME_GS_CFLA          ((uint32_t)0x00030000UL)
#define ME_GS_FMPLL         ((uint32_t)0x00000040UL)
#define ME_GS_FXOSC         ((uint32_t)0x00000020UL)
#define ME_GS_FIRC          ((uint32_t)0x00000010UL)

/*********************************************************
* @brief    Mode Control Register (ME_MCTL).
**********************************************************/
#define ME_CONTROL_KEY          ((uint32_t)0x00005AF0UL)
#define ME_CONTROL_INVERTED_KEY ((uint32_t)0x0000A50FUL)

/*********************************************************
* @brief    Mode Enable Register (ME_ME).
**********************************************************/
#define ME_ME_STANDBY       ((uint32_t)0x00002000UL)
#define ME_ME_STOP          ((uint32_t)0x00000400UL)
#define ME_ME_HALT          ((uint32_t)0x00000100UL)
#define ME_ME_RUN3          ((uint32_t)0x00000080UL)
#define ME_ME_RUN2          ((uint32_t)0x00000040UL)
#define ME_ME_RUN1          ((uint32_t)0x00000020UL)
#define ME_ME_RUN0          ((uint32_t)0x00000010UL)
#define ME_ME_DRUN          ((uint32_t)0x00000008UL)
#define ME_ME_SAFE          ((uint32_t)0x00000004UL)
#define ME_ME_TEST          ((uint32_t)0x00000002UL)
#define ME_ME_RESET         ((uint32_t)0x00000001UL)

/*********************************************************
* @brief    Interrupt Status Register (ME_IS).
**********************************************************/
#define ME_IS_MASK          ((uint32_t)0x0000000FUL)
#define ME_IS_I_ICONF       ((uint32_t)0x00000008UL)
#define ME_IS_I_IMODE       ((uint32_t)0x00000004UL)
#define ME_IS_I_SAFE        ((uint32_t)0x00000002UL)
#define ME_IS_I_MTC         ((uint32_t)0x00000001UL)
#define ME_IS_NULL          ((uint32_t)0x00000000UL)

/*********************************************************
* @brief    Interrupt Mask Register (ME_IM).
**********************************************************/
#define ME_IM_MASK          ((uint32_t)0x0000000FUL)
#define ME_IM_M_ICONF       ((uint32_t)0x00000008UL)
#define ME_IM_M_IMODE       ((uint32_t)0x00000004UL)
#define ME_IM_M_SAFE        ((uint32_t)0x00000002UL)
#define ME_IM_M_MTC         ((uint32_t)0x00000001UL)
#define ME_IM_NULL          ((uint32_t)0x00000000UL)

/*************************************************************
* @brief    Invalid Mode Transition Status Register (ME_IMTS).
**************************************************************/
#define ME_IMTS_MASK        ((uint32_t)0x0000001FUL)
#define ME_IMTS_MTI         ((uint32_t)0x00000010UL)
#define ME_IMTS_MRI         ((uint32_t)0x00000008UL)
#define ME_IMTS_DMA         ((uint32_t)0x00000004UL)
#define ME_IMTS_NMA         ((uint32_t)0x00000002UL)
#define ME_IMTS_SEA         ((uint32_t)0x00000001UL)
#define ME_IMTS_NULL        ((uint32_t)0x00000000UL)

/***********************************************************
* @brief    Debug Mode Transition Status Register (ME_DMTS).
************************************************************/
#define ME_DMTS_MASK            ((uint32_t)0x00FFFFFFUL)
#define ME_DMTS_MPH_BUSY        ((uint32_t)0x00800000UL)
#define ME_DMTS_PMC_PROG        ((uint32_t)0x00100000UL)
#define ME_DMTS_CORE_DBG        ((uint32_t)0x00080000UL)
#define ME_DMTS_SMR             ((uint32_t)0x00010000UL)
#define ME_DMTS_FMPLL_SC        ((uint32_t)0x00004000UL)
#define ME_DMTS_FXOSC_SC        ((uint32_t)0x00002000UL)
#define ME_DMTS_FIRC_SC         ((uint32_t)0x00001000UL)
#define ME_DMTS_SYSCLK_SW       ((uint32_t)0x00000400UL)
#define ME_DMTS_DFLASH_SC       ((uint32_t)0x00000200UL)
#define ME_DMTS_CFLASH_SC       ((uint32_t)0x00000100UL)
#define ME_DMTS_CDP_PRPH_0_143  ((uint32_t)0x00000080UL)
#define ME_DMTS_CDP_PRPH_96_127 ((uint32_t)0x00000008UL)
#define ME_DMTS_CDP_PRPH_64_95  ((uint32_t)0x00000004UL)
#define ME_DMTS_CDP_PRPH_32_63  ((uint32_t)0x00000002UL)
#define ME_DMTS_CDP_PRPH_0_31   ((uint32_t)0x00000001UL)
#define ME_DMTS_NULL            ((uint32_t)0x00000000UL)

/*********************************************************
* @brief     Mode Configuration Registers (ME_<mode>_MC).
**********************************************************/
#define ME_MC_PDO_MASK      ((uint32_t)0x00800000UL)
#define ME_MC_MVRON_MASK    ((uint32_t)0x00100000UL)
#define ME_MC_DFLAON_MASK   ((uint32_t)0x000C0000UL)
#define ME_MC_CFLAON_MASK   ((uint32_t)0x00030000UL)
#define ME_MC_FMPLLON_MASK  ((uint32_t)0x00000040UL)
#define ME_MC_FXOSCON_MASK  ((uint32_t)0x00000020UL)
#define ME_MC_FIRCON_MASK   ((uint32_t)0x00000010UL)
#define ME_MC_SYSCLK_MASK   MCU_SYSCLK_MASK

/**
* @brief     ME_MC_PDO_MASK.
**/
#define MC_PDO_OFF          ((uint32_t)0x00000000UL)
#define MC_PDO_ON           ((uint32_t)0x00800000UL)

/**
* @brief     ME_MC_MVRON_MASK.
**/
#define MC_MVR_OFF          ((uint32_t)0x00000000UL)
#define MC_MVR_ON           ((uint32_t)0x00100000UL)

/**
* @brief     ME_MC_DFLAON_MASK.
**/
#define MC_DFLS_POWERDOWN   ((uint32_t)0x00040000UL)
#define MC_DFLS_LOWPOWER    ((uint32_t)0x00080000UL)
#define MC_DFLS_NORMAL      ((uint32_t)0x000C0000UL)

/**
* @brief     ME_MC_CFLAON_MASK.
**/
#define MC_CFLS_POWERDOWN   ((uint32_t)0x00010000UL)
#define MC_CFLS_LOWPOWER    ((uint32_t)0x00020000UL)
#define MC_CFLS_NORMAL      ((uint32_t)0x00030000UL)

/**
* @brief     ME_MC_FMPLLON_MASK.
**/
#define MC_FMPLL_OFF        ((uint32_t)0x00000000UL)
#define MC_FMPLL_ON         ((uint32_t)0x00000040UL)

/**
* @brief     ME_MC_FXOSCON_MASK.
**/
#define MC_FXOSC_OFF        ((uint32_t)0x00000000UL)
#define MC_FXOSC_ON         ((uint32_t)0x00000020UL)

/**
* @brief     ME_MC_FIRCON_MASK.
**/
#define MC_FIRC_OFF         ((uint32_t)0x00000000UL)
#define MC_FIRC_ON          ((uint32_t)0x00000010UL)

/*********************************************************
* @brief     Peripheral Status Register 0 (ME_PS0).
**********************************************************/
#define PS0_DSPI8           ((uint32_t)0x00000008UL)
#define PS0_DSPI0           ((uint32_t)0x00000010UL)
#define PS0_DSPI1           ((uint32_t)0x00000020UL)
#define PS0_DSPI2           ((uint32_t)0x00000040UL)
#define PS0_DSPI3           ((uint32_t)0x00000080UL)
#define PS0_DSPI4           ((uint32_t)0x00000100UL)
#define PS0_DSPI5           ((uint32_t)0x00000200UL)
#define PS0_DSPI6           ((uint32_t)0x00000400UL)
#define PS0_DSPI7           ((uint32_t)0x00000800UL)
#define PS0_LINFLEX8        ((uint32_t)0x00001000UL)
#define PS0_LINFLEX9        ((uint32_t)0x00002000UL)
#define PS0_LINFLEX10       ((uint32_t)0x00004000UL)
#define PS0_LINFLEX11       ((uint32_t)0x00008000UL)
#define PS0_FLEXCAN0        ((uint32_t)0x00010000UL)
#define PS0_FLEXCAN1        ((uint32_t)0x00020000UL)
#define PS0_FLEXCAN2        ((uint32_t)0x00040000UL)
#define PS0_FLEXCAN3        ((uint32_t)0x00080000UL)
#define PS0_FLEXCAN4        ((uint32_t)0x00100000UL)
#define PS0_FLEXCAN5        ((uint32_t)0x00200000UL)
#define PS0_DMA_CH_MUX      ((uint32_t)0x00800000UL)
#define PS0_FLEXCAN6        ((uint32_t)0x01000000UL)
#define PS0_FLEXCAN7        ((uint32_t)0x02000000UL)
#define PS0_LINFLEX12       ((uint32_t)0x04000000UL)
#define PS0_LINFLEX13       ((uint32_t)0x08000000UL)

/*********************************************************
* @brief     Peripheral Status Register 1 (ME_PS1).
**********************************************************/
#define PS1_ADC0            ((uint32_t)0x00000001UL)
#define PS1_ADC1            ((uint32_t)0x00000002UL)
#define PS1_I2C0            ((uint32_t)0x00001000UL)
#define PS1_I2C1            ((uint32_t)0x00002000UL)
#define PS1_I2C2            ((uint32_t)0x00004000UL)
#define PS1_I2C3            ((uint32_t)0x00008000UL)
#define PS1_LINFLEX0        ((uint32_t)0x00010000UL)
#define PS1_LINFLEX1        ((uint32_t)0x00020000UL)
#define PS1_LINFLEX2        ((uint32_t)0x00040000UL)
#define PS1_LINFLEX3        ((uint32_t)0x00080000UL)
#define PS1_LINFLEX4        ((uint32_t)0x00100000UL)
#define PS1_LINFLEX5        ((uint32_t)0x00200000UL)
#define PS1_LINFLEX6        ((uint32_t)0x00400000UL)
#define PS1_LINFLEX7        ((uint32_t)0x00800000UL)
#define PS1_CTU             ((uint32_t)0x02000000UL)
#define PS1_CANSAMPLER      ((uint32_t)0x10000000UL)

/*********************************************************
* @brief     Peripheral Status Register 2 (ME_PS2).
**********************************************************/
#define PS2_SIUL            ((uint32_t)0x00000010UL)
#define PS2_WKPU            ((uint32_t)0x00000020UL)
#define PS2_ETPU            ((uint32_t)0x00000080UL)
#define PS2_EMIOS0          ((uint32_t)0x00000100UL)
#define PS2_EMIOS1          ((uint32_t)0x00000200UL)
#define PS2_FILTER          ((uint32_t)0x01000000UL)
#define PS2_RTC_API         ((uint32_t)0x08000000UL)
#define PS2_PIT_RTI         ((uint32_t)0x10000000UL)

/*********************************************************
* @brief     Peripheral Status Register 3 (ME_PS3).
**********************************************************/
#define PS3_CMU             ((uint32_t)0x00000100UL)

/*******************************************************************
* @brief     Run Peripheral Configuration Registers (ME_RUN_PC0-7).
********************************************************************/
#define RUN_PC_NULL         ((uint32_t)0x00000000UL)
#define RUN_PC_RESET        ((uint32_t)0x00000001UL)    /* Read Only */
#define RUN_PC_TEST         ((uint32_t)0x00000002UL)
#define RUN_PC_SAFE         ((uint32_t)0x00000004UL)
#define RUN_PC_DRUN         ((uint32_t)0x00000008UL)
#define RUN_PC_RUN0         ((uint32_t)0x00000010UL)
#define RUN_PC_RUN1         ((uint32_t)0x00000020UL)
#define RUN_PC_RUN2         ((uint32_t)0x00000040UL)
#define RUN_PC_RUN3         ((uint32_t)0x00000080UL)

/************************************************************************
* @brief     Low-Power Peripheral Configuration Registers (ME_LP_PC0-7).
*************************************************************************/
#define LP_PC_NULL          ((uint32_t)0x00000000UL)
#define LP_PC_HALT          ((uint32_t)0x00000100UL)
#define LP_PC_STOP          ((uint32_t)0x00000400UL)
#define LP_PC_STANDBY       ((uint32_t)0x00002000UL)

/*******************************************************************
* @brief     Peripheral Control Registers (ME_PCTL0-143).
********************************************************************/
#define PCTL_RUN_CFG_MASK   ((uint8_t)0x07UL)
#define PCTL_LP_CFG_MASK    ((uint8_t)0x38UL)
#define PCTL_DBG_F_MASK     ((uint8_t)0x40UL)

/**
* @brief    PCTL_RUN_CFG_MASK.
* @details  Peripheral configuration select for run modes.
**/
#define PCTL_SEL_RUN_PC0    ((uint8_t)0x00UL)
#define PCTL_SEL_RUN_PC1    ((uint8_t)0x01UL)
#define PCTL_SEL_RUN_PC2    ((uint8_t)0x02UL)
#define PCTL_SEL_RUN_PC3    ((uint8_t)0x03UL)
#define PCTL_SEL_RUN_PC4    ((uint8_t)0x04UL)
#define PCTL_SEL_RUN_PC5    ((uint8_t)0x05UL)
#define PCTL_SEL_RUN_PC6    ((uint8_t)0x06UL)
#define PCTL_SEL_RUN_PC7    ((uint8_t)0x07UL)

/**
* @brief    PCTL_LP_CFG_MASK.
* @details  Peripheral configuration select for Low-Power modes.
**/
#define PCTL_SEL_LP_PC0     ((uint8_t)0x00UL)
#define PCTL_SEL_LP_PC1     ((uint8_t)0x08UL)
#define PCTL_SEL_LP_PC2     ((uint8_t)0x10UL)
#define PCTL_SEL_LP_PC3     ((uint8_t)0x18UL)
#define PCTL_SEL_LP_PC4     ((uint8_t)0x20UL)
#define PCTL_SEL_LP_PC5     ((uint8_t)0x28UL)
#define PCTL_SEL_LP_PC6     ((uint8_t)0x30UL)
#define PCTL_SEL_LP_PC7     ((uint8_t)0x38UL)

/*===============================================================================
*                   FUNCTION PROTOTYPES
*================================================================================*/
extern void Mcu_Init(const Mcu_Config_t *ConfigPtr);
extern void Mcu_DeInit(void);
extern void Mcu_LLD_InitMode(const Mcu_ModeConfig_t *ModePtr);
extern void Mcu_Apply_Mode(uint32_t Mcu_Mode);
extern void Mcu_LLD_InitClock(const Mcu_ClockConfig_t *ClockPtr);
extern void Mcu_MeasureExtOsc_Init(void);
extern void Mcu_DRUN_Init(void);
extern void Mcu_PLL_Init(const Mcu_ClockConfig_t *ClockPtr);
extern void Mcu_PLL_LLD_Init(uint8_t PllStep, uint8_t mExtOSC, uint8_t PllClkSel);
extern void Mcu_Periph_Init(const Mcu_ClockConfig_t *ClockPtr);
extern void Mcu_ClkOut_Init(const Mcu_ClockConfig_t *ClockPtr);

#endif /* MCU_LLD_H_ */
