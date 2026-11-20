#include "button_driver.h"

ButtonDriver::ButtonDriver(uint8_t button)
{
    set_button(button);
}

void ButtonDriver::begin()
{
    pinMode(button, INPUT_PULLUP);
}

void ButtonDriver::setInterrupt(void (*callback)(), int mode)
{
    attachInterrupt(digitalPinToInterrupt(button), callback, mode);
}

uint16_t ButtonDriver::GetCurrentValue()
{
    set_value(digitalRead(button));
    return value;
}

// SETTERS

void ButtonDriver::set_value(uint16_t newValue)
{
    this->value = newValue;
}

void ButtonDriver::set_button(uint8_t newButton)
{
    this->button = newButton;
}

// GETTERS

uint8_t ButtonDriver::get_button()
{
    return this->button;
}