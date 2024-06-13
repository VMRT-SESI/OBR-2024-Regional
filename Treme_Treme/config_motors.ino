/**
  * Configuração dos estados que o motor apresenta durante a execução do run()
  *
  * - Última atualização
  * @date 26/05/2024
*/

void andar(int velocidade) {
  motorA.run(velocidade);
  motorB.run(velocidade);
}

void parar() {
  motorA.off();
  motorB.off();
}

void curvaEsquerda(int velocidade){
  motorA.run(velocidade);
  motorB.run(-velocidade);
}

void curvaDireita(int velocidade){
  motorA.run(-velocidade);
  motorB.run(velocidade);
}

void meia_volta() {
  for(tempo = 0; tempo < 200; tempo++){
    Serial.println(tempo);
    curvaDireita(150);
  }
  andar(0);
}

void curva_noventa_esquerda() {
  for(tempo = 0; tempo < 90; tempo++){
    curvaEsquerda(100);
  }
  
}

void curva_noventa_direita() {
  for(tempo = 0; tempo < 110; tempo++){
    curvaDireita(150);
  }
}