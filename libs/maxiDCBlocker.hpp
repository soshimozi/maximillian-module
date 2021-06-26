#pragma once
#include "maximilian.h"

namespace maximilian {

class maxiDCBlocker {
public:
    double xm1, ym1;
    maxiDCBlocker() : xm1(0), ym1(0) {}
    inline double play(double input, double R) {
        ym1 = input - xm1 + R * ym1;
        xm1 = input;
        return ym1;
    }
};
	
}