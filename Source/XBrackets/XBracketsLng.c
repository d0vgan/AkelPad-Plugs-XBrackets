#include "XBracketsLng.h"
#include "resource.h"


extern BOOL g_bOldWindows;


typedef struct sDlgItemLngA {
    unsigned int id;
    const char*  text;
} tDlgItemLngA;

typedef struct sDlgItemLngW {
    unsigned int   id;
    const wchar_t* text;
} tDlgItemLngW;


/* ENG */
tDlgItemLngA xbrSettingsDlgItemsA_eng[] = 
{
    { IDC_CH_BRACKETS_AUTOCOMPLETE,          "Autocomplete brackets ([{\"\"}])"               },
    { IDC_CH_BRACKETS_HIGHLIGHT,             "Highlight brackets"                             },
    { IDC_CH_BRACKETS_HIGHLIGHT_VISIBLEAREA, "In visible area only"                           },
    { IDC_BT_OK,                             "OK"                                             },
    { IDC_BT_CANCEL,                         "Cancel"                                         },
    { IDC_CH_BRACKETCOLOR,                   "Brackets colour"                                },
    { IDC_CH_BRACKETS_RIGHTEXISTS_OK,        "Even if corresponding right bracket exists"     },
    { IDC_CH_BRACKETS_DOSINGLEQUOTE,         "Treat \' \' as brackets"                        },
    { IDC_CH_BRACKETS_DOTAG,                 "Treat < > as brackets"                          },
    { IDC_CH_BRACKETS_DOTAGIF,               "Only if file extension contains:"               },
    { IDC_CH_BRACKETS_DOTAG2,                "< />"                                           },
    { IDC_CH_BRACKETS_SKIPESCAPED,           "Skip escaped bracket characters: \\[, \\} etc." },
    { IDC_CH_BRACKETS_SKIPCOMMENT1,          "Skip brackets after // in these files:"         },
    { IDC_ST_BRACKETS_SKIPCOMMENT1,          "(c;cc;cpp;cxx;h;hh;hpp;hxx;pas - hardcoded)"    },
    { IDC_CH_BKGNDCOLOR,                     "Background"                                     },
    { 0,                                     0                                                }
};

tDlgItemLngW xbrSettingsDlgItemsW_eng[] = 
{
    { IDC_CH_BRACKETS_AUTOCOMPLETE,          L"Autocomplete brackets ([{\"\"}])"               },
    { IDC_CH_BRACKETS_HIGHLIGHT,             L"Highlight brackets"                             },
    { IDC_CH_BRACKETS_HIGHLIGHT_VISIBLEAREA, L"In visible area only"                           },
    { IDC_BT_OK,                             L"OK"                                             },
    { IDC_BT_CANCEL,                         L"Cancel"                                         },
    { IDC_CH_BRACKETCOLOR,                   L"Brackets colour"                                },
    { IDC_CH_BRACKETS_RIGHTEXISTS_OK,        L"Even if corresponding right bracket exists"     },
    { IDC_CH_BRACKETS_DOSINGLEQUOTE,         L"Treat \' \' as brackets"                        },
    { IDC_CH_BRACKETS_DOTAG,                 L"Treat < > as brackets"                          },
    { IDC_CH_BRACKETS_DOTAGIF,               L"Only if file extension contains:"               },
    { IDC_CH_BRACKETS_DOTAG2,                L"< />"                                           },
    { IDC_CH_BRACKETS_SKIPESCAPED,           L"Skip escaped bracket characters: \\[, \\} etc." },
    { IDC_CH_BRACKETS_SKIPCOMMENT1,          L"Skip brackets after // in these files:"         },
    { IDC_ST_BRACKETS_SKIPCOMMENT1,          L"(c;cc;cpp;cxx;h;hh;hpp;hxx;pas - hardcoded)"    },
    { IDC_CH_BKGNDCOLOR,                     L"Background"                                     },
    { 0,                                     0                                                 }
};

