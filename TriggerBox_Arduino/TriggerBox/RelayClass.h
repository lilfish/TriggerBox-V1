class Relay
{
private:
    byte pin;

public:
    Relay(byte pin)
    {
        this->pin = pin;
        pinMode(pin, OUTPUT);
    }
    void toggle(void)
    {
        digitalWrite(pin, !digitalRead(pin));
    }
    
    bool turnOn()
    {
        if(digitalRead(pin) == LOW){
            digitalWrite(pin, HIGH);
            return true;
        }
        return false;
    }

    bool turnOff()
    {
        if(digitalRead(pin) == HIGH){
            digitalWrite(pin, LOW);
            return true;
        }
        return false;
    }

    void getState()
    {
        return digitalRead(pin);
    }

};