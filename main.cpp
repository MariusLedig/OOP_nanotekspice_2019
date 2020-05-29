/*
** EPITECH PROJECT, 2020
** cpp_pool
** File description:
** .cpp
*/

#include <iostream>
#include "include/entries/Input.hpp"
#include "include/entries/Output.hpp"
#include "include/gates/OrGate.hpp"
#include "include/core/Factory.hpp"
#include "include/core/Core.hpp"
#include "include/chipsets/C4001.hpp"

int main(int ac, char **av)
{
    std::string value;

    Core core;
    core.getParser()->parsethefile(ac, av);
    core.createAllComponents();
    for (int i = 2; av[i]; i++) {
        value.assign(av[i]);
        core.getParser()->setValue(value, core.getComponents());
    }
    core.run();
    return 0;
}