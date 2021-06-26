#pragma once

#include "maximilian.h"

namespace maximilian {

class maxiDyn {


public:
	//	double gate(double input, double threshold=0.9, long holdtime=1, double attack=1, double release=0.9995);
	//	double compressor(double input, double ratio, double threshold=0.9, double attack=1, double release=0.9995);
	double gate(double input, double threshold = 0.9, long holdtime = 1, double attack = 1, double release = 0.9995);
	double compressor(double input, double ratio, double threshold = 0.9, double attack = 1, double release = 0.9995);
	double compress(double input);
	double Input;
	double Ratio;
	double CurrentRatio;
	double Threshold;
	double Output;
	double Attack;
	double Release;
	double Amplitude;
	void setAttack(double attackMS);
	void setRelease(double releaseMS);
	void setThreshold(double thresholdI);
	void setRatio(double ratioF);
	long Holdtime;
	long Holdcount;
	int Attackphase;
	int Holdphase;
	int Releasephase;
};

}