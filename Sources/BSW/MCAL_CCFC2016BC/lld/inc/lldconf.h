/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS, " AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
* PROJECT     : CCFC2016BC
* DESCRIPTION : CCFC2016BC  low level drivers config code
* HISTORY     : Initial version.
* @file     lldconf.h
* @version  1.1
* @date     2023 - 02 - 15
* @brief    Initial version.
*
*****************************************************************************/

#ifndef LLDCONF_H_
#define LLDCONF_H_

#define CCFC2016BC_144LQFP_EVB      0U
#define CCFC2016BC_176LQFP_EVB      1U

#ifndef STD_ON
#define STD_ON                      0x01U
#endif

#ifndef STD_OFF
#define STD_OFF                     0x00U
#endif

/**
* @brief    NULL pointer.
**/
#ifndef NULL_PTR
#define NULL_PTR            ((void *)0)
#endif

typedef enum {
    CHANNEL0 = 0,
    CHANNEL1,
    CHANNEL2,
    CHANNEL3,
    CHANNEL4,
    CHANNEL5,
    CHANNEL6,
    CHANNEL7
} channel_enum;

/**
 * @name    Drivers enable switches
 */
#define LLD_USE_DMA                 FALSE
#define LLD_USE_PAL                 FALSE
#define LLD_USE_PIT                 FALSE
#define LLD_USE_STM                 FALSE
#define LLD_USE_SERIAL              FALSE
#define LLD_USE_PWM                 FALSE
#define LLD_USE_ICU                 TRUE
#define LLD_USE_CAN                 TRUE
#define LLD_USE_SPI                 TRUE
#define LLD_USE_ADC                 FALSE
#define LLD_USE_CTU                 FALSE
#define LLD_USE_I2C                 TRUE
#define LLD_USE_RTC                 TRUE
#define LLD_USE_SWT                 TRUE
#define LLD_USE_SARADC              FALSE
#define LLD_USE_FCCU                FALSE
#define LLD_USE_CRC                 FALSE
#define LLD_USE_WKPU                FALSE
#define LLD_USE_LIN                 FALSE
#define LLD_USE_I2S                 FALSE
/** @} */

/* ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==   = */
/**
 * @name SERIAL driver related setting
 * @{
 */
/* ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==   = */

/**
 * @name    SERIAL DMA modes
 * @{
 */
#define SERIAL_DMA_OFF                 0
#define SERIAL_DMA_ON                  1
/** @} */

/**
 * @name    LIN DMA modes
 * @{
 */
#define LIN_DMA_OFF                    0
#define LIN_DMA_ON                     1
/** @} */

/**
 * @name    LINFlex Mode Settings
 * @{
 */
#define LINFLEX_MODE_NONE              0
#define LINFLEX_MODE_SERIAL            1
#define LINFLEX_MODE_LIN               2
/** @} */

/** @} */

/* ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==   = */
/**
 * @name SPI driver related setting
 * @{
 */
/* ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==   = */

/**
 * @brief   Enables synchronous APIs.
 * @note    Disabling this option saves both code and data space.
 */
#if!defined(SPI_USE_WAIT)
#define SPI_USE_WAIT                TRUE
#endif

/**
 * @brief   Enables the @p spiAcquireBus() and @p spiReleaseBus() APIs.
 * @note    Disabling this option saves both code and data space.
 */
#if!defined(SPI_USE_MUTUAL_EXCLUSION)
#define SPI_USE_MUTUAL_EXCLUSION    FALSE
#endif
/** @} */

/**
 * @name    SPI DMA modes
 * @{
 */
#define SPI_DMA_NONE                   0
#define SPI_DMA_RX_ONLY                1
#define SPI_DMA_RX_AND_TX              2
/** @} */

/**
 * @name    ADC DMA modes
 * @{
 */
#define ADC_DMA_OFF                    0
#define ADC_DMA_ON                     1
/** @} */

/*
 * SERIAL driver system settings.
 */
