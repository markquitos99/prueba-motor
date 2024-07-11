#ifndef Estados_h
#define Estados_h

    #ifndef Arduino_h
        #include <Arduino.h>
    #endif    

    enum State {
    ESPERA,
    MOVER_X,
    MOVER_Y,
    EXTRUSOR,
    INICIO_X,
    INICIO_Y
    };

    extern State Estados;

#endif