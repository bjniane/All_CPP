#ifndef CAT_H
#define CAT_H

#include "Animal.h"
#include "Brain.h"

class Cat : public Animal
{
    private:
        Brain* cat;
    public:
        Cat();
        Cat(std::string type);
        Cat(const Cat& src);
        Cat& operator=(const Cat& rhs);
        ~Cat();

        void    makeSound() const;
};

#endif