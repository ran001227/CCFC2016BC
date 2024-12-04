/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS, " AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
* PROJECT     : CCFC2016BC
* DESCRIPTION : CCFC2016BC LIN low level drivers code
* HISTORY     : Initial version.
* @file     lin_lld.h
* @version  1.1
* @date     2023 - 02 - 15
* @brief    Initial version.
*
*****************************************************************************/
#ifndef LIN_LLD_H
#define LIN_LLD_H

#include "console.h"

#define CCFC20xx_LINFLEX_MODE_NONE                       0
#define CCFC20xx_LINFLEX_MODE_SERIAL                     1
#define CCFC20xx_LINFLEX_MODE_LIN                        2

#define CCFC20xx_LINFLEX0_SETTING                       CCFC20xx_LINFLEX_MODE_LIN
#define CCFC20xx_LINFLEX1_SETTING                       CCFC20xx_LINFLEX_MODE_LIN
#define CCFC20xx_LINFLEX2_SETTING                       CCFC20xx_LINFLEX_MODE_LIN
#define CCFC20xx_LINFLEX3_SETTING                       CCFC20xx_LINFLEX_MODE_LIN
#define CCFC20xx_LINFLEX4_SETTING                       CCFC20xx_LINFLEX_MODE_LIN
#define CCFC20xx_LINFLEX5_SETTING                           CCFC20xx_LINFLEX_MODE_LIN
#define CCFC20xx_LINFLEX6_SETTING                       CCFC20xx_LINFLEX_MODE_LIN
#define CCFC20xx_LINFLEX7_SETTING                       CCFC20xx_LINFLEX_MODE_LIN
#define CCFC20xx_LINFLEX8_SETTING                           CCFC20xx_LINFLEX_MODE_LIN
#define CCFC20xx_LINFLEX9_SETTING                       CCFC20xx_LINFLEX_MODE_LIN
#if 1
#define CCFC20xx_LINFLEX10_SETTING                      CCFC20xx_LINFLEX_MODE_LIN
#define CCFC20xx_LINFLEX11_SETTING                      CCFC20xx_LINFLEX_MODE_LIN
#define CCFC20xx_LINFLEX12_SETTING                      CCFC20xx_LINFLEX_MODE_LIN
#define CCFC20xx_LINFLEX13_SETTING                      CCFC20xx_LINFLEX_MODE_LIN
#endif

/**  LIN driver allowable modes  **/
typedef enum
{
    LIN_MODE_SLAVE,                                      /**  LINFlex is in slave mode.        */
    LIN_MODE_MASTER,                                     /**  LINFlex is in master mode.       */
    LIN_MODE_MASTER_SLAVE                                /**  LINFlex is in master/slave mode. */
} lin_mode_t;

/** LIN Message Direction Data Type **/
typedef enum
{
    LIN_DIRECTION_RECEIVE,                               /**  LINFlexD receives the data and copies them in the BDRs. */
    LIN_DIRECTION_TRANSMIT                               /**  LINFlexD transmits the data from the BDRs.              */
} lin_message_direction_t;

/**  LIN Message Checksum Data Type  **/
typedef enum
{
    LIN_ENHANCED_CHECKSUM,                               /**     Enhanced Checksum covering Identifier and Data fields. */
    LIN_CLASSIC_CHECKSUM                                 /**  Classic Checksum covering Data field only.             */
} lin_checksum_t;

/** LIN Message Checksum Data Type **/
typedef enum
{
    LIN_LIST_MODE,                                       /**  FIlter is configured in list mode. */
    LIN_MASK_MODE                                        /**  Filter is configured in mask mode. */
} lin_filter_mode_t;

typedef enum
{
    LIN_GPIO_DEFAULT,
    LIN_GPIO_MUX
}lin_gpio_select_t;

