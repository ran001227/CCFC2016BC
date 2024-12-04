/******************************************************************************
*	Copyright (c) ECO-EV Technologies Co., Ltd. 2015-2016.
*	All rights reserved.

*	File name:		MC33907.h
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

#ifndef __MC33907_H__
#define __MC33907_H__


#include "typedefs.h"
#include "MCAL_SPI.h"
#include "MCAL_GPIO.h"
#include "MCAL_ADC.h"

/** \brief the structure of the MC33907 chip pin
 */
typedef struct
{
   Mcal_Spi_Channel  SPI_Channel;
   Mcal_Spi_CS       SPI_CS;
   Mcal_Spi_MasterPin  SPI_MasterPin;

   Mcal_GPIO_Pin GPIO_FS0B;
   Mcal_ADC_Channel ADC_MUX;
   Mcal_ADC_Pin ADCPin_Ptr;
}MC33907_ChipPin;



/** \brief  enumerate Addresses of the MC33907/FS4500 registers
 */
typedef enum{
   MC33907_INIT_VREG1_ADR = 0x01,
   MC33907_INIT_VREG2_ADR = 0x02,
   MC33907_INIT_CAN_LIN_ADR = 0x03,
   MC33907_INIT_IO_WU1_ADR = 0x04,
   MC33907_INIT_IO_WU2_ADR = 0x05,
   MC33907_INIT_INT_ADR = 0x06,
   MC33907_HW_CONFIG_ADR = 0x08,
   MC33907_WU_SOURCE_ADR = 0x09,
   MC33907_IO_INPUT_ADR = 0x0B,
   MC33907_STATUS_VREG1_ADR = 0x0C,
   MC33907_STATUS_VREG2_ADR = 0x0D,
   MC33907_DIAG_VREG1_ADR = 0x0E,
   MC33907_DIAG_VREG2_ADR = 0x0F,
   MC33907_DIAG_VREG3_ADR = 0x10,
   MC33907_DIAG_CAN1_ADR    = 0x11,
   MC33907_DIAG_CAN_LIN_ADR = 0x12,
   MC33907_DIAG_SPI_ADR = 0x13,
   MC33907_MODE_ADR = 0x15,
   MC33907_VREG_MODE_ADR = 0x16,
   MC33907_IO_OUT_AMUX_ADR = 0x17,
   MC33907_CAN_LIN_MODE_ADR = 0x18,
   MC33907_CAN_MODE2_ADR = 0x19,


   MC33907_INIT_SUPERVISOR1_ADR = 0x21,
   MC33907_INIT_SUPERVISOR2_ADR = 0x22,
   MC33907_INIT_SUPERVISOR3_ADR = 0x23,
   MC33907_INIT_FSSM1_ADR = 0x24,
   MC33907_INIT_FSSM2_ADR = 0x25,
   MC33907_WD_WINDOW_ADR = 0x26,
   MC33907_WD_LFSR_ADR = 0x27,
   MC33907_WD_ANSWER_ADR = 0x28,
   MC33907_FS_OUT_ADR = 0x29,
   MC33907_RSTB_REQUEST_ADR = 0x2A,
   MC33907_INIT_WD_ADR = 0x2B,
   MC33907_DIAG_FS1_ADR = 0x2C,
   MC33907_WD_COUNTER_ADR = 0x2D,
   MC33907_DIAG_FS2_ADR = 0x2E,

}MC33907_RegisterAddress;


/** \brief the enumerate of the MC33907 watch dog window duration
 */
