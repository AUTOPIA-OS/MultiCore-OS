

#include "BootCore.h"


// [SWS_Os_00677] The function StartCore shall start one core that shall run under the control of the AUTOSAR OS(SRS_Os_80006)
// [SWS_Os_00678] Calls to the StartCore function after StartOS shall return with E_OS_ACCESS and the core shall not be started(SRS_Os_80006)
// [SWS_Os_00606] dThe AUTOSAR specification does not support the activation of  AUTOSAR cores after calling StartOS on that core.
// If StartCore is called after StartOS it shall return with E_OS_ACCESS in extended status.c(SRS_Os_80001)


/*
 [SWS_Os_00627] dAn implementation shall define a set of constants OS_CORE_ID_
 <No> of the type CoreIdType with <No> a value from 0 to OsNumberOfCores-1.c
 (SRS_Os_80001)
 [SWS_Os_00628] dAn implementation shall offer a constant OS_CORE_ID_MASTER of
 the type CoreIdType that refers to the master core.c(SRS_Os_80001)

*/
// [SWS_Os_00625] dThe AUTOSAR Operating System API function GetCoreID shall be callable before StartOS.c(SRS_Os_80006)



CoreType GetCoreID_Kernel() {
   uint32_t coreID; 
  //  coreID = ; 
  // TODO: Target HW specific implementation 
  return coreID;
}

void StartCore(CoreType coreID, StatusType *status) {

  StatusType status = E_OK;

// [SWS_Os_00677] The function StartCore shall start one core that shall run under the control of the AUTOSAR OS(SRS_Os_80006)
  if (coreID > NUMBER_OF_CORES) { 
    status = E_OS_ID;
  } 
  // [SWS_Os_00678] Calls to the StartCore function after StartOS shall return with E_OS_ACCESS and the core shall not be started(SRS_Os_80006)
  else if (OSApp[coreID].OSRunning == 1){  
    status = E_OS_ACCESS;
  
  } 
  // [SWS_Os_00679] If the parameter CoreIDs refers to a core that was already started by the function StartCore the related core is ignored and E_OS_STATE shall be returned(SRS_Os_80006)
  // TODO: Target HW specific implementation 
  // else if (){
  //   return E_OS_STATE;
  // } 
   else {

    // TODO: Add the code to start the core corresponding to the coreID
    // TODO: Target HW specific implementation 

  }

//  [SWS_Os_00681] There is no call to the ErrorHook if an error occurs during StartCore(SRS_Os_80006)
}
