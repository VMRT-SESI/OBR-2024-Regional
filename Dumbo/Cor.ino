void leitura_verde_direita() {
  detectaCor_esquerda();
  if (
    (valorAzul_sensor_direito < valorVermelho_sensor_direito) &&  //Verifica se a cor azul foi detectada
    (valorAzul_sensor_direito < valorVerde_sensor_direito) && (valorBranco_sensor_direito < 100)) {
    if (
      (valorVerde_sensor_direito < valorVermelho_sensor_direito) &&  //Verifica se a cor verde foi detectada
      (valorVerde_sensor_direito < valorAzul_sensor_direito) && (valorBranco_sensor_direito < 100)) {
      Serial.println("Curva com verde");
    }
    Serial.println("Curva com verde");
  } else {
    Serial.println("Não é curva");
  }

  Mostra valores no serial monitor
  Serial.print("Vermelho :");
  Serial.print(valorVermelho);

  Serial.print(" Verde : ");
  Serial.print(valorVerde);

  Serial.print(" Azul : ");
  Serial.print(valorAzul);

  Serial.print(" Branco : ");
  Serial.print(valorBranco);
  Serial.println();

  Verifica se a cor vermelha foi detectada
  if ((valorVermelho < valorAzul) &&
      (valorVermelho < valorVerde) &&
      (valorBranco < 100)) {
    Serial.println("Vermelho");
    digitalWrite(pinoLedVerm, HIGH); //Acende o led vermelho
    digitalWrite(pinoLedVerd, LOW);
    digitalWrite(pinoLedAzul, LOW);

  } else if ((valorAzul < valorVermelho) &&  //Verifica se a cor azul foi detectada
             (valorAzul < valorVerde) &&
             (valorBranco < 100)) {
    Serial.println("Azul");
    digitalWrite(pinoLedVerm, LOW);
    digitalWrite(pinoLedVerd, LOW);
    digitalWrite(pinoLedAzul, HIGH); //Acende o led azul

  } else if ((valorVerde < valorVermelho) &&  //Verifica se a cor verde foi detectada
             (valorVerde < valorAzul) &&
             (valorBranco < 100)) {
    Serial.println("Verde");
    digitalWrite(pinoLedVerm, LOW);
    digitalWrite(pinoLedVerd, HIGH); //Acende o led verde
    digitalWrite(pinoLedAzul, LOW);
  }
  Serial.println();

  //Delay para apagar os leds e reiniciar o processo
  delay(50);
  digitalWrite(pinoLedVerm, LOW);
  digitalWrite(pinoLedVerd, LOW);
  digitalWrite(pinoLedAzul, LOW);
}


// *********** Função de leitura so sensor de cor ********************
void detectaCor_esquerda() {
  //Vermelho
  digitalWrite(sensor_verde_esq_S2, LOW);
  digitalWrite(sensor_verde_esq_S3, LOW);
  valorVermelho_sensor_esquerdo = pulseIn(sensor_verde_esq_OUT, digitalRead(sensor_verde_esq_OUT) == HIGH ? LOW : HIGH);

  //Sem filtro
  digitalWrite(sensor_verde_dir_S2, HIGH);
  valorBranco_sensor_esquerdo = pulseIn(sensor_verde_esq_OUT, digitalRead(sensor_verde_esq_OUT) == HIGH ? LOW : HIGH);

  //Azul
  digitalWrite(sensor_verde_esq_S2, LOW);
  digitalWrite(sensor_verde_esq_S3, HIGH);
  valorAzul_sensor_esquerdo = pulseIn(sensor_verde_esq_OUT, digitalRead(sensor_verde_esq_OUT) == HIGH ? LOW : HIGH);

  //Verde
  digitalWrite(sensor_verde_esq_S2, HIGH);
  valorVerde_sensor_esquerdo = pulseIn(sensor_verde_esq_OUT, digitalRead(sensor_verde_esq_OUT) == HIGH ? LOW : HIGH);
}

void detectaCor_direita() {
  //Vermelho
  digitalWrite(sensor_verde_dir_S2, LOW);
  digitalWrite(sensor_verde_dir_S3, LOW);
  valorVermelho_sensor_direito = pulseIn(sensor_verde_dir_OUT, digitalRead(sensor_verde_dir_OUT) == HIGH ? LOW : HIGH);

  //Sem filtro
  digitalWrite(sensor_verde_dir_S2, HIGH);
  valorBranco_sensor_direito = pulseIn(sensor_verde_dir_OUT, digitalRead(sensor_verde_dir_OUT) == HIGH ? LOW : HIGH);

  //Azul
  digitalWrite(sensor_verde_dir_S2, LOW);
  digitalWrite(sensor_verde_dir_S3, HIGH);
  valorAzul_sensor_direito = pulseIn(sensor_verde_dir_OUT, digitalRead(sensor_verde_dir_OUT) == HIGH ? LOW : HIGH);

  //Verde
  digitalWrite(sensor_verde_dir_S2, HIGH);
  valorVerde_sensor_direito = pulseIn(sensor_verde_dir_OUT, digitalRead(sensor_verde_dir_OUT) == HIGH ? LOW : HIGH);
}