/* RUS */
tDlgItemLngA xbrSettingsDlgItemsA_rus[] = 
{
    { IDC_CH_BRACKETS_AUTOCOMPLETE,          "\xC0\xE2\xF2\xEE\xE7\xE0\xEA\xF0\xFB\xF2\xE8\xE5\x20\xF1\xEA\xEE\xE1\xEE\xEA ([{\"\"}])"            },
    { IDC_CH_BRACKETS_HIGHLIGHT,             "\xCF\xEE\xE4\xF1\xE2\xE5\xF7\xE8\xE2\xE0\xF2\xFC\x20\xF1\xEA\xEE\xE1\xEA\xE8"                       },
    { IDC_CH_BRACKETS_HIGHLIGHT_VISIBLEAREA, "\xD2\xEE\xEB\xFC\xEA\xEE\x20\xE2\x20\xE2\xE8\xE4\xE8\xEC\xEE\xE9\x20\xEE\xE1\xEB\xE0\xF1\xF2\xE8"   },
    { IDC_BT_OK,                             "OK"                                                                                                 },
    { IDC_BT_CANCEL,                         "\xCE\xF2\xEC\xE5\xED\xE0"                                                                           },
    { IDC_CH_BRACKETCOLOR,                   "\xD6\xE2\xE5\xF2\x20\xF1\xEA\xEE\xE1\xEE\xEA"                                                       },
    { IDC_CH_BRACKETS_RIGHTEXISTS_OK,        " \xC4\xE0\xE6\xE5\x20\xE5\xF1\xEB\xE8\x20\xEF\xF0\xE0\xE2\xE0\xFF\x20\xF1\xEA\xEE\xE1\xEA\xE0\x20\xF3\xE6\xE5\x20\xF1\xF3\xF9\xE5\xF1\xF2\xE2\xF3\xE5\xF2" },
    { IDC_CH_BRACKETS_DOSINGLEQUOTE,         "\xD1\xF7\xE8\xF2\xE0\xF2\xFC \' \' \xEF\xE0\xF0\xEE\xE9\x20\xF1\xEA\xEE\xE1\xEE\xEA"                },
    { IDC_CH_BRACKETS_DOTAG,                 "\xD1\xF7\xE8\xF2\xE0\xF2\xFC < > \xEF\xE0\xF0\xEE\xE9\x20\xF1\xEA\xEE\xE1\xEE\xEA"                  },
    { IDC_CH_BRACKETS_DOTAGIF,               "\xD2\xEE\xEB\xFC\xEA\xEE\x20\xE5\xF1\xEB\xE8\x20\xF0\xE0\xF1\xF8\xE8\xF0\xE5\xED\xE8\xE5\x20\xF4\xE0\xE9\xEB\xE0\x20\xF1\xEE\xE4\xE5\xF0\xE6\xE8\xF2:" },
    { IDC_CH_BRACKETS_DOTAG2,                "< />"                                                                                               },
    { IDC_CH_BRACKETS_SKIPESCAPED,           "\xCF\xF0\xEE\xEF\xF3\xF1\xEA\xE0\xF2\xFC\x20\xFD\xEA\xF0\xE0\xED\xE8\xF0\xEE\xE2\xE0\xED\xED\xFB\xE5\x20\xF1\xEA\xEE\xE1\xEA\xE8: \\[, \\} \xE8\x20\xF2\x2E\xE4\x2E" },
    { IDC_CH_BRACKETS_SKIPCOMMENT1,          "\xCF\xF0\xEE\xEF\xF3\xF1\xEA\xE0\xF2\xFC\x20\xF1\xEA\xEE\xE1\xEA\xE8\x20\xEF\xEE\xF1\xEB\xE5 // \xE2\x20\xF2\xE0\xEA\xE8\xF5\x20\xF4\xE0\xE9\xEB\xE0\xF5:" },
    { IDC_ST_BRACKETS_SKIPCOMMENT1,          "(\xE6\xB8\xF1\xF2\xEA\xEE\x20\xEF\xF0\xEE\xEF\xE8\xF1\xE0\xED\xFB:  c;cc;cpp;cxx;h;hh;hpp;hxx;pas)" },
    { IDC_CH_BKGNDCOLOR,                     "\xD6\xE2\xE5\xF2\x20\xF4\xEE\xED\xE0"                                                               },
    { 0,                                     0                                                                                                    }
};