#define LINFLEX0_SETTING               LINFLEX_MODE_NONE
#define LINFLEX1_SETTING               LINFLEX_MODE_NONE
#define LINFLEX2_SETTING               LINFLEX_MODE_NONE
#define LINFLEX3_SETTING               LINFLEX_MODE_NONE
#define LINFLEX4_SETTING               LINFLEX_MODE_NONE
#define LINFLEX5_SETTING               LINFLEX_MODE_NONE
#define LINFLEX6_SETTING               LINFLEX_MODE_NONE
#define LINFLEX7_SETTING               LINFLEX_MODE_NONE
#define LINFLEX8_SETTING               LINFLEX_MODE_NONE
#define LINFLEX9_SETTING               LINFLEX_MODE_NONE
#define LINFLEX0_PRIORITY              8
#define LINFLEX1_PRIORITY              8
#define LINFLEX2_PRIORITY              8
#define LINFLEX3_PRIORITY              8
#define LINFLEX4_PRIORITY              8
#define LINFLEX5_PRIORITY              8
#define LINFLEX6_PRIORITY              8
#define LINFLEX7_PRIORITY              8
#define LINFLEX8_PRIORITY              8
#define LINFLEX9_PRIORITY              8
#define SERIAL_DMA_MODE                SERIAL_DMA_OFF
#define LIN_DMA_MODE                   LIN_DMA_OFF

/*
 * SPI driver system settings.
 */
#define SPI_USE_DSPI0                  FALSE
#define SPI_USE_DSPI1                  FALSE
#define SPI_USE_DSPI2                  FALSE
#define SPI_USE_DSPI3                  FALSE
#define SPI_USE_DSPI4                  FALSE
#define SPI_USE_DSPI5                  TRUE
#define SPI_DMA_MODE                   SPI_DMA_RX_AND_TX
#define SPI_DSPI0_MCR                  (0U | MCR_PCSIS0 | MCR_PCSIS1 | MCR_PCSIS2 | MCR_PCSIS3 | MCR_PCSIS4 | MCR_PCSIS5)
#define SPI_DSPI1_MCR                  (0U | MCR_PCSIS0 | MCR_PCSIS1 | MCR_PCSIS2 | MCR_PCSIS3 | MCR_PCSIS4)
#define SPI_DSPI2_MCR                  (0U | MCR_PCSIS0 | MCR_PCSIS1 | MCR_PCSIS2 | MCR_PCSIS3)
#define SPI_DSPI3_MCR                  (0U | MCR_PCSIS0 | MCR_PCSIS1 | MCR_PCSIS2)
#define SPI_DSPI4_MCR                  (0U | MCR_PCSIS0 | MCR_PCSIS1)
#define SPI_DSPI5_MCR                  (0U | MCR_PCSIS0)

#define SPI_DSPI0_TX1_DMA_CH_ID        4
#define SPI_DSPI0_TX2_DMA_CH_ID        5
#define SPI_DSPI0_RX_DMA_CH_ID         6
#define SPI_DSPI1_TX1_DMA_CH_ID        7
#define SPI_DSPI1_TX2_DMA_CH_ID        8
#define SPI_DSPI1_RX_DMA_CH_ID         9
#define SPI_DSPI2_TX1_DMA_CH_ID        10
#define SPI_DSPI2_TX2_DMA_CH_ID        11
#define SPI_DSPI2_RX_DMA_CH_ID         12
#define SPI_DSPI3_TX1_DMA_CH_ID        13
#define SPI_DSPI3_TX2_DMA_CH_ID        14
#define SPI_DSPI3_RX_DMA_CH_ID         15
#define SPI_DSPI4_TX1_DMA_CH_ID        1
#define SPI_DSPI4_TX2_DMA_CH_ID        2
#define SPI_DSPI4_RX_DMA_CH_ID         3
#define SPI_DSPI5_TX1_DMA_CH_ID        4
#define SPI_DSPI5_TX2_DMA_CH_ID        5
#define SPI_DSPI5_RX_DMA_CH_ID         6
#define SPI_DSPI6_TX1_DMA_CH_ID        7
#define SPI_DSPI6_TX2_DMA_CH_ID        8
#define SPI_DSPI6_RX_DMA_CH_ID         9
#define SPI_DSPI7_TX1_DMA_CH_ID        10
#define SPI_DSPI7_TX2_DMA_CH_ID        11
#define SPI_DSPI7_RX_DMA_CH_ID         12
#define SPI_DSPI8_TX1_DMA_CH_ID        13
#define SPI_DSPI8_TX2_DMA_CH_ID        14
#define SPI_DSPI8_RX_DMA_CH_ID         15

