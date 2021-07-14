
const unsigned long INTERVALO_LED = 1000UL; // SON LAS CONSTANTE DE TIEMPO DADAS EN TIPO UNSIGNED LONG
const unsigned long INTERVALO_TEMP = 5000UL; // INTERVALO DE TIEMPO PARA CADA ACCION
const int pinLED = 11;
 
unsigned long evento_led;
unsigned long evento_temp;
 
void setup() {
  Serial.begin(9600);
  pinMode( pinLED, OUTPUT );
}
 
void CAMBIO_ESTADO_LED(){ // CAMBIAMOS EL ESTADO DEL LED REVISANDO EL ESTADO PIN ANTERIOR PORQUE EL IF
  if( digitalRead( pinLED ) ) // PREGUNTA SI ES VERDAD O SI ES UN 1
    digitalWrite(pinLED, LOW);
  else
    digitalWrite(pinLED, HIGH);
}
 
void sensor(){
  int VALUE = analogRead(A0); // LEEMOS EL VALOR DE AO Y LO TRANSFORMAMOS EN EL VOLTAJE
  float VOLTAGE = VALUE*(5.0/1023.0);
  
  Serial.print( "EL VOLTAGE ES: " ); 
  Serial.print( VOLTAGE, 2 );   // IMPRIMOS EL VALOR DEL VOLTAGE Y ESTO SE EJECUTARA CADA VEZ QUE SE CUMPLAN LOS TEMPOS EXACTOS
  Serial.println(" V");
}
 
void loop() {
  unsigned long actual = millis(); // LEER QUE VALE MILLS Y LO GUARDAMOS 
 
  if( actual > evento_led ){
    // COMPROBAMOS QUE EL EL TIEMPO ES MAYOR A LO QUE TIENE LA VARIABLE EVENTO LED,EN EL PRIMER CASO SE CUMPLE PORQUE INICIA EN 0  
    // AL PASAR EL TIEMPO YSE CUMPLE QUE SI ES MAYOR Y ENTRA A LA SIGUIENTE LINEA. 
    CAMBIO_ESTADO_LED(); EJECUTA 
    evento_led += INTERVALO_LED; // SE LE CARGA 1000UL A EVENTO_LED CADA VEZ QUE DESBORDE EL VALOR DEL INTERVALO
  }
 
  if( actual > evento_temp ){
    sensor();
    evento_temp += INTERVALO_TEMP; //IGUAL PARA ESTA FUNCION SOLO QUE VAMOS LEEMOS EL VALOR ANALO Y MOSTRAMOS
  }
  
  // otras acciones 
  
}
