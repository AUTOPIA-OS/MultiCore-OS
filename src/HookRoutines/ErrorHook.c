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

#include "HookRoutines.h"

/* 13.8.2.1 ErrorHook

   Syntax:             void ErrorHook (StatusType <Error>)

   Parameter (In):     Error: error occurred

   Parameter (Out):    None

   Description:        This hook routine is called by the operating system at the end of a system service which returns StatusType not equal E_OK. It is called before returning to the task level.
                       This hook routine is called when an alarm expires and an error is detected during task activation or event setting.
                       The ErrorHook is not called, if a system service called from ErrorHook does not return E_OK as status value. Any error by calling of system services from the ErrorHook can only be detected by evaluating the status value.

   Particularities:    See chapter 11.1 for general description of hook routines.

   Conformance:        BCC1, BCC2, ECC1, ECC2

*/

void ErrorHook(StatusType Error) {

    ApplicationType AppID = GetCurrentApplicationID_Kernel();
    
    if (AppID == OS_CORE_ID_MASTER_0) {
      // todo: initiate system call to the corresponing core and send the correct parameters 
    // todo: such as:
   //syscall_ErrorHook_TC0(Error, 0, 0, 0, 0, 0, 0, 0, 0);
    }else if (AppID == OS_CORE_ID_1) {  
      // todo: initiate system call to the corresponing core and send the correct parameters 
    // todo: such as:
   //syscall_ErrorHook_TC1(Error, 0, 0, 0, 0, 0, 0, 0, 0);
    }else if (AppID == OS_CORE_ID_2) {//todo:
    }else if (AppID == OS_CORE_ID_3) {//todo:
    }else if (AppID == OS_CORE_ID_4) {//todo:
    }else if (AppID == OS_CORE_ID_5) {//todo:
    }else if (AppID == OS_CORE_ID_6) {//todo:
    }else{}

 }

// This is the Kernel's implementation of the ErrorHook

void ErrorHook_Kernel(StatusType Error) {

#ifdef debug
  while (1) {
  }
#endif

  if ((uint32_t)Error == (uint32_t)E_OS_ACCESS) {

    // TODO

  } else if ((uint32_t)Error == (uint32_t)E_OS_CALLLEVEL)

  {

    // TODO

  }

  else if ((uint32_t)Error == (uint32_t)E_OS_ID)

  {

    // TODO

  }

  else if ((uint32_t)Error == (uint32_t)E_OS_LIMIT)

  {

    // TODO

  }

  else if ((uint32_t)Error == (uint32_t)E_OS_NUFUNC)

  {

    // TODO
  } else if ((uint32_t)Error == (uint32_t)E_OS_RESOURCE)

  {

    // TODO
  } else if ((uint32_t)Error == (uint32_t)E_OS_STATE)

  {

    // TODO
  } else if ((uint32_t)Error == (uint32_t)E_OS_VALUE)

  {

    // TODO
  } else if ((uint32_t)Error == (uint32_t)E_OS_NOFUNC)

  {

    // TODO
  } else if ((uint32_t)Error == (uint32_t)E_OS_LIFO)

  {

    // TODO
  } else if ((uint32_t)Error == (uint32_t)E_OS_RESTRICT)

  {

    // TODO
  } else {
  }
}