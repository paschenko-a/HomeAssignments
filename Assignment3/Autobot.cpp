/*
* Pashchenko Alexey
* st141278@student.spbu.ru
* My project number four
*/

#include "Autobot.h"
#include <iostream>

Autobot::Autobot(const std::string& name, int age, const std::string& rank,
                 float size, Vehicle* vehicle, int courageLevel,
                 const std::string& faction)
    : Transformer(name, "Blue", age, rank, size, vehicle),
      courageLevel_(courageLevel),
      faction_(faction)
{
}

Autobot::Autobot()
    : Transformer(),
      courageLevel_(50),
      faction_("Autobot")
{
}

Autobot::~Autobot()
{
}

int Autobot::getCourageLevel() const
{
    return courageLevel_;
}

std::string Autobot::getFaction() const
{
    return faction_;
}

void Autobot::setCourageLevel(int level)
{
    courageLevel_ = level;
}

void Autobot::setFaction(const std::string& faction)
{
    faction_ = faction;
}

bool Autobot::protect()
{
    return true;
}

bool Autobot::inspire()
{
    return true;
}

bool Autobot::peaceOffer()
{
    return true;
}

bool Autobot::introduce()
{
    return true;
}

void Autobot::battleCry()
{
    std::cout << "Autobot::battleCry()" << std::endl;
}

bool Autobot::defend()
{
    std::cout << "Autobot::defend()" << std::endl;
    return true;
}

std::ostream& operator<<(std::ostream& os, const Autobot& a)
{
    os << static_cast<const Transformer&>(a);

    os << ", Faction: " << a.faction_
       << ", Courage: " << a.courageLevel_;
    return os;
}