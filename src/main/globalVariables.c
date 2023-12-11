#include "includes.h"


int GlobalTaskAppId[MAX_TASK_ID]={{0}};
int GlobalCounterAppId[MAX_COUNTERS]={{0}};
int GlobalAlarmAppId[MAX_ALARM_ID]={{0}};
int GlobalResourceAppID[MAX_NUM_Resource]={{0}};
int GlobalTimerAppId[MAX_TIMERS]={0,0};
// This is a counter for the test case we are currently running 
int TestCaseNumber=0;
int TestPassed=0;
int TestCaseIndicator[18]={{0}};
Task Tasks[MAX_TASK_ID]= {{0}};
OSApplication OSApp[2]={{0}};

// for CrossCoreHandler
CCP Core0CCP={0};
CCP Core1CCP={0};

int TestIOC1Counter = 0;

uint32_t Data_Core0_Core1=0;
