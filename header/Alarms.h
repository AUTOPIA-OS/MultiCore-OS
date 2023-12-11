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

#ifndef ALARMS_H
#define ALARMS_H

/* ********************************************************************** */

#include "InterruptManager.h"
#include "PriorityQueueTimer.h"
#include "STM.h"
#include "StatusDefintions.h"
#include "includes.h"

/* ********************************************************************** */

/*  ALARMS APIs */
/**     DeclareAlarm serves as external declaration of an alarm element.    */
#define DeclareAlarm(AlarmIdentifier) void Alarm##Alarmname()

/* ********************************************************************** */

/*     ALARMS Functions Declarations    */
StatusType GetAlarmBase(AlarmType AlarmID, AlarmBaseRefType Base);
StatusType GetAlarm(AlarmType AlarmID, TickRefType Tick);
StatusType SetRelAlarm(AlarmType AlarmID, TickType increment, TickType cycle);
StatusType SetAbsAlarm(AlarmType AlarmID, TickType start, TickType cycle);
StatusType CancelAlarm(AlarmType AlarmID);

/* ********************************************************************** */

// prototypes for kernel functions

void GetAlarmBase_Kernel(AlarmType AlarmID, AlarmBaseRefType Base,StatusType *status, uint32_t *flag);
void GetAlarm_Kernel(AlarmType AlarmID, TickRefType Tick, StatusType *status, uint32_t *flag);
void SetRelAlarm_Kernel(AlarmType AlarmID, TickType increment,
                              TickType cycle, StatusType *status);
void SetAbsAlarm_Kernel(AlarmType AlarmID, TickType start,
                              TickType cycle, StatusType *status);
void CancelAlarm_Kernel(AlarmType AlarmID, StatusType *status, uint32_t *flag);

/* ********************************************************************** */

uint32_t GetRightWord(uint64_t value);
uint32_t GetLeftWord(uint64_t value);

/* ********************************************************************** */

#endif