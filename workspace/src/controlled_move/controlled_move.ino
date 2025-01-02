#include "src/MecanumDriver.h"

MecanumDriver mecanum(9, 8, 12, 13, 11, 10, 46, 21);

String command;

void setup() { // init mecanum car
  mecanum.begin();

  // start serial; set baudrate at 115200
  Serial.begin(115200);
}

void loop() {
  while (Serial.available() > 0) {

    // read command from serial
    char temp = char(Serial.read());
    command += temp;
  }
  if (command == "w") {
    mecanum.setDutyCycle(100, 100, 100, 100);
    delay(50);
    mecanum.setDutyCycle(0, 0, 0, 0);
  }
  if (command == "a") {
    mecanum.setDutyCycle(-100, 100, -100, 100);
    delay(50);
    mecanum.setDutyCycle(0, 0, 0, 0);
  }
}