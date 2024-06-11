void segue_linha() {
  leitura_verde();

  sensorExtDireita = analogRead(sensor1);
  sensorDireita = analogRead(sensor2);
  sensorMeio = analogRead(sensor3);
  sensorEsquerda = analogRead(sensor4);
  sensorExtDireita = analogRead(sensor5);

  Serial.println(sensorExtDireita);

  if (sensorDireita > preto && sensorEsquerda > preto) {
    andar(velocidade);
  } else if (sensorDireita < preto && sensorEsquerda > preto) {
    curvaDireita(115);
  } else if (sensorDireita > preto && sensorEsquerda < preto) {
    curvaEsquerda(115);
  } else {
    andar(velocidade);
  }

  // Serial.println(verde_direito);
  // Serial.println(verde_esquerdo);

  // if (verde_esquerdo == 1) {
  //   ledVermE.on();
  //   ledMeio.on();
  //   curva_noventa_esquerda();
  // } else if (verde_direito == 1) {
  //   ledVermD.on();
  //   ledMeio.on();
  //   curva_noventa_direita();
  // } else if ((verde_esquerdo == 1) && (verde_direito == 1)) {
  //   ledVermE.on();
  //   ledVermD.on();
  //   ledMeio.on();
  //   meia_volta();
  // } else {
  //   parar();
  // }
}