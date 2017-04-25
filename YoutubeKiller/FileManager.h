#pragma once
#include <string>

class FileManager
{
public:
	FileManager();

	void save(const std::string& fileName, int day, double timeOnYoutube);

	double load(const std::string& fileName, int day);

	~FileManager();
};

