#include "Arduino.h"
#include "Instrument.h"

Instrument::Instrument(int _outputPin, int _i1Pin, int i2Pin, bool _servo){
  outputPin = _outputPin;
  i1Pin = _i1Pin;
  i2Pin = _i2Pin;

  pinMode(outputPin, OUTPUT);
  pinMode(i1Pin, INPUT);
  pinMode(i2Pin, INPUT);
  servo = _servo;
  if(servo) attach(pin);
  //play variables
  state = LOW;
  //timing
  prevMillis = 0;
  realTime = 0;
  att = 0;
  stop = false;
}

void Instrument::attach(servoPin){
  servoMotor.attach(servoPin);
}

void Instrument::pattern(int _interval1, int _interval2){
  i1 = _interval1; 
  i2 = _interval2;
  //need logic on reacting depending on the value

}

void Instrument::attention(){
  att = millis();
  prevMillis = att;
}

void Instrument::stop(){
  stop = true;
}

void Instrument::play(){
  realTime = millis()-att;
  //past the start time or NOT longer than the duration.
  if(realTime>start){
    //compare to previous loop to see if its time to change state
    unsigned long currentMillis = millis();
    if(currentMillis - prevMillis > interval){
      prevMillis = currentMillis;
      //if its a servo, we need to do things a bit differently
      if(state==LOW)
        state = HIGH;
      else
        state = LOW;
      digitalWrite(pin, state);
    }
  }
}

void Instrument::servoPlay(int realTime, int start, int interval, int duration, int startAngle, int strikeAngle){
  servoMotor.write(startAngle);
  if(realTime>start && realTime<(start+duration)){
    //compare to previous loop to see if its time to change state
    unsigned long currentMillis = millis();
    if(currentMillis - prevMillis > interval){
        prevMillis = currentMillis;
        //if its a servo, we need to do things a bit differently
      servoMotor.write(strikeAngle);
    }
  }
}
