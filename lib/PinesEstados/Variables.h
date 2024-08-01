#ifndef Variables_h
#define Variables_h

    #ifndef Arduino_h
        #include <Arduino.h>
    #endif

    // Pines para controlar los motores
    #define STEP_PIN_X 22
    #define DIR_PIN_X  23
    #define ENABLE_PIN_X  21
    #define STEP_PIN_Y  33
    #define DIR_PIN_Y  25
    #define ENABLE_PIN_Y  32
    #define STEP_PIN_E  2
    #define DIR_PIN_E  4
    #define ENABLE_PIN_E  15
 
    // Pines para los finales de carrera
    #define FDCARRERA_X  19
    #define FDCARRERA_Y  18
    
    extern int destinoProximoX;
    extern int destinoProximoY;
    extern int destinoProximoE;
    extern int i;
    extern int e;
    extern unsigned int tiempo;
    extern long int duracion;

#endif