/***************************************************************************************
Copyright (c) ECO-EV Technologies Co., Ltd. 2017-2018. All rights reserved.

File name:		SS8050.h
Author:			ECO-EV
Version:		V1.0.1
Date:			2017-09-21
Description:
Others:
History:

	1. Date:
	   Author:
	   Modification:
	2. ...
****************************************************************************************/

/******************************************************************************
Includes
******************************************************************************/
#ifndef _SS8050_H_
#define _SS8050_H_

#include "MCAL_GPIO.h"


/** \brief the enumerate of the TJA1043T_Mode
 */
typedef enum  
{
   SS8050_ChipNum_1=0,
   SS8050_ChipNum_2=1,
}SS8050_ChipNum;

/** \brief the enumerate of the TJA1043T_Mode
 */
typedef enum
{
	SS8050_ControlMode_GPIO,
	SS8050_ControlMode_FS6500
}SS8050_ControlMode;

/** \brief the structure of the TJA1145 chip pin
 */
typedef struct
{
   SS8050_ControlMode  ControlMode;
   Mcal_GPIO_Pin GPIO_EN;
}SS8050_ChipPin;

#define        SS8050_CHIPNUM_MAX         (1)

/******************************************************************************
Exported Function Declarations
******************************************************************************/
void SS8050_InitChip(SS8050_ChipNum ChipNum,SS8050_ChipPin* ChipPin_Ptr);
void SS8050_SetSwitch(SS8050_ChipNum ChipNum,boolean SwitchStatus);

#endif
