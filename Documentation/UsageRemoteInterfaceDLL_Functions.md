
Recommended steps for a painless usage of the SymPhoTime 64 RemoteInterface-DLL functions
=============================================

Please understand all codelines herein as pseudo-code, and never intended to instantely run under whatsoever conditions. Instead, they are to picture out the in-general usage of the RemoteInterface DLL as supplied with SymPhoTime 64. We hope this document may reduce the time of familiarization with the DLL.


Create an DLL import function analogous to ```InitRemoteInterface_DLL ()`` from the stress client example. All DLL functions return a long int, coding their result as either finished without error or the error number which might be decoded to a human readable string cErrText, using the function ```RI_GetErrorText``"``:

```
    long int lRet;
    char     cErrText [SPT_RI_ERRORTEXT_MAXLEN+1];

    if (PQ_ERRCODE_NO_ERROR != (lRet = InitRemoteInterface_DLL ()))
    {
      RI_GetErrorText (lRet, cErrText);
    }
```

Check for version compatibility:

```
    char cLibVersion [SPT_RI_VERSIONSTRING_MAXLEN+1];

    RI_GetLibVersion (cLibVersion);
```

At least if still in debugging process, provide a means to show the debugging window. You may then compare between the received data and the information sent by SPT as shown in the server window. While running with enabled log, all insertations to the log are recorded with timestamp.

```
    if (PQ_ERRCODE_NO_ERROR == (lRet = RI_AssignLogFile ("MyLog.txt")))
    {
      RI_EnableLog (true);
      RI_AddLineToLog ("Begin of Session");
      RI_ShowLogWin ();
    }
```

Create a call-back function (or a maybe couple of specialized ones)
with the footprint
```
    typedef long (__stdcall *TReceiveParamFunc)(char* pcIdent,
                                                float fValue,
                                                long  iRecNr);
```
If passed over to the DLL with the start of a new measurement, they will be called on each incoming feedback frame, once for each named value in each frame. These frames will be sent by SPT64 and SPT32 as well in intervals of approx. 1.2 seconds. For the names of the values transmitted, refer to the document [!]Feedback_Values.txt

Let this call-back function have side effects, e.g.

  - in copying the values received to certain memory locations depending on the identifier recognized, for the usage outside e.g. for displaying. CAVEAT: Since the function is called from the context of a DLL internal thread, take care of thread-saveness (use e.g. Interlocked Exchange).

  - in making the decision when to stop the measurement either directly inside the function or on a decision value handed over into the function by means of a global variable.

  - in letting the function finally return the result of this decision to the DLL using values as given by enumeration type ```E_SPT_RI_STOP_REASONS``` or else

  - in letting the function always return ```SPT_RI_STOP_REASON_CONTINUE_OK```.
    (In the later case, you have to terminate measurements explicitely by calling the function ```RI_RequestStopMeas```.)


The following example will only react on each ```maxcpp``` and terminate the measurement if the value of any ```maxcpp``` value increases 250 counts. Consider, that this would never stop a time trace measurement, since there will never be a feedback sent like ```maxcpp```!
```
    long __stdcall AnImageParamCallBackFunc (char* pcIdent, float fValue, long iRecNr)
    {
      long int lStopReason;
      //
      lStopReason = SPT_RI_STOP_REASON_CONTINUE_OK;
      //
      if (0 == strcmp (PQ_OPT_DATANAME_MAX_COUNTS_PER_PIXEL, pcIdent))
      {
        if (fValue > 250.0f)
        {
          lStopReason = SPT_RI_STOP_REASON_FINISHED_OK;
        }
      }
      return lStopReason;
    }
```


Then create the infrastructure to hand over individual optional parameters for the next measurement to be started. As known from SPT32, this could be:

  - the desired file name for the raw data file

  - a group name (i.e. the name of a subdirectory to create, if not already existing, within the current working directory in the SPT64 workspace, where to insert the raw data file, the measurement process is about to create)

  - some measurement describing information, with predefined value names, as there are e.g.

```
      + "Objective"              // string
      + "Pinhole"                // string
      + "MajorDichroic"          // string
      + "TimePerPixel"           // float, set in seconds
      + "TimePerImageEstimated"  // float, set in seconds
```
    Future releases may or may not provide retrieval capabilities for these.

  - comments for documentation purposes, that will be inserted into the resulting raw data files, too. Other than the prementioned, comments are not scanned nor interpreted neither now nor is this planned for future releases. But they may contain a huge amount of measurement related information, given in human readable format. They may even contain formatting tabs or line feeds (DOS-style recommended: ```<CR><LF>```)


