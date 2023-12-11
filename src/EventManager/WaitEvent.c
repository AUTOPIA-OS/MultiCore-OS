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
Syntax:             StatusType WaitEvent ( EventMaskType <Mask> )
Parameter (In):     Mask        Mask of the events waited for.
Parameter (Out):    none
Description:        The state of the calling task is set to waiting, unless at
least one of the events specified in <Mask> has already been set.
Particularities: This call enforces rescheduling, if the wait condition occurs.
If rescheduling takes place, the internal resource of the task is released while
the task is in the waiting state. This service shall only be called from the
extended task owning the event.

Status:

\a Standard: \a
* No error, E_OK

\a Extended: \a

* Calling task is not an extended task, E_OS_ACCESS
* Calling task occupies resources, E_OS_RESOURCE
* Call at interrupt level, E_OS_CALLEVEL

Conformance:        ECC1, ECC2
#################################################################################################
*/

StatusType WaitEvent(EventMaskType Mask) {
    StatusType status = E_OK;

    ApplicationType AppID = GetCurrentApplicationID_Kernel();
    
    if (AppID == OS_CORE_ID_MASTER_0) {
// todo: initiate system call to the corresponing core and send the correct parameters 
    // todo: such as:
        //syscall_WaitEvent_TC0(0, 0, 0, Mask, 0, 0, 0, &status, 0);
    }else if (AppID == OS_CORE_ID_1) {
        // todo: initiate system call to the corresponing core and send the correct parameters 
    // todo: such as:
        //syscall_WaitEvent_TC1(0, 0, 0, Mask, 0, 0, 0, &status, 0);
    }else if (AppID == OS_CORE_ID_2) {//todo:
    }else if (AppID == OS_CORE_ID_3) {//todo:
    }else if (AppID == OS_CORE_ID_4) {//todo:
    }else if (AppID == OS_CORE_ID_5) {//todo:
    }else if (AppID == OS_CORE_ID_6) {//todo:
    }else{}
  return status;
}

// this is the kernel implementation of WaitEvent
void WaitEvent_Kernel(EventMaskType Mask, StatusType *status) {

  ApplicationType AppID = GetCurrentApplicationID_Kernel();
   *status = E_OK;
  // Making sure its not an ISR
  if (OSApp[AppID].CurrentTask->VERSION == ISR_CAT2) {
    *status = E_OS_CALLLEVEL;
    ErrorHook_Kernel(*status);
  }

  // Making sure its an extended task
  else if (OSApp[AppID].CurrentTask->VERSION != EXTENDED) {
    *status = E_OS_ACCESS;
    ErrorHook_Kernel(*status);
  }

  // Making sure it doesn't occupy resources
  else if (!StackIsEmpty(&OSApp[AppID].CurrentTask->TaskResources)) {
    *status = E_OS_RESOURCE;
    ErrorHook_Kernel(*status);
  }

  // Checking if the events specified in <Mask> has already been set
  else if ((OSApp[AppID].CurrentTask->Events & Mask) != (0U)) {
    *status = E_OK;
  } else {

    OSApp[AppID].CurrentTask->WaitEvents |= Mask;
    // Setting CurrentTask to WAITING state, giving the control to idle task before scheduling, then schedule
    OSApp[AppID].CurrentTask->TaskState = WAITING;
    Schedule_Kernel(status);
  }
}