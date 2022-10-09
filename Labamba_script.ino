#define pinBotaoA 5 // pino do button

#define pinSentido1MotorA 3 // pino do motor
#define pinSentido2MotorA 2 // pino motor 

// foi criado Três variaves para o botão pq ele tem três estadoa.
// Liga e gira no sendido horario, clica de novo e gira no sentido antihorario e clica de novo e desliga o brinquedo.
byte estadoA = 0;
bool estadoBotaoA = true;
bool estadoAntBotaoA = true;
unsigned long delayBotaoA;

void setup() {
  
  pinMode(pinBotaoA, INPUT_PULLUP);
  pinMode(pinSentido1MotorA, OUTPUT);
  pinMode(pinSentido2MotorA, OUTPUT);
 
}

void loop() {

  estadoBotaoA = digitalRead(pinBotaoA);
  if (!estadoBotaoA && estadoAntBotaoA) {
     if ((millis() - delayBotaoA) > 20) {
        estadoA++;
        if (estadoA > 2) {
           estadoA = 0;
        }
        delayBotaoA = millis();
     }
  } else if (estadoBotaoA != estadoAntBotaoA) {
        delayBotaoA = millis();    
  }

  estadoAntBotaoA = estadoBotaoA;

  switch(estadoA) {
    case 0: 
        digitalWrite(pinSentido1MotorA, LOW);
        digitalWrite(pinSentido2MotorA, LOW); 
      break;
      
    case 1: 
        digitalWrite(pinSentido1MotorA, LOW);
        digitalWrite(pinSentido2MotorA, HIGH); 
      break;
    
    case 2: 
        digitalWrite(pinSentido1MotorA, HIGH);
        digitalWrite(pinSentido2MotorA, LOW);  
      break;
  }
}
