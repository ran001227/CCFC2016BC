/**************************************************************************** 
* 
* Copyright (c) 2023  C*Core -   All Rights Reserved  
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* 
* PROJECT     : CCFC2016BC           
* DESCRIPTION : CCFC2016BC pit low level drivers code 
* HISTORY     : Initial version.
* @file     pit_lld.h
* @version  1.1
* @date     2023 - 02 - 15
* @brief    Initial version.
*
*****************************************************************************/

#ifndef PIT_LLD_H_
#define PIT_LLD_H_

#include "CCFC2016BC.h"
#include "lldconf.h"
#include "console.h"
/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/
#define PIT_CHANNELS                   8

/**
 * @name    PIT channel identifiers
 * @{
 */

#define PIT_CH0_INT_NUMBER              59
#define PIT_CH1_INT_NUMBER              60
#define PIT_CH2_INT_NUMBER              61
#define PIT_CH3_INT_NUMBER              127
#define PIT_CH4_INT_NUMBER              128
#define PIT_CH5_INT_NUMBER              129
#define PIT_CH6_INT_NUMBER              130
#define PIT_CH7_INT_NUMBER              131

#define PIT_CH0_HANDLER                 vector59
#define PIT_CH1_HANDLER                 vector60
#define PIT_CH2_HANDLER                 vector61
#define PIT_CH3_HANDLER                 vector127
#define PIT_CH4_HANDLER                 vector128
#define PIT_CH5_HANDLER                 vector129
#define PIT_CH6_HANDLER                 vector130
#define PIT_CH7_HANDLER                 vector131


/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/**
 * @brief Type of a structure representing an PIT driver.
 */
typedef struct PITDriver PITDriver;

/**
 * @brief   PIT notification callback type.
 *
 * @param[in] adcp      pointer to the @p PITDriver object triggering the
 *                      callback
 */
typedef void (*pitcallback_t)(void);

/**
 * @brief   Structure representing a PIT Channel configuration
 */
typedef struct { /* PRQA S 3630 */
/**
* @brief   Channel Enabled.
*/  
    uint8_t enabled;
/**
* @brief   timer frequency.
*/
    uint32_t loadValue;
/**
* @brief   callback function.
*/
    pitcallback_t callback;
}PIT_CH_Config;

/**
 * @brief   Structure representing a PIT driver.
 */
struct PITDriver {
  /**
   * @brief   Current configuration data.
   */
  PIT_CH_Config *pit_ch_config;
  /**
   * @brief Pointer to the PIT registers block.
   */
  volatile struct PIT_tag *pit_tagp;
};


/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/
extern PITDriver PITD;

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#ifdef __cplusplus
extern "C" {
#endif

extern void PIT_LLD_Init(PITDriver *pitd, PIT_CH_Config *config);
extern void PIT_LLD_DeInit(PITDriver *pitd);
extern void PIT_LLD_ConfiguredChannelStart(const PITDriver *pitd, uint32_t value);
extern void PIT_LLD_ChannelConf(const PITDriver *pitd, uint32_t channel, uint32_t value);
extern void PIT_LLD_ChannelStart(uint32_t channel);
extern void PIT_LLD_ChannelStop(uint32_t channel);
extern void PIT_LLD_ModuleDisable(void);
extern void PIT_LLD_ModuleEnable(void);
extern void PIT_LLD_FreezeMode(uint32_t state);

extern void PIT_LLD_SetChannelInterruptState(uint32_t channel, uint32_t newState);
extern uint32_t PIT_LLD_GetChannelInterruptState(uint32_t channel);
extern uint32_t PIT_LLD_GetChannelState(uint32_t channel);

extern void PIT_LLD_SetLoadValue(uint32_t channel, uint32_t loadValue);
extern uint32_t PIT_LLD_GetLoadValue(uint32_t channel);
extern uint32_t PIT_LLD_GetCurrentValue(uint32_t channel);
extern void PIT_LLD_ClearInterruptFlag(uint32_t channel);

#ifdef __cplusplus
}
#endif


#endif /* PIT_LLD_H_ */