tDlgItemLngW xbrSettingsDlgItemsW_rus[] = 
{
    { IDC_CH_BRACKETS_AUTOCOMPLETE,          L"\x0410\x0432\x0442\x043E\x0437\x0430\x043A\x0440\x044B\x0442\x0438\x0435\x0020\x0441\x043A\x043E\x0431\x043E\x043A ([{\"\"}])"                    },
    { IDC_CH_BRACKETS_HIGHLIGHT,             L"\x041F\x043E\x0434\x0441\x0432\x0435\x0447\x0438\x0432\x0430\x0442\x044C\x0020\x0441\x043A\x043E\x0431\x043A\x0438"                               },
    { IDC_CH_BRACKETS_HIGHLIGHT_VISIBLEAREA, L"\x0422\x043E\x043B\x044C\x043A\x043E\x0020\x0432\x0020\x0432\x0438\x0434\x0438\x043C\x043E\x0439\x0020\x043E\x0431\x043B\x0430\x0441\x0442\x0438" },
    { IDC_BT_OK,                             L"OK"                                                                                                                                               },
    { IDC_BT_CANCEL,                         L"\x041E\x0442\x043C\x0435\x043D\x0430"                                                                                                             },
    { IDC_CH_BRACKETCOLOR,                   L"\x0426\x0432\x0435\x0442\x0020\x0441\x043A\x043E\x0431\x043E\x043A"                                                                               },
    { IDC_CH_BRACKETS_RIGHTEXISTS_OK,        L" \x0414\x0430\x0436\x0435\x0020\x0435\x0441\x043B\x0438\x0020\x043F\x0440\x0430\x0432\x0430\x044F\x0020\x0441\x043A\x043E\x0431\x043A\x0430\x0020\x0443\x0436\x0435\x0020\x0441\x0443\x0449\x0435\x0441\x0442\x0432\x0443\x0435\x0442" },
    { IDC_CH_BRACKETS_DOSINGLEQUOTE,         L"\x0421\x0447\x0438\x0442\x0430\x0442\x044C \' \' \x043F\x0430\x0440\x043E\x0439\x0020\x0441\x043A\x043E\x0431\x043E\x043A"                        },
    { IDC_CH_BRACKETS_DOTAG,                 L"\x0421\x0447\x0438\x0442\x0430\x0442\x044C < > \x043F\x0430\x0440\x043E\x0439\x0020\x0441\x043A\x043E\x0431\x043E\x043A"                          },
    { IDC_CH_BRACKETS_DOTAGIF,               L"\x0422\x043E\x043B\x044C\x043A\x043E\x0020\x0435\x0441\x043B\x0438\x0020\x0440\x0430\x0441\x0448\x0438\x0440\x0435\x043D\x0438\x0435\x0020\x0444\x0430\x0439\x043B\x0430\x0020\x0441\x043E\x0434\x0435\x0440\x0436\x0438\x0442:" },
    { IDC_CH_BRACKETS_DOTAG2,                L"< />"                                                                                                                                             },
    { IDC_CH_BRACKETS_SKIPESCAPED,           L"\x041F\x0440\x043E\x043F\x0443\x0441\x043A\x0430\x0442\x044C\x0020\x044D\x043A\x0440\x0430\x043D\x0438\x0440\x043E\x0432\x0430\x043D\x043D\x044B\x0435\x0020\x0441\x043A\x043E\x0431\x043A\x0438: \\[, \\} \x0438\x0020\x0442\x002E\x0434\x002E" },
    { IDC_CH_BRACKETS_SKIPCOMMENT1,          L"\x041F\x0440\x043E\x043F\x0443\x0441\x043A\x0430\x0442\x044C\x0020\x0441\x043A\x043E\x0431\x043A\x0438\x0020\x043F\x043E\x0441\x043B\x0435 // \x0432\x0020\x0442\x0430\x043A\x0438\x0445\x0020\x0444\x0430\x0439\x043B\x0430\x0445:" },
    { IDC_ST_BRACKETS_SKIPCOMMENT1,          L"(\x0436\x0451\x0441\x0442\x043A\x043E\x0020\x043F\x0440\x043E\x043F\x0438\x0441\x0430\x043D\x044B:  c;cc;cpp;cxx;h;hh;hpp;hxx;pas)"               },
    { IDC_CH_BKGNDCOLOR,                     L"\x0426\x0432\x0435\x0442\x0020\x0444\x043E\x043D\x0430"                                                                                           },
    { 0,                                     0                                                                                                                                                   }
};

