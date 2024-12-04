/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS, " AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
* PROJECT     : CCFC2016BC
* DESCRIPTION : CCFC2016BC CHIP SYS Init
* HISTORY     : Initial version.
* @file     sys.c
* @version  1.1
* @date     2023 - 02 - 15
* @brief    Initial version.
*
*****************************************************************************/
#include "CCFC2016BC.h"
#include "sys.h"
#include "intc_lld.h"

/* *****************************************************************************
   Function:        void SWT_DisableWatchDog(void)
   Description:     Disable The Software WatchDog Timer (SWT)
   Parameters:      Input:    None
                    Output:   None
   Notes:           To Clear The SWT_CR[SLK] Soft Lock Bit,
                    The Value 0xC520 Followed By 0xD928 Is Written To The WSC Field.
   ***************************************************************************** */

void SWT_DisableWatchDog(void)
{
    SWT.SR.R = 0x0000C520u;  /* Write keys to clear soft lock bit */
    SWT.SR.R = 0x0000D928u;
    SWT.CR.R = 0x8000010Au;
}
void SWT_EnableWatchdog(void)
{
    SWT.SR.R = 0x0000c520u;
    SWT.SR.R = 0x0000d928u;
    SWT.CR.R = 0x8000010Bu;
}
/* *****************************************************************************
   Function:        void SYSTEM_Init(void)
   Description:     Initialize Following System Peripherals
                    - The Mode Entry (ME)
                    - Clock Generation Module (CGM)
                    - Frequency Modulated Phase Locked Loop (FMPLL)
                    - Clock Monitor Unit (CMU)
                    - Power Control Unit (PCU)
                    - ReSet Generation Module (RGM)
                    - System Status And Configuration Module (SSCM)
   Parameters:      Input:    None
                    Output:   None
   Notes:
   ***************************************************************************** */
void SYSTEM_Init(void)
{
    /* Enable DRUN, RUN0, SAFE, RESET modes */
    ME.MER.R = 0x0000001Du;

    /* Initialize PLL before turning it on: */
    /* 16 MHz xtal: Set PLL0 to 64 MHz */
    /*phi = (clkin*NDIV)/(IDF*ODF) = (16*32)/(2*4) = 64MHz*/
    //CGM.FMPLL_CR.R = 0x05200100u;  //  64MHz
    CGM.FMPLL_CR.R = 0x04280100u;   //160MHz

    /**  CGM.FMPLL_CR.R = 0x04460100u;   280MHz **/
    /**  CGM.FMPLL_CR.R = 0x043c0100u;   240MHz  **/
    /**  CGM.FMPLL_CR.R = 0x04320100u;   200MHz  **/
    /**  CGM.FMPLL_CR.R = 0x04280100u;   160MHz  **/
    /**  CGM.FMPLL_CR.R = 0x05460100u;   140MHz  **/
    /**  CGM.FMPLL_CR.R = 0x053c0100u;   120MHz  **/
    /**  CGM.FMPLL_CR.R = 0x05280100u;   80MHz  **/

    CGM.SC_DC0.R = 0x80u;    /* Enable system clock divider 0 */
    CGM.SC_DC1.R = 0x80u;    /* Enable system clock divider 1 */
    CGM.SC_DC2.R = 0x80u;    /* Enable system clock divider 2 */
    CGM.SC_DC3.R = 0x80u;    /* Enable system clock divider 3 */
    /* RUN0 cfg: 16MHzIRCON, OSC0ON, PLL0ON, syclk = PLL0 */
    ME.RUN[0].R   = 0x001F0074u;

    /* Peri. Cfg. 1 settings: only run in RUN0 mode */
    ME.RUNPC[0].R = 0x000000FEu;
    ME.RUNPC[1].R = 0x000000FF;
    ME.LPPC[2].R  = 0x00000100;

    ME.MCTL.R = 0x40005AF0u;                /* Enter RUN0 Mode & Key */
    ME.MCTL.R = 0x4000A50Fu;                /* Enter RUN0 Mode & Inverted Key */

    /* Wait for mode transition to complete */
    while (ME.GS.B.S_MTRANS == 1u)
    {
        ;
    }
    /* Verify RUN0 is the current mode */
    while (ME.GS.B.S_CURRENT_MODE != 4u)
    {
        ;
    }
}
void SYSTEM_Init_LowPower(void)
{
    /* Enable DRUN, RUN0, SAFE, RESET modes */
    ME.MER.R = 0x000025FFu;

    /* Initialize PLL before turning it on: */
    /* 16 MHz xtal: Set PLL0 to 64 MHz */
    /*phi = (clkin*NDIV)/(IDF*ODF) = (16*32)/(2*4) = 64MHz*/
    /**   CGM.FMPLL_CR.R = 0x05200100u; **/

    CGM.SC_DC0.R = 0x80u;    /* Enable system clock divider 0 */
    CGM.SC_DC1.R = 0x80u;    /* Enable system clock divider 1 */

    /* RUN0 cfg: 16MHzIRCON, OSC0ON, PLL0ON, syclk = PLL0 */
    ME.RUN[0].R = 0x001F0010u;  //  0000 16 MHz int. RC osc.
    /**    ME.RUN[0].R = 0x001F0074u; **/
    /* Peri. Cfg. 1 settings: only run in RUN0 mode */
#if 1u
    #if 0u
    ME.RUNPC[0].R = 0x000000FEu;  //  Peripheral is active
    #else
    ME.RUNPC[1].R = 0x000000FEu;  //  Peripheral is active
    ME.PCTL[68].B.RUN_CFG = 1u;  //  siul 001 Selects ME_RUN_PC1 configuration
    ME.PCTL[69].B.RUN_CFG = 1u;  //  WKPU 69
    #endif

    ME.STOP.R = 0x0015000Fu;

    ME.STOP.B.FIRCON = 1u;
    ME.STOP.B.SYSCLK = 1u;

    ME.STANDBY.R = 0x0015000Fu;
    ME.STANDBY.B.FIRCON = 1u;
    ME.STANDBY.B.SYSCLK = 1u;

    CGM.FIRC_CTL.B.RCDIV = 0x1Fu;

    #if 0u
    ME.LPPC[0].R = 0x000025FFu;
    #else
    ME.LPPC[1].R = 0x00002400u;
    ME.PCTL[68].B.LP_CFG = 1u;  //  siul 001 Selects ME_RUN_PC1 configuration
    ME.PCTL[69].B.LP_CFG = 1u;  //  WKPU 69
    #endif
#endif
    ME.MCTL.R = 0x40005AF0u;              /* Enter RUN0 Mode & Key */
    ME.MCTL.R = 0x4000A50Fu;              /* Enter RUN0 Mode & Inverted Key */

    /* Wait for mode transition to complete */
    while (ME.GS.B.S_MTRANS == 1u)
    {
        ;
    }
    /* Verify RUN0 is the current mode */
    while (ME.GS.B.S_CURRENT_MODE != 4u)
    {
        ;
    }
}

