#include <ESP8266WiFi.h>
#include <Arduino.h>
#include <espnow.h>

#define MY_ROLE         ESP_NOW_ROLE_COMBO              // establecer el rol de este dispositivo: CONTROLLER, SLAVE, COMBO
#define RECEIVER_ROLE   ESP_NOW_ROLE_COMBO              // establecer el rol del receptor
#define WIFI_CHANNEL    1

#define MY_NAME "PC-NODE"
uint8_t receiverAddress[] = {0x18, 0xFE, 0x34, 0xF8, 0xC4, 0x63};   // MAC del sensor
uint8_t receiverAddresss[] = {0x18, 0xFE, 0x34, 0xF8, 0xC5, 0x25};   // MAC del segundo sensor

struct __attribute__((packed)) dataPacket {
  int sensor1;
  int sensor2;
  float sensor3;
};

void transmissionComplete(uint8_t *receiver_mac, uint8_t transmissionStatus) {
  if (transmissionStatus == 0) {
    Serial.println("Datos enviados exitosamente");
  } else {
    Serial.print("Código de error: ");
    Serial.println(transmissionStatus);
  }
}

void dataReceived(uint8_t *senderMac, uint8_t *data, uint8_t dataLength) {
  char macStr[18];
  dataPacket packet;

  snprintf(macStr, sizeof(macStr), "%02x:%02x:%02x:%02x:%02x:%02x", senderMac[0], senderMac[1], senderMac[2], senderMac[3], senderMac[4], senderMac[5]);

  Serial.println();
  Serial.print("Datos recibidos de: ");
  Serial.println(macStr);

  memcpy(&packet, data, sizeof(packet));

  Serial.print("sensor1: ");
  Serial.println(packet.sensor1);

  Serial.print("sensor2: ");
  Serial.println(packet.sensor2);
  
  /*
  Serial.print("sensor3: ");
  Serial.println(packet.sensor3);
  */
}

void setup() {
  Serial.begin(9600);     // inicializar puerto serial

  Serial.println();
  Serial.println();
  Serial.println();
  Serial.print(MY_NAME);
  Serial.println("...inicializando...");

  WiFi.mode(WIFI_STA);
  WiFi.disconnect();        // no queremos conectarnos a una red WiFi

  if (esp_now_init() != 0) {
    Serial.println("Fallo la inicialización de ESP-NOW");
    return;
  }

  esp_now_set_self_role(MY_ROLE);
  esp_now_register_send_cb(transmissionComplete);   // esta función se llamará una vez que se hayan enviado todos los datos
  esp_now_register_recv_cb(dataReceived);           // esta función se llamará cada vez que se reciba datos
  esp_now_add_peer(receiverAddress, RECEIVER_ROLE, WIFI_CHANNEL, NULL, 0);
  esp_now_add_peer(receiverAddresss, RECEIVER_ROLE, WIFI_CHANNEL, NULL, 0);

  Serial.println("Inicializado.");
}

void loop() {
  dataPacket packet;

  /**
   * Valores a enviar
   **/
  packet.sensor1 = 1;
  //packet.sensor2 = 1;
  //packet.sensor3 = 4.20;

  /**
   * Valores recibidos
   **/
  esp_now_send(receiverAddress, (uint8_t *)&packet, sizeof(packet));
  esp_now_send(receiverAddresss, (uint8_t *)&packet, sizeof(packet));

  delay(3000);
}
