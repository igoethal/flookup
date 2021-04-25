// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include <string>
#include <clocale>
#include <cstdlib>
#include <iostream>
#include <math.h>
#include <string.h>

#include "levenshtein.h"

using namespace std;

BOOL APIENTRY DllMain(HMODULE hModule,
    DWORD  ul_reason_for_call,
    LPVOID lpReserved
)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

//--- The square function is rather to test the Excel interface ---

double __stdcall square(double& x) {
    return(x * x);
}

//--- The mystrlen function is to get the length of a string, it is at present not sure if it will count unicode characters as one or multiple bytes ---

size_t __stdcall mystrlen(LPCSTR in)
{
    return strlen(in);
}

//--- Function to transform a string into capitals but it does not seem to be used ---

STDAPI ToUpperLPSTR(LPCSTR in, LPSTR out, int cch)
{
    // ansi version
    LCMapStringA(LOCALE_USER_DEFAULT, LCMAP_LINGUISTIC_CASING | LCMAP_UPPERCASE, in, lstrlenA(in), out, cch);
    return S_OK;
}

//--- Function to calculate the Levenshtein distance between two strings str1 and str2 ---

INT16 __stdcall levenshtein(LPCSTR str1, LPCSTR str2)
{
    INT16 x = levenshtein_distance_fixed(str1, static_cast<INT16>(strlen(str1)), str2, static_cast<INT16>(strlen(str2)));
    return x;
}

//--- Function to return the character at position pos ---
//
// Returns the integer value of the character at position pos (starting at 0)
// Returns 0 of the requested position is out of bounds (>=length of the string)

INT16 __stdcall charval(LPCSTR in, INT16 pos)
{
    if (pos < strlen(in)) {
        UINT8 mychar = in[pos];
        return(mychar);
    } else {
        return(0);
    }
}