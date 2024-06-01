void segue_linha() {
  sensorExtDireita = analogRead(sensor1);
  sensorDireita = analogRead(sensor2);
  sensorMeio = analogRead(sensor3);
  sensorEsquerda = analogRead(sensor4);
  sensorExtDireita = analogRead(sensor5);

  if((sensorEsquerda > preto) && (sensorDireita > preto)) {
    andar(velocidade_constate);
  } else if((sensorEsquerda < preto) && (sensorDireita > preto)) {
    leitura_verde();

    if((sensorMeio > preto) && (sensorExtDireita > preto)) {
      curva_direita_eixo(velocidade_curva);
    } else {
      curva_direita(velocidade_curva);
    }
  } else if((sensorEsquerda > preto) && (sensorDireita < preto)){
    if((sensorMeio > preto) && (sensorEsquerda > preto) && (sensorExtEsquerda > preto)) {
      leitura_verde();

      curva_esquerda_eixo(velocidade_curva);
    } else {
      curva_esquerda(velocidade_curva);
    }
  }  else if(
    (sensorExtEsquerda < preto) && 
    (sensorEsquerda < preto) && 
    (sensorMeio < preto) && 
    (sensorDireita < preto) && 
    (sensorExtDireita < preto)
    ) {
      andar(20);
      leitura_verde();
      delay(2500);
      andar(velocidade_constate);
  } else {
    andar(velocidade_constate);
  }
}