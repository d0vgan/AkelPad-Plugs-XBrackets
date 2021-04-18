@echo off

set VC_ROOT=%ProgramFiles(x86)%\Microsoft Visual Studio\2017

if exist "%VC_ROOT%\Professional\VC\Auxiliary\Build\vcvarsall.bat" goto UseVcProfessional
if exist "%VC_ROOT%\Community\VC\Auxiliary\Build\vcvarsall.bat" goto UseVcCommunity

goto ErrorNoVcVarsAll

:UseVcProfessional
call "%VC_ROOT%\Professional\VC\Auxiliary\Build\vcvarsall.bat" x86
goto Building

:UseVcCommunity
call "%VC_ROOT%\Community\VC\Auxiliary\Build\vcvarsall.bat" x86
goto Building

:Building
msbuild XBrackets_vc2017.sln /t:Clean /p:Configuration=Release;Platform=Win32
msbuild XBrackets_vc2017.sln /t:Build /p:Configuration=Release;Platform=Win32

if exist .\Release\XBrackets.dll goto CopyDll
echo.
echo Build FAILED: XBrackets.dll has not been built!
goto End

:CopyDll
echo.
echo Build OK: Copying XBrackets.dll to ..\Plugs
if not exist ..\Plugs\ mkdir ..\Plugs
copy .\Release\XBrackets.dll ..\Plugs\ /Y
goto End

:ErrorNoVcVarsAll
echo ERROR: Could not find "vcvarsall.bat"
goto End

:End
