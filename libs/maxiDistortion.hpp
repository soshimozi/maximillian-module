#pragma once

#include "maximilian.h"


namespace maximilian
{

class maxiDistortion {
public:
    /*atan distortion, see http://www.musicdsp.org/showArchiveComment.php?ArchiveID=104*/
    /*shape from 1 (soft clipping) to infinity (hard clipping)*/
    double atanDist(const double in, const double shape);
    double fastAtanDist(const double in, const double shape);
    double fastatan( double x );
};

	
}