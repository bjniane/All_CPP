#include "Point.h"

Point::Point()
    :x(0), y(0)
{
}

Point::Point(const Fixed a, const Fixed b)
    :x(a), y(b)
{
}

Point::Point(const Point& src)
    :x(src.x), y(src.y)
{
}

Point&  Point::operator=(const Point& rhs)
{
    (void)rhs;
    return *this;
}

Point::~Point()
{
}