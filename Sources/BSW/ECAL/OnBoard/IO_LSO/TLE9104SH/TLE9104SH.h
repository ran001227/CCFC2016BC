/*************************************************************
Copyright (c)  2015-2016. All rights reserved.

File name:		TLE9104SH.h
Author:			
Version:		V1.0.2
Date:			2022-03-16
Description:
Others:
History:

	1. Date:
	   Author:	DHY
	   Modification:
	2. ...
**************************************************************/

#ifndef TLE9104SH_H
#define TLE9104SH_H

#include "bsw_typedefs.h"
#include "MCAL_GPIO.h"
#include "MCAL_SPI.h"
#include "MCAL_OPWM.h"

typedef enum{
	TLE9104SH_CTRL = 0,
	TLE9104SH_CFG = 1,
	TLE9104SH_OFF_DIAG_CFG = 2,
	TLE9104SH_ON_DIAG_CFG = 3,
	TLE9104SH_DIAG_OUT_1_2_ON = 4,
	TLE9104SH_DIAG_OUT_3_4_ON = 5,
	TLE9104SH_DIAG_OFF = 6,
	TLE9104SH_Global_Status = 7,
	TLE9104SH_ICVID = 8,
}TLE9104SH_Reg;

typedef enum{
	TLE9104SH_Reg_Read = 0,
	TLE9104SH_Reg_Write = 1,
}TLE9104SH_RegOperate;

#define BIGENDIAN

