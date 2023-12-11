
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

#ifndef STACK_POINTER_H
#define STACK_POINTER_H

/* ********************************************************************** */

#include "includes.h"

/* ********************************************************************** */

/* ********************************************************************** */

extern uint32_t InterruptStackPointer;
extern uint32_t InterruptStack[STACK_2k];

/* ********************************************************************** */

// this function is used to initialize the stack pointer
void Init_Stack_pointer(ApplicationType AppID);
void WriteStackPointer(uint32_t address);
uint32_t ReadStackPointer(void);
void WriteInterruptStackPointer(uint32_t address);
uint32_t ReadStackInterruptPointer(void);

/* ********************************************************************** */

#endif