#pragma once
#include "maximilian.h"
#include "maxiSettings.hpp"

namespace maximilian
{

template<typename T>
class maxiEnvelopeFollowerType {
public:
    maxiEnvelopeFollowerType() {
        setAttack(100);
        setRelease(100);
        env = 0;
    }
    void setAttack(T attackMS) {
        attack = pow( 0.01, 1.0 / (attackMS * maxiSettings::sampleRate * 0.001 ) );
    }
    void setRelease(T releaseMS) {
        release = pow( 0.01, 1.0 / (releaseMS * maxiSettings::sampleRate * 0.001 ) );
    }
    inline T play(T input) {
        input = fabs(input);
        if (input>env)
            env = attack * (env - input) + input;
        else
            env = release * (env - input) + input;
        return env;
    }
    void reset() {env=0;}
    inline T getEnv(){return env;}
    inline void setEnv(T val){env = val;}
private:
    T attack, release, env;
};

typedef maxiEnvelopeFollowerType<double> maxiEnvelopeFollower;
typedef maxiEnvelopeFollowerType<float> maxiEnvelopeFollowerF;
	
}