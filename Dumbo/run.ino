// Logíca prncipal executada pelo robô, identificando casos e realizando as ações

void run() {
  while (!verifica_regate) {
    GiroY = leitura_angulo_Y();
    GiroZ = leitura_angulo_Z();

    segue_linha();

    if (distancia_frente() < 10) {
      // Deviar de obstáculo
    }

    if (GiroY > 60) {
      verifica_rampa = true;
      if (distancia_lateral_direita < 20 && distancia_lateral_esquerda < 20) {
        // Rampa resgate
        // Aumentar um pouco a velocidade com a necessidade da garra abaixada
        // Deteccta Resgate - retornando true/fase (verifica_regate)
      } else {
        // Gangorra ou rampa comum
        // Diminir velocidade sem necessidade de abaixar garra -
      }
    } else
    {
      verifica_rampa = false;
    }
  }

  // Detecção sucessida da rampa de resgate - verifica_regate = true - e acionamento do modo de resgate
}

void aguardo() {
  led_blink(led_leitura_preto_vermelho);
  led_blink(led_curva_direita_vermelho);
  led_blink(led_curva_esquerda_vermelho);
}