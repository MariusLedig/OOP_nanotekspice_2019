//
// Created by chaoticks on 01/03/2020.
//

#ifndef OOP_NANOTEKSPICE_2019_CLOCK_HPP
#define OOP_NANOTEKSPICE_2019_CLOCK_HPP

#include "../IComponent.hpp"

namespace nts {
    class Clock : public IComponent {
    public:
        Clock(const std::string &, const Tristate);
        Clock(const std::string &);
        virtual ~Clock() = default;

        virtual Tristate compute(std::size_t pin = 1);
        virtual void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
        virtual void dump() const;
        void switchClock();
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

#endif //OOP_NANOTEKSPICE_2019_CLOCK_HPP
