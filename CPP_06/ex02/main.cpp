#include "Identify.hpp"
#include <string>

int main()
{
    srand(time(0));
    Base *basePtr = generate();

    identify(basePtr);
    identify(*basePtr);
    delete basePtr;
    return 0;
}