/* UKR */
tDlgItemLngA xbrSettingsDlgItemsA_ukr[] = 
{
    { IDC_CH_BRACKETS_AUTOCOMPLETE,          "\xC0\xE2\xF2\xEE\xE7\xE0\xEA\xF0\xE8\xF2\xF2\xFF\x20\xE4\xF3\xE6\xEE\xEA ([{\"\"}])"                    },
    { IDC_CH_BRACKETS_HIGHLIGHT,             "\xCF\xB3\xE4\xF1\xE2\xB3\xF7\xF3\xE2\xE0\xF2\xE8\x20\xE4\xF3\xE6\xEA\xE8"                               },
    { IDC_CH_BRACKETS_HIGHLIGHT_VISIBLEAREA, "\xD2\xB3\xEB\xFC\xEA\xE8\x20\xF3\x20\xE2\xE8\xE4\xE8\xEC\xB3\xE9\x20\xEE\xE1\xEB\xE0\xF1\xF2\xB3"       },
    { IDC_BT_OK,                             "OK"                                                                                                     },
    { IDC_BT_CANCEL,                         "\xD1\xEA\xE0\xF1\xF3\xE2\xE0\xF2\xE8"                                                                   },
    { IDC_CH_BRACKETCOLOR,                   "\xCA\xEE\xEB\xB3\xF0\x20\xE4\xF3\xE6\xEE\xEA"                                                           },
    { IDC_CH_BRACKETS_RIGHTEXISTS_OK,        " \xCD\xE0\xE2\xB3\xF2\xFC\x20\xFF\xEA\xF9\xEE\x20\xEF\xF0\xE0\xE2\xE0\x20\xE4\xF3\xE6\xEA\xE0\x20\xE2\xE6\xE5\x20\xB3\xF1\xED\xF3\xBA" },
    { IDC_CH_BRACKETS_DOSINGLEQUOTE,         "\xC2\xE2\xE0\xE6\xE0\xF2\xE8 \' \' \xE7\xE0\x20\xEF\xE0\xF0\xF3\x20\xE4\xF3\xE6\xEE\xEA"                },
    { IDC_CH_BRACKETS_DOTAG,                 "\xC2\xE2\xE0\xE6\xE0\xF2\xE8 < > \xE7\xE0\x20\xEF\xE0\xF0\xF3\x20\xE4\xF3\xE6\xEE\xEA"                  },
    { IDC_CH_BRACKETS_DOTAGIF,               "\xD2\xB3\xEB\xFC\xEA\xE8\x20\xFF\xEA\xF9\xEE\x20\xF0\xEE\xE7\xF8\xE8\xF0\xE5\xED\xED\xFF\x20\xF4\xE0\xE9\xEB\xE0\x20\xEC\xB3\xF1\xF2\xE8\xF2\xFC:" },
    { IDC_CH_BRACKETS_DOTAG2,                "< />"                                                                                                   },
    { IDC_CH_BRACKETS_SKIPESCAPED,           "\xCF\xF0\xEE\xEF\xF3\xF1\xEA\xE0\xF2\xE8\x20\xE5\xEA\xF0\xE0\xED\xEE\xE2\xE0\xED\xB3\x20\xE4\xF3\xE6\xEA\xE8: \\[, \\} \xB3\x20\xF2\x2E\xE4\x2E" },
    { IDC_CH_BRACKETS_SKIPCOMMENT1,          "\xCF\xF0\xEE\xEF\xF3\xF1\xEA\xE0\xF2\xE8\x20\xE4\xF3\xE6\xEA\xE8\x20\xEF\xB3\xF1\xEB\xFF // \xE2\x20\xF2\xE0\xEA\xE8\xF5\x20\xF4\xE0\xE9\xEB\xE0\xF5:" },
    { IDC_ST_BRACKETS_SKIPCOMMENT1,          "(\xE6\xEE\xF0\xF1\xF2\xEA\xEE\x20\xEF\xF0\xEE\xEF\xE8\xF1\xE0\xED\xB3:  c;cc;cpp;cxx;h;hh;hpp;hxx;pas)" },
    { IDC_CH_BKGNDCOLOR,                     "\xCA\xEE\xEB\xB3\xF0\x20\xF2\xEB\xE0"                                                                   },
    { 0,                                     0                                                                                                        }
};

