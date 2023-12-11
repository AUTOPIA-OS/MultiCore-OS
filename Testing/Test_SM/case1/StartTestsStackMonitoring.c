#include "test_hardware.h"

void startTestsStackMonitoring(void)
{
    ApplicationType AppID = GetCurrentApplicationID_Kernel();

    if (AppID == OS_CORE_ID_MASTER_0) {

        generateTask(OS_CORE_ID_MASTER_0, 6, SUSPENDED, FULL, EXTENDED, 6, 6, 0, 5, (0U), &task1StackMonitoring);
        generateTask(OS_CORE_ID_MASTER_0, 7, SUSPENDED, FULL, EXTENDED, 7, 7, 0, 5, (1U), &task2StackMonitoring);

        //PqPush(&OSApp[AppID].ReadyQueue, 5, OSApp[AppID].Tasks[5].PRIORITY);
        ActivateTask(6);
    }
    else{}
}

