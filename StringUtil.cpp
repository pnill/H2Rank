// StringUtil.cpp: implementation of the CStringUtil class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "StringUtil.h"
 
 #include <tchar.h>
 #include <stdio.h> 
 #include <stdarg.h>
 

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CStringUtil::CStringUtil()
{

}

CStringUtil::~CStringUtil()
{

}
   
 //-----------------------------------------------------------------------------
 // Name: ConvertAnsiStringToWide()
 // Desc: This is a UNICODE conversion utility to convert a CHAR string into a
 //       WCHAR string. cchDestChar defaults -1 which means it 
 //       assumes strDest is large enough to store strSource
 //-----------------------------------------------------------------------------
void CStringUtil::ConvertAnsiStringToWide( WCHAR* wstrDestination, const CHAR* strSource, 
                                      int cchDestChar )
 {
     if( wstrDestination==NULL || strSource==NULL )
         return;
 
     if( cchDestChar == -1 )
         cchDestChar = strlen(strSource)+1;
 
     MultiByteToWideChar( CP_ACP, 0, strSource, -1, 
                          wstrDestination, cchDestChar-1 );
 
     wstrDestination[cchDestChar-1] = 0;
 }
 
 
 
 
 //-----------------------------------------------------------------------------
 // Name: ConvertWideStringToAnsi()
 // Desc: This is a UNICODE conversion utility to convert a WCHAR string into a
 //       CHAR string. cchDestChar defaults -1 which means it 
 //       assumes strDest is large enough to store strSource
 //-----------------------------------------------------------------------------
