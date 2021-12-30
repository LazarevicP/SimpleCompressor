/*
  ==============================================================================

    Compressor.cpp
    Created: 19 Jul 2021 11:33:33am
    Author:  phili

  ==============================================================================
*/

#include "Compressor.h"

Compressor::Compressor()
{
    buffer = CircularBuffer(150, 20);
    tav = 0.01;
    rms = 0;
    gain = 1;
}

float Compressor::compressSample(float data, float thresh, float ratio, float attack, float release, float knee)
{
    return 0.0f;
}

float Compressor::compressSample(float data, float thresh, float ratio, float attack, float release, float knee)
{
    // adjusts rms depending on incoming signal
    rms = (1 - tav) * rms + tav * std::pow(data, 2.0f);
    // converts rms to decibel scale
    float dbRMS = 10 * std::log10(rms);

    // take the ratio and convert it into a slope value
    float slope = 1 - (1 / ratio);
    // Calculate gain reduction to be applied while making sure it is 0 or less then convert to linear scale
    float dbGain = std::min(0.0f, (slope * (thresh - dbRMS)));
    float newGain = std::pow(10, dbGain / 20);

    float coeff;
    if (newGain < gain) 
    {
        coeff = attack;
    }
    else 
    {
        coeff = release;
    }
    gain = (1 - coeff) * gain + coeff * newGain;

    float compressedSample = gain * buffer.getData();
    buffer.setData(data);
    buffer.nextSample();
    return compressedSample;
}