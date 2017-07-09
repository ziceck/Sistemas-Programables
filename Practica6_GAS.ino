/**
 * Esta código sirve para leer el valor que ofrece un senor de gas, y en base a esto
 * encender o apagar un LED.
 */
 
int analogInPin=A0;
int ledPin=13;

int sensorValue=0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledPin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorValue=analogRead(analogInPin);
  if(sensorValue >= 750){
    digitalWrite(ledPin,HIGH);
  }
  else{
    digitalWrite(ledPin,LOW);
  }
  Serial.print("sensor = ");
  Serial.println(sensorValue);
  delay(10);
}
