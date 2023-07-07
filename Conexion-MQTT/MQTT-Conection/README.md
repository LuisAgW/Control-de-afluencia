# Transmisión de datos mediante MQTT

Este proyecto permite la transmisión de datos utilizando el protocolo MQTT (Message Queuing Telemetry Transport) en un entorno de red. Utiliza la plataforma Arduino y las bibliotecas necesarias para establecer la comunicación con un servidor MQTT y enviar los datos capturados por un sensor.

## Requisitos

- Placa Arduino compatible (por ejemplo, Arduino Uno, ESP-32, ESP-01, ESP-8266)
- Sensor compatible (por ejemplo, sensor de temperatura)
- Biblioteca Arduino MQTT
- Conexión a Internet

## Configuración del Hardware

1. Conecta la placa Arduino a tu computadora mediante un cable USB.
2. Conecta el sensor al pin correspondiente en la placa.

## Configuración del Software

1. Asegúrate de tener instalado algun entorno de desarrollo de compatible con Arduino en tu computadora.
2. Abre el archivo del proyecto en el entorno de desarrollo de Arduino.
3. Configura las variables de conexión MQTT, como la dirección del servidor, el puerto, las credenciales de autenticación y los temas de suscripción y publicación.
4. Carga el código en la placa.

## Uso

1. Alimenta la placa con energía.
2. La placa Arduino se conectará al servidor MQTT y enviará los datos del sensor a través del tema de publicación configurado.
3. El servidor MQTT recibirá los datos y los almacenará o realizará cualquier acción adicional según la configuración del servidor.
4. Puedes verificar los datos publicados utilizando un cliente MQTT o realizar acciones adicionales según tus necesidades.

## Funcionamiento del Código

- Se establecen las configuraciones MQTT, como la dirección del servidor, el puerto y las credenciales de autenticación.
- En la función `setup()`, se realiza la configuración inicial, como la inicialización de la comunicación en serie y la conexión al servidor MQTT.
- En el bucle `loop()`, se capturan los datos del sensor y se publican en el tema configurado utilizando la función `publish()`.

