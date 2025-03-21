#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include "ClapTrap.h"

class ScavTrap : public ClapTrap
{
    public:
        ScavTrap();
        ScavTrap(std::string name);
        ScavTrap(const ScavTrap& source);
        ScavTrap& operator=(const ScavTrap& rhs);
        ~ScavTrap();
        
        void    attack(const std::string& target);
        void    guardGate();
};

#endif