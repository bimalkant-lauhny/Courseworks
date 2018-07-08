#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>

/**
* Suppose we want to have a Point class which represents cordinates
* using cartesian parameters x and y, or, polar cordinates r and theta
*/
/*

// this design is not possible, due to similar signature for constructors
class Point
{
    float x, y;
public:

    // intializing with catesian coordinates
    Point(float x, float y)
    {
        this->x = x;
        this->y = y;
    }

    // initializing with Polar coordinates
    Point(float r, float theta)
    {
        this->x = r * cos(theta);
        this->y = r * sin(theta);
    }
};
*/

// a possible solution for above
enum class PointType
{
  cartesian,
  polar
};

/
class Point
{
    Point(float a, float b, PointType type = PointType::cartesian)
    {
        if (type == PointType::cartesian)
        {
            x = a; b = y;
        }
        else
        {
            x = a*cos(b);
            y = a*sin(b);
        }
    }
};

/**
* Now, there is a single function for both polar and cartesian coordinates.
* But, what if the user sends Polar cordinates and forgets to set PointType as
* polar? The API doesn't provide any checks for that.
*/
