//
// Created by chaoticks on 26/02/2020.
//

#include <memory>
#include <iostream>
#include "../../include/core/Factory.hpp"
#include "../../include/entries/Output.hpp"
#include "../../include/entries/Input.hpp"
#include "../../include/entries/Clock.hpp"
#include "../../include/entries/True.hpp"
#include "../../include/entries/False.hpp"
#include "../../include/gates/AndGate.hpp"
#include "../../include/gates/NAndGate.hpp"
#include "../../include/gates/NOrGate.hpp"
#include "../../include/gates/OrGate.hpp"
#include "../../include/gates/NotGate.hpp"
#include "../../include/gates/XorGate.hpp"
#include "../../include/chipsets/C4001.hpp"
#include "../../include/chipsets/C4011.hpp"
#include "../../include/chipsets/C4030.hpp"
#include "../../include/chipsets/C4069.hpp"
#include "../../include/chipsets/C4071.hpp"
#include "../../include/chipsets/C4081.hpp"

Factory::Factory() {
    // entries
    _funcs.insert(std::make_pair("output", &Factory::createOutput));
    _funcs.insert(std::make_pair("input", &Factory::createInput));
    _funcs.insert(std::make_pair("clock", &Factory::createClock));
    _funcs.insert(std::make_pair("true", &Factory::createTrue));
    _funcs.insert(std::make_pair("false", &Factory::createFalse));
    // gates
    _funcs.insert(std::make_pair("AndGate", &Factory::createAndGate));
    _funcs.insert(std::make_pair("NAndGate", &Factory::createNAndGate));
    _funcs.insert(std::make_pair("NOrGate", &Factory::createNOrGate));
    _funcs.insert(std::make_pair("NotGate", &Factory::createNotGate));
    _funcs.insert(std::make_pair("OrGate", &Factory::createOrGate));
    _funcs.insert(std::make_pair("XorGate", &Factory::createXorGate));
    // chipsets
    _funcs.insert(std::make_pair("4001", &Factory::createC4001));
    _funcs.insert(std::make_pair("4011", &Factory::createC4011));
    _funcs.insert(std::make_pair("4030", &Factory::createC4030));
    _funcs.insert(std::make_pair("4069", &Factory::createC4069));
    _funcs.insert(std::make_pair("4071", &Factory::createC4071));
    _funcs.insert(std::make_pair("4081", &Factory::createC4081));
}

std::unique_ptr<nts::IComponent> Factory::createComponent(const std::string &type, const std::string &value) {
    return ((this->*this->_funcs.find(type)->second)(value));
}

// entries

std::unique_ptr<nts::IComponent> Factory::createOutput(const std::string &value) {
    return (std::make_unique<nts::Output>(value));
}

std::unique_ptr<nts::IComponent> Factory::createInput(const std::string &value) {
    return (std::make_unique<nts::Input>(value));
}

std::unique_ptr<nts::IComponent> Factory::createClock(const std::string &value) {
    return (std::make_unique<nts::Clock>(value));
}

std::unique_ptr<nts::IComponent> Factory::createTrue(const std::string &value) {
    return (std::make_unique<nts::True>(value));
}

std::unique_ptr<nts::IComponent> Factory::createFalse(const std::string &value) {
    return (std::make_unique<nts::False>(value));
}

// gates

std::unique_ptr<nts::IComponent> Factory::createAndGate(const std::string &value) {
    return (std::make_unique<nts::AndGate>(value));
}

std::unique_ptr<nts::IComponent> Factory::createNAndGate(const std::string &value) {
    return (std::make_unique<nts::NAndGate>(value));
}

std::unique_ptr<nts::IComponent> Factory::createNOrGate(const std::string &value) {
    return (std::make_unique<nts::NOrGate>(value));
}

std::unique_ptr<nts::IComponent> Factory::createNotGate(const std::string &value) {
    return (std::make_unique<nts::NotGate>(value));
}

std::unique_ptr<nts::IComponent> Factory::createOrGate(const std::string &value) {
    return (std::make_unique<nts::OrGate>(value));
}

std::unique_ptr<nts::IComponent> Factory::createXorGate(const std::string &value) {
    return (std::make_unique<nts::XorGate>(value));
}

// chipsets

std::unique_ptr<nts::IComponent> Factory::createC4001(const std::string &value) {
    return (std::make_unique<nts::C4001>(value));
}

std::unique_ptr<nts::IComponent> Factory::createC4011(const std::string &value) {
    return (std::make_unique<nts::C4011>(value));
}

std::unique_ptr<nts::IComponent> Factory::createC4030(const std::string &value) {
    return (std::make_unique<nts::C4030>(value));
}

std::unique_ptr<nts::IComponent> Factory::createC4069(const std::string &value) {
    return (std::make_unique<nts::C4069>(value));
}

std::unique_ptr<nts::IComponent> Factory::createC4071(const std::string &value) {
    return (std::make_unique<nts::C4071>(value));
}

std::unique_ptr<nts::IComponent> Factory::createC4081(const std::string &value) {
    return (std::make_unique<nts::C4081>(value));
}

