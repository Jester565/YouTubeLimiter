#define WINDOWS_LEAN_AND_MEAN
#include "Timer.h"
#include <windows.h>
#include <iostream>

static const unsigned int IDLE_MILLISECONDS = 60 * 10 * 1000;
static const unsigned int INTERVAL = 60 * 60 * 1000;

class ActivityDetector
{
public:
	ActivityDetector();
	int getInactiveMiliSeconds();
	~ActivityDetector();
private:
	DWORD lastTickCount;
	DWORD counter;
	Timer t;
};
