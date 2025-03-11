#include "HumanB.h"

HumanB::HumanB(std::string name_val)
    :name(name_val), weaponB(NULL)
{
}

HumanB::~HumanB()
{
}

void    HumanB::setWeapon(Weapon& weapon)
{
    weaponB = &weapon;
}

void    HumanB::attack(void)
{
    if (weaponB)
        std::cout << name << " attacks with their " << weaponB->getType() << std::endl;
    else
        std::cout << name << " has no weapon." << std::endl;
}