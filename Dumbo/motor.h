/**
  * Classe dos motores 
  * @author Matheus Gabriel
  * @version 1.0
  * 
  * - Última atualização
  * @date 26/05/2024
*/

class motor {
private:
  byte motorPinIn1; // Pino para controle de direção horária
  byte motorPinIn2; // Pino para controle de direção anti-horária

public:
  /**
    * @brief Construtor da classe do motor
    * @param motorPinIn1: pino para controle de direção horária
    * @param motorPinIn2: pino para controle de direção anti-horária
    *
    * @example
    *   motor motorName(  
    *     8,      // motorPinIn1
    *     9       // motorPinIn2
    *   );
  */
  motor(byte motorPinIn1, byte motorPinIn2) {
    this->motorPinIn1 = motorPinIn1;
    this->motorPinIn2 = motorPinIn2;

    init();
  }

  /**
    *@brief Inicialização da classe
  */
  void init() {
    pinMode(motorPinIn1, OUTPUT);
    pinMode(motorPinIn2, OUTPUT);

    off();
  }

  void on() {
    digitalWrite(motorPinIn1, 1);
    digitalWrite(motorPinIn2, 1);
  }

  void off() {
    digitalWrite(motorPinIn1, 0);
    digitalWrite(motorPinIn2, 0);
  }

  void run(int move) {
    if (move < 0) {
      analogWrite(motorPinIn1, 0);
      analogWrite(motorPinIn2, move);
    } else {
      analogWrite(motorPinIn1, move);
      analogWrite(motorPinIn2, 0);
    }
  }
};