#define CCFC20xx_LIN_API_MODE_SYNCHRONOUS               0U   /** < @brief Synchronous API.  */
#define CCFC20xx_LIN_API_MODE_ASYNCHRONOUS              1U   /** < @brief Asynchronous API. */
#define CCFC20xx_LIN_API_MODE_BUFFERED_IO               2U   /** < @brief Buffered IO API (only for Serial). */

#define CCFC20xx_LIN_RX_READY                           0U
#define CCFC20xx_LIN_RX_BUSY                            1U
#define CCFC20xx_LIN_TX_READY                           0U
#define CCFC20xx_LIN_TX_BUSY                            1U

#define SYS_CLOCK_LIN_MODE                       160000000U    /** system clock   **/
#define LIN_DEFAULT_BAUDRATE                        19200U    /** LIN driver default baud rate   **/
#define DIV_PARAMETER    (SYS_CLOCK_LIN_MODE/LIN_DEFAULT_BAUDRATE)

#define LIN_DIV_F            (DIV_PARAMETER % 16u)
#define LIN_DIV_M             (DIV_PARAMETER / 16u)

#define LIN_DATA_LEN                                    8U    /** LIN driver data length **/
#define LIN_NUM_FILTERS                                16U    /** LIN driver number of filters **/

#define    CCFC20xx_LINFLEX_IFCR0_OFFSET                 0x4CU
#define CCFC20xx_BIDR_ID_MASK                         0x3FU
#define CCFC20xx_BIDR_DFL_MASK                         0x3FU
#define LIN_DATA_CHECKSUM                               0U    /** Enhanced Checksum covering Identifier and Data fields. **/

#define BIDR_DIR_RECEIVE                                0U    /** LINFlexD receives the data and copies them in the BDRs **/
#define BIDR_DIR_TRANSMIT                               1U    /** LINFlexD transmits the data from the BDRs **/

#define LIN_MSG_OK                               (1UL << 1)   /** < @brief message OK.                 */
#define LIN_MSG_WAIT                             (1UL << 2)   /** < @brief ob or ib is non empty. wait */
#define LIN_MSG_ERROR                            (1UL << 3)   /** < @brief ob is non empty. wait       */
#define LIN_MSG_ERROR_LEN                        (1UL << 4)   /** < @brief buffer len not allowed      */

#define CCFC20xx_LINSR_HRF                      (1UL << 0)
#define CCFC20xx_LINSR_DTF                      (1UL << 1)
#define CCFC20xx_LINSR_DRF                      (1UL << 2)
#define CCFC20xx_LINSR_DBEF                     (1UL << 3)
#define CCFC20xx_LINSR_DBFF                     (1UL << 4)
#define CCFC20xx_LINSR_WUF                      (1UL << 5)
#define CCFC20xx_LINSR_RDI                      (1UL << 6)
#define CCFC20xx_LINSR_RXBUSY                   (1UL << 7)
#define CCFC20xx_LINSR_DRBNE                    (1UL << 8)
#define CCFC20xx_LINSR_RMB                      (1UL << 9)
#define CCFC20xx_LINSR_LINS                     (15UL << 12)

typedef void (*lincallback_t)(uint32_t  device);
typedef struct LinflexDriver LinflexDriver;                             /**  Type of a structure representing a Linflex driver. **/

typedef union tmpData /* PRQA S 1536 */
{
    uint32_t w;
    uint8_t  b[4];
}t_Data;
/**
 * @brief   Structure representing an LinflexDriver driver.
 */
struct LinflexDriver{
  uint32_t device; /* must be private */
  /*linflex rx interrupt call back */
  lincallback_t rxi_lincallback;
  /*linflex rx interrupt call back */
  lincallback_t txi_lincallback;
  /*linflex rx interrupt call back */
  lincallback_t err_lincallback;
};

typedef struct
{
    vuint32_t LINCR2;
    vuint32_t BIDR;
    vuint32_t BDRL;
    vuint32_t BDRM;
}LinD_DMA;

