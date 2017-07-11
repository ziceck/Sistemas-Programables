//**CS - Pin 10
//http://172.16.200.19/723456789

#include <Ethernet.h>
#include <SPI.h>
boolean reading=false;


byte ip[] = { 172, 16, 200, 19 };
byte gateway[] = { 172, 16, 200, 254 };
byte subnet[] = { 255, 255, 255, 0 };
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};


EthernetServer server = EthernetServer (80);

void setup(){
  Serial.begin(9600);
  
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(6, OUTPUT);
  
  Ethernet.begin (mac,ip,gateway);
  
  server.begin();
  Serial.println(Ethernet.localIP());
}

void loop(){
  checkForClient();
}

void checkForClient(){
  EthernetClient client = server.available();
  
    if(client){
      boolean currentLineIsBlank=true;
      boolean sentHeader=false;
      
      while(client.connected()){
        if(client.available()){
          if(!sentHeader){
            client.println("HTTP/1.1 200 OK");
            client.println("Content-Type: text/html");
            client.println();
            sentHeader = true;
            
          }
          char c=client.read();
          
          if(reading && c == ' ') reading = false;
          if(c == '?') reading = true;
          
          if(reading){
            Serial.print(c);
            
            switch(c){
              case '2':
              triggerPin(2,client);
              break;
              
              case '3':
              triggerPin(3,client);
              break;
              
              case '4':
              triggerPin(4,client);
              break;
              
              case '5':
              triggerPin(5,client);
              break;
              
              case '6':
              triggerPin(6,client);
              break;
              
            }
          }
              
              if (c == '\n' && currentLineIsBlank) break;
              
              if( c== '\n'){
                currentLineIsBlank=true;
              } else if(c != '\r'){
                currentLineIsBlank=false;
              }
        }
      }
      
      delay(1);
client.stop();
    }
}

void triggerPin(int pin,EthernetClient client){
  client.print("Turning on pin");
  client.println(pin); 
  client.print("<br>");
  
  digitalWrite(pin,HIGH);
  delay(25);
  digitalWrite(pin,LOW);
  delay(25);
  
  }
