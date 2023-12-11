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
*
*13.3.2.6 SuspendOSInterrupts
*
*Syntax: void SuspendOSInterrupts ( void )

*Parameter (In): none

*Parameter (Out): none

*Description: This service saves the recognition status of interrupts of
*category 2 and disables the recognition of these interrupts.

*Particularities: The service may be called from an ISR and from the task level,
*but not from hook routines.

*This service is intended to protect a critical section of code. This
*section shall be finished by calling the ResumeOSInterrupts
*service. No API service calls beside
*SuspendAllInterrupts/ResumeAllInterrupts pairs and
*SuspendOSInterrupts/ResumeOSInterrupts pairs are allowed
*within this critical section.

*The implementation should adapt this service to the target
*hardware providing a minimum overhead.
*It is intended only to disable interrupts of category 2. However,
*if this is not possible in an efficient way more interrupts may be
*disabled.

Status:

\a Standard: \a
* * none

\a Extended: \a
* * none

*Conformance: BCC1, BCC2, ECC1, ECC2
 */


// [SWS_Os_00594] dThe OS service SuspendOSInterrupts shall only affect the
// core on which it is called.c(SRS_Os_80013)

// todo: Hardware migration

void SuspendOSInterrupts(void) {

    ApplicationType AppID = GetCurrentApplicationID_Kernel();
    
    if (AppID == OS_CORE_ID_MASTER_0) {
       // todo: initiate system call to the corresponing core and send the correct parameters 
    // todo: such as:
        //syscall_SuspendOSInterrupts_TC0(0, 0, 0, 0, 0, 0, 0, 0, 0);
    }else if (AppID == OS_CORE_ID_1) {  
       // todo: initiate system call to the corresponing core and send the correct parameters 
    // todo: such as:
      //syscall_SuspendOSInterrupts_TC1(0, 0, 0, 0, 0, 0, 0, 0, 0);
      
    }else if (AppID == OS_CORE_ID_2) {//todo:
    }else if (AppID == OS_CORE_ID_3) {//todo:
    }else if (AppID == OS_CORE_ID_4) {//todo:
    }else if (AppID == OS_CORE_ID_5) {//todo:
    }else if (AppID == OS_CORE_ID_6) {//todo:
    }else{} 


    
}

void SuspendOSInterrupts_Kernel(uint32_t PCXI) {
  ApplicationType AppID = GetCurrentApplicationID_Kernel();
  OSApp[AppID].SUSPEND_OS_INTERRUPTS_COUNTER =
      OSApp[AppID].SUSPEND_OS_INTERRUPTS_COUNTER + 1;
  if (OSApp[AppID].SUSPEND_OS_INTERRUPTS_COUNTER == 1) {
   // TODO: Target HW specific implementation 
    // TODO: Disable all interrupts for the current core
  }
}