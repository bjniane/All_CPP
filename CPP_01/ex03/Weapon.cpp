#include "Weapon.h"

Weapon::Weapon(std::string type_val)
    :type(type_val)
{
}

Weapon::~Weapon()
{
}

void    Weapon::setType(std::string type_val)
{
    type = type_val;
}

const std::string&  Weapon::getType()
{
    return type;
}
