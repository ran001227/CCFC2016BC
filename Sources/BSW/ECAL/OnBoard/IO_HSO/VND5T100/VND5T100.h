/******************************************************************************
*	Copyright (c) ECO-EV Technologies Co., Ltd. 2015-2016.
*	All rights reserved.

*	File name:		HLSO.h
*	Author:			ECO-EV
*	Version:		V1.0.1
*	Date:			2019-6-2
*	Description:


*	Others:
*	History:
*
*	1. Date:
*	   Author:
*	   Modification:
*	2. ...
******************************************************************************/
#ifndef _VND5T100_H_
#define _VND5T100_H_

#include "typedefs.h"
#include "bsw_typedefs.h"
#include "MCAL_GPIO.h"
#include "MCAL_OPWM.h"
#include "MCAL_ADC.h"


/******************************************************************************
Public Constant Definitions
*******************************************************************************/
#define		VND5T100_CHIPNUM_MAX			(2)
#define 	VND5T100_CHIPCHANNEL_MAX		(2)

/** \brief Enumerate the Channels of SPI
 */
typedef enum
{
	VND5T100_ChipNum_U01=0,
	VND5T100_ChipNum_U02,
	VND5T100_CHIPNUM,

} VND5T100_ChipNum;

/** \brief Enumerate the Channels of SPI
 */
typedef enum
{
	VND5T100_OUT01=0,
	VND5T100_OUT02=1,
	VND5T100_OUTNUM

} VND5T100_OutChannel;

/** \brief the Structure of the LSO_Discrete_Config
 */
typedef struct
{
	Mcal_GPIO_Pin 		GPIO_INPUT[2];
	Mcal_OPWM_Channel 	PWM_INPUT[2];
	const Mcal_OPWM_Pin*      PWMPinPtr_INPUT[2];
	Mcal_ADC_Channel	ADC_CURRENTSENSE[2];
	const Mcal_ADC_Pin*       ADCPinPtr_CURRENTSENSE[2];
	Mcal_GPIO_Pin		GPIO_FR_Stby;
}VND5T100_ChipPin;

typedef struct
{
	uint16 QuiescentThreshold[2];
	uint16 OverLoadThreshold[2];
}VND5T100_Configure;

/******************************************************************************
Exported Function Declarations
******************************************************************************/
extern void  VND5T100_InitChip(VND5T100_ChipNum ChipNum,VND5T100_ChipPin *VND5T100_InitStruct);
extern void  VND5T100_ConfigChip(VND5T100_ChipNum ChipNum,VND5T100_Configure *Configure);
extern void  VND5T100_InitChannel(VND5T100_ChipNum ChipNum,VND5T100_OutChannel OutChannel,boolean EnableOpwm);      //Ecal_DO_Type OutType
extern uint8 VND5T100_SwitchOutType_SetState(VND5T100_ChipNum ChipNum,VND5T100_OutChannel OutChannel,boolean State);     //Ecal_DO_SwitchType_State State
extern uint8 VND5T100_PwmOutType_SetParameter(VND5T100_ChipNum ChipNum,VND5T100_OutChannel OutChannel,uint32 Freq,uint32 Duty); //Mcal_PWM_Parameter Parameter
extern uint8 VND5T100_ReadDTC(VND5T100_ChipNum ChipNum,VND5T100_OutChannel OutChannel);


#endif


