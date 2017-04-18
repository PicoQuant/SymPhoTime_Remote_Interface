unit RemoteInterfaceImportUnit;

interface

const
  LIB_VERSION_REFERENCE                   =  '1.0.9.';                     // actually the version string is longer,
  //                                                                       // but compare first n=6 characters only!
  STP_RI_VERSIONSTRING_MAXLEN             =       31;
  STP_RI_FILENAME_MAXLEN                  =      255;
  STP_RI_GROUPNAME_MAXLEN                 =       63;
  STP_RI_OPT_DATATYPE_NAME_MAXLEN         =       30;
  STP_RI_ERRORTEXT_MAXLEN                 =       63;
  STP_RI_STATUSTEXT_MAXLEN                =       31;
  //
  PQ_OPT_INFONAME_FILENAME                = 'Filename';                    // string (max. length = 255 chars.)
  PQ_OPT_INFONAME_GROUPNAME               = 'Groupname';                   // string (max. length =  63 chars.)
  PQ_OPT_INFONAME_OBJECTIVE               = 'Objective';                   // string
  PQ_OPT_INFONAME_PINHOLE                 = 'Pinhole';                     // string
  PQ_OPT_INFONAME_MAJOR_DICHROIC          = 'MajorDichroic';               // string
  PQ_OPT_INFONAME_COMMENT                 = 'Comment';                     // string
  PQ_OPT_INFONAME_TIME_PER_PIXEL          = 'TimePerPixel';                // float
  PQ_OPT_INFONAME_TIME_PER_IMAGE          = 'TimePerImageEstimated';       // float
  PQ_OPT_INFONAME_TIMESTAMP_ARRAY         = 'TimeStampArray';              // array of floats
  PQ_OPT_INFONAME_LASERREPRATE            = 'LaserRepetitionRate';         // integer [Hz]; will be set to next lower possible
  PQ_OPT_INFONAME_LASERPULSEPATTERN       = 'LaserPulsePatternIndex';      // integer; 0="Standard", 1="PIE", ...; see also script "SepiaPanel.stups"
  PQ_OPT_INFONAME_LASERON_ARRAY           = 'LaserOn';                     // integer array: 0=false, 1=true
  PQ_OPT_INFONAME_LASERINTENS_ARRAY       = 'LaserIntensity';              // float array [%]; although SPT64 only rounds to whole percent, ...
  //
  PQ_OPT_DATANAME_SPT_VERSION             = 'ServerVersion';               // use T_OPT_DATA to decode version
  PQ_OPT_DATANAME_CH1_COUNTS_PER_MOLECULE = 'cpm1';                        // float
  PQ_OPT_DATANAME_CH2_COUNTS_PER_MOLECULE = 'cpm2';                        // float
  PQ_OPT_DATANAME_CH1_COUNTS_PER_SECOND   = 'cps1';                        // ulong
  PQ_OPT_DATANAME_CH2_COUNTS_PER_SECOND   = 'cps2';                        // ulong
  PQ_OPT_DATANAME_DET1_COUNTS_PER_SECOND  = 'det1';                        // ulong
  PQ_OPT_DATANAME_DET2_COUNTS_PER_SECOND  = 'det2';                        // ulong
  PQ_OPT_DATANAME_DET3_COUNTS_PER_SECOND  = 'det3';                        // ulong
  PQ_OPT_DATANAME_DET4_COUNTS_PER_SECOND  = 'det4';                        // ulong
  PQ_OPT_DATANAME_MAX_COUNTS_PER_PIXEL    = 'maxcpp';                      // ulong
  PQ_OPT_DATANAME_RESULTINGFILENAME       = 'ResultingFilename';           // string;  sent if Filename contains symbolic constants
  PQ_OPT_DATANAME_RESULTINGGROUPNAME      = 'ResultingGroupname';          // string;  sent if Groupname contains symbolic constants
  PQ_OPT_DATANAME_RESULTINGLASERREPRATE   = 'ResultingLaserRepetitionRate';// integer; sent if RepRate differs from 'LaserRepetitionRate'
  PQ_OPT_DATANAME_LASERNAME               = 'LaserName';                   // comparision template
  PQ_OPT_DATANAME_LASERNAME1              = 'LaserName1';                  // string
  PQ_OPT_DATANAME_LASERNAME2              = 'LaserName2';                  // string
  PQ_OPT_DATANAME_LASERNAME3              = 'LaserName3';                  // string
  PQ_OPT_DATANAME_LASERNAME4              = 'LaserName4';                  // string
  PQ_OPT_DATANAME_LASERNAME5              = 'LaserName5';                  // string
  PQ_OPT_DATANAME_LASERNAME6              = 'LaserName6';                  // string
  PQ_OPT_DATANAME_LASERNAME7              = 'LaserName7';                  // string
  PQ_OPT_DATANAME_LASERNAME8              = 'LaserName8';                  // string


