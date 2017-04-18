//-----------------------------------------------------------------------------
//
//      RemoteInterface_Def.h
//      © by PicoQuant GmbH, February 2012
//
//-----------------------------------------------------------------------------
//
//  symbols used by SymPhoTime RemoteInterface_Lib
//
//-----------------------------------------------------------------------------
//  HISTORY:
//
//  apo  17.02.12   release of the library interface
//  apo  31.08.12   homogenized name conventions
//  apo  29.02.16   enhanced list of known optional data to be sent to server
//
//-----------------------------------------------------------------------------
//

#ifndef   __REMOTEINTERFACE_DEF_H__
  #define __REMOTEINTERFACE_DEF_H__

  #define LIB_VERSION_REFERENCE                    "1.0.9."                         // actually the version string is longer,
  #define LIB_OLDVERSION_REFERENCE                 "1.0.8."                         // but compare first n=6 characters only! 
  //                                                                                
  #define SPT_RI_VERSIONSTRING_MAXLEN               31
  #define SPT_RI_STATUSTEXT_MAXLEN                  31
  #define SPT_RI_HOSTNAME_MAXLEN                    63
  #define SPT_RI_FILENAME_MAXLEN                   255
  #define SPT_RI_GROUPNAME_MAXLEN                   63
  #define SPT_RI_COMMENT_MAXLEN                  32767
  #define SPT_RI_OPT_DATATYPE_NAME_MAXLEN           30
  #define SPT_RI_ERRORTEXT_MAXLEN                   63
  //
  // idents for optional data to be sent to the server
  #define PQ_OPT_INFONAME_FILENAME                 "Filename"                       // string (max. length = 255 chars.)
  #define PQ_OPT_INFONAME_GROUPNAME                "Groupname"                      // string (max. length =  63 chars.)
  #define PQ_OPT_INFONAME_OBJECTIVE                "Objective"                      // string
  #define PQ_OPT_INFONAME_PINHOLE                  "Pinhole"                        // string
  #define PQ_OPT_INFONAME_MAJOR_DICHROIC           "MajorDichroic"                  // string
  #define PQ_OPT_INFONAME_COMMENT                  "Comment"                        // string
  #define PQ_OPT_INFONAME_TIME_PER_PIXEL           "TimePerPixel"                   // float
  #define PQ_OPT_INFONAME_TIME_PER_IMAGE           "TimePerImageEstimated"          // float
  #define PQ_OPT_INFONAME_LASERREPRATE             "LaserRepetitionRate"            // long
  #define PQ_OPT_INFONAME_LASERPATTERNIDX          "LaserPulsePatternIndex"         // long
  #define PQ_OPT_INFONAME_LASERON                  "LaserOn"                        // long  (array indexed 0..7)
  #define PQ_OPT_INFONAME_LASERINTENS              "LaserIntensity"                 // float (array indexed 0..7)


  //
  // idents for optional data to be received from the server
  #define PQ_OPT_DATANAME_SPT_VERSION              "ServerVersion"                  // use T_OPT_DATA to decode version
  #define PQ_OPT_DATANAME_CH1_COUNTS_PER_MOLECULE  "cpm1"                           // float
  #define PQ_OPT_DATANAME_CH2_COUNTS_PER_MOLECULE  "cpm2"                           // float
  #define PQ_OPT_DATANAME_CH1_COUNTS_PER_SECOND    "cps1"                           // ulong
  #define PQ_OPT_DATANAME_CH2_COUNTS_PER_SECOND    "cps2"                           // ulong
  #define PQ_OPT_DATANAME_DET1_COUNTS_PER_SECOND   "det1"                           // ulong
  #define PQ_OPT_DATANAME_DET2_COUNTS_PER_SECOND   "det2"                           // ulong
  #define PQ_OPT_DATANAME_DET3_COUNTS_PER_SECOND   "det3"                           // ulong
  #define PQ_OPT_DATANAME_DET4_COUNTS_PER_SECOND   "det4"                           // ulong
  #define PQ_OPT_DATANAME_MAX_COUNTS_PER_PIXEL     "maxcpp"                         // ulong  
  #define PQ_OPT_DATANAME_RESULTINGFILENAME        "ResultingFilename"              // string (max. length = 255 chars.)
  #define PQ_OPT_DATANAME_RESULTINGGROUPNAME       "ResultingGroupname"             // string (max. length =  63 chars.)
  #define PQ_OPT_DATANAME_RESULTINGLASERREPRATE    "ResultingLaserRepetitionRate"   // long
  #define PQ_OPT_DATANAME_LASERNAME                "LaserName"                      // comparision template
  #define PQ_OPT_DATANAME_LASERNAME1               "LaserName1"                     // string
  #define PQ_OPT_DATANAME_LASERNAME2               "LaserName2"                     // string
  #define PQ_OPT_DATANAME_LASERNAME3               "LaserName3"                     // string
  #define PQ_OPT_DATANAME_LASERNAME4               "LaserName4"                     // string
  #define PQ_OPT_DATANAME_LASERNAME5               "LaserName5"                     // string
  #define PQ_OPT_DATANAME_LASERNAME6               "LaserName6"                     // string
  #define PQ_OPT_DATANAME_LASERNAME7               "LaserName7"                     // string
  #define PQ_OPT_DATANAME_LASERNAME8               "LaserName8"                     // string
  
  typedef enum {
    PQ_OPT_DATATYPE_FLOAT                        =  (unsigned char)0,
    PQ_OPT_DATATYPE_LONG                         =  (unsigned char)1,
    PQ_OPT_DATATYPE_ULONG                        =  (unsigned char)2,
    PQ_OPT_DATATYPE_REC_VERSION                  =  (unsigned char)7,
    PQ_OPT_DATATYPE_FIXED_LENGTH_STRING          =  (unsigned char)255
  } E_PQ_OPT_DATA_TYPES;
  
  typedef enum {
    PQ_ERRCODE_NO_ERROR                          =  (short)    0,
    PQ_ERRCODE_MEASUREMENT_READY                 =  (short)    1,
    PQ_ERRCODE_USER_BREAK                        =  (short)    2,
    PQ_ERRCODE_MEASUREMENT_TERMINATING           =  (short)    3,
    PQ_ERRCODE_REDEFINED_PARAM                   =  (short)    4,
    PQ_ERRCODE_UNKNOWN_PARAM                     =  (short)    5,
    PQ_ERRCODE_FUNCTION_BLOCKED                  =  (short)    9,
    PQ_ERRCODE_MESSAGE_CORRUPTED                 =  (short)   -1,
    PQ_ERRCODE_SERVER_BUSY                       =  (short)   -2,
    PQ_ERRCODE_MESSAGE_TIMEOUT                   =  (short)   -3,
    PQ_ERRCODE_TYPE_MISMATCH                     =  (short)   -7,
    PQ_ERRCODE_INVALID_REC_VERSION               =  (short)  -10,
    PQ_ERRCODE_MEASUREMENT_TIMEOUT               =  (short) -100,
    PQ_ERRCODE_FIFO_OVERRUN                      =  (short) -101,
    PQ_ERRCODE_DMA_ERROR                         =  (short) -102,
    PQ_ERRCODE_OSCILLOSCOPE_RUNNING              =  (short) -103,
    PQ_ERRCODE_HARDWARE_INIT                     =  (short) -104,
    PQ_ERRCODE_TTTR_INIT                         =  (short) -105,
    PQ_ERRCODE_TTTR_RUNNING                      =  (short) -106,
    PQ_ERRCODE_NO_WORKSPACE                      =  (short) -107,
    PQ_ERRCODE_FILE_EXISTS                       =  (short) -108,
    PQ_ERRCODE_FILE_CREATE                       =  (short) -109,
    PQ_ERRCODE_GROUPNAME_TOO_LONG                =  (short) -110,
    PQ_ERRCODE_FILENAME_TOO_LONG                 =  (short) -111,
    PQ_ERRCODE_TIMESTAMP_ARRAY_TOO_LONG          =  (short) -112,
    PQ_ERRCODE_OPEN_LOGFILE_FAILED               =  (short) -113,
    PQ_ERRCODE_MEASUREMENT_RUNNING               =  (short) -114,
    PQ_ERRCODE_NO_MEASUREMENT_RUNNING            =  (short) -115,
    PQ_ERRCODE_INVALID_PARAMETERNAME             =  (short) -116,
    PQ_ERRCODE_UNSUPPORTED_MEASUREMENT           =  (short) -117,
    PQ_ERRCODE_SERVER_NOT_INITIALISED            =  (short) -118,
    PQ_ERRCODE_TCSPCSYSTEM_ERROR                 =  (short) -119,
    PQ_ERRCODE_MEMORY_ACCESS_ERROR               =  (short) -120,
    PQ_ERRCODE_CLIENT_NOT_INITIALISED            =  (short) -121,
    PQ_ERRCODE_INVALID_LICENSE                   =  (short) -999,
    PQ_ERRCODE_HANDSHAKE_ERROR                   =  (short)-1000,
    PQ_ERRCODE_GENERAL_SOCKET_ERROR              =  (short)-1100,
    PQ_ERRCODE_SOCKET_ERROR_SEND                 =  (short)-1101,
    PQ_ERRCODE_SOCKET_ERROR_RECEIVE              =  (short)-1102,
    PQ_ERRCODE_SOCKET_ERROR_CONNECT              =  (short)-1103,
    PQ_ERRCODE_SOCKET_ERROR_DISCONNECT           =  (short)-1104,
    PQ_ERRCODE_SOCKET_ERROR_ACCEPT               =  (short)-1105,
    PQ_ERRCODE_SOCKET_ERROR_LOOKUP               =  (short)-1106,
    PQ_ERRCODE_DLL_NOT_FOUND                     =  (short)-9100,
    PQ_ERRCODE_UNKNOWN_FUNCTION                  =  (short)-9110,
    PQ_ERRCODE_ILLEGAL_FUNCTION_VALUE            =  (short)-9120,
    PQ_ERRCODE_UNKNOWN_ERROR                     =  (short)-9999
  } E_PQ_ERROR_CODES;
  
  typedef enum {
    SPT_RI_STOP_REASON_CONTINUE_OK               =  (short) 0,
    SPT_RI_STOP_REASON_FINISHED_OK               =  (short) 1,
    SPT_RI_STOP_REASON_USER_BREAK                =  (short) 2,
    SPT_RI_STOP_REASON_ERROR                     =  (short)-1
  } E_SPT_RI_STOP_REASONS;
                         
  typedef enum {
    SPT_RI_STATUS_UNKNOWN                        =  (long)0,
    SPT_RI_STATUS_IDLE                           =  (long)1,
    SPT_RI_STATUS_MEAS_RUNNING                   =  (long)2,
    SPT_RI_STATUS_MEAS_TERMINATING               =  (long)3
  } E_SPT_RI_STATUS;

  typedef unsigned long longbool;

#endif // __REMOTEINTERFACE_DEF_H__

