#include "Zombie.h"

Zombie* newZombie(std::string name)
{
    Zombie  *Z = new Zombie(name);
    return Z;
}