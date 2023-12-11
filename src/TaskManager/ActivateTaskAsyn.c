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
 * 13.2.3.1 ActivateTask
 *
 * Syntax:             StatusType ActivateTask ( TaskType <TaskID> )
 * Parameter (In):
 * TaskID              Task reference
 *
 * Description:        The task <TaskID> is transferred from the suspended state
 * into the ready state.The operating system ensures that the task code is being
 * executed from the first statement.
 *
 * Particularities:    The service may be called from interrupt level and from
 * task level. Rescheduling after the call to ActivateTask depends on theplace
 * it is called from (ISR, non preemptable task, preemptabletask).
 *
 * If E_OS_LIMIT is returned the activation is ignored.When
 * an extended task is transferred from suspended state into ready state all its
 * events are cleared. Status: Standard:     • No error, E_OK • Too many task
 * activations of <TaskID>, E_OS_LIMIT Extended:     • Task <TaskID> is invalid,
 * E_OS_ID Conformance:        BCC1, BCC2, ECC1, ECC2
 * #################################################################################################
 */

// [SWS_Os_00816] dThe operating system shall provide an asynchronous version of
// ActivateTask which does not return errors to the caller, but only calls the (global)
// error hook (if configured). The function name shall be ActivateTaskAsyn.c(SRS_-
// Os_80015)


void ActivateTaskAsyn (TaskType TaskID)
{
    ApplicationType AppID = GetCurrentApplicationID_Kernel();
    
    if (AppID == OS_CORE_ID_MASTER_0) {
        syscall_ActivateTask_TC0(TaskID, 0, 0, 0, 0, 0, 0, 0, 0);
    }else if (AppID == OS_CORE_ID_1) {
        syscall_ActivateTask_TC1(TaskID, 0, 0, 0, 0, 0, 0, 0, 0);
    }else if (AppID == OS_CORE_ID_2) {//todo:
    }else if (AppID == OS_CORE_ID_3) {//todo:
    }else if (AppID == OS_CORE_ID_4) {//todo:
    }else if (AppID == OS_CORE_ID_5) {//todo:
    }else if (AppID == OS_CORE_ID_6) {//todo:
    }else{}

  
  
}

void ActivateTaskAsyn_Kernel (TaskType TaskID)
{
    StatusType status = E_OK;
     ApplicationType AppID = GlobalTaskAppId[TaskID];
     ApplicationType CurrentApp = GetCurrentApplicationID_Kernel();

  if(AppID != CurrentApp){
      

      if (AppID == OS_CORE_ID_MASTER_0) {
 // todo: initiate system call to the corresponing core and send the correct parameters 
    // todo: such as:
          // syscall_ActivateTask_TC0(TaskID, 0, 0, 0, 0, 0, 0, 0, 0);
      }else if (AppID == OS_CORE_ID_1) {
           // todo: initiate system call to the corresponing core and send the correct parameters 
    // todo: such as:
          // syscall_ActivateTask_TC1(TaskID, 0, 0, 0, 0, 0, 0, 0, 0);
      }else if (AppID == OS_CORE_ID_2) {
      }else if (AppID == OS_CORE_ID_3) {
      }else if (AppID == OS_CORE_ID_4) {
      }else if (AppID == OS_CORE_ID_5) {
      }else if (AppID == OS_CORE_ID_6) {
      }else{}
      
  }
  else{
          // Making sure that this task exisits in the system
      if ((TaskID >= MAX_TASK_ID) || (TaskID < 0)) {
        status = E_OS_ID;
      }
      // Making sure that the number of Task instances with TaskID does not exceed the limit
      else if (OSApp[AppID].Tasks[TaskID].ACTIVATION >=
              OSApp[AppID].Tasks[TaskID].ACTIVATIONMAX) {
        status = E_OS_LIMIT;
      } else {

          // Clearing the events of the task
          OSApp[AppID].Tasks[TaskID].Events = (0U);
          OSApp[AppID].Tasks[TaskID].WaitEvents = (0U);

          // if the task was activated before, then only increment the number of
          // activations No need to add the task to the ready queue again
          if ((OSApp[AppID].Tasks[TaskID].TaskState == READY) ||
              (OSApp[AppID].Tasks[TaskID].TaskState == RUNNING)) {

            OSApp[AppID].Tasks[TaskID].ACTIVATION++;

            // No need to run the Sechedule here, because the task is already in the Ready Queue.
            // So if it has a higher priority than the CurrentTask it should have benn running in the first place
            status = E_OK;
          } else {

            if (OSApp[AppID].Tasks[TaskID].TaskState == SUSPENDED) {
              OSApp[AppID].Tasks[TaskID].ACTIVATION++;
              // todo: initialize the context of new task
              OSApp[AppID].Tasks[TaskID].PC =
                  (uint32_t)OSApp[AppID].Tasks[TaskID].TaskEntryPoint;
            } else {
            }

            // setting the task from suspended to ready state
            OSApp[AppID].Tasks[TaskID].TaskState = READY;
            PqPush(&OSApp[AppID].ReadyQueue, TaskID,
                  OSApp[AppID].Tasks[TaskID].PRIORITY);

            if (OSApp[AppID].CurrentTask->SCHEDULE == FULL) {

              Schedule_Kernel(&status);
            } else if (OSApp[AppID].CurrentTask->SCHEDULE == NON) {
              status = E_OK;
            } else {
              status = E_OK;
            }
          }
        }

          if (status != E_OK) {
          ErrorHook_Kernel(status);
          }
      }

 
  
    

  

}