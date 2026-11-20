#include <Arduino.h>
#include "led_driver.h"
#include "button_driver.h"
#include "bit_utils.h"



#define ledpin 13
#define Buttonpin 2

LedDriver led(ledpin); // Initialize led 
ButtonDriver button(Buttonpin); // Initialize button

void setup() {
    Serial.begin(115200);

    // configuration de la pin de led pinMode(led.led, OUTPUT);   
    SetBit(DDRB, PB7);   // Configure PB7 en sortie
    

    // configuration de la pin de led pinMode(button.button,INPUT);
    ClrBit(DDRE, PE4);  
    SetBit(PORTE, PE4);
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