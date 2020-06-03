const int ledPin =  6;
const int ledPinI =  3;
const int ledPinD =  5;

int ledState = 0;
int ledStateI = 0;
int ledStateD = 0;
unsigned long previousMillis = 0;

const long interval = 200;
int incomingByte;

int parpadeo = 0;
int parpadeoI = LOW;
int parpadeoD = LOW;

void setup() {

  pinMode(ledPinI, OUTPUT);
  pinMode(ledPinD, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  lecturapuerto();
  if (parpadeo == 1) {
    controlLEDmillis();
  }
  if (parpadeoI == 1) {
    controlLEDmillisI();
  }
  if (parpadeoD == 1) {
    controlLEDmillisD();
  }

  digitalWrite(ledPinI, ledStateI);
  digitalWrite(ledPinD, ledStateD);
  analogWrite(ledPin, ledState);
}

void controlLEDmillis() {

  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {

    previousMillis = currentMillis;
    if (ledState == 0) {
      ledState = 255;
    } else {
      ledState = 0;
    }
  }
}

void controlLEDmillisI() {

  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {

    previousMillis = currentMillis;
    if (ledStateI == LOW) {
      ledStateI = HIGH;
    } else {
      ledStateI = LOW;
    }
  }
}

void controlLEDmillisD() {

  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {

    previousMillis = currentMillis;
    if (ledStateD == LOW) {
      ledStateD = HIGH;
    } else {
      ledStateD = LOW;
    }
  }
}

void lecturapuerto() {

  if (Serial.available() > 0) {

    incomingByte = Serial.read();
    
    if (incomingByte == 'I') {
      parpadeoI = 1;
      parpadeoD = 0;
      ledStateD = LOW;
    }
    if (incomingByte == 'A') {
      ledStateI = LOW;
      parpadeoI = 0;
      ledStateD = LOW;
      parpadeoD = 0;
    }
    if (incomingByte == 'D') {
      parpadeoD = 1;
      parpadeoI = 0;
      ledStateI = LOW;
    }
    if (incomingByte == 'N') {
      parpadeo = 1;
    }
    else if (incomingByte == 'G') {
      ledState = 0;
      parpadeo = 0;
    }
    else if (incomingByte == 'F') {
      ledState = 255;
      parpadeo = 0;
    }
    else if (incomingByte == 'P') {
      ledState = 50;
      parpadeo = 0;
    }
  }
}
