/******************************************************************************
*	Copyright (c) ECO-EV Technologies Co., Ltd. 2015-2016.
*	All rights reserved.

*	File name:		FS6500.h
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

#ifndef __FS6500_H__
#define __FS6500_H__


#include "typedefs.h"
#include "MCAL_SPI.h"
#include "MCAL_GPIO.h"
#include "MCAL_ADC.h"

/** \brief the structure of the FS6500 chip pin
 */
typedef struct
{
   Mcal_Spi_Channel  SPI_Channel;
   Mcal_Spi_CS       SPI_CS;
   Mcal_Spi_MasterPin  SPI_MasterPin;

   Mcal_GPIO_Pin GPIO_FS0B;
   Mcal_ADC_Channel ADC_MUX;
   Mcal_ADC_Pin ADCPin_Ptr;
}FS6500_ChipPin;


/** \brief the enumerate of the FS6500 watch dog window duration
 */
typedef enum
{

   FS6500_WD_WindowDuration_Disable,
   FS6500_WD_WindowDuration_1ms,
   FS6500_WD_WindowDuration_2ms,
   FS6500_WD_WindowDuration_3ms,
   FS6500_WD_WindowDuration_4ms,
   FS6500_WD_WindowDuration_6ms,
   FS6500_WD_WindowDuration_8ms,
   FS6500_WD_WindowDuration_12ms,
   FS6500_WD_WindowDuration_16ms,
   FS6500_WD_WindowDuration_24ms,
   FS6500_WD_WindowDuration_32ms,
   FS6500_WD_WindowDuration_64ms,
   FS6500_WD_WindowDuration_128ms,
   FS6500_WD_WindowDuration_256ms,
   FS6500_WD_WindowDuration_512ms,
   FS6500_WD_WindowDuration_1024ms

}FS6500_WD_WindowDuration;         //watch dog window duration


/** \brief the enumerate of the FS6500's maximum value of the WD error counter
 */
typedef enum
{
   FS6500_WD_MaxErrorCounter_6 = 1,
   FS6500_WD_MaxErrorCounter_4,
   FS6500_WD_MaxErrorCounter_2
}FS6500_WD_MaxErrorCounter;


/** \brief the enumerate of the FS6500's maximum value of the WD refresh counter
 */
typedef enum
{
   FS6500_WD_MaxRefreshCounter_6,
   FS6500_WD_MaxRefreshCounter_4,
   FS6500_WD_MaxRefreshCounter_2,
   FS6500_WD_MaxRefreshCounter_1
}FS6500_WD_MaxRefreshCounter;


/** \brief the enumerate of the FS6500's maximum value of the fault error counter

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
   FS6500_FLT_MaxCounter_6,      //FLT_ERR_FS = 0/Intermediate = 3; Final = 6
   FS6500_FLT_MaxCounter_2       //FLT_ERR_FS = 1/Intermediate = 1; Final = 2
}FS6500_FLT_MaxCounter;


/** \brief the enumerate of the FS6500's counter
 */
typedef enum
{
   FS6500_Conuter_WDError,
   FS6500_Conuter_WDRefresh,
   FS6500_Conuter_FLT
}FS6500_Counter;


/** \brief the enumerate of the FS6500's selection of AMUX
 */
typedef enum
{
   FS6500_AMUX_Select_Vref,
   FS6500_AMUX_Select_Wide_Vsns,
   FS6500_AMUX_Select_Wide_IO0,
   FS6500_AMUX_Select_Wide_IO5,
   FS6500_AMUX_Select_Tight_Vsns,
   FS6500_AMUX_Select_Tight_IO0,
   FS6500_AMUX_Select_Tight_IO5,
   FS6500_AMUX_Select_Temperature

}FS6500_AMUX_Select;


/** \brief the enumerate of the FS6500 IOWakeUpStyle
 */
typedef enum
{
   FS6500_IOWakeUpStyle_Disble = 0,
   FS6500_IOWakeUpStyle_RisingEdgeOrHighLevel = 1,
   FS6500_IOWakeUpStyle_FallingEdgeOrLowLevel = 2,
   FS6500_IOWakeUpStyle_AnyEdge = 3
}FS6500_IOWakeUpStyle;

/** \brief the enumerate of the FS6500 IOWakeUpStyle
 */
typedef enum
{
   FS6500_LDT_Function1 = 0,
   FS6500_LDT_Function2,
   FS6500_LDT_Function3,
   FS6500_LDT_Function4,
   FS6500_LDT_Function5
}FS6500_LDT_Function;


/** \brief the structure of the FS6500 configure
 */
typedef struct
{
   boolean EnCanWakeUp;
   boolean EnLinWakeUp;
   boolean EnOut_IO4;
   boolean EnVKAM;
   boolean EnFCCU;
   FS6500_IOWakeUpStyle WakeUpStyle_IO0;
   FS6500_WD_WindowDuration WD_WindowDuration;
   FS6500_WD_MaxErrorCounter WD_MaxErrorCounter;
   FS6500_WD_MaxRefreshCounter MaxRefreshCounter;
   FS6500_FLT_MaxCounter FLT_MaxCounter;
}FS6500_ChipConfig;

