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

#ifndef PRIORITY_QUEUE__TIMER_H
#define PRIORITY_QUEUE__TIMER_H

/* ********************************************************************** */

#include "includes.h"

/* ********************************************************************** */

void PriorityQueueTimerPush(PriorityQueueTimer *queue, int index,
                            uint64_t priority);
int PqPopTimer(PriorityQueueTimer *queue);
int PqGetRootTimer(PriorityQueueTimer *queue);
int PqPopElementTimer(PriorityQueueTimer *queue, int index);
int PqGetLastTimer(PriorityQueueTimer *queue);
void PriorityQueueTimer_init(PriorityQueueTimer *queue);

/* ********************************************************************** */

#endif