#include "maxiDyn.hpp"

namespace maximilian {
/* OK this compressor and gate are now ready to use. The envelopes, like all the envelopes in this recent update, use stupid algorithms for
 incrementing - consequently a long attack is something like 0.0001 and a long release is like 0.9999.
 Annoyingly, a short attack is 0.1, and a short release is 0.99. I'll sort this out laters */

double maxiDyn::gate(double input, double threshold, long holdtime, double attack, double release) {

	if (fabs(input) > threshold && Attackphase != 1) {
		Holdcount = 0;
		Releasephase = 0;
		Attackphase = 1;
		if (Amplitude == 0) Amplitude = 0.01;
	}

	if (Attackphase == 1 && Amplitude < 1) {
		Amplitude *= (1 + attack);
		Output = input * Amplitude;
	}

	if (Amplitude >= 1) {
		Attackphase = 0;
		Holdphase = 1;
	}

	if (Holdcount < holdtime && Holdphase == 1) {
		Output = input;
		Holdcount++;
	}

	if (Holdcount == holdtime) {
		Holdphase = 0;
		Releasephase = 1;
	}

	if (Releasephase == 1 && Amplitude > 0.) {
		Output = input * (Amplitude *= release);

	}

	return Output;
}


double maxiDyn::compressor(double input, double ratio, double threshold, double attack, double release) {

	if (fabs(input) > threshold && Attackphase != 1) {
		Holdcount = 0;
		Releasephase = 0;
		Attackphase = 1;
		if (CurrentRatio == 0) CurrentRatio = ratio;
	}

	if (Attackphase == 1 && CurrentRatio < ratio - 1) {
		CurrentRatio *= (1 + attack);
	}

	if (CurrentRatio >= ratio - 1) {
		Attackphase = 0;
		Releasephase = 1;
	}

	if (Releasephase == 1 && CurrentRatio > 0.) {
		CurrentRatio *= release;
	}

	if (input > 0.) {
		Output = input / (1. + CurrentRatio);
	}
	else {
		Output = input / (1. + CurrentRatio);
	}

	return Output * (1 + log(ratio));
}

double maxiDyn::compress(double input) {

	if (fabs(input) > Threshold && Attackphase != 1) {
		Holdcount = 0;
		Releasephase = 0;
		Attackphase = 1;
		if (CurrentRatio == 0) CurrentRatio = Ratio;
	}

	if (Attackphase == 1 && CurrentRatio < Ratio - 1) {
		CurrentRatio *= (1 + Attack);
	}

	if (CurrentRatio >= Ratio - 1) {
		Attackphase = 0;
		Releasephase = 1;
	}

	if (Releasephase == 1 && CurrentRatio > 0.) {
		CurrentRatio *= Release;
	}

	if (input > 0.) {
		Output = input / (1. + CurrentRatio);
	}
	else {
		Output = input / (1. + CurrentRatio);
	}

	return Output * (1 + log(Ratio));
}

void maxiDyn::setAttack(double attackMS) {
	Attack = pow(0.01, 1.0 / (attackMS * maxiSettings::sampleRate * 0.001));
}

void maxiDyn::setRelease(double releaseMS) {
	Release = pow(0.01, 1.0 / (releaseMS * maxiSettings::sampleRate * 0.001));
}

void maxiDyn::setThreshold(double thresholdI) {
	Threshold = thresholdI;
}

void maxiDyn::setRatio(double ratioF) {
	Ratio = ratioF;
}

};