#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

//Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
Adafruit_SSD1306 display(4);

class Oled
{
private:
    Adafruit_SSD1306 _display;

public:
    Oled()
    {
        this->_display = display;
    }
    void init()
    {
        if (!_display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
        { // Address 0x3C for 128x32
            for (;;)
                ; // Don't proceed, loop forever
        }
        _display.clearDisplay();
        _display.setTextSize(1);
        _display.setTextColor(WHITE);
        _display.setCursor(0, 0);
    }
    void displayText(int posx, int posy, String text)
    {
        _display.setCursor(posx, posy * 8);
        _display.println(text);
        _display.display();
    }
    void clear()
    {
        _display.clearDisplay();
        _display.display();
    }
};