typedef struct LinDriver LinDriver;  /** Type of a structure representing a LIN driver. **/

typedef uint32_t (*linclbk_t)(const LinDriver *ldp, uint8_t idMessage, \
                  uint8_t *buffer, uint16_t len);
typedef uint32_t (*linclbk_s)(const LinDriver *ldp, uint8_t idMessage, \
                  const uint8_t *buffer, uint16_t len);

typedef void (*ldma_errorcallback_t)(LinDriver *ldp);   /** LIN DMA error callback type. **/

/**
 * @brief   Generic Lin Filter configuration structure.
 */
typedef struct { /* PRQA S 3630 */
  /**
   * @brief   Value. Filter value, it is in the range[0, 63]
   */
  uint8_t                         value;
  /**
   * @brief   Message data size. It is in the range[1, 8].
   */
  uint8_t                         datasize;
  /**
   * @brief   Message direction (Transmit, Receive).
   */
  lin_message_direction_t         direction;
  /**
   * @brief   Message Checksum Data Type.
   */
  lin_checksum_t                  ccs;
  /**
   * @brief   Callback function associated to the TX completion.
   */
  lin_filter_mode_t               mode;
  /**
   * @brief   Mask Value. Mask Filter value, it is in the range[0, 63]
   */
  uint8_t                         mask_value;
} LinFilter;

/**
 * @brief   Generic Lin No_Filter configuration structure.
 */
typedef struct { /* PRQA S 3630 */
  /**
   * @brief   Value. Filter value, it is in the range[0, 63]
   */
  uint8_t                         value;
  /**
   * @brief   Message data size. It is in the range[1, 8].
   */
  uint8_t                         datasize;
  /**
   * @brief   Message direction (Transmit, Receive).
   */
  lin_message_direction_t         direction;
  /**
   * @brief   Message Checksum Data Type.
   */
  lin_checksum_t                  ccs;
} No_LinFilter;

/** Generic Lin Driver configuration structure **/
typedef struct { /* PRQA S 3630 */
  /**
   * @brief   Bit rate.
   */
  uint32_t                        speed;
  /**
   * @brief   Lin Driver Mode flags.
   */
  lin_mode_t                      mode;
  /**
   * @brief   API Mode flags.
   */
  uint8_t                         api_mode;
  /**
   * @brief   Callback function associated to the TX completion.
   */
  linclbk_t                       tx_end_cb;
  /**
   * @brief   Callback function associated to the RX completion.
   */
  linclbk_s                       rx_end_cb;
  /**
   * @brief   Filters list.
   */
  LinFilter                      **filters;
  /**
   * @brief   no Filters list.
   */
  No_LinFilter                    *nofilter;
  /**
   * @brief   Linflex Loopback Mode Flag.
   */
  uint8_t                         loopBack;
  /**
   * @brief   Flag set if the DMA is enabled.
   */
  uint8_t                         dma_enable;
  /**
   * @brief   DMA error callback.
   */
  ldma_errorcallback_t            dma_err_cb;
} LinConfig;

/** Structure representing an LinDriver driver. **/
struct LinDriver {
  const LinConfig                        *config;    /** Current configuration data. **/
  uint8_t                                *rx_buf;    /** Input Buffer. **/
  uint8_t                                *tx_buf;    /** Output Buffer. **/
  uint16_t                                rx_len;    /** Number of bytes to receive. **/
  uint16_t                                tx_len;    /** Number of bytes to transmit. **/
  volatile uint16_t                      rx_busy;    /** Receive in progress. **/
  volatile uint16_t                      tx_busy;    /** Transmit in progress. **/
  uint8_t                              rx_id_msg;    /** Id of the received message. **/
  uint8_t                              tx_id_msg;    /** Id of the transmitted message. **/

  volatile struct CCFC20xxbc_linflexl   *linflexlp;
  volatile struct CCFC20xxbc_linflexh   *linflexhp;
  uint32_t                                 clock;    /** Clock value for this unit. **/
};

