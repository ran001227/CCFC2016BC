/**************************************************************************** 
* 
* Copyright (c) 2023  C*Core -   All Rights Reserved  
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* 
* PROJECT     : CCFC2016BC           
* DESCRIPTION : CCFC2016BC emios low level drivers code 
* HISTORY     : Initial version.
* @file     emios.h
* @version  1.1
* @date     2023 - 02 - 15
* @brief    Initial version.
*
*****************************************************************************/

#ifndef EMIOS_LLD_H
#define EMIOS_LLD_H

#include "pwm_lld.h"
#include "icu_lld.h"
#include "intc_lld.h"
#include "sys.h"

#if (LLD_USE_ICU == TRUE) || (LLD_USE_PWM == TRUE)

/*===========================================================================*/
/* eMIOS attributes.                                        */
/*===========================================================================*/

#define HAS_EMIOS0                     TRUE
#define EMIOS0_PCTL                    72
#define EMIOS0_GFR_F0F1_HANDLER        vector141
#define EMIOS0_GFR_F2F3_HANDLER        vector142
#define EMIOS0_GFR_F4F5_HANDLER        vector143
#define EMIOS0_GFR_F6F7_HANDLER        vector144
#define EMIOS0_GFR_F8F9_HANDLER        vector145
#define EMIOS0_GFR_F10F11_HANDLER      vector146
#define EMIOS0_GFR_F12F13_HANDLER      vector147
#define EMIOS0_GFR_F14F15_HANDLER      vector148
#define EMIOS0_GFR_F16F17_HANDLER      vector149
#define EMIOS0_GFR_F18F19_HANDLER      vector150
#define EMIOS0_GFR_F20F21_HANDLER      vector151
#define EMIOS0_GFR_F22F23_HANDLER      vector152
#define EMIOS0_GFR_F24F25_HANDLER      vector153
#define EMIOS0_GFR_F26F27_HANDLER      vector154
#define EMIOS0_GFR_F0F1_NUMBER         141
#define EMIOS0_GFR_F2F3_NUMBER         142
#define EMIOS0_GFR_F4F5_NUMBER         143
#define EMIOS0_GFR_F6F7_NUMBER         144
#define EMIOS0_GFR_F8F9_NUMBER         145
#define EMIOS0_GFR_F10F11_NUMBER       146
#define EMIOS0_GFR_F12F13_NUMBER       147
#define EMIOS0_GFR_F14F15_NUMBER       148
#define EMIOS0_GFR_F16F17_NUMBER       149
#define EMIOS0_GFR_F18F19_NUMBER       150
#define EMIOS0_GFR_F20F21_NUMBER       151
#define EMIOS0_GFR_F22F23_NUMBER       152
#define EMIOS0_GFR_F24F25_NUMBER       153
#define EMIOS0_GFR_F26F27_NUMBER       154
#define EMIOS0_GFR_F28F29_NUMBER       155
#define EMIOS0_GFR_F30F31_NUMBER       156


