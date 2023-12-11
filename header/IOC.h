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

#ifndef IOC_H
#define IOC_H

#include "test_hardware.h"
#include "TaskManager.h"
#include "includes.h"


// Send data to core 1
void IocSend_0 (uint32_t Data);

// Receive data From core 1
void IocReceive_0 (uint32_t* Data);

#endif