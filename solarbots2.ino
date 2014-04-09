int button = 2;

int stick = 13;
int stickTime = 250;
int stickStart = 0;
int stickState = LOW;

int sol = 12;
int solTime = 500;
int solStart = 500;
int solState = LOW;


int cym = 11;
int cymTime = 1000;
int cymStart = 1000;
int cymState = LOW;

int band[] = {
  stick, sol, cym}; 

int startTime;
boolean go;
long prevSMillis = 0;
long prevCMillis = 0;
long prevNMillis = 0;

void setup(){
  Serial.begin(9600);
  pinMode(stick, OUTPUT);
  pinMode(sol, OUTPUT);  
  pinMode(cym, OUTPUT);
  pinMode(button, INPUT_PULLUP);
  go = false;
}

void loop(){

  if(digitalRead(button)==LOW){
    start();
  }
  Serial.println(go);
  if(go){
    int gogo = millis()-startTime;
    unsigned long currentMillis = millis();
    if(currentMillis - prevSMillis > stickTime){
      prevSMillis = currentMillis;
      if(stickState==LOW)
        stickState = HIGH;
      else
        stickState = LOW;

      digitalWrite(stick, stickState);
    }
    if(currentMillis - prevCMillis > cymTime){
      prevCMillis = currentMillis;
      if(cymState==LOW)
        cymState = HIGH;
      else
        cymState = LOW;

      digitalWrite(cym, cymState);
    }
    if(currentMillis - prevNMillis > solTime){
      prevNMillis = currentMillis;
      if(solState==LOW)
        solState = HIGH;
      else
        solState = LOW;

      digitalWrite(sol, solState);
    }
  }

  //    if(gogo>stickStart){
  //
  //      play(stick, stickState, stickTime, currentMillis);
  //    }
  //    if(gogo>solStart){
  //
  //      play(sol, solState, solTime, currentMillis);
  //    }
  //    if(gogo>cymStart){
  //
  //      play(cym, cymState, cymTime, currentMillis);
  //    }
  //  }
}

//void play(int instrument, int instrumentState, int time, unsigned long current){
//  if(current - prevMillis > time){
//    prevMillis = current;
//    if(instrumentState==LOW)
//      instrumentState = HIGH;
//    else
//      instrumentState = LOW;
//
//    digitalWrite(instrument, instrumentState);
//  }
//}

void start(){
  go = true;
  startTime = millis();
  prevSMillis = startTime;
  prevCMillis = startTime;
  prevNMillis = startTime;
  stickStart += startTime;
  solStart += startTime;
  cymStart += startTime;
}








