// pch.h: This is a precompiled header file.
// Files listed below are compiled only once, improving build performance for future builds.
// This also affects IntelliSense performance, including code completion and many code browsing features.
// However, files listed here are ALL re-compiled if any one of them is updated between builds.
// Do not add files here that you will be updating frequently as this negates the performance advantage.

#ifndef PCH_H
#define PCH_H
#define NOP 0x90 //NOP opcode in byte format

// add headers that you want to pre-compile here
#include <windows.h>
#include <iostream>
#include <cstdint>
#include <string>

//#include "base.h" //Own header file for often used struct and functions like Vector2 + memory functions and some hooks

#include "MinHook.h" //Hooking library https://github.com/TsudaKageyu/minhook

//library files for d3d9 and GUI
#include <d3d9.h>
#pragma comment(lib, "d3d9.lib")
#include <d3dx9.h>
//#pragma comment(lib, "d3dx9.lib")
#include "zgui.hh" //Really simple GUI library by zxvnme (https://github.com/zxvnme)

#endif //PCH_H