#define SPI_DSPI0_DMA_IRQ_PRIO         10
#define SPI_DSPI1_DMA_IRQ_PRIO         10
#define SPI_DSPI2_DMA_IRQ_PRIO         10
#define SPI_DSPI3_DMA_IRQ_PRIO         10
#define SPI_DSPI4_DMA_IRQ_PRIO         10
#define SPI_DSPI5_DMA_IRQ_PRIO         10
#define SPI_DSPI6_DMA_IRQ_PRIO         10
#define SPI_DSPI7_DMA_IRQ_PRIO         10
#define SPI_DSPI8_DMA_IRQ_PRIO         10

#define SPI_DSPI0_IRQ_PRIO             10
#define SPI_DSPI1_IRQ_PRIO             10
#define SPI_DSPI2_IRQ_PRIO             10
#define SPI_DSPI3_IRQ_PRIO             10
#define SPI_DSPI4_IRQ_PRIO             10
#define SPI_DSPI5_IRQ_PRIO             10
#define SPI_DSPI6_IRQ_PRIO             10
#define SPI_DSPI7_IRQ_PRIO             10
#define SPI_DSPI8_IRQ_PRIO             10


#define DSPI_FIFO_DEPTH                4U
#define HAS_EDMA                       TRUE
/*
 * ICU - PWM driver system settings.
 */
#define ICU_USE_EMIOS0_CH0             TRUE
#define ICU_USE_EMIOS0_CH1             FALSE
#define ICU_USE_EMIOS0_CH2             FALSE
#define ICU_USE_EMIOS0_CH3             FALSE
#define ICU_USE_EMIOS0_CH4             FALSE
#define ICU_USE_EMIOS0_CH5             FALSE
#define ICU_USE_EMIOS0_CH6             FALSE
#define ICU_USE_EMIOS0_CH7             FALSE
#define ICU_USE_EMIOS0_CH24            FALSE

#define PWM_USE_EMIOS0_GROUP0          TRUE
#define PWM_USE_EMIOS0_GROUP1          FALSE

#define EMIOS0_GFR_F0F1_PRIORITY       8
#define EMIOS0_GFR_F2F3_PRIORITY       8
#define EMIOS0_GFR_F4F5_PRIORITY       8
#define EMIOS0_GFR_F6F7_PRIORITY       8
#define EMIOS0_GFR_F8F9_PRIORITY       8
#define EMIOS0_GFR_F10F11_PRIORITY     8
#define EMIOS0_GFR_F12F13_PRIORITY     8
#define EMIOS0_GFR_F14F15_PRIORITY     8
#define EMIOS0_GFR_F16F17_PRIORITY     8
#define EMIOS0_GFR_F18F19_PRIORITY     8
#define EMIOS0_GFR_F20F21_PRIORITY     8
#define EMIOS0_GFR_F22F23_PRIORITY     8
#define EMIOS0_GFR_F24F25_PRIORITY     8

#define EMIOS0_START_PCTL              (ME_PCTL_RUN(1) |          \
                                             ME_PCTL_LP(2))
#define EMIOS0_STOP_PCTL               (ME_PCTL_RUN(0) |          \
                                             ME_PCTL_LP(0))

#define EMIOS0_GPRE_VALUE              200UL

#define ICU_USE_EMIOS1_CH24            FALSE

#define PWM_USE_EMIOS1_GROUP0          FALSE
#define PWM_USE_EMIOS1_GROUP1          FALSE
#define PWM_USE_EMIOS1_GROUP2          FALSE

