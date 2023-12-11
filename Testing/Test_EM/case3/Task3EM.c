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

extern int TestEM3Counter;
void task3EM(void) { 

    TestEM3Counter = 0;
    ActivateTask(9);
    WaitEvent(1);               // Should go to task 4 now
    if (TestEM3Counter != 1)     // [Test_EM_7]
    {
        TestPassed = 0;
        while(1)
        {}
    }

    WaitEvent(1);               // Should not go to task 4 

    if (TestEM3Counter != 1)     // [Test_EM_8]
    {
        TestPassed = 0;
        while(1)
        {}
    }

    ClearEvent(1);
    WaitEvent(1);               // Should go to task 4
    if (TestEM3Counter != 2)
    {
        TestPassed = 0;
        while(1)
        {}
    }
    
    TerminateTask();
}
