#ifndef _xbrackets_lng_h_
#define _xbrackets_lng_h_
//---------------------------------------------------------------------------
#include <windows.h>

#define XBR_STR_PLUGINSTATUSACTIVE    1
#define XBR_STR_PLUGINSTATUSNOTACTIVE 2
#define XBR_STRCOUNT                  2

// lng funcs
void xbrSetSettingsDlgLang(HWND hDlg, LANGID sysLangId);
const char* xbrGetStrA(unsigned int strId, LANGID sysLangId);
const wchar_t* xbrGetStrW(unsigned int strId, LANGID sysLangId);

//---------------------------------------------------------------------------
#endif
