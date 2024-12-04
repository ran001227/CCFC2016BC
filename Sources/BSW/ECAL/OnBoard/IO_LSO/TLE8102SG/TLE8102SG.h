/******************************************************************************
* Copyright (C),                                                       
* File name:         TLE8102SG.h                                                       
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
#ifndef _TLE8102SG_H_
#define _TLE8102SG_H_

#include "typedefs.h"
#include "MCAL_GPIO.h"
#include "MCAL_SPI.h"
#include "MCAL_OPWM.h"
#include "MCAL_ADC.h"


/******************************************************************************
Public Types Definitions
*******************************************************************************/

/** \brief the enumerate of the TLE8102SG_Mode
 */
typedef enum  
{
	TLE8102SG_01=0,
	TLE8102SG_02
	
}TLE8102SG_ChipNum;

/** \brief Enumerate the Channels of SPI
 */
typedef enum 
{
	TLE8102SG_OUT1=0,
	TLE8102SG_OUT2=1,

} TLE8102SG_OutChannel;


/** \brief the Structure of the MonitorChip_ChipConfig
 */
typedef struct
{
	Mcal_GPIO_Pin GPIO_IN[2];
	Mcal_OPWM_Channel OPWM_IN[2];
	const Mcal_OPWM_Pin* OPWM_PinPtr[2];
	Mcal_Spi_Channel SPI_Channel;
	Mcal_Spi_CS	 SPI_CS;
	Mcal_Spi_MasterPin SPI_MasterPin;
	Mcal_ADC_Channel ADC_CO1;
	const Mcal_ADC_Pin* ADC_Pin_Ptr;
	Mcal_GPIO_Pin GPIO_CO1;
	Mcal_GPIO_Pin GPIO_CO2;	
	boolean OutState[2];
}TLE8102SG_ChipPin;

/** \brief the Structure of the MonitorChip_ChipConfig
 */
typedef enum 
{
	TLE8102SG_CurrentLimit1=0,		//6.5A,Current limitation
	TLE8102SG_CurrentLimit2,		//10.5A,Overload switch off
}TLE8102SG_CurrentLimit;

/** \brief the Structure of the MonitorChip_ChipConfig
 */
typedef enum 
{
	TLE8102SG_SlewRate1=0,		//5V/us
	TLE8102SG_SlewRate2,		//1V/us
}TLE8102SG_SlewRate;


/** \brief the Structure of the MonitorChip_ChipConfig
 */
typedef enum 
{
	TLE8102SG_OverTemperatureBehavior_Autorestart=0,		//6.5A,Current limitation
	TLE8102SG_OverTemperatureBehavior_Shutdown,		//10.5A,Overload switch off
}TLE8102SG_OverTemperatureBehavior;

/** \brief Enumerate the Pin Mode of CO1
 */
typedef enum 
{
	TLE8102SG_DiagnosisOutputForm_ST=0,		//Diagnosis output with one status output per channel (ST1, ST2)
	TLE8102SG_DiagnosisOutputForm_Fault,	//Diagnosis output with SPI interface (SO) and fault pin / current sense
}TLE8102SG_DiagnosisOutputForm;

/** \brief Enumerate the Pin Mode of CO1
 */
typedef enum 
{
	TLE8102SG_OutControl_ParallelOnly = 0b00,		
	TLE8102SG_OutControl_OperationOR = 0b01,
	TLE8102SG_OutControl_OperationAnd = 0b10,		
	TLE8102SG_OutControl_SerialOnly = 0b11,		
}TLE8102SG_OutControl;


/** \brief Enumerate the Pin Mode of CO1
 */
typedef enum 
{
	TLE8102SG_CO1_Function_Fault = 0b00,
	TLE8102SG_CO1_Function_CurrentSense1 = 0b01,
	TLE8102SG_CO1_Function_CurrentSense2 = 0b10,
	TLE8102SG_CO1_Function_CurrentSense12 = 0b11,
} TLE8102SG_CO1_Function;


/** \brief the Structure of the MonitorChip_ChipConfig
 */
typedef struct
{
	TLE8102SG_CurrentLimit  OutCurrentLimit[2];
	TLE8102SG_SlewRate  SlewRate[2];
	TLE8102SG_OverTemperatureBehavior  OverTemperatureBehavior;
	TLE8102SG_DiagnosisOutputForm  DiagnosisOutputForm;
	TLE8102SG_OutControl  OutControl;
	TLE8102SG_CO1_Function  CO1_Function;
	
}TLE8102SG_Configure;


#define		TLE8102SG_CHIPNUM_MAX			(1)
#define 	TLE8102SG_CHIPCHANNEL_MAX		(2)


/******************************************************************************
Exported Function Declarations                                                                  
******************************************************************************/
extern void  TLE8102SG_InitChip(TLE8102SG_ChipNum ChipNum,TLE8102SG_ChipPin	*ChipPin);
extern void  TLE8102SG_ConfigChip(TLE8102SG_ChipNum ChipNum,TLE8102SG_Configure	*ChipConfigure);
extern void  TLE8102SG_InitChannel(TLE8102SG_ChipNum ChipNum,TLE8102SG_OutChannel OutChannel,boolean EnableOpwm);
extern void  TLE8102SG_SwitchType_SetState(TLE8102SG_ChipNum ChipNum,TLE8102SG_OutChannel OutChannel,boolean State);
extern void  TLE8102SG_OPWMType_SetParameter(TLE8102SG_ChipNum ChipNum,TLE8102SG_OutChannel OutChannel,uint32 Freq,uint32 Duty);
extern uint8 TLE8102SG_ReadDTC(TLE8102SG_ChipNum ChipNum,TLE8102SG_OutChannel OutChannel);

extern uint16 TLE8102SG_GetCurrent(TLE8102SG_ChipNum ChipNum,TLE8102SG_OutChannel OutChannel);		//mA


#endif
