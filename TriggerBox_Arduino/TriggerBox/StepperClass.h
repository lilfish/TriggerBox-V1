class Stepper
{
private:
    byte pin;

public:
    Stepper(byte pin)
    {
        this->pin = pin;
        pinMode(pin, OUTPUT);
    }
};
