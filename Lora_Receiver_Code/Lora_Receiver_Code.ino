#include <SPI.h>
#include <LoRa.h>

const int RightMotorF = 4;
const int RightMotorB = 5;
const int LeftMotorF = 6;
const int LeftMotorB = 7;

String msg = "";

void setup() {
  pinMode(RightMotorF, OUTPUT);
  pinMode(RightMotorB, OUTPUT);
  pinMode(LeftMotorF, OUTPUT);
  pinMode(LeftMotorB, OUTPUT);
  Serial.begin(9600);
  while (!Serial)
    ;

  Serial.println("LoRa Receiver");

  if (!LoRa.begin(433E6)) {
    Serial.println("Starting LoRa failed!");
    while (1)
      ;
  }
}

void loop() {

  int packetSize = LoRa.parsePacket();
  if (packetSize) {

    while (LoRa.available()) {
      Serial.print((char)LoRa.read());
      msg = (char)LoRa.read();
      Serial.println(msg);
      if (msg == "f") {
        digitalWrite(RightMotorB, LOW);
        digitalWrite(LeftMotorB, LOW);
        digitalWrite(RightMotorF, HIGH);
        digitalWrite(LeftMotorF, HIGH);

        Serial.println("Motor forward");
      } else if (msg == "b") {
        digitalWrite(RightMotorB, HIGH);
        digitalWrite(LeftMotorB, HIGH);
        digitalWrite(RightMotorF, LOW);
        digitalWrite(LeftMotorF, LOW);

        Serial.println("Motor Backward");
      } else if (msg == "l") {
        digitalWrite(RightMotorB, LOW);
        digitalWrite(LeftMotorB, HIGH);
        digitalWrite(RightMotorF, HIGH);
        digitalWrite(LeftMotorF, LOW);
        Serial.println("Left");
        delay(300);
        digitalWrite(RightMotorB, LOW);
        digitalWrite(LeftMotorB, LOW);
        digitalWrite(RightMotorF, LOW);
        digitalWrite(LeftMotorF, LOW);
      } else if (msg == "r") {
        digitalWrite(RightMotorB, HIGH);
        digitalWrite(LeftMotorB, LOW);
        digitalWrite(RightMotorF, LOW);
        digitalWrite(LeftMotorF, HIGH);
        Serial.println("right");
        delay(300);
        digitalWrite(RightMotorB, LOW);
        digitalWrite(LeftMotorB, LOW);
        digitalWrite(RightMotorF, LOW);
        digitalWrite(LeftMotorF, LOW);
      }
    }
  }
}