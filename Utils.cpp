#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING 1;
#include "Utils.h"

#include <fstream>
#include <iostream>
#include <windows.h>
#include <experimental/filesystem>

#include "nlohmann/json.hpp"
using json = nlohmann::json;

using namespace std;

std::string Utils::getExecutablePath() {

    char buffer[MAX_PATH];
    GetModuleFileNameA(NULL, buffer, MAX_PATH);
    std::string::size_type pos = std::string(buffer).find_last_of("\\/");
    std::string pathString = std::string(buffer).substr(0, pos);

    std::experimental::filesystem::path p = pathString;
    std::experimental::filesystem::path parent_p = p.parent_path().parent_path().parent_path();

    return parent_p.string();
}

HANDLE Utils::getHProcess() {

    DWORD procId = GetCurrentProcessId();
    HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, false, procId);

    return hProcess;
}

HWND Utils::getProcessHWND(HWND hwnd) {

    DWORD process;
    DWORD procId = GetCurrentProcessId();
    GetWindowThreadProcessId(hwnd, &process);

    return hwnd;
}

uintptr_t Utils::getMemoryAddressValue(uintptr_t memory_address, vector<unsigned int> offsets) {

    HANDLE hProcess = getHProcess();

    HANDLE handle = GetModuleHandleA("tljh-Win64-Shipping.exe");
    uintptr_t moduleBase = (uintptr_t)handle;

    uintptr_t address = moduleBase + memory_address;

    for (unsigned int i = 0; i < offsets.size(); ++i)
    {
        // Read and proceed
        ReadProcessMemory(hProcess, (BYTE*)address, &address, sizeof(address), 0);
        //cout << hex << address << " + " << hex << offsets[i] << endl;
        address += offsets[i];
    }

    return address;
}

json Utils::getJSONDataFromFile(string filePath) {

    std::string fullExePath = getExecutablePath();
    string jsonFilePath = fullExePath + "/data/" + filePath;
    std::ifstream ifs(jsonFilePath);

    json jsonData;
    try
    {
        jsonData = json::parse(ifs);
    }
    catch (nlohmann::detail::parse_error& ex)
    {
        cout << "JSON Parse failed: " << jsonFilePath << endl;
    }

    return jsonData;
}

string Utils::replace(std::string subject, const std::string& search, const std::string& replace) {
    size_t pos = 0;
    while ((pos = subject.find(search, pos)) != std::string::npos) {
        subject.replace(pos, search.length(), replace);
        pos += replace.length();
    }
    return subject;
}
