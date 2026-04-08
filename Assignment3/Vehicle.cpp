/*
* Pashchenko Alexey
* st141278@student.spbu.ru
* My project number four
*/

#include "Vehicle.h"
#include <iostream>

Vehicle::Vehicle(const std::string& type, const std::string& model, int maxSpeed)
    : type_(type), model_(model), maxSpeed_(maxSpeed), isDamaged_(false)
{
}

Vehicle::Vehicle()
    : type_("Car"), model_("Default"), maxSpeed_(100), isDamaged_(false)
{
}

Vehicle::~Vehicle()
{
}

std::string Vehicle::getType() const
{
    return type_;
}

std::string Vehicle::getModel() const
{
    return model_;
}

int Vehicle::getMaxSpeed() const
{
    return maxSpeed_;
}

bool Vehicle::getIsDamaged() const
{
    return isDamaged_;
}

void Vehicle::setType(const std::string& type)
{
    type_ = type;
}

void Vehicle::setModel(const std::string& model)
{
    model_ = model;
}

void Vehicle::setMaxSpeed(int speed)
{
    if (speed >= 0)
    {
        maxSpeed_ = speed;
    }
}

void Vehicle::setIsDamaged(bool damaged)
{
    isDamaged_ = damaged;
}

void Vehicle::repair()
{
    isDamaged_ = false;
    std::cout << model_ << " has been repaired!" << std::endl;
}

void Vehicle::upgrade()
{
    maxSpeed_ += 10;
    std::cout << model_ << " New max speed: " << maxSpeed_ << std::endl;
}