/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Parser.hpp
*/
#ifndef OOP_NANOTEKSPICE_2019_PARSER_HPP
#define OOP_NANOTEKSPICE_2019_PARSER_HPP

#include <vector>
#include <memory>
#include "../IComponent.hpp"

class Parser {
public:
    Parser();
    virtual ~Parser();
    void parsethefile(int ac, char **arg);
    void lastcheck();
    void checkotherargs(char **argv);

    nts::Tristate switchClock(nts::Tristate);
    void setValue(std::string &, std::vector<std::shared_ptr<nts::IComponent>>);

    std::vector<std::pair<std::string, std::string>> _chipsets;
    std::vector<std::pair<std::pair<std::string, size_t>, std::pair<std::string, size_t>>> _links;
};

#endif //OOP_NANOTEKSPICE_2019_PARSER_HPP
