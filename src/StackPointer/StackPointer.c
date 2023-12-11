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

#include "StackPointer.h"

void Init_Stack_pointer(ApplicationType AppID) {
  
  // get the kernel stack base address
  OSApp[AppID].InterruptStackPointer = (uint32_t)&OSApp[AppID].InterruptStack + (2048U) - (4U);
  WriteInterruptStackPointer(OSApp[AppID].InterruptStackPointer);
}

void WriteInterruptStackPointer(uint32_t address) {
    // TODO: Target HW specific implementation 
}
uint32_t ReadStackInterruptPointer(void) {
  uint32_t ret;
    // TODO: Target HW specific implementation 
  return ret;
}