type
  E_OPT_DATA_TYPES                        = (PQ_OPT_DATATYPE_FLOAT               =    $00,
                                             PQ_OPT_DATATYPE_LONG                =    $01,
                                             PQ_OPT_DATATYPE_ULONG               =    $02,
                                             PQ_OPT_DATATYPE_REC_VERSION         =    $07,
                                             PQ_OPT_DATATYPE_FIXED_LENGTH_STRING =    $FF);

  T_OPT_DATA                              = packed record
                                              case E_OPT_DATA_TYPES of
                                                PQ_OPT_DATATYPE_FLOAT               : ( f       : single );
                                                PQ_OPT_DATATYPE_LONG                : ( il      : LongInt );
                                                PQ_OPT_DATATYPE_ULONG               : ( ul      : LongWord );
                                                PQ_OPT_DATATYPE_REC_VERSION         : ( bMinLo  : byte;
                                                                                        bMinHi  : byte;
                                                                                        bMajLo  : byte;
                                                                                        bMajHi  : byte   );
                                                PQ_OPT_DATATYPE_FIXED_LENGTH_STRING : ( usCount : word;
                                                                                        bData   : byte;  ); // just to get an address
                                            end;


  {$Z1} // values are byte
    E_STOP_REASONS                        = (PQ_STOP_REASON_CONTINUE_OK          =     0,
                                             PQ_STOP_REASON_FINISHED_OK          =     1,
                                             PQ_STOP_REASON_USER_BREAK           =     2,
                                             PQ_STOP_REASON_ERROR                =     3);

  {$Z2} // values are SmallInt
    E_ERROR_CODES                         = (PQ_ERRCODE_NO_ERROR                 =     0,
                                             PQ_ERRCODE_MEASUREMENT_READY        =     1,
                                             PQ_ERRCODE_USER_BREAK               =     2,
                                             PQ_ERRCODE_MEASUREMENT_TERMINATING  =     3,
                                             PQ_ERRCODE_REDEFINED_PARAM          =     4,
                                             PQ_ERRCODE_UNKNOWN_PARAM            =     5,
                                             PQ_ERRCODE_FUNCTION_BLOCKED         =     9,
                                             PQ_ERRCODE_MESSAGE_CORRUPTED        =    -1,
                                             PQ_ERRCODE_SERVER_BUSY              =    -2,
                                             PQ_ERRCODE_MESSAGE_TIMEOUT          =    -3,
                                             PQ_ERRCODE_TYPE_MISMATCH            =    -7,
                                             PQ_ERRCODE_INVALID_REC_VERSION      =   -10,
                                             PQ_ERRCODE_MEASUREMENT_TIMEOUT      =  -100,
                                             PQ_ERRCODE_FIFO_OVERRUN             =  -101,
                                             PQ_ERRCODE_DMA_ERROR                =  -102,
                                             PQ_ERRCODE_OSCILLOSCOPE_RUNNING     =  -103,
                                             PQ_ERRCODE_HARDWARE_INIT            =  -104,
                                             PQ_ERRCODE_TTTR_INIT                =  -105,
                                             PQ_ERRCODE_TTTR_RUNNING             =  -106,
                                             PQ_ERRCODE_NO_WORKSPACE             =  -107,
                                             PQ_ERRCODE_FILE_EXISTS              =  -108,
                                             PQ_ERRCODE_FILE_CREATE              =  -109,
                                             PQ_ERRCODE_GROUPNAME_TOO_LONG       =  -110,
                                             PQ_ERRCODE_FILENAME_TOO_LONG        =  -111,
                                             PQ_ERRCODE_TIMESTAMP_ARRAY_TOO_LONG =  -112,
                                             PQ_ERRCODE_OPEN_LOGFILE_FAILED      =  -113,
                                             PQ_ERRCODE_MEASUREMENT_RUNNING      =  -114,
                                             PQ_ERRCODE_NO_MEASUREMENT_RUNNING   =  -115,
                                             PQ_ERRCODE_INVALID_PARAMETERNAME    =  -116,
                                             PQ_ERRCODE_UNSUPPORTED_MEASUREMENT  =  -117,
                                             PQ_ERRCODE_SERVER_NOT_INITIALISED   =  -118,
                                             PQ_ERRCODE_TCSPCSYSTEM_ERROR        =  -119,
                                             PQ_ERRCODE_MEMORY_ACCESS_ERROR      =  -120,
                                             PQ_ERRCODE_CLIENT_NOT_INITIALISED   =  -121,
                                             PQ_ERRCODE_HARDWARE_NOT_AVAILABLE   =  -122,
                                             PQ_ERRCODE_INVALID_LICENSE          =  -999,
                                             PQ_ERRCODE_HANDSHAKE_ERROR          = -1000,
                                             PQ_ERRCODE_GENERAL_SOCKET_ERROR     = -1100,
                                             PQ_ERRCODE_SOCKET_ERROR_SEND        = -1101,
                                             PQ_ERRCODE_SOCKET_ERROR_RECEIVE     = -1102,
                                             PQ_ERRCODE_SOCKET_ERROR_CONNECT     = -1103,
                                             PQ_ERRCODE_SOCKET_ERROR_DISCONNECT  = -1104,
                                             PQ_ERRCODE_SOCKET_ERROR_ACCEPT      = -1105,
                                             PQ_ERRCODE_SOCKET_ERROR_LOOKUP      = -1106,
                                             PQ_ERRCODE_DLL_NOT_FOUND            = -9100,
                                             PQ_ERRCODE_UNKNOWN_FUNCTION         = -9110,
                                             PQ_ERRCODE_ILLEGAL_FUNCTION_VALUE   = -9120,
                                             PQ_ERRCODE_UNKNOWN_ERROR            = -9999);
  {$Z4} // values are LongInt
    E_RI_STATUS                           = (PQ_RI_STATUS_UNKNOWN                =     0,
                                             PQ_RI_STATUS_IDLE                   =     1,
                                             PQ_RI_STATUS_MEAS_RUNNING           =     2,
                                             PQ_RI_STATUS_MEAS_TERMINATING       =     3);