/* PPC register definitions not compatible with MISRA rules on bit - fields
 (Rules 6.1). */
/*lint - e46 */
struct CCFC20xxbc_linflexl { /* PRQA S 3630 */
  int16_t LINFLEX_reserved1;

  union {
    vuint16_t R;
    struct {
      vuint16_t CCD :1;
      vuint16_t CFD :1;
      vuint16_t LASE :1;
      vuint16_t AWUM :1;
      vuint16_t MBL :4;
      vuint16_t BF :1;
      vuint16_t SFTM :1;
      vuint16_t LBKM :1;
      vuint16_t MME :1;
      vuint16_t SBDT :1;
      vuint16_t RBLM :1;
      vuint16_t SLEEP :1;
      vuint16_t INIT :1;
    } B;
  } LINCR1;

  int16_t LINFLEX_reserved2;

  union {
    vuint16_t R;
    struct {
      vuint16_t SZIE :1;
      vuint16_t OCIE :1;
      vuint16_t BEIE :1;
      vuint16_t CEIE :1;
      vuint16_t HEIE :1;
      vuint16_t :2;
      vuint16_t FEIE :1;
      vuint16_t BOIE :1;
      vuint16_t LSIE :1;
      vuint16_t WUIE :1;
      vuint16_t DBFIE :1;
      vuint16_t DBEIE :1;
      vuint16_t DRIE :1;
      vuint16_t DTIE :1;
      vuint16_t HRIE :1;
    } B;
  } LINIER;

  int16_t LINFLEX_reserved3;

  union {
    vuint16_t R;
    struct {
      vuint16_t LINS :4;
      vuint16_t :2;
      vuint16_t RMB :1;
      vuint16_t :1;
      vuint16_t RBSY :1;
      vuint16_t RPS :1;
      vuint16_t WUF :1;
      vuint16_t DBFF :1;
      vuint16_t DBEF :1;
      vuint16_t DRF :1;
      vuint16_t DTF :1;
      vuint16_t HRF :1;
    } B;
  } LINSR;

  int16_t LINFLEX_reserved4;

  union {
    vuint16_t R;
    struct {
      vuint16_t SZF :1;
      vuint16_t OCF :1;
      vuint16_t BEF :1;
      vuint16_t CEF :1;
      vuint16_t SFEF :1;
      vuint16_t BDEF :1;
      vuint16_t IDPEF :1;
      vuint16_t FEF :1;
      vuint16_t BOF :1;
      vuint16_t :6;
      vuint16_t NF :1;
    } B;
  } LINESR;

  int16_t LINFLEX_reserved5;

  union {
    vuint16_t R;
    struct {
      vuint16_t TDFL :3;
      vuint16_t RDFL :3;
      vuint16_t RFBM :1;
      vuint16_t TFBM :1;
      vuint16_t WL1 :1;
      vuint16_t PC1 :1;
      vuint16_t RXEN :1;
      vuint16_t TXEN :1;
      vuint16_t PC0 :1;
      vuint16_t PCE :1;
      vuint16_t WL0 :1;
      vuint16_t UART :1;
    } B;
  } UARTCR;

  int16_t LINFLEX_reserved6;

  union {
    vuint16_t R;
    struct {
      vuint16_t SZF :1;
      vuint16_t OCF :1;
      vuint16_t PE :4;
      vuint16_t RMB :1;
      vuint16_t FEF :1;
      vuint16_t BOF :1;
      vuint16_t RPS :1;
      vuint16_t WUF :1;
      vuint16_t :2;
      vuint16_t DRF :1;
      vuint16_t DTF :1;
      vuint16_t NF :1;
    } B;
  } UARTSR;

  int16_t LINFLEX_reserved7;

