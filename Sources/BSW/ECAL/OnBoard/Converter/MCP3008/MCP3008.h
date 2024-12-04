/******************************************************************************
*	Copyright (c) ECO-EV Technologies Co., Ltd. 2015-2016.
*	All rights reserved.

*	File name:		MPC3008.h
*	Author:			ECO-EV
*	Version:		V1.0.0
*	Date:			2020-12-20
*	Description:
*	Others:
*	History:
*
*	1. Date:  2020-12-20
*	   Author: liyuhang
*	   Modification: None
*	   Add: First initialization file
*	   Delete: None
*	2. ...
******************************************************************************/
#ifndef _MCP3008_H_
#define _MCP3008_H_


/*************************************************************
Includes
**************************************************************/
#include "MCAL_SPI.h"
#include "Mcal_GPIO.h"
#include "bsw_typedefs.h"

#define SPI_BAUDRATE_K		(1000)
#define SPI_BAUDRATE_M		(1000*1000)

#define MCP3008_MODE_READ		(1)
#define MCP3008_MODE_WRITE		(0)

#define MCP3008_READ_REG(reg)	((reg) << 1 | MCP3008_MODE_READ)
#define MCP3008_WRITE_REG(reg)	((reg) << 1 | MCP3008_MODE_WRITE)


#define SIGNAL		(0x08)
#define DIFF		(0x00)

#define SIGNAL_CHANNEL(n)		((n) | SIGNAL)
#define DIFF_CHANNEL(n)			((n) | DIFF)

#define MCP3008_SIGNAL_CHANNEL_0		(0)
#define MCP3008_SIGNAL_CHANNEL_1		(1)
#define MCP3008_SIGNAL_CHANNEL_2		(2)
#define MCP3008_SIGNAL_CHANNEL_3		(3)
#define MCP3008_SIGNAL_CHANNEL_4		(4)
#define MCP3008_SIGNAL_CHANNEL_5		(5)
#define MCP3008_SIGNAL_CHANNEL_6		(6)
#define MCP3008_SIGNAL_CHANNEL_7		(7)

#define MCP3008_DIFF_CHANNEL_0_1		(0)
#define MCP3008_DIFF_CHANNEL_1_0		(1)
#define MCP3008_DIFF_CHANNEL_2_3		(2)
#define MCP3008_DIFF_CHANNEL_3_2		(3)
#define MCP3008_DIFF_CHANNEL_4_5		(4)
#define MCP3008_DIFF_CHANNEL_5_4		(5)
#define MCP3008_DIFF_CHANNEL_6_7		(6)
#define MCP3008_DIFF_CHANNEL_7_6		(7)

typedef enum{
	MCP3008_ChipNum_1 = 0,
	MCP3008_ChipNum_Count
}MCP3008_ChipNum_Type;

typedef enum
{
	MCP3008_Channel_0 = 0,
	MCP3008_Channel_1,
	MCP3008_Channel_2,
	MCP3008_Channel_3,
	MCP3008_Channel_4,
	MCP3008_Channel_5,
	MCP3008_Channel_6,
	MCP3008_Channel_7,
	MCP3008_Channel_Max,
} MCP3008_Channel;

typedef enum
{
	MCP3008_MODE_DIFF = 0,
	MCP3008_MODE_SIGNAL = 0x08,
} MCP3008_MODE;

typedef struct{
	Mcal_Spi_Channel spix;
	Mcal_Spi_CS spi_cs;
	boolean exist;
	MCP3008_MODE mode[MCP3008_Channel_Max];
}MCP3008_Config_Type;

typedef struct{
	Mcal_Spi_Channel spix;
	Mcal_Spi_MasterPin pin_cfg;
	Mcal_Spi_CS spi_cs;
	MCP3008_MODE mode[MCP3008_Channel_Max];
}MCP3008_InitPara_Type;


extern void   MCP3008_Init(MCP3008_ChipNum_Type chip_num, MCP3008_InitPara_Type *init_para);
extern uint32 MCP3008_GetValue(MCP3008_ChipNum_Type chip_num, uint8 channel);
extern void   MCP3008_SetChannelMode(MCP3008_ChipNum_Type chip_num, MCP3008_Channel channel, MCP3008_MODE mode);

#endif /* _MCP3008_H_ */
