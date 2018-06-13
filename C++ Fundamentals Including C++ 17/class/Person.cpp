#include "Person.h"
#include <iostream>

/*
using keyword basically copies down the whole specified namespace.
Therefore, it is better to copy down only required thing rather than
the whole namespace.
*/
/*
Never use the using keyword in header files because the users including
your header files might not want your copied down data 
*/

using std::cout;
using std::endl;

/*
This is initializer syntax
It is better to initialize variables before constructor body
because if variables are user defined types (say class objects)
then before the control goes to control goes to constructor body
it first initializes the variables and then executes the constructor body.
So if programmer initializes variables inside constructor body, then it is
doing same work twice.
*/
Person::Person(std::string first, std::string last) : firstname(first), lastname(last) {
    std::cout << "Constructing: " << getName() << std::endl;
}

Person::~Person() {
    std::cout << "Destructing: " << getName() << std::endl;
}

std::string Person::getName() {
    return this->firstname + " " + this->lastname;
}