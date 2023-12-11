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

/* 13.8.2.2 PreTaskHook

   Syntax:             void ShutdownHook ( StatusType <Error> )

   Parameter (In):     Error         error occurred

   Parameter (Out):    None

   Description:        This hook routine is called by the operating system when the OS service ShutdownOS has been called. This routine is called during the operating system shut down.

   Particularities:    ShutdownHook is a hook routine for user defined shutdown functionality, see chapter 11.4.

   Conformance:        BCC1, BCC2, ECC1, ECC2

*/

void ShutdownHook(StatusType Error) {
 
    ApplicationType AppID = GetCurrentApplicationID_Kernel();
    
    if (AppID == OS_CORE_ID_MASTER_0) {
      // todo: initiate system call to the corresponing core and send the correct parameters 
    // todo: such as:
    //  syscall_ShutdownHook_TC0(Error, 0, 0, 0, 0, 0, 0, 0, 0);
    }else if (AppID == OS_CORE_ID_1) {  
      // todo: initiate system call to the corresponing core and send the correct parameters 
    // todo: such as:
     // syscall_ShutdownHook_TC1(Error, 0, 0, 0, 0, 0, 0, 0, 0);
    }else if (AppID == OS_CORE_ID_2) {//todo:
    }else if (AppID == OS_CORE_ID_3) {//todo:
    }else if (AppID == OS_CORE_ID_4) {//todo:
    }else if (AppID == OS_CORE_ID_5) {//todo:
    }else if (AppID == OS_CORE_ID_6) {//todo:
    }else{} 


}

// This is the Kernel's implementation of the ShutdownHook
void ShutdownHook_Kernel(StatusType Error) {
  switch (Error) {
  case E_OS_ACCESS:
    break;
  case E_OS_CALLLEVEL:
    break;
  case E_OS_ID:
    break;
  case E_OS_LIMIT:
    break;
  case E_OS_NUFUNC:
    break;
  case E_OS_RESOURCE:
    break;
  case E_OS_STATE:
    break;
  case E_OS_VALUE:
    break;
  case E_OS_NOFUNC:
    break;
  case E_OS_LIFO:
    break;
  case E_OS_RESTRICT:
    break;
  case E_OS_PARAM_POINTER:
    break;
  default:
    break;
  }

}