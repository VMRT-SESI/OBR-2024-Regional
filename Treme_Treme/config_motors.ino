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

void curvaEsquerda(int velocidade) {
  motorA.run(velocidade);
  motorB.run(-velocidade);
}

void curvaDireita(int velocidade) {
  motorA.run(-velocidade);
  motorB.run(velocidade);
}

void meia_volta() {
  for (tempo = 0; tempo < 200; tempo++) {
    Serial.println(tempo);
    curvaDireita(150);
  }
  andar(0);
}

void curva_noventa_esquerda() {
  tempo = 0;
  for (tempo = 0; tempo < 110; tempo++) {
    curvaEsquerda(110);
  }
  parar();
  delay(1500);
}

void curva_noventa_direita() {
  tempo = 0;
  for (tempo = 0; tempo < 110; tempo++) {
    curvaDireita(110);
    Serial.println(tempo);
  }
  parar();
  delay(1500);
}