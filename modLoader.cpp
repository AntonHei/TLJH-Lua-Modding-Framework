#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING 1;
#include "modLoader.h"

#include <fstream>
#include <iostream>
#include <experimental/filesystem>

#include "Utils.h"
#include "LuaHandler.h"

Utils* g_Utils_2;
LuaHandler* g_LuaHandler;

string modFolder_Path = "\\mods\\";

string curPath = g_Utils_2->getExecutablePath() + modFolder_Path;

void modLoader::init() {

    const std::experimental::filesystem::path modFolderPath { curPath };

    if (!std::experimental::filesystem::is_directory(curPath) || !std::experimental::filesystem::exists(curPath)) {
        std::experimental::filesystem::create_directory(curPath);
        cout << "[ModLoader] Created Directory: " << curPath << endl;
    }

    g_LuaHandler->init();

    for (auto const& dir_entry : std::experimental::filesystem::directory_iterator{ modFolderPath })
    {
        std::experimental::filesystem::path curmodPath = dir_entry.path();
        g_LuaHandler->loadFile(curmodPath.string(), curmodPath.string() + "\\" + "index.lua");
    }

}

void modLoader::tick() {
    
    g_LuaHandler->tick();

}