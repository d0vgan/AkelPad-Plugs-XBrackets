#include "SettingsDlg.h"
#include "AnyWindow.h"
#include "resource.h"
#include "c_base/types.h"
#include "Plugin.h"
#include "XBracketsLng.h"

extern HWND        g_hMainWnd;
extern BOOL        g_bOldWindows;
extern BOOL        g_bInitialized;
extern LANGID      g_LangSystem;

extern BOOL        bBracketsAutoComplete;
extern UINT        uBracketsHighlight;
extern BOOL        bBracketsHighlightVisibleArea;
extern BOOL        bBracketsRightExistsOK;
extern BOOL        bBracketsDoSingleQuote;
extern BOOL        bBracketsDoTag;
extern BOOL        bBracketsDoTag2;
extern BOOL        bBracketsDoTagIf;
extern BOOL        bBracketsSkipEscaped;
extern BOOL        bBracketsSkipComment1;
extern COLORREF    bracketsColourHighlight[2];
extern COLORREF    g_CustomColoursHighlight[MAX_CUSTOM_COLOURS];
extern char        strHtmlFileExtsA[STR_FILEEXTS_SIZE];
extern wchar_t     strHtmlFileExtsW[STR_FILEEXTS_SIZE];
extern char        strEscaped1FileExtsA[STR_FILEEXTS_SIZE];
extern wchar_t     strEscaped1FileExtsW[STR_FILEEXTS_SIZE];
extern char        strComment1FileExtsA[STR_FILEEXTS_SIZE];
extern wchar_t     strComment1FileExtsW[STR_FILEEXTS_SIZE];
extern wchar_t     strPluginFuncMainW[STR_PLUGINFUNC_SIZE];

BOOL CheckBox_IsChecked(HWND hDlg, UINT idCheckBox);
BOOL CheckBox_SetCheck(HWND hDlg, UINT idCheckBox, BOOL bChecked);
BOOL DlgItem_EnableWindow(HWND hDlg, UINT idDlgItem, BOOL bEnable);
BOOL DlgItem_SetText(HWND hDlg, UINT idDlgItem, BOOL bUnicode, const void* pszText);

BOOL SettingsDlg_OnOK(HWND hDlg);
void SettingsDlg_OnBtColor(HWND hDlg, UINT uButtonID);
void SettingsDlg_OnChBracketsAutoCompleteClicked(HWND hDlg);
void SettingsDlg_OnChBracketsHighlightClicked(HWND hDlg);
void SettingsDlg_OnChBracketsDoTagClicked(HWND hDlg);
void SettingsDlg_OnChBracketsDoTagIfClicked(HWND hDlg);
void SettingsDlg_OnChBracketsSkipComment1(HWND hDlg);
void SettingsDlg_OnDrawItem(HWND hDlg, UINT uControlID, DRAWITEMSTRUCT* pDis);
void SettingsDlg_OnStPluginStateDblClicked(HWND hDlg);
void SettingsDlg_OnInitDialog(HWND hDlg);

void SettingsDlg_UpdateStateOfChBrackets(HWND hDlg, BOOL bInvert);

