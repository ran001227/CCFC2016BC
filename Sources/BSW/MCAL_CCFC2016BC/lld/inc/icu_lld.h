/**************************************************************************** 
* 
* Copyright (c) 2023  C*Core -   All Rights Reserved  
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* 
* PROJECT     : CCFC2016BC
* DESCRIPTION : CCFC2016BC icu low level drivers code
* HISTORY     : Initial version.
* @file     icu_lld.h
* @version  1.4
* @date     2023 - 06 - 12
* @brief    Initial version.
*
*****************************************************************************/
#ifndef ICU_LLD_H
#define ICU_LLD_H

#include "CCFC2016BC.h"
#include "common.h"
#include "lldconf.h"


#if (LLD_USE_ICU == TRUE)

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

typedef struct ICUDriver ICUDriver;
typedef void (*icucallback_t)(const ICUDriver *icudriver);
extern ICUDriver ICUD_0;

/**
 * @brief ICU interrupt group.
 */
typedef enum {
    ICU_INTERRUPT_GROUP_0 = 0x00000001,
    ICU_INTERRUPT_GROUP_1 = 0x00000004,
    ICU_INTERRUPT_GROUP_2 = 0x00000010,
    ICU_INTERRUPT_GROUP_3 = 0x00000040,
    ICU_INTERRUPT_GROUP_4 = 0x00000100,
    ICU_INTERRUPT_GROUP_5 = 0x00000400,
    ICU_INTERRUPT_GROUP_6 = 0x00001000,
    ICU_INTERRUPT_GROUP_7 = 0x00004000,
    ICU_INTERRUPT_GROUP_8 = 0x00010000,
    ICU_INTERRUPT_GROUP_9 = 0x00040000,
    ICU_INTERRUPT_GROUP_10 = 0x00100000,
    ICU_INTERRUPT_GROUP_11 = 0x00400000,
    ICU_INTERRUPT_GROUP_12 = 0x01000000,
    ICU_INTERRUPT_GROUP_13 = 0x04000000,
    ICU_INTERRUPT_GROUP_14 = 0x10000000,
    ICU_INTERRUPT_GROUP_15 = 0x40000000
} icu_interrupt_group_t;


/**
 * @brief ICU driver mode.
 */
typedef enum {
    ICU_INPUT_SINGLE_ACTION_MODE = 0,
    ICU_INPUT_PULSE_WIDTH_MEASUREMENT_MODE = 1,
    ICU_INPUT_PERIOD_WIDTH_MEASUREMENT_MODE = 2
} icumode_t;

typedef enum {
    ICU_USER_MODE_EDGE_COUNTER = 0,
    ICU_USER_MODE_TIME_STAMP       = 1,
    ICU_USER_MODE_WIDTH_PERIOD_MEASUREMENT = 2,
    ICU_USER_MODE_WIDTH_MEASUREMENT = 3,
    ICU_USER_MODE_PERIOD_MEASUREMENT = 4
} icuusermode_t;

typedef enum {
    FALLING_EDGE = 0,
    RISING_EDGE = 1,
    BOTH_EDGE = 2
} icuedgepolarity_t;

/**
 * @brief   ICU frequency type.
 */
typedef uint32_t icufreq_t;

/**
 * @brief   ICU counter type.
 */
typedef uint16_t icucnt_t;

/**
 * @brief   ICU pulse edge type.
 */
typedef uint16_t icupe_t;

/**
 * @brief   Pulse edge structure.
 * @note    It contains for each channel the temporary counter A2
 *          values used to calculate the period and width of the
 *          related input pulse.
 */
typedef struct {
    /**
    * @brief   Counter A2 value on the first pulse edge.
    * @note    First rising edge for ICU_INPUT_ACTIVE_HIGH,
    *          first falling edge for ICU_INPUT_ACTIVE_LOW.
    */
    icupe_t    a2_1;
    /**
    * @brief   Counter A2 value on the second pulse edge.
    * @note    First falling edge for ICU_INPUT_ACTIVE_HIGH,
    *          first rising edge for ICU_INPUT_ACTIVE_LOW.
    */
    icupe_t    a2_2;
    /**
    * @brief   Counter A2 value on the first pulse edge.
    * @note    Second rising edge for ICU_INPUT_ACTIVE_HIGH,
    *          second falling edge for ICU_INPUT_ACTIVE_LOW.
    */
    icupe_t    a2_3;
} ICUPulseEdges;


typedef union {
    vuint32_t R;
    struct {
        vuint32_t ch31:1;
        vuint32_t ch30:1;
        vuint32_t ch29:1;
        vuint32_t ch28:1;
        vuint32_t ch27:1;
        vuint32_t ch26:1;
        vuint32_t ch25:1;
        vuint32_t ch24:1;
        vuint32_t ch23:1;
        vuint32_t ch22:1;
        vuint32_t ch21:1;
        vuint32_t ch20:1;
        vuint32_t ch19:1;
        vuint32_t ch18:1;
        vuint32_t ch17:1;
        vuint32_t ch16:1;
        vuint32_t ch15:1;
        vuint32_t ch14:1;
        vuint32_t ch13:1;
        vuint32_t ch12:1;
        vuint32_t ch11:1;
        vuint32_t ch10:1;
        vuint32_t ch9:1;
        vuint32_t ch8:1;
        vuint32_t ch7:1;
        vuint32_t ch6:1;
        vuint32_t ch5:1;
        vuint32_t ch4:1;
        vuint32_t ch3:1;
        vuint32_t ch2:1;
        vuint32_t ch1:1;
        vuint32_t ch0:1;
    } B;
} icu_ch_num_t;


/**
 * @brief PWM driver mode.
 */
