// Logíca prncipal executada pelo robô, identificando casos e realizando as ações

void run() {
  while (!verifica_regate) {
    segue_linha();

    if (distancia_frente() < 50) {
      // Deviar de obstáculo
    }
  }
}

void aguardo() {
  led_blink(led_leitura_preto_vermelho);
  led_blink(led_curva_direita_vermelho);
  led_blink(led_curva_esquerda_vermelho);
}