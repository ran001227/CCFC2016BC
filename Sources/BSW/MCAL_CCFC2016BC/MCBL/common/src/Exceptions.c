/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS, " AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
* PROJECT     : CCFC2016BC
* DESCRIPTION : Setup of IVPR to point to the EXCEPTION_HANDLERS memory area
 *               defined in the linker command file.
 *               Default setup of the IVORxx registers.
* HISTORY     : Initial version.
* @file     Exceptions.c
* @version  1.0
* @date     2023 - 02 - 15
* @brief    Initial version.
*
*****************************************************************************/

#include "Exceptions.h" /* Implement functions from this file */

/*----------------------------------------------------------------------------*/
/* Function Implementations                                                   */
/*----------------------------------------------------------------------------*/
#ifdef __cplusplus
extern "C" {
#endif
unsigned long EXCEP_Err_handler(unsigned long return_address, unsigned short instruction)/* PRQA S 5209, 3206 ,3408*/
{
#if (VLE_IS_ON == 1U)/* PRQA S 3332 */
    if ((instruction & 0x9000U) == 0x1000U)
    {
        /* First 4 Bits have a value of 1, 3, 5, 7 */
        return_address += 4U;    /* Instruction was 32 bit */
    }
    else
    {
        /* First 4 Bits have a value of 0, 2, 4, 6, 8, 9, A, B, C, D, E (and F, but F is reserved) */
        return_address += 2U;    /* Instruction was 16 bit */
    }

#else   /* BookE */
    return_address += 4U;/* PRQA S 1338 */
#endif    /* VLE_IS_ON */

    return return_address;
}
#pragma push /* Save the current state */
/* Symbol EXCEPTION_HANDLERS is defined in the application linker command file (.lcf)
   It is defined to the start of the code memory area used for the .__exception_handlers section.
*/
/*lint - esym(752, EXCEPTION_HANDLERS) */
__declspec(section ".__exception_handlers") extern long EXCEPTION_HANDLERS;/* PRQA S 5209 */
#pragma force_active on
#pragma function_align 16 /* We use 16 bytes alignment for Exception handlers */
__declspec(interrupt)
__declspec(section ".__exception_handlers")
void EXCEP_DefaultExceptionHandler(void)
{
}
#pragma force_active off
#pragma pop

__asm void EXCEP_InitExceptionHandlers(void)/* PRQA S 1006 */
{
nofralloc
    //  Set the IVPR to the exception handlers address defined in the lcf file.
    //  The IVPR[0 - 15] bits Vector Base and IVPR[16 - 31] bits are ignored.
    lis     r0, EXCEPTION_HANDLERS@h/* PRQA S 0289 */
    mtivpr  r0

    li      r0, EXCEPTION_HANDLERS@l
    mtivor0 r0

    li      r0, (EXCEPTION_HANDLERS + 0x10)@l
    mtivor1 r0

    li      r0, (EXCEPTION_HANDLERS + 0x20)@l
    mtivor2 r0

    li      r0, (EXCEPTION_HANDLERS + 0x30)@l
    mtivor3 r0

    li      r0, (EXCEPTION_HANDLERS + 0x40)@l
    mtivor4 r0

    li      r0, (EXCEPTION_HANDLERS + 0x50)@l
    mtivor5 r0

    li      r0, (EXCEPTION_HANDLERS + 0x60)@l
    mtivor6 r0

    li      r0, (EXCEPTION_HANDLERS + 0x70)@l
    mtivor7 r0

    li      r0, (EXCEPTION_HANDLERS + 0x80)@l
    mtivor8 r0

    li      r0, (EXCEPTION_HANDLERS + 0x90)@l
    mtivor9 r0

    li      r0, (EXCEPTION_HANDLERS + 0xA0)@l
    mtivor10 r0

    li      r0, (EXCEPTION_HANDLERS + 0xB0)@l
    mtivor11 r0

    li      r0, (EXCEPTION_HANDLERS + 0xC0)@l
    mtivor12 r0

    li      r0, (EXCEPTION_HANDLERS + 0xD0)@l
    mtivor13 r0

    li      r0, (EXCEPTION_HANDLERS + 0xE0)@l
    mtivor14 r0

    li      r0, (EXCEPTION_HANDLERS + 0xF0)@l
    mtivor15 r0

    blr
}

#ifdef __cplusplus
}
#endif
