#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>
#include <string>

class Zombie
{
private:
    std::string name;
public:
    Zombie(std::string zombie_name);
    ~Zombie();
    void    announce(void);
};

Zombie  *newZombie(std::string name);
void    randomChump(std::string name);

#endif