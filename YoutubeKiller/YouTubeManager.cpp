#include "YouTubeManager.h"
#include "Timer.h"
#include "FileManager.h"
#include "ActivityManager.h";
#include <functional>
#include <thread>
#include <iostream>

const std::string YouTubeManager::WINDOW_NAME = "youtube";
const std::string YouTubeManager::FILE_NAME = "ytube.txt";
const size_t YouTubeManager::TIME_LIMIT = 2700000;
const std::chrono::milliseconds YouTubeManager::SLEEP_MILLIS(5000);

YouTubeManager::YouTubeManager()
{
	youtubeTimer = new Timer();
	activityManager = new ActivityManager();
	fileManager = new FileManager();
	saveTimer = new Timer();
	ytTime = fileManager->load(FILE_NAME, youtubeTimer->getDay());
}

void YouTubeManager::run()
{
	while (true) {
		if (youtubeTimer->dayChanged()) {
			ytTime = 0;
		}
		activityManager->update();
		if (activityManager->isActive(WINDOW_NAME, false, true)) {
			ytTime += youtubeTimer->getAndResetTime();
			if (ytTime > TIME_LIMIT) {
				terminateYoutube();
				ytTime = TIME_LIMIT - 10000;
			}
		}
		else
		{
			youtubeTimer->resetTime();
		}
		std::cout << ytTime << std::endl;
		if (ytTime != savedytTime && saveTimer->getTime() > 60000) {
			fileManager->save(FILE_NAME, saveTimer->getDay(), ytTime);
			savedytTime = ytTime;
			saveTimer->resetTime();
		}
		std::this_thread::sleep_for(SLEEP_MILLIS);
	}
}

YouTubeManager::~YouTubeManager()
{
}

void YouTubeManager::terminateYoutube()
{
}
