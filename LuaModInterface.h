#pragma once
#include <Windows.h>
#include <string>
#include <sol.hpp>

using namespace std;

class LuaModInterface {
public:
	void init(sol::state& lua);
};
