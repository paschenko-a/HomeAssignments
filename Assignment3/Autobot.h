/*
* Pashchenko Alexey
* st141278@student.spbu.ru
* My project number three
*/

#ifndef AUTOBOT_H
#define AUTOBOT_H

#include "Transformer.h"
#include <string>

class Autobot : public Transformer
{
public:
    Autobot(const std::string& name, int age, const std::string& rank,
            float size, Vehicle* vehicle, int courageLevel,
            const std::string& faction);
    ~Autobot();

    int getCourageLevel();
    std::string getFaction();

    void setCourageLevel(int level);
    void setFaction(const std::string& faction);

    bool protect();
    bool inspire();
    bool peaceOffer();

    bool introduce();

private:
    int courageLevel_;
    std::string faction_;
};

#endif