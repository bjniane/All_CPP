#ifndef HUMANA_H
#define HUMANA_H

#include "Weapon.h"

class HumanA
{
    private:
        std::string name;
        Weapon& weaponA;
    public:
        HumanA(std::string name_val, Weapon& weapon);
        ~HumanA();
        void    attack(void);
};

#endif