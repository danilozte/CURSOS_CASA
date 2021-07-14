
unsigned long prev;
void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN,OUTPUT);

}

void loop() {
 if(millis() - prev >1000UL ){
  prev = millis();
  Serial.println(prev);

  if(digitalRead(LED_BUILTIN))
    digitalWrite(LED_BUILTIN,false);
  else
    Serial.print("led on");
    digitalWrite(LED_BUILTIN, true);
  }
}
