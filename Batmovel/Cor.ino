/**
  * Confiuração e funções respectivas sobre os sensores responsáveis pela detecção
  * de cores durante o run()
  *
  * - Última atualização
  * @date 18/05/2024
  */

/**
 * @brief Função para detectar curvas com base na cor verde detectada por sensores.
 * @details Nesta função, usamos dois sensores para detectar cores e decidindo se uma
            curva deve ser realizada com base nas cores detectadas.
 *          Se a cor verde for detectada em um dos sensores, o robô realizará uma curva na direção correspondente.
 */
void leitura_verde() {
  detectaCor_esquerda();
  detectaCor_direita();

  if (
    (valorAzul_sensor_esquerdo < valorVermelho_sensor_esquerdo) &&  //Verifica se a cor azul foi detectada
    (valorAzul_sensor_esquerdo < valorVerde_sensor_esquerdo) && (valorBranco_sensor_esquerdo < 100)) {
    //frear();
    if (
      (valorVerde_sensor_esquerdo < valorVermelho_sensor_esquerdo) &&  //Verifica se a cor verde foi detectada
      (valorVerde_sensor_esquerdo < valorAzul_sensor_esquerdo) && (valorBranco_sensor_esquerdo < 100)) {
      Serial.println("Curva com verde");
      curva_esquerda(velocidade_constate);
    }
    delay(250);
    Serial.println("Curva com verde");
    curva_esquerda(velocidade_constate);
  } else {
    Serial.println("Não é curva");
  }


  if (
    (valorAzul_sensor_direito < valorVermelho_sensor_direito) &&  //Verifica se a cor azul foi detectada
    (valorAzul_sensor_direito < valorVerde_sensor_direito) && (valorBranco_sensor_direito < 100)) {
    if (
      (valorVerde_sensor_direito < valorVermelho_sensor_direito) &&  //Verifica se a cor verde foi detectada
      (valorVerde_sensor_direito < valorAzul_sensor_direito) && (valorBranco_sensor_direito < 100)) {
      Serial.println("Curva com verde");
      curva_direita(velocidade_constate);
    }
    Serial.println("Curva com verde");
    curva_direita(velocidade_constate);
  } else {
    Serial.println("Não é curva");
  }
}

/**
 * @brief Realiza a leitura dos sensores de cor para detectar a presença da cor verde.
 */
void leitura_sensores_verde() {
  // Esquerda
  // Mostra valores no serial monitor
  Serial.print("Sensor Esquerdo -> ");
  Serial.print("Vermelho: ");
  Serial.print(valorVermelho_sensor_esquerdo);
  Serial.print(", Verde: ");
  Serial.print(valorVerde_sensor_esquerdo);
  Serial.print(", Azul: ");
  Serial.print(valorAzul_sensor_esquerdo);
  Serial.print(", Branco: ");
  Serial.println(valorBranco_sensor_esquerdo);

  // Verifica se a cor vermelha foi detectada
  if ((valorVermelho_sensor_esquerdo < valorAzul_sensor_esquerdo) && (valorVermelho_sensor_esquerdo < valorVerde_sensor_esquerdo) && (valorBranco_sensor_esquerdo < 100)) {
    Serial.println("Cor detectada: Vermelho");
  } else if ((valorAzul_sensor_esquerdo < valorVermelho_sensor_esquerdo) && (valorAzul_sensor_esquerdo < valorVerde_sensor_esquerdo) && (valorBranco_sensor_esquerdo < 100)) {
    Serial.println("Cor detectada: Azul");
  } else if ((valorVerde_sensor_esquerdo < valorVermelho_sensor_esquerdo) && (valorVerde_sensor_esquerdo < valorAzul_sensor_esquerdo) && (valorBranco_sensor_esquerdo < 100)) {
    Serial.println("Cor detectada: Verde");
  }
  Serial.println();

  // Delay para apagar os LEDs e reiniciar o processo
  delay(50);

  // Direita
  // Mostra valores no serial monitor
  Serial.print("Sensor Direito -> ");
  Serial.print("Vermelho: ");
  Serial.print(valorVermelho_sensor_direito);
  Serial.print(", Verde: ");
  Serial.print(valorVerde_sensor_direito);
  Serial.print(", Azul: ");
  Serial.print(valorAzul_sensor_direito);
  Serial.print(", Branco: ");
  Serial.println(valorBranco_sensor_direito);

  // Verifica se a cor vermelha foi detectada
  if ((valorVermelho_sensor_direito < valorAzul_sensor_direito) && (valorVermelho_sensor_direito < valorVerde_sensor_direito) && (valorBranco_sensor_direito < 100)) {
    Serial.println("Cor detectada: Vermelho");
  } else if ((valorAzul_sensor_direito < valorVermelho_sensor_direito) && (valorAzul_sensor_direito < valorVerde_sensor_direito) && (valorBranco_sensor_direito < 100)) {
    Serial.println("Cor detectada: Azul");
  } else if ((valorVerde_sensor_direito < valorVermelho_sensor_direito) && (valorVerde_sensor_direito < valorAzul_sensor_direito) && (valorBranco_sensor_direito < 100)) {
    Serial.println("Cor detectada: Verde");
  }
  Serial.println();

  // Delay para apagar os LEDs e reiniciar o processo
  delay(50);
}

