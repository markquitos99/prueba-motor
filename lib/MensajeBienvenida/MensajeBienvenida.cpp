#include "MensajeBienvenida.h"
void MensajeBienvenida() {
  Serial.begin(115200); // Inicializar comunicación serial
  //Serial1.begin(9600);
  delay (5000);
  Serial.println("La Chispita 3d Alpha");
}