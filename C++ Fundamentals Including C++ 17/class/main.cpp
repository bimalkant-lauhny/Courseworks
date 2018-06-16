#include <iostream>
#include "Person.h"
#include "Tweeter.h"
/* 
Including both Person and Tweeter header will not throw redefinition error
since 'pragma once' has been included in every header
*/
#include "Status.h"

int main(void) {
    Person p("Bikram", "Lauhny");
    {
        Tweeter t1("Bimalkant", "Lauhny", "bkl");
        std::string name = t1.getName();
        std::cout << "Tweeter name: " << name << std::endl;
        Person p2;
    }
    std::cout << p.getName() << std::endl; 

    Status s = Pending;
    s = Approved;

    FileError fe = FileError::notfound;
    fe = FileError::ok;

    NetworkError ne = NetworkError::disconnected;
    ne = NetworkError::ok;

    return 0;
}