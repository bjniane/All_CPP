#include "Fixed.h"
#include "Point.h"

Fixed   triangleArea(const Point& a, const Point& b, const Point& c)
{
    Fixed   result(0);
    result = Fixed((a.x.toFloat() * (b.y.toFloat() - c.y.toFloat())) +
        (b.x.toFloat() * (c.y.toFloat() - a.y.toFloat())) +
        (c.x.toFloat() * (a.y.toFloat() - b.y.toFloat())));
    return result;
}

void    isInside(const Point& A, const Point& B, const Point& C, const Point& P)
{
    Fixed   S = triangleArea(A, B, C);
    Fixed   S1 = triangleArea(A, B, P);
    Fixed   S2 = triangleArea(B, C, P);
    Fixed   S3 = triangleArea(C, A, P);

    if (std::abs(S.toFloat()) == std::abs(S1.toFloat()) + std::abs(S2.toFloat()) + std::abs(S3.toFloat()))
        std::cout << "Inside triangle" << std::endl;
    else
        std::cout << "Outside triangle" << std::endl;
}