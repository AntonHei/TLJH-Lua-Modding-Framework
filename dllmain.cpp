#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <Windows.h>
#include <conio.h>

#include "modLoader.h"

using namespace std;

modLoader* g_modLoader;

DWORD APIENTRY MainThread(HMODULE param) {

	AllocConsole();
	::ShowWindow(::GetConsoleWindow(), SW_SHOW);

	freopen("CONOUT$", "w", stdout);

	cout << "[Main] Integration started" << endl;

	g_modLoader->init();

	while (true) {
		g_modLoader->tick();
		Sleep(500);
	}

	FreeConsole();

	return 0;
}

bool APIENTRY DllMain(HINSTANCE hModule, DWORD dwReason, LPVOID lpReserved) {

	switch (dwReason) {
	case DLL_PROCESS_ATTACH:
		CreateThread(0, 0, (LPTHREAD_START_ROUTINE)MainThread, hModule, 0, 0);
		break;
	case DLL_PROCESS_DETACH:
		break;
	}

	return true;
}
