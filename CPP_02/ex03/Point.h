#ifndef POINT_H
#define POINT_H

#include "Fixed.h"

class Point 
{
    private:
        const Fixed   x;
        const Fixed   y;
    public:
        Point();
        Point(const Fixed a, const Fixed b);
        Point(const Point& src);
        Point&  operator=(const Point& rhs);
        ~Point();

        Fixed   getX() const {return x;}
        Fixed   getY() const {return y;}

};

bool    bsp(Point const A, Point const B, Point const C, Point const P);

#endif