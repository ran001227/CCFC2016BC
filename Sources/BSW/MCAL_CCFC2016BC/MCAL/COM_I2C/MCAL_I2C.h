/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS, " AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
* PROJECT     : CCFC2016BC
* DESCRIPTION : CCFC2016BC I2C lower level driver h file
* HISTORY     : Initial version.
* @file     iic_lld.h
* @version  1.4
* @date     2023 - 06 - 12
* @brief    Initial version.
*
*****************************************************************************/
#ifndef IIC_LLD_H
#define IIC_LLD_H

#include "console.h"
#include "MCAL_GPIO.h"

#define I2C_TIMEOUT                              1500u

/* IBAD Bit Fields */
#define I2C_IBAD_ADR_MASK                        0xFEu
#define I2C_IBAD_ADR_SHIFT                       1u
#define I2C_IBAD_ADR_WIDTH                       7u
#define I2C_IBAD_ADR(x)                          (((uint8_t)(((uint8_t)(x)) << I2C_IBAD_ADR_SHIFT))&I2C_IBAD_ADR_MASK)
/* IBFD Bit Fields */
#define I2C_IBFD_IBC_MASK                        0xFFu
#define I2C_IBFD_IBC_SHIFT                       0u
#define I2C_IBFD_IBC_WIDTH                       8u
#define I2C_IBFD_IBC(x)                          (((uint8_t)(((uint8_t)(x)) << I2C_IBFD_IBC_SHIFT))&I2C_IBFD_IBC_MASK)
/* IBCR Bit Fields */
#define I2C_IBCR_DMAEN_MASK                      0x2u
#define I2C_IBCR_DMAEN_SHIFT                     1u
#define I2C_IBCR_DMAEN_WIDTH                     1u
#define I2C_IBCR_DMAEN(x)                        (((uint8_t)(((uint8_t)(x)) << I2C_IBCR_DMAEN_SHIFT))&I2C_IBCR_DMAEN_MASK)
#define I2C_IBCR_RSTA_MASK                       0x4u
#define I2C_IBCR_RSTA_SHIFT                      2u
#define I2C_IBCR_RSTA_WIDTH                      1u
#define I2C_IBCR_RSTA(x)                         (((uint8_t)(((uint8_t)(x)) << I2C_IBCR_RSTA_SHIFT))&I2C_IBCR_RSTA_MASK)
#define I2C_IBCR_NOACK_MASK                      0x8u
#define I2C_IBCR_NOACK_SHIFT                     3u
#define I2C_IBCR_NOACK_WIDTH                     1u
#define I2C_IBCR_NOACK(x)                        (((uint8_t)(((uint8_t)(x)) << I2C_IBCR_NOACK_SHIFT))&I2C_IBCR_NOACK_MASK)
#define I2C_IBCR_TXRX_MASK                       0x10u
#define I2C_IBCR_TXRX_SHIFT                      4u
#define I2C_IBCR_TXRX_WIDTH                      1u
#define I2C_IBCR_TXRX(x)                         (((uint8_t)(((uint8_t)(x)) << I2C_IBCR_TXRX_SHIFT))&I2C_IBCR_TXRX_MASK)
#define I2C_IBCR_MSSL_MASK                       0x20u
#define I2C_IBCR_MSSL_SHIFT                      5u
#define I2C_IBCR_MSSL_WIDTH                      1u
#define I2C_IBCR_MSSL(x)                         (((uint8_t)(((uint8_t)(x)) << I2C_IBCR_MSSL_SHIFT))&I2C_IBCR_MSSL_MASK)
#define I2C_IBCR_IBIE_MASK                       0x40u
#define I2C_IBCR_IBIE_SHIFT                      6u
#define I2C_IBCR_IBIE_WIDTH                      1u
#define I2C_IBCR_IBIE(x)                         (((uint8_t)(((uint8_t)(x)) << I2C_IBCR_IBIE_SHIFT))&I2C_IBCR_IBIE_MASK)
#define I2C_IBCR_MDIS_MASK                       0x80u
#define I2C_IBCR_MDIS_SHIFT                      7u
#define I2C_IBCR_MDIS_WIDTH                      1u
#define I2C_IBCR_MDIS(x)                         (((uint8_t)(((uint8_t)(x)) << I2C_IBCR_MDIS_SHIFT))&I2C_IBCR_MDIS_MASK)
/* IBSR Bit Fields */
#define I2C_IBSR_RXAK_MASK                       0x1u
#define I2C_IBSR_RXAK_SHIFT                      0u
#define I2C_IBSR_RXAK_WIDTH                      1u
#define I2C_IBSR_RXAK(x)                         (((uint8_t)(((uint8_t)(x)) << I2C_IBSR_RXAK_SHIFT))&I2C_IBSR_RXAK_MASK)
#define I2C_IBSR_IBIF_MASK                       0x2u
#define I2C_IBSR_IBIF_SHIFT                      1u
#define I2C_IBSR_IBIF_WIDTH                      1u
#define I2C_IBSR_IBIF(x)                         (((uint8_t)(((uint8_t)(x)) << I2C_IBSR_IBIF_SHIFT))&I2C_IBSR_IBIF_MASK)
#define I2C_IBSR_SRW_MASK                        0x4u
#define I2C_IBSR_SRW_SHIFT                       2u
#define I2C_IBSR_SRW_WIDTH                       1u
#define I2C_IBSR_SRW(x)                          (((uint8_t)(((uint8_t)(x)) << I2C_IBSR_SRW_SHIFT))&I2C_IBSR_SRW_MASK)
#define I2C_IBSR_IBB_MASK                        0x20u
#define I2C_IBSR_IBB_SHIFT                       5u
#define I2C_IBSR_IBB_WIDTH                       1u
#define I2C_IBSR_IBB(x)                          (((uint8_t)(((uint8_t)(x)) << I2C_IBSR_IBB_SHIFT))&I2C_IBSR_IBB_MASK)
#define I2C_IBSR_IAAS_MASK                       0x40u
#define I2C_IBSR_IAAS_SHIFT                      6u
#define I2C_IBSR_IAAS_WIDTH                      1u
#define I2C_IBSR_IAAS(x)                         (((uint8_t)(((uint8_t)(x)) << I2C_IBSR_IAAS_SHIFT))&I2C_IBSR_IAAS_MASK)
#define I2C_IBSR_TCF_MASK                        0x80u
#define I2C_IBSR_TCF_SHIFT                       7u
#define I2C_IBSR_TCF_WIDTH                       1u
#define I2C_IBSR_TCF(x)                          (((uint8_t)(((uint8_t)(x)) << I2C_IBSR_TCF_SHIFT))&I2C_IBSR_TCF_MASK)
/* IBDR Bit Fields */
#define I2C_IBDR_DATA_MASK                       0xFFu
#define I2C_IBDR_DATA_SHIFT                      0u
#define I2C_IBDR_DATA_WIDTH                      8u
#define I2C_IBDR_DATA(x)                         (((uint8_t)(((uint8_t)(x)) << I2C_IBDR_DATA_SHIFT))&I2C_IBDR_DATA_MASK)
/* IBIC Bit Fields */
#define I2C_IBIC_BIIE_MASK                       0x80u
#define I2C_IBIC_BIIE_SHIFT                      7u
#define I2C_IBIC_BIIE_WIDTH                      1u
#define I2C_IBIC_BIIE(x)                         (((uint8_t)(((uint8_t)(x)) << I2C_IBIC_BIIE_SHIFT))&I2C_IBIC_BIIE_MASK)

