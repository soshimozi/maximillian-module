#include "maxiFlanger.hpp"

namespace maximilian
{

inline double maxiFlanger::flange(const double input, const unsigned int delay, const double feedback, const double speed, const double depth)
 {
     //todo: needs fixing
     double output;
     double lfoVal = lfo.triangle(speed);
     output = dl.dl(input, delay + (lfoVal * depth * delay) + 1, feedback) ;    
     double normalise = (1 - fabs(output));
     output *= normalise;
     return (output + input) / 2.0;
 }
	
}