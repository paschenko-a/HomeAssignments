/*
* Pashchenko Alexey
* st141278@student.spbu.ru
* My project number three
*/

#ifndef SPARK_H
#define SPARK_H

class Spark {
public:
    Spark(int energyLevel, bool isActive, float frequency);
    ~Spark();
    
    int getEnergyLevel();
    bool getIsActive();
    float getFrequency();
    
    void setEnergyLevel(int level);
    void setIsActive(bool active);
    void setFrequency(float freq);
    
    bool recharge();
    void pulse();

private:
    int energyLevel_;
    bool isActive_;
    float frequency_;
};

#endif