#define I2C_IBSR_IBAL_MASK                       0x10u
#define I2C_IBSR_IBAL_SHIFT                      4u
#define I2C_IBSR_IBAL(x)                         (((uint8_t)(((uint8_t)(x)) << I2C_IBSR_IBAL_SHIFT))&I2C_IBSR_IBAL_MASK)

#define I2C_IBSR_IBIF(x)                         (((uint8_t)(((uint8_t)(x)) << I2C_IBSR_IBIF_SHIFT))&I2C_IBSR_IBIF_MASK)

#define I2C_BAUDRATE_100K                        0x65
#define I2C_BAUDRATE_200K                        0x5D

#define I2C_0_index                              0U
#define I2C_1_index                              1U
#define I2C_2_index                              2U
#define I2C_3_index                              3U

typedef enum
{
    I2C_DISABLE =  0,
    I2C_ENABLE = 1
}i2c_type;

typedef enum
{
    I2C_SLAVE =  0,                              /*! < The I2C module is in slave mode > */
    I2C_MASTER = 1                               /*! < The I2C module is in master mode > */
}i2c_module_type;

typedef enum
{
    I2C_RECEIVE = 0,                           /*! < The I2C module is in receive mode > */
    I2C_TRANSMIT = 1                           /*! < The I2C module is in transmit mode > */
}i2c_status;

typedef enum
{
    I2C_GPIO_DEFAULT,
    I2C_GPIO_MUX
}i2c_gpio_select_t;

