#include "ActivityManager.h"
#include "ActivityDetector.h"
#include "AudioDetector.h"
#include <algorithm>

ActivityManager::ActivityManager()
	:lastActivityTime(0), activeWindowName("")
{
	activityDetector = new ActivityDetector();
	audioDetector = new AudioDetector();
}

void ActivityManager::update()
{
	char wndTitle[256];
	HWND hwnd = GetForegroundWindow();
	GetWindowText(hwnd, wndTitle, 256);
	std::string wndTitleS(wndTitle, 256);
	std::transform(wndTitleS.begin(), wndTitleS.end(), wndTitleS.begin(), ::tolower);
	activeWindowName = wndTitleS;
	lastActivityTime = activityDetector->getInactiveMiliSeconds();
}

bool ActivityManager::isActive(std::string name, bool exact, bool media)
{
	return (lastActivityTime < 60000 || media && audioDetector->soundPlaying()) 
		&& (name == activeWindowName || !exact && activeWindowName.find(name) != -1);
}

ActivityManager::~ActivityManager()
{
	delete activityDetector;
	activityDetector = nullptr;
	delete audioDetector;
	audioDetector = nullptr;
}
