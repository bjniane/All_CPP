#include "Fixed.h"
#include "Point.h"

int main( void )
{
    Point A(5, 2);
    Point B(1, 0);
    Point C(1, 1);
    Point P(2, 1);
    
    isInside(A, B,  C, P);
    return 0;
}