
#include <Servo.h>
#include <AccelStepper.h>
#include <TaskManager.h>
#include "ButtonClass.h"
#include "OledClass.h"
#include "PWMClass.h"
#include "RelayClass.h"
#include "StepperClass.h"

//Buttons
#define restart_button 53
#define reset_button 52
#define PAUZE_BUTTON 51
#define CONTINUE_BUTTON 50
Button restart_button(restart_button);
Button reset_button(reset_button);
Button pauze_button(PAUZE_BUTTON);
Button continue_button(CONTINUE_BUTTON);

//Amount of...
#define SERVOS 6
#define STEPPERS 6
#define STEPPER_PINS 4
#define RELAYS 6
#define PWMS 4

// # Servo's
int servo_pins[SERVOS] = {2, 3, 4, 5, 6, 7};
Servo myservo[SERVOS];

// # Stepper's
int stepper_pins[STEPPERS][STEPPER_PINS] = {{15, 14}, {13, 12, 1, 1}, {11, 10}, {9, 8}, {7, 6}, {5, 4, 3, 2}};
AccelStepper *mystepper[STEPPERS];

// # Relays
int relay_pins[RELAYS] = {3, 5, 6, 9, 10, 11};
Relay *myrelay[RELAYS];

// # PWM same way
int pwm_pins[PWMS] = {3, 5, 6, 1};
PWM *mypwm[PWMS];
// # Oled
Oled oledd;

// for clearing the oledd screen after 2 seconds
long previousMillis = 0;
long screen_interval = 2000;
boolean clear_screen = false;

String incomingString; // for incoming serial data

void setup()
{
    Serial.begin(9600);
    // Init servo's
    for (int i = 0; i < SERVOS; i++)
    {
        myservo[i].attach(servo_pins[i]);
    }
    // Init steppers
    for (int i = 0; i < STEPPERS; i++)
    {
        int stepper_size = 0;
        for (int y = 0; y < STEPPER_PINS; y++)
        {
            if (stepper_pins[i][y] > 0)
            {
                stepper_size++;
            }
        }
        switch (stepper_size)
        {
        case 2:
            mystepper[i] = (AccelStepper::FULL2WIRE, stepper_pins[i][0], stepper_pins[i][1]);
            // AccelStepper stepper3(AccelStepper::FULL2WIRE, stepper_pins[i][0], stepper_pins[i][1]);
            break;
        case 3:
            mystepper[i] = (AccelStepper::FULL3WIRE, stepper_pins[i][0], stepper_pins[i][1], stepper_pins[i][2]);
            // AccelStepper stepper3(AccelStepper::FULL3WIRE, stepper_pins[i][0], stepper_pins[i][1], stepper_pins[i][2]);
            break;
        case 4:
            mystepper[i] = (AccelStepper::FULL4WIRE, stepper_pins[i][0], stepper_pins[i][1], stepper_pins[i][2], stepper_pins[i][3]);
            // AccelStepper stepper2(AccelStepper::FULL4WIRE, stepper_pins[i][0], stepper_pins[i][1], stepper_pins[i][2], stepper_pins[i][3]);
            break;
        default:
            // statements
            break;
        }

        mystepper[i] = (1);
    }
    // Init relay's
    for (int i = 0; i < RELAYS; i++)
    {
        myrelay[i] = (i);
    }
    // Init pwm's
    for (int i = 0; i < PWMS; i++)
    {
        mypwm[i] = (i);
    }
    // start oled scherm
    oledd.init();
    oledd.clear();

    // start seriale communicatie
    Serial.println("TriggerBox v1 started");
    oledd.displayText(0, 0, "TriggerBox v1");
    oledd.displayText(0, 1, "active");
    previousMillis = millis();
    clear_screen = true;

//    Tasks.add("test", [] {
//        Serial.println("Hello, World");
//    })->startInterval(1);                // call this function in 1[fps]
    Tasks.add("test2", [] {
        Serial.println("Hello, World xD");
    })->startOnceAfter(5);                // call this function in 1[fps]
    Tasks.pause();
}

void loop()
{
    unsigned long currentMillis = millis();
    // Check buttons
    if (restart_button.isPressed())
    {
        Serial.println("Restart button pressed.");
        oledd.clear();
        oledd.displayText(0, 0, "Restart button");
        oledd.displayText(0, 1, "pressed.");
        while (restart_button.isPressed())
        {
            delay(50);
        }
        Tasks.setTime(0);
        Tasks.play();
        previousMillis = currentMillis;
        clear_screen = true;
    }
    else if (reset_button.isPressed())
    {
        Serial.println("Reset button pressed.");
        oledd.clear();
        oledd.displayText(0, 0, "Reset button");
        oledd.displayText(0, 1, "pressed.");
        while (reset_button.isPressed())
        {
            delay(50);
        }
        for(int i = 0; i < Tasks.size(); i++){
          Tasks.erase(i);
        }
        previousMillis = currentMillis;
        clear_screen = true;
    }
    else if (pauze_button.isPressed())
    {
        Serial.println("Pauze button pressed.");
        oledd.clear();
        oledd.displayText(0, 0, "Pauze button");
        oledd.displayText(0, 1, "pressed.");
        while (pauze_button.isPressed())
        {
            delay(50);
        }
        Tasks.pause();
        previousMillis = currentMillis;
        clear_screen = true;
    }
    else if (continue_button.isPressed())
    {
        Serial.println("Continue button pressed.");
        oledd.clear();
        oledd.displayText(0, 0, "Continue button");
        oledd.displayText(0, 1, "pressed.");
        while (continue_button.isPressed())
        {
            delay(50);
        }
        Tasks.play();
        previousMillis = currentMillis;
        clear_screen = true;
    }

    // Clear screen
    if (clear_screen && currentMillis - previousMillis > screen_interval)
    {
        oledd.clear();
        clear_screen = false;
    }

    // Read serial
    if (Serial.available() > 0)
    {
        oledd.clear();
        oledd.displayText(0, 0, "Receiving");
        oledd.displayText(0, 1, "instructions.");
        while (Serial.available() > 0)
        {
            // read the incoming byte:
            incomingString = Serial.readString();
            // say what you got:
            Serial.println("I received: ");
            Serial.println(incomingString);
            if(incomingString == "start"){
              Tasks.start();
            }
        }
        previousMillis = currentMillis;
        clear_screen = true;
    }
    Tasks.update();
}
