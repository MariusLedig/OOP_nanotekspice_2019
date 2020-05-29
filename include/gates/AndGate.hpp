//
// Created by chaoticks on 26/02/2020.
//

#ifndef OOP_NANOTEKSPICE_2019_ANDGATE_HPP
#define OOP_NANOTEKSPICE_2019_ANDGATE_HPP

#include "../IComponent.hpp"

namespace nts {
    class AndGate : public IComponent {
    public:
        AndGate(const std::string &);
        virtual ~AndGate() = default;

        virtual Tristate compute(std::size_t pin = 1);
        virtual void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
        virtual void dump() const;

        Tristate getValue() const override;
        virtual std::string getName() const;
        void setValue(nts::Tristate tristate) override;

    private:
        std::string _name;
        Tristate _value;
        IComponent *_pin[2];
        std::map<size_t, size_t> _links;
    };
}

#endif //OOP_NANOTEKSPICE_2019_ANDGATE_HPP
