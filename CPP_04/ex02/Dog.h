#ifndef DOG_H
#define DOG_H

#include "Animal.h"

class Dog : public Animal
{
    public:
        Dog();
        Dog(std::string type);
        Dog(const Dog& src);
        Dog& operator=(const Dog& rhs);
        ~Dog();

        void    makeSound() const;
};

#endif