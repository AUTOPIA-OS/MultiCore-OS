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

/* ********************************************************************** */

#ifndef INCLUDES_H
#define INCLUDES_H

/* ********************************************************************** */

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////

/* ********************************************************************** */

#include "RegisterMacros.h"
#include <stdint.h>

/* ********************************************************************** */

typedef int StatusType;
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////


/* ********************************************************************** */

// APIS are backward compatible with OSEK
// [SRS_Os_00097] [SWS_Os_00001]
// The Operating System API shall check in extended mode all pointer arguments 
// for a NULL pointer and return E_OS_PARAM_POINTER in extended status if such 
// an argument is NULL.c
// [SWS_Os_00566] 

/* ********************************************************************** */

// [SWS_Os_00567] The generated part of the OS is derived from a single configuration
// that contains the relevant information for all cores. This implies, that IDs (e.g. TaskID,
// ResourceID, . . . ) are unique across cores. Every ID shall refer exactly to one entity
// independent from the core on which the entity is accessed. This applies also to objects
// that cannot be shared between cores(SRS_Os_80008)

/* ********************************************************************** */


////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////

/* ********************************************************************** */


void initializeArrays();
void IdleTask0(void);
void IdleTask1(void);

/**    Boolean Data Type    */
#define bool int
#define true 1
#define false 0

/* ********************************************************************** */

/**    Maximum number of resources    */
#define MAX_NUM_Resource    (5)
/**    Maximum number of tasks    */
#define MAX_TASK_ID         (10)
/**    Maximum number of Alarms    */
#define MAX_ALARM_ID        (6U)
/**    Maximum number of tasks    */
#define MAXPRIORITY         (MAX_TASK_ID)


/* ********************************************************************** */

/**    Invalid task id    */
#define INVALID_TASK -1

/* ********************************************************************** */

/**    Invalid resource id    */
#define INVALID_RSOURCE 0

/* ********************************************************************** */

/**  Task Manager    */
// Constants of data type TaskStateType for task state .
#define RUNNING (1U)
#define WAITING (2U)
#define READY (3U)
#define SUSPENDED (4U)

/* ********************************************************************** */

/// Constant of attribute version of the task.
#define BASIC 0
#define EXTENDED 1
#define ISR_CAT2 2

/* ********************************************************************** */

/// Constant of attribute preemptivity of the task.
#define FULL 0
#define NON 1

/* ********************************************************************** */

/**  Resource Manager    */
/// Constant of data type ResourceType .
#define STANDARD 1
#define LINKED 2
#define INTERNAL 3

/* ********************************************************************** */

/// ResScheduler resource.
#define RES_SCHEDULER 4

/* ********************************************************************** */

/**    This struct holdes the identifying attributes of a Stack    */
#define STACK_SIZE 100
#define STACK_2k 64
#define STACK_1k 32

/* ********************************************************************** */

/// @brief Defines that the alarm activates a task
#define ACTION_ACTIVATETASK (0U)
/// @brief Defines that the alarm sets an event
#define ACTION_SETEVENT (1U)
/// @brief Defines that the alarm calls a callback routine
#define ACTION_ALARMCALLBACK (2U)

/* ********************************************************************** */

/// @brief Defines that the alarm is not started automatically at system start-up
#define AUTOSTART_FALSE 0
/// @brief Defines that the alarm is started automatically at system start-up
#define AUTOSTART_TRUE 1

/* ********************************************************************** */

/// @brief This defines the maximum counter value of the counter
#define STM_MaxValue (0x00000000FFFFFFFFULL)

/* ********************************************************************** */

/// @brief This defines the maximum number of counters in the system
#define MAX_COUNTERS 4

/* ********************************************************************** */

/// @brief This defines the types of counters in the system
#define Hardware 0
#define Software 1

/* ********************************************************************** */

/// @brief This defines the types of HW timers in the system
#define STM 0
#define GPT1 1

/* ********************************************************************** */

/// @brief This defines the maximum number of timers in the system
#define MAX_TIMERS 2

/* ********************************************************************** */


////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////

/* ********************************************************************** */

/**  Task Manager    */
typedef uint32_t TaskType;                  // This data type identifies a task
typedef uint32_t TaskStateType;             // This data type identifies the state of a task.
typedef TaskType *TaskRefType;              // This data type points to a variable of TaskType.
typedef TaskStateType *TaskStateRefType;    // This data type points to a variable of the data type TaskStateType.

/* ********************************************************************** */

/**  Resource Manager    */
typedef uint32_t ResourceType;              // Data type for a resource.

/* ********************************************************************** */

/**  Event Mechanism    */
typedef uint32_t EventMaskType;             // Data type of the event mask.
typedef EventMaskType *EventMaskRefType;    // Reference to an event mask.

/* ********************************************************************** */

/**  OS EXECUTION CONTROL    */
typedef uint32_t AppModeType;               // Data type of the application mode.

/* ********************************************************************** */