INT_PTR CALLBACK SettingsDlgProc(
  HWND   hDlg, 
  UINT   uMessage, 
  WPARAM wParam, 
  LPARAM lParam)
{
  static COLORREF bracketsColourHighlight_0[2] = { 0, 0 };

  if (uMessage == WM_COMMAND)
  {
    switch (LOWORD(wParam)) 
    {
      case IDC_CH_BRACKETS_HIGHLIGHT:
      {
        if (HIWORD(wParam) == BN_CLICKED)
        {
          SettingsDlg_UpdateStateOfChBrackets(hDlg, TRUE);
          SettingsDlg_OnChBracketsHighlightClicked(hDlg);
        }
        break;
      }
      case IDC_CH_BRACKETCOLOR:
      case IDC_CH_BKGNDCOLOR:
      {
        if (HIWORD(wParam) == BN_CLICKED)
        {
          SettingsDlg_UpdateStateOfChBrackets(hDlg, FALSE);
        }
        break;
      }
      case IDC_CH_BRACKETS_AUTOCOMPLETE:
      {
        if (HIWORD(wParam) == BN_CLICKED)
        {
          SettingsDlg_OnChBracketsAutoCompleteClicked(hDlg);
        }
        break;
      }
      case IDC_CH_BRACKETS_DOTAG:
      {
        if (HIWORD(wParam) == BN_CLICKED)
        {
          SettingsDlg_OnChBracketsDoTagClicked(hDlg);
        }
        break;
      }
      case IDC_CH_BRACKETS_DOTAGIF:
      {
        if (HIWORD(wParam) == BN_CLICKED)
        {
          SettingsDlg_OnChBracketsDoTagIfClicked(hDlg);
        }
        break;
      }
      case IDC_CH_BRACKETS_SKIPCOMMENT1:
      {
        if (HIWORD(wParam) == BN_CLICKED)
        {
          SettingsDlg_OnChBracketsSkipComment1(hDlg);
        }
        break;
      }
      case IDC_ST_PLUGINSTATE:
      {
        if (HIWORD(wParam) == STN_DBLCLK)
        {
          SettingsDlg_OnStPluginStateDblClicked(hDlg);
        }
        break;
      }
      case IDC_BT_BRACKETCOLOR:
      case IDC_BT_BKGNDCOLOR:
      {
        SettingsDlg_OnBtColor(hDlg, LOWORD(wParam));
        break;
      }
      case IDC_BT_OK: // Run
      case IDOK:
      {
        if (SettingsDlg_OnOK(hDlg))
        {
          EndDialog(hDlg, 1); // OK - returns 1
        }
        return 1;
      }
      case IDC_BT_CANCEL: // Cancel
      case IDCANCEL:
      {
        bracketsColourHighlight[0] = bracketsColourHighlight_0[0];
        bracketsColourHighlight[1] = bracketsColourHighlight_0[1];
        EndDialog(hDlg, 0); // Cancel - returns 0
        return 1;
      }
      default:
        break;
    }
  }

  else if (uMessage == WM_DRAWITEM)
  {
    SettingsDlg_OnDrawItem(hDlg, (UINT)wParam, (DRAWITEMSTRUCT*)lParam);
    return TRUE;
  }

  else if (uMessage == WM_NOTIFY)
  {
    
  }

  else if (uMessage == WM_INITDIALOG)
  {
    bracketsColourHighlight_0[0] = bracketsColourHighlight[0];
    bracketsColourHighlight_0[1] = bracketsColourHighlight[1];
    SettingsDlg_OnInitDialog(hDlg);
  }

  return 0;
}

BOOL SettingsDlg_OnOK(HWND hDlg)
{
  HWND hEd;

  hEd = GetDlgItem(hDlg, IDC_ED_BRACKETS_DOTAGIF);
  if (hEd)
  {
    if (g_bOldWindows)
      GetWindowTextA(hEd, strHtmlFileExtsA, STR_FILEEXTS_SIZE - 1);
    else
      GetWindowTextW(hEd, strHtmlFileExtsW, STR_FILEEXTS_SIZE - 1);
  }

  hEd = GetDlgItem(hDlg, IDC_ED_BRACKETS_SKIPCOMMENT1);
  if (hEd)
  {
    if (g_bOldWindows)
      GetWindowTextA(hEd, strComment1FileExtsA, STR_FILEEXTS_SIZE - 1);
    else
      GetWindowTextW(hEd, strComment1FileExtsW, STR_FILEEXTS_SIZE - 1);
  }

  bBracketsAutoComplete = 
    CheckBox_IsChecked(hDlg, IDC_CH_BRACKETS_AUTOCOMPLETE);
  uBracketsHighlight = 0x00;
  if (CheckBox_IsChecked(hDlg, IDC_CH_BRACKETS_HIGHLIGHT))
    uBracketsHighlight |= BRHLF_ENABLED;
  if (CheckBox_IsChecked(hDlg, IDC_CH_BRACKETCOLOR))
    uBracketsHighlight |= BRHLF_TEXT;
  if (CheckBox_IsChecked(hDlg, IDC_CH_BKGNDCOLOR))
    uBracketsHighlight |= BRHLF_BKGND;
  bBracketsHighlightVisibleArea =
    CheckBox_IsChecked(hDlg, IDC_CH_BRACKETS_HIGHLIGHT_VISIBLEAREA);
  bBracketsRightExistsOK = 
    CheckBox_IsChecked(hDlg, IDC_CH_BRACKETS_RIGHTEXISTS_OK);
  bBracketsDoSingleQuote = 
    CheckBox_IsChecked(hDlg, IDC_CH_BRACKETS_DOSINGLEQUOTE);
  bBracketsDoTag = 
    CheckBox_IsChecked(hDlg, IDC_CH_BRACKETS_DOTAG);
  bBracketsDoTag2 = 
    CheckBox_IsChecked(hDlg, IDC_CH_BRACKETS_DOTAG2);
  bBracketsDoTagIf = 
    CheckBox_IsChecked(hDlg, IDC_CH_BRACKETS_DOTAGIF);
  bBracketsSkipEscaped =
    CheckBox_IsChecked(hDlg, IDC_CH_BRACKETS_SKIPESCAPED);
  bBracketsSkipComment1 = 
    CheckBox_IsChecked(hDlg, IDC_CH_BRACKETS_SKIPCOMMENT1);
  
  return TRUE;
}

