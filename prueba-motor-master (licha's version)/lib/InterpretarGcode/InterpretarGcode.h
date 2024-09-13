#ifndef InterpretarGcode_h
#define InterpretarGcode_h
   
    #ifndef Arduino_h
    #include <Arduino.h>
    #endif

#include "Estados.h" 
#include "EstadosG.h"
#include "Variables.h"

void esperaState();
void interpreteGcode(String comando);
void ejecutarMovimiento();

#endif