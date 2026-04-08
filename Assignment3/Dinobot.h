/*
* Pashchenko Alexey
* st141278@student.spbu.ru
* My project number four
*/

#ifndef DINOBOT_H
#define DINOBOT_H

#include "Transformer.h"
#include <string>
#include <ostream>

class Dinobot : public Transformer
{
public:
    Dinobot(const std::string& name, int age, const std::string& rank,
            float size, Vehicle* vehicle, int roarPower,
            const std::string& dinoType, bool canFly);
    Dinobot();
    ~Dinobot();

    int getRoarPower() const;
    std::string getDinoType() const;
    bool getCanFly() const;

    void setRoarPower(int power);
    void setDinoType(const std::string& type);
    void setCanFly(bool canFly);

    bool roar();
    bool primalRage();

    void battleCry() override;
    bool defend() override;

    friend std::ostream& operator<<(std::ostream& os, const Dinobot& d);

private:
    int roarPower_;
    std::string dinoType_;
    bool canFly_;
};

#endif