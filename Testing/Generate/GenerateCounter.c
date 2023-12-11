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

void generateCounter(ApplicationType AppID, CounterType CounterID, TimerType TimerID,


                     TickType MaxAllowedValue, uint32_t Version) {


  if(GlobalCounterAppId[CounterID] == -1){
    GlobalCounterAppId[CounterID] = AppID;
  }
  else{
    ShutdownOS_Kernel(OSApp[AppID].OSDEFAULTAPPMODE);
  }
  OSApp[AppID].Counters[CounterID].CounterID = CounterID;
  OSApp[AppID].Counters[CounterID].TimerID = TimerID;
  OSApp[AppID].Counters[CounterID].Version = Version;
  OSApp[AppID].Counters[CounterID].MaxAllowedValue = MaxAllowedValue;
  OSApp[AppID].Counters[CounterID].CounterValue = 0;
  OSApp[AppID].Counters[CounterID].PreviousValue = 0;
  PriorityQueueTimer_init(&OSApp[AppID].Counters[CounterID].AlarmQueue);
  return;
}