//
// Created by chaoticks on 26/02/2020.
//

#include <iostream>
#include "../../include/gates/XorGate.hpp"

nts::XorGate::XorGate(const std::string &name)
        : _name(name)
{
    _pin[0] = nullptr;
    _pin[1] = nullptr;
    _links.insert(std::pair<size_t, size_t>(0, 0));
    _links.insert(std::pair<size_t, size_t>(0, 0));
}

nts::Tristate nts::XorGate::compute(std::size_t pin) {
    pin--;
    if (_pin[0] == nullptr || _pin[1] == nullptr)
        return _value = UNDEFINED;
    if ( _pin[0]->getValue() == UNDEFINED || _pin[1]->getValue() == UNDEFINED)
        return _value = UNDEFINED;
    if ((_pin[0]->getValue() == FALSE && _pin[1]->getValue() == TRUE) ||
    (_pin[0]->getValue() == TRUE && _pin[1]->getValue() == FALSE))
        return _value = TRUE;
    return _value = FALSE;
}

void nts::XorGate::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) {
    if (pin - 1 < 3 && _pin[pin - 1] == nullptr) {
        _links[pin - 1] = otherPin;
        _pin[pin - 1] = &other;
        other.setLink(otherPin, *this, pin);
    } else if (pin - 1 > 2 || pin == 0) {
        //throw error
    }
}
void nts::XorGate::dump() const {
    std::cout << "XorGate name: " << _name << std::endl;
}

nts::Tristate nts::XorGate::getValue() const {
    return _value;
}

void nts::XorGate::setValue(nts::Tristate tristate) {
    _value = tristate;
}

std::string nts::XorGate::getName() const {
    return _name;
}