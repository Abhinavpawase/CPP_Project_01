@echo off

IF EXIST "App.exe" (
    del App.exe
)

g++ Main_File.cpp CPP_File_1.cpp -o App.exe

IF EXIST "App.exe" (
    echo Build Completed , Running exe ...
	App.exe
) ELSE (
    echo Build Unsuccessful ...
)
