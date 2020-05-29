//
// Created by chaoticks on 29/02/2020.
//

#include <iostream>
#include <csignal>
#include "../../include/core/Circuit.hpp"
#include "../../include/core/Parser.hpp"

bool _loop;

void Circuit::loop(std::string &input, std::vector<std::shared_ptr<nts::IComponent>> _components, Parser *parser) {
    if (input == "dump")
        dump(_components);
    else if (input == "display")
        display(_components, parser);
    else if (input == "simulate")
        simulate(_components, parser);
    else if (input == "loop")
        loop(_components, parser);
    else
        parser->setValue(input, _components);
}

void Circuit::dump(std::vector<std::shared_ptr<nts::IComponent>> _components) {
    for (auto &compo : _components)
        compo->dump();
}

void Circuit::display(std::vector<std::shared_ptr<nts::IComponent>> _components, Parser *parser) {
    std::string name;

    for (auto &comp : parser->_chipsets)
        if (comp.first == "output") {
            name = comp.second;
            for (auto &link : _components)
                if (link->getName() == name)
                    std::cout << name << "=" << (int)link->compute() << std::endl;
        }

}

void Circuit::simulate(std::vector<std::shared_ptr<nts::IComponent>> _components, Parser *parser) {
    for (auto &comp : parser->_chipsets)
        if (comp.first == "output")
            for (auto &compo : _components)
                if (compo->getName() == comp.second)
                    _value = compo->compute();
    for (auto &chip : parser->_chipsets)
        if (chip.first == "clock")
            for (auto &compo : _components)
                if (compo->getName() == chip.second)
                    compo->setValue(parser->switchClock(compo->getValue()));
}

void stopLoop(int signal) {
    (void)signal;
    _loop = false;
}

void Circuit::loop(std::vector<std::shared_ptr<nts::IComponent>> _components, Parser *parser) {
    _loop = true;

    while (_loop) {
        simulate(_components, parser);
        signal(SIGINT, stopLoop);
    }
    std::cout << std::endl;
}

void Circuit::setValue(nts::Tristate value) {
    _value = value;
}
