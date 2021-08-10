
char dato;         // incoming serial byte
bool flag1 = true;
bool flag2 = true;

void setup() {
 
Serial.begin(9600);
while (!Serial) 
 {
   ; // wait for serial port to connect. Needed for native USB port only
 }

}
void loop() {

pedir_dato();
mostrar_dato();

}

void pedir_dato(){
  
  
  if (Serial.available()>0)
{
   dato = Serial.read(); //Leer 1 carácter
   Serial.print(dato); 
}
  }

void mostrar_dato(){
  while(flag1){

   if(dato == 1){
  
     Serial.print("es 1");
     flag1 = false;
  }
}
}
