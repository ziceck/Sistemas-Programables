int xPin1 = A0;
int yPin1 = A1;
int xPin2 = A2;
int yPin2 = A3;
int xPosition1 = 0;
int yPosition1 = 0;
int xPosition2 = 0;
int yPosition2 = 0;

void setup() { 
  Serial.begin(9600);   
  pinMode(xPin1, INPUT);
  pinMode(yPin1, INPUT);
  pinMode(xPin2, INPUT);
  pinMode(yPin2, INPUT);  
}

void loop() {
  xPosition1 = analogRead(xPin1);
  yPosition1 = analogRead(yPin1);
  xPosition2 = analogRead(xPin2);
  yPosition2 = analogRead(yPin2);
  Serial.print(" | Joystick1 : ");
  Serial.print("X: ");
  Serial.print(xPosition1);
  Serial.print(" | Y: ");
  Serial.print(yPosition1);
  Serial.print(" | Joystick2 : ");
  Serial.print("X: ");
  Serial.print(xPosition2);
  Serial.print(" | Y: ");
  Serial.println(yPosition2);  
  delay(100);
}
