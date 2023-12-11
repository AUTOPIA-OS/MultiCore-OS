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

/**
 * 
 *  • REQ-1: Provide Task Activation
 *  • REQ-2: Provide a priority-based scheduling policy 
 *  • REQ-3: Provide non preemptive mechanism 
*/

int TestTM1Counter = 0;
void startTestsTM1(void)
{
    ApplicationType AppID = GetCurrentApplicationID_Kernel();
    TestTM1Counter = 0;

    if (AppID == OS_CORE_ID_MASTER_0) {


        generateTask(OS_CORE_ID_MASTER_0, 6, SUSPENDED, NON, BASIC, 1, 1, 0, 5, (0U), &task1TM);
        generateTask(OS_CORE_ID_MASTER_0, 7, SUSPENDED, FULL, BASIC, 2, 2, 0, 5, (0U), &task2TM);
        generateTask(OS_CORE_ID_MASTER_0, 8, SUSPENDED, FULL, BASIC, 5, 5, 0, 5, (0U), &task3TM);
        generateTask(OS_CORE_ID_MASTER_0, 9, SUSPENDED, FULL, BASIC, 4, 4, 0, 5, (0U), &task4TM);

            ActivateTask(6);   

    }
    else{}
}
