/*
* Pashchenko Alexey
* st141278@student.spbu.ru
* My project number four
*/

#ifndef AUTOBOT_H
#define AUTOBOT_H

#include "Transformer.h"
#include <string>
#include <ostream>

class Autobot : public Transformer
{
public:
    Autobot(const std::string& name, int age, const std::string& rank,
            float size, Vehicle* vehicle, int courageLevel,
            const std::string& faction);
    Autobot();
    ~Autobot();

    int getCourageLevel() const;
    std::string getFaction() const;

    void setCourageLevel(int level);
    void setFaction(const std::string& faction);

    bool protect();
    bool inspire();
    bool peaceOffer();
    bool introduce();

    void battleCry() override;
    bool defend() override;

    friend std::ostream& operator<<(std::ostream& os, const Autobot& a);

private:
    int courageLevel_;
    std::string faction_;
};

#endif