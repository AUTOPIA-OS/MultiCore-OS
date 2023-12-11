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

void task3Context(void) {

  int volatile register length = 10;
  int volatile register width = 20;
  int volatile register height = 30;
  int volatile register expected_volume = 6000;
  int register volatile length1 = 100;
  int register volatile width1 = 200;
  int register volatile height1 = 300;
  int register volatile expected_volume1 = 6000000;
  int register volatile length2 = 1;
  int register volatile width2 = 2;
  int register volatile height2 = 3;
  int register volatile expected_volume2 = 6;
  int register volatile length3 = 7;
  int register volatile width3 = 8;
  int register volatile height3 = 9;
  int register volatile expected_volume3 = 504;
  int register volatile length4 = 6;
  int register volatile width4 = 6;
  int register volatile height4 = 10;
  int register volatile expected_volume4 = 360;
  int register volatile flag = 0;

  ActivateTask(7);

  int register volatile volume = get_volume(length, width, height);
  int register volatile volume1 = get_volume(length1, width1, height1);
  int register volatile volume2 = get_volume(length2, width2, height2);
  int register volatile volume3 = get_volume(length3, width3, height3);
  int register volatile volume4 = get_volume(length4, width4, height4);

  if ((volume == expected_volume) && (volume1 == expected_volume1) &&
      (volume2 == expected_volume2) && (volume3 == expected_volume3) &&
      (volume4 == expected_volume4)) {
    flag = 1;
    TerminateTask();
  } else {
    flag = -1;
    TerminateTask();
  }
}