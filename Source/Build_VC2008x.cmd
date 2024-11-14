REM Visual Studio 9.0 (2008) Express

@ECHO OFF
Set SdkProgramFiles=%ProgramFiles%
if "%ProgramFiles(x86)%" == "" goto programfiles_ok
Set ProgramFiles=%ProgramFiles(x86)%
:programfiles_ok
Set VCDIR=%ProgramFiles%\Microsoft Visual Studio 9.0\VC
Set VSCOMMON=%ProgramFiles%\Microsoft Visual Studio 9.0\Common7\IDE
Set MSSDK=%SdkProgramFiles%\Microsoft SDKs\Windows\v6.0A

REM if exist "%MSSDK%" goto sdk_ok
REM Set MSSDK=%VCDIR%\PlatformSDK
REM :sdk_ok

::###################################::
Set PATH=%VCDIR%\bin;%MSSDK%\bin;%VSCOMMON%;%PATH%
Set INCLUDE=%MSSDK%\include;%VCDIR%\include;%INCLUDE%
Set LIB=%MSSDK%\lib;%VCDIR%\lib;%LIB%

cd "%~dp0."
if not exist "..\Plugs" mkdir "..\Plugs"
cd .\XBrackets

rc /r /Fo"XBrackets.res" "XBrackets.rc"
cl /O1 /GS- AutoBrackets.c Plugin.c AnyRichEdit.c AnyWindow.c SettingsDlg.c XBracketsLng.c XMemStrFunc.c XBrackets.res /LD /link kernel32.lib user32.lib comctl32.lib gdi32.lib Comdlg32.lib /NODEFAULTLIB /ENTRY:DllMain /OUT:..\..\Plugs\XBrackets.dll

if exist XBrackets.res del XBrackets.res
if exist AutoBrackets.lib del AutoBrackets.lib
if exist AutoBrackets.exp del AutoBrackets.exp
if exist AutoBrackets.obj del AutoBrackets.obj
if exist AnyRichEdit.obj del AnyRichEdit.obj
if exist AnyWindow.obj del AnyWindow.obj
if exist HexStr.obj del HexStr.obj
if exist Plugin.obj del Plugin.obj
if exist SettingsDlg.obj del SettingsDlg.obj
if exist XBracketsLng.obj del XBracketsLng.obj
if exist XMemStrFunc.obj del XMemStrFunc.obj
@PAUSE
