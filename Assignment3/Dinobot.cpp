/*
* Pashchenko Alexey
* st141278@student.spbu.ru
* My project number four
*/

#include "Dinobot.h"

Dinobot::Dinobot(const std::string& name, int age, const std::string& rank,
                 float size, Vehicle* vehicle, int roarPower,
                 const std::string& dinoType, bool canFly)
    : Transformer(name, "Yellow", age, rank, size, vehicle),
      roarPower_(roarPower),
      dinoType_(dinoType),
      canFly_(canFly)
{
}

Dinobot::Dinobot()
    : Transformer(),
      roarPower_(70),
      dinoType_("T-Rex"),
      canFly_(false)
{
}

Dinobot::~Dinobot()
{
}

int Dinobot::getRoarPower() const
{
    return roarPower_;
}

std::string Dinobot::getDinoType() const
{
    return dinoType_;
}

bool Dinobot::getCanFly() const
{
    return canFly_;
}

void Dinobot::setRoarPower(int power)
{
    roarPower_ = power;
}

void Dinobot::setDinoType(const std::string& type)
{
    dinoType_ = type;
}

void Dinobot::setCanFly(bool canFly)
{
    canFly_ = canFly;
}

bool Dinobot::roar()
{
    return true;
}

bool Dinobot::primalRage()
{
    return true;
}

void Dinobot::battleCry()
{
    std::cout << "Dinobot::battleCry()" << std::endl;
}

bool Dinobot::defend()
{
    std::cout << "Dinobot::defend()" << std::endl;
    return true;
}

std::ostream& operator<<(std::ostream& os, const Dinobot& d)
{
    // Выводим базовую информацию из Transformer
    os << static_cast<const Transformer&>(d);
    
    // Добавляем специфичную информацию Dinobot
    os << ", DinoType: " << d.dinoType_ 
       << ", RoarPower: " << d.roarPower_
       << ", CanFly: " << (d.canFly_ ? "Yes" : "No");
    return os;
}