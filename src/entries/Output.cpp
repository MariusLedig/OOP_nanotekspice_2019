//
// Created by chaoticks on 04/02/2020.
//

#include <iostream>
#include "../../include/entries/Output.hpp"

nts::Output::Output(const std::string &name)
    : _name(name)
{
    _pin[0] = nullptr;
    _links.first = 0;
    _links.second = 0;
}

nts::Tristate nts::Output::compute(std::size_t pin) {
    //if (pin - 1 > 0)
        //throw error
    if (pin - 1 == 0 && _links.first)
        return _value = _pin[pin - 1]->compute();
    return UNDEFINED;
}

void nts::Output::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) {
    if (pin - 1 < 1) {
        _links.first = pin;
        _links.second = otherPin;
        _pin[pin - 1] = &other;
        other.setLink(otherPin, *this, pin);
    } else if (pin - 1 > 0) {
        //throw error
    }
}

void nts::Output::dump() const {
    std::cout << "Output: " << _name << std::endl;
}

nts::Tristate nts::Output::getValue() const {
    return _value;
}

void nts::Output::setValue(nts::Tristate tristate) {
    _value = tristate;
}

std::string nts::Output::getName() const {
    return _name;
}
