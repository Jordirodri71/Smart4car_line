# Smartcar_line
 Robot para iniciación a competiciones

Autor: Jordi Rodriguez  
Practica de programación de robot seguidor de linea con IDE Arduino


*** Material utilizado ***

- HC-SR04 = Sensor ultrasonido de distancia (3x)  
- TCRT5000 = Sensor infrarrojo de proximidad (2x)  
- LCD I2C = Pantalla lcd  
- Buzzer activo + R100Ω
- Pulsador 1 + R10kΩ
- Pulsador 2 + R10kΩ
- L298N = Controlador de motores  
- TCST2103 = Foto interruptor para decoder (2x)


*** Pines de conexion ***  

A0 = Pulsador 1  
A1 = Pulsador 2  
A2 = Sensor línea izquierda TCRT5000 (Digital)
A3 = Sensor línea derecha TCRT5000 (Digital)
A4 = D18 = I2C LCD (SCA)
A5 = D19 = I2C LCD (SCL)

D0 = (RX) = ** VACIO **
D1 = (TX) = ** VACIO **
D2 = (INT0) = Decoder izquierdo
D3-= (INT1) = Decoder derecho
D4 = Buzzer
D5-= ENB motor izquierdo
D6-= ENA motor derecho
D7 = IN1 motor derecho
D8 = IN2 motor derecho
D9-= IN3 motor izquierdo
D10-= IN4 motor izquierdo
D11-= Sensor frontal ultrasonido  
D12 = Sensor derecho ultrasonido  
D13 = Sensor izquierdo ultrasonido