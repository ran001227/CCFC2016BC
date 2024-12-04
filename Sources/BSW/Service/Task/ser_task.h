/************************************************************************
Copyright (c) ECO-EV Technologies Co., Ltd. All rights reserved.

File name:     Ser_Task.h
Author:        ECO-EV
Version:
Date:
Description:
Others:
History:

   1. Date:
      Author:
      Modification:
   2. ...
*************************************************************************/
#ifndef   _SER_TASK_H_
#define   _SER_TASK_H_

/******************************************************************************
Exported Function Declarations
******************************************************************************/
typedef void (*FType_Task_ServiceWWD)(void);

extern FType_Task_ServiceWWD FPTask_ServiceWWD;

extern void Ser_Task_BSW_Init(void);

#endif