typedef enum {
    ICU_INTERNAL_COUNTER = 0,
    ICU_COUNTER_BUS_A = 1,
    ICU_COUNTER_BUS_2 = 2
} icu_selct_clock_bus_t;

/**
 * @brief PWM driver mode.
 */
typedef enum {
    ICU_UC_PRESCALE_DIV1 = 0,
    ICU_UC_PRESCALE_DIV2 = 1,
    ICU_UC_PRESCALE_DIV3 = 2,
    ICU_UC_PRESCALE_DIV4 = 3
} icu_uc_prescale_t;

typedef struct {
    icuusermode_t           usermode;
    icu_selct_clock_bus_t   clock_bus;
    /**
     * @brief   uc_prescale .
     */
    icu_uc_prescale_t       uc_prescale;
    icuedgepolarity_t       edge_polarity;
    /**
     * @brief   Callback for pulse width measurement.
     */
    icucallback_t           edge_count_cb;
    /**
     * @brief   Callback for pulse width measurement.
     */
    icucallback_t           time_stamp_cb;
    /**
     * @brief   Callback for pulse width measurement.
     */
    icucallback_t           width_cb;
    /**
     * @brief   Callback for cycle period measurement.
     */
    icucallback_t           period_cb;
    /**
     * @brief   Callback for timer overflow.
     */
    icucallback_t           overflow_cb;
    /* End of the mandatory fields.*/
} ICU_Config_SAIC;

typedef struct {
    icu_selct_clock_bus_t   clock_bus;
    /**
     * @brief   uc_prescale .
     */
    icu_uc_prescale_t       uc_prescale;
    icuedgepolarity_t       edge_polarity;
    /**
     * @brief   Callback for timer overflow.
     */
    icucallback_t           ipwm_cb;
    /* End of the mandatory fields.*/
    /**
     * @brief   Callback for timer overflow.
     */
    icucallback_t           overflow_cb;
} ICU_Config_IPWM;


typedef struct {
    icu_selct_clock_bus_t   clock_bus;
    /**
     * @brief   uc_prescale .
     */
    icu_uc_prescale_t       uc_prescale;
    icuedgepolarity_t       edge_polarity;
    /**
     * @brief   Callback for timer overflow.
     */
    icucallback_t           ipw_cb;
    /* End of the mandatory fields.*/
    /**
     * @brief   Callback for timer overflow.
     */
    icucallback_t           overflow_cb;
} ICU_Config_IPM;

/**
 * @brief   Driver configuration structure.
 * @note    It could be empty on some architectures.
 */
typedef struct { /* PRQA S 3630 */
    /**
     * @brief   mode.
     */
    icumode_t           hw_mode;
    ICU_Config_SAIC     config_saic;
    ICU_Config_IPWM     config_ipwm;
    ICU_Config_IPM      config_ipm;
} ICUConfig_t;

typedef struct {
    uint32_t        edge_numbers[32];
    uint16_t        time_stamp[32];
    /**
     * @brief Last pulse edges.
     */
    ICUPulseEdges   pe;
    /**
     * @brief Last width capture value.
     */
    uint16_t        width[32];
    /**
     * @brief Last period capture value.
     */
    uint16_t        period[32];
} ICU_SAIC_MODE_Data;

typedef struct {
    uint16_t    time_stamp1[32];
    uint16_t    time_stamp2[32];
    uint16_t    pulse_width_numbers[32];
} ICU_IPWM_MODE_Data;


typedef struct {
    uint16_t    time_stamp1[32];
    uint16_t    time_stamp2[32];
    uint16_t    period_numbers[32];
} ICU_IPM_MODE_Data;

typedef struct {
    ICU_SAIC_MODE_Data  saic_data;
    ICU_IPWM_MODE_Data  ipwm_data;
    ICU_IPM_MODE_Data   ipm_data;
} ICUData_t;

/**
 * @brief   Structure representing an ICU driver.
 */
typedef struct ICUDriver{
    /**
    * @brief Pointer to the eMIOSx registers block.
    */
    volatile struct EMIOS_tag *emiosp;
    /**
    * @brief UC channel number.
    */
    icu_ch_num_t     ch_num;
    /**
    * @brief sys clock.
    */
    uint32_t        sys_clock;
    /**
    * @brief sys clock.
    */
    uint8_t         emios_prescale;
    ICUConfig_t     *config;
    ICUData_t       data;
};

#ifdef __cplusplus
extern "C" {
#endif

void ICU_LLD_Serve_Interrupt(ICUDriver *icudriver, icu_interrupt_group_t group, uint8_t channel);
void ICU_LLD_Init(ICUDriver * icudriver, volatile struct EMIOS_tag * emios_base_address, uint8_t emios_prescale);
void ICU_LLD_UC_Channel_Init(ICUDriver * icudriver, uint8_t channel, ICUConfig_t * icuconfig);
void ICU_LLD_UC_Channel_Enable(const ICUDriver * icudriver, uint8_t channel);
void ICU_LLD_UC_Channel_Disable(const ICUDriver * icudriver, uint8_t channel);
void ICU_LLD_Interrupt_Register(const ICUDriver * icudriver, uint8_t channel);

uint32_t ICU_LLD_GetFrequency(const ICUDriver * icudriver, uint8_t channel);
float32_t ICU_LLD_GetDutyCycle(ICUDriver * icudriver, uint8_t channel);
uint16_t ICU_LLD_GetTimeElapsed(ICUDriver * icudriver, uint8_t channel);
uint16_t ICU_LLD_GetPeriodTime(ICUDriver * icudriver, uint8_t channel);

#ifdef __cplusplus
}
#endif

#endif /* LLD_USE_ICU */

#endif /* ICU_LLD_H */
