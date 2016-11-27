//const int switchPin = 2;
const int potPin = A0;
const int motorPin = 9;
//int switchState = 0;
int potValue = 0;
int spinSpeed;

void setup() {
//  pinMode(motorPin, OUTPUT);
  pinMode(motorPin, OUTPUT);
//  pinMode(potPin, INPUT);
}

void loop() {
//  switchState = digitalRead(switchPin);

//  if(switchState == HIGH){
//    digitalWrite(motorPin, HIGH);
//  }
//  else{
//    digitalWrite(motorPin, LOW);
//  }

  // hook up a potentiometer to very the speed, rather then a button
  potValue = analogRead(potPin);
  spinSpeed = potValue / 4;
  analogWrite(motorPin, spinSpeed);
}
