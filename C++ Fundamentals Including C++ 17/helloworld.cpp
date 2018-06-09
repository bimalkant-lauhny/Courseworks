#include <iostream>
#include <string>

int main() {
    std::cout << "Enter your name: " << std::endl;
    std::string name;
    std::cin >> name; 
    std::cout << "Welcome, " << name << "!" << std::endl;
    return 0;
}