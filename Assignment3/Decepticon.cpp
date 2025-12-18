/*
* Pashchenko Alexey
* st141278@student.spbu.ru
* My project number three
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

Decepticon::~Decepticon()
{
}

int Decepticon::getAggressionLevel()
{
    return aggressionLevel_;
}

std::string Decepticon::getSpecialAbility()
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