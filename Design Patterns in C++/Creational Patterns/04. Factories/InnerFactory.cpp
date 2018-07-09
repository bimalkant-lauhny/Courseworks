#include <cmath>

class Point
{
    // use a factory method
    Point(float x, float y) : x(x), y(y) {}

    // defined an inner private factory
    class PointFactory
    {
        PointFactory() {}

      public:
        static Point NewCartesian(float x, float y)
        {
            return {x, y};
        }
        static Point NewPolar(float r, float theta)
        {
            return {r * cos(theta), r * sin(theta)};
        }
    };

  public:
    float x, y;

    // this static memeber is now the only way to create Points
    static PointFactory Factory;
};

int main_2()
{
    // will not work
    // Point p{ 1,2 };

    // nope!
    // Point::PointFactory pf;

    // if factory is public, then
    //auto p = Point::PointFactory::NewCartesian(3, 4);

    // at any rate, use this
    auto pp = Point::Factory.NewCartesian(2, 3);

    return 0;
}