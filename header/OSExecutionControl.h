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

#ifndef OS_EXECUTION_Control
#define OS_EXECUTION_Control

/* ********************************************************************** */

/* ********************************************************************** */

#include "Alarms.h"
#include "BootCore.h"
#include "InterruptManager.h"
#include "StackPointer.h"
#include "TaskManager.h"
#include "test_hardware.h"

/* ********************************************************************** */

AppModeType GetActiveApplicationMode(void);
void StartOS(AppModeType Mode);
void ShutdownOS(StatusType Error);
void InitStacks(ApplicationType AppID);

/* ********************************************************************** */

// prototypes for kernel functions
void StartOS_Kernel(AppModeType Mode, uint32_t PCXI_IDLE);
void ShutdownOS_Kernel(StatusType Error);
void GetActiveApplicationMode_Kernel( AppModeType *Mode);

/* ********************************************************************** */

#endif