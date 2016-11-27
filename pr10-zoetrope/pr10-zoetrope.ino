const int controlPin1 = 2;
const int controlPin2 = 3;
const int enablePin = 9;
const int directionSwitchPin = 4;
const int onOffSwitchStatePin = 5;
const int potPin = A0;

int onOffSwitchState = 0;
int previousOnOffSwitchState = 0;
int directionSwitchState = 0;
int previousDirectionSwitchState = 0;

int motorEnabled = 0;
int motorSpeed = 0;
int motorDirection = 1;

void setup() {
  // switches
  pinMode(directionSwitchPin, INPUT);
  pinMode(onOffSwitchStatePin, INPUT);

  // h bridge
  pinMode(controlPin1, OUTPUT);
  pinMode(controlPin2, OUTPUT);
  pinMode(enablePin, OUTPUT);

  digitalWrite(enablePin, LOW); // power off the motor as default
}

void loop() {
  onOffSwitchState = digitalRead(onOffSwitchStatePin);
  delay(1);
  directionSwitchState = digitalRead(directionSwitchPin);

  // potentiometer
  motorSpeed = analogRead(potPin) / 4;  // motor has four times less range then the potentiometer

  // SECOND PAGE
  if(onOffSwitchState != previousOnOffSwitchState){
    if(onOffSwitchState == HIGH){
      motorEnabled = !motorEnabled;
    }
  }

  if(directionSwitchState != previousDirectionSwitchState){
    if(directionSwitchState == HIGH){
      motorDirection = !motorDirection;
    }
  }

  // turn motor on
  if(motorDirection == 1){
    digitalWrite(controlPin1, LOW);
    digitalWrite(controlPin2, HIGH);
  }
  else{
    digitalWrite(controlPin1, HIGH);
    digitalWrite(controlPin2, LOW);
  }

  if(motorEnabled == 1){
    analogWrite(enablePin, motorSpeed);
  }
  else{
    analogWrite(enablePin, 0); // 0 == LOW == off
  }

  previousDirectionSwitchState = directionSwitchState;
  previousOnOffSwitchState = onOffSwitchState;
  
}
