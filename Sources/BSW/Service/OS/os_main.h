/******************************************************************************
* Copyright (C),                                                       
* File name:         os_main.h                                                       
*   <Author>         <Version>        <Date>                                      
*   HXL              0.2             2015-5-28                      
* Description:                             
* Develop pack:      CodeWarrior                                       
* Function List:          
*   1.                                                         
* History:                
*   1. Date:         2015-5-15                                                                  
*      Author:       HXL           
*      Ver:          0.1                                                        
*      Modification: Create                                                        
*   2. ...         
*   Standards:                                                            
******************************************************************************/
#ifndef _OS_MAIN_H_
#define _OS_MAIN_H_
/******************************************************************************
Includes
******************************************************************************/
#include "bsw_typedefs.h"


/** \brief the structure of os task monitor
 */
typedef struct os_task_monitor_Tag{
		uint32 tStart;
		uint32 tEnd;
		uint32 tI; 
		uint32 tC;
		uint32 tIMax;
		uint32 tIMin; 
		uint32 tCMax;
		uint32 tCMin; 
		uint8 stNotFirst;   
}os_task_monitor_t;

/** \brief the structure of all os task monitor
 */
typedef struct OS_Monitor_Tag {
		os_task_monitor_t OS_H1ms;
		os_task_monitor_t OS_H5ms;
		os_task_monitor_t OS_H10ms;
		os_task_monitor_t OS_H20ms;
		os_task_monitor_t OS_H100ms;
		os_task_monitor_t OS_L1ms;
		os_task_monitor_t OS_L5ms;
		os_task_monitor_t OS_L10ms;
		os_task_monitor_t OS_L20ms;
		os_task_monitor_t OS_L50ms;
		os_task_monitor_t OS_L100ms;
		os_task_monitor_t OS_L200ms;
		os_task_monitor_t OS_L500ms;
		os_task_monitor_t OS_L1000ms;
}OS_MonitorType;


/** \brief the enumerate of the task
*/
typedef enum
{
   OS_Task_H1ms=0,
   OS_Task_H5ms,
   OS_Task_H10ms,
   OS_Task_H20ms,
   OS_Task_H100ms,

   OS_Task_L1ms,
   OS_Task_L5ms,
   OS_Task_L10ms,
   OS_Task_L20ms,
   OS_Task_L50ms,    //generate from PIT_5ms
   OS_Task_L100ms,
   OS_Task_L200ms,   //generate from PIT_10ms
   OS_Task_L500ms,   //generate from PIT_20ms
   OS_Task_L1000ms   //generate from PIT_100ms
} OS_Task;

/** \brief the enumerate of the task entry
 */
typedef enum
{
   OS_TaskEntryA=0,        //BSW
   OS_TaskEntryB,          //BSW
   OS_TaskEntryC,
   OS_TaskEntryD, //Application Entry point ,BSW don't use
   OS_TaskEntryE, //COM_SERVICE Entry point ,BSW don't use
   OS_TaskEntryF,
   OS_TaskEntryG,          //BSW
   OS_TaskEntryH           //BSW
} OS_TaskEntry;

/** \brief the ptr of the service Task
 */
typedef void (*task_ptr)(void);

/******************************************************************************
Public Constant Definitions
******************************************************************************/
#define  OS_HTASK_NUMMAX         (5)
#define  OS_LTASK_NUMMAX         (9)
#define  OS_HTASK_STARTNUM       ((uint8)(OS_Task_H1ms))
#define  OS_HTASK_ENDNUM         ((uint8)(OS_Task_H100ms))
#define  OS_LTASK_STARTNUM       ((uint8)(OS_Task_L1ms))
#define  OS_LTASK_ENDNUM         ((uint8)(OS_Task_L1000ms))
#define  OS_TASK_NUMMAX          (OS_HTASK_NUMMAX+OS_LTASK_NUMMAX)
#define  OS_TASKENTRY_NUMMAX     (8)

