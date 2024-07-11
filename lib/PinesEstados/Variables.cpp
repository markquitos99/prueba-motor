#include "Variables.h"

int STEP_PIN_X =23;
int DIR_PIN_X = 25;
int ENABLE_PIN_X = 22;
int STEP_PIN_Y = 27;
int DIR_PIN_Y = 32;
int ENABLE_PIN_Y = 26;
int STEP_PIN_E = 5;
int DIR_PIN_E = 4;
int ENABLE_PIN_E = 33;
 
// Pines para los finales de carrera
int FDCARRERA_X = 34;
int FDCARRERA_Y = 35;

// Variables para almacenar los comandos de G-code
int destinoProximoX = 0;
int destinoProximoY = 0;
int destinoProximoE = 0;
int i = 0;
int e = 0;