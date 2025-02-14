#include "Zombie.h"

Zombie::Zombie()
{
}

Zombie::Zombie(std::string zombie_name)
    : name(zombie_name)
{
    std::cout << "Constructor called for: " << name << std::endl;
}

Zombie::~Zombie()
{
    std::cout << "Destructor called for: " << name << std::endl;
}

void    Zombie::announce()
{
    std::cout << name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}
