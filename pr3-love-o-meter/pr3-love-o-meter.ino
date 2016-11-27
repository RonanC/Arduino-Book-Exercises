const int sensorPin = A0;
const float baselineTemp = 19.0;

void setup() {
  // 9600 bits per second (9.6 megabits per second) [1.2 megaBytes per second] 
  // Baud rate (view in arduino ide serial monitor)
  Serial.begin(9600); // open a serial port

  for(int pinNumber = 2; pinNumber < 5; pinNumber++){
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }
}

void loop() {
  int sensorVal = analogRead(sensorPin);  // reads a floating point number between 0 and 1023

  Serial.print("Sensor Value: ");
  Serial.print(sensorVal);

  // convert the ADC reading to a voltage
  float voltage = (sensorVal / 1023.0) * 5;

  Serial.print(", Volts: ");
  Serial.print(voltage);

  Serial.print(", degrees C: ");
  float temperature = (voltage - 0.5) * 100;
  Serial.println(temperature);

  if(temperature < baselineTemp){
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }else if(temperature >= baselineTemp+2 && temperature < baselineTemp+4){
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }else if(temperature >= baselineTemp+4 && temperature < baselineTemp+6){
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  }else if(temperature >= baselineTemp+6){
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
  }
  
  delay(1);
}
