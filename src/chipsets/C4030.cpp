//
// Created by chaoticks on 01/03/2020.
//


#include "../../include/chipsets/C4030.hpp"
#include "../../include/entries/Input.hpp"
#include "../../include/gates/XorGate.hpp"
#include <array>
#include <iostream>

nts::C4030::C4030(std::string const &value)
        : _name(value)
{
    _gates[0] = new nts::XorGate("gate1");
    _gates[1] = new nts::XorGate("gate2");
    _gates[2] = new nts::XorGate("gate3");
    _gates[3] = new nts::XorGate("gate4");

    for (int i = 0; i < 14; i++) {
        _links.insert(std::pair<size_t, size_t>(0, 0));
        _pin[i] = nullptr;
    }
}

nts::Tristate nts::C4030::compute(std::size_t pin) {
    if (pin > 0 && pin < 14 && _pin[pin - 1] != nullptr)
        return _value = _gates[0]->compute();
    return UNDEFINED;
}

void nts::C4030::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) {
    if (pin > 0 && pin < 14) {
        _links[pin - 1] = otherPin;
        _pin[pin - 1] = &other;
    } else {
        //throw error
    }
    if ((pin >= 1 && pin <= 3))
        _pin[pin - 1]->setLink(otherPin, *_gates[0], pin);
    if ((pin >= 4 && pin <= 6))
        _pin[pin - 1]->setLink(otherPin, *_gates[1], pin - 4);
    if ((pin >= 8 && pin <= 10))
        _pin[pin - 1]->setLink(otherPin, *_gates[2], pin - 8);
    if ((pin >= 11 && pin <= 13))
        _pin[pin - 1]->setLink(otherPin, *_gates[3], pin - 11);
}

void nts::C4030::dump() const {
    std::cout << "4001: " << _name << std::endl;
}

std::string nts::C4030::getName() const {
    return _name;
}

nts::Tristate nts::C4030::getValue() const {
    return _value;
}

void nts::C4030::setValue(nts::Tristate tristate) {
    _value = tristate;
}