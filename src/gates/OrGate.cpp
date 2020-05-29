//
// Created by chaoticks on 26/02/2020.
//

#include <iostream>
#include "../../include/gates/OrGate.hpp"

nts::OrGate::OrGate(const std::string &name)
        : _name(name)
{
    _pin[0] = nullptr;
    _pin[1] = nullptr;
    _links.insert(std::pair<size_t, size_t>(0, 0));
    _links.insert(std::pair<size_t, size_t>(0, 0));
}

nts::Tristate nts::OrGate::compute(std::size_t pin) {
    pin--;
    if (_pin[0] == nullptr || _pin[1] == nullptr)
        return _value = UNDEFINED;
    if ( _pin[0]->getValue() == UNDEFINED || _pin[1]->getValue() == UNDEFINED)
        return _value = UNDEFINED;
    if (_pin[0]->getValue() == FALSE && _pin[1]->getValue() == FALSE)
        return _value = FALSE;
    return _value = TRUE;
}

void nts::OrGate::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) {
    if (pin - 1 < 3 && _pin[pin - 1] == nullptr) {
        _links[pin - 1] = otherPin;
        _pin[pin - 1] = &other;
        other.setLink(otherPin, *this, pin);
    } else if (pin - 1 > 2 || pin == 0) {
        //throw error
    }
}
void nts::OrGate::dump() const {
    std::cout << "OrGate: " << _name << std::endl;
}

nts::Tristate nts::OrGate::getValue() const {
    return _value;
}

void nts::OrGate::setValue(nts::Tristate tristate) {
    _value = tristate;
}

std::string nts::OrGate::getName() const {
    return _name;
}