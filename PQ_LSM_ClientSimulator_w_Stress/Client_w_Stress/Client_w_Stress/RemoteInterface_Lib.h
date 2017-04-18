//-----------------------------------------------------------------------------
//
//      RemoteInterface_Lib.h
//      © by PicoQuant GmbH, February 2012
//
//-----------------------------------------------------------------------------
//
//  declares the functions exported by SymPhoTime RemoteInterface DLL
//
//-----------------------------------------------------------------------------
//  HISTORY:
//
//  apo  17.02.12   release of the library interface
//  apo  14.01.13   introduced new function "RI_AddLineToLog"
//  apo  20.01.13   introduced new function "RI_EnableLog"
//  apo  03.03.16   introduced new function "RI_RegisterStringHandler"
//
//-----------------------------------------------------------------------------
//

#ifndef   __REMOTEINTERFACE_LIB_H__
  #define __REMOTEINTERFACE_LIB_H__

  #ifndef _WIN32
    #define   __stdcall
  #endif

  #ifdef __CALLED_BY_REMOTEINTERFACE_LIB_CPP__
    #define   _MEMLOC
  #else
    #define   _MEMLOC  extern
  #endif

// #pragma pack(show)
#pragma pack(push)
#pragma pack(1)
// #pragma pack(show)

  typedef struct {
    unsigned char     bMinLo;
    unsigned char     bMinHi;
    unsigned char     bMajLo;
    unsigned char     bMajHi;
  } T_VERSION;

  typedef struct {
    unsigned short    usCount;
    unsigned char     bData;   // let your char*  point to this
    unsigned char     bDummy;
  } T_STRINGSTUB;

  typedef union {
    float             f;
    long int          l;
    unsigned long     ul;
    T_VERSION         v;
    T_STRINGSTUB      arr_chr; 
  } T_OPT_DATA; 
  typedef T_OPT_DATA* TP_OPT_DATA;

