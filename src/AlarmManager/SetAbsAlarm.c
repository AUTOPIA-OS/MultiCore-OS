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
/*
#################################################################################################
Syntax: StatusType SetAbsAlarm ( AlarmType <AlarmID>, TickType <start>,
TickType <cycle> )
Parameter (In):   AlarmID Reference to the alarm element start Absolute value in ticks
                  cycle Cycle value in case of cyclic alarm. In case of single alarms,
                  cycle shall be zero.

Parameter (Out):  none

Description:      The system service occupies the alarm <AlarmID> element.
                  When <start> ticks are reached, the task assigned to the alarm
                  <AlarmID> is activated or the assigned event (only for extended
                  tasks) is set or the alarm-callback routine is called.
                  Particularities: If the absolute value <start> is very close to the current counter
                  value, the alarm may expire, and the task may become ready or
                  the alarm-callback may be called before the system service
                  returns to the user.
                  If the absolute value <start> already was reached before the
                  system call, the alarm shall only expire when the absolute value
                  <start> is reached again, i.e. after the next overrun of the
                  counter.
                  If <cycle> is unequal zero, the alarm element is logged on again
                  immediately after expiry with the relative value <cycle>.
                  The alarm <AlarmID> shall not already be in use.
                  To change values of alarms already in use the alarm shall be
                  cancelled first.
                  If the alarm is already in use, this call will be ignored and the
                  error E_OS_STATE is returned.
                  Allowed on task level and in ISR, but not in hook routines.
Status:
Standard: • No error, E_OK
• Alarm <AlarmID> is already in use, E_OS_STATE
Extended: • Alarm <AlarmID> is invalid, E_OS_ID
• Value of <start> outside of the admissible counter limit (less
than zero or greater than maxallowedvalue), E_OS_VALUE
• Value of <cycle> unequal to 0 and outside of the admissible
counter limits (less than mincycle or greater than
maxallowedvalue), E_OS_VALUE
Conformance: BCC1, BCC2, ECC1, ECC2; Events only ECC1, ECC2
#################################################################################################
*/
#include "Alarms.h"

// [SWS_Os_00634] dThe AUTOSAR Operating System shall process an Alarm on the
// core on which its corresponding OS-Application resides. (SRS_Os_80018)

// [SWS_Os_00637] dSetAbsAlarm shall also work on an Alarm that is bound to another core. (SRS_Os_80013)
StatusType SetAbsAlarm(AlarmType AlarmID, TickType start, TickType cycle) {
  StatusType status = E_OK;
  

    // multicore migration
    // get application id

    ApplicationType AppID = GetCurrentApplicationID_Kernel();

    if (AppID == OS_CORE_ID_MASTER_0) {

      syscall_SetAbsAlarm_TC0(AlarmID, start, cycle, 0, 0, 0, 0, &status, 0);
    }else if (AppID == OS_CORE_ID_1) {
        
        syscall_SetAbsAlarm_TC1(AlarmID, start, cycle, 0, 0, 0, 0, &status, 0);
    }else if (AppID == OS_CORE_ID_2) {//todo:
    }else if (AppID == OS_CORE_ID_3) {//todo:
    }else if (AppID == OS_CORE_ID_4) {//todo:
    }else if (AppID == OS_CORE_ID_5) {//todo:
    }else if (AppID == OS_CORE_ID_6) {//todo:
    }else{}
  return status;
}

// this is the kernel implementation of SetAbsAlarm
void SetAbsAlarm_Kernel(AlarmType AlarmID, TickType start,
                              TickType cycle, StatusType *status) {

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
      
    
  }
  else{
    if ((AlarmID < 0) || (AlarmID >= MAX_ALARM_ID)) {
      *status = E_OS_ID;
    } else if ((OSApp[AppID].Alarms[AlarmID].INUSE == 1)) {
      *status = E_OS_STATE;
    } else {

        OSApp[AppID].Alarms[AlarmID].INUSE = 1;
        OSApp[AppID].Alarms[AlarmID].CYCLETIME = cycle;
        OSApp[AppID].Alarms[AlarmID].ALARMTIMECOMBINED =
            ((uint64_t)start *
            (uint64_t)OSApp[AppID].Alarms[AlarmID].AlarmBase.TICKSPERBASE);
        if (OSApp[AppID].Counters[OSApp[AppID].Alarms[AlarmID].CounterID].Version == Hardware) {

          OSApp[AppID]
              .HardwareTimers[OSApp[AppID].Counters[OSApp[AppID].Alarms[AlarmID].CounterID].TimerID]
              .SetAlarm(AlarmID, AppID);

        } else {
          // todo: the counter value is 32 bit : problem with 64 bit
          OSApp[AppID].Alarms[AlarmID].ALARMTIMECOMBINED =
            ((uint64_t)start *
            (uint64_t)OSApp[AppID].Alarms[AlarmID].AlarmBase.TICKSPERBASE);
        }
        PriorityQueueTimerPush(
            &OSApp[AppID].Counters[OSApp[AppID].Alarms[AlarmID].CounterID].AlarmQueue, AlarmID,
            OSApp[AppID].Alarms[AlarmID].ALARMTIMECOMBINED);
      }

      // Sync with the other core
    
  }
}