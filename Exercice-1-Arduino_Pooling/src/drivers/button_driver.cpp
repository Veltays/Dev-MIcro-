#include "button_driver.h"

ButtonDriver::ButtonDriver(uint8_t button)
{
    set_button(button);
}

uint16_t ButtonDriver::GetCurrentValue()
{
    value = digitalRead(button);
    set_value(value);
    return value;
}

// SETTER

void ButtonDriver::set_value(uint16_t newValue)
{
    this->value = newValue;
}


// GETTER

void ButtonDriver::set_button(uint8_t newButton)
{
    this->button = newButton;
}

uint8_t ButtonDriver::get_button()
{
    return this->button;
}