#include <Arduino.h>

#define canalA  2
#define canalB  4
#define salidaFW 5

int cantidadPulsosEnReversa = 0;

void procesaPulso();

void setup() {
  pinMode (canalA, INPUT_PULLUP);
  pinMode (canalB, INPUT_PULLUP);
  pinMode (salidaFW, OUTPUT);
  digitalWrite(salidaFW, LOW); //pone salida en bajo.
//Interrupción externa 0, D2, dispara por flanco ascendente.  
  attachInterrupt(digitalPinToInterrupt(canalA), procesaPulso, RISING);

}


void loop() {
  //do nothing.
}

void procesaPulso(){

  if( digitalRead(canalB) == LOW ){ 
    if( cantidadPulsosEnReversa ){
       cantidadPulsosEnReversa--;
    } 
    
    else{
      digitalWrite(salidaFW, HIGH);
      while( digitalRead(canalA) == HIGH );
      digitalWrite(salidaFW, LOW);
    }
  }
  else{
    cantidadPulsosEnReversa++;
  }

}