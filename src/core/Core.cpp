//
// Created by chaoticks on 26/02/2020.
//

#include <iostream>
#include "../../include/core/Core.hpp"

Core::Core() {
    // fonction de parsing
    _parser = new Parser();
    _circuit = new Circuit();
    createAllComponents();
}

Core::~Core() {

}

Factory Core::getFactory() const {
    return _facto;
}

void Core::makeAllLinks(std::string &name1, size_t pin1, std::string &name2, size_t pin2) {
    for (auto &compo : _components)
        if (compo->getName() == name1)
            for (auto &compo2 : _components)
                if (compo2->getName() == name2)
                    compo->setLink(pin1, *compo2, pin2);
}

void Core::createAllComponents() {
    for (auto &comp : getParser()->_chipsets)
        _components.push_back(_facto.createComponent(comp.first, comp.second));
    for (auto &link : getParser()->_links)
        makeAllLinks(
                link.first.first, link.first.second,
                link.second.first, link.second.second);
}

void Core::dump() {
    for (auto &link : _components) {
        std::cout << link->getName() << std::endl;
    }
}

Parser *Core::getParser() const {
    return _parser;
}

void Core::firstSimulate() const {
    for (auto &comp : _parser->_chipsets)
        if (comp.first == "output") {
            for (auto &compo : _components)
                if (compo->getName() == comp.second) {
                    _circuit->setValue(compo->compute());
                }
        }
}

void Core::run() {
    std::string input = "";

    firstSimulate();
    _circuit->display(_components, _parser);
    std::cout << "> ";
    while (getline(std::cin, input) && input != "exit")
    {
        if (input != "")
            _circuit->loop(input, _components, _parser);
        std::cout << "> ";
    }
}

void Core::setValue(std::string &value, std::vector<std::shared_ptr<nts::IComponent>> _components) {
    _parser->setValue(value, _components);
}

std::vector<std::shared_ptr<nts::IComponent>> Core::getComponents() const {
    return _components;
}
