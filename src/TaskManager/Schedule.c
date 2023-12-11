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

#include "TaskManager.h"
#include "test_hardware.h"

/**
 * #################################################################################################
 * 13.2.3.4 Schedule
 *
 * Syntax:             StatusType Schedule ( void )
 * Parameter (In):     none
 * Parameter (Out):    none
 *
 * Description:        If a higher-priority task is ready, the internal resource of the task
 *                     is released, the current task is put into the ready state, its context
 *                     is saved and the higher-priority task is executed. Otherwise the calling
 *                     task is continued.
 *
 * Particularities:    Rescheduling only takes place if the task an internal resource is assigned
 *                     to the calling task16 during system generation. For these tasks, Schedule
 *                     enables a processor assignment to other tasks with lower or equal priority
 *                     than the ceiling priority of the internal resource and higher priority than
 *                     the priority of the calling task in application-specific locations. When
 *                     returning from Schedule, the internal resource has been taken again.
 *
 *                     This service has no influence on tasks with no internal resource assigned
 *                     (preemptable tasks).
 *
 * Status:
 *
 * \a Standard: \a
 * * No error, E_OK
 *
 * \a Extended: \a
 * * Call at interrupt level, E_OS_CALLEVEL
 * * Calling task occupies resources, E_OS_RESOURCE
 * Conformance:        BCC1, BCC2, ECC1, ECC2
 * #################################################################################################
 */

// [SWS_Os_00568] Implementations shall be able to independently execute a Task or
// an ISR on each started AUTOSAR OS core in parallel.c(SRS_Os_80001)

// [SWS_Os_00569] The scheduling strategy as defined in AUTOSAR OS shall apply
// for each individual core in a Multi-Core system, for the Tasks and ISR assigned to the
// core.c(SRS_Os_80001, SRS_Os_80013)

// [SWS_Os_00570] All Tasks that are assigned to the same OS-Application 
// shall execute on the same core.c(SRS_Os_80003, SRS_Os_80005)

// [SWS_Os_00571] All ISRs that are assigned to the same OS-Application shall 
// execute on the same core.c(SRS_Os_80003, SRS_Os_80005)

// todo: [SWS_Os_00572] ISR balancing (if supported by the HW) shall be switched off at
// boot time by the OS.c(SRS_Os_80005, SRS_Os_80006)

// [SWS_Os_00764] The OS module shall support OS-Applications in case of 
// MultiCore also for SC1 and SC2.c()

// todo: [SWS_Os_00763] In an SC1 system standard mode shall be possible.c()

// todo: [SWS_Os_00573] The binding of OS-Applications to cores shall be configured within
// the OS-Application container.c(SRS_Os_80003, SRS_Os_80005)






StatusType Schedule(void) {
  StatusType *status = E_OK;

    ApplicationType AppID = GetCurrentApplicationID_Kernel();
    
    if (AppID == OS_CORE_ID_MASTER_0) {
         // todo: initiate system call to the corresponing core and send the correct parameters 
    // todo: such as:
    // syscall_Schedule_TC0(0, 0, 0, 0, 0, 0, 0, status, 0);
    }else if (AppID == OS_CORE_ID_1) {
       // todo: initiate system call to the corresponing core and send the correct parameters 
    // todo: such as:
        // syscall_Schedule_TC1(0, 0, 0, 0, 0, 0, 0, status, 0);
    }else if (AppID == OS_CORE_ID_2) {//todo:
    }else if (AppID == OS_CORE_ID_3) {//todo:
    }else if (AppID == OS_CORE_ID_4) {//todo:
    }else if (AppID == OS_CORE_ID_5) {//todo:
    }else if (AppID == OS_CORE_ID_6) {//todo:
    }else{}
  return *status;
}

// This is the kernel version of the Schedule service
void Schedule_Kernel(StatusType *status) {

  *status = E_OK;
  ApplicationType AppID = GetCurrentApplicationID_Kernel();

  // TODO: AT Extended if called from interrupt level, E_OS_CALLEVEL
  // TODO: Calling task occupies resources, E_OS_RESOURCE
  // Getting a pointer to the highest priority task in the ready queue
  Task *next = &OSApp[AppID].Tasks[PqGetRoot(&OSApp[AppID].ReadyQueue)];

  if (OSApp[AppID].CurrentTask->Stack[0] != (0xDEADBEEFU)) {
      // todo ADD THE needed error from autosar
      ShutdownOS_Kernel(E_OS_LIMIT);
      ErrorHook_Kernel(0);
    }

   // If the next has a lower priority than the CurrentTask, then continue current task
  if ((next->PRIORITY <= OSApp[AppID].CurrentTask->PRIORITY) && (next->TaskID != OSApp[AppID].CurrentTask->TaskID) &&
      (OSApp[AppID].CurrentTask->ACTIVATION > 0) && (OSApp[AppID].CurrentTask->TaskState != WAITING)) {

    PreTaskHook_Kernel();

    // continue where the PC stopped

    *status = E_OK;

  } else {

    // Release the Internal resources held by the current task
    ReleaseAllInternalResources(AppID);

    // Making sure that the idle task never leaves the ReadyQueue
    if (next->PRIORITY != 0) {
      PqPop(&OSApp[AppID].ReadyQueue);
    } else {
    }

    // Update the states of the previously CurrentTask and the upcoming CurrentTask
    if (OSApp[AppID].CurrentTask->TaskState == RUNNING) {
      OSApp[AppID].CurrentTask->TaskState = READY;
      if (OSApp[AppID].CurrentTask->PRIORITY != 0) {
        // Add the previously CurrentTask to the ready priority queue unless its idle
        PqPush(&OSApp[AppID].ReadyQueue, OSApp[AppID].CurrentTask->TaskID,
               OSApp[AppID].CurrentTask->PRIORITY);
      } else {
      }
    } else {
    }

    // TODO: Save context of the (previously) current task
    // Saving the context of the current task
      // Save_Context_Block(PCXI, AppID);
    


    next->TaskState = RUNNING;
    // Assign the new CurrentTask
    OSApp[AppID].CurrentTask = next;

  // TODO: load context of the (next) current task
    // loading the context of the (new) current task
    //  Load_Context_Block(PCXI, AppID, next->PC != next->TaskEntryPoint);

    PreTaskHook_Kernel();
  }

}