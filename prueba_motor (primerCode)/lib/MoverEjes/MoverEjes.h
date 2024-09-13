#ifndef MoverEjes_h
#define MoverEjes_h 
    #ifndef Arduino_h
    #include <Arduino.h>
    #endif

#include "Variables.h"
#include "Estados.h"

void moverEje(int stepPin, int dirPin, int steps, int enablePin);
void moverXstate(int pasos);
void moverYstate(int pasos);

#endif