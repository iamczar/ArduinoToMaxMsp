#include "Button.h"
#include "Mixer.h"
#include "Multiplexer.h"

// mux 1 channels
// equaliser
#define chanFreqAnalogueLeft 0
#define chanFreqAnalogueMidLeft 1
#define chanFreqAnalogueMidRight 2
#define chanFreqAnalogueRight 3

#define chanGainAnalogueLeft 4
#define chanGainAnalogueMidLeft 5
#define chanGainAnalogueMidRight 6
#define chanGainAnalogueRight 7

#define chanQAnalogueLeft 8
#define chanQAnalogueMidLeft 9
#define chanQAnalogueMidRight 10
#define chanQAnalogueRight 11

// saturation
#define chanSaturationDrive 12
#define chanSaturationDryWet 13

// mux 2 channels

// compressor
#define chanThresholdAnalogue 0
#define chanRatioAnalogue 1
#define chanAttackAnalogue 2
#define chanReleaseAnalogue 3

// limiter
#define chanLimiterGainAnalogue 4
#define chanLimiterCielingAnalogue 5
#define chanLimiterAttackAnalogue 6
#define chanLimiterReleaseAnalogue 7

// stereo imager
#define chanStereoLowAnalogue 8
#define chanStereoLmidAnalogue 9
#define chanStereoHmidAnalogue 10
#define chanStereoHighAnalogue 11

#define chanVolumeSilder 12
#define chanMiddleGain 13


// mux 1 variables
#define mux1CtrlPin1 8
#define mux1ctrlPin2 9
#define mux1ctrlPin3 10
#define mux1ctrlPin4 11
#define mux1analogReadPin A0

// mux 2 variables - TBD
#define mux2CtrlPin1 4
#define mux2ctrlPin2 5
#define mux2ctrlPin3 6
#define mux2ctrlPin4 7
#define mux2analogReadPin A1

Multiplexer multiplexer1(mux1CtrlPin1,
                         mux1ctrlPin2,
                         mux1ctrlPin3,
                         mux1ctrlPin4,
                         mux1analogReadPin);

Multiplexer multiplexer2(mux2CtrlPin1,
                         mux2ctrlPin2,
                         mux2ctrlPin3,
                         mux2ctrlPin4,
                         mux2analogReadPin);

