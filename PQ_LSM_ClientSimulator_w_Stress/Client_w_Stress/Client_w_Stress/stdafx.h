// stdafx.h : Includedatei f�r Standardsystem-Includedateien
// oder h�ufig verwendete projektspezifische Includedateien,
// die nur in unregelm��igen Abst�nden ge�ndert werden.
#pragma once

// TODO: Hier auf zus�tzliche Header, die das Programm erfordert, verweisen.

extern "C" {
  #pragma message( "Compiling <stdlib.h> in " __FILE__ )
  #include <stdlib.h>
  #pragma message( "Compiling <windows.h> in " __FILE__ )
  #include <windows.h>
  #pragma message( "Compiling <winver.h> in " __FILE__ )
  #include <winver.h>
  #pragma message( "Compiling <time.h> in " __FILE__ )
  #include <time.h>
  #pragma message( "Compiling <sys\timeb.h> in " __FILE__ )
  #include <sys\timeb.h>
  #pragma message( "Compiling <math.h> in " __FILE__ )
  #define _USE_MATH_DEFINES
  #include <math.h>
}

#include <string>
#include <msclr\marshal.h>
#include <msclr\marshal_cppstd.h>
