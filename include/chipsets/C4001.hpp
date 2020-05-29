//
// Created by chaoticks on 25/02/2020.
//

#ifndef OOP_NANOTEKSPICE_2019_C4001_HPP
#define OOP_NANOTEKSPICE_2019_C4001_HPP

#include "../IComponent.hpp"
#include <vector>

namespace nts {
    class C4001 : public IComponent {
    public:
        C4001(std::string const&);
        virtual ~C4001() = default;

        virtual Tristate compute(std::size_t pin);
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
        void dump() const override;

        virtual Tristate getValue() const;
        virtual void setValue(nts::Tristate tristate);
        virtual std::string getName() const;

    private:
        std::string _name;
        IComponent *_pin[14];
        IComponent *_gates[4];
        nts::Tristate _value;
        std::map<size_t, size_t> _links;
    };
}


#endif //OOP_NANOTEKSPICE_2019_C4001_HPP