// ************************************************************************************************
// call-back function types
// ************************************************************************************************

  TReceiveNumParameter = function (Ident: PAnsiChar; Value: Single; RecordNumber: LongInt): LongInt; stdcall;
    { Synopsis: Callback-Type;
        Function invoked by SPT DLL, if provided by the client application;
        Called on incoming data frames (NACK-frames), once for each numeric parameter received.
      Parameters:
        pcIdent                 : pointer to a string, to get the parameter name received
                                    (max. length : PQ_OPT_DATATYPE_NAME_MAXLEN+1)
        fValue                  : single;
        iRecNumber              : integer
      Returns:
        E_STOPREASON_CODES (to control the on-going measurement)
    }


  TReceiveStringParameter = function (Ident: PAnsiChar; Value: PAnsiChar; RecordNumber: LongInt): LongInt; stdcall;
    { Synopsis: Callback-Type;
        Function invoked by SPT DLL, if provided by the client application;
        Called on incoming data frames (NACK-frames), once for each string parameter received.
      Parameters:
        pcIdent                 : pointer to a string, to get the parameter name received
                                    (max. length : PQ_OPT_DATATYPE_NAME_MAXLEN+1)
        pcValue                 : pointer to a string, to get the parameter value received
        iRecNumber              : integer
      Returns:
        E_STOPREASON_CODES (to control the on-going measurement)
    }


// ************************************************************************************************
// debugging functions
// ************************************************************************************************

  function SPT_RI_AssignLogFile (const cLogFileName: string) : LongInt;
    { Synopsis:
        assigns the file identified by pcFileName to append all logging information.
        if the file does not exist, it will be created
      Parameters:
         pcFileName             : pointer to string, identifying the logfile;
      Returns:
        STP_RI_NO_ERROR         : OK
        STP_RI_ERROR            : Error
    }

  function SPT_RI_AddLineToLog (const cNewLine: string) : LongInt;
    { Synopsis:
        appends the line given by pcNewLine to log.
      Parameters:
         pcNewLine              : pointer to string, containing the text line to append;
      Returns:
        STP_RI_NO_ERROR         : OK
        STP_RI_ERROR            : Error
    }

  function SPT_RI_ShowLogWin : LongInt;
    { Synopsis:
        for debugging purposes: showing a log window with a readonly memofield containing the
        complete handshake protocol messages as Hex-Dump (no handshake traffic)
      Returns:
        STP_RI_NO_ERROR         : OK
        STP_RI_ERROR            : Error
    }

  function SPT_RI_HideLogWin : LongInt;
    { Synopsis:
        for debugging purposes: hiding the log window again (no handshake traffic)
      Returns:
        STP_RI_NO_ERROR         : OK
        STP_RI_ERROR            : Error
    }

  function SPT_RI_EnableLog (bEnableLog : LongBool) : LongInt;
    { Synopsis:
        for debugging purposes: enabling / disabling the log (no handshake traffic)
      Parameters:
         bEnableLog             : boolean, sets the logging mode, true enables the log;
      Returns:
        STP_RI_NO_ERROR         : OK
        STP_RI_ERROR            : Error
    }

