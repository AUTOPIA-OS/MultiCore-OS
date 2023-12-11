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

/*

  [SWS_Os_00285] dIf the input parameter <CounterID> in a call of IncrementCounter is not valid OR the Counter is a hardware Counter,
  IncrementCountershall return E_OS_ID.c()

  [SWS_Os_00286] dIf the input parameter of IncrementCounter is valid, IncrementCounter shall increment the Counter <CounterID> 
  by one (if any alarm connected to this Counter expires, the given action, e.g. Task activation, is done) and
  shall return E_OK.c(SRS_Os_11020)

  [SWS_Os_00321] dIf in a call of IncrementCounter an error happens during the
  execution of an alarm action, e.g. E_OS_LIMIT caused by a Task activation, IncrementCounter shall call the error hook(s), 
  but the IncrementCounter service itself shall return E_OK. ()

  [SWS_Os_00629] dA Counter belonging to an OS-Application shall be incremented
  by the core on which the OS-Application resides. The Counter shall not be incremented by other cores.c(SRS_Os_80013)


*/


StatusType IncrementCounter(CounterType CounterID) {
  StatusType status = E_OK;

    // multicore migration
    // get application id


    ApplicationType AppID = GetCurrentApplicationID_Kernel();
    
    if (AppID == OS_CORE_ID_MASTER_0) {
       // todo: initiate system call to the corresponing core and send the correct parameters 
    // todo: such as:
      // syscall_IncrementCounter_TC0(CounterID, 0, 0, 0, 0, 0, 0, &status, 0);
    }else if (AppID == OS_CORE_ID_1) {
         // todo: initiate system call to the corresponing core and send the correct parameters 
    // todo: such as:
       //  syscall_IncrementCounter_TC0(CounterID, 0, 0, 0, 0, 0, 0, &status, 0);
    }else if (AppID == OS_CORE_ID_2) {//todo:
    }else if (AppID == OS_CORE_ID_3) {//todo:
    }else if (AppID == OS_CORE_ID_4) {//todo:
    }else if (AppID == OS_CORE_ID_5) {//todo:
    }else if (AppID == OS_CORE_ID_6) {//todo:
    }else{}
  return status;
}

void IncrementCounter_Kernel(CounterType CounterID, StatusType *status) { // [SWS_Os_00301]
  ApplicationType AppID = GetCurrentApplicationID_Kernel();

  if(AppID != GlobalCounterAppId[CounterID]){
    *status = E_OS_ACCESS;
    return;
  }
  else{
  }

  *status = E_OK;
  if (CounterID > MAX_COUNTERS) {
    *status = E_OS_ID;
  } else if (OSApp[AppID].Counters[CounterID].Version == Hardware) {
    *status = E_OS_ID;
  } else {
    OSApp[AppID].Counters[CounterID].CounterValue++;

    Alarm *currentAlarm =
        &OSApp[AppID].Alarms[PqGetRootTimer(&OSApp[AppID].Counters[CounterID].AlarmQueue)];
    while (OSApp[AppID].Counters[CounterID].AlarmQueue.size &&
           (currentAlarm->ALARMTIMECOMBINED ==
            OSApp[AppID].Counters[CounterID].CounterValue)) {
      ExecuteAlarmAction(currentAlarm->AlarmID, status);
      PqPopTimer(&OSApp[AppID].Counters[CounterID].AlarmQueue);

      if (currentAlarm->CYCLETIME != (0U)) {

        currentAlarm->ALARMTIMECOMBINED +=
            (uint64_t)currentAlarm->CYCLETIME *
            (uint64_t)currentAlarm->AlarmBase.TICKSPERBASE;

        currentAlarm->INUSE = 1;
        PriorityQueueTimerPush(&OSApp[AppID].Counters[CounterID].AlarmQueue,
                               currentAlarm->AlarmID,
                               currentAlarm->ALARMTIMECOMBINED);
      }

      currentAlarm =
          &OSApp[AppID].Alarms[PqGetRootTimer(&OSApp[AppID].Counters[CounterID].AlarmQueue)];
    }
    
  }
}