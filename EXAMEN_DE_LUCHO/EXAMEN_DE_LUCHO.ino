// EXAMEN DE FLUJO DE CONTROL//
//has un codigo que lea el puerto analogico por 2 segundos y te saque el promedio de la lectura //
#define promedio // difinimos una variable para guardar el promedio del valor leido en tiempo estimado de un potenciometro...

int entrada = A0;       //Declaramos la entradas analógicas A0
int led = 9;            //Declaramos el pin digital 9 como salidas digitales PWM
int valor=0;           //creamos una variable valor de tipo entero para almacenar los valores de las lecturas analógicas
unsigned long myTime;  // TIPO DE VARIBLE LONG LONG DE 8 BITS


void setup ()
{ 
 Serial.begin(9600);
 pinMode(led,OUTPUT); // Definimos el pin digital será de salida
}

void loop()
{
  myTime = millis();
  Serial.println(myTime); // prints time since program started
  int valor = analogRead(entrada); // lee el valor del potenciómetro
  Serial.print ("el valor es:");
  Serial.println (valor);
  if (myTime == 2000){
  Serial.print ("llegué");
    }
       
  }


  
  

 


 
