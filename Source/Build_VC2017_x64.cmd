call "%ProgramFiles(x86)%\Microsoft Visual Studio\2017\Community\VC\Auxiliary\Build\vcvarsall.bat" x64
msbuild XBrackets_vc2017.sln /t:Clean /p:Configuration=Release;Platform=x64
msbuild XBrackets_vc2017.sln /t:Build /p:Configuration=Release;Platform=x64

@echo off

if exist .\x64\Release\XBrackets.dll goto CopyDll
echo.
echo FAILED: XBrackets.dll has not been built!
goto End

:CopyDll
echo.
echo OK: Copying XBrackets.dll to ..\Plugs64
copy .\x64\Release\XBrackets.dll ..\Plugs64 /Y

:End
