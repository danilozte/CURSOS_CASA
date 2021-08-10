#include <Arduino.h>
#include "ledRGB.h"

// ACCESO A AMBITO// LA FUNCION ledRGB en amarillo CORRESPONDE A LA 
// corresponde a la clase  ledRGB en color verde..

 ledRGB::ledRGB(byte red, byte green, byte blue){ 
   // AQUI EN EL CONSTRUCTOR 
  //inicializamos la clase y guardamos las variables inicializadas en las variables privadas. 
   
   _red = red;
   _green = green; 
   _blue = blue; 

   pinMode(_red, OUTPUT);
   pinMode(_green, OUTPUT);
   


   digitalWrite(_red, false);
   digitalWrite(_green, false);
   digitalWrite(_blue, false);
   randomSeed(analogRead(34));
   
 }


void::ledRGB::showrandomcolors()
{
  int  redValue = random (0,2);
  int  greenValue = random (0,2);
  int  blueValue = random (0,2);

  digitalWrite(_red, redValue);
  digitalWrite(_green, greenValue);
  digitalWrite(_blue, blueValue);

}
 void::ledRGB::redanalog() 
{
  
  float val = analogRead(_blue);
 // float valor = val*5.0/1024.0;}
 float valor = val/1024.0*5.0;
  Serial.println(valor);
}
