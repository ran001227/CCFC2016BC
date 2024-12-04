/*************************************************************
Copyright (c)  2015-2016. All rights reserved.

File name:		TLE8110.h
Author:			
Version:		V1.0.1
Date:			2017-1-16
Description:
Others:
History:

	1. Date:
	   Author:
	   Modification:
	2. ...
**************************************************************/


#ifndef TLE8110_H
#define TLE8110_H

#include "bsw_typedefs.h"
#include "MCAL_GPIO.h"
#include "MCAL_SPI.h"
#include "MCAL_OPWM.h"

/*************************************************************
Public Variable Definitions
**************************************************************/
#define BIGENDIAN

struct TLE8110drive
{
#ifdef BIGENDIAN


	union
	{
		uint16 D;
		struct
		{
			uint16 W_R  	: 1;
			uint16 Address  : 3;
			uint16 RCP  	: 1;
			uint16 DBT  	: 2;
			uint16 DEVS  	: 6;
			uint16 DCCX  	: 3;
		}bit;
	}DEVS;
	union
	{
		uint16 D;
		struct
		{
			uint16 W_R  	: 1;
			uint16 Address  : 3;
			uint16 NOP  	: 12;
		}bit;
	}CMD_NOP;
	union
	{
		uint16 D;
		struct
		{
			uint16 W_R  	: 1;
			uint16 Address  : 3;
			uint16 CSDS  	: 12;
		}bit;
	}CMD_CSDS;
	union
	{
		uint16 D;
		struct
		{
			uint16 W_R  	: 1;
			uint16 Address  : 3;
			uint16 RINx  	: 12;
		}bit;
	}CMD_RINx;
	union
	{
		uint16 D;
		struct
		{
			uint16 W_R  	: 1;
			uint16 Address  : 3;
			uint16 RPC  	: 12;
		}bit;
	}CMD_RPC;
	union
	{
		uint16 D;
		struct
		{
			uint16 W_R  	: 1;
			uint16 Address  : 3;
			uint16 RSD  	: 12;
		}bit;
	}CMD_RSD;
	union
	{
		uint16 D;
		struct
		{
			uint16 W_R  	: 1;
			uint16 Address  : 3;
			uint16 Reserved : 2;
			uint16 OUT10  	: 1;
			uint16 OUT9  	: 1;
			uint16 OUT8  	: 1;
			uint16 OUT7  	: 1;
			uint16 OUT6 	: 1;
			uint16 OUT5  	: 1;
			uint16 OUT4  	: 1;
			uint16 OUT3  	: 1;
			uint16 OUT2 	: 1;
			uint16 OUT1  	: 1;
		}bit;
	}OUT;
	union
	{
		uint16 D;
		struct
		{
			uint16 W_R  	: 1;
			uint16 Address  : 3;
			uint16 IS6  	: 2;
			uint16 IS5  	: 2;
			uint16 IS4  	: 2;
			uint16 IS3  	: 2;
			uint16 IS2 		: 2;
			uint16 IS1  	: 2;
		}bit;
	}ISA;
	union
	{
		uint16 D;
		struct
		{
			uint16 W_R  	: 1;
			uint16 Address  : 3;
			uint16 Reserved : 4;
			uint16 IS10  	: 2;
			uint16 IS9  	: 2;
			uint16 IS8  	: 2;
			uint16 IS7  	: 2;
		}bit;
	}ISB;
	union
	{
		uint16 D;
		struct
		{
			uint16 W_R  	: 1;
			uint16 Address  : 3;
			uint16 Reserved1 : 4;
			uint16 PM910  	: 1;
			uint16 PM89  	: 1;
			uint16 PM78  	: 1;
			uint16 PM56  	: 1;
			uint16 Reserved : 1;
			uint16 PM34  	: 1;
			uint16 PM23  	: 1;
			uint16 PM12  	: 1;
		}bit;
	}PM;
	union
	{
		uint16 D;
		struct
		{
			uint16 W_R  	: 1;
			uint16 Address  : 3;
			uint16 Reserved1 : 4;
			uint16 DRB10_1	: 1;
			uint16 DRB10_0	: 1;
			uint16 DRB9_1	: 1;
			uint16 DRB9_0	: 1;
			uint16 DRB8_1	: 1;
			uint16 DRB8_0	: 1;
			uint16 DRB7_1	: 1;
			uint16 DRB7_0	: 1;
		}bit;
	}DRB;
	union
	{
		uint16 D;
		struct
		{
			uint16 W_R  	: 1;
			uint16 Address  : 3;
			uint16 DRA6_1	: 1;
			uint16 DRA6_0	: 1;
			uint16 DRA5_1	: 1;
			uint16 DRA5_0	: 1;
			uint16 DRA4_1	: 1;
			uint16 DRA4_0	: 1;
			uint16 DRA3_1	: 1;
			uint16 DRA3_0	: 1;
			uint16 DRA2_1	: 1;
			uint16 DRA2_0	: 1;
			uint16 DRA1_1	: 1;
			uint16 DRA1_0	: 1;
		}bit;
	}DRA;


