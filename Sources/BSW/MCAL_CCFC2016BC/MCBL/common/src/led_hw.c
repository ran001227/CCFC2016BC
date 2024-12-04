/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS, " AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
* PROJECT     : CCFC2016BC
* DESCRIPTION : CCFC2016BC EVB LED Driver
* HISTORY     : Initial version.
* @file     led_hw.c
* @version  1.1
* @date     2023 - 02 - 15
* @brief    Initial version.
*
*****************************************************************************/

#include "CCFC2016BC.h"
#include "led_hw.h"
#include "siul_lld.h"

void LED_SIU_Init(void)
{
    /*CCFC2016BC 176 - pin LQFP*/
    SIUL_Init_GPIO_Out((uint8_t)PC6_PCR, PCR_GPIO_OUT_PP);   /* PC[6], Open Drain Output Disable */
    SIUL_Init_GPIO_Out((uint8_t)PC7_PCR, PCR_GPIO_OUT_PP);   /* PC[7], Open Drain Output Disable */
    SIUL_Init_GPIO_Out((uint8_t)PC8_PCR, PCR_GPIO_OUT_PP);   /* PC[8], Open Drain Output Disable */
}

void LED1_IO_Set(uint8_t val)/* PRQA S 1505*/
{
    SIUL_GPIO_OutputWrite((uint8_t)PC6_PCR, val);
}

void LED2_IO_Set(uint8_t val)
{
    SIUL_GPIO_OutputWrite((uint8_t)PC7_PCR, val);
}

void LED3_IO_Set(uint8_t val)/* PRQA S 1505*/
{
    SIUL_GPIO_OutputWrite((uint8_t)PC8_PCR, val);
}

void LED_Set(uint8_t ledNum, uint8_t value)
{
    if ((ledNum > 0x04u) && (value > 1u))
    {
        return;
    }

    if ((ledNum & LED1) == LED1)
    {
        LED1_IO_Set(value); /* PRQA S 1505*/
    }

    if ((ledNum & LED2) == LED2)
    {
        LED2_IO_Set(value);
    }

    if ((ledNum & LED3) == LED3)
    {
        LED3_IO_Set(value);
    }
}

void LED_Toggle(uint8_t ledNum)
{
     vuint8_t temp = 0;

    if (ledNum > 0x04u)
    {
        return;
    }

    if ((ledNum & LED1) == LED1)
    {
        temp = SIU.GPDO[38].B.PDO;
        if (temp == 0u)
        {
            LED1_IO_Set(1);
        }
        else
        {
            LED1_IO_Set(0);
        }
    }

    if ((ledNum & LED2) == LED2)
    {
        temp = SIU.GPDO[39].B.PDO;
        if (temp == 0u)
        {
            LED2_IO_Set(1);
        }
        else
        {
            LED2_IO_Set(0);
        }
    }

    if ((ledNum & LED3) == LED3)
    {
        temp = SIU.GPDO[40].B.PDO;
        if (temp == 0u)
        {
            LED3_IO_Set(1);
        }
        else
        {
            LED3_IO_Set(0);
        }
    }
}
