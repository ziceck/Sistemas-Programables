const int sensorPin=8;
const int ledPin=13;
const int periodoAprendizaje=30*1000;
int aprendizajeCompletado = 0;

void setup() {
  Serial.begin(9600);
  pinMode(sensorPin,INPUT);
  Serial.println("Aprendiendo objetos sin movimiento");
  pinMode(ledPin,OUTPUT);
}

void loop() {
  if(millis() < periodoAprendizaje){
    delay(20);
    return;
  }
  if(aprendizajeCompletado == 0){
    aprendizajeCompletado = 1;
    Serial.println("Aprendizaje Completado");
  }
  if (digitalRead(sensorPin) == HIGH) {
    Serial.println("Movimiento Detectado");
    digitalWrite(ledPin,HIGH);
  } else {
    Serial.println("No se ha detectado movimiento");
    digitalWrite(ledPin,LOW);
  }
  delay(100);
}
