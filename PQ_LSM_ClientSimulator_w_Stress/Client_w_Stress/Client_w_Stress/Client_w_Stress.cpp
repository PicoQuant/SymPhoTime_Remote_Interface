// Client_w_Stress.cpp: Hauptprojektdatei.



#include "stdafx.h"

extern "C" {
  #undef  __CALLED_BY_REMOTEINTERFACE_LIB_CPP__
  #pragma message( "Compiling <RemoteInterface_Def.h> in " __FILE__ )
  #include "RemoteInterface_Def.h"
  #pragma message( "Compiling <RemoteInterface_Lib.h> in " __FILE__ )
  #include "RemoteInterface_Lib.h"
}

#include "Client_LSM_SymPhoTime_Dlg.h"

using namespace Client_w_Stress;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
  const char *pcTemp;
  char  cPrae[32];
  int   i;
  int   iRet;
  int   count;
  int   iIP_Part1;
  int   iIP_Part2;
  int   iIP_Part3;
  int   iIP_Part4;
  //
  marshal_context^ context = gcnew marshal_context();
  //
  // Aktivieren visueller Effekte von Windows XP, bevor Steuerelemente erstellt werden
  Application::EnableVisualStyles();
  Application::SetCompatibleTextRenderingDefault(false); 

  // Hauptfenster erstellen und ausführen
  Client_LSM_SymPhoTime_Dlg^ Client_Dlg = gcnew Client_LSM_SymPhoTime_Dlg();
  Client_w_Stress::PClient_Dlg = &Client_Dlg;
  //
  (*Client_w_Stress::PClient_Dlg)->strLogFileName = L"";
  //
  count = args->Length;
  for (i=0; i < count; i++)
  {
    pcTemp = context->marshal_as <const char*> (args[i]); 
    if (0 == _strnicmp ("-ip=", pcTemp, 4))
    {
      if (0 != _strnicmp ("-ip=local", pcTemp, 9))
      {
        if ( (5 == (iRet = sscanf_s (pcTemp, "%4[^1-90]%d.%d.%d.%d", cPrae, 32, &iIP_Part1, &iIP_Part2, &iIP_Part3, &iIP_Part4 )))
          && (iIP_Part1 >= 0) && (iIP_Part1 < 256)
          && (iIP_Part2 >= 0) && (iIP_Part2 < 256)
          && (iIP_Part3 >= 0) && (iIP_Part3 < 256)
          && (iIP_Part4 >= 0) && (iIP_Part4 < 256)
           )
        {

          (*Client_w_Stress::PClient_Dlg)->iLastNonLocalIP        = ((Byte)(iIP_Part1) << 24) +
                                                                    ((Byte)(iIP_Part2) << 16) +
                                                                    ((Byte)(iIP_Part3) <<  8) +
                                                                     (Byte)(iIP_Part4);

          (*Client_w_Stress::PClient_Dlg)->rbtnOtherHost->Checked = true;
        }
        else
        {
          (*Client_w_Stress::PClient_Dlg)->iLastNonLocalIP        = ((Byte)(192) << 24) +
                                                                    ((Byte)(168) << 16) +
                                                                    ((Byte)( 43) <<  8) +
                                                                     (Byte)(  3);
        }
      }
    }
    if (0 == _strnicmp ("-log=", pcTemp, 5))
    {
      (*Client_w_Stress::PClient_Dlg)->strLogFileName = marshal_as<String^> ((char*)pcTemp);
      (*Client_w_Stress::PClient_Dlg)->strLogFileName = (*Client_w_Stress::PClient_Dlg)->strLogFileName->Remove (0, 5);
    }
  }
  delete context;
  //
  Application::Run(Client_Dlg);
  return 0;
}
