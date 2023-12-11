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
 * [Test_CNT1]
 * [Test_CNT2]
*/
int TestCNT1Counter = 0;

void startTestsCNT1(void)
{
    TestCNT1Counter = 0;
    ApplicationType AppID = GetCurrentApplicationID_Kernel();

    if (AppID == OS_CORE_ID_MASTER_0) {


        generateTask(OS_CORE_ID_MASTER_0, 6, SUSPENDED, FULL, EXTENDED, 1, 1, 0, 5, (0U), &task1CNT1);
        generateTask(OS_CORE_ID_MASTER_0, 7, SUSPENDED, FULL, EXTENDED, 2, 2, 0, 5, (0U), &task2CNT1);

        generateCounter(OS_CORE_ID_MASTER_0, 1, 0, 1000, Software);

        AlarmBaseType alarmBase;
        alarmBase.MAXALLOWEDVALUE = 1000;
        alarmBase.TICKSPERBASE = 1;
        alarmBase.MINCYCLE = 3;

        createAlarmSoftware(3, alarmBase, 2, 3, ACTION_ACTIVATETASK, 7, 0, 0, 0, NULL,
                            1);  


        ActivateTask(6);



    }
    else{}
}
