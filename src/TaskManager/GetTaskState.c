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
 * 13.2.3.6 GetTaskState
 *
 * Syntax:             StatusType GetTaskState (TaskType <TaskID>, TaskStateRefType <State> )
 *
 * Parameter (In):
 *     TaskID          Task references
 *
 * Parameter (Out):
 *     State           Reference to the state of the task <TaskID>
 *
 * Description:        Returns the state of a task (running, ready, waiting, suspended) at the
 *                     time of calling GetTaskState.
 *
 * Particularities:    The service may be called from interrupt service routines, task level,
 *                     and some hook routines (see Figure 12-1).
 *                     When a call is made from a task in a full preemptive system, the result
 *                     may already be incorrect at the time of evaluation.
 *                     When the service is called for a task, which is activated more than once,
 *                     the state is set to running if any instance of the task is running.
 *
 * Status:
 *
 * \a Standard: \a
 *
 * * No error, E_OK
 *
 * \a Extended: \a
 * * Task <TaskID> is invalid, E_OS_ID
 *
 *
 * Conformance:        BCC1, BCC2, ECC1, ECC2
 * #################################################################################################
 */

StatusType GetTaskState(TaskType TaskID, TaskStateRefType State) {
    StatusType *status = E_OK;
    uint32_t *flag = 0;
    
 ApplicationType AppID = GetCurrentApplicationID_Kernel();
     
    if (AppID == OS_CORE_ID_MASTER_0) {
         // todo: initiate system call to the corresponing core and send the correct parameters 
    // todo: such as:
    // syscall_GetTaskState_TC0(TaskID, 0, 0, 0, State, 0, 0, status, flag);
    }else if (AppID == OS_CORE_ID_1) {
         // todo: initiate system call to the corresponing core and send the correct parameters 
    // todo: such as:
    // syscall_GetTaskState_TC1(TaskID, 0, 0, 0, State, 0, 0, status, flag);
    }else if (AppID == OS_CORE_ID_2) {//todo:
    }else if (AppID == OS_CORE_ID_3) {//todo:
    }else if (AppID == OS_CORE_ID_4) {//todo:
    }else if (AppID == OS_CORE_ID_5) {//todo:
    }else if (AppID == OS_CORE_ID_6) {//todo:
    }else{}
  return *status;
}

// This is the kernel version of the GetTaskState service
void GetTaskState_Kernel(TaskType TaskID, TaskStateRefType State, StatusType *status, uint32_t *flag) {
  *status = E_OK;
  ApplicationType AppID = GlobalTaskAppId[TaskID];

  if ((OSApp[AppID].CurrentTask->TaskID >= 0) &&
      (OSApp[AppID].CurrentTask->TaskID < MAX_TASK_ID)) {
    State = &OSApp[AppID].Tasks[TaskID].TaskState;
    *status = E_OS_ID;
  }

}