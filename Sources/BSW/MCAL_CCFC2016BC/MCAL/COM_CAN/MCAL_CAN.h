/**********************************************************************
Copyright (c) ECO-EV Technologies Co., Ltd. 2015-2016.
All rights reserved.

File name:		Flash.h
Author:			ECO-EV
Version:		V1.0.1
Date:			2016-10-24
Description:
Others:
History:

	1. Date:
	   Author:
	   Modification:
	2. ...
**********************************************************************/
#ifndef _MCAL_CAN_H_
#define _MCAL_CAN_H_

#include "bsw_typedefs.h"
//#include "_Interrupt.h"
#include "IntcInterrupts.h"
#include "CCFC2016BC.h"


#define CAN_TOTAL_MAIL_BOX_NUM 64U
#define CAN_FIFO_USE_MAIL_BOX_NUM 8U
#define CAN_FIFO_FILTER_TABLE_NUM 8U
#define CAN_WORD_INDICATE_MAIL_BOX_NUM 32U

#define CANFD_MAX_FILTER_NUM        3U

static const uint8_t g_dlc_2_size_list[] =
{
    12, 16, 20, 24, 32, 48, 64,
};

#define BIT_SET(_word, _pos) ((_word) |= (1UL << (_pos)))
/* CANFD interface error code */
#define CANFD_OK                    0U
#define CANFD_ERROR_INVALID_PARA    1U
#define CANFD_ERROR_INVALID_STATE   2U
#define CANFD_ERROR_TRANS_BUF_BUSY  3U
#define CANFD_ERROR_NO_MSG_RECEIVED 4U
#define CANFD_ERROR_ABORT_MSG_TRANS 5U

#define Ifx__absf(X)                       ( ((X) < 0.0) ? -(X) : (X) )
extern sint32 __abs( sint32) __attribute__((intrinsic_pseudo(1, "abs") ));

#define Ifx__abs __abs

#ifndef IFX_ASSERT
#    define IFX_ASSERT(level, expr)   ((void)0)
#endif

#ifndef __absf
#define __absf Ifx__absf
#endif
#ifndef __abs
#define __abs Ifx__abs
#endif
#define SSCM_COD (*(volatile uint32_t *) 0xC3FD801CU)
#define SSCM_CANFD (*(volatile uint32_t *) 0xC3FD8068U)
//#define SSCM_CANFD    0x7fffff00
/** \brief Enumerate the Node of CAN
 */
typedef enum
{
	Mcal_CAN0 = 0,
	Mcal_CAN1 = 1,
	Mcal_CAN2 = 2,
	Mcal_CAN3 = 3,
//	Mcal_CAN4 = 4,
//	Mcal_CAN5 = 5,
//	Mcal_CAN6 = 6,
//	Mcal_CAN7 = 7,
	Mcal_MAX,
} Mcal_CAN_Node;


/** \brief Enumerate the message object of CAN
 */
