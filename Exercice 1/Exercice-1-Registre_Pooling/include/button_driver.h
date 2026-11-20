#ifndef BUTTON_DRIVER_H
#define BUTTON_DRIVER_H

#include <Arduino.h>


class ButtonDriver {
public:
    uint8_t button;
    uint16_t value;

    ButtonDriver(uint8_t bouton);

    uint16_t GetCurrentValue();


private:
    void set_button(uint8_t newButton);
    uint8_t get_button();
    void set_value(uint16_t value);

};

#endif