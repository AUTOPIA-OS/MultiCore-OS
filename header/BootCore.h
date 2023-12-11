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

#ifndef BOOT_CORE_H
#define BOOT_CORE_H

/* ********************************************************************** */

#include "RegisterMacros.h"
#include "StatusDefinitions.h"
#include "includes.h"

/* ********************************************************************** */


# define NUMBER_OF_CORES 2      
// TODO: Change this to the number of cores in the target HW

#define OS_CORE_ID_MASTER_0 0U
#define OS_CORE_ID_1 1U
// TODO: Add more cores identifiers here


#define CORE_SYNCHRONIZATION_FLAG_ONE_RUN NUMBER_OF_CORES
#define CORE_SYNCHRONIZATION_FLAG_TWO_RUN NUMBER_OF_CORES

/* ********************************************************************** */

CoreType GetCoreID_Kernel();
void StartCore(CoreType coreID, StatusType *status);

/* ********************************************************************** */

#endif /* BOOT_CORE_H */