typedef struct
{
    uint8_t * rxBuff;                           /* Pointer to receive data buffer */
    uint32_t rxSize;                            /* Size of receive data buffer */
    const uint8_t * txBuff;                     /* Pointer to transmit data buffer */
    uint8_t txData;
    uint8_t rxData;
    uint32_t txSize;                            /* Size of transmit data buffer */
    uint8_t slaveAddress;                       /* Slave address */
    volatile uint8_t i2cIdle;                   /* Idle/busy state of the driver */
    uint8_t sendStop;                           /* Specifies if STOP condition must be generated after current transfer */
    uint8_t blocking;                           /* Specifies if the current transfer is blocking */
    uint8_t dmaChannel;                         /* Channel number for DMA rx channel */
    uint8_t sendData;                           /* Master is in transmitting or receive mode*/
    uint8_t stopGenerated;                      /* Specifies if stop was generated for the previous transfer */
    void *callbackParam;                        /* Parameter for the master callback function */
} i2c_master_state_t;

typedef struct
{
/*! @cond DRIVER_INTERNAL_USE_ONLY */
    volatile uint8_t isTransferInProgress;      /* Slave is busy because of an ongoing transfer */
    uint32_t txSize;                            /* Size of the TX buffer */
    uint32_t rxSize;                            /* Size of the RX buffer */
    const uint8_t * txBuff;                     /* Pointer to Tx Buffer */
    uint8_t * rxBuff;                           /* Pointer to Rx Buffer */
    uint8_t txData;
    uint8_t rxData;
    uint8_t slaveAddress;                       /* Slave address */
    uint8_t slaveListening;                     /* Slave mode (always listening or on demand only) */
    uint8_t txUnderrunWarning;                  /* Possible slave tx underrun */
    uint8_t dataAck;                            /* Data acknowledge enable or disable*/
    uint8_t blocking;                           /* Specifies if the current transfer is blocking */
    void *callbackParam;                        /* Parameter for the slave callback function */
/*! @endcond */
} i2c_slave_state_t;

/** I2C - Register Layout Typedef */
typedef struct {
    volatile uint8_t IBAD;                               /** < I2C Bus Address Register, offset: 0x0 */
    volatile uint8_t IBFD;                               /** < I2C Bus Frequency Divider Register, offset: 0x1 */
    volatile uint8_t IBCR;                               /** < I2C Bus Control Register, offset: 0x2 */
    volatile uint8_t IBSR;                               /** < I2C Bus Status Register, offset: 0x3 */
    volatile uint8_t IBDR;                               /** < I2C Bus Data I/O Register, offset: 0x4 */
    volatile uint8_t IBIC;                               /** < I2C Bus Interrupt Config Register, offset: 0x5 */
} I2C_Type, *I2C_MemMapPtr;

/* I2C - Peripheral instance base addresses */
/** Peripheral I2C_1 base address */
#define I2C_0_BASE                               (0xFFE30000u)
/** Peripheral I2C_1 base pointer */
#define I2C_0_0                                  ((I2C_Type *)I2C_0_BASE)
/** Peripheral I2C_2 base address */
#define I2C_1_BASE                               (0xFFE34000u)
/** Peripheral I2C_2 base pointer */
#define I2C_1_1                                    ((I2C_Type *)I2C_1_BASE)

/** Peripheral I2C_2 base address */
#define I2C_2_BASE                               (0xFFE38000u)
/** Peripheral I2C_2 base pointer */
#define I2C_2_2                                    ((I2C_Type *)I2C_2_BASE)

/** Peripheral I2C_2 base address */
#define I2C_3_BASE                               (0xFFE3c000u)
/** Peripheral I2C_2 base pointer */
#define I2C_3_3                                  ((I2C_Type *)I2C_3_BASE)

/** Array initializer of I2C peripheral base addresses */
#define I2C_BASE_ADDRS                           { I2C_0_BASE, I2C_1_BASE, I2C_2_BASE, I2C_3_BASE}
/** Array initializer of I2C peripheral base pointers */
#define I2C_BASE_PTRS                            { I2C_0_0, I2C_1_1, I2C_2_2, I2C_3_3}

extern i2c_master_state_t I2CMasterState;

extern i2c_slave_state_t I2CSlaveState;

