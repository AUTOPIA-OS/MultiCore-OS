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

#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H

/* ********************************************************************** */

#include "HookRoutines.h"
#include "OSApplications.h"
#include "PriorityQueue.h"
#include "ResourceManager.h"
#include "StatusDefintions.h"
#include "stack.h"
#include "test_hardware.h"
#include "includes.h"

/* ********************************************************************** */

/*
DeclareTask serves as an external declaration of a task. The
function and use of this service are similar to that of the external
declaration of variables.
*/
#define DeclareTask(Taskname) void Task##Taskname()
// refer to page 50 in VDX

/* ********************************************************************** */

/*    Task Managment Functions Declarations    */

StatusType ActivateTask(TaskType TaskID);
void ActivateTaskAsyn (TaskType id);
StatusType TerminateTask(void);
StatusType ChainTask(TaskType TaskID);
StatusType Schedule(void);
StatusType GetTaskID(TaskRefType TaskID);
StatusType GetTaskState(TaskType TaskID, TaskStateRefType State);

/* ********************************************************************** */

StatusType TaskManagerInit(uint32_t PCXI_IDLE, ApplicationType AppID);
void emptyReadyQueue(ApplicationType AppID);

/* ********************************************************************** */

// prototypes for kernel functions
void ActivateTask_Kernel(TaskType TaskID, StatusType *status, uint32_t *flag);
void ActivateTaskAsyn_Kernel (TaskType id);
void TerminateTask_Kernel(StatusType *status);
void ChainTask_Kernel(TaskType TaskID, StatusType *status, uint32_t *flag);
void Schedule_Kernel(StatusType *status);
void GetTaskID_Kernel(TaskRefType TaskID, StatusType *status);
void GetTaskState_Kernel(TaskType TaskID, TaskStateRefType State, StatusType *status, uint32_t *flag);

/* ********************************************************************** */

void ReleaseAllInternalResources(ApplicationType AppID);

/* ********************************************************************** */

#endif