typedef enum
{

	MC33907_WD_WindowDuration_Disable,
	MC33907_WD_WindowDuration_1ms,
	MC33907_WD_WindowDuration_2ms,
	MC33907_WD_WindowDuration_3ms,
	MC33907_WD_WindowDuration_4ms,
	MC33907_WD_WindowDuration_6ms,
	MC33907_WD_WindowDuration_8ms,
	MC33907_WD_WindowDuration_12ms,
	MC33907_WD_WindowDuration_16ms,
	MC33907_WD_WindowDuration_24ms,
	MC33907_WD_WindowDuration_32ms,
	MC33907_WD_WindowDuration_64ms,
	MC33907_WD_WindowDuration_128ms,
	MC33907_WD_WindowDuration_256ms,
	MC33907_WD_WindowDuration_512ms,
	MC33907_WD_WindowDuration_1024ms

}MC33907_WD_WindowDuration;         //watch dog window duration


/** \brief the enumerate of the MC33907's maximum value of the WD error counter
 */
typedef enum
{
	MC33907_WD_MaxErrorCounter_6 = 1,
	MC33907_WD_MaxErrorCounter_4,
	MC33907_WD_MaxErrorCounter_2
}MC33907_WD_MaxErrorCounter;


/** \brief the enumerate of the MC33907's maximum value of the WD refresh counter
 */
typedef enum
{
	MC33907_WD_MaxRefreshCounter_6,
	MC33907_WD_MaxRefreshCounter_4,
	MC33907_WD_MaxRefreshCounter_2,
	MC33907_WD_MaxRefreshCounter_1
}MC33907_WD_MaxRefreshCounter;


/** \brief the enumerate of the MC33907's maximum value of the fault error counter

Conditions leading to an increment of the fault error counter, and according to the product configuration are:
   Watch dog refresh not OK or watch dog timeout during INIT phase
   Watch dog error counter = max value (6 by default)
   VPRE Over voltage
   VCORE, VCCA, VAUX under voltage
   VCORE, VCCA, VAUX over voltage
   FCRBM follows VCORE configuration
   IO_23 error detection (FCCU)
   IO_45 error detection (external IC error)
   ABIST1, ABIST2 fail
   RSTB short to high (by cascaded effect of FS0B assertion)
   SPI DED
   External reset (except reset extension by MCU after reset assertion by the device)
 */
typedef enum
{
	MC33907_RSTB_MaxCounter_6,      //RSTB_ERR_FS = 0/Intermediate = 3; Final = 6
	MC33907_RSTB_MaxCounter_2       //RSTB_ERR_FS = 1/Intermediate = 1; Final = 2
}MC33907_RSTB_MaxCounter;


/** \brief the enumerate of the MC33907's counter
 */
typedef enum
{
	MC33907_Conuter_WDError,
	MC33907_Conuter_WDRefresh,
	MC33907_Conuter_RSTB
}MC33907_Counter;


/** \brief the enumerate of the MC33907's selection of AMUX
 */
typedef enum
{
   MC33907_AMUX_Select_Vref,
   MC33907_AMUX_Select_Wide_Vsns,
   MC33907_AMUX_Select_Wide_IO0,
   MC33907_AMUX_Select_Wide_IO1,
   MC33907_AMUX_Select_Tight_Vsns,
   MC33907_AMUX_Select_Tight_IO0,
   MC33907_AMUX_Select_Tight_IO1,
   MC33907_AMUX_Select_Temperature

}MC33907_AMUX_Select;


/** \brief the enumerate of the MC33907 IOWakeUpStyle
 */
typedef enum
{
   MC33907_IOWakeUpStyle_Disble = 0,
   MC33907_IOWakeUpStyle_RisingEdge = 1,
   MC33907_IOWakeUpStyle_FallingEdge = 2,
   MC33907_IOWakeUpStyle_AnyEdge = 3
}MC33907_IOWakeUpStyle;

/** \brief the enumerate of the MC33907 IOWakeUpStyle
 */


