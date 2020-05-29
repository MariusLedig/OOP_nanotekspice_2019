//
// Created by chaoticks on 01/03/2020.
//

#include <iostream>
#include "../../include/entries/Clock.hpp"

nts::Clock::Clock(const std::string &name, const Tristate state)
        : _name(name), _value(state)
{
    _pin[0] = nullptr;
    _links.first = 0;
    _links.second = 0;
}

nts::Clock::Clock(const std::string &name)
        : _name(name)
{
    _value = UNDEFINED;
    _pin[0] = nullptr;
    _links.first = 0;
    _links.second = 0;
}

nts::Tristate nts::Clock::compute(std::size_t pin) {
    //if (pin - 1 > 0)
    //throw error
    pin--;
    return _value;
}

void nts::Clock::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) {
    if (pin - 1 < 1) {
        _links.first = pin - 1;
        _links.second = otherPin;
        _pin[pin - 1] = &other;
        other.setLink(otherPin, *this, pin);
    } else if (pin - 1 > 0) {
        //throw error
    }
}

void nts::Clock::dump() const {
    std::cout << "Clock: " << _name << " is " << int(_value) << std::endl;
}

nts::Tristate nts::Clock::getValue() const {
    return _value;
}

void nts::Clock::setValue(nts::Tristate tristate) {
    _value = tristate;
}

std::string nts::Clock::getName() const {
    return _name;
}

void nts::Clock::switchClock() {
    if (_value == UNDEFINED)
        return;
    _value = (_value == TRUE) ? FALSE : TRUE;
}