typedef enum
{
	Mcal_CAN_MB00 = 0,
	Mcal_CAN_MB01 = 1,
	Mcal_CAN_MB02 = 2,
	Mcal_CAN_MB03 = 3,
	Mcal_CAN_MB04 = 4,
	Mcal_CAN_MB05 = 5,
	Mcal_CAN_MB06 = 6,
	Mcal_CAN_MB07 = 7,
	Mcal_CAN_MB08 = 8,
	Mcal_CAN_MB09 = 9,
	Mcal_CAN_MB10 = 10,
	Mcal_CAN_MB11 = 11,
	Mcal_CAN_MB12 = 12,
	Mcal_CAN_MB13 = 13,
	Mcal_CAN_MB14 = 14,
	Mcal_CAN_MB15 = 15,
	Mcal_CAN_MB16 = 16,
	Mcal_CAN_MB17 = 17,
	Mcal_CAN_MB18 = 18,
	Mcal_CAN_MB19 = 19,
	Mcal_CAN_MB20 = 20,
	Mcal_CAN_MB21 = 21,
	Mcal_CAN_MB22 = 22,
	Mcal_CAN_MB23 = 23,
	Mcal_CAN_MB24 = 24,
	Mcal_CAN_MB25 = 25,
	Mcal_CAN_MB26 = 26,
	Mcal_CAN_MB27 = 27,
	Mcal_CAN_MB28 = 28,
	Mcal_CAN_MB29 = 29,
	Mcal_CAN_MB30 = 30,
	Mcal_CAN_MB31 = 31,
	Mcal_CAN_MB32 = 32,
	Mcal_CAN_MB33 = 33,
	Mcal_CAN_MB34 = 34,
	Mcal_CAN_MB35 = 35,
	Mcal_CAN_MB36 = 36,
	Mcal_CAN_MB37 = 37,
	Mcal_CAN_MB38 = 38,
	Mcal_CAN_MB39 = 39,
	Mcal_CAN_MB40 = 40,
	Mcal_CAN_MB41 = 41,
	Mcal_CAN_MB42 = 42,
	Mcal_CAN_MB43 = 43,
	Mcal_CAN_MB44 = 44,
	Mcal_CAN_MB45 = 45,
	Mcal_CAN_MB46 = 46,
	Mcal_CAN_MB47 = 47,
	Mcal_CAN_MB48 = 48,
	Mcal_CAN_MB49 = 49,
	Mcal_CAN_MB50 = 50,
	Mcal_CAN_MB51 = 51,
	Mcal_CAN_MB52 = 52,
	Mcal_CAN_MB53 = 53,
	Mcal_CAN_MB54 = 54,
	Mcal_CAN_MB55 = 55,
	Mcal_CAN_MB56 = 56,
	Mcal_CAN_MB57 = 57,
	Mcal_CAN_MB58 = 58,
	Mcal_CAN_MB59 = 59,
	Mcal_CAN_MB60 = 60,
	Mcal_CAN_MB61 = 61,
	Mcal_CAN_MB62 = 62,
	Mcal_CAN_MB63 = 63

} Mcal_CAN_MsgObj;

/** \brief Enumerate the type of CAN error
 */
typedef enum
{
	Mcal_CAN_Error_NoError = 0,
	Mcal_CAN_Error_STF,
	Mcal_CAN_Error_FRM,
	Mcal_CAN_Error_ACK,
	Mcal_CAN_Error_BIT1,
	Mcal_CAN_Error_BIT0,
	Mcal_CAN_Error_CRC,
}Mcal_CAN_Error;

/** \brief Enumerate the CAN state
 */
typedef enum
{
	Mcal_CAN_ErrorState_Active = 0,			//Counter <96
	Mcal_CAN_ErrorState_TXWARN,
	Mcal_CAN_ErrorState_RXWARN,
	Mcal_CAN_ErrorState_WARN,
	Mcal_CAN_ErrorState_TXPassive,
	Mcal_CAN_ErrorState_RXPassive,
	Mcal_CAN_ErrorState_Passive,			//Counter >=128
	Mcal_CAN_ErrorState_BusOff,				//Counter>=256
}Mcal_CAN_ErrorState;

/** \brief Enumerate the BusOff whether AutoRecover
 */
typedef enum
{
	EnAutoRecover_BusOff = 0,
	DisAutoRecover_BusOff
}Mcal_CAN_BusOff_AutoRecover;

/** \brief Enumerate the mode of CAN message object
 */
typedef enum
{
	Code_RXINACTIVE = 0b0000,
	Code_RXEMPTY = 0b0100,
	Code_RXFULL = 0b0010,
	Code_RXOVERRUN = 0b0110,
	Code_RANSWER = 0b1010,

	Code_TXINACTIVE = 0b1000,
	Code_TXABORT = 0b1001,
	Code_TXONCE = 0b1100,
	Code_TXUNTILREMOTE = 0b1010,
	Code_TXTANSWER = 0b1110

}Mcal_CAN_MsgObjCode;



/** \brief Enumerate the mode of CAN
 */
