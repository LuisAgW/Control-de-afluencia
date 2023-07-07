/*
TODO El código envia de manera constante una señal predefinada
*/

#include <Arduino.h>
#include <IRremoteESP8266.h>
#include <IRsend.h>

const uint16_t kIrLed = 2;  // Pin GPIO del ESP8266 que se utilizará para el LED IR.

#define POWER         0xE0E040BF           
#define SAMSUNG_BIT   32

IRsend irsend(kIrLed);

void setup() {
  // Código de configuración que se ejecuta una vez:
  Serial.begin(9600);  // Inicializa la comunicación serie a una velocidad de 9600 baudios.
  irsend.begin();      // Inicializa el envío de señales IR.
}

void loop() {
  // Código que se ejecuta en bucle continuamente:
  irsend.sendSAMSUNG(POWER, SAMSUNG_BIT);  // Envía la señal infrarroja de encendido/apagado de Samsung.
}
