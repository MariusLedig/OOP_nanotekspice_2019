//
// Created by chaoticks on 26/02/2020.
//

#ifndef OOP_NANOTEKSPICE_2019_NOTGATE_HPP
#define OOP_NANOTEKSPICE_2019_NOTGATE_HPP

#include "../IComponent.hpp"

namespace nts {
    class NotGate : public IComponent {
    public:
        NotGate(const std::string &);
        virtual ~NotGate() = default;

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
        std::pair<size_t, size_t> _links;
    };
}

#endif //OOP_NANOTEKSPICE_2019_NOTGATE_HPP
