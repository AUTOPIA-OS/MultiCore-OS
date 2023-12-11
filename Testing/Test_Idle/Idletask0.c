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

void IdleTask0(void) {
  // ActivateTask(1);
  TestPassed = 1;

  switch (TestCaseNumber)
  {
  case 0: // REQ-6: Idle task takes control when no task does
      TestCaseIndicator[TestCaseNumber] = TestPassed;  
      ShutdownOS(E_OS_ACCESS);
    break;
  case 1: // TM1 
    startTestsTM1();
    TestCaseIndicator[TestCaseNumber] = TestPassed;
    ShutdownOS(E_OS_ACCESS);
    break;
  case 2: // TM2
    startTestsTM2();    
    TestCaseIndicator[TestCaseNumber] = TestPassed;
    ShutdownOS(E_OS_ACCESS);
    break;
  case 3: // TM3
    startTestsTM3();  
    TestCaseIndicator[TestCaseNumber] = TestPassed;  
    ShutdownOS(E_OS_ACCESS);
    break;
  case 4: // TM4
    startTestsTM4();
    TestCaseIndicator[TestCaseNumber] = TestPassed;
    ShutdownOS(E_OS_ACCESS);
    break;
  case 5: // TM5
    startTestsTM5();
    TestCaseIndicator[TestCaseNumber] = TestPassed;
    ShutdownOS(E_OS_ACCESS);
    break;
  case 6: // TM6
    startTestsTM6();
    TestCaseIndicator[TestCaseNumber] = TestPassed;
    ShutdownOS(E_OS_ACCESS);
    break;
  case 7: // EM
    startTestsEM1();    
    TestCaseIndicator[TestCaseNumber] = TestPassed;
    ShutdownOS(E_OS_ACCESS);
    break;
  case 8: // EM2
    startTestsEM2();    
    TestCaseIndicator[TestCaseNumber] = TestPassed;
    ShutdownOS(E_OS_ACCESS);
    break;
  case 9: // EM3
    startTestsEM3();  
    TestCaseIndicator[TestCaseNumber] = TestPassed;  
    ShutdownOS(E_OS_ACCESS);
    break;
  case 10: // RM1
    startTestsRM1();
    TestCaseIndicator[TestCaseNumber] = TestPassed;
    ShutdownOS(E_OS_ACCESS);
    break;
  case 11: // RM2
    startTestsRM2();
    TestCaseIndicator[TestCaseNumber] = TestPassed;
    ShutdownOS(E_OS_ACCESS);
    break;
  case 12: // RM3
    startTestsRM3();
    TestCaseIndicator[TestCaseNumber] = TestPassed;
    ShutdownOS(E_OS_ACCESS);
    break;
    // todo: IM1, IM2
  // case 13: // IM1
  //   startTestsIM1();
  //   TestCaseIndicator[TestCaseNumber] = TestPassed;
  //   ShutdownOS(E_OS_ACCESS);
  //   break;
  // case 14: // IM2
  //   startTestsIM2();
  //   TestCaseIndicator[TestCaseNumber] = TestPassed;
  //   ShutdownOS(E_OS_ACCESS);
  //   break;
  case 15: // CNT1
    startTestsCNT1();
    TestCaseIndicator[TestCaseNumber] = TestPassed;
    ShutdownOS(E_OS_ACCESS);
    break;
  case 16: // CNT2
    startTestsCNT2();
    TestCaseIndicator[TestCaseNumber] = TestPassed;
    ShutdownOS(E_OS_ACCESS);
    break;
  case 17: // IOC
    startTestsIOC1();
    TestCaseIndicator[TestCaseNumber] = TestPassed;
    ShutdownOS(E_OS_ACCESS);
  
  default:
      for (;;) {
    }
    break;
  }


}