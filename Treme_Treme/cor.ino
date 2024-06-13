void leitura_verde() {
  //Detecta a cor
  detectaCor();

  //Mostra valores da esquerda no serial monitor
  // Serial.print("Vermelho :");
  // Serial.print(valorVermelhoE);

  // Serial.print(" Verde : ");
  // Serial.print(valorVerdeE);

  // Serial.print(" Azul : ");
  // Serial.print(valorAzulE);

  // Serial.print(" Branco : ");
  // Serial.print(valorBrancoE);
  // Serial.println();

  // //Mostra valores da direita no serial monitor
  // Serial.print("Vermelho :");
  // Serial.print(valorVermelhoD);

  // Serial.print(" Verde : ");
  // Serial.print(valorVerdeD);

  // Serial.print(" Azul : ");
  // Serial.print(valorAzulD);

  // Serial.print(" Branco : ");
  // Serial.print(valorBrancoD);
  // Serial.println();

  //Verifica se a cor vermelha foi detectada
  if (
    (valorVerdeE <= valorVermelhoE) &&
    (valorVerdeE < valorAzulE) &&
    (valorBrancoE < 110)
  ) {
    verde_esquerdo = 1;
  }else if(
    (valorVerdeE <= valorVermelhoE) &&
    (valorVerdeE > valorAzulE) &&
    (valorBrancoE > 50) && (valorBrancoE < 110)
  ){
    verde_esquerdo = 1;
  } else {
    verde_esquerdo = 0;
  }

if (
    (valorVerdeD <= valorVermelhoD) &&
    (valorVerdeD < valorAzulD) &&
    (valorBrancoD < 110)
  ) {
    verde_direito = 1;
  }else if(
    (valorVerdeD <= valorVermelhoD) &&
    (valorVerdeD > valorAzulD) &&
    (valorBrancoD > 50) && (valorBrancoE < 110)
  ){
    verde_direito = 1;
  } else {
    verde_direito = 0;
  }
  Serial.println();
  delay(50);
}

// *********** Função de leitura so sensor de cor ********************
void detectaCor() {
  //Vermelho esquerda
  digitalWrite(pinS2E, LOW);
  digitalWrite(pinS3E, LOW);
  valorVermelhoE = pulseIn(pinOutE, digitalRead(pinOutE) == HIGH ? LOW : HIGH);

  //Sem filtro esquerda
  digitalWrite(pinS2E, HIGH);
  valorBrancoE = pulseIn(pinOutE, digitalRead(pinOutE) == HIGH ? LOW : HIGH);

  //Azul esquerda
  digitalWrite(pinS2E, LOW);
  digitalWrite(pinS3E, HIGH);
  valorAzulE = pulseIn(pinOutE, digitalRead(pinOutE) == HIGH ? LOW : HIGH);

  //Verde esquerda
  digitalWrite(pinS2E, HIGH);
  valorVerdeE = pulseIn(pinOutE, digitalRead(pinOutE) == HIGH ? LOW : HIGH);

  //Vermelho direita
  digitalWrite(pinS2D, LOW);
  digitalWrite(pinS3D, LOW);
  valorVermelhoD = pulseIn(pinOutD, digitalRead(pinOutD) == HIGH ? LOW : HIGH);

  //Sem filtro direita
  digitalWrite(pinS2D, HIGH);
  valorBrancoD = pulseIn(pinOutD, digitalRead(pinOutD) == HIGH ? LOW : HIGH);

  //Azul direita
  digitalWrite(pinS2D, LOW);
  digitalWrite(pinS3D, HIGH);
  valorAzulD = pulseIn(pinOutD, digitalRead(pinOutD) == HIGH ? LOW : HIGH);

  //Verde direita
  digitalWrite(pinS2D, HIGH);
  valorVerdeD = pulseIn(pinOutD, digitalRead(pinOutD) == HIGH ? LOW : HIGH);
}
