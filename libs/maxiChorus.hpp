#pragma once

#include "maxiDelayLine.hpp"
#include "maxiFilter.hpp"
#include "maximilian.h"
#include "maxiOsc.hpp"

namespace maximilian
{

class maxiChorus {
public:
    //delay = delay time - ~800 sounds good
    //feedback = 0 - 1
    //speed = lfo speed in Hz, 0.0001 - 10 sounds good
    //depth = 0 - 1
    double chorus(const double input, const unsigned int delay, const double feedback, const double speed, const double depth);
    maxiDelayline dl, dl2;
    maxiOsc lfo;
    maxiFilter lopass;
};
	
}
