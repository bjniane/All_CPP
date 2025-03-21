#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <iostream>
#include <string>

class ClapTrap
{
    protected:
        std::string name;
        unsigned int    Hit_points;
        unsigned int    Energy_points;
        unsigned int    Attack_damage;
    public:
        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap& source);
        ClapTrap& operator=(const ClapTrap& rhs);
        virtual ~ClapTrap();

        virtual void    attack(const std::string& target);
        void    takeDamage(unsigned int amount);
        void    beRepaired(unsigned int amount);
        const std::string& getName() const;
};

#endif