tDlgItemLngW xbrSettingsDlgItemsW_ukr[] = 
{
    { IDC_CH_BRACKETS_AUTOCOMPLETE,          L"\x0410\x0432\x0442\x043E\x0437\x0430\x043A\x0440\x0438\x0442\x0442\x044F\x0020\x0434\x0443\x0436\x043E\x043A ([{\"\"}])"                          },
    { IDC_CH_BRACKETS_HIGHLIGHT,             L"\x041F\x0456\x0434\x0441\x0432\x0456\x0447\x0443\x0432\x0430\x0442\x0438\x0020\x0434\x0443\x0436\x043A\x0438"                                     },
    { IDC_CH_BRACKETS_HIGHLIGHT_VISIBLEAREA, L"\x0422\x0456\x043B\x044C\x043A\x0438\x0020\x0443\x0020\x0432\x0438\x0434\x0438\x043C\x0456\x0439\x0020\x043E\x0431\x043B\x0430\x0441\x0442\x0456" },
    { IDC_BT_OK,                             L"OK"                                                                                                                                               },
    { IDC_BT_CANCEL,                         L"\x0421\x043A\x0430\x0441\x0443\x0432\x0430\x0442\x0438"                                                                                           },
    { IDC_CH_BRACKETCOLOR,                   L"\x041A\x043E\x043B\x0456\x0440\x0020\x0434\x0443\x0436\x043E\x043A"                                                                               },
    { IDC_CH_BRACKETS_RIGHTEXISTS_OK,        L" \x041D\x0430\x0432\x0456\x0442\x044C\x0020\x044F\x043A\x0449\x043E\x0020\x043F\x0440\x0430\x0432\x0430\x0020\x0434\x0443\x0436\x043A\x0430\x0020\x0432\x0436\x0435\x0020\x0456\x0441\x043D\x0443\x0454" },
    { IDC_CH_BRACKETS_DOSINGLEQUOTE,         L"\x0412\x0432\x0430\x0436\x0430\x0442\x0438 \' \' \x0437\x0430\x0020\x043F\x0430\x0440\x0443\x0020\x0434\x0443\x0436\x043E\x043A"                  },
    { IDC_CH_BRACKETS_DOTAG,                 L"\x0412\x0432\x0430\x0436\x0430\x0442\x0438 < > \x0437\x0430\x0020\x043F\x0430\x0440\x0443\x0020\x0434\x0443\x0436\x043E\x043A"                    },
    { IDC_CH_BRACKETS_DOTAGIF,               L"\x0422\x0456\x043B\x044C\x043A\x0438\x0020\x044F\x043A\x0449\x043E\x0020\x0440\x043E\x0437\x0448\x0438\x0440\x0435\x043D\x043D\x044F\x0020\x0444\x0430\x0439\x043B\x0430\x0020\x043C\x0456\x0441\x0442\x0438\x0442\x044C:" },
    { IDC_CH_BRACKETS_DOTAG2,                L"< />"                                                                                                                                             },
    { IDC_CH_BRACKETS_SKIPESCAPED,           L"\x041F\x0440\x043E\x043F\x0443\x0441\x043A\x0430\x0442\x0438\x0020\x0435\x043A\x0440\x0430\x043D\x043E\x0432\x0430\x043D\x0456\x0020\x0434\x0443\x0436\x043A\x0438: \\[, \\} \x0456\x0020\x0442\x002E\x0434\x002E" },
    { IDC_CH_BRACKETS_SKIPCOMMENT1,          L"\x041F\x0440\x043E\x043F\x0443\x0441\x043A\x0430\x0442\x0438\x0020\x0434\x0443\x0436\x043A\x0438\x0020\x043F\x0456\x0441\x043B\x044F // \x0432\x0020\x0442\x0430\x043A\x0438\x0445\x0020\x0444\x0430\x0439\x043B\x0430\x0445:" },
    { IDC_ST_BRACKETS_SKIPCOMMENT1,          L"(\x0436\x043E\x0440\x0441\x0442\x043A\x043E\x0020\x043F\x0440\x043E\x043F\x0438\x0441\x0430\x043D\x0456:  c;cc;cpp;cxx;h;hh;hpp;hxx;pas)"         },
    { IDC_CH_BKGNDCOLOR,                     L"\x041A\x043E\x043B\x0456\x0440\x0020\x0442\x043B\x0430"                                                                                           },
    { 0,                                     0                                                                                                                                                   }
};


