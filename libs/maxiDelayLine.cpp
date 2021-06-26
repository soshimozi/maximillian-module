#include "maximilian.h"
#include "maxiDelayLine.hpp"

namespace maximilian
{

//Delay with feedback
maxiDelayline::maxiDelayline() {
	memset(memory, 0, 88200 * sizeof(double));
}


double maxiDelayline::dl(double input, int size, double feedback) {
	if (phase >= size) {
		phase = 0;
	}
	output = memory[phase];
	memory[phase] = (memory[phase] * feedback) + (input * feedback) * 0.5;
	phase += 1;
	return(output);

}

double maxiDelayline::dl(double input, int size, double feedback, int position) {
	if (phase >= size) phase = 0;
	if (position >= size) position = 0;
	output = memory[position];
	memory[phase] = (memory[phase] * feedback) + (input * feedback) * chandiv;
	phase += 1;
	return(output);

}
	
}