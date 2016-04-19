void setup() {
  // initialize digital pin 13 as an output.
  pinMode(13, OUTPUT);
}

void loop() {
 
//Blink "S" morse code
for (int x = 0; x < 3; x++){
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(150);              // wait for a second
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(150);              // wait for a second
}

  delay(500);
  
//Blink "O" morse code
for (int x = 0; x < 3; x++){
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500);              // wait for a second
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(500);              // wait for a second
}

  delay(150);

//Blink "S" morse code
for (int x = 0; x < 3; x++){
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(150);              // wait for a second
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(150);              // wait for a second
}
}
