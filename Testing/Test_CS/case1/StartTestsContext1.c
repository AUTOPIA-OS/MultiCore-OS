#include "test_hardware.h"

int TestContext1Counter = 0;

void startTestsContext1(void)
{
    ApplicationType AppID = GetCurrentApplicationID_Kernel();
    
    TestContext1Counter = 0;

    if (AppID == OS_CORE_ID_MASTER_0) {
        generateTask(OS_CORE_ID_MASTER_0, 6, SUSPENDED, FULL, EXTENDED, 4, 4, 1, 5, (0U), &task1Context);
        generateTask(OS_CORE_ID_MASTER_0, 7, SUSPENDED, FULL, EXTENDED, 5, 5, 0, 5, (0U), &task2Context);

        ActivateTask(6);
    }
    else{}
}
