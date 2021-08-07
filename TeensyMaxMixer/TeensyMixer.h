class TeensyMixer
{

public:
    TeensyMixer(/* args */);
    ~TeensyMixer();

    int compressorThreshold;
    int compressorRatio;
    int compressorAttack;
    int comppressorRelease;

    int limiterGain;
    int limiterCieling;
    int limiterAttack;
    int limiterRelease;

    int stereoImagerLow;
    int stereoImagerLowMid;
    int stereoImagerHighMid;
    int stereoImagerHigh;

    int saturationDrive;
    int saturationDryWet;

    int gain;
    int volumeSlider;

    int stereoImagerOnButton;
    int limiterOnButton;
    int saturationOnButton;

    int stopButton;       
    int playPauseButton;      
    int prevButton;         
    int fwdButton;            

    int ABButton;

    int volumeSilder; 

    int Gain;       

private:
    /* data */
};

