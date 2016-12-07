// StringUtil.h: interface for the CStringUtil class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STRINGUTIL_H__68D95375_3CF2_4883_8A32_E93EE2108995__INCLUDED_)
#define AFX_STRINGUTIL_H__68D95375_3CF2_4883_8A32_E93EE2108995__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CStringUtil  
{
public:
	CStringUtil();
	virtual ~CStringUtil();
	//-----------------------------------------------------------------------------
 // UNICODE support for converting between CHAR, TCHAR, and WCHAR strings
 //-----------------------------------------------------------------------------
 void ConvertAnsiStringToWide( WCHAR* wstrDestination, const CHAR* strSource, int cchDestChar = -1 );
 void ConvertWideStringToAnsi( CHAR* strDestination, const WCHAR* wstrSource, int cchDestChar = -1 );
 void ConvertGenericStringToAnsi( CHAR* strDestination, const TCHAR* tstrSource, int cchDestChar = -1 );
 void ConvertGenericStringToWide( WCHAR* wstrDestination, const TCHAR* tstrSource, int cchDestChar = -1 );
 void ConvertAnsiStringToGeneric( TCHAR* tstrDestination, const CHAR* strSource, int cchDestChar = -1 );
 void ConvertWideStringToGeneric( TCHAR* tstrDestination, const WCHAR* wstrSource, int cchDestChar = -1 );
 
 
 
 
 //-----------------------------------------------------------------------------
 // GUID to String converting 
 //-----------------------------------------------------------------------------
 void ConvertGUIDToString( const GUID* pGuidIn, TCHAR* strOut );
 BOOL ConvertStringToGUID( const TCHAR* strIn, GUID* pGuidOut );


};

#endif // !defined(AFX_STRINGUTIL_H__68D95375_3CF2_4883_8A32_E93EE2108995__INCLUDED_)
