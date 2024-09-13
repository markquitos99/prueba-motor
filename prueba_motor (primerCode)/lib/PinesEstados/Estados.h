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
    INICIO_Y,
    CONVERSION_Y_SETUP_VARIABLES,
    DIRECCION,
    MOVIMIENTO,
    FIN
    };

    extern State Estados;

#endif