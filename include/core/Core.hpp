//
// Created by chaoticks on 26/02/2020.
//

#ifndef OOP_NANOTEKSPICE_2019_CORE_HPP
#define OOP_NANOTEKSPICE_2019_CORE_HPP

#include "Factory.hpp"
#include "Parser.hpp"
#include "Circuit.hpp"

class Core {
public:
    Core();
    virtual ~Core();

    void createAllComponents();
    void makeAllLinks(std::string &, size_t, std::string &, size_t);
    void setValue(std::string &, std::vector<std::shared_ptr<nts::IComponent>>);

    void dump();
    void run();
    void firstSimulate() const;

    Factory getFactory() const;
    Parser *getParser() const;
    std::vector<std::shared_ptr<nts::IComponent>> getComponents() const;


private:
    std::vector<std::shared_ptr<nts::IComponent>> _components;
    Factory _facto;
    Parser *_parser;
    Circuit *_circuit;
};


#endif //OOP_NANOTEKSPICE_2019_CORE_HPP
