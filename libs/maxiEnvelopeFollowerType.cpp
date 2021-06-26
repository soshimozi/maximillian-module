#include "maxiEnvelopeFollowerType.hpp"

namespace maximilian
{

template<> void maxiEnvelopeFollower::setAttack(double attackMS) {
   attack = pow( 0.01, 1.0 / ( attackMS * maxiSettings::sampleRate * 0.001 ) );
}

template<> void maxiEnvelopeFollower::setRelease(double releaseMS) {
   release = pow( 0.01, 1.0 / ( releaseMS * maxiSettings::sampleRate * 0.001 ) );    
}
	
}