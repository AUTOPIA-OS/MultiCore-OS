
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

#ifndef COUNTER_H
#define COUNTER_H

/* ********************************************************************** */

// [SRS_Os_11020] 
// The OS shall provide a standard interface to tick a software counter
// [SWS_Os_00301]
// The Operating System module shall provide the ability to increment a software Counter as an alternative action on alarm expiry.

/* ********************************************************************** */

#include "EventMechanism.h"
#include "PriorityQueueTimer.h"
#include "TaskManager.h"
#include "StatusDefintions.h"
#include "includes.h"

/* ********************************************************************** */

void ExecuteAlarmAction(AlarmType AlarmID, StatusType *status);

StatusType GetCounterValue (CounterType CounterID,TickRefType Value);
StatusType IncrementCounter(CounterType CounterID);
StatusType GetElapsedValue (CounterType CounterID,TickRefType Value,TickRefType ElapsedValue);

void GetCounterValue_Kernel (CounterType CounterID,TickRefType Value, StatusType *status);
void IncrementCounter_Kernel(CounterType CounterID, StatusType *status);
void GetElapsedValue_Kernel (CounterType CounterID,TickRefType Value,TickRefType ElapsedValue, StatusType *status);


/* ********************************************************************** */

#endif