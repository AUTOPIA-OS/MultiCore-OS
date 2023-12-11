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
 * 13.3.2.3 ResumeAllInterrupts
 *
 * Syntax:             void ResumeAllInterrupts ( void )
 * Parameter (In):     none
 * Parameter (Out):    none
 * Description:        This service restores the recognition status of all interrupts
 *                     saved by the SuspendAllInterrupts service.
 *
 * Particularities:    The service may be called from an ISR category 1 and category
 *                     2, from alarm-callbacks and from the task level, but not from all
 *                     hook routines.
 *
 *                     This service is the counterpart of SuspendAllInterrupts service,
 *                     which has to have been called before, and its aim is the
 *                     completion of the critical section of code. No API service calls
 *                     beside SuspendAllInterrupts/ResumeAllInterrupts pairs and
 *                     SuspendOSInterrupts/ResumeOSInterrupts pairs are allowed
 *                     within this critical section.
 *
 *                     The implementation should adapt this service to the target
 *                     hardware providing a minimum overhead.
 *
 *                     SuspendAllInterrupts/ResumeAllInterrupts can be nested. In
 *                     case of nesting pairs of the calls SuspendAllInterrupts and
 *                     ResumeAllInterrupts the interrupt recognition status saved by
 *                     the first call of SuspendAllInterrupts is restored by the last call
 *                     of the ResumeAllInterrupts service.
 *
 * Status:
 *
 *\a Standard: \a
 * * none
 *
 *\a Extended: \a
 * * none
 *
 * Conformance:        BCC1, BCC2, ECC1, ECC2
 *
 */


// [SWS_Os_00593] dThe OS service ResumeAllInterrupts shall only affect the
// core on which it is called.c(SRS_Os_80013)

// todo: HardWre migration

void ResumeAllInterrupts(void) {

    ApplicationType AppID = GetCurrentApplicationID_Kernel();
    
    if (AppID == OS_CORE_ID_MASTER_0) {
      // todo: initiate system call to the corresponing core and send the correct parameters 
    // todo: such as:
      //syscall_ResumeAllInterrupts_TC0(0, 0, 0, 0, 0, 0, 0, 0, 0);
    }else if (AppID == OS_CORE_ID_1) {  
      // todo: initiate system call to the corresponing core and send the correct parameters 
    // todo: such as:
      // syscall_ResumeAllInterrupts_TC1(0, 0, 0, 0, 0, 0, 0, 0, 0);
    }else if (AppID == OS_CORE_ID_2) {//todo:
    }else if (AppID == OS_CORE_ID_3) {//todo:
    }else if (AppID == OS_CORE_ID_4) {//todo:
    }else if (AppID == OS_CORE_ID_5) {//todo:
    }else if (AppID == OS_CORE_ID_6) {//todo:
    }else{} 
}

void ResumeAllInterrupts_Kernel() {

  ApplicationType AppID = GetCurrentApplicationID_Kernel();
  OSApp[AppID].SUSPEND_COUNTER =
      OSApp[AppID].SUSPEND_COUNTER - 1; // decrement suspend counter
  if ((OSApp[AppID].SUSPEND_COUNTER == 0) &&
      (OSApp[AppID].INTERRUPTS_ENABLED ==
       1)) // if all suspend calls have been resumed and interrupts were enabled before suspending
  {

   // TODO: Target HW specific implementation 
    // TODO: Disable all interrupts for the current core

    OSApp[AppID].ICR_IE_VALUE = 1;
  }
}