/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
SimpleCompressorAudioProcessorEditor::SimpleCompressorAudioProcessorEditor (SimpleCompressorAudioProcessor& p, juce::AudioProcessorValueTreeState& state)
    : AudioProcessorEditor(&p), processor(p), params(state)
{
    addSlider("thresh", "Threshold", threshSlider, threshLabel, threshAttachment);
    addSlider("ratio", "Ratio", slopeSlider, slopeLabel, slopeAttachment);
    addSlider("knee", "Knee", kneeSlider, kneeLabel, kneeAttachment);
    addSlider("attack", "Attack", attackSlider, attackLabel, attackAttachment);
    addSlider("release", "Release", releaseSlider, releaseLabel, releaseAttachment);
    setSize(400, 300);
}

SimpleCompressorAudioProcessorEditor::~SimpleCompressorAudioProcessorEditor()
{
}

//==============================================================================
void SimpleCompressorAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Hello World!", getLocalBounds(), juce::Justification::centred, 1);
}

void SimpleCompressorAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    threshSlider.setBounds(100, 0, 200, 50);
    slopeSlider.setBounds(100, 50, 200, 50);
    kneeSlider.setBounds(100, 100, 200, 50);
    attackSlider.setBounds(100, 150, 200, 50);
    releaseSlider.setBounds(100, 200, 200, 50);
}
