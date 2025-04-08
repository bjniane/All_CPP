#include "WrongCat.h"

WrongCat::WrongCat()
    : WrongAnimal()
{
    type = "WrongCat";
    std::cout << "WrongCat default constructor called for: " << type << std::endl;
}

WrongCat::WrongCat(std::string type)
    : WrongAnimal(type)
{
    type = "WrongCat";
    std::cout << "WrongCat constructor called for: " << type << std::endl;
}

WrongCat::WrongCat(const WrongCat& src)
    : WrongAnimal(src.type)
{
    std::cout << "WrongCat copy constructor called for: " << type << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& rhs)
{
    if (this != &rhs)
        WrongAnimal::operator=(rhs);
    std::cout << "WrongCat copy assignment called for: " << type << std::endl;
    return *this;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor called for: " << type << std::endl;
}

void    WrongCat::makeSound() const
{
    std::cout << type << ", says Meow" << std::endl;
}
