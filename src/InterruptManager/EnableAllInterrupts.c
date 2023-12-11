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

#include "InterruptManager.h"

/**
 * 13.3.2.1 EnableAllInterrupts
 *
 * Syntax:             void EnableAllInterrupts ( void )
 * Parameter (In):     none
 * Parameter (Out):    none
 *
 * Description:        This service restores the state saved by DisableAllInterrupts.
 *
 * Particularities:    The service may be called from an ISR category 1 and category2 and from the
 *                     task level, but not from hook routines.
 *                     This service is a counterpart of DisableAllInterrupts service, which has to be
 *                     called before, and its aim is the completion of the critical section of code.
 *                     No API service calls are allowed within this critical section.
 *
 *                     The implementation should adapt this service to the target hardware providing a
 *                     minimum overhead. Usually, this service enables recognition of interrupts by the
 *                     central processing unit.
 *
 * Status:
 *
 *    \a Standard: \a
 * * none
 *
 * \a Extended: \a
 *
 * * none
 *
 * Conformance:        BCC1, BCC2, ECC1, ECC2
 *
 */


// [SWS_Os_00591] dThe OS service EnableAllInterrupts shall only affect the
// core on which it is called.c(SRS_Os_80013)

// todo: Hardware migration

void EnableAllInterrupts(void) {

    ApplicationType AppID = GetCurrentApplicationID_Kernel();
    
    if (AppID == OS_CORE_ID_MASTER_0) {
      // todo: initiate system call to the corresponing core and send the correct parameters 
    // todo: such as:
      //syscall_EnableAllInterrupts_TC0(0, 0, 0, 0, 0, 0, 0, 0, 0);
    }else if (AppID == OS_CORE_ID_1) {  
      // todo: initiate system call to the corresponing core and send the correct parameters 
    // todo: such as:
      //syscall_EnableAllInterrupts_TC1(0, 0, 0, 0, 0, 0, 0, 0, 0);
    }else if (AppID == OS_CORE_ID_2) {//todo:
    }else if (AppID == OS_CORE_ID_3) {//todo:
    }else if (AppID == OS_CORE_ID_4) {//todo:
    }else if (AppID == OS_CORE_ID_5) {//todo:
    }else if (AppID == OS_CORE_ID_6) {//todo:
    }else{} 
    
}



void EnableAllInterrupts_Kernel(void) {

  ApplicationType AppID = GetCurrentApplicationID_Kernel();
  if ((OSApp[AppID].ICR_IE_VALUE == 0) &&
      (OSApp[AppID].SUSPEND_COUNTER ==
       0)) // if interrupts were disabled and not suspended, enable them
  {
    // TODO: Target HW specific implementation 
    // TODO: Disable all interrupts for the current core
    OSApp[AppID].ICR_IE_VALUE = 1;
    OSApp[AppID].INTERRUPTS_ENABLED = 1;
  }
}