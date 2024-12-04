
/*************************************************************
Copyright (c) ECO-EV Technologies Co., Ltd. 2015-2016. All rights reserved.

File name:		Abstraction_CAN.h
Author:			ECO-EV
Version:		V1.0.1
Date:			2016-12-28
Description:
Others:
History:

	1. Date:
	   Author:
	   Modification:
	2. ...
**************************************************************/

#ifndef ABSTRACTION_CAN_H
#define ABSTRACTION_CAN_H

/*************************************************************
Includes
**************************************************************/
#include "MCAL_CAN.h"
#include "bsw_typedefs.h"
#include "MCAL_INTC.h"

#define USE_CANFD
#define RECOVER_BUSOFF_BSW_EN_AUTO
#define RECOVER_BUSOFF_FUNC_DEF


/** \brief the enumerate of the CAN channel
 */
typedef enum
{
   CAN_CTRL_A=0,
   CAN_CTRL_B,
   CAN_CTRL_C,
   CAN_CTRL_D,
//   CAN_CTRL_E,
//   CAN_CTRL_F,
//   CAN_CTRL_G,
//   CAN_CTRL_H

}CanControllerIdType;

/** \brief the structure of the CAN configure
 */
typedef Mcal_CAN_NodeConfigure CANDeviceSetting_t;

/** \brief the structure of the CAN message
 */
typedef struct
{
   uint8 data[8];   //
   uint32 id;        //
   boolean extended;
   uint8 length;
   boolean remote;
} CANMsgElement_t;


/** \brief the structure of the CAN message queue
 */
typedef struct
{
   CANMsgElement_t  *queue;
   uint16 maxSize;
   uint16 front;
   uint16 rear;
   boolean reading;
   boolean writing;
} CANMsgQueue_t;

/** \brief the structure of the CAN message queue information
 */
typedef struct
{
//	uint8           channel;
	CANMsgElement_t *Ele;
	uint16          size;
} CANMsgElementPrt_t;


typedef struct
{
   uint8   data[64];   //
   uint32  id;
   boolean extended;
   uint8   length;
   boolean remote;
   boolean extend;
   uint8   fastBitRate;
   uint8   ESI;
   uint8   DLC;
   uint8   FDF;
} CANFDMsgElement_t;

/** \brief the structure of the CAN Rx slot
 */
typedef struct
{
   uint8 ready;
   uint8 read;
   uint8 write;
   CANMsgElement_t messageObj;
} CANDirectSlot_t;
//typedef struct
//{
//   uint8 ready;
//   uint8 read;
//   uint8 write;
//   CANFDMsgElement_t FDmessageObj;
//} CANFDDirectSlot_t;
/** \brief the structure of the CAN Rx slot link
 */
typedef struct
{
   CANDirectSlot_t  *queue;
   uint16 maxSize;
   uint16 front;
   uint16 rear;
   uint16 track;
} CANDirectSlot_Queue_t;

/** \brief the structure of the CAN Rx message
 */
typedef struct
{
   CANDirectSlot_t  *Ele;   //
   uint16 size;             //
} CANDirectSlotElementPrt_t;


/** \brief the enumerate of the CAN Transceiver type
 */
typedef enum
{
	CAN_Type_NONE,
   CAN_Type_TLE6251D,
   CAN_Type_TJA1044T,
   CAN_Type_TJA1145T,
   CAN_Type_FS6500,
   CAN_Type_MC33907,
   CAN_Type_TJA1051T,
   CAN_Type_MCP2515,

}CanTransceiverType;


/** \brief the enumerate of the CAN Mode
 */
typedef enum
{
	CAN_Mode_Normal=0,
	CAN_Mode_ListenOnly,
	CAN_Mode_Loopback,
	CAN_Mode_Disable
}CAN_Mode_t;


/** \brief the enumerate of the CAN WakeUp
 */
