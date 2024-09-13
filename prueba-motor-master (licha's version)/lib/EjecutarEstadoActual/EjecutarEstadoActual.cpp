#include "EjecutarEstadoActual.h"

void ejecutarEstadoActual() {

  switch (Estados) {
    //espera recibir un comando
    case ESPERA:
      esperaState();
      break;

      // cuando se mueven los ejes y hay extrusion
      case MOVER_EJES:
      moverStates(destinoProximoX, destinoProximoY);
      break;

      //ir al final de carrera x
    case INICIO_X:
      inicioXstate();
      break;

      //ir al final de carrera y
    case INICIO_Y:
      inicioYstate();
      break;

      //va al (0,0)
      case AUTOHOMING:
      inicioXstate();
      break;
  }
}