void BCM_SYSTEM_Init(void)
{
    /* Enable DRUN, RUN0, SAFE, RESET modes */
    ME.MER.R = 0x000025FFu;

    /* Initialize PLL before turning it on: */
    /* 16 MHz xtal: Set PLL0 to 64 MHz */
    /*phi = (clkin*NDIV)/(IDF*ODF) = (16*32)/(2*4) = 64MHz*/
    CGM.FMPLL_CR.R = 0x05200100u;

    CGM.SC_DC0.R = 0x80u;    /* Enable system clock divider 0 */
    CGM.SC_DC1.R = 0x80u;    /* Enable system clock divider 1 */
    CGM.SC_DC2.R = 0x80u;    /* Enable system clock divider 2 */
    CGM.SC_DC3.R = 0x80u;    /* Enable system clock divider 3 */
    /* RUN0 cfg: 16MHzIRCON, OSC0ON, PLL0ON, syclk = PLL0 */
    ME.RUN[0].R   = 0x001F0074u;

    /* Peri. Cfg. 1 settings: only run in RUN0 mode */
#if 1
    #if 0
    ME.RUNPC[0].R = 0x000000FEu;  //  Peripheral is active
    #else
    ME.RUNPC[1].R = 0x000000FEu;  //  Peripheral is active
    ME.PCTL[68].B.RUN_CFG = 1u;  //  siul 001 Selects ME_RUN_PC1 configuration
    ME.PCTL[69].B.RUN_CFG = 1u;  //  WKPU 69
    ME.PCTL[48].R = 0x1u;
    ME.PCTL[91].R = 0x1u;
    ME.PCTL[92].R = 0x1u;
    #endif
    /** ME.STOP0.R = 0x00150004; **/
    /** ME.STOP0.R = 0x0015000F;   1111 system clock is disabled **/
    /** ME.STANDBY0.R = 0x0015000F; W1111 system clock is disabled **/

    #if 0
    ME.LPPC[0].R = 0x000025FFu;
    #else
    ME.LPPC[1].R = 0x00002400u;
    ME.PCTL[68].B.LP_CFG = 1u;  //  siul 001 Selects ME_RUN_PC1 configuration
    ME.PCTL[69].B.LP_CFG = 1u;  //  WKPU 69
    #endif
#endif
    ME.MCTL.R = 0x40005AF0u;              /* Enter RUN0 Mode & Key */
    ME.MCTL.R = 0x4000A50Fu;              /* Enter RUN0 Mode & Inverted Key */

    /* Wait for mode transition to complete */
    while (ME.GS.B.S_MTRANS == 1u)
    {
        ;
    }
    /* Verify RUN0 is the current mode */
    while (ME.GS.B.S_CURRENT_MODE != 4u)
    {
        ;
    }
}

