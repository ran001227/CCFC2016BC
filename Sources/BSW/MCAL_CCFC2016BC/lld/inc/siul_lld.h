/**************************************************************************** 
* 
* Copyright (c) 2023  C*Core -   All Rights Reserved  
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* 
* PROJECT     : CCFC2016BC           
* DESCRIPTION : CCFC2016BC siul low level drivers h file 
* HISTORY     : None
* @file     siul_lld.h
* @version  1.1
* @date     2023 - 02 - 15
* @brief    Initial version.
*
*****************************************************************************/
#ifndef SIUL_LLD_H
#define SIUL_LLD_H
#include "typedefs.h"

/************************************************************************
* @brief    MCU ID Register #1 (MIDR1)
*************************************************************************/
#define MIDR1_PARTNUM_MASK      ((uint32_t)0xFFFF0000UL)
#define MIDR1_CSP_MASK          ((uint32_t)0x00008000UL)
#define MIDR1_PKG_MASK          ((uint32_t)0x00007C00UL)
#define MIDR1_MAJOR_MASK        ((uint32_t)0x000000F0UL)
#define MIDR1_MINOR_MASK        ((uint32_t)0x0000000FUL)

/*
* @brief    MIDR1_PARTNUM_MASK.
**/
#define PARTNUM_L_128KB         ((uint32_t)0x56010000UL)
#define PARTNUM_L_256KB         ((uint32_t)0x56020000UL)
#define PARTNUM_L_320_384KB     ((uint32_t)0x56030000UL)
#define PARTNUM_L_512KB         ((uint32_t)0x56040000UL)
#define PARTNUM_L_768KB         ((uint32_t)0x56050000UL)
#define PARTNUM_L_1MB           ((uint32_t)0x56060000UL)
#define PARTNUM_L_1D5MB         ((uint32_t)0x56070000UL)

/*
* @brief    MIDR1_PKG_MASK.
**/
#define PKG_LQFP100             ((uint32_t)0x00002400UL)
#define PKG_LQFP144             ((uint32_t)0x00003400UL)
#define PKG_BGA208              ((uint32_t)0x00004000UL)
#define PKG_LQFP176             ((uint32_t)0x00004400UL)

/************************************************************************
* @brief    MCU ID Register #2 (MIDR2)
*************************************************************************/
#define MIDR2_SF_MASK           ((uint32_t)0x80000000UL)
#define MIDR2_FLASHSIZE1_MASK   ((uint32_t)0x78000000UL)
#define MIDR2_FLASHSIZE2_MASK   ((uint32_t)0x07800000UL)
#define MIDR2_PARTNUM_MASK      ((uint32_t)0x0000FF00UL)
#define MIDR2_EE_MASK           ((uint32_t)0x00000010UL)

/*
* @brief    MIDR2_SF_MASK.
**/
#define SF_MAKER_FREESCALE      ((uint32_t)0x00000000UL)
#define SF_MAKER_RESERVED       ((uint32_t)0x80000000UL)

/*
* @brief    MIDR2_FLASHSIZE1_MASK.
**/
#define FLASHSIZE1_128KB        ((uint32_t)0x18000000UL)
#define FLASHSIZE1_256KB        ((uint32_t)0x20000000UL)
#define FLASHSIZE1_512KB        ((uint32_t)0x28000000UL)
#define FLASHSIZE1_1MB          ((uint32_t)0x30000000UL)

/*
* @brief    MIDR2_FLASHSIZE2_MASK.
**/
#define FLASHSIZE2_TIMES_0      ((uint32_t)0x00000000UL)
#define FLASHSIZE2_TIMES_2      ((uint32_t)0x01000000UL)
#define FLASHSIZE2_TIMES_4      ((uint32_t)0x02000000UL)

/*
* @brief    MIDR2_PARTNUM_MASK.
* @details  Character B(Body controller)
*           Character C(Gateway)
**/
#define PARTNUM_H_CHARA_B       ((uint32_t)0x00004200UL)
#define PARTNUM_H_CHARA_C       ((uint32_t)0x00004300UL)

/*
* @brief    MIDR2_EE_MASK.
**/
#define EE_NO_DATA_FLASH        ((uint32_t)0x00000000UL)
#define EE_DATA_FLASH_PRESENT   ((uint32_t)0x00000010UL)

/************************************************************************
* @brief    External interrupt vectors correspond to interrupt flags
*************************************************************************/
#define EXTI_0_7_MASK           ((uint32_t)0x000000FFUL)
#define EXTI_8_15_MASK          ((uint32_t)0x0000FF00UL)
#define EXTI_16_23_MASK         ((uint32_t)0x00FF0000UL)

/************************************************************************
* @brief    External interrupt edge event
*************************************************************************/
typedef enum
{
    EXTI_RISING_EDGE    = 0U,   /**< @brief Rising edge */
    EXTI_FALLING_EDGE,          /**< @brief Falling edge */
    EXTI_BOTH_EDGES             /**< @brief falling and rising edge */
} ExtIrqEdgeEvent_t;

/************************************************************************
* @brief    Interrupt Status Flag Register (ISR)
*************************************************************************/
#define ISR_EIF0                ((uint32_t)0x00000001UL)
#define ISR_EIF1                ((uint32_t)0x00000002UL)
#define ISR_EIF2                ((uint32_t)0x00000004UL)
#define ISR_EIF3                ((uint32_t)0x00000008UL)
#define ISR_EIF4                ((uint32_t)0x00000010UL)
#define ISR_EIF5                ((uint32_t)0x00000020UL)
#define ISR_EIF6                ((uint32_t)0x00000040UL)
#define ISR_EIF7                ((uint32_t)0x00000080UL)
#define ISR_EIF8                ((uint32_t)0x00000100UL)
#define ISR_EIF9                ((uint32_t)0x00000200UL)
#define ISR_EIF10               ((uint32_t)0x00000400UL)
#define ISR_EIF11               ((uint32_t)0x00000800UL)
#define ISR_EIF12               ((uint32_t)0x00001000UL)
#define ISR_EIF13               ((uint32_t)0x00002000UL)
#define ISR_EIF14               ((uint32_t)0x00004000UL)
#define ISR_EIF15               ((uint32_t)0x00008000UL)
#define ISR_EIF16               ((uint32_t)0x00010000UL)
#define ISR_EIF17               ((uint32_t)0x00020000UL)
#define ISR_EIF18               ((uint32_t)0x00040000UL)
#define ISR_EIF19               ((uint32_t)0x00080000UL)
#define ISR_EIF20               ((uint32_t)0x00100000UL)
#define ISR_EIF21               ((uint32_t)0x00200000UL)
#define ISR_EIF22               ((uint32_t)0x00400000UL)
#define ISR_EIF23               ((uint32_t)0x00800000UL)

/************************************************************************
* @brief    Interrupt Request Enable Register (IRER)
*************************************************************************/
#define IRER_IRE0               ((uint32_t)0x00000001UL)
#define IRER_IRE1               ((uint32_t)0x00000002UL)
#define IRER_IRE2               ((uint32_t)0x00000004UL)
#define IRER_IRE3               ((uint32_t)0x00000008UL)
#define IRER_IRE4               ((uint32_t)0x00000010UL)
#define IRER_IRE5               ((uint32_t)0x00000020UL)
#define IRER_IRE6               ((uint32_t)0x00000040UL)
#define IRER_IRE7               ((uint32_t)0x00000080UL)
#define IRER_IRE8               ((uint32_t)0x00000100UL)
#define IRER_IRE9               ((uint32_t)0x00000200UL)
#define IRER_IRE10              ((uint32_t)0x00000400UL)
#define IRER_IRE11              ((uint32_t)0x00000800UL)
#define IRER_IRE12              ((uint32_t)0x00001000UL)
#define IRER_IRE13              ((uint32_t)0x00002000UL)
#define IRER_IRE14              ((uint32_t)0x00004000UL)
#define IRER_IRE15              ((uint32_t)0x00008000UL)
#define IRER_IRE16              ((uint32_t)0x00010000UL)
#define IRER_IRE17              ((uint32_t)0x00020000UL)
#define IRER_IRE18              ((uint32_t)0x00040000UL)
#define IRER_IRE19              ((uint32_t)0x00080000UL)
#define IRER_IRE20              ((uint32_t)0x00100000UL)
#define IRER_IRE21              ((uint32_t)0x00200000UL)
#define IRER_IRE22              ((uint32_t)0x00400000UL)
#define IRER_IRE23              ((uint32_t)0x00800000UL)

/************************************************************************
* @brief    Interrupt Rising-Edge Event Enable Register (IREER)
*************************************************************************/
#define IREER_IREE0             ((uint32_t)0x00000001UL)
#define IREER_IREE1             ((uint32_t)0x00000002UL)
#define IREER_IREE2             ((uint32_t)0x00000004UL)
#define IREER_IREE3             ((uint32_t)0x00000008UL)
#define IREER_IREE4             ((uint32_t)0x00000010UL)
#define IREER_IREE5             ((uint32_t)0x00000020UL)
#define IREER_IREE6             ((uint32_t)0x00000040UL)
#define IREER_IREE7             ((uint32_t)0x00000080UL)
#define IREER_IREE8             ((uint32_t)0x00000100UL)
#define IREER_IREE9             ((uint32_t)0x00000200UL)
#define IREER_IREE10            ((uint32_t)0x00000400UL)
#define IREER_IREE11            ((uint32_t)0x00000800UL)
#define IREER_IREE12            ((uint32_t)0x00001000UL)
#define IREER_IREE13            ((uint32_t)0x00002000UL)
#define IREER_IREE14            ((uint32_t)0x00004000UL)
#define IREER_IREE15            ((uint32_t)0x00008000UL)
#define IREER_IREE16            ((uint32_t)0x00010000UL)
#define IREER_IREE17            ((uint32_t)0x00020000UL)
#define IREER_IREE18            ((uint32_t)0x00040000UL)
#define IREER_IREE19            ((uint32_t)0x00080000UL)
#define IREER_IREE20            ((uint32_t)0x00100000UL)
#define IREER_IREE21            ((uint32_t)0x00200000UL)
#define IREER_IREE22            ((uint32_t)0x00400000UL)
#define IREER_IREE23            ((uint32_t)0x00800000UL)

