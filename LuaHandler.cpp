#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING 1;
#define _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS 1;
#define SOL_USE_JIT 1;

#include "LuaHandler.h"

#include "LuaModInterface.h"
#include "Utils.h"
#include <iostream>

#pragma comment(lib, "lua51.lib")
#pragma comment(lib, "luajit.lib")

#include <lua.hpp>
#include <luajit/luajit.h>
#include <sol.hpp>

using namespace std;

Utils* g_Utils_3;
LuaModInterface* g_LMI;
sol::state lua;

struct TLJHData {
    string credits;
} TLJHData;

void LuaHandler::init()
{
    cout << "[LuaHandler] Loading Lua" << endl;
    lua.open_libraries();
}

void LuaHandler::loadFile(string rootPath, string filePath)
{
    cout << "[LuaHandler] Loading File: " << filePath << endl;

    std::string x = lua["package"]["path"];
    lua["package"]["path"] = rootPath + "\\?.lua";

    g_LMI->init(lua);

    sol::protected_function_result result = lua.safe_script_file(filePath, &sol::script_pass_on_error);

    if (!result.valid())
    {
        sol::error error = result;
        cout << error.what() << endl;
    }

    cout << "[LuaHandler] Loaded File: " << filePath << endl;
}

void LuaHandler::tick()
{
    //cout << "[LuaHandler] Tick" << endl;
    
    sol::function luaTick = lua["tick"];
    luaTick();
}
