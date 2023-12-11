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

// [SWS_Os_00817] dThe operating system shall provide an asynchronous version of
// SetEvent which does not return errors to the caller, but only calls the (global) error
// hook (if configured). The function name shall be SetEventAsyn.c(SRS_Os_80016)

// [SWS_Os_00819] dAvailability of SetEventAsyn: Available in systems which support
// OS-Applications.c(SRS_Os_80015)

void SetEventAsyn(TaskType TaskID, EventMaskType Mask){
    
   

    // multicore migration
    // get application id

    ApplicationType AppID = GetCurrentApplicationID_Kernel();
    
    if (AppID == OS_CORE_ID_MASTER_0) {
// todo: initiate system call to the corresponing core and send the correct parameters 
    // todo: such as:
        //syscall_SetEventAsyn_TC0(TaskID, 0, 0, Mask, 0, 0, 0, 0, 0);
    }else if (AppID == OS_CORE_ID_1) {
        // todo: initiate system call to the corresponing core and send the correct parameters 
    // todo: such as:
        //syscall_SetEventAsyn_TC1(TaskID, 0, 0, Mask, 0, 0, 0, 0, 0);
    }else if (AppID == OS_CORE_ID_2) {//todo:
    }else if (AppID == OS_CORE_ID_3) {//todo:
    }else if (AppID == OS_CORE_ID_4) {//todo:
    }else if (AppID == OS_CORE_ID_5) {//todo:
    }else if (AppID == OS_CORE_ID_6) {//todo:
    }else{}
  return;
}


void SetEventAsyn_Kernel(TaskType TaskID, EventMaskType Mask){

   //! Inquire about whether to handle case where it can't be called from hook routine
 
  ApplicationType AppID = GlobalTaskAppId[TaskID];
  ApplicationType CurrentApp = GetCurrentApplicationID_Kernel();
  StatusType *status = E_OK;
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

    
    if (status != E_OK) {
      ErrorHook_Kernel(*status);
    }
      
  }

      
}