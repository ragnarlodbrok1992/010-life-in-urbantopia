@echo off
SET compiler_dir="C:\Program Files (x86)\Microsoft Visual Studio\2022\BuildTools\VC\Tools\MSVC\14.31.31103\bin\Hostx64\x64\cl.exe"
SET sdl_include_dir="D:\libraries\SDL2-2.28.2\include"
SET sdl_link_dir="D:\libraries\SDL2-2.28.2\lib\x64"
SET sdl_dll_dir="D:\libraries\SDL2-2.28.2\lib\x64"

REM Create build directory if not exists
IF NOT EXIST build mkdir build

pushd build

REM Compile

REM Copy SDL2.dll to build directory
copy %sdl_dll_dir%\SDL2.dll .

%compiler_dir% /EHsc /Zi^
  /DEBUG:FULL^
  /INCREMENTAL:NO^
  /Fe:"life-in-urbantopia"^
  ../src/main.cpp^
  /I%sdl_include_dir%^
  /link /LIBPATH:%sdl_link_dir% SDL2.lib

popd
