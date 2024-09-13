#include "MoverEjes.h"
void moverMotorVelocidad(int pin){

  //ledcWrite(pin,duty);

  //MOVIMIENTO  

      digitalWrite(pin, HIGH);
      delayMicroseconds(5000);
      digitalWrite(pin, LOW);
      delayMicroseconds(200);


}

void MEF(int pin_direccion, int pin_enable,int pin_pasos,int _pasos,Eje* _eje,unsigned long long int* _tiempo, unsigned long int* _duracion){
  switch(*_eje){
      case CONVERSION_Y_SETUP_VARIABLES:{
        if(_pasos>0){
          _pasos = map(_pasos,0,400,0,1100);
          // REVISAR CALCULOS
            *_duracion=_pasos*4.8; //750
          }
          else{
            _pasos =_pasos*(-1);
            _pasos = map(_pasos,0,400,0,1100);
            *_duracion=(_pasos*4.8); //750
          }
        *_tiempo=0;
        *_eje=DIRECCION;
      }
      break; 
      case DIRECCION:{
        if(_pasos>0){
          digitalWrite(pin_direccion,HIGH);
        }
        else{
          digitalWrite(pin_direccion,LOW);
        }
        *_eje=MOVIMIENTO;
        //digitalWrite(pin_enable,HIGH);
      }
      break;
      case MOVIMIENTO:{
        if(*_tiempo==0){
          *_tiempo=millis();
        }
        digitalWrite(pin_enable,LOW);
        if(*_tiempo+*_duracion>=millis()){
          if(pin_pasos==STEP_PIN_Y){
            moverMotorVelocidad(STEP_PIN_Y);
          } 
          if(pin_pasos==STEP_PIN_X){
            moverMotorVelocidad(STEP_PIN_X);
          }
        }
        else{
          *_tiempo=0;
          *_duracion=0;
          digitalWrite(pin_enable,HIGH);
          *_eje=FIN;
        }
      }
        break;
      }
  }

//Función para mover el eje X
void moverXstate(int pasos) {
  //   moverEje(STEP_PIN_X, DIR_PIN_X, pasos, ENABLE_PIN_X);
  MEF(DIR_PIN_X,ENABLE_PIN_X,STEP_PIN_X,pasos,&eje_1,&tiempo_1,&duracion_1);
  Estados = ESPERA;
}

//Función para mover el eje Y
void moverStates(int pasosX, int pasosY) {
  if(eje_1!=FIN || eje_2!=FIN){
    MEF(DIR_PIN_X,ENABLE_PIN_X,STEP_PIN_X,pasosX,&eje_1,&tiempo_1,&duracion_1);
    MEF(DIR_PIN_Y,ENABLE_PIN_Y,STEP_PIN_Y,pasosY,&eje_2,&tiempo_2,&duracion_2);
    
    //MOVIMIENTO DEL EXTRUSOR
    //if(extruye == 1){
    //  digitalWrite(ENABLE_PIN_E,LOW);
    //  digitalWrite(DIR_PIN_E,HIGH);
    //  moverMotorVelocidad(STEP_PIN_E);
    //}
      
  }else{
    eje_1 = CONVERSION_Y_SETUP_VARIABLES;
    eje_2 = CONVERSION_Y_SETUP_VARIABLES;
    Estados = ESPERA;  
  }
}