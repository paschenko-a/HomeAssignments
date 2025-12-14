#ifndef DECEPTICON_H
#define DECEPTICON_H

#include "Transformer.h"
#include <string>

class Decepticon : public Transformer {
public:
    Decepticon(const std::string& name, int age, const std::string& rank, 
               float size, Vehicle* vehicle, int aggressionLevel, 
               const std::string& specialAbility);
    ~Decepticon();
    
    int getAggressionLevel();
    std::string getSpecialAbility();
    
    void setAggressionLevel(int level);
    void setSpecialAbility(const std::string& ability);
    
    bool destroy();
    bool deceive();
    bool conquer();

private:
    int aggressionLevel_;
    std::string specialAbility_;
};

#endif