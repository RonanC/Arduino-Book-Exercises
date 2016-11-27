#include<Servo.h>
Servo myServo;

const int piezo = A0;
const int switchPin = 2;

const int yellowLed = 3;
const int greenLed = 4;
const int redLed = 5;

int knockVal;
int switchVal;

//const int quietKnock = 10;
//const int loudKnock = 100;

//const int quietKnock = 1;
//const int loudKnock = 1;

const int unlockKnocklow = 2;
const int unlockKnockHigh = 20;

const int interval = 1000;
unsigned long previousTime = 0;

boolean locked = false;
int numberOfKnocks = 0;

const int lockKnockLow = 1;
const int lockKnockHigh = 1;
int numLockKnocks = 0;

int lockNum = 2;
int unlockNum = 2;

void setup() {
  myServo.attach(9);

  pinMode(yellowLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(redLed, OUTPUT);

  pinMode(switchPin, INPUT);

  Serial.begin(9600);

  digitalWrite(greenLed, HIGH);
  myServo.write(0);
  Serial.println("The box is unlocked!");
}

void loop() {
  unsigned long currentTime = millis();

  //  if (locked == false) {
  //    switchVal = digitalRead(switchPin);
  //
  //    if (switchVal == HIGH) {
  //      locked = true;
  //
  //      digitalWrite(greenLed, LOW);
  //      digitalWrite(redLed, HIGH);
  //
  //      myServo.write(90);
  //
  //      Serial.println("The box is locked!");
  //      delay(1000);
  //    }
  //  }

  if (locked == false) {
    knockVal = analogRead(piezo);

    if (numLockKnocks < lockNum && knockVal > 0) {
      if (currentTime - previousTime > interval) {
        Serial.println();
        previousTime = currentTime;
        if (checkLockKnock(knockVal) == true) {
          numLockKnocks++;
        }
        Serial.print(lockNum - numLockKnocks);
        Serial.println(" more lock knocks to go");
        //        Serial.println("Knock lock activated");
      }
    }

    if (numLockKnocks >= lockNum) {
      locked = true;
      numLockKnocks = 0;
      myServo.write(90);
      delay(20);
      digitalWrite(greenLed, LOW);
      digitalWrite(redLed, HIGH);
      Serial.println("The box is locked!");
    }
  }

  if (locked == true) {
    knockVal = analogRead(piezo);

    if (numberOfKnocks < unlockNum && knockVal > 0) {
      if (currentTime - previousTime > interval) {
        Serial.println();
        previousTime = currentTime;
        if (checkForKnock(knockVal) == true) {
          numberOfKnocks++;
        }

        Serial.print(unlockNum - numberOfKnocks);
        Serial.println(" more knocks to go");
      }
    }

    if (numberOfKnocks >= unlockNum) {
      locked = false;
      numberOfKnocks = 0;
      myServo.write(0);
      delay(20);
      digitalWrite(greenLed, HIGH);
      digitalWrite(redLed, LOW);
      Serial.println("The box is unlocked!");
    }
  }
}

boolean checkForKnock(int value) {
  if (value > unlockKnocklow && value < unlockKnockHigh) {
    //  if (value == specificKnock) {
    digitalWrite(yellowLed, HIGH);
    delay(50);
    digitalWrite(yellowLed, LOW);

    Serial.print("Valid knock of value ");
    Serial.println(value);

    return true;
  }
  else {
    Serial.print("Bad knock value ");
    Serial.println(value);

    return false;
  }
}

boolean checkLockKnock(int value) {
  //  if (value > quietKnock && value < loudKnock) {
  if (value >= lockKnockLow && value <= lockKnockHigh) {
    digitalWrite(yellowLed, HIGH);
    delay(50);
    digitalWrite(yellowLed, LOW);

    Serial.print("Valid lock knock of value ");
    Serial.println(value);

    return true;
  }
  else {
    Serial.print("Bad lock knock value ");
    Serial.println(value);

    return false;
  }
}

