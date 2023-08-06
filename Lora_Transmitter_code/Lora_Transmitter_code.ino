//https://justdoelectronics.com
//https://www.youtube.com/@JustDoElectronics/videos

#include <SPI.h>
#include <LoRa.h>

int counter = 0;
int up_button = 4;
int down_button = 5;
int left_button = 6;
int right_button = 7;
int buttons[] = { up_button, down_button, left_button,
                  right_button };

void setup() {
  Serial.begin(9600);
  for (int i; i < 4; i++) {
    pinMode(buttons[i], INPUT);
    digitalWrite(buttons[i], HIGH);
  }

  while (!Serial);
  Serial.println("LoRa Sender");

  if (!LoRa.begin(433E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
  LoRa.setTxPower(20);
}

void loop() {

  if (digitalRead(up_button) == LOW) {
    LoRa.beginPacket();
    LoRa.print("f");
    Serial.println("UP Button Pressed");
    delay(300);
    LoRa.endPacket();

  } else if (digitalRead(down_button) == LOW) {
    LoRa.beginPacket();
    LoRa.print("b");
    Serial.println("down Button Pressed");
    delay(300);
    LoRa.endPacket();
  } else if (digitalRead(left_button) == LOW) {
    LoRa.beginPacket();
    LoRa.print("l");
    Serial.println("left Button Pressed");
    delay(300);
    LoRa.endPacket();

  } else if (digitalRead(right_button) == LOW) {
    LoRa.beginPacket();
    LoRa.print("r");
    Serial.println("right Button Pressed");
    delay(300);
    LoRa.endPacket();
  }


  counter++;

  // delay(5000);
}