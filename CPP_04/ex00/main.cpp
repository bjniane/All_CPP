#include "Cat.h"
#include "Dog.h"
#include "WrongCat.h"

int main()
{
    // const Animal* meta = new Animal();
    // const Animal* j = new Dog();
    const WrongAnimal* i = new WrongCat();

    // std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound();
    // j->makeSound();
    // meta->makeSound();
    
    delete i;
    // delete j;
    // delete meta;
    return 0;
}