/************************************************************************
* @brief    Interrupt Falling-Edge Event Enable Register (IFEER)
*************************************************************************/
#define IFEER_IFEE0             ((uint32_t)0x00000001UL)
#define IFEER_IFEE1             ((uint32_t)0x00000002UL)
#define IFEER_IFEE2             ((uint32_t)0x00000004UL)
#define IFEER_IFEE3             ((uint32_t)0x00000008UL)
#define IFEER_IFEE4             ((uint32_t)0x00000010UL)
#define IFEER_IFEE5             ((uint32_t)0x00000020UL)
#define IFEER_IFEE6             ((uint32_t)0x00000040UL)
#define IFEER_IFEE7             ((uint32_t)0x00000080UL)
#define IFEER_IFEE8             ((uint32_t)0x00000100UL)
#define IFEER_IFEE9             ((uint32_t)0x00000200UL)
#define IFEER_IFEE10            ((uint32_t)0x00000400UL)
#define IFEER_IFEE11            ((uint32_t)0x00000800UL)
#define IFEER_IFEE12            ((uint32_t)0x00001000UL)
#define IFEER_IFEE13            ((uint32_t)0x00002000UL)
#define IFEER_IFEE14            ((uint32_t)0x00004000UL)
#define IFEER_IFEE15            ((uint32_t)0x00008000UL)
#define IFEER_IFEE16            ((uint32_t)0x00010000UL)
#define IFEER_IFEE17            ((uint32_t)0x00020000UL)
#define IFEER_IFEE18            ((uint32_t)0x00040000UL)
#define IFEER_IFEE19            ((uint32_t)0x00080000UL)
#define IFEER_IFEE20            ((uint32_t)0x00100000UL)
#define IFEER_IFEE21            ((uint32_t)0x00200000UL)
#define IFEER_IFEE22            ((uint32_t)0x00400000UL)
#define IFEER_IFEE23            ((uint32_t)0x00800000UL)

/************************************************************************
* @brief    Interrupt Filter Enable Register (IFER)
*************************************************************************/
#define IFER_IFE0               ((uint32_t)0x00000001UL)
#define IFER_IFE1               ((uint32_t)0x00000002UL)
#define IFER_IFE2               ((uint32_t)0x00000004UL)
#define IFER_IFE3               ((uint32_t)0x00000008UL)
#define IFER_IFE4               ((uint32_t)0x00000010UL)
#define IFER_IFE5               ((uint32_t)0x00000020UL)
#define IFER_IFE6               ((uint32_t)0x00000040UL)
#define IFER_IFE7               ((uint32_t)0x00000080UL)
#define IFER_IFE8               ((uint32_t)0x00000100UL)
#define IFER_IFE9               ((uint32_t)0x00000200UL)
#define IFER_IFE10              ((uint32_t)0x00000400UL)
#define IFER_IFE11              ((uint32_t)0x00000800UL)
#define IFER_IFE12              ((uint32_t)0x00001000UL)
#define IFER_IFE13              ((uint32_t)0x00002000UL)
#define IFER_IFE14              ((uint32_t)0x00004000UL)
#define IFER_IFE15              ((uint32_t)0x00008000UL)
#define IFER_IFE16              ((uint32_t)0x00010000UL)
#define IFER_IFE17              ((uint32_t)0x00020000UL)
#define IFER_IFE18              ((uint32_t)0x00040000UL)
#define IFER_IFE19              ((uint32_t)0x00080000UL)
#define IFER_IFE20              ((uint32_t)0x00100000UL)
#define IFER_IFE21              ((uint32_t)0x00200000UL)
#define IFER_IFE22              ((uint32_t)0x00400000UL)
#define IFER_IFE23              ((uint32_t)0x00800000UL)

/************************************************************************
* @brief    Pad Configuration Registers (PCR0-PCR148)
*************************************************************************/
#define PCR_WPS                 ((uint16_t)0x0001U) /* Weak Pull Up/Down Select.               */
#define PCR_WPE                 ((uint16_t)0x0002U) /* Weak Pull Up/Down Enable.               */
#define PCR_SRC                 ((uint16_t)0x0004U) /* Slew Rate Control.                      */
#define PCR_ODE                 ((uint16_t)0x0020U) /* Open Drain Output Enable.               */
#define PCR_IBE                 ((uint16_t)0x0100U) /* Input Buffer Enable.                    */
#define PCR_OBE                 ((uint16_t)0x0200U) /* Output Buffer Enable.                   */
#define PCR_PA0                 ((uint16_t)0x0000U) /* Alternative Mode 0: PA[1:0]=00b, --GPIO */
#define PCR_PA1                 ((uint16_t)0x0400U) /* Alternative Mode 1: PA[1:0]=01b.        */
#define PCR_PA2                 ((uint16_t)0x0800U) /* Alternative Mode 2: PA[1:0]=10b.        */
#define PCR_PA3                 ((uint16_t)0x0C00U) /* Alternative Mode 3: PA[1:0]=11b.        */
#define PCR_APC                 ((uint16_t)0x2000U) /* Analog Pad Control.                     */
#define PCR_SMC                 ((uint16_t)0x4000U) /* Safe Mode Control.                      */

/* PCR configuration for the module */
#define PCR_GPIO_OUT_PP         (PCR_OBE)           /* Push/Pull output */
#define PCR_GPIO_OUT_OD         (PCR_OBE|PCR_ODE)   /* Open Drain */
#define PCR_EIRQ_WEAK_UP        (PCR_IBE|PCR_WPE|PCR_WPS)/* GPIO input, Weak pull up enable */
#define PCR_EIRQ_WEAK_DOWN      (PCR_IBE|PCR_WPE)   /* GPIO input, Weak pull down enable */
#define PCR_EIRQ                PCR_EIRQ_WEAK_UP
#define PCR_ADC                 (PCR_APC)

