/******************************************************************************
Copyright (c) ECO-EV Technologies Co., Ltd. 2015-2019. 
All rights reserved.

File name:		74HC595D.h
Author:			yang
Version:		V1.0.0
Date:			2019-03-16 11:58
Description:
Others:
History:

	1. Date:
	   Author:
	   Modification:
	2. ...
*******************************************************************************/
#ifndef BSW_ECAL_ONBOARD_SWITCH_74HC595D_H_
#define BSW_ECAL_ONBOARD_SWITCH_74HC595D_H_

#include "bsw_typedefs.h"
#include "Mcal_GPIO.h"

typedef enum{
	Latch_74HC595D_Channel_01=0,
	Latch_74HC595D_Channel_02,
	Latch_74HC595D_Channel_03,
	Latch_74HC595D_Channel_04,
	Latch_74HC595D_Channel_05,
	Latch_74HC595D_Channel_06,
	Latch_74HC595D_Channel_07,
	Latch_74HC595D_Channel_08,
	Latch_74HC595D_Channel_Num
}Latch_74HC595D_Channel_Type;

typedef enum{
	Latch_74HC595D_ChipNum_01=0,
	Latch_74HC595D_ChipNum_02,
	Latch_74HC595D_ChipNum_03,
	Latch_74HC595D_ChipNum_04,
	Latch_74HC595D_ChipNum_05,
	Latch_74HC595D_ChipNum_06,
	Latch_74HC595D_ChipNum_07,
	Latch_74HC595D_Chip_Count
}Latch_74HC595D_ChipNum_Type;

typedef struct{
	Mcal_GPIO_Pin ser_pin;		//Data in.
	Mcal_GPIO_Pin en_pin;		//Enable output, low enable.
	Mcal_GPIO_Pin rck_pin;		//SR->DR, rising edge.
	Mcal_GPIO_Pin sck_pin;		//SR update, rising edge.
	Mcal_GPIO_Pin sclr_pin;		//Clear DR, rising edge.
	boolean exist;
}Latch_74HC595D_Config_Type;

typedef struct{
	Mcal_GPIO_Pin ser_pin;		//Data in.
	Mcal_GPIO_Pin en_pin;		//Enable output, low enable.
	Mcal_GPIO_Pin rck_pin;		//SR->DR, rising edge.
	Mcal_GPIO_Pin sck_pin;		//SR update, rising edge.
	Mcal_GPIO_Pin sclr_pin;		//Clear DR, rising edge.
}Latch_74HC595D_InitPara_Type;

extern void Latch_74HC595D_Init(Latch_74HC595D_ChipNum_Type chip_num, Latch_74HC595D_InitPara_Type *init_para);
extern void Latch_74HC595D_EnableState(Latch_74HC595D_ChipNum_Type chip_num, boolean en);
extern void Latch_74HC595D_SetOutput(Latch_74HC595D_ChipNum_Type chip_num, uint8 data);

#endif /* BSW_ECAL_ONBOARD_SWITCH_74HC595D_H_ */
