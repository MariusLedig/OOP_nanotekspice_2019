//
// Created by chaoticks on 29/02/2020.
//

#ifndef OOP_NANOTEKSPICE_2019_CIRCUIT_HPP
#define OOP_NANOTEKSPICE_2019_CIRCUIT_HPP


#include <string>
#include <memory>
#include <vector>
#include "../IComponent.hpp"
#include "Parser.hpp"

class Circuit {
public:
    void loop(std::string &, std::vector<std::shared_ptr<nts::IComponent>>, Parser *);

    void dump(std::vector<std::shared_ptr<nts::IComponent>>);
    void display(std::vector<std::shared_ptr<nts::IComponent>>, Parser *);
    void simulate(std::vector<std::shared_ptr<nts::IComponent>>, Parser *);
    void loop(std::vector<std::shared_ptr<nts::IComponent>>, Parser *);

    void setValue(nts::Tristate);

private:
    nts::Tristate _value;
};


#endif //OOP_NANOTEKSPICE_2019_CIRCUIT_HPP
