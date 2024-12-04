/******************************************************************************
*	Copyright (c) ECO-EV Technologies Co., Ltd. 2015-2016. 
*	All rights reserved.

*	File name:		HLSO.h
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
#ifndef _VND5160_H_
#define _VND5160_H_

#include "typedefs.h"
#include "bsw_typedefs.h"
#include "MCAL_GPIO.h"
#include "MCAL_OPWM.h" //MCAL_PWM.h
#include "MCAL_ADC.h"
//#include "HWAL_DO_TypeDefs.h"

/** \brief Enumerate the Channels of SPI			
 */
typedef enum 
{
	VND5160_ChipNum_U01=0,
	VND5160_CHIPNUM,
	
} VND5160_ChipNum;

/** \brief Enumerate the Channels of SPI
 */
typedef enum 
{
	VND5160_OUT01=0,
	VND5160_OUT02=1,

} VND5160_OutChannel;

/** \brief the Structure of the LSO_Discrete_Config
 */
typedef struct
{
	
	Mcal_GPIO_Pin 		GPIO_INPUT[2];
	Mcal_OPWM_Channel 	PWM_INPUT[2];      //Mcal_PWM_Channel
	Mcal_OPWM_Pin*      OPWMPinPtr_IN_NON[2];          ///////////////////////////////////////////
	Mcal_ADC_Channel	ADC_CURRENTSENSE[2];
	Mcal_ADC_Pin*       ADCPinPtr_CURRENTSENSE[2];     ///////////////////////////////////////////

}VND5160_ChipConfig;

/******************************************************************************
Exported Function Declarations                                                                     
******************************************************************************/
extern void  VND5160_InitChip(VND5160_ChipNum ChipNum,VND5160_ChipConfig VND5160_InitStruct);
extern void  VND5160_InitChannel(VND5160_ChipNum ChipNum,VND5160_OutChannel OutChannel,boolean EnableOpwm);      //Ecal_DO_Type OutType
extern uint8 VND5160_SwitchOutType_SetState(VND5160_ChipNum ChipNum,VND5160_OutChannel OutChannel,boolean State);     //Ecal_DO_SwitchType_State State
extern uint8 VND5160_PwmOutType_SetParameter(VND5160_ChipNum ChipNum,VND5160_OutChannel OutChannel,uint32 Freq,uint32 Duty); //Mcal_PWM_Parameter Parameter
extern uint8 VND5160_ReadDTC(VND5160_ChipNum ChipNum,VND5160_OutChannel OutChannel);


#endif
