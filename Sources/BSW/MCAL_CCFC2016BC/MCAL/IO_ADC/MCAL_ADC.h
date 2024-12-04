/******************************************************************************
*	Copyright (c) ECO-EV Technologies Co., Ltd. 2015-2016.
*	All rights reserved.

*	File name:		ADC.h
*	Author:			ECO-EV
*	Version:		V1.0.1
*	Date:			2017-6-23
*	Description:
*	Others:
*	History:
*
*	1. Date:
*	   Author:
*	   Modification:
*	2. ...
******************************************************************************/
#ifndef _ADC_H_
#define _ADC_H_

#include "typedefs.h"
#include "bsw_typedefs.h"


//FlexPWM frequency = MOTC_CLK / PWM_MODULO
//160M / 16000 = 10K
//#define PWM_MODULO 16000

/** \brief Enumerate the Channels of ADC
 */
typedef enum
{
	Mcal_ADC_NONE = -1,


	Mcal_ADC1_AN00 = 0,
	Mcal_ADC1_AN01 = 1,
	Mcal_ADC1_AN02 = 2,
	Mcal_ADC1_AN03 = 3,
	Mcal_ADC1_AN04 = 4,
	Mcal_ADC1_AN05 = 5,
	Mcal_ADC1_AN06 = 6,
	Mcal_ADC1_AN07 = 7,
	Mcal_ADC1_AN08 = 8,
	Mcal_ADC1_AN09 = 9,
	Mcal_ADC1_AN10 = 10,
	Mcal_ADC1_AN11 = 11,
	Mcal_ADC1_AN12 = 12,


} Mcal_ADC_Channel;

/** \brief structure of adc pin
 */
typedef struct
{
   Port_Num Port;
   uint8_t  PinIndex;
}Mcal_ADC_Pin;
//
///******************************************************************************
//_PinMap_ADC
//******************************************************************************/
extern const Mcal_ADC_Pin ADC0_AN00_PB04;
extern const Mcal_ADC_Pin ADC0_AN01_PB05;
extern const Mcal_ADC_Pin ADC0_AN02_PB06;
extern const Mcal_ADC_Pin ADC0_AN03_PB07;
extern const Mcal_ADC_Pin ADC0_AN04_PD00;
extern const Mcal_ADC_Pin ADC0_AN05_PD01;
extern const Mcal_ADC_Pin ADC0_AN06_PD02;
extern const Mcal_ADC_Pin ADC0_AN07_PD03;
extern const Mcal_ADC_Pin ADC0_AN08_PD04;
extern const Mcal_ADC_Pin ADC0_AN08_PD05;
extern const Mcal_ADC_Pin ADC0_AN10_PD06;
extern const Mcal_ADC_Pin ADC0_AN11_PD07;
extern const Mcal_ADC_Pin ADC0_AN12_PD08;
extern const Mcal_ADC_Pin ADC0_AN13_PD09;
extern const Mcal_ADC_Pin ADC0_AN14_PD10;
extern const Mcal_ADC_Pin ADC0_AN15_PD11;


extern const Mcal_ADC_Pin ADC0_AN32_PB08;
extern const Mcal_ADC_Pin ADC0_AN33_PB09;
extern const Mcal_ADC_Pin ADC0_AN34_PB10;
extern const Mcal_ADC_Pin ADC0_AN35_PB11;
extern const Mcal_ADC_Pin ADC0_AN36_PD12;
extern const Mcal_ADC_Pin ADC0_AN37_PD13;
extern const Mcal_ADC_Pin ADC0_AN38_PD14;
extern const Mcal_ADC_Pin ADC0_AN39_PD15;
extern const Mcal_ADC_Pin ADC0_AN40_PF00;
extern const Mcal_ADC_Pin ADC0_AN41_PF01;
extern const Mcal_ADC_Pin ADC0_AN42_PF02;
extern const Mcal_ADC_Pin ADC0_AN43_PF03;
extern const Mcal_ADC_Pin ADC0_AN44_PF04;
extern const Mcal_ADC_Pin ADC0_AN45_PF05;
extern const Mcal_ADC_Pin ADC0_AN46_PF06;
extern const Mcal_ADC_Pin ADC0_AN47_PF07;
extern const Mcal_ADC_Pin ADC0_AN48_PI08;
extern const Mcal_ADC_Pin ADC0_AN49_PI09;
extern const Mcal_ADC_Pin ADC0_AN50_PI10;
extern const Mcal_ADC_Pin ADC0_AN51_PI11;
extern const Mcal_ADC_Pin ADC0_AN52_PI12;
extern const Mcal_ADC_Pin ADC0_AN53_PI13;
extern const Mcal_ADC_Pin ADC0_AN54_PI14;
extern const Mcal_ADC_Pin ADC0_AN55_PI15;
extern const Mcal_ADC_Pin ADC0_AN56_PJ00;
extern const Mcal_ADC_Pin ADC0_AN57_PJ01;
extern const Mcal_ADC_Pin ADC0_AN58_PJ02;
extern const Mcal_ADC_Pin ADC0_AN59_PJ03;


