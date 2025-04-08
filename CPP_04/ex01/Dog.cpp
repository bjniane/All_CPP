#include "Dog.h"

Dog::Dog()
    : Animal()
{
    type = "Dog";
    dog = new Brain();
    std::cout << "Dog default constructor called for: " << type << std::endl;
}

Dog::Dog(std::string type)
    : Animal(type)
{
    type = "Dog";
    dog = new Brain();
    std::cout << "Dog constructor called for: " << type << std::endl;
}

Dog::Dog(const Dog& src)
    : Animal(src.type)
{
    dog = new Brain();
    *dog = *(src.dog);
    std::cout << "Dog copy constructor called for: " << type << std::endl;
}

Dog& Dog::operator=(const Dog& rhs)
{
    if (this != &rhs)
    {
        Animal::operator=(rhs);
        delete dog;
        dog = new Brain();
        *dog = *(rhs.dog);
    }
    std::cout << "Dog copy assignment operator called for: " << type << std::endl;
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog destructor called for: " << type << std::endl;
    delete dog;
}

void    Dog::makeSound() const
{
    std::cout << type << ", says Woof" << std::endl;
}
