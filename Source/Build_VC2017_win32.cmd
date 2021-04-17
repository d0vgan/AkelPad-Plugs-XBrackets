call "%ProgramFiles(x86)%\Microsoft Visual Studio\2017\Community\VC\Auxiliary\Build\vcvarsall.bat" x86
msbuild XBrackets_vc2017.sln /t:Clean /p:Configuration=Release;Platform=Win32
msbuild XBrackets_vc2017.sln /t:Build /p:Configuration=Release;Platform=Win32

@echo off

if exist .\Release\XBrackets.dll goto CopyDll
echo.
echo FAILED: XBrackets.dll has not been built!
goto End

:CopyDll
echo.
echo OK: Copying XBrackets.dll to ..\Plugs
copy .\Release\XBrackets.dll ..\Plugs /Y

:End
