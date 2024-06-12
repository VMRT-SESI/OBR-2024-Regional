void segue_linha() {
  leitura_verde();

  sensorExtDireita = analogRead(sensor1);
  sensorDireita = analogRead(sensor2);
  sensorMeio = analogRead(sensor3);
  sensorEsquerda = analogRead(sensor4);
  sensorExtEsquerda = analogRead(sensor5);

  Serial.print(verde_direito);
  Serial.print(verde_esquerdo);
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
  // Todos os sensores a partir do meio para esquerda, estão vendo preto e verde 
  if (
    sensorMeio < preto && 
    sensorEsquerda < preto && 
    sensorExtEsquerda < preto && 
    verde_esquerdo == 1
  ) {
    curvaEsquerda(150);
    delay(2500);
  }

  // Todos os sensores a partir do meio para direita, estão vendo preto e verde 
  if (
    sensorMeio < preto && 
    sensorDireita < preto && 
    sensorExtDireita < preto && 
    verde_direito == 1
  ) {
    curvaEsquerda(150);
    delay(2500);
  }

  // Todos os sensores estão vendo o preto
  if (
    sensorExtDireita < preto && 
    sensorDireita < preto && 
    sensorMeio < preto && 
    sensorEsquerda < preto && 
    sensorExtEsquerda < preto
  ) {
    parar();
    delay(500);
    for (int i = 0; i < 60; i++) {
      andar(80);
    }
    parar();
    Serial.println(verde_direito);
    Serial.println(verde_esquerdo);
  }
}