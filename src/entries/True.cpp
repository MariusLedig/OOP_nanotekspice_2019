//
// Created by chaoticks on 04/02/2020.
//

#include <iostream>
#include "../../include/entries/True.hpp"

nts::True::True(const std::string &name)
    : _name(name)
{
    _value = TRUE;
    _pin[0] = nullptr;
    _links.first = 0;
    _links.second = 0;
}

nts::Tristate nts::True::compute(std::size_t pin) {
    //if (pin - 1 > 0)
    //throw error
    pin--;
    return _value;
}

void nts::True::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) {
    if (pin - 1 < 1 && _pin[pin - 1] == nullptr) {
        _links.first = pin - 1;
        _links.second = otherPin;
        _pin[pin - 1] = &other;
        other.setLink(otherPin, *this, pin);
    } else if (pin - 1 > 0) {
        //throw error
    }
}

void nts::True::dump() const {
    std::cout << "Input True value = " << static_cast<int>(_value) << std::endl;
}

nts::Tristate nts::True::getValue() const {
    return _value;
}

void nts::True::setValue(nts::Tristate tristate) {
    _value = tristate;
}

std::string nts::True::getName() const {
    return _name;
}