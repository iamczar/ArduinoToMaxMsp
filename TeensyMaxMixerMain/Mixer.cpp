#include "Mixer.h"

Mixer::Mixer()
{

}

Mixer::~Mixer()
{
}

String Mixer::buildTopButtons()
{
    return " " + String(GButton) 
    + " " + String(EQ1Button) 
    + " " + String(C1Button) 
    + " " + String(SAButton)
    + " " + String(EQ2Button)
    + " " + String(C2Button)
    + " " + String(SIButton)
    + " " + String(L1Button)
    + " " + String(L2Button);
}

String Mixer::buildEqualiser()
{
    return " " + String(equaliserOnButton)
    + " " + String(freqAnalogueLeft)
    + " " + String(freqAnalogueMidLeft)
    + " " + String(freqAnalogueMidRight)
    + " " + String(freqAnalogueRight)

    + " " + String(gainAnalogueLeft)
    + " " + String(gainAnalogueMidLeft)
    + " " + String(gainAnalogueMidRight)
    + " " + String(gainAnalogueRight)

    + " " + String(QAnalogueLeft)
    + " " + String(QAnalogueMidLeft)
    + " " + String(QAnalogueMidRight)
    + " " + String(QAnalogueRight);
}

String Mixer::buildCompressor()
{
    return " " + String(compressonOnButton)
    + " " + String(thresholdAnalogue)
    + " " + String(ratioAnalogue)
    + " " + String(attackAnalogue)
    + " " + String(releaseAnalogue);
}

String Mixer::buildLimiter()
{
    return " " + String(limiterOnButton)
    + " " + String(limiterGainAnalogue)
    + " " + String(limiterCielingAnalogue)
    + " " + String(limiterAttackAnalogue)
    + " " + String(limiterReleaseAnalogue);
}

String Mixer::buildStereoImager()
{
    return " " + String(stereoImagerOnButton)
    + " " + String(stereoLowAnalogue)
    + " " + String(stereoLmidAnalogue)
    + " " + String(stereoHmidAnalogue)
    + " " + String(stereoHighAnalogue);
}

String Mixer::buildSaturation()
{
  return " " + String(saturationOnButton)
    + " " + String(saturationDrive)
    + " " + String(saturationDryWet);
}

String Mixer::buildButtomButtonsAndVolSlider()
{
    return " " + String(stopButton)
    + " " + String(playPauseButton)
    + " " + String(prevButton)
    + " " + String(fwdButton)
    + " " + String(ABButton)
    + " " + String(Gain)
    + " " + String(volumeSilder);

}

void Mixer::sendMixerToMax()
{
    String stringToSend;

    //stringToSend = buildButtomButtonsAndVolSlider();

    stringToSend = buildTopButtons()
    + buildEqualiser()
    + buildCompressor()
    + buildLimiter()
    + buildStereoImager()
    + buildSaturation()
    + buildButtomButtonsAndVolSlider();

    Serial.println(stringToSend);
}