/**
 * @brief   Switches the system to the specified run mode.
 *
 * @param[in] mode      one of the possible run modes
 *
 * @return              The operation status.
 * @retval CLOCK_SUCCESS if the switch operation has been completed.
 * @retval CLOCK_FAILED  if the switch operation failed.
 */
uint8_t SetRunMode(uint8_t mode) /* PRQA S 1505*/
{
    /* Clearing status register bits */
    ME.IS.R = 0xFU;

    /* Starts a transition process.*/
    ME.MCTL.R = ME_MCTL_MODE(mode) | ME_MCTL_KEY;       /* PRQA S 3469*/
    ME.MCTL.R = ME_MCTL_MODE(mode) | ME_MCTL_KEY_INV;   /* PRQA S 3469*/

    /* Waits for the mode switch or an error condition.*/
    while (ME.IS.R == 0U)
    {
        ;
    }

    /* Check if no error during mode switch */
    if (ME.IS.B.I_MTC == 1U)
    {
        return CLOCK_SUCCESS;
    }
    else
    {
        return CLOCK_FAILED;
    }
}
/**
 * @brief   Changes the clock mode of a peripheral.
 *
 * @param[in] n         index of the @p PCTL register
 * @param[in] pctl      new value for the @p PCTL register
 *
 * @notapi
 */
void SetPeripheralClockMode(uint32_t n, uint32_t pctl)
{
    uint8_t mode;

    ME.PCTL[n].R = (uint8_t)pctl;
    mode = (uint8_t)ME.MCTL.B.TARGET_MODE;

    if (SetRunMode(mode) == CLOCK_FAILED)
    {
        CLOCK_FAILURE_HOOK(); /* PRQA S 3469*/
    }
}
/**
 * @brief   Returns the system clock under the current run mode.
 *
 * @return              The system clock in Hertz.
 */
uint32_t GetSystemClock(void)
{
    uint32_t sysclk;
    uint32_t temp;
    sysclk = ME.GS.B.S_SYSCLK;
    switch (sysclk)
    {
        case ME_GS_SYSCLK_FIRC:
             temp = FIRC_CLK;
             break;
        case ME_GS_SYSCLK_FIRCDIV:
             temp = FIRC_CLK / FIRCDIV_VALUE;
             break;
        case ME_GS_SYSCLK_XOSC:
             temp = XOSC_CLK;
             break;
        case ME_GS_SYSCLK_XOSCDIV:
             temp = XOSC_CLK / XOSCDIV_VALUE;
             break;
        case ME_GS_SYSCLK_FMPLL:
             temp = FMPLL_CLK;
             break;
        default:
             temp = 0u;
             break;
    }

    return temp;
}

/**
 * @brief   Returns the peripheral clock.
 *
 * @param[in] peripheral  identifier of the peripheral related to the clock to
 *                        be returned.
 *
 * @return              The peripheral clock in Hertz.
 */
uint32_t GetPeripheralClock(peripheral_t peripheral)
{
    uint32_t temp;
    switch (peripheral)
    {
        case PERIPHERAL_PIT0:
            temp = GetSystemClock();
            break;
        default:
            temp = 0u;
            break;
    }
    return temp;
}

void InitPeriClkGen(void)
{
    CGM.SC_DC1.R = 0x80u;              /* Enable peri set 2 sysclk divided by 1 */
}

void CLK_OUT(void)
{
    SIU.PCR[0].R = 0x0A00u;
    CGM.OCDS_SC.B.SELDIV = 3u;
    CGM.OCDS_SC.B.SELCTL = 2u;
    CGM.OC_EN.B.EN = 1u;
}

void delay(volatile uint32_t x)
{
    uint32_t x_temp = x;
    while (x_temp != 0u)
    {
        x_temp--;
    }
}

void delayms(volatile uint32_t ms)
{
    uint32_t ii, jj;
    uint32_t ms_temp = ms;

    if (ms_temp < 1u)
    {
        ms_temp = 1u;
    }

    /* 40MHz--1ms    3338
     * 64MHz--1ms    5334
     * 160MHz--1ms   6940
     * */
    for (ii = 0u; ii < ms_temp; ii++)
    {
        for (jj = 0u; jj < 6940u; jj++)
        {
        }
    }
}

/* 160M, - O0 */
void delay_ms(uint32_t ms)
{
    uint32_t i;
    uint32_t temp = ms;
    do
    {
        temp--;
        i = 16000;
        do
        {
           i--;
        }while (i != 0u);
    }while (temp != 0u);
}
