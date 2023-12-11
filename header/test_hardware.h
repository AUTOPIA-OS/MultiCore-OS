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

#ifndef TEST_HARDWARE_H
#define TEST_HARDWARE_H

/* ********************************************************************** */

#include "OS.h"
#include "BootCore.h"
#include "IOC.h"
#include "includes.h"

/* ********************************************************************** */

/** Task Functions */

// Testing Helper Functions
int AddTwoValues(int x, int y);
int get_volume(int length, int width, int height);
void startTests(void);
void generateTask(ApplicationType AppID, TaskType TaskID, TaskStateType TaskState,
                  uint32_t SCHEDULE, uint32_t VERSION,
                  uint32_t PRIORITY, uint32_t BASEPRIORITY, int activation,
                  int activationMax, EventMaskType events,
                  void (*TaskEntryPoint)(void));

void generateResource( ResourceType ResID,
                      int resourceProperty, uint32_t ceilingPriority,
                      int linkedResID, bool availability,
                      TaskType holdingTaskID);

void generateCounter(ApplicationType AppID, CounterType CounterID, TimerType TimerID,
                     TickType MaxAllowedValue, uint32_t Version);

void GenerateAlarmSoftware(AlarmType alarmID, AlarmBaseType Alarmbase,
                         TickType start, TickType cycle, uint16_t ACTION,
                         TaskType TaskID, EventMaskType EventMask,
                         uint32_t AUTOSTART, AppModeType APPMODE_TYPE,
                         void (*callback)(void), CounterType counterID);

void GenerateAlarmHardware(AlarmType alarmID, AlarmBaseType Alarmbase,
                         TickType start, TickType cycle, uint16_t ACTION,
                         TaskType TaskID, EventMaskType EventMask,
                         uint32_t AUTOSTART, AppModeType APPMODE_TYPE,
                         void (*callback)(void), CounterType counterID);
                         
/* ********************************************************************** */

// // Testing Tasks
// void taskIdle(void);

/* ********************************************************************** */



/* ********************************************************************** */

// Testing Event Mechanism
void startTestsEM1(void);
void task1EM(void);
void startTestsEM2(void);
void task2EM(void);
void startTestsEM3(void);
void task3EM(void);
void task4EM(void);

/* ********************************************************************** */

// Testing Stack Monitoring
void startTestsStackMonitoring(void);
void task1StackMonitoring(void);
void task2StackMonitoring(void);

/* ********************************************************************** */

// Testing CAT2 Interrupts
void startTestsCAT2(void);
void task1CAT2(void);
void task2CAT2(void);

/* ********************************************************************** */

// Testing Context Switching
void startTestsContext1(void);
void task1Context(void);
void task2Context(void);
void startTestsContext2(void);
void task3Context(void);
void task4Context(void);
void task5Context(void);
void task6Context(void);

/* ********************************************************************** */

// Testing Task Manager
void startTestsTM1(void);
void task1TM(void);
void task2TM(void);
void task3TM(void);
void task4TM(void);
void startTestsTM2(void);
void task5TM(void);
void task6TM(void);
void startTestsTM3(void);
void task7TM(void);
void task8TM(void);
void startTestsTM4(void);
void task9TM(void);
void task10TM(void);
void startTestsTM5(void);
void task11TM(void);
void task12TM(void);
void task13TM(void);
void startTestsTM6(void);
void task14TM(void);
void task15TM(void);
void task16TM(void);

/* ********************************************************************** */

// Testing Resource Manager
void startTestsRM1(void);
void task1RM1(void);
void task2RM1(void);
void startTestsRM2(void);
void task1RM2(void);
void task2RM2(void);
void startTestsRM3(void);
void task1RM3(void);

/* ********************************************************************** */

// Testing Interrupt Manager
void startTestsIM1(void);
void task1IM1(void);
void task2IM1(void);
void startTestsIM2(void);
void task1IM2(void);
void task2IM2(void);
void startTestsIM3(void);
void task1IM3(void);
void task2IM3(void);
void task3IM3(void);
/* ********************************************************************** */

// Testing Interrupt Manager
void startTestsCNT1(void);
void task1CNT1(void);
void task2CNT1(void);
void startTestsCNT2(void);
void task1CNT2(void);
void task2CNT2(void);
void startTestsCNT3(void);
void task1CNT3(void);
void task2CNT3(void);
void task3CNT3(void);
/* ********************************************************************** */
void startTestsStackMonitoring(void);


/* ********************************************************************** */

void task2IM1Helper(void);

void task2IM2Helper(void);


void task2IM3Helper(void);


void task3IM3Helper(void);

/* ********************************************************************** */


// IOC testing

void startTestsIOC1(void);
void task1IOC1(void);
void task2IOC1(void);
#endif