typedef enum
{
	Mcal_CAN_Mode_Normal,
	Mcal_CAN_Mode_ListenOnly,
	Mcal_CAN_Mode_LoopBack,
	Mcal_CAN_Mode_Disable
}Mcal_CAN_Mode;


/** \brief define the structure of CanFrame
 */
typedef struct
{

    uint32	  	Id;              /**< \brief CAN message ID */
    uint8 		DataLength;      /**< \brief CAN message data length code */
    uint8     	Data[8];         /**< \brief CAN message data */
    uint8		Remote;
    uint8		Extend;
    uint8       LocalPriority;
} Mcal_CAN_Frame;
typedef struct
{
    uint32	  	Id;              /**< \brief CAN message ID */
    uint8 		DLC;      /**< \brief CAN message data length code */
    uint8     	Data[64];         /**< \brief CAN message data */
    uint8		Remote;
    uint8		Extend;
    uint8       ProtocolMode;
    uint8       FastBitRate;
    uint8       DataLength;
    uint8       ESI;
    uint8		FDF;
} Mcal_CANFD_Frame;
/** \brief define the structure of CAN pin
 */
typedef struct
{
	const Mcal_PortPin_In* RxPin;
	const Mcal_PortPin_Out* TxPin;
}Mcal_CAN_Pin;


/** \brief define the structure for Configure CAN
 */
typedef struct
{
	boolean enChannel;
	boolean enIDFilter;
	uint32 rxID;
	uint32 rxIDMask;
	boolean Extended;
	uint16 baudrate;
	   
	uint32      BaudRate;	//500 --500k
	Mcal_CAN_Mode Mode;
	uint8 DisAutoRecover_BusOff;
	uint8 EnInterrupt_BusOff;
	uint8 EnInterrupt_Error;
	uint8 EnInterrupt_TxWarning;			//TxWarning = Tx_Err_Counter>96
	uint8 EnInterrupt_RxWarning;			//RxWarning = Rx_Err_Counter>96
	uint8 En_LowestFirst;
	
	//	Mcal_CANFD_Config fdConfig;
	boolean        CanFD_Enable;
	uint16         CanFD_nominalSynchJumpWidth;
	uint16         CanFD_nominalSamplePoint;
	uint32         CanFD_slowBaudrate;
	uint32         CanFD_fastBaudrate;
	uint16         CanFD_fastSynchJumpWidth;
	uint16         CanFD_fastSamplePoint;
	uint16         CanFD_loopDelayOffset;
}Mcal_CAN_NodeConfigure;


typedef struct {
    uint8_t is_remote;
    uint8_t is_extern;
    uint32_t id;
    uint32_t mask;
} CANFilter;


/** \brief define the structure for Configure CAN message object
 */
typedef struct
{
	Mcal_CAN_MsgObjCode  Code;
	uint8		EnInterrupt;
	uint32 	RxID;
	uint32 	RxIDMask;
	uint8 	Extend;
	uint8  	CanFD;

}Mcal_CAN_MsgObjConfigure;

/* CAN filter parameter */
typedef struct {
    uint8_t is_valid;
    uint8_t resv;
    uint32_t id;
    uint32_t mask; /* For bits is set to 1, the receiving ID must be the same as the filtering ID */
} CANFDFilter;
/* CANFD configuration parameter */
typedef struct {
//    CANFDModId canfd_id;
//    CANFDPhyPara phy_para;
//    CANFDFuncSwitch func_switch;
    CANFDFilter filter[CANFD_MAX_FILTER_NUM];
//    CANFDIntrCallback call_back;
} CANFDConfig;





typedef enum {
    CANFD_TRANS_BUF_TYPE_PRIMARY,
    CANFD_TRANS_BUF_TYPE_SECONDARY,
    CANFD_TRANS_BUF_TYPE_BUTT
} CANFDTransBufType;

/* CANFD data length */
typedef enum
{
    /* within 8 bytes, the DLC value is the same as the data length */
    CANFD_DLC_12_BYTES = 9UL,
    CANFD_DLC_16_BYTES,
    CANFD_DLC_20_BYTES,
    CANFD_DLC_24_BYTES,
    CANFD_DLC_32_BYTES,
    CANFD_DLC_48_BYTES,
    CANFD_DLC_64_BYTES,
    CANFD_DLC_TYPE_BUTT
} CANFD_DlcType; /* PRQA S 1535 # useful */

