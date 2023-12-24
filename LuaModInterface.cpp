#include "LuaModInterface.h"

#include <windows.h>
#include <iostream>
#include <sol.hpp>

#include "TLJH.h"
#include "LuaHandler.h"

using namespace std;

TLJH* g_TLJH;

string getCredits() {
    return g_TLJH->getCredits();
}

string getMissionDay() {
    return g_TLJH->getMissionDay();
}

string getShipPaintjob() {
    return g_TLJH->getShipPaintjob();
}

string getJumpCount() {
    return g_TLJH->getJumpCount();
}

string getDifficultyLevel() {
    return to_string(g_TLJH->getDifficultyLevel());
}

string getSeedName() {
    return g_TLJH->getSeedName();
}

string getShipType() {
    return g_TLJH->getShipType();
}

void LuaModInterface::init(sol::state& lua)
{
    cout << "[LuaModInterface] Loading Lua Mod Interface" << endl;

    lua.set_function("getCredits", &getCredits);
    lua.set_function("getMissionDay", &getMissionDay);
    lua.set_function("getShipPaintjob", &getShipPaintjob);
    lua.set_function("getJumpCount", &getJumpCount);
    lua.set_function("getDifficultyLevel", &getDifficultyLevel);
    lua.set_function("getSeedName", &getSeedName);
    lua.set_function("getShipType", &getShipType);
}
