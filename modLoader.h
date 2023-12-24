#pragma once
#include <Windows.h>
#include <string>

#include "nlohmann/json.hpp"

using namespace std;
using json = nlohmann::json;

class modLoader {
public:
	void init();
	void tick();
};
