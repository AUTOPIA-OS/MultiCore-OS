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

#include "Alarms.h"
#include "BootCore.h"
#include "InterruptManager.h"
#include "OSExecutionControl.h"
#include "OSApplications.h"
#include "ResourceManager.h"
#include "StackPointer.h"
#include "TaskManager.h"
#include "includes.h"
#include "test_hardware.h"



// [SWS_Os_00607] dStartOS shall start the OS on the core on which it is called.c (SRS_Os_80006, SRS_Os_80013)


// [SWS_Os_00567]  IDs (e.g. TaskID, ResourceID, . . . ) are unique across cores.
// [SWS_Os_00574]  ⌈The master core shall be able to activate cores.⌋
// [SWS_Os_00575]  ⌈Any slave core shall be able to activate cores.⌋
// [SWS_Os_00576] ⌈It shall be allowed to use only a subset of the cores available on a μC for the AUTOSAR system.⌋
// [SWS_Os_00577] ⌈The cores shall boot in master-slave mode. If this is not supported by the hardware, it shall be that the cores boot in parallel and emulate the behavior of a master-slave system.⌋
// [SWS_Os_00578] ⌈In case of an emulation a slave core (CoreS), which is controlled by the AUTOSAR OS (AUTOSAR core), 
// shall not enter the main function before another core has activated the slave core by means of StartCore(CoreS).⌋
int main(void) {
  
  // TestCaseNumber = 1;
  // TestPassed = 0;
  StatusType status;
  if(GetCoreID_Kernel() == OS_CORE_ID_MASTER_0)
  {
    initializeArrays();
   
    OSApp[0].CoreSynchronizationFlagOne = 0;
    OSApp[0].CoreSynchronizationFlagTwo = 0;
    OSApp[1].CoreSynchronizationFlagOne = 0;
    OSApp[1].CoreSynchronizationFlagTwo = 0;

    CCP Core0CCP = {0};
    CCP Core1CCP = {0};
  }
    

  TestCaseNumber = -1;
  TestCaseNumber++;

 for (int i = 0; i < 18; i++) {
    TestCaseIndicator[i] = 0;
  }


  switch (GetCoreID_Kernel()) {
  case OS_CORE_ID_MASTER_0:

    
    InitOSApplication(OS_CORE_ID_MASTER_0);
    // todo: sync data between cores
    InitOSApplication(OS_CORE_ID_1);
    StartCore(OS_CORE_ID_1, &status);
    

     for (TestCaseNumber = 0; TestCaseNumber < 18; TestCaseNumber++)
        {
          InterruptManagerInit();
          OSApp[0].OSDEFAULTAPPMODE = Normal;
          DisableAllInterrupts_Kernel2();
          EnableAllInterrupts_Kernel2();
          // DisableAllInterrupts();
          StartOS(OSApp[0].OSDEFAULTAPPMODE);
          InitOSApplication(OS_CORE_ID_MASTER_0);
        }
        break;
  case OS_CORE_ID_1:
  
  
    OSApp[1].OSDEFAULTAPPMODE = Normal;
    // todo: sync data between cores
     InterruptManagerInit();
    DisableAllInterrupts_Kernel2();
    EnableAllInterrupts_Kernel2();
    StartOS(OSApp[1].OSDEFAULTAPPMODE);
    break;

  default:
    break;
  }

  return 0;
}


void initializeArrays() {
    int i;
    for (i = 0; i < MAX_TASK_ID; i++) {
        GlobalTaskAppId[i] = -1;
    }
    for (i = 0; i < MAX_COUNTERS; i++) {
        GlobalCounterAppId[i] = -1;
    }
    for (i = 0; i < MAX_ALARM_ID; i++) {
        GlobalAlarmAppId[i] = -1;
    }
    for (i = 0; i < MAX_NUM_Resource; i++) {
        GlobalResourceAppID[i] = -1;
    }
    for (i = 0; i < MAX_TIMERS; i++) {
        GlobalTimerAppId[i] = -1;
    }
}