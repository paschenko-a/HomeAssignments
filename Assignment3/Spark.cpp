/*
* Pashchenko Alexey
* st141278@student.spbu.ru
* My project number four
*/

#include "Spark.h"

Spark::Spark(int energyLevel, bool isActive, float frequency)
    : energyLevel_(energyLevel),
      isActive_(isActive),
      frequency_(frequency)
{
}

Spark::Spark()
    : energyLevel_(100),
      isActive_(true),
      frequency_(60.5f)
{
}

Spark::~Spark()
{
}

int Spark::getEnergyLevel() const
{
    return energyLevel_;
}

bool Spark::getIsActive() const
{
    return isActive_;
}

float Spark::getFrequency() const
{
    return frequency_;
}

void Spark::setEnergyLevel(int level)
{
    if (level >= 0 && level <= 100)
    {
        energyLevel_ = level;
    }
}

void Spark::setIsActive(bool active)
{
    isActive_ = active;
}

void Spark::setFrequency(float freq)
{
    if (freq > 0)
    {
        frequency_ = freq;
    }
}

bool Spark::recharge()
{
    energyLevel_ = 100;
    isActive_ = true;
    return true;
}

void Spark::pulse()
{
    if (energyLevel_ > 0)
    {
        energyLevel_--;
    }
    if (energyLevel_ == 0)
    {
        isActive_ = false;
    }
}