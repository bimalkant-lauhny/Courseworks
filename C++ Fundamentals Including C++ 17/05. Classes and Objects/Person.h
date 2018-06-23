#pragma once
/*
  pragma once preprocessor forces the compiler to include declarations only once
*/

#include <string>

class Person {
  private:
    std::string firstname;
    std::string lastname;

  public:
    // Explicit constructor
    Person(std::string firstname, std::string lastname);
    
    /* 
    Ask compiler to generate a default constructor that doesn't take any 
    arguments since now there is one explicit constructor 
    Person()=default;
    */

    Person();

    // to get the full name of person
    // const means that getName() will not alter any data member of the class
    std::string getName() const;

    ~Person();
};