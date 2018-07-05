#include "di.hpp"
#include <iostream>
#include <memory>

struct ILogger
{
  virtual ~ILogger()
  {
  }

  virtual void Log(const std::string& s) = 0;
};

struct ConsoleLogger : ILogger
{
  void Log(const std::string& s) override {
    std::cout << "LOG: " << s.c_str() << std::endl;
  }
};

struct Engine
{
  float volume = 5;
  int horse_power = 400;


  friend std::ostream& operator<<(std::ostream& os, const Engine& obj)
  {
    return os
      << "volume: " << obj.volume
      << " horse_power: " << obj.horse_power;
  }
};

struct Car
{
  std::shared_ptr<Engine> engine;
  std::shared_ptr<ILogger> logger;


  Car(const std::shared_ptr<Engine>& engine, const std::shared_ptr<ILogger>& i_logger)
    : engine{engine},
      logger{i_logger}
  {
    logger->Log("Created a car");
  }

  friend std::ostream& operator<<(std::ostream& os, const Car& obj)
  {
    return os << "car with engine: " << *obj.engine;
  }
};

int main_()
{
  /**
  * Note for below commented out lines, we need to explicitly define an Engine
  * pass to a Car. This would become cumbersome if Car would've been dependent
  * on many more types of objects, which themselves would've been dependent on
  * other supertypes and so on. Therefore we need some way to automatically do
  * all this dependecy check.
  */
  /*auto e = std::make_shared<Engine>();
  auto c = std::make_shared<Car>(e);*/

  using namespace boost;
  auto injector = di::make_injector(
    di::bind<ILogger>().to<ConsoleLogger>()
  );

  /**
  * Note that for statement below, we didn't have to specifically intialize Engine
  * to pass to Car instead BoosDI framework took care of that.
  */
  auto c = injector.create<std::shared_ptr<Car>>();

  std::cout << *c << std::endl;

  getchar();
  return 0;
}