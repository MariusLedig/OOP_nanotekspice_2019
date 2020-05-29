/*
** EPITECH PROJECT, 2020
** ex06
** File description:
** openandparse.cpp
*/

#include <iostream>
#include <iterator>
#include <fstream>
#include <iostream>
#include <vector>
#include <cstring>
#include "../../include/core/Parser.hpp"

Parser::Parser() {
}

Parser::~Parser() {
}

std::string makestring(char *arg)
{
    std::ifstream file{arg};
    if (!file.is_open()) {
        std::cerr << "No such file" << std::endl;
        exit(84);
    }
    file >> std::noskipws;
    std::istream_iterator<char> b{file}, e{};
    bool hashtag = false;
    bool jump = false;
    std::string st;

    for (; e != b; ++b) {
        if (jump && *b == '\n')
            continue;
        else
            jump = false;
        if (*b == '#')
            hashtag = true;
        if (hashtag) {
            if (*b == '\n') {
                hashtag = false;
                jump = true;
                continue;
            } else
                continue;
        } else {
            if (*b == '\n')
                jump = true;
            st += *b;
        }
    }
    file.close();
    return st;
}

void checkfile(std::string str)
{
    size_t check = 0;
    size_t num = 0;
    size_t num2 = 0;
    for (int i = 0; str[i] ; ++i) {
        if(str[i] == '.' && str[i+1] == 'c' && str[i+2] == 'h' && str[i+3] == 'i' && str[i+4] == 'p' && str[i+5] == 's' && str[i+6] == 'e' && str[i+7] == 't' && str[i+8] == 's' && str[i+9] == ':' && str[i+10] == '\n')
            check++;
        if(str[i] == '.' && str[i+1] == 'l' && str[i+2] == 'i' && str[i+3] == 'n' && str[i+4] == 'k' && str[i+5] == 's' && str[i+6] == ':' && str[i+7] == '\n')
            check++;
    }
    if (check != 2) {
        std::cerr << "Wrong format file" << std::endl;
        exit(84);
    }
    for (size_t i = 0, enter = 0, check = 0; str[i] ; ++i) {
        if (str[i] == '.' && str[i+1] == 'c' && str[i+2] == 'h' && str[i+3] == 'i' && str[i+4] == 'p' && str[i+5] == 's' && str[i+6] == 'e' && str[i+7] == 't' && str[i+8] == 's' && str[i+9] == ':' && str[i+10] == '\n' && enter == 0) {
            enter++;
            i += 10;
            continue;
        }
        if (str[i] == '.' && str[i+1] == 'l' && str[i+2] == 'i' && str[i+3] == 'n' && str[i+4] == 'k' && str[i+5] == 's' && str[i+6] == ':' && str[i+7] == '\n' && enter == 1) {
            enter++;
            i += 7;
            check = 0;
            continue;
        }
        if (enter == 1) {
            if (str[i] == '\n') {
                if (check != 2) {
                    std::cerr << "Wrong format file" << std::endl;
                    exit(84);
                }
                check = 0;
            }
            if (check % 2) {
                if (str[i] == ' ' || str[i] == '\t');
                else
                    check++;
            } else {
                if (str[i] == ' ' || str[i] == '\t')
                    check++;
            }
        } else if (enter == 2) {
            if (str[i] == '\n') {
                if (check != 4) {
                    std::cerr << "Wrong format file" << std::endl;
                    exit(84);
                }
                else {
                    if (num == 0 || num2 == 0) {
                        std::cerr << "Wrong format file" << std::endl;
                        exit(84);
                    }
                    check = 0;
                    continue;
                }
            }
            if (check == 0) {
                if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z' ) || (str[i] >= '0' && str[i] <= '9'))
                    continue;
                if (str[i] == ':') {
                    check++;
                } else {
                    std::cerr << "Wrong format file" << std::endl;
                    exit(84);
                }
            } else if (check == 1) {
                if (str[i] >= '0' && str[i] <= '9')
                    num++;
                else if (str[i] == ' ' || str[i] == '\t')
                    check++;
                else {
                    std::cerr << "Wrong format file" << std::endl;
                    exit(84);
                }
            } else if (check == 2) {
                if (str[i] == ' ' || str[i] == '\t');
                else if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z' ) || (str[i] >= '0' && str[i] <= '9'))
                    check++;
                else {
                    std::cerr << "Wrong format file" << std::endl;
                    exit(84);
                }
            } else if (check == 3) {
                if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z' ) || (str[i] >= '0' && str[i] <= '9'))
                    continue;
                if (str[i] == ':') {
                    check++;
                } else {
                    std::cerr << "Wrong format file" << std::endl;
                    exit(84);
                }
            } else if (check == 4) {
                if (str[i] >= '0' && str[i] <= '9')
                    num2++;
                else if (str[i] == ' ' || str[i] == '\t' || str[i] == '\0' || str[i] == '\n' )
                    check++;
                else {
                    std::cerr << "Wrong format file" << std::endl;
                    exit(84);
                }
            }
        }
    }
}


