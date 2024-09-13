#include "MoverEjes.h"
// Función genérica para mover un eje
void moverEje(int stepPin, int dirPin, int steps, int enablePin) {
  digitalWrite(enablePin,LOW);
  digitalWrite(dirPin, steps > 0 ? HIGH : LOW);
  for (int i = 0; i < abs(steps) ; i++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(1000);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(1000);
  }
  digitalWrite(enablePin,HIGH);
  }
//Función para mover el eje X
void moverXstate(int pasos) {
  moverEje(STEP_PIN_X, DIR_PIN_X, pasos, ENABLE_PIN_X);

  Estados = ESPERA;

}
//Función para mover el eje Y
void moverYstate(int pasos) {
  moverEje(STEP_PIN_Y, DIR_PIN_Y, pasos, ENABLE_PIN_Y);
  Estados = ESPERA;
}