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

#include "test_hardware.h"
#include "includes.h"


void task1StackMonitoring(void) { 
    uint32_t ptr = OSApp[0].CurrentTask->StackPointerBaseAddress;

    // write to ptr a value
    for (ptr; ptr > OSApp[0].CurrentTask->StackPointerBaseAddress - 65 * 4; ptr-=4)
    {
        *((uint32_t*)ptr) = 123;
    }
    ActivateTask(7);
    TerminateTask();
}