/**
 * @brief Leitura dos sensores de cor do lado esquerdo para detectar as cores vermelha, azul, verde e branco.
 */
void detectaCor_esquerda() {
    // Vermelho
    digitalWrite(sensor_verde_esq_S2, LOW);
    digitalWrite(sensor_verde_esq_S3, LOW);
    valorVermelho_sensor_esquerdo = pulseIn(sensor_verde_esq_OUT, digitalRead(sensor_verde_esq_OUT) == HIGH ? LOW : HIGH);

    // Sem filtro
    digitalWrite(sensor_verde_dir_S2, HIGH);
    valorBranco_sensor_esquerdo = pulseIn(sensor_verde_esq_OUT, digitalRead(sensor_verde_esq_OUT) == HIGH ? LOW : HIGH);

    // Azul
    digitalWrite(sensor_verde_esq_S2, LOW);
    digitalWrite(sensor_verde_esq_S3, HIGH);
    valorAzul_sensor_esquerdo = pulseIn(sensor_verde_esq_OUT, digitalRead(sensor_verde_esq_OUT) == HIGH ? LOW : HIGH);

    // Verde
    digitalWrite(sensor_verde_esq_S2, HIGH);
    valorVerde_sensor_esquerdo = pulseIn(sensor_verde_esq_OUT, digitalRead(sensor_verde_esq_OUT) == HIGH ? LOW : HIGH);
}

/**
 * @brief Leitura dos sensores de cor do lado direito para detectar as cores vermelha, azul, verde e branco.
 */
void detectaCor_direita() {
    // Vermelho
    digitalWrite(sensor_verde_dir_S2, LOW);
    digitalWrite(sensor_verde_dir_S3, LOW);
    valorVermelho_sensor_direito = pulseIn(sensor_verde_dir_OUT, digitalRead(sensor_verde_dir_OUT) == HIGH ? LOW : HIGH);

    // Sem filtro
    digitalWrite(sensor_verde_dir_S2, HIGH);
    valorBranco_sensor_direito = pulseIn(sensor_verde_dir_OUT, digitalRead(sensor_verde_dir_OUT) == HIGH ? LOW : HIGH);

    // Azul
    digitalWrite(sensor_verde_dir_S2, LOW);
    digitalWrite(sensor_verde_dir_S3, HIGH);
    valorAzul_sensor_direito = pulseIn(sensor_verde_dir_OUT, digitalRead(sensor_verde_dir_OUT) == HIGH ? LOW : HIGH);

    // Verde
    digitalWrite(sensor_verde_dir_S2, HIGH);
    valorVerde_sensor_direito = pulseIn(sensor_verde_dir_OUT, digitalRead(sensor_verde_dir_OUT) == HIGH ? LOW : HIGH);
}
