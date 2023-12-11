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

#include "OSExecutionControl.h"

void InitStacks(ApplicationType AppID) {

  for (int i = 0; i < MAX_TASK_ID; i++) {
    OSApp[AppID].Tasks[i].StackPointerBaseAddress =
        (uint32_t)OSApp[AppID].Tasks[i].Stack + (256U) - (4U);
    OSApp[AppID].Tasks[i].Stack[0] = (0xDEADBEEFU);
  }
}

