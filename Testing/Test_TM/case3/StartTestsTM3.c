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
 *  • REQ-5: Allow multiple task activation requests
 * 
*/

int TestTM3Counter = 0;
void startTestsTM3(void)
{
    ApplicationType AppID = GetCurrentApplicationID_Kernel();

    TestTM3Counter = 0;

    if (AppID == OS_CORE_ID_MASTER_0) {


        generateTask(OS_CORE_ID_MASTER_0, 6, SUSPENDED, FULL, BASIC, 3, 3, 0, 5, (0U), &task7TM);
        generateTask(OS_CORE_ID_MASTER_0, 7, SUSPENDED, FULL, BASIC, 2, 2, 0, 5, (0U), &task8TM);        
    
        ActivateTask(6);
    }
    else{}
}
