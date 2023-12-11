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

int TestEM1Counter = 0;
void startTestsEM1(void)
{
    ApplicationType AppID = GetCurrentApplicationID_Kernel();

    if (AppID == OS_CORE_ID_MASTER_0) {

        generateTask(OS_CORE_ID_MASTER_0, 6, SUSPENDED, FULL, BASIC, 4, 4, 0, 5, (0U), &task1EM);
        TestEM1Counter = 0;
        //PqPush(&OSApp[AppID].ReadyQueue, 5, OSApp[AppID].Tasks[5].PRIORITY);
        ActivateTask(6);
    }
    else{}
}