/** \brief the structure of the FS6500 configure
 */
typedef enum
{
   FS6500_IO0,
   FS6500_IO2,
   FS6500_IO3,
   FS6500_IO4,
   FS6500_IO5,
   FS6500_FS0B,
   FS6500_FS1B,
   FS6500_RESET
}FS6500_IO;

/** \brief the enumerate of the FS6500 operation mode
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
   //VBATTERY
   FS6500_Trouble_VSNS_UV,        // Detection of VBATTERY below 8.5 V
   FS6500_Trouble_VSUP_UV_7,      //Detection of VSUP below 7.0 V (after reverse current protection diode)
   FS6500_Trouble_IPFF,           //Input power feed forward. Based on VSUP and IPRE_PEAK

   //VPRE
   FS6500_Trouble_ILIM_PRE,       //Pre-regulator current limitation
   FS6500_Trouble_TWARN_PRE,      //Temperature warning on the pass transistor
   FS6500_Trouble_VPRE_OV,        //Report a VPRE over voltage detection
   FS6500_Trouble_VPRE_UV,        //Report a VPRE under voltage detection

   //VCORE
   FS6500_Trouble_TWARN_CORE,     //Temperature warning on the pass transistor
   FS6500_Trouble_VCORE_OV,       //Report a VCORE over voltage detection
   FS6500_Trouble_VCORE_UV,       //Report a VCORE under voltage detection

   //VCCA
   FS6500_Trouble_ILIM_CCA,       //VCCA current limitation
   FS6500_Trouble_ILIM_CCA_OFF,   //Current limitation maximum duration expiration. Only used when external PNP connected.
   FS6500_Trouble_TWARN_CCA,      //Temperature warning on the pass transistor (internal pass transistor only)
   FS6500_Trouble_TSDVCCA,        //Temperature shutdown of the VCCA
   FS6500_Trouble_VCCA_OV,        //Report a VCCA over voltage detection
   FS6500_Trouble_VCCA_UV,        //Report a VCCA under voltage detection

   //VAUX
   FS6500_Trouble_ILIM_AUX,       //VAUX current limitation
   FS6500_Trouble_ILIM_AUX_OFF,   //Current limitation maximum duration expiration. Only used when external PNP connected.
   FS6500_Trouble_TSDVAUX,        //Temperature shutdown of the VAUX
   FS6500_Trouble_VAUX_OV,        //Report a VAUX over voltage detection
   FS6500_Trouble_VAUX_UV,        //Report a VAUX under voltage detection

   //VCAN
   FS6500_Trouble_ILIM_CAN,       //VCAN current limitation
   FS6500_Trouble_VCAN_OV,        //Report a VCAN over voltage detection
   FS6500_Trouble_TSDCAN,         //Temperature shutdown on the pass transistor. Auto restart when TJ < (TSDCAN ¨C TSDCAN_HYST).
   FS6500_Trouble_VCAN_UV,        //Report a VCAN under voltage detection

   //CAN Transceiver
   FS6500_Trouble_CAN_OT,         //CAN over temperature detection
   FS6500_Trouble_RXD_REC,        //CAN RXD recessive clamping detection (short-circuit to 5.0 V)
   FS6500_Trouble_TXD_DOM,        //CAN TXD dominant clamping detection (short-circuit to GND)
   FS6500_Trouble_CAN_DOM,        //CAN bus dominant clamping detection

   //LIN Transceiver
   FS6500_Trouble_LIN_OT,         //LIN over temperature detection
   FS6500_Trouble_RXDL_REC,       //LIN RXDL recessive clamping detection (short to high)
   FS6500_Trouble_TXDL_DOM,       //LIN TXDL dominant clamping detection (short to GND)
   FS6500_Trouble_LIN_DOM,        //LIN bus dominant clamping detection

   //SPI
   FS6500_Trouble_SPI_ERR,        //Secured SPI communication check
   FS6500_Trouble_SPI_CLK,        //Report a wrong number of CLK pulse different than 16 during the NCS low pulse in main state machine
   FS6500_Trouble_SPI_REQ,        //Invalid SPI access (wrong write or read, write to INIT registers in normal mode, wrong address)
   FS6500_Trouble_SPI_PARITY      //Report a parity error in main state machine

}FS6500_Trouble;

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
}Command_tag;

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
}CAN_LIN_MODE;

typedef union
{
   uint8 R;
   struct
   {
      uint8 IO_OUT_4_EN     :1;
      uint8 IO_OUT_4        :1;
      uint8 RESERVED        :3;
      uint8 AMUX            :3;
   }B;
}IO_OUT_AMUX;


typedef union
{
   uint8 R;
   struct
   {
      uint8 F2F0            :3;
      uint8 REG_SE          :1;
      uint8 LDT_RUNNING     :1;
      uint8 MODE            :1;
      uint8 LDT_ENABLE      :1;
      uint8 LDT_INT         :1;
   }B;
}LONG_DURATION_TIMER;

typedef union
{
   uint8 R;
   struct
   {
      uint8 WD_WINDOW       :4;
      uint8 SECURE          :4;
   }B;
}WD_WINDOW;

typedef union
{
   uint8 R;
   struct
   {
      uint8 WD_CNT_ERR      :2;
      uint8 WD_CNT_RFR      :2;
      uint8 SECURE          :4;
   }B;
}INIT_WD_CNT;

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
}WD_COUNTER;


/** \brief the enumerate of the FS6500 operation mode
 */
