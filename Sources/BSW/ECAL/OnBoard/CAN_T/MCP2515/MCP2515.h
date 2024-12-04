/*
 * MCP2515.h
 *
 *  Created on: 2020Äê8ÔÂ3ÈÕ
 *      Author: LI
 */

#ifndef MCP2515_H_
#define MCP2515_H_

#include "MCAL_SPI.h"
/** \brief the structure of the MCP2515 chip pin
 */
typedef struct
{
   Mcal_Spi_Channel  SPI_Channel;
   Mcal_Spi_CS       SPI_CS;
   Mcal_Spi_MasterPin  SPI_MasterPin;

}MCP2515_ChipPin;

typedef enum
{
	MCP2515_ChipNum_1=0

}MCP2515_ChipNum;
/** \brief the enumerate of the MCP2515 Register
 */
typedef enum
{
   RXF0SIDH_ADR = 0x00,
   RXF0SIDL_ADR = 0x01,
   RXF0EID8_ADR = 0x02,
   RXF0EID0_ADR = 0x03,
   RXF1SIDH_ADR = 0x04,
   RXF1SIDL_ADR = 0x05,
   RXF1EID8_ADR = 0x06,
   RXF1EID0_ADR = 0x07,
   RXF2SIDH_ADR = 0x08,
   RXF2SIDL_ADR = 0x09,
   RXF2EID8_ADR = 0x0A,
   RXF2EID0_ADR = 0x0B,
   CANSTAT_ADR = 0x0E,
   CANCTRL_ADR = 0x0F,
   RXF3SIDH_ADR = 0x10,
   RXF3SIDL_ADR = 0x11,
   RXF3EID8_ADR = 0x12,
   RXF3EID0_ADR = 0x13,
   RXF4SIDH_ADR = 0x14,
   RXF4SIDL_ADR = 0x15,
   RXF4EID8_ADR = 0x16,
   RXF4EID0_ADR = 0x17,
   RXF5SIDH_ADR = 0x18,
   RXF5SIDL_ADR = 0x19,
   RXF5EID8_ADR = 0x1A,
   RXF5EID0_ADR = 0x1B,
   TEC_ADR = 0x1C,
   REC_ADR = 0x1D,
   RXM0SIDH_ADR = 0x20,
   RXM0SIDL_ADR = 0x21,
   RXM0EID8_ADR = 0x22,
   RXM0EID0_ADR = 0x23,
   RXM1SIDH_ADR = 0x24,
   RXM1SIDL_ADR = 0x25,
   RXM1EID8_ADR = 0x26,
   RXM1EID0_ADR = 0x27,
   CNF3_ADR = 0x28,
   CNF2_ADR = 0x29,
   CNF1_ADR = 0x2A,
   CANINTE_ADR = 0x2B,
   CANINTF_ADR = 0x2C,
   EFLG_ADR = 0x2D,
   TXB0CTRL_ADR = 0x30,
   TXB0SIDH_ADR = 0x31,
   TXB0SIDL_ADR = 0x32,
   TXB0EID8_ADR = 0x33,
   TXB0EID0_ADR = 0x34,
   TXB0DLC_ADR = 0x35,
   TXB0D0_ADR = 0x36,
   TXB0D1_ADR = 0x37,
   TXB0D2_ADR = 0x38,
   TXB0D3_ADR = 0x39,
   TXB0D4_ADR = 0x3A,
   TXB0D5_ADR = 0x3B,
   TXB0D6_ADR = 0x3C,
   TXB0D7_ADR = 0x3D,
   TXB1CTRL_ADR = 0x40,
   TXB1SIDH_ADR = 0x41,
   TXB1SIDL_ADR = 0x42,
   TXB1EID8_ADR = 0x43,
   TXB1EID0_ADR = 0x44,
   TXB1DLC_ADR = 0x45,
   TXB1D0_ADR = 0x46,
   TXB1D1_ADR = 0x47,
   TXB1D2_ADR = 0x48,
   TXB1D3_ADR = 0x49,
   TXB1D4_ADR = 0x4A,
   TXB1D5_ADR = 0x4B,
   TXB1D6_ADR = 0x4C,
   TXB1D7_ADR = 0x4D,
   TXB2CTRL_ADR = 0x50,
   TXB2SIDH_ADR = 0x51,
   TXB2SIDL_ADR = 0x52,
   TXB2EID8_ADR = 0x53,
   TXB2EID0_ADR = 0x54,
   TXB2DLC_ADR = 0x55,
   TXB2D0_ADR = 0x56,
   TXB2D1_ADR = 0x57,
   TXB2D2_ADR = 0x58,
   TXB2D3_ADR = 0x59,
   TXB2D4_ADR = 0x5A,
   TXB2D_ADR = 0x5B,
   TXB2D6_ADR = 0x5C,
   TXB2D7_ADR = 0x5D,
   RXB0CTRL_ADR = 0x60,
   RXB0SIDH_ADR = 0x61,
   RXB0SIDL_ADR = 0x62,
   RXB0EID8_ADR = 0x63,
   RXB0EID0_ADR = 0x64,
   RXB0DLC_ADR = 0x65,
   RXB0D0_ADR = 0x66,
   RXB0D1_ADR = 0x67,
   RXB0D2_ADR = 0x68,
   RXB0D3_ADR = 0x69,
   RXB0D4_ADR = 0x6A,
   RXB0D5_ADR = 0x6B,
   RXB0D6_ADR = 0x6C,
   RXB0D7_ADR = 0x6D,
   RXB1CTRL_ADR = 0x70,
   RXB1SIDH_ADR = 0x71,
   RXB1SIDL_ADR = 0x72,
   RXB1EID8_ADR = 0x73,
   RXB1EID0_ADR = 0x74,
   RXB1DLC_ADR = 0x75,
   RXB1D0_ADR = 0x76,
   RXB1D1_ADR = 0x77,
   RXB1D2_ADR = 0x78,
   RXB1D3_ADR = 0x79,
   RXB1D4_ADR = 0x7A,
   RXB1D5_ADR = 0x7B,
   RXB1D6_ADR = 0x7C,
   RXB1D7_ADR = 0x7D,

}MCP2515_RegisterAddress;

