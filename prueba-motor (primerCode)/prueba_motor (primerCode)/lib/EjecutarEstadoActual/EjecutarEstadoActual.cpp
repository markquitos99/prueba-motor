#include "EjecutarEstadoActual.h"

void ejecutarEstadoActual() {
  switch (Estados) {
    case ESPERA:
      esperaState();
      break;
    case MOVER_X:
      digitalWrite(ENABLE_PIN_Y, HIGH);
      moverXstate(destinoProximoX);
      break;
    case MOVER_Y:
      digitalWrite(ENABLE_PIN_X, HIGH);
      moverYstate(destinoProximoY);
      break;
    /*case EXTRUSOR:
      extrusorState(destinoProximoE);
      break;
    case INICIO_X:
      inicioXstate();
      break;
    case INICIO_Y:
      inicioYstate();
      break;*/
  }
}