#pragma once
#include <string>
#include <map>
#include "HotDrinkFactory.h"
#include "CoffeeFactory.h"
#include "TeaFactory.h"
#include <functional>
using namespace std;

struct HotDrink;

class DrinkFactory
{
  map<string, unique_ptr<HotDrinkFactory>> factories;
public:

  DrinkFactory()
  {
    factories["coffee"] = make_unique<CoffeeFactory>();
    factories["tea"] = make_unique<TeaFactory>();
  }

  unique_ptr<HotDrink> make_drink(const string& name)
  {
    auto drink = factories[name]->make();
    /**
     * oops! we cannot have the luxuries of defining custom drink volume here!
     * So, we've defind DrinkWithVolumeFactory below for that!
     */
    drink->prepare(200); 
    return drink;
  }
};

class DrinkWithVolumeFactory
{
  map < string, function<unique_ptr<HotDrink>()>> factories;
public:


  // Note here, we are using a functional approach to build a factory
  DrinkWithVolumeFactory()
  {
    // each entry maps to a lambda which needs to be called to get the results
    factories["tea"] = [] {
      auto tea = make_unique<Tea>();
      tea->prepare(100);
      return tea;
    };

    // similarly we can define a lambda for coffee and other drinks
  }

  unique_ptr<HotDrink> make_drink(const string& name)
  {
    // returning the object returned by calling the lambda
    return factories[name]();
  }

  /**
   *  Notice that this approach although allows us to specify different volumes
   *  for each drink, it is kind of similar to the approach where we had to write
   *  a number of if else for different kind of drinks.
   */

};