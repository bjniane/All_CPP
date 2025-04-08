#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>

class Animal
{
    protected:
        std::string type;
    public:
        Animal();
        Animal(std::string type);
        Animal(const Animal& src);
        Animal& operator=(const Animal& rhs);
        virtual ~Animal();

        virtual void    makeSound() const = 0;
        const std::string& getType() const;
};

#endif