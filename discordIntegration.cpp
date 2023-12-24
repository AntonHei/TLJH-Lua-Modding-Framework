#include "discordIntegration.h"
#include "TLJH.h"

#include <iostream>
#include <Windows.h>

using namespace std;

TLJH * g_game;

// Runtime Data
time_t discordrp_time_start;

void discordIntegration::init() {
	//cout << "Discord Integration started" << endl;

	g_game->init();

	DiscordEventHandlers Handler;
	memset(&Handler, 0, sizeof(Handler));
	string discordAppId = g_game->getGeneralConfigData("discord_app_id");
	Discord_Initialize(discordAppId.c_str(), &Handler, 1, NULL);

	discordrp_time_start = time(0);
}

void discordIntegration::update() {
	//cout << "Discord Integration updated" << endl;

	string details = g_game->getDiscordRPDetails();
	string state = g_game->getDiscordRPState();

	string largeImageKey = g_game->getDiscordRPLargeImageKey();
	string smallImageKey = g_game->getDiscordRPSmallImageKey();

	string largeImageText = g_game->getDiscordRPLargeImageText();
	string smallImageText = g_game->getDiscordRPSmallImageText();

	DiscordRichPresence discordPresence;
	memset(&discordPresence, 0, sizeof(discordPresence));

	discordPresence.state = state.c_str();
	discordPresence.details = details.c_str();

	discordPresence.largeImageKey = largeImageKey.c_str();
	discordPresence.largeImageText = largeImageText.c_str();

	discordPresence.smallImageKey = smallImageKey.c_str();
	discordPresence.smallImageText = smallImageText.c_str();

	discordPresence.startTimestamp = discordrp_time_start;

	Discord_UpdatePresence(&discordPresence);
}
