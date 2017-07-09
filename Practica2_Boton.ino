/***
 * 
 * Este codigo enciende un led usando un push boton
 */

void setup(){
  //se leen los pines configurados cómo INPUT
  pinMode(8,INPUT);
  // se escribe en los pines configurados con OUTPUT
  pinMode(13,OUTPUT);
}

void loop(){
  digitalWrite(13,digitalRead(8));
}

