/*
* Pashchenko Alexey
* st141278@student.spbu.ru
* My project number four
*/

#include "Decepticon.h"

Decepticon::Decepticon(const std::string& name, int age, const std::string& rank,
                       float size, Vehicle* vehicle, int aggressionLevel,
                       const std::string& specialAbility)
    : Transformer(name, "Red", age, rank, size, vehicle),
      aggressionLevel_(aggressionLevel),
      specialAbility_(specialAbility)
{
}

Decepticon::Decepticon()
    : Transformer(),
      aggressionLevel_(80),
      specialAbility_("Energy Blast")
{
}

Decepticon::~Decepticon()
{
}

int Decepticon::getAggressionLevel() const
{
    return aggressionLevel_;
}

std::string Decepticon::getSpecialAbility() const
{
    return specialAbility_;
}

void Decepticon::setAggressionLevel(int level)
{
    aggressionLevel_ = level;
}

void Decepticon::setSpecialAbility(const std::string& ability)
{
    specialAbility_ = ability;
}

bool Decepticon::destroy()
{
    return true;
}

bool Decepticon::deceive()
{
    return true;
}

bool Decepticon::conquer()
{
    return true;
}

void Decepticon::battleCry()
{
    std::cout << "Decepticon::battleCry()" << std::endl;
}

bool Decepticon::defend()
{
    std::cout << "Decepticon::defend()" << std::endl;
    return true;
}

std::ostream& operator<<(std::ostream& os, const Decepticon& d)
{
    os << static_cast<const Transformer&>(d);

    os << ", Ability: " << d.specialAbility_
       << ", Aggression: " << d.aggressionLevel_;
    return os;
}