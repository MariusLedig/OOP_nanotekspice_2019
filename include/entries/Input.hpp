//
// Created by chaoticks on 04/02/2020.
//

#ifndef OOP_NANOTEKSPICE_2019_INPUT_HPP
#define OOP_NANOTEKSPICE_2019_INPUT_HPP

#include "../IComponent.hpp"

namespace nts {
    class Input : public IComponent {
    public:
        Input(const std::string &, const Tristate);
        Input(const std::string &);
        virtual ~Input() = default;

        virtual Tristate compute(std::size_t pin = 1);
        virtual void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
        virtual void dump() const;
        virtual Tristate getValue() const;
        virtual void setValue(nts::Tristate tristate);
        virtual std::string getName() const;

    private:
        std::string _name;
        Tristate _value;
        IComponent *_pin[1];
        std::pair<size_t, size_t> _links;
    };
}

#endif //OOP_NANOTEKSPICE_2019_INPUT_HPP
