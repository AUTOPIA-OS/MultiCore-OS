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

#include "Alarms.h"

/*
#################################################################################################
Syntax: StatusType CancelAlarm ( AlarmType <AlarmID> )

Parameter (In):   AlarmID Reference to an alarm

Parameter (Out):  none

Description:      The system service cancels the alarm <AlarmID>.

Particularities:  Allowed on task level and in ISR, but not in hook routines.

Status:
Standard: • No error, E_OK
• Alarm <AlarmID> not in use, E_OS_NOFUNC
Extended: • Alarm <AlarmID> is invalid, E_OS_ID
Conformance: BCC1, BCC2, ECC1, ECC2
#################################################################################################
*/

// [SWS_Os_00638] dCancelAlarm shall also work on an Alarm that is bound to another core.c(SRS_Os_80013)

StatusType CancelAlarm(AlarmType AlarmID) {
  StatusType *status = E_OK;
  uint32_t *flag = 0;

  ApplicationType AppID = GetCurrentApplicationID_Kernel();
    
  if (AppID == OS_CORE_ID_MASTER_0) {

    // todo: initiate system call to the corresponing core and send the correct parameters 
    // todo: such as:
    // syscall_CancelAlarm_TC0(AlarmID, 0, 0, 0, 0, 0, 0, status, flag);
  }else if (AppID == OS_CORE_ID_1) {
    // todo: initiate system call to the corresponing core and send the correct parameters 
    // todo: such as:
    // syscall_CancelAlarm_TC1(AlarmID, 0, 0, 0, 0, 0, 0, status, flag);
  }else if (AppID == OS_CORE_ID_2) {
    // todo:
  }else if (AppID == OS_CORE_ID_3) {
    // todo:
  }else if (AppID == OS_CORE_ID_4) {
    // todo:
  }else if (AppID == OS_CORE_ID_5) {
    // todo:
  }else if (AppID == OS_CORE_ID_6) {
    // todo:
  }else{}

  return *status;
}

// this is the kernel implementation of CancelAlarm
void CancelAlarm_Kernel(AlarmType AlarmID, StatusType *status, uint32_t *flag) {

  ApplicationType AppID = GlobalAlarmAppId[AlarmID];
  ApplicationType CurrentAppID = GetCurrentApplicationID_Kernel();
  *status = E_OK;
  if (AppID != CurrentAppID) {
  

      if (AppID == OS_CORE_ID_MASTER_0) {

        // todo: follow the activatetask API cross core example to implement this

      }else if (AppID == OS_CORE_ID_1) {
                // todo: follow the activatetask API cross core example to implement this

      }else if (AppID == OS_CORE_ID_2) {
                // todo: follow the activatetask API cross core example to implement this

      }else if (AppID == OS_CORE_ID_3) {
               // todo: follow the activatetask API cross core example to implement this

      }else if (AppID == OS_CORE_ID_4) {
                // todo: follow the activatetask API cross core example to implement this

      }else if (AppID == OS_CORE_ID_5) {
               // todo: follow the activatetask API cross core example to implement this

      }else if (AppID == OS_CORE_ID_6) {
               // todo: follow the activatetask API cross core example to implement this

      }else{}
      
      while(*flag == 0){
          //synchronize with the other core
      }
  }
  else{
      
    if ((AlarmID >= MAX_ALARM_ID) || (AlarmID < 0)) {
      *status = E_OS_ID;
    } else if (OSApp[AppID].Alarms[AlarmID].INUSE == 0) {
      *status = E_OS_NOFUNC;
    } else {
      if (OSApp[AppID].Counters[OSApp[AppID].Alarms[AlarmID].CounterID].Version == Hardware) {

        OSApp[AppID]
            .HardwareTimers[OSApp[AppID].Counters[OSApp[AppID].Alarms[AlarmID].CounterID].TimerID]
            .CancelAlarm(AlarmID, AppID);

        PqPopElementTimer(
            &OSApp[AppID].Counters[OSApp[AppID].Alarms[AlarmID].CounterID].AlarmQueue,
            AlarmID);
      } else {
        PqPopElementTimer(
            &OSApp[AppID].Counters[OSApp[AppID].Alarms[AlarmID].CounterID].AlarmQueue,
            AlarmID);
      }
      OSApp[AppID].Alarms[AlarmID].INUSE = 0;
    }

    // Synchronize with core
    *flag = 1;

  }
}