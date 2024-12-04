/**************************************************************************** 
* 
* Copyright (c) 2023  C*Core -   All Rights Reserved  
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* 
* PROJECT     : CCFC2016BC           
* DESCRIPTION:  This file defines all of the data types for the C*Core header file.
* AUTHOR      : System Software Department
* HISTORY     : Initial version
* @file     typedefs.h
* @version  1.1
* @date     2023 - 02 - 15
* @brief    Initial version.
*
*****************************************************************************/

#ifndef TYPEDEFS_H
#define TYPEDEFS_H

/**
 * @name    Common constants
 * @{
 */
#if !defined(FALSE) 
#define FALSE                       0U
#endif

#if !defined(TRUE) 
#define TRUE                        1U
#endif

#if !defined(NULL) 
#define NULL                        0U /* PRQA S 4600 */
#endif

#ifdef __MWERKS__    /*Metrowerk CodeWarrior*/
    #include <stdint.h>
    /* Standard typedefs used by header files, based on ISO C standard*/
    typedef volatile int8_t vint8_t;
    typedef volatile uint8_t vuint8_t;

    typedef volatile int16_t vint16_t;
    typedef volatile uint16_t vuint16_t;

    typedef volatile int32_t vint32_t;
    typedef volatile uint32_t vuint32_t;
    
    typedef float float32_t;
    typedef double double32_t;
    typedef long long32_t;
    typedef unsigned long ulong32_t;
#else

    /* This is needed for compilers that don't have a stdint.h file*/
    typedef signed char int8_t;
    typedef unsigned char uint8_t;
    typedef volatile signed char vint8_t;
    typedef volatile unsigned char vuint8_t;

    typedef signed short int16_t;
    typedef unsigned short uint16_t;
    typedef volatile signed short vint16_t;
    typedef volatile unsigned short vuint16_t;

    typedef signed int int32_t;
    typedef unsigned int uint32_t;
    typedef volatile signed int vint32_t;
    typedef volatile unsigned int vuint32_t;

    typedef float float32_t;
    typedef double double32_t;
    typedef long long32_t;
    typedef unsigned long ulong32_t;
    
    typedef unsigned long long uint64_t;
#endif
#endif



