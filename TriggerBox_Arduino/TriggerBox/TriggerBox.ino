
#include <TaskManager.h>
#include "ButtonClass.h"
#include "OledClass.h"
#include "PWMClass.h"
#include "RelayClass.h"
#include "StepperClass.h"
#include "CustomServo.h"
#include "ToolClass.h"

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
CustomServo *myservo[SERVOS];

// # Stepper's
int stepper_pins[STEPPERS][STEPPER_PINS] = {{A15, A14}, {A13, A12}, {A11, A10}, {A9, A8}, {A7, A6}, {A5, A4}};
Stepper *mystepper[STEPPERS];

// # Relays
int relay_pins[RELAYS] = {49, 48, 47, 46 };
Relay *myrelay[RELAYS];

// # PWM same way
int pwm_pins[PWMS] = {8, 9, 10, 11};
PWM *mypwm[PWMS];

// # All tools
Tool *tools_array[4][6];

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


void setup()
{
    Serial.begin(9600);
    // Init steppers
    for (int i = 0; i < STEPPERS; i++)
    {
        int stepper_size = 0;
        for (int y = 0; y < STEPPER_PINS; y++)
        {
            if (stepper_pins[STEPPER][y] > 0)
            {
                stepper_size++;
            }
        }
        switch (stepper_size)
        {
        case 2:
            mystepper[i] = new Stepper(stepper_pins[i][0], stepper_pins[i][1]);
            break;
        case 3:
            mystepper[i] = new Stepper(stepper_pins[i][0], stepper_pins[i][1], stepper_pins[i][2]);
            break;
        case 4:
            mystepper[i] = new Stepper(stepper_pins[i][0], stepper_pins[i][1], stepper_pins[i][2], stepper_pins[i][2]);
            break;
        default:
            // statements
            break;
        }
        tools_array[0][i] = mystepper[i];
    }
    // Init servo's
    for (int i = 0; i < SERVOS; i++)
    {
        myservo[i] = new CustomServo(servo_pins[i]);
        tools_array[SERVO][i] = myservo[i];
    }
    // Init relay's
    for (int i = 0; i < RELAYS; i++)
    {
        myrelay[i] = relay_pins[i];
        tools_array[RELAY][i] = myrelay[i];
    }
    // Init pwm's
    for (int i = 0; i < PWMS; i++)
    {
        mypwm[i] = pwm_pins[i];
        tools_array[PWM][i] = mypwm[i];
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
                break;
            }
        }

        parseInstruction(new_instruction, instruction_counter);
        instruction_counter = 0;
    }
    //    update tasks
    Tasks.update();
}

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

void parseInstruction(Instruction new_instruction, int instruction_counter)
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

    // intruction counter gebruiken om te weten hoeveel instructies ik moet parse met de run() functie;

    // tools_array[instruction_type][instruction_type_number]->run();
    // switch (instruction_type)
    // {
    // case STEPPER:
    //     instruction_tool = "mystepper";
    //     break;
    // case SERVO:
    //     instruction_tool = "myservo";
    //     break;
    // case RELAY:
    //     instruction_tool = "myrelay";
    //     break;
    // case PWM:
    //     instruction_tool = "mypwm";
    //     break;
    // default:
    //     Serial.println("Unknown instruction type");
    //     Serial.print(instruction_type);
    //     oledd.clear();
    //     oledd.displayText(0, 0, "Unkown instruction");
    //     oledd.displayText(0, 1, "type:" + String(instruction_type));
    //     previousMillis = millis();
    //     clear_screen = true;
    //     return;
    // }
    // Serial.println(tools[instruction_type].val1);

    // Tasks.add([new_instruction, instruction_type_number, instruction_tool]
    //           {
    //               Serial.print("My PWM ");
    //               Serial.println(instruction_type_number);
    //               instruction_tool[instruction_type_number]->parseInstruction(new_instruction.val1);
    //           })
    //     ->startOnceAfter(new_instruction.start);
    // Serial.println(new_instruction.val1);
    // Serial.println(instruction_type_number);
    // Serial.println(instruction_tool);

    Tasks.pause();
}
