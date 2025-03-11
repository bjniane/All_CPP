#include "harl.h"

int main(int ac, char **av)
{
    if (ac == 2)
    {
        Harl harl;
        harl.complain(av[1]);
    }
    else
        std::cout << "Usage: ./harlFilter level" << std::endl;
    return 0;
}