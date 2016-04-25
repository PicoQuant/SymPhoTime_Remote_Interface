//-----------------------------------------------------------------------------
//
//      RemoteInterface_Lib.cpp
//      © by PicoQuant GmbH, February 2012
//
//-----------------------------------------------------------------------------
//
//  imports the functions exported by SymPhoTime RemoteInterface DLL
//
//-----------------------------------------------------------------------------
//  HISTORY:
//
//  apo  17.02.12   release of the library interface
//  apo  14.01.13   introduced new function "RI_AddLineToLog"
//  apo  20.01.13   introduced new function "RI_EnableLog"
//
//-----------------------------------------------------------------------------
//

#include "stdafx.h"

#define __CALLED_BY_REMOTEINTERFACE_LIB_CPP__

extern "C" {
  #pragma message( "Compiling <RemoteInterface_Def.h> in " __FILE__ )
  #include "RemoteInterface_Def.h"
  #pragma message( "Compiling <RemoteInterface_Lib.h> in " __FILE__ )
  #include "RemoteInterface_Lib.h"
}

#undef  __CALLED_BY_REMOTEINTERFACE_LIB_CPP__


// ************************************************************************************************
// function footstep types (only used for missing functions)
// ************************************************************************************************

long __stdcall LongFuncVoid_missing (void)
{
  return PQ_ERRCODE_UNKNOWN_FUNCTION;
}

long __stdcall LongFuncPChar_missing (char* pc)
{
  strcpy_s (pc, 4, "???");
  return PQ_ERRCODE_UNKNOWN_FUNCTION;
}

long __stdcall LongFuncIntPChar_missing (long, char* pc)
{
  strcpy_s (pc, 4, "???");
  return PQ_ERRCODE_UNKNOWN_FUNCTION;
}

long __stdcall LongFuncPCharIntPChar_missing (char*, long, char* pc)
{
  strcpy_s (pc, 4, "???");
  return PQ_ERRCODE_UNKNOWN_FUNCTION;
}

long __stdcall LongFuncPChar2Int_missing (char*, long, long)
{
  return PQ_ERRCODE_UNKNOWN_FUNCTION;
}

long __stdcall LongFuncPCharFloatInt_missing (char*, float, long)
{
  return PQ_ERRCODE_UNKNOWN_FUNCTION;
}

long __stdcall LongFunc2PChar_missing (char*, char*)
{
  return PQ_ERRCODE_UNKNOWN_FUNCTION;
}

long __stdcall LongFuncBool_missing (longbool)
{
  return PQ_ERRCODE_UNKNOWN_FUNCTION;
}

long __stdcall LongFuncBoolPCBF_missing (longbool, TReceiveParamFunc)
{
  return PQ_ERRCODE_UNKNOWN_FUNCTION;
}

long __stdcall LongFuncBool2IntFloatBoolPCBF_missing (longbool, long, long, float, longbool, TReceiveParamFunc)
{
  return PQ_ERRCODE_UNKNOWN_FUNCTION;
}



// ************************************************************************************************
// function to initialise the DLL (call this to initialise the pointers to the DLL functions)
// ************************************************************************************************

