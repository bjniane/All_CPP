#ifndef WRONGCAT_H
#define WRONGCAT_H

#include "WrongAnimal.h"

class WrongCat : public WrongAnimal
{
    public:
        WrongCat();
        WrongCat(std::string type);
        WrongCat(const WrongCat& src);
        WrongCat& operator=(const WrongCat& rhs);
        ~WrongCat();

        void    makeSound() const;
};

#endif