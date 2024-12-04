/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS, " AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
* PROJECT     : CCFC2016BC
* DESCRIPTION : CCFC2016BC MCU configuration code.
* HISTORY     : Initial version.
* @file     Mcu_Config.h
* @version  1.1
* @date     2023 - 02 - 15
* @brief    Initial version.
*
*****************************************************************************/
#ifndef MCU_CONFIG_H_
#define MCU_CONFIG_H_
#include "typedefs.h"
#include "lldconf.h"

/**
* @brief   PLL Functional mode selection(PLL_FuncMode_t).
*/
#define PLL_NORMAL_MODE     ((uint8_t)0x00U)
#define PLL_CLK_SW_MODE     ((uint8_t)0x01U)
#define PLL_NORMAL_MODE_FM  ((uint8_t)0x02U)
#define PLL_POWERDOWN_MODE  ((uint8_t)0x04U)

/**
* @brief   PLL InitStep(PLL_Step_t).
*/
#define PLL_InitStep_0      ((uint8_t)0x00U)
#define PLL_InitStep_1      ((uint8_t)0x01U)

/**
* @brief    External crystal oscillator value(ExtOSC_t).
*/
#define ExtOSC_NULL         ((uint8_t)0x00U)
#define ExtOSC_8M           ((uint8_t)0x01U)
#define ExtOSC_16M          ((uint8_t)0x02U)
#define ExtOSC_40M          ((uint8_t)0x03U)

/**
* @brief    PLL clock value(PLLClkVal_t).
*/
#define PLL_NULL            ((uint8_t)0x00U)
#define PLL_32M             ((uint8_t)0x01U)
#define PLL_64M             ((uint8_t)0x02U)
#define PLL_80M             ((uint8_t)0x03U)
#define PLL_120M            ((uint8_t)0x04U)
#define PLL_160M            ((uint8_t)0x05U)
#define PLL_300M            ((uint8_t)0x06U)
#define PLL_VAL_MASK        ((uint8_t)0x0FU)

/**
* @brief    MCU mode driver configuration structure.
*/
typedef struct/* PRQA S 3630 */
{
    /**
    * @brief   Mode Enable.
    */
    uint32_t Mcu_ModeEnable_Cfg;

    /**
    * @brief   Interrupt Mask.
    */
    uint32_t InterruptMask_Cfg;

    /**
    * @brief   Mode configuration.
    */
    uint32_t TEST_Mode_Cfg;
    uint32_t DRUN_Mode_Cfg;
    uint32_t RUN0_Mode_Cfg;
    uint32_t RUN1_Mode_Cfg;
    uint32_t RUN2_Mode_Cfg;
    uint32_t RUN3_Mode_Cfg;
    uint32_t HALT_Mode_Cfg;
    uint32_t STOP_Mode_Cfg;
    uint32_t STANDBY_Mode_Cfg;

    /**
    * @brief   Run Peripheral configuration(ME_RUN_PC0 - 7).
    */
    uint32_t RUN_PeriphCfg0_Cfg;
    uint32_t RUN_PeriphCfg1_Cfg;
    uint32_t RUN_PeriphCfg2_Cfg;
    uint32_t RUN_PeriphCfg3_Cfg;
    uint32_t RUN_PeriphCfg4_Cfg;
    uint32_t RUN_PeriphCfg5_Cfg;
    uint32_t RUN_PeriphCfg6_Cfg;
    uint32_t RUN_PeriphCfg7_Cfg;

    /**
    * @brief   Low - Power Peripheral configuration(ME_LP_PC0 - 7).
    */
    uint32_t LowPower_PeriphCfg0_Cfg;
    uint32_t LowPower_PeriphCfg1_Cfg;
    uint32_t LowPower_PeriphCfg2_Cfg;
    uint32_t LowPower_PeriphCfg3_Cfg;
    uint32_t LowPower_PeriphCfg4_Cfg;
    uint32_t LowPower_PeriphCfg5_Cfg;
    uint32_t LowPower_PeriphCfg6_Cfg;
    uint32_t LowPower_PeriphCfg7_Cfg;
} Mcu_ModeConfig_t;

/**
* @brief    MCU clock driver configuration structure.
*/
typedef struct/* PRQA S 3630 */
{
    /**
    * @brief    Target mode selection.
    **/
    uint32_t TargetMode_Cfg;

    /**
    * @brief    FXOSC Control Register configuration.
    **/
    uint32_t FXOSC_Cfg;     /* 4 - 20MHz */

    /**
    * @brief    SXOSC Control Register configuration.
    **/
    uint32_t SXOSC_Cfg;     /* 32KHz   */

    /**
    * @brief    FIRC Control Register configuration.
    **/
    uint32_t FIRC_Cfg;      /* 16MHz   */

    /**
    * @brief    SIRC Control Register configuration.
    **/
    uint32_t SIRC_Cfg;      /* 128KHz  */

    /**
    * @brief    PLL functional mode selection.
    * @details  PLL functional mode: Normal, PLL_CLK_SW, FM mode.
    **/
    uint8_t PLLFuncMode_Cfg;

    /**
    * @brief    PLL clock value.
    **/
    uint8_t PLLClkVal_Cfg;

    /**
    * @brief    FM EN mode.
    * @details  The FM_EN switch is turned on only
    *               when PLLFuncMode_Cfg is in FM mode.
    **/
    uint32_t FMPLL_Cfg;

    /**
    * @brief    System Clock Divider Configuration.
    **/
    uint8_t PeriphDiv0_Cfg;
    uint8_t PeriphDiv1_Cfg;
    uint8_t PeriphDiv2_Cfg;
    uint8_t PeriphDiv3_Cfg;

    /**
    * @brief    Clock monitor unit:
    *           Control Status Register (CMU_CSR) Configuration.
    * @details  Configuration: SFM, CKSEL1, RCDIV, CME_A
    **/
    uint32_t CMU_Cfg;
    uint32_t CMU_HL_FreqRef_Cfg;
    uint32_t CMU_Measure_Cfg;

    /**
    * @brief    Output Clock(EN + DIV + Source).
    **/
    uint32_t ClkOut_Cfg;
} Mcu_ClockConfig_t;

/**
* @brief    MCU driver configuration structure.
**/
typedef struct
{
    Mcu_ModeConfig_t *Mcu_ModeConfig;
    Mcu_ClockConfig_t *Mcu_ClockConfig;
} Mcu_Config_t;

/*=============================================================================
*                   STRUCTURE PROTOTYPES
*==============================================================================*/
extern Mcu_Config_t McuConfig_PC;

/*=============================================================================
*                   USER-DEFINED
*==============================================================================*/
/* Mcu Measure ExtOsc Switch */
#define MCU_MEASURE_EXOSC_SWITCH        (STD_ON)
#if (MCU_MEASURE_EXOSC_SWITCH == STD_OFF)
#define MCU_EXTOSC_INIT_VAL             (ExtOSC_16M)
#endif

#endif /* MCU_CONFIG_H_ */

