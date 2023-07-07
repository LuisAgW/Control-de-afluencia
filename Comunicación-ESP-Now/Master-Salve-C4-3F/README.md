# Comunicación ESP-NOW

Este proyecto implementa la comunicación entre dispositivos utilizando la biblioteca ESP-NOW en el ESP8266. El dispositivo actual actúa como nodo de PC y envía datos a otros dispositivos receptores, como sensores.

## Requisitos

- Placa ESP8266 (por ejemplo, NodeMCU)
- Biblioteca ESP8266WiFi para Arduino
- Biblioteca espnow para Arduino

## Configuración del Hardware

- No se requiere una configuración específica del hardware, ya que se utiliza la comunicación inalámbrica a través de ESP-NOW.

## Configuración del Software

1. Asegúrate de tener instalado el entorno de desarrollo de Arduino en tu computadora.
2. Abre el archivo del proyecto `espnow_communication.ino` en el entorno de desarrollo de Arduino.
3. Verifica y ajusta el rol y las direcciones MAC de los dispositivos receptores en las constantes `MY_ROLE`, `receiverAddress` y `receiverAddresss`.
4. Sube el código al ESP8266.

## Uso

1. Alimenta el ESP8266 con energía.
2. El ESP8266 se iniciará y establecerá una comunicación ESP-NOW con los dispositivos receptores.
3. El ESP8266 enviará periódicamente un paquete de datos a los dispositivos receptores, que incluye valores ficticios de los sensores.
4. Los dispositivos receptores mostrarán los datos recibidos en la consola serial.

## Funcionamiento del Código

- Se establece el rol del dispositivo actual como `MY_ROLE` y se definen las direcciones MAC de los dispositivos receptores en `receiverAddress` y `receiverAddresss`.
- Se define una estructura `dataPacket` que contiene los valores de los sensores a enviar.
- La función `transmissionComplete` se llama una vez que se hayan enviado todos los datos y muestra un mensaje de éxito o un código de error.
- La función `dataReceived` se llama cada vez que se recibe un paquete de datos y muestra los valores de los sensores recibidos.
- En la función `setup()`, se inicializa la comunicación ESP-NOW y se registran las funciones de callback.
- En el bucle `loop()`, se crea un paquete de datos con valores ficticios de los sensores y se envía a los dispositivos receptores utilizando ESP-NOW.

En el código proporcionado, se involucran dos dispositivos receptores. Estos dispositivos están representados por las variables receiverAddress y receiverAddresss, 
que contienen las direcciones MAC de los dispositivos receptores. 

El dispositivo actual (emisor) también tiene la capacidad de recibir información de los dispositivos receptores. Cuando los dispositivos receptores envían datos al 
nodo actual utilizando la función `esp_now_send()`, se activa la función de callback `dataReceived()`. Esta función se encarga de procesar los datos recibidos y realizar 
acciones en consecuencia. Por lo tanto, el nodo actual actúa tanto como emisor como receptor de información.
