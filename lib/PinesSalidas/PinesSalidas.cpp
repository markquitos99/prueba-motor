#include "PinesSalidas.h"

void pines(){
  pinMode(DIR_PIN_X,OUTPUT);
  pinMode(STEP_PIN_X,OUTPUT);
  pinMode(ENABLE_PIN_X,OUTPUT);
  pinMode(DIR_PIN_Y,OUTPUT);
  pinMode(STEP_PIN_Y,OUTPUT);
  pinMode(ENABLE_PIN_Y,OUTPUT);
  //pinMode(STEP_PIN_E, OUTPUT);
  //pinMode(DIR_PIN_E, OUTPUT)
  pinMode(FDCARRERA_X, INPUT_PULLUP);
  pinMode(FDCARRERA_Y, INPUT_PULLUP);
  ledcSetup(0,500,16);
  ledcAttachPin(STEP_PIN_X,0);
  ledcAttachPin(STEP_PIN_Y,0);
  ledcAttachPin(STEP_PIN_E,0);
  digitalWrite(ENABLE_PIN_X,HIGH);
  digitalWrite(ENABLE_PIN_Y,HIGH);
}