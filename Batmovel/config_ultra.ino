/** 
  *   Detecção e retorno dos valores coletados pelos sensores HCSR04 - Ultrasônicos
  *
  * - Última atualização
  * @date 18/05/2024
  */

float distancia_frente() {
  float cmMsec = ultra_frente.measureDistanceCm();
  return cmMsec;
}

float distancia_lateral_esquerda() {
  float cmMsec = ultra_lateral_esquerda.measureDistanceCm();
  return cmMsec;
}

float distancia_lateral_direita() {
  float cmMsec = ultra_lateral_direta.measureDistanceCm();
  return cmMsec;
}