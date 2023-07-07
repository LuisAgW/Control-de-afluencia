#include <Arduino.h>
#include <Ultrasonic.h>

int aforo = 0; // Variable para almacenar el aforo
long eco_time; // Variable para almacenar el tiempo de eco del sensor ultrasónico
long distance; // Variable para almacenar la distancia medida
long initialDistance = 0; // Variable para almacenar la distancia inicial

// Configuraciones HC-SR04
int Echo = 19; // Pin del sensor ultrasónico para recibir el eco
int Trigger = 18; // Pin del sensor ultrasónico para enviar la señal de disparo

void setup() {
  Serial.begin(9600); // Iniciar la comunicación serial a 9600 baudios
  pinMode(Trigger, OUTPUT); // Establecer el pin del Trigger como salida
  pinMode(Echo, INPUT); // Establecer el pin del Echo como entrada
  Serial.print("Iniciando la medición de distancia con sensor HC-SR04");
  Serial.println("");
}

void loop() {
  digitalWrite(Trigger, HIGH); // Enviar un pulso de disparo al sensor ultrasónico
  delayMicroseconds(10);
  digitalWrite(Trigger, LOW);

  eco_time = pulseIn(Echo, HIGH); // Obtener el tiempo de eco del sensor ultrasónico

  distance = eco_time / 59; // Calcular la distancia en centímetros

  Serial.print("Distancia medida: ");
  Serial.print(distance);
  Serial.println("cm");
  delay(500);

  // Condición de aforo
  if (distance >= 10 && distance <= 80) {
    aforo++; // Incrementar el aforo
    Serial.print("Aforo: ");
    Serial.println(aforo);
  }
}
