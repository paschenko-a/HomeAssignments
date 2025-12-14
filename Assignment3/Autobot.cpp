#include "Autobot.h"
#include <iostream>

Autobot::Autobot(const std::string& name, int age, const std::string& rank, 
                 float size, Vehicle* vehicle, int courageLevel, 
                 const std::string& faction)
    : Transformer(name, "Blue", age, rank, size, vehicle),
      courageLevel_(courageLevel),
      faction_(faction) {
}

Autobot::~Autobot() {
}

int Autobot::getCourageLevel() {
    return courageLevel_;
}

std::string Autobot::getFaction() {
    return faction_;
}

void Autobot::setCourageLevel(int level) {
    courageLevel_ = level;
}

void Autobot::setFaction(const std::string& faction) {
    faction_ = faction;
}

bool Autobot::protect() {
    return true;
}

bool Autobot::inspire() {
    return true;
}

bool Autobot::peaceOffer() {
    return true;
}

bool Autobot::introduce() {
    return true;
}