/******************************************************************************
Copyright (c) ECO-EV Technologies Co., Ltd. 2015-2019. 
All rights reserved.

File name:		HEF4051B.h
Author:			yang
Version:		V1.0.0
Date:			2019-03-15 14:27
Description:
Others:
History:

	1. Date:
	   Author:
	   Modification:
	2. ...
*******************************************************************************/
#ifndef BSW_ECAL_ONBOARD_SWITCH_HEF4051B_H_
#define BSW_ECAL_ONBOARD_SWITCH_HEF4051B_H_

#include "bsw_typedefs.h"
#include "Mcal_GPIO.h"

typedef enum{
	HEF4051_ChipNum_01=0,
	HEF4051_ChipNum_02,
	HEF4051_ChipNum_03,
	HEF4051_ChipNum_04,
	HEF4051_ChipNum_05,
	HEF4051_ChipNum_06,
	HEF4051_ChipNum_07,
	HEF4051_ChipNum_08,
	HEF4051_ChipNum_09,
	HEF4051_ChipNum_10,
	HEF4051_ChipNum_Num
}HEF4051B_ChipNum_Type;

typedef enum{
	HEF4051_Channel_01=0,
	HEF4051_Channel_02,
	HEF4051_Channel_03,
	HEF4051_Channel_04,
	HEF4051_Channel_05,
	HEF4051_Channel_06,
	HEF4051_Channel_07,
	HEF4051_Channel_08,
	HEF4051_Channel_Num,
	HEF4051_Channel_Floating
}HEF4051B_Channle_Type;

typedef union{
	struct{
		uint8 :5;
		uint8 s2:1;
		uint8 s1:1;
		uint8 s0:1;
	}B;
	uint8 R;
}HEF4051B_OutputSelData_Type;

typedef struct{
	HEF4051B_ChipNum_Type chip;
	Mcal_GPIO_Pin s0_pin;
	Mcal_GPIO_Pin s1_pin;
	Mcal_GPIO_Pin s2_pin;
	Mcal_GPIO_Pin en_pin;
}HEF4051B_InitPara_Type;

typedef struct{
	Mcal_GPIO_Pin s0_pin;
	Mcal_GPIO_Pin s1_pin;
	Mcal_GPIO_Pin s2_pin;
	Mcal_GPIO_Pin en_pin;
	boolean exist;
}HEF4051B_ConfigPara_Type;

extern void HEF4051B_Init(HEF4051B_InitPara_Type *init_para);
extern void HEF4051B_SetOutput(HEF4051B_ChipNum_Type chip_num, uint8 outvalue);
extern void HEF4051B_EnableState(HEF4051B_ChipNum_Type chip_num, boolean en);


#endif /* BSW_ECAL_ONBOARD_SWITCH_HEF4051B_H_ */
