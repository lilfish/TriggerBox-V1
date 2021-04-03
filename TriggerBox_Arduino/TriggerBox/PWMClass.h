class PWM
{
private:
    byte pin;
    byte state;

public:
    PWM(byte pin)
    {
        this->pin = pin;
        pinMode(pin, OUTPUT);
    }
    void off(void)
    {
        analogWrite(pin, 0);
        state = 0;
    }

    void write(int procent)
    {
        analogWrite(pin, (255 / 100 * procent));
        state = procent;
    }

    int getState()
    {
        return state;
    }
    
};