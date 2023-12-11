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

extern int TestRM2Counter;

void task1RM2(void) { 

    if (GetResource(1) != E_OK){
        TestPassed = 0;
    }

    ActivateTask(7);

    if (TestRM2Counter != 0){
        TestPassed = 0;
    }

    TestRM2Counter++;

    if (ReleaseResource(1)!= E_OK){
        TestPassed = 0;
    }

    if (TestRM2Counter != 2){
        TestPassed = 0;
    }
    
    TerminateTask();
}