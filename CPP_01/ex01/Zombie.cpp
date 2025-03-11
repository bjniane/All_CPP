#include "Zombie.h"

Zombie::Zombie()
{
}

Zombie::Zombie(std::string name_val)
    : name(name_val)
{
}

Zombie::~Zombie()
{
    std::cout << "Destructor called for " << name << std::endl;
}

void    Zombie::announce(void)
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}