/*
* @brief    PCR Number 0 ~ 148.
**/
#define PCR_PIN0                ((uint8_t)0U)
#define PCR_PIN1                ((uint8_t)1U)
#define PCR_PIN2                ((uint8_t)2U)
#define PCR_PIN3                ((uint8_t)3U)
#define PCR_PIN4                ((uint8_t)4U)
#define PCR_PIN5                ((uint8_t)5U)
#define PCR_PIN6                ((uint8_t)6U)
#define PCR_PIN7                ((uint8_t)7U)
#define PCR_PIN8                ((uint8_t)8U)
#define PCR_PIN9                ((uint8_t)9U)
#define PCR_PIN10               ((uint8_t)10U)
#define PCR_PIN11               ((uint8_t)11U)
#define PCR_PIN12               ((uint8_t)12U)
#define PCR_PIN13               ((uint8_t)13U)
#define PCR_PIN14               ((uint8_t)14U)
#define PCR_PIN15               ((uint8_t)15U)
#define PCR_PIN16               ((uint8_t)16U)
#define PCR_PIN17               ((uint8_t)17U)
#define PCR_PIN18               ((uint8_t)18U)
#define PCR_PIN19               ((uint8_t)19U)
#define PCR_PIN20               ((uint8_t)20U)
#define PCR_PIN21               ((uint8_t)21U)
#define PCR_PIN22               ((uint8_t)22U)
#define PCR_PIN23               ((uint8_t)23U)
#define PCR_PIN24               ((uint8_t)24U)
#define PCR_PIN25               ((uint8_t)25U)
#define PCR_PIN26               ((uint8_t)26U)
#define PCR_PIN27               ((uint8_t)27U)
#define PCR_PIN28               ((uint8_t)28U)
#define PCR_PIN29               ((uint8_t)29U)
#define PCR_PIN30               ((uint8_t)30U)
#define PCR_PIN31               ((uint8_t)31U)
#define PCR_PIN32               ((uint8_t)32U)
#define PCR_PIN33               ((uint8_t)33U)
#define PCR_PIN34               ((uint8_t)34U)
#define PCR_PIN35               ((uint8_t)35U)
#define PCR_PIN36               ((uint8_t)36U)
#define PCR_PIN37               ((uint8_t)37U)
#define PCR_PIN38               ((uint8_t)38U)
#define PCR_PIN39               ((uint8_t)39U)
#define PCR_PIN40               ((uint8_t)40U)
#define PCR_PIN41               ((uint8_t)41U)
#define PCR_PIN42               ((uint8_t)42U)
#define PCR_PIN43               ((uint8_t)43U)
#define PCR_PIN44               ((uint8_t)44U)
#define PCR_PIN45               ((uint8_t)45U)
#define PCR_PIN46               ((uint8_t)46U)
#define PCR_PIN47               ((uint8_t)47U)
#define PCR_PIN48               ((uint8_t)48U)
#define PCR_PIN49               ((uint8_t)49U)
#define PCR_PIN50               ((uint8_t)50U)
#define PCR_PIN51               ((uint8_t)51U)
#define PCR_PIN52               ((uint8_t)52U)
#define PCR_PIN53               ((uint8_t)53U)
#define PCR_PIN54               ((uint8_t)54U)
#define PCR_PIN55               ((uint8_t)55U)
#define PCR_PIN56               ((uint8_t)56U)
#define PCR_PIN57               ((uint8_t)57U)
#define PCR_PIN58               ((uint8_t)58U)
#define PCR_PIN59               ((uint8_t)59U)
#define PCR_PIN60               ((uint8_t)60U)
#define PCR_PIN61               ((uint8_t)61U)
#define PCR_PIN62               ((uint8_t)62U)
#define PCR_PIN63               ((uint8_t)63U)
#define PCR_PIN64               ((uint8_t)64U)
#define PCR_PIN65               ((uint8_t)65U)
#define PCR_PIN66               ((uint8_t)66U)
#define PCR_PIN67               ((uint8_t)67U)
#define PCR_PIN68               ((uint8_t)68U)
#define PCR_PIN69               ((uint8_t)69U)
#define PCR_PIN70               ((uint8_t)70U)
#define PCR_PIN71               ((uint8_t)71U)
#define PCR_PIN72               ((uint8_t)72U)
#define PCR_PIN73               ((uint8_t)73U)
#define PCR_PIN74               ((uint8_t)74U)
#define PCR_PIN75               ((uint8_t)75U)
#define PCR_PIN76               ((uint8_t)76U)
#define PCR_PIN77               ((uint8_t)77U)
#define PCR_PIN78               ((uint8_t)78U)
#define PCR_PIN79               ((uint8_t)79U)
#define PCR_PIN80               ((uint8_t)80U)
#define PCR_PIN81               ((uint8_t)81U)
#define PCR_PIN82               ((uint8_t)82U)
#define PCR_PIN83               ((uint8_t)83U)
#define PCR_PIN84               ((uint8_t)84U)
#define PCR_PIN85               ((uint8_t)85U)
#define PCR_PIN86               ((uint8_t)86U)
#define PCR_PIN87               ((uint8_t)87U)
#define PCR_PIN88               ((uint8_t)88U)
#define PCR_PIN89               ((uint8_t)89U)
#define PCR_PIN90               ((uint8_t)90U)
#define PCR_PIN91               ((uint8_t)91U)
#define PCR_PIN92               ((uint8_t)92U)
#define PCR_PIN93               ((uint8_t)93U)
#define PCR_PIN94               ((uint8_t)94U)
#define PCR_PIN95               ((uint8_t)95U)
#define PCR_PIN96               ((uint8_t)96U)
#define PCR_PIN97               ((uint8_t)97U)
#define PCR_PIN98               ((uint8_t)98U)
#define PCR_PIN99               ((uint8_t)99U)
#define PCR_PIN100              ((uint8_t)100U)
#define PCR_PIN101              ((uint8_t)101U)
#define PCR_PIN102              ((uint8_t)102U)
#define PCR_PIN103              ((uint8_t)103U)
#define PCR_PIN104              ((uint8_t)104U)
#define PCR_PIN105              ((uint8_t)105U)
#define PCR_PIN106              ((uint8_t)106U)
#define PCR_PIN107              ((uint8_t)107U)
#define PCR_PIN108              ((uint8_t)108U)
#define PCR_PIN109              ((uint8_t)109U)
#define PCR_PIN110              ((uint8_t)110U)
#define PCR_PIN111              ((uint8_t)111U)
#define PCR_PIN112              ((uint8_t)112U)
#define PCR_PIN113              ((uint8_t)113U)
#define PCR_PIN114              ((uint8_t)114U)
#define PCR_PIN115              ((uint8_t)115U)
#define PCR_PIN116              ((uint8_t)116U)
#define PCR_PIN117              ((uint8_t)117U)
#define PCR_PIN118              ((uint8_t)118U)
#define PCR_PIN119              ((uint8_t)119U)
#define PCR_PIN120              ((uint8_t)120U)
#define PCR_PIN121              ((uint8_t)121U)
#define PCR_PIN122              ((uint8_t)122U)
#define PCR_PIN123              ((uint8_t)123U)
#define PCR_PIN124              ((uint8_t)124U)
#define PCR_PIN125              ((uint8_t)125U)
#define PCR_PIN126              ((uint8_t)126U)
#define PCR_PIN127              ((uint8_t)127U)
#define PCR_PIN128              ((uint8_t)128U)
#define PCR_PIN129              ((uint8_t)129U)
#define PCR_PIN130              ((uint8_t)130U)
#define PCR_PIN131              ((uint8_t)131U)
#define PCR_PIN132              ((uint8_t)132U)
#define PCR_PIN133              ((uint8_t)133U)
#define PCR_PIN134              ((uint8_t)134U)
#define PCR_PIN135              ((uint8_t)135U)
#define PCR_PIN136              ((uint8_t)136U)
#define PCR_PIN137              ((uint8_t)137U)
#define PCR_PIN138              ((uint8_t)138U)
#define PCR_PIN139              ((uint8_t)139U)
#define PCR_PIN140              ((uint8_t)140U)
#define PCR_PIN141              ((uint8_t)141U)
#define PCR_PIN142              ((uint8_t)142U)
#define PCR_PIN143              ((uint8_t)143U)
#define PCR_PIN144              ((uint8_t)144U)
#define PCR_PIN145              ((uint8_t)145U)
#define PCR_PIN146              ((uint8_t)146U)
#define PCR_PIN147              ((uint8_t)147U)
#define PCR_PIN148              ((uint8_t)148U)

/*
* @brief    PortA PCR Number.
**/
#define PA0_PCR                 PCR_PIN0
#define PA1_PCR                 PCR_PIN1
#define PA2_PCR                 PCR_PIN2
#define PA3_PCR                 PCR_PIN3
#define PA4_PCR                 PCR_PIN4
#define PA5_PCR                 PCR_PIN5
#define PA6_PCR                 PCR_PIN6
#define PA7_PCR                 PCR_PIN7
#define PA8_PCR                 PCR_PIN8
#define PA9_PCR                 PCR_PIN9
#define PA10_PCR                PCR_PIN10
#define PA11_PCR                PCR_PIN11
#define PA12_PCR                PCR_PIN12
#define PA13_PCR                PCR_PIN13
#define PA14_PCR                PCR_PIN14
#define PA15_PCR                PCR_PIN15

/*
* @brief    PortB PCR Number.
**/
#define PB0_PCR                 PCR_PIN16
#define PB1_PCR                 PCR_PIN17
#define PB2_PCR                 PCR_PIN18
#define PB3_PCR                 PCR_PIN19
#define PB4_PCR                 PCR_PIN20
#define PB5_PCR                 PCR_PIN21
#define PB6_PCR                 PCR_PIN22
#define PB7_PCR                 PCR_PIN23
#define PB8_PCR                 PCR_PIN24
#define PB9_PCR                 PCR_PIN25
#define PB10_PCR                PCR_PIN26
#define PB11_PCR                PCR_PIN27
#define PB12_PCR                PCR_PIN28
#define PB13_PCR                PCR_PIN29
#define PB14_PCR                PCR_PIN30
#define PB15_PCR                PCR_PIN31

/*
* @brief    PortC PCR Number.
**/
#define PC0_PCR                 PCR_PIN32
#define PC1_PCR                 PCR_PIN33
#define PC2_PCR                 PCR_PIN34
#define PC3_PCR                 PCR_PIN35
#define PC4_PCR                 PCR_PIN36
#define PC5_PCR                 PCR_PIN37
#define PC6_PCR                 PCR_PIN38
#define PC7_PCR                 PCR_PIN39
#define PC8_PCR                 PCR_PIN40
#define PC9_PCR                 PCR_PIN41
#define PC10_PCR                PCR_PIN42
#define PC11_PCR                PCR_PIN43
#define PC12_PCR                PCR_PIN44
#define PC13_PCR                PCR_PIN45
#define PC14_PCR                PCR_PIN46
#define PC15_PCR                PCR_PIN47

/*
* @brief    PortD PCR Number.
**/
#define PD0_PCR                 PCR_PIN48
#define PD1_PCR                 PCR_PIN49
#define PD2_PCR                 PCR_PIN50
#define PD3_PCR                 PCR_PIN51
#define PD4_PCR                 PCR_PIN52
#define PD5_PCR                 PCR_PIN53
#define PD6_PCR                 PCR_PIN54
#define PD7_PCR                 PCR_PIN55
#define PD8_PCR                 PCR_PIN56
#define PD9_PCR                 PCR_PIN57
#define PD10_PCR                PCR_PIN58
#define PD11_PCR                PCR_PIN59
#define PD12_PCR                PCR_PIN60
#define PD13_PCR                PCR_PIN61
#define PD14_PCR                PCR_PIN62
#define PD15_PCR                PCR_PIN63

/*
* @brief    PortE PCR Number.
**/
#define PE0_PCR                 PCR_PIN64
#define PE1_PCR                 PCR_PIN65
#define PE2_PCR                 PCR_PIN66
#define PE3_PCR                 PCR_PIN67
#define PE4_PCR                 PCR_PIN68
#define PE5_PCR                 PCR_PIN69
#define PE6_PCR                 PCR_PIN70
#define PE7_PCR                 PCR_PIN71
#define PE8_PCR                 PCR_PIN72
#define PE9_PCR                 PCR_PIN73
#define PE10_PCR                PCR_PIN74
#define PE11_PCR                PCR_PIN75
#define PE12_PCR                PCR_PIN76
#define PE13_PCR                PCR_PIN77
#define PE14_PCR                PCR_PIN78
#define PE15_PCR                PCR_PIN79

/*
* @brief    PortF PCR Number.
**/
#define PF0_PCR                 PCR_PIN80
#define PF1_PCR                 PCR_PIN81
#define PF2_PCR                 PCR_PIN82
#define PF3_PCR                 PCR_PIN83
#define PF4_PCR                 PCR_PIN84
#define PF5_PCR                 PCR_PIN85
#define PF6_PCR                 PCR_PIN86
#define PF7_PCR                 PCR_PIN87
#define PF8_PCR                 PCR_PIN88
#define PF9_PCR                 PCR_PIN89
#define PF10_PCR                PCR_PIN90
#define PF11_PCR                PCR_PIN91
#define PF12_PCR                PCR_PIN92
#define PF13_PCR                PCR_PIN93
#define PF14_PCR                PCR_PIN94
#define PF15_PCR                PCR_PIN95

