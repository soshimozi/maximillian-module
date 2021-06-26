#pragma once

#include "maximilian.h"

class maxiMap {
public:
	static double inline linlin(double val, double inMin, double inMax, double outMin, double outMax) {
	    val = max(min(val, inMax), inMin);
	    return ((val - inMin) / (inMax - inMin) * (outMax - outMin)) + outMin;
	}

    static double inline linexp(double val, double inMin, double inMax, double outMin, double outMax) {
        //clipping
        val = max(min(val, inMax), inMin);
        return pow((outMax / outMin), (val - inMin) / (inMax - inMin)) * outMin;
    }

    static double inline explin(double val, double inMin, double inMax, double outMin, double outMax) {
        //clipping
        val = max(min(val, inMax), inMin);
        return (log(val/inMin) / log(inMax/inMin) * (outMax - outMin)) + outMin;
    }

    //changed to templated function, e.g. maxiMap::maxiClamp<int>(v, l, h);
    template<typename T>
    static T inline clamp(T v, const T low, const T high) {
        if (v > high)
            v = high;
        else if (v < low) {
            v = low;
        }
        return v;
    }

};
