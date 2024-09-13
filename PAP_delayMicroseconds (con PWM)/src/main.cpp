#include <Arduino.h>
#define STEP_PIN_X 22
#define DIR_PIN_X 23
#define ENABLE_PIN_X 21
#define STEP_PIN_Y 33
#define DIR_PIN_Y 25
#define ENABLE_PIN_Y 32
#define STEP_PIN_E 2
#define DIR_PIN_E 4
#define ENABLE_PIN_E 15
 
#define FDCARRERA_X 19
#define FDCARRERA_Y 18
typedef enum Eje{CONVERSION_Y_SETUP_VARIABLES,DIRECCION,MOVIMIENTO,FIN};
void MEF(int pin_direccion, int pin_enable,int pin_pasos,int _pasos,Eje* _eje,unsigned long long int* _tiempo, unsigned long int* _duracion);
Eje eje_1=CONVERSION_Y_SETUP_VARIABLES;
Eje eje_2=CONVERSION_Y_SETUP_VARIABLES;
unsigned long long int tiempo_1=0;
unsigned long int duracion_1=0;
unsigned long long int tiempo_2=0;
unsigned long int duracion_2=0;
long int pasos1=400;
long int pasos2=400;
  //Duty cycle 96,15%
void setup() {
  pinMode(DIR_PIN_X,OUTPUT);
  pinMode(STEP_PIN_X,OUTPUT);
  pinMode(ENABLE_PIN_X,OUTPUT);
  pinMode(DIR_PIN_Y,OUTPUT);
  pinMode(STEP_PIN_Y,OUTPUT);
  pinMode(ENABLE_PIN_Y,OUTPUT);
  pinMode(STEP_PIN_E, OUTPUT);
  pinMode(DIR_PIN_E, OUTPUT);
  pinMode(ENABLE_PIN_E, OUTPUT);
  pinMode(FDCARRERA_X, INPUT_PULLUP);
  pinMode(FDCARRERA_Y, INPUT_PULLUP);
  digitalWrite(ENABLE_PIN_E,HIGH);
  digitalWrite(ENABLE_PIN_Y,HIGH);
  digitalWrite(ENABLE_PIN_X,HIGH);
  pasos1=map(pasos1,0,400,0,1150);
  pasos2=map(pasos2,0,400,0,1150);
  ledcSetup(0,192,16);
  ledcSetup(1,192,16);
  ledcAttachPin(STEP_PIN_X,0);
  ledcAttachPin(STEP_PIN_Y,1);
  delay(2000);
}

void loop() {
  digitalWrite(ENABLE_PIN_E,HIGH);
  if(eje_1!=FIN || eje_2!=FIN){
    MEF(DIR_PIN_X,ENABLE_PIN_X,STEP_PIN_X,pasos1,&eje_1,&tiempo_1,&duracion_1);
    MEF(DIR_PIN_Y,ENABLE_PIN_Y,STEP_PIN_Y,pasos2,&eje_2,&tiempo_2,&duracion_2);
  }
}

void moverMotorVelocidad(int pin){

  if(pin==STEP_PIN_X){
    ledcWrite(0,62913);
  }
  else{
    ledcWrite(1,62913);
  }

  //MOVIMIENTO  

}

void MEF(int pin_direccion, int pin_enable,int pin_pasos,int _pasos,Eje* _eje,unsigned long long int* _tiempo, unsigned long int* _duracion){
  switch(*_eje){
      case CONVERSION_Y_SETUP_VARIABLES:{
        if(_pasos>0){
          // REVISAR CALCULOS
            *_duracion=(_pasos*48)/10; //750
          }
          else{
            *_duracion=-(_pasos*48)/10; //750
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
  }
}