
/* Project: Smart4car */
/* Author: Jordi Rodriguez */

void Motores_init(){
  pinMode (IN1, OUTPUT);
  pinMode (IN2, OUTPUT);
  pinMode (ENA, OUTPUT);
  pinMode (ENB, OUTPUT);
  pinMode (IN3, OUTPUT);
  pinMode (IN4, OUTPUT);
}

void Para (int tiempo){
  digitalWrite (ENA, 0);
  digitalWrite (IN1, LOW);
  digitalWrite (IN2, LOW);
  digitalWrite (ENB, 0);
  digitalWrite (IN3, LOW);
  digitalWrite (IN4, LOW);
  delay (tiempo);
}

void Stop (){
  digitalWrite (ENA, 0);
  digitalWrite (IN1, LOW);
  digitalWrite (IN2, LOW);
  digitalWrite (ENB, 0);
  digitalWrite (IN3, LOW);
  digitalWrite (IN4, LOW);
}

void Avanza(){
  digitalWrite (ENA, Velocidad);
  digitalWrite (IN1, LOW);
  digitalWrite (IN2, HIGH);
  digitalWrite (ENB, Velocidad);
  digitalWrite (IN3, LOW);
  digitalWrite (IN4, HIGH);
}

void Retrocede(){
  digitalWrite (ENA, Velocidad/2);
  digitalWrite (IN1, HIGH);
  digitalWrite (IN2, LOW);
  digitalWrite (ENB, Velocidad/2);
  digitalWrite (IN3, HIGH);
  digitalWrite (IN4, LOW);
  Buzzer (1, 100, 100);
}

void Izquierda(){
  digitalWrite (ENA, Velocidad);
  digitalWrite (IN1, LOW);
  digitalWrite (IN2, HIGH);
  digitalWrite (ENB, 0);
  digitalWrite (IN3, HIGH);
  digitalWrite (IN4, LOW);
}

void Derecha(){
  digitalWrite (ENA, Velocidad);
  digitalWrite (IN1, HIGH);
  digitalWrite (IN2, LOW);
  digitalWrite (ENB, 0);
  digitalWrite (IN3, LOW);
  digitalWrite (IN4, HIGH);
}

void Gira_izquierda(){
  digitalWrite (ENA, Velocidad/2);
  digitalWrite (IN1, LOW);
  digitalWrite (IN2, HIGH);
  digitalWrite (ENB, Velocidad/2);
  digitalWrite (IN3, HIGH);
  digitalWrite (IN4, LOW);
}

void Gira_derecha(){
  digitalWrite (ENA, Velocidad/2);
  digitalWrite (IN1, HIGH);
  digitalWrite (IN2, LOW);
  digitalWrite (ENB, Velocidad/2);
  digitalWrite (IN3, LOW);
  digitalWrite (IN4, HIGH);
}
