#include "Brain.h"

Brain::Brain()
{
    for (int i = 0; i < 100; i++)
        ideas[i] = "Brain";
    std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain& src)
{
    for (int i = 0; i < 100; i++)
        ideas[i] = src.ideas[i];
    std::cout << "Brain copy constructor called" << std::endl;
}

Brain& Brain::operator=(const Brain& rhs)
{
    std::cout << "Brain copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
        for (int i = 0; i < 100; i++)
            ideas[i] = rhs.ideas[i];
    }
    return *this;
}

Brain::~Brain()
{
    std::cout << "Brain destructor called" << std::endl;
}