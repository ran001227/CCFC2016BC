/******************************************************************************
*	Copyright (c) ECO-EV Technologies Co., Ltd. 2015-2016. 
*	All rights reserved.

*	File name:		HSO_Discrete.h
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
#ifndef _HSO_Discrete_H_
#define _HSO_Discrete_H_

#include "typedefs.h"
#include "MCAL_OPWM.h"  //MCAL_PWM
#include "MCAL_ADC.h"
#include "MCAL_GPIO.h"
//#include "HWAL_DO_TypeDefs.h"

#define			HSO_DISCRETE_CHIP				0
#define			HSO_DISCRETE_CHANNELNUM			16

/** \brief Enumerate the Channels of SPI
 */
typedef enum 
{
	HSO_Discrete_OUT01=0,
	HSO_Discrete_OUT02=1,
	HSO_Discrete_OUT03=2,
	HSO_Discrete_OUT04=3,
	HSO_Discrete_OUT05=4,
	HSO_Discrete_OUT06=5,
	HSO_Discrete_OUT07=6,
	HSO_Discrete_OUT08=7,
	HSO_Discrete_OUT09=8,
	HSO_Discrete_OUT10=9,
	HSO_Discrete_OUT11=10,
	HSO_Discrete_OUT12=11,
	HSO_Discrete_OUT13=12,
	HSO_Discrete_OUT14=13,
	HSO_Discrete_OUT15=14,
	HSO_Discrete_OUT16=15,

	
	//HSO_Discrete_Channel_H_1 = 6,
} HSO_Discrete_Channel;

typedef struct
{

	Mcal_GPIO_Pin 		GPIO_INPUT;
	boolean				PWM_Enable;
	Mcal_OPWM_Channel 	PWM_INPUT;                  //Mcal_  PWM_Channel
	Mcal_OPWM_Pin*      OPWMPinPtr_INPUT;           //Mcal_OPWM_Pin*      HSO_Discrete_OPWMPinPtr_INPUT[HSO_DISCRETE_CHANNELNUM];
	boolean				DTC_Enable;
	Mcal_ADC_Channel 	ADC_VoltageSense;
	Mcal_ADC_Pin*       ADCPinPtr_VoltageSense;     //Mcal_ADC_Pin*       HSO_Discrete_ADCPinPtr_VoltageSense[HSO_DISCRETE_CHANNELNUM];

}HSO_Discrete_Config;



/******************************************************************************
Exported Function Declarations                                                                     
******************************************************************************/
extern void  HSO_Discrete_InitHardWare(HSO_Discrete_Channel Channel,HSO_Discrete_Config HSO_Discrete_InitStruct);
extern void  HSO_Discrete_InitChannel(HSO_Discrete_Channel Channel,boolean EnableOpwm);  //Ecal_DO_Type Type
extern uint8 HSO_Discrete_SwitchOutType_SetState(HSO_Discrete_Channel Channel,boolean State);
extern uint8 HSO_Discrete_PwmOutType_SetParameter(HSO_Discrete_Channel Channel,uint32 Freq,uint32 Duty);  ////uint32 Freq,uint32 Duty  Mcal_PWM_Parameter Parameter
extern uint8 HSO_Discrete_ReadDTC(HSO_Discrete_Channel Channel);


#endif
