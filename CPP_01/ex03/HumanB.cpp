#include "HumanB.h"

HumanB::HumanB(std::string name_val)
    : name(name_val), weaponb(NULL)
{
}

HumanB::~HumanB()
{
}

void    HumanB::attack()
{
    if (weaponb)
        std::cout << name << " attacks with their " << weaponb->getType() << std::endl;
    else
        std::cout << name << " has no woapon!" << std::endl;
}

void    HumanB::setWeapon(Weapon &weapon_name)
{
    weaponb = &weapon_name;
}