#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include "ClapTrap.h"

class FragTrap : public ClapTrap
{
    public:
        FragTrap();
        FragTrap(std::string name);
        FragTrap(const FragTrap& src);
        FragTrap& operator=(const FragTrap& rhs);
        ~FragTrap();

        void    attack(const std::string& target);
        void    highFivesGuys(void);
};

#endif