/*********************************** The function declaration ***********************************/
/** This function shall be the slave INIT **/
extern void I2C_LLD_Slave_Init(uint8_t instance, i2c_slave_state_t * slave);
/** This function shall be the master INIT **/
extern void I2C_LLD_Master_Init(uint8_t instance, i2c_master_state_t * master);
/** This function shall be the GPIO INIT **/
extern void I2C_LLD_Gpio_Init();
/** This function shall be the GPIO DEINIT **/
extern void I2C_LLD_Gpio_DeInit();

/** This function shall be the slave transmit **/
extern uint8_t I2C_LLD_Slave_Transmit(uint8_t instance, uint8_t * txBuff, uint32_t txSize);
/** This function shall be the slave receive **/
extern uint8_t I2C_LLD_Slave_Receive(uint32_t instance, uint8_t *rxBuff, uint32_t rxSize);

/** This function shall be the master transmit **/
extern uint8_t I2C_LLD_Master_Transmit(uint8_t instance, uint8_t *txBuff, uint32_t txSize, uint8_t sendStop);
/** This function shall be the master receive **/
extern uint8_t I2C_LLD_Master_Receive(uint8_t instance, uint8_t *rxBuff, uint32_t rxSize, uint8_t sendStop);

/** polling **/
/** This function shall be the polling slave INIT **/
extern void I2C_LLD_Polling_Slave_Init(uint8_t instance, uint8_t address);

/** This function shall be the polling master INIT **/
extern void I2C_LLD_Polling_Master_Init(uint8_t instance);

/** This function shall be the polling slave transmit **/
extern void I2C_Lld_Polling_Slave_Transmit(uint8_t instance, const uint8_t *txbuff, uint8_t txcount);
/** This function shall be the polling master transmit **/
extern uint8_t I2C_LLD_Pollling_Master_Transmit(uint8_t instance, uint8_t tx_count, const uint8_t *txbuff, uint8_t Slave_Address, uint8_t SendStop);
/** This function shall be the polling master receive **/
extern uint8_t I2C_LLD_Polling_Master_Receive(uint8_t instance, uint8_t rx_count , uint8_t *rxBuff, uint8_t Slave_Address);
/** This function shall be the polling salve receive **/
extern void I2C_LLD_Poliing_Slave_Receive(uint8_t instance, uint8_t *rxbuff, uint8_t rxcount);

/** This function shall be the polling master transmit **/
extern void I2C_LLD_Pollling_Master_Transmit_Dma(uint8_t instance, uint8_t tx_count, const uint8_t *txbuff, uint8_t SendStop); /* PRQA S 0777,0779 */
/** This function shall be the polling receive transmit **/
extern void I2c_LLD_Polling_Master_Receive_Dma(uint8_t instance, uint8_t rx_count , const uint8_t *rxBuff, uint8_t Slaver_Address);

uint8_t I2C_LLD_Master_Transmit_Blocking(uint8_t instance, const uint8_t *txBuff, uint32_t txSize, uint8_t sendStop, uint32_t timeout);

uint8_t I2C_LLD_Master_Receive_Blocking(uint8_t instance, const uint8_t *rxBuff, uint32_t rxSize, uint8_t sendStop, uint32_t timeout);

extern void MCAL_I2C_Init(Mcal_GPIO_Pin SDA,Mcal_GPIO_Pin SCL);
extern void MCAL_I2C_SetSDA(Mcal_GPIO_Pin SDA,boolean state);
extern void MCAL_I2C_SetSCL(Mcal_GPIO_Pin SCL,boolean state);
extern boolean MCAL_I2C_ReadSDA(Mcal_GPIO_Pin SDA);
extern void MCAL_I2C_Delay(void);
extern void MCAL_I2C_Start(Mcal_GPIO_Pin SDA,Mcal_GPIO_Pin SCL);
extern void MCAL_I2C_Stop(Mcal_GPIO_Pin SDA,Mcal_GPIO_Pin SCL);
extern boolean MCAL_I2C_WaitAck(Mcal_GPIO_Pin SDA,Mcal_GPIO_Pin SCL);
extern void MCAL_I2C_Ack(Mcal_GPIO_Pin SDA,Mcal_GPIO_Pin SCL);
extern void MCAL_I2C_NoAck(Mcal_GPIO_Pin SDA,Mcal_GPIO_Pin SCL);
extern void MCAL_I2C_SendByte(Mcal_GPIO_Pin SDA,Mcal_GPIO_Pin SCL,uint8 Data);
extern uint8 MCAL_I2C_ReceiveByte(Mcal_GPIO_Pin SDA,Mcal_GPIO_Pin SCL,boolean ack);
/*********************************** The function declaration ***********************************/

#endif