typedef enum
{
	CAN_WakeUpMode_Disable=0,
	CAN_WakeMode_Unselective,
	CAN_WakeMode_Selective
}CAN_WakeUpMode;
typedef enum
{
    IfxMultican_DataLengthCode_0 = 0,    /**< \brief 0 data bytes  */
    IfxMultican_DataLengthCode_1,        /**< \brief 1 data bytes  */
    IfxMultican_DataLengthCode_2,        /**< \brief 2 data bytes  */
    IfxMultican_DataLengthCode_3,        /**< \brief 3 data bytes  */
    IfxMultican_DataLengthCode_4,        /**< \brief 4 data bytes  */
    IfxMultican_DataLengthCode_5,        /**< \brief 5 data bytes  */
    IfxMultican_DataLengthCode_6,        /**< \brief 6 data bytes  */
    IfxMultican_DataLengthCode_7,        /**< \brief 7 data bytes  */
    IfxMultican_DataLengthCode_8,        /**< \brief 8 data bytes  */
    IfxMultican_DataLengthCode_12 = 9,   /**< \brief 12 data bytes */
    IfxMultican_DataLengthCode_16 = 10,  /**< \brief 16 data bytes */
    IfxMultican_DataLengthCode_20 = 11,  /**< \brief 20 data bytes */
    IfxMultican_DataLengthCode_24 = 12,  /**< \brief 24 data bytes */
    IfxMultican_DataLengthCode_32 = 13,  /**< \brief 32 data bytes */
    IfxMultican_DataLengthCode_48 = 14,  /**< \brief 48 data bytes */
    IfxMultican_DataLengthCode_64 = 15   /**< \brief 64 data bytes */
} IfxMultican_DataLengthCode;
/** \brief the structure of the remote-wake configure
 */
typedef struct
{
   CAN_WakeUpMode WakeUpMode;
   uint16      BaudRate;         //only 50k,100k,125k,250k,500k,1000k  valid
   uint32      Id;
   uint32      IdMask;
   boolean     Extend;
   boolean     EvaluateData;
   uint8       DLC;				//If DLC!=0000, at least one bit in the data field  must be set to 1
   uint8       DataMask[8];		//at least one equivalent bit must also be set to 1 for a successful wake-up.
} CAN_WakeUpConf;

/** \brief Enumerate the CAN Error
 */
typedef enum
{
	CAN_Error_NoError = 0,
	CAN_Error_STF,
	CAN_Error_FRM,
	CAN_Error_ACK,
	CAN_Error_BIT1,
	CAN_Error_BIT0,
	CAN_Error_CRC,
}CAN_Error;

/** \brief Enumerate the CAN Error state
 */
typedef enum
{
	CAN_ErrorState_Active = 0,			//Counter <96
	CAN_ErrorState_TXWARN,
	CAN_ErrorState_RXWARN,
	CAN_ErrorState_WARN,
	CAN_ErrorState_TXPassive,
	CAN_ErrorState_RXPassive,
	CAN_ErrorState_Passive,			//Counter >=128
	CAN_ErrorState_BusOff,			//Counter>=256
}CAN_ErrorState;

/** \brief Enumerate the BusOff whether AutoRecover
 */
typedef enum
{
	EnAutoRecover = 0,
	DisAutoRecover
}CAN_BusOff_AutoRecover;

typedef struct
{
//	CANFDMsgElement_t *queue;
	uint16          maxSize;
	uint16          front;
	uint16          rear;
	boolean         reading;
	boolean         writing;
} CANFDMsgQueue_t;

typedef struct
{
//	uint8           channel;
	CANFDMsgElement_t *Ele;
	uint16          size;
} CANFDMsgElementPrt_t;
typedef struct
{
   CANMsgElement_t* First_Ptr;
   uint16 Length;
   uint16 Index_In;           //
   uint16 Index_Out;          //
   Mcal_CAN_MsgObj Pos_MsgObj;
   Mcal_INTC_SS_Source Transmit_EventCh;
}Abstr_CanMessageQueue;