/*
* @brief    PortG PCR Number.
**/
#define PG0_PCR                 PCR_PIN96
#define PG1_PCR                 PCR_PIN97
#define PG2_PCR                 PCR_PIN98
#define PG3_PCR                 PCR_PIN99
#define PG4_PCR                 PCR_PIN100
#define PG5_PCR                 PCR_PIN101
#define PG6_PCR                 PCR_PIN102
#define PG7_PCR                 PCR_PIN103
#define PG8_PCR                 PCR_PIN104
#define PG9_PCR                 PCR_PIN105
#define PG10_PCR                PCR_PIN106
#define PG11_PCR                PCR_PIN107
#define PG12_PCR                PCR_PIN108
#define PG13_PCR                PCR_PIN109
#define PG14_PCR                PCR_PIN110
#define PG15_PCR                PCR_PIN111

/*
* @brief    PortH PCR Number.
**/
#define PH0_PCR                 PCR_PIN112
#define PH1_PCR                 PCR_PIN113
#define PH2_PCR                 PCR_PIN114
#define PH3_PCR                 PCR_PIN115
#define PH4_PCR                 PCR_PIN116
#define PH5_PCR                 PCR_PIN117
#define PH6_PCR                 PCR_PIN118
#define PH7_PCR                 PCR_PIN119
#define PH8_PCR                 PCR_PIN120
#define PH9_PCR                 PCR_PIN121
#define PH10_PCR                PCR_PIN122
#define PH11_PCR                PCR_PIN123
#define PH12_PCR                PCR_PIN124
#define PH13_PCR                PCR_PIN125
#define PH14_PCR                PCR_PIN126
#define PH15_PCR                PCR_PIN127

/*
* @brief    PortI PCR Number.
**/
#define PI0_PCR                 PCR_PIN128
#define PI1_PCR                 PCR_PIN129
#define PI2_PCR                 PCR_PIN130
#define PI3_PCR                 PCR_PIN131
#define PI4_PCR                 PCR_PIN132
#define PI5_PCR                 PCR_PIN133
#define PI6_PCR                 PCR_PIN134
#define PI7_PCR                 PCR_PIN135
#define PI8_PCR                 PCR_PIN136
#define PI9_PCR                 PCR_PIN137
#define PI10_PCR                PCR_PIN138
#define PI11_PCR                PCR_PIN139
#define PI12_PCR                PCR_PIN140
#define PI13_PCR                PCR_PIN141
#define PI14_PCR                PCR_PIN142
#define PI15_PCR                PCR_PIN143

/*
* @brief    PortJ PCR Number.
**/
#define PJ0_PCR                 PCR_PIN144
#define PJ1_PCR                 PCR_PIN145
#define PJ2_PCR                 PCR_PIN146
#define PJ3_PCR                 PCR_PIN147
#define PJ4_PCR                 PCR_PIN148

/******************************************************************************
* @brief    Pad Selection for Multiplexed Inputs Registers (PSMI0_3-PSMI68_71)
*******************************************************************************/
#define PSMI0_CAN1RX            ((uint8_t)0U)
#define PSMI1_CAN2RX            ((uint8_t)1U)
#define PSMI2_CAN3RX            ((uint8_t)2U)
#define PSMI3_CAN4RX            ((uint8_t)3U)
#define PSMI4_CAN5RX            ((uint8_t)4U)
#define PSMI5_SCK_0             ((uint8_t)5U)
#define PSMI6_CS0_0             ((uint8_t)6U)
#define PSMI7_SCK_1             ((uint8_t)7U)
#define PSMI8_SIN_1             ((uint8_t)8U)
#define PSMI9_CS0_1             ((uint8_t)9U)
#define PSMI10_SCK_2            ((uint8_t)10U)
#define PSMI11_SIN_2            ((uint8_t)11U)
#define PSMI12_CS0_2            ((uint8_t)12U)
#define PSMI13_E0UC3            ((uint8_t)13U)
#define PSMI14_E0UC4            ((uint8_t)14U)
#define PSMI15_E0UC5            ((uint8_t)15U)
#define PSMI16_E0UC6            ((uint8_t)16U)
#define PSMI17_E0UC7            ((uint8_t)17U)
#define PSMI18_E0UC10           ((uint8_t)18U)
#define PSMI19_E0UC11           ((uint8_t)19U)
#define PSMI20_E0UC12           ((uint8_t)20U)
#define PSMI21_E0UC13           ((uint8_t)21U)
#define PSMI22_E0UC14           ((uint8_t)22U)
#define PSMI23_E0UC22           ((uint8_t)23U)
#define PSMI24_E0UC23           ((uint8_t)24U)
#define PSMI25_E0UC24           ((uint8_t)25U)
#define PSMI26_E0UC25           ((uint8_t)26U)
#define PSMI27_E0UC26           ((uint8_t)27U)
#define PSMI28_E0UC27           ((uint8_t)28U)
#define PSMI29_SCL_0            ((uint8_t)29U)
#define PSMI30_SDA_0            ((uint8_t)30U)
#define PSMI31_LIN3RX           ((uint8_t)31U)
#define PSMI32_SCK_3            ((uint8_t)32U)
#define PSMI33_SIN_3            ((uint8_t)33U)
#define PSMI34_CS0_3            ((uint8_t)34U)
#define PSMI35_SCK_4            ((uint8_t)35U)
#define PSMI36_SIN_4            ((uint8_t)36U)
#define PSMI37_CS0_4            ((uint8_t)37U)
#define PSMI38_E0UC0            ((uint8_t)38U)
#define PSMI39_E0UC1            ((uint8_t)39U)
#define PSMI40_E0UC28           ((uint8_t)40U)
#define PSMI41_E0UC29           ((uint8_t)41U)
#define PSMI42_E0UC30           ((uint8_t)42U)
#define PSMI43_E0UC31           ((uint8_t)43U)
#define PSMI44_E1UC1            ((uint8_t)44U)
#define PSMI45_E1UC2            ((uint8_t)45U)
#define PSMI46_E1UC3            ((uint8_t)46U)
#define PSMI47_E1UC4            ((uint8_t)47U)
#define PSMI48_E1UC5            ((uint8_t)48U)
#define PSMI49_E1UC17           ((uint8_t)49U)
#define PSMI50_E1UC18           ((uint8_t)50U)
#define PSMI51_E1UC25           ((uint8_t)51U)
#define PSMI52_E1UC26           ((uint8_t)52U)
#define PSMI53_E1UC27           ((uint8_t)53U)
#define PSMI54_E1UC28           ((uint8_t)54U)
#define PSMI55_E1UC29           ((uint8_t)55U)
#define PSMI56_E1UC30           ((uint8_t)56U)
#define PSMI57_E1UC31           ((uint8_t)57U)
#define PSMI58_LIN2RX           ((uint8_t)58U)
#define PSMI59_LIN4RX           ((uint8_t)59U)
#define PSMI60_LIN5RX           ((uint8_t)60U)
#define PSMI61_LIN8RX           ((uint8_t)61U)
#define PSMI62_LIN0RX           ((uint8_t)62U)
#define PSMI63_SCL_1            ((uint8_t)63U)
#define PSMI64_SDA_1            ((uint8_t)64U)
#define PSMI65_SCL_2            ((uint8_t)65U)
#define PSMI66_SDA_2            ((uint8_t)66U)
#define PSMI67_SCL_3            ((uint8_t)67U)
#define PSMI68_SDA_3            ((uint8_t)68U)
#define PSMI69_CAN6RX           ((uint8_t)69U)
#define PSMI70_CAN7RX           ((uint8_t)70U)
#define PSMI71_LIN9RX           ((uint8_t)71U)

/****************************************************************
* @brief    IMUX Select Register 0
* @details  eTPU[x] input channel
*           This bit stores the data to be driven out on the
*           external GPIO pad controlled by this register.
* @param    0 eTPUx channel input pad
* @param    1 DSPI8 Serialized input x+32
*****************************************************************/
#define IMUX_ISEL0_MASK         ((uint32_t)0xFFFFFFFFUL)

/****************************************************************
* @brief    IMUX Select Register 1
* @details  eMIOS[x] input channel
* @param    0 eMIOSx channel input pad
* @param    1 DSPI8 Serialized input x
*****************************************************************/
#define IMUX_ISEL1_MASK         ((uint32_t)0xFFFFFFFFUL)

/****************************************************************
* @brief    GPIO Pad Data Output Registers (GPDO0_3-GPDO148_151)
* @param    Write 0: GPDO_OUT_LOW
* @param    Write 1: GPDO_OUT_HIGH
*****************************************************************/
#define GPDO_OUT_LOW            ((uint8_t)0x00U)
#define GPDO_OUT_HIGH           ((uint8_t)0x01U)

/****************************************************************
* @brief    GPIO Pad Data Input Registers (GPDI0_3-GPDI148_151)
* @param    Read 0: GPDI_IN_LOW
* @param    Read 1: GPDI_IN_HIGH
*****************************************************************/
#define GPDI_IN_LOW             ((uint8_t)0x00U)
#define GPDI_IN_HIGH            ((uint8_t)0x01U)

