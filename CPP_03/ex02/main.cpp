#include "FragTrap.h"

int main()
{
    FragTrap    frag1("frag1");
    FragTrap    frag2("frag2");
    // ClapTrap*   clap(&frag1);

    // frag1.takeDamage(10);
    frag1.attack(frag2.getName());
    frag1.highFivesGuys();
    frag1.takeDamage(60);
    frag1.beRepaired(20);
    // ClapTrap* clap = new FragTrap("Bilal");
    // delete clap;
    return 0;
}