#include "ToolClass.h"
#include "EasingLib.h"
#include <Servo.h>

class CustomServo : public Tool
{
private:
  byte pin;
  Servo servo;
  Easing easing_function;
  bool busy;

public:
  CustomServo(byte pin)
  {
    this->pin = pin;
    this->busy = false;
    servo.attach(pin);
    servo.write(0);
    Easing easing_function(EASE_IN_OUT_CUBIC, 0);
    easing_function.Init(0);
  };

  // RESET
  void reset()
  {
    servo.write(0);
    easing_function.Init(this->getPosition());
    delay(1);
    this->busy = false;
  }

  // GETTERS
  int getPosition()
  {
    return servo.read();
  };

  // RUNNERS
  void run(int val)
  {
    if (!this->busy)
    {
      this->busy = true;
      servo.write(val);
      easing_function.Init(this->getPosition());
      delay(1);
      this->busy = false;
    }
  };

  void run(int val, int period)
  {
    if (!this->busy)
    {
      this->busy = true;
      // Set easing function - default
      easing_function.Init(this->getPosition());
      easing_function.SetMillisInterval(period);

      for (uint32_t tStart = millis(); (millis() - tStart) <= period;)
      {
        servo.write(float(easing_function.SetSetpoint(val)));
      }
      servo.write(val);
      this->busy = false;
    }
  }

  void run(int val, int period, int easing_type)
  {
    if (!this->busy)
    {
      this->busy = true;
      // Set easing function
      easing_function.Init(this->getPosition());
      easing_function.SetMillisInterval(period);
      easing_function.SetMode(easing_type);

      for (uint32_t tStart = millis(); (millis() - tStart) <= period;)
      {
        servo.write(float(easing_function.SetSetpoint(val)));
      }
      servo.write(val);
      this->busy = false;
    }
  }
};
