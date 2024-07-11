#include "InterpretarGcode.h"

void esperaState() {

  if (Serial.available() > 0) {

    String comando = Serial.readStringUntil('\n');
    interpreteGcode(comando);

  }

}

void interpreteGcode(String comando) {
  
  if(comando.startsWith("G0"))
    EstadoG = G0;
  if(comando.startsWith("G1"))
    EstadoG = G1;
  if(comando.startsWith("G28"))
    EstadoG = G28;
  
  switch (EstadoG)
  {
    case G0:
      Serial.println("Comando G-code no reconocido: " + comando);
    break;
    case G28:
      if (comando.indexOf('X') > -1)
            Estados = INICIO_X; 
      if (comando.indexOf('Y') > -1)
            Estados = INICIO_Y;
    break;
    case G1:

        int xIndex = comando.indexOf('X');
        int yIndex = comando.indexOf('Y');
        int eIndex = comando.indexOf('E');
        
        Serial.println(comando.substring(xIndex + 1).toInt());
        Serial.println(comando.substring(yIndex + 1).toInt()); // G1 X100 // G1 X100
        
        if (xIndex > -1) {
          destinoProximoX = comando.substring(xIndex + 1).toInt();
          Estados = MOVER_X;
        } 
        if (yIndex > -1) { 
          destinoProximoY = comando.substring(yIndex + 1).toInt();
          Estados = MOVER_Y;
        } /*else if (eIndex > -1) {
          destinoProximoE = comando.substring(eIndex + 1).toInt();
          Estados = EXTRUSOR;
        }*/
    break;
  }
}
