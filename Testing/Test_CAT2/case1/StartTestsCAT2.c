#include "test_hardware.h"

void startTestsCAT2(void)
{
    ApplicationType AppID = GetCurrentApplicationID_Kernel();

    if (AppID == OS_CORE_ID_MASTER_0) {
        generateTask(OS_CORE_ID_MASTER_0, 6, SUSPENDED, FULL, EXTENDED, 7, 7, 0, 5, (0U), &task1CAT2);
        generateTask(OS_CORE_ID_MASTER_0, 7, SUSPENDED, FULL, EXTENDED, 6, 6, 0, 5, (0U), &task2CAT2);

        //PqPush(&OSApp[AppID].ReadyQueue, 5, OSApp[AppID].Tasks[5].PRIORITY);
         StatusType status = E_OK;
        // todo: sync data between cores
        uint32_t flag = E_OK;
        ActivateTask_Kernel(7, &status, &flag);
    }
    else{}
}