#define HAS_EMIOS1                     TRUE
#define EMIOS1_PCTL                    73
#define EMIOS1_GFR_F0F1_HANDLER        vector157
#define EMIOS1_GFR_F2F3_HANDLER        vector158
#define EMIOS1_GFR_F4F5_HANDLER        vector159
#define EMIOS1_GFR_F6F7_HANDLER        vector160
#define EMIOS1_GFR_F8F9_HANDLER        vector161
#define EMIOS1_GFR_F10F11_HANDLER      vector162
#define EMIOS1_GFR_F12F13_HANDLER      vector163
#define EMIOS1_GFR_F14F15_HANDLER      vector164
#define EMIOS1_GFR_F16F17_HANDLER      vector165
#define EMIOS1_GFR_F18F19_HANDLER      vector166
#define EMIOS1_GFR_F20F21_HANDLER      vector167
#define EMIOS1_GFR_F22F23_HANDLER      vector168
#define EMIOS1_GFR_F24F25_HANDLER      vector169
#define EMIOS1_GFR_F26F27_HANDLER      vector170
#define EMIOS1_GFR_F0F1_NUMBER         157
#define EMIOS1_GFR_F2F3_NUMBER         158
#define EMIOS1_GFR_F4F5_NUMBER         159
#define EMIOS1_GFR_F6F7_NUMBER         160
#define EMIOS1_GFR_F8F9_NUMBER         161
#define EMIOS1_GFR_F10F11_NUMBER       162
#define EMIOS1_GFR_F12F13_NUMBER       163
#define EMIOS1_GFR_F14F15_NUMBER       164
#define EMIOS1_GFR_F16F17_NUMBER       165
#define EMIOS1_GFR_F18F19_NUMBER       166
#define EMIOS1_GFR_F20F21_NUMBER       167
#define EMIOS1_GFR_F22F23_NUMBER       168
#define EMIOS1_GFR_F24F25_NUMBER       169
#define EMIOS1_GFR_F26F27_NUMBER       170

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

#define EMIOSMCR_MDIS                       (1UL << 30U)
#define EMIOSMCR_FRZ                        (1UL << 29U)
#define EMIOSMCR_GTBE                       (1UL << 28U)
#define EMIOSMCR_GPREN                      (1UL << 26U)
#define EMIOSMCR_GPRE(n)                    ((uint32_t)(n) << 8U) /* PRQA S 3472 */

#define EMIOSC_FREN                         (1UL << 31U)
#define EMIOSC_UCPRE(n)                     ((uint32_t)(n) << 26U) /* PRQA S 3472 */
#define EMIOSC_UCPREN                       (1UL << 25U)
#define EMIOSC_DMA                          (1UL << 24U)
#define EMIOSC_IF(n)                        ((uint32_t)(n) << 19U)
#define EMIOSC_FCK                          (1UL << 18U)
#define EMIOSC_FEN                          (1UL << 17U)
#define EMIOSC_FORCMA                       (1UL << 13U)
#define EMIOSC_FORCMB                       (1UL << 12U)
#define EMIOSC_BSL(n)                       ((uint32_t)(n) << 9U) /* PRQA S 3472 */
#define EMIOSC_EDSEL                        (1UL << 8U)
#define EMIOSC_EDPOL                        (1UL << 7U)
#define EMIOSC_MODE(n)                      ((uint32_t)(n) << 0)

#define EMIOS_BSL_COUNTER_BUS_A             0UL
#define EMIOS_BSL_COUNTER_BUS_2             1UL
#define EMIOS_BSL_INTERNAL_COUNTER          3UL

#define EMIOS_CCR_MODE_GPIO_IN              0
#define EMIOS_CCR_MODE_GPIO_OUT             1U
#define EMIOS_CCR_MODE_SAIC                 2U
#define EMIOS_CCR_MODE_SAOC                 3U
#define EMIOS_CCR_MODE_IPWM                 4U
#define EMIOS_CCR_MODE_IPM                  5U
#define EMIOS_CCR_MODE_DAOC_B_MATCH         6U
#define EMIOS_CCR_MODE_DAOC_BOTH_MATCH      7U
#define EMIOS_CCR_MODE_MC_CMS               16U
#define EMIOS_CCR_MODE_MC_CME               17U
#define EMIOS_CCR_MODE_MC_UP_DOWN           18U
#define EMIOS_CCR_MODE_OPWMT                38U
#define EMIOS_CCR_MODE_MCB_UP               80U
#define EMIOS_CCR_MODE_MCB_UP_DOWN          84U
#define EMIOS_CCR_MODE_OPWFMB               88U
#define EMIOS_CCR_MODE_OPWMCB_TE            92U
#define EMIOS_CCR_MODE_OPWMCB_LE            93U
#define EMIOS_CCR_MODE_OPWMB                96U

