/*
* Pashchenko Alexey
* st141278@student.spbu.ru
* My project number two (b)
*/

#include "calculate.hpp"

void myproject::calculateValue(std::string inputString) {

    double* stack = new double[100];
    double* i = stack;

    std::string symbol;
    std::stringstream stream(inputString);
    std::string operators = "+-*/";

    while (stream >> symbol) {
        if (operators.find(symbol) != std::string::npos){
            if (symbol == "+") {
                double firstElement = *i;
                i--; double secondElement = *i;
                *i = firstElement + secondElement;
            }
            if (symbol == "-") {
                double firstElement = *i;
                i--; double secondElement = *i;
                *i = secondElement - firstElement;
            }
            if (symbol == "*") {
                double firstElement = *i;
                i--; double secondElement = *i;
                *i = firstElement * secondElement;
            }
            if (symbol == "/") {
                double firstElement = *i;
                i--; double secondElement = *i;
                *i = secondElement / firstElement;
            }

        } else {
            i++; double digit = stod(symbol);
            *i = digit;
        }
    }
    std::cout << *i << "\n";
    delete[] stack;
}

