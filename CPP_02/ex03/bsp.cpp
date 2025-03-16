#include "Fixed.h"
#include "Point.h"

Fixed   triangleArea(Point const a, Point const b, Point const c)
{
    Fixed   result;
    result = Fixed((a.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat())) +
        (b.getX().toFloat() * (c.getY().toFloat() - a.getY().toFloat())) +
        (c.getX().toFloat() * (a.getY().toFloat() - b.getY().toFloat())));
    return result;
}

bool    bsp(Point const A, Point const B, Point const C, Point const P)
{
    Fixed   S = triangleArea(A, B, C);
    Fixed   S1 = triangleArea(A, B, P);
    Fixed   S2 = triangleArea(B, C, P);
    Fixed   S3 = triangleArea(C, A, P);

    if (S1 == 0 || S2 == 0 || S3 == 0)
        return false;
    if (std::abs(S.toFloat()) == std::abs(S1.toFloat()) + std::abs(S2.toFloat()) + std::abs(S3.toFloat()))
        return true;;
    return false;
}