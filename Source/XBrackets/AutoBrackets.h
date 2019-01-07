#ifndef _auto_brackets_h_
#define _auto_brackets_h_
//---------------------------------------------------------------------------
#include "base.h"
#include "AnyRichEdit.h"

#define MAX_USER_BRACKETS          31
#define MAX_PREV_NEXT_CHAR_OK_SIZE 96

#define DEFAULT_MAX_DETECT_DUPPAIR_LINES  1
#define DEFAULT_MAX_KNOWN_DUPPAIR_LINES  10

#define DEFAULT_MAX_BR_LINES 0

// highlight style flags
#define XBR_HSF_BOLDFONT     0x0001
#define XBR_HSF_REDRAWCODER  0x0002


typedef struct structMSGINFO {
  HWND   hWnd;
  UINT   uMsg;
  WPARAM wParam;
  LPARAM lParam;
} MSGINFO;

void  OnEditCharPressed(MSGINFO* pmsgi);
void  OnEditGetActiveBrackets(MSGINFO* pmsgi, const BOOL bAndHighlight /* = TRUE */);
void  OnEditHighlightActiveBrackets(void);
void  RemoveAllHighlightInfo(const BOOL bRepaint /* = TRUE */);
int   getFileType(int* pnCurrentFileType2);
void  AutoBrackets_Uninitialize(void);

void  setNextCharOkW(const wchar_t* cszNextCharOkW);
void  setPrevCharOkW(const wchar_t* cszPrevCharOkW);
void  setUserBracketsA(const char* cszUserBracketsA);
void  setUserBracketsW(const wchar_t* cszUserBracketsW);

const char*    getCurrentBracketsPairA(void);
const wchar_t* getCurrentBracketsPairW(void);

//---------------------------------------------------------------------------
#endif

