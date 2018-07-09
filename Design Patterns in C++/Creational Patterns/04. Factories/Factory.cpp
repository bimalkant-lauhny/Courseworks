#include <cmath>

enum class PointType
{
    cartesian,
    polar
};

class Point
{
    Point(float x, float y) : x(x), y(y) {}

  public:
    float x, y;
    // Taking the task of Point creation outside the Point class

    /** 
     * to access private members (Point constructor), we defined PersonFactory
     * as a friend of Point
     */ 
    friend class PersonFactory;
};

class PersonFactory
{
    static Point NewCartesian(float x, float y)
    {
        return Point{x, y};
    }

    static Point NewPolar(float r, float theta)
    {
        return Point{r * cos(theta), r * sin(theta)};
    }
};