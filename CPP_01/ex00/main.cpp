#include "Zombie.h"

int main()
{
    randomChump("Stack");
    Zombie  *Heap = newZombie("Heap");
    Heap->announce();
    delete Heap;
    return 0;
}