/** Alarms */
/// @brief This data type represents count values in ticks
typedef uint32_t TickType;
/// @brief This data type points to the data type TickType
typedef TickType *TickRefType;
/// @brief This data type represents the identification of an alarm
typedef uint32_t AlarmType;

/**     A COUNTER serves as a base for the ALARM mechanism     */
typedef struct AlarmBaseType {
  /// @brief Smallest allowed value for the cycle-parameter of SetRelAlarm/SetAbsAlarm) (only for systems with extended status).
  TickType MINCYCLE;
  /// @brief The MAXALLOWEDVALUE attribute defines the maximum allowed counter value.
  TickType MAXALLOWEDVALUE;
  /// @brief The TICKSPERBASE attribute specifies the number of ticks required to reach a counterspecific unit. The interpretation is implementation specific
  uint32_t TICKSPERBASE;
} AlarmBaseType;


/// @brief This data type points to the data type AlarmBaseType
typedef AlarmBaseType *AlarmBaseRefType;

/* ********************************************************************** */

/** Counters */
typedef uint32_t CounterType;

/* ********************************************************************** */

/**  Timers */
/// @brief This data type represents the identification of a timer
typedef uint32_t TimerType;

/* ********************************************************************** */

/**  OS Applications */
/// @brief This data type represents the identification of an application
typedef uint32_t ApplicationType;
/// @brief This data type represents the identification of Core
typedef uint32_t CoreType;

/* ********************************************************************** */


////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////


/* ********************************************************************** */

/**    App Modes Types */
enum AppModeType { Defualt = 0, Normal, Sleep, end_of_line_Programming };
// TODO: check this to store different application modes( tentative ) , should we put osdefault here?

/* ********************************************************************** */


////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////


/* ********************************************************************** */


/**    This struct holdes the identifying attributes of a PQNode    */
typedef struct PQNode {
  int index;    // index of the task in the tasks list
  int priority; // priority of the task
} PQNode;

/* ********************************************************************** */

/**    This struct holdes the identifying attributes of a PriorityQueue    */
typedef struct PriorityQueue {
  PQNode nodes[MAX_TASK_ID];
  int size;
} PriorityQueue;

/* ********************************************************************** */

/**    This struct holdes the identifying attributes of a PQNodeTimer    */
typedef struct PQNodeTimer {
  int index;     // index of the task in the tasks list
  uint64_t time; // priority of the task
} PQNodeTimer;

/* ********************************************************************** */

/**    This struct holdes the identifying attributes of a PriorityQueue    */
typedef struct PriorityQueueTimer {
  PQNodeTimer nodes[MAX_ALARM_ID];
  int size;
} PriorityQueueTimer;

/* ********************************************************************** */

typedef struct Stack {
  int nodes[MAX_NUM_Resource];
  int size;
} Stack;

/* ********************************************************************** */

/**    This struct holdes the identifying attributes of an event    */
typedef struct {
  EventMaskType Mask;
  bool Flag;
} Event;

/* ********************************************************************** */

/**    This struct holdes the identifying attributes of a task    */
typedef struct {
  TaskType TaskID;
  TaskStateType TaskState;
 uint32_t SCHEDULE;
  uint32_t VERSION;
  uint32_t PRIORITY;
  uint32_t BASEPRIORITY;
  int ACTIVATION; // Stores remaining posible activations
  int ACTIVATIONMAX;
  void (*TaskEntryPoint)(void); // Points to the function declaration address
  Stack TaskResources; //? may need to check the convention once again
  Stack InternalResoruces;
  EventMaskType Events;
  EventMaskType WaitEvents;
  uint32_t Stack[STACK_2k];
  uint32_t StackPointerBaseAddress;
  uint32_t StackPointer;
  uint32_t PC;
  uint32_t PCXI;
  uint32_t UpperContext[16];
} Task;

/* ********************************************************************** */

/**    This struct holdes the identifying attributes of a Resouce    */
typedef struct {
  ResourceType ResID;
  int resourceProperty;
  uint32_t ceilingPriority;
  int linkedResID;
  bool availability;
  TaskType holdingTaskID;
} Resource;

/* ********************************************************************** */


/* ********************************************************************** */

