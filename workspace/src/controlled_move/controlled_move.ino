#include "src/MecanumDriver.h"

MecanumDriver mecanum(9, 8, 12, 13, 11, 10, 46, 21);

String command;
String lastCommand = "x"; // 初始化为停止状态

void setup() { 
    mecanum.begin();
    Serial.begin(115200);
}

void loop() {
    while (Serial.available() > 0) {
        char temp = char(Serial.read());
        if (temp != '\n' && temp != '\r') { 
            command = temp; // 只保留最后一次有效指令
        }
    }

    if (command != lastCommand) { // 如果命令有变化，则执行
        if (command == "w") {
            mecanum.setDutyCycle(100, 100, 100, 100); // forward
        } else if (command == "a") {
            mecanum.setDutyCycle(-100, 100, -100, 100); // turn left
        } else if (command == "s") {
            mecanum.setDutyCycle(-100, -100, -100, -100); // backward
        } else if (command == "d") {
            mecanum.setDutyCycle(100, -100, 100, -100); // turn right
        } else if (command == "x") {
            mecanum.setDutyCycle(0, 0, 0, 0); // stop
        }

        lastCommand = command; // 更新上一次命令
    }
}