// ************************************************************************************************
// initialising and supporting functions
// ************************************************************************************************

  function SPT_RI_GetLibVersion (out cLibVersion: string) : LongInt;
    { Synopsis:
        retrieves library version (no handshake traffic)
      Parameters:
        pcLibVersion            : pointer to string, returning the library version
                                    (max. length to be granted by client application:
                                     PQ_VERSIONSTRING_MAXLEN+1)
      Returns:
        STP_RI_NO_ERROR         : OK
        STP_RI_ERROR            : Error
    }

  function SPT_RI_GetErrorText (const eec : LongInt; out cErrorText: string) : LongInt;
    { Synopsis:
        retrieves human readable error text by error code (no handshake traffic)
      Parameters:
        eec                     : error code
        pcErrorText             : pointer to string, returning the decoded error text
                                    (max. length to be granted by client application:
                                     PQ_ERRORTEXT_MAXLEN+1)
      Returns:
        STP_RI_NO_ERROR         : OK
        STP_RI_ERROR            : Error
    }

  function SPT_RI_GetStatus : LongInt;
    { Synopsis:
        for controlling purposes: returns the internal status of the DLL
      Returns:
        E_RI_STATUS
    }

  function SPT_RI_GetStatusText (const estc : LongInt; out cStatusText: string) : LongInt;
    { Synopsis:
        retrieves human readable status text by status code (no handshake traffic)
      Parameters:
        eec                     : error code
        pcStatusText            : pointer to string, returning the decoded status text
                                    (max. length to be granted by client application:
                                     PQ_STATUSTEXT_MAXLEN+1)
      Returns:
        STP_RI_NO_ERROR         : OK
        STP_RI_UNKNOWN_PARAM    : estc is no valid status code
    }

  function SPT_RI_GetLastExplanation (out cLastExplanation: string) : LongInt;
    { Synopsis:
        retrieves human readable text explanation for the last error (if sent)
      Parameters:
        pcLastExplanation       : pointer to string, returning the error explanation
                                    (max. length to be granted by client application:
                                     PQ_EXPLANATION_MAXLEN+1)
      Returns:
        STP_RI_NO_ERROR         : OK
        STP_RI_UNKNOWN_PARAM    : estc is no valid status code
    }

  function SPT_RI_Initialize (const cHost : string; const iPort : LongInt; out cSPTVersion: string) : LongInt;
    { Synopsis:
        etablishes connection and retrieves SPT version,
        informs SPT on existing DLL-partner on client's site,
        provides DLL with pointer to call back function 'StatusChanged'
        releases connection
      Parameters:
        pcHost                  : pointer to string, identifying the server;
                                    may contain either an IP-Adress or a symbol like e.g. 'local'
        iPort                   : integer, identifying the port to be used by the connection
        pcSPTVersion            : pointer to string, to receive the version of the SPT connected.
                                    (max. length to be granted by client application:
                                     PQ_VERSIONSTRING_MAXLEN+1)
      Returns:
        STP_RI_NO_ERROR         : OK
        STP_RI_ERROR            : Error
    }

  function SPT_RI_SetOptionalInt (const cIdent : AnsiString; const iValue : LongInt; const iArrIdx : LongInt = -1) : LongInt;
    { Synopsis:
        stores optional integer parameters for the next measurement
      Parameters:
        pcIdent                 : pointer to string, identifying the optional float parameter;
        iValue                  : LongInt, containing the integer parameter value;
        iArrIdx                 : integer, if the parameter identified isn't an array : -1,
                                           else : array index (zero-based) to write the value to
      Returns:
        STP_RI_NO_ERROR         : ( 0) OK, if parameter is known and valid
        STP_RI_REDEFINED_PARAM  : ( 4) Warning, if parameter is valid but already set
        STP_RI_UNKNOWN_PARAM    : ( 5) Warning, if parameter is unknown but valid
        SPT_RI_TYPE_MISMATCH    : (-7) Errorcode, if parameter is known but typecheck failed
    }

  function SPT_RI_SetOptionalFloat (const cIdent : AnsiString; const fValue : single; const iArrIdx : LongInt = -1) : LongInt;
    { Synopsis:
        stores optional float parameters for the next measurement
      Parameters:
        pcIdent                 : pointer to string, identifying the optional float parameter;
        fValue                  : single, containing the float parameter value;
        iArrIdx                 : integer, if the parameter identified isn't an array : -1,
                                           else : array index (zero-based) to write the value to
      Returns:
        STP_RI_NO_ERROR         : ( 0) OK, if parameter is known and valid
        STP_RI_REDEFINED_PARAM  : ( 4) Warning, if parameter is valid but already set
        STP_RI_UNKNOWN_PARAM    : ( 5) Warning, if parameter is unknown but valid
        SPT_RI_TYPE_MISMATCH    : (-7) Errorcode, if parameter is known but typecheck failed
    }

  function SPT_RI_SetOptionalString (const cIdent : AnsiString; const cValue : AnsiString) : LongInt;
    { Synopsis:
        stores optional string parameters for the next measurement
      Parameters:
        pcIdent                 : pointer to string, identifying the optional string parameter;
        pcValue                 : pointer to string, containing the string parameter value;
      Returns:
        STP_RI_NO_ERROR         : ( 0) OK, if parameter is known and valid
        STP_RI_REDEFINED_PARAM  : ( 4) Warning, if parameter is valid but already set
        STP_RI_UNKNOWN_PARAM    : ( 5) Warning, if parameter is unknown but valid
        SPT_RI_TYPE_MISMATCH    : (-7) Errorcode, if parameter is known but typecheck failed
    }

  function SPT_RI_RegisterStringHandler (StringParamCallbackFunc : TReceiveStringParameter) : LongInt;
    { Synopsis:
        Registers a function to be called by the DLL on incoming string online parameters
      Parameters:
        StringParamCallbackFunc : function pointer to the call back function
                                    to be called by the DLL on incoming string online parameters
      Returns:
        E_ERROR_CODES           : detailed error code
    }


// ************************************************************************************************
// measurement handshake functions
// ************************************************************************************************

  function SPT_RI_RequestTimeTrace (const bRecordFile : LongBool; NumParamCallbackFunc : TReceiveNumParameter) : LongInt;
    { Synopsis:
        establishes connection,
        transfers optional parameters collected and starts measurement,
        clears the optional parameter buffer,
        waits for reply
      Parameters:
        bRecordFile             : boolean, false for test measurement (i.e. data measured will not be stored)
                                           true  for regular measurement
        NumParamCallbackFunc    : function pointer to the call back function
                                    to be called by the DLL on incoming numerical online parameters
      Returns:
        E_ERROR_CODES           : detailed error code
    }

  function SPT_RI_RequestImage (const bRecordFile : LongBool; const iPixX : LongInt; const iPixY : LongInt; const fResol : Single; const bBiDirectionalScan : LongBool; NumParamCallbackFunc : TReceiveNumParameter) : LongInt;
    { Synopsis:
        establishes connection,
        transfers optional parameters collected and starts measurement,
        clears the optional parameter buffer,
        waits for reply
      Parameters:
        bRecordFile             : boolean, false for test measurement (i.e. data measured will not be stored)
                                           true  for regular measurement
        iPixX, iPixY            : integer, dimensions of the image to scan in pixel counts
        fResol                  : single, pixel resolution in µm
        bBiDirectionalScan      : boolean, sets the scanning mode
        NumParamCallbackFunc    : function pointer to the call back function
                                    to be called by the DLL on incoming numerical online parameters
      Returns:
        E_ERROR_CODES           : detailed error code
    }

  function SPT_RI_RequestStopMeas : LongInt;
    { Synopsis:
        sends stop request,
        waits for acknowledging reply or timeout
      Returns:
        E_ERROR_CODES           : detailed error code
    }



