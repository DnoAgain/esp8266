#include <Arduino.h>
#include <ESP8266WiFi.h>

const char* ssid = "TP-LINK_E6CD";

const char* passward = "15805291677";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  WiFi.begin(ssid, passward);
  Serial.print("Connecting to ");
  Serial.print(ssid);
  Serial.println("...");

  int i = 0;
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(1000);
    Serial.print(i++);
    Serial.print("");
  }
  
  Serial.println("");                          
  Serial.println("Connection established!");   
  Serial.print("IP address:    ");             
  Serial.println(WiFi.localIP());    
}

void loop() {
  // put your main code here, to run repeatedly:
}