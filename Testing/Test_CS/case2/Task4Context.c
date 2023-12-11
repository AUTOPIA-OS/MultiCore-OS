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

void task4Context(void) {
  int volatile val1 = 22;
  int volatile val2 = 100;
  int volatile x = 10000;
  int volatile z = 7777;
  int volatile flag = 0;

  ActivateTask(8);
  ActivateTask(9);

  int volatile sum = x + z;
  int volatile product = x * z;
  int volatile addition = AddTwoValues(val1, val2);

  if ((sum == 17777) && (product == 77770000) && (addition == 122)) {
    flag = 1;
    TerminateTask();
  } else {
    flag = -1;
    TerminateTask();
  }
}
