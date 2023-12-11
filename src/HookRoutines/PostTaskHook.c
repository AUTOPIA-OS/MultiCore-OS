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

#include "HookRoutines.h"

/* 13.8.2.3 PostTaskHook

   Syntax:             void PostTaskHook ( void )

   Parameter (In):     none

   Parameter (Out):    None

   Description:        This hook routine is called by the operating system after executing the current task, but before leaving the task's running state (to allow evaluation of the TaskID by GetTaskID).

   Particularities:    See chapter 11.1 for general description of hook routines.

   Conformance:        BCC1, BCC2, ECC1, ECC2

*/

void PostTaskHook(void) { 

    ApplicationType AppID = GetCurrentApplicationID_Kernel();
    
    if (AppID == OS_CORE_ID_MASTER_0) {
      // todo: initiate system call to the corresponing core and send the correct parameters 
    // todo: such as:
     // syscall_PostTaskHook_TC0(0, 0, 0, 0, 0, 0, 0, 0, 0);
    }else if (AppID == OS_CORE_ID_1) {
      // todo: initiate system call to the corresponing core and send the correct parameters 
    // todo: such as:  
      //syscall_PostTaskHook_TC1(0, 0, 0, 0, 0, 0, 0, 0, 0);
    }else if (AppID == OS_CORE_ID_2) {//todo:
    }else if (AppID == OS_CORE_ID_3) {//todo:
    }else if (AppID == OS_CORE_ID_4) {//todo:
    }else if (AppID == OS_CORE_ID_5) {//todo:
    }else if (AppID == OS_CORE_ID_6) {//todo:
    }else{} 
    }

// This is the Kernel's implementation of the PostTaskHook
void PostTaskHook_Kernel(void) {}