  union {
    vuint16_t R;
    struct {
      vuint16_t :5;
      vuint16_t LTOM :1;
      vuint16_t IOT :1;
      vuint16_t TOCE :1;
      vuint16_t CNT :8;
    } B;
  } LINTCSR;

  int16_t LINFLEX_reserved8;

  union {
    vuint16_t R;
    struct {
      vuint16_t OC2 :8;
      vuint16_t OC1 :8;
    } B;
  } LINOCR;

  int16_t LINFLEX_reserved9;

  union {
    vuint16_t R;
    struct {
      vuint16_t :4;
      vuint16_t RTO :4;
      vuint16_t :1;
      vuint16_t HTO :7;
    } B;
  } LINTOCR;

  int16_t LINFLEX_reserved10;

  union {
    vuint16_t R;
    struct {
      vuint16_t :12;
      vuint16_t DIV_F :4;
    } B;
  } LINFBRR;

  int16_t LINFLEX_reserved11;

  union {
    vuint16_t R;
    struct {
      vuint16_t :3;
      vuint16_t DIV_M :13;
    } B;
  } LINIBRR;

  int16_t LINFLEX_reserved12;

  union {
    vuint16_t R;
    struct {
      vuint16_t :8;
      vuint16_t CF :8;
    } B;
  } LINCFR;

  int16_t LINFLEX_reserved13;

  union {
    vuint16_t R;
    struct {
      vuint16_t :1;
      vuint16_t IOBE :1;
      vuint16_t IOPE :1;
      vuint16_t WURQ :1;
      vuint16_t DDRQ :1;
      vuint16_t DTRQ :1;
      vuint16_t ABRQ :1;
      vuint16_t HTRQ :1;
      vuint16_t :8;
    } B;
  } LINCR2;

  int16_t LINFLEX_reserved14;

  union {
    vuint16_t R;
    struct {
      vuint16_t DFL :6;
      vuint16_t DIR :1;
      vuint16_t CCS :1;
      vuint16_t :2;
      vuint16_t ID :6;
    } B;
  } BIDR;

  union {
    vuint32_t R;
    struct {
      vuint32_t DATA3 :8;
      vuint32_t DATA2 :8;
      vuint32_t DATA1 :8;
      vuint32_t DATA0 :8;
    } B;
  } BDRL;

  union {
    vuint32_t R;
    struct {
      vuint32_t DATA7 :8;
      vuint32_t DATA6 :8;
      vuint32_t DATA5 :8;
      vuint32_t DATA4 :8;
    } B;
  } BDRM;

  int16_t LINFLEX_reserved15;

  union {
    vuint16_t R;
    struct {
      vuint16_t FACT :16;
    } B;
  } IFER;

  int16_t LINFLEX_reserved16;

  union {
    vuint16_t R;
    struct {
      vuint16_t :11;
      vuint16_t IFMI :5;
    } B;
  } IFMI;

  int16_t LINFLEX_reserved17;

  union {
    vuint16_t R;
    struct {
      vuint16_t :12;
      vuint16_t IFM :4;
    } B;
  } IFMR;
};

struct CCFC20xxbc_linflexh /* PRQA S 3630 */
{
  union {
    vuint32_t R;
    struct {
      vuint32_t:26;
      vuint32_t TDFBM:1;
      vuint32_t RDFBM:1;
      vuint32_t TDLIS:1;
      vuint32_t RDLIS:1;
      vuint32_t STOP:1;
      vuint32_t SR:1;
    } B;
  } GCR;

  union {
    vuint32_t R;
    struct {
      vuint32_t:20;
      vuint32_t PTO:12;
    } B;
  } UARTPTO;

  union {
    vuint32_t R;
    struct {
      vuint32_t:20;
      vuint32_t CTO:12;
    } B;
  } UARTCTO;

  union {
    vuint32_t R;
    struct {
      vuint32_t:16;
      vuint32_t DTE:16;
    } B;
  } DMATXE;