void SettingsDlg_OnBtColor(HWND hDlg, UINT uButtonID)
{
  COLORREF  localCustomColoursHighlight[MAX_CUSTOM_COLOURS];
  COLORREF* lpcrColor;
  HWND      hWndButton;
  int       i;

  for (i = 0; i < MAX_CUSTOM_COLOURS; i++)
  {
    localCustomColoursHighlight[i] = g_CustomColoursHighlight[i];
  }

  switch (uButtonID)
  {
    case IDC_BT_BRACKETCOLOR:
      lpcrColor = &bracketsColourHighlight[0];
      hWndButton = GetDlgItem(hDlg, IDC_BT_BRACKETCOLOR);
      break;
    case IDC_BT_BKGNDCOLOR:
      lpcrColor = &bracketsColourHighlight[1];
      hWndButton = GetDlgItem(hDlg, IDC_BT_BKGNDCOLOR);
      break;
    default:
      lpcrColor = NULL;
      hWndButton = NULL;
      break;
  }

  if (lpcrColor)
  {
    i = 0;

    if (g_bOldWindows)
    {
      CHOOSECOLORA ccA = { 0 };

      ccA.lStructSize  = sizeof(CHOOSECOLORA);
      ccA.hwndOwner    = hDlg;
      ccA.lpCustColors = localCustomColoursHighlight;
      ccA.Flags        = CC_FULLOPEN | CC_RGBINIT;
      ccA.rgbResult    = *lpcrColor;

      if (ChooseColorA(&ccA))
      {
        *lpcrColor = ccA.rgbResult;
        i = 1;
      }
    }
    else
    {
      CHOOSECOLORW ccW = { 0 };

      ccW.lStructSize  = sizeof(CHOOSECOLORW);
      ccW.hwndOwner    = hDlg;
      ccW.lpCustColors = localCustomColoursHighlight;
      ccW.Flags        = CC_FULLOPEN | CC_RGBINIT;
      ccW.rgbResult    = *lpcrColor;

      if (ChooseColorW(&ccW))
      {
        *lpcrColor = ccW.rgbResult;
        i = 1;
      }
    }

    if (i != 0)
    {
      for (i = 0; i < MAX_CUSTOM_COLOURS; i++)
      {
        g_CustomColoursHighlight[i] = localCustomColoursHighlight[i];
      }

      InvalidateRect(hWndButton, NULL, FALSE);
    }
  }
}

void SettingsDlg_OnChBracketsAutoCompleteClicked(HWND hDlg)
{
  BOOL bEnable = CheckBox_IsChecked(hDlg, IDC_CH_BRACKETS_AUTOCOMPLETE);
  DlgItem_EnableWindow(hDlg, IDC_CH_BRACKETS_RIGHTEXISTS_OK, bEnable);
}

void SettingsDlg_OnChBracketsHighlightClicked(HWND hDlg)
{
  BOOL bEnable = CheckBox_IsChecked(hDlg, IDC_CH_BRACKETS_HIGHLIGHT);
  DlgItem_EnableWindow(hDlg, IDC_CH_BRACKETS_HIGHLIGHT_VISIBLEAREA, bEnable);
  DlgItem_EnableWindow(hDlg, IDC_CH_BRACKETCOLOR, bEnable);
  DlgItem_EnableWindow(hDlg, IDC_BT_BRACKETCOLOR, bEnable);
  DlgItem_EnableWindow(hDlg, IDC_CH_BKGNDCOLOR, bEnable);
  DlgItem_EnableWindow(hDlg, IDC_BT_BKGNDCOLOR, bEnable);
}

