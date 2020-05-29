//
// Created by chaoticks on 04/02/2020.
//

#include <iostream>
#include "../../include/entries/Input.hpp"

nts::Input::Input(const std::string &name, const Tristate state)
    : _name(name), _value(state)
{
    _pin[0] = nullptr;
    _links.first = 0;
    _links.second = 0;
}

nts::Input::Input(const std::string &name)
    : _name(name)
{
    _value = UNDEFINED;
    _pin[0] = nullptr;
    _links.first = 0;
    _links.second = 0;
}

nts::Tristate nts::Input::compute(std::size_t pin) {
    //if (pin - 1 > 0)
        //throw error
    pin--;
    return _value;
}

void nts::Input::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) {
    if (pin - 1 < 1) {
        _links.first = pin - 1;
        _links.second = otherPin;
        _pin[pin - 1] = &other;
        other.setLink(otherPin, *this, pin);
    } else if (pin - 1 > 0) {
        //throw error
    }
}

void nts::Input::dump() const {
    std::cout << "Input: " << _name << " is " << int(_value) << std::endl;
}

nts::Tristate nts::Input::getValue() const {
    return _value;
}

void nts::Input::setValue(nts::Tristate tristate) {
    _value = tristate;
}

std::string nts::Input::getName() const {
    return _name;
}
