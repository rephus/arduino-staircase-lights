#define IR_RECEIVER 8
#define RELAY 10

void setup() {
    pinMode(RELAY, OUTPUT);
  digitalWrite(RELAY, LOW);

}

unsigned long lastTimeDetected=0; 
#define TIME_TO_WAIT 60000

// the loop function runs over and over again forever
void loop() {

/**
  lastTimeDetected should always be >= than millis()
  if this is not the case, is because millis() had an overflow
  and it is starting from 0 again
**/
  if (millis() < lastTimeDetected) { // Reset on rollover 
    digitalWrite(RELAY, LOW);
    lastTimeDetected = 0 
  }
  
  int sensorValue = digitalRead(IR_RECEIVER);

  if (sensorValue == 0 ) {
    digitalWrite(RELAY, HIGH);   // turn the LED on (HIGH is the voltage level)

    // millis(): Returns the number of milliseconds passed since the Arduino board began running the current program. 
    // This number will overflow (go back to zero), after approximately 50 days.
    lastTimeDetected= millis() ; 
  }

  if (lastTimeDetected + TIME_TO_WAIT < millis() ) {
    digitalWrite(RELAY, LOW);

  }
  delay(100);

}
