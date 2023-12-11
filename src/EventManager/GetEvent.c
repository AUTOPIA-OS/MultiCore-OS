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
Syntax:             StatusType GetEvent ( TaskType <TaskID> EventMaskRefType <Event> )
Parameter (In):     TaskID      Task whose event mask is to be returned.
Parameter (Out):    Event       Reference to the memory of the return data.
Description:        This service returns the current state of all event bits of the task
                    <TaskID>, not the events that the task is waiting for.
                    The service may be called from interrupt service routines, task
                    level and some hook routines (see Figure 12-1).
                    The current status of the event mask of task <TaskID> is copied
                    to <Event>.
Particularities:    The referenced task shall be an extended task.

Status:

\a Standard: \a
* * No error, E_OK

\a Extended: \a
* * Task <TaskID> is invalid, E_OS_ID
* * Referenced task <TaskID> is not an extended task, E_OS_ACCESS
* * Referenced task <TaskID> is in the suspended state, E_OS_STATE

Conformance:        ECC1, ECC2
#################################################################################################
*/

StatusType GetEvent(TaskType TaskID, EventMaskRefType Event) {
  StatusType status = E_OK;

    // multicore migration
    // get application id




    ApplicationType AppID = GetCurrentApplicationID_Kernel();
    
    if (AppID == OS_CORE_ID_MASTER_0) {
 // todo: initiate system call to the corresponing core and send the correct parameters 
    // todo: such as:
        // syscall_GetEvent_TC0(TaskID, 0, 0, 0, 0, Event, 0, &status, 0);
    }else if (AppID == OS_CORE_ID_1) {
         // todo: initiate system call to the corresponing core and send the correct parameters 
    // todo: such as:
        // syscall_GetEvent_TC1(TaskID, 0, 0, 0, 0, Event, 0, &status, 0);
    }else if (AppID == OS_CORE_ID_2) {//todo:
    }else if (AppID == OS_CORE_ID_3) {//todo:
    }else if (AppID == OS_CORE_ID_4) {//todo:
    }else if (AppID == OS_CORE_ID_5) {//todo:
    }else if (AppID == OS_CORE_ID_6) {//todo:
    }else{}
  return status;
}

// this is the kernel implementation of GetEvent
void GetEvent_Kernel(TaskType TaskID, EventMaskRefType Event, StatusType *status) {

  ApplicationType AppID = GetCurrentApplicationID_Kernel();
  *status = E_OK;
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
  // Making sure that the task state is not suspended
  else if (OSApp[AppID].Tasks[TaskID].TaskState == SUSPENDED) {
    *status = E_OS_STATE;
    ErrorHook_Kernel(*status);
  } else {
    Event = &OSApp[AppID].Tasks[TaskID].Events;
  }

}