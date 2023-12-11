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

#include "OSExecutionControl.h"

/**
  #################################################################################################
 13.7.2.1 GetActiveApplicationMode

   Syntax:             AppModeType GetActiveApplicationMode ( void )

   Description:        This service returns the current application mode. It may be used to write mode dependent code.

   Particularities:    See chapter 5 for a general description of application modes. Allowed for task, ISR and all hook routines.

   Conformance:        BCC1, BCC2, ECC1, ECC2
 #################################################################################################
 */

AppModeType GetActiveApplicationMode(void) {

    ApplicationType AppID = GetCurrentApplicationID_Kernel();
    AppModeType appmode=0;
    if (AppID == OS_CORE_ID_MASTER_0) {
       // todo: initiate system call to the corresponing core and send the correct parameters 
    // todo: such as:
      //  syscall_GetActiveApplicationMode_TC0(0, 0, 0, 0, &appmode, 0, 0, 0, 0);
    }else if (AppID == OS_CORE_ID_1) {
       // todo: initiate system call to the corresponing core and send the correct parameters 
    // todo: such as:
        // syscall_GetActiveApplicationMode_TC1(0, 0, 0, 0, &appmode, 0, 0, 0, 0);
    }else if (AppID == OS_CORE_ID_2) {//todo:
    }else if (AppID == OS_CORE_ID_3) {//todo:
    }else if (AppID == OS_CORE_ID_4) {//todo:
    }else if (AppID == OS_CORE_ID_5) {//todo:
    }else if (AppID == OS_CORE_ID_6) {//todo:
    }else{}

  return appmode;
}

// This is the kernel version of the GetActiveApplicationMode service
void GetActiveApplicationMode_Kernel(AppModeType *appmode) {

  ApplicationType AppID = GetCurrentApplicationID_Kernel();
  *appmode = OSApp[AppID].CurrentAppMode; // get the current application mode of the current task

  //* we should get active even from ISR or Hook Routines?
}