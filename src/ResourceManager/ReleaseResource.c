
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

#include "ResourceManager.h"

/**
 * #################################################################################################
 * Syntax: StatusType ReleaseResource ( ResourceType <ResID> )
 * Parameter (In):
 * ResID Reference to resource
 * Parameter (Out): none
 * Description: ReleaseResource is the counterpart of GetResource and
 * serves to leave critical sections in the code that are assigned to
 * the resource referenced by <ResID>.
 *
 * Particularities: For information on nesting conditions, see particularities of
 *
 * GetResource.
 * The service may be called from an ISR and from task level (see
 * Figure 12-1).
 *
 * Status:
 *
 * \a Standard: \a
 * * No error, E_OK
 *
 * \a Extended: \a
 * * Resource <ResID> is invalid, E_OS_ID
 *
 * • Attempt to release a resource which is not occupied by any task
 * or ISR, or another resource shall be released before,
 * E_OS_NOFUNC
 * • Attempt to release a resource which has a lower ceiling priority
 * than the statically assigned priority of the calling task or
 * interrupt routine, E_OS_ACCESS
 *
 * Conformance: BCC1, BCC2, ECC1, ECC2
 * #################################################################################################
 */

StatusType ReleaseResource(ResourceType ResID) {
  StatusType status = E_OK;
  // todo: sync data between cores
  

    ApplicationType AppID = GetCurrentApplicationID_Kernel();
    
    if (AppID == OS_CORE_ID_MASTER_0) {
        syscall_ReleaseResource_TC0(ResID, 0, 0, 0, 0, 0, 0, &status, 0);
    }else if (AppID == OS_CORE_ID_1) {
        syscall_ReleaseResource_TC1(ResID, 0, 0, 0, 0, 0, 0, &status, 0);
    }else if (AppID == OS_CORE_ID_2) {//todo:
    }else if (AppID == OS_CORE_ID_3) {//todo:
    }else if (AppID == OS_CORE_ID_4) {//todo:
    }else if (AppID == OS_CORE_ID_5) {//todo:
    }else if (AppID == OS_CORE_ID_6) {//todo:
    }else{}
  return status;
}

// This is the kernel version of the ReleaseResource service
void ReleaseResource_Kernel(ResourceType ResID, StatusType *status) {

  ApplicationType AppID = GetCurrentApplicationID_Kernel();
  *status = E_OK;
  if (ResID >= MAX_NUM_Resource) {
    *status = E_OS_ID;

  } else if (OSApp[AppID].Resources[ResID].holdingTaskID !=
             OSApp[AppID].CurrentTask->TaskID) {
    *status = E_OS_ID;
  }
  // Resource is not occupied by any task or ISR
  else if (OSApp[AppID].Resources[ResID].holdingTaskID == 0) {
    *status = E_OS_NOFUNC;
  }
  // Attempt to release a resource which has a lower ceiling priority
  else if (OSApp[AppID].Resources[ResID].ceilingPriority <
           OSApp[AppID].CurrentTask->BASEPRIORITY) {
    *status = E_OS_ACCESS;
  } else {

    // Resource is available
    OSApp[AppID].Resources[ResID].availability = true;
    // Resource is not occupied by any task or ISR
    OSApp[AppID].Resources[ResID].holdingTaskID = 0;

    // Check if task is holding another resource
    // If it is holding another resource then change the priority to the ceiling priority of the resource
    // If it is not holding another resource then change the priority to the original priority of the task
    double maxCeilingPriority = OSApp[AppID].CurrentTask->BASEPRIORITY;
    for (uint32_t i = 0; i < MAX_NUM_Resource; i++) {
      if (OSApp[AppID].Resources[i].holdingTaskID ==
          OSApp[AppID].CurrentTask->TaskID) {
        if (OSApp[AppID].Resources[i].ceilingPriority > maxCeilingPriority) {
          maxCeilingPriority = OSApp[AppID].Resources[i].ceilingPriority;
        }
      }
    }
    OSApp[AppID].CurrentTask->PRIORITY = maxCeilingPriority;

    if (OSApp[AppID].CurrentTask->SCHEDULE == FULL)
    {
      Schedule_Kernel(status);
    }
  }

}