struct TLE9104SHdrive
{
#ifdef BIGENDIAN
	union
	{
		uint16 D;
		struct
		{
			uint8 W_R  	        : 1;
			uint8 Parity    	: 1;
			uint8 Reserved 		: 2;
			uint8 Address  		: 4;
			uint8 WD_TIME    	: 2;
			uint8 OUT3_4_PAR  	: 1;
			uint8 OUT1_2_PAR 	: 1;
			uint8 OUT4_DD    	: 1;
			uint8 OUT3_DD   	: 1;
			uint8 OUT2_DD   	: 1;
			uint8 OUT1_DD   	: 1;
		}bit;
	}CFG;
	union
	{
		uint16 D;
		struct
		{
			uint8 W_R  	        : 1;
			uint8 Parity    	: 1;
			uint8 Reserved 		: 2;
			uint8 Address  		: 4;
			uint8 OUT4_ON_S  	: 1;
			uint8 OUT4_ON_C  	: 1;
			uint8 OUT3_ON_S  	: 1;
			uint8 OUT3_ON_C  	: 1;
			uint8 OUT2_ON_S  	: 1;
			uint8 OUT2_ON_C  	: 1;
			uint8 OUT1_ON_S  	: 1;
			uint8 OUT1_ON_C  	: 1;
		}bit;
	}CTRL;
	union
	{
		uint16 D;
		struct
		{
			uint8 W_R  	       		: 1;
			uint8 Parity    		: 1;
			uint8 Reserved 			: 2;
			uint8 Address  			: 4;
			uint8 RES			  	: 2;
			uint8 DIAG_FILT_CFG  	: 2;
			uint8 OUT4_DIAG_EN  	: 1;
			uint8 OUT3_DIAG_EN  	: 1;
			uint8 OUT2_DIAG_EN  	: 1;
			uint8 OUT1_DIAG_EN  	: 1;
		}bit;
	}OFF_DIAG_CFG;
	union
	{
		uint16 D;
		struct
		{
			uint8 W_R  	        : 1;
			uint8 Parity    	: 1;
			uint8 Reserved 		: 2;
			uint8 Address  		: 4;
			uint8 RES			: 3;
			uint8 OC_FILT_CFG	: 3;
			uint8 OC_TH  		: 2;
		}bit;
	}ON_DIAG_CFG;
	union
	{
		uint16 D;
		struct
		{
			uint8 W_R  	        : 1;
			uint8 Parity    	: 1;
			uint8 Reserved 		: 2;
			uint8 Address  		: 4;
			uint8 OUT2_STAT		: 1;
			uint8 OUT1_STAT		: 1;
			uint8 DIAG_CH2_ON	: 3;
			uint8 DIAG_CH1_ON  	: 3;
		}bit;
	}DIAG_OUT_1_2_ON;
	union
	{
		uint16 D;
		struct
		{
			uint8 W_R  	        : 1;
			uint8 Parity    	: 1;
			uint8 Reserved 		: 2;
			uint8 Address  		: 4;
			uint8 OUT4_STAT		: 1;
			uint8 OUT3_STAT		: 1;
			uint8 DIAG_CH4_ON	: 3;
			uint8 DIAG_CH3_ON  	: 3;
		}bit;
	}DIAG_OUT_3_4_ON;
	union
	{
		uint16 D;
		struct
		{
			uint8 W_R  	        	: 1;
			uint8 Parity    		: 1;
			uint8 Reserved 			: 2;
			uint8 Address  			: 4;
			uint8 DIAG_CH4_OFF  	: 2;
			uint8 DIAG_CH3_OFF  	: 2;
			uint8 DIAG_CH2_OFF  	: 2;
			uint8 DIAG_CH1_OFF  	: 2;
		}bit;
	}DIAG_OFF;
	union
	{
		uint16 D;
		struct
		{
			uint8 W_R  	        : 1;
			uint8 Parity    	: 1;
			uint8 Reserved 		: 2;
			uint8 Address  		: 4;
			uint8 OUT_EN  		: 1;
			uint8 SPARE  		: 1;
		    uint8 GEN_FAULT  	: 1;
			uint8 COM_ERR  		: 1;
			uint8 PAR_ERR  		: 1;
			uint8 CWD_TO  		: 1;
			uint8 EN_LATCH  	: 1;
			uint8 POR_LATCH  	: 1;
		}bit;
	}GLOBAL_STATUS;
#else
	union
	{
		uint16 D;
		struct
		{
			uint8 OUT1_DD   	: 1;
			uint8 OUT2_DD   	: 1;
			uint8 OUT3_DD   	: 1;
			uint8 OUT4_DD    	: 1;
			uint8 OUT1_2_PAR 	: 1;
			uint8 OUT3_4_PAR  	: 1;
			uint8 WD_TIME    	: 2;
			uint8 Address  		: 4;
			uint8 Reserved 		: 2;
			uint8 Parity    	: 1;
			uint8 W_R  	        : 1;
		}bit;
	}CFG;
	union
	{
		uint16 D;
		struct
		{
			uint8 OUT1_ON_C  	: 1;
			uint8 OUT1_ON_S  	: 1;
			uint8 OUT2_ON_C  	: 1;
			uint8 OUT2_ON_S  	: 1;
			uint8 OUT3_ON_C  	: 1;
			uint8 OUT3_ON_S  	: 1;
			uint8 OUT4_ON_C  	: 1;
			uint8 OUT4_ON_S  	: 1;
			uint8 Address  		: 4;
			uint8 Reserved 		: 2;
			uint8 Parity    	: 1;
			uint8 W_R  	        : 1;
		}bit;
	}CTRL;
	union
	{
		uint16 D;
		struct
		{
			uint8 OUT1_DIAG_EN  	: 1;
			uint8 OUT2_DIAG_EN  	: 1;
			uint8 OUT3_DIAG_EN  	: 1;
			uint8 OUT4_DIAG_EN  	: 1;
			uint8 DIAG_FILT_CFG  	: 2;
			uint8 RES			  	: 2;
			uint8 Address  			: 4;
			uint8 Reserved 			: 2;
			uint8 Parity    		: 1;
			uint8 W_R  	       		: 1;
		}bit;
	}OFF_DIAG_CFG;
	union
	{
		uint16 D;
		struct
		{
			uint8 OC_TH  		: 2;
			uint8 OC_FILT_CFG	: 3;
			uint8 RES			: 3;
			uint8 Address  		: 4;
			uint8 Reserved 		: 2;
			uint8 Parity    	: 1;
			uint8 W_R  	        : 1;
		}bit;
	}ON_DIAG_CFG;
	union
	{
		uint16 D;
		struct
		{
			uint8 DIAG_CH1_ON  	: 3;
			uint8 DIAG_CH2_ON	: 3;
			uint8 OUT1_STAT		: 1;
			uint8 OUT2_STAT		: 1;
			uint8 Address  		: 4;
			uint8 Reserved 		: 2;
			uint8 Parity    	: 1;
			uint8 W_R  	        : 1;
		}bit;
	}DIAG_OUT_1_2_ON;
	union
	{
		uint16 D;
		struct
		{
			uint8 DIAG_CH3_ON  	: 3;
			uint8 DIAG_CH4_ON	: 3;
			uint8 OUT3_STAT		: 1;
			uint8 OUT4_STAT		: 1;
			uint8 Address  		: 4;
			uint8 Reserved 		: 2;
			uint8 Parity    	: 1;
			uint8 W_R  	        : 1;
		}bit;
	}DIAG_OUT_3_4_ON;
	union
	{
		uint16 D;
		struct
		{
			uint8 DIAG_CH1_OFF  	: 2;
			uint8 DIAG_CH2_OFF  	: 2;
			uint8 DIAG_CH3_OFF  	: 2;
			uint8 DIAG_CH4_OFF  	: 2;
			uint8 Address  			: 4;
			uint8 Reserved 			: 2;
			uint8 Parity    		: 1;
			uint8 W_R  	        	: 1;
		}bit;
	}DIAG_OFF;
	union
	{
		uint16 D;
		struct
		{
			uint8 POR_LATCH  	: 1;
			uint8 EN_LATCH  	: 1;
			uint8 CWD_TO  		: 1;
			uint8 PAR_ERR  		: 1;
			uint8 COM_ERR  		: 1;
		    uint8 GEN_FAULT  	: 1;
			uint8 SPARE  		: 1;
			uint8 OUT_EN  		: 1;
			uint8 Address  		: 4;
			uint8 Reserved 		: 2;
			uint8 Parity    	: 1;
			uint8 W_R  	        : 1;
		}bit;
	}GLOBAL_STATUS;
#endif
};

