long start = 0;

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(2, INPUT);

  digitalWrite(2, HIGH);

  randomSeed(millis());
 
  delay(random(1000, 3000));

  digitalWrite(13, HIGH);

  attachInterrupt(0, react, FALLING);

  start = millis();
}

void loop() {

}

void react(){
  long fin = millis();
  
  detachInterrupt(0);
  
  Serial.print("Tiempo: ");
  Serial.println(fin - start);
  }