#define EMIOS1_GFR_F0F1_PRIORITY       8
#define EMIOS1_GFR_F2F3_PRIORITY       8
#define EMIOS1_GFR_F4F5_PRIORITY       8
#define EMIOS1_GFR_F6F7_PRIORITY       8
#define EMIOS1_GFR_F8F9_PRIORITY       8
#define EMIOS1_GFR_F10F11_PRIORITY     8
#define EMIOS1_GFR_F12F13_PRIORITY     8
#define EMIOS1_GFR_F14F15_PRIORITY     8
#define EMIOS1_GFR_F16F17_PRIORITY     8
#define EMIOS1_GFR_F18F19_PRIORITY     8
#define EMIOS1_GFR_F20F21_PRIORITY     8
#define EMIOS1_GFR_F22F23_PRIORITY     8
#define EMIOS1_GFR_F24F25_PRIORITY     8

#define EMIOS1_START_PCTL              (ME_PCTL_RUN(1) |          \
                                             ME_PCTL_LP(2))
#define EMIOS1_STOP_PCTL               (ME_PCTL_RUN(0) |          \
                                             ME_PCTL_LP(0))

#define EMIOS1_GPRE_VALUE              200UL

/*
 * CAN driver system settings.
 */
#define CAN_USE_FILTERS                TRUE

#define CAN_USE_FLEXCAN0               TRUE
#define CAN_FLEXCAN0_USE_EXT_CLK       TRUE
#define CAN_FLEXCAN0_IRQ_PRIORITY      11
#define CAN_NUM_RX_MAILBOXES            8U
#define CAN_NUM_TX_MAILBOXES            24U
#define CAN_FLEXCAN0_START_PCTL        (ME_PCTL_RUN(1) |          \
                                             ME_PCTL_LP(2))
#define CAN_FLEXCAN0_STOP_PCTL         (ME_PCTL_RUN(0) |          \
                                             ME_PCTL_LP(0))

#define CAN_USE_FLEXCAN1               FALSE
#define CAN_FLEXCAN1_USE_EXT_CLK       TRUE
#define CAN_FLEXCAN1_IRQ_PRIORITY      11
#define CAN_FLEXCAN1_START_PCTL        (ME_PCTL_RUN(1) |          \
                                             ME_PCTL_LP(2))
#define CAN_FLEXCAN1_STOP_PCTL         (ME_PCTL_RUN(0) |          \
                                             ME_PCTL_LP(0))

#define CAN_USE_FLEXCAN2               FALSE
#define CAN_FLEXCAN2_USE_EXT_CLK       TRUE
#define CAN_FLEXCAN2_IRQ_PRIORITY      11
#define CAN_FLEXCAN2_START_PCTL        (ME_PCTL_RUN(1) |          \
                                             ME_PCTL_LP(2))
#define CAN_FLEXCAN2_STOP_PCTL         (ME_PCTL_RUN(0) |          \
                                             ME_PCTL_LP(0))

#define CAN_USE_FLEXCAN3               FALSE
#define CAN_FLEXCAN3_USE_EXT_CLK       TRUE
#define CAN_FLEXCAN3_IRQ_PRIORITY      11
#define CAN_FLEXCAN3_START_PCTL        (ME_PCTL_RUN(1) |          \
                                             ME_PCTL_LP(2))
#define CAN_FLEXCAN3_STOP_PCTL         (ME_PCTL_RUN(0) |          \
                                             ME_PCTL_LP(0))

#define CAN_USE_FLEXCAN4               FALSE
#define CAN_FLEXCAN4_USE_EXT_CLK       TRUE
#define CAN_FLEXCAN4_IRQ_PRIORITY      11
#define CAN_FLEXCAN4_START_PCTL        (ME_PCTL_RUN(1) |          \
                                             ME_PCTL_LP(2))
#define CAN_FLEXCAN4_STOP_PCTL         (ME_PCTL_RUN(0) |          \
                                             ME_PCTL_LP(0))

