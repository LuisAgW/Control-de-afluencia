#include <Arduino.h>
#include <ESP8266WiFi.h>
/*
TODO Código encargado de obtener la dirección MAC de la ESP-01/8266
*/
void setup() {
   // Inicializa la comunicación serial a una velocidad de 9600 baudios
  Serial.begin(9600);
}

void loop() {
  Serial.print("\n\nThis is my address: "); 
  // Imprime la dirección MAC de la tarjeta WiFi en formato hexadecimal
  Serial.println(WiFi.macAddress());
  // Imprime la dirección MAC del punto de acceso (AP) si se está utilizando en formato hexadecimal 
  Serial.print("AP MAC: "); 
  Serial.println(WiFi.softAPmacAddress()); 
}
