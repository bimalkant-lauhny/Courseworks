#include <iostream>
//#include "Person.h"
#include "Tweeter.h"

int main(void) {
    Person p("Bikram", "Lauhny");
    {
        Tweeter t1("Bimalkant", "Lauhny", "bkl");
        std::string name = t1.getName();
        std::cout << "Tweeter name: " << name << std::endl;
        Person p2;
    }
    std::cout << p.getName() << std::endl; 
    return 0;
}