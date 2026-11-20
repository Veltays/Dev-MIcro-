#include <Arduino.h>
#include "led_driver.h"
#include "button_driver.h"

#define ledpin 13
#define Buttonpin 2

LedDriver led(ledpin);
ButtonDriver button(Buttonpin);

volatile bool buttonPressed = false;

void button_press() {
    Serial.println("Interrupt triggered: Button pressed.");
    buttonPressed = true;
}

void setup() {
    Serial.begin(115200);

    pinMode(ledpin, OUTPUT);

    button.begin();
    button.setInterrupt(button_press, FALLING);

    Serial.println("Setup complete.");

}

void loop() {
    Serial.println("Current Value Of Button: " + String(button.GetCurrentValue()));
    if (buttonPressed) {
        buttonPressed = false;
        led.led_toggle();
        Serial.println("Button pressed! LED state toggled.");
    }

    delay(100); // Add a small delay to avoid flooding the serial output
}