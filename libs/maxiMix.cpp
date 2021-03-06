#include "maximilian.h"
#include "maxiMix.hpp"

namespace maximilian {
	
//stereo bus
double *maxiMix::stereo(double input,double two[2],double x) {
	if (x>1) x=1;
	if (x<0) x=0;
	two[0]=input*sqrt(1.0-x);
	two[1]=input*sqrt(x);
	return(two);
} 

//quad bus
double *maxiMix::quad(double input,double four[4],double x,double y) {
	if (x>1) x=1;
	if (x<0) x=0;
	if (y>1) y=1;
	if (y<0) y=0;
	four[0]=input*sqrt((1.0-x)*y);
	four[1]=input*sqrt((1.0-x)*(1.0-y));
	four[2]=input*sqrt(x*y);
	four[3]=input*sqrt(x*(1.0-y));
	return(four);
}

//ambisonic bus
double *maxiMix::ambisonic(double input,double eight[8],double x,double y,double z) {
	if (x>1) x=1;
	if (x<0) x=0;
	if (y>1) y=1;
	if (y<0) y=0;
	if (z>1) y=1;
	if (z<0) y=0;
	eight[0]=input*(sqrt((1.0-x)*y)*1.0-z);
	eight[1]=input*(sqrt((1.0-x)*(1.0-y))*1.0-z);
	eight[2]=input*(sqrt(x*y)*1.0-z);
	eight[3]=input*(sqrt(x*(1.0-y))*1.0-z);
	eight[4]=input*(sqrt((1.0-x)*y)*z);
	eight[5]=input*(sqrt((1.0-x)*(1.0-y))*z);
	eight[6]=input*sqrt((x*y)*z);
	eight[7]=input*sqrt((x*(1.0-y))*z);
	return(eight);
}	
	
}