void SettingsDlg_OnChBracketsDoTagClicked(HWND hDlg)
{
  BOOL bEnable = CheckBox_IsChecked(hDlg, IDC_CH_BRACKETS_DOTAG);
  DlgItem_EnableWindow(hDlg, IDC_CH_BRACKETS_DOTAG2, bEnable);
  DlgItem_EnableWindow(hDlg, IDC_CH_BRACKETS_DOTAGIF, bEnable);
  if (bEnable)
  {
    bEnable = CheckBox_IsChecked(hDlg, IDC_CH_BRACKETS_DOTAGIF);
  }
  DlgItem_EnableWindow(hDlg, IDC_ED_BRACKETS_DOTAGIF, bEnable);
}

void SettingsDlg_OnChBracketsDoTagIfClicked(HWND hDlg)
{
  BOOL bEnable = CheckBox_IsChecked(hDlg, IDC_CH_BRACKETS_DOTAGIF);
  DlgItem_EnableWindow(hDlg, IDC_ED_BRACKETS_DOTAGIF, bEnable);
}

void SettingsDlg_OnChBracketsSkipComment1(HWND hDlg)
{
  BOOL bEnable = CheckBox_IsChecked(hDlg, IDC_CH_BRACKETS_SKIPCOMMENT1);
  DlgItem_EnableWindow(hDlg, IDC_ED_BRACKETS_SKIPCOMMENT1, bEnable);
  DlgItem_EnableWindow(hDlg, IDC_ST_BRACKETS_SKIPCOMMENT1, bEnable);
}

void SettingsDlg_OnDrawItem(HWND hDlg, UINT uControlID, DRAWITEMSTRUCT* pDis)
{
  HBRUSH   hBrush;
  COLORREF dwColor;

  switch (uControlID)
  {
    case IDC_BT_BRACKETCOLOR:
      dwColor = bracketsColourHighlight[0];
      break;
    case IDC_BT_BKGNDCOLOR:
      dwColor = bracketsColourHighlight[1];
      break;
    default:
      dwColor = GetSysColor(COLOR_BTNFACE);
      break;
  }
    
  if (hBrush = CreateSolidBrush(dwColor))
  {
    FillRect(pDis->hDC, &pDis->rcItem, hBrush);
    if (pDis->hwndItem == GetFocus())
      DrawFocusRect(pDis->hDC, &pDis->rcItem);
    DeleteObject(hBrush);
  }
}

void showPluginStatus(HWND hDlg)
{
  if (g_bOldWindows)
  {
    DlgItem_SetText(hDlg, IDC_ST_PLUGINSTATE, FALSE,
      g_bInitialized ? xbrGetStrA(XBR_STR_PLUGINSTATUSACTIVE, g_LangSystem) : 
        xbrGetStrA(XBR_STR_PLUGINSTATUSNOTACTIVE, g_LangSystem) );
  }
  else
  {
    DlgItem_SetText(hDlg, IDC_ST_PLUGINSTATE, TRUE,
      g_bInitialized ? xbrGetStrW(XBR_STR_PLUGINSTATUSACTIVE, g_LangSystem) :
        xbrGetStrW(XBR_STR_PLUGINSTATUSNOTACTIVE, g_LangSystem) );
  }
}

