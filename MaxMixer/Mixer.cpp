#include "Mixer.h"

Mixer::Mixer()
{
}

Mixer::~Mixer()
{
}

String Mixer::toString(int value)
{
    return String(value);
}

String Mixer::buildTopButtons()
{
    return " " + toString(GButton) 
    + " " + toString(EQ1Button) 
    + " " + toString(C1Button) 
    + " " + toString(SAButton)
    + " " + toString(EQ2Button)
    + " " + toString(C2Button)
    + " " + toString(SIButton)
    + " " + toString(L1Button)
    + " " + toString(L2Button);
}

String Mixer::buildEqualiser()
{
    return " " + toString(equaliserOnButton)
    + " " + toString(freqAnalogueLeft)
    + " " + toString(freqAnalogueMidLeft)
    + " " + toString(freqAnalogueMidRight)
    + " " + toString(freqAnalogueRight)

    + " " + toString(gainAnalogueLeft)
    + " " + toString(gainAnalogueMidLeft)
    + " " + toString(gainAnalogueMidRight)
    + " " + toString(gainAnalogueRight)

    + " " + toString(QAnalogueLeft)
    + " " + toString(QAnalogueMidLeft)
    + " " + toString(QAnalogueMidRight)
    + " " + toString(QAnalogueRight);
}

String Mixer::buildCompressor()
{
    return " " + toString(compressonOnButton)
    + " " + toString(thresholdAnalogue)
    + " " + toString(ratioAnalogue)
    + " " + toString(attackAnalogue)
    + " " + toString(releaseAnalogue);
}

String Mixer::buildLimiter()
{
    return " " + toString(limiterOnButton)
    + " " + toString(limiterGainAnalogue)
    + " " + toString(limiterCielingAnalogue)
    + " " + toString(limiterAttackAnalogue)
    + " " + toString(limiterReleaseAnalogue);
}

String Mixer::buildStereoImager()
{
    return " " + toString(stereoImagerOnButton)
    + " " + toString(stereoLowAnalogue)
    + " " + toString(stereoLmidAnalogue)
    + " " + toString(stereoHmidAnalogue)
    + " " + toString(stereoHighAnalogue);
}

String Mixer::buildSaturation()
{
  return " " + toString(saturationOnButton)
    + " " + toString(saturationDrive)
    + " " + toString(saturationDryWet);
}

String Mixer::buildButtomButtonsAndVolSlider()
{
    return " " + toString(stopButton)
    + " " + toString(playPauseButton)
    + " " + toString(prevButton)
    + " " + toString(fwdButton)
    + " " + toString(ABButton)
    + " " + toString(volumeSilder);
}

void Mixer::sendMixerToMax()
{
    String stringToSend;

    stringToSend = buildEqualiser();

    //stringToSend = buildTopButtons();
    //+ buildEqualiser();
    // + buildCompressor()
    // + buildLimiter()
    // + buildStereoImager()
    // + buildSaturation()
    // + buildButtomButtonsAndVolSlider();

    Serial.print(stringToSend);
}