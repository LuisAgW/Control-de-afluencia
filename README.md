# Compilatorio de códigos para el conteo de afluencia de personas

Este es un compilatorio de códigos utilizados para el conteo de la afluencia de personas. Se emplea uso de sensores infrarrojos, ultrasonidos, protocolos de comunicación como ESP-NOW y MQTT, y placas como ESP01 y ESP32. Los códigos proporcionados te permitirán implementar soluciones de conteo de personas en diferentes entornos y con distintos enfoques.

## Contenido

El compilatorio incluye los siguientes códigos:

1. **Conteo de personas con sensor infrarrojo:** Este código utiliza un sensor infrarrojo para detectar el paso de personas y realiza el conteo incrementando una variable cada vez que se detecta un paso.

2. **Conteo de personas con sensor ultrasonido:** En este código se emplea un sensor ultrasonido para medir la distancia y detectar la presencia de personas. Se realiza el conteo incrementando una variable cuando se detecta la entrada o salida de una persona.

3. **Comunicación ESP-NOW entre dispositivos:** Este código utiliza el protocolo de comunicación ESP-NOW para transmitir datos de conteo de personas entre dispositivos ESP01 o ESP32. Permite establecer una red de dispositivos y compartir información de conteo.

4. **Transmisión de datos mediante MQTT:** En este código se implementa la transmisión de datos utilizando el protocolo MQTT. Los datos de conteo de personas se envían a un servidor MQTT y se pueden visualizar o procesar en tiempo real.

## Requisitos

- Placas ESP01 o ESP32
- Visual Studio Code (Extención -> PlatformIO)
- Sensores infrarrojos y/o ultrasonidos (dependiendo del código específico)
- Bibliotecas necesarias para cada código (por ejemplo, IRremoteESP8266 para el sensor infrarrojo, Ultrasonic para el sensor ultrasonido, PubSubClient para MQTT)

## Configuración

Cada código requiere una configuración específica que se detalla en los comentarios del código. Deberás configurar las conexiones de hardware, como los pines utilizados para los sensores, así como las variables relacionadas con la red (por ejemplo, SSID y contraseña del Wi-Fi) y la configuración del protocolo de comunicación específico.

## Uso

1. Configura las conexiones de hardware y la configuración correspondiente en cada código.
2. Carga el código en las placas ESP01 o ESP32 utilizando el el IDE adecuado.
3. Alimenta las placas con energía.
4. Observa el conteo de personas o verifica la transmisión de datos según el código específico utilizado.

## Contribución

Si deseas contribuir a este compilatorio de códigos, puedes seguir estos pasos:

1. Realiza un fork del repositorio.
2. Crea una nueva rama para tu contribución.
3. Agrega nuevos códigos, mejora los existentes o realiza modificaciones según sea necesario.
4. Realiza un pull request y describe en detalle los cambios realizados.
