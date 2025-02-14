#include "Zombie.h"

Zombie* zombieHorde(int N, std::string name)
{
    Zombie* hodre = new Zombie[N];
    for (int i = 0; i < N; i++)
    {
        hodre[i] = Zombie(name);
    }
    return hodre;
}