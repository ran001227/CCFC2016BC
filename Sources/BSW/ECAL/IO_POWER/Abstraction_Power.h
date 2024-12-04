/*************************************************************
Copyright (c) ECO-EV Technologies Co., Ltd. 2015-2016. All rights reserved.

File name:		Abstraction_POWER.h
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
**************************************************************/

#ifndef ABSTRACTION_POWER_H
#define ABSTRACTION_POWER_H

/*************************************************************
Includes
**************************************************************/
#include "bsw_typedefs.h"


/** \brief  enumerate of the POWER channel
 */
typedef enum
{
   ABS_Power_PWR12V = 0,         //12V 总电源
   ABS_Power_PWR12V_DRVP,      //功率器件电源
   ABS_Power_PWR12V_DRVP_2,		//HSO diag Power
   ABS_Power_PWR5V1,
   ABS_Power_PWR5V2,
   ABS_Power_PWR5V3,
   ABS_Power_PWR5V4,
   ABS_Power_PWR5V5,
   ABS_Power_PWR5V6
} ABS_Power_Channel_t;


/** \brief enumerate the type of POWER
 */
typedef enum
{
   Abstr_Power_ControlType_Control,
   Abstr_Power_ControlType_TJA1145,
   Abstr_Power_ControlType_FS6500,
   Abstr_Power_ControlType_SS8050,
   Abstr_Power_ControlType_TLE4250,
   Abstr_Power_ControlType_MC33907,
} Abstr_Power_ControlType;


/** \brief the Structure of the Single  Control
 */
typedef struct
{
   Abstr_Power_ControlType ControlType;
   uint8 ChipNum;
   uint8 ChannelNum;
}ABS_Power_SingleControl;

/** \brief the Structure of the power control
 */
typedef struct
{
	ABS_Power_SingleControl* FirstSigleControl_Ptr;
   uint8 ControlNum;
}ABS_Power_Control;


/*************************************************************
Exported Function Declarations                                                                     
**************************************************************/
extern void F_Abstr_Power_BuildChannel(ABS_Power_Channel_t Power_Channel,ABS_Power_Control* Control_Ptr);

extern uint8 F_Abstr_Power_Turn(ABS_Power_Channel_t Power_Channel,boolean State);

extern uint8 F_Abstr_Power_ReadDTC(ABS_Power_Channel_t Power_Channel);

#endif


