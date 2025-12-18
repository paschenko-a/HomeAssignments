/*
* Pashchenko Alexey
* st141278@student.spbu.ru
* My project number three
*/

#include "Transformer.h"
#include <iostream>

Transformer::Transformer(const std::string& name, const std::string& eyeColor,
                         int age, const std::string& rank, float size, Vehicle* vehicle)
    : name_(name),
      eyeColor_(eyeColor),
      age_(age),
      rank_(rank),
      size_(size),
      spark_(100, true, 60.5f),
      vehicle_(vehicle)
{
}

Transformer::~Transformer()
{
}

std::string Transformer::getName()
{
    return name_;
}

std::string Transformer::getEyeColor()
{
    return eyeColor_;
}

int Transformer::getAge()
{
    return age_;
}

std::string Transformer::getRank()
{
    return rank_;
}

float Transformer::getSize()
{
    return size_;
}

void Transformer::setName(const std::string& name)
{
    name_ = name;
}

void Transformer::setEyeColor(const std::string& eyeColor)
{
    eyeColor_ = eyeColor;
}

void Transformer::setAge(int age)
{
    age_ = age;
}

void Transformer::setRank(const std::string& rank)
{
    rank_ = rank;
}

void Transformer::setSize(float size)
{
    size_ = size;
}

Spark& Transformer::getSpark()
{
    return spark_;
}

void Transformer::rechargeSpark()
{
    spark_.recharge();
}

Vehicle* Transformer::getVehicle()
{
    return vehicle_;
}

void Transformer::setVehicle(Vehicle* vehicle)
{
    vehicle_ = vehicle;
}

bool Transformer::attack()
{
    return true;
}

bool Transformer::transform()
{
    if (vehicle_)
    {
        return true;
    }
    return false;
}

bool Transformer::introduce()
{
    return true;
}