/****************************************************************
* @brief    Parallel GPIO Pad Data Out Registers (PGPDO0-PGPDO4)
*           Parallel GPIO Pad Data In Registers (PGPDI0-PGPDI4)
*****************************************************************/
/* SIUL Parallel GPIO Pad Data Out/In 0 */
#define PGPD0_PB15              ((uint32_t)0x00000001UL)
#define PGPD0_PB14              ((uint32_t)0x00000002UL)
#define PGPD0_PB13              ((uint32_t)0x00000004UL)
#define PGPD0_PB12              ((uint32_t)0x00000008UL)
#define PGPD0_PB11              ((uint32_t)0x00000010UL)
#define PGPD0_PB10              ((uint32_t)0x00000020UL)
#define PGPD0_PB9               ((uint32_t)0x00000040UL)
#define PGPD0_PB8               ((uint32_t)0x00000080UL)
#define PGPD0_PB7               ((uint32_t)0x00000100UL)
#define PGPD0_PB6               ((uint32_t)0x00000200UL)
#define PGPD0_PB5               ((uint32_t)0x00000400UL)
#define PGPD0_PB4               ((uint32_t)0x00000800UL)
#define PGPD0_PB3               ((uint32_t)0x00001000UL)
#define PGPD0_PB2               ((uint32_t)0x00002000UL)
#define PGPD0_PB1               ((uint32_t)0x00004000UL)
#define PGPD0_PB0               ((uint32_t)0x00008000UL)
#define PGPD0_PA15              ((uint32_t)0x00010000UL)
#define PGPD0_PA14              ((uint32_t)0x00020000UL)
#define PGPD0_PA13              ((uint32_t)0x00040000UL)
#define PGPD0_PA12              ((uint32_t)0x00080000UL)
#define PGPD0_PA11              ((uint32_t)0x00100000UL)
#define PGPD0_PA10              ((uint32_t)0x00200000UL)
#define PGPD0_PA9               ((uint32_t)0x00400000UL)
#define PGPD0_PA8               ((uint32_t)0x00800000UL)
#define PGPD0_PA7               ((uint32_t)0x01000000UL)
#define PGPD0_PA6               ((uint32_t)0x02000000UL)
#define PGPD0_PA5               ((uint32_t)0x04000000UL)
#define PGPD0_PA4               ((uint32_t)0x08000000UL)
#define PGPD0_PA3               ((uint32_t)0x10000000UL)
#define PGPD0_PA2               ((uint32_t)0x20000000UL)
#define PGPD0_PA1               ((uint32_t)0x40000000UL)
#define PGPD0_PA0               ((uint32_t)0x80000000UL)

/* SIUL Parallel GPIO Pad Data Out/In 1 */
#define PGPD1_PD15              ((uint32_t)0x00000001UL)
#define PGPD1_PD14              ((uint32_t)0x00000002UL)
#define PGPD1_PD13              ((uint32_t)0x00000004UL)
#define PGPD1_PD12              ((uint32_t)0x00000008UL)
#define PGPD1_PD11              ((uint32_t)0x00000010UL)
#define PGPD1_PD10              ((uint32_t)0x00000020UL)
#define PGPD1_PD9               ((uint32_t)0x00000040UL)
#define PGPD1_PD8               ((uint32_t)0x00000080UL)
#define PGPD1_PD7               ((uint32_t)0x00000100UL)
#define PGPD1_PD6               ((uint32_t)0x00000200UL)
#define PGPD1_PD5               ((uint32_t)0x00000400UL)
#define PGPD1_PD4               ((uint32_t)0x00000800UL)
#define PGPD1_PD3               ((uint32_t)0x00001000UL)
#define PGPD1_PD2               ((uint32_t)0x00002000UL)
#define PGPD1_PD1               ((uint32_t)0x00004000UL)
#define PGPD1_PD0               ((uint32_t)0x00008000UL)
#define PGPD1_PC15              ((uint32_t)0x00010000UL)
#define PGPD1_PC14              ((uint32_t)0x00020000UL)
#define PGPD1_PC13              ((uint32_t)0x00040000UL)
#define PGPD1_PC12              ((uint32_t)0x00080000UL)
#define PGPD1_PC11              ((uint32_t)0x00100000UL)
#define PGPD1_PC10              ((uint32_t)0x00200000UL)
#define PGPD1_PC9               ((uint32_t)0x00400000UL)
#define PGPD1_PC8               ((uint32_t)0x00800000UL)
#define PGPD1_PC7               ((uint32_t)0x01000000UL)
#define PGPD1_PC6               ((uint32_t)0x02000000UL)
#define PGPD1_PC5               ((uint32_t)0x04000000UL)
#define PGPD1_PC4               ((uint32_t)0x08000000UL)
#define PGPD1_PC3               ((uint32_t)0x10000000UL)
#define PGPD1_PC2               ((uint32_t)0x20000000UL)
#define PGPD1_PC1               ((uint32_t)0x40000000UL)
#define PGPD1_PC0               ((uint32_t)0x80000000UL)

/* SIUL Parallel GPIO Pad Data Out/In 2 */
#define PGPD2_PF15              ((uint32_t)0x00000001UL)
#define PGPD2_PF14              ((uint32_t)0x00000002UL)
#define PGPD2_PF13              ((uint32_t)0x00000004UL)
#define PGPD2_PF12              ((uint32_t)0x00000008UL)
#define PGPD2_PF11              ((uint32_t)0x00000010UL)
#define PGPD2_PF10              ((uint32_t)0x00000020UL)
#define PGPD2_PF9               ((uint32_t)0x00000040UL)
#define PGPD2_PF8               ((uint32_t)0x00000080UL)
#define PGPD2_PF7               ((uint32_t)0x00000100UL)
#define PGPD2_PF6               ((uint32_t)0x00000200UL)
#define PGPD2_PF5               ((uint32_t)0x00000400UL)
#define PGPD2_PF4               ((uint32_t)0x00000800UL)
#define PGPD2_PF3               ((uint32_t)0x00001000UL)
#define PGPD2_PF2               ((uint32_t)0x00002000UL)
#define PGPD2_PF1               ((uint32_t)0x00004000UL)
#define PGPD2_PF0               ((uint32_t)0x00008000UL)
#define PGPD2_PE15              ((uint32_t)0x00010000UL)
#define PGPD2_PE14              ((uint32_t)0x00020000UL)
#define PGPD2_PE13              ((uint32_t)0x00040000UL)
#define PGPD2_PE12              ((uint32_t)0x00080000UL)
#define PGPD2_PE11              ((uint32_t)0x00100000UL)
#define PGPD2_PE10              ((uint32_t)0x00200000UL)
#define PGPD2_PE9               ((uint32_t)0x00400000UL)
#define PGPD2_PE8               ((uint32_t)0x00800000UL)
#define PGPD2_PE7               ((uint32_t)0x01000000UL)
#define PGPD2_PE6               ((uint32_t)0x02000000UL)
#define PGPD2_PE5               ((uint32_t)0x04000000UL)
#define PGPD2_PE4               ((uint32_t)0x08000000UL)
#define PGPD2_PE3               ((uint32_t)0x10000000UL)
#define PGPD2_PE2               ((uint32_t)0x20000000UL)
#define PGPD2_PE1               ((uint32_t)0x40000000UL)
#define PGPD2_PE0               ((uint32_t)0x80000000UL)

/* SIUL Parallel GPIO Pad Data Out/In 3 */
#define PGPD3_PH15              ((uint32_t)0x00000001UL)
#define PGPD3_PH14              ((uint32_t)0x00000002UL)
#define PGPD3_PH13              ((uint32_t)0x00000004UL)
#define PGPD3_PH12              ((uint32_t)0x00000008UL)
#define PGPD3_PH11              ((uint32_t)0x00000010UL)
#define PGPD3_PH10              ((uint32_t)0x00000020UL)
#define PGPD3_PH9               ((uint32_t)0x00000040UL)
#define PGPD3_PH8               ((uint32_t)0x00000080UL)
#define PGPD3_PH7               ((uint32_t)0x00000100UL)
#define PGPD3_PH6               ((uint32_t)0x00000200UL)
#define PGPD3_PH5               ((uint32_t)0x00000400UL)
#define PGPD3_PH4               ((uint32_t)0x00000800UL)
#define PGPD3_PH3               ((uint32_t)0x00001000UL)
#define PGPD3_PH2               ((uint32_t)0x00002000UL)
#define PGPD3_PH1               ((uint32_t)0x00004000UL)
#define PGPD3_PH0               ((uint32_t)0x00008000UL)
#define PGPD3_PG15              ((uint32_t)0x00010000UL)
#define PGPD3_PG14              ((uint32_t)0x00020000UL)
#define PGPD3_PG13              ((uint32_t)0x00040000UL)
#define PGPD3_PG12              ((uint32_t)0x00080000UL)
#define PGPD3_PG11              ((uint32_t)0x00100000UL)
#define PGPD3_PG10              ((uint32_t)0x00200000UL)
#define PGPD3_PG9               ((uint32_t)0x00400000UL)
#define PGPD3_PG8               ((uint32_t)0x00800000UL)
#define PGPD3_PG7               ((uint32_t)0x01000000UL)
#define PGPD3_PG6               ((uint32_t)0x02000000UL)
#define PGPD3_PG5               ((uint32_t)0x04000000UL)
#define PGPD3_PG4               ((uint32_t)0x08000000UL)
#define PGPD3_PG3               ((uint32_t)0x10000000UL)
#define PGPD3_PG2               ((uint32_t)0x20000000UL)
#define PGPD3_PG1               ((uint32_t)0x40000000UL)
#define PGPD3_PG0               ((uint32_t)0x80000000UL)

/* SIUL Parallel GPIO Pad Data Out/In 4 */
#define PGPD4_PJ4               ((uint32_t)0x00000800UL)
#define PGPD4_PJ3               ((uint32_t)0x00001000UL)
#define PGPD4_PJ2               ((uint32_t)0x00002000UL)
#define PGPD4_PJ1               ((uint32_t)0x00004000UL)
#define PGPD4_PJ0               ((uint32_t)0x00008000UL)
#define PGPD4_PI15              ((uint32_t)0x00010000UL)
#define PGPD4_PI14              ((uint32_t)0x00020000UL)
#define PGPD4_PI13              ((uint32_t)0x00040000UL)
#define PGPD4_PI12              ((uint32_t)0x00080000UL)
#define PGPD4_PI11              ((uint32_t)0x00100000UL)
#define PGPD4_PI10              ((uint32_t)0x00200000UL)
#define PGPD4_PI9               ((uint32_t)0x00400000UL)
#define PGPD4_PI8               ((uint32_t)0x00800000UL)
#define PGPD4_PI7               ((uint32_t)0x01000000UL)
#define PGPD4_PI6               ((uint32_t)0x02000000UL)
#define PGPD4_PI5               ((uint32_t)0x04000000UL)
#define PGPD4_PI4               ((uint32_t)0x08000000UL)
#define PGPD4_PI3               ((uint32_t)0x10000000UL)
#define PGPD4_PI2               ((uint32_t)0x20000000UL)
#define PGPD4_PI1               ((uint32_t)0x40000000UL)
#define PGPD4_PI0               ((uint32_t)0x80000000UL)

