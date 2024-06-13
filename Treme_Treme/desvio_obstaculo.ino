void devioObstaculo() {
  tempo = 0;
  delay(500);
  while (tempo != 110) {
    curva_noventa_direita();
  }

  delay(500);
  tempo = 0;
  while (tempo != 125) {
    andar(100);
    Serial.println(tempo);
    tempo++;
  }

  delay(500);
  tempo = 0;
  curvaEsquerda(100);
  delay(1500);

  while (tempo != 275) {
    andar(100);
    Serial.println(tempo);
    tempo++;
  }

  curvaEsquerda(100);
  delay(1500);

  tempo = 0;
  while (tempo != 150) {
    andar(120);
    Serial.println(tempo);
    tempo++;
  }
  curvaDireita(100);
  delay(1500);
  parar();

  EstadoAtual = estado_segue_linha;
}