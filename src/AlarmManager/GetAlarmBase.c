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
Syntax: StatusType GetAlarmBase ( AlarmType <AlarmID>,
AlarmBaseRefType <Info> )

Parameter (In):   AlarmID Reference to alarm

Parameter (Out):  Info Reference to structure with constants of the alarm base.


Description:      The system service GetAlarmBase reads the alarm base
                  characteristics. The return value <Info> is a structure in
which the information of data type AlarmBaseType is stored.

Particularities: Allowed on task level, ISR, and in several hook routines (see
Figure 12-1).

Status:
Standard: • No error, E_OK
Extended: • Alarm <AlarmID> is invalid, E_OS_ID
Conformance: BCC1, BCC2, ECC1, ECC2
#################################################################################################
*/

// [SWS_Os_00639] dGetAlarmBase shall also work on an Alarm that is bound to another core.c(SRS_Os_80013)

StatusType GetAlarmBase(AlarmType AlarmID, AlarmBaseRefType Base) {
  StatusType *status = E_OK;
  uint32_t *flag = 0;

    // multicore migration
    // get application id

    ApplicationType AppID = GetCurrentApplicationID_Kernel();
    
    if (AppID == OS_CORE_ID_MASTER_0) {

      syscall_GetAlarmBase_TC0(AlarmID, 0, 0, 0, 0, 0, Base, status, flag);
    }else if (AppID == OS_CORE_ID_1) {
        
        syscall_GetAlarmBase_TC1(AlarmID, 0, 0, 0, 0, 0, Base, status, flag);
    }else if (AppID == OS_CORE_ID_2) {//todo:
    }else if (AppID == OS_CORE_ID_3) {//todo:
    }else if (AppID == OS_CORE_ID_4) {//todo:
    }else if (AppID == OS_CORE_ID_5) {//todo:
    }else if (AppID == OS_CORE_ID_6) {//todo:
    }else{}
  return *status;
}

// this is the kernel implementation of GetAlarmBase
void GetAlarmBase_Kernel(AlarmType AlarmID, AlarmBaseRefType Base, StatusType *status, uint32_t *flag) {
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
      if (Base == NULL) {
        *status = E_OS_PARAM_POINTER;
      }
      if ((AlarmID >= MAX_ALARM_ID) || (AlarmID < 0)) {
        *status = E_OS_ID;
      } else {
        // Fill in the alarm base information
        Base->TICKSPERBASE = OSApp[AppID].Alarms[AlarmID].AlarmBase.TICKSPERBASE;
        Base->MINCYCLE = OSApp[AppID].Alarms[AlarmID].AlarmBase.MINCYCLE;
        Base->MAXALLOWEDVALUE =
            OSApp[AppID].Alarms[AlarmID].AlarmBase.MAXALLOWEDVALUE;
      }

      // Sync with the other core
      *flag = 1;
  }
}