#include "ToolClass.h"
#include "EasingLib.h"

class CustomPWM : public Tool
{
private:
    byte pin;
    byte state;
    Easing easing_function;
    bool busy;

public:
    CustomPWM(byte pin)
    {
        this->pin = pin;
        this->busy = false;
        pinMode(pin, OUTPUT);
        Easing easing_function(EASE_IN_OUT_CUBIC, 0);
        easing_function.SetSetpoint(0);
    }

    // RESET
    void reset()
    {
        this->state = 0;
        analogWrite(this->pin, this->state);
        easing_function.Init(this->state);
        delay(1);
        this->busy = false;
    }

    // GETTERS
    int getState()
    {
        return this->state;
    }

    // RUNNERS
    void run(int val)
    {
        if (!this->busy)
        {
            this->busy = true;
            if (val <= 100)
            {
                float real_val = float(val) / 100 * 255;
                analogWrite(this->pin, real_val);
                this->state = real_val;
                easing_function.Init(this->state);
                delay(1);
            }
            this->busy = false;
        }
    }

    void run(int val, int period)
    {
        if (!this->busy)
        {
            this->busy = true;
            // Transform 100% to 255 val.
            float real_val = float(val) / 100 * 255;

            // Set easing function - default
            easing_function.Init(this->state);
            easing_function.SetMillisInterval(period);

            for (uint32_t tStart = millis(); (millis() - tStart) <= period;)
            {
                analogWrite(this->pin, float(easing_function.SetSetpoint(real_val)));
                delay(1);
            }
            analogWrite(this->pin, real_val);
            this->state = real_val;
            this->busy = false;
        }
    }

    void run(int val, int period, int easing_type)
    {
        if (!this->busy)
        {
            this->busy = true;
            // Transform 100% to 255 val.
            float real_val = float(val) / 100 * 255;

            // Set easing function
            easing_function.Init(this->state);
            easing_function.SetMillisInterval(period);
            easing_function.SetMode(easing_type);

            for (uint32_t tStart = millis(); (millis() - tStart) <= period;)
            {
                analogWrite(this->pin, float(easing_function.SetSetpoint(real_val)));
                delay(1);
            }
            analogWrite(this->pin, real_val);
            this->state = real_val;
            this->busy = false;
        }
    }
};