typedef enum
{
   FS6500_WakeUpEvent_Null = 0,
   FS6500_WakeUpEvent_IO0 = 1,
   FS6500_WakeUpEvent_IO2,
   FS6500_WakeUpEvent_IO3,
   FS6500_WakeUpEvent_IO4,
   FS6500_WakeUpEvent_IO5,
   FS6500_WakeUpEvent_CAN,
   FS6500_WakeUpEvent_LIN,
   FS6500_WakeUpEvent_Timer,
   FS6500_WakeUpEvent_AUTO

}FS6500_WakeUpEvent;

/** \brief the enumerate of the FS6500 operation mode
 */
typedef enum
{
   FS6500_Mode_Normal,
   FS6500_Mode_LPOFF_Sleep,
   FS6500_Mode_LPOFF_AutoWU,
   FS6500_Mode_LPOFF_DeepFS
}FS6500_Mode;

/** \brief the enumerate of the FS6500 voltage out
 */
typedef enum
{
   FS6500_Vout_VPRE,
   FS6500_Vout_VCORE,
   FS6500_Vout_VCCA,
   FS6500_Vout_VAUX,
   FS6500_Vout_VCAN,
   FS6500_Vout_VKAM
}FS6500_Vout;

/** \brief the enumerate of the FS6500 voltage out
 */
typedef enum
{
   FS6500_RELEASE_FS0B,
   FS6500_RELEASE_FS1B,
   FS6500_RELEASE_FS0B_FA1B
}FS6500_FSxB;

/** \brief the enumerate of the FS6500  out
 */
typedef enum
{
   FS6500_CanTransceiverMode_Sleep_NoWakeup=0,
   FS6500_CanTransceiverMode_ListenOnly,
   FS6500_CanTransceiverMode_Sleep_WakeUp,
   FS6500_CanTransceiverMode_Normal,
}FS6500_CanTransceiverMode;


/** \brief the enumerate of the FS6500  out
 */
typedef enum
{
   FS6500_LinTransceiverMode_Sleep_NoWakeup=0,
   FS6500_LinTransceiverMode_ListenOnly,
   FS6500_LinTransceiverMode_Sleep_WakeUp,
   FS6500_LinTransceiverMode_Normal,
}FS6500_LinTransceiverMode;

/******************************************************************************
Exported Function Declarations
******************************************************************************/
extern void FS6500_InitChipPin(FS6500_ChipPin* ChipPin_Ptr);
extern void FS6500_ConfigureChip(FS6500_ChipConfig* ChipConfig_Ptr);
extern void FS6500_SetMode(FS6500_Mode Mode);
extern uint8 FS6500_SetVoutState(FS6500_Vout Vout,boolean SwitchState);
extern uint8 FS6500_GetVoutState(FS6500_Vout Vout,boolean* SwitchState);

extern void FS6500_ConfigureWTD(FS6500_WD_WindowDuration WD_WindowDuration);
extern void FS6500_ServiceWWD(void);
extern void  FS6500_SetLDT(FS6500_LDT_Function Functino,uint32 AfterRunValue,uint32 WakeUpValue);
extern uint8 FS6500_GetLDTValue(uint32* LDT_Value_Ptr);
extern uint8 FS6500_GetIOState(FS6500_IO IO_Num,boolean* State);
extern uint8 FS6500_SetIOState(FS6500_IO IO_Num,boolean State);
extern uint8 FS6500_GetAMUXValue(FS6500_AMUX_Select AMUX_Select,float32* Value);
extern boolean FS6500_TroubleOccured(FS6500_Trouble Trouble);
extern FS6500_WakeUpEvent FS6500_GetWakeUpEvent(void);
extern uint8 FS6500_Release_FSxB(FS6500_FSxB FSxB);
extern void FS6500_VAUX_DIAG(void);
extern boolean FS6500_FS0B_LEVEL(void);
extern uint8   FS6500_GetCounterValue(FS6500_Counter Counter);
extern void FS6500_SetCanTransceiverMode(FS6500_CanTransceiverMode CanTransceiverMode);
extern void FS6500_SetLinTransceiverMode(FS6500_LinTransceiverMode LinTransceiverMode);
extern void FS6500_Task_ServiceWWD(void);
#endif


