//
// Created by chaoticks on 01/03/2020.
//

#include "../../include/chipsets/C4011.hpp"
#include "../../include/entries/Input.hpp"
#include "../../include/gates/NAndGate.hpp"
#include <array>
#include <iostream>

nts::C4011::C4011(std::string const &value)
        : _name(value)
{
    _gates[0] = new nts::NAndGate("gateNAnd1");
    _gates[1] = new nts::NAndGate("gateNAnd2");
    _gates[2] = new nts::NAndGate("gateNAnd3");
    _gates[3] = new nts::NAndGate("gateNAnd4");

    for (int i = 0; i < 14; i++) {
        _links.insert(std::pair<size_t, size_t>(0, 0));
        _pin[i] = nullptr;
    }
}

nts::Tristate nts::C4011::compute(std::size_t pin) {
    std::size_t finalPin = pin / 2 - 1;

    if (pin > 0 && pin < 14 && _pin[pin - 1] != nullptr)
        return _value = _gates[finalPin]->compute();
    return UNDEFINED;
}

void nts::C4011::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) {
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

void nts::C4011::dump() const {
    std::cout << "4011: " << _name << std::endl;
}

std::string nts::C4011::getName() const {
    return _name;
}

nts::Tristate nts::C4011::getValue() const {
    return _value;
}

void nts::C4011::setValue(nts::Tristate tristate) {
    _value = tristate;
}
