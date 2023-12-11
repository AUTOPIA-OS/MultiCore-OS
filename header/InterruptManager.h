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

#ifndef INTERRUPT_HANDLER_H
#define INTERRUPT_HANDLER_H

/* ********************************************************************** */

// The OS shall provide interrupt mask functions
// [SRS_Os_11018] 
// The Operating System module shall provide the services DisableAllInterrupts, EnableAllInterrupts, SuspendAllInterrupts, ResumeAllInterrupts prior to calling StartOS and after calling ShutdownOS.
// [SWS_Os_00299] 

/* ********************************************************************** */

#include "ResourceManager.h"

#include "test_hardware.h"
#include "includes.h"

/* ********************************************************************** */

// This is the highest priority an OS interrupt can have
#define MAX_OS_INTERRUPT_PRIORITY              50 

/* ********************************************************************** */

/* ********************************************************************** */

/*    Interrupt Handler Functions Declarations    */
void EnableAllInterrupts(void);
void DisableAllInterrupts(void);
void ResumeAllInterrupts(void);
void SuspendAllInterrupts(void);
void ResumeOSInterrupts(void);
void SuspendOSInterrupts(void);

/* ********************************************************************** */

void InterruptManagerInit(void);
void GlobalInterruptHandler(void);
void Cat2test(void);
void ConfigCat2test(void);
void CrossCoreHandler(void);

/* ********************************************************************** */

// prototypes for kernel functions
void EnableAllInterrupts_Kernel(void);
void DisableAllInterrupts_Kernel(void);
void ResumeAllInterrupts_Kernel(void);
void SuspendAllInterrupts_Kernel(void);
void ResumeOSInterrupts_Kernel(void);
void SuspendOSInterrupts_Kernel(void);

/* ********************************************************************** */

#endif