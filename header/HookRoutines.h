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

#ifndef HOOK_ROUTINES_H
#define HOOK_ROUTINES_H

/* ********************************************************************** */

#include "EventMechanism.h"
#include "InterruptManager.h"
#include "TaskManager.h"

/* ********************************************************************** */

void ErrorHook(StatusType Error);
void PreTaskHook(void);
void PostTaskHook(void);
void StartupHook(void);
void ShutdownHook(StatusType Error);

/* ********************************************************************** */

// prototypes for kernel functions
void ErrorHook_Kernel(StatusType Error);
void PreTaskHook_Kernel(void);
void PostTaskHook_Kernel(void);
void StartupHook_Kernel(void);
void ShutdownHook_Kernel(StatusType Error);

/* ********************************************************************** */

#endif