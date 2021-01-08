class Button {
  private:
    byte pin;
    byte state;
    byte lastReading;
    unsigned long lastDebounceTime = 0;
    unsigned long debounceDelay = 5;
  public:
    Button(byte pin) {
      this->pin = pin;
      lastReading = LOW;
      Serial.println("CMA HERE BUTTON");
      init();
    }
    void init() {
      pinMode(pin, INPUT);
      update();
    }
    void update() {
      // You can handle the debounce of the button directly
      // in the class, so you don't have to think about it
      // elsewhere in your code
      byte newReading = digitalRead(pin);
      
      if (newReading != lastReading) {
        lastDebounceTime = millis();
      }
      if (millis() - lastDebounceTime > debounceDelay) {
        // Update the 'staxte' attribute only if debounce is checked
        state = newReading;
      }
      lastReading = newReading;
    }
    byte getState() {
      update();
      return state;
    }
    bool isPressed() {
      return (getState() == HIGH);
    }
    bool myTest(){
      return (getState() == HIGH);
    }
}; // don't forget the semicolon at the end of the class
