//
// Created by chaoticks on 04/02/2020.
//

#ifndef OOP_NANOTEKSPICE_2019_ICOMPONENT_HPP
#define OOP_NANOTEKSPICE_2019_ICOMPONENT_HPP

#include <string>
#include <map>

namespace nts
{
    enum Tristate {
        UNDEFINED = (-true),
        TRUE = true,
        FALSE = false
    };

    class IComponent {
    public:
        virtual ~IComponent() = default;
        virtual nts::Tristate compute(std::size_t pin = 1) = 0;
        virtual void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) = 0;
        virtual void dump() const = 0;
        virtual nts::Tristate getValue() const = 0;
        virtual void setValue(nts::Tristate) = 0;
        virtual std::string getName() const = 0;
    };
}

#endif //OOP_NANOTEKSPICE_2019_ICOMPONENT_HPP

