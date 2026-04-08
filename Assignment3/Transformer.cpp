/*
* Pashchenko Alexey
* st141278@student.spbu.ru
* My project number four
*/

#include "Transformer.h"

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

Transformer::Transformer()
    : name_("Unknown"),
      eyeColor_("Blue"),
      age_(0),
      rank_("Recruit"),
      size_(1.0f),
      spark_(100, true, 60.5f),
      vehicle_(nullptr)
{
}

Transformer::~Transformer()
{
}

std::string Transformer::getName() const
{
    return name_;
}

std::string Transformer::getEyeColor() const
{
    return eyeColor_;
}

int Transformer::getAge() const
{
    return age_;
}

std::string Transformer::getRank() const
{
    return rank_;
}

float Transformer::getSize() const
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

bool Transformer::defend()
{
    std::cout << "Transformer::defend()" << std::endl;
    return true;
}

std::ostream& operator<<(std::ostream& os, const Transformer& t)
{
    std::string vehicleModel = "None";
    if (t.vehicle_ != nullptr)
    {
        vehicleModel = t.vehicle_->getModel();
    }

    os << "Transformer '" << t.name_ << "' (" << t.rank_
       << "), Age: " << t.age_
       << ", Spark: " << t.spark_.getEnergyLevel() << "%"
       << ", Vehicle: " << vehicleModel;
    return os;
}