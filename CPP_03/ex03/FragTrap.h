#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include "ClapTrap.h"

class FragTrap : virtual public ClapTrap
{
    public:
        FragTrap();
        FragTrap(std::string name);
        FragTrap(const FragTrap& src);
        FragTrap& operator=(const FragTrap& rhs);
        ~FragTrap();

        virtual void    attack(const std::string& target);
        void    highFivesGuys(void);
};

#endif