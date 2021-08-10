#ifndef cajero_h
#define cajero_h
#include <Arduino.h>



class ledRGB

{
    public:
       ledRGB(byte red, byte green, byte blue);// este es el constructor por donde le voy a mandar los 3 pines del led RGB
       void showrandomcolors();
       void redanalog(); // aqui se escriben todos los metodos..
       //void redanalog();
    private:
       byte _red;  // son variables privadas que nadie puede acceder desder afuera 
       byte _green; // son los pines de los puertos. 
       byte _blue;

};


#endif

