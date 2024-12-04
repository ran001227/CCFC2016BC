/*****************************************************************************
Copyright (c) ECO-EV Technologies Co., Ltd. 2015-2016. All rights reserved.

File name:		Abstraction_ADC.h
Author:			ECO-EV
Version:		V1.0.1
Date:			2017-6-6
Description:
Others:
History:

	1. Date:
	   Author:
	   Modification:
	2. ...
******************************************************************************/
#ifndef ABSTRACTION_ADC_H
#define ABSTRACTION_ADC_H
/*****************************************************************************
Includes
******************************************************************************/
#include "bsw_typedefs.h"
#include "MCAL_ADC.h"



/** \brief the enumerate of the AI channel
 */
typedef enum
{
	ABS_ADC_01 = 0,
	ABS_ADC_02 = 1,
	ABS_ADC_03 = 2,
	ABS_ADC_04 = 3,
	
	ABS_ADC_BATT = 4,
	ABS_ADC_DRVPO = 5,
	ABS_ADC_5V = 6,

	
	ABS_ADC_NUM
} ABS_ADC_Channel_t;

/******************************************************************************
public symbol Definitions
******************************************************************************/
//#define ABS_ADC_0  ABS_ADC_00
#define ABS_ADC_1  ABS_ADC_01
#define ABS_ADC_2  ABS_ADC_02
#define ABS_ADC_3  ABS_ADC_03
#define ABS_ADC_4  ABS_ADC_04
//#define ABS_ADC_5  ABS_ADC_05
//#define ABS_ADC_6  ABS_ADC_06
//#define ABS_ADC_7  ABS_ADC_07
//#define ABS_ADC_8  ABS_ADC_08
//#define ABS_ADC_9  ABS_ADC_09

#define ADC_ADCLKSEL_0          0U
#define ADC_ADCLKSEL_1          1U
#define ADC_MODE_SCAN           1U
#define ADC_MODE_ONESHOT        0U
#define ADC_OWREN               1U
#define ADC_ACKO                1U
#define ADC_PWDN                0U
#define ADC_PWON                1U
#define ADC_RIGHTALIGNED        0U

#ifdef ECO_VCU_EB4274A
#define ABS_ADCHiRes_03 ABS_ADC_34  // MCP3914 23bits
#define ABS_ADCHiRes_04 ABS_ADC_35  // MCP3914 23bits
#define ABS_ADCHiRes_05	ABS_ADC_33  // MCP3914 23bits
#define ABS_ADCHiRes_07	ABS_ADC_31  // MCP3914 23bits
#define ABS_ADCHiRes_08	ABS_ADC_29  // MCP3914 23bits


#define ABS_ADCHiRes_3  ABS_ADCHiRes_03
#define ABS_ADCHiRes_4  ABS_ADCHiRes_04
#define ABS_ADCHiRes_5  ABS_ADCHiRes_05
#define ABS_ADCHiRes_6  ABS_ADCHiRes_06
#define ABS_ADCHiRes_7  ABS_ADCHiRes_07
#define ABS_ADCHiRes_8  ABS_ADCHiRes_08
#endif

//#define ABS_ADC_3V3      ABS_ADC_26
//#define ABS_ADC_5V1      ABS_ADC_25
//#define ABS_ADC_5V2      ABS_ADC_27


typedef enum
{
	Abstr_ADC_ChannelType_Inside = 0,
	Abstr_ADC_ChannelType_MCP3008,
	Abstr_ADC_ChannelType_MCP3914,
} Abstr_ADC_ChannelType;



typedef struct
{
	Abstr_ADC_ChannelType Type;
	uint8 ConvertBits;
	uint8 RefVoltageByMv;
	uint8 ChipNum;
	uint8 Channel;
	Mcal_ADC_Channel    McalChannel;
	const Mcal_ADC_Pin* ptr_Pin;
} ADC_Config_t;



/*************************************************************
Exported Function Declarations                                                                     
**************************************************************/
extern void    F_Abstr_ADC_BuildChannelByType(ABS_ADC_Channel_t channel, ADC_Config_t * cfg);
extern void    F_Abstr_ADC_BuildChannel(ABS_ADC_Channel_t channel,Mcal_ADC_Channel Adc_Channel,const Mcal_ADC_Pin* ptr_Pin);
extern void    F_Abstr_ADC_InitChannel(ABS_ADC_Channel_t channel);
extern void    ADC0_EOC_InterruptHandler(void);

extern uint16  F_Abstr_ADC_GetValue(ABS_ADC_Channel_t channel);
extern uint8   F_Abstr_ADC_GetResolution(ABS_ADC_Channel_t channel);
extern uint32  F_Abstr_ADC_GetValueHighPrecision(ABS_ADC_Channel_t channel);
extern void    FlexPWM_CTU_ADC_Init(void);
extern void ADC_PinInit();

#endif



