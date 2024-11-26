#ifndef _xbrackets_lng_h_
#define _xbrackets_lng_h_
//---------------------------------------------------------------------------
#include "base.h"
#include <windows.h>

#define XBR_STR_PLUGINSTATUSACTIVE    1
#define XBR_STR_PLUGINSTATUSNOTACTIVE 2
#define XBR_STR_HINTAUTOCOMPLHGLT     3
#define XBR_STRCOUNT                  3

// lng funcs
void xbrSetSettingsDlgLang(HWND hDlg, LANGID sysLangId);
const wchar_t* xbrGetStrW(unsigned int strId, LANGID sysLangId);
void xbrSetAutocompleteWindowText(HWND hDlg, LANGID sysLangId);

#ifdef XBR_OLD_WINDOWS
const char* xbrGetStrA(unsigned int strId, LANGID sysLangId);
#endif

//---------------------------------------------------------------------------
#endif
