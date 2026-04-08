/*
* Pashchenko Alexey
* st141278@student.spbu.ru
* My project number four
*/

#ifndef DECEPTICON_H
#define DECEPTICON_H

#include "Transformer.h"
#include <string>
#include <ostream>

class Decepticon : public Transformer
{
public:
    Decepticon(const std::string& name, int age, const std::string& rank,
               float size, Vehicle* vehicle, int aggressionLevel,
               const std::string& specialAbility);
    Decepticon();
    ~Decepticon();

    int getAggressionLevel() const;
    std::string getSpecialAbility() const;

    void setAggressionLevel(int level);
    void setSpecialAbility(const std::string& ability);

    bool destroy();
    bool deceive();
    bool conquer();

    void battleCry() override;
    bool defend() override;

    friend std::ostream& operator<<(std::ostream& os, const Decepticon& d);

private:
    int aggressionLevel_;
    std::string specialAbility_;
};

#endif