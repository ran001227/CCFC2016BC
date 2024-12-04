/******************************************************************************
*	Copyright (c) ECO-EV Technologies Co., Ltd. 2015-2016.
*	All rights reserved.

*	File name:		MPC3914.h
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

#ifndef _MCP3914_H_
#define _MCP3914_H_


#include "bsw_typedefs.h"
#include "Mcal_SPI.h"
#include "Mcal_GPIO.h"

#define SPI_BAUDRATE_K		(1000)
#define SPI_BAUDRATE_M		(1000*1000)

#define MCP3914_MODE_READ		(0x41)
#define MCP3914_MODE_WRITE		(0x40)

#define MCP3914_READ_REG(reg)	((reg) << 1 | MCP3914_MODE_READ)
#define MCP3914_WRITE_REG(reg)	((reg) << 1 | MCP3914_MODE_WRITE)

typedef enum{
	MCP3914_ChipNum_1 = 0,
	MCP3914_ChipNum_Count
}MCP3914_ChipNum_Type;

typedef enum
{
	MCP3914_Channel_0 = 0,
	MCP3914_Channel_1,
	MCP3914_Channel_2,
	MCP3914_Channel_3,
	MCP3914_Channel_4,
	MCP3914_Channel_5,
	MCP3914_Channel_6,
	MCP3914_Channel_7,
} MCP3914_Channel;

typedef struct{
	Mcal_Spi_Channel spix;
	Mcal_Spi_CS spi_cs;
	Mcal_GPIO_Pin rst;
	boolean exist;
}MCP3914_Config_Type;

typedef struct{
	Mcal_Spi_Channel spix;
	Mcal_Spi_MasterPin pin_cfg;
	Mcal_Spi_CS spi_cs;
	Mcal_GPIO_Pin rst;
}MCP3914_InitPara_Type;





typedef enum
{
	MCP3914_GAIN_1 = 0,
	MCP3914_GAIN_2,
	MCP3914_GAIN_4,
	MCP3914_GAIN_8,
	MCP3914_GAIN_16,
	MCP3914_GAIN_32,
} MCP3914_GAIN;

typedef union
{
	struct
	{
		uint8  GAIN0:3;
		uint8  GAIN1:3;
		uint8  GAIN2:3;
		uint8  GAIN3:3;
		uint8  GAIN4:3;
		uint8  GAIN5:3;
		uint8  GAIN6:3;
		uint8  GAIN7:3;
	} B;
	uint32 R;
};


typedef enum
{
	MCP3914_DATA_WIDTH_16 = 0,
	MCP3914_DATA_WIDTH_24,
	MCP3914_DATA_WIDTH_32_ZERO,
	MCP3914_DATA_WIDTH_32_SIGN,
} MCP3914_DATA_WIDTH;


typedef union
{
	struct
	{
		uint8 DRSTATUS0:1;
		uint8 DRSTATUS1:1;
		uint8 DRSTATUS2:1;
		uint8 DRSTATUS3:1;
		uint8 DRSTATUS4:1;
		uint8 DRSTATUS5:1;
		uint8 DRSTATUS6:1;
		uint8 DRSTATUS7:1;

		uint8 reserved:6;
		uint8 EN_INT:1;
		uint8 EN_CRCCOM:1;

		uint8 WIDTH_DATA:2;
		uint8 WIDTH_CRC:1;
		uint8 DR_LINK:1;
		uint8 DR_HIZ:1;
		uint8 WRITE:1;
		uint8 READ:2;
	} B;
	uint32 R;
} MCP3914_COMSTATUS;


typedef enum
{
	MCP3914_DITHERING_OFF = 0,
	MCP3914_DITHERING_MINI,
	MCP3914_DITHERING_MEDIUM,
	MCP3914_DITHERING_MAX,
} MCP3914_DITHERING;;

typedef enum
{
	AMCLK_1 = 0,
	AMCLK_2,
	AMCLK_4,
	AMCLK_8,
} MCP3914_AMCLK;

typedef enum
{
	MCP3914_OSR_32 = 0,
	MCP3914_OSR_64,
	MCP3914_OSR_128,
	MCP3914_OSR_256,
	MCP3914_OSR_512,
	MCP3914_OSR_1024,
	MCP3914_OSR_2048,
	MCP3914_OSR_4096,
} MCP3914_OSR;

// MCLK = 4MHz   AMCLK = 1MHz
#define GET_MCP3914_SPS(osr)		(312500 / (1 << (5 + (osr))))


typedef union
{
	struct
	{
		uint8  VREFCAL0:1;
		uint8  VREFCAL1:1;
		uint8  VREFCAL2:1;
		uint8  VREFCAL3:1;
		uint8  VREFCAL4:1;
		uint8  VREFCAL5:1;
		uint8  VREFCAL6:1;
		uint8  VREFCAL7:1;

		uint8  Reserve:5;
		uint8  OSR:3;

		uint8  PRE:3;
		uint8  BOOST:2;
		uint8  DITHER:2;
		uint8  EN_GAINCAL:1;
		uint8  EN_OFFCAL:1;
	} B;
	uint32 R;
} MCP3914_CONFIG0;


typedef union
{
	struct
	{
		uint8  Reserve:6;
		uint8  CLKEXT:1;
		uint8  VREFEXT:1;

		uint8  SHUTDOWN0:1;
		uint8  SHUTDOWN1:1;
		uint8  SHUTDOWN2:1;
		uint8  SHUTDOWN3:1;
		uint8  SHUTDOWN4:1;
		uint8  SHUTDOWN5:1;
		uint8  SHUTDOWN6:1;
		uint8  SHUTDOWN7:1;

		uint8  RESET0:1;
		uint8  RESET1:1;
		uint8  RESET2:1;
		uint8  RESET3:1;
		uint8  RESET4:1;
		uint8  RESET5:1;
		uint8  RESET6:1;
		uint8  RESET7:1;
	} B;
	uint32 R;
} MCP3914_CONFIG1;

typedef union
{
	struct
	{
		uint16 CRCREG;
		uint8  LOCK;
	} B;
	uint32 R;
} MCP3914_SECURITY;

typedef enum
{
	MCP3914_REG_CHANNEL0 = 0,
	MCP3914_REG_CHANNEL1,
	MCP3914_REG_CHANNEL2,
	MCP3914_REG_CHANNEL3,
	MCP3914_REG_CHANNEL4,
	MCP3914_REG_CHANNEL5,
	MCP3914_REG_CHANNEL6,
	MCP3914_REG_CHANNEL7,
	MCP3914_REG_MOD,				// DO NOT WRITE TO THIS REGISTER
	MCP3914_REG_PHASE0,
	MCP3914_REG_PHASE1,
	MCP3914_REG_GAIN,
	MCP3914_REG_STATUSCOM,
	MCP3914_REG_CONFIG0,
	MCP3914_REG_CONFIG1,
	MCP3914_REG_OFFCAL_CH0,
	MCP3914_REG_GAINCAL_CH0,
	MCP3914_REG_OFFCAL_CH1,
	MCP3914_REG_GAINCAL_CH1,
	MCP3914_REG_OFFCAL_CH2,
	MCP3914_REG_GAINCAL_CH2,
	MCP3914_REG_OFFCAL_CH3,
	MCP3914_REG_GAINCAL_CH3,
	MCP3914_REG_OFFCAL_CH4,
	MCP3914_REG_GAINCAL_CH4,
	MCP3914_REG_OFFCAL_CH5,
	MCP3914_REG_GAINCAL_CH5,
	MCP3914_REG_OFFCAL_CH6,
	MCP3914_REG_GAINCAL_CH6,
	MCP3914_REG_OFFCAL_CH7,
	MCP3914_REG_GAINCAL_CH7,
	MCP3914_REG_LOCK,
} MCP3914_REG;


extern void MCP3914_Init(MCP3914_ChipNum_Type chip_num, MCP3914_InitPara_Type *init_para);
extern void MCP3914_SetGain(MCP3914_ChipNum_Type chip_num, MCP3914_Channel channel, MCP3914_GAIN gain);
extern uint32 MCP3914_GetValue(MCP3914_ChipNum_Type chip_num, MCP3914_Channel channel);


#endif /* _MCP3914_H_ */
