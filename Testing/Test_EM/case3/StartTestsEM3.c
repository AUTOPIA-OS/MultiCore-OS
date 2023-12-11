#include "test_hardware.h"

int TestEM3Counter = 0;
void startTestsEM3(void)
{
    ApplicationType AppID = GetCurrentApplicationID_Kernel();

    if (AppID == OS_CORE_ID_MASTER_0) {
        generateTask(OS_CORE_ID_MASTER_0, 8, SUSPENDED, FULL, EXTENDED, 6, 6, 0, 5, (0U), &task3EM);
        generateTask(OS_CORE_ID_MASTER_0, 9, SUSPENDED, FULL, EXTENDED, 5, 5, 0, 5, (0U), &task4EM);
        TestEM3Counter = 0;
        //PqPush(&OSApp[AppID].ReadyQueue, 5, OSApp[AppID].Tasks[5].PRIORITY);
        ActivateTask(8);
    }
    else{}
}
