//
// Created by chaoticks on 04/02/2020.
//

#include <iostream>
#include "../../include/entries/False.hpp"

nts::False::False(const std::string &name)
    : _name(name)
{
    _value = FALSE;
    _pin[0] = nullptr;
    _links.first = 0;
    _links.second = 0;
}

nts::Tristate nts::False::compute(std::size_t pin) {
    //if (pin - 1 > 0)
        //throw error
    pin--;
    return _value;
}

void nts::False::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) {
    if (pin - 1 < 1 && _pin[pin - 1] == nullptr) {
        _links.first = pin - 1;
        _links.second = otherPin;
        _pin[pin - 1] = &other;
        other.setLink(otherPin, *this, pin);
    } else if (pin - 1 > 0) {
        //throw error
    }
}

void nts::False::dump() const {
    std::cout << "Input False value = " << static_cast<int>(_value) << std::endl;
}

nts::Tristate nts::False::getValue() const {
    return _value;
}

void nts::False::setValue(nts::Tristate tristate) {
    _value = tristate;
}

std::string nts::False::getName() const {
    return _name;
}