var
  strLibVersion      : string;
  bSTP_RI_DLL_OK     : Boolean;
  bSTP_RI_DLLVERS_OK : Boolean;
  bSTP_RI_FUNCTS_OK  : Boolean;


implementation

  uses
    WinApi.Windows,
    System.SysUtils, System.AnsiStrings;

const

  PQ_SPT_VERSIONSTRING_MAXLEN           = 31;
  PQ_OPT_DATATYPE_NAME_MAXLEN           = 30;

type
  T_RI_AssignLogFile         = function (pcFileName : pAnsiChar) : LongInt; stdcall;
  T_RI_AddLineToLog          = function (pcNewLine : pAnsiChar) : LongInt; stdcall;
  T_RI_ShowLogWin            = function : LongInt; stdcall;
  T_RI_HideLogWin            = function : LongInt; stdcall;
  T_RI_EnableLog             = function (bEnableLog : LongBool) : LongInt; stdcall;
  T_RI_GetLibVersion         = function (pcLibVersion : pAnsiChar) : LongInt; stdcall;
  T_RI_GetErrorText          = function (eec : integer; pcErrorText : pAnsiChar) : LongInt; stdcall;
  T_RI_GetStatus             = function : LongInt; stdcall;
  T_RI_GetStatusText         = function (estc : integer; pcStatusText : pAnsiChar) : LongInt; stdcall;
  T_RI_GetLastExplanation    = function (pcLastExplanation : pAnsiChar) : LongInt; stdcall;
  T_RI_Initialize            = function (pcHost: pAnsiChar; iPort: integer; pcSPTVersion: pAnsiChar) : LongInt; stdcall;
  T_RI_SetOptionalInt        = function (pcIdent : pAnsiChar; iValue  : LongInt; iArrIdx : LongInt) : LongInt; stdcall;
  T_RI_SetOptionalFloat      = function (pcIdent : pAnsiChar; fValue  : Single;  iArrIdx : LongInt) : LongInt; stdcall;
  T_RI_SetOptionalString     = function (pcIdent : pAnsiChar; pcValue : pAnsiChar) : LongInt; stdcall;
  T_RI_RegisterStringHandler = function (StrParamCallbackFunc : TReceiveStringParameter) : LongInt; stdcall;
  T_RI_RequestTimeTrace      = function (bRecordFile : LongBool; NumParamCallbackFunc : TReceiveNumParameter) : LongInt; stdcall;
  T_RI_RequestImage          = function (bRecordFile : LongBool; iPixX, iPixY : LongInt; fResol : Single; bBiDirectionalScan : LongBool; NumParamCallbackFunc : TReceiveNumParameter) : LongInt; stdcall;
  T_RI_RequestStopMeas       = function : LongInt; stdcall;

