/*
DB9 MACHO al controlador
1. nc
2. nc
3. nc
4. Pulsos sintetizados
5. nc
7. GND
8. 24Vcc
9. nc

DB9 HEMBRA al ENCODER
1. nc
2. nc
3. Canal B
4. Canal A
5. GND
6. Canal Z (nc)
7. nc
8. nc
9. 12V

Ajustar la salida del regulador de voltaje a 12V
*/
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