#include "ScavTrap.h"

ScavTrap::ScavTrap()
    : ClapTrap()
{
    Hit_points = 100;
    Energy_points = 50;
    Attack_damage = 20;
    std::cout << "ScavTrap default constructor called for: " << name << std::endl;
}

ScavTrap::ScavTrap(std::string name)
    : ClapTrap(name)
{
    Hit_points = 100;
    Energy_points = 50;
    Attack_damage = 20;
    std::cout << "ScavTrap constructor called for: " << name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& source)
    : ClapTrap(source)
{
    std::cout << "ScavTrap copy constructor called for: " << name << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& rhs)
{
    std::cout << "ScavTrap copy assignment called: " << name << std::endl;
    if (this != &rhs)
        ClapTrap::operator=(rhs);
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor called for: " << name << std::endl;
}

void    ScavTrap::attack(const std::string& target)
{
    if (Energy_points > 0 && Hit_points > 0)
    {
        Energy_points--;
        std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << Attack_damage << " points of damage!" << std::endl;
    }
    else
        std::cout << "ScavTrap " << name << " cannot attack" << std::endl;
}

void    ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << name << " is now in Gate keeper mode" << std::endl;
}
