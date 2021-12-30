/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class SimpleCompressorAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    SimpleCompressorAudioProcessorEditor (SimpleCompressorAudioProcessor&);
    ~SimpleCompressorAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
    void SimpleCompressorAudioProcessorEditor::addSlider(juce::String name, juce::String labelText, juce::Slider& slider, juce::Label& label,
        std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment>& attachment) {
        addAndMakeVisible(slider);
        attachment.reset(new juce::AudioProcessorValueTreeState::SliderAttachment(params, name, slider));
        label.setText(labelText, juce::dontSendNotification);
        label.attachToComponent(&slider, true);
        addAndMakeVisible(label);
    }
private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    SimpleCompressorAudioProcessor& audioProcessor;
    juce::AudioProcessorValueTreeState& params;

    juce::Slider threshSlider, slopeSlider, kneeSlider, attackSlider, releaseSlider;
    juce::Label threshLabel, slopeLabel, kneeLabel, attackLabel, releaseLabel;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> threshAttachment, slopeAttachment, kneeAttachment, attackAttachment, releaseAttachment;


  

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SimpleCompressorAudioProcessorEditor)
};
