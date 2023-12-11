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

// [SWS_Os_00596] dIt shall be possible to activate a Task that is part of an OSApplication located on another core,
// as long as the assigned access rights allow it.

// [SWS_Os_00598] dThe call of ActivateTask across cores shall behave synchronously, 
// i.e. a call returns after the Task has been activated or an error has been
// detected. It shall not be possible to continue execution on the calling core before
// ActivateTask is accomplished on the remote core.c(SRS_Os_80015)

// [SWS_Os_00599] dIn case of an error when calling ActivateTask across cores,
// the error handler shall be called on the core on which ActivateTask was originally
// called.


StatusType ActivateTask(TaskType TaskID) {
  StatusType status = E_OK;
  // todo: sync data between cores
  uint32_t flag = E_OK;
    
    ApplicationType AppID = GetCurrentApplicationID_Kernel();
    
    if (AppID == OS_CORE_ID_MASTER_0) {
         // todo: initiate system call to the corresponing core and send the correct parameters 
    // todo: such as:
    // syscall_ActivateTask_TC0(TaskID, 0, 0, 0, 0, 0, 0, &status, &flag);
    }else if (AppID == OS_CORE_ID_1) {
       // todo: initiate system call to the corresponing core and send the correct parameters 
    // todo: such as:
        // syscall_ActivateTask_TC1(TaskID, 0, 0, 0, 0, 0, 0,  &status,  &flag);
    }else if (AppID == OS_CORE_ID_2) {//todo:
    }else if (AppID == OS_CORE_ID_3) {//todo:
    }else if (AppID == OS_CORE_ID_4) {//todo:
    }else if (AppID == OS_CORE_ID_5) {//todo:
    }else if (AppID == OS_CORE_ID_6) {//todo:
    }else{}

  return status;
}


// This is the kernel version of the ActivateTask service
void ActivateTask_Kernel(TaskType TaskID, StatusType *status, uint32_t *flag) {


  ApplicationType AppID = GlobalTaskAppId[TaskID];
  ApplicationType CurrentApp = GetCurrentApplicationID_Kernel();


  if(AppID != CurrentApp){
      
      if(OSApp[AppID].OSRunning == false){
          *status = E_OS_ACCESS;
          // todo: sync data between cores
      }
      else{
      if (AppID == OS_CORE_ID_MASTER_0) {

        
       
          
          // syscall_ActivateTask_TC1(TaskID, 0, 0, 0, 0, 0, 0,status, &flag);
          //Core0CCP.tin = 1;
          //Core0CCP.ID = TaskID;
          //Core0CCP.status = status; 
          // todo: sync data between cores
          // Core1CCP.flag = 0;
          // flag = Core1CCP.flag;
          
          // todo: fire interrupt to the other core and make it jump to cross core handler
         
      }else if (AppID == OS_CORE_ID_1) {
          

          
          // syscall_ActivateTask_TC1(TaskID, 0, 0, 0, 0, 0, 0,status, &flag);
          // Core1CCP.tin = 1;
          // Core1CCP.ID = TaskID;
          // Core1CCP.status = status; 
          // todo: sync data between cores
          // Core1CCP.flag = 0;
          // flag = Core1CCP.flag;
          
          // todo: fire interrupt to the other core and make it jump to cross core handler

      }else if (AppID == OS_CORE_ID_2) {
      }else if (AppID == OS_CORE_ID_3) {
      }else if (AppID == OS_CORE_ID_4) {
      }else if (AppID == OS_CORE_ID_5) {
      }else if (AppID == OS_CORE_ID_6) {
      }else{}
      
      while(*status >= 0){
          //synchronize with the other core
      }
    }
  }
  else{
          // Making sure that this task exisits in the system
      if ((TaskID >= MAX_TASK_ID) || (TaskID < 0)) {
        *status = E_OS_ID;
        // todo: sync data between cores
      }
      // Making sure that the number of Task instances with TaskID does not exceed the limit
      else if (OSApp[AppID].Tasks[TaskID].ACTIVATION >=
              OSApp[AppID].Tasks[TaskID].ACTIVATIONMAX) {
        *status = E_OS_LIMIT;
        // todo: sync data between cores
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
            *status = E_OK;
            // todo: sync data between cores
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

            Schedule_Kernel(status);
            } else if (OSApp[AppID].CurrentTask->SCHEDULE == NON) {
              *status = E_OK;
              // todo: sync data between cores
            } else {
              *status = E_OK;
              // todo: sync data between cores
            }
          }
        }
      
      }

 
    //synchronize with the other core
    *status *= -1;
    // todo: sync data between cores

    if ((*status * *status) != E_OK) {
      ErrorHook_Kernel(*status);
    }
  
}