typedef struct
{
   CANFDMsgElement_t* First_Ptr;
   uint16 Length;
   uint16 Index_In;
   uint16 Index_Out;
   Mcal_CAN_MsgObj Pos_MsgObj;
   Mcal_INTC_SS_Source Transmit_EventCh;
   CANFDTransBufType BufType;
//   boolean Abstr_CANFDTxOP_Flag;
}Abstr_CanFDMessageQueue;
/** \brief the structure of the CAN message queue
 */
typedef struct
{
   boolean IsExist;
   boolean AbsCanFDEnableFlag;
   Mcal_CAN_Node CanNode;
   CanTransceiverType TransceiverType;
   
   uint8 ChipNum;
   
   Abstr_CanMessageQueue TxQueue;
   Abstr_CanFDMessageQueue FDTxQueue;
   CANDirectSlot_t* RxSlot_Ptr;
//   CANFDDirectSlot_t* FDRxSlot_Ptr;
   uint16 RxSlot_Num;
   uint16 FDRxSlot_Num;

   uint32 RxCount;
   uint32 FDRxCount;

}Abstr_CanStruct;

typedef void (*FType_Abstr_CANRxIsr)(CanControllerIdType channel,CANMsgElement_t *messageObj);
typedef void (*FType_Abstr_CANFDRxIsr)(CanControllerIdType channel,CANFDMsgElement_t *FDmessageObj);

/*************************************************************
Exported Function Declarations                                                                     
**************************************************************/
extern void F_Abstr_CAN_BuildChannel(CanControllerIdType controller,CanTransceiverType TransceiverType,uint8 ChipNum,Mcal_CAN_Node CanNode);

extern void F_Abstr_CANDevice_Init(CanControllerIdType controller,CANDeviceSetting_t *canSetting);
extern uint8 F_Abstr_CAN_Init(CANMsgQueue_t *canMsgTxQueue,CANMsgElementPrt_t *canMsgElementPrt,uint8 numChannel);
extern uint8 F_Abstr_CANRx_Init(CANDirectSlot_Queue_t *rxMsgQueueArray,CANDirectSlotElementPrt_t *canDirectSlotElementPrt,uint8 numChannel);
extern uint8 F_Abstr_CAN_Transmit2Queue(CanControllerIdType channel, CANMsgElement_t *messageObj);
extern uint8 F_Abstr_CAN_ReceiveDirect(CANDirectSlot_t *directslot, CANMsgElement_t *messageObj);
extern uint32 F_Abstr_CAN_RxLiveCounter(CanControllerIdType channel);
extern uint8 F_Abstr_CAN_ConfigWakeup(CanControllerIdType controller ,CAN_WakeUpConf* WakeUpConf_Ptr);
extern void F_Abstr_CAN_ModeSet(CanControllerIdType controller, CAN_Mode_t CanNodeMode);
extern void F_Abstr_CAN_InstallRxSltCall(FType_Abstr_CANRxIsr CANRxIsrPtr);
extern void F_Abstr_CANFD_InstallRxSltCall(FType_Abstr_CANFDRxIsr CANFDRxIsrPtr);
extern void F_Abstr_CAN_TransmitQueue_1ms(void);
extern void F_Abstr_CANFD_TransmitQueue_1ms(void);
extern CAN_Error F_Abstr_CAN_GetLastError(CanControllerIdType channel);
extern CAN_ErrorState F_Abstr_CAN_GetErrorState(CanControllerIdType channel);
extern uint8 F_Abstr_CAN_GetTxErrorCounter(CanControllerIdType channel);
extern uint8 F_Abstr_CAN_GetRxErrorCounter(CanControllerIdType channel);
extern void F_Abstr_CAN_ConfBusoffRec(CanControllerIdType channel,CAN_BusOff_AutoRecover state);
extern void CAN_PinInit(void);

#ifdef RECOVER_BUSOFF_BSW_EN_AUTO
extern void F_Abstr_CAN_DisBSWRecBusOff(CanControllerIdType channel);
#endif

#ifdef RECOVER_BUSOFF_FUNC_DEF
extern void F_Abstr_CAN_RecoverBusOff(CanControllerIdType channel);
#endif





#endif /* ABSTRACTION_CAN_H_ */
