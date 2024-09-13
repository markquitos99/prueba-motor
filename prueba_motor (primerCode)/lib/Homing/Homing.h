#ifndef Homing_h
#define Homing_h
   
    #ifndef Arduino_h
    #include <Arduino.h>
    #endif

#include "Estados.h" 
#include "EstadosG.h"
#include "Variables.h"
#include "MoverEjes.h"

void extrusorState(int steps);
void inicioYstate();
void inicioXstate();
void realizarHoming(int stepPin, int dirPin, int endStopPin);

#endif