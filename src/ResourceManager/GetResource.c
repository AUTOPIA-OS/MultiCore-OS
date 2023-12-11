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
 * 13.4.3.1 GetResource
 * Syntax:     StatusType GetResource ( ResourceType <ResID> )
 *             Parameter (In):
 *             ResID Reference to resource
 *             Parameter (Out): none
 *             Description: This call serves to enter critical sections in the
 *             code that are assigned to the resource referenced by <ResID>.
 *
 *             A critical section
 *             shall always be left using ReleaseResource. Particularities: The
 * OSEK priority ceiling protocol for resource management is described in
 * chapter 8.5. Nested resource occupation is only allowed if the inner critical
 * sections are completely executed within the surrounding critical section
 * (strictly stacked, see chapter 8.2, Restrictions when using resources).
 * Nested occupation of one and the same resource is also forbidden!
 *
 *It is recommended that corresponding calls to GetResource and
 *ReleaseResource appear within the same function.
 *It is not allowed to use services which are points of
 *rescheduling for non preemptable tasks (TerminateTask,
 *ChainTask, Schedule and WaitEvent, see chapter 4.6.2) in
 *critical sections. Additionally, critical sections are to be left
 *before completion of an interrupt service routine.
 *
 *Generally speaking, critical sections should be short.
 *The service may be called from an ISR and from task level (see
 *Figure 12-1).

 * Status:
 *
 * \a Standard: \a
 * * No error, E_OK
 *
 * \a Extended: \a
 * * Resource <ResID> is invalid, E_OS_ID
 * * Attempt to get a resource which is already occupied
 * by any task or ISR, or the statically assigned priority of the calling task
 * or interrupt routine is higher than the calculated ceiling priority,
 *                         E_OS_ACCESS
 * Conformance:
 *             BCC1, BCC2, ECC1, ECC2
 * #################################################################################################
 */

StatusType GetResource(ResourceType ResID) {
  StatusType status = E_OK;
  // todo: sync data between cores

    ApplicationType AppID = GetCurrentApplicationID_Kernel();
    
    if (AppID == OS_CORE_ID_MASTER_0) {
     syscall_GetResource_TC0(ResID, 0, 0, 0, 0, 0, 0, &status, 0);
    }else if (AppID == OS_CORE_ID_1) {
        syscall_GetResource_TC1(ResID, 0, 0, 0, 0, 0, 0, &status, 0);
    }else if (AppID == OS_CORE_ID_2) {//todo:
    }else if (AppID == OS_CORE_ID_3) {//todo:
    }else if (AppID == OS_CORE_ID_4) {//todo:
    }else if (AppID == OS_CORE_ID_5) {//todo:
    }else if (AppID == OS_CORE_ID_6) {//todo:
    }else{}
  return status;
}

// This is the kernel version of the GetResource service
void GetResource_Kernel(ResourceType ResID, StatusType *status) {

  ApplicationType AppID = GetCurrentApplicationID_Kernel();
  *status = E_OK;
  if (ResID >= MAX_NUM_Resource) {
    *status = E_OS_ID;

  } else if (OSApp[AppID].Resources[ResID].availability == false) {
    *status = E_OS_ACCESS;

  } else {
    if (OSApp[AppID].Resources[ResID].ceilingPriority <
        OSApp[AppID].CurrentTask->BASEPRIORITY) {
      *status = E_OS_ACCESS;

    } else {

      if (OSApp[AppID].CurrentTask->PRIORITY <
          OSApp[AppID].Resources[ResID].ceilingPriority) {
        OSApp[AppID].CurrentTask->PRIORITY =
            OSApp[AppID].Resources[ResID].ceilingPriority;
      } else {
      }
      OSApp[AppID].Resources[ResID].holdingTaskID =
          OSApp[AppID].CurrentTask->TaskID;
      OSApp[AppID].Resources[ResID].availability = false;
    }
  }
}