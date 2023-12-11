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

#include "Counter.h"


StatusType GetCounterValue (CounterType CounterID,TickRefType Value){

    StatusType *status = E_OK;
    uint32_t *flag = 0;

    ApplicationType AppID = GetCurrentApplicationID_Kernel();
    
    if (AppID == OS_CORE_ID_MASTER_0) {
         // todo: initiate system call to the corresponing core and send the correct parameters 
    // todo: such as:
    // syscall_GetCounterValue_TC0(CounterID, 0, 0, 0, Value, 0, 0, status, flag);
    }else if (AppID == OS_CORE_ID_1) {
         // todo: initiate system call to the corresponing core and send the correct parameters 
    // todo: such as:
    // syscall_GetCounterValue_TC1(CounterID, 0, 0, 0, Value, 0, 0, status, flag);
    }else if (AppID == OS_CORE_ID_2) {//todo:
    }else if (AppID == OS_CORE_ID_3) {//todo:
    }else if (AppID == OS_CORE_ID_4) {//todo:
    }else if (AppID == OS_CORE_ID_5) {//todo:
    }else if (AppID == OS_CORE_ID_6) {//todo:
    }else{}
  return *status;
}

void GetCounterValue_Kernel (CounterType CounterID,TickRefType Value, StatusType *status){
    
    ApplicationType AppID = GlobalCounterAppId[CounterID];
    *status = E_OK;
    if( CounterID > MAX_COUNTERS)
    {
        *status = E_OS_ID;
    }
    else if(OSApp[AppID].Counters[CounterID].Version == Hardware)
    {
        *Value = OSApp[AppID]
              .HardwareTimers[OSApp[AppID].Counters[CounterID].TimerID]
              .getABSTIME(AppID);
        OSApp[AppID].Counters[CounterID].PreviousValue = *Value;
    }
    else{
        *Value = OSApp[AppID].Counters[CounterID].CounterValue;
        OSApp[AppID].Counters[CounterID].PreviousValue = *Value; 
    }
}
/*
[SWS_Os_00376] dIf the input parameter <CounterID> in a call of GetCounterValue is not valid, GetCounterValue shall return E_OS_ID.c()
[SWS_Os_00377] dIf the input parameter <CounterID> in a call of GetCounterValue is valid, GetCounterValue shall return the current tick value of the Counter via <Value> and return E_OK.c(SRS_Frt_00033)
[SWS_Os_00531] dCaveats of GetCounterValue: Note that for counters of OsCounterType = HARDWARE the real timer value (the - possibly adjusted - hardware
value, see [SWS_Os_00384]) is returned, whereas for counters of OsCounterType =
SOFTWARE the current "software" tick value is returned.c()
[SWS_Os_00532] dAvailability of GetCounterValue: Available in all Scalability Classes
*/