/************************************************************************
* @brief    Masked Parallel GPIO Pad Data Out Register (MPGPDO0-MPGPDO9)
*************************************************************************/
/* Masked Parallel GPIO Pad Data Out 0 (DATA and MASK) */
#define MPGPDO0_DATA_PA15       ((uint32_t)0x00000001UL)
#define MPGPDO0_DATA_PA14       ((uint32_t)0x00000002UL)
#define MPGPDO0_DATA_PA13       ((uint32_t)0x00000004UL)
#define MPGPDO0_DATA_PA12       ((uint32_t)0x00000008UL)
#define MPGPDO0_DATA_PA11       ((uint32_t)0x00000010UL)
#define MPGPDO0_DATA_PA10       ((uint32_t)0x00000020UL)
#define MPGPDO0_DATA_PA9        ((uint32_t)0x00000040UL)
#define MPGPDO0_DATA_PA8        ((uint32_t)0x00000080UL)
#define MPGPDO0_DATA_PA7        ((uint32_t)0x00000100UL)
#define MPGPDO0_DATA_PA6        ((uint32_t)0x00000200UL)
#define MPGPDO0_DATA_PA5        ((uint32_t)0x00000400UL)
#define MPGPDO0_DATA_PA4        ((uint32_t)0x00000800UL)
#define MPGPDO0_DATA_PA3        ((uint32_t)0x00001000UL)
#define MPGPDO0_DATA_PA2        ((uint32_t)0x00002000UL)
#define MPGPDO0_DATA_PA1        ((uint32_t)0x00004000UL)
#define MPGPDO0_DATA_PA0        ((uint32_t)0x00008000UL)
#define MPGPDO0_MASK_PA15       ((uint32_t)0x00010000UL)
#define MPGPDO0_MASK_PA14       ((uint32_t)0x00020000UL)
#define MPGPDO0_MASK_PA13       ((uint32_t)0x00040000UL)
#define MPGPDO0_MASK_PA12       ((uint32_t)0x00080000UL)
#define MPGPDO0_MASK_PA11       ((uint32_t)0x00100000UL)
#define MPGPDO0_MASK_PA10       ((uint32_t)0x00200000UL)
#define MPGPDO0_MASK_PA9        ((uint32_t)0x00400000UL)
#define MPGPDO0_MASK_PA8        ((uint32_t)0x00800000UL)
#define MPGPDO0_MASK_PA7        ((uint32_t)0x01000000UL)
#define MPGPDO0_MASK_PA6        ((uint32_t)0x02000000UL)
#define MPGPDO0_MASK_PA5        ((uint32_t)0x04000000UL)
#define MPGPDO0_MASK_PA4        ((uint32_t)0x08000000UL)
#define MPGPDO0_MASK_PA3        ((uint32_t)0x10000000UL)
#define MPGPDO0_MASK_PA2        ((uint32_t)0x20000000UL)
#define MPGPDO0_MASK_PA1        ((uint32_t)0x40000000UL)
#define MPGPDO0_MASK_PA0        ((uint32_t)0x80000000UL)

/* Masked Parallel GPIO Pad Data Out 1 (DATA and MASK) */
#define MPGPDO1_DATA_PB15       ((uint32_t)0x00000001UL)
#define MPGPDO1_DATA_PB14       ((uint32_t)0x00000002UL)
#define MPGPDO1_DATA_PB13       ((uint32_t)0x00000004UL)
#define MPGPDO1_DATA_PB12       ((uint32_t)0x00000008UL)
#define MPGPDO1_DATA_PB11       ((uint32_t)0x00000010UL)
#define MPGPDO1_DATA_PB10       ((uint32_t)0x00000020UL)
#define MPGPDO1_DATA_PB9        ((uint32_t)0x00000040UL)
#define MPGPDO1_DATA_PB8        ((uint32_t)0x00000080UL)
#define MPGPDO1_DATA_PB7        ((uint32_t)0x00000100UL)
#define MPGPDO1_DATA_PB6        ((uint32_t)0x00000200UL)
#define MPGPDO1_DATA_PB5        ((uint32_t)0x00000400UL)
#define MPGPDO1_DATA_PB4        ((uint32_t)0x00000800UL)
#define MPGPDO1_DATA_PB3        ((uint32_t)0x00001000UL)
#define MPGPDO1_DATA_PB2        ((uint32_t)0x00002000UL)
#define MPGPDO1_DATA_PB1        ((uint32_t)0x00004000UL)
#define MPGPDO1_DATA_PB0        ((uint32_t)0x00008000UL)
#define MPGPDO1_MASK_PB15       ((uint32_t)0x00010000UL)
#define MPGPDO1_MASK_PB14       ((uint32_t)0x00020000UL)
#define MPGPDO1_MASK_PB13       ((uint32_t)0x00040000UL)
#define MPGPDO1_MASK_PB12       ((uint32_t)0x00080000UL)
#define MPGPDO1_MASK_PB11       ((uint32_t)0x00100000UL)
#define MPGPDO1_MASK_PB10       ((uint32_t)0x00200000UL)
#define MPGPDO1_MASK_PB9        ((uint32_t)0x00400000UL)
#define MPGPDO1_MASK_PB8        ((uint32_t)0x00800000UL)
#define MPGPDO1_MASK_PB7        ((uint32_t)0x01000000UL)
#define MPGPDO1_MASK_PB6        ((uint32_t)0x02000000UL)
#define MPGPDO1_MASK_PB5        ((uint32_t)0x04000000UL)
#define MPGPDO1_MASK_PB4        ((uint32_t)0x08000000UL)
#define MPGPDO1_MASK_PB3        ((uint32_t)0x10000000UL)
#define MPGPDO1_MASK_PB2        ((uint32_t)0x20000000UL)
#define MPGPDO1_MASK_PB1        ((uint32_t)0x40000000UL)
#define MPGPDO1_MASK_PB0        ((uint32_t)0x80000000UL)

/* Masked Parallel GPIO Pad Data Out 2 (DATA and MASK) */
#define MPGPDO2_DATA_PC15       ((uint32_t)0x00000001UL)
#define MPGPDO2_DATA_PC14       ((uint32_t)0x00000002UL)
#define MPGPDO2_DATA_PC13       ((uint32_t)0x00000004UL)
#define MPGPDO2_DATA_PC12       ((uint32_t)0x00000008UL)
#define MPGPDO2_DATA_PC11       ((uint32_t)0x00000010UL)
#define MPGPDO2_DATA_PC10       ((uint32_t)0x00000020UL)
#define MPGPDO2_DATA_PC9        ((uint32_t)0x00000040UL)
#define MPGPDO2_DATA_PC8        ((uint32_t)0x00000080UL)
#define MPGPDO2_DATA_PC7        ((uint32_t)0x00000100UL)
#define MPGPDO2_DATA_PC6        ((uint32_t)0x00000200UL)
#define MPGPDO2_DATA_PC5        ((uint32_t)0x00000400UL)
#define MPGPDO2_DATA_PC4        ((uint32_t)0x00000800UL)
#define MPGPDO2_DATA_PC3        ((uint32_t)0x00001000UL)
#define MPGPDO2_DATA_PC2        ((uint32_t)0x00002000UL)
#define MPGPDO2_DATA_PC1        ((uint32_t)0x00004000UL)
#define MPGPDO2_DATA_PC0        ((uint32_t)0x00008000UL)
#define MPGPDO2_MASK_PC15       ((uint32_t)0x00010000UL)
#define MPGPDO2_MASK_PC14       ((uint32_t)0x00020000UL)
#define MPGPDO2_MASK_PC13       ((uint32_t)0x00040000UL)
#define MPGPDO2_MASK_PC12       ((uint32_t)0x00080000UL)
#define MPGPDO2_MASK_PC11       ((uint32_t)0x00100000UL)
#define MPGPDO2_MASK_PC10       ((uint32_t)0x00200000UL)
#define MPGPDO2_MASK_PC9        ((uint32_t)0x00400000UL)
#define MPGPDO2_MASK_PC8        ((uint32_t)0x00800000UL)
#define MPGPDO2_MASK_PC7        ((uint32_t)0x01000000UL)
#define MPGPDO2_MASK_PC6        ((uint32_t)0x02000000UL)
#define MPGPDO2_MASK_PC5        ((uint32_t)0x04000000UL)
#define MPGPDO2_MASK_PC4        ((uint32_t)0x08000000UL)
#define MPGPDO2_MASK_PC3        ((uint32_t)0x10000000UL)
#define MPGPDO2_MASK_PC2        ((uint32_t)0x20000000UL)
#define MPGPDO2_MASK_PC1        ((uint32_t)0x40000000UL)
#define MPGPDO2_MASK_PC0        ((uint32_t)0x80000000UL)

