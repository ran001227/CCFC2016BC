/***************************************************************************************
Copyright (c) ECO-EV Technologies Co., Ltd. 2017-2018. All rights reserved.

File name:		TLE4250.h
Author:			ECO-EV
Version:		V1.0.1
Date:			2017-09-21
Description:
Others:
History:

	1. Date:
	   Author:
	   Modification:
	2. ...
****************************************************************************************/

/******************************************************************************
Includes
******************************************************************************/
#ifndef _TLE4250_H_
#define _TLE4250_H_

#include "MCAL_GPIO.h"
#include "Mcal_ADC.h"

/** \brief the enumerate of the TLE4250
 */
typedef enum  
{
   TLE4250_ChipNum_1=0,
   TLE4250_ChipNum_2,
   TLE4250_ChipNum_3,
   TLE4250_ChipNum_4
}TLE4250_ChipNum;


/** \brief the structure of the TLE4250 chip pin
 */
typedef enum
{
   TLE4250_EN_ControlMode_GPIO,
   TLE4250_EN_ControlMode_Vcc,
}TLE4250_EN_ControlMode;


/** \brief the structure of the TLE4250 chip pin
 */
typedef struct
{
   TLE4250_EN_ControlMode EN_ControlMode;
   Mcal_GPIO_Pin GPIO_EN;
   boolean EnMeasure;
   Mcal_ADC_Channel Adc_Channel;
   Mcal_ADC_Pin* Pin_Ptr;
   float32 Ratio;       //PowerVoltage / MCU_Pin Voltage

}TLE4250_ChipPin;


/******************************************************************************
Public Constant Definitions
*******************************************************************************/
#define		TLE4250_CHIPNUM_MAX			(4)

/******************************************************************************
Exported Function Declarations                                                                  
******************************************************************************/
extern void TLE4250_InitChip(TLE4250_ChipNum ChipNum,TLE4250_ChipPin* ChipPin_Ptr);
extern void TLE4250_SetOut(TLE4250_ChipNum ChipNum,boolean OutStatus);
extern uint8 TLE4250_GetValue(TLE4250_ChipNum ChipNum,float32* PowerValue_Ptr);



#endif
