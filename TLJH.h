#pragma once
#include <Windows.h>
#include <string>

#include "nlohmann/json.hpp"

using namespace std;
using json = nlohmann::json;

class TLJH {
public:
	void   init();
	string getCredits();
	string getMissionDay();
	string getShipPaintjob();
	string getJumpCount();
	int getDifficultyLevel();
	string getSeedName();
	string getShipType();
};
