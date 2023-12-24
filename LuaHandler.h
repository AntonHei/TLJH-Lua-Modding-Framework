#pragma once
#include <Windows.h>
#include <string>

using namespace std;

class LuaHandler {
public:
	void init();
	void loadFile(string rootPath, string filePath);
	void LuaHandler::tick();
};