/* Masked Parallel GPIO Pad Data Out 3 (DATA and MASK) */
#define MPGPDO3_DATA_PD15       ((uint32_t)0x00000001UL)
#define MPGPDO3_DATA_PD14       ((uint32_t)0x00000002UL)
#define MPGPDO3_DATA_PD13       ((uint32_t)0x00000004UL)
#define MPGPDO3_DATA_PD12       ((uint32_t)0x00000008UL)
#define MPGPDO3_DATA_PD11       ((uint32_t)0x00000010UL)
#define MPGPDO3_DATA_PD10       ((uint32_t)0x00000020UL)
#define MPGPDO3_DATA_PD9        ((uint32_t)0x00000040UL)
#define MPGPDO3_DATA_PD8        ((uint32_t)0x00000080UL)
#define MPGPDO3_DATA_PD7        ((uint32_t)0x00000100UL)
#define MPGPDO3_DATA_PD6        ((uint32_t)0x00000200UL)
#define MPGPDO3_DATA_PD5        ((uint32_t)0x00000400UL)
#define MPGPDO3_DATA_PD4        ((uint32_t)0x00000800UL)
#define MPGPDO3_DATA_PD3        ((uint32_t)0x00001000UL)
#define MPGPDO3_DATA_PD2        ((uint32_t)0x00002000UL)
#define MPGPDO3_DATA_PD1        ((uint32_t)0x00004000UL)
#define MPGPDO3_DATA_PD0        ((uint32_t)0x00008000UL)
#define MPGPDO3_MASK_PD15       ((uint32_t)0x00010000UL)
#define MPGPDO3_MASK_PD14       ((uint32_t)0x00020000UL)
#define MPGPDO3_MASK_PD13       ((uint32_t)0x00040000UL)
#define MPGPDO3_MASK_PD12       ((uint32_t)0x00080000UL)
#define MPGPDO3_MASK_PD11       ((uint32_t)0x00100000UL)
#define MPGPDO3_MASK_PD10       ((uint32_t)0x00200000UL)
#define MPGPDO3_MASK_PD9        ((uint32_t)0x00400000UL)
#define MPGPDO3_MASK_PD8        ((uint32_t)0x00800000UL)
#define MPGPDO3_MASK_PD7        ((uint32_t)0x01000000UL)
#define MPGPDO3_MASK_PD6        ((uint32_t)0x02000000UL)
#define MPGPDO3_MASK_PD5        ((uint32_t)0x04000000UL)
#define MPGPDO3_MASK_PD4        ((uint32_t)0x08000000UL)
#define MPGPDO3_MASK_PD3        ((uint32_t)0x10000000UL)
#define MPGPDO3_MASK_PD2        ((uint32_t)0x20000000UL)
#define MPGPDO3_MASK_PD1        ((uint32_t)0x40000000UL)
#define MPGPDO3_MASK_PD0        ((uint32_t)0x80000000UL)

/* Masked Parallel GPIO Pad Data Out 4 (DATA and MASK) */
#define MPGPDO4_DATA_PE15       ((uint32_t)0x00000001UL)
#define MPGPDO4_DATA_PE14       ((uint32_t)0x00000002UL)
#define MPGPDO4_DATA_PE13       ((uint32_t)0x00000004UL)
#define MPGPDO4_DATA_PE12       ((uint32_t)0x00000008UL)
#define MPGPDO4_DATA_PE11       ((uint32_t)0x00000010UL)
#define MPGPDO4_DATA_PE10       ((uint32_t)0x00000020UL)
#define MPGPDO4_DATA_PE9        ((uint32_t)0x00000040UL)
#define MPGPDO4_DATA_PE8        ((uint32_t)0x00000080UL)
#define MPGPDO4_DATA_PE7        ((uint32_t)0x00000100UL)
#define MPGPDO4_DATA_PE6        ((uint32_t)0x00000200UL)
#define MPGPDO4_DATA_PE5        ((uint32_t)0x00000400UL)
#define MPGPDO4_DATA_PE4        ((uint32_t)0x00000800UL)
#define MPGPDO4_DATA_PE3        ((uint32_t)0x00001000UL)
#define MPGPDO4_DATA_PE2        ((uint32_t)0x00002000UL)
#define MPGPDO4_DATA_PE1        ((uint32_t)0x00004000UL)
#define MPGPDO4_DATA_PE0        ((uint32_t)0x00008000UL)
#define MPGPDO4_MASK_PE15       ((uint32_t)0x00010000UL)
#define MPGPDO4_MASK_PE14       ((uint32_t)0x00020000UL)
#define MPGPDO4_MASK_PE13       ((uint32_t)0x00040000UL)
#define MPGPDO4_MASK_PE12       ((uint32_t)0x00080000UL)
#define MPGPDO4_MASK_PE11       ((uint32_t)0x00100000UL)
#define MPGPDO4_MASK_PE10       ((uint32_t)0x00200000UL)
#define MPGPDO4_MASK_PE9        ((uint32_t)0x00400000UL)
#define MPGPDO4_MASK_PE8        ((uint32_t)0x00800000UL)
#define MPGPDO4_MASK_PE7        ((uint32_t)0x01000000UL)
#define MPGPDO4_MASK_PE6        ((uint32_t)0x02000000UL)
#define MPGPDO4_MASK_PE5        ((uint32_t)0x04000000UL)
#define MPGPDO4_MASK_PE4        ((uint32_t)0x08000000UL)
#define MPGPDO4_MASK_PE3        ((uint32_t)0x10000000UL)
#define MPGPDO4_MASK_PE2        ((uint32_t)0x20000000UL)
#define MPGPDO4_MASK_PE1        ((uint32_t)0x40000000UL)
#define MPGPDO4_MASK_PE0        ((uint32_t)0x80000000UL)

/* Masked Parallel GPIO Pad Data Out 5 (DATA and MASK) */
#define MPGPDO5_DATA_PF15       ((uint32_t)0x00000001UL)
#define MPGPDO5_DATA_PF14       ((uint32_t)0x00000002UL)
#define MPGPDO5_DATA_PF13       ((uint32_t)0x00000004UL)
#define MPGPDO5_DATA_PF12       ((uint32_t)0x00000008UL)
#define MPGPDO5_DATA_PF11       ((uint32_t)0x00000010UL)
#define MPGPDO5_DATA_PF10       ((uint32_t)0x00000020UL)
#define MPGPDO5_DATA_PF9        ((uint32_t)0x00000040UL)
#define MPGPDO5_DATA_PF8        ((uint32_t)0x00000080UL)
#define MPGPDO5_DATA_PF7        ((uint32_t)0x00000100UL)
#define MPGPDO5_DATA_PF6        ((uint32_t)0x00000200UL)
#define MPGPDO5_DATA_PF5        ((uint32_t)0x00000400UL)
#define MPGPDO5_DATA_PF4        ((uint32_t)0x00000800UL)
#define MPGPDO5_DATA_PF3        ((uint32_t)0x00001000UL)
#define MPGPDO5_DATA_PF2        ((uint32_t)0x00002000UL)
#define MPGPDO5_DATA_PF1        ((uint32_t)0x00004000UL)
#define MPGPDO5_DATA_PF0        ((uint32_t)0x00008000UL)
#define MPGPDO5_MASK_PF15       ((uint32_t)0x00010000UL)
#define MPGPDO5_MASK_PF14       ((uint32_t)0x00020000UL)
#define MPGPDO5_MASK_PF13       ((uint32_t)0x00040000UL)
#define MPGPDO5_MASK_PF12       ((uint32_t)0x00080000UL)
#define MPGPDO5_MASK_PF11       ((uint32_t)0x00100000UL)
#define MPGPDO5_MASK_PF10       ((uint32_t)0x00200000UL)
#define MPGPDO5_MASK_PF9        ((uint32_t)0x00400000UL)
#define MPGPDO5_MASK_PF8        ((uint32_t)0x00800000UL)
#define MPGPDO5_MASK_PF7        ((uint32_t)0x01000000UL)
#define MPGPDO5_MASK_PF6        ((uint32_t)0x02000000UL)
#define MPGPDO5_MASK_PF5        ((uint32_t)0x04000000UL)
#define MPGPDO5_MASK_PF4        ((uint32_t)0x08000000UL)
#define MPGPDO5_MASK_PF3        ((uint32_t)0x10000000UL)
#define MPGPDO5_MASK_PF2        ((uint32_t)0x20000000UL)
#define MPGPDO5_MASK_PF1        ((uint32_t)0x40000000UL)
#define MPGPDO5_MASK_PF0        ((uint32_t)0x80000000UL)

/* Masked Parallel GPIO Pad Data Out 6 (DATA and MASK) */
#define MPGPDO6_DATA_PG15       ((uint32_t)0x00000001UL)
#define MPGPDO6_DATA_PG14       ((uint32_t)0x00000002UL)
#define MPGPDO6_DATA_PG13       ((uint32_t)0x00000004UL)
#define MPGPDO6_DATA_PG12       ((uint32_t)0x00000008UL)
#define MPGPDO6_DATA_PG11       ((uint32_t)0x00000010UL)
#define MPGPDO6_DATA_PG10       ((uint32_t)0x00000020UL)
#define MPGPDO6_DATA_PG9        ((uint32_t)0x00000040UL)
#define MPGPDO6_DATA_PG8        ((uint32_t)0x00000080UL)
#define MPGPDO6_DATA_PG7        ((uint32_t)0x00000100UL)
#define MPGPDO6_DATA_PG6        ((uint32_t)0x00000200UL)
#define MPGPDO6_DATA_PG5        ((uint32_t)0x00000400UL)
#define MPGPDO6_DATA_PG4        ((uint32_t)0x00000800UL)
#define MPGPDO6_DATA_PG3        ((uint32_t)0x00001000UL)
#define MPGPDO6_DATA_PG2        ((uint32_t)0x00002000UL)
#define MPGPDO6_DATA_PG1        ((uint32_t)0x00004000UL)
#define MPGPDO6_DATA_PG0        ((uint32_t)0x00008000UL)
#define MPGPDO6_MASK_PG15       ((uint32_t)0x00010000UL)
#define MPGPDO6_MASK_PG14       ((uint32_t)0x00020000UL)
#define MPGPDO6_MASK_PG13       ((uint32_t)0x00040000UL)
#define MPGPDO6_MASK_PG12       ((uint32_t)0x00080000UL)
#define MPGPDO6_MASK_PG11       ((uint32_t)0x00100000UL)
#define MPGPDO6_MASK_PG10       ((uint32_t)0x00200000UL)
#define MPGPDO6_MASK_PG9        ((uint32_t)0x00400000UL)
#define MPGPDO6_MASK_PG8        ((uint32_t)0x00800000UL)
#define MPGPDO6_MASK_PG7        ((uint32_t)0x01000000UL)
#define MPGPDO6_MASK_PG6        ((uint32_t)0x02000000UL)
#define MPGPDO6_MASK_PG5        ((uint32_t)0x04000000UL)
#define MPGPDO6_MASK_PG4        ((uint32_t)0x08000000UL)
#define MPGPDO6_MASK_PG3        ((uint32_t)0x10000000UL)
#define MPGPDO6_MASK_PG2        ((uint32_t)0x20000000UL)
#define MPGPDO6_MASK_PG1        ((uint32_t)0x40000000UL)
#define MPGPDO6_MASK_PG0        ((uint32_t)0x80000000UL)

