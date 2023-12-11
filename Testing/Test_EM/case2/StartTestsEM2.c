#include "test_hardware.h"

int TestEM2Counter = 0;
void startTestsEM2(void)
{
    ApplicationType AppID = GetCurrentApplicationID_Kernel();

    if (AppID == OS_CORE_ID_MASTER_0) {

        generateTask(OS_CORE_ID_MASTER_0, 7, SUSPENDED, FULL, EXTENDED, 5, 5, 0, 5, (1U), &task2EM);
        TestEM2Counter = 0;
        //PqPush(&OSApp[AppID].ReadyQueue, 5, OSApp[AppID].Tasks[5].PRIORITY);
        ActivateTask(7);
    }
    else{}
}

