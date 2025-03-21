#include "ClapTrap.h"

ClapTrap::ClapTrap()
    : name("None"), Hit_points(10), Energy_points(10), Attack_damage(0)
{
    name = name + "_clap_name";
    std::cout << "ClapTrap default constructor called for: " << name << std::endl;
}

ClapTrap::ClapTrap(std::string name)
    : name(name), Hit_points(10), Energy_points(10), Attack_damage(0)
{
    std::cout << "ClapTrap constructor called for: " << name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& source)
    : name(source.name), Hit_points(source.Hit_points), Energy_points(source.Energy_points), Attack_damage(source.Attack_damage)
{
    std::cout << "ClapTrap copy constructor called for: " << name << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& rhs)
{
    std::cout << "ClapTrap copy assignment called: " << name << std::endl;
    if (this != &rhs)
    {
        name = rhs.name;
        Hit_points = rhs.Hit_points;
        Energy_points = rhs.Energy_points;
        Attack_damage = rhs.Attack_damage;
    }
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap destructor called for: " << name << std::endl;
}

const std::string& ClapTrap::getName() const
{
    return name;
}

void    ClapTrap::attack(const std::string& target)
{
    if (Energy_points > 0 && Hit_points > 0)
    {
        Energy_points--;
        std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << Attack_damage << " points of damage!" << std::endl;
    }
    else
        std::cout << "ClapTrap " << name << " cannot attack" << std::endl;
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    if (Hit_points == 0)
        std::cout << name << " is dead" << std::endl;
    else
    {
        if (Hit_points - amount > 0)
            Hit_points -= amount;
        else
            Hit_points = 0;
        std::cout << name << " took " << amount << " hit points, remaining points " << Hit_points << std::endl;
    }
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if (Energy_points > 0 && Hit_points > 0)
    {
        Hit_points += amount;
        Energy_points--;
        std::cout << name << " Repaired " << amount << " hit points, remaining points " << Hit_points << std::endl;
    }
    else
        std::cout << name << " cannot repair itself" << std::endl;
}