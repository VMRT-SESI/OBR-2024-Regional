#include <HCSR04.h>

#define T_PIN_frente 25
#define E_PIN_frente 24
UltraSonicDistanceSensor ultra_frente(T_PIN_frente, E_PIN_frente);
#define T_PIN_lat 23
#define E_PIN_lat 22
UltraSonicDistanceSensor ultra_lateral_esquerda(T_PIN_lat, E_PIN_lat);
#define T_PIN_late 27
#define E_PIN_late 26
UltraSonicDistanceSensor ultra_lateral_direta(T_PIN_late, E_PIN_late);

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println("Ultrasônico Frente: ");
  Serial.print(ultra_frente.measureDistanceCm());
  Serial.println("Ultrasônico ESquerda: ");
  Serial.print(ultra_lateral_esquerda.measureDistanceCm());
  Serial.println("Ultrasônico Direita: ");
  Serial.print(ultra_lateral_direta.measureDistanceCm());
  Serial.println();
}