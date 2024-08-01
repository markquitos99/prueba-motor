#include <Arduino.h>
#include "EjecutarEstadoActual.h"
#include "PinesSalidas.h"
#include "MensajeBienvenida.h"

void setup() {
  pines();
  MensajeBienvenida();
}

void loop() {
  ejecutarEstadoActual();
}