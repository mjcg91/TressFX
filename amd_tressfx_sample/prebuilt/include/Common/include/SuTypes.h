//
// Copyright (c) 2016 Advanced Micro Devices, Inc. All rights reserved.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//

#ifndef _SUTYPES_H
#define _SUTYPES_H

// DEFINES ===============================================================================================================================================
//#define SU_USE_NATIVE_STL // Defining this will make it so SuList, SuAlgorithm, etc. are all implemented
                            // using the native underlying STL implementation


#if defined( SUSHI_DLL_EXPORT )
   // for exporting symbols from a DLL (used to build the core DLL)
   #define SU_DLL   __declspec(dllexport)
#elif defined( SUSHI_DLL_IMPORT )
   // for importing symbols from a DLL (used to build the engine and plugins)
   #define SU_DLL   __declspec(dllimport)
#else
   // for static linking, used to build the tools
   #define SU_DLL 
#endif





// TYPEDEFS ==============================================================================================================================================
#if defined( _WINDOWS ) || defined( WIN32 )
   //======================================================
   // 32-bit Windows using the Visual Studio 2005 compiler
   //======================================================

   // for TCHAR type
   #include <tchar.h>

   // tolua_begin

   //Signed
   typedef char char8;
   typedef wchar_t char16;

   typedef char    int8;
   typedef short   int16;
   typedef int     int32;
   typedef __int64 int64;

   typedef float       float32;
   typedef double      float64;

   //Unsigned
   typedef unsigned char    uint8;
   typedef unsigned short   uint16;
   typedef unsigned int     uint32;
   typedef unsigned __int64 uint64;

   //Handle
   // this used to be unsigned __int64, but I changed it because tolua was generating bad code for it -- JDB
   typedef __int64 SuHandle;

   //Time
   typedef double           SuTime;
   
   // tolua_end
#elif defined ( MACOSX )
   //=====================
   // MAC using GCC 4
   //=====================

   //#define SU_USE_NATIVE_STL
   
   //Signed
   typedef char char8;
   typedef wchar_t char16;
   typedef char TCHAR;  // no unicode

   typedef char  int8;
   typedef short int16;
   typedef int  int32;
   typedef long long int64;

   typedef float       float32;
   typedef double      float64;

   //Unsigned
   typedef unsigned char  uint8;
   typedef unsigned short uint16;
   typedef unsigned int  uint32;
   typedef unsigned long long  uint64;
   typedef unsigned long  LARGE_INTEGER;
   
   typedef unsigned int   UINT;
   
   // we need this definition for lua
   #define __int64 long long  

   //Handle
   typedef __int64 SuHandle;

   //Time
   typedef double           SuTime;
   
   #if defined (_T)
      #error "_T already defined. I'm confused."
   #else
      #define _T(x) (x)
   #endif

#elif defined(_LINUX)
   //=====================
   // Linux using GCC
   //=====================

#ifdef __cplusplus
   #include <cstddef>
#endif

   //Signed
   typedef char char8;
   typedef wchar_t char16;
   typedef char TCHAR;  // no unicode

   typedef char      int8;
   typedef short     int16;
   typedef int       int32;
   typedef long long int64;

   typedef long long __int64;

   typedef float     float32;
   typedef double    float64;

   //Unsigned
   typedef unsigned char      uint8;
   typedef unsigned short     uint16;
   typedef unsigned int       uint32;
   typedef unsigned long long uint64;

   //Handle
   typedef unsigned long long SuHandle;

   //Time
   typedef double           SuTime;   

   #if defined (_T)
      #error "_T already defined. I'm confused."
   #else
      #define _T(x) (x)
   #endif

#elif defined (__SYMBIAN32__)
   
   //======================
   // SYMBIAN using GCC 2.9
   //======================
   #include <stddef.h>

   //Signed
   typedef char char8;
   typedef wchar_t char16;
#ifdef _UNICODE
   typedef wchar_t TCHAR;  
#else
   typedef char TCHAR;
#endif

   typedef char      int8;
   typedef short     int16;
   typedef int       int32;
   typedef long long int64;

   typedef float     float32;
   typedef double    float64;

   //Unsigned
   typedef unsigned char      uint8;
   typedef unsigned short     uint16;
   typedef unsigned int       uint32;
   typedef unsigned long long uint64;

   //Handle
   typedef unsigned long long SuHandle;

   //Time
   typedef double           SuTime;   

   #if defined (_T)
      #error "_T already defined. I'm confused."
   #else
      #define _T(x) (x)
   #endif

#endif

#include "SuString.h"

#endif // _SUTYPES_H
