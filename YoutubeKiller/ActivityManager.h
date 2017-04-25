#pragma once
#include <Windows.h>
#include <string>

class ActivityDetector;
class AudioDetector;

class ActivityManager
{
public:
	ActivityManager();
	void update();
	bool isActive(std::string name, bool exact, bool media);
	~ActivityManager();
private:
	double lastActivityTime;
	std::string activeWindowName;
	ActivityDetector* activityDetector;
	AudioDetector* audioDetector;
};
