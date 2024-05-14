/* Configurações gerais em relação ao funcionamento/modos leds que podem apresentadar 
   diferentes estados durante o run();
*/

const int time = 2500;

void led_on(int pin){
  digitalWrite(pin, HIGH);
}

void led_off(int pin){
  digitalWrite(pin, LOW);
}

void led_blink(int pin) {
  digitalWrite(pin, HIGH);
  delay(time);
  digitalWrite(pin, LOW);
}
