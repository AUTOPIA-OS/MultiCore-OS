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
StatusType GetElapsedValue (CounterType CounterID,TickRefType Value,TickRefType ElapsedValue
){
    StatusType *status = E_OK;
    uint32_t *flag = 0;

    ApplicationType AppID = GetCurrentApplicationID_Kernel();
    
    if (AppID == OS_CORE_ID_MASTER_0) {
 // todo: initiate system call to the corresponing core and send the correct parameters 
    // todo: such as:
    // syscall_GetElapsedValue_TC0(CounterID, 0, 0, 0, Value, ElapsedValue, 0, status, flag);
    }else if (AppID == OS_CORE_ID_1) {
         // todo: initiate system call to the corresponing core and send the correct parameters 
    // todo: such as:
   //  syscall_GetElapsedValue_TC1(CounterID, 0, 0, 0, Value, ElapsedValue, 0, status, flag);
    }else if (AppID == OS_CORE_ID_2) {//todo:
    }else if (AppID == OS_CORE_ID_3) {//todo:
    }else if (AppID == OS_CORE_ID_4) {//todo:
    }else if (AppID == OS_CORE_ID_5) {//todo:
    }else if (AppID == OS_CORE_ID_6) {//todo:
    }else{}
  return *status;

}

void GetElapsedValue_Kernel (CounterType CounterID,TickRefType Value,TickRefType ElapsedValue, StatusType *status
){
    
    ApplicationType AppID = GlobalCounterAppId[CounterID];
    *status = E_OK;
    if( CounterID > MAX_COUNTERS)
    {
        *status = E_OS_ID;
    }
    else if( *Value > OSApp[AppID].Counters[CounterID].MaxAllowedValue)
    {
        *status = E_OS_VALUE;
    }
    else if(OSApp[AppID].Counters[CounterID].Version == Hardware)
    {
        *ElapsedValue = OSApp[AppID]
              .HardwareTimers[OSApp[AppID].Counters[CounterID].TimerID]
              .getABSTIME(AppID) - *Value;
        *Value = OSApp[AppID]
              .HardwareTimers[OSApp[AppID].Counters[CounterID].TimerID]
              .getABSTIME(AppID);
    }
    else{
        *ElapsedValue = OSApp[AppID].Counters[CounterID].CounterValue - *Value;
        *Value = OSApp[AppID].Counters[CounterID].CounterValue;
    }

}
/*

[SWS_Os_00381] If the input parameter <CounterID> in a call of GetElapsedValue is not valid GetElapsedValue shall return E_OS_ID.
[SWS_Os_00391] If the <Value> in a call of GetElapsedValue is larger than the max allowed value of the <CounterID>, GetElapsedValue shall return E_OS_VALUE.
[SWS_Os_00382] If the input parameters in a call of GetElapsedValue are valid, GetElapsedValue shall return the number of elapsed ticks since the given <Value> value via <ElapsedValue> and shall return E_OK.
[SWS_Os_00460] GetElapsedValue shall return the current tick value of the Counter in the <Value> parameter
[SWS_Os_00534] Availability of GetElapsedValue: Available in all Scalability Classes */