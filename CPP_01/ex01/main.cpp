#include "Zombie.h"

int main()
{
    int N = 5;
    std::string name = "bilal";

    Zombie* hodre = zombieHorde(N, name);
    for (int i = 0; i < N; i++)
    {
        hodre[i].announce();
    }
    delete [] hodre;
}