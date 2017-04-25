#include "ActivityDetector.h"

ActivityDetector::ActivityDetector()
	:counter(0), lastTickCount(0)
{
}

int ActivityDetector::getInactiveMiliSeconds()
{
	LASTINPUTINFO info;
	info.cbSize = sizeof(info);
	GetLastInputInfo(&info);
	if (info.dwTime != lastTickCount)
	{
		counter = 0;
		lastTickCount = info.dwTime;
	}
	counter += t.getAndResetTime();
	return counter;
}

ActivityDetector::~ActivityDetector()
{
}
