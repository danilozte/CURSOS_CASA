#include <Arduino.h>

//GLOBALES

int estado = 0; //estado del cerificacion del login
int cont_1 = 0;
int cont_2 = 0;//

bool flag = true;
bool flag2 = true;
char aux; // VARIABLE PARA GUARDAR EL VALOR DE LAS OPCIONES ESCRITAS POR PUERTO SERIAL

bool E_ID = false;
bool E_PASS = false;
bool Flag_Cred = true;

/// variables de cantidad de dinero

float Money;
double saldo = 45.000; // valor neto del cajero

String _usuario = "TOYOTA"; // VARIABLES DE LOGUEO POR DEFECTO
String _contras = "456";  //

int LED = 2;
int LED2 = 3;

// ESTRUCTURAS PARA LOS NOMBRES Y CONTRASEÑAS DE LAS BASES DE DATOS
struct NAME__
{
    String nombres[3] = {"ALLEGRO", "BMW", "TOYOTA"};
    String apellido[3] = {"12sd5", "45asd6", "asd457"};
    String contras[3] = {"12as5", "456", "456asf"};
}; // aqui podemos declaramos el objeto de esta esctructura

struct NAME__ list_nombre;
struct NAME__ list_cont;

////// FUNCIONES DE MENU//////////
int Descontar(){
    if (Money <= saldo)
    {
      saldo = ( saldo - Money );
      Serial.print("Su fondo actual es de:");Serial.println(saldo);
      Serial.println("...........................");
      delay(1000);
    }
    else
    {
       Serial.println("No hay saldo disponible");
       delay(1000);
       Serial.println(".............");
    }
    
}

void Menu_Bienvenida()
{
    Serial.println("BIENVENIDOS    AL    CAJERO");
    Serial.println("NO OLVIDES NO COMPARTIR TU CONTRASEÑA");
    Serial.println("INGRESE LA LETRA H PARA VALIDAR SUS CREDENCIALES");
}

bool TEST_NOMBRE()
{

    while (flag)
    {
        for (int i = 0; i < 3; i = i + 1)
        {
            //Serial.print("valor de la lista :"); Serial.println(list_nombre.nombres[i]);
            
            if (list_nombre.nombres[i] == _usuario)
            {
                E_ID = true;
                digitalWrite(LED2, HIGH);
                delay(600);
                digitalWrite(LED2, LOW);
                delay(600);
            }
            cont_1++;

            if (cont_1 == 3)
            {
                flag = false;
            }
        }
    }
    return E_ID;
}

bool TEST_CONTRA()
{

    while (flag2)
    {
        for (int J = 0; J < 3; J = J + 1)
        {

            
            if (list_cont.contras[J] == _contras)
            {

                E_PASS = true;
                //Serial.print("valor de la contraseña es  :"); Serial.println(list_cont.contras[J]);
                digitalWrite(LED, HIGH);
                delay(600);
                digitalWrite(LED, LOW);
                delay(600);
            }
            cont_2++;

            if (cont_2 == 3)
            {
                flag2 = false;
            }
        }
    }
    return E_PASS;
}

void Validar_credenciales()
{

    TEST_NOMBRE();
    TEST_CONTRA();
    if (E_ID == true && E_PASS == true)
    {
        Flag_Cred = false;
        Serial.println("Contraseña correcta........");
        estado = 1;
    }
    else
    {
        Serial.println("Contraseña incorrecta");
    }
}

void Menu(char valores)
{
    Serial.println(valores);
    
 switch (valores){
    
    case 'A':
        Serial.println("Cuanto desea sacar:"); // statements
        while (true)
        {
            if (Serial.available() > 1)
            {
                String Valor_in = Serial.readString();
                //Serial.print(Valor_in);
                Money= Valor_in.toDouble(); // money es el cantiad a retirar,ingresada
                //Serial.println(Money);
                Descontar(); 
                //estado = 0;
                break;
            } 
          
            
        }   
        
        break;

    case 'B':
        Serial.println("EL SALDO RESTANTE  ES DE:");
        Serial.println(saldo);
       //delay(2000);
        //estado = 0;

        break;
    case 'C':
        Serial.println("GRACIAS POR UTILIZAR NUESTROS SERVICIOS");
        //delay(2000);
        //estado = 0;
        break;

    default:
        Serial.println("ERROR"); // El valor introducido es incorrecto
        break;
    }
    Menu_Bienvenida();
    delay(2000);
}

void Visualizar_opciones()
{
    Serial.println("QUE DESEAS HACER:");
    Serial.println("A. Sacar dinero");
    Serial.println("B. consultar saldo");
    Serial.println("C. Salir");
    Serial.print("FONDO DEL CAJERO ES DE : "); Serial.println(saldo);
}