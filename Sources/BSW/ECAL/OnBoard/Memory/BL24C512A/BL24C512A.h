/*
 * BL24C512A.h
 *
 *  Created on: Aug 19, 2024
 *      Author: Yu
 */

#ifndef BL24C512A_H_
#define BL24C512A_H_

#include "Mcal_I2C.h"
#include "Mcal_GPIO.h"


typedef enum
{
	BL24C512A_ChipNum_U01
}BL24C512A_ChipNum;

typedef struct
{
	Mcal_GPIO_Pin 		SDA;
	Mcal_GPIO_Pin		SCL;
}BL24C512A_ChipPin;

typedef struct
{
	uint8 Device_W_addr;
	uint8 Device_R_addr;
	uint8 First_w_addr;
	uint8 Sed_W_addr;
}Address;
typedef enum
{
	BL24C512A_WriteProtectLength_None=0,
	BL24C512A_WriteProtectLength_HighQuarter,
	BL24C512A_WriteProtectLength_HighHalf,
	BL24C512A_WriteProtectLength_All
} BL24C512A_WriteProtectLength;

/** \List the error enum of the EEPROM
 */
typedef enum
{
	BL24C512A_Error_None=0,
	BL24C512A_Error_WriteInProcess=1,
	BL24C512A_Error_OutOfRange=2,

} BL24C512A_ErrorState;
typedef struct
{
	BL24C512A_ChipPin   ChipConfigure;
}BL24C512A_ChipStruct;
#define		BL24C512A_CHIPNUM_MAX			(1)
#define		BL24C512A_BYTELENGTH_MAX		(512*128)
#define 	BL24C512A_BYTE_PAGESIZE			(128)
extern void BL24C512A_I2C_WriteData(Address addr,uint8 DATA);
//extern void BL24C512A_I2C_ReadData(uint8 I2C_addr_W,uint8 reg_addr,uint8 I2C_addr_R,uint8 Ack_Data);
extern uint8 BL24C512A_I2C_ReadData(Address addr);

extern void Master_Transmit(uint8 slaveAddr);
extern void Master_Receive(uint8 slaveAddr);
extern void Slave_Transmit(uint8 slaveAddr);
extern void Slave_Receive(uint8 slaveAddr);
#endif /* BL24C512A_H_ */
