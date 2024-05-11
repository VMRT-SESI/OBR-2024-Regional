void segue_linha() {
  sensorExtDireita = analogRead(sensor1);
  sensorDireita = analogRead(sensor2);
  sensorMeio = analogRead(sensor3);
  sensorEsquerda = analogRead(sensor4);
  sensorExtDireita = analogRead(sensor5);

  //Serial.println(sensorEsquerda);
  if((sensorEsquerda > preto) && (sensorDireita > preto)) {
    //andarFrente(velocidade);
  }else if((sensorEsquerda < preto) && (sensorDireita > preto)) {
    if((sensorMeio > preto) && (sensorExtDireita > preto)) {
      //curvaDireita(velocidade);
    } else {
      //curvaDireita(velocidade);
    }
  } else if((sensorEsquerda > preto) && (sensorDireita < preto)){
    if((sensorMeio > preto) && (sensorEsquerda > preto) && (sensorExtEsquerda > preto)) {
      //curvaEsquerda(velocidade);
    } else {
      //curvaEsquerda(velocidade);
    }
  }  else if(
    (sensorExtEsquerda < preto) && 
    (sensorEsquerda < preto) && 
    (sensorMeio < preto) && 
    (sensorDireita < preto) && 
    (sensorExtDireita < preto)
    ) {
      //andarFrente(20);
      delay(2500);
      // andarFrente(velocidade);
      Serial.println("2");
  } else {
    // andarFrente(velocidade);
  }
}