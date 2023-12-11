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
 * 13.2.3.2 TerminateTask
 * Syntax: StatusType TerminateTask ( void )
 * Parameter (In):     none
 * Parameter (Out):    none
 * Description:        This service causes the termination of the calling task. The
 *                     calling task is transferred from the running state into the
 *                     suspended state15.
 *
 * Particularities:    An internal resource assigned to the calling task is automatically
 *                     released. Other resources occupied by the task shall have been
 *                     released before the call to TerminateTask. If a resource is still
 *                     occupied in standard status the behaviour is undefined.
 *
 *                     If the call was successful, TerminateTask does not return to the
 *                     call level and the status can not be evaluated.
 *
 *                     If the version with extended status is used, the service returns
 *                     in case of error, and provides a status which can be evaluated
 *                     in the application.
 *
 *                     If the service TerminateTask is called successfully, it enforces a
 *                     rescheduling.
 *
 *                     Ending a task function without call to TerminateTask or
 *                     ChainTask is strictly forbidden and may leave the system in an
 *                     undefined state.
 *
 * Status:
 *
 * \a Standard: \a
 * *     No return to call level
 *
 *\a Extended: \a
 *  *   Task still occupies resources, E_OS_RESOURCE
 *  *   Call at interrupt level, E_OS_CALLEVEL
 *
 * Conformance:        BCC1, BCC2, ECC1, ECC2
 * #################################################################################################
 */

StatusType TerminateTask(void) {
  StatusType status = E_OK;

    ApplicationType AppID = GetCurrentApplicationID_Kernel();
    
    if (AppID == OS_CORE_ID_MASTER_0) {
         // todo: initiate system call to the corresponing core and send the correct parameters 
    // todo: such as:
    // syscall_TerminateTask_TC0(0, 0, 0, 0, 0, 0, 0, &status, 0);
    }else if (AppID == OS_CORE_ID_1) {
         // todo: initiate system call to the corresponing core and send the correct parameters 
    // todo: such as:
    // syscall_TerminateTask_TC1(0, 0, 0, 0, 0, 0, 0, &status, 0);
    }else if (AppID == OS_CORE_ID_2) {//todo:
    }else if (AppID == OS_CORE_ID_3) {//todo:
    }else if (AppID == OS_CORE_ID_4) {//todo:
    }else if (AppID == OS_CORE_ID_5) {//todo:
    }else if (AppID == OS_CORE_ID_6) {//todo:
    }else{}
  return status;
}

// This is the kernel version of the TerminateTask service
void TerminateTask_Kernel(StatusType *status) {
   *status = E_OK;
  ApplicationType AppID = GetCurrentApplicationID_Kernel();
  // if Calling task still holds resources return error
  if (!StackIsEmpty(&OSApp[AppID].CurrentTask->TaskResources)) {
    *status = E_OS_RESOURCE;
  }
  {
    // releasing the internal resources held
    ReleaseAllInternalResources(AppID);

    // Checking if there are multiple activations of the Current task
    // If so, decrement the number of ative instances and enqueue it again to the ready queue
    if (OSApp[AppID].CurrentTask->ACTIVATION > 1) {
      OSApp[AppID].CurrentTask->TaskState = READY;
      // todo:
      
      // for (int i = 2; i < 16; i++) {
      //   OSApp[AppID].CurrentTask->UpperContext[i] = 0;
      // }

      
      // Save_PC_and_SP_to_Task_CSA(
      //     OSApp[AppID].CurrentTask,
      //     (uint32_t)OSApp[AppID].CurrentTask->TaskEntryPoint,
      //     (uint32_t)OSApp[AppID].CurrentTask->StackPointerBaseAddress);

      OSApp[AppID].CurrentTask->PC =
          (uint32_t)OSApp[AppID].CurrentTask->TaskEntryPoint;
      PqPush(&OSApp[AppID].ReadyQueue, OSApp[AppID].CurrentTask->TaskID,
             OSApp[AppID].CurrentTask->PRIORITY);
    } else {
      OSApp[AppID].CurrentTask->TaskState = SUSPENDED;
    }

    OSApp[AppID].CurrentTask->ACTIVATION = OSApp[AppID].CurrentTask->ACTIVATION - 1;

    Schedule_Kernel(status);
  }
}