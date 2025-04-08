#include "Animal.h"

Animal::Animal()
    : type("None")
{
    std::cout << "Animal default constructor called for: " << type << std::endl;
}

Animal::Animal(std::string type)
    : type(type)
{
    std::cout << "Animal constructor called for: " << type << std::endl;
}

Animal::Animal(const Animal& src)
    : type(src.type)
{
    std::cout << "Animal copy constructor called for: " << type << std::endl;
}

Animal& Animal::operator=(const Animal& rhs)
{
    std::cout << "Animal copy assignment operator called for: " << type << std::endl;
    if (this != &rhs)
        type = rhs.type;
    return *this;
}

Animal::~Animal()
{
    std::cout << "Animal Destructor called for: " << type << std::endl;
}

void    Animal::makeSound() const
{
    std::cout << "Animal sound" << std::endl;
}

const std::string& Animal::getType() const
{
    return type;
}
