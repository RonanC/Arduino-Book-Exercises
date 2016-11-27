int switchState = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(2, INPUT);  // switch
  pinMode(3, OUTPUT); // green led
  pinMode(4, OUTPUT); // red led
  pinMode(5, OUTPUT); // red led
}

void loop() {
  // put your main code here, to run repeatedly:
  switchState = digitalRead(2);

  if(switchState == LOW){
    // button is not pressed
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
  }
  else{
    // button is pressed
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);

    delay(250); // wait for a quarter second
    digitalWrite(4, LOW); // toggle the leds
    digitalWrite(5, LOW);
    delay(250);
  }
} // go back to the beginning of the loop