static inline void Canfd_LLD_Switch_In(uint32 SSCM_val) /* PRQA S 3007 # specified address is reserved in SSCM struct */
{
    /* enter privilege mode */
    SSCM_COD = 0xA5A56666U;
    SSCM_COD = 0xB6B67777U;

    SSCM_CANFD = SSCM_val;

    /* exit privilege mode */
    SSCM_COD = 0xC7C78888U;
}
static inline void Canfd_LLD_Switch_Out(void) /* PRQA S 3007 # specified address is reserved in SSCM struct */
{
    /* enter privilege mode */
    SSCM_COD = 0xA5A56666U;
    SSCM_COD = 0xB6B67777U;

    /* Exit CANFD mode */
    SSCM_CANFD = 0U;

    /* exit privilege mode */
    SSCM_COD = 0xC7C78888U;
}

typedef void (*ErrIsr_PtrType)(Mcal_CAN_Node Node,Mcal_CAN_Error Error);
typedef void (*ErrStateIsr_PtrType)(Mcal_CAN_Node Node,Mcal_CAN_ErrorState Error);
typedef void (*MsgObjIsr_PtrType)(Mcal_CAN_Node Node,Mcal_CAN_MsgObj MsgObj);
typedef void (*FDTxIsr_PtrType)(Mcal_CAN_Node Node, CANFDTransBufType buf_idx);
typedef void (*FDRxIsr_PtrType)(Mcal_CAN_Node Node, Mcal_CANFD_Frame * rx_msg);
typedef void (*FDIsrTest_PtrType)(Mcal_CAN_Node Node);




/******************************************************************************
_PinMap_CAN
******************************************************************************/
extern const Mcal_PortPin_Out CAN0_TX_PB00_OUT;
extern const Mcal_PortPin_Out CAN1_TX_PC10_OUT;
extern const Mcal_PortPin_Out CAN2_TX_PF08_OUT;
extern const Mcal_PortPin_Out CAN3_TX_PE08_OUT;
extern const Mcal_PortPin_Out CAN4_TX_PF14_OUT;
extern const Mcal_PortPin_Out CAN5_TX_PG00_OUT;
extern const Mcal_PortPin_Out CAN6_TX_PI08_OUT;
extern const Mcal_PortPin_Out CAN7_TX_PI09_OUT;

extern const Mcal_PortPin_In CAN0_RX_PB01_IN;
extern const Mcal_PortPin_In CAN1_RX_PC11_IN;
extern const Mcal_PortPin_In CAN2_RX_PF09_IN;
extern const Mcal_PortPin_In CAN3_RX_PE09_IN;
extern const Mcal_PortPin_In CAN4_RX_PF15_IN;
extern const Mcal_PortPin_In CAN5_RX_PG01_IN;
extern const Mcal_PortPin_In CAN6_RX_PI10_IN;
extern const Mcal_PortPin_In CAN7_RX_PI11_IN;

extern volatile struct FLEXCAN_tag *CAN[4];
extern volatile struct FLEXCANFD_tag *CANFD[4];

/******************************************************************************
public symbol Definitions
******************************************************************************/
#define		MCAL_CANCHANNEL_NUMMAX		(4)
#define 	MCAL_CAN_MB_NUMMAX			(64)
#define 	MCAL_CAN_INTERRUPT_NUMMAX	(68)
#define     CAN_FLEXCAN_START_PCTL        (ME_PCTL_RUN(1) |          \
                                                  ME_PCTL_LP(2))
