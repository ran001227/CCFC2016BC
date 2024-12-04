/******************************************************************************
Copyright (c) ECO-EV Technologies Co., Ltd. 2015-2019. 
All rights reserved.

File name:		MCP4822.h
Author:			yang
Version:		V1.0.0
Date:			2019-03-16 08:10
Description:
Others:
History:

	1. Date:
	   Author:
	   Modification:
	2. ...
*******************************************************************************/
#ifndef BSW_ECAL_ONBOARD_CONVERTER_MCP4822_H_
#define BSW_ECAL_ONBOARD_CONVERTER_MCP4822_H_

#include "bsw_typedefs.h"
#include "Mcal_SPI.h"
#include "Mcal_GPIO.h"

typedef enum{
	MCP4822_ChipNum_1 = 0,
	MCP4822_ChipNum_Count
}MCP4822_ChipNum_Type;

typedef struct{
	Mcal_Spi_Channel spix;
	Mcal_Spi_CS spi_cs;
	Mcal_GPIO_Pin ldac;
	boolean exist;
}MCP4822_Config_Type;

typedef struct{
	Mcal_Spi_Channel spix;
	Mcal_Spi_MasterPin pin_cfg;
	Mcal_Spi_CS spi_cs;
	Mcal_GPIO_Pin ldac;
}MCP4822_InitPara_Type;

typedef enum{
	MCP4822_OutCH_A=0,
	MCP4822_OutCH_B,
	MCP4822_OutCH_Num
}MCP4822_OutCH_Typel;

typedef union{
	struct{
		uint16 AB:1;
		uint16 :1;
		uint16 GA:1;
		uint16 SHDN:1;
		uint16 DO:12;
	}B;
	uint16 R;
}MCP4822_Data_Type;

extern void MCP4822_Init(MCP4822_ChipNum_Type chip_num, MCP4822_InitPara_Type *init_para);
extern void MCP4822_SetOutputVol(MCP4822_ChipNum_Type chip_num, MCP4822_OutCH_Typel out_ch, uint16 out_val);
extern void MCP4822_SetOutputEN(MCP4822_ChipNum_Type chip_num, MCP4822_OutCH_Typel out_ch, boolean en_st);

#endif /* BSW_ECAL_ONBOARD_CONVERTER_MCP4822_H_ */
