//
// Created by chaoticks on 25/02/2020.
//

#ifndef OOP_NANOTEKSPICE_2019_FALSE_HPP
#define OOP_NANOTEKSPICE_2019_FALSE_HPP

#include "../IComponent.hpp"

namespace nts {
    class False : public IComponent {
    public:
        False(const std::string &);
        virtual ~False() = default;

        virtual Tristate compute(std::size_t pin = 1);
        virtual void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
        virtual void dump() const;
        virtual Tristate getValue() const;
        virtual void setValue(nts::Tristate tristate);
        virtual std::string getName() const;

    private:
        std::string _name;
    public:

    private:
        Tristate _value;
        IComponent *_pin[1];
        std::pair<size_t, size_t> _links;
    };
}

#endif //OOP_NANOTEKSPICE_2019_FALSE_HPP