/******************************************************************************
Exported Data Declarations
******************************************************************************/
extern OS_MonitorType OS_Monitor;
extern task_ptr OS_Task_Function[OS_TASK_NUMMAX][OS_TASKENTRY_NUMMAX];

/******************************************************************************
public task Definitions
******************************************************************************/
#define FP_OS_ASW_L1ms     (OS_Task_Function[OS_Task_L1ms][OS_TaskEntryD])
#define FP_OS_ASW_L5ms     (OS_Task_Function[OS_Task_L5ms][OS_TaskEntryD])
#define FP_OS_ASW_L10ms    (OS_Task_Function[OS_Task_L10ms][OS_TaskEntryD])
#define FP_OS_ASW_L20ms    (OS_Task_Function[OS_Task_L20ms][OS_TaskEntryD])
#define FP_OS_ASW_L50ms    (OS_Task_Function[OS_Task_L50ms][OS_TaskEntryD])
#define FP_OS_ASW_L100ms   (OS_Task_Function[OS_Task_L100ms][OS_TaskEntryD])
#define FP_OS_ASW_L200ms   (OS_Task_Function[OS_Task_L200ms][OS_TaskEntryD])
#define FP_OS_ASW_L500ms   (OS_Task_Function[OS_Task_L500ms][OS_TaskEntryD])
#define FP_OS_ASW_L1000ms  (OS_Task_Function[OS_Task_L1000ms][OS_TaskEntryD])

#define FP_OS_ASW_H1ms     (OS_Task_Function[OS_Task_H1ms][OS_TaskEntryD])
#define FP_OS_ASW_H5ms     (OS_Task_Function[OS_Task_H5ms][OS_TaskEntryD])
#define FP_OS_ASW_H10ms    (OS_Task_Function[OS_Task_H10ms][OS_TaskEntryD])
#define FP_OS_ASW_H20ms    (OS_Task_Function[OS_Task_H20ms][OS_TaskEntryD])
#define FP_OS_ASW_H100ms   (OS_Task_Function[OS_Task_H100ms][OS_TaskEntryD])

#define FP_OS_COM_SERVE_H1ms     (OS_Task_Function[OS_Task_H1ms][OS_TaskEntryH])
#define FP_OS_COM_SERVE_H5ms     (OS_Task_Function[OS_Task_H5ms][OS_TaskEntryH])
#define FP_OS_COM_SERVE_H10ms    (OS_Task_Function[OS_Task_H10ms][OS_TaskEntryH])
#define FP_OS_COM_SERVE_L1ms     (OS_Task_Function[OS_Task_L1ms][OS_TaskEntryH])
#define FP_OS_COM_SERVE_L20ms    (OS_Task_Function[OS_Task_L20ms][OS_TaskEntryH])
#define FP_OS_COM_SERVE_L100ms   (OS_Task_Function[OS_Task_L100ms][OS_TaskEntryH])

/******************************************************************************
Exported Function Declarations                                                                     
******************************************************************************/
extern void F_OS_Init(void);
extern void F_OS_LStart(void);

extern void F_OS_EnableAllTask(void);
extern void F_OS_DisableAllTask(void);

extern void F_OS_EnableASWTask(void);
extern void F_OS_DisbleASWTask(void);
extern void F_OS_ASWTaskCtrl(boolean Enable);

extern void F_OS_EnableTask(OS_Task Task);
extern void F_OS_DisableTask(OS_Task Task);

extern void F_OS_EnableTaskEntry(OS_Task Task,OS_TaskEntry TaskEntry);
extern void F_OS_DisableTaskEntry(OS_Task Task,OS_TaskEntry TaskEntry);

extern void F_OS_InstallTask(OS_Task Task,OS_TaskEntry TaskEntry,task_ptr Task_ptr);
extern void F_OS_UninstallTask(OS_Task Task,OS_TaskEntry TaskEntry);

extern void F_OS_GetTaskOperationState(OS_Task Task,os_task_monitor_t *task_monitor_ptr);

#endif
