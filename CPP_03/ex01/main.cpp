#include "ScavTrap.h"

int main()
{
    ScavTrap    scav1("scav1");
    ScavTrap    scav2("scav2");
    // ClapTrap*   clap(&scav1);

    scav1.takeDamage(10);
    scav1.attack(scav2.getName());
    scav2.guardGate();
    scav1.takeDamage(5);
    scav1.beRepaired(4);
    // ClapTrap* clap = new ScavTrap("Bilal");
    // delete clap;
    return 0;
}