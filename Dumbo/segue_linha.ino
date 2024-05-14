void segue_linha() {
  sensorExtDireita = analogRead(sensor1);
  sensorDireita = analogRead(sensor2);
  sensorMeio = analogRead(sensor3);
  sensorEsquerda = analogRead(sensor4);
  sensorExtDireita = analogRead(sensor5);

  if((sensorEsquerda > preto) && (sensorDireita > preto)) {
    andar_frente(velocidade_constate);
  }else if((sensorEsquerda < preto) && (sensorDireita > preto)) {
    if((sensorMeio > preto) && (sensorExtDireita > preto)) {
      curva_direita(velocidade_curva);
    } else {
      curva_direita(velocidade_curva);
    }
  } else if((sensorEsquerda > preto) && (sensorDireita < preto)){
    if((sensorMeio > preto) && (sensorEsquerda > preto) && (sensorExtEsquerda > preto)) {
      curva_esquerda(velocidade_curva);
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
      andar_frente(20);
      delay(2500);
      andar_frente(velocidade_constate);
  } else {
    andar_frente(velocidade_constate);
  }
}