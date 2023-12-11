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
 * 13.3.2.4 SuspendAllInterrupts
 *
 * Syntax:             void SuspendAllInterrupts ( void )
 * Parameter (In):     none
 * Parameter (Out):    none
 * Description:        This service saves the recognition status of all interrupts and
 *                     disables all interrupts for which the hardware supports
 *                     disabling.
 *
 * Particularities:    The service may be called from an ISR category 1 and category
 *                     2, from alarm-callbacks and from the task level, but not from all
 *                     hook routines.
 *
 *                     This service is intended to protect a critical section of code from
 *                     interruptions of any kind. This section shall be finished by
 *                     calling the ResumeAllInterrupts service. No API service calls
 *                     beside SuspendAllInterrupts/ResumeAllInterrupts pairs and
 *                     SuspendOSInterrupts/ResumeOSInterrupts pairs are allowed
 *                     within this critical section.
 *
 *                     The implementation should adapt this service to the target
 *                     hardware providing a minimum overhead.
 * Status:
 *
 * \a Standard: \a
 * * none
 *
 * \a Extended: \a
 * * none
 *
 * Conformance:        BCC1, BCC2, ECC1, ECC2
 *
 */

// [SWS_Os_00592] dThe OS service SuspendAllInterrupts shall only affect the
// core on which it is called.c(SRS_Os_80013)

// todo: Hardware migration

void SuspendAllInterrupts(void) {

    ApplicationType AppID = GetCurrentApplicationID_Kernel();
    
    if (AppID == OS_CORE_ID_MASTER_0) {
       // todo: initiate system call to the corresponing core and send the correct parameters 
    // todo: such as:
     // syscall_SuspendAllInterrupts_TC0(0, 0, 0, 0, 0, 0, 0, 0, 0);
    }else if (AppID == OS_CORE_ID_1) {  
       // todo: initiate system call to the corresponing core and send the correct parameters 
    // todo: such as:
     // syscall_SuspendAllInterrupts_TC1(0, 0, 0, 0, 0, 0, 0, 0, 0);
    }else if (AppID == OS_CORE_ID_2) {//todo:
    }else if (AppID == OS_CORE_ID_3) {//todo:
    }else if (AppID == OS_CORE_ID_4) {//todo:
    }else if (AppID == OS_CORE_ID_5) {//todo:
    }else if (AppID == OS_CORE_ID_6) {//todo:
    }else{} 

}

void SuspendAllInterrupts_Kernel(uint32_t PCXI) {
  ApplicationType AppID = GetCurrentApplicationID_Kernel();
  OSApp[AppID].SUSPEND_COUNTER =
      OSApp[AppID].SUSPEND_COUNTER + 1; // increment suspend counter
  if ((OSApp[AppID].SUSPEND_COUNTER == 1) ||
      (OSApp[AppID].ICR_IE_VALUE ==
       1)) { // if interrupts were not suspended before and not disabled before, suspend them
  
  // TODO: Target HW specific implementation 
    // TODO: Disable all interrupts for the current core
    OSApp[AppID].ICR_IE_VALUE = 0;
  }
}