void xbrSetSettingsDlgLang(HWND hDlg, LANGID sysLangId)
{
    sysLangId = PRIMARYLANGID(sysLangId);
    
    if ( g_bOldWindows )
    {
        const tDlgItemLngA* pDIL;
        HWND hDlgItem;

        if ( sysLangId == LANG_RUSSIAN )
            pDIL = xbrSettingsDlgItemsA_rus;
        else if ( sysLangId == LANG_UKRAINIAN )
            pDIL = xbrSettingsDlgItemsA_ukr;
        else
            pDIL = xbrSettingsDlgItemsA_eng;

        while ( pDIL->id != 0 )
        {
            hDlgItem = GetDlgItem(hDlg, pDIL->id);
            if ( hDlgItem )
            {
                SetWindowTextA(hDlgItem, pDIL->text);
            }
            ++pDIL;
        }
    }
    else
    {
        const tDlgItemLngW* pDIL;
        HWND hDlgItem;

        if ( sysLangId == LANG_RUSSIAN )
            pDIL = xbrSettingsDlgItemsW_rus;
        else if ( sysLangId == LANG_UKRAINIAN )
            pDIL = xbrSettingsDlgItemsW_ukr;
        else
            pDIL = xbrSettingsDlgItemsW_eng;

        while ( pDIL->id != 0 )
        {
            hDlgItem = GetDlgItem(hDlg, pDIL->id);
            if ( hDlgItem )
            {
                SetWindowTextW(hDlgItem, pDIL->text);
            }
            ++pDIL;
        }
    }
}

/* ENG */
const char* strA_eng[XBR_STRCOUNT] = 
{
    "Status: the plugin is active",
    "Status: the plugin is NOT active"
};

const wchar_t* strW_eng[XBR_STRCOUNT] = 
{
    L"Status: the plugin is active",
    L"Status: the plugin is NOT active"
};

/* RUS */
const char* strA_rus[XBR_STRCOUNT] = 
{
    "\xD1\xEE\xF1\xF2\xEE\xFF\xED\xE8\xE5\x3A\x20\xEF\xEB\xE0\xE3\xE8\xED\x20\xE0\xEA\xF2\xE8\xE2\xE5\xED",
    "\xD1\xEE\xF1\xF2\xEE\xFF\xED\xE8\xE5\x3A\x20\xEF\xEB\xE0\xE3\xE8\xED\x20\xCD\xC5\x20\xE0\xEA\xF2\xE8\xE2\xE5\xED"
};

const wchar_t* strW_rus[XBR_STRCOUNT] = 
{
    L"\x0421\x043E\x0441\x0442\x043E\x044F\x043D\x0438\x0435\x003A\x0020\x043F\x043B\x0430\x0433\x0438\x043D\x0020\x0430\x043A\x0442\x0438\x0432\x0435\x043D",
    L"\x0421\x043E\x0441\x0442\x043E\x044F\x043D\x0438\x0435\x003A\x0020\x043F\x043B\x0430\x0433\x0438\x043D\x0020\x041D\x0415\x0020\x0430\x043A\x0442\x0438\x0432\x0435\x043D"
};

/* UKR */
const char* strA_ukr[XBR_STRCOUNT] = 
{
    "\xD1\xF2\xE0\xED\x3A\x20\xEF\xEB\xE0\xE3\xB3\xED\x20\xE0\xEA\xF2\xE8\xE2\xED\xE8\xE9",
    "\xD1\xF2\xE0\xED\x3A\x20\xEF\xEB\xE0\xE3\xB3\xED\x20\xCD\xC5\x20\xE0\xEA\xF2\xE8\xE2\xED\xE8\xE9"
};

const wchar_t* strW_ukr[XBR_STRCOUNT] = 
{
    L"\x0421\x0442\x0430\x043D\x003A\x0020\x043F\x043B\x0430\x0433\x0456\x043D\x0020\x0430\x043A\x0442\x0438\x0432\x043D\x0438\x0439",
    L"\x0421\x0442\x0430\x043D\x003A\x0020\x043F\x043B\x0430\x0433\x0456\x043D\x0020\x041D\x0415\x0020\x0430\x043A\x0442\x0438\x0432\x043D\x0438\x0439"
};


const char* xbrGetStrA(unsigned int strId, LANGID sysLangId)
{
    sysLangId = PRIMARYLANGID(sysLangId);
    
    if ( strId > 0 && strId <= XBR_STRCOUNT )
    {
        if ( sysLangId == LANG_RUSSIAN )
            return strA_rus[strId - 1];
        else if ( sysLangId == LANG_UKRAINIAN )
            return strA_ukr[strId - 1];
        else
            return strA_eng[strId - 1];
    }

    return "";
}

const wchar_t* xbrGetStrW(unsigned int strId, LANGID sysLangId)
{
    sysLangId = PRIMARYLANGID(sysLangId);
    
    if ( strId > 0 && strId <= XBR_STRCOUNT )
    {
        if ( sysLangId == LANG_RUSSIAN )
            return strW_rus[strId - 1];
        else if ( sysLangId == LANG_UKRAINIAN )
            return strW_ukr[strId - 1];
        else
            return strW_eng[strId - 1];
    }

    return L"";
}