void SettingsDlg_OnStPluginStateDblClicked(HWND hDlg)
{
  BOOL bDoInitializeHere = TRUE;
  
  if (g_bInitialized)
  {
    Uninitialize(FALSE); 
    bDoInitializeHere = FALSE;
  }
  
  if (g_bOldWindows)
  {
    if (bDoInitializeHere)
    {
      // XBrackets::Main is unloaded, let's load it
      PLUGINCALLSENDA pcsA;
      pcsA.pFunction = (char *) strPluginFuncMainW;
      //pcsA.bOnStart = FALSE;
      pcsA.lParam = 0;
      pcsA.dwSupport = 0;
      SendMessageA( g_hMainWnd, AKD_DLLCALLA, 0, (LPARAM) &pcsA );
    }
    else
    {
      PLUGINFUNCTION* pfA = (PLUGINFUNCTION *) SendMessageA( g_hMainWnd, 
        AKD_DLLFINDA, (WPARAM) strPluginFuncMainW, 0 );
      if (pfA) 
      { 
        pfA->bRunning = FALSE; 
      }
    }
  }
  else
  {
    if (bDoInitializeHere)
    {
      // XBrackets::Main is unloaded, let's load it
      PLUGINCALLSENDW pcsW;
      pcsW.pFunction = (wchar_t *) strPluginFuncMainW;
      //pcsW.bOnStart = FALSE;
      pcsW.lParam = 0;
      pcsW.dwSupport = 0;
      SendMessageW( g_hMainWnd, AKD_DLLCALLW, 0, (LPARAM) &pcsW );
    }
    else
    {
      PLUGINFUNCTION* pfW = (PLUGINFUNCTION *) SendMessageW( g_hMainWnd,
        AKD_DLLFINDW, (WPARAM) strPluginFuncMainW, 0 );
      if (pfW)
      {
        pfW->bRunning = FALSE;
      } 
    }
  }
 
  showPluginStatus(hDlg);
}

void SettingsDlg_OnInitDialog(HWND hDlg)
{
  HWND hEd;
  BOOL bEnable;

  xbrSetSettingsDlgLang(hDlg, g_LangSystem);

  AnyWindow_CenterWindow(hDlg, g_hMainWnd, FALSE);

  CheckBox_SetCheck(hDlg, 
    IDC_CH_BRACKETS_AUTOCOMPLETE, bBracketsAutoComplete);
  CheckBox_SetCheck(hDlg, 
    IDC_CH_BRACKETS_RIGHTEXISTS_OK, bBracketsRightExistsOK);
  CheckBox_SetCheck(hDlg, 
    IDC_CH_BRACKETS_HIGHLIGHT, (uBracketsHighlight & BRHLF_ENABLED) != 0);
  CheckBox_SetCheck(hDlg, 
    IDC_CH_BRACKETS_HIGHLIGHT_VISIBLEAREA, bBracketsHighlightVisibleArea);
  CheckBox_SetCheck(hDlg,
    IDC_CH_BRACKETCOLOR, (uBracketsHighlight & BRHLF_TEXT) != 0);
  CheckBox_SetCheck(hDlg,
    IDC_CH_BKGNDCOLOR, (uBracketsHighlight & BRHLF_BKGND) != 0);
  SettingsDlg_UpdateStateOfChBrackets(hDlg, FALSE);
  CheckBox_SetCheck(hDlg, 
    IDC_CH_BRACKETS_DOSINGLEQUOTE, bBracketsDoSingleQuote);
  CheckBox_SetCheck(hDlg, 
    IDC_CH_BRACKETS_DOTAG, bBracketsDoTag);
  CheckBox_SetCheck(hDlg, 
    IDC_CH_BRACKETS_DOTAG2, bBracketsDoTag2);
  CheckBox_SetCheck(hDlg, 
    IDC_CH_BRACKETS_DOTAGIF, bBracketsDoTagIf);
  CheckBox_SetCheck(hDlg,
    IDC_CH_BRACKETS_SKIPESCAPED, bBracketsSkipEscaped);
  CheckBox_SetCheck(hDlg, 
    IDC_CH_BRACKETS_SKIPCOMMENT1, bBracketsSkipComment1);
  DlgItem_EnableWindow(hDlg, 
    IDC_CH_BRACKETS_RIGHTEXISTS_OK, bBracketsAutoComplete);
  bEnable = ((uBracketsHighlight & BRHLF_ENABLED) != 0);
  DlgItem_EnableWindow(hDlg, 
    IDC_CH_BRACKETS_HIGHLIGHT_VISIBLEAREA, bEnable);
  DlgItem_EnableWindow(hDlg, IDC_CH_BRACKETCOLOR, bEnable);
  DlgItem_EnableWindow(hDlg, IDC_BT_BRACKETCOLOR, bEnable);
  DlgItem_EnableWindow(hDlg, IDC_CH_BKGNDCOLOR, bEnable);
  DlgItem_EnableWindow(hDlg, IDC_BT_BKGNDCOLOR, bEnable);
  DlgItem_EnableWindow(hDlg, 
    IDC_ED_BRACKETS_SKIPCOMMENT1, bBracketsSkipComment1);
  DlgItem_EnableWindow(hDlg, 
    IDC_ST_BRACKETS_SKIPCOMMENT1, bBracketsSkipComment1);

  DlgItem_EnableWindow(hDlg, IDC_CH_BRACKETS_DOTAG2, bBracketsDoTag);
  DlgItem_EnableWindow(hDlg, IDC_CH_BRACKETS_DOTAGIF, bBracketsDoTag);
  DlgItem_EnableWindow(hDlg, IDC_ED_BRACKETS_DOTAGIF, 
      bBracketsDoTag ? bBracketsDoTagIf : FALSE);

  showPluginStatus(hDlg);
  
  hEd = GetDlgItem(hDlg, IDC_ED_BRACKETS_DOTAGIF);
  if (hEd)
  {
    SendMessage(hEd, EM_LIMITTEXT, (WPARAM) (STR_FILEEXTS_SIZE - 1), 0);
      
    if (g_bOldWindows)
      SetWindowTextA(hEd, strHtmlFileExtsA);
    else
      SetWindowTextW(hEd, strHtmlFileExtsW);
  }

  hEd = GetDlgItem(hDlg, IDC_ED_BRACKETS_SKIPCOMMENT1);
  if (hEd)
  {
    SendMessage(hEd, EM_LIMITTEXT, (WPARAM) (STR_FILEEXTS_SIZE - 1), 0);
      
    if (g_bOldWindows)
      SetWindowTextA(hEd, strComment1FileExtsA);
    else
      SetWindowTextW(hEd, strComment1FileExtsW);
  }

}

