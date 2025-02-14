#include "HumanA.h"

HumanA::HumanA(std::string name_val, Weapon &weapon_name)
    : name(name_val), weapona(weapon_name)
{
}

HumanA::~HumanA()
{
}

void    HumanA::attack()
{
    std::cout << name << " attacks with their " << weapona.getType() << std::endl;
}