Now, for the opening handshake, call the init function ```RI_Initialize``` where the parameter cHost should contain the IP address, like e.g. ```127.0.0.1```, the long int parameter lPort contains the port to be used for the comunication, (should equal 6000). If the return code equals ```PQ_ERRCODE_NO_ERROR```, you may rely on the SPT version string returned in ```cSPTVersion```.

```
    char     cHost[SPT_RI_HOSTNAME_MAXLEN];
    long int lPort;
    char     cSPTVersion[SPT_RI_VERSIONSTRING_MAXLEN];

    strcpy (cHost, "127.0.0.1");
    lPort = 6000;
    lRet = RI_Initialize (cHost, lPort, cSPTVersion);
```

If terminated without error, continue, else react on the error and maybe retry. An error frequently made is to forget to open a workspace, resulting in the errocode ```PQ_ERRCODE_NO_WORKSPACE```.

Now, as the connection is approved to be free of errors, you may sent the upper mentioned optional parameters to the DLL, e.g.:

```
    RI_SetOptionalString (PQ_OPT_INFONAME_GROUPNAME, "MySubdir");
    RI_SetOptionalString (PQ_OPT_INFONAME_FILENAME,  "MyRawData");
```

Consider, if there is already a file with the given name in the subdirectory, the measurement will terminate with an error ```PQ_ERRCODE_FILE_EXISTS```.
Now, if the SPT signals to be in IDLE state, we are ready to start a measurement, in this example let's record for an image.

```
    long int          lState;
    longbool          bRecord;
    long int          lPixX;
    long int          lPixy;
    float             fResol;
    longbool          bBiDirectionalScan;
    TReceiveParamFunc MyPCBFunc;

    lState      = SPT_RI_STATUS_UNKNOWN;
    bRecord     = true;                     // i.e. measureement mode; false would be test mode
    lPixX       = 128;
    lPixY       = 128;
    fResol      = 1.0e-6f;                  // given in meter
    bBiDirScan  = false;                    // mono-directional scan
    MyPCBFunc   = AnImageParamCallBackFunc; // see above


    do
    {
      if (PQ_ERRCODE_NO_ERROR == (lRet = RI_GetStatusText (lState = RI_GetStatus (), cStatus)))
      {
        if (lState == SPT_RI_STATUS_IDLE)
        {
          lRet = RI_RequestImage (bRecord, lPixX, lPixY, fResol, bBiDirScan, MyPCBFunc);
          lState = RI_GetStatus ();
        }
        else
        {
          // show cStatus in GUI
          //
          Sleep 1000;
          //
          // IMPORTANT: Give SPT some time for the apr�s measurement work;
          //            Don't poll too fast, because this would hinder SPT
          //            ever to get ready for the next measurement, again!
        }
      }
    } while ( (lRet == PQ_ERRCODE_NO_ERROR) && (lState != SPT_RI_STATUS_MEAS_RUNNING) )
```

If
  a) the return value is ```PQ_ERRCODE_NO_ERROR``` and
  b) the state is ```SPT_RI_STATUS_MEAS_RUNNING```, the measurement is accepted and running, else decode the return value and
state code and act appropriately. The illustrated state machine shall only show the in principle possibility of reaction on changes of the state. You should properly design your own machine according to the demands of your
respective application.

Assuming, the measurement is running, the function ```AnImageParamCallBackFunc``` will be called for feedback transmission. If a pixel reaches more than 250 counts, the measurement will be terminated according to plan. But it also might happen, that a user wants to stop the running measurement, for he or she realizes a mistake in the supplied information or perhaps the preview provided by the SPT64. On behalf of this you should provide e.g. a button, which on click launches a stop measurement request:

```
    if (PQ_ERRCODE_NO_ERROR == (lRet = RI_RequestStopMeas ()))
    {
      RI_AddLineToLog ("Measurement stopped by user!");
    }
```

After checking


At last, if running under debugging conditions, release the logfile:

```
    RI_AddLineToLog ("End of Session");
    RI_EnableLog (false);
    RI_HideLogWin ();
```

We hope, this little doc made things easier for you.
Enjoy remote controlling your SymPhoTime!

apo (PQ).
