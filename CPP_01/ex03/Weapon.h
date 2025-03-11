#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>
#include <string>

class Weapon
{
    private:
        std::string type;
    public:
        Weapon(std::string type_val);
        ~Weapon();
        const std::string& getType();
        void    setType(std::string type_val);
};

#endif