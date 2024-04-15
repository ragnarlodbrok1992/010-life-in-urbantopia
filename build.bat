@echo off
SET compiler_dir="C:\Program Files (x86)\Microsoft Visual Studio\2022\BuildTools\VC\Tools\MSVC\14.31.31103\bin\Hostx64\x64\cl.exe"

REM Create build directory if not exists
IF NOT EXIST build mkdir build

pushd build

REM Compile

%compiler_dir% /EHsc /Zi^
  /DEBUG:FULL^
  /INCREMENTAL:NO^
  /Fe:"life-in-urbantopia"^
  ../src/main.cpp

popd
