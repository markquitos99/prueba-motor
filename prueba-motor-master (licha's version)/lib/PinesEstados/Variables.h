#ifndef Variables_h
#define Variables_h

    #ifndef Arduino_h
        #include <Arduino.h>
    #endif
    
    #define STEP_PIN_X 22
    #define DIR_PIN_X 23
    #define ENABLE_PIN_X 21
    #define STEP_PIN_Y 33
    #define DIR_PIN_Y 25
    #define ENABLE_PIN_Y 32
    #define STEP_PIN_E 2
    #define DIR_PIN_E 4
    #define ENABLE_PIN_E 15
 
    // Pines para los finales de carrera
    #define FDCARRERA_X 19
    #define FDCARRERA_Y 18
    extern int destinoProximoX;
    extern int destinoProximoY;
    extern int destinoProximoE;
    extern int i;
    extern int e;
    extern int xIndex;
    extern int yIndex;
    extern int extruye;
    extern unsigned long long int tiempo_1;
    extern unsigned long int duracion_1;
    extern unsigned long long int tiempo_2;
    extern unsigned long int duracion_2;
    extern unsigned long long int tiempo_3;
    extern unsigned long int duracion_3;
#endif