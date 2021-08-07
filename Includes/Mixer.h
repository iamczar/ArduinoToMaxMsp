#include "Arduino.h"

class Mixer
{
public:
    Mixer();

    ~Mixer();

    void sendMixerToMax();

    String buildTopButtons();
    String buildEqualiser();
    String buildCompressor();
    String buildLimiter();
    String buildStereoImager();
    String buildSaturation();
    String buildButtomButtonsAndVolSlider();

    // top buttons
    int GButton;
    int EQ1Button;
    int C1Button;
    int SAButton;
    int EQ2Button;
    int C2Button;
    int SIButton;
    int L1Button;
    int L2Button;

    // equaliser
    int equaliserOnButton;
    int freqAnalogueLeft;
    int freqAnalogueMidLeft;
    int freqAnalogueMidRight;
    int freqAnalogueRight;

    int gainAnalogueLeft;
    int gainAnalogueMidLeft;
    int gainAnalogueMidRight;
    int gainAnalogueRight;

    int QAnalogueLeft;
    int QAnalogueMidLeft;
    int QAnalogueMidRight;
    int QAnalogueRight;

    // compressor
    int compressonOnButton;
    int thresholdAnalogue;
    int ratioAnalogue;
    int attackAnalogue;
    int releaseAnalogue;

    // limiter
    int limiterOnButton;
    int limiterGainAnalogue;
    int limiterCielingAnalogue;
    int limiterAttackAnalogue;
    int limiterReleaseAnalogue;

    // stereo imager
    int stereoImagerOnButton;
    int stereoLowAnalogue;
    int stereoLmidAnalogue;
    int stereoHmidAnalogue;
    int stereoHighAnalogue;

    // saturation
    int saturationOnButton;
    int saturationDrive;
    int saturationDryWet;

    // bottom
    int stopButton;
    int playPauseButton;
    int prevButton;
    int fwdButton;

    int volumeSilder;
    int ABButton;

    // middle
    int Gain;
};