	union
	{
		uint16 D;
		struct
		{
			uint16 W_R  	: 1;
			uint16 Address  : 3;
			uint16 Command  : 4;
			uint16 reserved : 8;
		}bit;
	}DRBCL;
	union
	{
		uint16 D;
		struct
		{
			uint16 W_R  	: 1;
			uint16 Address  : 3;
			uint16 Command  : 4;
			uint16 reserved : 8;
		}bit;
	}DRACL;

#else
	union
	{
		uint16 D;
		struct
		{
			uint16 OUT1  	: 1;
			uint16 OUT2  	: 1;
			uint16 OUT3  	: 1;
			uint16 OUT4  	: 1;
			uint16 OUT5 	: 1;
			uint16 OUT6  	: 1;
			uint16 OUT7  	: 1;
			uint16 OUT8  	: 1;
			uint16 OUT9 	: 1;
			uint16 OUT10  	: 1;
			uint16 Reserved : 2;
			uint16 Address  : 3;
			uint16 W_R  	: 1;

		}bit;
	}OUT;
	union
	{
		uint16 D;
		struct
		{
			uint16 IS1  	: 2;
			uint16 IS2  	: 2;
			uint16 IS3  	: 2;
			uint16 IS4  	: 2;
			uint16 IS5 		: 2;
			uint16 IS6  	: 2;
			uint16 Address  : 3;
			uint16 W_R  	: 1;

		}bit;
	}ISA;
	union
	{
		uint16 D;
		struct
		{
			uint16 IS7  	: 2;
			uint16 IS8  	: 2;
			uint16 IS9  	: 2;
			uint16 IS10  	: 2;
			uint16 Reserved : 4;
			uint16 Address  : 3;
			uint16 W_R  	: 1;

		}bit;
	}ISB;
	union
	{
		uint16 D;
		struct
		{
			uint16 PM12  	: 1;
			uint16 PM23  	: 1;
			uint16 PM34  	: 1;
			uint16 Reserved : 1;
			uint16 PM56  	: 1;
			uint16 PM78  	: 1;
			uint16 PM89  	: 1;
			uint16 PM910  	: 1;
			uint16 Reserved1 : 4;
			uint16 Address  : 3;
			uint16 W_R  	: 1;
		}bit;
	}PM;
#endif
};

typedef enum
{
	TLE8110_ChipNum_U01=0,
	TLE8110_ChipNum_U02=1,
	TLE8110_ChipNum_U03=2,
	TLE8110_CHIPNUM_MAX
} TLE8110_ChipNum;


/** \brief Enumerate the Channels of SPI
 */
typedef enum
{
	TLE8110_OUT01=0,
	TLE8110_OUT02,
	TLE8110_OUT03,
	TLE8110_OUT04,
	TLE8110_OUT05,
	TLE8110_OUT06,
	TLE8110_OUT07,
	TLE8110_OUT08,
	TLE8110_OUT09,
	TLE8110_OUT10,
	TLE8110_CHIPCHANNEL_MAX
} TLE8110_OutChannel;


/** \brief the Structure of the BTT6200 Pin
 */
typedef struct
{
	uint16  GPIO_IN[TLE8110_CHIPCHANNEL_MAX];
	uint8 OPWM_IN[TLE8110_CHIPCHANNEL_MAX];
	const Mcal_OPWM_Pin* OPWM_PinPtr[TLE8110_CHIPCHANNEL_MAX];
	uint16  GPIO_RST;
	uint16  GPIO_EN;
	Mcal_Spi_Channel SPI_Channel;
	Mcal_Spi_CS	 SPI_CS;
	Mcal_Spi_MasterPin SPI_MasterPin;

}TLE8110_ChipPin;

extern void TLE8110_InitChannel(TLE8110_ChipNum ChipNum, TLE8110_OutChannel OutChannel,boolean EnableOpwm);
extern void TLE8110_EnableChannel(TLE8110_ChipNum ChipNum);
extern void TLE8110_DisableChannel(TLE8110_ChipNum ChipNum);
extern void  TLE8110_InitChip(TLE8110_ChipNum ChipNum,TLE8110_ChipPin	*ChipPin);
extern void TLE8110_SwitchType_SetState(TLE8110_ChipNum ChipNum,TLE8110_OutChannel OutChannel,boolean State);
extern uint8 TLE8110_ReadDTC(TLE8110_ChipNum ChipNum,TLE8110_OutChannel OutChannel);
extern void TLE8110_OPWMType_SetParameter(TLE8110_ChipNum ChipNum,TLE8110_OutChannel OutChannel,uint32 Freq,uint32 Duty);
extern void F_TLE8110_PinOut_r10ms(void);
#endif

