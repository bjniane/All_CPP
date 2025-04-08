#include "Cat.h"

Cat::Cat()
    : Animal()
{
    type = "Cat";
    std::cout << "Cat default constructor called for: " << type << std::endl;
}

Cat::Cat(std::string type)
    : Animal(type)
{
    type = "Cat";
    std::cout << "Cat constructor called for: " << type << std::endl;
}

Cat::Cat(const Cat& src)
    : Animal(src.type)
{
    std::cout << "Cat copy constructor called for: " << type << std::endl;
}

Cat& Cat::operator=(const Cat& rhs)
{
    if (this != &rhs)
        Animal::operator=(rhs);
    std::cout << "Cat copy assignment called for: " << type << std::endl;
    return *this;
}

Cat::~Cat()
{
    std::cout << "Cat destructor called for: " << type << std::endl;
}

void    Cat::makeSound() const
{
    std::cout << type << ", says Meow" << std::endl;
}
