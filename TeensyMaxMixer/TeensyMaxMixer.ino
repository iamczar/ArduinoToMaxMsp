#include "TeensyMixer.h"
#include "Button.h"

#include <ArduinoJson.h>

TeensyMixer teensyMixer;

Button StereoImagerOnButton(32);
Button SaturationrOnButton(31);
Button ABButton(30);
Button FwdButton(29);
Button PrevButton(28);
Button PlayPauseButton(27);
Button StopButton(26);
Button LimiterOnButton(25);

DynamicJsonDocument mixerJson(1024);

void setup()
{
    pinMode(13,OUTPUT);
    digitalWrite(13,HIGH);

    Serial.begin(115200);
    Serial1.begin(115200);

    LimiterOnButton.begin();
    StereoImagerOnButton.begin();
    SaturationrOnButton.begin();

    StopButton.begin();
    PlayPauseButton.begin();
    PrevButton.begin();
    FwdButton.begin();
    ABButton.begin();
}

void loop()
{
    teensyMixer.compressorThreshold = analogRead(A20);
    teensyMixer.compressorRatio     = analogRead(A21);
    teensyMixer.compressorAttack    = analogRead(A22);
    teensyMixer.comppressorRelease  = analogRead(A14);

    teensyMixer.limiterGain     = analogRead(A15);
    teensyMixer.limiterCieling  = analogRead(A16);
    teensyMixer.limiterAttack   = analogRead(A17);
    teensyMixer.limiterRelease  = analogRead(A18);

    teensyMixer.stereoImagerLow     = analogRead(A1);
    teensyMixer.stereoImagerLowMid  = analogRead(A2);
    teensyMixer.stereoImagerHighMid = analogRead(A3);
    teensyMixer.stereoImagerHigh    = analogRead(A4);

    teensyMixer.saturationDrive     = analogRead(A5);
    teensyMixer.saturationDryWet    = analogRead(A6);

    teensyMixer.gain  = analogRead(A19);
    teensyMixer.volumeSlider = analogRead(A0);

    teensyMixer.stereoImagerOnButton = StereoImagerOnButton.isButtonPressed();
    teensyMixer.saturationOnButton = SaturationrOnButton.isButtonPressed();

    teensyMixer.ABButton = ABButton.isButtonPressed();
    teensyMixer.fwdButton = FwdButton.isButtonPressed();
    teensyMixer.prevButton = PrevButton.isButtonPressed();
    teensyMixer.playPauseButton = PlayPauseButton.isButtonPressed();
    teensyMixer.stopButton = StopButton.isButtonPressed();
    teensyMixer.limiterOnButton = LimiterOnButton.isButtonPressed();

    mixerJson["compressorThreshold"] = teensyMixer.compressorThreshold;
    mixerJson["compressorRatio"] = teensyMixer.compressorRatio;
    mixerJson["compressorAttack"] = teensyMixer.compressorAttack;
    mixerJson["comppressorRelease"] = teensyMixer.comppressorRelease;

    mixerJson["limiterOnButton"] = teensyMixer.limiterOnButton;
    mixerJson["limiterGain"] = teensyMixer.limiterGain;
    mixerJson["limiterCieling"] = teensyMixer.limiterCieling;
    mixerJson["limiterAttack"] = teensyMixer.limiterAttack;
    mixerJson["limiterRelease"] = teensyMixer.limiterRelease;

    mixerJson["stereoImagerOnButton"] = teensyMixer.stereoImagerOnButton;
    mixerJson["stereoImagerLow"] = teensyMixer.stereoImagerLow;
    mixerJson["stereoImagerLowMid"] = teensyMixer.stereoImagerLowMid;
    mixerJson["stereoImagerHighMid"] = teensyMixer.stereoImagerHighMid;
    mixerJson["stereoImagerHigh"] = teensyMixer.stereoImagerHigh;

    mixerJson["saturationOnButton"] = teensyMixer.saturationOnButton;
    mixerJson["saturationDrive"] = teensyMixer.saturationDrive;
    mixerJson["saturationDryWet"] = teensyMixer.saturationDryWet;

    mixerJson["gain"] = teensyMixer.gain;
    mixerJson["volumeSlider"] = teensyMixer.volumeSlider;

    mixerJson["ABButton"] = teensyMixer.ABButton;
    mixerJson["fwdButton"] = teensyMixer.fwdButton;
    mixerJson["prevButton"] = teensyMixer.prevButton;
    mixerJson["playPauseButton"] = teensyMixer.playPauseButton;
    mixerJson["stopButton"] = teensyMixer.stopButton;
    mixerJson["limiterOnButton"] = teensyMixer.limiterOnButton;

    serializeJson(mixerJson, Serial1);
    //serializeJson(mixerJson, Serial);
    //Serial.println("");
    //debug();
}

void debug()
{
    Serial.print(teensyMixer.compressorThreshold);
    Serial.print(" ");
    Serial.print(teensyMixer.compressorRatio);
    Serial.print(" ");    
    Serial.print(teensyMixer.compressorAttack);
    Serial.print(" ");   
    Serial.print(teensyMixer.comppressorRelease);
    Serial.print(" "); 

    Serial.print(teensyMixer.limiterGain);
    Serial.print(" ");
    Serial.print(teensyMixer.limiterCieling);
    Serial.print(" ");
    Serial.print(teensyMixer.limiterAttack);
    Serial.print(" ");    
    Serial.print(teensyMixer.limiterRelease);   
    Serial.print(" ");

    Serial.print(teensyMixer.stereoImagerLow);
    Serial.print(" ");
    Serial.print(teensyMixer.stereoImagerLowMid);
    Serial.print(" ");
    Serial.print(teensyMixer.stereoImagerHighMid);
    Serial.print(" ");    
    Serial.print(teensyMixer.stereoImagerHigh);
    Serial.print(" ");

    Serial.print(teensyMixer.saturationDrive);
    Serial.print(" ");
    Serial.print(teensyMixer.saturationDryWet);
    Serial.print(" ");

    Serial.print(teensyMixer.gain);
    Serial.print(" ");    
    Serial.print(teensyMixer.volumeSlider);
    Serial.print(" ");

    Serial.print(teensyMixer.stereoImagerOnButton);
    Serial.print(" "); 
    Serial.print(teensyMixer.saturationOnButton);
    Serial.print(" "); 
    Serial.print(teensyMixer.ABButton);
    Serial.print(" "); 
    Serial.print(teensyMixer.fwdButton);
    Serial.print(" "); 
    Serial.print(teensyMixer.prevButton);
    Serial.print(" "); 
    Serial.print(teensyMixer.playPauseButton);
    Serial.print(" "); 
    Serial.print(teensyMixer.stopButton);
    Serial.print(" "); 
    Serial.print(teensyMixer.limiterOnButton);
    Serial.println("");
}
