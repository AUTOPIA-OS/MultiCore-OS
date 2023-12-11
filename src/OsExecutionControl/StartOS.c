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
 13.7.2.1 StartOS

   Syntax:             void StartOS ( AppModeType <Mode> )

   Parameter (In):     Mode: Application Mode

   Parameter (Out):    None

   Description:        The user can call this system service to start the operating system in a specific mode, see chapter 5, Application modes.

   Particularities:    Only allowed outside of the operating system, therefore implementation specific restrictions may apply.
                       See also chapter 11.3, System start-up, especially with respect to systems where OSEK and OSEKtime coexist. This call does not need to return

   Conformance:        BCC1, BCC2, ECC1, ECC2
 #################################################################################################
 */

void StartOS(AppModeType Mode) {
  

    ApplicationType AppID = GetCurrentApplicationID_Kernel();
    
    if (AppID == OS_CORE_ID_MASTER_0) {
      syscall_StartOS_TC0(Mode, 0, 0, 0, 0, 0, 0, 0, 0);
    }else if (AppID == OS_CORE_ID_1) {
      syscall_StartOS_TC1(Mode, 0, 0, 0, 0, 0, 0, 0, 0);
    }else if (AppID == OS_CORE_ID_2) {//todo:
    }else if (AppID == OS_CORE_ID_3) {//todo:
    }else if (AppID == OS_CORE_ID_4) {//todo:
    }else if (AppID == OS_CORE_ID_5) {//todo:
    }else if (AppID == OS_CORE_ID_6) {//todo:
    }else{}

    while (1) { // [SWS_Os_00424] The first call to StartOS (for starting the Operating System) shall not return
    }
  return;
}

// This is the kernel version of the StartOS service
void StartOS_Kernel(AppModeType Mode, uint32_t PCXI_IDLE) {

  ApplicationType AppID = GetCurrentApplicationID_Kernel();

    StatusType err = 0;

  
  OSApp[AppID].CoreSynchronizationFlagOne = 1;
  // todo: sync data between cores
  // [SWS_Os_00579] ⌈All cores that belong to the AUTOSAR system shall be synchro- nized within the StartOS function before the scheduling is started and after the global StartupHook is called.⌋
  while ((OSApp[0].CoreSynchronizationFlagOne + OSApp[1].CoreSynchronizationFlagOne ) != CORE_SYNCHRONIZATION_FLAG_ONE_RUN) {
        
  }

  // [SWS_Os_00581] ⌈The global StartupHook shall be called on all cores immediately after the first synchronization point.⌋
  // Todo: [SWS_Os_00582] ⌈The OS-Application-specific StartupHooks shall be called after the global StartupHook but only on the cores to which the OS-Application is bound.⌋
  StartupHook_Kernel();

  // Check if StartOS is allowed at this point in time
  if (OSApp[AppID].OSRunning == true) {
    ShutdownOS_Kernel(E_OS_RESTRICT);

  } else {
    
    // Initialize system resources
    //InitializeSTM(AppID);

    // Initialize task manager
    err = TaskManagerInit(PCXI_IDLE, AppID);

    InitStacks(AppID);



    // Initialize System Timer
    Init_Stack_pointer(AppID);

    // Enter specified application mode
    OSApp[AppID].CurrentAppMode = Mode;
    OSApp[AppID].OSRunning = true;




  
    OSApp[AppID].CoreSynchronizationFlagTwo = 1;
    // todo: sync data between cores
 
    // [SWS_Os_00580] ⌈All cores that belong to the AUTOSAR system shall be synchro- nized within the StartOS before the global StartupHook is called.⌋
    while ( (OSApp[0].CoreSynchronizationFlagTwo + OSApp[1].CoreSynchronizationFlagTwo ) != CORE_SYNCHRONIZATION_FLAG_TWO_RUN) {
         
    }
    // Call Schedule function to start task execution
    Schedule_Kernel(&err);
  }

  // error hook
  if (err != E_OK) {
    ErrorHook_Kernel(err);
  }
}