#define CAN_USE_FLEXCAN5               FALSE
#define CAN_FLEXCAN5_USE_EXT_CLK       TRUE
#define CAN_FLEXCAN5_IRQ_PRIORITY      11
#define CAN_FLEXCAN5_START_PCTL        (ME_PCTL_RUN(1) |          \
                                             ME_PCTL_LP(2))
#define CAN_FLEXCAN5_STOP_PCTL         (ME_PCTL_RUN(0) |          \
                                             ME_PCTL_LP(0))

#define CAN_USE_FLEXCAN6               FALSE
#define CAN_FLEXCAN6_USE_EXT_CLK       TRUE
#define CAN_FLEXCAN6_IRQ_PRIORITY      11
#define CAN_FLEXCAN6_START_PCTL        (ME_PCTL_RUN(1) |          \
                                             ME_PCTL_LP(2))
#define CAN_FLEXCAN6_STOP_PCTL         (ME_PCTL_RUN(0) |          \
                                             ME_PCTL_LP(0))

#define CAN_USE_FLEXCAN7               FALSE
#define CAN_FLEXCAN7_USE_EXT_CLK       TRUE
#define CAN_FLEXCAN7_IRQ_PRIORITY      11
#define CAN_FLEXCAN7_START_PCTL        (ME_PCTL_RUN(1) |          \
                                             ME_PCTL_LP(2))
#define CAN_FLEXCAN7_STOP_PCTL         (ME_PCTL_RUN(0) |          \
                                             ME_PCTL_LP(0))

/*
* ADC driver system settings.
*/
#define ADC_DMA_MODE                   ADC_DMA_OFF
#define ADC_USE_ADC0                   FALSE
#define ADC_ADC0_CLK_FREQUENCY         HALF_PERIPHERAL_SET_CLOCK_FREQUENCY
#define ADC_ADC0_AUTO_CLOCK_OFF        FALSE
#define ADC_ADC0_WD_PRIORITY           12
#define ADC_ADC0_EOC_PRIORITY          ADC_ADC0_WD_PRIORITY
#define ADC_ADC0_START_PCTL            (ME_PCTL_RUN(1) |          \
                                             ME_PCTL_LP(2))
#define ADC_ADC0_STOP_PCTL             (ME_PCTL_RUN(0) |          \
                                             ME_PCTL_LP(0))

#define ADC_USE_ADC1                   FALSE
#define ADC_ADC1_CLK_FREQUENCY         HALF_PERIPHERAL_SET_CLOCK_FREQUENCY
#define ADC_ADC1_AUTO_CLOCK_OFF        FALSE
#define ADC_ADC1_WD_PRIORITY           12
#define ADC_ADC1_EOC_PRIORITY          ADC_ADC1_WD_PRIORITY
#define ADC_ADC1_START_PCTL            (ME_PCTL_RUN(1) |          \
                                             ME_PCTL_LP(2))
#define ADC_ADC1_STOP_PCTL             (ME_PCTL_RUN(0) |          \
                                             ME_PCTL_LP(0))
/*
* PIT driver system settings.
*/
#define PIT_CHANNEL_CH0_ENABLED             TRUE
#define PIT_CHANNEL_CH1_ENABLED             TRUE
#define PIT_CHANNEL_CH2_ENABLED             TRUE
#define PIT_CHANNEL_CH3_ENABLED             TRUE
#define PIT_CHANNEL_CH4_ENABLED             TRUE
#define PIT_CHANNEL_CH5_ENABLED             TRUE
#define PIT_CHANNEL_CH6_ENABLED             TRUE
#define PIT_CHANNEL_CH7_ENABLED             TRUE

#define PIT_START_PCTL                 (ME_PCTL_RUN(1) |          \
                                             ME_PCTL_LP(2))
#define PIT_STOP_PCTL                  (ME_PCTL_RUN(0) |          \
                                             ME_PCTL_LP(0))
