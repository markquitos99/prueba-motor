#include "Homing.h"

// Función para el homing del eje X
void inicioXstate(){
  if (digitalRead(FDCARRERA_X) == HIGH)
  {
    moverStates(-10000, 0);
  }
  if (digitalRead(FDCARRERA_X) == LOW){
    tiempo_1 = 0;
    duracion_1 = 0;
    tiempo_2 = 0;
    duracion_2= 0;
    eje_1 = CONVERSION_Y_SETUP_VARIABLES;
    eje_2 = CONVERSION_Y_SETUP_VARIABLES;
    Estados == AUTOHOMING ? Estados = INICIO_Y : Estados = ESPERA;
  }
}

// Función para el homing del eje Y
void inicioYstate() {
  if (digitalRead(FDCARRERA_Y) == HIGH)
  {
    moverStates(0, -10000);
  }
  if (digitalRead(FDCARRERA_Y) == LOW){
    tiempo_1 = 0;
    duracion_1 = 0;
    tiempo_2 = 0;
    duracion_2= 0;
    eje_1 = CONVERSION_Y_SETUP_VARIABLES;
    eje_2 = CONVERSION_Y_SETUP_VARIABLES;
    Estados = ESPERA;
  }
}
