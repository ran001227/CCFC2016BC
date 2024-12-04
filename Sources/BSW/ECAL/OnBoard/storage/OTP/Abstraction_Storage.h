/*************************************************************
Copyright (c) ECO-EV Technologies Co., Ltd. 2015-2016. All rights reserved.

File name:		OTP.h
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
#ifndef _Abstraction_Storage_H_
#define _Abstraction_Storage_H_
#include "bsw_typedefs.h"

typedef enum
{
	OTP_OP_Success=0,
	OTP_OP_OutRange,
	OTP_OP_AddrErr,
	OTP_OP_LenErr,
	OTP_OP_WriteErr,
	OTP_OP_ParaErr
}OTP_OP_Result;


extern OTP_OP_Result F_Abs_Storage_OTP_Read(uint32 offset, uint32 len, uint8 * const out_buf);
extern OTP_OP_Result F_Abs_Storage_OTP_Write(uint32 offset, uint32 len, const uint8 *data_buf);

#endif
