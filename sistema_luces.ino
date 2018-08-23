#include <NewPing.h>

int led_habitacion = 10; 
int led_sala = 11;
int led_cocina = 9; 
int led_exterior1 = 13;
int led_exterior2 = 12;
int led_bano = 8;
int estado = 0;


 /*Aqui se configuran los pines donde debemos conectar el sensor*/
#define TRIGGER_PIN  3
#define ECHO_PIN     2
#define MAX_DISTANCE 200
 
/*Crear el objeto de la clase NewPing*/
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
 


void setup() {
  Serial.begin(9600);
  pinMode(led_exterior1, OUTPUT);
  pinMode(led_exterior2, OUTPUT);
  pinMode(led_sala, OUTPUT);
  pinMode(led_cocina, OUTPUT);
  pinMode(led_habitacion, OUTPUT);
  pinMode(led_bano, OUTPUT);
  
    
   
}

void loop() {
  if (Serial.available() > 0) {
    estado = Serial.read();
  }
  ////////Led Exterior/////////////////
  //Encender Led Exterior
  if (estado == '1') {
    digitalWrite(led_exterior1, HIGH);
    digitalWrite(led_exterior2, HIGH);
    

  }
  //Apagar Led Exterior
  if (estado == '2') {
    digitalWrite(led_exterior1, LOW);
    digitalWrite(led_exterior2, LOW);
  }
  ////////Led Sala/////////////////
  //Encender Led Sala
  if (estado == '3') {
    digitalWrite(led_sala, HIGH);
  }
  //Apagar Led Sala
  if (estado == '4') {
    digitalWrite(led_sala, LOW);
  }

  ////////Led Cocina/////////////////
  //Encender Led Cocina
  if (estado == '5') {
    digitalWrite(led_cocina, HIGH);
  }
  //Apagar Led Cocina
  if (estado == '6') {
    digitalWrite(led_cocina, LOW);
  }


  ////////Led Habitacion/////////////////
  //Encender Led Habitacion
  if (estado == '7') {
    digitalWrite(led_habitacion, HIGH);
  }
  //Apagar Led Habitacion
  if (estado == '8') {
    digitalWrite(led_habitacion, LOW);
  }

  ////////Led baño/////////////////
  //Encender Led baño
  if (estado == '9') {
    digitalWrite(led_bano, HIGH);
  }
  //Apagar Led Exterior
  if (estado == '0') {
    digitalWrite(led_bano, LOW);
  }



// Esperar 1 segundo entre mediciones
  delay(2000);
  // Obtener medicion de tiempo de viaje del sonido y guardar en variable uS
  int uS = sonar.ping_median();
  // Imprimir la distancia medida a la consola serial
  // Calcular la distancia con base en una constante
  Serial.print(uS / US_ROUNDTRIP_CM);



  
}

