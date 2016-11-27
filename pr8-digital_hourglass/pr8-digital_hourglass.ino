
const int switchPin = 8;
unsigned long previousTime = 0;

int switchState = 0;
int prevSwitchState = 0;

int led = 2;

//int oneSecond = 6000;
//long interval = oneSecond * 10; // 1 minute

long interval = 1000;

bool shook = false;
      
void setup() {
  for(int i = 2; i < 8; i++){
    pinMode(i, OUTPUT);
  }

  pinMode(switchPin, INPUT);
}

void loop() {
  unsigned long currentTime = millis();

  if(currentTime - previousTime > interval){
    previousTime = currentTime;
    digitalWrite(led, HIGH);
    led++;

    if(led == 8){
      // flash all leds
      shook = false;
      
      while(shook == false){
        switchState = digitalRead(switchPin);
        if(switchState != prevSwitchState){
          shook = true;
        }
          
        delay(500);
        for(int i = 2; i < 8; i++){
          digitalWrite(i, LOW);
        }

        switchState = digitalRead(switchPin);
        if(switchState != prevSwitchState){
          shook = true;
        }
        
        delay(500);
        for(int i = 2; i < 8; i++){
          digitalWrite(i, HIGH);
        }
      }

      // sound alarm
    }
  }

  switchState = digitalRead(switchPin);

  if(switchState != prevSwitchState || shook == true){
    for(int i = 2; i < 8; i++){
      digitalWrite(i, LOW);
    }

    led = 2;
    previousTime = currentTime;
  }

  prevSwitchState = switchState;
}
