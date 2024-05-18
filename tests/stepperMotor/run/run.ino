#include "stepperMotor.h"

int velocidade = 75;

stepperMotor motorX (
  2,     // Step pin
  5,     // Direction pin
  8,     // Enable pin
  400,   // Resolution
  4490,  // Minimum velocity
  256    // Maximum velocity
);

stepperMotor motorY (
  3,     // Step pin
  6,     // Direction pin
  8,     // Enable pin
  400,   // Resolution
  4490,  // Minimum velocity
  256    // Maximum velocity
);

stepperMotor motorZ (
  4,     // Step pin
  7,     // Direction pin
  8,     // Enable pin
  400,   // Resolution
  4490,  // Minimum velocity
  256    // Maximum velocity
);

stepperMotor motorA (
  12,    // Step pin
  13,    // Direction pin
  8,     // Enable pin
  400,   // Resolution
  4490,  // Minimum velocity
  256    // Maximum velocity
);

void setup() {
  Serial.begin(115200);
}

void loop() {
  motorX.set(velocidade);
  motorY.set(velocidade);
  motorZ.set(velocidade);
  motorA.set(velocidade);

  motorX.run();
  motorY.run();
  motorZ.run();
  motorA.run();

  delay(2500);
}
