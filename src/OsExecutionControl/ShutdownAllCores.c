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


// [SWS_Os_00621] dShutdownAllCores shall be callable from each core running an AUTOSAR OS.(SRS_Os_80007)


void ShutdownAllCores (StatusType Error){

    
    ApplicationType AppID = GetCurrentApplicationID_Kernel();
    
    for(int i =0; i < OsNumberOfCores; i++){

        if(OSApp[i].OSRunning == true)
        {
            if (i == AppID) {

                continue;           
            }else if(AppID == OS_CORE_ID_MASTER_0){
                 // todo: initiate system call to the corresponing core and send the correct parameters 
                // todo: such as:
                // syscall_ShutdownOS_TC0(Error, 0, 0, 0, 0, 0, 0, 0, 0);
            }
            else if (AppID == OS_CORE_ID_1) {
                 // todo: initiate system call to the corresponing core and send the correct parameters 
                // todo: such as:
            // syscall_ShutdownOS_TC1(Error, 0, 0, 0, 0, 0, 0, 0, 0);
            }else if (AppID == OS_CORE_ID_2) {
            }else if (AppID == OS_CORE_ID_3) {
            }else if (AppID == OS_CORE_ID_4) {
            }else if (AppID == OS_CORE_ID_5) {
            }else if (AppID == OS_CORE_ID_6) {
            }else{}
        }
    }
    
     if(AppID == OS_CORE_ID_MASTER_0){
         // todo: initiate system call to the corresponing core and send the correct parameters 
        // todo: such as:
        // syscall_ShutdownOS_TC0(Error, 0, 0, 0, 0, 0, 0, 0, 0);
        }
        else if (AppID == OS_CORE_ID_1) {  
             // todo: initiate system call to the corresponing core and send the correct parameters 
            // todo: such as:
        // syscall_ShutdownOS_TC1(Error, 0, 0, 0, 0, 0, 0, 0, 0);
        }else if (AppID == OS_CORE_ID_2) {
        }else if (AppID == OS_CORE_ID_3) {
        }else if (AppID == OS_CORE_ID_4) {
        }else if (AppID == OS_CORE_ID_5) {
        }else if (AppID == OS_CORE_ID_6) {
        }else{}
    while (1) {         // [SWS_Os_00715] dShutdownAllCores shall not return.
        // do nothing
    }
  return;


}
