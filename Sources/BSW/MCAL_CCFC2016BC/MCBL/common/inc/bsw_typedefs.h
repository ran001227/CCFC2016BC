/******************************************************************************
*  Copyright (c) ECO-EV Technologies Co., Ltd. 2015-2016.
*  All rights reserved.

*  File name:     bsw_typedefs.h
*  Author:        ECO-EV
*  Version:    V1.0.1
*  Date:       2018-4-27
*  Description:
*  Others:
*  History:
*
*  1. Date:
*     Author:
*     Modification:
*  2. ...
******************************************************************************/

#ifndef _BSW_TYPEDEFS_H_
#define _BSW_TYPEDEFS_H_

#include "typedefs.h"
/*
 * AUTOSAR integer data types
 */
typedef signed char  	 	sint8;               /*        -128 .. +127            */
typedef unsigned char 		uint8;               /*           0 .. 255             */
typedef signed short  		sint16;              /*      -32768 .. +32767          */
typedef unsigned short		uint16;              /*           0 .. 65535           */
typedef signed long   		sint32;              /* -2147483648 .. +2147483647     */
typedef unsigned long 		uint32;              /*           0 .. 4294967295      */
typedef signed long long	sint64;
typedef unsigned long long 	uint64;

typedef float          float32;
typedef double         float64;

typedef unsigned long  uint8_least;         /* At least 8 bit                 */
typedef unsigned long  uint16_least;        /* At least 16 bit                */
typedef unsigned long  uint32_least;        /* At least 32 bit                */
typedef signed long    sint8_least;         /* At least 7 bit + 1 bit sign    */
typedef signed long    sint16_least;        /* At least 15 bit + 1 bit sign   */
typedef signed long    sint32_least;        /* At least 31 bit + 1 bit sign   */

typedef unsigned char  boolean;             /* for use with TRUE/FALSE        */

#ifndef TRUE                                /* conditional check */
#define TRUE  1
#endif

#ifndef FALSE                                            /* conditional check */
#define FALSE 0
#endif

#ifndef NULL
    #define NULL   (void *)(0)
#endif

#ifndef NONE
    #define NONE   (-1)
#endif

#ifndef  RES_OK
   #define RES_OK   (0)
#endif



/** \brief Pin output Alternate function
 */
typedef enum
{
   Port_Num_PA=0,
   Port_Num_PB,
   Port_Num_PC,
   Port_Num_PD,
   Port_Num_PE,
   Port_Num_PF,
   Port_Num_PG,
   Port_Num_PH,
   Port_Num_PI,
   Port_Num_PJ
} Port_Num;


/** \ MSCR/IMCR SSS Value
 */
typedef enum
{
   SSS0,
   SSS1,
   SSS2,
   SSS3,
   SSS4
} Source_Signal_Select;


/** \brief PWM out pin mapping structure */
typedef  struct
{
   Port_Num Port;
    uint8  PinIndex;
//    Source_Signal_Select SSS;
} Mcal_PortPin_Out;


/** \brief CAN TX out pin mapping structure */
typedef  struct
{
   Port_Num Port;
    uint8  PinIndex;
    uint8 IMCR;
//    Source_Signal_Select SSS;
} Mcal_PortPin_In;


/** \brief port  pin mapping structure */
typedef  struct
{
   Port_Num Port;
   uint8  PinIndex;
} Mcal_PortPin;

/** \brief Enumerate the Type of Hwal_DO_ErrType
 */
typedef enum
{
	Ecal_DO_ErrType_Normal        =0b00000000,
	Ecal_DO_ErrType_ShortToBattery   =0b00000001,
	Ecal_DO_ErrType_ShortToGround    =0b00000010,
	Ecal_DO_ErrType_OpenLoad      =0b00000100,
	Ecal_DO_ErrType_OverTemperature =0b00001000,
	Ecal_DO_ErrType_PowerError       =0b00010000,
	Ecal_DO_ErrType_ShortedLoad   =0b00100000,
	Ecal_DO_ErrType_OverLoad      =0b01000000,
	Ecal_DO_ErrType_Others        =0b10000000,
} Ecal_DO_ErrType;


#endif