// Pin TBD
Button Gbutton(22);
Button EQ1Button(24);
Button C1Button(26;
Button SAButton(28);
Button EQ2Button(30);
Button C2Button(32);
Button SIButton(34);
Button L1Button(36);
Button L2Button(38);

Button EqualizserOnButton(40);
Button CompressorOnButton(42);
Button LimiterOnButton(44);
Button StereoImagerOnButton(46);
Button SaturationrOnButton(48);

Button StopButton(31);
Button PlayPauseButton(33);
Button PrevButton(35);
Button FwdButton(37);
Button ABBUtton(39);

Mixer mixer;

void setup() 
{
  multiplexer1.begin();
  multiplexer2.begin();

  Gbutton.begin();
  EQ1Button.begin();
  C1Button.begin();
  SAButton.begin();
  EQ2Button.begin();
  C2Button.begin();
  SIButton.begin();
  L1Button.begin();
  L2Button.begin();

  EqualizserOnButton.begin();
  CompressorOnButton.begin();
  LimiterOnButton.begin();
  StereoImagerOnButton.begin();
  SaturationrOnButton.begin();

  StopButton.begin();
  PlayPauseButton.begin();
  PrevButton.begin();
  FwdButton.begin();
  ABBUtton.begin();

  Serial.begin(9600);
}

void loop() 
{
  // top buttons
  mixer.GButton               = Gbutton.isButtonPressed();
  mixer.EQ1Button             = EQ1Button.isButtonPressed();
  mixer.C1Button              = C1Button.isButtonPressed();
  mixer.SAButton              = SAButton.isButtonPressed();
  mixer.EQ2Button             = EQ2Button.isButtonPressed();
  mixer.C2Button              = C2Button.isButtonPressed();
  mixer.SIButton              = SIButton.isButtonPressed();
  mixer.L1Button              = L1Button.isButtonPressed();
  mixer.L2Button              = L2Button.isButtonPressed();

  // mux 1 channels

  // Equaliser
  mixer.equaliserOnButton     = EqualizserOnButton.isButtonPressed();

  mixer.freqAnalogueLeft      = multiplexer1.readChannel(chanFreqAnalogueLeft);
  mixer.freqAnalogueMidLeft   = multiplexer1.readChannel(chanFreqAnalogueMidLeft);
  mixer.freqAnalogueMidRight  = multiplexer1.readChannel(chanFreqAnalogueMidRight);
  mixer.freqAnalogueRight     = multiplexer1.readChannel(chanFreqAnalogueRight);

  mixer.gainAnalogueLeft      = multiplexer1.readChannel(chanGainAnalogueLeft);
  mixer.gainAnalogueMidLeft   = multiplexer1.readChannel(chanGainAnalogueMidLeft);
  mixer.gainAnalogueMidRight  = multiplexer1.readChannel(chanGainAnalogueMidRight);
  mixer.gainAnalogueRight     = multiplexer1.readChannel(chanGainAnalogueRight);

  mixer.QAnalogueLeft         = multiplexer1.readChannel(chanQAnalogueLeft);
  mixer.QAnalogueMidLeft      = multiplexer1.readChannel(chanQAnalogueMidLeft);
  mixer.QAnalogueMidRight     = multiplexer1.readChannel(chanQAnalogueMidRight);
  mixer.QAnalogueRight        = multiplexer1.readChannel(chanQAnalogueRight);

  // Saturation 
  mixer.saturationOnButton    = SaturationrOnButton.isButtonPressed();
  mixer.saturationDrive       = multiplexer1.readChannel(chanSaturationDrive);
  mixer.saturationDryWet      = multiplexer1.readChannel(chanSaturationDryWet);

  // mux 2 channels

  // compressor
  mixer.compressonOnButton    = CompressorOnButton.isButtonPressed();
  mixer.thresholdAnalogue     = multiplexer2.readChannel(chanThresholdAnalogue);
  mixer.ratioAnalogue         = multiplexer2.readChannel(chanRatioAnalogue);
  mixer.attackAnalogue        = multiplexer2.readChannel(chanAttackAnalogue);
  mixer.releaseAnalogue       = multiplexer2.readChannel(chanReleaseAnalogue);

  // limiter
  mixer.limiterOnButton       = LimiterOnButton.isButtonPressed();
  mixer.limiterGainAnalogue   = multiplexer2.readChannel(chanLimiterGainAnalogue);
  mixer.limiterCielingAnalogue = multiplexer2.readChannel(chanLimiterCielingAnalogue);
  mixer.limiterAttackAnalogue = multiplexer2.readChannel(chanLimiterAttackAnalogue);
  mixer.limiterReleaseAnalogue= multiplexer2.readChannel(chanLimiterReleaseAnalogue);

  // stereo imager
  mixer.stereoImagerOnButton  = StereoImagerOnButton.isButtonPressed();
  mixer.stereoLowAnalogue     = multiplexer2.readChannel(chanStereoLowAnalogue);
  mixer.stereoLmidAnalogue    = multiplexer2.readChannel(chanStereoLmidAnalogue);
  mixer.stereoHmidAnalogue    = multiplexer2.readChannel(chanStereoHmidAnalogue);
  mixer.stereoHighAnalogue    = multiplexer2.readChannel(chanStereoHighAnalogue);

  // buttom buttons
  mixer.stopButton            = StopButton.isButtonPressed();
  mixer.playPauseButton       = PlayPauseButton.isButtonPressed();
  mixer.prevButton            = PrevButton.isButtonPressed();
  mixer.fwdButton             = FwdButton.isButtonPressed();

  mixer.ABButton              = ABBUtton.isButtonPressed();

  mixer.volumeSilder          = multiplexer2.readChannel(chanVolumeSilder);

  mixer.Gain                  = multiplexer2.readChannel(chanMiddleGain);

  delay(100);

  mixer.sendMixerToMax();

}
