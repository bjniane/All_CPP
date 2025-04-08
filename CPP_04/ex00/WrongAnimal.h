#ifndef WRONGANIMAL_H
#define WRONGANIMAL_H

#include <iostream>
#include <string>

class WrongAnimal
{
    protected:
        std::string type;
    public:
        WrongAnimal();
        WrongAnimal(std::string type);
        WrongAnimal(const WrongAnimal& src);
        WrongAnimal& operator=(const WrongAnimal& rhs);
        virtual ~WrongAnimal();

        void    makeSound() const;
        const std::string& getType() const;
};

#endif