  union {
    vuint32_t R;
    struct {
      vuint32_t:16;
      vuint32_t DRE:16;
    } B;
  } DMARXE;
};
/*lint + e46 */

#define CCFC20xx_LINFLEX0L_BASE                         0xFFE40000UL
#define CCFC20xx_LINFLEX0H_BASE                         0xFFE4008CUL

#define CCFC20xx_LINFLEX1L_BASE                         0xFFE44000UL
#define CCFC20xx_LINFLEX1H_BASE                         0xFFE4404CUL

#define CCFC20xx_LINFLEX2L_BASE                         0xFFE48000UL
#define CCFC20xx_LINFLEX3L_BASE                         0xFFE4C000UL
#define CCFC20xx_LINFLEX4L_BASE                         0xFFE50000UL
#define CCFC20xx_LINFLEX5L_BASE                         0xFFE54000UL
#define CCFC20xx_LINFLEX6L_BASE                         0xFFE58000UL
#define CCFC20xx_LINFLEX7L_BASE                         0xFFE5C000UL
#define CCFC20xx_LINFLEX8L_BASE                         0xFFFB0000UL
#define CCFC20xx_LINFLEX9L_BASE                         0xFFFB4000UL
#define CCFC20xx_LINFLEX10L_BASE                        0xFFFB8000UL
#define CCFC20xx_LINFLEX11L_BASE                        0xFFFBC000UL
#define CCFC20xx_LINFLEX12L_BASE                        0xFFFE8000UL
#define CCFC20xx_LINFLEX13L_BASE                        0xFFFEC000UL

#define CCFC20xx_LINFLEX0L  (*(struct CCFC20xxbc_linflexl *)CCFC20xx_LINFLEX0L_BASE)
#define CCFC20xx_LINFLEX0H  (*(struct CCFC20xxbc_linflexh *)CCFC20xx_LINFLEX0H_BASE)

#define CCFC20xx_LINFLEX1L  (*(struct CCFC20xxbc_linflexl *)CCFC20xx_LINFLEX1L_BASE)
#define CCFC20xx_LINFLEX1H  (*(struct CCFC20xxbc_linflexh *)CCFC20xx_LINFLEX1H_BASE)

#define CCFC20xx_LINFLEX2L  (*(struct CCFC20xxbc_linflexl *)CCFC20xx_LINFLEX2L_BASE)
#define CCFC20xx_LINFLEX3L  (*(struct CCFC20xxbc_linflexl *)CCFC20xx_LINFLEX3L_BASE)
#define CCFC20xx_LINFLEX4L  (*(struct CCFC20xxbc_linflexl *)CCFC20xx_LINFLEX4L_BASE)
#define CCFC20xx_LINFLEX5L  (*(struct CCFC20xxbc_linflexl *)CCFC20xx_LINFLEX5L_BASE)
#define CCFC20xx_LINFLEX6L  (*(struct CCFC20xxbc_linflexl *)CCFC20xx_LINFLEX6L_BASE)
#define CCFC20xx_LINFLEX7L  (*(struct CCFC20xxbc_linflexl *)CCFC20xx_LINFLEX7L_BASE)
#define CCFC20xx_LINFLEX8L  (*(struct CCFC20xxbc_linflexl *)CCFC20xx_LINFLEX8L_BASE)
#define CCFC20xx_LINFLEX9L  (*(struct CCFC20xxbc_linflexl *)CCFC20xx_LINFLEX9L_BASE)
#define CCFC20xx_LINFLEX10L  (*(struct CCFC20xxbc_linflexl *)CCFC20xx_LINFLEX10L_BASE)
#define CCFC20xx_LINFLEX11L  (*(struct CCFC20xxbc_linflexl *)CCFC20xx_LINFLEX11L_BASE)
#define CCFC20xx_LINFLEX12L  (*(struct CCFC20xxbc_linflexl *)CCFC20xx_LINFLEX12L_BASE)
#define CCFC20xx_LINFLEX13L  (*(struct CCFC20xxbc_linflexl *)CCFC20xx_LINFLEX13L_BASE)

