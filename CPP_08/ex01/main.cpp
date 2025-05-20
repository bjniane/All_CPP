#include "Span.hpp"
#include <exception>
#include <list>

int main()
{
    Span sp = Span(10);

    try 
    {
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::list<int> more;
        more.push_back(10);
        more.push_back(20);
        more.push_back(30);
        more.push_back(40);
        more.push_back(50);
        sp.addRange(more.begin(), more.end());
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    return 0;
}