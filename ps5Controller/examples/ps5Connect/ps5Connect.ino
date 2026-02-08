#include <ps5Controller.h>

void setup() {
  Serial.begin(115200);

  ps5.begin("4c:b9:9b:3b:fd:e5"); //replace with MAC address of your controller
  Serial.println("Ready.");
}

void loop() {
  if (ps5.isConnected()) {
    Serial.println("Connected!");
  }

  delay(3000);
}
