#include <Arduino.h>
#include<IRrecv.h>
/**
 *@param RECV_PIN Pin e del ESP8266 en el cual se recibira la señal infrarroja
 **/

int RECV_PIN = 2;
int count = 0;
/**
 * @param results description sera la variable encargada de asignar 
 * los valores exadecimales recibidos e identificar el tipo 
 * de señal a la cual esta asociada.
 **/
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() { 
	Serial.begin(9600);
  irrecv.enableIRIn();
  Serial.println("IR Receiver ready");
} 


void loop() { 

/**
 * Dentro del Loop estaremos decifrando el
 * tipo de señal que estaremos captando. dependiendo 
 * del tipo de la señal se emitira un mensaje para 
 * saber cual fue el que ha llegado al receptor.
 **/

	if (irrecv.decode(&results)) {
    Serial.print("Received signal: 0x");
    Serial.print(results.value, HEX);
    Serial.print(" - ");

    if (results.decode_type == UNKNOWN) {
        Serial.println("UNKNOWN");
        Serial.print("Persons detected: ");
        Serial.println(++count); 
    }
    
    irrecv.resume(); // Recibe el siguiente valor
}

  delay(300);
}