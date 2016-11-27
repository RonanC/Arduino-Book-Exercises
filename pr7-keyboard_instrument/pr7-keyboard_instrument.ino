int buttons[6];
// set up an array with 6 integers

// Middle C, D, E, F (http://phy.mtu.edu/~suits/notefreqs.html)
int notes[] = {262, 294, 330, 349};

void setup() {
  Serial.begin(9600);
  
  buttons[0] = 2;
  // give the first element of the array the value 2
}

void loop() {
  // keyVal = electricity given back, resistence is blocking this
  int keyVal = analogRead(A0);
  
//  if(millis() % 1000 == 0){
      Serial.print(keyVal);
      Serial.print("\n");
//  }

  if(keyVal >= 1001 && keyVal <= 1002){
    tone(8, notes[1]);
  }
  else if(keyVal >= 970 && keyVal <= 1025){
    tone(8, notes[0]);
  }
  else if(keyVal >= 505 && keyVal <= 515){
    tone(8, notes[2]);
  }
  else if(keyVal >= 5 && keyVal <= 10){
    tone(8, notes[3]);
  }
  else {
    noTone(8);
  }
}
