
int periodo = 5000;
unsigned long TiempoAhora = 0;
int cont = 0;
 
void setup() {
    Serial.begin(9600);
}
 
void loop() {
     TiempoAhora = millis(); // el tiempo transcurrido se va escribiendo en la variable TIEMPO AHORA 
     Serial.println("Hola"); // IMPRIMIMOS HOLA
     while(millis() < TiempoAhora+periodo){// esperemos dos segundos para mostrar la palabra hola
     if (cont < 5){
      cont++;
      }
      
     }
    
}
