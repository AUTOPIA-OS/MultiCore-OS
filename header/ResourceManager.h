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

#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

/* ********************************************************************** */

#include "StatusDefintions.h"
#include "TaskManager.h"

/* ********************************************************************** */

/*
DeclareResource serves as an external declaration of a resource. The
function and use of this service are similar to that of the external
declaration of variables.
*/
#define DeclareResource(Resourcename) void Resource##Resourcename()

/* ********************************************************************** */

/*    Resource Managment Functions Declarations    */
StatusType GetResource(ResourceType ResID);
StatusType ReleaseResource(ResourceType ResID);

/* ********************************************************************** */

// prototypes for kernel functions
void GetResource_Kernel(ResourceType ResID, StatusType *status);
void ReleaseResource_Kernel(ResourceType ResID, StatusType *status);

/* ********************************************************************** */

#endif