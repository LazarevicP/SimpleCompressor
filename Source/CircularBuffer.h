/*
  ==============================================================================

    CircularBuffer.h
    Created: 19 Jul 2021 11:09:34am
    Author:  phili

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
class CircularBuffer {
public:
    CircularBuffer();
    CircularBuffer(int bufferSize, int delayLength);
    float getData();
    void setData(float data);
    void nextSample();
private:
    juce::AudioBuffer<float> buffer;
    int writeIndex;
    int readIndex;
    int delayLength;
};