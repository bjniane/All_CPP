#include "Point.h"

Point::Point()
    :x(0), y(0)
{
}

Point::Point(Fixed a, Fixed b)
    :x(a), y(b)
{
}

Point::Point(const Point& src)
    :x(src.x), y(src.y)
{
}
Point&  Point::operator=(const Point& rhs)
{
    if (this != &rhs)
    {
        this->x = rhs.x;
        this->y = rhs.y;
    }
    return *this;
}

Point::~Point()
{
}

bool    Point::operator==(const Point& rhs)
{
    if ((this->x == rhs.x) && (this->y == rhs.y))
        return true;
    return false;
}