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
 * #################################################################################################
 13.7.2.1 ShutDownOS

   Syntax:             void ShutdownOS ( StatusType <Error> )

   Parameter (In):     Error: error occurred

   Parameter (Out):    None

   Description:        The user can call this system service to abort the overall system (e.g. emergency off).
                       The operating system also calls this function internally, if it has reached an undefined internal state and is no longer ready to run.
                       If a ShutdownHook is configured the hook routine ShutdownHook is always called (with <Error> as argument) before shutting down the operating system.
                       If ShutdownHook returns, further behaviour of ShutdownOS is implementation specific.
                       In case of a system where OSEK OS and OSEKtime OS coexist, ShutdownHook has to return.
                       <Error> needs to be a valid error code supported by OSEK OS. In case of a system where OSEK OS and OSEKtime OS coexist, <Error> might also be a value accepted by OSEKtime OS.
                       In this case, if enabled by an OSEKtime configuration parameter, OSEKtime OS will be shut down after OSEK OS shutdown.

   Particularities:    After this service the operating system is shut down.
                       Allowed at task level, ISR level, in ErrorHook and StartupHook, and also called internally by the operating system.
                       If the operating system calls ShutdownOS it never uses E_OK as the passed parameter value.

   Conformance:        BCC1, BCC2, ECC1, ECC2
 #################################################################################################
 */

// [SWS_Os_00616] dShutdownOS shall be callable from each core running an
// AUTOSAR OS.c(SRS_Os_80001, SRS_Os_80007)

// [SWS_Os_00617] dShutdownOS shall shutdown the core on which it was called.
// (SRS_Os_80007)

// [SWS_Os_00618] dThe OS shall not start Tasks of an OS-Application once the shutdown procedure 
// has been entered on a particular core. (SRS_Os_80013)

// [SWS_Os_00619] dThe AUTOSAR OS function ShutdownOS shall be callable in parallel on multiple cores (SRS_Os_80013)

void ShutdownOS(StatusType Error) {
  

    ApplicationType AppID = GetCurrentApplicationID_Kernel();
    
      if (AppID == OS_CORE_ID_MASTER_0) {
      syscall_ShutdownOS_TC0(Error, 0, 0, 0, 0, 0, 0, 0, 0);
    }else if (AppID == OS_CORE_ID_1) {
      syscall_ShutdownOS_TC1(Error, 0, 0, 0, 0, 0, 0, 0, 0);
    }else if (AppID == OS_CORE_ID_2) {//todo:
    }else if (AppID == OS_CORE_ID_3) {//todo:
    }else if (AppID == OS_CORE_ID_4) {//todo:
    }else if (AppID == OS_CORE_ID_5) {//todo:
    }else if (AppID == OS_CORE_ID_6) {//todo:
    }else{}
  return;
}

// This is the kernel version of the ShutdownOS service
void ShutdownOS_Kernel(StatusType Error) {

  // Perform any necessary cleanup
  // Deallocate the ready queue
  ApplicationType AppID = GetCurrentApplicationID_Kernel();
  if (Error != (StatusType)E_OK) // Cannot call ShutdownOS with E_OK
  {
    ShutdownHook_Kernel(Error);
    emptyReadyQueue(AppID);
    // Set operating system state to "shutting down"
    OSApp[AppID].OSRunning = false;
    // Disable all interrupts
    // DisableAllInterrupts_Kernel(); // [SWS_Os_00425] If ShutdownOS is called and ShutdownHook returns then the Operating System module shall disable all interrupts and enter an endless loop.
    // while (1) {
    //   // Do nothing
    // }

    int i;
    for (i = 0; i < MAX_TASK_ID; i++) {
        GlobalTaskAppId[i] = -1;
    }
    for (i = 0; i < MAX_COUNTERS; i++) {
        GlobalCounterAppId[i] = -1;
    }
    for (i = 0; i < MAX_ALARM_ID; i++) {
        GlobalAlarmAppId[i] = -1;
    }
    for (i = 0; i < MAX_NUM_Resource; i++) {
        GlobalResourceAppID[i] = -1;
    }
    for (i = 0; i < MAX_TIMERS; i++) {
        GlobalTimerAppId[i] = -1;
    }

    

   OSApp[AppID].CoreSynchronizationFlagOne = 0;
   OSApp[AppID].CoreSynchronizationFlagTwo = 0;

  for (int i = 0; i < 1; i++)
  {

    OSApp[i].GlobalNumberOfOverflows = 0;
    OSApp[i].SUSPEND_COUNTER = 0;
    OSApp[i].OSRunning = false;
    OSApp[i].STMQueue.size = 0;
    OSApp[i].STMOverflowQueue.size = 0;
    OSApp[i].GlobalNumberOfOverflows = 0;
    OSApp[i].SUSPEND_COUNTER = 0;
    OSApp[i].SUSPEND_OS_INTERRUPTS_COUNTER = 0; 
    OSApp[i].ICR_IE_VALUE = 0;
    OSApp[i].INTERRUPTS_ENABLED = 0;
    OSApp[i].ReadyQueue.size = 0;    
  }



  } else {

    // Cannot call ShutdownOS with E_OK
    // (void) Error; // cast to void to explicitly indicate that the value is intentionally unused
  }
}