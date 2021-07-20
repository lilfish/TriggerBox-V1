#include "ToolClass.h"

class Relay : public Tool
{
private:
    byte pin;

public:
    Relay(byte pin)
    {
        this->pin = pin;
        pinMode(pin, OUTPUT);
    }

    // RESET
    void reset()
    {
        digitalWrite(this->pin, LOW);
    }
    
    // GETTERS
    void getState()
    {
        return digitalRead(this->pin);
    }

    // RUNNERS
    void run() {
        digitalWrite(this->pin, !digitalRead(this->pin));
    }
    
    void run(int state) {
        digitalWrite(this->pin, state);
    }
};