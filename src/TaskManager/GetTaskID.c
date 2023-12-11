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
 * 13.2.3.5 GetTaskID
 *
 * Syntax:             StatusType GetTaskID ( TaskRefType <TaskID> )
 * Parameter (In):     none
 * Parameter (Out):
 *     TaskID          Reference to the task which is currently running
 *
 * Description:        GetTaskID returns the information about the TaskID of the task which is
 *                     currently running.
 *
 * Particularities:    Allowed on task level, ISR level and in several hook routines.
 *
 *This service is intended to be used by library functions and hook routines.
 *
 *If <TaskID> can’t be evaluated (no task currently running), the service
 *returns INVALID_TASK as TaskType.

 * Status:

*\a Standard: \a
*  * No error, E_OK
*
*\a Extended: \a
*  * No error, E_OK

 * Conformance:        BCC1, BCC2, ECC1, ECC2
 * #################################################################################################
 */

StatusType GetTaskID(TaskRefType TaskID) {
  StatusType *status = E_OK;

    ApplicationType AppID = GetCurrentApplicationID_Kernel();
    
    if (AppID == OS_CORE_ID_MASTER_0) {
       // todo: initiate system call to the corresponing core and send the correct parameters 
    // todo: such as:
        // syscall_GetTaskID_TC0(0, 0, 0, 0, TaskID, 0, 0, status, 0);
    }else if (AppID == OS_CORE_ID_1) {
       // todo: initiate system call to the corresponing core and send the correct parameters 
    // todo: such as:
        // syscall_GetTaskID_TC1(0, 0, 0, 0, TaskID, 0, 0, status, 0);
    }else if (AppID == OS_CORE_ID_2) {//todo:
    }else if (AppID == OS_CORE_ID_3) {//todo:
    }else if (AppID == OS_CORE_ID_4) {//todo:
    }else if (AppID == OS_CORE_ID_5) {//todo:
    }else if (AppID == OS_CORE_ID_6) {//todo:
    }else{}
  return *status;
}

// This is the kernel version of the GetTaskID service
void GetTaskID_Kernel(TaskRefType TaskID, StatusType *status) {
  ApplicationType AppID = GetCurrentApplicationID_Kernel();
  *status = E_OK;
  if ((OSApp[AppID].CurrentTask->TaskID >= 0) &&
      (OSApp[AppID].CurrentTask->TaskID < MAX_TASK_ID)) {
    TaskID = &OSApp[AppID].CurrentTask->TaskID;
  } else {
    TaskType invalid = INVALID_TASK;
    TaskID = &invalid;
  }
}