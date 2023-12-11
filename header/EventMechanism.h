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

#ifndef EVENT_MECHANISM_H
#define EVENT_MECHANISM_H

/* ********************************************************************** */

#include "HookRoutines.h"
#include "InterruptManager.h"
#include "StatusDefintions.h"
#include "TaskManager.h"

/* ********************************************************************** */

/*
DeclareEvent serves as an external declaration of an event.
The function and use of this service are similar to that of the
external declaration of variables.
*/
#define DeclareEvent(EventIdentifier) void Event##EventIdentifier()

/* ********************************************************************** */

/*    Event Mechanism Functions Declarations    */
StatusType SetEvent(TaskType TaskID, EventMaskType Mask);
StatusType ClearEvent(EventMaskType Mask);
StatusType GetEvent(TaskType TaskID, EventMaskRefType Event);
StatusType WaitEvent(EventMaskType Mask);
void SetEventAsyn(TaskType TaskID, EventMaskType Mask);

/* ********************************************************************** */

// prototypes for kernel functions
void SetEvent_Kernel(TaskType TaskID, EventMaskType Mask, StatusType *status, uint32_t *flag);
void ClearEvent_Kernel(EventMaskType Mask, StatusType *status);
void GetEvent_Kernel(TaskType TaskID, EventMaskRefType Event, StatusType *status);
void WaitEvent_Kernel(EventMaskType Mask, StatusType *status);
void SetEventAsyn_Kernel(TaskType TaskID, EventMaskType Mask);

/* ********************************************************************** */

#endif