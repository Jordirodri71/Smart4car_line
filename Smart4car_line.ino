
/* Project: Smart4car */
/* Author: Jordi Rodriguez */

#include "Pinout.h"
#include "Constants.h"

#include <ButtonKing.h>
ButtonKing button_menu(BUTTON_L, true);
ButtonKing button_intro(BUTTON_R, true);

#include <NewPing.h>
NewPing sonar_front (PING_PIN_F, PING_PIN_F);
NewPing sonar_left (PING_PIN_L, PING_PIN_L);
NewPing sonar_right (PING_PIN_R, PING_PIN_R);

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd (0x27, 20, 4);


void setup() {
  lcd.init();
  lcd.clear();
  lcd.setCursor (0,0);
  lcd.print("****Smart4car****");

  button_menu.setClick(Menu);
  button_menu.setLongClickStop(Abort);
  
  button_intro.setClick(Intro);
  button_intro.setLongClickStop(Cuenta_atras);
  
  Buzzer_init();
  Buzzer(2,100,100);

  pinMode(SENSOR_L, INPUT);
  pinMode(SENSOR_R, INPUT);

  Motores_init();

  lcd.setCursor (5,1);
  lcd.print("Inicio");
}


void loop() {
  button_intro.isClick();
  button_menu.isClick();

}


void Menu(){
  
}

void Intro(){
  
}

void Cuenta_atras(){
  
}

void Abort(){
  Stop();
  lcd.clear();
  lcd.setCursor (0,0);
  lcd.print("****Smart4car****");
  lcd.setCursor (5,1);
  lcd.print("Detenido");
  Buzzer(1,500, 1000);
  Menu();
}

void Lectura_sensores() {
  Sensor_left_old = Sensor_left;
  Sensor_right_old = Sensor_right;
  
  Sensor_left = digitalRead(SENSOR_L);
  Sensor_right = digitalRead(SENSOR_R);

  Sensor_front = sonar_front.ping_cm();
}

void Distancia() {

  while (Sensor_front<=STOP_DISTANCE){
    Para(100);
    Sensor_front = sonar_front.ping_cm();
    
    /* Retrocede si tiene un obstáculo cerca */
    if (Sensor_front<=ATRAS_DISTANCE) {
      lcd.print("******Atras******");
      Retrocede();
      Buzzer(1,500,500);
    }
  
    /* Se mantiene parado si tiene un obstáculo delante */
    else {
      
      lcd.print("******Stop*******");
      Stop();
      Buzzer(1,100,1000);
    }
  }
}

void Linea() {
  /* Decisiones de movimiento en función de los sensores de línea */
  if (Sensor_left == 1 && Sensor_right == 1){
    Avanza();
    lcd.print("*****Avanza******");
    
  }
  if (Sensor_left == 0 && Sensor_right == 1){
    Derecha();
    lcd.print("*****Derecha*****");
  }
  if (Sensor_left == 1 && Sensor_right == 0){
    Izquierda();
    lcd.print("****Izquierda****");
  }

  /* Si pierde la línea */ 
  if (Sensor_left == 0 && Sensor_right == 0){
    Para(100);
    lcd.print("******Stop*******");
    if (Sensor_left_old == 1 && Sensor_right_old == 0){
      lcd.print("**Buscando izq.**");
      Gira_izquierda();
      Avanza();
    }
    if (Sensor_left_old == 0 && Sensor_right_old == 1){
      lcd.print("**Buscando der.**");
      Gira_derecha();
      Avanza();
    }   
  }
}