void SettingsDlg_UpdateStateOfChBrackets(HWND hDlg, BOOL bInvert)
{
  UINT uState;
  BOOL bChecked;
  
  uState = BST_UNCHECKED;
  bChecked = CheckBox_IsChecked(hDlg, IDC_CH_BRACKETS_HIGHLIGHT);
  if ((bChecked && !bInvert) || (bInvert && !bChecked))
  {
    if (CheckBox_IsChecked(hDlg, IDC_CH_BRACKETCOLOR) ||
        CheckBox_IsChecked(hDlg, IDC_CH_BKGNDCOLOR))
    {
      uState = BST_CHECKED;
    }
    else
    {
      uState = BST_INDETERMINATE;
    }
  }
  SendMessage(GetDlgItem(hDlg, IDC_CH_BRACKETS_HIGHLIGHT), 
    BM_SETCHECK, uState, 0);
}

//---------------------------------------------------------------------------

BOOL CheckBox_IsChecked(HWND hDlg, UINT idCheckBox)
{
  HWND hCheckBox = GetDlgItem(hDlg, idCheckBox);
  if (hCheckBox)
  {
    UINT uState = (UINT) SendMessage(hCheckBox, BM_GETCHECK, 0, 0);
    if (uState == BST_CHECKED || uState == BST_INDETERMINATE)
      return TRUE;
  }
  return FALSE;
}

BOOL CheckBox_SetCheck(HWND hDlg, UINT idCheckBox, BOOL bChecked)
{
  HWND hCheckBox = GetDlgItem(hDlg, idCheckBox);
  if (hCheckBox)
  {
    SendMessage(hCheckBox, BM_SETCHECK,
      (WPARAM) (bChecked ? BST_CHECKED : BST_UNCHECKED), 0);
    return TRUE;
  }
  return FALSE;
}

BOOL DlgItem_EnableWindow(HWND hDlg, UINT idDlgItem, BOOL bEnable)
{
  HWND hDlgItem = GetDlgItem(hDlg, idDlgItem);
  if (hDlgItem)
  {
    return EnableWindow(hDlgItem, bEnable);
  }
  return FALSE;
}

BOOL DlgItem_SetText(HWND hDlg, UINT idDlgItem, BOOL bUnicode, const void* pszText)
{
  HWND hDlgItem = GetDlgItem(hDlg, idDlgItem);
  if (hDlgItem)
  {
    if (!bUnicode)
      return SetWindowTextA(hDlgItem, (const char *) pszText);
    else
      return SetWindowTextW(hDlgItem, (const wchar_t *) pszText);
  }
  return FALSE;
}
