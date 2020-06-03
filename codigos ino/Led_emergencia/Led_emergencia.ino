const int ledPin =  8; //Se asigna el pin al Led
int ledState = LOW; //Se declara el estado del Led  
      
unsigned long previousMillis = 0;      
const long interval = 500; //Intervalo de tiempo del parpadeo 
         
int incomingByte;
int parpadeo = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  //Se declara la salida del Led
  Serial.begin(9600);
  //Se declara la frecuencia
}

void loop() {
  lecturapuerto();
  if (parpadeo == 1) {
    controlLEDmillis();
  }
  digitalWrite(ledPin, ledState);
}

void controlLEDmillis() { //Se crea un void para el parpadeo
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }
  }
}

void lecturapuerto() { //Se crea un void para establecer la función de las letras que se mandarán por el teclado
  if (Serial.available() > 0) {
    incomingByte = Serial.read();
    if (incomingByte == 'h') {
      parpadeo = 1;
    }
    else if (incomingByte == 'l') {
      ledState = LOW;
      parpadeo = 0;
    }
  }
}
