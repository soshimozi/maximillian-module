#pragma once

namespace maximilian {
	
class maxiOsc {
	
	double frequency_;
	double phase_;
	double startphase_;
	double endphase_;
	double output_;
	double tri_;
	
	
public:
	maxiOsc();
	double sinewave(double /*frequency*/);
	double coswave(double /*frequency*/);
	double phasor(double /*frequency*/);
	double phasor(double /*frequency*/, double /*startphase*/, double /*endphase*/);
	double saw(double /*frequency*/);
	double triangle(double /*frequency*/);
	double square(double /*frequency*/);
	double pulse(double /*frequency*/, double /*duty*/);
	double noise();
	double sinebuf(double /*frequency*/);
	double sinebuf4(double /*frequency*/);
    double sawn(double /*frequency*/);
    double rect(double /*frequency*/, double /* duty=0.5*/);
	void phaseReset(double /*phaseIn*/);
	
};

}