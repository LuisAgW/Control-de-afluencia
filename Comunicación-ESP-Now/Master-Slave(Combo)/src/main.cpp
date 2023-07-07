#include <ESP8266WiFi.h>
#include <Arduino.h>
#include <espnow.h>

#define MY_ROLE         ESP_NOW_ROLE_COMBO
#define RECEIVER_ROLE   ESP_NOW_ROLE_COMBO
#define WIFI_CHANNEL    1

#define MY_NAME         "PC NODE"
uint8_t receiverAddress[] = {0x18, 0xFE, 0x34, 0xF8, 0xC4, 0x63};   // MAC del sensor

struct __attribute__((packed)) dataPacket {
  int sensor1;
  int sensor2;
  float sensor3;
};

void transmissionComplete(uint8_t *receiver_mac, uint8_t transmissionStatus) {
  if (transmissionStatus == 0) {
    Serial.println("Data sent successfully"); // Imprimir mensaje si la transmisión de datos fue exitosa
  } else {
    Serial.print("Error code: ");
    Serial.println(transmissionStatus); // Imprimir el código de error si la transmisión de datos falló
  }
}

void dataReceived(uint8_t *senderMac, uint8_t *data, uint8_t dataLength) {
  char macStr[18];
  dataPacket packet;

  snprintf(macStr, sizeof(macStr), "%02x:%02x:%02x:%02x:%02x:%02x", senderMac[0], senderMac[1], senderMac[2], senderMac[3], senderMac[4], senderMac[5]);

  Serial.println();
  Serial.print("Received data from: ");
  Serial.println(macStr); // Imprimir la dirección MAC del dispositivo emisor de los datos

  memcpy(&packet, data, sizeof(packet));

  Serial.print("sensor1: ");
  Serial.println(packet.sensor1); // Imprimir el valor del sensor1 recibido
  Serial.print("sensor2: ");
  Serial.println(packet.sensor2); // Imprimir el valor del sensor2 recibido
  Serial.print("sensor3: ");
  Serial.println(packet.sensor3); // Imprimir el valor del sensor3 recibido
}

void setup() {
  Serial.begin(9600);     // Inicializar el puerto serial

  Serial.println();
  Serial.println();
  Serial.println();
  Serial.print(MY_NAME);
  Serial.println("...initializing...");

  WiFi.mode(WIFI_STA);
  WiFi.disconnect();        // No queremos conectarnos a una red WiFi

  if (esp_now_init() != 0) {
    Serial.println("ESP-NOW initialization failed"); // Imprimir mensaje si la inicialización de ESP-NOW falló
    return;
  }

  esp_now_set_self_role(MY_ROLE);
  esp_now_register_send_cb(transmissionComplete);   // Esta función se llamará una vez que se haya enviado todos los datos
  esp_now_register_recv_cb(dataReceived);           // Esta función se llamará cada vez que se reciba datos
  esp_now_add_peer(receiverAddress, RECEIVER_ROLE, WIFI_CHANNEL, NULL, 0);

  Serial.println("Initialized.");
}

void loop() {
  dataPacket packet;

  packet.sensor1 = 789; // Valor ficticio del sensor1
  packet.sensor2 = 1011; // Valor ficticio del sensor2
  packet.sensor3 = 6.28; // Valor ficticio del sensor3

  esp_now_send(receiverAddress, (uint8_t *)&packet, sizeof(packet)); // Enviar los datos al dispositivo receptor utilizando ESP-NOW

  delay(3000);
}
