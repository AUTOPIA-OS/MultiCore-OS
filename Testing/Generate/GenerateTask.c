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

#include "test_hardware.h"

void generateTask(ApplicationType AppID, TaskType TaskID, TaskStateType TaskState,
                  uint32_t SCHEDULE, uint32_t VERSION,
                  uint32_t PRIORITY, uint32_t BASEPRIORITY, int activation,
                  int activationMax, EventMaskType events,
                  void (*TaskEntryPoint)(void)) {
  

  if(GlobalTaskAppId[TaskID] == -1){
    GlobalTaskAppId[TaskID] = AppID;
  }
  else{
    ShutdownOS_Kernel(OSApp[AppID].OSDEFAULTAPPMODE);
  }
  OSApp[AppID].Tasks[TaskID].TaskID = TaskID;
  OSApp[AppID].Tasks[TaskID].TaskState = TaskState;
  OSApp[AppID].Tasks[TaskID].SCHEDULE = SCHEDULE;
  OSApp[AppID].Tasks[TaskID].VERSION = VERSION;
  OSApp[AppID].Tasks[TaskID].PRIORITY = PRIORITY;
  OSApp[AppID].Tasks[TaskID].BASEPRIORITY = BASEPRIORITY;
  OSApp[AppID].Tasks[TaskID].ACTIVATION = activation;
  OSApp[AppID].Tasks[TaskID].ACTIVATIONMAX = activationMax;
  OSApp[AppID].Tasks[TaskID].TaskEntryPoint = TaskEntryPoint;
  OSApp[AppID].Tasks[TaskID].PC = (uint32_t)TaskEntryPoint;
  OSApp[AppID].Tasks[TaskID].Events = events;
  OSApp[AppID].Tasks[TaskID].WaitEvents = (0U);


// todo : init task context

  StackInit(&OSApp[AppID].Tasks[TaskID].TaskResources);
  StackInit(&OSApp[AppID].Tasks[TaskID].InternalResoruces);
  return;
}