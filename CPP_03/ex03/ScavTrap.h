#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include "ClapTrap.h"

class ScavTrap : virtual public ClapTrap
{
    public:
        ScavTrap();
        ScavTrap(std::string name);
        ScavTrap(const ScavTrap& source);
        ScavTrap& operator=(const ScavTrap& rhs);
        ~ScavTrap();
        
        virtual void    attack(const std::string& target);
        void    guardGate();
};

#endif