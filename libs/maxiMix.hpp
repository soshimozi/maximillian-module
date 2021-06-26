#pragma once

namespace maximilian {
	
class maxiMix  {
	double input_;
	double two_[2];
	double four_[4];
	double eight_[8];
 public:
	double X;
	double Y;
	double Z;
	double *stereo(double /*input*/,double /*two*/[2],double /*x*/);
	double *quad(double /*input*/,double /*four*/[4], double /*x*/,double /*y*/);
	double *ambisonic(double /*input*/,double /*eight*/[8],double /*x*/,double /*y*/, double /*z*/);
	
};	

}