#define IR_RECEIVER 8
#define RELAY 10

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
    pinMode(RELAY, OUTPUT);
  digitalWrite(RELAY, LOW);

}

// the loop function runs over and over again forever
void loop() {

  int sensorValue = digitalRead(IR_RECEIVER);
  // print out the value you read:
  delay(10);        // delay in between reads for stability

  if (sensorValue == 0 ) {
    digitalWrite(RELAY, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(5000);
  }
  else {
    digitalWrite(RELAY, LOW);

  }
}