#define		TLE9104SH_CHIPNUM_MAX			(2)
#define 	TLE9104SH_CHIPCHANNEL_MAX		(4)

typedef enum
{
	TLE9104SH_01=0,
	TLE9104SH_02,

}TLE9104SH_ChipNum;

typedef enum
{
	TLE9104SH_OUT01=0,
	TLE9104SH_OUT02,
	TLE9104SH_OUT03,
	TLE9104SH_OUT04,

}TLE9104SH_OutChannel;

typedef enum
{
	TLE9104SH_ChipMode_SPI_IN=0,
	TLE9104SH_ChipMode_IO_IN,

}TLE9104SH_ControlMode;

typedef enum
{
	current_1000_mA=0,
	current_2000_mA=1,
	current_3000_mA=2,
	current_4000_mA=3,
}Overcurrent_threshold;

typedef struct
{
	boolean TLE9104_OUT1_diag_EN;
	boolean TLE9104_OUT2_diag_EN;
	boolean TLE9104_OUT3_diag_EN;
	boolean TLE9104_OUT4_diag_EN;
}TLE9104SH_OffState_Diag_Config;

typedef struct
{
	Mcal_GPIO_Pin GPIO_IN[TLE9104SH_CHIPCHANNEL_MAX];
	Mcal_OPWM_Channel OPWM_IN[TLE9104SH_CHIPCHANNEL_MAX];
	const Mcal_OPWM_Pin* OPWMPinPtr_IN[TLE9104SH_CHIPCHANNEL_MAX];
	TLE9104SH_ControlMode ControlMode;
	Mcal_Spi_Channel SPI_Channel;
	Mcal_Spi_CS	 SPI_CS;
	Mcal_Spi_MasterPin SPI_MasterPin;
	Mcal_GPIO_Pin GPIO_RESET;
	Mcal_GPIO_Pin GPIO_EN;
	Overcurrent_threshold OverCurrent_TS;
}TLE9104SH_ChipConfig;


extern void  TLE9104SH_InitChip(TLE9104SH_ChipNum ChipNum, TLE9104SH_ChipConfig	*ChipCfg);
extern void  TLE9104SH_InitChannel(TLE9104SH_ChipNum ChipNum, TLE9104SH_OutChannel OutChannel,boolean EnableOpwm);
extern void  TLE9104SH_SwitchType_SetState(TLE9104SH_ChipNum ChipNum,TLE9104SH_OutChannel OutChannel,boolean State);
extern uint8 TLE9104SH_ReadDTC(TLE9104SH_ChipNum ChipNum, TLE9104SH_OutChannel OutChannel);
extern void  TLE9104SH_OPWMType_SetParameter(TLE9104SH_ChipNum ChipNum,TLE9104SH_OutChannel OutChannel,uint32 Freq,uint32 Duty);
extern void F_TLE9104SH_OffState_Diag_Config(TLE9104SH_ChipNum ChipNum,TLE9104SH_OffState_Diag_Config OffState_Diag_Config );


#endif
