/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS, " AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
* PROJECT     : CCFC2016BC
* DESCRIPTION : CCFC2016BC rtc low level drivers code
* HISTORY     : Initial version.
* @file     rtc_lld.h
* @version  1.1
* @date     2023 - 02 - 15
* @brief    Initial version.
*
*****************************************************************************/

#ifndef RTC_LLD_H_
#define RTC_LLD_H_

#include "CCFC2016BC.h"
#include "lldconf.h"
#include "intc_lld.h"

#define ENABLE_API_RTC                  TURE

/**
 * @brief   RTC interrupt status flag.
 */
#define RTC_INT_FLAG_MASK               (0x20000000UL)
#define API_INT_FLAG_MASK               (0x00002000UL)
#define CONT_ROLL_OVER_INT_FLAG_MASK    (0x00000400UL)

#if (LLD_USE_RTC == TRUE)

/* ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==   = */
/* Driver constants.                                                         */
/* ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==   = */

/* ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==   = */
/* Driver pre - compile time settings.                                         */
/* ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==   = */

/**
 * @name    Configuration options
 * @{
 */

/**
 * @brief   SWT0 driver enable switch.
 * @details If set to @p TRUE the support for SWT0 is included.
 */
#if!defined(SWT_USE_SWT0)
#define SWT_USE_SWT0                          FALSE
#endif

/**
 * @brief   SWT0 IRQ priority.
 */
#if!defined(SWT0_IRQ_PRIORITY)
#define SWT0_IRQ_PRIORITY                    INTC_PSR_ENABLE(INTC_PSR_MAINCORE, 15)
#endif

#if!defined(SWT0_INTERRUPT_MODE)
#define SWT0_INTERRUPT_MODE                  FALSE
#endif

/* ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==   = */
/* Derived constants and error checks.                                       */
/* ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==   = */
#if (SWT_USE_SWT0 == FALSE) && (SWT_USE_SWT1 == FALSE) && \
    (SWT_USE_SWT2 == FALSE) && (SWT_USE_SWT3 == FALSE)
#error "SWT driver activated but no SWT peripheral assigned"
#endif

/* ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==   = */
/* Driver data structures and types.                                         */
/* ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==   = */

/**
 * @brief Type of a structure representing an SWT driver.
 */
typedef struct RTCAPIDriver RTCAPIDriver;

/**
 * @brief   RTC notification callback type.
 *
 */
typedef void (*rtccallback_t)(RTCAPIDriver *RtcApip);

/**
 * @brief   API notification callback type.
 *
 */
typedef void (*apicallback_t)(RTCAPIDriver *RtcApip);

/**
 * @brief   Structure representing a SWT configuration
 */
typedef struct { /* PRQA S 3630 */
    /**
    * @brief   Channel Enabled.
    */
    uint8_t clocksource;

    /**
    * @brief   Channel Enabled.
    */
    uint8_t rtcenabled;

    /**
    * @brief   timeout period (in ms) for RTC.
    */
    uint32_t rtc_timeout;

    /**
    * @brief   rtc callback function.
    */
    rtccallback_t rtccallback;

    /**
    * @brief   Channel Enabled.
    */
    uint8_t apienabled;

    /**
    * @brief   timeout period (in ms) for API.
    */
    uint32_t api_timeout;
    /**
    * @brief   rtc callback function.
    */
    apicallback_t apicallback;
} RTCAPI_Config;

/**
 * @brief   Structure representing a SWT driver.
 */
struct RTCAPIDriver {
  /**
    * @brief   Current configuration data.
    */
    RTCAPI_Config*          rtcapi_config;

  /**
    * @brief Pointer to the SWT registers block.
    */
    volatile struct RTC_tag *rtcapi;
};

/* ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==   = */
/* IRQ Handlers                                                              */
/* ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==   = */

#if ((HAS_RTC == TRUE) && (RTC_INTERRUPT_MODE == TRUE))
IRQ_HANDLER(RTC_HANDLER);
#endif

#if ((HAS_SWT1 == TRUE) && (API_INTERRUPT_MODE == TRUE))
IRQ_HANDLER(API_HANDLER);
#endif

/* ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==   = */
/* External declarations.                                                    */
/* ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==   = */
#ifdef HAS_RTC0
#if (HAS_RTC0 == TRUE)
extern SWTDriver SWTD1;
#endif
#endif

#if (HAS_RTC1 == TRUE)
extern SWTDriver SWTD2;
#endif

extern RTCAPIDriver RTCAPID1;

#ifdef __cplusplus
extern "C" {
#endif
uint8_t RTCAPI_LLD_Set_Period_Msec(const RTCAPIDriver *RtcApip, uint32_t msec, uint32_t *period);
void RTCAPI_LLD_Init(RTCAPIDriver *RtcApip, RTCAPI_Config *config);
void RTC_LLD_Change_Period(const RTCAPIDriver *RtcApip, uint32_t period);
void API_LLD_Change_Period(const RTCAPIDriver *RtcApip, uint32_t period);
void RTC_LLD_Start(const RTCAPIDriver *RtcApip);
void RTC_LLD_Stop(const RTCAPIDriver *RtcApip);
void RTCAPI_LLD_DeInit(RTCAPIDriver *RtcApip);

#ifdef __cplusplus
}

#endif

#endif /* RTC_LLD_H_ */

#endif
