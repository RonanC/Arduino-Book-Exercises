int sensorPitchValue;
int sensorPitchLow = 1023;
int sensorPitchHigh = 0;

//int sensorVolValue;
//int sensorVolLow = 1023;
//int sensorVolHigh = 0;

const int ledPin = 13;

void setup() {
  Serial.begin(9600);
    
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);

  while(millis() < 5000){
    // pitch
    sensorPitchValue = analogRead(A0);

    if(sensorPitchValue > sensorPitchHigh){
      sensorPitchHigh = sensorPitchValue;
    }
    if(sensorPitchValue < sensorPitchLow){
      sensorPitchLow = sensorPitchValue;
    }

//    // volume
//    sensorVolValue = analogRead(A1);
//
//    if(sensorVolValue > sensorVolHigh){
//      sensorVolHigh = sensorVolValue;
//    }
//    if(sensorVolValue < sensorVolLow){
//      sensorVolLow = sensorVolValue;
//    }
  }

  digitalWrite(ledPin, LOW);
}

void loop() {
  sensorPitchValue = analogRead(A0);
  int pitch = map(sensorPitchValue, sensorPitchLow, sensorPitchHigh, 40, 1000);

  Serial.print("pitch: ");
  Serial.print(pitch);

//  sensorVolValue = analogRead(A1);
//  pitch = pitch / sensorPitchValue;
//  Serial.print("\tsensorVolValue: ");
//  Serial.print(sensorVolValue);
  Serial.print("\n");

  tone(8, pitch, 20); // plays for 20 milli seconds

  delay(10);  // mixes with next tone
}
