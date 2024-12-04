/**************************************************************************** 
* 
* Copyright (c) 2023  C*Core -   All Rights Reserved  
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* 
* PROJECT     : CCFC2016BC           
* DESCRIPTION : CCFC2016BC pwm low level drivers code 
* HISTORY     : Initial version.
* @file     pwm_lld.h
* @version  1.4
* @date     2023 - 06 - 12
* @brief    Initial version.
*
*****************************************************************************/

#ifndef PWM_LLD_H
#define PWM_LLD_H

#include "lldconf.h"
#include "CCFC2016BC.h"
#include "emios_lld.h"

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/
typedef struct PWMDriver PWMDriver;
typedef void (*pwmcallback_t)(PWMDriver *pwmdriver);
extern PWMDriver PWMD_0;

typedef struct
{
    uint32_t MAXCounterValue;
    uint32_t dutyCycle;
    uint8_t globalPrescaler;
    uint8_t channelPrescaler;
    uint8_t edgePolarity;
}PWM_DriverStruct;

/**
 * @brief PWM driver mode.
 */
typedef enum {
    PWM_OPWFMB_MODE = 0,
    PWM_MCB_MODE = 1,
    PWM_OPWMB_MODE = 2,
    PWM_OPWMCB_MODE = 3
} pwmmode_t;


typedef enum {
    START_FALLING_EDGE = 0,
    START_RISING_EDGE = 1
} pwmedgepolarity_t;

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
} pwm_ch_num_t;

/**
 * @brief PWM driver mode.
 */
typedef enum {
    PWM_INTERNAL_COUNTER = 0,
    PWM_COUNTER_BUS_A = 1,
    PWM_COUNTER_BUS_2 = 2
} pwm_selct_clock_bus_t;

/**
 * @brief PWM driver mode.
 */
typedef enum {
    PWM_UC_PRESCALE_DIV1 = 0,
    PWM_UC_PRESCALE_DIV2 = 1,
    PWM_UC_PRESCALE_DIV3 = 2,
    PWM_UC_PRESCALE_DIV4 = 3
} uc_prescale_t;

typedef struct { /* PRQA S 3630 */
    pwm_selct_clock_bus_t   clock_bus;
    uc_prescale_t           uc_prescale;
    pwmedgepolarity_t       edge_polarity;
    uint16_t                peroid_value;
    uint16_t                dutycycle_value;
    pwmcallback_t           opwfmb_cb;
} PWM_Config_OPWFMB;


typedef enum {
    MCB_COUNTER_UP_MODE = 0,
    MCB_COUNTER_UP_DOWN_MODE = 1
} pwm_mcb_counter_mode_t;


typedef struct { /* PRQA S 3630 */
    pwm_selct_clock_bus_t       clock_bus;
    uc_prescale_t               uc_prescale;
    pwm_mcb_counter_mode_t      counter_mode;
    uint16_t                    up_mode_peroid_value;
    uint16_t                    up_down_mode_peroid_value;
    pwmcallback_t               mcb_cb;
} PWM_Config_MCB;

typedef struct { /* PRQA S 3630 */
    pwm_selct_clock_bus_t       clock_bus;
    uc_prescale_t               uc_prescale;
    pwmedgepolarity_t           edge_polarity;
    uint16_t                    a;
    uint16_t                    b;
    pwmcallback_t               opwmb_cb;
} PWM_Config_OPWMB;

/**
 * @brief PWM driver mode.
 */
typedef enum {
    PWM_LEADING_EDGE = 0,
    PWM_TRAILING_EDGE = 1
} pwm_dead_insert_t;

typedef struct { /* PRQA S 3630 */
    pwm_selct_clock_bus_t   clock_bus;
    uc_prescale_t           uc_prescale;
    pwmedgepolarity_t       edge_polarity;
    pwm_dead_insert_t       dead_insertion;
    uint16_t                b;
    uint16_t                a;
    pwmcallback_t           opwmcb_cb;
} PWM_Config_OPWMCB;

/**
 * @brief   Driver configuration structure.
 * @note    It could be empty on some architectures.
 */
typedef struct { /* PRQA S 3630 */
    /**
     * @brief   mode.
     */
    pwmmode_t           hw_mode;
    PWM_Config_OPWFMB   *config_opwfmb;
    PWM_Config_MCB      *config_mcb;
    PWM_Config_OPWMB    *config_opwmb;
    PWM_Config_OPWMCB   *config_opwmcb;
} PWMConfig_t;

typedef struct PWMDriver
{
    /**
     * @brief Pointer to the eMIOSx registers block.
     */
    volatile struct EMIOS_tag   *emiosp;
    pwm_ch_num_t    ch_num;
    uint32_t        sys_clock;
    uint8_t         emios_prescale;
    PWMConfig_t     *config;
};

extern void PWM_LLD_Serve_Interrupt(const PWMDriver *pwmdriver, uint8_t channel);
extern void PWM_LLD_Init(PWMDriver * pwmdriver, volatile struct EMIOS_tag * emios_base_address, uint8_t emios_prescale);
extern void PWM_LLD_UC_Channel_Init(PWMDriver * pwmdriver, uint8_t channel, PWMConfig_t * pwmconfig);
extern void PWM_LLD_UC_Channel_Enable(const PWMDriver * pwmdriver, uint8_t channel);
extern void PWM_LLD_UC_Channel_Disable(const PWMDriver * pwmdriver, uint8_t channel);
extern void PWM_LLD_Interrupt_Register(const PWMDriver * pwmdriver, uint8_t channel);
#endif /* PWM_LLD_H */
