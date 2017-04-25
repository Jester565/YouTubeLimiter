#include "Timer.h"


Timer::Timer()
{
	lastTime = GetNow();
	lastDay = getDay();
}

Timer::~Timer()
{
}
