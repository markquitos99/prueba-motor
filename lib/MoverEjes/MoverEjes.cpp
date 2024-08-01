#include "MoverEjes.h"
// Función genérica para mover un eje
/*void moverEje(int stepPin, int dirPin, int steps, int enablePin) {
  digitalWrite(enablePin,LOW);
  digitalWrite(dirPin, steps > 0 ? HIGH : LOW);
  for (int i = 0; i < abs(steps) ; i++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(1000);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(1000);
  }
  digitalWrite(enablePin,HIGH);
  }
*/
void moverMotor(int stepPin, int dirPin, int steps, int enablePin){
  switch(etapa){
    case CONVERSION_Y_SETUP_VARIABLES:{
      if(steps>0){
        duracion=steps*18;
      }
      else{
        duracion=-(steps*18);
      }
      tiempo=0;
      etapa=DIRECCION;
    }
    break; 
    case DIRECCION:{
      if(steps>0){
        digitalWrite(dirPin,LOW);
      }
      else{
        digitalWrite(dirPin,HIGH);
      }
      etapa=MOVIMIENTO;
      digitalWrite(enablePin,HIGH);
    }
    break;
    case MOVIMIENTO:{
      if(tiempo==0){
        tiempo=millis();
      }
      digitalWrite(enablePin,LOW);
      if(tiempo+duracion>=millis()){
        ledcWrite(0,32768);
      }
      else{
        tiempo=0;
        digitalWrite(enablePin,HIGH);
        etapa=FIN;
      }
    }
    break;
    case FIN:{
    }
  }
}
//Función para mover el eje X
void moverXstate(int pasos) {
  if(etapa!=FIN){
    moverMotor(STEP_PIN_X, DIR_PIN_X, pasos, ENABLE_PIN_X);
  }
  else {
     Estados = ESPERA;
     etapa = CONVERSION_Y_SETUP_VARIABLES;
  }
}
//Función para mover el eje Y
void moverYstate(int pasos) {
  if(etapa!=FIN)
    moverMotor(STEP_PIN_Y, DIR_PIN_Y, pasos, ENABLE_PIN_Y);
  else {
    Estados = ESPERA;
    etapa=CONVERSION_Y_SETUP_VARIABLES;
  }
}