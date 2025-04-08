#include "WrongAnimal.h"

WrongAnimal::WrongAnimal()
    : type("None")
{
    std::cout << "WrongAnimal default constructor called for: " << type << std::endl;
}

WrongAnimal::WrongAnimal(std::string type)
    : type(type)
{
    std::cout << "WrongAnimal constructor called for: " << type << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& src)
    : type(src.type)
{
    std::cout << "WrongAnimal copy constructor called for: " << type << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& rhs)
{
    std::cout << "WrongAnimal copy assignment operator called for: " << type << std::endl;
    if (this != &rhs)
        type = rhs.type;
    return *this;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal Destructor called for: " << type << std::endl;
}

void    WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal sound" << std::endl;
}

const std::string& WrongAnimal::getType() const
{
    return type;
}
