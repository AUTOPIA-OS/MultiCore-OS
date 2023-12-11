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
Syntax: StatusType GetAlarm ( AlarmType <AlarmID>
 TickRefType <Tick>)
Parameter (In):   AlarmID Reference to an alarm

Parameter (Out):  Tick Relative value in ticks before the alarm <AlarmID> expires.

Description:      The system service GetAlarm returns the relative value in ticks
                  before the alarm <AlarmID> expires.

Particularities:  It is up to the application to decide whether for example a
                  CancelAlarm may still be useful. If <AlarmID> is not in use, <Tick> is not defined.
                  Allowed on task level, ISR, and in several hook routines (see Figure 12-1).
Status:

Standard: • No error, E_OK
• Alarm <AlarmID> is not used, E_OS_NOFUNC
Extended: • Alarm <AlarmID> is invalid, E_OS_ID
Conformance: BCC1, BCC2, ECC1, ECC2
#################################################################################################
*/

// [SWS_Os_00640] dGetAlarm shall also work on an Alarm that is bound to another core. (SRS_Os_80013)


StatusType GetAlarm(AlarmType AlarmID, TickRefType Tick) {
  StatusType *status = E_OK;
  uint32_t *flag = 0;

    // multicore migration
    // get application id


    ApplicationType AppID = GetCurrentApplicationID_Kernel();
    
    if (AppID == OS_CORE_ID_MASTER_0) {

      syscall_GetAlarm_TC0(AlarmID, 0, 0, 0, Tick, 0, 0, status, flag);
    }else if (AppID == OS_CORE_ID_1) {
        
      syscall_GetAlarm_TC1(AlarmID, 0, 0, 0, Tick, 0, 0, status, flag);
    }else if (AppID == OS_CORE_ID_2) {//todo:
    }else if (AppID == OS_CORE_ID_3) {//todo:
    }else if (AppID == OS_CORE_ID_4) {//todo:
    }else if (AppID == OS_CORE_ID_5) {//todo:
    }else if (AppID == OS_CORE_ID_6) {//todo:
    }else{}
  return *status;
}

// this is the kernel implementation of GetAlarm
void GetAlarm_Kernel(AlarmType AlarmID, TickRefType Tick, StatusType *status, uint32_t *flag){
  

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
      // Check if AlarmID is valid
      if (Tick == NULL) {
        *status = E_OS_PARAM_POINTER;
      }
      if ((AlarmID < 0) || (AlarmID >= MAX_ALARM_ID)) {
        *status = E_OS_ID;
      } else if (OSApp[AppID].Alarms[AlarmID].INUSE == 0) {
        *status = E_OS_NOFUNC;
      } else {
        if (OSApp[AppID].Counters[OSApp[AppID].Alarms[AlarmID].CounterID].Version == Hardware) {

          *Tick = OSApp[AppID].Alarms[AlarmID].ALARMTIMECOMBINED -
                  OSApp[AppID]
                      .HardwareTimers[OSApp[AppID].Counters[OSApp[AppID].Alarms[AlarmID].CounterID].TimerID]
                      .getABSTIME(AppID);

        } else {
          *Tick = OSApp[AppID].Alarms[AlarmID].ALARMTIMECOMBINED -
                  OSApp[AppID].Counters[OSApp[AppID].Alarms[AlarmID].CounterID].CounterValue;
        }
      }

      // Synch with the other core
      *flag = 1;
  }

}