typedef union { /* register32_struct */
	uint32_t R;
	struct {
		uint32_t				:16;
		uint32_t	bit15	:	1;
		uint32_t	bit14	:	1;
		uint32_t	bit13	:	1;
		uint32_t	bit12	:	1;
		uint32_t	bit11	:	1;
		uint32_t	bit10	:	1;
		uint32_t	bit9	:	1;
		uint32_t	bit8	:	1;
		uint32_t	bit7	:	1;
		uint32_t	bit6	:	1;
		uint32_t	bit5	:	1;
		uint32_t	bit4	:	1;
		uint32_t	bit3	:	1;
		uint32_t	bit2	:	1;
		uint32_t	bit1	:	1;
		uint32_t	bit0	:	1;
	} B;
} register32_struct;



struct {
	uint32_t	WD_answer;							///actual content of the WD_answer register
	register32_struct currentLFSR;		///last LFSR state
} FSstruct;



/** \brief the structure of the MC33907 configure
 */
typedef struct
{
   boolean EnCanWakeUp;
   boolean EnLinWakeUp;
   boolean EnOut_IO4;
   boolean EnFCCU;
   MC33907_IOWakeUpStyle WakeUpStyle_IO0;
   MC33907_WD_WindowDuration WD_WindowDuration;
   MC33907_WD_MaxErrorCounter WD_MaxErrorCounter;
   MC33907_WD_MaxRefreshCounter MaxRefreshCounter;
   MC33907_RSTB_MaxCounter RSTB_MaxCounter;
}MC33907_ChipConfig;

/** \brief the structure of the MC33907 configure
 */
typedef enum
{
   MC33907_IO0,
   MC33907_IO1,
   MC33907_IO2,
   MC33907_IO3,
   MC33907_IO4,
   MC33907_IO5,
   MC33907_FS0B,
   MC33907_RESET
}MC33907_IO;

/** \brief the enumerate of the MC33907 operation mode
 *
 * The following faults impact on RSTB activation (by default)
   Watch dog error counter = max value
   VCORE, VCCA, VAUX over voltage

   The following faults impact on FS0B activation (by default)
   VCORE, VCCA, VAUX under voltage
   Fault error counter incremented
 *
 */
typedef enum
{

	//VREG1
	MC33907_Trouble_VCORE_FB_OV,
	MC33907_Trouble_VCORE_FB_UV,
	MC33907_Trouble_VSNS_UV,
	MC33907_Trouble_VSUP_UV_7,
	MC33907_Trouble_VPRE_OV,
	MC33907_Trouble_VPRE_UV,
	MC33907_Trouble_TSD_PRE,
	MC33907_Trouble_TSD_CORE,


   //VREG2
	MC33907_Trouble_VCAN_OV,
	MC33907_Trouble_VCAN_UV,
	MC33907_Trouble_VAUX_OV,
	MC33907_Trouble_VAUX_UV,
	MC33907_Trouble_TSD_CAN,
	MC33907_Trouble_TSD_AUX,
	MC33907_Trouble_ILIM_AUX_OFF,


	//VREG3
	MC33907_Trouble_VCCA_OV,
	MC33907_Trouble_VCCA_UV,
	MC33907_Trouble_ILIM_CCA_OFF,
	MC33907_Trouble_TSD_CCA,

	//CAN
	MC33907_Trouble_CANH_BATT,
	MC33907_Trouble_CANH_GND,
	MC33907_Trouble_CANL_BATT,
	MC33907_Trouble_CANL_GND,
	MC33907_Trouble_CAN_Dominate,         //CAN over temperature detection
	MC33907_Trouble_RXD_Recessive,        //CAN RXD recessive clamping detection (short-circuit to 5.0 V)
	MC33907_Trouble_TXD_Dominant,        //CAN TXD dominant clamping detection (short-circuit to GND)

	//CAN_LIN
	MC33907_Trouble_CAN_OC,
	MC33907_Trouble_CAN_OT,
	MC33907_Trouble_LIN_OT,
	MC33907_Trouble_LIN_Dominate,         //CAN over temperature detection
	MC33907_Trouble_RXDL_Recessive,        //CAN RXD recessive clamping detection (short-circuit to 5.0 V)
	MC33907_Trouble_TXDL_Dominant,        //CAN TXD dominant clamping detection (short-circuit to GND)

	//SPI
	MC33907_Trouble_SPI_ERR,        //Secured SPI communication check
	MC33907_Trouble_SPI_CLK,        //Report a wrong number of CLK pulse different than 16 during the NCS low pulse in main state machine
	MC33907_Trouble_SPI_REQ,        //Invalid SPI access (wrong write or read, write to INIT registers in normal mode, wrong address)
	MC33907_Trouble_SPI_PARITY,      //Report a parity error in main state machine


	//FS1
	MC33907_Trouble_RSTb_diag,
	MC33907_Trouble_RSTb_ext,
	MC33907_Trouble_FS0b_diag_1,
	MC33907_Trouble_FS0b_diag_0,

	//FS2
	MC33907_Trouble_RSTb_err_2,
	MC33907_Trouble_RSTb_err_1,
	MC33907_Trouble_RSTb_err_0,
	MC33907_Trouble_IO_45_fail,
	MC33907_Trouble_IO_23_fail,
	MC33907_Trouble_IO_1_fail,
	MC33907_Trouble_IO_01_fail,


	//STATUS VREG1
	MC33907_Trouble_IPFF,
	MC33907_Trouble_ILIM_PRE,
	MC33907_Trouble_TWARN_PRE,
	MC33907_Trouble_BoB,
	MC33907_Trouble_VPRE_STATE,


	//STATUS VREG2
	MC33907_Trouble_ILIM_CORE,
	MC33907_Trouble_TWARN_CORE,
	MC33907_Trouble_VCORE_STATE,
	MC33907_Trouble_TWARN_CCA,
	MC33907_Trouble_ILIM_CCA,
	MC33907_Trouble_ILIM_AUX,
	MC33907_Trouble_ILIM_CAN,

}MC33907_Trouble;

