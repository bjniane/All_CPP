#ifndef HUMANB_H
#define HUMANB_H

#include "Weapon.h"

class HumanB
{
    private:
        std::string name;
        Weapon* weaponB;
    public:
        HumanB(std::string name_val);
        ~HumanB();
        void    attack(void);
        void    setWeapon(Weapon& weapon);
};

#endif