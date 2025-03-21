#include "FragTrap.h"

FragTrap::FragTrap()
    : ClapTrap()
{
    name = "None";
    Hit_points = 100;
    Energy_points = 100;
    Attack_damage = 30;
    std::cout << "FragTrap default constructor called for: " << name << std::endl;
}

FragTrap::FragTrap(std::string name)
    : ClapTrap(name)
{
    this->name = name;
    Hit_points = 100;
    Energy_points = 100;
    Attack_damage = 30;
    std::cout << "FragTrap constructor called for: " << name << std::endl;
}

FragTrap::FragTrap(const FragTrap& src)
    : ClapTrap(src)
{
    std::cout << "FragTrap copy constructor called for: " << name << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& rhs)
{
    if (this != &rhs)
        ClapTrap::operator=(rhs);
    std::cout << "FragTrap copy assignment called for: " << name << std::endl;
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructor called for: " << name << std::endl;
}

void    FragTrap::attack(const std::string& target)
{
    if (Energy_points > 0 && Hit_points > 0)
    {
        std::cout << "FragTrap " << name << " attacks " << target << ", causing " << Attack_damage << " points of damage!" << std::endl;
        Energy_points--;
    }
    else
        std::cout << "FragTrap " << name << " cannot attack" << std::endl;
}

void    FragTrap::highFivesGuys(void)
{
    std::cout << "High five!" << std::endl;
}