#define PIT_CH0_IRQ_PRIO               4
#define PIT_CH1_IRQ_PRIO               12
#define PIT_CH2_IRQ_PRIO               12
#define PIT_CH3_IRQ_PRIO               12
#define PIT_CH4_IRQ_PRIO               12
#define PIT_CH5_IRQ_PRIO               12
#define PIT_CH6_IRQ_PRIO               12
#define PIT_CH7_IRQ_PRIO               12
/*
* STM driver system settings.
*/
#define STM_USE_STM0                   TRUE
#define STM_USE_STM0_INT               TRUE

#define STM0_CH0_ENABLED                TRUE
#define STM0_CH1_ENABLED                TRUE
#define STM0_CH2_ENABLED                TRUE
#define STM0_CH3_ENABLED                TRUE

#define STM0_SYSCLOCK_PRE                64

#define STM0_CH0_IRQ_PRIO              11
#define STM0_CH1_IRQ_PRIO              11
#define STM0_CH2_IRQ_PRIO              11
#define STM0_CH3_IRQ_PRIO              12

/*
 * I2C driver system settings.
 */
#define I2C_IRQ_PRIORITY               INTC_PSR_ENABLE(INTC_PSR_MAINCORE, 13)

/*
 * RTC driver system settings.
 */
#define RTCAPI_USE                     TRUE
#define RTC_IRQ_PRIO                   1
#define API_IRQ_PRIO                   1

#define RTCAPI_CLOCK_SOURCE_OSC        TRUE
#define RTCAPI_FREQUENCY               128000U
#define RTCAPI_TIMEOUT_PERIOD          0
#define RTC_INTERRUPT_MODE             TRUE
#define API_INTERRUPT_MODE             FALSE
#define RTCAPI_STOP_IN_STOP_MODE       FALSE
#define RTCAPI_FREEZE_IN_DEBUG_MODE    TRUE
#define RTCAPI_SYSTEM_RESET            FALSE
#define RTCAPI_FREEZE_IN_DEBUG_MODE    TRUE

/**
 * @name    Clock selector value used in the RTTC register
 * @{
 */
#define RTCC_CLKSEL_SXOSC   0U //  32 KHz
#define RTCC_CLKSEL_SIRC    1U //  128 kHz
#define RTCC_CLKSEL_FIRC    2U //  16 MHz

#define API_RTC_CLK_SRC                RTCC_CLKSEL_SXOSC

/* RTC Attributes */
#define HAS_RTC                       TRUE
#define RTC_HANDLER                   vector38
#define RTC_INT_NUMBER                38

#define API_HANDLER                   vector39
#define API_INT_NUMBER                39

#define HAS_RTC1                       FALSE
#define HAS_RTC2                       FALSE
#define HAS_RTC3                       FALSE

/*
 * SWT driver system settings.
 */
#define SWT_USE_SWT0                   TRUE
#define SWT0_IRQ_PRIO                  15

#define HAS_SWT0                       TRUE
#define SWT0_HANDLER                   vector28
#define SWT0_INT_NUMBER                28

#define HAS_SWT1                       FALSE
#define HAS_SWT2                       FALSE
#define HAS_SWT3                       FALSE
#define HAS_FCCU                       FALSE

#define SWT0_CLOCK_SOURCE_OSC          TRUE
#define SWT0_FREQUENCY                 102950U
#define SWT0_TIMEOUT_PERIOD            0
#define SWT0_INTERRUPT_MODE            TRUE
#define SWT0_PSEUDO_RANDOM_KEY         FALSE
#define SWT0_WINDOW_MODE               FALSE
#define SWT0_WINDOW_PERIOD             0
#define SWT0_STOP_IN_STOP_MODE         FALSE
#define SWT0_FREEZE_IN_DEBUG_MODE      FALSE
#define SWT0_SYSTEM_RESET              FALSE

/**
 * DECFILTER Defines
 * */
#define DECFILTER_BASE                 0xFFF8C000UL
#define DECFILTER_COEF_COUNT           9u
#define DECFILTER_TAP_COUNT            8u

#endif /* LLDCONF_H_ */
