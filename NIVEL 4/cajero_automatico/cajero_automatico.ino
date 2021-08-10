#include "cajero.h""

#include<Arduino.h>

// este es mi tipo // creo el objeto miled // le paso los parametros 27, 26,  17 al constructor
//float val;
 
ledRGB miled(5, 6, 7); 
//entramos a la clase asiganamos los pines 
//ejecutamos la funcion showrandomcolors
//
ledRGB leer(2, 3, 0);

void setup(){
  Serial.begin(115200);
}

void loop(){
 miled.showrandomcolors();
 leer.redanalog();
 delay(500);
}
