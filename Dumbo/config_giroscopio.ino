/*  Configuração das informações coletas pelo MPU6050 - Giroscópio,
  para detecção da inclição e movimentação do robô, durante a execução
  do run()
*/

float leitura_angulo_Z() {
  mpu6050.update();

  float GiroZ = 0.0;
  GiroZ = mpu6050.getGyroAngleZ();

  Serial.println("____________");
  Serial.println("Ângulo Z: ");
  Serial.print(GiroZ);
  Serial.println("____________");

  return GiroZ;
}

float leitura_angulo_Y() {
  mpu6050.update();
  
  float GiroY = 0.0;
  GiroY = mpu6050.getGyroAngleY();

  Serial.println("____________");
  Serial.println("Ângulo Y: ");
  Serial.print(GiroY);
  Serial.println("____________");

  return GiroY;
}