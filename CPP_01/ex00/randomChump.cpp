#include "Zombie.h"

void    randomChump(std::string name)
{
    Zombie  Z = Zombie(name);
    Z.announce();
}