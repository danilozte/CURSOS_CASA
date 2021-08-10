#include <Arduino.h>

int led = 2;
float money;
bool E_ID = false;
bool V_PSS = false;

String Valor_in;

struct NAME__
{
  String nombres[3] = {"ALLEGRO", "BMW", "TOYOTA"};
  String apellido[3] = {"12345", "4567", "78910"};
  String contras[3] = {"abcd", "efgh", "hijk"};
  /// array vacios 
  String name[50];
  String password[50];


};

struct banderas
{
  bool bandera_1 ; 
  bool bandera_2; 
};

 

struct NAME__ list_nombre;
struct NAME__ list_cont;
void setup()
{

  Serial.begin(9600);
  pinMode(2, OUTPUT);
}

void loop()
{

 /////REGISTRAR USUARIOS/////
  
 
 
//// VALIDAMOS LAS CREDENCIALES////

 V_CREDENCIALES();

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
      E_ID = true;
      flag = true;
      break;
    }
  }
  if(!flag) {
    Serial.println("Usuario incorrecto");
  }
  return E_ID;
}

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
    CHECK_CONTRA();
  }

  if (V_PSS == true && E_ID == true)
  {
    Serial.println("Contraseña VALIDA");
  }
  else
  {
    Serial.println("LAS CREDENCIALES NO COINCIDEN");
    Serial.println("...........................");
  }

  }

/*
void REGISTRAR_USUARIO(){
    String  data_in;
    while (true)
    {
      
      if (Serial.available() > 1)
      {
        data_in = Serial.readString();
        Serial.println(data_in);
        // float Money= Valor_in.toDouble(); // money es el cantiad a retirar,ingresada
        //Serial.println(Money);

        break;
      }
    }
  

    bool flag2 = false;
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