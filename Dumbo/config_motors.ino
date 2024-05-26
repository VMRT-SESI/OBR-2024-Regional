/**
  * Configuração dos estados que o motor apresenta durante a execução do run()
  *
  * - Última atualização
  * @date 26/05/2024
*/

void andar(int move) {
  motorLeft.run(move);
  motorRight.run(move);
}

// Curva esquerda

void curva_esquerda(int move) {
  motorLeft.run(move);
  motorRight.off();
}

void curva_esquerda_eixo(int move) {
  motorLeft.run(move);
  motorRight.run(-move);
}

void curva_esqueda_gyro(int move, int grau_alvo) {
  GiroY = 0.0;

  while(GiroY != grau_alvo){
    curva_esquerda_eixo(move);
  }
}

// Curva direita

void curva_direita(int move) {
  motorLeft.off();
  motorRight.run(move);
}

void curva_direita_eixo(int move) {
  motorLeft.run(move);
  motorRight.run(-move);
}

void curva_direita_gyro(int move, int grau_alvo) {
  GiroY = 0.0;

  while(GiroY != grau_alvo){
    curva_direita_eixo(move);
  }
}