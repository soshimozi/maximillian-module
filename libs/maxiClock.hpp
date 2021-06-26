#pragma once
#include "maximilian.h"
#include "maxiOsc.hpp"

namespace maximilian
{

 class maxiClock {
 public:
     maxiClock();
     void ticker();
     void setTempo(double bpm);
     void setTicksPerBeat(int ticksPerBeat);
     maxiOsc timer;
     int currentCount;
     int lastCount;
     int playHead;
     double bps;
     double bpm;
     int ticks;
     bool tick;
 };
	
}
