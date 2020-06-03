  const int ledPin =  6;


int ledState = LOW;
unsigned long previousMillis = 0;

const long interval = 200;
int incomingByte;

int parpadeo = 0;

void setup() {

  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  lecturapuerto();
  if (parpadeo == 1) {
    controlLEDmillis();
  }

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

void lecturapuerto() {

  if (Serial.available() > 0) {

    incomingByte = Serial.read();
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
