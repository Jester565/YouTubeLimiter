#pragma once
#include <windows.h>
#include <mmdeviceapi.h>
#include <endpointvolume.h>
#include <iostream>

class AudioDetector
{
public:

	AudioDetector();
	bool soundPlaying();
	~AudioDetector();
private:
	void checkError(HRESULT hr);
	IAudioMeterInformation* aInfo;
};

