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
  int distanciaFrente = ultra_frente.measureDistanceCm();
  int distanciaEsquerda = ultra_lateral_esquerda.measureDistanceCm();
  int distanciaDireita = ultra_lateral_direta.measureDistanceCm();

  if (distanciaFrente < 15) {
    Serial.println("Objeto proximo ao sensor frontal");
  } else if (distanciaEsquerda < 15) {
    Serial.println("Objeto proximo ao sensor lateral esquerdo");
  } else if (distanciaDireita < 15) {
    Serial.println("Objeto proximo ao sensor lateral direito");
  } else if ((distanciaEsquerda < 15) && (distanciaDireita < 15)) {
    Serial.println("Paredes encontradas");
  } else {
    Serial.println();
  }
}