#define CCFC20xx_LIN_TX_IN_PROGRESS(ddp)                                        \
  (ddp)->tx_busy = CCFC20xx_LIN_TX_BUSY

#define CCFC20xx_LIN_RX_IN_PROGRESS(ddp)                                        \
  (ddp)->rx_busy = CCFC20xx_LIN_RX_BUSY

#define CCFC20xx_LIN_TX_DONE(ddp)                                               \
  (ddp)->tx_busy = CCFC20xx_LIN_TX_READY

#define CCFC20xx_LIN_RX_DONE(ddp)                                               \
  (ddp)->rx_busy = CCFC20xx_LIN_RX_READY

#define CCFC20xx_LIN_WAIT_FOR_TX_COMPLETION(ddp)                                \
  if ((ddp)->config->api_mode == CCFC20xx_LIN_API_MODE_SYNCHRONOUS ||           \
      (ddp)->config->api_mode == CCFC20xx_LIN_API_MODE_BUFFERED_IO)             \
  {                                                                             \
    while ((ddp)->tx_busy == CCFC20xx_LIN_TX_BUSY)                              \
    { ; }                                                                       \
  }

#define CCFC20xx_LIN_WAIT_FOR_RX_COMPLETION(ddp)                                \
  if ((ddp)->config->api_mode == CCFC20xx_LIN_API_MODE_SYNCHRONOUS)             \
  {                                                                             \
    while ((ddp)->rx_busy == CCFC20xx_LIN_RX_BUSY)                              \
     { ; }                                                                      \
  }

/**
 * @brief   LIINFlex - 0 lin driver identifier.
 */
#if (CCFC20xx_LINFLEX0_SETTING == CCFC20xx_LINFLEX_MODE_LIN) || defined(__DOXYGEN__)
extern LinDriver LD1;
#endif

/**
 * @brief   LIINFlex - 1 lin driver identifier.
 */
#if (CCFC20xx_LINFLEX1_SETTING == CCFC20xx_LINFLEX_MODE_LIN) || defined(__DOXYGEN__)
extern LinDriver LD2;
#endif

/**
 * @brief   LIINFlex - 2 lin driver identifier.
 */
#if (CCFC20xx_LINFLEX2_SETTING == CCFC20xx_LINFLEX_MODE_LIN) || defined(__DOXYGEN__)
extern LinDriver LD3;
#endif

/** LIINFlex - 3 LIN driver identifier **/
#if (CCFC20xx_LINFLEX3_SETTING == CCFC20xx_LINFLEX_MODE_LIN) || defined(__DOXYGEN__)
extern LinDriver LD4;
#endif

/** LIINFlex - 4 LIN driver identifier **/
#if (CCFC20xx_LINFLEX4_SETTING == CCFC20xx_LINFLEX_MODE_LIN) || defined(__DOXYGEN__)
extern LinDriver LD5;
#endif

/** LIINFlex - 5 LIN driver identifier **/
#if (CCFC20xx_LINFLEX5_SETTING == CCFC20xx_LINFLEX_MODE_LIN) || defined(__DOXYGEN__)
extern LinDriver LD6;
#endif

/** LIINFlex - 6 LIN driver identifier **/
#if (CCFC20xx_LINFLEX6_SETTING == CCFC20xx_LINFLEX_MODE_LIN) || defined(__DOXYGEN__)
extern LinDriver LD7;
#endif

/** LIINFlex - 7 LIN driver identifier **/
#if (CCFC20xx_LINFLEX7_SETTING == CCFC20xx_LINFLEX_MODE_LIN) || defined(__DOXYGEN__)
extern LinDriver LD8;
#endif

