
/* Project: Smart4car */
/* Author: Jordi Rodriguez */

void Buzzer_init(){
  pinMode (BUZZER, OUTPUT);
  digitalWrite (BUZZER, HIGH);
}

void Buzzer (uint8_t numero, unsigned int tiempo, unsigned int silencio){
  for (uint8_t i=0; i<numero; i++){
    digitalWrite (BUZZER, LOW);
    delay (tiempo);
    digitalWrite (BUZZER, HIGH);
    delay (silencio);
  }  
}
