#include "src/MecanumDriver.h"

MecanumDriver mecanum(9, 8, 12, 13, 11, 10, 46, 21);

char command = 'x'; // defalut command
unsigned long last_command_time = 0; // last time receive command
const unsigned long command_timeout = 100; // timeout unit:ms

void setup() {
    mecanum.begin();
    Serial.begin(115200);
}

void loop() {

    if (Serial.available() > 0) {
        char temp = char(Serial.read());
        if (temp != '\n' && temp != '\r') { 
            command = temp; // update command
            last_command_time = millis(); // record time when command received
        }
    }

    // execute
    if (command == 'w') {
        mecanum.setDutyCycle(100, 100, 100, 100); // forward
    } else if (command == 'a') {
        mecanum.setDutyCycle(-100, 100, -100, 100); // turn left
    } else if (command == 's') {
        mecanum.setDutyCycle(-100, -100, -100, -100); // backward
    } else if (command == 'd') {
        mecanum.setDutyCycle(100, -100, -100, 100); // turn right
    } else if (command == 'x') {
        mecanum.setDutyCycle(0, 0, 0, 0); // stop
    }

    // timeout check
    if (millis() - last_command_time > command_timeout) {
        command = 'x'; // stop
        mecanum.setDutyCycle(0, 0, 0, 0);
    }
}
