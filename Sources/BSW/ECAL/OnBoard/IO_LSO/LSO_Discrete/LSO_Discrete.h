/******************************************************************************
*	Copyright (c) ECO-EV Technologies Co., Ltd. 2015-2016. 
*	All rights reserved.

*	File name:		LSO_Discrete.h
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
#ifndef _LSO_Discrete_H_
#define _LSO_Discrete_H_

#include "typedefs.h"
#include "MCAL_OPWM.h"     //MCAL_PWM
#include "MCAL_ADC.h"
#include "bsw_typedefs.h"


//#include "HWAL_DO_TypeDefs.h"

#define			LSO_DISCRETE_CHIP				0
#define			LSO_DISCRETE_CHANNELNUM			2

/** \brief Enumerate the Channels of SPI
 */
typedef enum 
{
	LSO_Discrete_OUT01=0,
	LSO_Discrete_OUT02=1,
	LSO_Discrete_OUT03=2,
	LSO_Discrete_OUT04=3,
	LSO_Discrete_OUT05,
	LSO_Discrete_OUT06,
	LSO_Discrete_OUT07,
	LSO_Discrete_OUT08,
	LSO_Discrete_OUT09,
	LSO_Discrete_OUT10,
	LSO_Discrete_OUT11,
	LSO_Discrete_OUT12,
	LSO_Discrete_OUT13,
	LSO_Discrete_OUT14,
	LSO_Discrete_OUT15,
	LSO_Discrete_OUT16,
	LSO_Discrete_OUTNUM
} LSO_Discrete_Channel;

typedef struct
{

	Mcal_GPIO_Pin 		GPIO_INPUT;
	boolean				PWM_Enable;
	Mcal_OPWM_Channel 	PWM_INPUT;    //Mcal_  PWM_Channel
	Mcal_OPWM_Pin*      OPWMPinPtr_INPUT;
	boolean				DTC_Enable;
	Mcal_ADC_Channel 	ADC_VoltageSense;
	Mcal_ADC_Pin*       ADCPinPtr_VoltageSense;

}LSO_Discrete_Config;


/******************************************************************************
Exported Function Declarations                                                                     
******************************************************************************/
extern void  LSO_Discrete_InitHardWare(LSO_Discrete_Channel Channel,LSO_Discrete_Config LSO_Discrete_InitStruct);
extern void  LSO_Discrete_InitChannel(LSO_Discrete_Channel Channel,boolean EnableOpwm); //Ecal_DO_Type Type
extern uint8 LSO_Discrete_SwitchOutType_SetState(LSO_Discrete_Channel Channel,boolean State); //Ecal_DO_SwitchType_State State
extern uint8 LSO_Discrete_PwmOutType_SetParameter(LSO_Discrete_Channel Channel,uint32 Freq,uint32 Duty);
extern uint8 LSO_Discrete_ReadDTC(LSO_Discrete_Channel Channel);


#endif
