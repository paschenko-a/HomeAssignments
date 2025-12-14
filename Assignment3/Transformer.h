#ifndef TRANSFORMER_H
#define TRANSFORMER_H

#include <string>
#include "Spark.h"
#include "Vehicle.h"

class Transformer {
public:
    Transformer(const std::string& name, const std::string& eyeColor, 
                int age, const std::string& rank, float size, Vehicle* vehicle);
    ~Transformer();
    
    std::string getName();
    std::string getEyeColor();
    int getAge();
    std::string getRank();
    float getSize();
    
    void setName(const std::string& name);
    void setEyeColor(const std::string& eyeColor);
    void setAge(int age);
    void setRank(const std::string& rank);
    void setSize(float size);
    
    Spark getSpark();
    void rechargeSpark();
    
    Vehicle* getVehicle();
    void setVehicle(Vehicle* vehicle);
    
    bool attack();
    bool transform();
    virtual bool introduce();

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