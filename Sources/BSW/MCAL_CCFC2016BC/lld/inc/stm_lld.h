/**************************************************************************** 
* 
* Copyright (c) 2023  C*Core -   All Rights Reserved  
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* 
* PROJECT     : CCFC2016BC           
* DESCRIPTION : CCFC2016BC stm low level drivers code 
* HISTORY     : Initial version.
* @file     stm_lld.h
* @version  1.4
* @date     2023 - 06 - 12
* @brief    Initial version.
* 
*****************************************************************************/
#ifndef STM_LLD_H_
#define STM_LLD_H_

#include "CCFC2016BC.h"
#include "lldconf.h"
#include "sys.h"
#include "intc_lld.h"

#define STM_CHANNELS                  4

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/
#define STM0_CH0_HANDLER               vector30
#define STM0_CH1_HANDLER               vector31
#define STM0_CH2_HANDLER               vector32
#define STM0_CH3_HANDLER               vector33

#define STM0_CH0_INT_NUMBER            30
#define STM0_CH1_INT_NUMBER            31
#define STM0_CH2_INT_NUMBER            32
#define STM0_CH3_INT_NUMBER            33

/**
 * @brief   STM registers block.
 * @note    declaration of the SubModules registers among the various
 *          
 */
  struct STM_CH_tag{
    union { /* STM Channel Control 0..3 */
        vuint32_t R;
        struct {
            vuint32_t :31;
            vuint32_t CEN:1;
        } B;
    } CCR;

    union { /* STM Channel Interrupt 0..3 */
        vuint32_t R;
        struct {
            vuint32_t :31;
            vuint32_t CIF:1;
        } B;
    } CIR;

    union { /* STM Channel Compare 0..3 */
        vuint32_t R;
        struct {
            vuint32_t CMP:32;
        } B;
    } CMP;

    vuint8_t STM_CHANNEL_reserved0[4]; /* Reserved 4 bytes between ch reg's */
  }; /* end of STM_CHANNEL_tag */

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/
/**
 * @name    Configuration options
 * @{
 */
/**
 * @brief   STM0 driver enable switch.
 * @details If set to @p TRUE the support for STM0 is included.
 */
/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/**
 * @name    STM definitions
 * @{
 */
#define STM_CR_TEN_ENABLE     1U   /**< @brief STM Counter Enabled.  */
#define STM_CR_TEN_DISABLE    0U   /**< @brief STM Counter Disabled. */
#define STM_CR_FRZ_ENABLE     1U   /**< @brief STM Counter freeze when entering in debug.  */
#define STM_CIR_CEN_ENABLE    1U   /**< @brief Channel Enabled.      */
#define STM_CIR_CEN_DISABLE   0U   /**< @brief Channel Disabled.     */
#define STM_CCR_CIF_CLEAR     1U   /**< @brief Interrupt Clear Flag. */

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/**
 * @brief Type of a structure representing an STM driver.
 */
typedef struct STMDriver STMDriver;

/**
 * @brief   STM notification callback type.
 *
 * @param[in] adcp      pointer to the @p STMDriver object triggering the
 *                      callback
 */
typedef void (*stmcallback_t)(void);

/**
 * @brief   Structure representing a STM Channel configuration
 */
typedef struct { /* PRQA S 3630 */
/**
* @brief   Channel Enabled.
*/  
    uint8_t enabled;
/**
* @brief   number of tick for interrupt generation.
*/
    uint32_t counter;
/**
* @brief   callback function.
*/
    stmcallback_t callback;
}STM_CH_Config;

/**
 * @brief   Structure representing a STM driver.
 */
struct STMDriver {
  /**
  * @brief   System Clock Prescaler
  */
  uint8_t noofchannels;
  /**
   * @brief   System Clock Prescaler
  */
  uint32_t prescaler;
  /**
   * @brief   Current configuration data.
   */
  STM_CH_Config *stm_ch_config;
  /**
   * @brief Pointer to the STM registers block.
   */
  volatile struct STM_tag *stm_tagp;
  /**
   * @brief counter status flag. running (ENBALED) or not (DISABLED)
   */
  uint8_t status;
};

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

extern STMDriver STMD;

#ifdef __cplusplus
extern "C" {
#endif

extern void  STM_LLD_Init(STMDriver *stmd, STM_CH_Config *config);
extern void  STM_LLD_DeInit(STMDriver *stmd);
extern void  STM_LLD_Configure(STMDriver *stmd);
extern void  STM_LLD_ModuleEnable(const STMDriver *stmd);
extern void  STM_LLD_ModuleDisable(const STMDriver *stmd);
extern void  STM_LLD_Stop(const STMDriver *stmd);
extern void  STM_LLD_ResetCounter(const STMDriver *stmd);
extern uint32_t STM_LLD_GetCounter(const STMDriver *stmd);
extern void  STM_LLD_SetCounter(const STMDriver *stmd, uint32_t value);

extern void STM_LLD_DelayInit(void);
extern void STM_LLD_Delayms(uint32_t ms);
extern void STM_LLD_Delayus(uint32_t us);
void STM_LLD_SetPrescaler(uint32_t clockDivision);
uint32_t STM_LLD_GetPrescaler(void);
void STM_LLD_SetDebugFreeze(uint32_t newState);
uint32_t STM_LLD_GetDebugFreeze(void);
void STM_LLD_SetChannelState(uint32_t channel , uint32_t newState);
uint32_t STM_LLD_GetChannelState(uint32_t channel);
void STM_LLD_ClearInterruptFlag(uint32_t channel);
uint32_t STM_LLD_GetInterruptFlag(uint32_t channel);
void STM_LLD_SetCompareValue(uint32_t channel , uint32_t compareValue);
uint32_t STM_LLD_GetCompareValue(uint32_t channel);

#ifdef __cplusplus
}
#endif

#endif /* STM_LLD_H_ */
