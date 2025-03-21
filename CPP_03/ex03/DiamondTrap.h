#ifndef DIAMONDTRAP_H
#define DIAMONDTRAP_H

#include "ScavTrap.h"
#include "FragTrap.h"

class DiamondTrap : public ScavTrap, public FragTrap
{
    private:
        std::string name;
    public:
        DiamondTrap();
        DiamondTrap(std::string name);
        DiamondTrap(const DiamondTrap& src);
        DiamondTrap& operator=(const DiamondTrap& rhs);
        ~DiamondTrap();

        void    attack(const std::string& target);
        void    whoAmI();
};

#endif