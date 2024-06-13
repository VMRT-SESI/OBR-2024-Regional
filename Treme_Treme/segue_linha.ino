void segue_linha() {
  leitura_verde();

  sensorExtDireita = analogRead(sensor1);
  sensorDireita = analogRead(sensor2);
  sensorMeio = analogRead(sensor3);
  sensorEsquerda = analogRead(sensor4);
  sensorExtEsquerda = analogRead(sensor5);

  //Serial.print(sensorExtEsquerda);
  Serial.println();

  if (sensorDireita > preto && sensorEsquerda > preto) {
    andar(velocidade);
  } else if (sensorDireita < preto && sensorEsquerda > preto) {
    curvaDireita(90);
  } else if (sensorDireita > preto && sensorEsquerda < preto) {
    curvaEsquerda(90);
  } else {
    andar(velocidade);
  }

  identifica_casos();
}

void identifica_casos() {
  leitura_verde();
  // Todos os sensores a partir do meio para esquerda, estão vendo preto e verde 
  if (
    sensorEsquerda < preto && 
    sensorExtEsquerda < preto && 
    verde_esquerdo == 1
  ) {
    Serial.println("Curva esquerda com verde");
    curva_noventa_direita();
    delay(2000);
  }

  // Todos os sensores a partir do meio para direita, estão vendo preto e verde 
  if (
    sensorDireita < preto && 
    sensorExtDireita < preto && 
    verde_direito == 1
  ) {
    Serial.println("Curva esquerda com verde");
    curva_noventa_esquerda();
    delay(2500);
  }

  // Todos os sensores estão vendo o preto
  if (
    sensorExtDireita < preto && 
    sensorDireita < preto && 
    sensorMeio < preto && 
    sensorEsquerda < preto && 
    sensorExtEsquerda < preto &&
    verde_direito == 1 &&
    verde_esquerdo == 1
  ) {
    meia_volta();
  } else if (
    sensorExtDireita < preto && 
    sensorDireita < preto && 
    sensorMeio < preto && 
    sensorEsquerda < preto && 
    sensorExtEsquerda < preto &&
    verde_direito == 1
  ) {
    Serial.println("Curva esquerda com verde");
    curva_noventa_esquerda();
    delay(2500);

  } else if (
    sensorExtDireita < preto && 
    sensorDireita < preto && 
    sensorMeio < preto && 
    sensorEsquerda < preto && 
    sensorExtEsquerda < preto &&
    verde_esquerdo == 1
  ) {
    Serial.println("Curva esquerda com verde");
    curva_noventa_direita();
    delay(2500);
  } else if (
    sensorExtDireita < preto && 
    sensorDireita < preto && 
    sensorMeio < preto && 
    sensorEsquerda < preto && 
    sensorExtEsquerda < preto
  ) {
    andar(100);
  }
}