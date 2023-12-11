//   Copyright 2023 AUC-Siemens Thesis Project
//
//   Licensed under the Apache License, Version 2.0 (the "License");
//   you may not use this file except in compliance with the License.
//   You may obtain a copy of the License at
//
//       http://www.apache.org/licenses/LICENSE-2.0
//
//   Unless required by applicable law or agreed to in writing, software
//   distributed under the License is distributed on an "AS IS" BASIS,
//   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//   See the License for the specific language governing permissions and
//   limitations under the License.

#include "EventMechanism.h"

/**
#################################################################################################
Syntax:             StatusType SetEvent ( TaskType <TaskID> EventMaskType <Mask> )

Parameter (In):     TaskID      Reference to the task for which one or several events are to be set.
                    Mask        Mask of the events to be set
Parameter (Out):    none

Description:        The service may be called from an interrupt service routine and
                    from the task level, but not from hook routines.
                    The events of task <TaskID> are set according to the event
                    mask <Mask>. Calling SetEvent causes the task <TaskID> to
                    be transferred to the ready state, if it was waiting for at least
                    one of the events specified in <Mask>.

Particularities:    Any events not set in the event mask remain unchanged.

Status:

\a Standard: \a
        *  * No error, E_OK


\a Extended: \a
          *  * Task <TaskID> is invalid, E_OS_ID

          *  * Referenced task is no extended task, E_OS_ACCESS

          *  * Events can not be set as the referenced task is in the suspended state, E_OS_STATE

Conformance:        ECC1, ECC2
#################################################################################################
*/


/*

[SWS_Os_00602] dIt shall be possible to set an Event that is part of an OSApplication located on another core,
 as long as the assigned access rights allow it (SRS_Os_80016)
 
[SWS_Os_00604] dThe call of SetEvent across cores shall behave synchronously,
i.e. a call returns after the Event has been set or an error has been detected. It
shall not be possible to continue execution on the calling core before SetEvent is
accomplished on the remote core.c(SRS_Os_80016)
[SWS_Os_00605] dIn case of an error when calling SetEvent across cores, the error
handler shall be called on the core on which SetEvent was originally called.c(SRS_-
Os_80016)
[SWS_Os_00817] dThe operating system shall provide an asynchronous version of
SetEvent which does not return errors to the caller, but only calls the (global) error
hook (if configured). The function name shall be SetEventAsyn.c(SRS_Os_80016)

*/

StatusType SetEvent(TaskType TaskID, EventMaskType Mask){
    StatusType status = E_OK;
    uint32_t flag = 0;

    // multicore migration
    // get application id

    ApplicationType AppID = GetCurrentApplicationID_Kernel();
    
    if (AppID == OS_CORE_ID_MASTER_0) {
 // todo: initiate system call to the corresponing core and send the correct parameters 
    // todo: such as:
        // syscall_SetEvent_TC0(TaskID, 0, 0, Mask, 0, 0, 0, &status, &flag);
    }else if (AppID == OS_CORE_ID_1) {
         // todo: initiate system call to the corresponing core and send the correct parameters 
    // todo: such as:
        //syscall_SetEvent_TC1(TaskID, 0, 0, Mask, 0, 0, 0, &status, &flag);
    }else if (AppID == OS_CORE_ID_2) {//todo:
    }else if (AppID == OS_CORE_ID_3) {//todo:
    }else if (AppID == OS_CORE_ID_4) {//todo:
    }else if (AppID == OS_CORE_ID_5) {//todo:
    }else if (AppID == OS_CORE_ID_6) {//todo:
    }else{}
  return status;
}

// this is the kernel implementation of SetEvent
void SetEvent_Kernel(TaskType TaskID, EventMaskType Mask, StatusType *status, uint32_t *flag) {

 
  //! Inquire about whether to handle case where it can't be called from hook routine
 
  ApplicationType AppID = GlobalTaskAppId[TaskID];
  ApplicationType CurrentApp = GetCurrentApplicationID_Kernel();
  *status = E_OK;
  if(AppID != CurrentApp){
      

      if (AppID == OS_CORE_ID_MASTER_0) {

        // todo: follow the activatetask API cross core example to implement this

      }else if (AppID == OS_CORE_ID_1) {
                // todo: follow the activatetask API cross core example to implement this

      }else if (AppID == OS_CORE_ID_2) {
                // todo: follow the activatetask API cross core example to implement this

      }else if (AppID == OS_CORE_ID_3) {
               // todo: follow the activatetask API cross core example to implement this

      }else if (AppID == OS_CORE_ID_4) {
                // todo: follow the activatetask API cross core example to implement this

      }else if (AppID == OS_CORE_ID_5) {
               // todo: follow the activatetask API cross core example to implement this

      }else if (AppID == OS_CORE_ID_6) {
               // todo: follow the activatetask API cross core example to implement this

      }else{}
      
      while(*flag == 0){
          //synchronize with the other core
      }
  }
  else{
      // Making sure that this task exisits in the system
      if ((TaskID >= MAX_TASK_ID) || (TaskID < 0)) {
        *status = E_OS_ID;
        ErrorHook_Kernel(*status);
      }

      // Making sure its an extended task
      else if (OSApp[AppID].Tasks[TaskID].VERSION != EXTENDED) {
        *status = E_OS_ACCESS;
        ErrorHook_Kernel(*status);
      }

      // Making sure that the task state is not susspended
      else if (OSApp[AppID].Tasks[TaskID].TaskState == SUSPENDED) {
        *status = E_OS_STATE;
        ErrorHook_Kernel(*status);
      } else {
        // Setting the Events to the given Mask
        OSApp[AppID].Tasks[TaskID].Events |= Mask;

        // Making sure its in the waiting state
        if (OSApp[AppID].Tasks[TaskID].TaskState == WAITING) {

          if ((OSApp[AppID].Tasks[TaskID].WaitEvents & Mask) != (0U)) {
            OSApp[AppID].Tasks[TaskID].TaskState = READY;
          PqPush(&OSApp[AppID].ReadyQueue, TaskID,
                OSApp[AppID].Tasks[TaskID].PRIORITY);
            Schedule_Kernel(status);
          }
        }
      }

      //synchronize with the other core
    *status *= -1;
    // todo: sync data between cores

    if ((*status * *status) != E_OK) {
      ErrorHook_Kernel(*status);
    }

  }
}