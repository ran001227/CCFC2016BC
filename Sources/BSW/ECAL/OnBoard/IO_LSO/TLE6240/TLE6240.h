/******************************************************************************
* Copyright (C),                                                       
* File name:         TLE6240.h                                                       
*   <Author>         <Version>        <Date>                                      
*   HXL              0.1              2015-6-1                        
* Description:       
                  
* Develop pack:      CodeWarrior                                       
* Function List:          
*   1. mcu_init                                                                  
* History:                
*   1. Date:         2015-6-1                                                                  
*      Author:       fzw          
*      Ver:          0.1                                                        
*      Modification: Create                                                       
*   2. ...         
*   Standards:                                                           
******************************************************************************/ 

/******************************************************************************
Includes
******************************************************************************/
#ifndef _TLE6240_H_
#define _TLE6240_H_

#include "bsw_typedefs.h"
#include "MCAL_GPIO.h"
#include "MCAL_SPI.h"
#include "MCAL_OPWM.h"
#include "MCAL_ADC.h"


/******************************************************************************
Public Constant Definitions
*******************************************************************************/
#define		TLE6240_CHIPNUM_MAX			(1)
#define 	TLE6240_CHIPCHANNEL_MAX		(16)

/******************************************************************************
Public Types Definitions
*******************************************************************************/

/** \brief the enumerate of the TLE6240_Mode
 */
typedef enum  
{
	TLE6240_01=0,
	
}TLE6240_ChipNum;

/** \brief Enumerate the Channels of SPI
 */
typedef enum 
{

	TLE6240_OUT01=0,
	TLE6240_OUT02,
	TLE6240_OUT03,
	TLE6240_OUT04,
	TLE6240_OUT05,
	TLE6240_OUT06,
	TLE6240_OUT07,
	TLE6240_OUT08,
	TLE6240_OUT09,
	TLE6240_OUT10,
	TLE6240_OUT11,
	TLE6240_OUT12,
	TLE6240_OUT13,
	TLE6240_OUT14,
	TLE6240_OUT15,
	TLE6240_OUT16
	
} TLE6240_OutChannel;

/** \brief the enumerate of the TLE6240_Mode
 */
typedef enum  
{
	TLE6240_ChipMode_Normal=0,
	TLE6240_ChipMode_Standby,
		
}TLE6240_ChipMode;

/** \brief the enumerate of the TLE6240_Mode
 */
typedef enum  
{
	TLE6240_PrgMode_ToGround,
	TLE6240_PrgMode_ToVs,
	TLE6240_PrgMode_ToGPIO,
		
}TLE6240_PrgMode;


/** \brief the Structure of the TLE6240 Pin 
 */
typedef struct
{
	Mcal_GPIO_Pin GPIO_IN[TLE6240_CHIPCHANNEL_MAX];
	Mcal_OPWM_Channel OPWM_IN[TLE6240_CHIPCHANNEL_MAX];
	const Mcal_OPWM_Pin* OPWMPinPtr_IN[TLE6240_CHIPCHANNEL_MAX];
	Mcal_Spi_Channel SPI_Channel;
	Mcal_Spi_CS	 SPI_CS;
	Mcal_Spi_MasterPin SPI_MasterPin;
	Mcal_GPIO_Pin GPIO_RESET;
	Mcal_GPIO_Pin GPIO_FAULT;
	TLE6240_PrgMode PrgMode;
	Mcal_GPIO_Pin GPIO_PRG;

}TLE6240_ChipPin;


/** \brief the enumerate of the TLE6240_Mode
 */
typedef enum  
{
	TLE6240_ControlMode_Parallel=0,
	TLE6240_ControlMode_Serial,
		
}TLE6240_ControlMode;


/** \brief the Structure of the TLE6240 Pin 
 */
typedef struct
{
	TLE6240_ControlMode ControlMode[TLE6240_CHIPCHANNEL_MAX];

}TLE6240_Configure;


/******************************************************************************
Exported Function Declarations                                                                  
******************************************************************************/
extern void  TLE6240_InitChip(TLE6240_ChipNum ChipNum,TLE6240_ChipPin	*ChipPin);
extern void  TLE6240_ConfChip(TLE6240_ChipNum ChipNum,TLE6240_Configure	*ChipConf);
extern void  TLE6240_SetMode(TLE6240_ChipNum ChipNum,TLE6240_ChipMode Mode);
extern void  TLE6240_SetPrgState(TLE6240_ChipNum ChipNum,boolean State);
extern void  TLE6240_InitChannel(TLE6240_ChipNum ChipNum,TLE6240_OutChannel OutChannel,boolean EnableOpwm);
extern void  TLE6240_SwitchType_SetState(TLE6240_ChipNum ChipNum,TLE6240_OutChannel OutChannel,boolean State);
extern void  TLE6240_OPWMType_SetParameter(TLE6240_ChipNum ChipNum,TLE6240_OutChannel OutChannel,uint32 Freq,uint32 Duty);
extern uint8 TLE6240_ReadDTC(TLE6240_ChipNum ChipNum,TLE6240_OutChannel OutChannel);

#endif
