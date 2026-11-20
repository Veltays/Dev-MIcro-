#ifndef LED_DRIVER_H
#define LED_DRIVER_H

#include <Arduino.h>

const uint8_t INTERNAL_LED = 13;

class LedDriver {
public:
    uint8_t led;
    bool state;

    LedDriver(uint8_t led);
    LedDriver();

    void led_on();
    void led_off();
    void led_toggle(uint32_t TimeSleep = 100);
    void change_state(bool state);


private:
    void set_led(uint8_t newLed);
    uint8_t get_led();
    bool get_state();
    void set_state(bool state);
};

#endif
