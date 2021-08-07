#include "Button.h"
#include "Mixer.h"

#include <ArduinoJson.h>

// top buttons
Button EqualiserOnButton(0);
Button GButton(1);
Button EQ1Button(2);
Button C1Button(3);
Button SAButton(4);
Button EQ2Button(5);
Button C2Button(6);
Button SIButton(7);
Button L1Button(8);
Button L2Button(9);
Button CompressonOnButton(10);

Mixer mixer;

DynamicJsonDocument mixerJson(1024);

void setup()
{
    pinMode(13,OUTPUT);
    digitalWrite(13,HIGH);

    Serial.begin(9600);
    Serial4.begin(115200);

    EqualiserOnButton.begin();
    GButton.begin();
    EQ1Button.begin();
    C1Button.begin();
    SAButton.begin();
    EQ2Button.begin();
    C2Button.begin();
    SIButton.begin();
    L1Button.begin();
    L2Button.begin();
    CompressonOnButton.begin();
}

void loop()
{
    DeserializationError err;
    // recieve from TeensyMaxMixer
    if (Serial4.available())
    {
        err = deserializeJson(mixerJson, Serial4);
    }
    
    //top buttons
    mixer.GButton               = GButton.isButtonPressed();
    mixer.EQ1Button             = EQ1Button.isButtonPressed();
    mixer.C1Button              = C1Button.isButtonPressed();
    mixer.SAButton              = SAButton.isButtonPressed();
    mixer.EQ2Button             = EQ2Button.isButtonPressed();
    mixer.C2Button              = C2Button.isButtonPressed();
    mixer.SIButton              = SIButton.isButtonPressed();
    mixer.L1Button              = L1Button.isButtonPressed();
    mixer.L2Button              = L2Button.isButtonPressed();

    // Equaliser
    mixer.equaliserOnButton     = EqualiserOnButton.isButtonPressed();
    mixer.freqAnalogueLeft      = analogRead(A9);
    mixer.freqAnalogueMidLeft   = analogRead(A8);
    mixer.freqAnalogueMidRight  = analogRead(A7);
    mixer.freqAnalogueRight     = analogRead(A6);

    mixer.gainAnalogueLeft      = analogRead(A5);
    mixer.gainAnalogueMidLeft   = analogRead(A4);
    mixer.gainAnalogueMidRight  = analogRead(A3);
    mixer.gainAnalogueRight     = analogRead(A2);

    mixer.QAnalogueLeft         = analogRead(A1);
    mixer.QAnalogueMidLeft      = analogRead(A0);
    mixer.QAnalogueMidRight     = analogRead(A22);
    mixer.QAnalogueRight        = analogRead(A21);

    // Compressor
    mixer.compressonOnButton    = CompressonOnButton.isButtonPressed();

    if (err == DeserializationError::Ok)
    {
        mixer.thresholdAnalogue     = mixerJson["compressorThreshold"].as<int>();
        mixer.ratioAnalogue         = mixerJson["compressorRatio"].as<int>();
        mixer.attackAnalogue        = mixerJson["compressorAttack"].as<int>();
        mixer.releaseAnalogue       = mixerJson["comppressorRelease"].as<int>();

        mixer.limiterOnButton       = mixerJson["limiterOnButton"].as<int>();
        mixer.limiterGainAnalogue   = mixerJson["limiterGain"].as<int>();
        mixer.limiterCielingAnalogue= mixerJson["limiterCieling"].as<int>();
        mixer.limiterAttackAnalogue = mixerJson["limiterAttack"].as<int>();
        mixer.limiterReleaseAnalogue= mixerJson["limiterRelease"].as<int>();

        mixer.stereoImagerOnButton  = mixerJson["stereoImagerOnButton"].as<int>();
        mixer.stereoLowAnalogue     = mixerJson["stereoImagerLow"].as<int>();
        mixer.stereoLmidAnalogue    = mixerJson["stereoImagerLowMid"].as<int>();
        mixer.stereoHmidAnalogue    = mixerJson["stereoImagerHighMid"].as<int>();
        mixer.stereoHighAnalogue    = mixerJson["stereoImagerHigh"].as<int>();

        mixer.saturationOnButton    = mixerJson["saturationOnButton"].as<int>();
        mixer.saturationDrive       = mixerJson["saturationDrive"].as<int>();
        mixer.saturationDryWet      = mixerJson["saturationDryWet"].as<int>();

        mixer.Gain                  = mixerJson["gain"].as<int>();
        mixer.volumeSilder          = mixerJson["volumeSlider"].as<int>();


        mixer.ABButton              = mixerJson["ABButton"].as<int>();
        mixer.fwdButton             = mixerJson["fwdButton"].as<int>();
        mixer.prevButton            = mixerJson["prevButton"].as<int>();
        mixer.playPauseButton       = mixerJson["playPauseButton"].as<int>();
        mixer.stopButton            = mixerJson["stopButton"].as<int>();
        mixer.limiterOnButton       = mixerJson["limiterOnButton"].as<int>();

    }

    mixer.sendMixerToMax();

}