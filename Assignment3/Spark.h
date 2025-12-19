/*
* Pashchenko Alexey
* st141278@student.spbu.ru
* My project number four
*/

#ifndef SPARK_H
#define SPARK_H

class Spark
{
public:
    Spark(int energyLevel, bool isActive, float frequency);
    Spark();
    ~Spark();

    int getEnergyLevel() const;
    bool getIsActive() const;
    float getFrequency() const;

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