void CStringUtil::ConvertWideStringToAnsi( CHAR* strDestination, const WCHAR* wstrSource, 
                                      int cchDestChar )
 {
     if( strDestination==NULL || wstrSource==NULL )
         return;
 
     if( cchDestChar == -1 )
         cchDestChar = wcslen(wstrSource)+1;
 
     WideCharToMultiByte( CP_ACP, 0, wstrSource, -1, strDestination, 
                          cchDestChar-1, NULL, NULL );
 
     strDestination[cchDestChar-1] = 0;
 }
 
 
 
 
 //-----------------------------------------------------------------------------
 // Name:	ConvertGenericStringToAnsi()
 // Desc: This is a UNICODE conversion utility to convert a TCHAR string into a
 //       CHAR string. cchDestChar defaults -1 which means it 
 //       assumes strDest is large enough to store strSource
 //-----------------------------------------------------------------------------
 void CStringUtil::ConvertGenericStringToAnsi( CHAR* strDestination, const TCHAR* tstrSource, 
                                         int cchDestChar )
 {
     if( strDestination==NULL || tstrSource==NULL || cchDestChar == 0 )
         return;
 
 #ifdef _UNICODE
     ConvertWideStringToAnsi( strDestination, tstrSource, cchDestChar );
 #else
     if( cchDestChar == -1 )
     {
         strcpy( strDestination, tstrSource );
     }
     else
     {
         strncpy( strDestination, tstrSource, cchDestChar );
         strDestination[cchDestChar-1] = '\0';
     }
 #endif
 }
 
 
 
 
 //-----------------------------------------------------------------------------
 // Name: ConvertGenericStringToWide()
 // Desc: This is a UNICODE conversion utility to convert a TCHAR string into a
 //       WCHAR string. cchDestChar defaults -1 which means it 
 //       assumes strDest is large enough to store strSource
 //-----------------------------------------------------------------------------
 void CStringUtil::ConvertGenericStringToWide( WCHAR* wstrDestination, const TCHAR* tstrSource, 
                                         int cchDestChar )
 {
     if( wstrDestination==NULL || tstrSource==NULL || cchDestChar == 0 )
         return;
 
 #ifdef _UNICODE
     if( cchDestChar == -1 )
     {
         wcscpy( wstrDestination, tstrSource );
     }
     else
     {
         wcsncpy( wstrDestination, tstrSource, cchDestChar );
         wstrDestination[cchDestChar-1] = L'\0';
     }
 #else
     ConvertAnsiStringToWide( wstrDestination, tstrSource, cchDestChar );
 #endif
 }
 
 
 
 
 //-----------------------------------------------------------------------------
 // Name: ConvertAnsiStringToGeneric()
 // Desc: This is a UNICODE conversion utility to convert a CHAR string into a
 //       TCHAR string. cchDestChar defaults -1 which means it 
 //       assumes strDest is large enough to store strSource
 //-----------------------------------------------------------------------------
 void CStringUtil::ConvertAnsiStringToGeneric( TCHAR* tstrDestination, const CHAR* strSource, 
                                         int cchDestChar )
 {
     if( tstrDestination==NULL || strSource==NULL || cchDestChar == 0 )
         return;
         
 #ifdef _UNICODE
     ConvertAnsiStringToWide( tstrDestination, strSource, cchDestChar );
 #else
     if( cchDestChar == -1 )
     {
         strcpy( tstrDestination, strSource );
     }
     else
     {
         strncpy( tstrDestination, strSource, cchDestChar );
         tstrDestination[cchDestChar-1] = '\0';
     }
 #endif
 }
 
 
 
 
 //-----------------------------------------------------------------------------
 // Name: ConvertAnsiStringToGeneric()
 // Desc: This is a UNICODE conversion utility to convert a WCHAR string into a
 //       TCHAR string. cchDestChar defaults -1 which means it 
 //       assumes strDest is large enough to store strSource
 //-----------------------------------------------------------------------------
 void CStringUtil::ConvertWideStringToGeneric( TCHAR* tstrDestination, const WCHAR* wstrSource, 
                                         int cchDestChar )
 {
     if( tstrDestination==NULL || wstrSource==NULL || cchDestChar == 0 )
         return;
 
 #ifdef _UNICODE
     if( cchDestChar == -1 )
     {
         wcscpy( tstrDestination, wstrSource );
     }
     else
     {
         wcsncpy( tstrDestination, wstrSource, cchDestChar );
         tstrDestination[cchDestChar-1] = L'\0';
     }
 #else
     ConvertWideStringToAnsi( tstrDestination, wstrSource, cchDestChar );
 #endif
 }
 
 
 
 
 //-----------------------------------------------------------------------------
 // Name: ConvertStringToGUID()
 // Desc: Converts a string to a GUID
 //-----------------------------------------------------------------------------
 BOOL CStringUtil::ConvertStringToGUID( const TCHAR* strIn, GUID* pGuidOut )
 {
     UINT aiTmp[10];
 
     if( _stscanf( strIn, TEXT("{%8X-%4X-%4X-%2X%2X-%2X%2X%2X%2X%2X%2X}"),
                     &pGuidOut->Data1, 
                     &aiTmp[0], &aiTmp[1], 
                     &aiTmp[2], &aiTmp[3],
                     &aiTmp[4], &aiTmp[5],
                     &aiTmp[6], &aiTmp[7],
                     &aiTmp[8], &aiTmp[9] ) != 11 )
     {
         ZeroMemory( pGuidOut, sizeof(GUID) );
         return FALSE;
     }
     else
     {
         pGuidOut->Data2       = (USHORT) aiTmp[0];
         pGuidOut->Data3       = (USHORT) aiTmp[1];
         pGuidOut->Data4[0]    = (BYTE) aiTmp[2];
         pGuidOut->Data4[1]    = (BYTE) aiTmp[3];
         pGuidOut->Data4[2]    = (BYTE) aiTmp[4];
         pGuidOut->Data4[3]    = (BYTE) aiTmp[5];
         pGuidOut->Data4[4]    = (BYTE) aiTmp[6];
         pGuidOut->Data4[5]    = (BYTE) aiTmp[7];
         pGuidOut->Data4[6]    = (BYTE) aiTmp[8];
         pGuidOut->Data4[7]    = (BYTE) aiTmp[9];
         return TRUE;
     }
 }
 
 
 
 
 //-----------------------------------------------------------------------------
 // Name: ConvertGUIDToString()
 // Desc: Converts a GUID to a string 
 //-----------------------------------------------------------------------------
 void CStringUtil::ConvertGUIDToString( const GUID* pGuidIn, TCHAR* strOut )
 {
     _stprintf( strOut, TEXT("{%0.8X-%0.4X-%0.4X-%0.2X%0.2X-%0.2X%0.2X%0.2X%0.2X%0.2X%0.2X}"),
                pGuidIn->Data1, pGuidIn->Data2, pGuidIn->Data3,
                pGuidIn->Data4[0], pGuidIn->Data4[1],
                pGuidIn->Data4[2], pGuidIn->Data4[3],
                pGuidIn->Data4[4], pGuidIn->Data4[5],
                pGuidIn->Data4[6], pGuidIn->Data4[7] );
 }
 
      
