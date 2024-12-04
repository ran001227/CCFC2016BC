/*
 * TJA1145.h
 *
 *  Created on: 2018Äê4ÔÂ24ÈÕ
 *      Author: dalad
 */
#ifndef _TJA1145_H_
#define _TJA1145_H_

#include "MCAL_SPI.h"
#include "MCAL_GPIO.h"
#include "typedefs.h"


/** \brief the enumerate of the TJA1043T_Mode
 */
typedef enum
{
   TJA1145_ChipNum_1=0,
}TJA1145_ChipNum;


/** \brief the enumerate of the mode of TJA1145
 */
typedef enum
{
   TJA1145_Mode_Sleep = 1,
   TJA1145_Mode_Standby = 4,
   TJA1145_Mode_Normal = 7,
}TJA1145_Mode;

/** \brief the enumerate of the local wake mode of TJA1145
 */
typedef enum
{
   TJA1145_LocalWakeMode_Disable = 0,
   TJA1145_LocalWakeMode_FallingEdge = 1,
   TJA1145_LocalWakeMode_RrisingEdge = 2,
   TJA1145_LocalWakeMode_AllEdge = 3
}TJA1145_LocalWakeMode;

/** \brief the enumerate of the local wake mode of TJA1145
 */
typedef enum
{
   TJA1145_RemoteWakeMode_Disable = 0,
   TJA1145_RemoteWakeMode_Unselective = 1,
   TJA1145_RemoteWakeMode_Selective = 2

}TJA1145_RemoteWakeMode;

/** \brief the enumerate of the CAN mode of TJA1145
 */
typedef enum
{
   TJA1145_CAN_Offline,
   TJA1145_CAN_Active_undervoltage,
   TJA1145_CAN_Active,
   TJA1145_Listen_Only
}TJA1145_CANMode;

/** \brief the structure of the CAN Baud rate
 */
typedef enum
{
   bit_50k = 0,
   bit_100k = 1,
   bit_125k = 2,
   bit_250k = 3,
   bit_500k = 5,
   bit_1000k = 7,
}TJA1145_WakeUp_BaudRate;

/** \brief the structure of the remote-wake configure of TJA1145
 */
typedef struct
{
   TJA1145_RemoteWakeMode    Mode;
   TJA1145_WakeUp_BaudRate   BaudRate;         //only 50k,100k,125k,250k,500k,1000k  valid
   boolean     Extend;
   uint32      Id;
   uint32      IdMask;
   boolean     EvaluateData;				//data length code and data field are evaluated at wake-up
   uint8       DLC;
   uint8     DataMask[8];
} TJA1145_RemoteWakeConf;

/** \brief the structure of the TJA1145 chip pin
 */
typedef struct
{
   Mcal_Spi_CS SPI_CS;
   Mcal_Spi_Channel  SPI_Channel;
   Mcal_Spi_MasterPin SPI_MasterPin;
//   Mcal_Spi_MasterPin SPI_CsPin;
   Mcal_GPIO_Pin GPIO_VIO;
}TJA1145_ChipPin;

#define     TJA1145_MAXNUM    (1)

/******************************************************************************
Exported Function Declarations
******************************************************************************/
extern void          TJA1145_InitChipPin(TJA1145_ChipNum ChipNum,TJA1145_ChipPin* ChipPin_Ptr);


extern void          TJA1145_EnableWriteProtection(TJA1145_ChipNum ChipNum);
extern void          TJA1145_DisableWriteProtection(TJA1145_ChipNum ChipNum);
extern uint8         TJA1145_ChangeMode(TJA1145_ChipNum ChipNum,TJA1145_Mode Mode);
extern void          TJA1145_SetCANMode(TJA1145_ChipNum ChipNum,TJA1145_CANMode Mode);
extern TJA1145_Mode  TJA1145_GetMode(TJA1145_ChipNum ChipNum);
extern void          TJA1145_SetLocalWakeMode(TJA1145_ChipNum ChipNum,TJA1145_LocalWakeMode Mode);
extern void          TJA1145_ConfigureRemoteWake(TJA1145_ChipNum ChipNum,TJA1145_RemoteWakeConf* Config_Ptr);

extern uint8         TJA1145_Identification(TJA1145_ChipNum ChipNum);

#endif

