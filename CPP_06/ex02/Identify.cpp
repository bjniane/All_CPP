#include "Identify.hpp"
#include <cstdlib>
#include <typeinfo>

Base::~Base()
{
}

Base* generate(void)
{
    if (rand() % 2 == 0)
        return new A();
    else if (rand() % 2 == 1)
        return new B();
    else
        return new C();
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown type" << std::endl;
}

void identify(Base& p)
{
    try
    {
        A& aRef = dynamic_cast<A&>(p);
        (void)aRef;
        std::cout << "A" << std::endl;
    }
    catch(std::bad_cast& e)
    {
        try
        {
            B& bRef = dynamic_cast<B&>(p);
            (void)bRef;
            std::cout << "B" << std::endl;
        }
        catch(std::bad_cast& e)
        {
            try
            {
                C& cRef = dynamic_cast<C&>(p);
                (void)cRef;
                std::cout << "C" << std::endl;
            }
            catch(std::bad_cast& e)
            {
                std::cout << e.what() << std::endl;
            }
        }
    }
}
