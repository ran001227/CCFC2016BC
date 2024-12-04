/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS, " AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
* PROJECT     : CCFC2016BC
* DESCRIPTION : CCFC2016BC CHIP SYS Init H file
* HISTORY     : Initial version.
* @file     sys.h
* @version  1.1
* @date     2023 - 02 - 15
* @brief    Initial version.
*
*****************************************************************************/

#ifndef SYS_H
#define SYS_H

#define CLOCK_SUCCESS           (0U)
#define CLOCK_FAILED            (1U)
#define CLOCK_FAILURE_HOOK()    irqSysHalt() /* PRQA S 3472 */
/**
 * @name    ME_GS register bits definitions
 * @{
 */
#define ME_GS_SYSCLK_MASK       (15U << 0U)
#define ME_GS_SYSCLK_FIRC       (0U << 0U)
#define ME_GS_SYSCLK_FIRCDIV    (1U << 0U)
#define ME_GS_SYSCLK_XOSC       (2U << 0U)
#define ME_GS_SYSCLK_XOSCDIV    (3U << 0U)
#define ME_GS_SYSCLK_FMPLL      (4U << 0U)
/** @} */

/**
 * @name    ME_ME register bits definitions
 * @{
 */
#define ME_MEN_RESET            (1UL << 0U)
#define ME_MEN_TEST             (1UL << 1U)
#define ME_MEN_SAFE             (1UL << 2U)
#define ME_MEN_DRUN             (1UL << 3U)
#define ME_MEN_RUN0             (1UL << 4U)
#define ME_MEN_RUN1             (1UL << 5U)
#define ME_MEN_RUN2             (1UL << 6U)
#define ME_MEN_RUN3             (1UL << 7U)
#define ME_MEN_HALT             (1UL << 8U)
#define ME_MEN_STOP             (1UL << 10U)
#define ME_MEN_STANDBY          (1UL << 13U)
/** @} */

/** @} */

#define FIRCDIV_VALUE           (1U)
#define XOSCDIV_VALUE           (1U)
/**
 * @name    FMPLL_CR register bits definitions
 * @{
 */
#define FMPLL_IDF_MASK          (15UL << 26U)
#define FMPLL_IDF(n)            (((uint32_t)((n) - 1U)) << 26U)
#define FMPLL_ODF_MASK          (3UL << 24U)
#define FMPLL_ODF_DIV2          (0UL << 24U)
#define FMPLL_ODF_DIV4          (1UL << 24U)
#define FMPLL_ODF_DIV8          (2UL << 24U)
#define FMPLL_ODF_DIV16         (3UL << 24U)
#define FMPLL_ODF               FMPLL_ODF_DIV2
#define FMPLL_NDIV_MASK         (0x7FUL << 16U)
#define FMPLL_NDIV(n)           (((uint32_t)(n)) << 16U)
#define FMPLL_EN_PLL_SW         (1UL << 8U)
#define FMPLL_PLL_FAIL_MASK     (1UL << 2U)
/** @} */

/**
 * @brief   FMPLL IDF division value.
 */
#define FMPLL_IDF_VALUE         (2U)
/**
 * @brief   FMPLL NDIV division value.
 */
#define FMPLL_NDIV_VALUE        (40U)
/**
 * @brief   FMPLL ODF division value.
 */
#if (FMPLL_ODF == FMPLL_ODF_DIV8)
#define FMPLL_ODF_VALUE         (8U)
#elif (FMPLL_ODF == FMPLL_ODF_DIV4)
#define FMPLL_ODF_VALUE         (4U)
#elif (FMPLL_ODF == FMPLL_ODF_DIV2)
#define FMPLL_ODF_VALUE         (2U)
#elif (FMPLL_ODF == FMPLL_ODF_DIV16)
#define FMPLL_ODF_VALUE         (16U)
#endif

/**
 * @brief   FMPLL_VCO_CLK clock point.
 */
#define FMPLL_VCO_CLK           ((XOSC_CLK / FMPLL_IDF_VALUE) * FMPLL_NDIV_VALUE)

/**
 * @brief   FMPLL_CLK clock point.
 */
#define FMPLL_CLK               (FMPLL_VCO_CLK / FMPLL_ODF_VALUE)

/**
 * @brief   FXOSC_CLK clock point.
 */
#define XOSC_CLK                (16000000U)

#define FXOSC_CLK                (16000000U)
/** @} */

/**
 * @name    Internal clock sources
 * @{
 */
#define FIRC_CLK                (16000000U)   /** < Internal fast RC oscillator. */
#define SIRC_CLK                (128000U)     /** < Internal RC slow oscillator. */
/** @} */

/** @} */
#define IRCOSC_CLK			       16000000			     //External crystal oscillator freq 16M
#define CAN_PLL_CLK				   16000000				 //16MHz CAN PLL clock
#define CANFD_CLK                  160000000
#define PERIPHERAL_CLK             160000000             //50MHz Peripheral clocks

/**
 * @name    ME_MCTL register bits definitions
 * @{
 */
#define ME_MCTL_KEY            (0x5AF0U)
#define ME_MCTL_KEY_INV        (0xA50FU)
#define ME_MCTL_MODE_MASK      (15UL << 28U)
#define ME_MCTL_MODE(n)        (((uint32_t)(n)) << 28U) /* PRQA S 3472 */
/** @} */

/**
 * @name    ME_PCTL registers bits definitions
 * @{
 */
#define ME_PCTL_RUN_MASK       (7UL << 0U)
#define ME_PCTL_RUN(n)         (((uint8_t)(n)) << 0U)
#define ME_PCTL_LP_MASK        (7UL << 3U)
#define ME_PCTL_LP(n)          (((uint8_t)(n)) << 3U)
#define ME_PCTL_DBG            (1UL << 6U)
/** @} */

#define PIT_PCTL                       (92U)
#define PIT_ENABLE_CLOCK()             SetPeripheralClockMode(PIT_PCTL, PIT_START_PCTL);
#define PIT_DISABLE_CLOCK()            SetPeripheralClockMode(PIT_PCTL, PIT_STOP_PCTL);

#define PERIPHERAL1_CLK_DIV_VALUE      (2U)
#define PERIPHERAL2_CLK_DIV_VALUE      (2U)
#define PERIPHERAL3_CLK_DIV_VALUE      (2U)

/* Module data structures and types. */
/**
 * @brief   Peripheral type.
 */
typedef enum
{
    PERIPHERAL_PIT0 = 0u
} peripheral_t;

extern void SetPeripheralClockMode(uint32_t n, uint32_t pctl);
extern uint32_t GetSystemClock(void);
extern uint32_t GetPeripheralClock(peripheral_t peripheral);

extern void SYSTEM_Init(void);
extern void SYSTEM_Init_LowPower(void);
extern void BCM_SYSTEM_Init(void);
extern void SWT_DisableWatchDog(void);
extern void delayms(volatile uint32_t ms);
extern void delay(volatile uint32_t x);
extern void delay_ms(uint32_t ms);
extern void CLK_OUT(void);
extern void InitPeriClkGen(void);
extern uint8_t SetRunMode(uint8_t mode);
extern void SWT_EnableWatchdog(void);

#endif /* _SYS_H_ */
