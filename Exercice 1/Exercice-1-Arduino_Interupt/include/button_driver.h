#ifndef BUTTON_DRIVER_H
#define BUTTON_DRIVER_H

#include <Arduino.h>

class ButtonDriver
{
private:
    uint8_t button;
    uint16_t value;

public:
    ButtonDriver(uint8_t button);

    void begin();
    void setInterrupt(void (*callback)(), int mode);

    uint16_t GetCurrentValue();

    // SETTERS
    void set_value(uint16_t newValue);
    void set_button(uint8_t newButton);

    // GETTERS
    uint8_t get_button();
};

#endif