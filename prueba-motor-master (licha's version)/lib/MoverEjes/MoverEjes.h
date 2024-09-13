#ifndef MoverEjes_h
#define MoverEjes_h 
    #ifndef Arduino_h
    #include <Arduino.h>
    #endif

#include "Variables.h"
#include "Estados.h"

void MEF(int pin_direccion, int pin_enable,int pin_pasos,int _pasos,Eje* _eje,unsigned long long int* _tiempo, unsigned long int* _duracion);
void moverMotorVelocidad(int pin);
void moverXstate(int pasos);
void moverStates(int pasosX, int pasosY);

#endif