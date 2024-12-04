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
#ifndef _L9826_H_
#define _L9826_H_

#include "typedefs.h"
#include "bsw_typedefs.h"   //_BSW_TYPEDEFS_H_
#include "MCAL_GPIO.h"
#include "MCAL_SPI.h"
#include "MCAL_OPWM.h"  //MCAL_PWM.h
//#include "HWAL_DO_TypeDefs.h"

#define		L9826_CHIPNUM		2	

/** \brief Enumerate the Channels of SPI			//移植该模块需要修改
 */

typedef enum 
{
	L9826_ChipNum_U01=0,
	L9826_ChipNum_U02=1
} L9826_ChipNum;

/** \brief Enumerate the Channels of SPI
 */
typedef enum 
{
	L9826_OUT01=0,
	L9826_OUT02=1,
	L9826_OUT03=2,
	L9826_OUT04=3,
	L9826_OUT05=4,
	L9826_OUT06=5,
	L9826_OUT07=6,
	L9826_OUT08=7
} L9826_OutChannel;


/** \brief the Structure of the LSO_Discrete_Config
 */
typedef struct
{
	
	Mcal_GPIO_Pin 		GPIO_NON[2];
	Mcal_OPWM_Channel 	PWM_NON[2];   //Mcal_PWM_Channel
	Mcal_OPWM_Pin*      OPWMPinPtr_IN_NON[2];    ///////////////////////////////////////
	Mcal_GPIO_Pin	 	GPIO_nRES;
	Mcal_Spi_Channel 	SPI_Channel;
	Mcal_Spi_CS		 	SPI_CS;
	Mcal_Spi_MasterPin  SPI_MasterPin;

}L9826_ChipConfig;

/** \brief Enumerate the Type of DO
 */




/******************************************************************************
Exported Function Declarations                                                                     
******************************************************************************/
extern void  L9826_InitChip(L9826_ChipNum ChipNum,L9826_ChipConfig	L9826_InitStruct);
extern uint8 L9826_InitChannel(L9826_ChipNum ChipNum,L9826_OutChannel OutChannel,boolean EnableOpwm);
extern uint8 L9826_SwitchOutType_SetState(L9826_ChipNum ChipNum,L9826_OutChannel OutChannel,boolean State);  //Ecal_DO_SwitchType_State State
extern uint8 L9826_PwmOutType_SetParameter(L9826_ChipNum ChipNum,L9826_OutChannel OutChannel,uint32 Freq,uint32 Duty);
extern uint8 L9826_ReadDTC(L9826_ChipNum ChipNum,L9826_OutChannel OutChannel);


#endif
