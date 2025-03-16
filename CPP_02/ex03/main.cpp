#include "Fixed.h"
#include "Point.h"

int main( void )
{
    Point A(5, 2);
    Point B(1, 0);
    Point C(1, 1);
    
    Point P1(3, 1);
    Point P2(5, 2);
    Point P3(2, 1);
    
    if (!bsp(A, B,  C, P1))
        std::cout << "The point is on edge" << std::endl;
    if (!bsp(A, B, C, P2))
        std::cout << "The point is a vertex" << std::endl;
    if (!bsp(A, B, C, P3))
        std::cout << "Outside triangle" << std::endl;
    else
        std::cout << "Inside triangle" << std::endl;
    return 0;
}