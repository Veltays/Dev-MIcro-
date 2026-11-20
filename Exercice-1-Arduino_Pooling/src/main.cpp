#include <Arduino.h>
#include "led_driver.h"
#include "button_driver.h"



#define ledpin 13
#define Buttonpin 2

LedDriver led(ledpin); // Initialize led 
ButtonDriver button(Buttonpin); // Initialize button

void setup() {
    Serial.begin(115200);
    pinMode(led.led, OUTPUT);   
    pinMode(button.button,INPUT);
}

void loop() {

    // Pooling 
    uint16_t value = button.GetCurrentValue();

    if (value == HIGH) {
        led.led_toggle();
    }

    Serial.print("Current Value");
    Serial.println(value);


    delay(1000);
}