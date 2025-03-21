#include "DiamondTrap.h"

DiamondTrap::DiamondTrap()
    :  ClapTrap(), ScavTrap(), FragTrap(), name("None")
{
    ClapTrap::name = name + "_clap_name";
    Hit_points = FragTrap::Hit_points;
    Energy_points = ScavTrap::Energy_points;
    Attack_damage = FragTrap::Attack_damage;
    std::cout << "DiamondTrap default constructor called for: " << name << std::endl; 
}

DiamondTrap::DiamondTrap(std::string name)
    : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), name(name)
{
    ClapTrap::name = name + "_clap_name";
    Hit_points = FragTrap::Hit_points;
    Energy_points = ScavTrap::Energy_points;
    Attack_damage = FragTrap::Attack_damage;
    std::cout << "DiamondTrap constructor called for: " << name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& src)
    : ClapTrap(src), ScavTrap(src), FragTrap(src)
{
    name = src.name;
    Hit_points = src.Hit_points;
    Energy_points = src.Energy_points;
    Attack_damage = src.Attack_damage;
    std::cout << "DiamondTrap copy constructor called for: " << name << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& rhs)
{
    if (this != &rhs)
    {
        ClapTrap::operator=(rhs);
        ScavTrap::operator=(rhs);
        FragTrap::operator=(rhs);
        name = rhs.name;
        Hit_points = rhs.Hit_points;
        Energy_points = rhs.Energy_points;
        Attack_damage = rhs.Attack_damage;
    }
    std::cout << "DiamondTrap copy assignment called for: " << name << std::endl;
    return *this;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap destructor called for: " << name << std::endl;
}

void    DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}

void    DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap: " << name << ", ClapTrap: " << ClapTrap::name << std::endl;
}