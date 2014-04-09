#ifndef Instrument_h
#define Instrument_h

#include "Arduino.h"
#include "Servo.h"

class Instrument
{
public:
    Instrument(int _pin, bool _servo);
    //play functions
    
    void pattern(int _interval1, int _interval2);
    void attention();
    void play();
    void servoPlay(int startAngle, int strikeAngle);
    
private:
    //if its a servo we need this stuff.
    Servo servoMotor;
    void attach();

    //instantiated in the constructor
    int pin;
    int state;
    bool servo;
    //timing vars
    long att;
    long prevMillis;
    long realTime;
    bool stop;
    //interval vars sent by the Panel class
    int i1;
    int i2;
};

#endif