typedef union
{
   uint8 R;
   struct
   {
      uint8 bit7      :1;
      uint8 bit6      :1;
      uint8 bit5      :1;
      uint8 bit4      :1;
      uint8 bit3      :1;
      uint8 bit2      :1;
      uint8 bit1      :1;
      uint8 bit0      :1;
   }B;
}MC33907_Command_tag;

typedef union
{
   uint8 R;
   struct
   {
      uint8 CAN_MODE        :2;
      uint8 CAN_AUTO_DIS    :1;
      uint8 LIN_MODE        :2;
      uint8 LIN_AUTO_DIS    :1;
      uint8 CAN_WU          :1;
      uint8 LIN_WU          :1;
   }B;
}MC33907_CAN_LIN_MODE;

typedef union
{
   uint8 R;
   struct
   {
      uint8 IO_OUT_4_EN     :1;
      uint8 IO_OUT_4        :1;
      uint8 IO_OUT_5_EN     :1;
      uint8 IO_OUT_5        :1;
      uint8 RESERVED        :1;
      uint8 AMUX            :3;
   }B;
}MC33907_IO_OUT_AMUX;


typedef union
{
   uint8 R;
   struct
   {
      uint8 RSTb_err_FS     :1;
      uint8 IO_23_FS        :1;
      uint8 PS              :1;
      uint8 RESERVED        :1;
      uint8 SECURE          :4;
   }B;
}INIT_FSSM2;



typedef union
{
   uint8 R;
   struct
   {
      uint8 WD_WINDOW       :4;
      uint8 SECURE          :4;
   }B;
}MC33907_WD_WINDOW;

typedef union
{
   uint8 R;
   struct
   {
      uint8 WD_CNT_ERR      :2;
      uint8 WD_CNT_RFR      :2;
      uint8 SECURE          :4;
   }B;
}INIT_WD;

typedef union
{
   uint8 R;
   struct
   {
      uint8 WD_ERR         :3;
      uint8 RESERVE        :1;
      uint8 WD_RFR         :3;
      uint8 RESERVED       :1;
   }B;
}MC33907_WD_COUNTER;


