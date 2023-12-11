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

void generateResource( ResourceType ResID,
                      int resourceProperty, uint32_t ceilingPriority,
                      int linkedResID, bool availability,
                      TaskType holdingTaskID) {
  ApplicationType AppID = GetCurrentApplicationID_Kernel();
  if(GlobalResourceAppID[ResID] == -1){
    GlobalResourceAppID[ResID] = AppID;
  }
  else{
    ShutdownOS_Kernel(OSApp[AppID].OSDEFAULTAPPMODE);
  }
  OSApp[AppID].Resources[ResID].ResID = ResID;
  OSApp[AppID].Resources[ResID].resourceProperty = resourceProperty;
  OSApp[AppID].Resources[ResID].ceilingPriority = ceilingPriority;
  OSApp[AppID].Resources[ResID].linkedResID = linkedResID;
  OSApp[AppID].Resources[ResID].availability = availability;
  OSApp[AppID].Resources[ResID].holdingTaskID = holdingTaskID;
  return;
}