/******************************************************************************
Exported Function Declarations
******************************************************************************/
extern void Mcal_CAN_InitPin(Mcal_CAN_Pin *CAN_Pin);
//extern void Canfd_LLD_Switch_In(Mcal_CAN_Node Node);
extern void Mcal_CAN_ConfigureNode(Mcal_CAN_Node Node,Mcal_CAN_NodeConfigure *NodeConfigure);
//extern void Mcal_CANFD_ConfigureNode(Mcal_CANFD_Node Node,Mcal_CAN_NodeConfigure *NodeConfigure);
extern void Mcal_CAN_SetBaudRate(Mcal_CAN_Node Node,uint32 BaudRate);
extern void Mcal_CAN_SetMode(Mcal_CAN_Node Node,Mcal_CAN_Mode Mode);
extern void IfxCan_Node_setFastBitTiming(Mcal_CAN_Node Node, uint32 baudrate, uint16 samplePoint, uint16 syncJumpWidth);
extern void IfxCan_Node_setNominalBitTiming(Mcal_CAN_Node Node, uint32 baudrate, uint16 samplePoint, uint16 syncJumpWidth);

extern void Mcal_CAN_ConfigureMsgObj(Mcal_CAN_Node Node,Mcal_CAN_MsgObj CAN_MsgObj,Mcal_CAN_MsgObjConfigure *MsgObjConfigure);
extern void Mcal_CANFD_ConfigureMsgObj(Mcal_CAN_Node Node);
extern uint8 Mcal_CAN_WriteMsgObj(Mcal_CAN_Node Node,Mcal_CAN_MsgObj CAN_MsgObj,Mcal_CAN_Frame *TxFrame);
extern uint8 Mcal_CANFD_WriteMsgObj(Mcal_CAN_Node Node,Mcal_CANFD_Frame *TxFDFrame);
extern uint8 Mcal_CAN_ReadMsgObj(Mcal_CAN_Node Node,Mcal_CAN_MsgObj CAN_MsgObj,Mcal_CAN_Frame *RxFrame);
extern uint8 Mcal_CAN_TxFrame(Mcal_CAN_Node node, Mcal_CAN_Frame *tx_frame);
extern uint8 Mcal_CAN_RxFrame(Mcal_CAN_Node node, Mcal_CAN_Frame *rx_frame);
extern uint8 Mcal_CAN_GetMsgObjCode(Mcal_CAN_Node Node,Mcal_CAN_MsgObj CAN_MsgObj);

extern uint8 Mcal_CAN_ReadTxErrorCounter(Mcal_CAN_Node Node);
extern uint8 Mcal_CAN_ReadRxErrorCounter(Mcal_CAN_Node Node);
extern Mcal_CAN_Error Mcal_CAN_GetLastError(Mcal_CAN_Node Node);
extern Mcal_CAN_ErrorState Mcal_CAN_GetErrorState(Mcal_CAN_Node Node);
extern void  Mcal_CAN_ConfBusoffRec(Mcal_CAN_Node Node,Mcal_CAN_BusOff_AutoRecover state);

extern void  Mcal_CAN_InstallErrIsr(Mcal_CAN_Node node,ErrIsr_PtrType IsrPtr);
extern void  Mcal_CAN_InstallErrStateIsr(Mcal_CAN_Node node,ErrStateIsr_PtrType IsrPtr);
extern void  Mcal_CAN_InstallMsgObjIsr(Mcal_CAN_Node node,MsgObjIsr_PtrType IsrPtr);
extern void  Mcal_CANFD_InstallMsgObjIsr(Mcal_CAN_Node Node,FDRxIsr_PtrType rx_isr);
extern void  Mcal_CAN_InstallTxCopleteIsr(Mcal_CAN_Node Node,MsgObjIsr_PtrType IsrPtr);
extern void  Mcal_CANFD_InstallTxCopleteIsr(Mcal_CAN_Node Node,FDTxIsr_PtrType buf_idx);
extern void  Mcal_CAN_UninstallErrIsr(Mcal_CAN_Node node);
extern void  Mcal_CAN_UninstallErrStateIsr(Mcal_CAN_Node node);
extern void  Mcal_CAN_UninstallMsgObjIsr(Mcal_CAN_Node node);
extern void  Mcal_CAN_UninstallTxCompleteIsr(Mcal_CAN_Node Node);



#endif