long InitRemoteInterface_DLL (void)
{
  long lRet = PQ_ERRCODE_NO_ERROR;

  OutputDebugString(L"Loading RemoteInterface.dll");
  hDLL = LoadLibrary (L"RemoteInterface.dll");
  if (hDLL != NULL)
  {
    OutputDebugString(L"RemoteInterface.dll loaded successfully");
    //
    //
    // ************************************************************************************************
    // debugging functions
    // ************************************************************************************************
    //
    RI_AssignLogFile = (TLongFuncPChar) GetProcAddress (hDLL, "RI_AssignLogFile");
    if (! RI_AssignLogFile)
    {
      lRet = PQ_ERRCODE_UNKNOWN_FUNCTION;
      RI_AssignLogFile = (TLongFuncPChar) LongFuncPChar_missing;       
    }
    //
    RI_AddLineToLog = (TLongFuncPChar) GetProcAddress (hDLL, "RI_AddLineToLog");
    if (! RI_AddLineToLog)
    {
      lRet = PQ_ERRCODE_UNKNOWN_FUNCTION;
      RI_AddLineToLog = (TLongFuncPChar) LongFuncPChar_missing;       
    }
    //
    RI_ShowLogWin = (TLongFuncVoid) GetProcAddress (hDLL, "RI_ShowLogWin");
    if (! RI_ShowLogWin)
    {
      lRet = PQ_ERRCODE_UNKNOWN_FUNCTION;
      RI_ShowLogWin = (TLongFuncVoid) LongFuncVoid_missing;       
    }
    //
    RI_HideLogWin = (TLongFuncVoid) GetProcAddress (hDLL, "RI_HideLogWin");
    if (! RI_HideLogWin)
    {
      lRet = PQ_ERRCODE_UNKNOWN_FUNCTION;
      RI_HideLogWin = (TLongFuncVoid) LongFuncVoid_missing;       
    }
    //
    RI_EnableLog = (TLongFuncBool) GetProcAddress (hDLL, "RI_EnableLog");
    if (! RI_EnableLog)
    {
      lRet = PQ_ERRCODE_UNKNOWN_FUNCTION;
      RI_EnableLog = (TLongFuncBool) LongFuncBool_missing;       
    }
    //
    //
    // ************************************************************************************************
    // initialising and supporting functions
    // ************************************************************************************************
    //
    RI_GetLibVersion = (TLongFuncPChar) GetProcAddress (hDLL, "RI_GetLibVersion");
    if (! RI_GetLibVersion)
    {
      lRet = PQ_ERRCODE_UNKNOWN_FUNCTION;
      RI_GetLibVersion = (TLongFuncPChar) LongFuncPChar_missing;       
    }
    //
    RI_GetErrorText = (TLongFuncIntPChar) GetProcAddress (hDLL, "RI_GetErrorText");
    if (! RI_GetErrorText)
    {
      lRet = PQ_ERRCODE_UNKNOWN_FUNCTION;
      RI_GetErrorText = (TLongFuncIntPChar) LongFuncIntPChar_missing;       
    }
    //
    RI_GetStatus = (TLongFuncVoid) GetProcAddress (hDLL, "RI_GetStatus");
    if (! RI_GetStatus)
    {
      lRet = PQ_ERRCODE_UNKNOWN_FUNCTION;
      RI_GetStatus = (TLongFuncVoid) LongFuncVoid_missing;       
    }
    //
    RI_GetStatusText = (TLongFuncIntPChar) GetProcAddress (hDLL, "RI_GetStatusText");
    if (! RI_GetStatusText)
    {
      lRet = PQ_ERRCODE_UNKNOWN_FUNCTION;
      RI_GetStatusText = (TLongFuncIntPChar) LongFuncIntPChar_missing;       
    }
    //
    RI_Initialize = (TLongFuncPCharIntPChar) GetProcAddress (hDLL, "RI_Initialize");
    if (! RI_Initialize)
    {
      lRet = PQ_ERRCODE_UNKNOWN_FUNCTION;
      RI_Initialize = (TLongFuncPCharIntPChar) LongFuncPCharIntPChar_missing;       
    }
    //
    RI_SetOptionalInt = (TLongFuncPChar2Int) GetProcAddress (hDLL, "RI_SetOptionalInt");
    if (! RI_SetOptionalInt)
    {
      lRet = PQ_ERRCODE_UNKNOWN_FUNCTION;
      RI_SetOptionalInt = (TLongFuncPChar2Int) LongFuncPChar2Int_missing;       
    }
    //
    RI_SetOptionalFloat = (TLongFuncPCharFloatInt) GetProcAddress (hDLL, "RI_SetOptionalFloat");
    if (! RI_SetOptionalFloat)
    {
      lRet = PQ_ERRCODE_UNKNOWN_FUNCTION;
      RI_SetOptionalFloat = (TLongFuncPCharFloatInt) LongFuncPCharFloatInt_missing;       
    }
    //
    RI_SetOptionalString = (TLongFunc2PChar) GetProcAddress (hDLL, "RI_SetOptionalString");
    if (! RI_SetOptionalString)
    {
      lRet = PQ_ERRCODE_UNKNOWN_FUNCTION;
      RI_SetOptionalString = (TLongFunc2PChar) LongFunc2PChar_missing;       
    }
    //
    //
    // ************************************************************************************************
    // measurement handshake functions
    // ************************************************************************************************
    //
    RI_RequestTimeTrace = (TLongFuncBoolPCBF) GetProcAddress (hDLL, "RI_RequestTimeTrace");
    if (! RI_RequestTimeTrace)
    {
      lRet = PQ_ERRCODE_UNKNOWN_FUNCTION;
      RI_RequestTimeTrace = (TLongFuncBoolPCBF) LongFuncBoolPCBF_missing;       
    }
    //
    RI_RequestImage = (TLongFuncBool2IntFloatBoolPCBF) GetProcAddress (hDLL, "RI_RequestImage");
    if (! RI_RequestImage)
    {
      lRet = PQ_ERRCODE_UNKNOWN_FUNCTION;
      RI_RequestImage = (TLongFuncBool2IntFloatBoolPCBF) LongFuncBool2IntFloatBoolPCBF_missing;       
    }
    //
    RI_RequestStopMeas = (TLongFuncVoid) GetProcAddress (hDLL, "RI_RequestStopMeas");
    if (! RI_RequestStopMeas)
    {
      lRet = PQ_ERRCODE_UNKNOWN_FUNCTION;
      RI_RequestStopMeas = (TLongFuncVoid) LongFuncVoid_missing;       
    }
    //
  }
  else
  {
    OutputDebugString(L"RemoteInterface.dll not loaded");
    lRet = PQ_ERRCODE_DLL_NOT_FOUND;
  }
  //
  return lRet;
}