/** \brief the enumerate of the MCP2515 Mode
 */
typedef enum
{
	MCP2515_MODE_NORMAL = 0x00,
	MCP2515_MODE_SLEEP = 0x20,
	MCP2515_MODE_LOOPBACK = 0x40,
	MCP2515_MODE_LISTENONLY = 0x60,
	MCP2515_MODE_CONFIG = 0x80,

}MCP2515_Mode;

/** \brief the enumerate of the MCP2515 SPI Command
 */
typedef enum
{
	SPI_Write = 0x02,
	SPI_Read = 0x03,
	SPI_Write_Tx = 0x40,
	SPI_Bit_Modify = 0x05,
	SPI_RTS_TXB0 = 0x81,
	SPI_RTS_TXB1 = 0x82,
	SPI_RTS_TXB2 = 0x83,
	SPI_Read_Rx = 0x90,
	SPI_Read_Status = 0xA0,
	SPI_Rx_Status = 0xB0,
	SPI_Reset = 0xC0,

}MCP2515_SPI_Command;

typedef struct
{

    uint32	  	Id;              /**< \brief CAN message ID */
    uint8 		DataLength;      /**< \brief CAN message data length code */
    uint8     	Data[8];         /**< \brief CAN message data */
    uint8		Remote;
    uint8		Extend;
} MCP2515_CAN_Frame;

extern void MCP2515_InitChipPin(MCP2515_ChipPin* ChipPin_Ptr);
extern void MCP2515_Init(uint32 BaudRate);
extern uint8 MCP2515_CAN_ReceiveData(MCP2515_CAN_Frame *RxFrame);
extern uint8 MCP2515_CAN_SendData(MCP2515_CAN_Frame *TxFrame);
extern void MCP2515_Check(void);

#endif /* MCP2515_H_ */
