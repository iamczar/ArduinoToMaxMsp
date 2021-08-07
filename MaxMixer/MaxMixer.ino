#include "Button.h"
#include "Mixer.h"
#include "Multiplexer.h"
#include "Mux.h"

// mux 1 channels
// equaliser
#define chanFreqAnalogueLeft 15
#define chanFreqAnalogueMidLeft 14
#define chanFreqAnalogueMidRight 13
#define chanFreqAnalogueRight 12

#define chanGainAnalogueLeft 11
#define chanGainAnalogueMidLeft 10
#define chanGainAnalogueMidRight 9
#define chanGainAnalogueRight 8

#define chanQAnalogueLeft 7
#define chanQAnalogueMidLeft 6
#define chanQAnalogueMidRight 5
#define chanQAnalogueRight 4

// saturation
#define chanSaturationDrive 1
#define chanSaturationDryWet 0

// mux 2 channels

// compressor
#define chanThresholdAnalogue 15
#define chanRatioAnalogue 14
#define chanAttackAnalogue 13
#define chanReleaseAnalogue 12

// limiter
#define chanLimiterGainAnalogue 7
#define chanLimiterCielingAnalogue 6
#define chanLimiterAttackAnalogue 5
#define chanLimiterReleaseAnalogue 4

// stereo imager
#define chanStereoLowAnalogue 11
#define chanStereoLmidAnalogue 10
#define chanStereoHmidAnalogue 9
#define chanStereoHighAnalogue 8

#define chanVolumeSilder 0
#define chanMiddleGain 1


// mux 1 variables
#define mux1CtrlPin1 8
#define mux1ctrlPin2 9
#define mux1ctrlPin3 10
#define mux1ctrlPin4 11
#define mux1analogReadPin A0

#define mux2CtrlPin1 2
#define mux2ctrlPin2 3
#define mux2ctrlPin3 4
#define mux2ctrlPin4 5
#define mux2analogReadPin A1

// Multiplexer multiplexer1(mux1CtrlPin1,
//                          mux1ctrlPin2,
//                          mux1ctrlPin3,
//                          mux1ctrlPin4,
//                          mux1analogReadPin);



Mux multiplexer1(mux1CtrlPin1,
                mux1ctrlPin2,
                mux1ctrlPin3,
                mux1ctrlPin4,
                mux1analogReadPin);

Mux multiplexer2(mux2CtrlPin1,
                mux2ctrlPin2,
                mux2ctrlPin3,
                mux2ctrlPin4,
                mux2analogReadPin);

// Pin TBD
Button Gbutton(22);
Button EQ1Button(24);
Button C1Button(26);
Button SAButton(28);
Button EQ2Button(31);
Button C2Button(33);
Button SIButton(35);
Button L1Button(37);
Button L2Button(39);

Button EqualizserOnButton(30);
Button CompressorOnButton(41);
Button LimiterOnButton(44);
Button StereoImagerOnButton(46);
Button SaturationrOnButton(48);

Button StopButton(222);
Button PlayPauseButton(34);
Button PrevButton(38);
Button FwdButton(36);
Button ABBUtton(42);

Mixer mixer;

void setup() 
{

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
  //top buttons
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

  mixer.freqAnalogueLeft      = multiplexer1.read(chanFreqAnalogueLeft);
  mixer.freqAnalogueMidLeft   = multiplexer1.read(chanFreqAnalogueMidLeft);
  mixer.freqAnalogueMidRight  = multiplexer1.read(chanFreqAnalogueMidRight);
  mixer.freqAnalogueRight     = multiplexer1.read(chanFreqAnalogueRight);

  mixer.gainAnalogueLeft      = multiplexer1.read(chanGainAnalogueLeft);
  mixer.gainAnalogueMidLeft   = multiplexer1.read(chanGainAnalogueMidLeft);
  mixer.gainAnalogueMidRight  = multiplexer1.read(chanGainAnalogueMidRight);
  mixer.gainAnalogueRight     = multiplexer1.read(chanGainAnalogueRight);

  mixer.QAnalogueLeft         = multiplexer1.read(chanQAnalogueLeft);
  mixer.QAnalogueMidLeft      = multiplexer1.read(chanQAnalogueMidLeft);
  mixer.QAnalogueMidRight     = multiplexer1.read(chanQAnalogueMidRight);
  mixer.QAnalogueRight        = multiplexer1.read(chanQAnalogueRight);
  
  // // // Saturation 
  // mixer.saturationOnButton    = SaturationrOnButton.isButtonPressed();
  // mixer.saturationDrive       = multiplexer1.read(chanSaturationDrive);
  // mixer.saturationDryWet      = multiplexer1.read(chanSaturationDryWet);

  // // mux 2 channels

  // // compressor
  // mixer.compressonOnButton    = CompressorOnButton.isButtonPressed();
  // mixer.thresholdAnalogue     = multiplexer1.read(chanThresholdAnalogue);
  // mixer.ratioAnalogue         = multiplexer2.read(chanRatioAnalogue);
  // mixer.attackAnalogue        = multiplexer2.read(chanAttackAnalogue);
  // mixer.releaseAnalogue       = multiplexer2.read(chanReleaseAnalogue);

  // // limiter
  // mixer.limiterOnButton       = LimiterOnButton.isButtonPressed();
  // mixer.limiterGainAnalogue   = multiplexer2.read(chanLimiterGainAnalogue);
  // mixer.limiterCielingAnalogue = multiplexer2.read(chanLimiterCielingAnalogue);
  // mixer.limiterAttackAnalogue = multiplexer2.read(chanLimiterAttackAnalogue);
  // mixer.limiterReleaseAnalogue= multiplexer2.read(chanLimiterReleaseAnalogue);

  // // stereo imager
  // mixer.stereoImagerOnButton  = StereoImagerOnButton.isButtonPressed();
  // mixer.stereoLowAnalogue     = multiplexer2.read(chanStereoLowAnalogue);
  // mixer.stereoLmidAnalogue    = multiplexer2.read(chanStereoLmidAnalogue);
  // mixer.stereoHmidAnalogue    = multiplexer2.read(chanStereoHmidAnalogue);
  // mixer.stereoHighAnalogue    = multiplexer2.read(chanStereoHighAnalogue);

  // // // buttom buttons
  // mixer.stopButton            = StopButton.isButtonPressed();
  // mixer.playPauseButton       = PlayPauseButton.isButtonPressed();
  // mixer.prevButton            = PrevButton.isButtonPressed();
  // mixer.fwdButton             = FwdButton.isButtonPressed();

  // mixer.ABButton              = ABBUtton.isButtonPressed();

  // mixer.volumeSilder          = multiplexer2.read(chanVolumeSilder);

  // mixer.Gain                  = multiplexer2.read(chanMiddleGain);

  mixer.sendMixerToMax();

  Serial.println(".....");

}