#pragma pack(pop)
// #pragma pack(show)


  _MEMLOC HINSTANCE hDLL;                              // Handle to DLL
  _MEMLOC long      InitRemoteInterface_DLL (void);

  //
  // ************************************************************************************************
  // call-back function type
  // ************************************************************************************************
  //
  typedef long (__stdcall *TReceiveNumParamFunc)   (char* pcIdent, float  fValue,  long iRecNr);
  typedef long (__stdcall *TReceiveStrParamFunc)   (char* pcIdent, char*  pcValue, long iRecNr);
  /*
  // prepared for future versions:
  typedef long (__stdcall *TReceiveNumArrParamFunc)(char* pcIdent, int iElemCnt, float* pfValue, long iRecNr); 
  */
  //
  //
  // ************************************************************************************************
  // function footstep types (only used for missing functions)
  // ************************************************************************************************
  //
  typedef long (__stdcall *TLongFuncVoid)                    (void);
  typedef long (__stdcall *TLongFuncPChar)                   (char*);
  typedef long (__stdcall *TLongFuncIntPChar)                (long,  char*);
  typedef long (__stdcall *TLongFunc2PChar)                  (char*, char*);
  typedef long (__stdcall *TLongFuncPCharIntPChar)           (char*, long, char*);
  typedef long (__stdcall *TLongFuncPChar2Int)               (char*, long, long);
  typedef long (__stdcall *TLongFuncPCharFloatInt)           (char*, float, long);
  typedef long (__stdcall *TLongFuncBool)                    (longbool);
  typedef long (__stdcall *TLongFuncBoolNPCBF)               (longbool, TReceiveNumParamFunc);
  typedef long (__stdcall *TLongFuncBool2IntFloatBoolNPCBF)  (longbool, long, long, float, longbool, TReceiveNumParamFunc);
  typedef long (__stdcall *TLongFuncSPCBF)                   (TReceiveStrParamFunc);
  /*
  // prepared for future versions:
  typedef long (__stdcall *TLongFuncNAPCBF)                  (TReceiveNumArrParamFunc);
  */
  //
  //
  // ************************************************************************************************
  // debugging functions
  // ************************************************************************************************
  //
  //__declspec(dllimport)  long __stdcall RI_AssignLogFile     (char* pcLogFileName);
  //__declspec(dllimport)  long __stdcall RI_AddLineToLog      (char* pcNewLine);

  //__declspec(dllimport)  long __stdcall RI_ShowLogWin        (void);
  //__declspec(dllimport)  long __stdcall RI_HideLogWin        (void);
  //__declspec(dllimport)  long __stdcall RI_EnableLog         (longbool bEnableLog);
  //
  _MEMLOC TLongFuncPChar    RI_AssignLogFile;
  _MEMLOC TLongFuncPChar    RI_AddLineToLog;
  _MEMLOC TLongFuncVoid     RI_ShowLogWin; 
  _MEMLOC TLongFuncVoid     RI_HideLogWin; 
  _MEMLOC TLongFuncBool     RI_EnableLog; 
  //
  //
  // ************************************************************************************************
  // initialising and supporting functions
  // ************************************************************************************************
  //
  //__declspec(dllimport)  long __stdcall RI_GetLibVersion          (char* pcLibVersion);
  //__declspec(dllimport)  long __stdcall RI_GetErrorText           (long  iErrCode,    char* pcErrorString);
  //__declspec(dllimport)  long __stdcall RI_GetStatus              (void);
  //__declspec(dllimport)  long __stdcall RI_GetStatusText          (long  iStatusCode, char* pcStatusString);
  //__declspec(dllimport)  long __stdcall RI_Initialize             (char* pcHost,  long  iPort,  char* pcSPTVersion);
  //__declspec(dllimport)  long __stdcall RI_SetOptionalInt         (char* pcIdent, long  iValue, long  iArrIdx);
  //__declspec(dllimport)  long __stdcall RI_SetOptionalFloat       (char* pcIdent, float fValue, long  iArrIdx);
  //__declspec(dllimport)  long __stdcall RI_SetOptionalString      (char* pcIdent, char* pcValue);
  //__declspec(dllimport)  long __stdcall RI_RegisterStringHandler  (TReceiveStrParamFunc StrParamCallbackFunc); 
  /*
  // prepared for future versions:
  //__declspec(dllimport)  long __stdcall RI_RegisterNumArrayHandler(TReceiveNumArrParamFunc NumArrParamCallbackFunc);
  */
  //
  _MEMLOC TLongFuncPChar                 RI_GetLibVersion;
  _MEMLOC TLongFuncIntPChar              RI_GetErrorText;
  _MEMLOC TLongFuncVoid                  RI_GetStatus;
  _MEMLOC TLongFuncIntPChar              RI_GetStatusText;
  _MEMLOC TLongFuncPCharIntPChar         RI_Initialize;
  _MEMLOC TLongFuncPChar2Int             RI_SetOptionalInt;
  _MEMLOC TLongFuncPCharFloatInt         RI_SetOptionalFloat;
  _MEMLOC TLongFunc2PChar                RI_SetOptionalString;
  _MEMLOC TLongFuncSPCBF                 RI_RegisterStringHandler;
  /*
  // prepared for future versions:
  _MEMLOC TLongFuncNAPCBF                RI_RegisterNumArrayHandler;
  */
  //
  //
  // ************************************************************************************************
  // measurement handshake functions
  // ************************************************************************************************
  //
  //__declspec(dllimport)  long __stdcall RI_RequestTimeTrace  (longbool bRecordFile, TReceiveNumParamFunc NumParamCallbackFunc);
  //__declspec(dllimport)  long __stdcall RI_RequestImage      (longbool bRecordFile, long iPixX, long iPixY, float fResol, longbool bBiDirectionalScan, TReceiveNumParamFunc NumParamCallbackFunc);
  //__declspec(dllimport)  long __stdcall RI_RequestStopMeas   (void);
  //
  _MEMLOC TLongFuncBoolNPCBF              RI_RequestTimeTrace;
  _MEMLOC TLongFuncBool2IntFloatBoolNPCBF RI_RequestImage;
  _MEMLOC TLongFuncVoid                   RI_RequestStopMeas; 
  //
#endif // __REMOTEINTERFACE_LIB_H__