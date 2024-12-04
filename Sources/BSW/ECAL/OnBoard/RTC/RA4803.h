#ifndef __RA4803_H__
#define __RA4803_H__

#include "Mcal_Spi.h"
#include "Mcal_GPIO.h"


#define SPI_BAUDRATE_K		(1000)
#define SPI_BAUDRATE_M		(1000*1000)


#define RA4803_REG_READ(n)  (0x80 | ((n) & 0x0F))
#define RA4803_REG_WRITE(n) (0x00 | ((n) & 0x0F))

#define RA4803_REG_READ_BANK1(n)        (0x90 | ((n) & 0x0F))
#define RA4803_REG_READ_BANK2(n)        (0xA0 | ((n) & 0x0F))
#define RA4803_REG_READ_BANK3(n)        (0xB0 | ((n) & 0x0F))

#define RA4803_REG_WRITE_BANK1(n)       (0x10 | ((n) & 0x0F))
#define RA4803_REG_WRITE_BANK2(n)       (0x20 | ((n) & 0x0F))
#define RA4803_REG_WRITE_BANK3(n)       (0x30 | ((n) & 0x0F))

typedef enum
{
    RA4803_ChipNum_U01,
	RA4803_ChipNum_Num,
} RA4803_ChipNum;

/** \brief the Structure of the 25LC512 Chip Configure
 */

typedef struct
{
    Mcal_Spi_Channel spix;
    Mcal_Spi_CS spi_cs;
    Mcal_GPIO_Pin rst;
    boolean exist;
} RA4803_Config;

typedef struct
{
    Mcal_Spi_Channel spix;
    Mcal_Spi_MasterPin pin_cfg;
    Mcal_Spi_CS spi_cs;
} RA4803_InitPara;

typedef enum
{
    RA4803_4096Hz = 0,
    RA4803_64Hz = 1,
    RA4803_SecondUpdate = 2,
    RA4803_MinuteUpdate = 3,
} RA4803_SourceClockType;




#define  RA4803_ERR_CHIP    (0x00000001)
#define  RA4803_ERR_SEC     (0x00000002)
#define  RA4803_ERR_MIN     (0x00000004)
#define  RA4803_ERR_HOUR    (0x00000008)
#define  RA4803_ERR_WEEK    (0x00000010)
#define  RA4803_ERR_DAY     (0x00000020)
#define  RA4803_ERR_MONTH   (0x00000040)
#define  RA4803_ERR_YEAR    (0x00000080)

#define  RA4803_ERR_NOT_EXAIT   (0x00010000)
#define  RA4803_ERR_NULL_PTR    (0x01000000)




extern void RA4803_Init(RA4803_ChipNum chip_num, RA4803_InitPara *init_para);
extern uint32 RTC_SetTimerValue(RA4803_ChipNum chip_num, uint8 en, RA4803_SourceClockType sourceClock, uint16 cntTimeSet);
extern uint32 RTC_GetDateAndTime(RA4803_ChipNum chip_num, uint8 *year, uint8 *month, uint8 *day, uint8 *week, uint8 *hour, uint8 *min, uint8 *sec);
extern uint32 RTC_SetDateAndTime(RA4803_ChipNum chip_num, uint8 year, uint8 month, uint8 day, uint8 week, uint8 hour, uint8 min, uint8 sec);


#endif
