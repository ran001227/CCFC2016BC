/*
 * INA226.h
 *
 *  Created on: 2019Äê9ÔÂ16ÈÕ
 *      Author: LI
 */

#ifndef _INA226_H_
#define _INA226_H_

#include "bsw_typedefs.h"
#include "MCAL_GPIO.h"
#include "MCAL_I2C.h"

#define		INA226_CHIPNUM_MAX			(4)

/** \brief the enumerate of the INA226_ChipNum
 */
typedef enum
{
	INA226_ChipNum_01=0,
	INA226_ChipNum_02=1,
	INA226_ChipNum_03=2,
	INA226_ChipNum_04=3
}INA226_ChipNum;

/** \brief the enumerate of the INA226 slave address
 */
typedef enum
{
	INA226_Addr_01=0x40,  //U705 A1-GND,A0-GND
	INA226_Addr_02=0x41,  //U707 A1-GND,A0-VS
	INA226_Addr_03=0x44,  //U708 A1-VS,A0-GND
	INA226_Addr_04=0x45   //U710 A1-VS,A0-VS
}INA226_Address;

/** \brief the enumerate of the INA226 write or read operation
 */
typedef enum
{
	INA226_Operation_Write=0,
	INA226_Operation_Read=1
}INA226_Operation_Command;

/** \brief the enumerate of the INA226 register
 */
typedef enum
{
	INA226_Conf_REG=0x00,   //All-register reset, shunt voltage and bus voltage ADC conversion times and averaging, operating mode.
	INA226_ShVolt_REG=0x01,   //Shunt voltage measurement data.
	INA226_BusVolt_REG=0x02,   //Bus voltage measurement data.
	INA226_Pwr_REG=0x03,   //Contains the value of the calculated power being delivered to the load.
	INA226_Cur_REG=0x04,   //Contains the value of the calculated current flowing through the shunt resistor.
	INA226_Cal_REG=0x05,   //Sets full-scale range and LSB of current and power measurements. Overall system calibration.
	INA226_Msk_EN_REG=0x06,   //Alert configuration and Conversion Ready flag.
	INA226_AL_REG=0x07,   //Contains the limit value to compare to the selected Alert function.
	INA226_ManID_REG=0xFE,   //Contains unique manufacturer identification number.
	INA226_DieID_REG=0xFF,   //Contains unique die identification number.
}INA226_Register;

/** \brief the Structure of the INA226 Pin
 */
typedef struct
{
	Mcal_GPIO_Pin GPIO_Alert;
	Mcal_GPIO_Pin GPIO_SDA;
	Mcal_GPIO_Pin GPIO_SCL;
}INA226_ChipPin;

typedef enum
{
	INA226_AVG_1=0,
	INA226_AVG_4,
	INA226_AVG_16,
	INA226_AVG_64,
	INA226_AVG_128,
	INA226_AVG_256,
	INA226_AVG_512,
	INA226_AVG_1024
}INA226_Sample_Num;

typedef enum
{
	INA226_ConvTime_140us=0,
	INA226_ConvTime_204us,
	INA226_ConvTime_332us,
	INA226_ConvTime_588us,
	INA226_ConvTime_1100us,
	INA226_ConvTime_2116us,
	INA226_ConvTime_4156us,
	INA226_ConvTime_8244us
}INA226_ConversionTime;

extern void INA226_InitChip(INA226_ChipNum ChipNum,INA226_ChipPin *ChipPin);
extern void INA226_Init(INA226_ChipNum ChipNum,INA226_Sample_Num AVG,INA226_ConversionTime time);
extern INA226_Address INA226_GetAddress(INA226_ChipNum ChipNum);
extern void INA226_WriteData(INA226_ChipNum ChipNum,INA226_Register reg,uint16 data);
extern uint16 INA226_ReadData(INA226_ChipNum ChipNum);
extern void INA226_SetRegPointer(INA226_ChipNum ChipNum,INA226_Register reg);
extern uint16 INA226_Get_Current(INA226_ChipNum ChipNum);
extern uint16 INA226_Get_ShuntVoltage(INA226_ChipNum ChipNum);


#endif /* _INA226_H_ */
