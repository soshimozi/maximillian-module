#pragma once

namespace maximilian {
	
class maxiSettings {
public:
	static int sampleRate;
	static int channels;
	static int bufferSize;
	static void setup(int initSampleRate, int initChannels, int initBufferSize) {
		sampleRate = initSampleRate;
		channels = initChannels;
		bufferSize = initBufferSize;
	}
};

}