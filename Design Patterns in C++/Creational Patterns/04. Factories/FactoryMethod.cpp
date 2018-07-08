#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>

enum class PointType
{
  cartesian,
  polar
};

class Point
{
  // NOTE: constructor is private. No user can directly create a Point
  Point(const float x, const float y)
    : x{x},
      y{y}
  {
  }

public:
  float x, y;

  // overloading stream output operator
  friend std::ostream& operator<<(std::ostream& os, const Point& obj)
  {
    return os
      << "x: " << obj.x
      << " y: " << obj.y;
  }

  // factory method to return a Point using cartesian coordinates
  static Point NewCartesian(float x, float y)
  {
    return{ x,y };
  }

  // factory method to return a Point using polar coordinates
  static Point NewPolar(float r, float theta)
  {
    return{ r*cos(theta), r*sin(theta) };
  }

};

int main()
{
  // will not work
  //Point p{ 1,2 };

  auto c = Point::NewCartesian(2, 3);
  std::cout << c << std::endl;
  
  auto p = Point::NewPolar(5, M_PI_4 /* PI/4 */);
  std::cout << p << std::endl;

  getchar();
  return 0;
}