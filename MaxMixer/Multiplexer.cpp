#include "Multiplexer.h"
#include "Arduino.h"

Multiplexer::Multiplexer(int ctrlPin1,
                        int ctrlPin2,
                        int ctrlPin3,
                        int ctrlPin4,
                        int analogReadPin)
{
    _ctrlPin1 = ctrlPin1;
    _ctrlPin2 = ctrlPin2;
    _ctrlPin3 = ctrlPin3;
    _ctrlPin4 = ctrlPin4;
    _analogReadPin = analogReadPin;
}

Multiplexer::~Multiplexer()
{

}

void Multiplexer::begin()
{
    pinMode(_ctrlPin1, OUTPUT); 
    pinMode(_ctrlPin2, OUTPUT); 
    pinMode(_ctrlPin3, OUTPUT); 
    pinMode(_ctrlPin4, OUTPUT); 

    digitalWrite(_ctrlPin1, LOW);
    digitalWrite(_ctrlPin2, LOW);
    digitalWrite(_ctrlPin3, LOW);
    digitalWrite(_ctrlPin4, LOW);
}

int Multiplexer::readChannel(int channel)
{
    int controlPin[] = {_ctrlPin1, _ctrlPin2, _ctrlPin3, _ctrlPin4};

    int muxChannel[16][4]={
    {0,0,0,0}, //channel 0
    {1,0,0,0}, //channel 1
    {0,1,0,0}, //channel 2
    {1,1,0,0}, //channel 3
    {0,0,1,0}, //channel 4
    {1,0,1,0}, //channel 5
    {0,1,1,0}, //channel 6
    {1,1,1,0}, //channel 7
    {0,0,0,1}, //channel 8
    {1,0,0,1}, //channel 9
    {0,1,0,1}, //channel 10
    {1,1,0,1}, //channel 11
    {0,0,1,1}, //channel 12
    {1,0,1,1}, //channel 13
    {0,1,1,1}, //channel 14
    {1,1,1,1}  //channel 15
    };

    //loop through the 4 sig
    for(int i = 0; i < 4; i ++){
        digitalWrite(controlPin[i], muxChannel[channel][i]);
    }
    
    //read the value at the SIG pin
    int val = analogRead(_analogReadPin);

    //return the value
    return val;

}