#ifndef Estados_h
#define Estados_h

    #ifndef Arduino_h
        #include <Arduino.h>
    #endif    

    enum State {
    ESPERA,
    MOVER_EJES,
    INICIO_X,
    INICIO_Y,
    AUTOHOMING
    };

    enum Eje{
        CONVERSION_Y_SETUP_VARIABLES,
        DIRECCION,
        MOVIMIENTO,
        FIN
    };

    extern Eje eje_1;
    extern Eje eje_2;
    extern Eje eje_3;
    extern State Estados;

#endif