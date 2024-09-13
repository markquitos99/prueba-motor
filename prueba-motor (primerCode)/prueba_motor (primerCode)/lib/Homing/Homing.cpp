#include "Homing.h"
// Función para operar el extrusor
void extrusorState(int steps) {
  moverEje(STEP_PIN_E, DIR_PIN_E, steps, ENABLE_PIN_Y);
  Estados = ESPERA;
}

// Función para el homing del eje X
void inicioXstate() {
  realizarHoming(STEP_PIN_X, DIR_PIN_X, FDCARRERA_X);
  Estados = ESPERA;
}

// Función para el homing del eje Y
void inicioYstate() {
  realizarHoming(STEP_PIN_Y, DIR_PIN_Y, FDCARRERA_Y);
  Estados = ESPERA;
}

// Función genérica para realizar el homing de un eje
void realizarHoming(int stepPin, int dirPin, int endStopPin) {
  while (digitalRead(endStopPin) == HIGH) {
    digitalWrite(dirPin, LOW);
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(1000);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(1000);
  }
}
