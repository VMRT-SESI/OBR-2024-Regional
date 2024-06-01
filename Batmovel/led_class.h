class led {
  private:
  byte led_pin;       // Pino do LED

  public:
  /**
    * @brief Construtor da classe de LED
    * @param led_pin : pino digital do LED
    *
    * @example
    *   led led_Example(
    *     3           // Pino do LED
    *   )
  */
  led(byte led_pin) {
    this -> led_pin = led_pin;

    init();
  } 

  /**
    * @brief Inicialização do LED
  */
  void init() {
    pinMode(led_pin, OUTPUT);
    off();
  }

  /**
    * @brief LED ligado
  */
  void on() {
    digitalWrite(led_pin, 1);
  }

  /**
    * @brief LED desligado
  */
  void off() {
    digitalWrite(led_pin, 0);
  }

  /**
    * @brief LED alterna seu estado de on() e off() num intervalo de 250ms
  */
  void blink() {
    on();
    delay(250);
    off();
    delay(250);
  }

  /**
    * @brief LED fica acesso por um número especificado de vezes.
    *       
    * @param pulse O número de vezes que o LED deve piscar.
  */
  void pulse(int pulse) {
    for(int i = 0; i < pulse; i++){
      on();
    }
    delay(250);
    off();
  }
};