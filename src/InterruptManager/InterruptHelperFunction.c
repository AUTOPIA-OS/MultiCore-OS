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

#include "InterruptManager.h"

/** Initialize interrupt Manager */
void InterruptManagerInit(void) {

  ApplicationType AppID = GetCurrentApplicationID_Kernel();
  OSApp[AppID].SUSPEND_COUNTER = 0;
  OSApp[AppID].SUSPEND_OS_INTERRUPTS_COUNTER = 0;
  OSApp[AppID].INTERRUPTS_ENABLED = 0;
  OSApp[AppID].ICR_IE_VALUE = 0;

  // TODO : potentially add hardware initlization here
  return;
}

void GlobalInterruptHandler(void) {
  while (1) {
  }
}

void Cat1_int1(void) {
  while (1) {
  }
}

void ConfigCat2test(void) {
  
  // fire an interrupt 
  return;
}



  void CrossCoreHandler(void){
  ApplicationType AppID = GetCurrentApplicationID_Kernel();


  if (AppID == OS_CORE_ID_MASTER_0) {
    switch (Core0CCP.tin){
          case 0:
      break;
    case 1:
      syscall_ActivateTask_TC0(Core0CCP.ID, 0, 0, 0, 0, 0, 0,  Core0CCP.status,  Core0CCP.flag);
      break;
// other cases should be considered as well
    default:
      break;
    }

  }else if (AppID == OS_CORE_ID_1){

    switch (Core1CCP.tin){
      case 0:
      break;
    case 1:
      syscall_ActivateTask_TC1(Core1CCP.ID, 0, 0, 0, 0, 0, 0,  Core1CCP.status,  Core1CCP.flag);
      break;
// other cases should be considered as well
    default:
      break;
      }


  }

  // todo: return from interrupt

}