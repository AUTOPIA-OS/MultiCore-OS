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
 * 13.2.3.3 ChainTask
 * Syntax:             StatusType ChainTask ( TaskType <TaskID> )
 * Parameter (In):
 * TaskID              Reference to the sequential succeeding task to be activated.
 * Parameter (Out):    none
 * Description:        This service causes the termination of the calling task. After
 *                     termination of the calling task a succeeding task <TaskID> is
 *                     activated. Using this service, it ensures that the succeeding task
 *                     starts to run at the earliest after the calling task has been
 *                     terminated.
 *
 *                     Particularities: If the succeeding task is identical with the current task,
 *                     this does not result in multiple requests. The task is not transferred
 *                     to the suspended state, but will immediately become ready
 *                     again.
 *
 *                     An internal resource assigned to the calling task is automatically
 *                     released, even if the succeeding task is identical with the
 *                     current task. Other resources occupied by the calling shall have
 *                     been released before ChainTask is called. If a resource is still
 *                     occupied in standard status the behaviour is undefined.
 *
 *                     If called successfully, ChainTask does not return to the call level
 *                     and the status can not be evaluated.
 *
 *                     In case of error the service returns to the calling task and
 *                     provides a status which can then be evaluated in the
 *                     application.
 *
 *                     If the service ChainTask is called successfully, this enforces a
 *                     rescheduling.
 *
 *                     Ending a task function without call to TerminateTask or
 *                     ChainTask is strictly forbidden and may leave the system in an
 *                     undefined state.
 *
 *                     If E_OS_LIMIT is returned the activation is ignored.
 *                     When an extended task is transferred from suspended state
 *                     into ready state all its events are cleared.
 *
 * Status:
 *
 *\a Standard: \a
 * * No return to call level
 * * Too many task activations of <TaskID>, E_OS_LIMIT
 *
 *\a  Extended: \a
 * * Task <TaskID> is invalid, E_OS_ID
 * * Calling task still occupies resources, E_OS_RESOURCE
 * * Call at interrupt level, E_OS_
 * #################################################################################################
 */
 
// TODO: Test this service
StatusType ChainTask(TaskType TaskID) {
  StatusType *status = E_OK;
  uint32_t *flag = 0;
    
 ApplicationType AppID = GetCurrentApplicationID_Kernel();
     
    if (AppID == OS_CORE_ID_MASTER_0) {
        syscall_ChainTask_TC0(TaskID, 0, 0, 0, 0, 0, 0, status, flag);
    }else if (AppID == OS_CORE_ID_1) {
        syscall_ChainTask_TC1(TaskID, 0, 0, 0, 0, 0, 0, status, flag);
    }else if (AppID == OS_CORE_ID_2) {//todo:
    }else if (AppID == OS_CORE_ID_3) {//todo:
    }else if (AppID == OS_CORE_ID_4) {//todo:
    }else if (AppID == OS_CORE_ID_5) {//todo:
    }else if (AppID == OS_CORE_ID_6) {//todo:
    }else{}
  return *status;
}

// This is the kernel version of the ChainTask service
void ChainTask_Kernel(TaskType TaskID, StatusType *status, uint32_t *flag) {
  
  // todo: 
}