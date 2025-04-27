#include "Bureaucrat.hpp"
#include <exception>

int main()
{
    try
    {
        Bureaucrat Test1;
        std::cout << Test1 << std::endl;

        Bureaucrat Test2("Test2", 150);
        std::cout << Test2 << std::endl;
    }
    catch(std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    return 0;
}