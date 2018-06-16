#pragma once
/*
  pragma once preprocessor forces the compiler to include declarations only once
*/
#include "Person.h"
#include <string>

class Tweeter: public Person {
  private:
    std::string twitterhandle;

  public:

    Tweeter(
        std::string first, 
        std::string last, 
        std::string handle);

    ~Tweeter();
};