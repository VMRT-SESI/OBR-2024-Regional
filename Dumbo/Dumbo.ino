#include <MPU6050_tockn.h>
#include "stepperMotor.h"
#include <HCSR04.h>
#include <Servo.h>
#include <Wire.h>

// Definição dos motores
stepperMotor motor_esquerda_frente(
  3,    // Step pin
  6,    // Direction pin
  8,    // Enable pin
  400,  // Resolution
  4490, // Minimum velocity
  256   // Maximum velocity
);

stepperMotor motor_esquerda_fundo(
  2,    // Step pin
  5,    // Direction pin
  8,    // Enable pin
  400,  // Resolution
  4490, // Minimum velocity
  256   // Maximum velocity
);

stepperMotor motor_direita_frente(
  4,    // Step pin
  7,    // Direction pin
  8,    // Enable pin
  400,  // Resolution
  4490, // Minimum velocity
  256   // Maximum velocity
);

stepperMotor motor_direta_fundo(
  12,    // Step pin 
  13,    // Direction pin
  8,    // Enable pin
  400,  // Resolution
  4490, // Minimum velocity
  256   // Maximum velocity
);

// Giroscópio
MPU6050 mpu6050(Wire);
double gyro;

// Sensores de refletância - Pinagem
int sensor1 = A11;        //Sensor extrema direita
int sensor2 = A12;        //Sensor direta
int sensor3 = A13;        //Sensor meio
int sensor4 = A14;        //Sensor esquerda
int sensor5 = A15;        //Sensor extrema esquerda

// Sensores de refletância - Armazenagem
unsigned int sensorExtEsquerda = 0,
    sensorEsquerda = 0,
    sensorMeio = 0, 
    sensorDireita = 0, 
    sensorExtDireita = 0;

// Sensor de cor TCS230 - Esquerda
const int sensor_verde_esq_S0 = 40;
const int sensor_verde_esq_S1 = 42;
const int sensor_verde_esq_S2 = 44;
const int sensor_verde_esq_S3 = 46;
const int sensor_verde_esq_OUT = 48;

// Sensor de cor TCS230 - Direita
const int sensor_verde_dir_S0 = 40;
const int sensor_verde_dir_S1 = 42;
const int sensor_verde_dir_S2 = 44;
const int sensor_verde_dir_S3 = 46;
const int sensor_verde_dir_OUT = 48;


// Sensores Ultrasônicos
#define T_PIN_frente 25
#define E_PIN_frente 24
UltraSonicDistanceSensor ultra_frente(T_PIN_frente, E_PIN_frente);
#define T_PIN_lat 23
#define E_PIN_lat 22
UltraSonicDistanceSensor ultra_lateral_esquerda(T_PIN_lat, E_PIN_lat);
#define T_PIN_late 27
#define E_PIN_late 26
UltraSonicDistanceSensor ultra_lateral_direta(T_PIN_late, E_PIN_late);

// Declaração LEDS
int led_detecta_obstaculo_amarelo = 28;
int led_detecta_rampa_amarelo = 29;
int led_detecta_resgate = 30;

int led_curva_esquerda_vermelho = 31;
int led_curva_direita_vermelho = 32;
int led_leitura_preto_vermelho = 33;
int led_casos_vermelho = 34;

int led_detecta_esquerda_verde = 35;
int led_detecta_direta_verde = 37;

// Declaração botão
const int push_button_start = 36;
bool estado_botao = 0;

// Declaração motores da garra;
const int motor_tower_garra = 38;
const int motor_microServo_garra = 39;
Servo s;
int posicao_inicial = 0;

// =================================== //
//             REGULAGEM              //
  int preto = 15;
  int verde = 50;
// =================================== //

// =================================== //
//             VARIÁVEIS              //
  int velocidade_curva = 50;
  int velocidade_rampa = 50;
  int velocidade_constate = 50;

  float GiroY = 0.0;
  float GiroZ = 0.0;

  int tempo = 0;
  int grau_alvo = 0;
  bool verifica_rampa = false;
  bool verifica_obstaculo = false;
  bool verifica_regate = false;
// =================================== //

void setup(){
  Serial.begin(115200);
  setupMotors(0);
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);

  // Sensor de refletância
  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
  pinMode(sensor3, INPUT);
  pinMode(sensor4, INPUT);
  pinMode(sensor5, INPUT);

  // Sensores de cor
  pinMode(sensor_verde_esq_S0, OUTPUT);
  pinMode(sensor_verde_esq_S1, OUTPUT);
  pinMode(sensor_verde_esq_S2, OUTPUT);
  pinMode(sensor_verde_esq_S3, OUTPUT);
  pinMode(sensor_verde_esq_OUT, INPUT);

  pinMode(sensor_verde_dir_S0, OUTPUT);
  pinMode(sensor_verde_dir_S1, OUTPUT);
  pinMode(sensor_verde_dir_S2, OUTPUT);
  pinMode(sensor_verde_dir_S3, OUTPUT);
  pinMode(sensor_verde_dir_OUT, INPUT);

  // Leds
  pinMode(led_detecta_obstaculo_amarelo, OUTPUT);
  pinMode(led_detecta_rampa_amarelo, OUTPUT);
  pinMode(led_detecta_resgate, OUTPUT);

  pinMode(led_casos_vermelho, OUTPUT);
  pinMode(led_curva_direita_vermelho, OUTPUT);
  pinMode(led_curva_esquerda_vermelho, OUTPUT);
  pinMode(led_leitura_preto_vermelho, OUTPUT);

  pinMode(led_detecta_direta_verde, OUTPUT);
  pinMode(led_detecta_esquerda_verde, OUTPUT);

  // Motores
  s.attach(motor_tower_garra);
  s.attach(motor_microServo_garra);
  s.write(0);

  // Botão
  pinMode(push_button_start, INPUT_PULLUP);
}

void loop() {
  if(digitalRead(push_button_start) == LOW) {
    estado_botao = !estado_botao;
    run();
  } else {
    aguardo();
  }
}
