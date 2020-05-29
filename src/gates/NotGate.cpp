//
// Created by chaoticks on 26/02/2020.
//

#include <iostream>
#include "../../include/gates/NotGate.hpp"

nts::NotGate::NotGate(const std::string &name)
        : _name(name)
{
    _pin[0] = nullptr;
    _pin[1] = nullptr;
    _links.first = 0;
    _links.second = 0;
}

nts::Tristate nts::NotGate::compute(std::size_t pin) {
    pin--;
    if (_pin[0] == nullptr || _pin[0]->getValue() == UNDEFINED)
        return _value = UNDEFINED;
    return _value = (_pin[0]->getValue() == TRUE ? FALSE : TRUE);
}

void nts::NotGate::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) {
    if (pin - 1 < 2 && _pin[pin - 1] == nullptr) {
        _links.second = otherPin;
        _pin[pin - 1] = &other;
        other.setLink(otherPin, *this, pin);
    } else if (pin - 1 > 1 || pin == 0) {
        //throw error
    }
}
void nts::NotGate::dump() const {
    std::cout << "NotGate: " << _name << std::endl;
}

nts::Tristate nts::NotGate::getValue() const {
    return _value;
}

void nts::NotGate::setValue(nts::Tristate tristate) {
    _value = tristate;
}

std::string nts::NotGate::getName() const {
    return _name;
}