/*
 ==============================================================================
 *  maximilian_audio_library.h
 *  platform independent synthesis library using portaudio or rtaudio
 *
 *  Created by Mick Grierson on 29/12/2009.
 *  Copyright 2009 Mick Grierson & Strangeloop Limited. All rights reserved.
 *	Thanks to the Goldsmiths Creative Computing Team.
 *	Special thanks to Arturo Castro for the PortAudio implementation.
 * 
 *	Permission is hereby granted, free of charge, to any person
 *	obtaining a copy of this software and associated documentation
 *	files (the "Software"), to deal in the Software without
 *	restriction, including without limitation the rights to use,
 *	copy, modify, merge, publish, distribute, sublicense, and/or sell
 *	copies of the Software, and to permit persons to whom the
 *	Software is furnished to do so, subject to the following
 *	conditions:
 *	
 *	The above copyright notice and this permission notice shall be
 *	included in all copies or substantial portions of the Software.
 *
 *	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,	
 *	EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 *	OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 *	NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 *	HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 *	WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 *	FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 *	OTHER DEALINGS IN THE SOFTWARE.
 *
 ==============================================================================

    BEGIN_JUCE_MODULE_DECLARATION

    ID:            maximilian_audio_library
    vendor:        Maximilian
    version:       1.0.0
    name:          Maximilian Audio Library
    description:   This module contains various audio components.
    dependencies:  juce_core, juce_audio_basics, juce_audio_devices, juce_audio_formats,
                   juce_audio_utils, juce_audio_processors, juce_dsp, juce_cryptography
	website:
    license:       Dual license: non commercial under BSD V2 3-clause

    END_JUCE_MODULE_DECLARATION

 ============================================================================== 
 */

#pragma once

#include <juce_core/juce_core.h>
#include <juce_audio_basics/juce_audio_basics.h>
#include <juce_audio_processors/juce_audio_processors.h>
#include <juce_gui_basics/juce_gui_basics.h>
#include <juce_audio_devices/juce_audio_devices.h>
#include <juce_audio_formats/juce_audio_formats.h>
#include <juce_audio_utils/juce_audio_utils.h>
#include <juce_cryptography/juce_cryptography.h>
#include <juce_dsp/juce_dsp.h>

#include "libs/maxiSettings.hpp"
#include "libs/maxiOsc.hpp"
#include "libs/maxiEnvelope.h"
#include "libs/maxiMix.hpp"
#include "libs/maxiDelayLine.hpp"
#include "libs/maxiFilter.hpp"
#include "libs/maxiDyn.hpp"
#include "libs/maxiEnv.hpp"
#include "libs/maxiDistortion.hpp"
#include "libs/maxiFlanger.hpp"
#include "libs/maxiChorus.hpp"
#include "libs/maxiEnvelopeFollowerType.hpp"
#include "libs/maxiSVF.hpp"
#include "libs/maxiClock.hpp"