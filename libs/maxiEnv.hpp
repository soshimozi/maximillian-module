#pragma once

#include "maximilian.h"

namespace maximilian
{

class maxiEnv {


public:
	double ar(double input, double attack=1, double release=0.9, long holdtime=1, int trigger=0);
	double adsr(double input, double attack=1, double decay=0.99, double sustain=0.125, double release=0.9, long holdtime=1, int trigger=0);
	double adsr(double input,int trigger);
	double Input;
	double Output;
	double Attack;
	double Decay;
	double Sustain;
	double Release;
	double Amplitude;
	void setAttack(double attackMS);
	void setRelease(double releaseMS);
	void setDecay(double decayMS);
	void setSustain(double sustainL);
	int Trigger;
	long Holdtime=1;
	long Holdcount;
	int Attackphase;
	int Decayphase;
	int Sustainphase;
	int Holdphase;
	int Releasephase;
 };
	
}