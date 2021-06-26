#include "maxiChorus.hpp"

namespace maximilian
{

inline double maxiChorus::chorus(const double input, const unsigned int delay, const double feedback, const double speed, const double depth)
{
     //this needs fixing
    double output1, output2;
    double lfoVal = lfo.noise();
    lfoVal = lopass.lores(lfoVal, speed, 1.0) * 2.0;
    output1 = dl.dl(input, delay + (lfoVal * depth * delay) + 1, feedback) ;    
    output2 = dl2.dl(input, (delay + (lfoVal * depth * delay * 1.02) + 1) * 0.98, feedback * 0.99) ;    
    output1 *= (1.0 - fabs(output1));
    output2 *= (1.0 - fabs(output2));
    return (output1 + output2 + input) / 3.0;
}
	
}