/** LIINFlex - 8 LIN driver identifier **/
#if (CCFC20xx_LINFLEX8_SETTING == CCFC20xx_LINFLEX_MODE_LIN) || defined(__DOXYGEN__)
extern LinDriver LD9;
#endif

/** LIINFlex - 9 LIN driver identifier **/
#if (CCFC20xx_LINFLEX9_SETTING == CCFC20xx_LINFLEX_MODE_LIN) || defined(__DOXYGEN__)
extern LinDriver LD10;
#endif

/** LIINFlex - 10 LIN driver identifier **/
#if (CCFC20xx_LINFLEX10_SETTING == CCFC20xx_LINFLEX_MODE_LIN) || defined(__DOXYGEN__)
extern LinDriver LD11;
#endif

/** LIINFlex - 11 LIN driver identifier **/
#if (CCFC20xx_LINFLEX11_SETTING == CCFC20xx_LINFLEX_MODE_LIN) || defined(__DOXYGEN__)
extern LinDriver LD12;
#endif

/** LIINFlex - 12 LIN driver identifier **/
#if (CCFC20xx_LINFLEX12_SETTING == CCFC20xx_LINFLEX_MODE_LIN) || defined(__DOXYGEN__)
extern LinDriver LD13;
#endif

/** LIINFlex - 13 LIN driver identifier **/
#if (CCFC20xx_LINFLEX13_SETTING == CCFC20xx_LINFLEX_MODE_LIN) || defined(__DOXYGEN__)
extern LinDriver LD14;
#endif

/** API function **/
extern void Lin_Gpio_Init(const LinDriver *ldp, lin_gpio_select_t IO);
extern void Lin_Lld_Init(const LinDriver *ldp, const LinConfig *config);
extern void Lin_Lld_DeInit(const LinDriver *ldp);
extern void Lin_Init_IrqIsrEnable(const LinDriver *ldp);

extern uint16_t Lin_Master_Receive(LinDriver *ldp, uint8_t idMessage, uint8_t *buffer, uint8_t msg_len);
extern void Lin_Master_Transmit(LinDriver *ldp, uint8_t idMessage, uint8_t *buffer, uint8_t msg_len);
extern uint16_t Lin_Slave_Receive(LinDriver *ldp, uint8_t *buffer, uint8_t msg_len);
extern void Lin_Slave_Transmit(LinDriver *ldp, uint8_t idMessage, uint8_t *buffer, uint8_t msg_len);

extern void Lin_Master_Polling_Transmit(const LinDriver *ldp, uint8_t idMessage, const uint8_t *buffer, uint8_t buf_len);
extern void Lin_Master_Polling_Receive(const LinDriver *ldp, uint8_t idMessage, uint8_t *buffer, uint8_t buf_len);
extern void Lin_Slave_Polling_Receive(const LinDriver *ldp, uint8_t idMessage, uint8_t *buffer, uint8_t buf_len);
extern void Lin_Slave_Polling_Transmit(const LinDriver *ldp, uint8_t idMessage, const uint8_t *buffer, uint8_t buf_len);

extern void Lin_Master_Transmit_DMA(LinDriver *ldp, uint8_t idMessage, uint8_t *buffer, uint8_t msg_len);
extern uint16_t Lin_Master_Receive_DMA(LinDriver *ldp, uint8_t idMessage, uint8_t *buffer, uint8_t msg_len);
extern void Lin_Slave_Transmit_DMA(LinDriver *ldp, uint8_t idMessage, uint8_t *buffer, uint8_t msg_len);
extern uint16_t Lin_Slave_Receive_DMA(LinDriver *ldp, uint8_t *buffer, uint8_t msg_len);

extern void Lin_LLD_Lowper_enter(const LinDriver *ldp);
extern void Lin_LLD_Lowper_exit(const LinDriver *ldp);

extern void Lin_Master_Polling_Transmit_ExtendFrame(const LinDriver *lind, uint8_t idMessage, const uint8_t *buffer, uint8_t msg_len);

#endif
