#include "ToolClass.h"
#include <Servo.h>

class CustomServo : public Tool
{
private:
  byte pin;
  Servo servo;

public:
  CustomServo(byte pin)
  {
    this->pin = pin;
    servo.attach(pin);
  };

  void setAngle(int angle)
  {
    servo.write(angle);
    Serial.println(angle);
  };

  int getPosition()
  {
    return servo.read();
  };
};
