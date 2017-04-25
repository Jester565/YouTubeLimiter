#pragma once
#include <chrono>
#include <ctime>

typedef std::chrono::system_clock::time_point TimePoint;

static TimePoint GetNow() {
	return std::chrono::system_clock::now();
}

class Timer
{
public:
	Timer();

	double getAndResetTime()
	{
		TimePoint now = GetNow();
		double millis = std::chrono::duration_cast<std::chrono::milliseconds>(now - lastTime).count();
		lastTime = now;
		return millis;
	}

	double getTime()
	{
		TimePoint now = GetNow();
		double millis = std::chrono::duration_cast<std::chrono::milliseconds>(now - lastTime).count();
		return millis;
	}

	void resetTime()
	{
		TimePoint now = GetNow();
		double millis = std::chrono::duration_cast<std::chrono::milliseconds>(now - lastTime).count();
		lastTime = now;
	}

	bool dayChanged()
	{
		if (getDay() != lastDay)
		{
			lastDay = getDay();
			return true;
		}
		return false;
	}

	int getDay()
	{
		std::time_t t = time(0);
		struct tm* now = localtime(&t);
		return now->tm_mday;
	}
	~Timer();

private:
	TimePoint lastTime;
	int lastDay;
};

