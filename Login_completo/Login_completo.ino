#include <Arduino.h>

int led = 2;
float money;
bool E_ID = false;
bool V_PSS = false;

String Valor_in;
char Valor;

struct NAME__
{
  String nombres[10]; //  = {"ALLEGRO", "BMW", "TOYOTA"};
  //String apellido[10]; //  = {"12345", "4567", "78910"};
  String contras[10] ; // = {"abcd", "efgh", "hijk"};
  /// array vacios 

};

 
  struct NAME__ list_nombre;
  struct NAME__ list_cont;
  int cont1 = 0;
  int cont2 = 0;
  int cont_login = 0; // variable contadora para saber cuantos usuarios se registraron


void setup()
{

  Serial.begin(9600);
  pinMode(2, OUTPUT);
  Menu_Bienvenida();
}

void loop()
{
 
  while (true)
  {
    
    if (Serial.available() > 0)
    {
      Valor = Serial.read();
      Serial.println(Valor);
      // float Money= Valor_in.toDouble(); // money es el cantiad a retirar,ingresada
      //Serial.println(Money);
    }
     break;
  }


  if (Valor == 'A')
  {
    REGISTRAR_USUARIO();
  }

  if (Valor ==  'B')
  {
    V_CREDENCIALES();
  }
  

  if (Valor == 'C')
  {
    for (int i = 0; i <= cont1; i = i + 1) {
      Serial.println(list_nombre.nombres[i]);  /// se muestran los usuarios registrados pero hay que definir; el numero manual.
      if (i == cont1)
      {
        Valor = 'D';
      }
      delay (1000);
      Menu_Bienvenida();
    }
  }
   
  
  
 
}


void Menu_Bienvenida()
{
    Serial.println("BIENVENIDOS    AL    CAJERO");
    Serial.println("NO OLVIDES NO COMPARTIR TU CONTRASEÑA");
    Serial.println("A. Registrar usuario");
    Serial.println("B. Ingresar");
    Serial.println("C. CONSULTAR BASE DE DATOS");
}



bool CHECK_LOGIN()
{
  
  bool flag = false;
  for (int i = 0; i < 3; i = i + 1)
  {
    //Serial.print("valor de la lista :"); Serial.println(list_nombre.nombres[i]);
    if (list_nombre.nombres[i] == Valor_in)
    {
      Serial.println("INGRESA TU CONTRASEÑA");
      //delay(2000);
      //Serial.println("Digite su contraseña");
      cont_login = cont_login + 1 ;
      E_ID = true;
      break;
    }
  }
  if(!flag) {
    Serial.println("Usuario incorrecto");
    Serial.println("Vuele a ingresar tu USUARIO:");
  }
  return E_ID;
}

/*
bool CHECK_CONTRA()
{   bool flag2 = false;
    for (int i = 0; i < 3; i = i + 1)
    {
      //Serial.print("valor de la lista :"); Serial.println(list_nombre.nombres[i]);
      if (list_cont.contras[i] == Valor_in)
      {
        //Serial.println("Usuario correcto");
        //delay(2000);
        //Serial.println("Digite su contraseña");
        V_PSS = true;
        flag2 = true;
         break;
      }
    }
      if(!flag2) {
        Serial.println("CONTRASEÑA INCORRECTA");
      }
    
    return V_PSS; 
 }
 */

void data_serial()
{

  while (true)
  {
    
    if (Serial.available() > 1)
    {
      Valor_in = Serial.readString();
      Serial.println(Valor_in);
      // float Money= Valor_in.toDouble(); // money es el cantiad a retirar,ingresada
      //Serial.println(Money);

      break;
    }
  }
}


void V_CREDENCIALES (){
 Serial.println("INGRESA TU USUARIO");
  
  data_serial();
  CHECK_LOGIN();

  if (E_ID)
  {
       
      data_serial();
      if ( Valor_in == list_cont.contras[cont_login] )
      {
        Serial.print(Valor_in);
        Serial.print( list_cont.contras[cont_login] );
        V_PSS = true;
      }
    
  }

  if (V_PSS == true && E_ID == true)
  {
    Serial.println("Contraseña VALIDA");
    Valor = 0;
    Menu_Bienvenida();

  }
  else
  {
    Serial.println("LAS CREDENCIALES NO COINCIDEN");
    Serial.println("...........................");
  }

  }


void REGISTRAR_USUARIO(){
    String  data_in;
    Serial.print("Ingrese Su nombre: ");
    while (true)
    {
      if (Serial.available() > 1)
      {
        data_in = Serial.readString();
       //  Serial.println(data_in);
        
        list_nombre.nombres[cont1] = data_in;
        Serial.println(list_nombre.nombres[cont1]);
        cont1 = cont1 + 1;
        Serial.println(" ");
        Serial.println("Ingrese Su Contraseña: ");
        Valor = 0;
        break;
      }

    } 
  
    while (true)
    {
      bool bandera = true;
      int i = 0;

      data_in = ""; 
      if (Serial.available() > 1)
      {
        data_in = Serial.readString();
       // Serial.println(data_in);

        list_cont.contras[cont2] = data_in;
        Serial.println(list_cont.contras[cont2]);
        cont2 = cont2 + 1;
        Serial.println(" ");
        
        Serial.println("REGISTRO EXITOSO");

         


        Serial.println("....................... ");
        
        delay(4000);
        Menu_Bienvenida();
        break;
      }
        
      }
 }
    
