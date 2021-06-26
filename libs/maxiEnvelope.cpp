#include "maximilian.h"
#include "maxiEnvelope.h"

#include "maxiSettings.hpp"

namespace maximilian {
	

    // don't use this nonsense. Use ramps instead.
    // ..er... I mean "This method is deprecated"
    double maxiEnvelope::line(int numberofsegments, double segments[1000]) {
        //This is a basic multi-segment ramp generator that you can use for more or less anything.
        //However, it's not that intuitive.
        if (is_playing_ == 1) {//only make a sound once you've been triggered
            period_ = 4. / (segments[valindex + 1] * 0.0044);
            nextval_ = segments[valindex + 2];
            currentval_ = segments[valindex];
            if (currentval_ - amplitude > 0.0000001 && valindex < numberofsegments) {
                amplitude += ((currentval_ - start_val_) / (maxiSettings::sampleRate / period_));
            }
            else if (currentval_ - amplitude < -0.0000001 && valindex < numberofsegments) {
                amplitude -= (((currentval_ - start_val_) * (-1)) / (maxiSettings::sampleRate / period_));
            }
            else if (valindex > numberofsegments - 1) {
                valindex = numberofsegments - 2;
            }
            else {
                valindex = valindex + 2;
                start_val_ = currentval_;
            }
            output_ = amplitude;

        }
        else {
            output_ = 0;

        }
        return(output_);
    }

    //and this is also deprecated
    void maxiEnvelope::trigger(int index, double amp) {
        is_playing_ = 1;//ok the envelope is being used now.
        valindex = index;
        amplitude = amp;

    }

    void maxiEnvelope::trigger(bool noteOn) {

        if (noteOn) trig = 1;
        if (noteOn == false) trig = 0;

    }

    double maxiEnvelope::ramp(double startVal=0, double endVal=1, double duration=1) {

        if (trig != 0) {
            phase_ = startVal;
            is_playing_ = true;
            trig = 0;
        }

        if (is_playing_) {

            if (startVal < endVal) {
                phase_ += ((endVal - startVal) / (maxiSettings::sampleRate / (1. / duration)));
                if (phase_ >= endVal) phase_ = endVal;
            }

            if (startVal > endVal) {
                phase_ += ((endVal - startVal) / (maxiSettings::sampleRate / (1. / duration)));
                if (phase_ <= endVal) phase_ = endVal;
            }
            return(phase_);
        }
        else {

            return(0);

        }


    }


    double maxiEnvelope::ramps(std::vector<double> rampsArray) {

        if (trig != 0) {
            valindex = 0;
            end_val_ = rampsArray[valindex + 1];
            is_playing_ = true;
            trig = 0;

        }

        if (is_playing_) {

            if (valindex > 0 && rampsArray[valindex - 1] == rampsArray[valindex + 1]) {
                period_ += (1 / (maxiSettings::sampleRate / (1. / rampsArray[valindex])));
                if (period_ >= 1) {
                    phase_ = end_val_;
                    start_val_ = phase_;
                    if (valindex + 2 < rampsArray.size()) {
                        valindex += 2;
                        end_val_ = rampsArray[valindex + 1];
                        period_ = 0;
                    }
                } output_ = phase_;
            }

            if (valindex == 0 && output_ == end_val_) {
                period_ += (1 / (maxiSettings::sampleRate / (1. / rampsArray[valindex])));
                if (period_ >= 1) {
                    phase_ = end_val_;
                    start_val_ = phase_;
                    if (valindex + 2 < rampsArray.size()) {
                        valindex += 2;
                        end_val_ = rampsArray[valindex + 1];
                        period_ = 0;
                    }
                } output_ = phase_;
            }

            if (phase_ < end_val_) {
                phase_ += ((end_val_ - start_val_) / (maxiSettings::sampleRate / (1. / rampsArray[valindex])));
                if (phase_ >= end_val_) {
                    phase_ = end_val_;
                    start_val_ = phase_;
                    if (valindex + 2 < rampsArray.size()) {
                        valindex += 2;
                        end_val_ = rampsArray[valindex + 1];

                    }
                }
                output_ = phase_;
            }

            if (phase_ > end_val_) {
                phase_ += ((end_val_ - start_val_) / (maxiSettings::sampleRate / (1. / rampsArray[valindex])));
                if (phase_ <= end_val_) {
                    phase_ = end_val_;
                    start_val_ = phase_;
                    if (valindex + 2 < rampsArray.size()) {
                        valindex += 2;
                        end_val_ = rampsArray[valindex + 1];

                    }
                } output_ = phase_;
            }

            return(output_);

        }
        else {

            return(0);
        }
    }

    double maxiEnvelope::ar(double attack=0.1, double release=0.1) {

        if (trig != 0) {
            //phase=0;
            release_mode_ = false;
            trig = 0;
        }

        if (phase_ < 1 && release_mode_ == false) {
            phase_ += ((1) / (maxiSettings::sampleRate / (1. / attack)));
            if (phase_ >= 1) {
                phase_ = 1;
                release_mode_ = true;
            };
        }

        if (release_mode_ == true) {
            phase_ += ((-1) / (maxiSettings::sampleRate / (1. / release)));
            if (phase_ <= 0) phase_ = 0;
        }

        return phase_;
    }


    double maxiEnvelope::adsr(double attack = 0.1, double decay = 0.1, double sustain = 0.1, double release = 0.1) {

        if (trig != 0 && !attack_mode_) {
            //        phase=0.;
            release_mode_ = false;
            decay_mode_ = false;
            sustain_mode_ = false;
            attack_mode_ = true;
            trig = 0;
        }

        if (attack_mode_) {
            phase_ += ((1) / (maxiSettings::sampleRate / (1. / attack)));

            if (phase_ >= 1) {
                phase_ = 1;
                attack_mode_ = false;
                decay_mode_ = true;
            };
        }

        if (decay_mode_) {
            phase_ += ((-1) / (maxiSettings::sampleRate / (1. / decay)));
            if (phase_ <= sustain) {
                phase_ = sustain;
                decay_mode_ = false;
                sustain_mode_ = true;
            };
        }

        if (sustain_mode_) {

            if (note_on_) {
                phase_ = sustain;
            }

            if (!note_on_) {
                sustain_mode_ = false;
                release_mode_ = true;
            }
        }

        if (release_mode_) {
            phase_ += ((-sustain) / (maxiSettings::sampleRate / (1. / release)));
            if (phase_ <= 0) {
                phase_ = 0;
                release_mode_ = false;
            }
        }

        return phase_;
    }


}
