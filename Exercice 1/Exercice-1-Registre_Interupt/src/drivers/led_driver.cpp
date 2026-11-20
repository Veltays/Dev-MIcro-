#include "led_driver.h"
#include "bit_utils.h"


LedDriver::LedDriver(uint8_t led) {
    set_led(led);
    set_state(false);
}

LedDriver::LedDriver() {
    set_led(INTERNAL_LED);
    set_state(false);
}


void LedDriver::led_on() {
    Serial.println("Led ON");
    set_state(true);
    SetBit(PORTB, PB7);  // Allume la LED
    delay(1000);
}

void LedDriver::led_off() {
    Serial.println("Led OFF");
    set_state(false);
    ClrBit(PORTB, PB7);  // Éteint la LED
}

void LedDriver::led_toggle(uint32_t TimeSleep) {
    change_state(get_state());
    delay(TimeSleep);
}

void LedDriver::set_led(uint8_t newLed) {
    led = newLed;
}

uint8_t LedDriver::get_led() {
    return led;
}



void LedDriver::change_state(bool state)
{
    bool newState = !state;

    set_state(newState);
    if(get_state()) {
        led_on();
    } else {
        led_off();
    }
    
    Serial.print("Led state changed to: ");
    Serial.println(newState ? "ON" : "OFF");
}


bool LedDriver::get_state() {
    return state;
}


void LedDriver::set_state(bool newState){
    this->state = newState;
}
