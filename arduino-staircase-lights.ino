#define IR_RECEIVER 8
#define RELAY 10

void setup() {
    pinMode(RELAY, OUTPUT);
  digitalWrite(RELAY, LOW);
 // Serial.begin(9600);

}

unsigned long lastTimeDetected=0; 
#define TIME_TO_WAIT 60000

// the loop function runs over and over again forever
void loop() {

  int sensorValue = digitalRead(IR_RECEIVER);

  if (sensorValue == 0 ) {
    digitalWrite(RELAY, HIGH);   // turn the LED on (HIGH is the voltage level)

    // millis(): Returns the number of milliseconds passed since the Arduino board began running the current program. 
    // This number will overflow (go back to zero), after approximately 50 days.
    lastTimeDetected= millis() ; 
  }
  /*Serial.print("sensor");
  Serial.println(sensorValue);
  Serial.print("lastTimeDetected");
  Serial.println(lastTimeDetected);
*/
  if (lastTimeDetected + TIME_TO_WAIT < millis() ) {
    digitalWrite(RELAY, LOW);

  }
  delay(100);

}
