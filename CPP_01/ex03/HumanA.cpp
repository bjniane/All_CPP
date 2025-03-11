#include "HumanA.h"

HumanA::HumanA(std::string name_val, Weapon& weapon)
    :name(name_val), weaponA(weapon)
{
}

HumanA::~HumanA()
{
}

void    HumanA::attack(void)
{
    std::cout << name << " attacks with their " << weaponA.getType() << std::endl;
}