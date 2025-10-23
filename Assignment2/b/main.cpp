/*
* Pashchenko Alexey
* st141278@student.spbu.ru
* My project number two (b)
*/

#include "calculate.hpp"


int main() {
    std::cout << "Write reverse Polish notation\n";
    std::string word;
    std::string inputString;
    std::getline(std::cin, inputString);
    
    myproject::calculateValue(inputString);
    return 0;
}
