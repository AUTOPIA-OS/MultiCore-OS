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
Syntax:             StatusType ClearEvent ( EventMaskType <Mask> )
Parameter (In)      Mask        Mask of the events to be cleared
Parameter (Out)     none
Description:        The events of the extended task calling ClearEvent are
                    cleared according to the event mask <Mask>.
Particularities:    The system service ClearEvent is restricted to extended
                    tasks which own the event.

Status:

 \a Standard: \a
* * No error, E_OK

 \a Extended: \a
 * * Call not from extended task, E_OS_ACCESS
 * * Call at interrupt level, E_OS_CALLEVEL
 *
Conformance:        ECC1, ECC2
#################################################################################################
*/

StatusType ClearEvent(EventMaskType Mask) {
  StatusType status = E_OK;


    ApplicationType AppID = GetCurrentApplicationID_Kernel();
    
    if (AppID == OS_CORE_ID_MASTER_0) {
 // todo: initiate system call to the corresponing core and send the correct parameters 
    // todo: such as:
  // syscall_ClearEvent_TC0(0, 0, 0, Mask, 0, 0, 0, &status, 0);
    }else if (AppID == OS_CORE_ID_1) {
         // todo: initiate system call to the corresponing core and send the correct parameters 
    // todo: such as:
  // syscall_ClearEvent_TC0(0, 0, 0, Mask, 0, 0, 0, &status, 0);
    }else if (AppID == OS_CORE_ID_2) {//todo:
    }else if (AppID == OS_CORE_ID_3) {//todo:
    }else if (AppID == OS_CORE_ID_4) {//todo:
    }else if (AppID == OS_CORE_ID_5) {//todo:
    }else if (AppID == OS_CORE_ID_6) {//todo:
    }else{}
  return status;
}

// this is the kernel implementation of ClearEvent
void ClearEvent_Kernel(EventMaskType Mask, StatusType *status) {

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
  } else {

    // Assuming when user wants to clear certain bit, the bit is set to 1
    // 101 means user wants to clear event 1 and 3.
    OSApp[AppID].CurrentTask->Events &= ~Mask;
  }

}