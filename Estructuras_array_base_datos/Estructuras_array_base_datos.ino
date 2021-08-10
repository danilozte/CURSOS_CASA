#include "Estructuras.h"




//MATRIZ
//String nombres[3] = {"ALLEGRO", "BMW", "TOYOTA"};
//String contras[3] = {"125", "456", "456"};

void setup()
{
  Serial.begin(9600);
  while (!Serial)
  {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  pinMode(LED, OUTPUT);
  pinMode(LED2, OUTPUT);
  Menu_Bienvenida(); // ESTE MENSAJE SE EJECUTARA 1 SOLA VEZ LUEGO QUE ENTREMOS AL BUCLE LOOP SE JUAGARA CON LAS CONDICIONES PARA VOLVERLO A MOSTRAR
  
}

char optionInput()
{
  
  char valores = Serial.read();
  while (true)
  {
    if (valores == 'A' || valores == 'B' || valores == 'C')
    {
      break; valores;
    }
    valores = Serial.read();
  }
  return valores;
}





void loop()
{
  
  if (Serial.available() > 1)
  {
    //Menu_Bienvenida(); // ESTE MENSAJE SE EJECUTARA 1 SOLA VEZ LUEGO QUE ENTREMOS AL BUCLE LOOP SE JUAGARA CON LAS CONDICIONES PARA VOLVERLO A MOSTRAR
    aux = Serial.read(); //Leer 1 carácter// si colocan mas de uno tomara solo el primero
    Serial.println(aux); Serial.print(".........");
    // VALIDAR USUARIO
    Validar_credenciales();   
    if (estado == 1)
    {
      Visualizar_opciones();
      aux = optionInput(); //INGRESAR VALORES VALIDOS DEL MENU
      Menu(aux); // SWITCH CASE DE REQUERIMIENTOS
    }
    else {
      Serial.print(" valide  nuevamente las credenciales");
    }
  }
}