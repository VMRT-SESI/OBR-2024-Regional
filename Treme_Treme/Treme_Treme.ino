/** ------------------ Treme Treme  ------------------
  * Robô segue linha que realiza os desafios propostos 
  * no trajeto da OBR (Olimpiada Brasileira de Robótica).
  * - Segue Linha;
  * - Identificação de cores
  * - Desvio de Obstáculo
  * - Controle de estados por giroscópio
*/

#include <MPU6050_tockn.h>
#include <HCSR04.h>
#include <Wire.h>
#include "motor.h"
#include "led_class.h"

// --------------------------
//        Regulagem

int velocidade = 100;
int velocidade_rampa = 125;
int preto = 750;
int branco = 200;
int tempo = 0;

//     - Controle -

int distancia_frente = 0;
bool verde_esquerdo = 0;
bool verde_direito = 0;
bool inclinacao_rampa = 0;
bool obstaculo_encontrado = 0;

// --------------------------

enum EstadosRobo {
  estado_segue_linha,
  estado_obstaculo_encontrado,
  estado_rampa_encontrada
};
EstadosRobo EstadoAtual = estado_segue_linha;

// Giroscópio
MPU6050 mpu6050(Wire);
double gyro;
float GiroY = 0.0;
float GiroZ = 0.0;

// Pinos do sensor de refletância
int sensor1 = A15;
int sensor2 = A14;
int sensor3 = A13;
int sensor4 = A12;
int sensor5 = A11;

// Variáveis de armazenamento dos valores coletados nos sensores de refletância
int sensorExtEsquerda,
  sensorEsquerda,
  sensorMeio,
  sensorDireita,
  sensorExtDireita = 0;

// Pinos de conexao do modulo da esquerda
#define pinS0E 35
#define pinS1E 37
#define pinS2E 39
#define pinS3E 41
#define pinOutE 43

// Pinos de conexao do modulo da direita
#define pinS0D 34
#define pinS1D 36
#define pinS2D 38
#define pinS3D 40
#define pinOutD 42

// Variáveis de armazenamento dos valores coletados nos modulos
// E - Esquerda
// D - Direita
unsigned int valorVermelhoE = 0;
unsigned int valorVerdeE = 0;
unsigned int valorAzulE = 0;
unsigned int valorBrancoE = 0;
unsigned int valorVermelhoD = 0;
unsigned int valorVerdeD = 0;
unsigned int valorAzulD = 0;
unsigned int valorBrancoD = 0;

#define T_PIN_frente 24
#define E_PIN_frente 25
UltraSonicDistanceSensor ultra_frente(T_PIN_frente, E_PIN_frente);

// Motores
motor motorA(6, 7);
motor motorB(8, 9);

// LEDs
led ledVermE(44);
led ledMeio(46);
led ledVermD(48);

void setup() {
  // Configurações inicializadas
  ledMeio.on();
  ledVermD.on();
  ledVermE.on();

  Serial.begin(2400);
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);

  // Saídas dos sensores de refletância
  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
  pinMode(sensor3, INPUT);
  pinMode(sensor4, INPUT);
  pinMode(sensor5, INPUT);

  //Saídas dos Pinos da esquerda
  pinMode(pinS0E, OUTPUT);
  pinMode(pinS1E, OUTPUT);
  pinMode(pinS2E, OUTPUT);
  pinMode(pinS3E, OUTPUT);
  pinMode(pinOutE, INPUT);

  //Saídas dos Pinos da direita
  pinMode(pinS0D, OUTPUT);
  pinMode(pinS1D, OUTPUT);
  pinMode(pinS2D, OUTPUT);
  pinMode(pinS3D, OUTPUT);
  pinMode(pinOutD, INPUT);

  // Escrita dos modulos
  digitalWrite(pinS0E, HIGH);
  digitalWrite(pinS1E, LOW);
  digitalWrite(pinS0D, HIGH);
  digitalWrite(pinS1D, LOW);

  // Configurações finalizadas
  ledMeio.off();
  ledVermD.off();
  ledVermE.off();
}

void detectaCor();

void loop() {
  distancia_frente = ultra_frente.measureDistanceCm();
  //Serial.println(distancia_frente);

  // if (distancia_frente <= 15 && distancia_frente > 0) {
  //   EstadoAtual = estado_obstaculo_encontrado;
  // }
  // switch(EstadoAtual) {
  //   case estado_segue_linha:
  //   segue_linha();
  //   break;

  //   case estado_obstaculo_encontrado:
  //   devioObstaculo();
  //   break;

  //   case estado_rampa_encontrada:
  //   break;
  // }
  for(int i = 0; i < 90; i++){
    curvaEsquerda(100);
  }
  parar();
  delay(1500);
  for(int i = 0; i < 90; i++){
    curvaDireita(100);
  }
  parar();
  delay(1500);
  andar(150);
  delay(2500);
  for(int i = 0; i < 90; i++){
    curvaEsquerda(100);
  }
  parar();
  delay(1500);
  for(int i = 0; i < 90; i++){
    curvaDireita(100);
  }
  parar();
  delay(1500);
}