void Parser::lastcheck()
{
    size_t check = 0;
    size_t check2 = 0;

    for (auto &chipset : _chipsets) {
        if (chipset.first == "input" || chipset.first == "output" || chipset.first == "false" || chipset.first == "true" || chipset.first == "clock" || chipset.first == "4081" || chipset.first == "4011" || chipset.first == "4001" 
        || chipset.first == "4030" || chipset.first == "4071" || chipset.first == "4069");
        else {
            std::cerr << "No such chipset" << std::endl;
            exit(84);
        }
        for (auto &chips : _chipsets) {
            if(chips.second == chipset.second)
                check++;
        }
        if (check > 1) {
            std::cerr << "Two Chipsets are the same" << std::endl;
            exit(84);
        }
        check = 0;
    }

    for (auto &link : _links) {
        for(auto &chipset : _chipsets) {
            if (link.first.first == chipset.second)
                check++;
            if (link.second.first == chipset.second)
                check2++;
        }
        if (check == 0 || check2 == 0) {
            std::cerr << "A link is linked to an unknown chipset" << std::endl;
            exit(84);
        } else {
            check = 0;
            check2 = 0;
        }
    }
}

void Parser::checkotherargs(char **argv)
{
    std::string str;
    std::string str2;
    size_t check = 0;
    size_t check2 = 0;
    for (size_t i = 2; argv[i]; ++i) {
        for (size_t j = 0; argv[i][j] != '\0'; j++) {
            if (argv[i][j] == '=') {
                check2++;
                continue;
            }
            if (check2 == 0) {
                str += argv[i][j];
            } else if (check2 == 1) {
                str2 += argv[i][j];
            } else {
                std::cerr << "Wrong argument" << std::endl;
                exit(84);
            }
        }
        if (str2 == "0" || str2 == "-1" || str2 == "1");
        else {
            std::cerr << "Wrong argument" << std::endl;
            exit(84);
        }
        if (str2 == "\0") {
            std::cerr << "Wrong argument" << std::endl;
            exit(84);
        }
        for (auto &chips : _chipsets) {
            if(chips.second == str)
                check++;
        }
        if (check == 0) {
            std::cerr << "Wrong argument" << std::endl;
            exit(84);
        }
        str = "";
        str2 = "";
        check = 0;
        check2 = 0;
    }
}

void Parser::parsethefile(int ac, char **argv)
{
    char *arg = argv[1];
    std::string st = makestring(arg);
    std::string str;
    std::string l1;
    std::string str2;
    std::string l2;
    bool check = false;
    bool check2 = false;
    checkfile(st);

    for (size_t i = 0, enter = 0; st[i] ; ++i) {
        if(i < st.length() - 10) {
            if(st[i] == '.' && st[i+1] == 'c' && st[i+2] == 'h' && st[i+3] == 'i' && st[i+4] == 'p' && st[i+5] == 's' && st[i+6] == 'e' && st[i+7] == 't' && st[i+8] == 's' && st[i+9] == ':' && st[i+10] == '\n') {
                enter = 1;
                i += 11;
            }
            if(st[i] == '.' && st[i+1] == 'l' && st[i+2] == 'i' && st[i+3] == 'n' && st[i+4] == 'k' && st[i+5] == 's' && st[i+6] == ':' && st[i+7] == '\n') {
                enter = 2;
                i += 8;
            }
        }
        if (enter == 1) {
            if (!check) {
                if (st[i] == ' ' || st[i] == '\t')
                    check = true;
                else {
                    str += st[i];
                }
            } else {
                if (st[i] == ' ' || st[i] == '\t')
                    continue;
                else if (st[i] == '\n') {
                    check = false;
                    _chipsets.emplace_back(str, str2);
                    str = "";
                    str2 = "";
                } else {
                    str2 += st[i];
                }
            }
        } else if (enter == 2) {
            if (!check) {
                if (check2) {
                    if (st[i] == ' ' || st[i] == '\t') {
                        check2 = false;
                        check = true;
                    } else
                        l1 += st[i];
                } else {
                    if (st[i] == ':')
                        check2 = true;
                    else
                        str += st[i];
                }
            } else {
                if (st[i] == ' ' || st[i] == '\t')
                    continue;
                if (check2) {
                    if (st[i] == '\n' || st[i] == '\0') {
                        _links.emplace_back(
                                std::make_pair(str, std::stoi(l1)),
                                std::make_pair(str2, std::stoi(l2))
                        );
                        str = "";
                        str2 = "";
                        l1 = "";
                        l2 = "";
                        check2 = false;
                        check = false;
                    } else
                        l2 += st[i];
                } else {
                    if (st[i] == ':')
                        check2 = true;
                    else
                        str2 += st[i];
                }
            }
        }
    }
    if (str != "") {
        _links.emplace_back(
                std::make_pair(str, std::stoi(l1)),
                std::make_pair(str2, std::stoi(l2))
        );
    }
    lastcheck();
    if (ac > 2)
        checkotherargs(argv);
}

void Parser::setValue(std::string &input, std::vector<std::shared_ptr<nts::IComponent>> _components) {
    int index = input.find('=');
    if (index == -1) {
        std::cout << "Wrong input name." << std::endl;
        return;
    }
    std::string name = input.substr(0, index);
    int value;
    bool isValid = false;

    for (auto &chip : _chipsets)
        if (chip.second == name)
            isValid = true;
    if (!isValid) {
        std::cout << "Wrong input name." << std::endl;
        // throw error
        return;
    }
    value =  std::stoi(input.substr(index + 1));
    if (value != 0 && value != 1 && value != -1) {
        std::cout << "Wrong input value." << std::endl;
        // throw error
        return;
    }
    for (auto &compo : _components)
        if (compo->getName() == name)
            compo->setValue((nts::Tristate)value);
}

nts::Tristate Parser::switchClock(nts::Tristate value) {
    if (value == nts::UNDEFINED)
        return value;
    return (value == nts::TRUE ? nts::FALSE : nts::TRUE);
}