var
  iRet                       : LongInt;
  bRet                       : LongBool;
  pcTmpVal                   : pAnsiChar;
  hdlDLL                     : THandle;
  //
  _RI_AssignLogFile          : T_RI_AssignLogFile;
  _RI_AddLineToLog           : T_RI_AddLineToLog;
  _RI_ShowLogWin             : T_RI_ShowLogWin;
  _RI_HideLogWin             : T_RI_HideLogWin;
  _RI_EnableLog              : T_RI_EnableLog;
  //
  _RI_GetLibVersion          : T_RI_GetLibVersion;
  _RI_GetErrorText           : T_RI_GetErrorText;
  _RI_GetStatus              : T_RI_GetStatus;
  _RI_GetStatusText          : T_RI_GetStatusText;
  _RI_GetLastExplanation     : T_RI_GetLastExplanation;
  _RI_Initialize             : T_RI_Initialize;
  //
  _RI_SetOptionalInt         : T_RI_SetOptionalInt;
  _RI_SetOptionalFloat       : T_RI_SetOptionalFloat;
  _RI_SetOptionalString      : T_RI_SetOptionalString;
  //
  _RI_RegisterStringHandler  : T_RI_RegisterStringHandler;
  //
  _RI_RequestTimeTrace       : T_RI_RequestTimeTrace;
  _RI_RequestImage           : T_RI_RequestImage;
  _RI_RequestStopMeas        : T_RI_RequestStopMeas;


  function LongIntFunction_void_missing () : LongInt; stdcall;
  begin
    result := ord (PQ_ERRCODE_UNKNOWN_FUNCTION);
  end;

  function LongIntFunction_pAnsiChar_missing (pc : pAnsiChar) : LongInt; stdcall;
  begin
    result := ord (PQ_ERRCODE_UNKNOWN_FUNCTION);
  end;

  function LongIntFunction_Boolean_missing (b : LongBool) : LongInt; stdcall;
  begin
    result := ord (PQ_ERRCODE_UNKNOWN_FUNCTION);
  end;

  function LongIntFunction_Integer_pAnsiChar_missing (i : integer; pc : pAnsiChar) : LongInt; stdcall;
  begin
    result := ord (PQ_ERRCODE_UNKNOWN_FUNCTION);
  end;

  function LongIntFunction_pAnsiChar_Integer_pAnsiChar_missing (pc1 : pAnsiChar; i : integer; pc2 : pAnsiChar) : LongInt; stdcall;
  begin
    result := ord (PQ_ERRCODE_UNKNOWN_FUNCTION);
  end;

  function LongIntFunction_pAnsiChar_2Integer_missing (pc : pAnsiChar; i1, i2 : LongInt) : LongInt; stdcall;
  begin
    result := ord (PQ_ERRCODE_UNKNOWN_FUNCTION);
  end;

  function LongIntFunction_pAnsiChar_Single_Integer_missing (pc : pAnsiChar; f : Single; i : LongInt) : LongInt; stdcall;
  begin
    result := ord (PQ_ERRCODE_UNKNOWN_FUNCTION);
  end;

  function LongIntFunction_2pAnsiChar_missing (pc1, pc2 : pAnsiChar) : LongInt; stdcall;
  begin
    result := ord (PQ_ERRCODE_UNKNOWN_FUNCTION);
  end;

  function LongIntFunction_SCBFunc_missing (scbf : TReceiveStringParameter) : LongInt; stdcall;
  begin
    result := ord (PQ_ERRCODE_UNKNOWN_FUNCTION);
  end;

  function LongIntFunction_Boolean_NCBFunc_missing (b : LongBool; ncbf : TReceiveNumParameter) : LongInt; stdcall;
  begin
    result := ord (PQ_ERRCODE_UNKNOWN_FUNCTION);
  end;

  function LongIntFunction_Boolean_2Integer_Single_Boolean_NCBFunc_missing (b1 : LongBool; i1, i2 : LongInt; f : Single; b2 : LongBool; ncbf : TReceiveNumParameter) : LongInt; stdcall;
  begin
    result := ord (PQ_ERRCODE_UNKNOWN_FUNCTION);
  end;

  function SPT_RI_AssignLogFile (const cLogFileName: string) : LongInt;
  var
    iRetVal : LongInt;
    strTemp : AnsiString;
  begin
    strTemp := AnsiString (cLogFileName);
    iRetVal := _RI_AssignLogFile (PAnsiChar(strTemp));
    result  := iRetVal;
  end;  // SPT_RI_AssignLogFile

  function SPT_RI_AddLineToLog (const cNewLine: string) : LongInt;
  var
    iRetVal : LongInt;
    strTemp : AnsiString;
  begin
    strTemp := AnsiString (cNewLine);
    iRetVal := _RI_AddLineToLog (PAnsiChar(strTemp));
    result  := iRetVal;
  end;  // SPT_RI_AddLineToLog

  function SPT_RI_ShowLogWin () : LongInt;
  begin
    result := _RI_ShowLogWin ();
  end; // STP_RI_ShowLogWin

  function SPT_RI_HideLogWin () : LongInt;
  begin
    result := _RI_HideLogWin ();
  end; // STP_RI_HideLogWin

  function SPT_RI_EnableLog (bEnableLog : LongBool) : LongInt;
  begin
    result := _RI_EnableLog (bEnableLog);
  end; // SPT_RI_EnableLog

  function SPT_RI_GetLibVersion (out cLibVersion: string) : LongInt;
  var
    iRetVal : LongInt;
    strTemp : AnsiString;
  begin
    System.AnsiStrings.StrCopy (pcTmpVal, '');
    iRetVal := _RI_GetLibVersion (pcTmpVal);
    strTemp := AnsiString (pcTmpVal);
    cLibVersion := string(strTemp);
    result  := iRetVal;
  end;  // STP_RI_GetLibVersion

  function SPT_RI_GetErrorText (const eec : LongInt; out cErrorText: string) : LongInt;
  var
    iRetVal : LongInt;
    strTemp : AnsiString;
  begin
    System.AnsiStrings.StrCopy (pcTmpVal, '');
    iRetVal := _RI_GetErrorText (eec, pcTmpVal);
    strTemp := AnsiString (pcTmpVal);
    cErrorText := string(strTemp);
    result  := iRetVal;
  end;  // STP_RI_GetErrorText

  function SPT_RI_GetStatus : LongInt;
  begin
    result  := _RI_GetStatus;
  end; // SPT_RI_GetStatus

  function SPT_RI_GetStatusText (const estc : LongInt; out cStatusText: string) : LongInt;
  var
    iRetVal : LongInt;
    strTemp : AnsiString;
  begin
    System.AnsiStrings.StrCopy (pcTmpVal, '');
    iRetVal := _RI_GetStatusText (estc, pcTmpVal);
    strTemp := AnsiString (pcTmpVal);
    cStatusText := string(strTemp);
    result  := iRetVal;
  end; // SPT_RI_GetStatusText

  function SPT_RI_GetLastExplanation (out cLastExplanation: string) : LongInt;
  var
    iRetVal : LongInt;
    strTemp : AnsiString;
  begin
    System.AnsiStrings.StrCopy (pcTmpVal, '');
    iRetVal := _RI_GetLastExplanation (pcTmpVal);
    strTemp := AnsiString (pcTmpVal);
    cLastExplanation := string(strTemp);
    result  := iRetVal;
  end;  // SPT_RI_GetLastExplanation



  function SPT_RI_Initialize (const cHost : string; const iPort : LongInt; out cSPTVersion: string) : LongInt;
  var
    iRetVal : integer;
    strTemp : AnsiString;
  begin
    System.AnsiStrings.StrCopy (pcTmpVal, '');
    strTemp := AnsiString(cHost);
    iRetVal := _RI_Initialize (pAnsiChar (strTemp), iPort, pcTmpVal);
    strTemp := AnsiString (pcTmpVal);
    cSPTVersion := string(strTemp);
    result  := iRetVal;
  end;  // STP_RI_Initialize

  function SPT_RI_SetOptionalInt (const cIdent : AnsiString; const iValue : LongInt; const iArrIdx : LongInt = -1) : LongInt;
  begin
    //
    result := _RI_SetOptionalInt (pAnsiChar (cIdent), iValue, iArrIdx);
    //
  end; // SPT_RI_SetOptionalInt

  function SPT_RI_SetOptionalFloat (const cIdent : AnsiString; const fValue : Single; const iArrIdx : LongInt = -1) : LongInt;
  begin
    //
    result := _RI_SetOptionalFloat (pAnsiChar (cIdent), fValue, iArrIdx);
    //
  end; // SPT_RI_SetOptionalFloat

  function SPT_RI_SetOptionalString (const cIdent : AnsiString; const cValue : AnsiString) : LongInt;
  begin
    //
    result := _RI_SetOptionalString (pAnsiChar (cIdent), pAnsiChar(cValue));
    //
  end; // SPT_RI_SetOptionalString

  function SPT_RI_RegisterStringHandler (StringParamCallbackFunc : TReceiveStringParameter) : LongInt;
  begin
    //
    result := _RI_RegisterStringHandler (@StringParamCallbackFunc);
    //
  end; // SPT_RI_RegisterStringHandler

  function SPT_RI_RequestTimeTrace (const bRecordFile : LongBool; NumParamCallbackFunc : TReceiveNumParameter) : LongInt;
  begin
    //
    result := _RI_RequestTimeTrace (bRecordFile, NumParamCallbackFunc);
    //
  end; // STP_RI_RequestTimeTrace

  function SPT_RI_RequestImage (const bRecordFile : LongBool; const iPixX : LongInt; const iPixY : LongInt; const fResol : Single; const bBiDirectionalScan : LongBool; NumParamCallbackFunc : TReceiveNumParameter) : LongInt;
  begin
    //
    result := _RI_RequestImage (bRecordFile, iPixX, iPixY, fResol, bBiDirectionalScan, NumParamCallbackFunc);
    //
  end; // SPT_RI_RequestImage

  function SPT_RI_RequestStopMeas : LongInt;
  begin
    //
    result := _RI_RequestStopMeas;
    //
  end; // STP_RI_RequestStopMeas

