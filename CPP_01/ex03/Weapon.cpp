#include "Weapon.h"

Weapon::Weapon(std::string type_value)
    : type(type_value)
{
}

Weapon::~Weapon()
{
}

void    Weapon::setType(std::string type_value)
{
    type = type_value;
}

const std::string& Weapon::getType()
{
    return type;
}