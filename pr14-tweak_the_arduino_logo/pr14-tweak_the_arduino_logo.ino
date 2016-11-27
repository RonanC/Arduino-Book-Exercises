//int sensorValue;
//int sensorLow = 1023;
//int sensorHigh = 0;

void setup() {
  Serial.begin(9600);

  //  while (millis() < 5000) {
  //    sensorValue = analogRead(A0);
  //
  //    if (sensorValue > sensorHigh) {
  //      sensorHigh = sensorValue;
  //    }
  //
  //    if (sensorValue < sensorLow) {
  //      sensorLow = sensorValue;
  //    }
  //  }
}

void loop() {
  //  sensorValue = analogRead(A0);
  //  int hue = map(sensorValue, sensorLow, sensorHigh, 0, 122);
  //  Serial.write(hue);

  Serial.write(analogRead(A0) / 4);
  delay(100);
}
