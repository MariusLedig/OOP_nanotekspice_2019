//
// Created by chaoticks on 01/03/2020.
//

#include "../../include/chipsets/C4069.hpp"
#include "../../include/entries/Input.hpp"
#include "../../include/gates/NotGate.hpp"
#include <array>
#include <iostream>

nts::C4069::C4069(std::string const &value)
        : _name(value)
{
    _gates[0] = new nts::NotGate("gate1");
    _gates[1] = new nts::NotGate("gate2");
    _gates[2] = new nts::NotGate("gate3");
    _gates[3] = new nts::NotGate("gate4");
    _gates[4] = new nts::NotGate("gate5");
    _gates[5] = new nts::NotGate("gate6");

    for (int i = 0; i < 14; i++) {
        _links.insert(std::pair<size_t, size_t>(0, 0));
        _pin[i] = nullptr;
    }
}

nts::Tristate nts::C4069::compute(std::size_t pin) {
    std::size_t finalPin = pin / 2 - 1;

    if (pin > 0 && pin < 14 && _pin[pin - 1] != nullptr)
        return _value = _gates[finalPin]->compute();
    return UNDEFINED;
}

void nts::C4069::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) {
    if (pin > 0 && pin < 14) {
        _links[pin - 1] = otherPin;
        _pin[pin - 1] = &other;
    } else {
        //throw error
    }
    if ((pin >= 1 && pin <= 2))
        _pin[pin - 1]->setLink(otherPin, *_gates[0], pin);
    if ((pin >= 3 && pin <= 4))
        _pin[pin - 1]->setLink(otherPin, *_gates[1], pin - 3);
    if ((pin >= 5 && pin <= 6))
        _pin[pin - 1]->setLink(otherPin, *_gates[2], pin - 5);
    if ((pin >= 8 && pin <= 9))
        _pin[pin - 1]->setLink(otherPin, *_gates[3], pin - 8);
    if ((pin >= 10 && pin <= 11))
        _pin[pin - 1]->setLink(otherPin, *_gates[4], pin - 10);
    if ((pin >= 12 && pin <= 13))
        _pin[pin - 1]->setLink(otherPin, *_gates[5], pin - 12);
}

void nts::C4069::dump() const {
    std::cout << "4069: " << _name << std::endl;
}

std::string nts::C4069::getName() const {
    return _name;
}

nts::Tristate nts::C4069::getValue() const {
    return _value;
}

void nts::C4069::setValue(nts::Tristate tristate) {
    _value = tristate;
}