#include "ToolClass.h"
#include <AccelStepper.h>

class Stepper : public Tool
{
private:
    byte pin_1;
    byte pin_2;
    byte pin_3;
    byte pin_4;
    AccelStepper stepper;

public:
    Stepper(byte pin_1, byte pin_2)
    {
        this->pin_1 = pin_1;
        this->pin_2 = pin_2;
        this->stepper = (AccelStepper::FULL2WIRE, pin_1, pin_2);
    }

    Stepper(byte pin_1, byte pin_2, byte pin_3)
    {
        this->pin_1 = pin_1;
        this->pin_2 = pin_2;
        this->pin_3 = pin_3;
        this->stepper = (AccelStepper::FULL3WIRE, pin_1, pin_2, pin_3);
    }

    Stepper(byte pin_1, byte pin_2, byte pin_3, byte pin_4)
    {
        this->pin_1 = pin_1;
        this->pin_2 = pin_2;
        this->pin_3 = pin_3;
        this->pin_4 = pin_4;
        this->stepper = (AccelStepper::FULL4WIRE, pin_1, pin_2, pin_3, pin_4);
    }

    // RESET
    void reset(){
        //
    }

    // RUNNERS 
    void run(int a)
    {
        Serial.println("Stepper says hi");
    };

    void run(int a, int b)
    {
        Serial.println("Stepper says hi");
    };

    void run(int a, int b, int c)
    {
        Serial.println("Stepper says hi");
    };
};
