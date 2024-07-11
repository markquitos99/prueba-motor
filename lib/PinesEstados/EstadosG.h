#ifndef EstadosG_h
#define EstadosG_h
    #ifndef Arduino_h
        #include <Arduino.h>
    #endif    
    enum State2 {
    G0,
    G1,
    G28
    };

    extern State2 EstadoG;

#endif