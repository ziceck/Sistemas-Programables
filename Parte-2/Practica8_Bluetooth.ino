#include <SoftwareSerial.h>

SoftwareSerial mySerial(4,2);

int a=0;
char c;
char d;

void setup() {
  Serial.begin(9600);
  Serial.println("Buenas noches Luna!!");
   
  mySerial.begin(9600);
  mySerial.println("Hola, Mundo");
}

void loop() {
  delay(10);

  if(Serial.available()){
    c=Serial.read();
    delay(10);
    mySerial.write(c);
    }
  delay(10);
  
  if(mySerial.available()){
    d=mySerial.read();
    delay(10);
    Serial.write(d);    
    }
}
