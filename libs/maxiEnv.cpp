#include "maxiEnv.hpp"

#include "maxiSettings.hpp"

namespace maximilian
{

/* Lots of people struggle with the envelope generators so here's a new easy one.
 It takes mental numbers for attack and release tho. Basically, they're exponentials.
 I'll map them out later so that it's a bit more intuitive */
double maxiEnv::ar(double input, double attack, double release, long holdtime, int trigger) {
	
	if (trigger==1 && Attackphase!=1 && Holdphase!=1){ 
		Holdcount=0;
		Releasephase=0;
		Attackphase=1;
	}
	
	if (Attackphase==1) {
		Amplitude+=(1*attack);
		Output=input*Amplitude;
	}
	
	if (Amplitude>=1) {
		Amplitude=1;
		Attackphase=0;
		Holdphase=1;
	}
	
	if (Holdcount<holdtime && Holdphase==1) {
		Output=input;
		Holdcount++;
	}
	
	if (Holdcount==holdtime && trigger==1) {
		Output=input;
	}
	
	if (Holdcount==holdtime && trigger!=1) {
		Holdphase=0;
		Releasephase=1;
	}
	
	if (Releasephase==1 && Amplitude>0.) {
		Output=input*(Amplitude*=release);
		
	}
	
	return Output;
}

/* adsr. It's not bad, very simple to use*/

double maxiEnv::adsr(double input, double attack, double decay, double sustain, double release, long holdtime, int trigger) {
    
    if (trigger==1 && Attackphase!=1 && Holdphase!=1 && Decayphase!=1){
        Holdcount=0;
        Decayphase=0;
        Sustainphase=0;
        Releasephase=0;
        Attackphase=1;
    }
    
    if (Attackphase==1) {
        Releasephase=0;
        Amplitude+=(1*attack);
        Output=input*Amplitude;
        
        if (Amplitude>=1) {
            Amplitude=1;
            Attackphase=0;
            Decayphase=1;
        }
    }
    
    
    if (Decayphase==1) {
        Output=input*(Amplitude*=decay);
        if (Amplitude<=sustain) {
            Decayphase=0;
            Holdphase=1;
        }
    }
    
    if (Holdcount<holdtime && Holdphase==1) {
        Output=input*Amplitude;
        Holdcount++;
    }
    
    if (Holdcount>=holdtime && trigger==1) {
        Output=input*Amplitude;
    }
    
    if (Holdcount>=holdtime && trigger!=1) {
        Holdphase=0;
        Releasephase=1;
    }
    
    if (Releasephase==1 && Amplitude>0.) {
        Output=input*(Amplitude*=release);
        
    }
    
    return Output;
}

double maxiEnv::adsr(double input, int trigger) {
    
    if (trigger==1 && Attackphase!=1 && Holdphase!=1 && Decayphase!=1){
        Holdcount=0;
        Decayphase=0;
        Sustainphase=0;
        Releasephase=0;
        Attackphase=1;
    }
    
    if (Attackphase==1) {
        Releasephase=0;
        Amplitude+=(1*Attack);
        Output=input*Amplitude;
        
        if (Amplitude>=1) {
            Amplitude=1;
            Attackphase=0;
            Decayphase=1;
        }
    }
    
    
    if (Decayphase==1) {
        Output=input*(Amplitude*=Decay);
        if (Amplitude<=Sustain) {
            Decayphase=0;
            Holdphase=1;
        }
    }
    
    if (Holdcount<Holdtime && Holdphase==1) {
        Output=input*Amplitude;
        Holdcount++;
    }
    
    if (Holdcount>=Holdtime && trigger==1) {
        Output=input*Amplitude;
    }
    
    if (Holdcount>=Holdtime && trigger!=1) {
        Holdphase=0;
        Releasephase=1;
    }
    
    if (Releasephase==1 && Amplitude>0.) {
        Output=input*(Amplitude*=Release);
        
    }
    
    return Output;
}


void maxiEnv::setAttack(double attackMS) {
    Attack = 1-pow( 0.01, 1.0 / ( attackMS * maxiSettings::sampleRate * 0.001 ) );
}

void maxiEnv::setRelease(double releaseMS) {
    Release = pow( 0.01, 1.0 / ( releaseMS * maxiSettings::sampleRate * 0.001 ) );
}

void maxiEnv::setSustain(double sustainL) {
    Sustain = sustainL;
}

void maxiEnv::setDecay(double decayMS) {
    Decay = pow( 0.01, 1.0 / ( decayMS * maxiSettings::sampleRate * 0.001 ) );
}

	
}