extern const Mcal_ADC_Pin ADC1_AN00_PB04;
extern const Mcal_ADC_Pin ADC1_AN01_PB05;
extern const Mcal_ADC_Pin ADC1_AN02_PB06;
extern const Mcal_ADC_Pin ADC1_AN03_PB07;
extern const Mcal_ADC_Pin ADC1_AN04_PD00;
extern const Mcal_ADC_Pin ADC1_AN05_PD01;
extern const Mcal_ADC_Pin ADC1_AN06_PD02;
extern const Mcal_ADC_Pin ADC1_AN07_PD03;
extern const Mcal_ADC_Pin ADC1_AN08_PD04;
extern const Mcal_ADC_Pin ADC1_AN09_PD05;
extern const Mcal_ADC_Pin ADC1_AN10_PD06;
extern const Mcal_ADC_Pin ADC1_AN11_PD07;
extern const Mcal_ADC_Pin ADC1_AN12_PD08;
extern const Mcal_ADC_Pin ADC1_AN13_PD09;
extern const Mcal_ADC_Pin ADC1_AN14_PD10;
extern const Mcal_ADC_Pin ADC1_AN15_PD11;

extern const Mcal_ADC_Pin ADC1_AN32_PA03;
extern const Mcal_ADC_Pin ADC1_AN33_PA07;
extern const Mcal_ADC_Pin ADC1_AN34_PA10;
extern const Mcal_ADC_Pin ADC1_AN35_PA11;
extern const Mcal_ADC_Pin ADC1_AN36_PB08;
extern const Mcal_ADC_Pin ADC1_AN37_PB09;
extern const Mcal_ADC_Pin ADC1_AN38_PB10;
extern const Mcal_ADC_Pin ADC1_AN39_PE12;


/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS, " AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
* PROJECT     : CCFC2016BC
* DESCRIPTION : CCFC2016BC adc low level drivers h file
* HISTORY     : Initial version
* @file     adc_lld.h
* @version  1.1
* @date     2023 - 02 - 15
* @brief    Initial version.
*
*****************************************************************************/

/************************************************************************
* @brief    ADC_0 with 10-bit resolution and ADC_1 with 12-bit resolution
*************************************************************************/
#define ADC0_10BIT          (0x3FFU)
#define ADC1_12BIT          (0xFFFU)



/*===============================================================================
*                   STRUCT PROTOTYPES
*================================================================================*/
#define ADC0_SELECT         ((uint8_t)0x00U)
#define ADC1_SELECT         ((uint8_t)0x01U)

#define ADC_CTR0_CH0_CH15   ((uint8_t)0x01U)
#define ADC_CTR1_CH32_CH59  ((uint8_t)0x02U)
#define ADC_CTR2_CH64_CH95  ((uint8_t)0x04U)









/******************************************************************************
Exported Function Declarations
******************************************************************************/
extern void Mcal_ADC_InitChannel(Mcal_ADC_Channel Channel,const Mcal_ADC_Pin* Pin_Ptr);
extern uint16 Mcal_ADC_ReadResult(Mcal_ADC_Channel Channel);
extern uint8 Mcal_ADC_GetResolution(Mcal_ADC_Channel Channel);

extern void Mcal_ADC_InitModule(void);
void FlexPWM_Init(void);
void CTU0_Init(uint8 ADC01_Count, uint8 *ADC01_Num);
void CTU1_Init(uint8 ADC23_Count, uint8 *ADC23_Num);

//extern void ADC_ConfigInit(const ADC_Driver *adcd);
//extern void ADC_LLD_Cfg_Init(ADC_Driver *adcd, const ADC_Config *config);
//extern void ADC_LLD_ChannelConfig(const ADC_Driver *adcd, uint32_t channel);
//extern void ADC_LLD_InjectedChannelConfig(const ADC_Driver *adcd, uint32_t channel);
//extern void ADC_LLD_IntcConfig(const ADC_Driver *adcd, uint32_t mode);
//extern void ADC_LLD_IntcEnable(const ADC_Driver *adcd, uint32_t channel);
//extern uint16_t ADC_LLD_ChanValue(const ADC_Driver *adcd, uint32_t channel);
//extern void ADC_LLD_ConversionTiming(const ADC_Driver *adcd, uint8_t ctrNum, uint32_t inpcmp, uint32_t inpsamp);
//extern void ADC_LLD_SetClockDivide(const ADC_Driver *adcd, uint8_t clkDiv);
//extern void ADC_LLD_Start(const ADC_Driver *adcd);
//extern void ADC_Stop(const ADC_Driver *adcd);
//extern uint8_t ADC_ECH_IntFlag(const ADC_Driver *adcd);
//extern uint8_t ADC_JECH_IntFlag(const ADC_Driver *adcd);
//extern void ADC_LLD_TriggerMode(const ADC_Driver *adcd, uint8_t mode);
//extern void ADC_LLD_WDGInit(const ADC_Driver *adcd);
//extern void ADC_LLD_CTUTriggerEnable(const ADC_Driver *adcd , uint8_t edge);
//extern void ADC_LLD_InjectedStart(const ADC_Driver *adcd);
//extern void ADC_LLD_DMAChannelConfig(const ADC_Driver *adcd, uint32_t channel);
//extern void ADC_LLD_DMA_Enable(const ADC_Driver *adcd);
//extern void ADC_LLD_CTU_Enable(const ADC_Driver *adcd);
//extern uint16_t ADC_0_Receive(uint8_t Channel);

#endif

