#pragma once

namespace maximilian {
	
class maxiEnvelope {
	
	double period_=0;
	double output_;
    double phase_;
	double start_val_;
    double end_val_;
	double currentval_;
	double nextval_;
    bool note_on_;
    bool release_mode_;
    bool decay_mode_;
    bool sustain_mode_;
    bool attack_mode_;
	int is_playing_;

public:
    int trig;
	double line(int /*numberofsegments*/,double /*segments*/[100]);
    double ramp(double /*startVal=0*/, double /*endVal=1*/, double /*duration=1*/);
    double ramps(std::vector<double> /*rampsArray*/);
    double ar(double /*attack=0.1*/, double /*release=0.1*/);
    double adsr(double /*attack=0.1*/, double /*decay=0.1*/, double /*sustain=0.1*/, double /*release=0.1*/);
	void trigger(int /*index*/,double /*amp*/);
    void trigger(bool /*noteOn=false*/);
	int valindex;
	double amplitude;
};

}