/**     An ALARM may be used to asynchronously inform or activate a specific task. It is possible to
start ALARMS automatically at system start-up depending on the application mode */
typedef struct ALARM {
  /// @brief This data type represents the identification of an alarm
  AlarmType AlarmID;
  /// @brief The COUNTER reference defines the counter assigned to this alarm.
  AlarmBaseType AlarmBase;
  /// @brief The ACTION attribute defines which type of task notification is used when the alarm expires.
  uint16_t ACTION;
  /// @brief The TASK reference parameter defines the task to be activated when the alarm expires
  TaskType ACTION_TASKID;
  /// @brief  The EVENT reference parameter defines the event to be set when the alarm expires.
  EventMaskType ACTION_EVENTMASK;
  long INUSE;
  /// @brief  The ALARMCALLBACKNAME reference parameter defines the callback routine which is called when the alarm expires.
  void (*ACTION_CALLBACK)(void);
  /// @brief The AUTOSTART attribute defines whether the alarm is started automatically at system start-up.
  uint32_t AUTOSTART;
  uint32_t RightWord;
  uint32_t LeftWord;
  /// @brief The ALARMTIME attribute defines the time in ticks when the alarm expires.
  uint64_t ALARMTIME;
  /// @brief The ALARMTIME attribute defines Tickperbase * Alarmtime.
  uint64_t ALARMTIMECOMBINED;
  /// @brief The CYCLETIME attribute defines the cycle time in ticks of the alarm.
  TickType CYCLETIME;
  /// @brief APPMODE_TYPE  defines the application mode in which the alarm is started automatically.
  AppModeType APPMODE_TYPE;
  CounterType CounterID;
} Alarm;

/* ********************************************************************** */

// Counter
typedef struct Counter {
  CounterType CounterID;
  TickType CounterValue;
  TickType PreviousValue;
  struct PriorityQueueTimer AlarmQueue;
  TickType MaxAllowedValue;
  uint32_t Version;
  TimerType TimerID;
} Counter;

/* ********************************************************************** */

// Hardware Timer
typedef struct HardwareTimer {
  TimerType TimerID;
  CounterType CounterID;
  void (*HandlerEntryPoint)(void);
  void (*InitTimer)(ApplicationType AppID);
  void (*ConfigureTimer)(ApplicationType AppID);
  uint64_t (*getABSTIME)(ApplicationType AppID);
  void (*CancelAlarm)(AlarmType AlarmID, ApplicationType AppID);
  void (*SetAlarm)(AlarmType AlarmID, ApplicationType AppID);
} HardwareTimer;

/* ********************************************************************** */

// OSapplication
typedef struct OSApplication {
  /*    Idle Task Pointer    */
  Task *IdleTask;
  // Tasks
  Task *Tasks;
  /*    Alarms List    */
  struct PriorityQueueTimer STMQueue;
  struct PriorityQueueTimer STMOverflowQueue;
  uint32_t GlobalNumberOfOverflows;
  Alarm Alarms[MAX_ALARM_ID];
  /*    Internal Resources List    */
  Resource InternalResources[MAX_NUM_Resource];
  /*    Resources List    */
  Resource Resources[MAX_NUM_Resource];
  Resource RESSCHEDULER;
  AppModeType OSDEFAULTAPPMODE;
  uint32_t InterruptStack[STACK_2k];
  uint32_t InterruptStackPointer;
  bool OSRunning;
  AppModeType CurrentAppMode;
  uint32_t SUSPEND_COUNTER;
  uint32_t SUSPEND_OS_INTERRUPTS_COUNTER;
  uint32_t ICR_IE_VALUE;
  uint32_t INTERRUPTS_ENABLED;
  Counter Counters[MAX_COUNTERS];
  HardwareTimer HardwareTimers[MAX_COUNTERS];
  struct PriorityQueue ReadyQueue;
  Task *CurrentTask;
    uint32_t volatile CoreSynchronizationFlagOne;
  uint32_t volatile CoreSynchronizationFlagTwo;
} OSApplication;


// CrossCore Parameters
typedef struct CCP{

 uint32_t tin;
 uint32_t flag;
 StatusType *status;
 uint32_t ID;
 TickRefType Tick;
 AlarmBaseRefType Base;
 TickType start;
 TickType cycle;


} CCP;
/* ********************************************************************** */


////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////


/* ********************************************************************** */

/// @brief These are the global mapping arrays to OS IDs
extern int GlobalTaskAppId[MAX_TASK_ID];
extern int GlobalCounterAppId[MAX_COUNTERS];
extern int GlobalAlarmAppId[MAX_ALARM_ID];
extern int GlobalResourceAppID[MAX_NUM_Resource];
extern int GlobalTimerAppId[MAX_TIMERS];

/* ********************************************************************** */

/// @brief These are the global mapping arrays to OS IDs
extern int GlobalTaskAppId[MAX_TASK_ID];
extern int GlobalCounterAppId[MAX_COUNTERS];
extern int GlobalAlarmAppId[MAX_ALARM_ID];
extern int GlobalResourceAppID[MAX_NUM_Resource];
extern int GlobalTimerAppId[MAX_TIMERS];

/* ********************************************************************** */

// Testing extern variables
extern int TestCaseNumber;
extern int TestPassed;
extern int TestCaseIndicator[18];

/* ********************************************************************** */

extern uint32_t Data_Core0_Core1;
/// @brief This is an array of OSApplications
extern OSApplication OSApp[2];


// CrossCore
extern CCP Core0CCP;
extern CCP Core1CCP;

/* ********************************************************************** */


extern Task Tasks[MAX_TASK_ID];

#endif