#include "maxiFilter.hpp"

#include "maxiSettings.hpp"

namespace maximilian
{
	//I particularly like these. cutoff between 0 and 1
	double maxiFilter::lopass(double input, double cutoff) {
		output_=outputs_[0] + cutoff*(input-outputs_[0]);
		outputs_[0]=output_;
		return(output_);
	}
	
	//as above
	double maxiFilter::hipass(double input, double cutoff) {
		output_=input-(outputs_[0] + cutoff*(input-outputs_[0]));
		outputs_[0]=output_;
		return(output_);
	}
	//awesome. cuttof is freq in hz. res is between 1 and whatever. Watch out!
	double maxiFilter::lores(double input,double cutoff1, double resonance) {
		Cutoff=cutoff1;
		if (Cutoff<10) Cutoff=10;
		if (Cutoff>(maxiSettings::sampleRate)) Cutoff=(maxiSettings::sampleRate);
		if (resonance<1.) resonance = 1.;
		z_=cos(TWOPI*Cutoff/maxiSettings::sampleRate);
		c_=2-2*z_;
		double r=(sqrt(2.0)*sqrt(-pow((z_-1.0),3.0))+resonance*(z_-1))/(resonance*(z_-1));
		x_=x_+(input-y_)*c_;
		y_=y_+x_;
		x_=x_*r;
		output_=y_;
		return(output_);
	}
	
	//working hires filter
	double maxiFilter::hires(double input,double cutoff1, double resonance) {
		Cutoff=cutoff1;
		if (Cutoff<10) Cutoff=10;
		if (Cutoff>(maxiSettings::sampleRate)) Cutoff=(maxiSettings::sampleRate);
		if (resonance<1.) resonance = 1.;
		z_=cos(TWOPI*Cutoff/maxiSettings::sampleRate);
		c_=2-2*z_;
		double r=(sqrt(2.0)*sqrt(-pow((z_-1.0),3.0))+resonance*(z_-1))/(resonance*(z_-1));
		x_=x_+(input-y_)*c_;
		y_=y_+x_;
		x_=x_*r;
		output_=input-y_;
		return(output_);
	}
	
	//This works a bit. Needs attention.
	double maxiFilter::bandpass(double input,double cutoff1, double resonance) {
		Cutoff=cutoff1;
		if (Cutoff>(maxiSettings::sampleRate*0.5)) Cutoff=(maxiSettings::sampleRate*0.5);
		if (resonance>=1.) resonance=0.999999;
		z_=cos(TWOPI*Cutoff/maxiSettings::sampleRate);
		inputs_[0] = (1-resonance)*(sqrt(resonance*(resonance-4.0*pow(z_,2.0)+2.0)+1));
		inputs_[1] = 2*z_*resonance;
		inputs_[2] = pow((resonance*-1),2);
		
		output_=inputs_[0]*input+inputs_[1]*outputs_[1]+inputs_[2]*outputs_[2];
		outputs_[2]=outputs_[1];
		outputs_[1]=output_;
		return(output_);
	}	
}
