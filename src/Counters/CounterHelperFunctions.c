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

  [SWS_Os_00632] dIf an Alarm expires, it shall be allowed to activate a Task on a
  different core.c(SRS_Os_80018)

  [SWS_Os_00633] dIf an Alarm expires, it shall be allowed to set an Event on a
  different core.c(SRS_Os_80018)


*/
void ExecuteAlarmAction(AlarmType AlarmID, StatusType *status) {
  ApplicationType AppID = GetCurrentApplicationID_Kernel();

  OSApp[AppID].Alarms[AlarmID].INUSE = 0;
  if (OSApp[AppID].Alarms[AlarmID].ACTION == ACTION_ACTIVATETASK) {
      StatusType status = E_OK;
        // todo: sync data between cores
        uint32_t flag = E_OK;
    ActivateTask_Kernel(OSApp[AppID].Alarms[AlarmID].ACTION_TASKID, &status, &flag);
  } else if (OSApp[AppID].Alarms[AlarmID].ACTION == ACTION_SETEVENT) {
    uint32_t *flag = 0;
    SetEvent_Kernel(OSApp[AppID].Alarms[AlarmID].ACTION_TASKID,
                    OSApp[AppID].Alarms[AlarmID].ACTION_EVENTMASK, status, flag);
  } else if (OSApp[AppID].Alarms[AlarmID].ACTION == ACTION_ALARMCALLBACK) {
    // todo: cat2 interrupt call back
  } else {
    // Do nothing
  }
}