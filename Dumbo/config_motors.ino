/**
  *  Configurações dos estados que os motores podem apresentar durante a 
  *  execução do run()
  *
  * - Última atualização
  * @date 18/05/2024
  */

void setupMotors(int state) {
  if (state == 0) {
    motor_direita_frente.off();
    motor_direta_fundo.off();
    motor_esquerda_frente.off();
    motor_esquerda_fundo.off();
  } else {
    motor_direita_frente.on();
    motor_direta_fundo.on();
    motor_esquerda_frente.on();
    motor_esquerda_fundo.on();
  }
}

void andar_frente(int move) {
  motor_direita_frente.move(move);
  motor_direta_fundo.move(move);
  motor_esquerda_frente.move(move);
  motor_esquerda_fundo.move(move);
}

void reverso(int move) {
  motor_direita_frente.move(-move);
  motor_direta_fundo.move(-move);
  motor_esquerda_frente.move(-move);
  motor_esquerda_fundo.move(-move);
}

void frear() {
  motor_direita_frente.move(0);
  motor_direta_fundo.move(0);
  motor_esquerda_frente.move(0);
  motor_esquerda_fundo.move(0);
}

void curva_esquerda(int move) {
  motor_direita_frente.move(0);
  motor_direta_fundo.move(0);
  motor_esquerda_frente.move(move);
  motor_esquerda_fundo.move(move);
}

void curva_direita(int move) {
  motor_direita_frente.move(move);
  motor_direta_fundo.move(move);
  motor_esquerda_frente.move(0);
  motor_esquerda_fundo.move(0);
}