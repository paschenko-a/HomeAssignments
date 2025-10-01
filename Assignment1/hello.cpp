#include "hello.h"

#include <iostream>

void myproject::sayHello() {
    std::cout << "Hello, world!" << std::endl;

    std::string input;
    
    std::cout << "Write the name (or 'exit' to end the program): ";
    std::getline(std::cin, input);  // reading the string before the loop to check the exit condition

    while (input != "exit") {                
        std::cout << "Hello, " << input << "!" << std::endl;

        std::cout << "Write the name (or 'exit' to end the program): ";
        std::getline(std::cin, input);
    }
}