initialization
  strLibVersion := #0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0;
  pcTmpVal  := AllocMem  (4097);
  bSTP_RI_FUNCTS_OK := true;
  //
  hdlDLL := 0;
  hdlDLL := LoadLibrary ('RemoteInterface.dll');
  if hdlDLL > 32
  then begin
    bSTP_RI_DLL_OK := true;
    //
    @_RI_AssignLogFile := GetProcAddress (hdlDLL, 'RI_AssignLogFile');
    bSTP_RI_FUNCTS_OK := bSTP_RI_FUNCTS_OK and (@_RI_AssignLogFile <> nil);
    if (@_RI_AssignLogFile = nil) then
      @_RI_AssignLogFile := @LongIntFunction_pAnsiChar_missing;
    //
    @_RI_AddLineToLog := GetProcAddress (hdlDLL, 'RI_AddLineToLog');
    bSTP_RI_FUNCTS_OK := bSTP_RI_FUNCTS_OK and (@_RI_AddLineToLog <> nil);
    if (@_RI_AddLineToLog = nil) then
      @_RI_AddLineToLog := @LongIntFunction_pAnsiChar_missing;
    //
    @_RI_ShowLogWin := GetProcAddress (hdlDLL, 'RI_ShowLogWin');
    bSTP_RI_FUNCTS_OK := bSTP_RI_FUNCTS_OK and (@_RI_ShowLogWin <> nil);
    if (@_RI_ShowLogWin = nil) then
      @_RI_ShowLogWin := @LongIntFunction_void_missing;
    //
    @_RI_HideLogWin := GetProcAddress (hdlDLL, 'RI_HideLogWin');
    bSTP_RI_FUNCTS_OK := bSTP_RI_FUNCTS_OK and (@_RI_HideLogWin <> nil);
    if (@_RI_HideLogWin = nil) then
      @_RI_HideLogWin := @LongIntFunction_void_missing;
    //
    @_RI_EnableLog := GetProcAddress (hdlDLL, 'RI_EnableLog');
    bSTP_RI_FUNCTS_OK := bSTP_RI_FUNCTS_OK and (@_RI_EnableLog <> nil);
    if (@_RI_EnableLog = nil) then
      @_RI_EnableLog := @LongIntFunction_Boolean_missing;
    //
    @_RI_GetLibVersion := GetProcAddress (hdlDLL, 'RI_GetLibVersion');
    bSTP_RI_FUNCTS_OK := bSTP_RI_FUNCTS_OK and (@_RI_GetLibVersion <> nil);
    if (@_RI_GetLibVersion = nil) then
      @_RI_GetLibVersion := @LongIntFunction_pAnsiChar_missing;
    //
    @_RI_GetErrorText := GetProcAddress (hdlDLL, 'RI_GetErrorText');
    bSTP_RI_FUNCTS_OK := bSTP_RI_FUNCTS_OK and (@_RI_GetErrorText <> nil);
    if (@_RI_GetErrorText = nil) then
      @_RI_GetErrorText := @LongIntFunction_Integer_pAnsiChar_missing;
    //
    @_RI_GetStatus := GetProcAddress (hdlDLL, 'RI_GetStatus');
    bSTP_RI_FUNCTS_OK := bSTP_RI_FUNCTS_OK and (@_RI_GetStatus <> nil);
    if (@_RI_GetStatus = nil) then
      @_RI_GetStatus := @LongIntFunction_void_missing;
    //
    @_RI_GetStatusText := GetProcAddress (hdlDLL, 'RI_GetStatusText');
    bSTP_RI_FUNCTS_OK := bSTP_RI_FUNCTS_OK and (@_RI_GetStatusText <> nil);
    if (@_RI_GetStatusText = nil) then
      @_RI_GetStatusText := @LongIntFunction_Integer_pAnsiChar_missing;
    //
    @_RI_GetLastExplanation := GetProcAddress (hdlDLL, 'RI_GetLastExplanation');
    bSTP_RI_FUNCTS_OK := bSTP_RI_FUNCTS_OK and (@_RI_GetLastExplanation <> nil);
    if (@_RI_GetLastExplanation = nil) then
      @_RI_GetLastExplanation := @LongIntFunction_pAnsiChar_missing;
    //
    @_RI_Initialize := GetProcAddress (hdlDLL, 'RI_Initialize');
    bSTP_RI_FUNCTS_OK := bSTP_RI_FUNCTS_OK and (@_RI_Initialize <> nil);
    if (@_RI_Initialize = nil) then
      @_RI_Initialize := @LongIntFunction_pAnsiChar_Integer_pAnsiChar_missing;
    //
    @_RI_SetOptionalInt := GetProcAddress (hdlDLL, 'RI_SetOptionalInt');
    bSTP_RI_FUNCTS_OK := bSTP_RI_FUNCTS_OK and (@_RI_SetOptionalInt <> nil);
    if (@_RI_SetOptionalInt = nil) then
      @_RI_SetOptionalInt := @LongIntFunction_pAnsiChar_2Integer_missing;
    //
    @_RI_SetOptionalFloat := GetProcAddress (hdlDLL, 'RI_SetOptionalFloat');
    bSTP_RI_FUNCTS_OK := bSTP_RI_FUNCTS_OK and (@_RI_SetOptionalFloat <> nil);
    if (@_RI_SetOptionalFloat = nil) then
      @_RI_SetOptionalFloat := @LongIntFunction_pAnsiChar_Single_Integer_missing;
    //
    @_RI_SetOptionalString := GetProcAddress (hdlDLL, 'RI_SetOptionalString');
    bSTP_RI_FUNCTS_OK := bSTP_RI_FUNCTS_OK and (@_RI_SetOptionalString <> nil);
    if (@_RI_SetOptionalString = nil) then
      @_RI_SetOptionalString := @LongIntFunction_2pAnsiChar_missing;
    //
    @_RI_RegisterStringHandler := GetProcAddress (hdlDLL, 'RI_RegisterStringHandler');
    bSTP_RI_FUNCTS_OK := bSTP_RI_FUNCTS_OK and (@_RI_RegisterStringHandler <> nil);
    if (@_RI_RegisterStringHandler = nil) then
      @_RI_RegisterStringHandler := @LongIntFunction_SCBFunc_missing;
    //
    @_RI_RequestTimeTrace := GetProcAddress (hdlDLL, 'RI_RequestTimeTrace');
    bSTP_RI_FUNCTS_OK := bSTP_RI_FUNCTS_OK and (@_RI_RequestTimeTrace <> nil);
    if (@_RI_RequestTimeTrace = nil) then
      @_RI_RequestTimeTrace := @LongIntFunction_Boolean_NCBFunc_missing;
    //
    @_RI_RequestImage := GetProcAddress (hdlDLL, 'RI_RequestImage');
    bSTP_RI_FUNCTS_OK := bSTP_RI_FUNCTS_OK and (@_RI_RequestImage <> nil);
    if (@_RI_RequestImage = nil) then
      @_RI_RequestImage := @LongIntFunction_Boolean_2Integer_Single_Boolean_NCBFunc_missing;
    //
    @_RI_RequestStopMeas := GetProcAddress (hdlDLL, 'RI_RequestStopMeas');
    bSTP_RI_FUNCTS_OK := bSTP_RI_FUNCTS_OK and (@_RI_RequestStopMeas <> nil);
    if (@_RI_RequestStopMeas = nil) then
      @_RI_RequestStopMeas := @LongIntFunction_void_missing;
    //
    if bSTP_RI_DLL_OK
    then begin
      iRet := SPT_RI_GetLibVersion (strLibVersion);
      if (iRet = ord (PQ_ERRCODE_NO_ERROR))
      then begin
        bSTP_RI_DLLVERS_OK := (ord (PQ_ERRCODE_NO_ERROR) = StrLComp(PChar(strLibVersion), PChar(LIB_VERSION_REFERENCE), Length(LIB_VERSION_REFERENCE)));
      end;
    end;
  end
  else begin
    bSTP_RI_DLL_OK     := false;
    bSTP_RI_DLLVERS_OK := false;
    bSTP_RI_FUNCTS_OK  := false;
  end;

finalization
  try
    if hdlDLL > 32
    then begin
      bRet := FreeLibrary (hdlDLL);
    end;
  finally
    FreeMem (pcTmpVal);
  end;
end.