/* Masked Parallel GPIO Pad Data Out 7 (DATA and MASK) */
#define MPGPDO7_DATA_PH15       ((uint32_t)0x00000001UL)
#define MPGPDO7_DATA_PH14       ((uint32_t)0x00000002UL)
#define MPGPDO7_DATA_PH13       ((uint32_t)0x00000004UL)
#define MPGPDO7_DATA_PH12       ((uint32_t)0x00000008UL)
#define MPGPDO7_DATA_PH11       ((uint32_t)0x00000010UL)
#define MPGPDO7_DATA_PH10       ((uint32_t)0x00000020UL)
#define MPGPDO7_DATA_PH9        ((uint32_t)0x00000040UL)
#define MPGPDO7_DATA_PH8        ((uint32_t)0x00000080UL)
#define MPGPDO7_DATA_PH7        ((uint32_t)0x00000100UL)
#define MPGPDO7_DATA_PH6        ((uint32_t)0x00000200UL)
#define MPGPDO7_DATA_PH5        ((uint32_t)0x00000400UL)
#define MPGPDO7_DATA_PH4        ((uint32_t)0x00000800UL)
#define MPGPDO7_DATA_PH3        ((uint32_t)0x00001000UL)
#define MPGPDO7_DATA_PH2        ((uint32_t)0x00002000UL)
#define MPGPDO7_DATA_PH1        ((uint32_t)0x00004000UL)
#define MPGPDO7_DATA_PH0        ((uint32_t)0x00008000UL)
#define MPGPDO7_MASK_PH15       ((uint32_t)0x00010000UL)
#define MPGPDO7_MASK_PH14       ((uint32_t)0x00020000UL)
#define MPGPDO7_MASK_PH13       ((uint32_t)0x00040000UL)
#define MPGPDO7_MASK_PH12       ((uint32_t)0x00080000UL)
#define MPGPDO7_MASK_PH11       ((uint32_t)0x00100000UL)
#define MPGPDO7_MASK_PH10       ((uint32_t)0x00200000UL)
#define MPGPDO7_MASK_PH9        ((uint32_t)0x00400000UL)
#define MPGPDO7_MASK_PH8        ((uint32_t)0x00800000UL)
#define MPGPDO7_MASK_PH7        ((uint32_t)0x01000000UL)
#define MPGPDO7_MASK_PH6        ((uint32_t)0x02000000UL)
#define MPGPDO7_MASK_PH5        ((uint32_t)0x04000000UL)
#define MPGPDO7_MASK_PH4        ((uint32_t)0x08000000UL)
#define MPGPDO7_MASK_PH3        ((uint32_t)0x10000000UL)
#define MPGPDO7_MASK_PH2        ((uint32_t)0x20000000UL)
#define MPGPDO7_MASK_PH1        ((uint32_t)0x40000000UL)
#define MPGPDO7_MASK_PH0        ((uint32_t)0x80000000UL)

/* Masked Parallel GPIO Pad Data Out 8 (DATA and MASK) */
#define MPGPDO8_DATA_PI15       ((uint32_t)0x00000001UL)
#define MPGPDO8_DATA_PI14       ((uint32_t)0x00000002UL)
#define MPGPDO8_DATA_PI13       ((uint32_t)0x00000004UL)
#define MPGPDO8_DATA_PI12       ((uint32_t)0x00000008UL)
#define MPGPDO8_DATA_PI11       ((uint32_t)0x00000010UL)
#define MPGPDO8_DATA_PI10       ((uint32_t)0x00000020UL)
#define MPGPDO8_DATA_PI9        ((uint32_t)0x00000040UL)
#define MPGPDO8_DATA_PI8        ((uint32_t)0x00000080UL)
#define MPGPDO8_DATA_PI7        ((uint32_t)0x00000100UL)
#define MPGPDO8_DATA_PI6        ((uint32_t)0x00000200UL)
#define MPGPDO8_DATA_PI5        ((uint32_t)0x00000400UL)
#define MPGPDO8_DATA_PI4        ((uint32_t)0x00000800UL)
#define MPGPDO8_DATA_PI3        ((uint32_t)0x00001000UL)
#define MPGPDO8_DATA_PI2        ((uint32_t)0x00002000UL)
#define MPGPDO8_DATA_PI1        ((uint32_t)0x00004000UL)
#define MPGPDO8_DATA_PI0        ((uint32_t)0x00008000UL)
#define MPGPDO8_MASK_PI15       ((uint32_t)0x00010000UL)
#define MPGPDO8_MASK_PI14       ((uint32_t)0x00020000UL)
#define MPGPDO8_MASK_PI13       ((uint32_t)0x00040000UL)
#define MPGPDO8_MASK_PI12       ((uint32_t)0x00080000UL)
#define MPGPDO8_MASK_PI11       ((uint32_t)0x00100000UL)
#define MPGPDO8_MASK_PI10       ((uint32_t)0x00200000UL)
#define MPGPDO8_MASK_PI9        ((uint32_t)0x00400000UL)
#define MPGPDO8_MASK_PI8        ((uint32_t)0x00800000UL)
#define MPGPDO8_MASK_PI7        ((uint32_t)0x01000000UL)
#define MPGPDO8_MASK_PI6        ((uint32_t)0x02000000UL)
#define MPGPDO8_MASK_PI5        ((uint32_t)0x04000000UL)
#define MPGPDO8_MASK_PI4        ((uint32_t)0x08000000UL)
#define MPGPDO8_MASK_PI3        ((uint32_t)0x10000000UL)
#define MPGPDO8_MASK_PI2        ((uint32_t)0x20000000UL)
#define MPGPDO8_MASK_PI1        ((uint32_t)0x40000000UL)
#define MPGPDO8_MASK_PI0        ((uint32_t)0x80000000UL)

/* Masked Parallel GPIO Pad Data Out 9 (DATA and MASK) */
#define MPGPDO9_DATA_PJ4        ((uint32_t)0x00000800UL)
#define MPGPDO9_DATA_PJ3        ((uint32_t)0x00001000UL)
#define MPGPDO9_DATA_PJ2        ((uint32_t)0x00002000UL)
#define MPGPDO9_DATA_PJ1        ((uint32_t)0x00004000UL)
#define MPGPDO9_DATA_PJ0        ((uint32_t)0x00008000UL)
#define MPGPDO9_MASK_PJ4        ((uint32_t)0x08000000UL)
#define MPGPDO9_MASK_PJ3        ((uint32_t)0x10000000UL)
#define MPGPDO9_MASK_PJ2        ((uint32_t)0x20000000UL)
#define MPGPDO9_MASK_PJ1        ((uint32_t)0x40000000UL)
#define MPGPDO9_MASK_PJ0        ((uint32_t)0x80000000UL)

/************************************************************************
* @brief    Interrupt Filter Maximum Counter Registers (IFMC0-IFMC23)
*************************************************************************/
#define IFMC_MAXCNT_MASK        ((uint32_t)0x0000000FUL)

/************************************************************************
* @brief    Interrupt Filter Clock Prescaler Register (IFCPR)
*************************************************************************/
#define IFCPR_IFCP_MASK         ((uint32_t)0x0000000FUL)

/************************************************************************
 *    System Integration Unit Lite (SIUL)
 *    Function declaration
 ************************************************************************/
extern uint16_t SIUL_MIDR1_PartNumRead(void);
extern uint8_t SIUL_MIDR1_PackSetRead(void);
extern uint8_t SIUL_MIDR1_MajorMaskRead(void);
extern uint8_t SIUL_MIDR1_MinorMaskRead(void);
extern uint8_t SIUL_MIDR2_MakerRead(void);
extern uint8_t SIUL_MIDR2_FlashSize1Read(void);
extern uint8_t SIUL_MIDR2_FlashSize2SelRead(void);
extern uint8_t SIUL_MIDR2_PartNumRead(void);
extern uint8_t SIUL_MIDR2_DataFlashRead(void);
extern void SIUL_EXTI_Clear_Flag(uint32_t eifNum);
extern uint32_t SIUL_EXTI_Get_Flag(void);
extern void SIUL_EXT_IntReqEnable(uint32_t ireNum);
extern void SIUL_IntRisingEventEnable(uint32_t ireeNum);
extern void SIUL_IntFallingEventEnable(uint32_t ifeeNum);
extern void SIUL_IntFilterEnable(uint32_t ifeNum);
extern void SIUL_Init(uint8_t pcrNum, uint16_t padType);
extern void SIUL_Init_GPIO_Out(uint8_t pcrNum, uint16_t mode);
extern void SIUL_Init_EIRQ(uint8_t pcrNum);
extern void SIUL_Init_ADC(uint8_t pcrNum);
extern void SIUL_PadSelMuxInput(uint8_t selNum, uint8_t mapNum);
extern void SIUL_GPIO_OutputWrite(uint8_t pcrNum, uint8_t status);
extern uint8_t SIUL_GPIO_InputRead(uint8_t pcrNum);
extern void SIUL_ParallelGPIOPadData_Out(uint8_t portNum, uint32_t pinNum);
extern uint32_t SIUL_ParallelGPIOPadData_In(uint8_t portNum);
extern void SIUL_MaskedParallelGPIOPadData_Out(uint8_t portNum, uint32_t maskPinNum);
extern void SIUL_IntFilterMacCounter_Set(uint8_t regNum, uint8_t maxcntNum);
extern void SIUL_IntFilterClkPres_Set(uint8_t ifcpNum);

#endif  /* SIUL_LLD_H */
