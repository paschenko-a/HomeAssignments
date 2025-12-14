#ifndef DINOBOT_H
#define DINOBOT_H

#include "Transformer.h"
#include <string>

class Dinobot : public Transformer {
public:
    Dinobot(const std::string& name, int age, const std::string& rank, 
            float size, Vehicle* vehicle, int roarPower, 
            const std::string& dinoType, bool canFly);
    
    ~Dinobot();
    
    int getRoarPower();
    std::string getDinoType();
    bool getCanFly();
    
    void setRoarPower(int power);
    void setDinoType(const std::string& type);
    void setCanFly(bool canFly);
    
    bool roar();
    bool primalRage();

private:
    int roarPower_;
    std::string dinoType_;
    bool canFly_;
};

#endif