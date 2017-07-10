/*
Este ejemplo hace parpadear un led.
*/


void setup() {
  //Se configura el pin 13 cómo pin de salida.
  pinMode(13, OUTPUT);
}

void loop() {
  //En un pin de salida se puede escribir un valor.
  digitalWrite(13, HIGH);
  delay(1000);                  
  digitalWrite(13, LOW);  
  delay(1000);
}
