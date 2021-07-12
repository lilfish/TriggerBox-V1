
#include <Servo.h>
#include <AccelStepper.h>
#include <TaskManager.h>
#include "ButtonClass.h"
#include "OledClass.h"
#include "PWMClass.h"
#include "RelayClass.h"
#include "StepperClass.h"

//Buttons
#define RESTART_BUTTON 53
#define RESET_BUTTON 52
#define PAUZE_BUTTON 51
#define CONTINUE_BUTTON 50
Button restart_button(RESTART_BUTTON);
Button reset_button(RESET_BUTTON);
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

// recieving data
const byte numChars = 32;
char receivedChars[numChars];
boolean newData = false;

String incomingString; // for incoming serial data

struct Instruction
{
    String tool;
    char type;
    double start;
    int val1;
    int val2;
    int val3;
};

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
        for (int i = 0; i < Tasks.size(); i++)
        {
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
        previousMillis = currentMillis;
        clear_screen = true;

        int instruction_counter = 0;

        char seperator = ',';
        char end_char = ';';
        char rc;
        String incoming = "";

        Instruction new_instruction = {};

        while (Serial.available() > 0)
        {
            rc = Serial.read();
            if (rc != seperator && rc != end_char)
            {
                incoming += rc;
            }
            else
            {
                switch (instruction_counter)
                {
                case 0:
                    new_instruction.tool = incoming;
                    break;
                case 1:
                    new_instruction.type = incoming[0];
                    break;
                case 2:
                    new_instruction.start = incoming.toDouble();
                    break;
                case 3:
                    new_instruction.val1 = incoming.toInt();
                    break;
                case 4:
                    new_instruction.val2 = incoming.toInt();
                    break;
                case 5:
                    new_instruction.val3 = incoming.toInt();
                    break;
                default:
                    oledd.clear();
                    oledd.displayText(0, 0, "Receiving");
                    oledd.displayText(0, 1, "to many");
                    oledd.displayText(0, 2, "instructions.");
                    previousMillis = currentMillis;
                    clear_screen = true;
                    break;
                }
                incoming = "";
                instruction_counter++;
            }
            if (rc == end_char)
            {
                Serial.flush();
                instruction_counter = 0;
            }
        }

        parseInstruction(new_instruction);
    }
    //    update tasks
    Tasks.update();
}

enum TypeNumber
{
    A,
    B,
    C,
    D,
    E,
    F,
    G
};
enum InstructionType
{
    STEPPER,
    SERVO,
    RELAY,
    PWM
};

int ConvertType(String input)
{
    if (input == "STEPPER")
        return STEPPER;
    else if (input == "SERVO")
        return SERVO;
    else if (input == "RELAY")
        return RELAY;
    else if (input == "PWM")
        return PWM;
}

int ConvertTypeNumber(String input)
{
    if (input == "A")
    {
        return A;
    }
    else if (input == "B")
        return B;
    else if (input == "C")
        return C;
    else if (input == "D")
        return D;
    else if (input == "E")
        return E;
    else if (input == "F")
        return F;
    else if (input == "G")
        return G;
}

void parseInstruction(Instruction new_instruction)
{

    InstructionType instruction_type = ConvertType(new_instruction.tool);
    TypeNumber instruction_type_number = ConvertTypeNumber(String(new_instruction.type));
    Serial.println("=New instruction===========");
    Serial.print(new_instruction.tool);
    Serial.print(",");
    Serial.print(new_instruction.type);
    Serial.print(",");
    Serial.print(new_instruction.start);
    Serial.print(",");
    Serial.print(new_instruction.val1);
    Serial.print(",");
    Serial.print(new_instruction.val2);
    Serial.print(",");
    Serial.println(new_instruction.val3);

    switch (instruction_type)
    {
    case STEPPER:
        Tasks.add([new_instruction, instruction_type_number]
                  {
                      Serial.print("My stepper ");
                      Serial.println(instruction_type_number);
                      //   mystepper[instruction_type_number]
                  })
            ->startOnceAfter(new_instruction.start);
        break;
    case SERVO:
        Tasks.add([new_instruction, instruction_type_number]
                  {
                      Serial.print("My servo ");
                      Serial.println(instruction_type_number);
                      myservo[instruction_type_number].write(new_instruction.val1);
                  })
            ->startOnceAfter(new_instruction.start);
        break;
    case RELAY:
        if (new_instruction.val1 == 1)
        {
            Tasks.add([instruction_type_number]
                      {
                          Serial.print("My relay ");
                          Serial.println(instruction_type_number);
                          myrelay[instruction_type_number]->turnOn();
                      })
                ->startOnceAfter(new_instruction.start);
        }
        else if (new_instruction.val1 == 0)
        {
            Tasks.add([instruction_type_number]
                      {
                          Serial.print("My relay ");
                          Serial.println(instruction_type_number);
                          myrelay[instruction_type_number]->turnOff();
                      })
                ->startOnceAfter(new_instruction.start);
        }

        break;
    case PWM:
        Tasks.add([new_instruction, instruction_type_number]
                  {
                      Serial.print("My PWM ");
                      Serial.println(instruction_type_number);
                      mypwm[instruction_type_number]->write(new_instruction.val1);
                  })
            ->startOnceAfter(new_instruction.start);
        break;
    default:
        Serial.println("Unknown instruction type");
        Serial.print(instruction_type);
        oledd.clear();
        oledd.displayText(0, 0, "Unkown instruction");
        oledd.displayText(0, 1, "type:" + String(instruction_type));
        previousMillis = millis();
        clear_screen = true;
        break;
    }

    Tasks.pause();
}
