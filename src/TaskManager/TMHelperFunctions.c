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

// This function is used to Save the Context of the current task
void Save_Context_Block(uint32_t PCXI, ApplicationType AppID) {
   // todo: 
}

// This function is used to Load the Context of the current task

void Load_Context_Block(uint32_t PCXI, ApplicationType AppID, bool all) {
  // todo:
  return;
}

// This function is used to Save the Context of a given task
void Save_PC_and_SP_to_Task_CSA(Task *task, int PC, int SP) {
  // todo:
}

// This function is used to Release all the Internal Resources of the current task
void ReleaseAllInternalResources(ApplicationType AppID) {
  if (!StackIsEmpty(&OSApp[AppID].CurrentTask->InternalResoruces)) {
    while (!StackIsEmpty(&OSApp[AppID].CurrentTask->InternalResoruces)) {
      Resource *InternalResource = &OSApp[AppID].InternalResources[StackPop(
          &OSApp[AppID].CurrentTask->InternalResoruces)];
      InternalResource->availability = true;
    }
  }
}

// This function is used to initialize the Idle Task
void InitializeIdleTask(uint32_t PCXI_IDLE, ApplicationType AppID) {


  OSApp[AppID].Tasks[AppID].TaskID = AppID;
  OSApp[AppID].Tasks[AppID].TaskState = RUNNING;
  OSApp[AppID].Tasks[AppID].SCHEDULE = FULL;
  OSApp[AppID].Tasks[AppID].VERSION = BASIC;
  OSApp[AppID].Tasks[AppID].ACTIVATION = 1;
  OSApp[AppID].Tasks[AppID].ACTIVATIONMAX = 5;
  OSApp[AppID].Tasks[AppID].PRIORITY = 0;
  OSApp[AppID].Tasks[AppID].BASEPRIORITY = 0;
  OSApp[AppID].IdleTask = &OSApp[AppID].Tasks[AppID];
  OSApp[AppID].Tasks[AppID].PCXI = PCXI_IDLE;
  // initialize TASKS array
  OSApp[AppID].CurrentTask = OSApp[AppID].IdleTask;
  PqPush(&OSApp[AppID].ReadyQueue, AppID, OSApp[AppID].Tasks[AppID].PRIORITY);

  if(AppID == OS_CORE_ID_MASTER_0)
    OSApp[AppID].Tasks[AppID].TaskEntryPoint = &IdleTask0;
  else if(AppID == OS_CORE_ID_1)
    OSApp[AppID].Tasks[AppID].TaskEntryPoint = &IdleTask1;
  
  OSApp[AppID].Tasks[AppID].PC = (uint32_t)OSApp[AppID].Tasks[AppID].TaskEntryPoint;
  OSApp[AppID].Tasks[AppID].Events = 0U;
  OSApp[AppID].Tasks[AppID].WaitEvents = (0U);
  OSApp[AppID].Tasks[AppID].StackPointerBaseAddress =
      (uint32_t)OSApp[AppID].Tasks[AppID].Stack + (256U) - (4U);



  // todo: initialize the task context

  StackInit(&OSApp[AppID].Tasks[AppID].TaskResources);
  StackInit(&OSApp[AppID].Tasks[AppID].InternalResoruces);
}

/*    Task Manager Initializer    */
StatusType TaskManagerInit(uint32_t PCXI_IDLE, ApplicationType AppID) {

  PriorityQueue_init(&OSApp[AppID].ReadyQueue);
  InitializeIdleTask(PCXI_IDLE, AppID);

  return E_OK;
}

void emptyReadyQueue(ApplicationType AppID) {
  while (PqPop(&OSApp[AppID].ReadyQueue) != -1) {
  }
}