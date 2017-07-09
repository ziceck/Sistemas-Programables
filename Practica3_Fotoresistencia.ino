/*
Este código sirve para encender o apagar un led en función del valor que se lee de una foto resistencia, 
si la foteresistencia detecta mucha luz el LED se apaga, si hay poca luz el LED se enciende.
A menos luz menor resistencia, a mayor luz mayor resistencia.
*/
int sensorPin = A0;
int ledPin = 13;
int sensorValue = 0;

void setup() {
  pinMode(ledPin,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  sensorValue=analogRead(sensorPin);
  Serial.println(sensorValue);
  if(sensorValue<=500){
    digitalWrite(ledPin,HIGH);
  }
  else{
    digitalWrite(ledPin,LOW);
  }
  delay(10);
}
