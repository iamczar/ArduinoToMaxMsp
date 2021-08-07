#include "Button.h"
#include "Arduino.h"


Button::Button(int pin)
{
    _pin = pin;
}

Button::~Button()
{
}

void Button::begin()
{
    pinMode(_pin,INPUT);
}

bool Button::isButtonPressed()
{
    if (HIGH == digitalRead(_pin))
    {
        return true;
    }
    else
    {
        return false;
    }

}
