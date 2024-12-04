/**************************************************************************** 
* 
* Copyright (c) 2023  C*Core -   All Rights Reserved  
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* 
* PROJECT     : CCFC2016BC           
* DESCRIPTION:  Contains defines for utilizing the Interrupt Controller
 *   in the CCFC2016BC MCU families. There are also function prototypes
 *   for the common interrupt handling routines.
* AUTHOR      : System Software Department
* HISTORY     : Initial version.
* @file     IntcInterrupts.h
* @version  1.1
* @date     2023 - 02 - 15
* @brief    Initial version.
*
*****************************************************************************/
#ifndef INTCINTERRUPTS_H_
#define INTCINTERRUPTS_H_

/*----------------------------------------------------------------------------*/
/* Types                                                                      */
/*----------------------------------------------------------------------------*/

/** All interrupt handlers should be of this type */
typedef void(*INTCInterruptFn)(void);

/*----------------------------------------------------------------------------*/
/* Function declarations                                                      */
/*----------------------------------------------------------------------------*/

#ifdef __cplusplus
extern "C" {
#endif

/**
 * This function will setup the PowerPC Zen core to jump to an Interrupt Service Routine
 * handler. This function can be used from user_init() (no stack frame, no memory access).
 */
__asm void INTC_InitINTCInterrupts(void);

/**
 * This function can be used to install an interrupt handler for a given
 * interrupt vector. It will also set the Priority Status Register for the
 * source to the one given.
 * parameter handlerFn: The function to call when the interrupt occurs.
 * parameter vectoryNum: The number of the INTC Interrupt Request Source we wish 
 * to install the handler for.
 * parameter psrPriority: The priority to set in the Interrupt Controller Priority
 * Select Register.
 */
void INTC_InstallINTCInterruptHandler(INTCInterruptFn handlerFn, unsigned short vectorNum, /* PRQA S 5209 */
                                      unsigned char psrPriority); /* PRQA S 5209 */

#pragma section RX ".__exception_handlers"

/**
 * This function is used to Handle the interrupt source by jumping to the ISR
 * branch table (IACKR)
 */
__declspec (section ".__exception_handlers") void INTC_INTCInterruptHandler(void);

#ifdef __cplusplus
}
#endif

#endif

