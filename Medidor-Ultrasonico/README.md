# Sensor Ultrasonico

Este proyecto utiliza una placa ESP32 y un sensor ultrasónico para medir la distancia. El sensor ultrasónico emite ondas de sonido y mide el tiempo que tarda en recibir el eco de las ondas reflejadas en un objeto, lo que permite calcular la distancia al objeto.

## Requisitos

- Placa ESP32 o ESP8266 (por ejemplo, NodeMCU o ESP-01)
- Sensor ultrasónico HC-SR04
- Biblioteca Ultrasonic para Arduino

## Configuración del Hardware

1. Conecta el pin TRIGGER del sensor ultrasónico al pin de salida de la placa ESP32 o ESP8266 (por ejemplo, GPIO18).
2. Conecta el pin ECHO del sensor ultrasónico al pin de entrada de la placa ESP32 o ESP8266 (por ejemplo, GPIO19).
3. Alimenta el sensor ultrasónico y la placa ESP32 o ESP8266.

## Configuración del Software

1. Asegúrate de tener instalado el entorno de desarrollo de Arduino en tu computadora.
2. Abre el archivo del proyecto `ultrasonic_sensor.ino` en el entorno de desarrollo de Arduino.
3. Sube el código a tu placa ESP32 o ESP8266.

## Uso

1. Alimenta la placa ESP32 o ESP8266.
2. La placa leerá periódicamente la distancia medida por el sensor ultrasónico.
3. La distancia medida se mostrará en la consola serial.

## Funcionamiento del Código

- Se definen las constantes `Echo` y `Trigger` para especificar los pines utilizados para la conexión del sensor ultrasónico.
- En la función `setup()`, se establece la velocidad de comunicación serial y se configuran los pines como entradas o salidas.
- En el bucle `loop()`, se emite un pulso ultrasónico y se mide el tiempo que tarda en recibir el eco. A partir de este tiempo, se calcula la distancia al objeto y se muestra en la consola serial.

