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
  digitalWrite(led_leitura_preto_vermelho, HIGH);
  digitalWrite(led_curva_direita_vermelho, HIGH);
  digitalWrite(led_curva_esquerda_vermelho, HIGH);
  delay(2500);
  digitalWrite(led_leitura_preto_vermelho, LOW);
  digitalWrite(led_curva_direita_vermelho, LOW);
  digitalWrite(led_curva_esquerda_vermelho, LOW);
  delay(1000);
}