#include "Variables.h"

// Variables para almacenar los comandos de G-code
int destinoProximoX = 0;
int destinoProximoY = 0;
int destinoProximoE = 0;
int i = 0;
int e = 0;
int xIndex = 0;
int yIndex = 0;
int extruye = 0;

//tiempos
unsigned long long int tiempo_1=0;
unsigned long int duracion_1=0;
unsigned long long int tiempo_2=0;
unsigned long int duracion_2=0;
unsigned long long int tiempo_3=0;
unsigned long int duracion_3=0;