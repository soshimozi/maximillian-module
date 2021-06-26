#pragma once

#include "maximilian.h"

namespace maximilian
{

class maxiFilter {
	double gain_;
	double input_;
	double output_;
	double inputs_[10];
	double outputs_[10];
	double cutoff1_;
	double x_;//speed
	double y_;//pos
	double z_;//pole
	double c_;//filter coefficient

public:
	maxiFilter() :x_(0.0), y_(0.0), z_(0.0), c_(0.0) {}
	double Cutoff;
	double Resonance;
	double lores(double input, double cutoff1, double resonance);
	double hires(double input, double cutoff1, double resonance);
	double bandpass(double input, double cutoff1, double resonance);
	double lopass(double input, double cutoff);
	double hipass(double input, double cutoff);

};

}