#ifndef POINT_H
#define POINT_H

#include "Fixed.h"

class Point 
{
    public:
        Fixed   x;
        Fixed   y;
        Point();
        Point(Fixed a, Fixed b);
        Point(const Point& src);
        Point&  operator=(const Point& rhs);
        ~Point();

        bool    operator==(const Point& rhs);
};

void    isInside(const Point& A, const Point& B, const Point& C, const Point& P);

#endif