#define EMIOSS_OVR                          (1UL << 31U)
#define EMIOSS_OVRC                         (1UL << 31U)
#define EMIOSS_OVFL                         (1UL << 15U)
#define EMIOSS_OVFLC                        (1UL << 15U)
#define EMIOSS_FLAG                         (1UL << 0)
#define EMIOSS_FLAGC                        (1UL << 0)


/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

#if HAS_EMIOS0
/**
 * @brief   eMIOS0 peripheral configuration when started.
 * @note    The default configuration is 1 (always run) in run mode and
 *          2 (only halt) in low power mode.
 */
#if !defined(EMIOS0_START_PCTL)
#define EMIOS0_START_PCTL              (ME_PCTL_RUN(1) |          \
                                             ME_PCTL_LP(2))
#endif

/**
 * @brief   eMIOS0 peripheral configuration when stopped.
 * @note    The default configuration is 0 (never run) in run mode and
 *          0 (never run) in low power mode.
 */
#if !defined(EMIOS0_STOP_PCTL)
#define EMIOS0_STOP_PCTL               (ME_PCTL_RUN(0) |          \
                                             ME_PCTL_LP(0))
#endif
#endif

#if HAS_EMIOS1
/**
 * @brief   eMIOS1 peripheral configuration when started.
 * @note    The default configuration is 1 (always run) in run mode and
 *          2 (only halt) in low power mode.
 */
#if !defined(EMIOS1_START_PCTL)
#define EMIOS1_START_PCTL              (ME_PCTL_RUN(1) |  \
                                             ME_PCTL_LP(2))
#endif

/**
 * @brief   eMIOS1 peripheral configuration when stopped.
 * @note    The default configuration is 0 (never run) in run mode and
 *          0 (never run) in low power mode.
 */
#if !defined(EMIOS1_STOP_PCTL)
#define EMIOS1_STOP_PCTL               (ME_PCTL_RUN(0) |  \
                                             ME_PCTL_LP(0))
#endif
#endif

#define EMIOS0_CLK                     ((GetSystemClock() /         \
                                             PERIPHERAL3_CLK_DIV_VALUE) / \
                                             EMIOS0_GPRE_VALUE)

#define EMIOS1_CLK                     ((GetSystemClock() /         \
                                             PERIPHERAL3_CLK_DIV_VALUE) / \
                                             EMIOS1_GPRE_VALUE)

#define EMIOS0_START_PCTL              (ME_PCTL_RUN(1) |          \
                                             ME_PCTL_LP(2))
#define EMIOS0_STOP_PCTL               (ME_PCTL_RUN(0) |          \
                                             ME_PCTL_LP(0))

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#if (HAS_EMIOS0 == TRUE)
void reset_emios0_active_channels(void);
uint32_t get_emios0_active_channels(void);
void increase_emios0_active_channels(void);
void decrease_emios0_active_channels(void);
#if (LLD_USE_ICU == TRUE)
void icu_active_emios0_clock(ICUDriver *icup);
void icu_deactive_emios0_clock(ICUDriver *icup);
#endif
#if (LLD_USE_PWM == TRUE)
void pwm_active_emios0_clock(PWMDriver *pwmp);
void pwm_deactive_emios0_clock(PWMDriver *pwmp);
#endif
#endif
#if (HAS_EMIOS1 == TRUE)
void reset_emios1_active_channels(void);
uint32_t get_emios1_active_channels(void);
void increase_emios1_active_channels(void);
void decrease_emios1_active_channels(void);
#if (LLD_USE_ICU == TRUE)
void icu_active_emios1_clock(ICUDriver *icup);
void icu_deactive_emios1_clock(ICUDriver *icup);
#endif
#if (LLD_USE_PWM == TRUE)
void pwm_active_emios1_clock(PWMDriver *pwmp);
void pwm_deactive_emios1_clock(PWMDriver *pwmp);
#endif
#endif

#endif /* LLD_USE_ICU || LLD_USE_PWM */


#endif /* EMIOS_LLD_H */
