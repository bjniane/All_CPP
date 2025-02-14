#include "Zombie.h"

int main()
{
    Zombie* heap_zombie = newZombie("HeapZombie");
    heap_zombie->announce();
    delete heap_zombie;

    randomChump("StackZombie");
}