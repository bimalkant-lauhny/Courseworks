#include <iostream>
#include "Person.h"

int main(void) {
    Person p("Bikram", "Lauhny");
    Person p2;
    std::cout << p.getName() << std::endl; 
    return 0;
}