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

In this file all the necessary type defenitions for the status
data types are defined

*/

#ifndef STATUS_DEFINITIONS_H
#define STATUS_DEFINITIONS_H

/* ********************************************************************** */

#include "includes.h"

/* ********************************************************************** */



/* ********************************************************************** */

#define E_OK 100

// defining the error codes for API services according to OSEK
// some services in the OS will be able to return these errors

#define E_OS_ACCESS 1
#define E_OS_CALLLEVEL 2
#define E_OS_ID 3
#define E_OS_LIMIT 4
#define E_OS_NUFUNC 5
#define E_OS_RESOURCE 6
#define E_OS_STATE 7
#define E_OS_VALUE 8
#define E_OS_NOFUNC 9
#define E_OS_LIFO 10
#define E_OS_RESTRICT 11
#define E_OS_PARAM_POINTER 12

/* ********************************************************************** */

#endif