/** \brief the enumerate of the MC33907 operation mode
 */
typedef enum
{
   MC33907_WakeUpEvent_Null = 0,
   MC33907_WakeUpEvent_IO0 = 1,
   MC33907_WakeUpEvent_IO1,
   MC33907_WakeUpEvent_IO2,
   MC33907_WakeUpEvent_IO3,
   MC33907_WakeUpEvent_IO4,
   MC33907_WakeUpEvent_IO5,
   MC33907_WakeUpEvent_CAN,
   MC33907_WakeUpEvent_LIN,
}MC33907_WakeUpEvent;

/** \brief the enumerate of the MC33907 operation mode
 */
typedef enum
{
   MC33907_Mode_Normal,
   MC33907_Mode_LPOFF_Sleep,
   MC33907_Mode_LPOFF_DeepFS
}MC33907_Mode;

/** \brief the enumerate of the MC33907 voltage out
 */
typedef enum
{
   MC33907_Vout_VPRE,
   MC33907_Vout_VCORE,
   MC33907_Vout_VCCA,
   MC33907_Vout_VAUX,
   MC33907_Vout_VCAN,
}MC33907_Vout;


/** \brief the enumerate of the MC33907  out
 */
typedef enum
{
   MC33907_CanTransceiverMode_Sleep_NoWakeup=0,
   MC33907_CanTransceiverMode_ListenOnly,
   MC33907_CanTransceiverMode_Sleep_WakeUp,
   MC33907_CanTransceiverMode_Normal,
}MC33907_CanTransceiverMode;


/** \brief the enumerate of the MC33907  out
 */
typedef enum
{
   MC33907_LinTransceiverMode_Sleep_NoWakeup=0,
   MC33907_LinTransceiverMode_ListenOnly,
   MC33907_LinTransceiverMode_Sleep_WakeUp,
   MC33907_LinTransceiverMode_Normal,
}MC33907_LinTransceiverMode;

/******************************************************************************
Exported Function Declarations
******************************************************************************/
extern void MC33907_InitChipPin(MC33907_ChipPin* ChipPin_Ptr);
extern void MC33907_ConfigureChip(MC33907_ChipConfig* ChipConfig_Ptr);
extern void MC33907_SetMode(MC33907_Mode Mode);
extern uint8 MC33907_SetVoutState(MC33907_Vout Vout,boolean SwitchState);
extern uint8 MC33907_GetVoutState(MC33907_Vout Vout,boolean* SwitchState);
extern void MC33907_ConfigureWTD(MC33907_WD_WindowDuration WD_WindowDuration);
extern void MC33907_ServiceWWD(void);
extern uint8 MC33907_GetIOState(MC33907_IO IO_Num,boolean* State);
extern uint8 MC33907_SetIOState(MC33907_IO IO_Num,boolean State);
extern uint8 MC33907_GetAMUXValue(MC33907_AMUX_Select AMUX_Select,float32* Value);
extern boolean MC33907_TroubleOccured(MC33907_Trouble Trouble);
extern MC33907_WakeUpEvent MC33907_GetWakeUpEvent(void);
extern void MC33907_Release_FS0B(void);
extern boolean MC33907_FS0B_LEVEL(void);
extern uint8   MC33907_GetCounterValue(MC33907_Counter Counter);
extern void MC33907_SetCanTransceiverMode(MC33907_CanTransceiverMode CanTransceiverMode);
extern void MC33907_SetLinTransceiverMode(MC33907_LinTransceiverMode LinTransceiverMode);
extern void MC33907_WriteRegister(MC33907_RegisterAddress RegAddr,uint8 RegData);
extern void MC33907_Task_ServiceWWD(void);
extern uint8 MC33907_ReadRegister(MC33907_RegisterAddress RegisterAddress);
#endif


