const int ledPinI =  3;
const int ledPinD =  5;


int ledStateI = LOW;
int ledStateD = LOW;
unsigned long previousMillis = 0;

const long interval = 200;
int incomingByte;

int parpadeoI = 0;
int parpadeoD = 0;

void setup() {

  pinMode(ledPinI, OUTPUT);
  pinMode(ledPinD, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  lecturapuerto();
  if (parpadeoI == 1) {
    controlLEDmillisI();
  }
  if (parpadeoD == 1) {
    controlLEDmillisD();
  }

  digitalWrite(ledPinI, ledStateI);
  digitalWrite(ledPinD, ledStateD);
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
  }
}
