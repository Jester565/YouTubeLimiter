#pragma once
#include <string>
#include <chrono>

class Timer;
class FileManager;
class ActivityManager;

class YouTubeManager
{
public:
	const static std::string WINDOW_NAME;
	const static std::string FILE_NAME;
	const static size_t TIME_LIMIT;
	const static std::chrono::milliseconds SLEEP_MILLIS;

	YouTubeManager();

	void run();

	~YouTubeManager();

private:
	void terminateYoutube();

	double ytTime;
	double savedytTime;
	ActivityManager* activityManager;
	Timer* youtubeTimer;
	Timer* saveTimer;
	FileManager* fileManager;
};

