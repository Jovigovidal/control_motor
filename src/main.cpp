#include <Arduino.h>

int IN1 = 18;
int IN2 = 19;
int IN3 = 21;
int IN4 = 22;

void stepMotor(int step);

void setup() {
  // Configurar los pines como salida
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void loop() {
  // Secuencia para mover el motor paso a paso
  for (int i = 0; i < 512; i++) {  // Hacer 512 pasos (ajustable según el motor)
    stepMotor(i % 4);
    delay(3); // Retardo entre pasos
  }
}
// Función para mover el motor un paso
void stepMotor(int step) {
  switch (step) {
    case 0:
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
      break;
    case 1:
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
      break;
    case 2:
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      break;
    case 3:
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      break;
  }
}