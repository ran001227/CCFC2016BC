/**************************************************************************** 
* 
* Copyright (c) 2023  C*Core -   All Rights Reserved  
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* 
* PROJECT     : CCFC2016BC           
* DESCRIPTION : CCFC2016BC swt low level drivers code 
* HISTORY     : Initial version.
* @file     swt_lld.h
* @version  1.1
* @date     2023 - 02 - 15
* @brief    Initial version.
*
*****************************************************************************/

#ifndef SWT_LLD_H_
#define SWT_LLD_H_

#include "CCFC2016BC.h"
#include "lldconf.h"
#include "intc_lld.h"

/*
 * Service keys
 */
#define SWT_SERVICE_KEY_1   0xA602
#define SWT_SERVICE_KEY_2   0xB480

/*
 * Unlock keys
 */
#define SWT_UNLOCK_KEY_1    0xC520
#define SWT_UNLOCK_KEY_2    0xD928


/*
 * Converts a period (milliseconds) to ticks
 */
#define SWT_PERIOD_TO_TICKS(__frequency__, __period__) \
        ((__frequency__ * __period__) / 1000U)

/*
 * Pseudo random generated keys
 *
 * SKn+1 = ((17 * SKn) + 3) mod 2^16
 */
#define NEW_SERVICE_KEY(__old_key__) \
        ((((__old_key__ << 4)+(0x00000003U)+(__old_key__))) & 0xFFFFU)

#if (LLD_USE_SWT == TRUE)
/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/**
 * @name    Configuration options
 * @{
 */

/**
 * @brief   SWT0 driver enable switch.
 * @details If set to @p TRUE the support for SWT0 is included.
 */
#if !defined(SWT_USE_SWT0)
#define SWT_USE_SWT0                          FALSE
#endif

/**
 * @brief   SWT1 driver enable switch.
 * @details If set to @p TRUE the support for SWT1 is included.
 */
#if !defined(SWT_USE_SWT1)
#define SWT_USE_SWT1                          FALSE
#endif

/**
 * @brief   SWT2 driver enable switch.
 * @details If set to @p TRUE the support for SWT0 is included.
 */
#if !defined(SWT_USE_SWT2)
#define SWT_USE_SWT2                          FALSE
#endif

/**
 * @brief   SWT3 driver enable switch.
 * @details If set to @p TRUE the support for SWT0 is included.
 */
#if !defined(SWT_USE_SWT3)
#define SWT_USE_SWT3                          FALSE
#endif


#if !defined(SWT0_INTERRUPT_MODE)
#define SWT0_INTERRUPT_MODE                  FALSE
#endif

#if !defined(SWT1_INTERRUPT_MODE)
#define SWT1_INTERRUPT_MODE                  FALSE
#endif

#if !defined(SWT2_INTERRUPT_MODE)
#define SWT2_INTERRUPT_MODE                  FALSE
#endif

#if !defined(SWT3_INTERRUPT_MODE)
#define SWT3_INTERRUPT_MODE                  FALSE
#endif
/** @} */

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/
#if (SWT_USE_SWT0 == FALSE) && (SWT_USE_SWT1 == FALSE) && \
    (SWT_USE_SWT2 == FALSE) && (SWT_USE_SWT3 == FALSE)
#error "SWT driver activated but no SWT peripheral assigned"
#endif

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/**
 * @brief Type of a structure representing an SWT driver.
 */
typedef struct SWTDriver SWTDriver;

/**
 * @brief   SWT notification callback type.
 *
 */
typedef void (*swtcallback_t)(const SWTDriver *swtd);

/**
 * @brief   Structure representing a SWT configuration
 */
typedef struct {
/**
* @brief   timeout period (in ms).
*/
    uint32_t                  timeout_period;

/**
* @brief   Window period (in ms).
*/
    uint32_t                 window_period;

/**
* @brief   callback function.
*/
    swtcallback_t             callback;
} SWT_Config;

/**
 * @brief   Structure representing a SWT driver.
 */
struct SWTDriver {
/**
* @brief   Current configuration data.
*/
    SWT_Config               *swt_config;

/**
* @brief   Current running frequency.
*/
    uint32_t                  swt_freq;

/**
* @brief Pointer to the SWT registers block.
*/
    volatile struct SWT_tag *swtp;
};

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/


/*===========================================================================*/
/* IRQ Handlers                                                              */
/*===========================================================================*/
#if ((HAS_SWT0 == TRUE) && (SWT0_INTERRUPT_MODE == TRUE))
IRQ_HANDLER(SWT0_HANDLER);
#endif

#if ((HAS_SWT1 == TRUE) && (SWT1_INTERRUPT_MODE == TRUE))
IRQ_HANDLER(SWT1_HANDLER);
#endif

#if ((HAS_SWT2 == TRUE) && (SWT2_INTERRUPT_MODE == TRUE))
IRQ_HANDLER(SWT2_HANDLER);
#endif

#if ((HAS_SWT3 == TRUE) && (SWT3_INTERRUPT_MODE == TRUE))
IRQ_HANDLER(SWT3_HANDLER);
#endif

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#if (HAS_SWT0 == TRUE)
extern SWTDriver SWTD1;
#endif

#if (HAS_SWT1 == TRUE)
extern SWTDriver SWTD2;
#endif

#if (HAS_SWT2 == TRUE)
extern SWTDriver SWTD3;
#endif

#if (HAS_SWT3 == TRUE)
extern SWTDriver SWTD4;
#endif

#ifdef __cplusplus
extern "C" {
#endif
void SWT_LLD_Init(SWTDriver *swtd, SWT_Config *config);
void SWT_LLD_DeInit(SWTDriver *swtd);
void SWT_LLD_KeepAlive(const SWTDriver *swtd);
void SWT_LLD_RandomKeepAlive(const SWTDriver *swtd);
void SWT_LLD_Stop(SWTDriver *swtd);
void SWT_LLD_ModuleEnable(const SWTDriver *swtd);
void SWT_LLD_ModuleDisable(const SWTDriver *swtd);
void SWT_LLD_SetTimeOutPeriod(SWTDriver *swtd, uint32_t timeout);
void SWT_LLD_SetWindowTime(SWTDriver *swtd, uint32_t window_time);
void SWT_LLD_SetKeyedService(const SWTDriver *swtd, uint8_t keyed_service);
void SWT_LLD_SetMode(const SWTDriver *swtd, uint8_t mode);
void SWT_LLD_SetInterruptMode(const SWTDriver *swtd, uint8_t int_mode);
void SWT_LLD_SetInvalidAccess(const SWTDriver *swtd, uint8_t mode);
void SWT_LLD_FreezeMode(const SWTDriver *swtd, uint8_t state);
void SWT_LLD_StopMode(const SWTDriver *swtd, uint8_t state);
#ifdef __cplusplus
}
#endif

#endif /* LLD_USE_SWT */


#endif /* SWT_LLD_H_ */
