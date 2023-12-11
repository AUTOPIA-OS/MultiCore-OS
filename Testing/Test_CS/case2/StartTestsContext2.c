#include "test_hardware.h"

int TestContext2Counter = 0;

void startTestsContext2(void)
{
    ApplicationType AppID = GetCurrentApplicationID_Kernel();
    
    TestContext2Counter = 0;

    if (AppID == OS_CORE_ID_MASTER_0) {
        generateTask(OS_CORE_ID_MASTER_0, 6, SUSPENDED, FULL, EXTENDED, 4, 4, 0, 5, (0U), &task3Context);
        generateTask(OS_CORE_ID_MASTER_0, 7, SUSPENDED,  NON, EXTENDED, 5, 5, 0, 5, (0U), &task4Context);
        generateTask(OS_CORE_ID_MASTER_0, 8, SUSPENDED, FULL, EXTENDED, 6, 6, 0, 5, (0U), &task5Context);
        generateTask(OS_CORE_ID_MASTER_0, 9, SUSPENDED, FULL, EXTENDED, 7, 7, 0, 5, (0U), &task6Context);

        ActivateTask(6);
    }
    else{}
}
