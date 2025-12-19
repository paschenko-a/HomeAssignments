/*
* Pashchenko Alexey
* st141278@student.spbu.ru
* My project number four
*/

#ifndef TRANSFORMER_H
#define TRANSFORMER_H

#include <string>
#include <iostream>
#include "Spark.h"
#include "Vehicle.h"

class Transformer
{
public:
    Transformer(const std::string& name, const std::string& eyeColor,
                int age, const std::string& rank, float size, Vehicle* vehicle);
    Transformer();
    ~Transformer();

    std::string getName() const;
    std::string getEyeColor() const;
    int getAge() const;
    std::string getRank() const;
    float getSize() const;

    void setName(const std::string& name);
    void setEyeColor(const std::string& eyeColor);
    void setAge(int age);
    void setRank(const std::string& rank);
    void setSize(float size);

    Spark& getSpark();
    void rechargeSpark();

    Vehicle* getVehicle();
    void setVehicle(Vehicle* vehicle);

    bool attack();
    bool transform();
    bool introduce();

    virtual bool defend();
    virtual void battleCry() = 0;

    friend std::ostream& operator<<(std::ostream& os, const Transformer& t);

private:
    std::string name_;
    std::string eyeColor_;
    int age_;
    std::string rank_;
    float size_;

    Spark spark_;

    Vehicle* vehicle_;
};

#endif