#include "TLJH.h"

#include <fstream>
#include <iostream>

#include "Utils.h"

using namespace std;

Utils* g_Utils;

// Runtime Variables
json generalConfig;
json languageJSONData;
json locationMappingjsonData;

void TLJH::init() {

}

// Game specific

string TLJH::getCredits() {

    uintptr_t address = g_Utils->getMemoryAddressValue(0x2842760, {0x1D8});

    // Get final value
    HANDLE hProcess = g_Utils->getHProcess();
    DWORD value;
    ReadProcessMemory(hProcess, (BYTE*)address, &value, sizeof(value), nullptr);

    return to_string((int)value);
}

string TLJH::getShipPaintjob() {

    uintptr_t address = g_Utils->getMemoryAddressValue(0x2842760, {0x110});

    // Get final value
    HANDLE hProcess = g_Utils->getHProcess();
    DWORD value;
    ReadProcessMemory(hProcess, (BYTE*)address, &value, sizeof(value), nullptr);

    return to_string((int)value);
}

string TLJH::getMissionDay() {

    uintptr_t address = g_Utils->getMemoryAddressValue(0x2842760, {0x114});

    // Get final value
    HANDLE hProcess = g_Utils->getHProcess();
    DWORD value;
    ReadProcessMemory(hProcess, (BYTE*)address, &value, sizeof(value), nullptr);

    return to_string((int)value);
}

string TLJH::getJumpCount() {

    uintptr_t address = g_Utils->getMemoryAddressValue(0x2842760, {0x548});

    // Get final value
    HANDLE hProcess = g_Utils->getHProcess();
    DWORD value;
    ReadProcessMemory(hProcess, (BYTE*)address, &value, sizeof(value), nullptr);

    return to_string((int)value);
}

int TLJH::getDifficultyLevel() {

    uintptr_t address = g_Utils->getMemoryAddressValue(0x2842760, {0x527});

    // Get final value
    HANDLE hProcess = g_Utils->getHProcess();
    DWORD value;
    ReadProcessMemory(hProcess, (BYTE*)address, &value, sizeof(value), nullptr);

    int difficultyLevel = (int)(BYTE)value;

    return difficultyLevel;
}

string TLJH::getSeedName() {

    uintptr_t address = g_Utils->getMemoryAddressValue(0x2842760, {0x100, 0x0});

    // Get final value
    HANDLE hProcess = g_Utils->getHProcess();
    wchar_t value[255]{0};
    ReadProcessMemory(hProcess, (BYTE*)address, &value, sizeof(value), nullptr);

    wstring ws(value);
    string seedName(ws.begin(), ws.end());

    return seedName;
}

string TLJH::getShipType() {

    uintptr_t address = g_Utils->getMemoryAddressValue(0x2842760, {0x248, 0x38});

    // Get final value
    HANDLE hProcess = g_Utils->getHProcess();
    DWORD value;
    ReadProcessMemory(hProcess, (BYTE*)address, &value, sizeof(value), nullptr);

    return to_string((int)value);
}
