#ifndef HUMANA_H
#define HUMANA_H

#include <string>
#include "Weapon.h"

class HumanA
{
private:
    std::string name;
    Weapon  &weapona;
public:
    HumanA(std::string name_val, Weapon &weapon_name);
    ~HumanA();
    void    attack();
};



#endif