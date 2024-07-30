#include "Variables.h"

int STEP_PIN_X =22;
int DIR_PIN_X = 23;
int ENABLE_PIN_X = 21;
int STEP_PIN_Y = 33;
int DIR_PIN_Y = 25;
int ENABLE_PIN_Y = 32;
int STEP_PIN_E = 2;
int DIR_PIN_E = 4;
int ENABLE_PIN_E = 15;
 
// Pines para los finales de carrera
int FDCARRERA_X = 19;
int FDCARRERA_Y = 18;

// Variables para almacenar los comandos de G-code
int destinoProximoX = 0;
int destinoProximoY = 0;
int destinoProximoE = 0;
int i = 0;
int e = 0;