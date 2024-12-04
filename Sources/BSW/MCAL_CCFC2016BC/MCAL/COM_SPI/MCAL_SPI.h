/*************************************************************
Copyright (c) ECO-EV Technologies Co., Ltd. 2015-2016. 
All rights reserved.

File name:		CAN.h
Author:			ECO-EV
Version:		V1.0.1
Date:			2016-10-24
Description:
Others:
History:

	1. Date:
	   Author:
	   Modification:
	2. ...
**************************************************************/

#ifndef _SPI_H
#define _SPI_H

#include "bsw_typedefs.h"

/** \brief Enumerate the Channels of SPI
 */
typedef enum 
{
	Mcal_Spi0=0,
	Mcal_Spi1=1,
	Mcal_Spi2=2,
//	Mcal_Spi3=3
} Mcal_Spi_Channel;

/** \brief the structure of SPI pin */
typedef  struct
{
	Mcal_PortPin_In Mrst;
	Mcal_PortPin_Out Mtsr;
	Mcal_PortPin_Out Sclk;
	Mcal_PortPin_Out CsPin;
} Mcal_Spi_MasterPin;

/** \brief Enumerate the CS of SPI
 */
typedef enum
{
	Mcal_Spi_CS0=0,
//	Mcal_Spi_CS1,
//	Mcal_Spi_CS2,
//	Mcal_Spi_CS3,
//	Mcal_Spi_CS4,
//	Mcal_Spi_CS5,

} Mcal_Spi_CS;

/** \brief Enumerate the level of CLK initialization.
 */
typedef enum 
{
	Mcal_Spi_ClockPolarity_IdleLow=0,
	Mcal_Spi_ClockPolarity_IdleHigh
} Mcal_Spi_ClockPolarity;

/** \brief Enumerate the edge of SCK when Data is shift.
 */
typedef enum 
{
	Mcal_Spi_ClockPhase_CaptureOnLeadingEdge_ShiftOnFollowingEdge=0,
	Mcal_Spi_ClockPhase_ShiftOnLeadingEdge_CaptureOnFollowingEdge,
} Mcal_Spi_ClockPhase;

/** \brief Enumerate bit Order.
 */
typedef enum
{
	Mcal_Spi_BitOrder_MsbFirst=0,
	Mcal_Spi_BitOrder_LsbFirst
} Mcal_Spi_BitOrder;

typedef enum
{
	Mcal_Spi_CsIdle_Low = 0,
	Mcal_Spi_CsIdle_High,
} Mcal_Spi_CsIdle;

/** \brief the Structure of the SPI Frame
 */
typedef struct
{
	uint32 					Baudrate;			//range 250KHz 500KHz 1MHz 2MHz 4MHz
	uint8 					FrameSize;			//range 4-16
	Mcal_Spi_ClockPolarity 	ClockPolarity;
	Mcal_Spi_ClockPhase		ClockPhase;
	Mcal_Spi_BitOrder       BitOrder;
	Mcal_Spi_CsIdle         CsIdle;
	Mcal_Spi_CS             CsCh;
}Mcal_Spi_Configure;

/******************************************************************************
public symbol Definitions
******************************************************************************/
#define		MCAL_SPI_CHANNELNUM_MAX			(3)
#define		MCAL_SPI_CTARNUM_MAX				(3)

/******************************************************************************
_PinMap_SPI
******************************************************************************/
extern const Mcal_PortPin_In  DSPI0_SIN_PA12_IN;
extern const Mcal_PortPin_Out DSPI0_SOUT_PA13_OUT;
extern const Mcal_PortPin_Out DSPI0_SCK_PA14_OUT;
extern const Mcal_PortPin_Out DSPI0_CS0_PA15_OUT;

extern const Mcal_PortPin_In  DSPI1_SIN_PC04_IN;
extern const Mcal_PortPin_Out DSPI1_SOUT_PC05_OUT;
extern const Mcal_PortPin_Out DSPI1_SCK_PC02_OUT;
extern const Mcal_PortPin_Out DSPI1_CS0_PC03_OUT;

extern const Mcal_PortPin_In  DSPI2_SIN_PC12_IN;
extern const Mcal_PortPin_Out DSPI2_SOUT_PC13_OUT;
extern const Mcal_PortPin_Out DSPI2_SCK_PC14_OUT;
extern const Mcal_PortPin_Out DSPI2_CS0_PC15_OUT;

/******************************************************************************
Exported Function Declarations
******************************************************************************/
extern void  Mcal_SpiMaster_Init(Mcal_Spi_Channel Channel,Mcal_Spi_MasterPin *SPI_MasterPin, Mcal_Spi_Configure *spiConfig);
extern void  Mcal_SpiMaster_Configure(Mcal_Spi_Channel Channel,Mcal_Spi_CS SPI_CS,Mcal_Spi_Configure *SPI_Configure);
extern uint8  Mcal_SpiMaster_ExchangeData(Mcal_Spi_Channel Channel,Mcal_Spi_CS SPI_CS,uint16 *TxData,uint16 *RxData,uint8 Length);
extern uint8  Mcal_SpiMaster_TxData(Mcal_Spi_Channel Channel,Mcal_Spi_CS SPI_CS,uint16 *TxData,uint8 Length);


#endif


