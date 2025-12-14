/*
* Pashchenko Alexey
* st141278@student.spbu.ru
* My project number three
*/

#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>

class Vehicle {
public:
    Vehicle(const std::string& type, const std::string& model, int maxSpeed);
    ~Vehicle();
    
    std::string getType();
    std::string getModel();
    int getMaxSpeed();
    bool getIsDamaged();
    
    void setType(const std::string& type);
    void setModel(const std::string& model);
    void setMaxSpeed(int speed);
    void setIsDamaged(bool damaged);
    
    void repair();
    void upgrade();

private:
    std::string type_;
    std::string model_;
    int maxSpeed_;
    bool isDamaged_;
};

#endif