#include <Arduino.h>
#include <WiFi.h>
#include <PubSubClient.h>

/**
************ MQTT CONFIG **************
**/

// Configuración del servidor MQTT
const char *mqtt_server = "172.30.3.10";
const int mqtt_port = 1883;
const char *mqtt_user = "";
const char *mqtt_pass = "";
const char *root_topic_subscribe = "Sensor_conteo/in";
const char *root_topic_publish = "Sensor_conteo";

/**
************ WIFICONFIG **************
**/

// Configuración de la red WiFi
const char* ssid = "labred";
const char* password =  "labred2017";

/**
************ PRAM GLOBALES *************
**/

WiFiClient espClient;            // Cliente WiFi
PubSubClient client(espClient);  // Instancia de la librería PubSubClient
char msg[25];                    // Mensaje a enviar
long count = 20;

/**
************ FUNCIONES **************
**/

void callback(char* topic, byte* payload, unsigned int length);
void reconnect();
void setup_wifi();

void setup() {
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, mqtt_port);   // Configuración del servidor y puerto MQTT
  client.setCallback(callback);               // Asignación de la función de callback para recibir mensajes
}

void loop() {
  if (!client.connected()) {   // Intentar conexión si no está conectado
    reconnect();
  }

	/*
	!  String temp valor cambiante dependiendo del conteo realizado
	*/
  if (client.connected()) {
    String temp = "15";							
    String str = String(temp);   				// Convertir el valor a String
    str.toCharArray(msg, 25);    				// Convertir el mensaje a un array de caracteres
    client.publish(root_topic_publish, msg);   // Publicar el mensaje en el tópico
    delay(300);   // Retardo entre mensajes
  }
}

/**
************ CONEXION WIFI **************
**/

void setup_wifi() {
  delay(10);
  // Conexión a la red WiFi
  Serial.println();
  Serial.print("Conectando a la red WiFi: ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("Conectado a la red WiFi!");
  Serial.println("Dirección IP: ");
  Serial.println(WiFi.localIP());
}

/**
************ CONEXION MQTT **************
**/

void reconnect() {
  while (!client.connected()) {
    Serial.print("Intentando conexión MQTT...");
    // Crear un ID de cliente único
    String clientId = "CLIENT";
    clientId += String(random(0xffff), HEX);
    // Intentar conexión
    if (client.connect(clientId.c_str(), mqtt_user, mqtt_pass)) {
      Serial.println("Conectado!");
      // Suscribirse al tópico
      if (client.subscribe(root_topic_subscribe)) {
        Serial.println("Suscripción exitosa");
      } else {
        Serial.println("Fallo en la suscripción");
      }
    } else {
      Serial.print("Falló con error -> ");
      Serial.print(client.state());   // Mostrar número de error para depuración
      Serial.println(" Intentando de nuevo en 5 segundos");
      delay(5000);
    }
  }
}

/**
************ CALLBACK **************
**/

void callback(char* topic, byte* payload, unsigned int length) {
  String incoming = "";
  Serial.print("Mensaje recibido desde -> ");
  Serial.print(topic);
  Serial.println("");
  for (int i = 0; i < length; i++) {   // Recuperar caracter por caracter del mensaje
    incoming += (char)payload[i];
  }
  incoming.trim();   // Eliminar espacios en blanco delante y detrás del mensaje
  Serial.println("Mensaje -> " + incoming);
}
