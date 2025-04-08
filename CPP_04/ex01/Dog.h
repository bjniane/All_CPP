#ifndef DOG_H
#define DOG_H

#include "Animal.h"
#include "Brain.h"

class Dog : public Animal
{
    private:
        Brain* dog;
    public:
        Dog();
        Dog(std::string type);
        Dog(const Dog& src);
        Dog& operator=(const Dog& rhs);
        ~Dog();

        void    makeSound() const;
};

#endif