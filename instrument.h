#ifndef Instrument_h
#define Instrument_h

#include "Arduino.h"
#include "Servo.h"

class Instrument
{
  public:
    Instrument(int _pin, boolean _servo);
    //play functions
    
    void pattern(int _realTime, int _start, int _interval, int_duration);
    void attention();
    void play();
    void servoPlay(int startAngle, int strikeAngle);
    

    //if its a servo we need this stuff.
    Servo servoMotor;
    void attach();

    //instantiated in the constructor
    int pin;
    int state;
    bool servo;
    //timing vars
    long att;
    long realTime;
    bool stop;
    //instantiated/overwritten in the pattern function
    int start;
    int interval;
    int duration;
};

#endif