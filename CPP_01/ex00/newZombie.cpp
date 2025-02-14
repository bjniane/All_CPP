#include "Zombie.h"

Zombie  *newZombie(std::string name)
{
    Zombie  *Zombie_ptr = new Zombie(name);
    return Zombie_ptr;
}