//
// Created by chaoticks on 26/02/2020.
//

#ifndef OOP_NANOTEKSPICE_2019_FACTORY_HPP
#define OOP_NANOTEKSPICE_2019_FACTORY_HPP

#include <memory>
#include <vector>
#include "../IComponent.hpp"

class Factory {
public:
    Factory();
    virtual ~Factory() = default;

    std::unique_ptr<nts::IComponent> createComponent(const std::string &type, const std::string &value);

private:
    std::map<std::string, std::unique_ptr<nts::IComponent> (Factory::*)(const std::string &value)> _funcs;

    // entries
    std::unique_ptr<nts::IComponent> createOutput(const std::string &value);
    std::unique_ptr<nts::IComponent> createInput(const std::string &value);
    std::unique_ptr<nts::IComponent> createClock(const std::string &value);
    std::unique_ptr<nts::IComponent> createTrue(const std::string &value);
    std::unique_ptr<nts::IComponent> createFalse(const std::string &value);

    // gates
    std::unique_ptr<nts::IComponent> createAndGate(const std::string &value);
    std::unique_ptr<nts::IComponent> createNAndGate(const std::string &value);
    std::unique_ptr<nts::IComponent> createNOrGate(const std::string &value);
    std::unique_ptr<nts::IComponent> createNotGate(const std::string &value);
    std::unique_ptr<nts::IComponent> createOrGate(const std::string &value);
    std::unique_ptr<nts::IComponent> createXorGate(const std::string &value);

    // chipsets
    std::unique_ptr<nts::IComponent> createC4001(const std::string &value);
    std::unique_ptr<nts::IComponent> createC4011(const std::string &value);
    std::unique_ptr<nts::IComponent> createC4030(const std::string &value);
    std::unique_ptr<nts::IComponent> createC4069(const std::string &value);
    std::unique_ptr<nts::IComponent> createC4071(const std::string &value);
    std::unique_ptr<nts::IComponent> createC4081(const std::string &value);
};

#endif //OOP_NANOTEKSPICE_2019_FACTORY_HPP
