#include "FileManager.h"
#include <string>
#include <fstream>

FileManager::FileManager()
{
}

void FileManager::save(const std::string& fileName, int day, double timeOnYoutube)
{
	std::ofstream fileOut(fileName);
	fileOut << day << std::endl << timeOnYoutube << std::endl;
}

double FileManager::load(const std::string& fileName, int day)
{
	std::ifstream fileIn(fileName);
	if (!fileIn.fail())
	{
		int lastDay;
		if (fileIn >> lastDay) {
			if (lastDay == day)
			{
				double lastTime = 0;
				if (fileIn >> lastTime) {
					return lastTime;
				}
			}
		}
	}
	return 0;
}

FileManager::~FileManager()
{
}
