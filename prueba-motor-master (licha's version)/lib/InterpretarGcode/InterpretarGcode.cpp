#include "InterpretarGcode.h"

void esperaState() {
  if (Serial.available() > 0) {
    String comando = Serial.readStringUntil('\n');
    interpreteGcode(comando);
  }
}

void ejecutarMovimiento(String comando){

        xIndex = comando.indexOf('X');
        yIndex = comando.indexOf('Y');

        tiempo_1 = 0;
        duracion_1 = 0;
        tiempo_2 = 0;
        duracion_2= 0;
        
        if (xIndex > -1 || yIndex > -1) {
          destinoProximoX = comando.substring(xIndex + 1).toInt();
          destinoProximoY = comando.substring(yIndex + 1).toInt();
          Estados = MOVER_EJES;
        } 
}

void interpreteGcode(String comando) {
  
  if(comando.startsWith("G0") || comando.startsWith("G00")) EstadoG = G0;
  if(comando.startsWith("G1") || comando.startsWith("G01")) EstadoG = G1;
  if(comando.startsWith("G28")) EstadoG = G28;
  if(comando.startsWith("G29")) EstadoG = G29;
  if(comando.startsWith("G30")) EstadoG = G30;
  if(comando.startsWith("G40")) EstadoG = G30;
  
  switch (EstadoG)
  {
    case G0:
      extruye = 0;
      ejecutarMovimiento(comando);
    break;
    case G28:
          Estados = INICIO_X;
    break;
    case G29:
          Estados = INICIO_Y;
    break;
    case G30:
          Estados = AUTOHOMING;
    break;
    case G1:
        extruye = 1;
        ejecutarMovimiento(comando);
    break;
  }
}
