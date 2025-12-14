#include "Dinobot.h"

Dinobot::Dinobot(const std::string& name, int age, const std::string& rank, 
                 float size, Vehicle* vehicle, int roarPower, 
                 const std::string& dinoType, bool canFly)
    : Transformer(name, "Yellow", age, rank, size, vehicle),
      roarPower_(roarPower),
      dinoType_(dinoType),
      canFly_(canFly) {
}

Dinobot::~Dinobot() {
}

int Dinobot::getRoarPower() {
    return roarPower_;
}

std::string Dinobot::getDinoType() {
    return dinoType_;
}

bool Dinobot::getCanFly() {
    return canFly_;
}

void Dinobot::setRoarPower(int power) {
    roarPower_ = power;
}

void Dinobot::setDinoType(const std::string& type) {
    dinoType_ = type;
}

void Dinobot::setCanFly(bool canFly) {
    canFly_ = canFly;
}

bool Dinobot::roar() {
    return true;
}

bool Dinobot::primalRage() {
    return true;
}