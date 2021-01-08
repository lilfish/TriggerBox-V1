

#include "ButtonClass.h"
#include "OledClass.h"

#define BUTTON_PIN 22



Button button1(BUTTON_PIN);
Oled oledd;
  
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); 
  Serial.println("STARTED");
  oledd.init();
}

void loop() {
  if (button1.isPressed()) {
    Serial.println("HOI");
    oledd.displayText("HOI5667");
  } else {
    Serial.println("HOI2");
    oledd.displayText("HOI123");
  }
  delay(100);

}
