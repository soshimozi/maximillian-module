#pragma once
#include "maximilian.h"
#include "maxiSettings.hpp"

namespace maximilian
{

 /*
  State Variable Filter

  algorithm from  http://www.cytomic.com/files/dsp/SvfLinearTrapOptimised.pdf
  usage:
  either set the parameters separately as required (to save CPU)

  filter.setCutoff(param1);
  filter.setResonance(param2);

  w = filter.play(w, 0.0, 1.0, 0.0, 0.0);

  or set everything together at once

  w = filter.setCutoff(param1).setResonance(param2).play(w, 0.0, 1.0, 0.0, 0.0);

  */
 class maxiSVF {
 public:
     maxiSVF() : v0z(0), v1(0), v2(0) { setParams(1000, 1);}

     //20 < cutoff < 20000
     inline maxiSVF& setCutoff(double cutoff) {
        setParams(cutoff, res);
        return *this;
     }

     //from 0 upwards, starts to ring from 2-3ish, cracks a bit around 10
     inline maxiSVF& setResonance(double q) {
        setParams(freq, q);
        return *this;
     }

     //run the filter, and get a mixture of lowpass, bandpass, highpass and notch outputs
	inline double play(double w, double lpmix, double bpmix, double hpmix, double notchmix) {
		double low, band, high, notch;
		double v1z = v1;
		double v2z = v2;
		double v3 = w + v0z - 2.0 * v2z;
		v1 += g1*v3-g2*v1z;
		v2 += g3*v3+g4*v1z;
		v0z = w;
		low = v2;
		band = v1;
		high = w-k*v1-v2;
		notch = w-k*v1;
		return (low * lpmix) + (band * bpmix) + (high * hpmix) + (notch * notchmix);
	}

private:
	inline void setParams(double _freq, double _res) {
		freq = _freq;
		res = _res;
		g = tan(PI * freq / maxiSettings::sampleRate);
		damping = res == 0 ? 0 : 1.0 / res;
		k = damping;
		ginv = g / (1.0 + g * (g + k));
		g1 = ginv;
		g2 = 2.0 * (g + k) * ginv;
		g3 = g * ginv;
		g4 = 2.0 * ginv;
	}

	double v0z, v1, v2, g, damping, k, ginv, g1, g2, g3 ,g4;
	double freq, res;

};

	
}
